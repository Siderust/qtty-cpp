// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct SquareDegreeTag {};
struct SteradianTag {};
struct SquareMilliradianTag {};
struct SquareArcminuteTag {};
struct SquareArcsecondTag {};

template <> struct UnitTraits<SquareDegreeTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SQUARE_DEGREE; }
  static constexpr std::string_view symbol() { return ""; }
};
template <> struct UnitTraits<SteradianTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_STERADIAN; }
  static constexpr std::string_view symbol() { return ""; }
};
template <> struct UnitTraits<SquareMilliradianTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SQUARE_MILLIRADIAN; }
  static constexpr std::string_view symbol() { return ""; }
};
template <> struct UnitTraits<SquareArcminuteTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SQUARE_ARCMINUTE; }
  static constexpr std::string_view symbol() { return ""; }
};
template <> struct UnitTraits<SquareArcsecondTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_SQUARE_ARCSECOND; }
  static constexpr std::string_view symbol() { return ""; }
};

using SquareDegree = Quantity<SquareDegreeTag>;
using Steradian = Quantity<SteradianTag>;
using SquareMilliradian = Quantity<SquareMilliradianTag>;
using SquareArcminute = Quantity<SquareArcminuteTag>;
using SquareArcsecond = Quantity<SquareArcsecondTag>;

} // namespace qtty
