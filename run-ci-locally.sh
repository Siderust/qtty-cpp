#!/usr/bin/env bash
set -euo pipefail

# qtty-cpp C++ CI runner for local development
# This script mirrors the GitHub Actions CI workflow and can be run locally

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Options
RUN_ALL=false
RUN_LINT=false
RUN_BUILD=false
RUN_COVERAGE=false
SKIP_INSTALL=false
PARALLEL_LEVEL=2

# Default: run all
if [[ $# -eq 0 ]]; then
    RUN_ALL=true
fi

# Parse arguments
while [[ $# -gt 0 ]]; do
    case "$1" in
        all)
            RUN_ALL=true
            shift
            ;;
        lint)
            RUN_LINT=true
            shift
            ;;
        build)
            RUN_BUILD=true
            shift
            ;;
        test)
            RUN_BUILD=true
            shift
            ;;
        coverage)
            RUN_COVERAGE=true
            shift
            ;;
        --skip-install)
            SKIP_INSTALL=true
            shift
            ;;
        --parallel)
            PARALLEL_LEVEL="$2"
            shift 2
            ;;
        --help|-h)
            cat <<EOF
Usage: $0 [COMMAND] [OPTIONS]

Commands (run specific checks):
  all               Run all checks: lint, build, test, coverage (default)
  lint              clang-format + clang-tidy checks
  build             Build C++ project with CMake/Ninja
  test              Build and run ctest
  coverage          Build with coverage and generate reports (requires gcovr)

Options:
  --skip-install    Don't install tools (assume already installed)
  --parallel N      Set CMAKE_BUILD_PARALLEL_LEVEL (default: 2)
  --help            Show this help message

Examples:
  $0                           # Run all checks
  $0 lint                      # Check code formatting and linting
  $0 build                     # Build C++ project
  $0 coverage                  # Generate coverage report
  $0 --skip-install all        # Run all without reinstalling tools

EOF
            exit 0
            ;;
        *)
            echo "Unknown command: $1"
            echo "Run '$0 --help' for usage"
            exit 1
            ;;
    esac
done

# If running all, enable all checks
if [[ "$RUN_ALL" == "true" ]]; then
    RUN_LINT=true
    RUN_BUILD=true
    RUN_COVERAGE=true
fi

# Helper functions
print_header() {
    echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
    echo -e "${BLUE}$1${NC}"
    echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}\n"
}

print_success() {
    echo -e "${GREEN}✓ $1${NC}"
}

print_error() {
    echo -e "${RED}✗ $1${NC}"
}

print_warning() {
    echo -e "${YELLOW}⚠ $1${NC}"
}

check_command() {
    if ! command -v "$1" &> /dev/null; then
        return 1
    fi
    return 0
}

# Check and install tools
if [[ "$SKIP_INSTALL" == "false" ]]; then
    print_header "Checking/Installing build tools"
    
    # Check for cmake
    if ! check_command cmake; then
        print_warning "cmake not found, installing..."
        sudo apt-get update
        sudo apt-get install -y cmake
    else
        print_success "cmake found: $(cmake --version | head -1)"
    fi
    
    # Check for ninja
    if ! check_command ninja; then
        print_warning "ninja-build not found, installing..."
        sudo apt-get update
        sudo apt-get install -y ninja-build
    else
        print_success "ninja found: $(ninja --version)"
    fi
    
    # Check for clang-format (only needed for lint)
    if [[ "$RUN_LINT" == "true" ]]; then
        if ! check_command clang-format; then
            print_warning "clang-format not found, installing clang-format-18..."
            sudo apt-get update
            wget -qO /tmp/llvm.sh https://apt.llvm.org/llvm.sh
            sudo bash /tmp/llvm.sh 18
            sudo apt-get install -y clang-format-18
            sudo ln -sf /usr/bin/clang-format-18 /usr/local/bin/clang-format
            rm -f /tmp/llvm.sh
        else
            print_success "clang-format found: $(clang-format --version | head -1)"
        fi
        
        # Check for clang-tidy
        if ! check_command clang-tidy; then
            print_warning "clang-tidy not found, installing..."
            sudo apt-get update
            sudo apt-get install -y clang-tidy
        else
            print_success "clang-tidy found"
        fi
    fi
    
    # Check for gcovr (only needed for coverage)
    if [[ "$RUN_COVERAGE" == "true" ]]; then
        if ! check_command gcovr; then
            print_warning "gcovr not found, installing..."
            sudo apt-get update
            sudo apt-get install -y gcovr
        else
            print_success "gcovr found: $(gcovr --version | head -1)"
        fi
    fi
fi

# Check for Rust (needed for submodule validation)
if ! check_command rustc; then
    print_error "Rust not found. Please install from https://rustup.rs/"
    exit 1
fi

FAILED=()
PASSED=()

# Show submodule status
print_header "Submodule Information"
git submodule status --recursive 2>/dev/null || true
if [[ -f qtty/Cargo.toml ]]; then
    echo -e "${GREEN}✓${NC} qtty submodule OK"
else
    print_error "qtty submodule missing (run: git submodule update --init --recursive)"
    FAILED+=("submodules")
fi

# Lint checks
if [[ "$RUN_LINT" == "true" ]]; then
    print_header "Check: clang-format"
    mapfile -t files < <(git ls-files '*.hpp' '*.cpp' 2>/dev/null || echo "")
    
    if [[ ${#files[@]} -eq 0 ]]; then
        print_warning "No C++ files found (check git ls-files)"
    else
        if clang-format --dry-run --Werror "${files[@]}" 2>/dev/null; then
            print_success "clang-format check passed"
            PASSED+=("clang-format")
        else
            print_error "clang-format check failed"
            print_warning "Run: clang-format -i \$(git ls-files '*.hpp' '*.cpp')"
            FAILED+=("clang-format")
        fi
    fi
    
    print_header "Check: clang-tidy"
    
    # First configure to generate compile_commands.json
    print_warning "Configuring CMake for compile commands..."
    if cmake -S . -B build -G Ninja -DQTTY_BUILD_DOCS=OFF -DCMAKE_EXPORT_COMPILE_COMMANDS=ON >/dev/null 2>&1; then
        mapfile -t cpp_files < <(git ls-files '*.cpp' 2>/dev/null || echo "")
        
        if [[ ${#cpp_files[@]} -eq 0 ]]; then
            print_warning "No C++ source files found (check git ls-files)"
        else
            tidy_failed=false
            for file in "${cpp_files[@]}"; do
                echo "  Checking: $file"
                if ! clang-tidy -p build --warnings-as-errors='*' "$file" 2>/dev/null; then
                    tidy_failed=true
                fi
            done
            
            if [[ "$tidy_failed" == "false" ]]; then
                print_success "clang-tidy check passed"
                PASSED+=("clang-tidy")
            else
                print_error "clang-tidy check failed"
                FAILED+=("clang-tidy")
            fi
        fi
    else
        print_error "CMake configuration failed"
        FAILED+=("clang-tidy")
    fi
fi

# Build and test
if [[ "$RUN_BUILD" == "true" ]]; then
    print_header "Configure: CMake (build directory)"
    
    if cmake -S . -B build -G Ninja -DQTTY_BUILD_DOCS=ON >/dev/null 2>&1; then
        print_success "CMake configuration complete"
    else
        print_error "CMake configuration failed"
        FAILED+=("cmake-config")
        exit 1
    fi
    
    print_header "Build: test_ffi target"
    
    if CMAKE_BUILD_PARALLEL_LEVEL="$PARALLEL_LEVEL" cmake --build build --target test_ffi 2>&1 | tee /tmp/build.log | tail -20; then
        if [[ -f build/test_ffi ]]; then
            print_success "Build successful"
            PASSED+=("build")
        else
            print_error "Build failed (test_ffi executable not found)"
            FAILED+=("build")
        fi
    else
        print_error "Build failed"
        FAILED+=("build")
    fi
    
    print_header "Test: ctest"
    
    if ctest --test-dir build --output-on-failure -L qtty_cpp; then
        print_success "All tests passed"
        PASSED+=("test")
    else
        print_error "Tests failed"
        FAILED+=("test")
    fi
    
    print_header "Build: Doxygen documentation"
    if cmake --build build --target docs 2>&1 | tee /tmp/docs.log | tail -10; then
        if [[ -d build/docs/html ]]; then
            print_success "Documentation built (see build/docs/html/index.html)"
            PASSED+=("docs")
        else
            print_warning "Documentation build skipped (doxygen may not be installed)"
        fi
    else
        print_warning "Documentation build skipped or failed"
    fi
fi

# Coverage
if [[ "$RUN_COVERAGE" == "true" ]]; then
    print_header "Configure: CMake (coverage build)"
    
    if cmake -S . -B build-coverage -G Ninja \
        -DQTTY_BUILD_DOCS=OFF \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCMAKE_CXX_FLAGS="--coverage" \
        -DCMAKE_EXE_LINKER_FLAGS="--coverage" >/dev/null 2>&1; then
        print_success "CMake configuration complete"
    else
        print_error "CMake configuration failed"
        FAILED+=("coverage-config")
        exit 1
    fi
    
    print_header "Build: test_ffi target (coverage)"
    
    if CMAKE_BUILD_PARALLEL_LEVEL="$PARALLEL_LEVEL" cmake --build build-coverage --target test_ffi >/dev/null 2>&1; then
        print_success "Build complete"
    else
        print_error "Build failed"
        FAILED+=("coverage-build")
        exit 1
    fi
    
    print_header "Test: ctest (coverage)"
    
    if ctest --test-dir build-coverage --output-on-failure -L qtty_cpp >/dev/null 2>&1; then
        print_success "All tests passed"
    else
        print_error "Tests failed"
        FAILED+=("coverage-test")
        exit 1
    fi
    
    print_header "Generate coverage reports"
    
    mkdir -p coverage_html
    
    if gcovr \
        --root . \
        --exclude 'build-coverage/.*' \
        --exclude 'qtty/.*' \
        --exclude 'tests/.*' \
        --exclude 'examples/.*' \
        --xml \
        --output coverage.xml >/dev/null 2>&1; then
        print_success "Cobertura XML report generated"
    else
        print_error "Failed to generate Cobertura report"
        FAILED+=("coverage-xml")
    fi
    
    if gcovr \
        --root . \
        --exclude 'build-coverage/.*' \
        --exclude 'qtty/.*' \
        --exclude 'tests/.*' \
        --exclude 'examples/.*' \
        --html-details \
        --output coverage_html/index.html >/dev/null 2>&1; then
        print_success "HTML coverage report generated (see coverage_html/index.html)"
        PASSED+=("coverage")
    else
        print_error "Failed to generate HTML report"
        FAILED+=("coverage-html")
    fi
fi

# Summary
print_header "CI Summary"
echo -e "${GREEN}Passed (${#PASSED[@]}):${NC}"
for check in "${PASSED[@]}"; do
    echo "  ✓ $check"
done

if [[ ${#FAILED[@]} -gt 0 ]]; then
    echo -e "\n${RED}Failed (${#FAILED[@]}):${NC}"
    for check in "${FAILED[@]}"; do
        echo "  ✗ $check"
    done
    exit 1
else
    echo -e "\n${GREEN}All checks passed!${NC}\n"
    exit 0
fi
