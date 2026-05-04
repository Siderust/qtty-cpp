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
