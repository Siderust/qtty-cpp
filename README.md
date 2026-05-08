# qtty-cpp

qtty-cpp is a C++17 library for working with physical quantities using unit-safe types. It provides a header-only C++ API backed by the Rust `qtty-ffi` conversion engine (via a C FFI).

[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![CMake](https://img.shields.io/badge/CMake-3.15%2B-064F8C.svg)](https://cmake.org/)
[![License](https://img.shields.io/badge/License-See%20qtty-green.svg)](qtty/LICENSE)

## Features

- Strong types per unit (e.g., `Meter`, `Second`) to prevent mixing incompatible dimensions
- Unit conversion via `Quantity::to<T>()` using the Rust `qtty-ffi` engine
- User-defined literals for convenient construction (e.g., `10.0_km`, `5.0_s`)
- Generated unit/type/literal headers derived from `qtty/qtty-ffi/discriminants.csv`
- Coverage for the full linear `qtty` unit catalog carried by `qtty-ffi`, including pressure, solid angle, temperature, radiometry, photometric SI units, frequency, chemistry, electrical, and density
- CMake target (`qtty_cpp`) for straightforward integration

## Requirements

- CMake 3.15+
- C++17 compiler (GCC 7+, Clang 5+, MSVC 2017+)
- Rust/Cargo (builds `qtty-ffi`)

## Build and Test

```bash
git clone --recurse-submodules <repo-url>
cd qtty-cpp

cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
./build/demo
./build/all_features
```

If you cloned without submodules:

```bash
git submodule update --init --recursive
```

## Usage

```cpp
#include <iostream>
#include "qtty/qtty.hpp"

using namespace qtty;

int main() {
    auto distance = 100.0_km;
    auto time = 2.0_h;

    auto speed = distance / time; // compound type (e.g., KilometerPerHour)
    std::cout << speed.value() << " km/h\n";

    Meter m = distance.to<Meter>();
    std::cout << m.value() << " m\n";
}
```

### Coverage Notes

Division creates quotient-based compound quantity types (for example,
velocity), and `Quantity::to<T>()` supports compound-to-compound conversion
through `qtty_derived_convert()` when both sides are simple
numerator/denominator unit pairs.

The C++ adapter now covers every **linear** unit family exposed by `qtty-ffi`.
Rust-only non-linear helpers such as `photometry::Magnitude`,
`photometry::SurfaceBrightness`, and other non-`Quantity` APIs are not exposed
through the C ABI and therefore remain Rust-only.

## Documentation

- `docs/README.md` (documentation index)
- `docs/QUICK_REFERENCE.md` (one-page usage summary)
- `docs/api/quantities.md` (API reference)
- `docs/build-and-testing.md` (build, test, troubleshooting)
- `docs/extending-units.md` (adding units)
- `docs/architecture.md` (design overview)

## Integration

### Add as a Subdirectory

```cmake
add_subdirectory(path/to/qtty-cpp)
target_link_libraries(your_target PRIVATE qtty_cpp)
```

### Install and Use `find_package`

```bash
cmake --install build
```

```cmake
find_package(qtty_cpp REQUIRED)
target_link_libraries(your_target PRIVATE qtty::qtty_cpp)
```

## Deployment

Packages for Debian/Ubuntu (`.deb`) and RHEL/Fedora/openSUSE (`.rpm`) are built
with CPack.

### Prerequisites

```bash
# Debian/Ubuntu
sudo apt-get install cmake ninja-build rpm

# RHEL/Fedora
sudo dnf install cmake ninja-build dpkg
```

### Build the packages

```bash
git clone --recurse-submodules <repo-url>
cd qtty-cpp

cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DQTTY_BUILD_DOCS=OFF
cmake --build build --parallel

# Install headers + cmake config to a staging prefix
cmake --install build --prefix build/staging

# Generate .deb and .rpm in build/packages/
cd build
cpack --config CPackConfig.cmake -G "DEB;RPM" -B packages
ls packages/
```

### Install on the target system

```bash
# Debian/Ubuntu
sudo dpkg -i packages/qtty-cpp-*.deb

# RHEL/Fedora/openSUSE
sudo rpm -i packages/qtty-cpp-*.rpm
```

After installation, headers land in `/usr/local/include/qtty/` and the
shared library in `/usr/local/lib/`.  CMake consumers can then use:

```cmake
find_package(qtty_cpp REQUIRED)
target_link_libraries(your_target PRIVATE qtty::qtty_cpp)
```

> **Note:** Pre-built `.deb` and `.rpm` packages are also automatically attached
> to every [GitHub Release](https://github.com/Siderust/qtty-cpp/releases).

## License

This repository wraps the upstream `qtty` project (git submodule in `qtty/`). See `qtty/LICENSE` for licensing details.
