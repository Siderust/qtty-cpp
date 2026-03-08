// SPDX-License-Identifier: AGPL-3.0-or-later
// Copyright (C) 2026 Vallés Puig, Ramon

/**
 * @file serialization.cpp
 * @example serialization.cpp
 * @brief Demonstrates JSON serialization and deserialization of qtty quantities.
 *
 * Requires the qtty-ffi library built with the `serde` Cargo feature:
 *
 *   cmake -B build -DQTTY_FFI_FEATURES=serde && cmake --build build
 *   ./build/serialization
 *
 * Features shown:
 *  - Compact value-only JSON via `to_json_value` / `from_json_value`
 *  - Self-documenting JSON (value + unit) via `to_json` / `from_json`
 *  - DerivedQuantity JSON round-trip
 *  - Constructing quantities from external JSON payloads
 */

#include "qtty/qtty.hpp"
#include "qtty/serialization.hpp"
#include <cassert>
#include <iomanip>
#include <iostream>

using namespace qtty;
using namespace qtty::serialization;

int main() {
  std::cout << "=== qtty-cpp Serialization Demo ===" << std::endl;
  std::cout << "FFI ABI Version: " << abi_version() << "\n" << std::endl;

  // ── 1. Value-only JSON ──────────────────────────────────────────────────
  std::cout << "1. Value-only JSON (compact, default serde format):" << std::endl;

  auto distance = Meter(42.5);
  auto time     = Second(9.58);
  auto mass     = Kilogram(70.0);

  std::string json_d = to_json_value(distance);
  std::string json_t = to_json_value(time);
  std::string json_m = to_json_value(mass);

  std::cout << "   " << distance << " → " << json_d << std::endl;
  std::cout << "   " << time     << " → " << json_t << std::endl;
  std::cout << "   " << mass     << " → " << json_m << std::endl;

  // Deserialize back
  Meter  d_rt  = from_json_value<Meter>(json_d);
  Second t_rt  = from_json_value<Second>(json_t);
  Kilogram m_rt = from_json_value<Kilogram>(json_m);

  std::cout << "   (restored) " << d_rt << ", " << t_rt << ", " << m_rt << std::endl;
  assert(std::abs(d_rt.value() - 42.5)  < 1e-9);
  assert(std::abs(t_rt.value() - 9.58)  < 1e-9);
  assert(std::abs(m_rt.value() - 70.0)  < 1e-9);

  // ── 2. Self-documenting JSON (value + unit name) ────────────────────────
  std::cout << "\n2. Self-documenting JSON (value + unit name):" << std::endl;

  auto wavelength = Nanometer(656.3);   // Hα spectral line
  auto period     = Hour(24.0);

  std::string full_d = to_json(wavelength);
  std::string full_t = to_json(period);

  std::cout << "   " << wavelength << " → " << full_d << std::endl;
  std::cout << "   " << period     << " → " << full_t << std::endl;

  // Round-trip
  Nanometer wl_rt = from_json<Nanometer>(full_d);
  Hour      p_rt  = from_json<Hour>(full_t);

  std::cout << "   (restored) " << wl_rt << ", " << p_rt << std::endl;
  assert(std::abs(wl_rt.value() - 656.3) < 1e-6);
  assert(std::abs(p_rt.value()  - 24.0)  < 1e-9);

  // ── 3. DerivedQuantity JSON round-trip ─────────────────────────────────────
  std::cout << "\n3. DerivedQuantity JSON (velocity = length / time):" << std::endl;

  auto velocity = MeterPerSecond(343.0);  // speed of sound in air at 20 °C
  std::string vel_json = derived_serialization::to_json(velocity);
  std::cout << "   " << velocity << " → " << vel_json << std::endl;

  MeterPerSecond vel_rt = derived_serialization::from_json<MeterPerSecond>(vel_json);
  std::cout << "   (restored) " << vel_rt << std::endl;
  assert(std::abs(vel_rt.value() - 343.0) < 1e-9);

  // ── 4. Consuming external JSON payloads ─────────────────────────────────────
  std::cout << "\n4. External JSON payloads:" << std::endl;

  // Value-only
  const std::string ext_val = "1.496e+11";          // 1 AU in metres
  Meter au_m = from_json_value<Meter>(ext_val);
  Kilometer au_km = au_m.to<Kilometer>();
  std::cout << std::fixed << std::setprecision(3);
  std::cout << "   1 AU from JSON → " << au_km << std::endl;

  // Self-documenting
  const std::string ext_full
      = R"({"value":3.085677581e+16,"unit":"Meter"})"; // 1 parsec
  Meter pc_m = from_json<Meter>(ext_full);
  std::cout << std::scientific << std::setprecision(4);
  std::cout << "   1 pc from JSON → " << pc_m << std::endl;

  std::cout << "\n=== Serialization demo completed successfully ===" << std::endl;
  return 0;
}
