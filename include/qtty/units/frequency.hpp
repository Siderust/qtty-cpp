// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct HertzTag {};
struct MillihertzTag {};
struct KilohertzTag {};
struct MegahertzTag {};
struct GigahertzTag {};
struct TerahertzTag {};

template <> struct UnitTraits<HertzTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_HERTZ; }
  static constexpr std::string_view symbol() { return "Hz"; }
};
template <> struct UnitTraits<MillihertzTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIHERTZ; }
  static constexpr std::string_view symbol() { return "mHz"; }
};
template <> struct UnitTraits<KilohertzTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOHERTZ; }
  static constexpr std::string_view symbol() { return "kHz"; }
};
template <> struct UnitTraits<MegahertzTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MEGAHERTZ; }
  static constexpr std::string_view symbol() { return "MHz"; }
};
template <> struct UnitTraits<GigahertzTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_GIGAHERTZ; }
  static constexpr std::string_view symbol() { return "GHz"; }
};
template <> struct UnitTraits<TerahertzTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_TERAHERTZ; }
  static constexpr std::string_view symbol() { return "THz"; }
};

using Hertz = Quantity<HertzTag>;
using Millihertz = Quantity<MillihertzTag>;
using Kilohertz = Quantity<KilohertzTag>;
using Megahertz = Quantity<MegahertzTag>;
using Gigahertz = Quantity<GigahertzTag>;
using Terahertz = Quantity<TerahertzTag>;

} // namespace qtty
