# Changelog

All notable changes to `qtty-cpp` are documented in this file.

Format follows [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)
and [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.4.3] - 2026-05-11

### Fixed

- `CMakeLists.txt`: guarded all `install()` rules, `CMakePackageConfigHelpers`
  calls, tests, examples, and GoogleTest integration inside
  `if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)`.  When qtty-cpp is
  used as a subdirectory by tempoch-cpp or siderust-cpp, its artifacts are no
  longer registered as install rules, preventing file-conflict errors such as
  `trying to overwrite '/usr/include/qtty/ffi_core.hpp'` when multiple packages
  are installed simultaneously.
- Added a `scripts/fmt.sh` compatibility wrapper so `scripts/ci.sh fmt` / `all`
  delegates to the same clang-format and clang-tidy pipeline as `scripts/lint.sh`.
- CI lint now runs `scripts/lint.sh --check` directly so the GitHub Actions
  lint rules stay aligned with the local developer script entrypoint.
- Documentation targets are now project-specific: `qtty-cpp` builds `qtty_docs`
  internally and only exposes `docs` as the top-level alias, preventing nested
  consumers from colliding on a generic `docs` target name.
- `docs/Doxyfile.in` no longer points `PROJECT_LOGO` at a missing
  `../../public/logo.png`, eliminating a Doxygen configuration error from the
  docs build.
- `gen_cpp_units` now emits headers and literal overloads in the same shape
  required by the repository's active `.clang-format` rules, so regenerated
  files no longer fail the `clang-format --dry-run --Werror` CI check.

## [0.4.2] - 2026-07-15

### Changed
- Reformatted spectral and photon radiance unit headers
  (`photon_radiance.hpp`, `spectral_photon_radiance.hpp`,
  `spectral_radiance.hpp`) for code consistency: collapsed single-expression
  `unit_id()` definitions to one line and consolidated multi-line `using`
  type aliases to single lines.
- Reordered `#include` directives in `literals.hpp` from alphabetical to a
  logical physical-dimension grouping (length → time → angular → mass → …),
  and reformatted some operator bodies to the multi-line brace style used
  elsewhere.
- Updated `gen_cpp_units/Cargo.lock` with a minor dependency refresh.

## [0.4.1] - 2026-05-08

### Added
- Expose named dimensionless units in the C++ wrapper: `OpticalDepth`,
  `Airmass`, `Transmittance`, `Albedo`, `IlluminationFraction`, and
  `Refractivity`. A generated header `include/qtty/units/dimensionless.hpp`
  provides tag types and type aliases for these units and `include/qtty/qtty.hpp`
  includes the new header so the units are available with a single include.
- Add FFI discriminants and identifiers for the new dimensionless units and
  dimension: `DIMENSION_ID_DIMENSIONLESS = 33` and
  `UNIT_ID_OPTICAL_DEPTH = 330000` … `UNIT_ID_REFRACTIVITY = 330005` in the
  generated `qtty_ffi.h` so the units are available across the C ABI.

### Changed
- `gen_cpp_units` generator: include `Dimensionless` in the `DIMENSIONS`
  constant and map discriminant code `33` to the `Dimensionless` group so
  `dimensionless.hpp` is generated automatically from `discriminants.csv`.
  `literals.hpp` was regenerated (no user-defined literals for these units as
  they have empty symbols).
- `CMakeLists.txt` and the generator invocation updated to include the new
  generated `dimensionless.hpp` so it is installed and packaged like other
  generated headers.
- Tests: added `DimensionlessUnits` coverage in
  `tests/test_extended_inventory.cpp` to verify construction and cross-unit
  conversions for the new named dimensionless units.

### Notes
- The generator output and ABI remain backward compatible: new discriminant
  values were appended and existing values were not changed.

## [0.4.0] - 2026-05-04

### Added
- Generated headers for the full `qtty-ffi` linear inventory, extending the
  C++ wrapper beyond the original ten families to pressure, solid angle,
  temperature, radiometry, photometric SI units, frequency, chemistry,
  electrical, and density.
- New example `examples/all_features.cpp` demonstrating one conversion from
  each newly exposed unit family.
- New regression coverage in `tests/test_extended_inventory.cpp` for pressure,
  solid angle, temperature, frequency, chemistry, electrical, density,
  radiometry, and photometric SI units.

### Changed
- Updated bundled `qtty` integration target to the `0.7.0` release line and
  aligned the generator with the expanded `discriminants.csv` dimension ranges.
- `qtty.hpp`, `literals.hpp`, and the generated unit headers now expose the
  full linear `qtty` catalog available through `qtty-ffi`.
- `qtty-cpp` project version bumped to `0.4.0`.

## [0.3.0] - 2026-05-04

### Added
- Five new dimension headers generated for the full FFI unit inventory:
  `area.hpp` (11 units), `volume.hpp` (13 units), `acceleration.hpp` (2 units),
  `force.hpp` (8 units), `energy.hpp` (13 units).
- `include/qtty/qtty.hpp` now includes all ten dimension headers so every
  FFI-backed unit is available with a single `#include "qtty/qtty.hpp"`.
- Extended `examples/demo.cpp` with four new numbered sections covering area,
  volume, force/acceleration, and energy conversions.
- Added an area and energy serialisation round-trip to
  `examples/serialization.cpp` (section 5).

### Changed
- **License**: the project is now released under the BSD 3-Clause License,
  matching the upstream `qtty` crate.  All source files and the `LICENSE` file
  have been updated accordingly.
- Updated bundled `qtty` submodule to `v0.2.2-189-g318b1fc`, bringing support
  for 191 FFI units across 10 physical dimensions.
- `gen_cpp_units` generator rewritten to read `discriminants.csv` (2-field
  format) instead of the now-removed `units.csv`.  Symbols are now resolved at
  compile time from the `qtty-ffi` Rust crate instead of being duplicated in the
  CSV.  Generator version bumped to 0.3.0.
- `CMakeLists.txt` project version bumped to 0.3.0; `QTTY_UNITS_CSV` now
  points to `qtty-ffi/discriminants.csv`; `GENERATED_HEADERS` extended with the
  five new dimension filenames.
- `include/qtty/qtty.hpp` version struct updated to `0.3.0`.

## [0.2.0] - 2026-03-08

### Added
- Optional Doxygen documentation generation via `QTTY_BUILD_DOCS`, plus a Doxygen configuration and a richer project main page under `docs/`.
- A Rust-based `gen_cpp_units` generator that emits the C++ unit wrappers from `qtty-ffi/units.csv`, replacing the previous Python script.
- A JSON serialization example program (`examples/serialization.cpp`) covering value-only, unit-aware, and derived-quantity round trips.
- Quantity formatting support in the C++ wrapper, including stream insertion coverage and dedicated tests for default, fixed-precision, and scientific formatting.
- Repository tooling for local CI execution (`run-ci-locally.sh`) and a shared `.clang-format`.

### Changed
- Updated the bundled `qtty` submodule multiple times, bringing the C++ wrapper forward to newer upstream `qtty` and `qtty-ffi` revisions.
- Reworked generated headers and wrapper internals to align with the newer upstream unit catalog, unit symbols, serialization APIs, and formatting helpers.
- Updated CMake and CI configuration around `QTTY_FFI_FEATURES`, documentation builds, formatting checks, and containerized/local workflow execution.
- Expanded and refreshed the test suite across unit conversions, serialization, derived quantities, precision, and formatting behavior.

### Fixed
- Corrected Cargo feature handling in CMake so `qtty-ffi` can be built cleanly with an empty feature list or explicit feature selections.
- Resolved CI and formatting issues across generated headers and wrapper sources.

## [0.1.0] - 2025-12-15

### Added
- Initial public release of `qtty-cpp`.
- Header-only C++ wrapper library backed by the Rust `qtty-ffi` conversion engine.
- CMake build/install support, CI coverage workflow, Docker-based development environment, and JSON serialization support through `qtty-ffi`.
