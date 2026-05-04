// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct LuxTag {};
struct MilliluxTag {};
struct KiloluxTag {};

template <> struct UnitTraits<LuxTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_LUX; }
  static constexpr std::string_view symbol() { return "lx"; }
};
template <> struct UnitTraits<MilliluxTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLILUX; }
  static constexpr std::string_view symbol() { return "mlx"; }
};
template <> struct UnitTraits<KiloluxTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOLUX; }
  static constexpr std::string_view symbol() { return "klx"; }
};

using Lux = Quantity<LuxTag>;
using Millilux = Quantity<MilliluxTag>;
using Kilolux = Quantity<KiloluxTag>;

} // namespace qtty
