// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct TeslaTag {};
struct MilliteslaTag {};
struct MicroteslaTag {};

template <> struct UnitTraits<TeslaTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_TESLA; }
  static constexpr std::string_view symbol() { return "T"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MAGNETIC_FLUX_DENSITY; }
};
template <> struct UnitTraits<MilliteslaTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLITESLA; }
  static constexpr std::string_view symbol() { return "mT"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MAGNETIC_FLUX_DENSITY; }
};
template <> struct UnitTraits<MicroteslaTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROTESLA; }
  static constexpr std::string_view symbol() { return "µT"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MAGNETIC_FLUX_DENSITY; }
};

using Tesla = Quantity<TeslaTag>;
using Millitesla = Quantity<MilliteslaTag>;
using Microtesla = Quantity<MicroteslaTag>;

} // namespace qtty
