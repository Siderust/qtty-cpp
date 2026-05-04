// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct SquareMeterTag {};
struct SquareKilometerTag {};
struct SquareCentimeterTag {};
struct SquareMillimeterTag {};
struct HectareTag {};
struct AreTag {};
struct SquareInchTag {};
struct SquareFootTag {};
struct SquareYardTag {};
struct SquareMileTag {};
struct AcreTag {};

template <> struct UnitTraits<SquareMeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SQUARE_METER; }
  static constexpr std::string_view symbol() { return ""; }
};
template <> struct UnitTraits<SquareKilometerTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SQUARE_KILOMETER; }
  static constexpr std::string_view symbol() { return ""; }
};
template <> struct UnitTraits<SquareCentimeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SQUARE_CENTIMETER; }
  static constexpr std::string_view symbol() { return ""; }
};
template <> struct UnitTraits<SquareMillimeterTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SQUARE_MILLIMETER; }
  static constexpr std::string_view symbol() { return ""; }
};
template <> struct UnitTraits<HectareTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_HECTARE; }
  static constexpr std::string_view symbol() { return "ha"; }
};
template <> struct UnitTraits<AreTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ARE; }
  static constexpr std::string_view symbol() { return "a"; }
};
template <> struct UnitTraits<SquareInchTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SQUARE_INCH; }
  static constexpr std::string_view symbol() { return "in²"; }
};
template <> struct UnitTraits<SquareFootTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SQUARE_FOOT; }
  static constexpr std::string_view symbol() { return "ft²"; }
};
template <> struct UnitTraits<SquareYardTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SQUARE_YARD; }
  static constexpr std::string_view symbol() { return "yd²"; }
};
template <> struct UnitTraits<SquareMileTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SQUARE_MILE; }
  static constexpr std::string_view symbol() { return "mi²"; }
};
template <> struct UnitTraits<AcreTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ACRE; }
  static constexpr std::string_view symbol() { return "ac"; }
};

using SquareMeter = Quantity<SquareMeterTag>;
using SquareKilometer = Quantity<SquareKilometerTag>;
using SquareCentimeter = Quantity<SquareCentimeterTag>;
using SquareMillimeter = Quantity<SquareMillimeterTag>;
using Hectare = Quantity<HectareTag>;
using Are = Quantity<AreTag>;
using SquareInch = Quantity<SquareInchTag>;
using SquareFoot = Quantity<SquareFootTag>;
using SquareYard = Quantity<SquareYardTag>;
using SquareMile = Quantity<SquareMileTag>;
using Acre = Quantity<AcreTag>;

} // namespace qtty
