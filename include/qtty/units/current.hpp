// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct AmpereTag {};
struct MicroampereTag {};
struct MilliampereTag {};
struct KiloampereTag {};

template <> struct UnitTraits<AmpereTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_AMPERE; }
  static constexpr std::string_view symbol() { return "A"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_CURRENT; }
};
template <> struct UnitTraits<MicroampereTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROAMPERE; }
  static constexpr std::string_view symbol() { return "µA"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_CURRENT; }
};
template <> struct UnitTraits<MilliampereTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIAMPERE; }
  static constexpr std::string_view symbol() { return "mA"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_CURRENT; }
};
template <> struct UnitTraits<KiloampereTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOAMPERE; }
  static constexpr std::string_view symbol() { return "kA"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_CURRENT; }
};

using Ampere = Quantity<AmpereTag>;
using Microampere = Quantity<MicroampereTag>;
using Milliampere = Quantity<MilliampereTag>;
using Kiloampere = Quantity<KiloampereTag>;

} // namespace qtty
