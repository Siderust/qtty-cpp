// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct CubicMeterTag {};
struct CubicKilometerTag {};
struct CubicCentimeterTag {};
struct CubicMillimeterTag {};
struct LiterTag {};
struct MilliliterTag {};
struct MicroliterTag {};
struct CentiliterTag {};
struct DeciliterTag {};
struct CubicInchTag {};
struct CubicFootTag {};
struct UsGallonTag {};
struct UsFluidOunceTag {};

template <> struct UnitTraits<CubicMeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CUBIC_METER; }
  static constexpr std::string_view symbol() { return "m³"; }
};
template <> struct UnitTraits<CubicKilometerTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CUBIC_KILOMETER; }
  static constexpr std::string_view symbol() { return "km³"; }
};
template <> struct UnitTraits<CubicCentimeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CUBIC_CENTIMETER; }
  static constexpr std::string_view symbol() { return "cm³"; }
};
template <> struct UnitTraits<CubicMillimeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CUBIC_MILLIMETER; }
  static constexpr std::string_view symbol() { return "mm³"; }
};
template <> struct UnitTraits<LiterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_LITER; }
  static constexpr std::string_view symbol() { return "L"; }
};
template <> struct UnitTraits<MilliliterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLILITER; }
  static constexpr std::string_view symbol() { return "mL"; }
};
template <> struct UnitTraits<MicroliterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROLITER; }
  static constexpr std::string_view symbol() { return "µL"; }
};
template <> struct UnitTraits<CentiliterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CENTILITER; }
  static constexpr std::string_view symbol() { return "cL"; }
};
template <> struct UnitTraits<DeciliterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_DECILITER; }
  static constexpr std::string_view symbol() { return "dL"; }
};
template <> struct UnitTraits<CubicInchTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CUBIC_INCH; }
  static constexpr std::string_view symbol() { return "in³"; }
};
template <> struct UnitTraits<CubicFootTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CUBIC_FOOT; }
  static constexpr std::string_view symbol() { return "ft³"; }
};
template <> struct UnitTraits<UsGallonTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_US_GALLON; }
  static constexpr std::string_view symbol() { return "gal"; }
};
template <> struct UnitTraits<UsFluidOunceTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_US_FLUID_OUNCE; }
  static constexpr std::string_view symbol() { return "fl oz"; }
};

using CubicMeter = Quantity<CubicMeterTag>;
using CubicKilometer = Quantity<CubicKilometerTag>;
using CubicCentimeter = Quantity<CubicCentimeterTag>;
using CubicMillimeter = Quantity<CubicMillimeterTag>;
using Liter = Quantity<LiterTag>;
using Milliliter = Quantity<MilliliterTag>;
using Microliter = Quantity<MicroliterTag>;
using Centiliter = Quantity<CentiliterTag>;
using Deciliter = Quantity<DeciliterTag>;
using CubicInch = Quantity<CubicInchTag>;
using CubicFoot = Quantity<CubicFootTag>;
using UsGallon = Quantity<UsGallonTag>;
using UsFluidOunce = Quantity<UsFluidOunceTag>;

} // namespace qtty
