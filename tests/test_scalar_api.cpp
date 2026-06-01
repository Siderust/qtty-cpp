// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

// Tests for the scalar `Real` API mirrored from the Rust `Quantity` type:
// reductions, floating-point predicates, rounding helpers and unit-aware
// comparisons.

#include "fixtures.hpp"

class ScalarApiTest : public QttyTest {};

TEST_F(ScalarApiTest, IdentitiesAndConstants) {
  EXPECT_EQ(Meter::zero().value(), 0.0);
  EXPECT_EQ(Meter::one().value(), 1.0);
  EXPECT_TRUE(Meter::nan().is_nan());
  EXPECT_TRUE(Meter::infinity().is_infinite());
  EXPECT_TRUE(Meter::neg_infinity().is_infinite());
  EXPECT_LT(Meter::neg_infinity().value(), 0.0);
}

TEST_F(ScalarApiTest, ValueAccessors) {
  Meter m(42.0);
  EXPECT_EQ(m.value_ref(), 42.0);
  EXPECT_EQ(m.erase_unit_raw(), 42.0);
}

TEST_F(ScalarApiTest, MinMaxClampMean) {
  Meter a(3.0);
  Meter b(8.0);
  EXPECT_EQ(a.min(b).value(), 3.0);
  EXPECT_EQ(a.max(b).value(), 8.0);
  EXPECT_EQ(Meter(10.0).clamp(Meter(0.0), Meter(5.0)).value(), 5.0);
  EXPECT_EQ(Meter(-1.0).clamp(Meter(0.0), Meter(5.0)).value(), 0.0);
  EXPECT_EQ(a.mean(b).value(), 5.5);
}

TEST_F(ScalarApiTest, Predicates) {
  EXPECT_TRUE(Meter(1.0).is_finite());
  EXPECT_FALSE(Meter(1.0).is_nan());
  EXPECT_FALSE(Meter(1.0).is_infinite());
}

TEST_F(ScalarApiTest, SignumAndScalarSqrt) {
  EXPECT_EQ(Meter(5.0).signum(), 1.0);
  EXPECT_EQ(Meter(-5.0).signum(), -1.0);
  EXPECT_DOUBLE_EQ(Meter(9.0).scalar_sqrt(), 3.0);
}

TEST_F(ScalarApiTest, Rounding) {
  EXPECT_EQ(Meter(2.7).floor().value(), 2.0);
  EXPECT_EQ(Meter(2.1).ceil().value(), 3.0);
  EXPECT_EQ(Meter(2.5).round().value(), 3.0);
  EXPECT_EQ(Meter(2.9).trunc().value(), 2.0);
  EXPECT_NEAR(Meter(2.25).fract().value(), 0.25, 1e-12);
}

TEST_F(ScalarApiTest, RemEuclid) {
  EXPECT_NEAR(Meter(7.0).rem_euclid(3.0).value(), 1.0, 1e-12);
  EXPECT_NEAR(Meter(-1.0).rem_euclid(3.0).value(), 2.0, 1e-12);
}

TEST_F(ScalarApiTest, UnitAwareComparison) {
  // 1 km equals 1000 m across units.
  Kilometer one_km(1.0);
  Meter thousand_m(1000.0);
  EXPECT_TRUE(one_km.eq_unit(thousand_m));

  Meter half_km(500.0);
  EXPECT_EQ(one_km.cmp_unit(half_km).value(), 1);
  EXPECT_EQ(half_km.cmp_unit(one_km).value(), -1);
  EXPECT_EQ(one_km.cmp_unit(thousand_m).value(), 0);

  EXPECT_FALSE(Meter::nan().cmp_unit(Meter(1.0)).has_value());
}
