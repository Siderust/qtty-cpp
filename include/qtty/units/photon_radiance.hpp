// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct PhotonPerSquareMeterSecondSteradianTag {};
struct PhotonPerSquareCentimeterSecondSteradianTag {};
struct PhotonPerSquareCentimeterNanosecondSteradianTag {};

template <> struct UnitTraits<PhotonPerSquareMeterSecondSteradianTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_PHOTON_PER_SQUARE_METER_SECOND_STERADIAN; }
  static constexpr std::string_view symbol() { return "ph·m⁻²·s⁻¹·sr⁻¹"; }
};
template <> struct UnitTraits<PhotonPerSquareCentimeterSecondSteradianTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_PHOTON_PER_SQUARE_CENTIMETER_SECOND_STERADIAN; }
  static constexpr std::string_view symbol() { return "ph·cm⁻²·s⁻¹·sr⁻¹"; }
};
template <> struct UnitTraits<PhotonPerSquareCentimeterNanosecondSteradianTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_PHOTON_PER_SQUARE_CENTIMETER_NANOSECOND_STERADIAN; }
  static constexpr std::string_view symbol() { return "ph·cm⁻²·ns⁻¹·sr⁻¹"; }
};

using PhotonPerSquareMeterSecondSteradian = Quantity<PhotonPerSquareMeterSecondSteradianTag>;
using PhotonPerSquareCentimeterSecondSteradian = Quantity<PhotonPerSquareCentimeterSecondSteradianTag>;
using PhotonPerSquareCentimeterNanosecondSteradian = Quantity<PhotonPerSquareCentimeterNanosecondSteradianTag>;

} // namespace qtty
