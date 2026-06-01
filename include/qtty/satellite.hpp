// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

/**
 * @file satellite.hpp
 * @brief Spacecraft astrodynamics quantities, mirroring the Rust `qtty`
 *        `satellite` feature (`dynamics` + `tolerances` modules).
 *
 * These are header-only value types: gravitational parameters, ballistic /
 * radiation / geopotential coefficients, and integrator tolerances. They carry
 * the same numeric definitions and semantics as their Rust counterparts.
 *
 * Note: `GravitationalParameter` is a nested compound unit (km³/s²) in Rust.
 * The FFI derived-conversion ABI only encodes a single numerator/denominator
 * pair, so the C++ mirror is a value-carrying quantity (arithmetic, comparison
 * and `value()` are supported; cross-unit `.to<>()` is not).
 */

#include <array>
#include <string_view>

#include "ffi_core.hpp"
#include "units/dimensionless.hpp"
#include "units/length.hpp"
#include "units/time.hpp"
#include "units/velocity.hpp"

namespace qtty {
namespace satellite {

// ── Compound kinematic unit aliases ─────────────────────────────────────────

/// Kilometre per second (km/s) — orbital speed scale.
using KmPerSeconds = Quantity<CompoundTag<KilometerTag, SecondTag>>;

// ── Gravitational parameter μ = G·M (km³/s²) ────────────────────────────────

struct GravitationalParameterTag {};

/// Standard gravitational parameter μ = G·M, expressed in km³/s².
using GravitationalParameter = Quantity<GravitationalParameterTag>;

// Canonical μ values (km³/s²), matching qtty::dynamics.
inline const GravitationalParameter GM_EARTH{398600.4418};
inline const GravitationalParameter GM_SUN{1.32712440018e11};
inline const GravitationalParameter GM_MOON{4.902800066e3};
inline const GravitationalParameter GM_MERCURY{2.2031878328e4};
inline const GravitationalParameter GM_VENUS{3.24858592e5};
inline const GravitationalParameter GM_MARS{4.2828375816e4};
inline const GravitationalParameter GM_JUPITER{1.267127648e8};
inline const GravitationalParameter GM_SATURN{3.79405852e7};
inline const GravitationalParameter GM_URANUS{5.7945486e6};
inline const GravitationalParameter GM_NEPTUNE{6.8365271005e6};
inline const GravitationalParameter GM_PLUTO{9.770e2};

// ── Dimensionless astrodynamics coefficients ────────────────────────────────

/// Aerodynamic drag coefficient C_D (dimensionless).
class DragCoefficient {
public:
  constexpr explicit DragCoefficient(double value) : m_value(value) {}
  constexpr double value() const { return m_value; }

private:
  double m_value;
};

/// Solar radiation pressure coefficient C_R (dimensionless).
class SrpCoefficient {
public:
  constexpr explicit SrpCoefficient(double value) : m_value(value) {}
  constexpr double value() const { return m_value; }

private:
  double m_value;
};

/// Gravitational zonal harmonic J₂ coefficient (dimensionless).
class J2Coefficient {
public:
  constexpr explicit J2Coefficient(double value) : m_value(value) {}
  constexpr double value() const { return m_value; }

private:
  double m_value;
};

/// Fully-normalised Stokes geopotential coefficient C_nm / S_nm (dimensionless).
class StokesCoefficient {
public:
  constexpr explicit StokesCoefficient(double value) : m_value(value) {}
  constexpr double value() const { return m_value; }

private:
  double m_value;
};

// ── Integrator tolerances ───────────────────────────────────────────────────

/// Relative tolerance (dimensionless) for adaptive ODE integration.
class RelativeTolerance {
public:
  constexpr explicit RelativeTolerance(double value) : m_value(value) {}
  constexpr double value() const { return m_value; }

private:
  double m_value;
};

/// Absolute position tolerance, stored in kilometres.
class AbsoluteTolerancePosition {
public:
  constexpr explicit AbsoluteTolerancePosition(Kilometer quantity) : m_value(quantity) {}
  static AbsoluteTolerancePosition new_km(double value) {
    return AbsoluteTolerancePosition(Kilometer(value));
  }
  double value() const { return m_value.value(); }

private:
  Kilometer m_value;
};

/// Absolute velocity tolerance, stored in kilometres per second.
class AbsoluteToleranceVelocity {
public:
  constexpr explicit AbsoluteToleranceVelocity(KmPerSeconds quantity) : m_value(quantity) {}
  static AbsoluteToleranceVelocity new_km_s(double value) {
    return AbsoluteToleranceVelocity(KmPerSeconds(value));
  }
  double value() const { return m_value.value(); }

private:
  KmPerSeconds m_value;
};

/// Per-axis integrator tolerances for state propagation.
struct IntegratorTolerances {
  RelativeTolerance rel;
  std::array<AbsoluteTolerancePosition, 3> abs_pos;
  std::array<AbsoluteToleranceVelocity, 3> abs_vel;

  /// Builds tolerances with the same value applied to every axis.
  static IntegratorTolerances uniform(double rel, double abs_pos_km, double abs_vel_km_s) {
    AbsoluteTolerancePosition p = AbsoluteTolerancePosition::new_km(abs_pos_km);
    AbsoluteToleranceVelocity v = AbsoluteToleranceVelocity::new_km_s(abs_vel_km_s);
    return IntegratorTolerances{RelativeTolerance(rel), {p, p, p}, {v, v, v}};
  }
};

} // namespace satellite
} // namespace qtty
