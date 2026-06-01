// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

/**
 * @file astronomy.cpp
 * @example astronomy.cpp
 * @brief Astronomy-flavoured example using AU, light-years, and an orbital
 *        velocity estimate.
 *
 * Mirrors qtty/examples/astronomy.rs.
 */

#include "qtty/qtty.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace qtty;

int main() {
  Velocity<Kilometer, Second> earth_velocity(29.78);
  Second time_sec = Day(1.0).to<Second>();
  Kilometer distance(earth_velocity.value() * time_sec.value());
  assert(std::abs(distance.value() - 2'573'395.2) < 5'000.0);
  std::cout << "Earth travels " << distance << " per day\n";

  LightYear proxima(4.24);
  AstronomicalUnit au = proxima.to<AstronomicalUnit>();
  assert(au.value() > 200'000.0);
  std::cout << "Proxima Centauri: " << proxima << " = " << au << '\n';

  return 0;
}
