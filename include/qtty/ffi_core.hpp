#pragma once

#include <cmath>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <ostream>
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
class QttyException : public std::runtime_error {
public:
    explicit QttyException(const std::string& msg) : std::runtime_error(msg) {}
};

class InvalidUnitError : public QttyException {
public:
    explicit InvalidUnitError(const std::string& msg) : QttyException(msg) {}
};

class IncompatibleDimensionsError : public QttyException {
public:
    explicit IncompatibleDimensionsError(const std::string& msg) : QttyException(msg) {}
};

class ConversionError : public QttyException {
public:
    explicit ConversionError(const std::string& msg) : QttyException(msg) {}
};

// ============================================================================
// Error Translation from C FFI to C++ Exceptions
// ============================================================================
// Maps C-style integer error codes from the Rust FFI layer to typed C++
// exceptions. This provides idiomatic error handling for C++ users while
// maintaining compatibility with the C FFI boundary.

// Helper function to check status and throw appropriate exceptions
inline void check_status(int32_t status, const char* operation) {
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
template<typename UnitTag>
class Quantity;

// Template trait to get unit ID from unit tag
// Each unit tag (e.g., MeterTag) must specialize this template to provide
// its corresponding C FFI unit ID constant (e.g., UNIT_ID_METER).
// Specializations are auto-generated in include/qtty/units/*.hpp
template<typename UnitTag>
struct UnitTraits;

// Helper to extract tag from either a tag or Quantity<Tag>
// This allows .to<>() to accept both Quantity<KilometerTag> and KilometerTag,
// making the API more flexible and user-friendly.
template<typename T>
struct ExtractTag {
    using type = T;
};

template<typename Tag>
struct ExtractTag<Quantity<Tag>> {
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
template<typename UnitTag>
class Quantity {
private:
    double m_value;
    
public:
    using unit_tag = UnitTag;
    
    // Constructors
    constexpr Quantity() : m_value(0.0) {}
    constexpr explicit Quantity(double value) : m_value(value) {}
    
    // Get the unit ID for this quantity type
    static constexpr UnitId unit_id() {
        return UnitTraits<UnitTag>::unit_id();
    }
    
    // Get the raw value
    constexpr double value() const {
        return m_value;
    }
    
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
    template<typename TargetType>
    Quantity<typename ExtractTag<TargetType>::type> to() const {
        using TargetTag = typename ExtractTag<TargetType>::type;
        qtty_quantity_t src_qty;
        qtty_quantity_t dst_qty;
        
        int32_t status = qtty_quantity_make(m_value, unit_id(), &src_qty);
        check_status(status, "Creating source quantity");
        
        status = qtty_quantity_convert(src_qty, UnitTraits<TargetTag>::unit_id(), &dst_qty);
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
    Quantity operator+(const Quantity& other) const {
        return Quantity(m_value + other.m_value);
    }
    
    Quantity operator-(const Quantity& other) const {
        return Quantity(m_value - other.m_value);
    }
    
    // ========================================================================
    // Scalar Operations
    // ========================================================================
    // Multiplying or dividing a quantity by a scalar preserves the unit.
    // E.g., 10 meters * 2 = 20 meters
    
    // Scalar multiplication and division
    Quantity operator*(double scalar) const {
        return Quantity(m_value * scalar);
    }
    
    Quantity operator/(double scalar) const {
        return Quantity(m_value / scalar);
    }
    
    // Friend function for scalar * quantity
    friend Quantity operator*(double scalar, const Quantity& q) {
        return q * scalar;
    }
    
    // ========================================================================
    // Comparison Operators
    // ========================================================================
    // All standard comparison operators are provided for convenience.
    // Comparisons only work between quantities of the same unit type,
    // enforcing type safety at compile time.
    
    // Comparison operators
    bool operator==(const Quantity& other) const {
        return m_value == other.m_value;
    }
    
    bool operator!=(const Quantity& other) const {
        return m_value != other.m_value;
    }
    
    bool operator<(const Quantity& other) const {
        return m_value < other.m_value;
    }
    
    bool operator>(const Quantity& other) const {
        return m_value > other.m_value;
    }
    
    bool operator<=(const Quantity& other) const {
        return m_value <= other.m_value;
    }
    
    bool operator>=(const Quantity& other) const {
        return m_value >= other.m_value;
    }
    
    // ========================================================================
    // Compound Assignment Operators
    // ========================================================================
    // Modify the quantity in place for efficiency.
    
    // Compound assignment operators
    Quantity& operator+=(const Quantity& other) {
        m_value += other.m_value;
        return *this;
    }
    
    Quantity& operator-=(const Quantity& other) {
        m_value -= other.m_value;
        return *this;
    }
    
    Quantity& operator*=(double scalar) {
        m_value *= scalar;
        return *this;
    }
    
    Quantity& operator/=(double scalar) {
        m_value /= scalar;
        return *this;
    }
    
    // ========================================================================
    // Unary Operators and Utilities
    // ========================================================================
    
    // Unary operators
    Quantity operator-() const {
        return Quantity(-m_value);
    }
    
    Quantity abs() const {
        return Quantity(std::abs(m_value));
    }

// ============================================================================
// Stream Insertion Operator
// ============================================================================
// Prints a quantity with its unit symbol, e.g., "1500 m" or "42.5 km"

template <typename UnitTag>
std::ostream &operator<<(std::ostream &os, const Quantity<UnitTag> &q) {
    os << q.value() << " " << UnitTraits<UnitTag>::symbol();
    return os;
}

} // namespace qtty
