// SPDX-License-Identifier: AGPL-3.0-or-later
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

/**
 * @file ffi_core.hpp
 * @brief Core quantity template and error translation utilities.
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
extern "C" {
#include "qtty_ffi.h"
}

namespace qtty {

// ============================================================================
// Exception Hierarchy
// ============================================================================
// All qtty exceptions derive from std::runtime_error for compatibility with
// standard exception handling practices. The hierarchy provides fine-grained
// error types for different failure modes when interacting with the FFI layer.

// Exception types for error handling
/**
 * @brief Base exception for all qtty wrapper failures.
 */
class QttyException : public std::runtime_error {
public:
  explicit QttyException(const std::string &msg) : std::runtime_error(msg) {}
};

/**
 * @brief Raised when an unknown or invalid unit identifier is used.
 */
class InvalidUnitError : public QttyException {
public:
  explicit InvalidUnitError(const std::string &msg) : QttyException(msg) {}
};

/**
 * @brief Raised when mixing incompatible dimensions in conversion/arithmetic.
 */
class IncompatibleDimensionsError : public QttyException {
public:
  explicit IncompatibleDimensionsError(const std::string &msg)
      : QttyException(msg) {}
};

/**
 * @brief Raised when value conversion fails at the FFI boundary.
 */
class ConversionError : public QttyException {
public:
  explicit ConversionError(const std::string &msg) : QttyException(msg) {}
};

// ============================================================================
// Error Translation from C FFI to C++ Exceptions
// ============================================================================
// Maps C-style integer error codes from the Rust FFI layer to typed C++
// exceptions. This provides idiomatic error handling for C++ users while
// maintaining compatibility with the C FFI boundary.

// Helper function to check status and throw appropriate exceptions
/**
 * @brief Convert qtty FFI status codes into typed C++ exceptions.
 * @param status Status code returned by a qtty FFI function.
 * @param operation Human-readable operation label for error context.
 * @throws QttyException and derived exception types on failure statuses.
 */
inline void check_status(int32_t status, const char *operation) {
  if (status == QTTY_OK) {
    return;
  }

  std::string msg = std::string(operation) + " failed: ";
  switch (status) {
  case QTTY_ERR_UNKNOWN_UNIT:
    throw InvalidUnitError(msg + "unknown unit");
  case QTTY_ERR_INCOMPATIBLE_DIM:
    throw IncompatibleDimensionsError(msg + "incompatible dimensions");
  case QTTY_ERR_NULL_OUT:
    throw QttyException(msg + "null output pointer");
  case QTTY_ERR_INVALID_VALUE:
    throw ConversionError(msg + "invalid value");
  default:
    throw QttyException(msg + "unknown error");
  }
}

// ============================================================================
// Forward Declarations and Type Traits
// ============================================================================

// Forward declarations
template <typename UnitTag> class Quantity;

// Template trait to get unit ID from unit tag
// Each unit tag (e.g., MeterTag) must specialize this template to provide
// its corresponding C FFI unit ID constant (e.g., UNIT_ID_METER).
// Specializations are auto-generated in include/qtty/units/*.hpp
template <typename UnitTag> struct UnitTraits;

// Helper to extract tag from either a tag or Quantity<Tag>
// This allows .to<>() to accept both Quantity<KilometerTag> and KilometerTag,
// making the API more flexible and user-friendly.
template <typename T> struct ExtractTag {
  using type = T;
};

template <typename Tag> struct ExtractTag<Quantity<Tag>> {
  using type = Tag;
};

// ============================================================================
// Quantity Template Class
// ============================================================================
// The core abstraction representing a physical quantity with compile-time
// type safety. Each instantiation (e.g., Quantity<MeterTag>) is a distinct
// type, preventing accidental mixing of incompatible units at compile time.
//
// Key Design Decisions:
// - Header-only for zero-cost abstraction (all code inlined)
// - constexpr constructors enable compile-time quantity creation
// - explicit constructor prevents implicit double-to-Quantity conversions
// - Conversions go through the Rust FFI layer for correctness

// Base Quantity template class
template <typename UnitTag> class Quantity {
private:
  double m_value;

public:
  using unit_tag = UnitTag;

  // Constructors
  constexpr Quantity() : m_value(0.0) {}
  constexpr explicit Quantity(double value) : m_value(value) {}

  // Get the unit ID for this quantity type
  static constexpr UnitId unit_id() { return UnitTraits<UnitTag>::unit_id(); }

  // Get the raw value
  constexpr double value() const { return m_value; }

  // ========================================================================
  // Unit Conversion
  // ========================================================================
  // Converts this quantity to a different unit of the same dimension.
  // The conversion is performed by the Rust qtty-ffi library to ensure
  // correctness and consistency with the authoritative conversion factors.
  //
  // Accepts either a tag type (e.g., KilometerTag) or a Quantity type
  // (e.g., Kilometer) for convenience, thanks to the ExtractTag helper.
  //
  // Throws IncompatibleDimensionsError if attempting to convert between
  // different dimensions (e.g., length to time).

  // Convert to another unit type (accepts either Tag or Quantity<Tag>)
  template <typename TargetType>
  Quantity<typename ExtractTag<TargetType>::type> to() const {
    using TargetTag = typename ExtractTag<TargetType>::type;
    qtty_quantity_t src_qty;
    qtty_quantity_t dst_qty;

    int32_t status = qtty_quantity_make(m_value, unit_id(), &src_qty);
    check_status(status, "Creating source quantity");

    status = qtty_quantity_convert(src_qty, UnitTraits<TargetTag>::unit_id(),
                                   &dst_qty);
    check_status(status, "Converting units");

    return Quantity<TargetTag>(dst_qty.value);
  }

  // ========================================================================
  // Arithmetic Operators (Same Unit)
  // ========================================================================
  // Addition and subtraction only work between quantities of the same unit.
  // This enforces dimensional correctness at compile time. To add quantities
  // of different units, explicitly convert one to match the other first.

  // Arithmetic operators - same unit
  Quantity operator+(const Quantity &other) const {
    return Quantity(m_value + other.m_value);
  }

  Quantity operator-(const Quantity &other) const {
    return Quantity(m_value - other.m_value);
  }

  // ========================================================================
  // Scalar Operations
  // ========================================================================
  // Multiplying or dividing a quantity by a scalar preserves the unit.
  // E.g., 10 meters * 2 = 20 meters

  // Scalar multiplication and division
  Quantity operator*(double scalar) const { return Quantity(m_value * scalar); }

  Quantity operator/(double scalar) const { return Quantity(m_value / scalar); }

  // Friend function for scalar * quantity
  friend Quantity operator*(double scalar, const Quantity &q) {
    return q * scalar;
  }

  // ========================================================================
  // Comparison Operators
  // ========================================================================
  // All standard comparison operators are provided for convenience.
  // Comparisons only work between quantities of the same unit type,
  // enforcing type safety at compile time.

  // Comparison operators
  bool operator==(const Quantity &other) const {
    return m_value == other.m_value;
  }

  bool operator!=(const Quantity &other) const {
    return m_value != other.m_value;
  }

  bool operator<(const Quantity &other) const {
    return m_value < other.m_value;
  }

  bool operator>(const Quantity &other) const {
    return m_value > other.m_value;
  }

  bool operator<=(const Quantity &other) const {
    return m_value <= other.m_value;
  }

  bool operator>=(const Quantity &other) const {
    return m_value >= other.m_value;
  }

  // ========================================================================
  // Compound Assignment Operators
  // ========================================================================
  // Modify the quantity in place for efficiency.

  // Compound assignment operators
  Quantity &operator+=(const Quantity &other) {
    m_value += other.m_value;
    return *this;
  }

  Quantity &operator-=(const Quantity &other) {
    m_value -= other.m_value;
    return *this;
  }

  Quantity &operator*=(double scalar) {
    m_value *= scalar;
    return *this;
  }

  Quantity &operator/=(double scalar) {
    m_value /= scalar;
    return *this;
  }

  // ========================================================================
  // Unary Operators and Utilities
  // ========================================================================

  // Unary operators
  Quantity operator-() const { return Quantity(-m_value); }

  Quantity abs() const { return Quantity(std::abs(m_value)); }

  // ========================================================================
  // String Formatting
  // ========================================================================
  // Format the quantity as a human-readable string, mirroring Rust's format
  // annotations.  The mapping is:
  //
  //   Rust             C++
  //   {}               format()
  //   {:.2}            format(2)
  //   {:e}             format(-1, QTTY_FMT_LOWER_EXP)
  //   {:.4e}           format(4,  QTTY_FMT_LOWER_EXP)
  //   {:E}             format(-1, QTTY_FMT_UPPER_EXP)
  //   {:.4E}           format(4,  QTTY_FMT_UPPER_EXP)
  //
  // The formatting logic lives in the Rust qtty-ffi library, so precision
  // semantics are identical on both sides of the FFI boundary.

  /**
   * @brief Format this quantity as a string.
   *
   * Delegates to the Rust qtty-ffi `qtty_quantity_format` function so that
   * C++ and Rust produce identical output for the same parameters.
   *
   * @param precision  Digits after the decimal point.  Pass a negative value
   *                   (default) for the shortest exact representation.
   * @param flags      Notation selector:
   *                   - `QTTY_FMT_DEFAULT`   (0): decimal (e.g. `"1234.57 m"`)
   *                   - `QTTY_FMT_LOWER_EXP` (1): scientific lower-case `e`
   *                   - `QTTY_FMT_UPPER_EXP` (2): scientific upper-case `E`
   * @return Formatted string, e.g. `"1234.57 m"` or `"1.23e3 m"`.
   * @throws QttyException on formatting failure.
   */
  std::string format(int precision = -1,
                     uint32_t flags = QTTY_FMT_DEFAULT) const {
    qtty_quantity_t qty;
    int32_t make_status = qtty_quantity_make(m_value, unit_id(), &qty);
    check_status(make_status, "format: creating quantity");

    char buf[512];
    int32_t result =
        qtty_quantity_format(qty, precision, flags, buf, sizeof(buf));
    if (result == QTTY_ERR_BUFFER_TOO_SMALL) {
      // Retry with a generous large buffer (quantities should never need this)
      char big_buf[4096];
      result = qtty_quantity_format(qty, precision, flags, big_buf,
                                    sizeof(big_buf));
      if (result < 0) {
        throw QttyException("format: buffer too small even at 4096 bytes");
      }
      return std::string(big_buf);
    }
    if (result < 0) {
      check_status(result, "format: formatting quantity");
    }
    return std::string(buf);
  }
};

// ============================================================================
// Stream Insertion Operator
// ============================================================================
// Prints a quantity with its unit symbol, e.g., "1500 m" or "42.5 km".
//
// Because this streams `q.value()` (a plain double) directly into the
// `std::ostream`, all standard stream format manipulators are respected:
//
//   std::cout << std::fixed << std::setprecision(2) << qty;   // "1234.57 m"
//   std::cout << std::scientific << qty;                       // "1.23457e+003 m"
//   std::cout << std::scientific << std::setprecision(4)
//             << qty;                                          // "1.2346e+003 m"
//
// For `std::format` (C++20) see the std::formatter specialisation below.

template <typename UnitTag>
std::ostream &operator<<(std::ostream &os, const Quantity<UnitTag> &q) {
  os << q.value() << " " << UnitTraits<UnitTag>::symbol();
  return os;
}

} // namespace qtty

// ============================================================================
// C++20 std::formatter specialisation
// ============================================================================
// Allows `std::format` and `std::print` to be used with any Quantity type,
// honouring the same format specifiers as std::formatter<double>:
//
//   std::format("{}", qty)          → "1234.56789 s"
//   std::format("{:.2f}", qty)      → "1234.57 s"
//   std::format("{:e}", qty)        → "1.23457e+03 s"
//   std::format("{:.4e}", qty)      → "1.2346e+03 s"
//   std::format("{:E}", qty)        → "1.23457E+03 s"
//   std::format("{:>15.2f}", qty)   → "        1234.57 s"   (number padded, not symbol)
//
// Note: width / fill / align specifications are applied to the numeric part
// only; the unit symbol is always appended directly after without padding.
// This mirrors the behaviour of the Rust Display/LowerExp/UpperExp impls.

#if __cplusplus >= 202002L
#include <format>

namespace std {

template <typename UnitTag>
struct formatter<qtty::Quantity<UnitTag>> {
private:
  std::formatter<double> double_fmt_;

public:
  /// Parse the format specification (e.g. ".2f", "e", ".4e").
  template <typename ParseContext>
  constexpr auto parse(ParseContext &ctx) {
    return double_fmt_.parse(ctx);
  }

  /// Format the quantity: apply the parsed spec to the value, then append the
  /// unit symbol.
  template <typename FormatContext>
  auto format(const qtty::Quantity<UnitTag> &qty, FormatContext &ctx) const {
    auto out = double_fmt_.format(qty.value(), ctx);
    return std::format_to(out, " {}", qtty::UnitTraits<UnitTag>::symbol());
  }
};

} // namespace std
#endif // __cplusplus >= 202002L
