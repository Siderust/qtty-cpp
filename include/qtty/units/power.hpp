#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct YoctowattTag {};
struct ZeptowattTag {};
struct AttowattTag {};
struct FemtowattTag {};
struct PicowattTag {};
struct NanowattTag {};
struct MicrowattTag {};
struct MilliwattTag {};
struct DeciwattTag {};
struct WattTag {};
struct DecawattTag {};
struct HectowattTag {};
struct KilowattTag {};
struct MegawattTag {};
struct GigawattTag {};
struct TerawattTag {};
struct PetawattTag {};
struct ExawattTag {};
struct ZettawattTag {};
struct YottawattTag {};
struct ErgPerSecondTag {};
struct HorsepowerMetricTag {};
struct HorsepowerElectricTag {};
struct SolarLuminosityTag {};

template<> struct UnitTraits<YoctowattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_YOCTOWATT; }
    static constexpr std::string_view symbol() { return "yW"; }
};
template<> struct UnitTraits<ZeptowattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_ZEPTOWATT; }
    static constexpr std::string_view symbol() { return "zW"; }
};
template<> struct UnitTraits<AttowattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_ATTOWATT; }
    static constexpr std::string_view symbol() { return "aW"; }
};
template<> struct UnitTraits<FemtowattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_FEMTOWATT; }
    static constexpr std::string_view symbol() { return "fW"; }
};
template<> struct UnitTraits<PicowattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_PICOWATT; }
    static constexpr std::string_view symbol() { return "pW"; }
};
template<> struct UnitTraits<NanowattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_NANOWATT; }
    static constexpr std::string_view symbol() { return "nW"; }
};
template<> struct UnitTraits<MicrowattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MICROWATT; }
    static constexpr std::string_view symbol() { return "µW"; }
};
template<> struct UnitTraits<MilliwattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MILLIWATT; }
    static constexpr std::string_view symbol() { return "mW"; }
};
template<> struct UnitTraits<DeciwattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_DECIWATT; }
    static constexpr std::string_view symbol() { return "dW"; }
};
template<> struct UnitTraits<WattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_WATT; }
    static constexpr std::string_view symbol() { return "W"; }
};
template<> struct UnitTraits<DecawattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_DECAWATT; }
    static constexpr std::string_view symbol() { return "daW"; }
};
template<> struct UnitTraits<HectowattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_HECTOWATT; }
    static constexpr std::string_view symbol() { return "hW"; }
};
template<> struct UnitTraits<KilowattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_KILOWATT; }
    static constexpr std::string_view symbol() { return "kW"; }
};
template<> struct UnitTraits<MegawattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MEGAWATT; }
    static constexpr std::string_view symbol() { return "MW"; }
};
template<> struct UnitTraits<GigawattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_GIGAWATT; }
    static constexpr std::string_view symbol() { return "GW"; }
};
template<> struct UnitTraits<TerawattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_TERAWATT; }
    static constexpr std::string_view symbol() { return "TW"; }
};
template<> struct UnitTraits<PetawattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_PETAWATT; }
    static constexpr std::string_view symbol() { return "PW"; }
};
template<> struct UnitTraits<ExawattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_EXAWATT; }
    static constexpr std::string_view symbol() { return "EW"; }
};
template<> struct UnitTraits<ZettawattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_ZETTAWATT; }
    static constexpr std::string_view symbol() { return "ZW"; }
};
template<> struct UnitTraits<YottawattTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_YOTTAWATT; }
    static constexpr std::string_view symbol() { return "YW"; }
};
template<> struct UnitTraits<ErgPerSecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_ERG_PER_SECOND; }
    static constexpr std::string_view symbol() { return "erg/s"; }
};
template<> struct UnitTraits<HorsepowerMetricTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_HORSEPOWER_METRIC; }
    static constexpr std::string_view symbol() { return "PS"; }
};
template<> struct UnitTraits<HorsepowerElectricTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_HORSEPOWER_ELECTRIC; }
    static constexpr std::string_view symbol() { return "hp_e"; }
};
template<> struct UnitTraits<SolarLuminosityTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_SOLAR_LUMINOSITY; }
    static constexpr std::string_view symbol() { return "L_☉"; }
};

using Yoctowatt = Quantity<YoctowattTag>;
using Zeptowatt = Quantity<ZeptowattTag>;
using Attowatt = Quantity<AttowattTag>;
using Femtowatt = Quantity<FemtowattTag>;
using Picowatt = Quantity<PicowattTag>;
using Nanowatt = Quantity<NanowattTag>;
using Microwatt = Quantity<MicrowattTag>;
using Milliwatt = Quantity<MilliwattTag>;
using Deciwatt = Quantity<DeciwattTag>;
using Watt = Quantity<WattTag>;
using Decawatt = Quantity<DecawattTag>;
using Hectowatt = Quantity<HectowattTag>;
using Kilowatt = Quantity<KilowattTag>;
using Megawatt = Quantity<MegawattTag>;
using Gigawatt = Quantity<GigawattTag>;
using Terawatt = Quantity<TerawattTag>;
using Petawatt = Quantity<PetawattTag>;
using Exawatt = Quantity<ExawattTag>;
using Zettawatt = Quantity<ZettawattTag>;
using Yottawatt = Quantity<YottawattTag>;
using ErgPerSecond = Quantity<ErgPerSecondTag>;
using HorsepowerMetric = Quantity<HorsepowerMetricTag>;
using HorsepowerElectric = Quantity<HorsepowerElectricTag>;
using SolarLuminosity = Quantity<SolarLuminosityTag>;

} // namespace qtty
