// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct S10Tag {};

template <> struct UnitTraits<S10Tag> {
  static constexpr UnitId unit_id() { return UNIT_ID_S10; }
  static constexpr std::string_view symbol() { return "S10"; }
};

using S10 = Quantity<S10Tag>;

} // namespace qtty
