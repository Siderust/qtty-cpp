// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

/**
 * @file angles.hpp
 * @brief Angle wrapping and separation helpers, mirroring the angular methods
 *        on the Rust `Quantity<U: AngularUnit>` (`qtty_core::angular`).
 *
 * These are provided as free functions templated on the angular unit tag, and
 * are SFINAE-constrained to the angular units only. The full-turn magnitude in
 * the target unit is obtained through the FFI conversion of 2π radians, so the
 * helpers are exact in every supported angular unit.
 */

#include <cmath>
#include <type_traits>

#include "ffi_core.hpp"
#include "units/angular.hpp"

namespace qtty {

/// Trait marking a tag as an angular unit. Only angular units expose the
/// wrapping / separation helpers below.
template <class Tag> struct AngularTraits {
  static constexpr bool is_angular = false;
};

#define QTTY_MARK_ANGULAR(Tag)                                                                     \
  template <> struct AngularTraits<Tag> {                                                          \
    static constexpr bool is_angular = true;                                                       \
  }

QTTY_MARK_ANGULAR(MilliradianTag);
QTTY_MARK_ANGULAR(RadianTag);
QTTY_MARK_ANGULAR(MicroArcsecondTag);
QTTY_MARK_ANGULAR(MilliArcsecondTag);
QTTY_MARK_ANGULAR(ArcsecondTag);
QTTY_MARK_ANGULAR(ArcminuteTag);
QTTY_MARK_ANGULAR(DegreeTag);
QTTY_MARK_ANGULAR(GradianTag);
QTTY_MARK_ANGULAR(TurnTag);
QTTY_MARK_ANGULAR(HourAngleTag);

#undef QTTY_MARK_ANGULAR

template <class Tag> inline constexpr bool is_angular_v = AngularTraits<Tag>::is_angular;

namespace detail {

inline double rem_euclid(double a, double b) {
  double r = std::fmod(a, b);
  return (r < 0.0) ? r + std::abs(b) : r;
}

} // namespace detail

/// Magnitude of one full revolution expressed in the angular unit @c Tag.
template <class Tag, class = std::enable_if_t<is_angular_v<Tag>>>
inline double angular_full_turn() {
  constexpr double tau = 6.283185307179586476925286766559;
  return Quantity<RadianTag>(tau).template to<Tag>().value();
}

/// Wrap into the canonical positive range `[0, FULL_TURN)`.
template <class Tag, class = std::enable_if_t<is_angular_v<Tag>>>
inline Quantity<Tag> wrap_pos(Quantity<Tag> a) {
  return Quantity<Tag>(detail::rem_euclid(a.value(), angular_full_turn<Tag>()));
}

/// Alias of @ref wrap_pos: normalize into `[0, FULL_TURN)`.
template <class Tag, class = std::enable_if_t<is_angular_v<Tag>>>
inline Quantity<Tag> normalize(Quantity<Tag> a) {
  return wrap_pos(a);
}

/// Wrap into the signed range `(-HALF_TURN, HALF_TURN]`.
template <class Tag, class = std::enable_if_t<is_angular_v<Tag>>>
inline Quantity<Tag> wrap_signed(Quantity<Tag> a) {
  double full = angular_full_turn<Tag>();
  double half = 0.5 * full;
  double y = detail::rem_euclid(a.value() + half, full) - half;
  double norm = (y <= -half) ? y + full : y;
  return Quantity<Tag>(norm);
}

/// Wrap into the alternate signed range `[-HALF_TURN, HALF_TURN)`.
template <class Tag, class = std::enable_if_t<is_angular_v<Tag>>>
inline Quantity<Tag> wrap_signed_lo(Quantity<Tag> a) {
  double full = angular_full_turn<Tag>();
  double half = 0.5 * full;
  double y = wrap_signed(a).value();
  if (y >= half) {
    y -= full;
  }
  return Quantity<Tag>(y);
}

/// "Latitude fold": map into `[-QUARTER_TURN, +QUARTER_TURN]`.
template <class Tag, class = std::enable_if_t<is_angular_v<Tag>>>
inline Quantity<Tag> wrap_quarter_fold(Quantity<Tag> a) {
  double full = angular_full_turn<Tag>();
  double half = 0.5 * full;
  double quarter = 0.25 * full;
  double y = detail::rem_euclid(a.value() + quarter, full);
  return Quantity<Tag>(quarter - std::abs(y - half));
}

/// Signed smallest angular separation in `(-HALF_TURN, HALF_TURN]`.
template <class Tag, class = std::enable_if_t<is_angular_v<Tag>>>
inline Quantity<Tag> signed_separation(Quantity<Tag> a, Quantity<Tag> b) {
  return wrap_signed(a - b);
}

/// Absolute smallest angular separation (magnitude only).
template <class Tag, class = std::enable_if_t<is_angular_v<Tag>>>
inline Quantity<Tag> abs_separation(Quantity<Tag> a, Quantity<Tag> b) {
  return Quantity<Tag>(std::abs(signed_separation(a, b).value()));
}

} // namespace qtty
