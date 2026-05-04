// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct MeterPerSecondSquaredTag {};
struct StandardGravityTag {};

template <> struct UnitTraits<MeterPerSecondSquaredTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_METER_PER_SECOND_SQUARED; }
  static constexpr std::string_view symbol() { return "m/s²"; }
};
template <> struct UnitTraits<StandardGravityTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_STANDARD_GRAVITY; }
  static constexpr std::string_view symbol() { return "g₀"; }
};

using MeterPerSecondSquared = Quantity<MeterPerSecondSquaredTag>;
using StandardGravity = Quantity<StandardGravityTag>;

} // namespace qtty
