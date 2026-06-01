// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct NewtonTag {};
struct MicronewtonTag {};
struct MillinewtonTag {};
struct KilonewtonTag {};
struct MeganewtonTag {};
struct GiganewtonTag {};
struct DyneTag {};
struct PoundForceTag {};

template <> struct UnitTraits<NewtonTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NEWTON; }
  static constexpr std::string_view symbol() { return "N"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_FORCE; }
};
template <> struct UnitTraits<MicronewtonTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICRONEWTON; }
  static constexpr std::string_view symbol() { return "µN"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_FORCE; }
};
template <> struct UnitTraits<MillinewtonTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLINEWTON; }
  static constexpr std::string_view symbol() { return "mN"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_FORCE; }
};
template <> struct UnitTraits<KilonewtonTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILONEWTON; }
  static constexpr std::string_view symbol() { return "kN"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_FORCE; }
};
template <> struct UnitTraits<MeganewtonTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MEGANEWTON; }
  static constexpr std::string_view symbol() { return "MN"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_FORCE; }
};
template <> struct UnitTraits<GiganewtonTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_GIGANEWTON; }
  static constexpr std::string_view symbol() { return "GN"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_FORCE; }
};
template <> struct UnitTraits<DyneTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_DYNE; }
  static constexpr std::string_view symbol() { return "dyn"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_FORCE; }
};
template <> struct UnitTraits<PoundForceTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_POUND_FORCE; }
  static constexpr std::string_view symbol() { return "lbf"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_FORCE; }
};

using Newton = Quantity<NewtonTag>;
using Micronewton = Quantity<MicronewtonTag>;
using Millinewton = Quantity<MillinewtonTag>;
using Kilonewton = Quantity<KilonewtonTag>;
using Meganewton = Quantity<MeganewtonTag>;
using Giganewton = Quantity<GiganewtonTag>;
using Dyne = Quantity<DyneTag>;
using PoundForce = Quantity<PoundForceTag>;

} // namespace qtty
