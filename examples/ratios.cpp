// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

/**
 * @file ratios.cpp
 * @example ratios.cpp
 * @brief Derived-unit example: ratios and an angle from inverse trig.
 *
 * Mirrors qtty/examples/ratios.rs.
 */

#include "qtty/qtty.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace qtty;

int main() {
  // Same-unit ratio yields a dimensionless Ratio.
  double half = ratio_to(Meter(1.0), Meter(2.0)).value();
  assert(std::abs(half - 0.5) < 1e-12);
  std::cout << "1 m / 2 m = " << half << '\n';

  double ratio = ratio_to(Second(1.0), Second(1.0)).value();
  Radian angle(std::asin(ratio));
  assert(std::abs(angle.value() - M_PI / 2.0) < 1e-12);
  std::cout << "asin(1) = " << angle << '\n';

  return 0;
}
