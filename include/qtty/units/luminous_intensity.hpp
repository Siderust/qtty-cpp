// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct CandelaTag {};

template <> struct UnitTraits<CandelaTag> {
  static constexpr UnitId unit_id() { return UNIT_ID_CANDELA; }
  static constexpr std::string_view symbol() { return "cd"; }
};

using Candela = Quantity<CandelaTag>;

} // namespace qtty
