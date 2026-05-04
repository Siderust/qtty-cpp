// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) 2026 Vallés Puig, Ramon

#include "fixtures.hpp"

TEST_F(DimensionSafetyTest, ExceptionHandling) {
  Meter m(100.0);

  EXPECT_THROW(
      {
        qtty_quantity_t qty;
        qtty_quantity_make(100.0, UNIT_ID_METER, &qty);
        qtty_quantity_t result;
        QttyStatus status = qtty_quantity_convert(qty, UNIT_ID_SECOND, &result);
        check_status(status, "Invalid conversion");
      },
      IncompatibleDimensionsError);
}
