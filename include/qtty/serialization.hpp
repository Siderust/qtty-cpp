// SPDX-License-Identifier: AGPL-3.0-or-later
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

/**
 * @file serialization.hpp
 * @brief JSON serialization helpers for qtty quantities.
 */

#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
extern "C" {
#include "qtty_ffi.h"
}
#include "ffi_core.hpp"

// Forward declarations for JSON-related FFI functions. These may not be present
// in older generated headers; we declare them here to ensure availability at
// compile time when linking against a serde-enabled qtty-ffi.
extern "C" {
int32_t qtty_quantity_to_json_value(qtty_quantity_t src, char **out_json);
int32_t qtty_quantity_from_json_value(UnitId unit, const char *json,
                                      qtty_quantity_t *out);
int32_t qtty_quantity_to_json(qtty_quantity_t src, char **out_json);
int32_t qtty_quantity_from_json(const char *json, qtty_quantity_t *out);
int32_t qtty_derived_to_json(qtty_derived_quantity_t src, char **out);
int32_t qtty_derived_from_json(const char *json, qtty_derived_quantity_t *out);
void qtty_string_free(char *s);
}

namespace qtty {
namespace serialization {

// Thin wrappers over Rust FFI JSON serialize/deserialize.
// Requires qtty-ffi to be built with the `serde` Cargo feature.

/**
 * @brief Convert an owned C string from FFI into std::string and free it.
 * @param ptr Pointer allocated by qtty-ffi.
 * @return Copied C++ string (or empty when @p ptr is null).
 */
inline std::string from_owned_c(char *ptr) {
  if (!ptr)
    return {};
  std::string s(ptr);
  // Free via FFI allocator
  qtty_string_free(ptr);
  return s;
}

// Serialize only the numeric value as a JSON number string.
// Mirrors Rust's default serde for quantities.

/**
 * @brief Serialize only the numeric value as JSON for a typed quantity.
 * @tparam UnitTag Unit tag of the source quantity.
 * @param q Source quantity.
 * @return JSON string representing only the value.
 */
template <typename UnitTag>
std::string to_json_value(const Quantity<UnitTag> &q) {
  qtty_quantity_t src{};
  int32_t status =
      qtty_quantity_make(q.value(), UnitTraits<UnitTag>::unit_id(), &src);
  check_status(status, "Creating source quantity for to_json_value");

  char *out = nullptr;
  status = qtty_quantity_to_json_value(src, &out);
  check_status(status, "Serializing value to JSON");
  return from_owned_c(out);
}

/**
 * @brief Deserialize a JSON numeric value into a typed quantity.
 * @tparam T Unit tag or Quantity type of the target.
 * @param json JSON input string view.
 * @return Deserialized typed quantity.
 */
template <typename T>
Quantity<typename ExtractTag<T>::type> from_json_value(std::string_view json) {
  using UnitTag = typename ExtractTag<T>::type;
  qtty_quantity_t out_qty{};
  int32_t status = qtty_quantity_from_json_value(UnitTraits<UnitTag>::unit_id(),
                                                 json.data(), &out_qty);
  check_status(status, "Deserializing value from JSON");
  return Quantity<UnitTag>(out_qty.value);
}

// Serialize value and unit_id into an object {"value":<f64>, "unit_id":<u32>}.

/**
 * @brief Serialize a typed quantity as JSON object with value and unit id.
 * @tparam UnitTag Unit tag of the source quantity.
 * @param q Source quantity.
 * @return JSON object string with value/unit_id fields.
 */
template <typename UnitTag> std::string to_json(const Quantity<UnitTag> &q) {
  qtty_quantity_t src{};
  int32_t status =
      qtty_quantity_make(q.value(), UnitTraits<UnitTag>::unit_id(), &src);
  check_status(status, "Creating source quantity for to_json");

  char *out = nullptr;
  status = qtty_quantity_to_json(src, &out);
  check_status(status, "Serializing quantity to JSON");
  return from_owned_c(out);
}

inline UnitId unit_id_from_u32(uint32_t raw) {
  // cbindgen exposes UnitId directly; cast is safe for values from Rust
  return static_cast<UnitId>(raw);
}

// Parse {"value":<f64>, "unit_id":<u32>} and construct a typed quantity.
// Rejects mismatched dimensions and unknown unit_ids at the Rust boundary.

/**
 * @brief Deserialize a JSON quantity object into a requested target type.
 * @tparam T Unit tag or Quantity type of the target.
 * @param json JSON input string view.
 * @return Quantity converted to requested target unit.
 */
template <typename T>
Quantity<typename ExtractTag<T>::type> from_json(std::string_view json) {
  using UnitTag = typename ExtractTag<T>::type;
  qtty_quantity_t out_qty{};
  int32_t status = qtty_quantity_from_json(json.data(), &out_qty);
  check_status(status, "Deserializing quantity from JSON");

  // Convert to requested UnitTag if needed; Rust returns the unit in JSON
  if (out_qty.unit != UnitTraits<UnitTag>::unit_id()) {
    qtty_quantity_t conv{};
    status =
        qtty_quantity_convert(out_qty, UnitTraits<UnitTag>::unit_id(), &conv);
    check_status(status, "Converting deserialized quantity to target unit");
    return Quantity<UnitTag>(conv.value);
  }
  return Quantity<UnitTag>(out_qty.value);
}

} // namespace serialization

// ============================================================================
// Compound Quantity Serialization
// ============================================================================
// Serialize/deserialize derived quantities (e.g., velocity) via the Rust FFI.

namespace derived_serialization {

/**
 * @brief Serialize a compound quantity as JSON.
 * @tparam Tag CompoundTag type of the quantity.
 * @param q Source compound quantity.
 * @return JSON string.
 */
template <typename Tag> std::string to_json(const Quantity<Tag> &q) {
  static_assert(is_compound_v<Tag>,
                "derived_serialization::to_json requires a compound quantity");
  qtty_derived_quantity_t src{};
  int32_t status =
      qtty_derived_make(q.value(), UnitTraits<Tag>::numerator_unit_id(),
                        UnitTraits<Tag>::denominator_unit_id(), &src);
  check_status(status, "Creating derived quantity for serialization");

  char *out = nullptr;
  status = qtty_derived_to_json(src, &out);
  check_status(status, "Serializing derived quantity to JSON");
  return serialization::from_owned_c(out);
}

/**
 * @brief Deserialize a JSON string into a compound quantity.
 * @tparam T CompoundTag or Quantity<CompoundTag> type.
 * @param json JSON input string view.
 * @return Deserialized compound quantity, converted to requested target units.
 */
template <typename T>
Quantity<typename ExtractTag<T>::type> from_json(std::string_view json) {
  using Tag = typename ExtractTag<T>::type;
  static_assert(is_compound_v<Tag>,
                "derived_serialization::from_json requires a compound type");
  qtty_derived_quantity_t out_qty{};
  int32_t status = qtty_derived_from_json(json.data(), &out_qty);
  check_status(status, "Deserializing derived quantity from JSON");

  // Convert to requested units if needed
  if (out_qty.numerator != UnitTraits<Tag>::numerator_unit_id() ||
      out_qty.denominator != UnitTraits<Tag>::denominator_unit_id()) {
    qtty_derived_quantity_t conv{};
    status =
        qtty_derived_convert(out_qty, UnitTraits<Tag>::numerator_unit_id(),
                             UnitTraits<Tag>::denominator_unit_id(), &conv);
    check_status(status, "Converting deserialized derived quantity");
    return Quantity<Tag>(conv.value);
  }
  return Quantity<Tag>(out_qty.value);
}

} // namespace derived_serialization
} // namespace qtty
