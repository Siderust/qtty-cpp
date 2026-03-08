# Changelog

All notable changes to `qtty-cpp` are documented in this file.

Format follows [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)
and [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

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
