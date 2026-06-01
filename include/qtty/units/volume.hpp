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
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLUME; }
};
template <> struct UnitTraits<CubicKilometerTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CUBIC_KILOMETER; }
  static constexpr std::string_view symbol() { return "km³"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLUME; }
};
template <> struct UnitTraits<CubicCentimeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CUBIC_CENTIMETER; }
  static constexpr std::string_view symbol() { return "cm³"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLUME; }
};
template <> struct UnitTraits<CubicMillimeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CUBIC_MILLIMETER; }
  static constexpr std::string_view symbol() { return "mm³"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLUME; }
};
template <> struct UnitTraits<LiterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_LITER; }
  static constexpr std::string_view symbol() { return "L"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLUME; }
};
template <> struct UnitTraits<MilliliterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLILITER; }
  static constexpr std::string_view symbol() { return "mL"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLUME; }
};
template <> struct UnitTraits<MicroliterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROLITER; }
  static constexpr std::string_view symbol() { return "µL"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLUME; }
};
template <> struct UnitTraits<CentiliterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CENTILITER; }
  static constexpr std::string_view symbol() { return "cL"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLUME; }
};
template <> struct UnitTraits<DeciliterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_DECILITER; }
  static constexpr std::string_view symbol() { return "dL"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLUME; }
};
template <> struct UnitTraits<CubicInchTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CUBIC_INCH; }
  static constexpr std::string_view symbol() { return "in³"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLUME; }
};
template <> struct UnitTraits<CubicFootTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CUBIC_FOOT; }
  static constexpr std::string_view symbol() { return "ft³"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLUME; }
};
template <> struct UnitTraits<UsGallonTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_US_GALLON; }
  static constexpr std::string_view symbol() { return "gal"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLUME; }
};
template <> struct UnitTraits<UsFluidOunceTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_US_FLUID_OUNCE; }
  static constexpr std::string_view symbol() { return "fl oz"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLUME; }
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
