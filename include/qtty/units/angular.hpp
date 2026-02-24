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
    static constexpr std::string_view symbol() { return "mrad"; }
};
template<> struct UnitTraits<RadianTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_RADIAN; }
    static constexpr std::string_view symbol() { return "rad"; }
};
template<> struct UnitTraits<MicroArcsecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MICRO_ARCSECOND; }
    static constexpr std::string_view symbol() { return "µas"; }
};
template<> struct UnitTraits<MilliArcsecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MILLI_ARCSECOND; }
    static constexpr std::string_view symbol() { return "mas"; }
};
template<> struct UnitTraits<ArcsecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_ARCSECOND; }
    static constexpr std::string_view symbol() { return "″"; }
};
template<> struct UnitTraits<ArcminuteTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_ARCMINUTE; }
    static constexpr std::string_view symbol() { return "′"; }
};
template<> struct UnitTraits<DegreeTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_DEGREE; }
    static constexpr std::string_view symbol() { return "°"; }
};
template<> struct UnitTraits<GradianTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_GRADIAN; }
    static constexpr std::string_view symbol() { return "gon"; }
};
template<> struct UnitTraits<TurnTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_TURN; }
    static constexpr std::string_view symbol() { return "tr"; }
};
template<> struct UnitTraits<HourAngleTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_HOUR_ANGLE; }
    static constexpr std::string_view symbol() { return "ʰ"; }
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
