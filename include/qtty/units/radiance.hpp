// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct WattPerSquareMeterSteradianTag {};
struct ErgPerSecondSquareCentimeterSteradianTag {};

template <> struct UnitTraits<WattPerSquareMeterSteradianTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_WATT_PER_SQUARE_METER_STERADIAN; }
  static constexpr std::string_view symbol() { return "W·m⁻²·sr⁻¹"; }
};
template <> struct UnitTraits<ErgPerSecondSquareCentimeterSteradianTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ERG_PER_SECOND_SQUARE_CENTIMETER_STERADIAN; }
  static constexpr std::string_view symbol() { return "erg·s⁻¹·cm⁻²·sr⁻¹"; }
};

using WattPerSquareMeterSteradian = Quantity<WattPerSquareMeterSteradianTag>;
using ErgPerSecondSquareCentimeterSteradian = Quantity<ErgPerSecondSquareCentimeterSteradianTag>;

} // namespace qtty
