// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

/**
 * @file qtty.hpp
 * @brief Main header for the qtty C++ wrapper library
 *
 * This header provides a modern, type-safe C++ interface to the qtty-ffi
 * library. It includes:
 * - Template-based Quantity class with compile-time unit checking
 * - Operator overloading for natural arithmetic syntax
 * - User-defined literals for convenient quantity creation
 * - Support for length, time, angular, mass, power, area, volume,
 *   acceleration, force, energy, and compound (velocity) units
 *
 * Usage example:
 * @code
 * using namespace qtty;
 *
 * // Create quantities using constructors or literals
 * Meter distance(1000.0);
 * auto time = 20.0_s;
 *
 * // Perform arithmetic operations
 * auto doubled = distance * 2.0;
 *
 * // Convert units
 * Kilometer km = distance.to<Kilometer>();
 *
 * // Derived quantities (velocity)
 * auto velocity = distance / time;
 *
 * // New dimensions
 * Hectare field(2.5);
 * Newton force(9.8);
 * Joule energy(500.0);
 * @endcode
 */

// Core template definitions
#include "ffi_core.hpp"

// Unit-specific headers
#include "units/angular.hpp"
#include "units/length.hpp"
#include "units/mass.hpp"
#include "units/power.hpp"
#include "units/time.hpp"
#include "units/area.hpp"
#include "units/volume.hpp"
#include "units/acceleration.hpp"
#include "units/force.hpp"
#include "units/energy.hpp"
#include "units/velocity.hpp"

// User-defined literals
#include "literals.hpp"

namespace qtty {

/**
 * @brief Library version information
 */
inline constexpr struct {
  int major = 0;
  int minor = 3;
  int patch = 0;
} version;

/**
 * @brief Get the ABI version of the underlying qtty-ffi library
 * @return ABI version number
 */
inline uint32_t abi_version() { return qtty_ffi_version(); }

} // namespace qtty
