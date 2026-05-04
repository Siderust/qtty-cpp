// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct JouleTag {};
struct MicrojouleTag {};
struct MillijouleTag {};
struct KilojouleTag {};
struct MegajouleTag {};
struct GigajouleTag {};
struct TerajouleTag {};
struct ErgTag {};
struct ElectronvoltTag {};
struct KiloelectronvoltTag {};
struct MegaelectronvoltTag {};
struct CalorieTag {};
struct KilocalorieTag {};

template <> struct UnitTraits<JouleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_JOULE; }
  static constexpr std::string_view symbol() { return "J"; }
};
template <> struct UnitTraits<MicrojouleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROJOULE; }
  static constexpr std::string_view symbol() { return "µJ"; }
};
template <> struct UnitTraits<MillijouleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIJOULE; }
  static constexpr std::string_view symbol() { return "mJ"; }
};
template <> struct UnitTraits<KilojouleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOJOULE; }
  static constexpr std::string_view symbol() { return "kJ"; }
};
template <> struct UnitTraits<MegajouleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MEGAJOULE; }
  static constexpr std::string_view symbol() { return "MJ"; }
};
template <> struct UnitTraits<GigajouleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_GIGAJOULE; }
  static constexpr std::string_view symbol() { return "GJ"; }
};
template <> struct UnitTraits<TerajouleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_TERAJOULE; }
  static constexpr std::string_view symbol() { return "TJ"; }
};
template <> struct UnitTraits<ErgTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ERG; }
  static constexpr std::string_view symbol() { return "erg"; }
};
template <> struct UnitTraits<ElectronvoltTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ELECTRONVOLT; }
  static constexpr std::string_view symbol() { return "eV"; }
};
template <> struct UnitTraits<KiloelectronvoltTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOELECTRONVOLT; }
  static constexpr std::string_view symbol() { return "keV"; }
};
template <> struct UnitTraits<MegaelectronvoltTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MEGAELECTRONVOLT; }
  static constexpr std::string_view symbol() { return "MeV"; }
};
template <> struct UnitTraits<CalorieTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CALORIE; }
  static constexpr std::string_view symbol() { return "cal"; }
};
template <> struct UnitTraits<KilocalorieTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOCALORIE; }
  static constexpr std::string_view symbol() { return "kcal"; }
};

using Joule = Quantity<JouleTag>;
using Microjoule = Quantity<MicrojouleTag>;
using Millijoule = Quantity<MillijouleTag>;
using Kilojoule = Quantity<KilojouleTag>;
using Megajoule = Quantity<MegajouleTag>;
using Gigajoule = Quantity<GigajouleTag>;
using Terajoule = Quantity<TerajouleTag>;
using Erg = Quantity<ErgTag>;
using Electronvolt = Quantity<ElectronvoltTag>;
using Kiloelectronvolt = Quantity<KiloelectronvoltTag>;
using Megaelectronvolt = Quantity<MegaelectronvoltTag>;
using Calorie = Quantity<CalorieTag>;
using Kilocalorie = Quantity<KilocalorieTag>;

} // namespace qtty
