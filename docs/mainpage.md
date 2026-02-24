# qtty-cpp API Documentation

`qtty-cpp` is a **modern, header-only C++17 library** for working with
physical quantities using strongly-typed, unit-safe value types. It wraps
the Rust-based [`qtty`](https://github.com/siderust/qtty) conversion engine
through its C FFI layer (`qtty-ffi`), giving you compile-time dimension
safety and zero-overhead unit conversions without writing a single line of
Rust.

---

## Features

| Feature | Description |
|---------|-------------|
| **Strong unit types** | Each unit (e.g., `Meter`, `Second`, `Kilogram`) is a distinct C++ type — mixing incompatible dimensions is a compile error |
| **Unit conversion** | `Quantity::to<T>()` delegates to the `qtty-ffi` Rust engine for exact conversions |
| **User-defined literals** | Ergonomic construction: `10.0_km`, `5.0_s`, `90.0_deg`, `1.0_kg` |
| **Generated headers** | Unit aliases and literals auto-generated from `qtty_ffi.h` — always in sync with the Rust layer |
| **CMake integration** | One `target_link_libraries` call: `qtty_cpp` |

---

## Quick Start

```cpp
#include <qtty/qtty.hpp>
#include <iostream>

using namespace qtty;
using namespace qtty::literals;

int main() {
    // Distance and time with unit literals
    auto distance = 100.0_km;
    auto time     = 2.0_h;

    // Compound type (KilometerPerHour)
    auto speed = distance / time;
    std::cout << speed.value() << " km/h\n";

    // Convert to metres
    Meter m = distance.to<Meter>();
    std::cout << m.value() << " m\n";

    // Angular quantities
    auto angle = 90.0_deg;
    Radian r   = angle.to<Radian>();
    std::cout << r.value() << " rad\n";

    return 0;
}
```

---

## Architecture

```
┌──────────────┐
│  C++ user    │   #include <qtty/qtty.hpp>
│  code        │
└──────┬───────┘
       │  header-only (inline)
┌──────▼───────┐
│   qtty-cpp   │   C++17 strong types, literals, conversion API
│  (headers)   │
└──────┬───────┘
       │  extern "C" calls
┌──────▼───────┐
│  qtty-ffi   │   C ABI (cbindgen-generated from Rust)
│ (.so/.dylib) │
└──────┬───────┘
       │
┌──────▼───────┐
│  qtty (Rust) │   Unit registry, exact conversions, dimension algebra
└──────────────┘
```

---

## Modules

- `qtty/qtty.hpp` — umbrella include for the full public API
- `qtty/ffi_core.hpp` — FFI helpers and exception hierarchy
- `qtty/units/length.hpp` — `Meter`, `Kilometer`, `Mile`, `NauticalMile`, …
- `qtty/units/time.hpp` — `Second`, `Minute`, `Hour`, `Day`, …
- `qtty/units/angular.hpp` — `Radian`, `Degree`, `ArcMinute`, `ArcSecond`, …
- `qtty/units/mass.hpp` — `Kilogram`, `Gram`, `Pound`, …
- `qtty/units/velocity.hpp` — compound velocity types
- `qtty/literals.hpp` — user-defined literals for all units
- `qtty/serialization.hpp` — optional JSON/serde helpers

---

## Error Model

FFI status codes are translated into typed C++ exceptions:

| Exception | When thrown |
|-----------|-------------|
| `QttyException` | Base class for all qtty errors |
| `InvalidUnitError` | Unrecognised unit identifier |
| `IncompatibleDimensionsError` | Conversion between incompatible dimensions |
| `ConversionError` | Numeric conversion failure in the FFI layer |

---

## Prerequisites

- C++17 compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.15+
- Python 3.6+ (for header generation)
- Rust toolchain (`cargo`) — `qtty-ffi` is built automatically

---

## Building

```bash
git clone --recurse-submodules <url>
cd qtty-cpp

cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure

./build/demo
```

---

## Building This Documentation

```bash
cmake -S . -B build -G Ninja -DQTTY_BUILD_DOCS=ON
cmake --build build --target docs
```

Then open:

- `build/docs/doxygen/html/index.html`
