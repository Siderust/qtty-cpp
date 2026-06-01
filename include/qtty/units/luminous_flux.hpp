// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct LumenTag {};
struct MillilumenTag {};
struct KilolumenTag {};

template <> struct UnitTraits<LumenTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_LUMEN; }
  static constexpr std::string_view symbol() { return "lm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LUMINOUS_FLUX; }
};
template <> struct UnitTraits<MillilumenTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLILUMEN; }
  static constexpr std::string_view symbol() { return "mlm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LUMINOUS_FLUX; }
};
template <> struct UnitTraits<KilolumenTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOLUMEN; }
  static constexpr std::string_view symbol() { return "klm"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_LUMINOUS_FLUX; }
};

using Lumen = Quantity<LumenTag>;
using Millilumen = Quantity<MillilumenTag>;
using Kilolumen = Quantity<KilolumenTag>;

} // namespace qtty
