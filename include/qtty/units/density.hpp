// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct KilogramPerCubicMeterTag {};
struct GramPerCubicCentimeterTag {};
struct GramPerMilliliterTag {};
struct PoundPerCubicFootTag {};

template <> struct UnitTraits<KilogramPerCubicMeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOGRAM_PER_CUBIC_METER; }
  static constexpr std::string_view symbol() { return "kg/m³"; }
};
template <> struct UnitTraits<GramPerCubicCentimeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_GRAM_PER_CUBIC_CENTIMETER; }
  static constexpr std::string_view symbol() { return "g/cm³"; }
};
template <> struct UnitTraits<GramPerMilliliterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_GRAM_PER_MILLILITER; }
  static constexpr std::string_view symbol() { return "g/mL"; }
};
template <> struct UnitTraits<PoundPerCubicFootTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_POUND_PER_CUBIC_FOOT; }
  static constexpr std::string_view symbol() { return "lb/ft³"; }
};

using KilogramPerCubicMeter = Quantity<KilogramPerCubicMeterTag>;
using GramPerCubicCentimeter = Quantity<GramPerCubicCentimeterTag>;
using GramPerMilliliter = Quantity<GramPerMilliliterTag>;
using PoundPerCubicFoot = Quantity<PoundPerCubicFootTag>;

} // namespace qtty
