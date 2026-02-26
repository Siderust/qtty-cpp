#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct AttosecondTag {};
struct FemtosecondTag {};
struct PicosecondTag {};
struct NanosecondTag {};
struct MicrosecondTag {};
struct MillisecondTag {};
struct CentisecondTag {};
struct DecisecondTag {};
struct SecondTag {};
struct DecasecondTag {};
struct HectosecondTag {};
struct KilosecondTag {};
struct MegasecondTag {};
struct GigasecondTag {};
struct TerasecondTag {};
struct MinuteTag {};
struct HourTag {};
struct DayTag {};
struct WeekTag {};
struct FortnightTag {};
struct YearTag {};
struct DecadeTag {};
struct CenturyTag {};
struct MillenniumTag {};
struct JulianYearTag {};
struct JulianCenturyTag {};
struct SiderealDayTag {};
struct SynodicMonthTag {};
struct SiderealYearTag {};

template<> struct UnitTraits<AttosecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_ATTOSECOND; }
    static constexpr std::string_view symbol() { return "as"; }
};
template<> struct UnitTraits<FemtosecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_FEMTOSECOND; }
    static constexpr std::string_view symbol() { return "fs"; }
};
template<> struct UnitTraits<PicosecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_PICOSECOND; }
    static constexpr std::string_view symbol() { return "ps"; }
};
template<> struct UnitTraits<NanosecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_NANOSECOND; }
    static constexpr std::string_view symbol() { return "ns"; }
};
template<> struct UnitTraits<MicrosecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MICROSECOND; }
    static constexpr std::string_view symbol() { return "µs"; }
};
template<> struct UnitTraits<MillisecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MILLISECOND; }
    static constexpr std::string_view symbol() { return "ms"; }
};
template<> struct UnitTraits<CentisecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_CENTISECOND; }
    static constexpr std::string_view symbol() { return "cs"; }
};
template<> struct UnitTraits<DecisecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_DECISECOND; }
    static constexpr std::string_view symbol() { return "ds"; }
};
template<> struct UnitTraits<SecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_SECOND; }
    static constexpr std::string_view symbol() { return "s"; }
};
template<> struct UnitTraits<DecasecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_DECASECOND; }
    static constexpr std::string_view symbol() { return "das"; }
};
template<> struct UnitTraits<HectosecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_HECTOSECOND; }
    static constexpr std::string_view symbol() { return "hs"; }
};
template<> struct UnitTraits<KilosecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_KILOSECOND; }
    static constexpr std::string_view symbol() { return "ks"; }
};
template<> struct UnitTraits<MegasecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MEGASECOND; }
    static constexpr std::string_view symbol() { return "Ms"; }
};
template<> struct UnitTraits<GigasecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_GIGASECOND; }
    static constexpr std::string_view symbol() { return "Gs"; }
};
template<> struct UnitTraits<TerasecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_TERASECOND; }
    static constexpr std::string_view symbol() { return "Ts"; }
};
template<> struct UnitTraits<MinuteTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MINUTE; }
    static constexpr std::string_view symbol() { return "min"; }
};
template<> struct UnitTraits<HourTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_HOUR; }
    static constexpr std::string_view symbol() { return "h"; }
};
template<> struct UnitTraits<DayTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_DAY; }
    static constexpr std::string_view symbol() { return "d"; }
};
template<> struct UnitTraits<WeekTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_WEEK; }
    static constexpr std::string_view symbol() { return "wk"; }
};
template<> struct UnitTraits<FortnightTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_FORTNIGHT; }
    static constexpr std::string_view symbol() { return "fn"; }
};
template<> struct UnitTraits<YearTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_YEAR; }
    static constexpr std::string_view symbol() { return "yr"; }
};
template<> struct UnitTraits<DecadeTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_DECADE; }
    static constexpr std::string_view symbol() { return "dec"; }
};
template<> struct UnitTraits<CenturyTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_CENTURY; }
    static constexpr std::string_view symbol() { return "c"; }
};
template<> struct UnitTraits<MillenniumTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MILLENNIUM; }
    static constexpr std::string_view symbol() { return "mill"; }
};
template<> struct UnitTraits<JulianYearTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_JULIAN_YEAR; }
    static constexpr std::string_view symbol() { return "a"; }
};
template<> struct UnitTraits<JulianCenturyTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_JULIAN_CENTURY; }
    static constexpr std::string_view symbol() { return "jc"; }
};
template<> struct UnitTraits<SiderealDayTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_SIDEREAL_DAY; }
    static constexpr std::string_view symbol() { return "sd"; }
};
template<> struct UnitTraits<SynodicMonthTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_SYNODIC_MONTH; }
    static constexpr std::string_view symbol() { return "mo_s"; }
};
template<> struct UnitTraits<SiderealYearTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_SIDEREAL_YEAR; }
    static constexpr std::string_view symbol() { return "yr_s"; }
};

using Attosecond = Quantity<AttosecondTag>;
using Femtosecond = Quantity<FemtosecondTag>;
using Picosecond = Quantity<PicosecondTag>;
using Nanosecond = Quantity<NanosecondTag>;
using Microsecond = Quantity<MicrosecondTag>;
using Millisecond = Quantity<MillisecondTag>;
using Centisecond = Quantity<CentisecondTag>;
using Decisecond = Quantity<DecisecondTag>;
using Second = Quantity<SecondTag>;
using Decasecond = Quantity<DecasecondTag>;
using Hectosecond = Quantity<HectosecondTag>;
using Kilosecond = Quantity<KilosecondTag>;
using Megasecond = Quantity<MegasecondTag>;
using Gigasecond = Quantity<GigasecondTag>;
using Terasecond = Quantity<TerasecondTag>;
using Minute = Quantity<MinuteTag>;
using Hour = Quantity<HourTag>;
using Day = Quantity<DayTag>;
using Week = Quantity<WeekTag>;
using Fortnight = Quantity<FortnightTag>;
using Year = Quantity<YearTag>;
using Decade = Quantity<DecadeTag>;
using Century = Quantity<CenturyTag>;
using Millennium = Quantity<MillenniumTag>;
using JulianYear = Quantity<JulianYearTag>;
using JulianCentury = Quantity<JulianCenturyTag>;
using SiderealDay = Quantity<SiderealDayTag>;
using SynodicMonth = Quantity<SynodicMonthTag>;
using SiderealYear = Quantity<SiderealYearTag>;

} // namespace qtty
