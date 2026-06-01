// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

/**
 * @file quickstart.cpp
 * @example quickstart.cpp
 * @brief Minimal end-to-end example: convert angles and compute a velocity.
 *
 * Mirrors qtty/examples/quickstart.rs.
 */

#include "qtty/qtty.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace qtty;

int main() {
  Degree a(180.0);
  Radian r = a.to<Radian>();
  assert(std::abs(r.value() - M_PI) < 1e-12);
  std::cout << a << " = " << r << '\n';

  Kilometer d(1000.0);
  Second t(100.0);
  Velocity<Kilometer, Second> v = d / t;
  assert(std::abs(v.value() - 10.0) < 1e-12);
  std::cout << d << " / " << t << " = " << v.value() << " km/s\n";

  return 0;
}
