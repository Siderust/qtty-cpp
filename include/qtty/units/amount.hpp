// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct MoleTag {};
struct NanomoleTag {};
struct MicromoleTag {};
struct MillimoleTag {};
struct KilomoleTag {};

template <> struct UnitTraits<MoleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MOLE; }
  static constexpr std::string_view symbol() { return "mol"; }
};
template <> struct UnitTraits<NanomoleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NANOMOLE; }
  static constexpr std::string_view symbol() { return "nmol"; }
};
template <> struct UnitTraits<MicromoleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROMOLE; }
  static constexpr std::string_view symbol() { return "µmol"; }
};
template <> struct UnitTraits<MillimoleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIMOLE; }
  static constexpr std::string_view symbol() { return "mmol"; }
};
template <> struct UnitTraits<KilomoleTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOMOLE; }
  static constexpr std::string_view symbol() { return "kmol"; }
};

using Mole = Quantity<MoleTag>;
using Nanomole = Quantity<NanomoleTag>;
using Micromole = Quantity<MicromoleTag>;
using Millimole = Quantity<MillimoleTag>;
using Kilomole = Quantity<KilomoleTag>;

} // namespace qtty
