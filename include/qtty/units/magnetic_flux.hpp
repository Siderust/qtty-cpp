// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct WeberTag {};
struct MilliweberTag {};

template <> struct UnitTraits<WeberTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_WEBER; }
  static constexpr std::string_view symbol() { return "Wb"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MAGNETIC_FLUX; }
};
template <> struct UnitTraits<MilliweberTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIWEBER; }
  static constexpr std::string_view symbol() { return "mWb"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_MAGNETIC_FLUX; }
};

using Weber = Quantity<WeberTag>;
using Milliweber = Quantity<MilliweberTag>;

} // namespace qtty
