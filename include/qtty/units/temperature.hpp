// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct KelvinTag {};
struct RankineTag {};

template <> struct UnitTraits<KelvinTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KELVIN; }
  static constexpr std::string_view symbol() { return "K"; }
};
template <> struct UnitTraits<RankineTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_RANKINE; }
  static constexpr std::string_view symbol() { return "°R"; }
};

using Kelvin = Quantity<KelvinTag>;
using Rankine = Quantity<RankineTag>;

} // namespace qtty
