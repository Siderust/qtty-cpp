// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct WattPerSquareMeterSteradianMeterTag {};
struct WattPerSquareMeterSteradianNanometerTag {};
struct ErgPerSecondSquareCentimeterSteradianAngstromTag {};

template <> struct UnitTraits<WattPerSquareMeterSteradianMeterTag> {
  static constexpr UnitId unit_id() {
    return UNIT_ID_WATT_PER_SQUARE_METER_STERADIAN_METER;
  }
  static constexpr std::string_view symbol() { return "W·m⁻²·sr⁻¹·m⁻¹"; }
};
template <> struct UnitTraits<WattPerSquareMeterSteradianNanometerTag> {
  static constexpr UnitId unit_id() {
    return UNIT_ID_WATT_PER_SQUARE_METER_STERADIAN_NANOMETER;
  }
  static constexpr std::string_view symbol() { return "W·m⁻²·sr⁻¹·nm⁻¹"; }
};
template <>
struct UnitTraits<ErgPerSecondSquareCentimeterSteradianAngstromTag> {
  static constexpr UnitId unit_id() {
    return UNIT_ID_ERG_PER_SECOND_SQUARE_CENTIMETER_STERADIAN_ANGSTROM;
  }
  static constexpr std::string_view symbol() { return "erg·s⁻¹·cm⁻²·sr⁻¹·Å⁻¹"; }
};

using WattPerSquareMeterSteradianMeter =
    Quantity<WattPerSquareMeterSteradianMeterTag>;
using WattPerSquareMeterSteradianNanometer =
    Quantity<WattPerSquareMeterSteradianNanometerTag>;
using ErgPerSecondSquareCentimeterSteradianAngstrom =
    Quantity<ErgPerSecondSquareCentimeterSteradianAngstromTag>;

} // namespace qtty
