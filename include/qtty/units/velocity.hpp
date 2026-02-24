// SPDX-License-Identifier: AGPL-3.0-or-later
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"
#include "length.hpp"
#include "time.hpp"

namespace qtty {

// ============================================================================
// Compound Units: Velocity
// ============================================================================
// Velocity is a derived quantity representing length divided by time.
// Compound units are fully supported through the FFI layer via
// qtty_derived_make() and qtty_derived_convert(), which independently convert
// numerator and denominator units to produce the correct result.
//
// Design: CompoundTag<NumeratorTag, DenominatorTag> encodes a quotient of
// two unit types. The type system tracks the unit relationship at compile
// time, while the Rust FFI layer handles conversions at runtime.
//
// Conversions between different compound units (e.g., m/s to km/h) are
// fully supported via the .to<>() method, just like simple unit conversions.

// Velocity type alias using compound units
// This is a template alias, not a concrete type. Instantiate with specific
// length and time units, e.g., Velocity<Meter, Second>.
template <typename LengthUnit, typename TimeUnit>
using Velocity = Quantity<
    CompoundTag<typename LengthUnit::unit_tag, typename TimeUnit::unit_tag>>;

// ============================================================================
// Division Operator: Create Compound Units
// ============================================================================
// Dividing a length quantity by a time quantity produces a velocity.
// The resulting type encodes both the numerator and denominator units,
// allowing type-safe operations on velocities while maintaining dimensional
// correctness (e.g., you can't add m/s to m/s² by accident).
//
// Example:
//   Meter distance(100.0);
//   Second time(20.0);
//   auto velocity = distance / time;  // Type: MeterPerSecond
//   std::cout << velocity.value();    // Prints: 5.0

// Division operator to create velocity from length and time
template <typename LengthTag, typename TimeTag>
Quantity<CompoundTag<LengthTag, TimeTag>>
operator/(const Quantity<LengthTag> &length, const Quantity<TimeTag> &time) {
  return Quantity<CompoundTag<LengthTag, TimeTag>>(length.value() /
                                                   time.value());
}

// ============================================================================
// UnitTraits for Compound Units
// ============================================================================
// Compound tags expose numerator_unit_id() and denominator_unit_id() instead
// of a single unit_id(). The Quantity::to<>() template detects compound tags
// via is_compound_v<> and dispatches to qtty_derived_convert() accordingly.

// Generic template: derives unit IDs from the component tags
template <typename NumeratorTag, typename DenominatorTag>
struct UnitTraits<CompoundTag<NumeratorTag, DenominatorTag>> {
  static constexpr UnitId numerator_unit_id() {
    return UnitTraits<NumeratorTag>::unit_id();
  }
  static constexpr UnitId denominator_unit_id() {
    return UnitTraits<DenominatorTag>::unit_id();
  }
  static constexpr std::string_view symbol() { return ""; }
};

// Specializations for common velocity types: provide human-readable symbols
template <> struct UnitTraits<CompoundTag<MeterTag, SecondTag>> {
  static constexpr UnitId numerator_unit_id() { return UNIT_ID_METER; }
  static constexpr UnitId denominator_unit_id() { return UNIT_ID_SECOND; }
  static constexpr std::string_view symbol() { return "m/s"; }
};

template <> struct UnitTraits<CompoundTag<KilometerTag, HourTag>> {
  static constexpr UnitId numerator_unit_id() { return UNIT_ID_KILOMETER; }
  static constexpr UnitId denominator_unit_id() { return UNIT_ID_HOUR; }
  static constexpr std::string_view symbol() { return "km/h"; }
};

template <> struct UnitTraits<CompoundTag<MeterTag, HourTag>> {
  static constexpr UnitId numerator_unit_id() { return UNIT_ID_METER; }
  static constexpr UnitId denominator_unit_id() { return UNIT_ID_HOUR; }
  static constexpr std::string_view symbol() { return "m/h"; }
};

template <> struct UnitTraits<CompoundTag<KilometerTag, SecondTag>> {
  static constexpr UnitId numerator_unit_id() { return UNIT_ID_KILOMETER; }
  static constexpr UnitId denominator_unit_id() { return UNIT_ID_SECOND; }
  static constexpr std::string_view symbol() { return "km/s"; }
};

template <> struct UnitTraits<CompoundTag<MeterTag, MinuteTag>> {
  static constexpr UnitId numerator_unit_id() { return UNIT_ID_METER; }
  static constexpr UnitId denominator_unit_id() { return UNIT_ID_MINUTE; }
  static constexpr std::string_view symbol() { return "m/min"; }
};

template <> struct UnitTraits<CompoundTag<KilometerTag, MinuteTag>> {
  static constexpr UnitId numerator_unit_id() { return UNIT_ID_KILOMETER; }
  static constexpr UnitId denominator_unit_id() { return UNIT_ID_MINUTE; }
  static constexpr std::string_view symbol() { return "km/min"; }
};

// ============================================================================
// Common Velocity Type Aliases
// ============================================================================
// Pre-defined aliases for commonly used velocity combinations.
// These improve readability but are purely convenience types—they're just
// specific instantiations of Quantity<CompoundTag<...>>.

using MeterPerSecond = Quantity<CompoundTag<MeterTag, SecondTag>>;
using KilometerPerHour = Quantity<CompoundTag<KilometerTag, HourTag>>;
using KilometerPerSecond = Quantity<CompoundTag<KilometerTag, SecondTag>>;
using MeterPerHour = Quantity<CompoundTag<MeterTag, HourTag>>;
using MeterPerMinute = Quantity<CompoundTag<MeterTag, MinuteTag>>;
using KilometerPerMinute = Quantity<CompoundTag<KilometerTag, MinuteTag>>;

} // namespace qtty
