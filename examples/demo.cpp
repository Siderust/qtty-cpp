// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

/**
 * @file demo.cpp
 * @example demo.cpp
 * @brief Demonstrates the qtty-cpp quantity API.
 *
 * Covers all supported dimensions: length, time, angular, mass, power,
 * area, volume, acceleration, force, and energy.
 */

#include "qtty/qtty.hpp"
#include <iomanip>
#include <iostream>

using namespace qtty;

int main() {
  std::cout << "=== qtty-cpp Demo ===" << std::endl;
  std::cout << "FFI ABI Version: " << abi_version() << "\n" << std::endl;

  // Example 1: Basic construction and conversion
  std::cout << "1. Distance Conversion:" << std::endl;
  Meter distance(1500.0);
  std::cout << "   Distance: " << distance << std::endl;

  Kilometer km = distance.to<Kilometer>();
  std::cout << "   Distance: " << km << std::endl;

  // Example 2: Using literals
  std::cout << "\n2. Using Literals:" << std::endl;
  auto height = 10.5_m;
  auto width = 5.0_m;
  auto area_side = height + width;
  std::cout << "   Height: " << height << std::endl;
  std::cout << "   Width: " << width << std::endl;
  std::cout << "   Sum: " << area_side << std::endl;

  // Example 3: Velocity calculation
  std::cout << "\n3. Velocity Calculation:" << std::endl;
  auto car_distance = 100.0_km;
  auto travel_time = 2.0_h;
  auto speed = car_distance / travel_time;
  std::cout << "   Distance: " << car_distance << std::endl;
  std::cout << "   Time: " << travel_time << std::endl;
  std::cout << "   Speed: " << speed << std::endl;

  // Example 4: Angular conversions
  std::cout << "\n4. Angular Conversions:" << std::endl;
  auto angle_deg = 180.0_deg;
  Radian angle_rad = angle_deg.to<Radian>();
  std::cout << "   Angle: " << angle_deg << std::endl;
  std::cout << std::setprecision(6);
  std::cout << "   Angle: " << angle_rad << std::endl;

  // Example 5: Time conversions
  std::cout << "\n5. Time Conversions:" << std::endl;
  auto duration_seconds = 3665.0_s;
  Hour duration_hours = duration_seconds.to<Hour>();
  Minute duration_minutes = duration_seconds.to<Minute>();
  std::cout << "   Duration: " << duration_seconds << std::endl;
  std::cout << std::setprecision(4);
  std::cout << "   Duration: " << duration_hours << std::endl;
  std::cout << std::setprecision(2);
  std::cout << "   Duration: " << duration_minutes << std::endl;

  // Example 6: Compound operations
  std::cout << "\n6. Compound Operations:" << std::endl;
  Meter total(100.0);
  std::cout << "   Initial: " << total << std::endl;

  total += 50.0_m;
  std::cout << "   After += 50m: " << total << std::endl;

  total *= 2.0;
  std::cout << "   After *= 2: " << total << std::endl;

  total /= 3.0;
  std::cout << std::setprecision(2) << std::fixed;
  std::cout << "   After /= 3: " << total << std::endl;

  // Example 7: Comparisons
  std::cout << "\n7. Comparisons:" << std::endl;
  auto length1 = 10.0_m;
  auto length2 = 5.0_m;
  std::cout << "   " << length1.value() << "m > " << length2.value() << "m? "
            << (length1 > length2 ? "Yes" : "No") << std::endl;
  std::cout << "   " << length1.value() << "m == " << length2.value() << "m? "
            << (length1 == length2 ? "Yes" : "No") << std::endl;

  // Example 8: Absolute value and negation
  std::cout << "\n8. Absolute Value and Negation:" << std::endl;
  Meter negative(-42.5);
  auto positive = negative.abs();
  auto double_negative = -negative;
  std::cout << "   Original: " << negative << std::endl;
  std::cout << "   Absolute: " << positive << std::endl;
  std::cout << "   Negated: " << double_negative << std::endl;

  // Example 9: Area conversions
  std::cout << std::defaultfloat << std::setprecision(6);
  std::cout << "\n9. Area Conversions:" << std::endl;
  SquareMeter plot(10000.0);
  Hectare plot_ha = plot.to<Hectare>();
  SquareKilometer plot_km2 = plot.to<SquareKilometer>();
  std::cout << "   Plot: " << plot << std::endl;
  std::cout << "   Plot: " << plot_ha << std::endl;
  std::cout << "   Plot: " << plot_km2 << std::endl;

  // Example 10: Volume conversions
  std::cout << "\n10. Volume Conversions:" << std::endl;
  Liter bottle(1.5);
  CubicMeter bottle_m3 = bottle.to<CubicMeter>();
  Milliliter bottle_ml = bottle.to<Milliliter>();
  std::cout << "    Bottle: " << bottle << std::endl;
  std::cout << "    Bottle: " << bottle_m3 << std::endl;
  std::cout << "    Bottle: " << bottle_ml << std::endl;

  // Example 11: Force and acceleration
  std::cout << "\n11. Force and Acceleration:" << std::endl;
  Kilogram mass(70.0);
  MeterPerSecondSquared accel(9.81);
  Newton force_n(mass.value() * accel.value());
  Kilonewton force_kn = force_n.to<Kilonewton>();
  std::cout << "    Mass: " << mass << std::endl;
  std::cout << "    Acceleration: " << accel << std::endl;
  std::cout << "    Force: " << force_n << std::endl;
  std::cout << "    Force: " << force_kn << std::endl;

  // Example 12: Energy conversions
  std::cout << "\n12. Energy Conversions:" << std::endl;
  Kilojoule energy_kj(1.0);
  Joule energy_j = energy_kj.to<Joule>();
  Kilocalorie energy_kcal = energy_j.to<Kilocalorie>();
  Electronvolt energy_ev = energy_j.to<Electronvolt>();
  std::cout << "    Energy: " << energy_kj << std::endl;
  std::cout << "    Energy: " << energy_j << std::endl;
  std::cout << "    Energy: " << energy_kcal << std::endl;
  std::cout << std::setprecision(4) << std::scientific;
  std::cout << "    Energy: " << energy_ev << std::endl;

  std::cout << std::defaultfloat;
  std::cout << "\n=== All examples completed successfully! ===" << std::endl;

  return 0;
}
