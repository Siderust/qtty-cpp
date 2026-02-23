// SPDX-License-Identifier: AGPL-3.0-or-later
// Copyright (C) 2026 Vallés Puig, Ramon

#include "fixtures.hpp"

TEST_F(DerivedQuantityTest, VelocityCreation) {
    Meter distance(100.0);
    Second time(20.0);
    auto velocity = distance / time;

    EXPECT_NEAR(velocity.value(), 5.0, 1e-12);

    Velocity<Meter, Second> v1(10.0);
    EXPECT_EQ(v1.value(), 10.0);
}
