// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct MoleTag {};
struct NanomoleTag {};
struct MicromoleTag {};
struct MillimoleTag {};
struct KilomoleTag {};

template <> struct UnitTraits<MoleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MOLE; }
  static constexpr std::string_view symbol() { return "mol"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_AMOUNT_OF_SUBSTANCE; }
};
template <> struct UnitTraits<NanomoleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NANOMOLE; }
  static constexpr std::string_view symbol() { return "nmol"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_AMOUNT_OF_SUBSTANCE; }
};
template <> struct UnitTraits<MicromoleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROMOLE; }
  static constexpr std::string_view symbol() { return "µmol"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_AMOUNT_OF_SUBSTANCE; }
};
template <> struct UnitTraits<MillimoleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIMOLE; }
  static constexpr std::string_view symbol() { return "mmol"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_AMOUNT_OF_SUBSTANCE; }
};
template <> struct UnitTraits<KilomoleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOMOLE; }
  static constexpr std::string_view symbol() { return "kmol"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_AMOUNT_OF_SUBSTANCE; }
};

using Mole = Quantity<MoleTag>;
using Nanomole = Quantity<NanomoleTag>;
using Micromole = Quantity<MicromoleTag>;
using Millimole = Quantity<MillimoleTag>;
using Kilomole = Quantity<KilomoleTag>;

} // namespace qtty
