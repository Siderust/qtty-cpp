// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

// Tests for the spacecraft astrodynamics quantities mirrored from the Rust
// `qtty` `satellite` feature (dynamics + tolerances).

#include "fixtures.hpp"

using namespace qtty::satellite;

class SatelliteTest : public QttyTest {};

TEST_F(SatelliteTest, GravitationalParameters) {
  EXPECT_NEAR(GM_EARTH.value(), 398600.4418, 1e-6);
  EXPECT_NEAR(GM_SUN.value(), 1.32712440018e11, 1e3);
  EXPECT_NEAR(GM_MOON.value(), 4.902800066e3, 1e-6);
  // Earth's μ is far smaller than the Sun's.
  EXPECT_LT(GM_EARTH.value(), GM_SUN.value());
}

TEST_F(SatelliteTest, GravitationalParameterArithmetic) {
  GravitationalParameter sum = GM_EARTH + GM_MOON;
  EXPECT_NEAR(sum.value(), 398600.4418 + 4.902800066e3, 1e-6);
}

TEST_F(SatelliteTest, Coefficients) {
  DragCoefficient cd(2.2);
  SrpCoefficient cr(1.3);
  J2Coefficient j2(1.0826359e-3);
  StokesCoefficient c20(-4.84e-4);
  EXPECT_NEAR(cd.value(), 2.2, 1e-12);
  EXPECT_NEAR(cr.value(), 1.3, 1e-12);
  EXPECT_NEAR(j2.value(), 1.0826359e-3, 1e-12);
  EXPECT_NEAR(c20.value(), -4.84e-4, 1e-12);
}

TEST_F(SatelliteTest, KmPerSecondsConversion) {
  KmPerSeconds v(7.8);
  EXPECT_NEAR(v.value(), 7.8, 1e-12);
}

TEST_F(SatelliteTest, ToleranceConstructors) {
  RelativeTolerance rel(1e-9);
  AbsoluteTolerancePosition pos = AbsoluteTolerancePosition::new_km(1e-6);
  AbsoluteToleranceVelocity vel = AbsoluteToleranceVelocity::new_km_s(1e-9);
  EXPECT_NEAR(rel.value(), 1e-9, 1e-18);
  EXPECT_NEAR(pos.value(), 1e-6, 1e-15);
  EXPECT_NEAR(vel.value(), 1e-9, 1e-18);
}

TEST_F(SatelliteTest, IntegratorTolerancesUniform) {
  IntegratorTolerances tol = IntegratorTolerances::uniform(1e-10, 1e-6, 1e-9);
  EXPECT_NEAR(tol.rel.value(), 1e-10, 1e-18);
  for (const auto &p : tol.abs_pos) {
    EXPECT_NEAR(p.value(), 1e-6, 1e-15);
  }
  for (const auto &v : tol.abs_vel) {
    EXPECT_NEAR(v.value(), 1e-9, 1e-18);
  }
}
