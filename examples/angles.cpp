// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

/**
 * @file angles.cpp
 * @example angles.cpp
 * @brief Angle helpers example: wrapping and separation in a single unit type.
 *
 * Mirrors qtty/examples/angles.rs.
 */

#include "qtty/qtty.hpp"
#include <cassert>
#include <iostream>

using namespace qtty;

int main() {
  Degree a = wrap_signed(Degree(370.0));
  assert(a.value() == 10.0);
  std::cout << "wrap_signed(370 deg) = " << a << '\n';

  Degree s = abs_separation(Degree(45.0), Degree(350.0));
  assert(s.value() == 55.0);
  std::cout << "abs_separation(45 deg, 350 deg) = " << s << '\n';

  Arcsecond arcsec = Degree(1.0).to<Arcsecond>();
  assert(arcsec.value() == 3600.0);
  std::cout << "1 deg = " << arcsec << '\n';

  return 0;
}
