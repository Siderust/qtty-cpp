#pragma once

#include "../ffi_core.hpp"

namespace qtty {

struct YoctogramTag {};
struct ZeptogramTag {};
struct AttogramTag {};
struct FemtogramTag {};
struct PicogramTag {};
struct NanogramTag {};
struct MicrogramTag {};
struct MilligramTag {};
struct CentigramTag {};
struct DecigramTag {};
struct GramTag {};
struct DecagramTag {};
struct HectogramTag {};
struct KilogramTag {};
struct MegagramTag {};
struct GigagramTag {};
struct TeragramTag {};
struct PetagramTag {};
struct ExagramTag {};
struct ZettagramTag {};
struct YottagramTag {};
struct GrainTag {};
struct OunceTag {};
struct PoundTag {};
struct StoneTag {};
struct ShortTonTag {};
struct LongTonTag {};
struct CaratTag {};
struct TonneTag {};
struct AtomicMassUnitTag {};
struct SolarMassTag {};

template<> struct UnitTraits<YoctogramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_YOCTOGRAM; }
    static constexpr std::string_view symbol() { return "yg"; }
};
template<> struct UnitTraits<ZeptogramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_ZEPTOGRAM; }
    static constexpr std::string_view symbol() { return "zg"; }
};
template<> struct UnitTraits<AttogramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_ATTOGRAM; }
    static constexpr std::string_view symbol() { return "ag"; }
};
template<> struct UnitTraits<FemtogramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_FEMTOGRAM; }
    static constexpr std::string_view symbol() { return "fg"; }
};
template<> struct UnitTraits<PicogramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_PICOGRAM; }
    static constexpr std::string_view symbol() { return "pg"; }
};
template<> struct UnitTraits<NanogramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_NANOGRAM; }
    static constexpr std::string_view symbol() { return "ng"; }
};
template<> struct UnitTraits<MicrogramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MICROGRAM; }
    static constexpr std::string_view symbol() { return "µg"; }
};
template<> struct UnitTraits<MilligramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MILLIGRAM; }
    static constexpr std::string_view symbol() { return "mg"; }
};
template<> struct UnitTraits<CentigramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_CENTIGRAM; }
    static constexpr std::string_view symbol() { return "cg"; }
};
template<> struct UnitTraits<DecigramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_DECIGRAM; }
    static constexpr std::string_view symbol() { return "dg"; }
};
template<> struct UnitTraits<GramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_GRAM; }
    static constexpr std::string_view symbol() { return "g"; }
};
template<> struct UnitTraits<DecagramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_DECAGRAM; }
    static constexpr std::string_view symbol() { return "dag"; }
};
template<> struct UnitTraits<HectogramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_HECTOGRAM; }
    static constexpr std::string_view symbol() { return "hg"; }
};
template<> struct UnitTraits<KilogramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_KILOGRAM; }
    static constexpr std::string_view symbol() { return "kg"; }
};
template<> struct UnitTraits<MegagramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_MEGAGRAM; }
    static constexpr std::string_view symbol() { return "Mg"; }
};
template<> struct UnitTraits<GigagramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_GIGAGRAM; }
    static constexpr std::string_view symbol() { return "Gg"; }
};
template<> struct UnitTraits<TeragramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_TERAGRAM; }
    static constexpr std::string_view symbol() { return "Tg"; }
};
template<> struct UnitTraits<PetagramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_PETAGRAM; }
    static constexpr std::string_view symbol() { return "Pg"; }
};
template<> struct UnitTraits<ExagramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_EXAGRAM; }
    static constexpr std::string_view symbol() { return "Eg"; }
};
template<> struct UnitTraits<ZettagramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_ZETTAGRAM; }
    static constexpr std::string_view symbol() { return "Zg"; }
};
template<> struct UnitTraits<YottagramTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_YOTTAGRAM; }
    static constexpr std::string_view symbol() { return "Yg"; }
};
template<> struct UnitTraits<GrainTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_GRAIN; }
    static constexpr std::string_view symbol() { return "gr"; }
};
template<> struct UnitTraits<OunceTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_OUNCE; }
    static constexpr std::string_view symbol() { return "oz"; }
};
template<> struct UnitTraits<PoundTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_POUND; }
    static constexpr std::string_view symbol() { return "lb"; }
};
template<> struct UnitTraits<StoneTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_STONE; }
    static constexpr std::string_view symbol() { return "st"; }
};
template<> struct UnitTraits<ShortTonTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_SHORT_TON; }
    static constexpr std::string_view symbol() { return "ton"; }
};
template<> struct UnitTraits<LongTonTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_LONG_TON; }
    static constexpr std::string_view symbol() { return "ton_l"; }
};
template<> struct UnitTraits<CaratTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_CARAT; }
    static constexpr std::string_view symbol() { return "ct"; }
};
template<> struct UnitTraits<TonneTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_TONNE; }
    static constexpr std::string_view symbol() { return "t"; }
};
template<> struct UnitTraits<AtomicMassUnitTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_ATOMIC_MASS_UNIT; }
    static constexpr std::string_view symbol() { return "u"; }
};
template<> struct UnitTraits<SolarMassTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_SOLAR_MASS; }
    static constexpr std::string_view symbol() { return "M_☉"; }
};

using Yoctogram = Quantity<YoctogramTag>;
using Zeptogram = Quantity<ZeptogramTag>;
using Attogram = Quantity<AttogramTag>;
using Femtogram = Quantity<FemtogramTag>;
using Picogram = Quantity<PicogramTag>;
using Nanogram = Quantity<NanogramTag>;
using Microgram = Quantity<MicrogramTag>;
using Milligram = Quantity<MilligramTag>;
using Centigram = Quantity<CentigramTag>;
using Decigram = Quantity<DecigramTag>;
using Gram = Quantity<GramTag>;
using Decagram = Quantity<DecagramTag>;
using Hectogram = Quantity<HectogramTag>;
using Kilogram = Quantity<KilogramTag>;
using Megagram = Quantity<MegagramTag>;
using Gigagram = Quantity<GigagramTag>;
using Teragram = Quantity<TeragramTag>;
using Petagram = Quantity<PetagramTag>;
using Exagram = Quantity<ExagramTag>;
using Zettagram = Quantity<ZettagramTag>;
using Yottagram = Quantity<YottagramTag>;
using Grain = Quantity<GrainTag>;
using Ounce = Quantity<OunceTag>;
using Pound = Quantity<PoundTag>;
using Stone = Quantity<StoneTag>;
using ShortTon = Quantity<ShortTonTag>;
using LongTon = Quantity<LongTonTag>;
using Carat = Quantity<CaratTag>;
using Tonne = Quantity<TonneTag>;
using AtomicMassUnit = Quantity<AtomicMassUnitTag>;
using SolarMass = Quantity<SolarMassTag>;

} // namespace qtty
