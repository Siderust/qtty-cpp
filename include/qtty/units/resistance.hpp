// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct OhmTag {};
struct MilliohmTag {};
struct KilohmTag {};
struct MegaohmTag {};

template <> struct UnitTraits<OhmTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_OHM; }
  static constexpr std::string_view symbol() { return "Ω"; }
};
template <> struct UnitTraits<MilliohmTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIOHM; }
  static constexpr std::string_view symbol() { return "mΩ"; }
};
template <> struct UnitTraits<KilohmTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOHM; }
  static constexpr std::string_view symbol() { return "kΩ"; }
};
template <> struct UnitTraits<MegaohmTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MEGAOHM; }
  static constexpr std::string_view symbol() { return "MΩ"; }
};

using Ohm = Quantity<OhmTag>;
using Milliohm = Quantity<MilliohmTag>;
using Kilohm = Quantity<KilohmTag>;
using Megaohm = Quantity<MegaohmTag>;

} // namespace qtty
