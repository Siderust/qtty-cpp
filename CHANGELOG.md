# Changelog

All notable changes to `qtty-cpp` are documented in this file.

Format follows [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)
and [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

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
