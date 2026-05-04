// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct CoulombTag {};
struct MillicoulombTag {};
struct MicrocoulombTag {};
struct KilocoulombTag {};

template <> struct UnitTraits<CoulombTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_COULOMB; }
  static constexpr std::string_view symbol() { return "C"; }
};
template <> struct UnitTraits<MillicoulombTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLICOULOMB; }
  static constexpr std::string_view symbol() { return "mC"; }
};
template <> struct UnitTraits<MicrocoulombTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROCOULOMB; }
  static constexpr std::string_view symbol() { return "µC"; }
};
template <> struct UnitTraits<KilocoulombTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_KILOCOULOMB; }
  static constexpr std::string_view symbol() { return "kC"; }
};

using Coulomb = Quantity<CoulombTag>;
using Millicoulomb = Quantity<MillicoulombTag>;
using Microcoulomb = Quantity<MicrocoulombTag>;
using Kilocoulomb = Quantity<KilocoulombTag>;

} // namespace qtty
