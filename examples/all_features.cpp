// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#include "qtty/qtty.hpp"
#include <iostream>

using namespace qtty;

int main() {
  std::cout << "qtty-cpp all-features sample\n";

  std::cout << "1 bar = " << Bar(1.0).to<Pascal>() << '\n';
  std::cout << "1 sr = " << Steradian(1.0).to<SquareDegree>() << '\n';
  std::cout << "491.67 R = " << Rankine(491.67).to<Kelvin>() << '\n';
  std::cout << "2.4 GHz = " << Gigahertz(2.4).to<Hertz>() << '\n';
  std::cout << "1250 mmol = " << Millimole(1250.0).to<Mole>() << '\n';
  std::cout << "1 mV = " << Millivolt(1.0).to<Volt>() << '\n';
  std::cout << "50 uT = " << Microtesla(50.0).to<Tesla>() << '\n';
  std::cout << "1 lb/ft^3 = " << PoundPerCubicFoot(1.0).to<KilogramPerCubicMeter>() << '\n';
  std::cout << "1 erg s^-1 cm^-2 sr^-1 = "
            << ErgPerSecondSquareCentimeterSteradian(1.0).to<WattPerSquareMeterSteradian>() << '\n';
  std::cout << "1 klm = " << Kilolumen(1.0).to<Lumen>() << '\n';
  std::cout << "500 mlx = " << Millilux(500.0).to<Lux>() << '\n';
  std::cout << "Surface brightness marker: " << S10(42.0) << '\n';
  std::cout << "1 kWh = " << KilowattHour(1.0).to<Joule>() << '\n';

  return 0;
}
