// SPDX-License-Identifier: AGPL-3.0-or-later
// Copyright (C) 2026 Vallés Puig, Ramon

#include "fixtures.hpp"

TEST_F(DerivedQuantityTest, VelocityCreation) {
  Meter distance(100.0);
  Second time(20.0);
  auto velocity = distance / time;

  EXPECT_NEAR(velocity.value(), 5.0, 1e-12);

  Velocity<Meter, Second> v1(10.0);
  EXPECT_EQ(v1.value(), 10.0);
}

TEST_F(DerivedQuantityTest, VelocityConversion) {
  // 100 m/s should be 360 km/h
  MeterPerSecond v_ms(100.0);
  auto v_kmh = v_ms.to<KilometerPerHour>();
  EXPECT_NEAR(v_kmh.value(), 360.0, 1e-9);

  // Round-trip: 360 km/h → m/s
  auto v_back = v_kmh.to<MeterPerSecond>();
  EXPECT_NEAR(v_back.value(), 100.0, 1e-9);
}

TEST_F(DerivedQuantityTest, VelocityConversionKmToM) {
  // 1 km/s should be 3600 km/h
  KilometerPerSecond v_ks(1.0);
  auto v_kmh = v_ks.to<KilometerPerHour>();
  EXPECT_NEAR(v_kmh.value(), 3600.0, 1e-9);
}

TEST_F(DerivedQuantityTest, VelocityArithmetic) {
  MeterPerSecond v1(10.0);
  MeterPerSecond v2(5.0);

  auto sum = v1 + v2;
  EXPECT_NEAR(sum.value(), 15.0, 1e-12);

  auto diff = v1 - v2;
  EXPECT_NEAR(diff.value(), 5.0, 1e-12);

  auto scaled = v1 * 3.0;
  EXPECT_NEAR(scaled.value(), 30.0, 1e-12);
}

TEST_F(DerivedQuantityTest, VelocityFromDivision) {
  // Create velocity from actual division
  Kilometer dist(180.0);
  Hour t(2.0);
  auto v = dist / t;  // type: KilometerPerHour

  EXPECT_NEAR(v.value(), 90.0, 1e-12);

  // Convert to m/s
  auto v_ms = v.to<MeterPerSecond>();
  EXPECT_NEAR(v_ms.value(), 25.0, 1e-9);
}
