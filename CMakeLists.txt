cmake_minimum_required(VERSION 3.15)
project(qtty_cpp VERSION 0.4.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
option(QTTY_BUILD_DOCS "Enable Doxygen documentation target." ON)
option(QTTY_USE_CANONICAL_RUST
       "Build/link against ../../../../rust/qtty instead of the vendored snapshot."
       OFF)

# Find Cargo for building Rust library
find_program(CARGO_BIN cargo REQUIRED)

# Paths to qtty-ffi
if(QTTY_USE_CANONICAL_RUST)
    set(QTTY_CANONICAL_RUST_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../rust/qtty
        CACHE PATH "Path to the canonical rust/qtty workspace")
    set(QTTY_SUBMODULE_DIR ${QTTY_CANONICAL_RUST_DIR})
    set(QTTY_ARTIFACT_DIR ${QTTY_CANONICAL_RUST_DIR}/target/release)
else()
    set(QTTY_SUBMODULE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/qtty)
    set(QTTY_ARTIFACT_DIR ${QTTY_SUBMODULE_DIR}/target/release)
endif()
set(QTTY_FFI_INCLUDE_DIR ${QTTY_SUBMODULE_DIR}/qtty-ffi/include)

# Allow enabling Cargo features for qtty-ffi (e.g., qtty_serde)
# Use a STRING cache var (not BOOL) so users can set: "qtty_serde", "", or custom lists.
set(QTTY_FFI_FEATURES "" CACHE STRING "Cargo features for qtty-ffi (e.g., 'qtty_serde' or empty)")

# Normalize feature args: treat OFF/FALSE/0 as empty.
set(_QTTY_FEATURES_ARGS "")
set(QTTY_FFI_HAS_SERDE OFF)
string(TOUPPER "${QTTY_FFI_FEATURES}" _QTTY_FEATURES_UP)
if("${_QTTY_FEATURES_UP}" STREQUAL "OFF" OR "${_QTTY_FEATURES_UP}" STREQUAL "FALSE" OR "${_QTTY_FEATURES_UP}" STREQUAL "0")
    # No features
elseif("${_QTTY_FEATURES_UP}" STREQUAL "ON")
    set(_QTTY_FEATURES_ARGS --features qtty_serde)
    set(QTTY_FFI_HAS_SERDE ON)
elseif(NOT "${QTTY_FFI_FEATURES}" STREQUAL "")
    set(_QTTY_FEATURES_ARGS --features ${QTTY_FFI_FEATURES})
    if("${QTTY_FFI_FEATURES}" MATCHES "(^|,)qtty_serde(,|$)")
        set(QTTY_FFI_HAS_SERDE ON)
    endif()
endif()

# Platform-specific library paths
if(APPLE)
    set(QTTY_LIBRARY_PATH ${QTTY_ARTIFACT_DIR}/libqtty_ffi.dylib)
elseif(WIN32)
    set(QTTY_LIBRARY_PATH ${QTTY_ARTIFACT_DIR}/qtty_ffi.dll)
    set(QTTY_IMPORT_LIBRARY ${QTTY_ARTIFACT_DIR}/qtty_ffi.dll.lib)
else()
    set(QTTY_LIBRARY_PATH ${QTTY_ARTIFACT_DIR}/libqtty_ffi.so)
endif()

# Generate C++ unit wrappers from units.csv via the Rust gen_cpp_units binary.
# Running `cargo run` builds the binary (and the qtty-ffi library) if needed.
set(QTTY_UNITS_CSV ${QTTY_SUBMODULE_DIR}/qtty-ffi/discriminants.csv)
set(GENERATED_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/length.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/time.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/angular.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/mass.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/power.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/area.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/volume.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/acceleration.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/force.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/energy.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/pressure.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/solid_angle.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/temperature.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/radiance.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/spectral_radiance.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/photon_radiance.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/spectral_photon_radiance.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/inverse_solid_angle.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/luminous_intensity.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/luminous_flux.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/illuminance.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/frequency.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/amount.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/current.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/charge.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/voltage.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/resistance.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/capacitance.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/inductance.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/magnetic_flux.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/magnetic_flux_density.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/density.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/units/dimensionless.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty/literals.hpp
)

add_custom_command(
    OUTPUT ${GENERATED_HEADERS}
    COMMAND ${CARGO_BIN} run --manifest-path ${CMAKE_CURRENT_SOURCE_DIR}/gen_cpp_units/Cargo.toml --release
        -- ${QTTY_UNITS_CSV} ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty
    DEPENDS ${QTTY_UNITS_CSV}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating C++ unit wrappers from units.csv (Rust)"
    VERBATIM
)

add_custom_target(
    gen_cpp_units
    DEPENDS ${GENERATED_HEADERS}
)

# Build qtty-ffi via Cargo
add_custom_target(
    build_qtty_ffi
    COMMAND ${CARGO_BIN} build -p qtty-ffi --release ${_QTTY_FEATURES_ARGS}
    WORKING_DIRECTORY ${QTTY_SUBMODULE_DIR}
    BYPRODUCTS ${QTTY_LIBRARY_PATH}
    DEPENDS gen_cpp_units
    COMMENT "Building qtty-ffi library via Cargo"
    VERBATIM
)

# Import qtty-ffi as a library target
add_library(qtty_ffi SHARED IMPORTED GLOBAL)
set_target_properties(qtty_ffi PROPERTIES IMPORTED_LOCATION ${QTTY_LIBRARY_PATH})
if(WIN32)
    set_target_properties(qtty_ffi PROPERTIES IMPORTED_IMPLIB ${QTTY_IMPORT_LIBRARY})
endif()
add_dependencies(qtty_ffi build_qtty_ffi)

# Header-only C++ wrapper library
add_library(qtty_cpp INTERFACE)
target_include_directories(qtty_cpp INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${QTTY_FFI_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(qtty_cpp INTERFACE qtty_ffi)
add_dependencies(qtty_cpp build_qtty_ffi)

# Doxygen documentation
if(QTTY_BUILD_DOCS)
    find_package(Doxygen QUIET)
    if(DOXYGEN_FOUND)
        set(QTTY_DOXYFILE_IN  ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
        set(QTTY_DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.qtty_cpp)
        configure_file(${QTTY_DOXYFILE_IN} ${QTTY_DOXYFILE_OUT} @ONLY)

        add_custom_target(docs
            COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/docs/doxygen
            COMMAND ${DOXYGEN_EXECUTABLE} ${QTTY_DOXYFILE_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM
        )
    else()
        message(STATUS "Doxygen not found; 'docs' target will not be available")
    endif()
endif()

# Set RPATH for runtime library location
if(APPLE)
    if(QTTY_USE_CANONICAL_RUST)
        set(_qtty_rpath "${QTTY_ARTIFACT_DIR}")
    else()
        set(_qtty_rpath "@loader_path/../qtty/target/release")
    endif()
elseif(UNIX)
    if(QTTY_USE_CANONICAL_RUST)
        set(_qtty_rpath "${QTTY_ARTIFACT_DIR}")
    else()
        set(_qtty_rpath "$ORIGIN/../qtty/target/release")
    endif()
endif()

# Google Test integration
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# Disable googletest installation rules in downstream projects —
# we don't want GTest/GMock files installed when packaging qtty-cpp.
set(INSTALL_GTEST OFF CACHE BOOL "Disable installing googletest components" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Examples
add_executable(demo examples/demo.cpp)
target_link_libraries(demo PRIVATE qtty_cpp)
if(DEFINED _qtty_rpath)
    set_target_properties(demo PROPERTIES 
        BUILD_RPATH ${_qtty_rpath}
        INSTALL_RPATH ${_qtty_rpath}
    )
endif()

add_executable(all_features examples/all_features.cpp)
target_link_libraries(all_features PRIVATE qtty_cpp)
if(DEFINED _qtty_rpath)
    set_target_properties(all_features PROPERTIES
        BUILD_RPATH ${_qtty_rpath}
        INSTALL_RPATH ${_qtty_rpath}
    )
endif()

# JSON serialization example — requires qtty-ffi built with the 'qtty_serde' feature:
#   cmake -B build -DQTTY_FFI_FEATURES=qtty_serde && cmake --build build
if(QTTY_FFI_HAS_SERDE)
    add_executable(serialization examples/serialization.cpp)
    target_link_libraries(serialization PRIVATE qtty_cpp)
    if(DEFINED _qtty_rpath)
        set_target_properties(serialization PROPERTIES
            BUILD_RPATH ${_qtty_rpath}
            INSTALL_RPATH ${_qtty_rpath}
        )
    endif()
else()
    message(STATUS "Skipping qtty-cpp serialization example because qtty-ffi is built without qtty_serde")
endif()

# Test executables with Google Test
set(TEST_FFI_SOURCES
    tests/main.cpp
    tests/fixtures.hpp
    tests/test_length.cpp
    tests/test_time.cpp
    tests/test_angular.cpp
    tests/test_mass.cpp
    tests/test_power.cpp
    tests/test_derived.cpp
    tests/test_operations.cpp
    tests/test_dimension_safety.cpp
    tests/test_precision.cpp
    tests/test_formatting.cpp
    tests/test_extended_inventory.cpp
)
if(QTTY_FFI_HAS_SERDE)
    list(APPEND TEST_FFI_SOURCES tests/test_serialization.cpp)
endif()

add_executable(test_ffi ${TEST_FFI_SOURCES})
target_link_libraries(test_ffi PRIVATE qtty_cpp GTest::gtest)
if(DEFINED _qtty_rpath)
    set_target_properties(test_ffi PROPERTIES 
        BUILD_RPATH ${_qtty_rpath}
        INSTALL_RPATH ${_qtty_rpath}
    )
endif()

# Add tests to CTest
include(GoogleTest)
gtest_discover_tests(test_ffi
    PROPERTIES LABELS "qtty_cpp"
)

# Installation rules
install(DIRECTORY include/qtty 
    DESTINATION include
    FILES_MATCHING PATTERN "*.hpp"
)

install(DIRECTORY ${QTTY_FFI_INCLUDE_DIR}/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

# Install the qtty_ffi shared library
install(FILES ${QTTY_LIBRARY_PATH}
    DESTINATION lib
)

# Install CMake config files for find_package support
include(CMakePackageConfigHelpers)

# Create the config file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/qtty_cppConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/qtty_cppConfig.cmake
    INSTALL_DESTINATION lib/cmake/qtty_cpp
)

# Create the version file
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/qtty_cppConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

# Install the config and version files
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/qtty_cppConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/qtty_cppConfigVersion.cmake
    DESTINATION lib/cmake/qtty_cpp
)

# Export targets
install(TARGETS qtty_cpp
    EXPORT qtty_cppTargets
    INCLUDES DESTINATION include
)

install(EXPORT qtty_cppTargets
    FILE qtty_cppTargets.cmake
    NAMESPACE qtty::
    DESTINATION lib/cmake/qtty_cpp
)

# ---------------------------------------------------------------------------
# Packaging (CPack — DEB and RPM)
# ---------------------------------------------------------------------------
set(CPACK_PACKAGE_NAME             "qtty-cpp")
set(CPACK_PACKAGE_VERSION          "${PROJECT_VERSION}")
set(CPACK_PACKAGE_VENDOR           "Siderust")
set(CPACK_PACKAGE_CONTACT          "VPRamon <vallespuigramon@gmail.com>")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
    "C++ wrapper for the qtty unit-safe physical quantities library")
set(CPACK_PACKAGE_DESCRIPTION
    "qtty-cpp provides a header-only C++17 API over the qtty Rust\n"
    "quantities library via the qtty-ffi C ABI.  It bundles the pre-built\n"
    "shared library (qtty_ffi) together with the C++ headers and CMake\n"
    "package config.")
set(CPACK_RESOURCE_FILE_LICENSE    "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_HOMEPAGE_URL     "https://github.com/Siderust/qtty-cpp")

# -- DEB -----------------------------------------------------------------------
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "VPRamon <vallespuigramon@gmail.com>")
set(CPACK_DEBIAN_PACKAGE_SECTION    "libs")
set(CPACK_DEBIAN_PACKAGE_DEPENDS    "libc6 (>= 2.17), libstdc++6 (>= 9)")
set(CPACK_DEBIAN_FILE_NAME          DEB-DEFAULT)

# -- RPM -----------------------------------------------------------------------
set(CPACK_RPM_PACKAGE_LICENSE    "AGPL-3.0")
set(CPACK_RPM_PACKAGE_GROUP      "Development/Libraries")
set(CPACK_RPM_PACKAGE_REQUIRES   "glibc >= 2.17, libstdc++ >= 9")
set(CPACK_RPM_FILE_NAME          RPM-DEFAULT)

set(CPACK_GENERATOR "DEB;RPM")

include(CPack)

# Generate unit files (if needed)
add_custom_target(
    gen_units
    COMMAND ${CARGO_BIN} run --manifest-path ${CMAKE_CURRENT_SOURCE_DIR}/gen_cpp_units/Cargo.toml --release
        -- ${QTTY_UNITS_CSV} ${CMAKE_CURRENT_SOURCE_DIR}/include/qtty
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating C++ unit wrappers from units.csv (Rust)"
    VERBATIM
)
