// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

// Tests for the angular wrapping / separation helpers mirrored from the Rust
// `qtty_core::angular` methods on `Quantity<U: AngularUnit>`.

#include "fixtures.hpp"

class AngleHelpersTest : public QttyTest {};

TEST_F(AngleHelpersTest, WrapPos) {
  EXPECT_NEAR(wrap_pos(Degree(370.0)).value(), 10.0, 1e-12);
  EXPECT_NEAR(wrap_pos(Degree(-30.0)).value(), 330.0, 1e-12);
  EXPECT_NEAR(normalize(Degree(720.0)).value(), 0.0, 1e-12);
}

TEST_F(AngleHelpersTest, WrapSigned) {
  EXPECT_NEAR(wrap_signed(Degree(370.0)).value(), 10.0, 1e-12);
  EXPECT_NEAR(wrap_signed(Degree(190.0)).value(), -170.0, 1e-12);
  // Upper bound is inclusive.
  EXPECT_NEAR(wrap_signed(Degree(180.0)).value(), 180.0, 1e-12);
}

TEST_F(AngleHelpersTest, WrapSignedLo) {
  // Lower bound inclusive, upper bound exclusive: +180 folds to -180.
  EXPECT_NEAR(wrap_signed_lo(Degree(180.0)).value(), -180.0, 1e-12);
}

TEST_F(AngleHelpersTest, WrapQuarterFold) {
  EXPECT_NEAR(wrap_quarter_fold(Degree(100.0)).value(), 80.0, 1e-12);
  EXPECT_NEAR(wrap_quarter_fold(Degree(-100.0)).value(), -80.0, 1e-12);
}

TEST_F(AngleHelpersTest, Separation) {
  EXPECT_NEAR(abs_separation(Degree(45.0), Degree(350.0)).value(), 55.0, 1e-12);
  EXPECT_NEAR(signed_separation(Degree(10.0), Degree(350.0)).value(), 20.0, 1e-12);
}

TEST_F(AngleHelpersTest, RadianFullTurn) {
  EXPECT_NEAR(angular_full_turn<RadianTag>(), 2.0 * M_PI, 1e-12);
  EXPECT_NEAR(angular_full_turn<DegreeTag>(), 360.0, 1e-9);
}
