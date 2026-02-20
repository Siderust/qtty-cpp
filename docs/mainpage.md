# qtty-cpp

Header-only C++ wrapper over `qtty-ffi` for strongly typed physical quantities.

## Modules

- **Quantity template**: compile-time unit-safe quantity type.
- **Unit aliases**: generated unit aliases under `qtty::units::*`.
- **Literals**: user-defined literals for common units.
- **Serialization**: optional serde JSON helpers over the FFI layer.

## Error model

FFI status codes are translated into C++ exceptions:

- `QttyException`
- `InvalidUnitError`
- `IncompatibleDimensionsError`
- `ConversionError`

## Build docs

Generate API docs with:

```bash
cmake -S . -B build -G Ninja -DQTTY_BUILD_DOCS=ON
cmake --build build --target docs
```

Generated HTML is located in:

`build/docs/doxygen/html/index.html`
