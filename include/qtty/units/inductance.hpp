// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct HenryTag {};
struct MicrohenryTag {};
struct MillihenryTag {};

template <> struct UnitTraits<HenryTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_HENRY; }
  static constexpr std::string_view symbol() { return "H"; }
};
template <> struct UnitTraits<MicrohenryTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROHENRY; }
  static constexpr std::string_view symbol() { return "µH"; }
};
template <> struct UnitTraits<MillihenryTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIHENRY; }
  static constexpr std::string_view symbol() { return "mH"; }
};

using Henry = Quantity<HenryTag>;
using Microhenry = Quantity<MicrohenryTag>;
using Millihenry = Quantity<MillihenryTag>;

} // namespace qtty
