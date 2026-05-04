// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct PascalTag {};
struct MillipascalTag {};
struct HectopascalTag {};
struct KilopascalTag {};
struct MegapascalTag {};
struct GigapascalTag {};
struct BarTag {};
struct AtmosphereTag {};
struct TorrTag {};
struct MillimeterOfMercuryTag {};
struct PoundPerSquareInchTag {};
struct InchOfMercuryTag {};

template <> struct UnitTraits<PascalTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_PASCAL; }
  static constexpr std::string_view symbol() { return "Pa"; }
};
template <> struct UnitTraits<MillipascalTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIPASCAL; }
  static constexpr std::string_view symbol() { return "mPa"; }
};
template <> struct UnitTraits<HectopascalTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_HECTOPASCAL; }
  static constexpr std::string_view symbol() { return "hPa"; }
};
template <> struct UnitTraits<KilopascalTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOPASCAL; }
  static constexpr std::string_view symbol() { return "kPa"; }
};
template <> struct UnitTraits<MegapascalTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MEGAPASCAL; }
  static constexpr std::string_view symbol() { return "MPa"; }
};
template <> struct UnitTraits<GigapascalTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_GIGAPASCAL; }
  static constexpr std::string_view symbol() { return "GPa"; }
};
template <> struct UnitTraits<BarTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_BAR; }
  static constexpr std::string_view symbol() { return "bar"; }
};
template <> struct UnitTraits<AtmosphereTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ATMOSPHERE; }
  static constexpr std::string_view symbol() { return "atm"; }
};
template <> struct UnitTraits<TorrTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_TORR; }
  static constexpr std::string_view symbol() { return "Torr"; }
};
template <> struct UnitTraits<MillimeterOfMercuryTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIMETER_OF_MERCURY; }
  static constexpr std::string_view symbol() { return "mmHg"; }
};
template <> struct UnitTraits<PoundPerSquareInchTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_POUND_PER_SQUARE_INCH; }
  static constexpr std::string_view symbol() { return "psi"; }
};
template <> struct UnitTraits<InchOfMercuryTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_INCH_OF_MERCURY; }
  static constexpr std::string_view symbol() { return "inHg"; }
};

using Pascal = Quantity<PascalTag>;
using Millipascal = Quantity<MillipascalTag>;
using Hectopascal = Quantity<HectopascalTag>;
using Kilopascal = Quantity<KilopascalTag>;
using Megapascal = Quantity<MegapascalTag>;
using Gigapascal = Quantity<GigapascalTag>;
using Bar = Quantity<BarTag>;
using Atmosphere = Quantity<AtmosphereTag>;
using Torr = Quantity<TorrTag>;
using MillimeterOfMercury = Quantity<MillimeterOfMercuryTag>;
using PoundPerSquareInch = Quantity<PoundPerSquareInchTag>;
using InchOfMercury = Quantity<InchOfMercuryTag>;

} // namespace qtty
