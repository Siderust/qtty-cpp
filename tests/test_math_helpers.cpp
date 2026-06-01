// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

// Tests for dimension-aware math helpers mirrored from the Rust `Quantity`
// API: ratio_to plus dimensionless transcendental functions.

#include "fixtures.hpp"
#include <cmath>

class MathHelpersTest : public QttyTest {};

TEST_F(MathHelpersTest, RatioTo) {
  Meter a(10.0);
  Meter b(4.0);
  Ratio r = ratio_to(a, b);
  EXPECT_NEAR(r.value(), 2.5, 1e-12);
}

TEST_F(MathHelpersTest, RatioUnitRoundtrip) {
  // Ratio is now a first-class FFI unit; conversion to itself is identity.
  Ratio r(0.75);
  EXPECT_NEAR(r.to<RatioTag>().value(), 0.75, 1e-12);
}

TEST_F(MathHelpersTest, ExpLn) {
  Ratio x(2.0);
  EXPECT_NEAR(exp(x).value(), std::exp(2.0), 1e-12);
  EXPECT_NEAR(ln(Ratio(std::exp(1.0))).value(), 1.0, 1e-12);
}

TEST_F(MathHelpersTest, Powers) {
  Ratio base(3.0);
  EXPECT_NEAR(powi(base, 3).value(), 27.0, 1e-9);
  EXPECT_NEAR(powf(base, Ratio(2.0)).value(), 9.0, 1e-9);
}

TEST_F(MathHelpersTest, InverseTrigReturnsRadians) {
  Ratio half(0.5);
  EXPECT_NEAR(asin_angle(half).value(), std::asin(0.5), 1e-12);
  EXPECT_NEAR(acos_angle(half).value(), std::acos(0.5), 1e-12);
  EXPECT_NEAR(atan_angle(Ratio(1.0)).value(), std::atan(1.0), 1e-12);

  // Result is a typed angle convertible to degrees.
  Degree deg = asin_angle(half).to<DegreeTag>();
  EXPECT_NEAR(deg.value(), 30.0, 1e-9);
}

TEST_F(MathHelpersTest, DimensionlessTraitSelectivity) {
  static_assert(is_dimensionless_v<RatioTag>, "Ratio must be dimensionless");
  static_assert(is_dimensionless_v<AirmassTag>, "Airmass must be dimensionless");
  static_assert(!is_dimensionless_v<MeterTag>, "Meter must not be dimensionless");
  static_assert(!is_dimensionless_v<RadianTag>, "Radian (Angle) must not be dimensionless");
}
