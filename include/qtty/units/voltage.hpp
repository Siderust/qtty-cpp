// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct VoltTag {};
struct MicrovoltTag {};
struct MillivoltTag {};
struct KilovoltTag {};
struct MegavoltTag {};

template <> struct UnitTraits<VoltTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_VOLT; }
  static constexpr std::string_view symbol() { return "V"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLTAGE; }
};
template <> struct UnitTraits<MicrovoltTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROVOLT; }
  static constexpr std::string_view symbol() { return "µV"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLTAGE; }
};
template <> struct UnitTraits<MillivoltTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIVOLT; }
  static constexpr std::string_view symbol() { return "mV"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLTAGE; }
};
template <> struct UnitTraits<KilovoltTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOVOLT; }
  static constexpr std::string_view symbol() { return "kV"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLTAGE; }
};
template <> struct UnitTraits<MegavoltTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MEGAVOLT; }
  static constexpr std::string_view symbol() { return "MV"; }
  static constexpr DimensionId dimension() { return DIMENSION_ID_VOLTAGE; }
};

using Volt = Quantity<VoltTag>;
using Microvolt = Quantity<MicrovoltTag>;
using Millivolt = Quantity<MillivoltTag>;
using Kilovolt = Quantity<KilovoltTag>;
using Megavolt = Quantity<MegavoltTag>;

} // namespace qtty
