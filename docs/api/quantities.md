# Quantity API Reference

This document provides a comprehensive reference for the `Quantity<UnitTag>` template class, the core abstraction in qtty-cpp.

## Table of Contents

- [Overview](#overview)
- [Template Class: Quantity](#template-class-quantity)
- [UnitTraits Contract](#unittraits-contract)
- [Exception Types](#exception-types)
- [User-Defined Literals](#user-defined-literals)
- [Usage Examples](#usage-examples)

## Overview

The `Quantity<UnitTag>` template provides type-safe physical quantities with compile-time unit checking. Each unit (Meter, Second, etc.) is a distinct instantiation of this template, preventing accidental mixing of incompatible units.

**Header**: [include/qtty/ffi_core.hpp](../../include/qtty/ffi_core.hpp)

## Template Class: Quantity

```cpp
template<typename UnitTag>
class Quantity;
```

### Template Parameters

| Parameter | Description |
|-----------|-------------|
| `UnitTag` | An empty tag struct identifying the unit (e.g., `MeterTag`, `SecondTag`) |

### Member Types

| Type | Description |
|------|-------------|
| `unit_tag` | Type alias for `UnitTag` |

### Constructors

#### Default Constructor

```cpp
constexpr Quantity();
```

Constructs a quantity with value 0.0.

**Line Reference**: Line 91 in [ffi_core.hpp](../../include/qtty/ffi_core.hpp)

**Example**:
```cpp
Meter m;  // m.value() == 0.0
```

#### Value Constructor

```cpp
constexpr explicit Quantity(double value);
```

Constructs a quantity with the specified value.

**Parameters**:
- `value` - The numeric value in this unit

**Line Reference**: Line 92 in [ffi_core.hpp](../../include/qtty/ffi_core.hpp)

**Example**:
```cpp
Meter m(10.5);  // m.value() == 10.5
```

Note: The `explicit` keyword prevents implicit conversions from `double`, enforcing clear intent:
```cpp
Meter m = 10.5;     // Error: explicit constructor
Meter m(10.5);      // OK
Meter m{10.5};      // OK (uniform initialization)
```

### Static Member Functions

#### unit_id()

```cpp
static constexpr UnitId unit_id();
```

Returns the C FFI unit identifier for this unit type.

**Line Reference**: Lines 95-97 in [ffi_core.hpp](../../include/qtty/ffi_core.hpp)

**Returns**: `UnitId` constant from the qtty_ffi.h header

**Example**:
```cpp
UnitId id = Meter::unit_id();  // Returns UNIT_ID_METER
```

This function delegates to `UnitTraits<UnitTag>::unit_id()`.

### Member Functions

#### value()

```cpp
constexpr double value() const;
```

Returns the raw numeric value of the quantity.

**Line Reference**: Lines 100-102 in [ffi_core.hpp](../../include/qtty/ffi_core.hpp)

**Returns**: The stored value as a `double`

**Example**:
```cpp
Meter m(42.0);
std::cout << m.value() << " m\n";  // Prints: 42 m
```

#### to<TargetType>()

```cpp
template<typename TargetType>
Quantity<typename ExtractTag<TargetType>::type> to() const;
```

Converts this quantity to a different unit of the same dimension.

**Line Reference**: Lines 105-118 in [ffi_core.hpp](../../include/qtty/ffi_core.hpp)

**Template Parameters**:
- `TargetType` - Can be either a tag type (e.g., `KilometerTag`) or a quantity type (e.g., `Kilometer`)

**Returns**: A new `Quantity` of the target type with converted value

**Throws**:
- `IncompatibleDimensionsError` - If units have different dimensions (e.g., length vs time)
- `ConversionError` - If the conversion produces an invalid value

**Example**:
```cpp
Meter m(1000.0);
Kilometer km = m.to<Kilometer>();  // km.value() == 1.0

// Both syntaxes are equivalent:
auto km1 = m.to<Kilometer>();      // Using Quantity type
auto km2 = m.to<KilometerTag>();   // Using Tag type
```

**Conversion Process**:
1. Create a `qtty_quantity_t` with the source value and unit ID
2. Call `qtty_quantity_convert()` from the FFI layer
3. Check status and throw exception if conversion fails
4. Return new `Quantity` with converted value

#### abs()

```cpp
Quantity abs() const;
```

Returns the absolute value of this quantity.

**Line Reference**: Lines 196-198 in [ffi_core.hpp](../../include/qtty/ffi_core.hpp)

**Returns**: A new `Quantity` with the absolute value

**Example**:
```cpp
Meter m(-10.5);
Meter positive = m.abs();  // positive.value() == 10.5
```

### Arithmetic Operators

#### Addition (same unit)

```cpp
Quantity operator+(const Quantity& other) const;
```

**Line Reference**: Lines 121-123 in [ffi_core.hpp](../../include/qtty/ffi_core.hpp)

**Example**:
```cpp
Meter a(10.0), b(5.0);
Meter sum = a + b;  // sum.value() == 15.0
```

#### Subtraction (same unit)

```cpp
Quantity operator-(const Quantity& other) const;
```

**Line Reference**: Lines 125-127 in [ffi_core.hpp](../../include/qtty/ffi_core.hpp)

**Example**:
```cpp
Meter a(10.0), b(3.0);
Meter diff = a - b;  // diff.value() == 7.0
```

#### Scalar Multiplication

```cpp
Quantity operator*(double scalar) const;
friend Quantity operator*(double scalar, const Quantity& q);
```

**Line Reference**: Lines 130-132, 139-141 in [ffi_core.hpp](../../include/qtty/ffi_core.hpp)

**Example**:
```cpp
Meter m(10.0);
Meter doubled = m * 2.0;      // 20.0 m
Meter tripled = 3.0 * m;      // 30.0 m (friend function)
```

#### Scalar Division

```cpp
Quantity operator/(double scalar) const;
```

**Line Reference**: Lines 134-136 in [ffi_core.hpp](../../include/qtty/ffi_core.hpp)

**Example**:
```cpp
Meter m(10.0);
Meter half = m / 2.0;  // 5.0 m
```

#### Quantity Division (creates compound units)

```cpp
template<typename LengthTag, typename TimeTag>
Quantity<CompoundTag<LengthTag, TimeTag>> operator/(
    const Quantity<LengthTag>& length,
    const Quantity<TimeTag>& time);
```

**Header**: [include/qtty/units/velocity.hpp](../../include/qtty/units/velocity.hpp) (lines 22-28)

**Example**:
```cpp
Meter distance(100.0);
Second time(20.0);
auto velocity = distance / time;  // Type: MeterPerSecond
```

See [Compound Units documentation](../architecture.md#compound-units-and-velocity) for details.

### Comparison Operators

All comparison operators work with quantities of the same unit type:

```cpp
bool operator==(const Quantity& other) const;  // Line 144
bool operator!=(const Quantity& other) const;  // Line 148
bool operator<(const Quantity& other) const;   // Line 152
bool operator>(const Quantity& other) const;   // Line 156
bool operator<=(const Quantity& other) const;  // Line 160
bool operator>=(const Quantity& other) const;  // Line 164
```

**Example**:
```cpp
Meter a(10.0), b(5.0), c(10.0);

bool eq = (a == c);   // true
bool ne = (a != b);   // true
bool lt = (b < a);    // true
bool gt = (a > b);    // true
bool le = (a <= c);   // true
bool ge = (a >= c);   // true
```

### Compound Assignment Operators

```cpp
Quantity& operator+=(const Quantity& other);  // Line 169
Quantity& operator-=(const Quantity& other);  // Line 174
Quantity& operator*=(double scalar);          // Line 179
Quantity& operator/=(double scalar);          // Line 184
```

**Example**:
```cpp
Meter m(10.0);

m += 5.0_m;   // m.value() == 15.0
m -= 3.0_m;   // m.value() == 12.0
m *= 2.0;     // m.value() == 24.0
m /= 4.0;     // m.value() == 6.0
```

### Unary Operators

#### Negation

```cpp
Quantity operator-() const;
```

**Line Reference**: Lines 190-192 in [ffi_core.hpp](../../include/qtty/ffi_core.hpp)

**Example**:
```cpp
Meter m(10.0);
Meter negated = -m;  // negated.value() == -10.0
```

## UnitTraits Contract

The `UnitTraits<>` template must be specialized for each unit tag to provide the FFI unit ID.

**Header**: [include/qtty/ffi_core.hpp](../../include/qtty/ffi_core.hpp) (lines 64-66)

### Template Specialization

```cpp
template<typename UnitTag>
struct UnitTraits;
```

### Required Member

```cpp
static constexpr UnitId unit_id();
```

Returns the C FFI constant for this unit (e.g., `UNIT_ID_METER`, `UNIT_ID_SECOND`).

### Example Specialization

```cpp
template<> struct UnitTraits<MeterTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_METER; }
};

template<> struct UnitTraits<SecondTag> {
    static constexpr UnitId unit_id() { return UNIT_ID_SECOND; }
};
```

**Location**: Generated headers in [include/qtty/units/](../../include/qtty/units/)

All `UnitTraits` specializations are automatically generated by [gen_cpp_units.py](../../gen_cpp_units.py).

## Exception Types

qtty-cpp uses a hierarchy of exception types for error handling. All exceptions derive from `std::runtime_error`.

**Header**: [include/qtty/ffi_core.hpp](../../include/qtty/ffi_core.hpp) (lines 14-35)

### QttyException

```cpp
class QttyException : public std::runtime_error;
```

Base class for all qtty-related exceptions.

**Line Reference**: Lines 14-17

### InvalidUnitError

```cpp
class InvalidUnitError : public QttyException;
```

Thrown when an unknown or invalid unit ID is encountered.

**Line Reference**: Lines 19-22

**Example**:
```cpp
// Manually creating an invalid unit ID in FFI calls
try {
    qtty_quantity_t qty;
    qtty_quantity_make(100.0, 99999, &qty);  // Invalid ID
    check_status(status, "Invalid unit");
} catch (const InvalidUnitError& e) {
    std::cerr << "Invalid unit: " << e.what() << '\n';
}
```

### IncompatibleDimensionsError

```cpp
class IncompatibleDimensionsError : public QttyException;
```

Thrown when attempting to convert between units of different dimensions.

**Line Reference**: Lines 24-27

**Example**:
```cpp
try {
    Meter m(100.0);
    Second s = m.to<Second>();  // Cannot convert length to time
} catch (const IncompatibleDimensionsError& e) {
    std::cerr << "Incompatible dimensions: " << e.what() << '\n';
    // Prints: Converting units failed: incompatible dimensions
}
```

### ConversionError

```cpp
class ConversionError : public QttyException;
```

Thrown when a conversion produces an invalid or out-of-range value.

**Line Reference**: Lines 29-32

**Example**:
```cpp
try {
    // Hypothetical case: conversion to a unit with restricted range
    // Real conversions typically don't throw this
} catch (const ConversionError& e) {
    std::cerr << "Conversion failed: " << e.what() << '\n';
}
```

### check_status()

```cpp
inline void check_status(int32_t status, const char* operation);
```

Helper function that translates C FFI status codes into C++ exceptions.

**Line Reference**: Lines 38-56 in [ffi_core.hpp](../../include/qtty/ffi_core.hpp)

**Parameters**:
- `status` - The status code returned by an FFI function
- `operation` - Descriptive text for error messages

**Throws**: Appropriate exception type based on status code

**Status Code Mapping**:

| FFI Status | C++ Exception |
|------------|---------------|
| `QTTY_OK` | (no exception) |
| `QTTY_ERR_UNKNOWN_UNIT` | `InvalidUnitError` |
| `QTTY_ERR_INCOMPATIBLE_DIM` | `IncompatibleDimensionsError` |
| `QTTY_ERR_NULL_OUT` | `QttyException` |
| `QTTY_ERR_INVALID_VALUE` | `ConversionError` |
| Other | `QttyException` |

## User-Defined Literals

User-defined literals provide intuitive syntax for creating quantities.

**Header**: [include/qtty/literals.hpp](../../include/qtty/literals.hpp)

### Literal Syntax

Literals are defined in an inline namespace for easy access:

```cpp
namespace qtty {
inline namespace literals {
    // Literal operators here
}
}
```

This allows:
```cpp
using namespace qtty;
auto distance = 10.0_m;  // No need for 'using namespace literals'
```

### Literal Operators

Each unit has two overloads to support both floating-point and integer literals:

```cpp
// Floating-point literal
constexpr Meter operator""_m(long double value) {
    return Meter(static_cast<double>(value));
}

// Integer literal
constexpr Meter operator""_m(unsigned long long value) {
    return Meter(static_cast<double>(value));
}
```

### Available Literals

#### Length Literals

| Literal | Unit | Example |
|---------|------|---------|
| `_m` | Meter | `10.0_m` |
| `_km` | Kilometer | `5.0_km` |
| `_mm` | Millimeter | `100.0_mm` |
| `_cm` | Centimeter | `50.0_cm` |
| `_um` | Micrometer | `500.0_um` |
| `_nm` | Nanometer | `750.0_nm` |
| `_in` | Inch | `12.0_in` |
| `_ft` | Foot | `3.0_ft` |
| `_mi` | Mile | `1.0_mi` |
| `_au` | Astronomical Unit | `1.0_au` |
| `_ly` | Light Year | `1.0_ly` |
| `_pc` | Parsec | `1.0_pc` |

#### Time Literals

| Literal | Unit | Example |
|---------|------|---------|
| `_s` | Second | `30.0_s` |
| `_min` | Minute | `5.0_min` |
| `_h` | Hour | `2.0_h` |
| `_day` | Day | `1.0_day` |
| `_ms` | Millisecond | `100.0_ms` |
| `_us` | Microsecond | `500.0_us` |
| `_ns` | Nanosecond | `1000.0_ns` |

#### Angular Literals

| Literal | Unit | Example |
|---------|------|---------|
| `_rad` | Radian | `3.14159_rad` |
| `_deg` | Degree | `90.0_deg` |
| `_arcmin` | Arcminute | `60.0_arcmin` |
| `_arcsec` | Arcsecond | `3600.0_arcsec` |

#### Mass Literals

| Literal | Unit | Example |
|---------|------|---------|
| `_kg` | Kilogram | `10.0_kg` |
| `_g` | Gram | `1000.0_g` |
| `_mg` | Milligram | `5000.0_mg` |
| `_ton` | Metric Ton | `1.0_ton` |
| `_lb` | Pound | `2.2_lb` |
| `_oz` | Ounce | `16.0_oz` |

#### Power Literals

| Literal | Unit | Example |
|---------|------|---------|
| `_W` | Watt | `100.0_W` |
| `_kW` | Kilowatt | `5.0_kW` |
| `_MW` | Megawatt | `1.0_MW` |
| `_hp` | Horsepower | `1.0_hp` |

### Literal Suffix Collisions

When multiple units have the same symbol, the generator detects collisions and skips duplicate literals. Warnings are printed during generation:

```
Warning: Skipping literal _nm for ... (conflicts with Nanometer)
```

In such cases, use explicit constructors:
```cpp
Nanometer nm(500.0);  // Instead of 500.0_nm if collision exists
```

## Usage Examples

### Basic Construction and Access

```cpp
#include "qtty/qtty.hpp"
using namespace qtty;

// Constructor
Meter distance(1000.0);
std::cout << distance.value() << " m\n";  // Prints: 1000 m

// User-defined literal
auto height = 5.5_m;
std::cout << height.value() << " m\n";  // Prints: 5.5 m
```

### Unit Conversions

```cpp
// Convert meters to kilometers
Meter m(1500.0);
Kilometer km = m.to<Kilometer>();
std::cout << km.value() << " km\n";  // Prints: 1.5 km

// Convert back
Meter m2 = km.to<Meter>();
std::cout << m2.value() << " m\n";  // Prints: 1500 m

// Angular conversion
auto angle = 180.0_deg;
Radian rad = angle.to<Radian>();
std::cout << rad.value() << " rad\n";  // Prints: 3.14159 rad
```

### Arithmetic Operations

```cpp
Meter a(10.0), b(5.0);

// Same-unit operations
Meter sum = a + b;           // 15 m
Meter diff = a - b;          // 5 m

// Scalar operations
Meter doubled = a * 2.0;     // 20 m
Meter half = a / 2.0;        // 5 m
Meter tripled = 3.0 * a;     // 30 m

// Compound assignment
a += 5.0_m;                  // a = 15 m
a *= 2.0;                    // a = 30 m
```

### Comparisons

```cpp
Meter a(10.0), b(5.0), c(10.0);

if (a > b) {
    std::cout << "a is greater\n";
}

if (a == c) {
    std::cout << "a equals c\n";
}

// Can use in algorithms
std::vector<Meter> distances = {10.0_m, 5.0_m, 15.0_m};
std::sort(distances.begin(), distances.end());
```

### Velocity (Compound Units)

```cpp
Meter distance(100.0);
Second time(20.0);

// Division creates compound unit
auto velocity = distance / time;
std::cout << velocity.value() << " m/s\n";  // Prints: 5 m/s

// Type is Quantity<CompoundTag<MeterTag, SecondTag>>
// or MeterPerSecond (type alias)
MeterPerSecond v = distance / time;
```

### Error Handling

```cpp
try {
    Meter m(100.0);
    // Attempt invalid conversion
    Second s = m.to<Second>();
} catch (const IncompatibleDimensionsError& e) {
    std::cerr << "Error: " << e.what() << '\n';
    // Prints: Converting units failed: incompatible dimensions
} catch (const QttyException& e) {
    std::cerr << "Qtty error: " << e.what() << '\n';
}
```

### Working with Raw Values

```cpp
// Extract value for external calculations
Meter m(10.0);
double raw_value = m.value();

// Process raw value
double processed = raw_value * 2.0 + 5.0;

// Create new quantity from processed value
Meter result(processed);
```

### Utility Functions

```cpp
// Absolute value
Meter negative(-10.5);
Meter positive = negative.abs();  // 10.5 m

// Negation
Meter m(5.0);
Meter opposite = -m;              // -5.0 m

// Double negation
Meter back = -(-m);               // 5.0 m
```

### Type Safety Examples

```cpp
// Compile-time type safety prevents errors

Meter m(10.0);
Second s(5.0);

// m + s;  // Compile error: no operator+ for different types

// Must explicitly convert first
// (Though this example would throw at runtime due to incompatible dimensions)

// Type deduction works with auto
auto distance = 10.0_m;  // Type: Meter
auto time = 5.0_s;       // Type: Second
auto velocity = distance / time;  // Type: MeterPerSecond
```

## See Also

- [Architecture Documentation](../architecture.md) - Overall design and data flow
- [Build and Testing Guide](../build-and-testing.md) - Building and testing the library
- [Extending Units Guide](../extending-units.md) - Adding new unit types
