// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct YoctowattTag {};
struct ZeptowattTag {};
struct AttowattTag {};
struct FemtowattTag {};
struct PicowattTag {};
struct NanowattTag {};
struct MicrowattTag {};
struct MilliwattTag {};
struct DeciwattTag {};
struct WattTag {};
struct DecawattTag {};
struct HectowattTag {};
struct KilowattTag {};
struct MegawattTag {};
struct GigawattTag {};
struct TerawattTag {};
struct PetawattTag {};
struct ExawattTag {};
struct ZettawattTag {};
struct YottawattTag {};
struct ErgPerSecondTag {};
struct HorsepowerMetricTag {};
struct HorsepowerElectricTag {};
struct SolarLuminosityTag {};

template <> struct UnitTraits<YoctowattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_YOCTOWATT; }
  static constexpr std::string_view symbol() { return "yW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<ZeptowattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ZEPTOWATT; }
  static constexpr std::string_view symbol() { return "zW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<AttowattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ATTOWATT; }
  static constexpr std::string_view symbol() { return "aW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<FemtowattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_FEMTOWATT; }
  static constexpr std::string_view symbol() { return "fW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<PicowattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_PICOWATT; }
  static constexpr std::string_view symbol() { return "pW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<NanowattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NANOWATT; }
  static constexpr std::string_view symbol() { return "nW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<MicrowattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROWATT; }
  static constexpr std::string_view symbol() { return "µW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<MilliwattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIWATT; }
  static constexpr std::string_view symbol() { return "mW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<DeciwattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_DECIWATT; }
  static constexpr std::string_view symbol() { return "dW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<WattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_WATT; }
  static constexpr std::string_view symbol() { return "W"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<DecawattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_DECAWATT; }
  static constexpr std::string_view symbol() { return "daW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<HectowattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_HECTOWATT; }
  static constexpr std::string_view symbol() { return "hW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<KilowattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOWATT; }
  static constexpr std::string_view symbol() { return "kW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<MegawattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MEGAWATT; }
  static constexpr std::string_view symbol() { return "MW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<GigawattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_GIGAWATT; }
  static constexpr std::string_view symbol() { return "GW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<TerawattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_TERAWATT; }
  static constexpr std::string_view symbol() { return "TW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<PetawattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_PETAWATT; }
  static constexpr std::string_view symbol() { return "PW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<ExawattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_EXAWATT; }
  static constexpr std::string_view symbol() { return "EW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<ZettawattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ZETTAWATT; }
  static constexpr std::string_view symbol() { return "ZW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<YottawattTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_YOTTAWATT; }
  static constexpr std::string_view symbol() { return "YW"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<ErgPerSecondTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ERG_PER_SECOND; }
  static constexpr std::string_view symbol() { return "erg/s"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<HorsepowerMetricTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_HORSEPOWER_METRIC; }
  static constexpr std::string_view symbol() { return "PS"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<HorsepowerElectricTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_HORSEPOWER_ELECTRIC; }
  static constexpr std::string_view symbol() { return "hp_e"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};
template <> struct UnitTraits<SolarLuminosityTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SOLAR_LUMINOSITY; }
  static constexpr std::string_view symbol() { return "L☉"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_POWER; }
};

using Yoctowatt = Quantity<YoctowattTag>;
using Zeptowatt = Quantity<ZeptowattTag>;
using Attowatt = Quantity<AttowattTag>;
using Femtowatt = Quantity<FemtowattTag>;
using Picowatt = Quantity<PicowattTag>;
using Nanowatt = Quantity<NanowattTag>;
using Microwatt = Quantity<MicrowattTag>;
using Milliwatt = Quantity<MilliwattTag>;
using Deciwatt = Quantity<DeciwattTag>;
using Watt = Quantity<WattTag>;
using Decawatt = Quantity<DecawattTag>;
using Hectowatt = Quantity<HectowattTag>;
using Kilowatt = Quantity<KilowattTag>;
using Megawatt = Quantity<MegawattTag>;
using Gigawatt = Quantity<GigawattTag>;
using Terawatt = Quantity<TerawattTag>;
using Petawatt = Quantity<PetawattTag>;
using Exawatt = Quantity<ExawattTag>;
using Zettawatt = Quantity<ZettawattTag>;
using Yottawatt = Quantity<YottawattTag>;
using ErgPerSecond = Quantity<ErgPerSecondTag>;
using HorsepowerMetric = Quantity<HorsepowerMetricTag>;
using HorsepowerElectric = Quantity<HorsepowerElectricTag>;
using SolarLuminosity = Quantity<SolarLuminosityTag>;

} // namespace qtty
