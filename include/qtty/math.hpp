// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

/**
 * @file math.hpp
 * @brief Dimension-aware math helpers mirroring the Rust `Quantity` API.
 *
 * These mirror the Rust methods that change the dimension of the result and
 * therefore cannot live as plain members of `Quantity` (which is unit-tag
 * agnostic). They are provided as free functions:
 *
 *   Rust                         C++
 *   q.ratio_to(other)            qtty::ratio_to(q, other)
 *   q.exp()                      qtty::exp(q)
 *   q.ln()                       qtty::ln(q)
 *   q.powi(n)                    qtty::powi(q, n)
 *   q.powf(exp)                  qtty::powf(q, exp)
 *   q.asin_angle()               qtty::asin_angle(q)
 *   q.acos_angle()               qtty::acos_angle(q)
 *   q.atan_angle()               qtty::atan_angle(q)
 *
 * The transcendental helpers are constrained to dimensionless inputs, matching
 * the Rust trait bounds (`U: Unit<Dim = Dimensionless>`).
 */

#include <cmath>
#include <type_traits>

#include "units/angular.hpp"
#include "units/dimensionless.hpp"

namespace qtty {

/**
 * @brief Same-unit division returning a typed dimensionless `Ratio`.
 *
 * Mirrors Rust `Quantity::ratio_to`. Unlike `operator/` (which returns a raw
 * scalar for same-unit division), this wraps the result in `Ratio`.
 */
template <typename U> Ratio ratio_to(const Quantity<U> &a, const Quantity<U> &b) {
  return Ratio(a.value() / b.value());
}

// ── Transcendental helpers on dimensionless quantities ──────────────────────

template <typename U, std::enable_if_t<is_dimensionless_v<U>, int> = 0>
Ratio exp(const Quantity<U> &q) {
  return Ratio(std::exp(q.value()));
}

template <typename U, std::enable_if_t<is_dimensionless_v<U>, int> = 0>
Ratio ln(const Quantity<U> &q) {
  return Ratio(std::log(q.value()));
}

template <typename U, std::enable_if_t<is_dimensionless_v<U>, int> = 0>
Ratio powi(const Quantity<U> &q, int n) {
  return Ratio(std::pow(q.value(), static_cast<double>(n)));
}

template <typename U, std::enable_if_t<is_dimensionless_v<U>, int> = 0>
Ratio powf(const Quantity<U> &q, const Ratio &exponent) {
  return Ratio(std::pow(q.value(), exponent.value()));
}

template <typename U, std::enable_if_t<is_dimensionless_v<U>, int> = 0>
Radian asin_angle(const Quantity<U> &q) {
  return Radian(std::asin(q.value()));
}

template <typename U, std::enable_if_t<is_dimensionless_v<U>, int> = 0>
Radian acos_angle(const Quantity<U> &q) {
  return Radian(std::acos(q.value()));
}

template <typename U, std::enable_if_t<is_dimensionless_v<U>, int> = 0>
Radian atan_angle(const Quantity<U> &q) {
  return Radian(std::atan(q.value()));
}

} // namespace qtty
