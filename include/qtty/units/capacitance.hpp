// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct FaradTag {};
struct PicofaradTag {};
struct NanofaradTag {};
struct MicrofaradTag {};
struct MillifaradTag {};

template <> struct UnitTraits<FaradTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_FARAD; }
  static constexpr std::string_view symbol() { return "F"; }
};
template <> struct UnitTraits<PicofaradTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_PICOFARAD; }
  static constexpr std::string_view symbol() { return "pF"; }
};
template <> struct UnitTraits<NanofaradTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_NANOFARAD; }
  static constexpr std::string_view symbol() { return "nF"; }
};
template <> struct UnitTraits<MicrofaradTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MICROFARAD; }
  static constexpr std::string_view symbol() { return "µF"; }
};
template <> struct UnitTraits<MillifaradTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_MILLIFARAD; }
  static constexpr std::string_view symbol() { return "mF"; }
};

using Farad = Quantity<FaradTag>;
using Picofarad = Quantity<PicofaradTag>;
using Nanofarad = Quantity<NanofaradTag>;
using Microfarad = Quantity<MicrofaradTag>;
using Millifarad = Quantity<MillifaradTag>;

} // namespace qtty
