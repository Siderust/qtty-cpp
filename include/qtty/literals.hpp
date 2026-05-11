// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "units/length.hpp"
#include "units/time.hpp"
#include "units/angular.hpp"
#include "units/mass.hpp"
#include "units/power.hpp"
#include "units/area.hpp"
#include "units/volume.hpp"
#include "units/acceleration.hpp"
#include "units/force.hpp"
#include "units/energy.hpp"
#include "units/pressure.hpp"
#include "units/solid_angle.hpp"
#include "units/temperature.hpp"
#include "units/radiance.hpp"
#include "units/spectral_radiance.hpp"
#include "units/photon_radiance.hpp"
#include "units/spectral_photon_radiance.hpp"
#include "units/inverse_solid_angle.hpp"
#include "units/luminous_intensity.hpp"
#include "units/luminous_flux.hpp"
#include "units/illuminance.hpp"
#include "units/frequency.hpp"
#include "units/amount.hpp"
#include "units/current.hpp"
#include "units/charge.hpp"
#include "units/voltage.hpp"
#include "units/resistance.hpp"
#include "units/capacitance.hpp"
#include "units/inductance.hpp"
#include "units/magnetic_flux.hpp"
#include "units/magnetic_flux_density.hpp"
#include "units/density.hpp"
#include "units/dimensionless.hpp"

namespace qtty {

// Inline namespace for user-defined literals
inline namespace literals {

// ====================
// Length literals
// ====================

constexpr PlanckLength operator""_lp(long double value) {
  return PlanckLength(static_cast<double>(value));
}
constexpr PlanckLength operator""_lp(unsigned long long value) {
  return PlanckLength(static_cast<double>(value));
}

constexpr Yoctometer operator""_ym(long double value) {
  return Yoctometer(static_cast<double>(value));
}
constexpr Yoctometer operator""_ym(unsigned long long value) {
  return Yoctometer(static_cast<double>(value));
}

constexpr Zeptometer operator""_zm(long double value) {
  return Zeptometer(static_cast<double>(value));
}
constexpr Zeptometer operator""_zm(unsigned long long value) {
  return Zeptometer(static_cast<double>(value));
}

constexpr Attometer operator""_am(long double value) {
  return Attometer(static_cast<double>(value));
}
constexpr Attometer operator""_am(unsigned long long value) {
  return Attometer(static_cast<double>(value));
}

constexpr Femtometer operator""_fm(long double value) {
  return Femtometer(static_cast<double>(value));
}
constexpr Femtometer operator""_fm(unsigned long long value) {
  return Femtometer(static_cast<double>(value));
}

constexpr Picometer operator""_pm(long double value) {
  return Picometer(static_cast<double>(value));
}
constexpr Picometer operator""_pm(unsigned long long value) {
  return Picometer(static_cast<double>(value));
}

constexpr Nanometer operator""_nm(long double value) {
  return Nanometer(static_cast<double>(value));
}
constexpr Nanometer operator""_nm(unsigned long long value) {
  return Nanometer(static_cast<double>(value));
}

constexpr Micrometer operator""_um(long double value) {
  return Micrometer(static_cast<double>(value));
}
constexpr Micrometer operator""_um(unsigned long long value) {
  return Micrometer(static_cast<double>(value));
}

constexpr Millimeter operator""_mm(long double value) {
  return Millimeter(static_cast<double>(value));
}
constexpr Millimeter operator""_mm(unsigned long long value) {
  return Millimeter(static_cast<double>(value));
}

constexpr Centimeter operator""_cm(long double value) {
  return Centimeter(static_cast<double>(value));
}
constexpr Centimeter operator""_cm(unsigned long long value) {
  return Centimeter(static_cast<double>(value));
}

constexpr Decimeter operator""_dm(long double value) {
  return Decimeter(static_cast<double>(value));
}
constexpr Decimeter operator""_dm(unsigned long long value) {
  return Decimeter(static_cast<double>(value));
}

constexpr Meter operator""_m(long double value) {
  return Meter(static_cast<double>(value));
}
constexpr Meter operator""_m(unsigned long long value) {
  return Meter(static_cast<double>(value));
}

constexpr Decameter operator""_dam(long double value) {
  return Decameter(static_cast<double>(value));
}
constexpr Decameter operator""_dam(unsigned long long value) {
  return Decameter(static_cast<double>(value));
}

constexpr Hectometer operator""_hm(long double value) {
  return Hectometer(static_cast<double>(value));
}
constexpr Hectometer operator""_hm(unsigned long long value) {
  return Hectometer(static_cast<double>(value));
}

constexpr Kilometer operator""_km(long double value) {
  return Kilometer(static_cast<double>(value));
}
constexpr Kilometer operator""_km(unsigned long long value) {
  return Kilometer(static_cast<double>(value));
}

constexpr Megameter operator""_Mm(long double value) {
  return Megameter(static_cast<double>(value));
}
constexpr Megameter operator""_Mm(unsigned long long value) {
  return Megameter(static_cast<double>(value));
}

constexpr Gigameter operator""_Gm(long double value) {
  return Gigameter(static_cast<double>(value));
}
constexpr Gigameter operator""_Gm(unsigned long long value) {
  return Gigameter(static_cast<double>(value));
}

constexpr Terameter operator""_Tm(long double value) {
  return Terameter(static_cast<double>(value));
}
constexpr Terameter operator""_Tm(unsigned long long value) {
  return Terameter(static_cast<double>(value));
}

constexpr Petameter operator""_Pm(long double value) {
  return Petameter(static_cast<double>(value));
}
constexpr Petameter operator""_Pm(unsigned long long value) {
  return Petameter(static_cast<double>(value));
}

constexpr Exameter operator""_Em(long double value) {
  return Exameter(static_cast<double>(value));
}
constexpr Exameter operator""_Em(unsigned long long value) {
  return Exameter(static_cast<double>(value));
}

constexpr Zettameter operator""_Zm(long double value) {
  return Zettameter(static_cast<double>(value));
}
constexpr Zettameter operator""_Zm(unsigned long long value) {
  return Zettameter(static_cast<double>(value));
}

constexpr Yottameter operator""_Ym(long double value) {
  return Yottameter(static_cast<double>(value));
}
constexpr Yottameter operator""_Ym(unsigned long long value) {
  return Yottameter(static_cast<double>(value));
}

constexpr BohrRadius operator""_a0(long double value) {
  return BohrRadius(static_cast<double>(value));
}
constexpr BohrRadius operator""_a0(unsigned long long value) {
  return BohrRadius(static_cast<double>(value));
}

constexpr ClassicalElectronRadius operator""_re(long double value) {
  return ClassicalElectronRadius(static_cast<double>(value));
}
constexpr ClassicalElectronRadius operator""_re(unsigned long long value) {
  return ClassicalElectronRadius(static_cast<double>(value));
}

constexpr ElectronReducedComptonWavelength operator""_lambda_bar_e(long double value) {
  return ElectronReducedComptonWavelength(static_cast<double>(value));
}
constexpr ElectronReducedComptonWavelength operator""_lambda_bar_e(unsigned long long value) {
  return ElectronReducedComptonWavelength(static_cast<double>(value));
}

constexpr AstronomicalUnit operator""_au(long double value) {
  return AstronomicalUnit(static_cast<double>(value));
}
constexpr AstronomicalUnit operator""_au(unsigned long long value) {
  return AstronomicalUnit(static_cast<double>(value));
}

constexpr LightYear operator""_ly(long double value) {
  return LightYear(static_cast<double>(value));
}
constexpr LightYear operator""_ly(unsigned long long value) {
  return LightYear(static_cast<double>(value));
}

constexpr Parsec operator""_pc(long double value) {
  return Parsec(static_cast<double>(value));
}
constexpr Parsec operator""_pc(unsigned long long value) {
  return Parsec(static_cast<double>(value));
}

constexpr Kiloparsec operator""_kpc(long double value) {
  return Kiloparsec(static_cast<double>(value));
}
constexpr Kiloparsec operator""_kpc(unsigned long long value) {
  return Kiloparsec(static_cast<double>(value));
}

constexpr Megaparsec operator""_Mpc(long double value) {
  return Megaparsec(static_cast<double>(value));
}
constexpr Megaparsec operator""_Mpc(unsigned long long value) {
  return Megaparsec(static_cast<double>(value));
}

constexpr Gigaparsec operator""_Gpc(long double value) {
  return Gigaparsec(static_cast<double>(value));
}
constexpr Gigaparsec operator""_Gpc(unsigned long long value) {
  return Gigaparsec(static_cast<double>(value));
}

constexpr Inch operator""_in(long double value) {
  return Inch(static_cast<double>(value));
}
constexpr Inch operator""_in(unsigned long long value) {
  return Inch(static_cast<double>(value));
}

constexpr Foot operator""_ft(long double value) {
  return Foot(static_cast<double>(value));
}
constexpr Foot operator""_ft(unsigned long long value) {
  return Foot(static_cast<double>(value));
}

constexpr Yard operator""_yd(long double value) {
  return Yard(static_cast<double>(value));
}
constexpr Yard operator""_yd(unsigned long long value) {
  return Yard(static_cast<double>(value));
}

constexpr Mile operator""_mi(long double value) {
  return Mile(static_cast<double>(value));
}
constexpr Mile operator""_mi(unsigned long long value) {
  return Mile(static_cast<double>(value));
}

constexpr Link operator""_lk(long double value) {
  return Link(static_cast<double>(value));
}
constexpr Link operator""_lk(unsigned long long value) {
  return Link(static_cast<double>(value));
}

constexpr Fathom operator""_ftm(long double value) {
  return Fathom(static_cast<double>(value));
}
constexpr Fathom operator""_ftm(unsigned long long value) {
  return Fathom(static_cast<double>(value));
}

constexpr Rod operator""_rd(long double value) {
  return Rod(static_cast<double>(value));
}
constexpr Rod operator""_rd(unsigned long long value) {
  return Rod(static_cast<double>(value));
}

constexpr Chain operator""_ch(long double value) {
  return Chain(static_cast<double>(value));
}
constexpr Chain operator""_ch(unsigned long long value) {
  return Chain(static_cast<double>(value));
}

constexpr NauticalMile operator""_nmi(long double value) {
  return NauticalMile(static_cast<double>(value));
}
constexpr NauticalMile operator""_nmi(unsigned long long value) {
  return NauticalMile(static_cast<double>(value));
}

constexpr NominalLunarRadius operator""_Rmoon(long double value) {
  return NominalLunarRadius(static_cast<double>(value));
}
constexpr NominalLunarRadius operator""_Rmoon(unsigned long long value) {
  return NominalLunarRadius(static_cast<double>(value));
}

constexpr NominalLunarDistance operator""_LD(long double value) {
  return NominalLunarDistance(static_cast<double>(value));
}
constexpr NominalLunarDistance operator""_LD(unsigned long long value) {
  return NominalLunarDistance(static_cast<double>(value));
}

constexpr NominalEarthPolarRadius operator""_Rearth_p(long double value) {
  return NominalEarthPolarRadius(static_cast<double>(value));
}
constexpr NominalEarthPolarRadius operator""_Rearth_p(unsigned long long value) {
  return NominalEarthPolarRadius(static_cast<double>(value));
}

constexpr NominalEarthRadius operator""_Rearth(long double value) {
  return NominalEarthRadius(static_cast<double>(value));
}
constexpr NominalEarthRadius operator""_Rearth(unsigned long long value) {
  return NominalEarthRadius(static_cast<double>(value));
}

constexpr NominalEarthEquatorialRadius operator""_Rearth_eq(long double value) {
  return NominalEarthEquatorialRadius(static_cast<double>(value));
}
constexpr NominalEarthEquatorialRadius operator""_Rearth_eq(unsigned long long value) {
  return NominalEarthEquatorialRadius(static_cast<double>(value));
}

constexpr EarthMeridionalCircumference operator""_Cmer(long double value) {
  return EarthMeridionalCircumference(static_cast<double>(value));
}
constexpr EarthMeridionalCircumference operator""_Cmer(unsigned long long value) {
  return EarthMeridionalCircumference(static_cast<double>(value));
}

constexpr EarthEquatorialCircumference operator""_Ceq(long double value) {
  return EarthEquatorialCircumference(static_cast<double>(value));
}
constexpr EarthEquatorialCircumference operator""_Ceq(unsigned long long value) {
  return EarthEquatorialCircumference(static_cast<double>(value));
}

constexpr NominalJupiterRadius operator""_Rjup(long double value) {
  return NominalJupiterRadius(static_cast<double>(value));
}
constexpr NominalJupiterRadius operator""_Rjup(unsigned long long value) {
  return NominalJupiterRadius(static_cast<double>(value));
}

constexpr NominalSolarRadius operator""_Rsun(long double value) {
  return NominalSolarRadius(static_cast<double>(value));
}
constexpr NominalSolarRadius operator""_Rsun(unsigned long long value) {
  return NominalSolarRadius(static_cast<double>(value));
}

constexpr NominalSolarDiameter operator""_Dsun(long double value) {
  return NominalSolarDiameter(static_cast<double>(value));
}
constexpr NominalSolarDiameter operator""_Dsun(unsigned long long value) {
  return NominalSolarDiameter(static_cast<double>(value));
}

// ====================
// Time literals
// ====================

constexpr Attosecond operator""_as(long double value) {
  return Attosecond(static_cast<double>(value));
}
constexpr Attosecond operator""_as(unsigned long long value) {
  return Attosecond(static_cast<double>(value));
}

constexpr Femtosecond operator""_fs(long double value) {
  return Femtosecond(static_cast<double>(value));
}
constexpr Femtosecond operator""_fs(unsigned long long value) {
  return Femtosecond(static_cast<double>(value));
}

constexpr Picosecond operator""_ps(long double value) {
  return Picosecond(static_cast<double>(value));
}
constexpr Picosecond operator""_ps(unsigned long long value) {
  return Picosecond(static_cast<double>(value));
}

constexpr Nanosecond operator""_ns(long double value) {
  return Nanosecond(static_cast<double>(value));
}
constexpr Nanosecond operator""_ns(unsigned long long value) {
  return Nanosecond(static_cast<double>(value));
}

constexpr Microsecond operator""_us(long double value) {
  return Microsecond(static_cast<double>(value));
}
constexpr Microsecond operator""_us(unsigned long long value) {
  return Microsecond(static_cast<double>(value));
}

constexpr Millisecond operator""_ms(long double value) {
  return Millisecond(static_cast<double>(value));
}
constexpr Millisecond operator""_ms(unsigned long long value) {
  return Millisecond(static_cast<double>(value));
}

constexpr Centisecond operator""_cs(long double value) {
  return Centisecond(static_cast<double>(value));
}
constexpr Centisecond operator""_cs(unsigned long long value) {
  return Centisecond(static_cast<double>(value));
}

constexpr Decisecond operator""_ds(long double value) {
  return Decisecond(static_cast<double>(value));
}
constexpr Decisecond operator""_ds(unsigned long long value) {
  return Decisecond(static_cast<double>(value));
}

constexpr Second operator""_s(long double value) {
  return Second(static_cast<double>(value));
}
constexpr Second operator""_s(unsigned long long value) {
  return Second(static_cast<double>(value));
}

constexpr Decasecond operator""_das(long double value) {
  return Decasecond(static_cast<double>(value));
}
constexpr Decasecond operator""_das(unsigned long long value) {
  return Decasecond(static_cast<double>(value));
}

constexpr Hectosecond operator""_hs(long double value) {
  return Hectosecond(static_cast<double>(value));
}
constexpr Hectosecond operator""_hs(unsigned long long value) {
  return Hectosecond(static_cast<double>(value));
}

constexpr Kilosecond operator""_ks(long double value) {
  return Kilosecond(static_cast<double>(value));
}
constexpr Kilosecond operator""_ks(unsigned long long value) {
  return Kilosecond(static_cast<double>(value));
}

constexpr Megasecond operator""_Ms(long double value) {
  return Megasecond(static_cast<double>(value));
}
constexpr Megasecond operator""_Ms(unsigned long long value) {
  return Megasecond(static_cast<double>(value));
}

constexpr Gigasecond operator""_Gs(long double value) {
  return Gigasecond(static_cast<double>(value));
}
constexpr Gigasecond operator""_Gs(unsigned long long value) {
  return Gigasecond(static_cast<double>(value));
}

constexpr Terasecond operator""_Ts(long double value) {
  return Terasecond(static_cast<double>(value));
}
constexpr Terasecond operator""_Ts(unsigned long long value) {
  return Terasecond(static_cast<double>(value));
}

constexpr Minute operator""_min(long double value) {
  return Minute(static_cast<double>(value));
}
constexpr Minute operator""_min(unsigned long long value) {
  return Minute(static_cast<double>(value));
}

constexpr Hour operator""_h(long double value) {
  return Hour(static_cast<double>(value));
}
constexpr Hour operator""_h(unsigned long long value) {
  return Hour(static_cast<double>(value));
}

constexpr Day operator""_d(long double value) {
  return Day(static_cast<double>(value));
}
constexpr Day operator""_d(unsigned long long value) {
  return Day(static_cast<double>(value));
}

constexpr Week operator""_wk(long double value) {
  return Week(static_cast<double>(value));
}
constexpr Week operator""_wk(unsigned long long value) {
  return Week(static_cast<double>(value));
}

constexpr Fortnight operator""_fn(long double value) {
  return Fortnight(static_cast<double>(value));
}
constexpr Fortnight operator""_fn(unsigned long long value) {
  return Fortnight(static_cast<double>(value));
}

constexpr Year operator""_yr(long double value) {
  return Year(static_cast<double>(value));
}
constexpr Year operator""_yr(unsigned long long value) {
  return Year(static_cast<double>(value));
}

constexpr Decade operator""_dec(long double value) {
  return Decade(static_cast<double>(value));
}
constexpr Decade operator""_dec(unsigned long long value) {
  return Decade(static_cast<double>(value));
}

constexpr Century operator""_c(long double value) {
  return Century(static_cast<double>(value));
}
constexpr Century operator""_c(unsigned long long value) {
  return Century(static_cast<double>(value));
}

constexpr Millennium operator""_mill(long double value) {
  return Millennium(static_cast<double>(value));
}
constexpr Millennium operator""_mill(unsigned long long value) {
  return Millennium(static_cast<double>(value));
}

constexpr JulianYear operator""_a(long double value) {
  return JulianYear(static_cast<double>(value));
}
constexpr JulianYear operator""_a(unsigned long long value) {
  return JulianYear(static_cast<double>(value));
}

constexpr JulianCentury operator""_JC(long double value) {
  return JulianCentury(static_cast<double>(value));
}
constexpr JulianCentury operator""_JC(unsigned long long value) {
  return JulianCentury(static_cast<double>(value));
}

constexpr SiderealDay operator""_sd(long double value) {
  return SiderealDay(static_cast<double>(value));
}
constexpr SiderealDay operator""_sd(unsigned long long value) {
  return SiderealDay(static_cast<double>(value));
}

constexpr SynodicMonth operator""_synmo(long double value) {
  return SynodicMonth(static_cast<double>(value));
}
constexpr SynodicMonth operator""_synmo(unsigned long long value) {
  return SynodicMonth(static_cast<double>(value));
}

constexpr SiderealYear operator""_syr(long double value) {
  return SiderealYear(static_cast<double>(value));
}
constexpr SiderealYear operator""_syr(unsigned long long value) {
  return SiderealYear(static_cast<double>(value));
}

// ====================
// Angle literals
// ====================

constexpr Milliradian operator""_mrad(long double value) {
  return Milliradian(static_cast<double>(value));
}
constexpr Milliradian operator""_mrad(unsigned long long value) {
  return Milliradian(static_cast<double>(value));
}

constexpr Radian operator""_rad(long double value) {
  return Radian(static_cast<double>(value));
}
constexpr Radian operator""_rad(unsigned long long value) {
  return Radian(static_cast<double>(value));
}

constexpr MicroArcsecond operator""_uas(long double value) {
  return MicroArcsecond(static_cast<double>(value));
}
constexpr MicroArcsecond operator""_uas(unsigned long long value) {
  return MicroArcsecond(static_cast<double>(value));
}

constexpr MilliArcsecond operator""_mas(long double value) {
  return MilliArcsecond(static_cast<double>(value));
}
constexpr MilliArcsecond operator""_mas(unsigned long long value) {
  return MilliArcsecond(static_cast<double>(value));
}

constexpr Arcsecond operator""_arcsec(long double value) {
  return Arcsecond(static_cast<double>(value));
}
constexpr Arcsecond operator""_arcsec(unsigned long long value) {
  return Arcsecond(static_cast<double>(value));
}

constexpr Arcminute operator""_arcmin(long double value) {
  return Arcminute(static_cast<double>(value));
}
constexpr Arcminute operator""_arcmin(unsigned long long value) {
  return Arcminute(static_cast<double>(value));
}

constexpr Degree operator""_deg(long double value) {
  return Degree(static_cast<double>(value));
}
constexpr Degree operator""_deg(unsigned long long value) {
  return Degree(static_cast<double>(value));
}

constexpr Gradian operator""_gon(long double value) {
  return Gradian(static_cast<double>(value));
}
constexpr Gradian operator""_gon(unsigned long long value) {
  return Gradian(static_cast<double>(value));
}

constexpr Turn operator""_tr(long double value) {
  return Turn(static_cast<double>(value));
}
constexpr Turn operator""_tr(unsigned long long value) {
  return Turn(static_cast<double>(value));
}

// ====================
// Mass literals
// ====================

constexpr Yoctogram operator""_yg(long double value) {
  return Yoctogram(static_cast<double>(value));
}
constexpr Yoctogram operator""_yg(unsigned long long value) {
  return Yoctogram(static_cast<double>(value));
}

constexpr Zeptogram operator""_zg(long double value) {
  return Zeptogram(static_cast<double>(value));
}
constexpr Zeptogram operator""_zg(unsigned long long value) {
  return Zeptogram(static_cast<double>(value));
}

constexpr Attogram operator""_ag(long double value) {
  return Attogram(static_cast<double>(value));
}
constexpr Attogram operator""_ag(unsigned long long value) {
  return Attogram(static_cast<double>(value));
}

constexpr Femtogram operator""_fg(long double value) {
  return Femtogram(static_cast<double>(value));
}
constexpr Femtogram operator""_fg(unsigned long long value) {
  return Femtogram(static_cast<double>(value));
}

constexpr Picogram operator""_pg(long double value) {
  return Picogram(static_cast<double>(value));
}
constexpr Picogram operator""_pg(unsigned long long value) {
  return Picogram(static_cast<double>(value));
}

constexpr Nanogram operator""_ng(long double value) {
  return Nanogram(static_cast<double>(value));
}
constexpr Nanogram operator""_ng(unsigned long long value) {
  return Nanogram(static_cast<double>(value));
}

constexpr Microgram operator""_ug(long double value) {
  return Microgram(static_cast<double>(value));
}
constexpr Microgram operator""_ug(unsigned long long value) {
  return Microgram(static_cast<double>(value));
}

constexpr Milligram operator""_mg(long double value) {
  return Milligram(static_cast<double>(value));
}
constexpr Milligram operator""_mg(unsigned long long value) {
  return Milligram(static_cast<double>(value));
}

constexpr Centigram operator""_cg(long double value) {
  return Centigram(static_cast<double>(value));
}
constexpr Centigram operator""_cg(unsigned long long value) {
  return Centigram(static_cast<double>(value));
}

constexpr Decigram operator""_dg(long double value) {
  return Decigram(static_cast<double>(value));
}
constexpr Decigram operator""_dg(unsigned long long value) {
  return Decigram(static_cast<double>(value));
}

constexpr Gram operator""_g(long double value) {
  return Gram(static_cast<double>(value));
}
constexpr Gram operator""_g(unsigned long long value) {
  return Gram(static_cast<double>(value));
}

constexpr Decagram operator""_dag(long double value) {
  return Decagram(static_cast<double>(value));
}
constexpr Decagram operator""_dag(unsigned long long value) {
  return Decagram(static_cast<double>(value));
}

constexpr Hectogram operator""_hg(long double value) {
  return Hectogram(static_cast<double>(value));
}
constexpr Hectogram operator""_hg(unsigned long long value) {
  return Hectogram(static_cast<double>(value));
}

constexpr Kilogram operator""_kg(long double value) {
  return Kilogram(static_cast<double>(value));
}
constexpr Kilogram operator""_kg(unsigned long long value) {
  return Kilogram(static_cast<double>(value));
}

constexpr Megagram operator""_Mg(long double value) {
  return Megagram(static_cast<double>(value));
}
constexpr Megagram operator""_Mg(unsigned long long value) {
  return Megagram(static_cast<double>(value));
}

constexpr Gigagram operator""_Gg(long double value) {
  return Gigagram(static_cast<double>(value));
}
constexpr Gigagram operator""_Gg(unsigned long long value) {
  return Gigagram(static_cast<double>(value));
}

constexpr Teragram operator""_Tg(long double value) {
  return Teragram(static_cast<double>(value));
}
constexpr Teragram operator""_Tg(unsigned long long value) {
  return Teragram(static_cast<double>(value));
}

constexpr Petagram operator""_Pg(long double value) {
  return Petagram(static_cast<double>(value));
}
constexpr Petagram operator""_Pg(unsigned long long value) {
  return Petagram(static_cast<double>(value));
}

constexpr Exagram operator""_Eg(long double value) {
  return Exagram(static_cast<double>(value));
}
constexpr Exagram operator""_Eg(unsigned long long value) {
  return Exagram(static_cast<double>(value));
}

constexpr Zettagram operator""_Zg(long double value) {
  return Zettagram(static_cast<double>(value));
}
constexpr Zettagram operator""_Zg(unsigned long long value) {
  return Zettagram(static_cast<double>(value));
}

constexpr Yottagram operator""_Yg(long double value) {
  return Yottagram(static_cast<double>(value));
}
constexpr Yottagram operator""_Yg(unsigned long long value) {
  return Yottagram(static_cast<double>(value));
}

constexpr Grain operator""_gr(long double value) {
  return Grain(static_cast<double>(value));
}
constexpr Grain operator""_gr(unsigned long long value) {
  return Grain(static_cast<double>(value));
}

constexpr Ounce operator""_oz(long double value) {
  return Ounce(static_cast<double>(value));
}
constexpr Ounce operator""_oz(unsigned long long value) {
  return Ounce(static_cast<double>(value));
}

constexpr Pound operator""_lb(long double value) {
  return Pound(static_cast<double>(value));
}
constexpr Pound operator""_lb(unsigned long long value) {
  return Pound(static_cast<double>(value));
}

constexpr Stone operator""_st(long double value) {
  return Stone(static_cast<double>(value));
}
constexpr Stone operator""_st(unsigned long long value) {
  return Stone(static_cast<double>(value));
}

constexpr ShortTon operator""_ton_us(long double value) {
  return ShortTon(static_cast<double>(value));
}
constexpr ShortTon operator""_ton_us(unsigned long long value) {
  return ShortTon(static_cast<double>(value));
}

constexpr LongTon operator""_ton_uk(long double value) {
  return LongTon(static_cast<double>(value));
}
constexpr LongTon operator""_ton_uk(unsigned long long value) {
  return LongTon(static_cast<double>(value));
}

constexpr Carat operator""_ct(long double value) {
  return Carat(static_cast<double>(value));
}
constexpr Carat operator""_ct(unsigned long long value) {
  return Carat(static_cast<double>(value));
}

constexpr Tonne operator""_t(long double value) {
  return Tonne(static_cast<double>(value));
}
constexpr Tonne operator""_t(unsigned long long value) {
  return Tonne(static_cast<double>(value));
}

constexpr AtomicMassUnit operator""_u(long double value) {
  return AtomicMassUnit(static_cast<double>(value));
}
constexpr AtomicMassUnit operator""_u(unsigned long long value) {
  return AtomicMassUnit(static_cast<double>(value));
}

constexpr SolarMass operator""_Msol(long double value) {
  return SolarMass(static_cast<double>(value));
}
constexpr SolarMass operator""_Msol(unsigned long long value) {
  return SolarMass(static_cast<double>(value));
}

// ====================
// Power literals
// ====================

constexpr Yoctowatt operator""_yW(long double value) {
  return Yoctowatt(static_cast<double>(value));
}
constexpr Yoctowatt operator""_yW(unsigned long long value) {
  return Yoctowatt(static_cast<double>(value));
}

constexpr Zeptowatt operator""_zW(long double value) {
  return Zeptowatt(static_cast<double>(value));
}
constexpr Zeptowatt operator""_zW(unsigned long long value) {
  return Zeptowatt(static_cast<double>(value));
}

constexpr Attowatt operator""_aW(long double value) {
  return Attowatt(static_cast<double>(value));
}
constexpr Attowatt operator""_aW(unsigned long long value) {
  return Attowatt(static_cast<double>(value));
}

constexpr Femtowatt operator""_fW(long double value) {
  return Femtowatt(static_cast<double>(value));
}
constexpr Femtowatt operator""_fW(unsigned long long value) {
  return Femtowatt(static_cast<double>(value));
}

constexpr Picowatt operator""_pW(long double value) {
  return Picowatt(static_cast<double>(value));
}
constexpr Picowatt operator""_pW(unsigned long long value) {
  return Picowatt(static_cast<double>(value));
}

constexpr Nanowatt operator""_nW(long double value) {
  return Nanowatt(static_cast<double>(value));
}
constexpr Nanowatt operator""_nW(unsigned long long value) {
  return Nanowatt(static_cast<double>(value));
}

constexpr Microwatt operator""_uW(long double value) {
  return Microwatt(static_cast<double>(value));
}
constexpr Microwatt operator""_uW(unsigned long long value) {
  return Microwatt(static_cast<double>(value));
}

constexpr Milliwatt operator""_mW(long double value) {
  return Milliwatt(static_cast<double>(value));
}
constexpr Milliwatt operator""_mW(unsigned long long value) {
  return Milliwatt(static_cast<double>(value));
}

constexpr Deciwatt operator""_dW(long double value) {
  return Deciwatt(static_cast<double>(value));
}
constexpr Deciwatt operator""_dW(unsigned long long value) {
  return Deciwatt(static_cast<double>(value));
}

constexpr Watt operator""_W(long double value) {
  return Watt(static_cast<double>(value));
}
constexpr Watt operator""_W(unsigned long long value) {
  return Watt(static_cast<double>(value));
}

constexpr Decawatt operator""_daW(long double value) {
  return Decawatt(static_cast<double>(value));
}
constexpr Decawatt operator""_daW(unsigned long long value) {
  return Decawatt(static_cast<double>(value));
}

constexpr Hectowatt operator""_hW(long double value) {
  return Hectowatt(static_cast<double>(value));
}
constexpr Hectowatt operator""_hW(unsigned long long value) {
  return Hectowatt(static_cast<double>(value));
}

constexpr Kilowatt operator""_kW(long double value) {
  return Kilowatt(static_cast<double>(value));
}
constexpr Kilowatt operator""_kW(unsigned long long value) {
  return Kilowatt(static_cast<double>(value));
}

constexpr Megawatt operator""_MW(long double value) {
  return Megawatt(static_cast<double>(value));
}
constexpr Megawatt operator""_MW(unsigned long long value) {
  return Megawatt(static_cast<double>(value));
}

constexpr Gigawatt operator""_GW(long double value) {
  return Gigawatt(static_cast<double>(value));
}
constexpr Gigawatt operator""_GW(unsigned long long value) {
  return Gigawatt(static_cast<double>(value));
}

constexpr Terawatt operator""_TW(long double value) {
  return Terawatt(static_cast<double>(value));
}
constexpr Terawatt operator""_TW(unsigned long long value) {
  return Terawatt(static_cast<double>(value));
}

constexpr Petawatt operator""_PW(long double value) {
  return Petawatt(static_cast<double>(value));
}
constexpr Petawatt operator""_PW(unsigned long long value) {
  return Petawatt(static_cast<double>(value));
}

constexpr Exawatt operator""_EW(long double value) {
  return Exawatt(static_cast<double>(value));
}
constexpr Exawatt operator""_EW(unsigned long long value) {
  return Exawatt(static_cast<double>(value));
}

constexpr Zettawatt operator""_ZW(long double value) {
  return Zettawatt(static_cast<double>(value));
}
constexpr Zettawatt operator""_ZW(unsigned long long value) {
  return Zettawatt(static_cast<double>(value));
}

constexpr Yottawatt operator""_YW(long double value) {
  return Yottawatt(static_cast<double>(value));
}
constexpr Yottawatt operator""_YW(unsigned long long value) {
  return Yottawatt(static_cast<double>(value));
}

constexpr ErgPerSecond operator""_erg_per_s(long double value) {
  return ErgPerSecond(static_cast<double>(value));
}
constexpr ErgPerSecond operator""_erg_per_s(unsigned long long value) {
  return ErgPerSecond(static_cast<double>(value));
}

constexpr HorsepowerMetric operator""_PS(long double value) {
  return HorsepowerMetric(static_cast<double>(value));
}
constexpr HorsepowerMetric operator""_PS(unsigned long long value) {
  return HorsepowerMetric(static_cast<double>(value));
}

constexpr HorsepowerElectric operator""_hp_e(long double value) {
  return HorsepowerElectric(static_cast<double>(value));
}
constexpr HorsepowerElectric operator""_hp_e(unsigned long long value) {
  return HorsepowerElectric(static_cast<double>(value));
}

constexpr SolarLuminosity operator""_Lsol(long double value) {
  return SolarLuminosity(static_cast<double>(value));
}
constexpr SolarLuminosity operator""_Lsol(unsigned long long value) {
  return SolarLuminosity(static_cast<double>(value));
}

// ====================
// Area literals
// ====================

constexpr Hectare operator""_ha(long double value) {
  return Hectare(static_cast<double>(value));
}
constexpr Hectare operator""_ha(unsigned long long value) {
  return Hectare(static_cast<double>(value));
}

constexpr Acre operator""_ac(long double value) {
  return Acre(static_cast<double>(value));
}
constexpr Acre operator""_ac(unsigned long long value) {
  return Acre(static_cast<double>(value));
}

// ====================
// Volume literals
// ====================

constexpr Liter operator""_L(long double value) {
  return Liter(static_cast<double>(value));
}
constexpr Liter operator""_L(unsigned long long value) {
  return Liter(static_cast<double>(value));
}

constexpr Milliliter operator""_mL(long double value) {
  return Milliliter(static_cast<double>(value));
}
constexpr Milliliter operator""_mL(unsigned long long value) {
  return Milliliter(static_cast<double>(value));
}

constexpr Microliter operator""_uL(long double value) {
  return Microliter(static_cast<double>(value));
}
constexpr Microliter operator""_uL(unsigned long long value) {
  return Microliter(static_cast<double>(value));
}

constexpr Centiliter operator""_cL(long double value) {
  return Centiliter(static_cast<double>(value));
}
constexpr Centiliter operator""_cL(unsigned long long value) {
  return Centiliter(static_cast<double>(value));
}

constexpr Deciliter operator""_dL(long double value) {
  return Deciliter(static_cast<double>(value));
}
constexpr Deciliter operator""_dL(unsigned long long value) {
  return Deciliter(static_cast<double>(value));
}

constexpr UsGallon operator""_gal(long double value) {
  return UsGallon(static_cast<double>(value));
}
constexpr UsGallon operator""_gal(unsigned long long value) {
  return UsGallon(static_cast<double>(value));
}

constexpr UsFluidOunce operator""_fl_oz(long double value) {
  return UsFluidOunce(static_cast<double>(value));
}
constexpr UsFluidOunce operator""_fl_oz(unsigned long long value) {
  return UsFluidOunce(static_cast<double>(value));
}

// ====================
// Acceleration literals
// ====================

constexpr MeterPerSecondSquared operator""_m_per_s(long double value) {
  return MeterPerSecondSquared(static_cast<double>(value));
}
constexpr MeterPerSecondSquared operator""_m_per_s(unsigned long long value) {
  return MeterPerSecondSquared(static_cast<double>(value));
}

// ====================
// Force literals
// ====================

constexpr Newton operator""_N(long double value) {
  return Newton(static_cast<double>(value));
}
constexpr Newton operator""_N(unsigned long long value) {
  return Newton(static_cast<double>(value));
}

constexpr Micronewton operator""_uN(long double value) {
  return Micronewton(static_cast<double>(value));
}
constexpr Micronewton operator""_uN(unsigned long long value) {
  return Micronewton(static_cast<double>(value));
}

constexpr Millinewton operator""_mN(long double value) {
  return Millinewton(static_cast<double>(value));
}
constexpr Millinewton operator""_mN(unsigned long long value) {
  return Millinewton(static_cast<double>(value));
}

constexpr Kilonewton operator""_kN(long double value) {
  return Kilonewton(static_cast<double>(value));
}
constexpr Kilonewton operator""_kN(unsigned long long value) {
  return Kilonewton(static_cast<double>(value));
}

constexpr Meganewton operator""_MN(long double value) {
  return Meganewton(static_cast<double>(value));
}
constexpr Meganewton operator""_MN(unsigned long long value) {
  return Meganewton(static_cast<double>(value));
}

constexpr Giganewton operator""_GN(long double value) {
  return Giganewton(static_cast<double>(value));
}
constexpr Giganewton operator""_GN(unsigned long long value) {
  return Giganewton(static_cast<double>(value));
}

constexpr Dyne operator""_dyn(long double value) {
  return Dyne(static_cast<double>(value));
}
constexpr Dyne operator""_dyn(unsigned long long value) {
  return Dyne(static_cast<double>(value));
}

constexpr PoundForce operator""_lbf(long double value) {
  return PoundForce(static_cast<double>(value));
}
constexpr PoundForce operator""_lbf(unsigned long long value) {
  return PoundForce(static_cast<double>(value));
}

// ====================
// Energy literals
// ====================

constexpr Joule operator""_J(long double value) {
  return Joule(static_cast<double>(value));
}
constexpr Joule operator""_J(unsigned long long value) {
  return Joule(static_cast<double>(value));
}

constexpr Picojoule operator""_pJ(long double value) {
  return Picojoule(static_cast<double>(value));
}
constexpr Picojoule operator""_pJ(unsigned long long value) {
  return Picojoule(static_cast<double>(value));
}

constexpr Nanojoule operator""_nJ(long double value) {
  return Nanojoule(static_cast<double>(value));
}
constexpr Nanojoule operator""_nJ(unsigned long long value) {
  return Nanojoule(static_cast<double>(value));
}

constexpr Microjoule operator""_uJ(long double value) {
  return Microjoule(static_cast<double>(value));
}
constexpr Microjoule operator""_uJ(unsigned long long value) {
  return Microjoule(static_cast<double>(value));
}

constexpr Millijoule operator""_mJ(long double value) {
  return Millijoule(static_cast<double>(value));
}
constexpr Millijoule operator""_mJ(unsigned long long value) {
  return Millijoule(static_cast<double>(value));
}

constexpr Kilojoule operator""_kJ(long double value) {
  return Kilojoule(static_cast<double>(value));
}
constexpr Kilojoule operator""_kJ(unsigned long long value) {
  return Kilojoule(static_cast<double>(value));
}

constexpr Megajoule operator""_MJ(long double value) {
  return Megajoule(static_cast<double>(value));
}
constexpr Megajoule operator""_MJ(unsigned long long value) {
  return Megajoule(static_cast<double>(value));
}

constexpr Gigajoule operator""_GJ(long double value) {
  return Gigajoule(static_cast<double>(value));
}
constexpr Gigajoule operator""_GJ(unsigned long long value) {
  return Gigajoule(static_cast<double>(value));
}

constexpr Terajoule operator""_TJ(long double value) {
  return Terajoule(static_cast<double>(value));
}
constexpr Terajoule operator""_TJ(unsigned long long value) {
  return Terajoule(static_cast<double>(value));
}

constexpr WattHour operator""_Wh(long double value) {
  return WattHour(static_cast<double>(value));
}
constexpr WattHour operator""_Wh(unsigned long long value) {
  return WattHour(static_cast<double>(value));
}

constexpr KilowattHour operator""_kWh(long double value) {
  return KilowattHour(static_cast<double>(value));
}
constexpr KilowattHour operator""_kWh(unsigned long long value) {
  return KilowattHour(static_cast<double>(value));
}

constexpr Erg operator""_erg(long double value) {
  return Erg(static_cast<double>(value));
}
constexpr Erg operator""_erg(unsigned long long value) {
  return Erg(static_cast<double>(value));
}

constexpr Electronvolt operator""_eV(long double value) {
  return Electronvolt(static_cast<double>(value));
}
constexpr Electronvolt operator""_eV(unsigned long long value) {
  return Electronvolt(static_cast<double>(value));
}

constexpr Kiloelectronvolt operator""_keV(long double value) {
  return Kiloelectronvolt(static_cast<double>(value));
}
constexpr Kiloelectronvolt operator""_keV(unsigned long long value) {
  return Kiloelectronvolt(static_cast<double>(value));
}

constexpr Megaelectronvolt operator""_MeV(long double value) {
  return Megaelectronvolt(static_cast<double>(value));
}
constexpr Megaelectronvolt operator""_MeV(unsigned long long value) {
  return Megaelectronvolt(static_cast<double>(value));
}

constexpr Calorie operator""_cal(long double value) {
  return Calorie(static_cast<double>(value));
}
constexpr Calorie operator""_cal(unsigned long long value) {
  return Calorie(static_cast<double>(value));
}

constexpr Kilocalorie operator""_kcal(long double value) {
  return Kilocalorie(static_cast<double>(value));
}
constexpr Kilocalorie operator""_kcal(unsigned long long value) {
  return Kilocalorie(static_cast<double>(value));
}

constexpr BritishThermalUnit operator""_BTU(long double value) {
  return BritishThermalUnit(static_cast<double>(value));
}
constexpr BritishThermalUnit operator""_BTU(unsigned long long value) {
  return BritishThermalUnit(static_cast<double>(value));
}

constexpr Therm operator""_therm(long double value) {
  return Therm(static_cast<double>(value));
}
constexpr Therm operator""_therm(unsigned long long value) {
  return Therm(static_cast<double>(value));
}

// ====================
// Pressure literals
// ====================

constexpr Pascal operator""_Pa(long double value) {
  return Pascal(static_cast<double>(value));
}
constexpr Pascal operator""_Pa(unsigned long long value) {
  return Pascal(static_cast<double>(value));
}

constexpr Millipascal operator""_mPa(long double value) {
  return Millipascal(static_cast<double>(value));
}
constexpr Millipascal operator""_mPa(unsigned long long value) {
  return Millipascal(static_cast<double>(value));
}

constexpr Hectopascal operator""_hPa(long double value) {
  return Hectopascal(static_cast<double>(value));
}
constexpr Hectopascal operator""_hPa(unsigned long long value) {
  return Hectopascal(static_cast<double>(value));
}

constexpr Kilopascal operator""_kPa(long double value) {
  return Kilopascal(static_cast<double>(value));
}
constexpr Kilopascal operator""_kPa(unsigned long long value) {
  return Kilopascal(static_cast<double>(value));
}

constexpr Megapascal operator""_MPa(long double value) {
  return Megapascal(static_cast<double>(value));
}
constexpr Megapascal operator""_MPa(unsigned long long value) {
  return Megapascal(static_cast<double>(value));
}

constexpr Gigapascal operator""_GPa(long double value) {
  return Gigapascal(static_cast<double>(value));
}
constexpr Gigapascal operator""_GPa(unsigned long long value) {
  return Gigapascal(static_cast<double>(value));
}

constexpr Bar operator""_bar(long double value) {
  return Bar(static_cast<double>(value));
}
constexpr Bar operator""_bar(unsigned long long value) {
  return Bar(static_cast<double>(value));
}

constexpr Atmosphere operator""_atm(long double value) {
  return Atmosphere(static_cast<double>(value));
}
constexpr Atmosphere operator""_atm(unsigned long long value) {
  return Atmosphere(static_cast<double>(value));
}

constexpr Torr operator""_Torr(long double value) {
  return Torr(static_cast<double>(value));
}
constexpr Torr operator""_Torr(unsigned long long value) {
  return Torr(static_cast<double>(value));
}

constexpr MillimeterOfMercury operator""_mmHg(long double value) {
  return MillimeterOfMercury(static_cast<double>(value));
}
constexpr MillimeterOfMercury operator""_mmHg(unsigned long long value) {
  return MillimeterOfMercury(static_cast<double>(value));
}

constexpr PoundPerSquareInch operator""_psi(long double value) {
  return PoundPerSquareInch(static_cast<double>(value));
}
constexpr PoundPerSquareInch operator""_psi(unsigned long long value) {
  return PoundPerSquareInch(static_cast<double>(value));
}

constexpr InchOfMercury operator""_inHg(long double value) {
  return InchOfMercury(static_cast<double>(value));
}
constexpr InchOfMercury operator""_inHg(unsigned long long value) {
  return InchOfMercury(static_cast<double>(value));
}

// ====================
// Temperature literals
// ====================

constexpr Kelvin operator""_K(long double value) {
  return Kelvin(static_cast<double>(value));
}
constexpr Kelvin operator""_K(unsigned long long value) {
  return Kelvin(static_cast<double>(value));
}

constexpr Rankine operator""_degR(long double value) {
  return Rankine(static_cast<double>(value));
}
constexpr Rankine operator""_degR(unsigned long long value) {
  return Rankine(static_cast<double>(value));
}

// ====================
// Radiance literals
// ====================

constexpr WattPerSquareMeterSteradian operator""_Wmsr(long double value) {
  return WattPerSquareMeterSteradian(static_cast<double>(value));
}
constexpr WattPerSquareMeterSteradian operator""_Wmsr(unsigned long long value) {
  return WattPerSquareMeterSteradian(static_cast<double>(value));
}

constexpr ErgPerSecondSquareCentimeterSteradian operator""_ergscmsr(long double value) {
  return ErgPerSecondSquareCentimeterSteradian(static_cast<double>(value));
}
constexpr ErgPerSecondSquareCentimeterSteradian operator""_ergscmsr(unsigned long long value) {
  return ErgPerSecondSquareCentimeterSteradian(static_cast<double>(value));
}

// ====================
// SpectralRadiance literals
// ====================

constexpr WattPerSquareMeterSteradianMeter operator""_Wmsrm(long double value) {
  return WattPerSquareMeterSteradianMeter(static_cast<double>(value));
}
constexpr WattPerSquareMeterSteradianMeter operator""_Wmsrm(unsigned long long value) {
  return WattPerSquareMeterSteradianMeter(static_cast<double>(value));
}

constexpr WattPerSquareMeterSteradianNanometer operator""_Wmsrnm(long double value) {
  return WattPerSquareMeterSteradianNanometer(static_cast<double>(value));
}
constexpr WattPerSquareMeterSteradianNanometer operator""_Wmsrnm(unsigned long long value) {
  return WattPerSquareMeterSteradianNanometer(static_cast<double>(value));
}

// ====================
// PhotonRadiance literals
// ====================

constexpr PhotonPerSquareMeterSecondSteradian operator""_phmssr(long double value) {
  return PhotonPerSquareMeterSecondSteradian(static_cast<double>(value));
}
constexpr PhotonPerSquareMeterSecondSteradian operator""_phmssr(unsigned long long value) {
  return PhotonPerSquareMeterSecondSteradian(static_cast<double>(value));
}

constexpr PhotonPerSquareCentimeterSecondSteradian operator""_phcmssr(long double value) {
  return PhotonPerSquareCentimeterSecondSteradian(static_cast<double>(value));
}
constexpr PhotonPerSquareCentimeterSecondSteradian operator""_phcmssr(unsigned long long value) {
  return PhotonPerSquareCentimeterSecondSteradian(static_cast<double>(value));
}

constexpr PhotonPerSquareCentimeterNanosecondSteradian operator""_phcmnssr(long double value) {
  return PhotonPerSquareCentimeterNanosecondSteradian(static_cast<double>(value));
}
constexpr PhotonPerSquareCentimeterNanosecondSteradian operator""_phcmnssr(unsigned long long value) {
  return PhotonPerSquareCentimeterNanosecondSteradian(static_cast<double>(value));
}

// ====================
// SpectralPhotonRadiance literals
// ====================

constexpr PhotonPerSquareMeterSecondSteradianMeter operator""_phmssrm(long double value) {
  return PhotonPerSquareMeterSecondSteradianMeter(static_cast<double>(value));
}
constexpr PhotonPerSquareMeterSecondSteradianMeter operator""_phmssrm(unsigned long long value) {
  return PhotonPerSquareMeterSecondSteradianMeter(static_cast<double>(value));
}

constexpr PhotonPerSquareCentimeterSecondSteradianNanometer operator""_phcmssrnm(long double value) {
  return PhotonPerSquareCentimeterSecondSteradianNanometer(static_cast<double>(value));
}
constexpr PhotonPerSquareCentimeterSecondSteradianNanometer operator""_phcmssrnm(unsigned long long value) {
  return PhotonPerSquareCentimeterSecondSteradianNanometer(static_cast<double>(value));
}

constexpr PhotonPerSquareCentimeterNanosecondSteradianNanometer operator""_phcmnssrnm(long double value) {
  return PhotonPerSquareCentimeterNanosecondSteradianNanometer(static_cast<double>(value));
}
constexpr PhotonPerSquareCentimeterNanosecondSteradianNanometer operator""_phcmnssrnm(unsigned long long value) {
  return PhotonPerSquareCentimeterNanosecondSteradianNanometer(static_cast<double>(value));
}

// ====================
// InverseSolidAngle literals
// ====================

constexpr S10 operator""_S10(long double value) {
  return S10(static_cast<double>(value));
}
constexpr S10 operator""_S10(unsigned long long value) {
  return S10(static_cast<double>(value));
}

// ====================
// LuminousIntensity literals
// ====================

constexpr Candela operator""_cd(long double value) {
  return Candela(static_cast<double>(value));
}
constexpr Candela operator""_cd(unsigned long long value) {
  return Candela(static_cast<double>(value));
}

// ====================
// LuminousFlux literals
// ====================

constexpr Lumen operator""_lm(long double value) {
  return Lumen(static_cast<double>(value));
}
constexpr Lumen operator""_lm(unsigned long long value) {
  return Lumen(static_cast<double>(value));
}

constexpr Millilumen operator""_mlm(long double value) {
  return Millilumen(static_cast<double>(value));
}
constexpr Millilumen operator""_mlm(unsigned long long value) {
  return Millilumen(static_cast<double>(value));
}

constexpr Kilolumen operator""_klm(long double value) {
  return Kilolumen(static_cast<double>(value));
}
constexpr Kilolumen operator""_klm(unsigned long long value) {
  return Kilolumen(static_cast<double>(value));
}

// ====================
// Illuminance literals
// ====================

constexpr Lux operator""_lx(long double value) {
  return Lux(static_cast<double>(value));
}
constexpr Lux operator""_lx(unsigned long long value) {
  return Lux(static_cast<double>(value));
}

constexpr Millilux operator""_mlx(long double value) {
  return Millilux(static_cast<double>(value));
}
constexpr Millilux operator""_mlx(unsigned long long value) {
  return Millilux(static_cast<double>(value));
}

constexpr Kilolux operator""_klx(long double value) {
  return Kilolux(static_cast<double>(value));
}
constexpr Kilolux operator""_klx(unsigned long long value) {
  return Kilolux(static_cast<double>(value));
}

// ====================
// Frequency literals
// ====================

constexpr Hertz operator""_Hz(long double value) {
  return Hertz(static_cast<double>(value));
}
constexpr Hertz operator""_Hz(unsigned long long value) {
  return Hertz(static_cast<double>(value));
}

constexpr Millihertz operator""_mHz(long double value) {
  return Millihertz(static_cast<double>(value));
}
constexpr Millihertz operator""_mHz(unsigned long long value) {
  return Millihertz(static_cast<double>(value));
}

constexpr Kilohertz operator""_kHz(long double value) {
  return Kilohertz(static_cast<double>(value));
}
constexpr Kilohertz operator""_kHz(unsigned long long value) {
  return Kilohertz(static_cast<double>(value));
}

constexpr Megahertz operator""_MHz(long double value) {
  return Megahertz(static_cast<double>(value));
}
constexpr Megahertz operator""_MHz(unsigned long long value) {
  return Megahertz(static_cast<double>(value));
}

constexpr Gigahertz operator""_GHz(long double value) {
  return Gigahertz(static_cast<double>(value));
}
constexpr Gigahertz operator""_GHz(unsigned long long value) {
  return Gigahertz(static_cast<double>(value));
}

constexpr Terahertz operator""_THz(long double value) {
  return Terahertz(static_cast<double>(value));
}
constexpr Terahertz operator""_THz(unsigned long long value) {
  return Terahertz(static_cast<double>(value));
}

// ====================
// AmountOfSubstance literals
// ====================

constexpr Mole operator""_mol(long double value) {
  return Mole(static_cast<double>(value));
}
constexpr Mole operator""_mol(unsigned long long value) {
  return Mole(static_cast<double>(value));
}

constexpr Nanomole operator""_nmol(long double value) {
  return Nanomole(static_cast<double>(value));
}
constexpr Nanomole operator""_nmol(unsigned long long value) {
  return Nanomole(static_cast<double>(value));
}

constexpr Micromole operator""_umol(long double value) {
  return Micromole(static_cast<double>(value));
}
constexpr Micromole operator""_umol(unsigned long long value) {
  return Micromole(static_cast<double>(value));
}

constexpr Millimole operator""_mmol(long double value) {
  return Millimole(static_cast<double>(value));
}
constexpr Millimole operator""_mmol(unsigned long long value) {
  return Millimole(static_cast<double>(value));
}

constexpr Kilomole operator""_kmol(long double value) {
  return Kilomole(static_cast<double>(value));
}
constexpr Kilomole operator""_kmol(unsigned long long value) {
  return Kilomole(static_cast<double>(value));
}

// ====================
// Current literals
// ====================

constexpr Ampere operator""_A(long double value) {
  return Ampere(static_cast<double>(value));
}
constexpr Ampere operator""_A(unsigned long long value) {
  return Ampere(static_cast<double>(value));
}

constexpr Microampere operator""_uA(long double value) {
  return Microampere(static_cast<double>(value));
}
constexpr Microampere operator""_uA(unsigned long long value) {
  return Microampere(static_cast<double>(value));
}

constexpr Milliampere operator""_mA(long double value) {
  return Milliampere(static_cast<double>(value));
}
constexpr Milliampere operator""_mA(unsigned long long value) {
  return Milliampere(static_cast<double>(value));
}

constexpr Kiloampere operator""_kA(long double value) {
  return Kiloampere(static_cast<double>(value));
}
constexpr Kiloampere operator""_kA(unsigned long long value) {
  return Kiloampere(static_cast<double>(value));
}

// ====================
// Charge literals
// ====================

constexpr Coulomb operator""_C(long double value) {
  return Coulomb(static_cast<double>(value));
}
constexpr Coulomb operator""_C(unsigned long long value) {
  return Coulomb(static_cast<double>(value));
}

constexpr Millicoulomb operator""_mC(long double value) {
  return Millicoulomb(static_cast<double>(value));
}
constexpr Millicoulomb operator""_mC(unsigned long long value) {
  return Millicoulomb(static_cast<double>(value));
}

constexpr Microcoulomb operator""_uC(long double value) {
  return Microcoulomb(static_cast<double>(value));
}
constexpr Microcoulomb operator""_uC(unsigned long long value) {
  return Microcoulomb(static_cast<double>(value));
}

constexpr Kilocoulomb operator""_kC(long double value) {
  return Kilocoulomb(static_cast<double>(value));
}
constexpr Kilocoulomb operator""_kC(unsigned long long value) {
  return Kilocoulomb(static_cast<double>(value));
}

// ====================
// Voltage literals
// ====================

constexpr Volt operator""_V(long double value) {
  return Volt(static_cast<double>(value));
}
constexpr Volt operator""_V(unsigned long long value) {
  return Volt(static_cast<double>(value));
}

constexpr Microvolt operator""_uV(long double value) {
  return Microvolt(static_cast<double>(value));
}
constexpr Microvolt operator""_uV(unsigned long long value) {
  return Microvolt(static_cast<double>(value));
}

constexpr Millivolt operator""_mV(long double value) {
  return Millivolt(static_cast<double>(value));
}
constexpr Millivolt operator""_mV(unsigned long long value) {
  return Millivolt(static_cast<double>(value));
}

constexpr Kilovolt operator""_kV(long double value) {
  return Kilovolt(static_cast<double>(value));
}
constexpr Kilovolt operator""_kV(unsigned long long value) {
  return Kilovolt(static_cast<double>(value));
}

constexpr Megavolt operator""_MV(long double value) {
  return Megavolt(static_cast<double>(value));
}
constexpr Megavolt operator""_MV(unsigned long long value) {
  return Megavolt(static_cast<double>(value));
}

// ====================
// Resistance literals
// ====================

constexpr Kilohm operator""_k(long double value) {
  return Kilohm(static_cast<double>(value));
}
constexpr Kilohm operator""_k(unsigned long long value) {
  return Kilohm(static_cast<double>(value));
}

constexpr Megaohm operator""_M(long double value) {
  return Megaohm(static_cast<double>(value));
}
constexpr Megaohm operator""_M(unsigned long long value) {
  return Megaohm(static_cast<double>(value));
}

// ====================
// Capacitance literals
// ====================

constexpr Farad operator""_F(long double value) {
  return Farad(static_cast<double>(value));
}
constexpr Farad operator""_F(unsigned long long value) {
  return Farad(static_cast<double>(value));
}

constexpr Picofarad operator""_pF(long double value) {
  return Picofarad(static_cast<double>(value));
}
constexpr Picofarad operator""_pF(unsigned long long value) {
  return Picofarad(static_cast<double>(value));
}

constexpr Nanofarad operator""_nF(long double value) {
  return Nanofarad(static_cast<double>(value));
}
constexpr Nanofarad operator""_nF(unsigned long long value) {
  return Nanofarad(static_cast<double>(value));
}

constexpr Microfarad operator""_uF(long double value) {
  return Microfarad(static_cast<double>(value));
}
constexpr Microfarad operator""_uF(unsigned long long value) {
  return Microfarad(static_cast<double>(value));
}

constexpr Millifarad operator""_mF(long double value) {
  return Millifarad(static_cast<double>(value));
}
constexpr Millifarad operator""_mF(unsigned long long value) {
  return Millifarad(static_cast<double>(value));
}

// ====================
// Inductance literals
// ====================

constexpr Henry operator""_H(long double value) {
  return Henry(static_cast<double>(value));
}
constexpr Henry operator""_H(unsigned long long value) {
  return Henry(static_cast<double>(value));
}

constexpr Microhenry operator""_uH(long double value) {
  return Microhenry(static_cast<double>(value));
}
constexpr Microhenry operator""_uH(unsigned long long value) {
  return Microhenry(static_cast<double>(value));
}

constexpr Millihenry operator""_mH(long double value) {
  return Millihenry(static_cast<double>(value));
}
constexpr Millihenry operator""_mH(unsigned long long value) {
  return Millihenry(static_cast<double>(value));
}

// ====================
// MagneticFlux literals
// ====================

constexpr Weber operator""_Wb(long double value) {
  return Weber(static_cast<double>(value));
}
constexpr Weber operator""_Wb(unsigned long long value) {
  return Weber(static_cast<double>(value));
}

constexpr Milliweber operator""_mWb(long double value) {
  return Milliweber(static_cast<double>(value));
}
constexpr Milliweber operator""_mWb(unsigned long long value) {
  return Milliweber(static_cast<double>(value));
}

// ====================
// MagneticFluxDensity literals
// ====================

constexpr Tesla operator""_T(long double value) {
  return Tesla(static_cast<double>(value));
}
constexpr Tesla operator""_T(unsigned long long value) {
  return Tesla(static_cast<double>(value));
}

constexpr Millitesla operator""_mT(long double value) {
  return Millitesla(static_cast<double>(value));
}
constexpr Millitesla operator""_mT(unsigned long long value) {
  return Millitesla(static_cast<double>(value));
}

constexpr Microtesla operator""_uT(long double value) {
  return Microtesla(static_cast<double>(value));
}
constexpr Microtesla operator""_uT(unsigned long long value) {
  return Microtesla(static_cast<double>(value));
}

// ====================
// Density literals
// ====================

constexpr KilogramPerCubicMeter operator""_kg_per_m(long double value) {
  return KilogramPerCubicMeter(static_cast<double>(value));
}
constexpr KilogramPerCubicMeter operator""_kg_per_m(unsigned long long value) {
  return KilogramPerCubicMeter(static_cast<double>(value));
}

constexpr GramPerCubicCentimeter operator""_g_per_cm(long double value) {
  return GramPerCubicCentimeter(static_cast<double>(value));
}
constexpr GramPerCubicCentimeter operator""_g_per_cm(unsigned long long value) {
  return GramPerCubicCentimeter(static_cast<double>(value));
}

constexpr GramPerMilliliter operator""_g_per_mL(long double value) {
  return GramPerMilliliter(static_cast<double>(value));
}
constexpr GramPerMilliliter operator""_g_per_mL(unsigned long long value) {
  return GramPerMilliliter(static_cast<double>(value));
}

constexpr PoundPerCubicFoot operator""_lb_per_ft(long double value) {
  return PoundPerCubicFoot(static_cast<double>(value));
}
constexpr PoundPerCubicFoot operator""_lb_per_ft(unsigned long long value) {
  return PoundPerCubicFoot(static_cast<double>(value));
}

} // namespace literals

} // namespace qtty
