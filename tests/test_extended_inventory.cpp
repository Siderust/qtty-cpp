// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#include "fixtures.hpp"

TEST_F(QttyTest, PressureConversions) {
  Pascal pa = Bar(1.0).to<Pascal>();
  EXPECT_NEAR(pa.value(), 100000.0, 1e-9);
}

TEST_F(QttyTest, SolidAngleConversions) {
  SquareDegree sq_deg = Steradian(1.0).to<SquareDegree>();
  EXPECT_NEAR(sq_deg.value(), 3282.806350011744, 1e-9);
}

TEST_F(QttyTest, TemperatureConversions) {
  Kelvin k = Rankine(491.67).to<Kelvin>();
  EXPECT_NEAR(k.value(), 273.15, 1e-9);
}

TEST_F(QttyTest, FrequencyAndChemistryConversions) {
  Hertz hz = Kilohertz(1.25).to<Hertz>();
  EXPECT_NEAR(hz.value(), 1250.0, 1e-12);

  Mole mol = Millimole(1250.0).to<Mole>();
  EXPECT_NEAR(mol.value(), 1.25, 1e-12);
}

TEST_F(QttyTest, ElectricalAndDensityConversions) {
  Volt v = Millivolt(1000.0).to<Volt>();
  EXPECT_NEAR(v.value(), 1.0, 1e-12);

  KilogramPerCubicMeter rho =
      PoundPerCubicFoot(1.0).to<KilogramPerCubicMeter>();
  EXPECT_NEAR(rho.value(), 16.018463373, 1e-9);
}

TEST_F(QttyTest, RadiometryAndPhotometryConversions) {
  WattPerSquareMeterSteradian si = ErgPerSecondSquareCentimeterSteradian(1.0)
                                       .to<WattPerSquareMeterSteradian>();
  EXPECT_NEAR(si.value(), 1.0e-3, 1e-15);

  Lumen lm = Kilolumen(1.0).to<Lumen>();
  EXPECT_NEAR(lm.value(), 1000.0, 1e-12);

  Lux lx = Millilux(1000.0).to<Lux>();
  EXPECT_NEAR(lx.value(), 1.0, 1e-12);
}

TEST_F(QttyTest, DimensionlessUnits) {
  // All dimensionless units have ratio 1.0, so conversion is identity.
  OpticalDepth tau(0.5);
  EXPECT_NEAR(tau.value(), 0.5, 1e-15);

  Airmass X(1.2);
  EXPECT_NEAR(X.value(), 1.2, 1e-15);

  Transmittance T(0.8);
  EXPECT_NEAR(T.value(), 0.8, 1e-15);

  Albedo A(0.3);
  EXPECT_NEAR(A.value(), 0.3, 1e-15);

  IlluminationFraction k(0.75);
  EXPECT_NEAR(k.value(), 0.75, 1e-15);

  Refractivity n(2.7e-4);
  EXPECT_NEAR(n.value(), 2.7e-4, 1e-18);

  // Conversion between dimensionless units is identity (same dimension, ratio 1).
  Airmass from_tau = tau.to<Airmass>();
  EXPECT_NEAR(from_tau.value(), 0.5, 1e-15);

  Transmittance from_albedo = A.to<Transmittance>();
  EXPECT_NEAR(from_albedo.value(), 0.3, 1e-15);
}
