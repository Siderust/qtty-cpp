// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct YoctogramTag {};
struct ZeptogramTag {};
struct AttogramTag {};
struct FemtogramTag {};
struct PicogramTag {};
struct NanogramTag {};
struct MicrogramTag {};
struct MilligramTag {};
struct CentigramTag {};
struct DecigramTag {};
struct GramTag {};
struct DecagramTag {};
struct HectogramTag {};
struct KilogramTag {};
struct MegagramTag {};
struct GigagramTag {};
struct TeragramTag {};
struct PetagramTag {};
struct ExagramTag {};
struct ZettagramTag {};
struct YottagramTag {};
struct GrainTag {};
struct OunceTag {};
struct PoundTag {};
struct StoneTag {};
struct ShortTonTag {};
struct LongTonTag {};
struct CaratTag {};
struct TonneTag {};
struct AtomicMassUnitTag {};
struct SolarMassTag {};

template <> struct UnitTraits<YoctogramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_YOCTOGRAM; }
  static constexpr std::string_view symbol() { return "yg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<ZeptogramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ZEPTOGRAM; }
  static constexpr std::string_view symbol() { return "zg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<AttogramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ATTOGRAM; }
  static constexpr std::string_view symbol() { return "ag"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<FemtogramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_FEMTOGRAM; }
  static constexpr std::string_view symbol() { return "fg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<PicogramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_PICOGRAM; }
  static constexpr std::string_view symbol() { return "pg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<NanogramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NANOGRAM; }
  static constexpr std::string_view symbol() { return "ng"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<MicrogramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROGRAM; }
  static constexpr std::string_view symbol() { return "µg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<MilligramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIGRAM; }
  static constexpr std::string_view symbol() { return "mg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<CentigramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CENTIGRAM; }
  static constexpr std::string_view symbol() { return "cg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<DecigramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_DECIGRAM; }
  static constexpr std::string_view symbol() { return "dg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<GramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_GRAM; }
  static constexpr std::string_view symbol() { return "g"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<DecagramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_DECAGRAM; }
  static constexpr std::string_view symbol() { return "dag"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<HectogramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_HECTOGRAM; }
  static constexpr std::string_view symbol() { return "hg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<KilogramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOGRAM; }
  static constexpr std::string_view symbol() { return "kg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<MegagramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MEGAGRAM; }
  static constexpr std::string_view symbol() { return "Mg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<GigagramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_GIGAGRAM; }
  static constexpr std::string_view symbol() { return "Gg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<TeragramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_TERAGRAM; }
  static constexpr std::string_view symbol() { return "Tg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<PetagramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_PETAGRAM; }
  static constexpr std::string_view symbol() { return "Pg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<ExagramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_EXAGRAM; }
  static constexpr std::string_view symbol() { return "Eg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<ZettagramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ZETTAGRAM; }
  static constexpr std::string_view symbol() { return "Zg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<YottagramTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_YOTTAGRAM; }
  static constexpr std::string_view symbol() { return "Yg"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<GrainTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_GRAIN; }
  static constexpr std::string_view symbol() { return "gr"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<OunceTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_OUNCE; }
  static constexpr std::string_view symbol() { return "oz"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<PoundTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_POUND; }
  static constexpr std::string_view symbol() { return "lb"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<StoneTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_STONE; }
  static constexpr std::string_view symbol() { return "st"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<ShortTonTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SHORT_TON; }
  static constexpr std::string_view symbol() { return "ton_us"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<LongTonTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_LONG_TON; }
  static constexpr std::string_view symbol() { return "ton_uk"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<CaratTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CARAT; }
  static constexpr std::string_view symbol() { return "ct"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<TonneTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_TONNE; }
  static constexpr std::string_view symbol() { return "t"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<AtomicMassUnitTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ATOMIC_MASS_UNIT; }
  static constexpr std::string_view symbol() { return "u"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};
template <> struct UnitTraits<SolarMassTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SOLAR_MASS; }
  static constexpr std::string_view symbol() { return "M☉"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MASS; }
};

using Yoctogram = Quantity<YoctogramTag>;
using Zeptogram = Quantity<ZeptogramTag>;
using Attogram = Quantity<AttogramTag>;
using Femtogram = Quantity<FemtogramTag>;
using Picogram = Quantity<PicogramTag>;
using Nanogram = Quantity<NanogramTag>;
using Microgram = Quantity<MicrogramTag>;
using Milligram = Quantity<MilligramTag>;
using Centigram = Quantity<CentigramTag>;
using Decigram = Quantity<DecigramTag>;
using Gram = Quantity<GramTag>;
using Decagram = Quantity<DecagramTag>;
using Hectogram = Quantity<HectogramTag>;
using Kilogram = Quantity<KilogramTag>;
using Megagram = Quantity<MegagramTag>;
using Gigagram = Quantity<GigagramTag>;
using Teragram = Quantity<TeragramTag>;
using Petagram = Quantity<PetagramTag>;
using Exagram = Quantity<ExagramTag>;
using Zettagram = Quantity<ZettagramTag>;
using Yottagram = Quantity<YottagramTag>;
using Grain = Quantity<GrainTag>;
using Ounce = Quantity<OunceTag>;
using Pound = Quantity<PoundTag>;
using Stone = Quantity<StoneTag>;
using ShortTon = Quantity<ShortTonTag>;
using LongTon = Quantity<LongTonTag>;
using Carat = Quantity<CaratTag>;
using Tonne = Quantity<TonneTag>;
using AtomicMassUnit = Quantity<AtomicMassUnitTag>;
using SolarMass = Quantity<SolarMassTag>;

} // namespace qtty
