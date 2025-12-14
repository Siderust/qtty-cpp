#pragma once

#include "../ffi_core.hpp"
#include "length.hpp"
#include "time.hpp"

namespace qtty {

// ============================================================================
// Compound Units: Velocity
// ============================================================================
// Velocity is a derived quantity representing length divided by time.
// Unlike base dimensions (length, time, mass, etc.), compound units are not
// directly supported by the C FFI layer. Instead, we use C++ template
// metaprogramming to encode the compound relationship in the type system.
//
// Design: CompoundTag<NumeratorTag, DenominatorTag> encodes a quotient of
// two unit types. The division operator (/) creates instances by dividing
// the raw values, while the type system tracks the unit relationship.
//
// Limitation: Conversions between different compound units (e.g., m/s to km/h)
// are not automatically supported. Users must manually convert numerator and
// denominator separately, then recombine.

// Template for compound units (e.g., velocity = length/time)
template<typename NumeratorTag, typename DenominatorTag>
struct CompoundTag {};

// Velocity type alias using compound units
// This is a template alias, not a concrete type. Instantiate with specific
// length and time units, e.g., Velocity<Meter, Second>.
template<typename LengthUnit, typename TimeUnit>
using Velocity = Quantity<CompoundTag<typename LengthUnit::unit_tag, typename TimeUnit::unit_tag>>;

// Note: The C API doesn't have explicit velocity unit IDs
// We create velocity by dividing length by time, operating on raw values
// No unit conversion is available for compound units through the C API

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
template<typename LengthTag, typename TimeTag>
Quantity<CompoundTag<LengthTag, TimeTag>> operator/(
    const Quantity<LengthTag>& length,
    const Quantity<TimeTag>& time)
{
    return Quantity<CompoundTag<LengthTag, TimeTag>>(length.value() / time.value());
}

// ============================================================================
// Common Velocity Type Aliases
// ============================================================================
// Pre-defined aliases for commonly used velocity combinations.
// These improve readability but are purely convenience types—they're just
// specific instantiations of Quantity<CompoundTag<...>>.

// Common velocity type aliases (constructed from division, not convertible)
using MeterPerSecond = Quantity<CompoundTag<MeterTag, SecondTag>>;
using KilometerPerHour = Quantity<CompoundTag<KilometerTag, HourTag>>;

} // namespace qtty
