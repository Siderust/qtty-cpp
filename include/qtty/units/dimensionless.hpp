// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct OpticalDepthTag {};
struct AirmassTag {};
struct TransmittanceTag {};
struct AlbedoTag {};
struct IlluminationFractionTag {};
struct RefractivityTag {};

template <> struct UnitTraits<OpticalDepthTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_OPTICAL_DEPTH; }
  static constexpr std::string_view symbol() { return ""; }
};
template <> struct UnitTraits<AirmassTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_AIRMASS; }
  static constexpr std::string_view symbol() { return ""; }
};
template <> struct UnitTraits<TransmittanceTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_TRANSMITTANCE; }
  static constexpr std::string_view symbol() { return ""; }
};
template <> struct UnitTraits<AlbedoTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ALBEDO; }
  static constexpr std::string_view symbol() { return ""; }
};
template <> struct UnitTraits<IlluminationFractionTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_ILLUMINATION_FRACTION; }
  static constexpr std::string_view symbol() { return ""; }
};
template <> struct UnitTraits<RefractivityTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_REFRACTIVITY; }
  static constexpr std::string_view symbol() { return ""; }
};

using OpticalDepth = Quantity<OpticalDepthTag>;
using Airmass = Quantity<AirmassTag>;
using Transmittance = Quantity<TransmittanceTag>;
using Albedo = Quantity<AlbedoTag>;
using IlluminationFraction = Quantity<IlluminationFractionTag>;
using Refractivity = Quantity<RefractivityTag>;

} // namespace qtty
