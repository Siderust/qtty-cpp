#!/usr/bin/env python3
"""
Generate C++ unit wrapper headers from qtty_ffi.h

This script parses the generated qtty_ffi.h header and creates
type-safe C++ wrapper headers for all defined units.
"""

import re
from pathlib import Path
from typing import Dict, List, Tuple
from collections import defaultdict

# File header template
HEADER_TEMPLATE = """#pragma once

#include "../ffi_core.hpp"

namespace qtty {{

{tag_declarations}

{unit_traits}

{type_aliases}

}} // namespace qtty
"""

# Literal file template
LITERALS_HEADER = """#pragma once

#include "units/length.hpp"
#include "units/time.hpp"
#include "units/angular.hpp"
#include "units/mass.hpp"
#include "units/power.hpp"

namespace qtty {{

// Inline namespace for user-defined literals
inline namespace literals {{

{literal_definitions}

}} // namespace literals

}} // namespace qtty
"""

def to_pascal_case(name: str) -> str:
    """Convert UPPER_SNAKE_CASE to PascalCase"""
    parts = name.split('_')
    return ''.join(p.capitalize() for p in parts if p)

def parse_qtty_ffi_header(header_path: Path) -> Dict[str, List[Tuple[str, str, str]]]:
    """Parse qtty_ffi.h and extract unit IDs with symbols grouped by dimension"""
    units_by_dimension = defaultdict(list)
    
    with open(header_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Extract units with their symbols from comments
    # Pattern: /* UnitName (symbol) */ UNIT_ID_NAME = discriminant
    unit_pattern = r'/\*\s*(\w+)\s*\(([^)]+)\)\s*\*/\s*UNIT_ID_(\w+)\s*=\s*(\d+)'
    
    for match in re.finditer(unit_pattern, content):
        display_name = match.group(1)
        symbol = match.group(2)
        const_name = match.group(3)
        discriminant = int(match.group(4))
        
        # Determine dimension from discriminant (first digit)
        dim_code = discriminant // 10000
        dimension_map = {
            1: 'Length',
            2: 'Time', 
            3: 'Angle',
            4: 'Mass',
            5: 'Power'
        }
        
        if dim_code in dimension_map:
            dimension = dimension_map[dim_code]
            unit_name = to_pascal_case(const_name)
            units_by_dimension[dimension].append((const_name, unit_name, symbol))
    
    return dict(units_by_dimension)

def generate_header_for_dimension(dimension: str, units: List[Tuple[str, str, str]]) -> str:
    """Generate a complete header file for a dimension"""
    
    # Generate tag declarations
    tag_declarations = []
    for _, name, _ in units:
        tag_declarations.append(f"struct {name}Tag {{}};")
    
    # Generate unit traits specializations
    unit_traits = []
    for const_name, name, _ in units:
        unit_traits.append(f"""template<> struct UnitTraits<{name}Tag> {{
    static constexpr UnitId unit_id() {{ return UNIT_ID_{const_name}; }}
}};""")
    
    # Generate type aliases
    type_aliases = []
    for _, name, _ in units:
        type_aliases.append(f"using {name} = Quantity<{name}Tag>;")
    
    return HEADER_TEMPLATE.format(
        tag_declarations='\n'.join(tag_declarations),
        unit_traits='\n'.join(unit_traits),
        type_aliases='\n'.join(type_aliases)
    )

def make_literal_suffix(symbol: str) -> str:
    """Convert a symbol into a valid C++ literal suffix"""
    # Replace special characters
    suffix = symbol.replace('/', '_per_')
    suffix = suffix.replace('°', 'deg')
    suffix = suffix.replace('′', 'arcmin')
    suffix = suffix.replace('″', 'arcsec')
    suffix = suffix.replace('µ', 'u')
    suffix = suffix.replace('☉', 'sol')
    suffix = suffix.replace('⊕', 'earth')
    suffix = suffix.replace('☾', 'moon')
    suffix = suffix.replace('♃', 'jupiter')
    suffix = suffix.replace(' ', '_')
    # Remove any remaining special characters
    suffix = re.sub(r'[^a-zA-Z0-9_]', '', suffix)
    return suffix if suffix else None

def generate_literals_file(all_units: Dict[str, List[Tuple[str, str, str]]]) -> str:
    """Generate the literals.hpp file for all units with valid symbols"""
    literal_sections = []
    
    # Track used suffixes to detect collisions
    used_suffixes = {}
    
    for dimension in ['Length', 'Time', 'Angle', 'Mass', 'Power']:
        if dimension not in all_units:
            continue
        
        units = all_units[dimension]
        dimension_literals = []
        
        for _, name, symbol in units:
            suffix = make_literal_suffix(symbol)
            if suffix:
                # Check for collision
                if suffix in used_suffixes:
                    # Skip this literal to avoid collision
                    # Could also use longer suffix like _nm vs _nanometer
                    print(f"  Warning: Skipping literal _{suffix} for {name} (conflicts with {used_suffixes[suffix]})")
                    continue
                
                used_suffixes[suffix] = name
                dimension_literals.append(
                    f"""constexpr {name} operator""_{suffix}(long double value) {{
    return {name}(static_cast<double>(value));
}}
constexpr {name} operator""_{suffix}(unsigned long long value) {{
    return {name}(static_cast<double>(value));
}}""")
        
        if dimension_literals:
            literal_sections.append(f"// ====================\n// {dimension} literals\n// ====================\n")
            literal_sections.append('\n\n'.join(dimension_literals))
    
    return LITERALS_HEADER.format(
        literal_definitions='\n\n'.join(literal_sections)
    )

def main():
    script_dir = Path(__file__).parent
    header_path = script_dir / 'qtty' / 'qtty-ffi' / 'include' / 'qtty_ffi.h'
    include_dir = script_dir / 'include' / 'qtty' / 'units'
    
    if not header_path.exists():
        print(f"Error: {header_path} not found")
        print("Make sure the qtty submodule is built (cargo build -p qtty-ffi)")
        return 1
    
    print(f"Reading units from: {header_path}")
    units_by_dimension = parse_qtty_ffi_header(header_path)
    
    # Create include directory if it doesn't exist
    include_dir.mkdir(parents=True, exist_ok=True)
    
    # Mapping of dimension names to file names
    dimension_files = {
        'Length': 'length.hpp',
        'Time': 'time.hpp',
        'Angle': 'angular.hpp',
        'Mass': 'mass.hpp',
        'Power': 'power.hpp',
    }
    
    # Generate header for each dimension
    for dimension, filename in dimension_files.items():
        if dimension in units_by_dimension:
            units = units_by_dimension[dimension]
            header_content = generate_header_for_dimension(dimension, units)
            
            output_path = include_dir / filename
            with open(output_path, 'w', encoding='utf-8') as f:
                f.write(header_content)
            
            print(f"Generated {filename} with {len(units)} units")
        else:
            print(f"Warning: No units found for dimension {dimension}")
    
    # Generate literals.hpp
    literals_path = script_dir / 'include' / 'qtty' / 'literals.hpp'
    literals_content = generate_literals_file(units_by_dimension)
    with open(literals_path, 'w', encoding='utf-8') as f:
        f.write(literals_content)
    print(f"Generated literals.hpp")
    
    # Print summary
    total_units = sum(len(units) for units in units_by_dimension.values())
    print(f"\nTotal units generated: {total_units}")
    for dimension, units in sorted(units_by_dimension.items()):
        print(f"  {dimension}: {len(units)} units")
    
    return 0

if __name__ == '__main__':
    exit(main())
