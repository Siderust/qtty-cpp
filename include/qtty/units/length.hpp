// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct PlanckLengthTag {};
struct YoctometerTag {};
struct ZeptometerTag {};
struct AttometerTag {};
struct FemtometerTag {};
struct PicometerTag {};
struct NanometerTag {};
struct MicrometerTag {};
struct MillimeterTag {};
struct CentimeterTag {};
struct DecimeterTag {};
struct MeterTag {};
struct DecameterTag {};
struct HectometerTag {};
struct KilometerTag {};
struct MegameterTag {};
struct GigameterTag {};
struct TerameterTag {};
struct PetameterTag {};
struct ExameterTag {};
struct ZettameterTag {};
struct YottameterTag {};
struct BohrRadiusTag {};
struct ClassicalElectronRadiusTag {};
struct ElectronReducedComptonWavelengthTag {};
struct AstronomicalUnitTag {};
struct LightYearTag {};
struct ParsecTag {};
struct KiloparsecTag {};
struct MegaparsecTag {};
struct GigaparsecTag {};
struct InchTag {};
struct FootTag {};
struct YardTag {};
struct MileTag {};
struct LinkTag {};
struct FathomTag {};
struct RodTag {};
struct ChainTag {};
struct NauticalMileTag {};
struct NominalLunarRadiusTag {};
struct NominalLunarDistanceTag {};
struct NominalEarthPolarRadiusTag {};
struct NominalEarthRadiusTag {};
struct NominalEarthEquatorialRadiusTag {};
struct EarthMeridionalCircumferenceTag {};
struct EarthEquatorialCircumferenceTag {};
struct NominalJupiterRadiusTag {};
struct NominalSolarRadiusTag {};
struct NominalSolarDiameterTag {};

template <> struct UnitTraits<PlanckLengthTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_PLANCK_LENGTH; }
  static constexpr std::string_view symbol() { return "lp"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<YoctometerTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_YOCTOMETER; }
  static constexpr std::string_view symbol() { return "ym"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<ZeptometerTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ZEPTOMETER; }
  static constexpr std::string_view symbol() { return "zm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<AttometerTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ATTOMETER; }
  static constexpr std::string_view symbol() { return "am"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<FemtometerTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_FEMTOMETER; }
  static constexpr std::string_view symbol() { return "fm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<PicometerTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_PICOMETER; }
  static constexpr std::string_view symbol() { return "pm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<NanometerTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NANOMETER; }
  static constexpr std::string_view symbol() { return "nm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<MicrometerTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROMETER; }
  static constexpr std::string_view symbol() { return "μm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<MillimeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIMETER; }
  static constexpr std::string_view symbol() { return "mm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<CentimeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CENTIMETER; }
  static constexpr std::string_view symbol() { return "cm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<DecimeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_DECIMETER; }
  static constexpr std::string_view symbol() { return "dm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<MeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_METER; }
  static constexpr std::string_view symbol() { return "m"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<DecameterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_DECAMETER; }
  static constexpr std::string_view symbol() { return "dam"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<HectometerTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_HECTOMETER; }
  static constexpr std::string_view symbol() { return "hm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<KilometerTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOMETER; }
  static constexpr std::string_view symbol() { return "km"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<MegameterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MEGAMETER; }
  static constexpr std::string_view symbol() { return "Mm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<GigameterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_GIGAMETER; }
  static constexpr std::string_view symbol() { return "Gm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<TerameterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_TERAMETER; }
  static constexpr std::string_view symbol() { return "Tm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<PetameterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_PETAMETER; }
  static constexpr std::string_view symbol() { return "Pm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<ExameterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_EXAMETER; }
  static constexpr std::string_view symbol() { return "Em"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<ZettameterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ZETTAMETER; }
  static constexpr std::string_view symbol() { return "Zm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<YottameterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_YOTTAMETER; }
  static constexpr std::string_view symbol() { return "Ym"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<BohrRadiusTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_BOHR_RADIUS; }
  static constexpr std::string_view symbol() { return "a0"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<ClassicalElectronRadiusTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CLASSICAL_ELECTRON_RADIUS; }
  static constexpr std::string_view symbol() { return "re"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<ElectronReducedComptonWavelengthTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ELECTRON_REDUCED_COMPTON_WAVELENGTH; }
  static constexpr std::string_view symbol() { return "lambda_bar_e"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<AstronomicalUnitTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ASTRONOMICAL_UNIT; }
  static constexpr std::string_view symbol() { return "au"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<LightYearTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_LIGHT_YEAR; }
  static constexpr std::string_view symbol() { return "ly"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<ParsecTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_PARSEC; }
  static constexpr std::string_view symbol() { return "pc"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<KiloparsecTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOPARSEC; }
  static constexpr std::string_view symbol() { return "kpc"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<MegaparsecTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MEGAPARSEC; }
  static constexpr std::string_view symbol() { return "Mpc"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<GigaparsecTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_GIGAPARSEC; }
  static constexpr std::string_view symbol() { return "Gpc"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<InchTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_INCH; }
  static constexpr std::string_view symbol() { return "in"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<FootTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_FOOT; }
  static constexpr std::string_view symbol() { return "ft"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<YardTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_YARD; }
  static constexpr std::string_view symbol() { return "yd"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<MileTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILE; }
  static constexpr std::string_view symbol() { return "mi"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<LinkTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_LINK; }
  static constexpr std::string_view symbol() { return "lk"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<FathomTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_FATHOM; }
  static constexpr std::string_view symbol() { return "ftm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<RodTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ROD; }
  static constexpr std::string_view symbol() { return "rd"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<ChainTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CHAIN; }
  static constexpr std::string_view symbol() { return "ch"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<NauticalMileTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NAUTICAL_MILE; }
  static constexpr std::string_view symbol() { return "nmi"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<NominalLunarRadiusTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NOMINAL_LUNAR_RADIUS; }
  static constexpr std::string_view symbol() { return "Rmoon"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<NominalLunarDistanceTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NOMINAL_LUNAR_DISTANCE; }
  static constexpr std::string_view symbol() { return "LD"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<NominalEarthPolarRadiusTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NOMINAL_EARTH_POLAR_RADIUS; }
  static constexpr std::string_view symbol() { return "Rearth_p"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<NominalEarthRadiusTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NOMINAL_EARTH_RADIUS; }
  static constexpr std::string_view symbol() { return "Rearth"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<NominalEarthEquatorialRadiusTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NOMINAL_EARTH_EQUATORIAL_RADIUS; }
  static constexpr std::string_view symbol() { return "Rearth_eq"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<EarthMeridionalCircumferenceTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_EARTH_MERIDIONAL_CIRCUMFERENCE; }
  static constexpr std::string_view symbol() { return "Cmer"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<EarthEquatorialCircumferenceTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_EARTH_EQUATORIAL_CIRCUMFERENCE; }
  static constexpr std::string_view symbol() { return "Ceq"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<NominalJupiterRadiusTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NOMINAL_JUPITER_RADIUS; }
  static constexpr std::string_view symbol() { return "Rjup"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<NominalSolarRadiusTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NOMINAL_SOLAR_RADIUS; }
  static constexpr std::string_view symbol() { return "Rsun"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};
template <> struct UnitTraits<NominalSolarDiameterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NOMINAL_SOLAR_DIAMETER; }
  static constexpr std::string_view symbol() { return "Dsun"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LENGTH; }
};

using PlanckLength = Quantity<PlanckLengthTag>;
using Yoctometer = Quantity<YoctometerTag>;
using Zeptometer = Quantity<ZeptometerTag>;
using Attometer = Quantity<AttometerTag>;
using Femtometer = Quantity<FemtometerTag>;
using Picometer = Quantity<PicometerTag>;
using Nanometer = Quantity<NanometerTag>;
using Micrometer = Quantity<MicrometerTag>;
using Millimeter = Quantity<MillimeterTag>;
using Centimeter = Quantity<CentimeterTag>;
using Decimeter = Quantity<DecimeterTag>;
using Meter = Quantity<MeterTag>;
using Decameter = Quantity<DecameterTag>;
using Hectometer = Quantity<HectometerTag>;
using Kilometer = Quantity<KilometerTag>;
using Megameter = Quantity<MegameterTag>;
using Gigameter = Quantity<GigameterTag>;
using Terameter = Quantity<TerameterTag>;
using Petameter = Quantity<PetameterTag>;
using Exameter = Quantity<ExameterTag>;
using Zettameter = Quantity<ZettameterTag>;
using Yottameter = Quantity<YottameterTag>;
using BohrRadius = Quantity<BohrRadiusTag>;
using ClassicalElectronRadius = Quantity<ClassicalElectronRadiusTag>;
using ElectronReducedComptonWavelength = Quantity<ElectronReducedComptonWavelengthTag>;
using AstronomicalUnit = Quantity<AstronomicalUnitTag>;
using LightYear = Quantity<LightYearTag>;
using Parsec = Quantity<ParsecTag>;
using Kiloparsec = Quantity<KiloparsecTag>;
using Megaparsec = Quantity<MegaparsecTag>;
using Gigaparsec = Quantity<GigaparsecTag>;
using Inch = Quantity<InchTag>;
using Foot = Quantity<FootTag>;
using Yard = Quantity<YardTag>;
using Mile = Quantity<MileTag>;
using Link = Quantity<LinkTag>;
using Fathom = Quantity<FathomTag>;
using Rod = Quantity<RodTag>;
using Chain = Quantity<ChainTag>;
using NauticalMile = Quantity<NauticalMileTag>;
using NominalLunarRadius = Quantity<NominalLunarRadiusTag>;
using NominalLunarDistance = Quantity<NominalLunarDistanceTag>;
using NominalEarthPolarRadius = Quantity<NominalEarthPolarRadiusTag>;
using NominalEarthRadius = Quantity<NominalEarthRadiusTag>;
using NominalEarthEquatorialRadius = Quantity<NominalEarthEquatorialRadiusTag>;
using EarthMeridionalCircumference = Quantity<EarthMeridionalCircumferenceTag>;
using EarthEquatorialCircumference = Quantity<EarthEquatorialCircumferenceTag>;
using NominalJupiterRadius = Quantity<NominalJupiterRadiusTag>;
using NominalSolarRadius = Quantity<NominalSolarRadiusTag>;
using NominalSolarDiameter = Quantity<NominalSolarDiameterTag>;

} // namespace qtty
