// SPDX-License-Identifier: AGPL-3.0-or-later
// Copyright (C) 2026 Vallés Puig, Ramon

#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct MilliradianTag {};
struct RadianTag {};
struct MicroArcsecondTag {};
struct MilliArcsecondTag {};
struct ArcsecondTag {};
struct ArcminuteTag {};
struct DegreeTag {};
struct GradianTag {};
struct TurnTag {};
struct HourAngleTag {};

template<> struct UnitTraits<MilliradianTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MILLIRADIAN; }
};
template<> struct UnitTraits<RadianTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_RADIAN; }
};
template<> struct UnitTraits<MicroArcsecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MICRO_ARCSECOND; }
};
template<> struct UnitTraits<MilliArcsecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MILLI_ARCSECOND; }
};
template<> struct UnitTraits<ArcsecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_ARCSECOND; }
};
template<> struct UnitTraits<ArcminuteTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_ARCMINUTE; }
};
template<> struct UnitTraits<DegreeTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_DEGREE; }
};
template<> struct UnitTraits<GradianTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_GRADIAN; }
};
template<> struct UnitTraits<TurnTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_TURN; }
};
template<> struct UnitTraits<HourAngleTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_HOUR_ANGLE; }
};

using Milliradian = Quantity<MilliradianTag>;
using Radian = Quantity<RadianTag>;
using MicroArcsecond = Quantity<MicroArcsecondTag>;
using MilliArcsecond = Quantity<MilliArcsecondTag>;
using Arcsecond = Quantity<ArcsecondTag>;
using Arcminute = Quantity<ArcminuteTag>;
using Degree = Quantity<DegreeTag>;
using Gradian = Quantity<GradianTag>;
using Turn = Quantity<TurnTag>;
using HourAngle = Quantity<HourAngleTag>;

} // namespace qtty
