// SPDX-License-Identifier: AGPL-3.0-or-later
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "units/length.hpp"
#include "units/time.hpp"
#include "units/angular.hpp"
#include "units/mass.hpp"
#include "units/power.hpp"

namespace qtty {

// Inline namespace for user-defined literals
inline namespace literals {

// ====================
// Length literals
// ====================


constexpr PlanckLength operator""_l_P(long double value) {
    return PlanckLength(static_cast<double>(value));
}
constexpr PlanckLength operator""_l_P(unsigned long long value) {
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

constexpr BohrRadius operator""_a(long double value) {
    return BohrRadius(static_cast<double>(value));
}
constexpr BohrRadius operator""_a(unsigned long long value) {
    return BohrRadius(static_cast<double>(value));
}

constexpr ClassicalElectronRadius operator""_r_e(long double value) {
    return ClassicalElectronRadius(static_cast<double>(value));
}
constexpr ClassicalElectronRadius operator""_r_e(unsigned long long value) {
    return ClassicalElectronRadius(static_cast<double>(value));
}

constexpr ElectronReducedComptonWavelength operator""__e(long double value) {
    return ElectronReducedComptonWavelength(static_cast<double>(value));
}
constexpr ElectronReducedComptonWavelength operator""__e(unsigned long long value) {
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

constexpr NominalLunarRadius operator""_R_moon(long double value) {
    return NominalLunarRadius(static_cast<double>(value));
}
constexpr NominalLunarRadius operator""_R_moon(unsigned long long value) {
    return NominalLunarRadius(static_cast<double>(value));
}

constexpr NominalLunarDistance operator""_LD(long double value) {
    return NominalLunarDistance(static_cast<double>(value));
}
constexpr NominalLunarDistance operator""_LD(unsigned long long value) {
    return NominalLunarDistance(static_cast<double>(value));
}

constexpr NominalEarthPolarRadius operator""_R_earthpol(long double value) {
    return NominalEarthPolarRadius(static_cast<double>(value));
}
constexpr NominalEarthPolarRadius operator""_R_earthpol(unsigned long long value) {
    return NominalEarthPolarRadius(static_cast<double>(value));
}

constexpr NominalEarthRadius operator""_R_earth(long double value) {
    return NominalEarthRadius(static_cast<double>(value));
}
constexpr NominalEarthRadius operator""_R_earth(unsigned long long value) {
    return NominalEarthRadius(static_cast<double>(value));
}

constexpr NominalEarthEquatorialRadius operator""_R_eartheq(long double value) {
    return NominalEarthEquatorialRadius(static_cast<double>(value));
}
constexpr NominalEarthEquatorialRadius operator""_R_eartheq(unsigned long long value) {
    return NominalEarthEquatorialRadius(static_cast<double>(value));
}

constexpr EarthMeridionalCircumference operator""_C_mer(long double value) {
    return EarthMeridionalCircumference(static_cast<double>(value));
}
constexpr EarthMeridionalCircumference operator""_C_mer(unsigned long long value) {
    return EarthMeridionalCircumference(static_cast<double>(value));
}

constexpr EarthEquatorialCircumference operator""_C_eq(long double value) {
    return EarthEquatorialCircumference(static_cast<double>(value));
}
constexpr EarthEquatorialCircumference operator""_C_eq(unsigned long long value) {
    return EarthEquatorialCircumference(static_cast<double>(value));
}

constexpr NominalJupiterRadius operator""_R_jupiter(long double value) {
    return NominalJupiterRadius(static_cast<double>(value));
}
constexpr NominalJupiterRadius operator""_R_jupiter(unsigned long long value) {
    return NominalJupiterRadius(static_cast<double>(value));
}

constexpr NominalSolarRadius operator""_R_sol(long double value) {
    return NominalSolarRadius(static_cast<double>(value));
}
constexpr NominalSolarRadius operator""_R_sol(unsigned long long value) {
    return NominalSolarRadius(static_cast<double>(value));
}

constexpr NominalSolarDiameter operator""_D_sol(long double value) {
    return NominalSolarDiameter(static_cast<double>(value));
}
constexpr NominalSolarDiameter operator""_D_sol(unsigned long long value) {
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

constexpr JulianCentury operator""_jc(long double value) {
    return JulianCentury(static_cast<double>(value));
}
constexpr JulianCentury operator""_jc(unsigned long long value) {
    return JulianCentury(static_cast<double>(value));
}

constexpr SiderealDay operator""_sd(long double value) {
    return SiderealDay(static_cast<double>(value));
}
constexpr SiderealDay operator""_sd(unsigned long long value) {
    return SiderealDay(static_cast<double>(value));
}

constexpr SynodicMonth operator""_mo_s(long double value) {
    return SynodicMonth(static_cast<double>(value));
}
constexpr SynodicMonth operator""_mo_s(unsigned long long value) {
    return SynodicMonth(static_cast<double>(value));
}

constexpr SiderealYear operator""_yr_s(long double value) {
    return SiderealYear(static_cast<double>(value));
}
constexpr SiderealYear operator""_yr_s(unsigned long long value) {
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

constexpr ShortTon operator""_ton(long double value) {
    return ShortTon(static_cast<double>(value));
}
constexpr ShortTon operator""_ton(unsigned long long value) {
    return ShortTon(static_cast<double>(value));
}

constexpr LongTon operator""_ton_l(long double value) {
    return LongTon(static_cast<double>(value));
}
constexpr LongTon operator""_ton_l(unsigned long long value) {
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

constexpr SolarMass operator""_M_sol(long double value) {
    return SolarMass(static_cast<double>(value));
}
constexpr SolarMass operator""_M_sol(unsigned long long value) {
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

constexpr SolarLuminosity operator""_L_sol(long double value) {
    return SolarLuminosity(static_cast<double>(value));
}
constexpr SolarLuminosity operator""_L_sol(unsigned long long value) {
    return SolarLuminosity(static_cast<double>(value));
}

} // namespace literals

} // namespace qtty
