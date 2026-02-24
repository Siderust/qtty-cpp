// SPDX-License-Identifier: AGPL-3.0-or-later
// Copyright (C) 2026 Vallés Puig, Ramon

//! Generate C++ unit-wrapper headers from `units.csv`.
//!
//! Reads the canonical `units.csv` (source-of-truth for every supported unit),
//! then emits one header per physical dimension and a `literals.hpp` with
//! user-defined literal operators for every unit that has a usable C++
//! identifier suffix.
//!
//! # Usage
//!
//! ```text
//! cargo run -p gen_cpp_units --bin gen_cpp_units --release \
//!     -- <path/to/units.csv> <path/to/include/qtty>
//! ```
//!
//! The second argument must point to the directory that contains `ffi_core.hpp`
//! (i.e., `include/qtty`).  The script creates `units/` under that directory.

use std::collections::HashMap;
use std::env;
use std::fmt::Write as FmtWrite;
use std::fs;
use std::path::{Path, PathBuf};

// ---------------------------------------------------------------------------
// Constants
// ---------------------------------------------------------------------------

const LICENSE: &str = "// SPDX-License-Identifier: AGPL-3.0-or-later\n\
                        // Copyright (C) 2026 Vallés Puig, Ramon\n";

/// Dimension name → (output file name, discriminant leading digit).
const DIMENSIONS: &[(&str, &str, u32)] = &[
    ("Length", "length.hpp", 1),
    ("Time", "time.hpp", 2),
    ("Angle", "angular.hpp", 3),
    ("Mass", "mass.hpp", 4),
    ("Power", "power.hpp", 5),
];

// ---------------------------------------------------------------------------
// Data types
// ---------------------------------------------------------------------------

#[derive(Debug, Clone)]
struct UnitDef {
    /// PascalCase name from the CSV, e.g. `"Kilometer"`.
    name: String,
    /// UPPER_SNAKE_CASE constant suffix, e.g. `"KILOMETER"`.
    const_suffix: String,
    /// Raw unit symbol, e.g. `"km"` or `"µm"`.
    symbol: String,
    /// Dimension name, e.g. `"Length"`.
    dimension: String,
}

// ---------------------------------------------------------------------------
// Entry point
// ---------------------------------------------------------------------------

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 3 {
        eprintln!(
            "Usage: gen_cpp_units <units_csv_path> <output_qtty_include_dir>"
        );
        std::process::exit(1);
    }

    let csv_path = Path::new(&args[1]);
    let out_dir = PathBuf::from(&args[2]);

    let units = parse_csv(csv_path);

    // Group by dimension, preserving CSV order within each group.
    let mut order: Vec<&str> = Vec::new();
    let mut by_dim: HashMap<&str, Vec<&UnitDef>> = HashMap::new();
    for unit in &units {
        let dim = unit.dimension.as_str();
        if !by_dim.contains_key(dim) {
            order.push(dim);
        }
        by_dim.entry(dim).or_default().push(unit);
    }

    // Generate one header per dimension.
    let units_dir = out_dir.join("units");
    fs::create_dir_all(&units_dir)
        .expect("Failed to create units output directory");

    for (dim_name, file_name, _) in DIMENSIONS {
        if let Some(units) = by_dim.get(dim_name) {
            let content = generate_dimension_header(dim_name, units);
            let path = units_dir.join(file_name);
            fs::write(&path, &content)
                .unwrap_or_else(|_| panic!("Failed to write {file_name}"));
            eprintln!("Generated {file_name} ({} units)", units.len());
        } else {
            eprintln!("Warning: no units found for dimension {dim_name}");
        }
    }

    // Generate literals.hpp.
    let literals_content = generate_literals(&by_dim, &order);
    let literals_path = out_dir.join("literals.hpp");
    fs::write(&literals_path, &literals_content)
        .expect("Failed to write literals.hpp");
    eprintln!("Generated literals.hpp");

    let total: usize = by_dim.values().map(|v| v.len()).sum();
    eprintln!("\nTotal units generated: {total}");
    for (dim, units) in &by_dim {
        eprintln!("  {dim}: {} units", units.len());
    }
}

// ---------------------------------------------------------------------------
// CSV parsing
// ---------------------------------------------------------------------------

/// Parse `units.csv`, skipping comments and blank lines.
//
/// Expected format (5 comma-separated fields per row):
/// ```csv
/// discriminant,dimension,name,symbol,ratio
/// 10011,Length,Meter,m,1.0
/// ```
fn parse_csv(path: &Path) -> Vec<UnitDef> {
    let content =
        fs::read_to_string(path).expect("Failed to read units.csv");
    let mut units = Vec::new();

    for line in content.lines() {
        let line = line.trim();
        if line.is_empty() || line.starts_with('#') {
            continue;
        }

        // Split on (at most) 5 commas to protect ratio values that may
        // themselves contain commas (defensive, though none currently do).
        let parts: Vec<&str> = line.splitn(5, ',').collect();
        if parts.len() != 5 {
            eprintln!("Warning: skipping malformed line: {line}");
            continue;
        }

        let discriminant: u32 = match parts[0].trim().parse() {
            Ok(v) => v,
            Err(_) => {
                eprintln!("Warning: invalid discriminant on line: {line}");
                continue;
            }
        };

        // Map the leading digit to a dimension name.
        let dim_code = discriminant / 10_000;
        let dimension = match dim_code {
            1 => "Length",
            2 => "Time",
            3 => "Angle",
            4 => "Mass",
            5 => "Power",
            _ => {
                eprintln!("Warning: unknown dimension code {dim_code} for discriminant {discriminant}");
                continue;
            }
        };

        let name = parts[2].trim().to_owned();
        let symbol = parts[3].trim().to_owned();
        let const_suffix = pascal_to_upper_snake(&name);

        units.push(UnitDef {
            name,
            const_suffix,
            symbol,
            dimension: dimension.to_owned(),
        });
    }

    units
}

// ---------------------------------------------------------------------------
// Name conversion
// ---------------------------------------------------------------------------

/// Convert a PascalCase identifier to UPPER_SNAKE_CASE.
//
/// Handles:
/// - `Meter`              → `METER`
/// - `PlanckLength`       → `PLANCK_LENGTH`
/// - `MicroArcsecond`     → `MICRO_ARCSECOND`
/// - `AstronomicalUnit`   → `ASTRONOMICAL_UNIT`
/// - `ErgPerSecond`       → `ERG_PER_SECOND`
//
/// The algorithm inserts `_` before an uppercase letter when:
/// 1. The preceding character is lowercase, **or**
/// 2. The preceding character is uppercase **and** the following character is
///    lowercase (handles abbreviations like `HTTPSClient` → `HTTPS_CLIENT`).
fn pascal_to_upper_snake(name: &str) -> String {
    let chars: Vec<char> = name.chars().collect();
    let mut out = String::with_capacity(name.len() + 8);

    for (i, &c) in chars.iter().enumerate() {
        if c.is_uppercase() && i > 0 {
            let prev = chars[i - 1];
            let next = chars.get(i + 1).copied();
            let need_sep = prev.is_lowercase()
                || (prev.is_uppercase()
                    && next.map_or(false, |n| n.is_lowercase()));
            if need_sep {
                out.push('_');
            }
        }
        for uc in c.to_uppercase() {
            out.push(uc);
        }
    }

    out
}

// ---------------------------------------------------------------------------
// Header generation — dimension files
// ---------------------------------------------------------------------------

fn generate_dimension_header(_dimension: &str, units: &[&UnitDef]) -> String {
    let mut s = String::new();

    // License + pragma once + include
    writeln!(s, "{LICENSE}").unwrap();
    writeln!(s, "#pragma once").unwrap();
    writeln!(s).unwrap();
    writeln!(s, "#include \"../ffi_core.hpp\"").unwrap();
    writeln!(s).unwrap();
    writeln!(s, "namespace qtty {{").unwrap();
    writeln!(s).unwrap();

    // Tag struct declarations (one per line, all packed together)
    for unit in units {
        writeln!(s, "struct {}Tag {{}};", unit.name).unwrap();
    }
    writeln!(s).unwrap();

    // UnitTraits specializations
    for unit in units {
        writeln!(
            s,
            "template <> struct UnitTraits<{}Tag> {{",
            unit.name
        )
        .unwrap();
        writeln!(
            s,
            "  static constexpr UnitId unit_id() {{ return UNIT_ID_{}; }}",
            unit.const_suffix
        )
        .unwrap();
        writeln!(
            s,
            "  static constexpr std::string_view symbol() {{ return \"{}\"; }}",
            escape_cpp_string(&unit.symbol)
        )
        .unwrap();
        writeln!(s, "}};").unwrap();
    }
    writeln!(s).unwrap();

    // Type aliases
    for unit in units {
        writeln!(
            s,
            "using {name} = Quantity<{name}Tag>;",
            name = unit.name
        )
        .unwrap();
    }
    writeln!(s).unwrap();

    writeln!(s, "}} // namespace qtty").unwrap();

    s
}

// ---------------------------------------------------------------------------
// Header generation — literals.hpp
// ---------------------------------------------------------------------------

fn generate_literals(
    by_dim: &HashMap<&str, Vec<&UnitDef>>,
    _order: &[&str],
) -> String {
    let mut s = String::new();

    // License + pragma once + includes
    writeln!(s, "{LICENSE}").unwrap();
    writeln!(s, "#pragma once").unwrap();
    writeln!(s).unwrap();
    writeln!(s, "#include \"units/length.hpp\"").unwrap();
    writeln!(s, "#include \"units/time.hpp\"").unwrap();
    writeln!(s, "#include \"units/angular.hpp\"").unwrap();
    writeln!(s, "#include \"units/mass.hpp\"").unwrap();
    writeln!(s, "#include \"units/power.hpp\"").unwrap();
    writeln!(s).unwrap();
    writeln!(s, "namespace qtty {{").unwrap();
    writeln!(s).unwrap();
    writeln!(s, "// Inline namespace for user-defined literals").unwrap();
    writeln!(s, "inline namespace literals {{").unwrap();

    let mut used_suffixes: HashMap<String, String> = HashMap::new();

    for (dim_name, _, _) in DIMENSIONS {
        let Some(units) = by_dim.get(dim_name) else {
            continue;
        };

        let mut section = String::new();
        let mut has_any = false;

        for unit in units {
            let Some(suffix) = make_literal_suffix(&unit.symbol) else {
                continue;
            };

            if let Some(existing) = used_suffixes.get(&suffix) {
                eprintln!(
                    "  Warning: skipping literal _{suffix} for {} \
                     (conflicts with {existing})",
                    unit.name
                );
                continue;
            }
            used_suffixes.insert(suffix.clone(), unit.name.clone());

            writeln!(section).unwrap();
            writeln!(
                section,
                "constexpr {name} operator\"\"_{suffix}(long double value) {{",
                name = unit.name
            )
            .unwrap();
            writeln!(
                section,
                "  return {name}(static_cast<double>(value));",
                name = unit.name
            )
            .unwrap();
            writeln!(section, "}}").unwrap();
            writeln!(
                section,
                "constexpr {name} operator\"\"_{suffix}(unsigned long long value) {{",
                name = unit.name
            )
            .unwrap();
            writeln!(
                section,
                "  return {name}(static_cast<double>(value));",
                name = unit.name
            )
            .unwrap();
            writeln!(section, "}}").unwrap();
            has_any = true;
        }

        if has_any {
            writeln!(s).unwrap();
            writeln!(s, "// ====================").unwrap();
            writeln!(s, "// {dim_name} literals").unwrap();
            writeln!(s, "// ====================").unwrap();
            s.push_str(&section);
        }
    }

    writeln!(s).unwrap();
    writeln!(s, "}} // namespace literals").unwrap();
    writeln!(s).unwrap();
    writeln!(s, "}} // namespace qtty").unwrap();

    s
}

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

/// Convert a unit symbol into a valid C++ identifier suffix for a UDL.
//
/// Returns `None` if the resulting string would be empty (no valid chars).
//
/// Transformation rules:
/// - `/`   → `_per_`  (e.g., `m/s` → `m_per_s`)
/// - `°`   → `deg`
/// - `′`   → `arcmin`
/// - `″`   → `arcsec`
/// - `µ`   → `u`
/// - `☉`   → `sol`
/// - `⊕`   → `earth`
/// - `☾`   → `moon`
/// - `♃`   → `jupiter`
/// - ` `   → `_`
/// - All remaining non-`[A-Za-z0-9_]` characters are dropped.
fn make_literal_suffix(symbol: &str) -> Option<String> {
    let s = symbol
        .replace('/', "_per_")
        .replace('°', "deg")
        .replace('′', "arcmin")
        .replace('″', "arcsec")
        .replace('µ', "u")
        .replace('☉', "sol")
        .replace('⊕', "earth")
        .replace('☾', "moon")
        .replace('♃', "jupiter")
        .replace(' ', "_");

    let filtered: String = s
        .chars()
        .filter(|c| c.is_ascii_alphanumeric() || *c == '_')
        .collect();

    if filtered.is_empty() {
        None
    } else {
        Some(filtered)
    }
}

/// Escape a string for embedding in a C++ string literal.
//
/// Currently only escapes backslashes and double-quotes; all other characters
/// (including UTF-8 multi-byte sequences like `µ`) are passed through as-is,
/// which is valid in C++11 and later string literals.
fn escape_cpp_string(s: &str) -> String {
    s.replace('\\', "\\\\").replace('"', "\\\"")
}

// ---------------------------------------------------------------------------
// Tests
// ---------------------------------------------------------------------------

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn snake_simple() {
        assert_eq!(pascal_to_upper_snake("Meter"), "METER");
        assert_eq!(pascal_to_upper_snake("Kilometer"), "KILOMETER");
    }

    #[test]
    fn snake_multi_word() {
        assert_eq!(pascal_to_upper_snake("PlanckLength"), "PLANCK_LENGTH");
        assert_eq!(pascal_to_upper_snake("LightYear"), "LIGHT_YEAR");
        assert_eq!(pascal_to_upper_snake("MicroArcsecond"), "MICRO_ARCSECOND");
        assert_eq!(pascal_to_upper_snake("BohrRadius"), "BOHR_RADIUS");
        assert_eq!(
            pascal_to_upper_snake("AstronomicalUnit"),
            "ASTRONOMICAL_UNIT"
        );
        assert_eq!(pascal_to_upper_snake("ErgPerSecond"), "ERG_PER_SECOND");
        assert_eq!(pascal_to_upper_snake("HourAngle"), "HOUR_ANGLE");
        assert_eq!(pascal_to_upper_snake("JulianCentury"), "JULIAN_CENTURY");
        assert_eq!(pascal_to_upper_snake("SynodicMonth"), "SYNODIC_MONTH");
        assert_eq!(pascal_to_upper_snake("SiderealDay"), "SIDEREAL_DAY");
    }

    #[test]
    fn snake_abbreviation() {
        // All-caps abbreviation followed by PascalCase word.
        assert_eq!(pascal_to_upper_snake("HTTPSClient"), "HTTPS_CLIENT");
        // Single all-caps "word" — no underscore should be added.
        assert_eq!(pascal_to_upper_snake("AU"), "AU");
    }

    #[test]
    fn literal_suffix_simple() {
        assert_eq!(make_literal_suffix("m").as_deref(), Some("m"));
        assert_eq!(make_literal_suffix("km").as_deref(), Some("km"));
    }

    #[test]
    fn literal_suffix_slash() {
        assert_eq!(
            make_literal_suffix("m/s").as_deref(),
            Some("m_per_s")
        );
    }

    #[test]
    fn literal_suffix_unicode() {
        assert_eq!(make_literal_suffix("µm").as_deref(), Some("um"));
        assert_eq!(make_literal_suffix("°").as_deref(), Some("deg"));
        assert_eq!(make_literal_suffix("′").as_deref(), Some("arcmin"));
    }

    #[test]
    fn literal_suffix_strips_non_ascii() {
        // λ̄_e → after removing non-ASCII chars the underscore and 'e' survive
        assert_eq!(make_literal_suffix("λ̄_e").as_deref(), Some("_e"));
        // A symbol that is purely non-ASCII yields None
        assert_eq!(make_literal_suffix("λ"), None);
    }
}
