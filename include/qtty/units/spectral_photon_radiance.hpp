// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct PhotonPerSquareMeterSecondSteradianMeterTag {};
struct PhotonPerSquareCentimeterSecondSteradianAngstromTag {};
struct PhotonPerSquareCentimeterSecondSteradianNanometerTag {};
struct PhotonPerSquareCentimeterNanosecondSteradianNanometerTag {};

template <> struct UnitTraits<PhotonPerSquareMeterSecondSteradianMeterTag> {
  static constexpr UnitId unit_id() {
    return UNIT_ID_PHOTON_PER_SQUARE_METER_SECOND_STERADIAN_METER;
  }
  static constexpr std::string_view symbol() { return "ph·m⁻²·s⁻¹·sr⁻¹·m⁻¹"; }
};
template <> struct UnitTraits<PhotonPerSquareCentimeterSecondSteradianAngstromTag> {
  static constexpr UnitId unit_id() {
    return UNIT_ID_PHOTON_PER_SQUARE_CENTIMETER_SECOND_STERADIAN_ANGSTROM;
  }
  static constexpr std::string_view symbol() { return "ph·cm⁻²·s⁻¹·sr⁻¹·Å⁻¹"; }
};
template <> struct UnitTraits<PhotonPerSquareCentimeterSecondSteradianNanometerTag> {
  static constexpr UnitId unit_id() {
    return UNIT_ID_PHOTON_PER_SQUARE_CENTIMETER_SECOND_STERADIAN_NANOMETER;
  }
  static constexpr std::string_view symbol() { return "ph·cm⁻²·s⁻¹·sr⁻¹·nm⁻¹"; }
};
template <> struct UnitTraits<PhotonPerSquareCentimeterNanosecondSteradianNanometerTag> {
  static constexpr UnitId unit_id() {
    return UNIT_ID_PHOTON_PER_SQUARE_CENTIMETER_NANOSECOND_STERADIAN_NANOMETER;
  }
  static constexpr std::string_view symbol() { return "ph·cm⁻²·ns⁻¹·sr⁻¹·nm⁻¹"; }
};

using PhotonPerSquareMeterSecondSteradianMeter =
    Quantity<PhotonPerSquareMeterSecondSteradianMeterTag>;
using PhotonPerSquareCentimeterSecondSteradianAngstrom =
    Quantity<PhotonPerSquareCentimeterSecondSteradianAngstromTag>;
using PhotonPerSquareCentimeterSecondSteradianNanometer =
    Quantity<PhotonPerSquareCentimeterSecondSteradianNanometerTag>;
using PhotonPerSquareCentimeterNanosecondSteradianNanometer =
    Quantity<PhotonPerSquareCentimeterNanosecondSteradianNanometerTag>;

} // namespace qtty
