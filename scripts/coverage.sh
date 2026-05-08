#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
# shellcheck source=scripts/lib.sh
source "${SCRIPT_DIR}/lib.sh"

BUILD_DIR="build-coverage"
PARALLEL_LEVEL="${CMAKE_BUILD_PARALLEL_LEVEL:-2}"

usage() {
  cat <<EOF
Usage: $(basename "$0") [--build-dir DIR] [--parallel N]
EOF
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --build-dir)
      BUILD_DIR="$2"
      shift 2
      ;;
    --parallel)
      PARALLEL_LEVEL="$2"
      shift 2
      ;;
    --help|-h)
      usage
      exit 0
      ;;
    *)
      fail "Unknown argument: $1"
      usage
      exit 1
      ;;
  esac
done

ensure_repo_root
require_cmd cmake
require_cmd ninja
require_cmd ctest
require_cmd gcovr

header "Configure: CMake (${BUILD_DIR})"
ensure_fresh_cmake_build_dir "${BUILD_DIR}" "${REPO_ROOT}"
cmake -S . -B "${BUILD_DIR}" -G Ninja \
  -DQTTY_BUILD_DOCS=OFF \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_CXX_FLAGS="--coverage" \
  -DCMAKE_EXE_LINKER_FLAGS="--coverage"

header "Build tests (${BUILD_DIR})"
CMAKE_BUILD_PARALLEL_LEVEL="${PARALLEL_LEVEL}" cmake --build "${BUILD_DIR}" --target test_ffi

header "Run tests (${BUILD_DIR})"
ctest --test-dir "${BUILD_DIR}" --output-on-failure -L qtty_cpp

header "Generate coverage reports"
mkdir -p coverage_html
gcovr \
  --root . \
  --exclude 'build-coverage/.*' \
  --exclude 'qtty/.*' \
  --exclude 'tests/.*' \
  --exclude 'examples/.*' \
  --xml \
  --output coverage.xml

gcovr \
  --root . \
  --exclude 'build-coverage/.*' \
  --exclude 'qtty/.*' \
  --exclude 'tests/.*' \
  --exclude 'examples/.*' \
  --html-details \
  --output coverage_html/index.html

ok "Coverage artifacts generated: coverage.xml and coverage_html/index.html"
