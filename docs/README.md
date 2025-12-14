# Documentation Index

Welcome to the qtty-cpp documentation! This page helps you find the information you need.

## Quick Links

| Document | Purpose | When to Read |
|----------|---------|--------------|
| [README](../README.md) | Quick start, overview, features | Start here |
| [Architecture](architecture.md) | Design, layering, data flow | Understanding how it works |
| [API Reference](api/quantities.md) | Complete API documentation | Writing code |
| [Build & Testing](build-and-testing.md) | Setup, compilation, testing | Getting started, troubleshooting |
| [Extending Units](extending-units.md) | Adding new units | Contributing new units |

## Documentation Structure

```
docs/
├── README.md              # This file
├── architecture.md        # Design and implementation details
├── build-and-testing.md   # Build instructions and test guide
├── extending-units.md     # Guide for adding new units
└── api/
    └── quantities.md      # Complete API reference
```

## Getting Started Path

1. **First Time**: Read [README](../README.md) for quick start and installation
2. **Building**: Follow [Build & Testing Guide](build-and-testing.md#quick-start)
3. **Using**: Check [API Reference](api/quantities.md#usage-examples) for examples
4. **Understanding**: Read [Architecture](architecture.md) to learn how it works
5. **Extending**: Follow [Extending Units Guide](extending-units.md) to add units

## By Task

### I want to...

#### Build the Project
→ [Build & Testing: Quick Start](build-and-testing.md#quick-start)

#### Fix Build Errors
→ [Build & Testing: Troubleshooting](build-and-testing.md#troubleshooting)

#### Use the Library
→ [README: Usage Examples](../README.md#usage-examples)  
→ [API Reference: Usage Examples](api/quantities.md#usage-examples)

#### Understand the Design
→ [Architecture: Overview](architecture.md#overview)  
→ [Architecture: Layered Architecture](architecture.md#layered-architecture)

#### Learn About Unit Conversions
→ [Architecture: Data Flow](architecture.md#data-flow-for-conversions)  
→ [API Reference: to<>() method](api/quantities.md#totargettype)

#### Work with Compound Units (Velocity)
→ [Architecture: Compound Units](architecture.md#compound-units-and-velocity)  
→ [README: Compound Units](../README.md#compound-units-velocity)

#### Handle Errors
→ [Architecture: Error Propagation](architecture.md#error-propagation)  
→ [API Reference: Exception Types](api/quantities.md#exception-types)

#### Run Tests
→ [Build & Testing: Running Tests](build-and-testing.md#running-tests)  
→ [Build & Testing: Testing Strategy](build-and-testing.md#testing-strategy)

#### Add a New Unit
→ [Extending Units: Step-by-Step Guide](extending-units.md#step-by-step-guide)  
→ [Extending Units: Example](extending-units.md#example-adding-a-new-length-unit)

#### Understand Code Generation
→ [Architecture: Code Generation Pipeline](architecture.md#code-generation-pipeline)

#### Integrate with My Project
→ [README: Integration](../README.md#integration-with-your-project)  
→ [Build & Testing: Advanced Build Options](build-and-testing.md#advanced-build-options)

## By Role

### User (Using the Library)
1. [README](../README.md) - Quick start and overview
2. [API Reference](api/quantities.md) - All methods and types
3. [Build & Testing](build-and-testing.md) - Setup and troubleshooting

### Contributor (Adding Units)
1. [Extending Units](extending-units.md) - Complete guide
2. [Architecture](architecture.md) - Understanding the system
3. [Build & Testing](build-and-testing.md) - Testing new units

### Maintainer (Understanding Internals)
1. [Architecture](architecture.md) - Complete architecture
2. [Build & Testing](build-and-testing.md) - Build system details
3. [API Reference](api/quantities.md) - API contracts

## Key Concepts

### Type Safety
The library uses C++ templates to prevent dimensional errors at compile time:
- [Architecture: Template Design](architecture.md#layer-3-c-template-wrapper)
- [API Reference: Quantity Class](api/quantities.md#template-class-quantity)

### Unit Conversion
Conversions go through the Rust FFI layer for correctness:
- [Architecture: Data Flow](architecture.md#data-flow-for-conversions)
- [API Reference: to<>() method](api/quantities.md#totargettype)

### Code Generation
C++ wrappers are automatically generated from Rust:
- [Architecture: Code Generation Pipeline](architecture.md#code-generation-pipeline)
- [Extending Units: Regenerate Wrappers](extending-units.md#step-3-regenerate-c-wrappers)

### Build System
CMake orchestrates Python, Cargo, and C++ compilation:
- [Architecture: Build System Integration](architecture.md#build-system-integration)
- [Build & Testing: Build Pipeline](build-and-testing.md#build-pipeline)

## External Resources

- [qtty Rust Library](https://github.com/sidereal-dave/qtty) - The underlying Rust library
- [Google Test Documentation](https://google.github.io/googletest/) - Testing framework
- [CMake Documentation](https://cmake.org/documentation/) - Build system
- [C++17 Reference](https://en.cppreference.com/w/cpp/17) - Language features

## Contributing Documentation

When updating documentation:

1. **Maintain cross-links**: Keep references between documents current
2. **Update examples**: Ensure code examples compile and work
3. **Check accuracy**: Verify against actual code/tests
4. **Use relative paths**: Enable documentation portability
5. **ASCII format**: Avoid Unicode for compatibility

## Questions?

- **Build issues**: Check [Troubleshooting](build-and-testing.md#troubleshooting)
- **API questions**: See [API Reference](api/quantities.md)
- **Design questions**: Read [Architecture](architecture.md)
- **Integration questions**: Check [README Integration](../README.md#integration-with-your-project)

---

**Last Updated**: 2025-12-14  
**qtty-cpp Version**: 0.1.0
