# ADXL345 v11 detailed score — revised AGENTS.md rules

## 1. Scoring basis

- n=30 unique truth physical registers are scored by numeric address, bank, and page; hexadecimal and decimal representations of one numeric address are equivalent.
- m=30 truth physical locations are matched and x=0 extra extracted physical locations are counted. Extra-location factor m/(m+x)=1.000000000.
- Each matched logical register is calculated bottom-up: exact bit-range bit fields, then field parts, then the logical register. Missing truth bit fields receive zero for all primitive fields.
- Split data-byte representations are compared with the corresponding truth field part; grouping alone is not penalized.
- Descriptions are judged semantically: equivalent paraphrase 1.0, relevant but incomplete 0.5, missing or contradictory 0.0. Objective facts including names, numeric addresses, widths, bit boundaries, access types, reserved flags, default values, and value-code sets are strict.
- Value-code notation and list order are normalized. Simultaneously empty truth and candidate fields receive 1.0. Reserved bit names and descriptions may be empty. Category and unlisted fields are excluded.
- AHP weights are applied exactly as specified in AGENTS.md.

## Extracted logical register 1: `DEVID`

v11_0 location: `registers[0]`; truth association: `truth registers[0]` (`DEVID`).
Associated physical locations: 0x00 (0).

### Bottom layer: bit fields, then field parts

#### Field part 1: `DEVID` at 0x00 (0)

Locations: `truth registers[0].field_parts[0]` ↔ `v11_0 registers[0].field_parts[0]`

Truth bit field 1: `DEVID` bits 0:7

Locations: `truth registers[0].field_parts[0].bit_field[0]` ↔ `v11_0 registers[0].field_parts[0].bit_field[0]`.
Judgment: all primitive fields match.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "DEVID" | "DEVID" |
| "`field_description`" | "0.0586" | "1.000000" | "Device identification code." | "Fixed device ID code 0xE5 (345 octal)." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 8 | 8 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0xE5","value_description":"ADXL345 device ID."}] | [{"value":"11100101","value_description":"Device ID 0xE5 (345 octal)."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "1.000000" | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

`bit_field` correctness = mean(1.000000) = **1.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DEVID" | "DEVID" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Device ID"} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Device ID register address"} |
| "`description`" | "0.0693" | "1.000000" | "Fixed device ID register." | "Fixed device ID code." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "1.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct logical fields match.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DEVID" | "DEVID" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Device ID"}] | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Device ID register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Fixed device ID code of 0xE5." | "Read-only register holding a fixed device ID code of 0xE5 (345 octal)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "1.000000" | "mean(1.000000)" | "mean(1.000000)" |
| "`default_value`" | "0.0667" | "1.000000" | "11100101" | "11100101" |
| "`default_value_description`" | "0.0334" | "1.000000" | "0xE5" | "Fixed device ID code 0xE5 (345 octal)." |

\(Q(L_{1})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)


## Extracted logical register 2: `THRESH_TAP`

v11_0 location: `registers[1]`; truth association: `truth registers[1]` (`THRESH_TAP`).
Associated physical locations: 0x1D (29).

### Bottom layer: bit fields, then field parts

#### Field part 1: `THRESH_TAP` at 0x1D (29)

Locations: `truth registers[1].field_parts[0]` ↔ `v11_0 registers[1].field_parts[0]`

Truth bit field 1: `THRESH_TAP` bits 0:7

Locations: `truth registers[1].field_parts[0].bit_field[0]` ↔ `v11_0 registers[1].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "THRESH_TAP" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Unsigned tap threshold, 62.5 mg/LSB." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "THRESH_TAP" | "THRESH_TAP" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Tap threshold"} | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Tap threshold register address"} |
| "`description`" | "0.0693" | "1.000000" | "Tap threshold." | "Unsigned tap threshold, 62.5 mg/LSB." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "THRESH_TAP" | "THRESH_TAP" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Tap threshold"}] | [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Tap threshold register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned threshold magnitude for tap interrupts; scale factor 62.5 mg/LSB." | "Eight-bit unsigned threshold value for tap interrupts. Magnitude of the tap event is compared with THRESH_TAP; scale factor is 62.5 mg/LSB (0xFF = 16 g). A value of 0 may cause undesirable behavior if single/double tap interrupts are enabled." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 may result in undesirable behavior if tap interrupts are enabled." | "" |

\(Q(L_{2})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 3: `OFSX`

v11_0 location: `registers[2]`; truth association: `truth registers[2]` (`OFSX`).
Associated physical locations: 0x1E (30).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OFSX` at 0x1E (30)

Locations: `truth registers[2].field_parts[0]` ↔ `v11_0 registers[2].field_parts[0]`

Truth bit field 1: `OFSX` bits 0:7

Locations: `truth registers[2].field_parts[0].bit_field[0]` ↔ `v11_0 registers[2].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "OFSX" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Two's-complement X-axis offset, 15.6 mg/LSB." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "OFSX" | "OFSX" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"X-axis offset"} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"X-axis offset register address"} |
| "`description`" | "0.0693" | "1.000000" | "X-axis offset adjustment." | "Twos complement X-axis offset, 15.6 mg/LSB." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "OFSX" | "OFSX" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"X-axis offset"}] | [{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"X-axis offset register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement X-axis offset adjustment, 15.6 mg/LSB." | "Eight-bit user-set X-axis offset adjustment in twos complement format, scale factor 15.6 mg/LSB (0x7F = 2 g), independent of g-range. The stored value is automatically added to the acceleration data and the result placed in the output data registers; a negative value eliminates a positive offset. See the Offset Calibration section for calibration workflow and formulas (e.g., X_ACTUAL = X_MEAS - X_0g; offset register value = -Round(X_0g/4) in full-resolution)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "1.000000" | "0" | "Returns to 0x00 after power-cycling." |

\(Q(L_{3})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.906637/1.0001=\mathbf{0.906546}\)


## Extracted logical register 4: `OFSY`

v11_0 location: `registers[3]`; truth association: `truth registers[3]` (`OFSY`).
Associated physical locations: 0x1F (31).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OFSY` at 0x1F (31)

Locations: `truth registers[3].field_parts[0]` ↔ `v11_0 registers[3].field_parts[0]`

Truth bit field 1: `OFSY` bits 0:7

Locations: `truth registers[3].field_parts[0].bit_field[0]` ↔ `v11_0 registers[3].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "OFSY" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Two's-complement Y-axis offset, 15.6 mg/LSB." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "OFSY" | "OFSY" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Y-axis offset"} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Y-axis offset register address"} |
| "`description`" | "0.0693" | "1.000000" | "Y-axis offset adjustment." | "Twos complement Y-axis offset, 15.6 mg/LSB." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "OFSY" | "OFSY" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Y-axis offset"}] | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Y-axis offset register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement Y-axis offset adjustment, 15.6 mg/LSB." | "Eight-bit user-set Y-axis offset adjustment in twos complement format, scale factor 15.6 mg/LSB (0x7F = 2 g), independent of g-range. Automatically added to acceleration data; see the Offset Calibration section for the calibration workflow and formulas." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "1.000000" | "0" | "Returns to 0x00 after power-cycling." |

\(Q(L_{4})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.906637/1.0001=\mathbf{0.906546}\)


## Extracted logical register 5: `OFSZ`

v11_0 location: `registers[4]`; truth association: `truth registers[4]` (`OFSZ`).
Associated physical locations: 0x20 (32).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OFSZ` at 0x20 (32)

Locations: `truth registers[4].field_parts[0]` ↔ `v11_0 registers[4].field_parts[0]`

Truth bit field 1: `OFSZ` bits 0:7

Locations: `truth registers[4].field_parts[0].bit_field[0]` ↔ `v11_0 registers[4].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "OFSZ" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Two's-complement Z-axis offset, 15.6 mg/LSB." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "OFSZ" | "OFSZ" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Z-axis offset"} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Z-axis offset register address"} |
| "`description`" | "0.0693" | "1.000000" | "Z-axis offset adjustment." | "Twos complement Z-axis offset, 15.6 mg/LSB." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "OFSZ" | "OFSZ" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Z-axis offset"}] | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Z-axis offset register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement Z-axis offset adjustment, 15.6 mg/LSB." | "Eight-bit user-set Z-axis offset adjustment in twos complement format, scale factor 15.6 mg/LSB (0x7F = 2 g), independent of g-range. Automatically added to acceleration data; see the Offset Calibration section for the calibration workflow and formulas (e.g., Z_0g = Z_+1g - S_z)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "1.000000" | "0" | "Returns to 0x00 after power-cycling." |

\(Q(L_{5})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.906637/1.0001=\mathbf{0.906546}\)


## Extracted logical register 6: `DUR`

v11_0 location: `registers[5]`; truth association: `truth registers[5]` (`DUR`).
Associated physical locations: 0x21 (33).

### Bottom layer: bit fields, then field parts

#### Field part 1: `DUR` at 0x21 (33)

Locations: `truth registers[5].field_parts[0]` ↔ `v11_0 registers[5].field_parts[0]`

Truth bit field 1: `DUR` bits 0:7

Locations: `truth registers[5].field_parts[0].bit_field[0]` ↔ `v11_0 registers[5].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "DUR" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Unsigned tap duration, 625 us/LSB." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DUR" | "DUR" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"Tap duration"} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"Tap duration register address"} |
| "`description`" | "0.0693" | "1.000000" | "Maximum tap duration." | "Unsigned maximum tap duration, 625 us/LSB." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DUR" | "DUR" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"Tap duration"}] | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"Tap duration register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned maximum tap duration; 625 us/LSB. Zero disables tap functions." | "Eight-bit unsigned time value representing the maximum time an event must be above the THRESH_TAP threshold to qualify as a tap event. Scale factor 625 us/LSB. A value of 0 disables the single tap/double tap functions." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 disables the single-tap and double-tap functions." | "" |

\(Q(L_{6})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 7: `Latent`

v11_0 location: `registers[6]`; truth association: `truth registers[6]` (`Latent`).
Associated physical locations: 0x22 (34).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Latent` at 0x22 (34)

Locations: `truth registers[6].field_parts[0]` ↔ `v11_0 registers[6].field_parts[0]`

Truth bit field 1: `Latent` bits 0:7

Locations: `truth registers[6].field_parts[0].bit_field[0]` ↔ `v11_0 registers[6].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "Latent" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Unsigned tap latency, 1.25 ms/LSB." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "Latent" | "Latent" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Tap latency"} | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Tap latency register address"} |
| "`description`" | "0.0693" | "1.000000" | "Tap latency." | "Unsigned tap latency time, 1.25 ms/LSB." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "Latent" | "Latent" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x22","decimal":"34","bank":"","page":"","description":"Tap latency"}] | [{"hex":"0x22","decimal":"34","bank":"","page":"","description":"Tap latency register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned wait time from first tap to the start of the second-tap window; 1.25 ms/LSB." | "Eight-bit unsigned time value representing the wait time from detection of a tap event to the start of the time window (defined by the Window register) during which a possible second tap can be detected. Scale factor 1.25 ms/LSB. A value of 0 disables the double tap function." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 disables the double-tap function." | "" |

\(Q(L_{7})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 8: `Window`

v11_0 location: `registers[7]`; truth association: `truth registers[7]` (`Window`).
Associated physical locations: 0x23 (35).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Window` at 0x23 (35)

Locations: `truth registers[7].field_parts[0]` ↔ `v11_0 registers[7].field_parts[0]`

Truth bit field 1: `Window` bits 0:7

Locations: `truth registers[7].field_parts[0].bit_field[0]` ↔ `v11_0 registers[7].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "Window" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Unsigned tap window, 1.25 ms/LSB." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "Window" | "Window" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"Tap window"} | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"Tap window register address"} |
| "`description`" | "0.0693" | "1.000000" | "Tap window." | "Unsigned double-tap window time, 1.25 ms/LSB." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "Window" | "Window" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"Tap window"}] | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"Tap window register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned duration after latency during which a second tap can begin; 1.25 ms/LSB." | "Eight-bit unsigned time value representing the amount of time after expiration of the latency time (Latent register) during which a second valid tap can begin. Scale factor 1.25 ms/LSB. A value of 0 disables the double tap function." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 disables the double-tap function." | "" |

\(Q(L_{8})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 9: `THRESH_ACT`

v11_0 location: `registers[8]`; truth association: `truth registers[8]` (`THRESH_ACT`).
Associated physical locations: 0x24 (36).

### Bottom layer: bit fields, then field parts

#### Field part 1: `THRESH_ACT` at 0x24 (36)

Locations: `truth registers[8].field_parts[0]` ↔ `v11_0 registers[8].field_parts[0]`

Truth bit field 1: `THRESH_ACT` bits 0:7

Locations: `truth registers[8].field_parts[0].bit_field[0]` ↔ `v11_0 registers[8].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "THRESH_ACT" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Unsigned activity threshold, 62.5 mg/LSB." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "THRESH_ACT" | "THRESH_ACT" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Activity threshold"} | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Activity threshold register address"} |
| "`description`" | "0.0693" | "1.000000" | "Activity threshold." | "Unsigned activity threshold, 62.5 mg/LSB." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "THRESH_ACT" | "THRESH_ACT" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Activity threshold"}] | [{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Activity threshold register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned activity threshold; 62.5 mg/LSB." | "Eight-bit unsigned threshold value for detecting activity; magnitude of the activity event is compared with THRESH_ACT. Scale factor 62.5 mg/LSB. A value of 0 may cause undesirable behavior if the activity interrupt is enabled." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 may result in undesirable behavior if the activity interrupt is enabled." | "" |

\(Q(L_{9})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 10: `THRESH_INACT`

v11_0 location: `registers[9]`; truth association: `truth registers[9]` (`THRESH_INACT`).
Associated physical locations: 0x25 (37).

### Bottom layer: bit fields, then field parts

#### Field part 1: `THRESH_INACT` at 0x25 (37)

Locations: `truth registers[9].field_parts[0]` ↔ `v11_0 registers[9].field_parts[0]`

Truth bit field 1: `THRESH_INACT` bits 0:7

Locations: `truth registers[9].field_parts[0].bit_field[0]` ↔ `v11_0 registers[9].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "THRESH_INACT" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Unsigned inactivity threshold, 62.5 mg/LSB." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "THRESH_INACT" | "THRESH_INACT" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"Inactivity threshold"} | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"Inactivity threshold register address"} |
| "`description`" | "0.0693" | "1.000000" | "Inactivity threshold." | "Unsigned inactivity threshold, 62.5 mg/LSB." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "THRESH_INACT" | "THRESH_INACT" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":"Inactivity threshold"}] | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":"Inactivity threshold register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned inactivity threshold; 62.5 mg/LSB." | "Eight-bit unsigned threshold value for detecting inactivity; magnitude of the inactivity event is compared with THRESH_INACT. Scale factor 62.5 mg/LSB. A value of 0 may cause undesirable behavior if the inactivity interrupt is enabled." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 may result in undesirable behavior if the inactivity interrupt is enabled." | "" |

\(Q(L_{10})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 11: `TIME_INACT`

v11_0 location: `registers[10]`; truth association: `truth registers[10]` (`TIME_INACT`).
Associated physical locations: 0x26 (38).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_INACT` at 0x26 (38)

Locations: `truth registers[10].field_parts[0]` ↔ `v11_0 registers[10].field_parts[0]`

Truth bit field 1: `TIME_INACT` bits 0:7

Locations: `truth registers[10].field_parts[0].bit_field[0]` ↔ `v11_0 registers[10].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TIME_INACT" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Unsigned inactivity time, 1 s/LSB." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "TIME_INACT" | "TIME_INACT" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Inactivity time"} | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Inactivity time register address"} |
| "`description`" | "0.0693" | "1.000000" | "Inactivity time." | "Unsigned inactivity time, 1 sec/LSB." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "TIME_INACT" | "TIME_INACT" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Inactivity time"}] | [{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Inactivity time register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned time acceleration must remain below THRESH_INACT; 1 s/LSB." | "Eight-bit unsigned time value for how long acceleration must be less than THRESH_INACT for inactivity to be declared; scale factor 1 sec/LSB (max 255 sec). Uses filtered output data; a value of 0 results in an interrupt when output data is less than THRESH_INACT." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 results in an interrupt when acceleration is below THRESH_INACT." | "" |

\(Q(L_{11})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 12: `ACT_INACT_CTL`

v11_0 location: `registers[11]`; truth association: `truth registers[11]` (`ACT_INACT_CTL`).
Associated physical locations: 0x27 (39).

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACT_INACT_CTL` at 0x27 (39)

Locations: `truth registers[11].field_parts[0]` ↔ `v11_0 registers[11].field_parts[0]`

Truth bit field 1: `ACT_ACDC` bits 7:7

Locations: `truth registers[11].field_parts[0].bit_field[0]` ↔ `v11_0 registers[11].field_parts[0].bit_field[0]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_ACDC" | "ACT ac/dc" |
| "`field_description`" | "0.0586" | "1.000000" | "Activity coupling: 0 dc-coupled, 1 ac-coupled." | "0 selects dc-coupled operation, 1 enables ac-coupled operation for activity detection." |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"DC-coupled activity detection."},{"value":"1","value_description":"AC-coupled activity detection."}] | [{"value":"0","value_description":"DC-coupled activity operation."},{"value":"1","value_description":"AC-coupled activity operation."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 2: `ACT_X_ENABLE` bits 6:6

Locations: `truth registers[11].field_parts[0].bit_field[1]` ↔ `v11_0 registers[11].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_X_ENABLE" | "ACT_X enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable X-axis activity participation." | "1 enables x-axis participation in activity detection; 0 excludes it." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 3: `ACT_Y_ENABLE` bits 5:5

Locations: `truth registers[11].field_parts[0].bit_field[2]` ↔ `v11_0 registers[11].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_Y_ENABLE" | "ACT_Y enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable Y-axis activity participation." | "1 enables y-axis participation in activity detection; 0 excludes it." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 4: `ACT_Z_ENABLE` bits 4:4

Locations: `truth registers[11].field_parts[0].bit_field[3]` ↔ `v11_0 registers[11].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_Z_ENABLE" | "ACT_Z enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable Z-axis activity participation." | "1 enables z-axis participation in activity detection; 0 excludes it." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 5: `INACT_ACDC` bits 3:3

Locations: `truth registers[11].field_parts[0].bit_field[4]` ↔ `v11_0 registers[11].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACT_ACDC" | "INACT ac/dc" |
| "`field_description`" | "0.0586" | "1.000000" | "Inactivity coupling: 0 dc-coupled, 1 ac-coupled." | "0 selects dc-coupled operation, 1 enables ac-coupled operation for inactivity detection." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"DC-coupled inactivity detection."},{"value":"1","value_description":"AC-coupled inactivity detection."}] | [{"value":"0","value_description":"DC-coupled inactivity operation."},{"value":"1","value_description":"AC-coupled inactivity operation."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 6: `INACT_X_ENABLE` bits 2:2

Locations: `truth registers[11].field_parts[0].bit_field[5]` ↔ `v11_0 registers[11].field_parts[0].bit_field[5]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACT_X_ENABLE" | "INACT_X enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable X-axis inactivity participation." | "1 enables x-axis participation in inactivity detection; 0 excludes it." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 7: `INACT_Y_ENABLE` bits 1:1

Locations: `truth registers[11].field_parts[0].bit_field[6]` ↔ `v11_0 registers[11].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACT_Y_ENABLE" | "INACT_Y enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable Y-axis inactivity participation." | "1 enables y-axis participation in inactivity detection; 0 excludes it." |
| "`bit_start`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 8: `INACT_Z_ENABLE` bits 0:0

Locations: `truth registers[11].field_parts[0].bit_field[7]` ↔ `v11_0 registers[11].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACT_Z_ENABLE" | "INACT_Z enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable Z-axis inactivity participation." | "1 enables z-axis participation in inactivity detection; 0 excludes it." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Field-part aggregation

`bit_field` correctness = mean(0.920492, 0.710771, 0.710771, 0.710771, 0.920492, 0.710771, 0.710771, 0.710771) = **0.763201**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "ACT_INACT_CTL" | "ACT_INACT_CTL" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"Axis enable control for activity and inactivity detection"} | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"Activity/inactivity control register address"} |
| "`description`" | "0.0693" | "1.000000" | "Activity/inactivity axis control." | "Activity/inactivity coupling and axis participation control." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.763201" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.763201)/1.0000=0.925906/1.0000=\mathbf{0.925906}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.925906) = **0.925906**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "ACT_INACT_CTL" | "ACT_INACT_CTL" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Axis enable control for activity and inactivity detection"}] | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Activity/inactivity control register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Axis and AC/DC coupling control for activity and inactivity detection." | "Axis enable control for activity and inactivity detection. Selects ac/dc-coupled operation and per-axis participation. In dc-coupled operation current acceleration magnitude is compared directly with THRESH_ACT/THRESH_INACT; in ac-coupled operation a reference value is used and the difference magnitude is compared. For activity, participating axes are logically OR'ed; for inactivity, participating axes are logically AND'ed. If all axes are excluded the function is disabled." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.925906" | "mean(0.925906)" | "mean(0.925906)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "DC-coupled; all axes disabled" | "" |

\(Q(L_{12})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.925906 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.944568/1.0001=\mathbf{0.944474}\)


## Extracted logical register 13: `THRESH_FF`

v11_0 location: `registers[12]`; truth association: `truth registers[12]` (`THRESH_FF`).
Associated physical locations: 0x28 (40).

### Bottom layer: bit fields, then field parts

#### Field part 1: `THRESH_FF` at 0x28 (40)

Locations: `truth registers[12].field_parts[0]` ↔ `v11_0 registers[12].field_parts[0]`

Truth bit field 1: `THRESH_FF` bits 0:7

Locations: `truth registers[12].field_parts[0].bit_field[0]` ↔ `v11_0 registers[12].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "THRESH_FF" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Unsigned free-fall threshold, 62.5 mg/LSB." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "THRESH_FF" | "THRESH_FF" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Free-fall threshold"} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Free-fall threshold register address"} |
| "`description`" | "0.0693" | "1.000000" | "Free-fall threshold." | "Unsigned free-fall threshold, 62.5 mg/LSB." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "THRESH_FF" | "THRESH_FF" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Free-fall threshold"}] | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Free-fall threshold register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned free-fall threshold; 62.5 mg/LSB." | "Eight-bit unsigned threshold for free-fall detection; acceleration on all axes is compared with THRESH_FF (logical AND). Scale factor 62.5 mg/LSB. Values between 300 mg and 600 mg (0x05 to 0x09) are recommended; 0 may cause undesirable behavior." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 mg may result in undesirable behavior if the free-fall interrupt is enabled." | "" |

\(Q(L_{13})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 14: `TIME_FF`

v11_0 location: `registers[13]`; truth association: `truth registers[13]` (`TIME_FF`).
Associated physical locations: 0x29 (41).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_FF` at 0x29 (41)

Locations: `truth registers[13].field_parts[0]` ↔ `v11_0 registers[13].field_parts[0]`

Truth bit field 1: `TIME_FF` bits 0:7

Locations: `truth registers[13].field_parts[0].bit_field[0]` ↔ `v11_0 registers[13].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TIME_FF" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Unsigned free-fall time, 5 ms/LSB." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "TIME_FF" | "TIME_FF" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"Free-fall time"} | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"Free-fall time register address"} |
| "`description`" | "0.0693" | "1.000000" | "Free-fall time." | "Unsigned free-fall time, 5 ms/LSB." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "TIME_FF" | "TIME_FF" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x29","decimal":"41","bank":"","page":"","description":"Free-fall time"}] | [{"hex":"0x29","decimal":"41","bank":"","page":"","description":"Free-fall time register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned minimum free-fall time; 5 ms/LSB." | "Eight-bit unsigned minimum time that all axes must be less than THRESH_FF to generate a free-fall interrupt. Scale factor 5 ms/LSB (1.28 sec maximum). Values between 100 ms and 350 ms (0x14 to 0x46) are recommended." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 may result in undesirable behavior if the free-fall interrupt is enabled." | "" |

\(Q(L_{14})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 15: `TAP_AXES`

v11_0 location: `registers[14]`; truth association: `truth registers[14]` (`TAP_AXES`).
Associated physical locations: 0x2A (42).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TAP_AXES` at 0x2A (42)

Locations: `truth registers[14].field_parts[0]` ↔ `v11_0 registers[14].field_parts[0]`

Truth bit field 1: `SUPPRESS` bits 3:3

Locations: `truth registers[14].field_parts[0].bit_field[0]` ↔ `v11_0 registers[14].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "SUPPRESS" | "Suppress" |
| "`field_description`" | "0.0586" | "1.000000" | "Suppress double-tap detection for acceleration above THRESH_TAP between taps." | "Setting suppresses double tap detection if acceleration greater than THRESH_TAP is present between taps." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Do not suppress."},{"value":"1","value_description":"Suppress double-tap detection."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 2: `TAP_X_ENABLE` bits 2:2

Locations: `truth registers[14].field_parts[0].bit_field[1]` ↔ `v11_0 registers[14].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TAP_X_ENABLE" | "TAP_X enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable X-axis tap participation." | "1 enables x-axis participation in tap detection; 0 excludes it." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude X axis from tap detection."},{"value":"1","value_description":"Enable X-axis participation in tap detection."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 3: `TAP_Y_ENABLE` bits 1:1

Locations: `truth registers[14].field_parts[0].bit_field[2]` ↔ `v11_0 registers[14].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TAP_Y_ENABLE" | "TAP_Y enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable Y-axis tap participation." | "1 enables y-axis participation in tap detection; 0 excludes it." |
| "`bit_start`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude Y axis from tap detection."},{"value":"1","value_description":"Enable Y-axis participation in tap detection."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 4: `TAP_Z_ENABLE` bits 0:0

Locations: `truth registers[14].field_parts[0].bit_field[3]` ↔ `v11_0 registers[14].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TAP_Z_ENABLE" | "TAP_Z enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable Z-axis tap participation." | "1 enables z-axis participation in tap detection; 0 excludes it." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude Z axis from tap detection."},{"value":"1","value_description":"Enable Z-axis participation in tap detection."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 5: `RESERVED` bits 4:7

Locations: `truth registers[14].field_parts[0].bit_field[4]` ↔ `v11_0 registers[14].field_parts[0].bit_field[0]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RESERVED" | "0" |
| "`field_description`" | "0.0586" | "1.000000" | "Reserved bits; do not access." | "Unused bits shown as 0." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 4 | 4 |
| "`values`" | "0.2097" | "1.000000" | [] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | true | true |
| "`type_write_read`" | "0.0583" | "1.000000" | "" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

`bit_field` correctness = mean(0.710771, 0.710771, 0.710771, 0.710771, 0.978798) = **0.764376**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "TAP_AXES" | "TAP_AXES" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Axis control for single tap/double tap"} | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Tap axes control register address"} |
| "`description`" | "0.0693" | "1.000000" | "Tap-axis control." | "Tap axis participation and suppress control." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.764376" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.764376)/1.0000=0.926273/1.0000=\mathbf{0.926273}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.926273) = **0.926273**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "TAP_AXES" | "TAP_AXES" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Axis control for single tap/double tap"}] | [{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Tap axes control register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Axis control and suppress control for single-tap/double-tap detection." | "Axis control for single tap/double tap. TAP_x enable bits (1) include the corresponding axis in tap detection and (0) exclude it. The Suppress bit suppresses double tap detection if acceleration greater than THRESH_TAP is present between taps." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.926273" | "mean(0.926273)" | "mean(0.926273)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "All tap axes disabled; suppress disabled" | "" |

\(Q(L_{15})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.926273 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.944678/1.0001=\mathbf{0.944583}\)


## Extracted logical register 16: `ACT_TAP_STATUS`

v11_0 location: `registers[15]`; truth association: `truth registers[15]` (`ACT_TAP_STATUS`).
Associated physical locations: 0x2B (43).

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACT_TAP_STATUS` at 0x2B (43)

Locations: `truth registers[15].field_parts[0]` ↔ `v11_0 registers[15].field_parts[0]`

Truth bit field 1: `ACT_X_SOURCE` bits 6:6

Locations: `truth registers[15].field_parts[0].bit_field[0]` ↔ `v11_0 registers[15].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_X_SOURCE" | "ACT_X source" |
| "`field_description`" | "0.0586" | "1.000000" | "X axis involved in activity event." | "1 indicates x-axis involvement in the activity event." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"X axis not involved in activity."},{"value":"1","value_description":"X axis involved in activity."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 2: `ACT_Y_SOURCE` bits 5:5

Locations: `truth registers[15].field_parts[0].bit_field[1]` ↔ `v11_0 registers[15].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_Y_SOURCE" | "ACT_Y source" |
| "`field_description`" | "0.0586" | "1.000000" | "Y axis involved in activity event." | "1 indicates y-axis involvement in the activity event." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Y axis not involved in activity."},{"value":"1","value_description":"Y axis involved in activity."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 3: `ACT_Z_SOURCE` bits 4:4

Locations: `truth registers[15].field_parts[0].bit_field[2]` ↔ `v11_0 registers[15].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_Z_SOURCE" | "ACT_Z source" |
| "`field_description`" | "0.0586" | "1.000000" | "Z axis involved in activity event." | "1 indicates z-axis involvement in the activity event." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Z axis not involved in activity."},{"value":"1","value_description":"Z axis involved in activity."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 4: `ASLEEP` bits 3:3

Locations: `truth registers[15].field_parts[0].bit_field[3]` ↔ `v11_0 registers[15].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ASLEEP" | "Asleep" |
| "`field_description`" | "0.0586" | "1.000000" | "Sleep status: 1 asleep, 0 not asleep." | "1 indicates the part is asleep; 0 not asleep. Toggles only if configured for auto sleep." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Not asleep."},{"value":"1","value_description":"Asleep."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 5: `TAP_X_SOURCE` bits 2:2

Locations: `truth registers[15].field_parts[0].bit_field[4]` ↔ `v11_0 registers[15].field_parts[0].bit_field[5]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TAP_X_SOURCE" | "TAP_X source" |
| "`field_description`" | "0.0586" | "1.000000" | "X axis involved in tap event." | "1 indicates x-axis involvement in the tap event." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"X axis not involved in tap."},{"value":"1","value_description":"X axis involved in tap."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 6: `TAP_Y_SOURCE` bits 1:1

Locations: `truth registers[15].field_parts[0].bit_field[5]` ↔ `v11_0 registers[15].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TAP_Y_SOURCE" | "TAP_Y source" |
| "`field_description`" | "0.0586" | "1.000000" | "Y axis involved in tap event." | "1 indicates y-axis involvement in the tap event." |
| "`bit_start`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Y axis not involved in tap."},{"value":"1","value_description":"Y axis involved in tap."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 7: `TAP_Z_SOURCE` bits 0:0

Locations: `truth registers[15].field_parts[0].bit_field[6]` ↔ `v11_0 registers[15].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TAP_Z_SOURCE" | "TAP_Z source" |
| "`field_description`" | "0.0586" | "1.000000" | "Z axis involved in tap event." | "1 indicates z-axis involvement in the tap event." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Z axis not involved in tap."},{"value":"1","value_description":"Z axis involved in tap."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 8: `RESERVED` bits 7:7

Locations: `truth registers[15].field_parts[0].bit_field[7]` ↔ `v11_0 registers[15].field_parts[0].bit_field[0]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RESERVED" | "0" |
| "`field_description`" | "0.0586" | "1.000000" | "Reserved bit." | "Unused bit shown as 0." |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | true | true |
| "`type_write_read`" | "0.0583" | "1.000000" | "" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

`bit_field` correctness = mean(0.710771, 0.710771, 0.710771, 0.710771, 0.710771, 0.710771, 0.710771, 0.978798) = **0.744274**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "ACT_TAP_STATUS" | "ACT_TAP_STATUS" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Source of single tap/double tap"} | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Activity/tap status register address"} |
| "`description`" | "0.0693" | "1.000000" | "Activity and tap source status." | "First-axis event source and asleep status." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.744274" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.744274)/1.0000=0.919983/1.0000=\mathbf{0.919983}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.919983) = **0.919983**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "ACT_TAP_STATUS" | "ACT_TAP_STATUS" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Source of single tap/double tap"}] | [{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Activity/tap status register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Reports the first axis involved in a tap or activity event and asleep status." | "Read-only source of single tap/double tap and activity events. ACT_x/TAP_x source bits indicate the first axis involved (1 = involved); they are not cleared but overwritten by new data and should be read before clearing the interrupt. Asleep bit indicates sleep state (toggles only in auto sleep). Disabling an axis clears the corresponding source bit on the next event." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.919983" | "mean(0.919983)" | "mean(0.919983)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "No event source; not asleep" | "" |

\(Q(L_{16})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.919983 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.942799/1.0001=\mathbf{0.942705}\)


## Extracted logical register 17: `BW_RATE`

v11_0 location: `registers[16]`; truth association: `truth registers[16]` (`BW_RATE`).
Associated physical locations: 0x2C (44).

### Bottom layer: bit fields, then field parts

#### Field part 1: `BW_RATE` at 0x2C (44)

Locations: `truth registers[16].field_parts[0]` ↔ `v11_0 registers[16].field_parts[0]`

Truth bit field 1: `LOW_POWER` bits 4:4

Locations: `truth registers[16].field_parts[0].bit_field[0]` ↔ `v11_0 registers[16].field_parts[0].bit_field[1]`.
Judgment: deductions: type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "LOW_POWER" | "LOW_POWER" |
| "`field_description`" | "0.0586" | "1.000000" | "Power mode selection." | "0 selects normal operation; 1 selects reduced power operation with somewhat higher noise." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Normal operation."},{"value":"1","value_description":"Reduced-power operation."}] | [{"value":"0","value_description":"Normal operation."},{"value":"1","value_description":"Reduced power operation (higher noise)."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\)

Truth bit field 2: `RATE` bits 0:3

Locations: `truth registers[16].field_parts[0].bit_field[1]` ↔ `v11_0 registers[16].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RATE" | "Rate" |
| "`field_description`" | "0.0586" | "1.000000" | "Output data rate and bandwidth selection; see Table 7 and Table 8 on datasheet page 13." | "Select device bandwidth and output data rate; default 0x0A = 100 Hz output data rate. Refer to Table 7 and Table 8 for the rate/bit mapping." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 4 | 4 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0000 (0x00)","value_description":"0.10 Hz output data rate; 0.05 Hz bandwidth."},{"value":"0001 (0x01)","value_description":"0.20 Hz output data rate; 0.10 Hz bandwidth."},{"value":"0010 (0x02)","value_description":"0.39 Hz output data rate; 0.20 Hz bandwidth."},{"value":"0011 (0x03)","value_description":"0.78 Hz output data rate; 0.39 Hz bandwidth."},{"value":"0100 (0x04)","value_description":"1.56 Hz output data rate; 0.78 Hz bandwidth."},{"value":"0101 (0x05)","value_description":"3.13 Hz output data rate; 1.56 Hz bandwidth."},{"value":"0110 (0x06)","value_description":"6.25 Hz output data rate; 3.13 Hz bandwidth."},{"value":"0111 (0x07)","value_description":"12.5 Hz output data rate; 6.25 Hz bandwidth; low-power mode table entry."},{"value":"1000 (0x08)","value_description":"25 Hz output data rate; 12.5 Hz bandwidth; low-power mode table entry."},{"value":"1001 (0x09)","value_description":"50 Hz output data rate; 25 Hz bandwidth; low-power mode table entry."},{"value":"1010 (0x0A)","value_description":"100 Hz output data rate; 50 Hz bandwidth; default; low-power mode table entry."},{"value":"1011 (0x0B)","value_description":"200 Hz output data rate; 100 Hz bandwidth; low-power mode table entry."},{"value":"1100 (0x0C)","value_description":"400 Hz output data rate; 200 Hz bandwidth; low-power mode table entry."},{"value":"1101 (0x0D)","value_description":"800 Hz output data rate; 400 Hz bandwidth."},{"value":"1110 (0x0E)","value_description":"1600 Hz output data rate; 800 Hz bandwidth."},{"value":"1111 (0x0F)","value_description":"3200 Hz output data rate; 1600 Hz bandwidth."}] | [{"value":"0x0A","value_description":"Default; 100 Hz output data rate."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 3: `RESERVED` bits 5:7

Locations: `truth registers[16].field_parts[0].bit_field[2]` ↔ `v11_0 registers[16].field_parts[0].bit_field[0]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RESERVED" | "0" |
| "`field_description`" | "0.0586" | "1.000000" | "Reserved bits." | "Unused bits shown as 0." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 3 | 3 |
| "`values`" | "0.2097" | "1.000000" | [] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | true | true |
| "`type_write_read`" | "0.0583" | "1.000000" | "" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

`bit_field` correctness = mean(0.941694, 0.710771, 0.978798) = **0.877088**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "BW_RATE" | "BW_RATE" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Data rate and power mode control"} | {"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Data rate and power mode control register address"} |
| "`description`" | "0.0693" | "1.000000" | "Data rate and power mode control." | "Power mode and output data rate selection." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.877088" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.877088)/1.0000=0.961541/1.0000=\mathbf{0.961541}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.961541) = **0.961541**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "BW_RATE" | "BW_RATE" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Data rate and power mode control"}] | [{"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Data rate and power mode control register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Controls output data rate, bandwidth and low-power mode." | "Data rate and power mode control. LOW_POWER bit selects normal (0) or reduced power operation (1, higher noise). Rate bits select device bandwidth and output data rate (see Table 7 and Table 8); default 0x0A = 100 Hz. Self-test requires normal power (LOW_POWER = 0) and rate 100 Hz-800 Hz or 3200 Hz (rate bits 0x0A-0x0D or 0x0F)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.961541" | "mean(0.961541)" | "mean(0.961541)" |
| "`default_value`" | "0.0667" | "1.000000" | "00001010" | "00001010" |
| "`default_value_description`" | "0.0334" | "0.500000" | "100 Hz, normal power" | "Rate default 0x0A = 100 Hz output data rate." |

\(Q(L_{17})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.961541 + 0.0667×1.000000 + 0.0334×0.500000)/1.0001=0.971912/1.0001=\mathbf{0.971815}\)


## Extracted logical register 18: `POWER_CTL`

v11_0 location: `registers[17]`; truth association: `truth registers[17]` (`POWER_CTL`).
Associated physical locations: 0x2D (45).

### Bottom layer: bit fields, then field parts

#### Field part 1: `POWER_CTL` at 0x2D (45)

Locations: `truth registers[17].field_parts[0]` ↔ `v11_0 registers[17].field_parts[0]`

Truth bit field 1: `LINK` bits 5:5

Locations: `truth registers[17].field_parts[0].bit_field[0]` ↔ `v11_0 registers[17].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "LINK" | "Link" |
| "`field_description`" | "0.0586" | "1.000000" | "Serially links activity and inactivity functions." | "1 with activity and inactivity enabled delays activity until inactivity is detected, serially linking the functions; 0 makes them concurrent." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Activity and inactivity functions operate concurrently."},{"value":"1","value_description":"Activity and inactivity functions are serially linked."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 2: `AUTO_SLEEP` bits 4:4

Locations: `truth registers[17].field_parts[0].bit_field[1]` ↔ `v11_0 registers[17].field_parts[0].bit_field[2]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "AUTO_SLEEP" | "AUTO_SLEEP" |
| "`field_description`" | "0.0586" | "1.000000" | "Enables automatic sleep when linked inactivity is detected." | "If Link is set, 1 enables auto-sleep on inactivity and automatic wake on activity; 0 disables automatic switching. No effect if Link is not set." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Automatic sleep disabled."},{"value":"1","value_description":"Automatic sleep enabled when linked inactivity is detected."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 3: `MEASURE` bits 3:3

Locations: `truth registers[17].field_parts[0].bit_field[2]` ↔ `v11_0 registers[17].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "MEASURE" | "Measure" |
| "`field_description`" | "0.0586" | "1.000000" | "0 standby, 1 measurement mode." | "0 places the part into standby mode; 1 places the part into measurement mode." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Standby mode."},{"value":"1","value_description":"Measurement mode."}] | [{"value":"0","value_description":"Standby mode."},{"value":"1","value_description":"Measurement mode."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 4: `SLEEP` bits 2:2

Locations: `truth registers[17].field_parts[0].bit_field[3]` ↔ `v11_0 registers[17].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "SLEEP" | "Sleep" |
| "`field_description`" | "0.0586" | "1.000000" | "0 normal, 1 sleep mode." | "0 normal operation; 1 sleep mode (suppresses DATA_READY, stops FIFO, sampling rate set by Wakeup bits; only activity function usable)." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Normal operation."},{"value":"1","value_description":"Sleep mode."}] | [{"value":"0","value_description":"Normal mode of operation."},{"value":"1","value_description":"Sleep mode."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 5: `WAKEUP` bits 0:1

Locations: `truth registers[17].field_parts[0].bit_field[4]` ↔ `v11_0 registers[17].field_parts[0].bit_field[5]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "WAKEUP" | "Wakeup" |
| "`field_description`" | "0.0586" | "1.000000" | "Sleep-mode reading frequency." | "Controls frequency of readings in sleep mode." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 2 | 2 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"00","value_description":"8 Hz."},{"value":"01","value_description":"4 Hz."},{"value":"10","value_description":"2 Hz."},{"value":"11","value_description":"1 Hz."}] | [{"value":"00","value_description":"8 Hz"},{"value":"01","value_description":"4 Hz"},{"value":"10","value_description":"2 Hz"},{"value":"11","value_description":"1 Hz"}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 6: `RESERVED` bits 6:7

Locations: `truth registers[17].field_parts[0].bit_field[5]` ↔ `v11_0 registers[17].field_parts[0].bit_field[0]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RESERVED" | "0" |
| "`field_description`" | "0.0586" | "1.000000" | "Reserved bits." | "Unused bits shown as 0." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 2 | 2 |
| "`values`" | "0.2097" | "1.000000" | [] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | true | true |
| "`type_write_read`" | "0.0583" | "1.000000" | "" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

`bit_field` correctness = mean(0.710771, 0.731973, 0.920492, 0.920492, 0.920492, 0.978798) = **0.863836**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "POWER_CTL" | "POWER_CTL" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Power-saving features control"} | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Power-saving features control register address"} |
| "`description`" | "0.0693" | "1.000000" | "Power-control bits." | "Link, auto-sleep, measure, sleep, and wakeup control." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.863836" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.863836)/1.0000=0.957394/1.0000=\mathbf{0.957394}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.957394) = **0.957394**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "POWER_CTL" | "POWER_CTL" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Power-saving features control"}] | [{"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Power-saving features control register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Controls link, autosleep, measurement, sleep and wakeup behavior." | "Power-saving features control. Link bit serially links activity and inactivity functions. AUTO_SLEEP (only when Link is set) enables automatic switching to sleep mode on inactivity and wake-up on activity. Measure bit: 0 standby, 1 measurement (powers up in standby). Sleep bit places part in sleep mode (suppresses DATA_READY, stops FIFO, sampling set by Wakeup bits). Wakeup bits set sleep-mode reading frequency. When clearing Link/AUTO_SLEEP/Sleep, place part in standby then back to measurement to ensure proper biasing." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.957394" | "mean(0.957394)" | "mean(0.957394)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "Standby, normal mode" | "" |

\(Q(L_{18})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.957394 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.953974/1.0001=\mathbf{0.953878}\)


## Extracted logical register 19: `INT_ENABLE`

v11_0 location: `registers[18]`; truth association: `truth registers[18]` (`INT_ENABLE`).
Associated physical locations: 0x2E (46).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_ENABLE` at 0x2E (46)

Locations: `truth registers[18].field_parts[0]` ↔ `v11_0 registers[18].field_parts[0]`

Truth bit field 1: `DATA_READY` bits 7:7

Locations: `truth registers[18].field_parts[0].bit_field[0]` ↔ `v11_0 registers[18].field_parts[0].bit_field[0]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "DATA_READY" | "DATA_READY" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable DATA_READY interrupt output." | "1 enables the data-ready interrupt output." |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 2: `SINGLE_TAP` bits 6:6

Locations: `truth registers[18].field_parts[0].bit_field[1]` ↔ `v11_0 registers[18].field_parts[0].bit_field[1]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "SINGLE_TAP" | "SINGLE_TAP" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable single-tap interrupt." | "1 enables the single-tap interrupt." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 3: `DOUBLE_TAP` bits 5:5

Locations: `truth registers[18].field_parts[0].bit_field[2]` ↔ `v11_0 registers[18].field_parts[0].bit_field[2]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "DOUBLE_TAP" | "DOUBLE_TAP" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable double-tap interrupt." | "1 enables the double-tap interrupt." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 4: `ACTIVITY` bits 4:4

Locations: `truth registers[18].field_parts[0].bit_field[3]` ↔ `v11_0 registers[18].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACTIVITY" | "Activity" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable activity interrupt." | "1 enables the activity interrupt." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 5: `INACTIVITY` bits 3:3

Locations: `truth registers[18].field_parts[0].bit_field[4]` ↔ `v11_0 registers[18].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACTIVITY" | "Inactivity" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable inactivity interrupt." | "1 enables the inactivity interrupt." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 6: `FREE_FALL` bits 2:2

Locations: `truth registers[18].field_parts[0].bit_field[5]` ↔ `v11_0 registers[18].field_parts[0].bit_field[5]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "FREE_FALL" | "FREE_FALL" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable free-fall interrupt." | "1 enables the free-fall interrupt." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 7: `WATERMARK` bits 1:1

Locations: `truth registers[18].field_parts[0].bit_field[6]` ↔ `v11_0 registers[18].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "WATERMARK" | "Watermark" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable watermark interrupt output." | "1 enables the watermark interrupt output." |
| "`bit_start`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 8: `OVERRUN` bits 0:0

Locations: `truth registers[18].field_parts[0].bit_field[7]` ↔ `v11_0 registers[18].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "OVERRUN" | "Overrun" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable overrun interrupt output." | "1 enables the overrun interrupt output." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Field-part aggregation

`bit_field` correctness = mean(0.731973, 0.731973, 0.731973, 0.710771, 0.710771, 0.731973, 0.710771, 0.710771) = **0.721372**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "INT_ENABLE" | "INT_ENABLE" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":"Interrupt enable control"} | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":"Interrupt enable control register address"} |
| "`description`" | "0.0693" | "1.000000" | "Interrupt enable control." | "Per-function interrupt enable bits." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.721372" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.721372)/1.0000=0.912817/1.0000=\mathbf{0.912817}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.912817) = **0.912817**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "INT_ENABLE" | "INT_ENABLE" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x2E","decimal":"46","bank":"","page":"","description":"Interrupt enable control"}] | [{"hex":"0x2E","decimal":"46","bank":"","page":"","description":"Interrupt enable control register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Enables interrupt generation for the listed functions." | "Setting a bit to 1 enables the corresponding function to generate interrupts; 0 prevents it. DATA_READY, Watermark, and Overrun bits enable only the interrupt output (functions always enabled). Interrupts should be configured (functions and INT_MAP mapping) before enabling outputs." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.912817" | "mean(0.912817)" | "mean(0.912817)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "All interrupts disabled" | "" |

\(Q(L_{19})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.912817 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.940659/1.0001=\mathbf{0.940564}\)


## Extracted logical register 20: `INT_MAP`

v11_0 location: `registers[19]`; truth association: `truth registers[19]` (`INT_MAP`).
Associated physical locations: 0x2F (47).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_MAP` at 0x2F (47)

Locations: `truth registers[19].field_parts[0]` ↔ `v11_0 registers[19].field_parts[0]`

Truth bit field 1: `DATA_READY` bits 7:7

Locations: `truth registers[19].field_parts[0].bit_field[0]` ↔ `v11_0 registers[19].field_parts[0].bit_field[0]`.
Judgment: deductions: type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "DATA_READY" | "DATA_READY" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0 maps to INT1; 1 maps to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [{"value":"0","value_description":"Send to INT1 pin."},{"value":"1","value_description":"Send to INT2 pin."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\)

Truth bit field 2: `SINGLE_TAP` bits 6:6

Locations: `truth registers[19].field_parts[0].bit_field[1]` ↔ `v11_0 registers[19].field_parts[0].bit_field[1]`.
Judgment: deductions: type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "SINGLE_TAP" | "SINGLE_TAP" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0 maps to INT1; 1 maps to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [{"value":"0","value_description":"Send to INT1 pin."},{"value":"1","value_description":"Send to INT2 pin."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\)

Truth bit field 3: `DOUBLE_TAP` bits 5:5

Locations: `truth registers[19].field_parts[0].bit_field[2]` ↔ `v11_0 registers[19].field_parts[0].bit_field[2]`.
Judgment: deductions: type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "DOUBLE_TAP" | "DOUBLE_TAP" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0 maps to INT1; 1 maps to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [{"value":"0","value_description":"Send to INT1 pin."},{"value":"1","value_description":"Send to INT2 pin."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\)

Truth bit field 4: `ACTIVITY` bits 4:4

Locations: `truth registers[19].field_parts[0].bit_field[3]` ↔ `v11_0 registers[19].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACTIVITY" | "Activity" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0 maps to INT1; 1 maps to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [{"value":"0","value_description":"Send to INT1 pin."},{"value":"1","value_description":"Send to INT2 pin."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 5: `INACTIVITY` bits 3:3

Locations: `truth registers[19].field_parts[0].bit_field[4]` ↔ `v11_0 registers[19].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACTIVITY" | "Inactivity" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0 maps to INT1; 1 maps to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [{"value":"0","value_description":"Send to INT1 pin."},{"value":"1","value_description":"Send to INT2 pin."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 6: `FREE_FALL` bits 2:2

Locations: `truth registers[19].field_parts[0].bit_field[5]` ↔ `v11_0 registers[19].field_parts[0].bit_field[5]`.
Judgment: deductions: type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "FREE_FALL" | "FREE_FALL" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0 maps to INT1; 1 maps to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [{"value":"0","value_description":"Send to INT1 pin."},{"value":"1","value_description":"Send to INT2 pin."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\)

Truth bit field 7: `WATERMARK` bits 1:1

Locations: `truth registers[19].field_parts[0].bit_field[6]` ↔ `v11_0 registers[19].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "WATERMARK" | "Watermark" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0 maps to INT1; 1 maps to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [{"value":"0","value_description":"Send to INT1 pin."},{"value":"1","value_description":"Send to INT2 pin."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 8: `OVERRUN` bits 0:0

Locations: `truth registers[19].field_parts[0].bit_field[7]` ↔ `v11_0 registers[19].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "OVERRUN" | "Overrun" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0 maps to INT1; 1 maps to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [{"value":"0","value_description":"Send to INT1 pin."},{"value":"1","value_description":"Send to INT2 pin."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Field-part aggregation

`bit_field` correctness = mean(0.941694, 0.941694, 0.941694, 0.920492, 0.920492, 0.941694, 0.920492, 0.920492) = **0.931093**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "INT_MAP" | "INT_MAP" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":"Interrupt mapping control"} | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":"Interrupt mapping control register address"} |
| "`description`" | "0.0693" | "1.000000" | "Interrupt mapping." | "Per-function interrupt pin mapping (0=INT1, 1=INT2)." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.931093" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.931093)/1.0000=0.978439/1.0000=\mathbf{0.978439}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.978439) = **0.978439**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "INT_MAP" | "INT_MAP" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x2F","decimal":"47","bank":"","page":"","description":"Interrupt mapping control"}] | [{"hex":"0x2F","decimal":"47","bank":"","page":"","description":"Interrupt mapping control register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Maps each interrupt to INT1 or INT2; 0 selects INT1 and 1 selects INT2." | "Maps each interrupt function to an output pin: a bit set to 0 sends the respective interrupt to INT1; a bit set to 1 sends it to INT2. All selected interrupts for a given pin are OR'ed." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.978439" | "mean(0.978439)" | "mean(0.978439)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "All interrupts mapped to INT1" | "" |

\(Q(L_{20})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.978439 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.960260/1.0001=\mathbf{0.960164}\)


## Extracted logical register 21: `INT_SOURCE`

v11_0 location: `registers[20]`; truth association: `truth registers[20]` (`INT_SOURCE`).
Associated physical locations: 0x30 (48).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_SOURCE` at 0x30 (48)

Locations: `truth registers[20].field_parts[0]` ↔ `v11_0 registers[20].field_parts[0]`

Truth bit field 1: `DATA_READY` bits 7:7

Locations: `truth registers[20].field_parts[0].bit_field[0]` ↔ `v11_0 registers[20].field_parts[0].bit_field[0]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "DATA_READY" | "DATA_READY" |
| "`field_description`" | "0.0586" | "1.000000" | "DATA_READY event occurred." | "1 indicates new data is available; cleared when no new data is available." |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 2: `SINGLE_TAP` bits 6:6

Locations: `truth registers[20].field_parts[0].bit_field[1]` ↔ `v11_0 registers[20].field_parts[0].bit_field[1]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "SINGLE_TAP" | "SINGLE_TAP" |
| "`field_description`" | "0.0586" | "1.000000" | "Single-tap event occurred." | "1 indicates a single-tap event occurred." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 3: `DOUBLE_TAP` bits 5:5

Locations: `truth registers[20].field_parts[0].bit_field[2]` ↔ `v11_0 registers[20].field_parts[0].bit_field[2]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "DOUBLE_TAP" | "DOUBLE_TAP" |
| "`field_description`" | "0.0586" | "1.000000" | "Double-tap event occurred." | "1 indicates a double-tap event occurred." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 4: `ACTIVITY` bits 4:4

Locations: `truth registers[20].field_parts[0].bit_field[3]` ↔ `v11_0 registers[20].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACTIVITY" | "Activity" |
| "`field_description`" | "0.0586" | "1.000000" | "Activity event occurred." | "1 indicates an activity event occurred." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 5: `INACTIVITY` bits 3:3

Locations: `truth registers[20].field_parts[0].bit_field[4]` ↔ `v11_0 registers[20].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACTIVITY" | "Inactivity" |
| "`field_description`" | "0.0586" | "1.000000" | "Inactivity event occurred." | "1 indicates an inactivity event occurred." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 6: `FREE_FALL` bits 2:2

Locations: `truth registers[20].field_parts[0].bit_field[5]` ↔ `v11_0 registers[20].field_parts[0].bit_field[5]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "FREE_FALL" | "FREE_FALL" |
| "`field_description`" | "0.0586" | "1.000000" | "Free-fall event occurred." | "1 indicates a free-fall event occurred." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 7: `WATERMARK` bits 1:1

Locations: `truth registers[20].field_parts[0].bit_field[6]` ↔ `v11_0 registers[20].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "WATERMARK" | "Watermark" |
| "`field_description`" | "0.0586" | "1.000000" | "FIFO watermark event occurred." | "1 indicates FIFO samples reached the FIFO_CTL samples level." |
| "`bit_start`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 8: `OVERRUN` bits 0:0

Locations: `truth registers[20].field_parts[0].bit_field[7]` ↔ `v11_0 registers[20].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "OVERRUN" | "Overrun" |
| "`field_description`" | "0.0586" | "1.000000" | "FIFO overrun event occurred." | "1 indicates new data replaced unread data (mode dependent)." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Field-part aggregation

`bit_field` correctness = mean(0.731973, 0.731973, 0.731973, 0.710771, 0.710771, 0.731973, 0.710771, 0.710771) = **0.721372**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "INT_SOURCE" | "INT_SOURCE" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x30","decimal":"48","bank":"","page":"","description":"Source of interrupts"} | {"hex":"0x30","decimal":"48","bank":"","page":"","description":"Interrupt source register address"} |
| "`description`" | "0.0693" | "1.000000" | "Interrupt source status." | "Per-function interrupt triggered status." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.721372" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.721372)/1.0000=0.912817/1.0000=\mathbf{0.912817}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.912817) = **0.912817**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "INT_SOURCE" | "INT_SOURCE" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x30","decimal":"48","bank":"","page":"","description":"Source of interrupts"}] | [{"hex":"0x30","decimal":"48","bank":"","page":"","description":"Interrupt source register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Reports which interrupt functions have triggered; event bits are cleared by reading this register or data registers as specified." | "Read-only source of interrupts. A bit set to 1 indicates the corresponding function triggered an event. DATA_READY, Watermark, and Overrun are set regardless of INT_ENABLE and are cleared by reading the DATAX/DATAY/DATAZ registers (multiple reads may be required); other bits and interrupts are cleared by reading INT_SOURCE." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.912817" | "mean(0.912817)" | "mean(0.912817)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000010" | "00000010" |
| "`default_value_description`" | "0.0334" | "0.000000" | "Watermark status bit set in reset value per register map" | "" |

\(Q(L_{21})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.912817 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.940659/1.0001=\mathbf{0.940564}\)


## Extracted logical register 22: `DATA_FORMAT`

v11_0 location: `registers[21]`; truth association: `truth registers[21]` (`DATA_FORMAT`).
Associated physical locations: 0x31 (49).

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATA_FORMAT` at 0x31 (49)

Locations: `truth registers[21].field_parts[0]` ↔ `v11_0 registers[21].field_parts[0]`

Truth bit field 1: `SELF_TEST` bits 7:7

Locations: `truth registers[21].field_parts[0].bit_field[0]` ↔ `v11_0 registers[21].field_parts[0].bit_field[0]`.
Judgment: deductions: type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "SELF_TEST" | "SELF_TEST" |
| "`field_description`" | "0.0586" | "1.000000" | "Applies self-test force when set." | "1 applies a self-test force to the sensor causing a shift in output data; 0 disables." |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Self-test force disabled."},{"value":"1","value_description":"Self-test force enabled."}] | [{"value":"0","value_description":"Self-test force disabled."},{"value":"1","value_description":"Self-test force applied."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\)

Truth bit field 2: `SPI` bits 6:6

Locations: `truth registers[21].field_parts[0].bit_field[1]` ↔ `v11_0 registers[21].field_parts[0].bit_field[1]`.
Judgment: deductions: type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "SPI" | "SPI" |
| "`field_description`" | "0.0586" | "1.000000" | "SPI mode selection: 0 four-wire, 1 three-wire." | "1 sets 3-wire SPI mode; 0 sets 4-wire SPI mode." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Four-wire SPI mode."},{"value":"1","value_description":"Three-wire SPI mode."}] | [{"value":"0","value_description":"4-wire SPI mode."},{"value":"1","value_description":"3-wire SPI mode."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\)

Truth bit field 3: `INT_INVERT` bits 5:5

Locations: `truth registers[21].field_parts[0].bit_field[2]` ↔ `v11_0 registers[21].field_parts[0].bit_field[2]`.
Judgment: deductions: type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "INT_INVERT" | "INT_INVERT" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt polarity: 0 active high, 1 active low." | "0 sets interrupts active high; 1 sets interrupts active low." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Active-high interrupts."},{"value":"1","value_description":"Active-low interrupts."}] | [{"value":"0","value_description":"Interrupts active high."},{"value":"1","value_description":"Interrupts active low."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\)

Truth bit field 4: `FULL_RES` bits 3:3

Locations: `truth registers[21].field_parts[0].bit_field[3]` ↔ `v11_0 registers[21].field_parts[0].bit_field[4]`.
Judgment: deductions: type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "FULL_RES" | "FULL_RES" |
| "`field_description`" | "0.0586" | "1.000000" | "Full-resolution mode selection." | "1 selects full resolution mode (4 mg/LSB maintained across g range); 0 selects 10-bit mode." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"10-bit mode."},{"value":"1","value_description":"Full-resolution mode."}] | [{"value":"0","value_description":"10-bit mode; range bits determine max g range and scale factor."},{"value":"1","value_description":"Full resolution mode; output resolution increases with g range to maintain 4 mg/LSB."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\)

Truth bit field 5: `JUSTIFY` bits 2:2

Locations: `truth registers[21].field_parts[0].bit_field[4]` ↔ `v11_0 registers[21].field_parts[0].bit_field[5]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "JUSTIFY" | "Justify" |
| "`field_description`" | "0.0586" | "1.000000" | "Data justification: 0 right-justified with sign extension, 1 left-justified." | "1 selects left-justified (MSB) mode; 0 selects right-justified mode with sign extension." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Right-justified with sign extension."},{"value":"1","value_description":"Left-justified."}] | [{"value":"0","value_description":"Right-justified with sign extension."},{"value":"1","value_description":"Left-justified (MSB) mode."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 6: `RANGE` bits 0:1

Locations: `truth registers[21].field_parts[0].bit_field[5]` ↔ `v11_0 registers[21].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RANGE" | "Range" |
| "`field_description`" | "0.0586" | "1.000000" | "Measurement range selection." | "Sets the g range." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 2 | 2 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"00","value_description":"+/-2 g."},{"value":"01","value_description":"+/-4 g."},{"value":"10","value_description":"+/-8 g."},{"value":"11","value_description":"+/-16 g."}] | [{"value":"00","value_description":"+/-2 g"},{"value":"01","value_description":"+/-4 g"},{"value":"10","value_description":"+/-8 g"},{"value":"11","value_description":"+/-16 g"}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 7: `RESERVED` bits 4:4

Locations: `truth registers[21].field_parts[0].bit_field[6]` ↔ `v11_0 registers[21].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RESERVED" | "0" |
| "`field_description`" | "0.0586" | "1.000000" | "Reserved bit." | "Unused bit shown as 0." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | true | true |
| "`type_write_read`" | "0.0583" | "1.000000" | "" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

`bit_field` correctness = mean(0.941694, 0.941694, 0.941694, 0.941694, 0.920492, 0.920492, 0.978798) = **0.940937**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATA_FORMAT" | "DATA_FORMAT" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x31","decimal":"49","bank":"","page":"","description":"Data format control"} | {"hex":"0x31","decimal":"49","bank":"","page":"","description":"Data format control register address"} |
| "`description`" | "0.0693" | "1.000000" | "Data format control." | "Self-test, SPI mode, interrupt polarity, resolution, justification, and g-range control." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.940937" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.940937)/1.0000=0.981519/1.0000=\mathbf{0.981519}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.981519) = **0.981519**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATA_FORMAT" | "DATA_FORMAT" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x31","decimal":"49","bank":"","page":"","description":"Data format control"}] | [{"hex":"0x31","decimal":"49","bank":"","page":"","description":"Data format control register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Controls the presentation of output data." | "Controls presentation of data to Register 0x32-0x37. SELF_TEST applies a self-test force; SPI selects 3-wire (1) or 4-wire (0) SPI; INT_INVERT sets interrupts active low (1) or active high (0); FULL_RES enables full resolution mode (output resolution scales with g range to keep 4 mg/LSB) vs 10-bit mode; Justify selects left-justified (1) or right-justified with sign extension (0); Range bits set the g range. All data except +/-16 g range must be clipped to avoid rollover." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.981519" | "mean(0.981519)" | "mean(0.981519)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "10-bit, +/-2 g, right-justified, four-wire SPI, active-high interrupts" | "" |

\(Q(L_{22})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981519 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.961180/1.0001=\mathbf{0.961084}\)


## Extracted logical register 23: `DATAX0`

v11_0 location: `registers[22]`; truth association: `truth registers[22]` (`DATAX`).
Associated physical locations: 0x32 (50).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATAX0` at 0x32 (50)

Locations: `truth registers[22].field_parts[0]` ↔ `v11_0 registers[22].field_parts[0]`

Truth bit field 1: `DATAX0` bits 0:7

Locations: `truth registers[22].field_parts[0].bit_field[0]` ↔ `v11_0 registers[22].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "DATAX0" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Least significant byte of two's-complement X-axis output data." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATAX0" | "DATAX0" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x32","decimal":"50","bank":"","page":"","description":"X-Axis Data 0"} | {"hex":"0x32","decimal":"50","bank":"","page":"","description":"X-axis data least significant byte address"} |
| "`description`" | "0.0693" | "1.000000" | "Least significant byte of X-axis output data." | "Least significant byte of X-axis output data." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATAX0" | "DATAX0" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x32","decimal":"50","bank":"","page":"","description":"X-Axis Data 0"}] | [{"hex":"0x32","decimal":"50","bank":"","page":"","description":"X-axis data least significant byte address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "DATAX0 and DATAX1 hold the 16-bit two's-complement X-axis output data; DATAX0 is the least significant byte and DATAX1 is the most significant byte." | "X-axis output data, least significant byte of the twos complement 16-bit value (DATAX0 = LSB, DATAX1 = MSB). Format is controlled by DATA_FORMAT (0x31). A multiple-byte read of all data registers is recommended; when FIFO is in FIFO/stream/trigger mode, reads pop the oldest x/y/z sample from FIFO." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "0000000000000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{23})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 24: `DATAX1`

v11_0 location: `registers[23]`; truth association: `truth registers[22]` (`DATAX`).
Associated physical locations: 0x33 (51).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part.

### Bottom layer: bit fields, then field parts

#### Field part 2: `DATAX1` at 0x33 (51)

Locations: `truth registers[22].field_parts[1]` ↔ `v11_0 registers[23].field_parts[0]`

Truth bit field 1: `DATAX1` bits 0:7

Locations: `truth registers[22].field_parts[1].bit_field[0]` ↔ `v11_0 registers[23].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "DATAX1" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Most significant byte of two's-complement X-axis output data." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATAX1" | "DATAX1" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x33","decimal":"51","bank":"","page":"","description":"X-Axis Data 1"} | {"hex":"0x33","decimal":"51","bank":"","page":"","description":"X-axis data most significant byte address"} |
| "`description`" | "0.0693" | "1.000000" | "Most significant byte of X-axis output data." | "Most significant byte of X-axis output data." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATAX1" | "DATAX1" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x33","decimal":"51","bank":"","page":"","description":"X-Axis Data 1"}] | [{"hex":"0x33","decimal":"51","bank":"","page":"","description":"X-axis data most significant byte address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "DATAX0 and DATAX1 hold the 16-bit two's-complement X-axis output data; DATAX0 is the least significant byte and DATAX1 is the most significant byte." | "X-axis output data, most significant byte of the twos complement 16-bit value (DATAX0 = LSB, DATAX1 = MSB). Format is controlled by DATA_FORMAT (0x31). A multiple-byte read of all data registers is recommended." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "0000000000000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{24})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 25: `DATAY0`

v11_0 location: `registers[24]`; truth association: `truth registers[23]` (`DATAY`).
Associated physical locations: 0x34 (52).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATAY0` at 0x34 (52)

Locations: `truth registers[23].field_parts[0]` ↔ `v11_0 registers[24].field_parts[0]`

Truth bit field 1: `DATAY0` bits 0:7

Locations: `truth registers[23].field_parts[0].bit_field[0]` ↔ `v11_0 registers[24].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "DATAY0" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Least significant byte of two's-complement Y-axis output data." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATAY0" | "DATAY0" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x34","decimal":"52","bank":"","page":"","description":"Y-Axis Data 0"} | {"hex":"0x34","decimal":"52","bank":"","page":"","description":"Y-axis data least significant byte address"} |
| "`description`" | "0.0693" | "1.000000" | "Least significant byte of Y-axis output data." | "Least significant byte of Y-axis output data." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATAY0" | "DATAY0" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x34","decimal":"52","bank":"","page":"","description":"Y-Axis Data 0"}] | [{"hex":"0x34","decimal":"52","bank":"","page":"","description":"Y-axis data least significant byte address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement Y-axis output data; DATAY0 is least significant and DATAY1 most significant." | "Y-axis output data, least significant byte of the twos complement 16-bit value (DATAY0 = LSB, DATAY1 = MSB). Format is controlled by DATA_FORMAT (0x31). A multiple-byte read of all data registers is recommended." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "0000000000000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{25})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 26: `DATAY1`

v11_0 location: `registers[25]`; truth association: `truth registers[23]` (`DATAY`).
Associated physical locations: 0x35 (53).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part.

### Bottom layer: bit fields, then field parts

#### Field part 2: `DATAY1` at 0x35 (53)

Locations: `truth registers[23].field_parts[1]` ↔ `v11_0 registers[25].field_parts[0]`

Truth bit field 1: `DATAY1` bits 0:7

Locations: `truth registers[23].field_parts[1].bit_field[0]` ↔ `v11_0 registers[25].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "DATAY1" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Most significant byte of two's-complement Y-axis output data." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATAY1" | "DATAY1" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x35","decimal":"53","bank":"","page":"","description":"Y-Axis Data 1"} | {"hex":"0x35","decimal":"53","bank":"","page":"","description":"Y-axis data most significant byte address"} |
| "`description`" | "0.0693" | "1.000000" | "Most significant byte of Y-axis output data." | "Most significant byte of Y-axis output data." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATAY1" | "DATAY1" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x35","decimal":"53","bank":"","page":"","description":"Y-Axis Data 1"}] | [{"hex":"0x35","decimal":"53","bank":"","page":"","description":"Y-axis data most significant byte address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement Y-axis output data; DATAY0 is least significant and DATAY1 most significant." | "Y-axis output data, most significant byte of the twos complement 16-bit value (DATAY0 = LSB, DATAY1 = MSB). Format is controlled by DATA_FORMAT (0x31). A multiple-byte read of all data registers is recommended." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "0000000000000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{26})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 27: `DATAZ0`

v11_0 location: `registers[26]`; truth association: `truth registers[24]` (`DATAZ`).
Associated physical locations: 0x36 (54).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATAZ0` at 0x36 (54)

Locations: `truth registers[24].field_parts[0]` ↔ `v11_0 registers[26].field_parts[0]`

Truth bit field 1: `DATAZ0` bits 0:7

Locations: `truth registers[24].field_parts[0].bit_field[0]` ↔ `v11_0 registers[26].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "DATAZ0" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Least significant byte of two's-complement Z-axis output data." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATAZ0" | "DATAZ0" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x36","decimal":"54","bank":"","page":"","description":"Z-Axis Data 0"} | {"hex":"0x36","decimal":"54","bank":"","page":"","description":"Z-axis data least significant byte address"} |
| "`description`" | "0.0693" | "1.000000" | "Least significant byte of Z-axis output data." | "Least significant byte of Z-axis output data." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATAZ0" | "DATAZ0" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":"Z-Axis Data 0"}] | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":"Z-axis data least significant byte address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement Z-axis output data; DATAZ0 is least significant and DATAZ1 most significant." | "Z-axis output data, least significant byte of the twos complement 16-bit value (DATAZ0 = LSB, DATAZ1 = MSB). Format is controlled by DATA_FORMAT (0x31). A multiple-byte read of all data registers is recommended." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "0000000000000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{27})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 28: `DATAZ1`

v11_0 location: `registers[27]`; truth association: `truth registers[24]` (`DATAZ`).
Associated physical locations: 0x37 (55).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part.

### Bottom layer: bit fields, then field parts

#### Field part 2: `DATAZ1` at 0x37 (55)

Locations: `truth registers[24].field_parts[1]` ↔ `v11_0 registers[27].field_parts[0]`

Truth bit field 1: `DATAZ1` bits 0:7

Locations: `truth registers[24].field_parts[1].bit_field[0]` ↔ `v11_0 registers[27].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "DATAZ1" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Most significant byte of two's-complement Z-axis output data." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATAZ1" | "DATAZ1" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x37","decimal":"55","bank":"","page":"","description":"Z-Axis Data 1"} | {"hex":"0x37","decimal":"55","bank":"","page":"","description":"Z-axis data most significant byte address"} |
| "`description`" | "0.0693" | "1.000000" | "Most significant byte of Z-axis output data." | "Most significant byte of Z-axis output data." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATAZ1" | "DATAZ1" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":"Z-Axis Data 1"}] | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":"Z-axis data most significant byte address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement Z-axis output data; DATAZ0 is least significant and DATAZ1 most significant." | "Z-axis output data, most significant byte of the twos complement 16-bit value (DATAZ0 = LSB, DATAZ1 = MSB). Format is controlled by DATA_FORMAT (0x31). A multiple-byte read of all data registers is recommended." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "0000000000000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{28})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 29: `FIFO_CTL`

v11_0 location: `registers[28]`; truth association: `truth registers[25]` (`FIFO_CTL`).
Associated physical locations: 0x38 (56).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_CTL` at 0x38 (56)

Locations: `truth registers[25].field_parts[0]` ↔ `v11_0 registers[28].field_parts[0]`

Truth bit field 1: `FIFO_MODE` bits 6:7

Locations: `truth registers[25].field_parts[0].bit_field[0]` ↔ `v11_0 registers[28].field_parts[0].bit_field[0]`.
Judgment: deductions: type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "FIFO_MODE" | "FIFO_MODE" |
| "`field_description`" | "0.0586" | "1.000000" | "FIFO operating mode." | "Selects the FIFO mode." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 2 | 2 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"00","value_description":"Bypass."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Trigger mode."}] | [{"value":"00","value_description":"Bypass: FIFO is bypassed."},{"value":"01","value_description":"FIFO: collects up to 32 values then stops, collecting new data only when FIFO is not full."},{"value":"10","value_description":"Stream: holds the last 32 data values; oldest overwritten when full."},{"value":"11","value_description":"Trigger: holds last samples before trigger event, then collects until full."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\)

Truth bit field 2: `TRIGGER` bits 5:5

Locations: `truth registers[25].field_parts[0].bit_field[1]` ↔ `v11_0 registers[28].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TRIGGER" | "Trigger" |
| "`field_description`" | "0.0586" | "1.000000" | "Trigger interrupt pin selection: 0 INT1, 1 INT2." | "0 links the trigger event of trigger mode to INT1; 1 links it to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"Trigger event linked to INT1."},{"value":"1","value_description":"Trigger event linked to INT2."}] | [{"value":"0","value_description":"Trigger event linked to INT1."},{"value":"1","value_description":"Trigger event linked to INT2."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 3: `SAMPLES` bits 0:4

Locations: `truth registers[25].field_parts[0].bit_field[2]` ↔ `v11_0 registers[28].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "SAMPLES" | "Samples" |
| "`field_description`" | "0.0586" | "1.000000" | "Number of FIFO entries for watermark or pre-trigger samples; zero immediately sets watermark." | "Function depends on FIFO mode: watermark entry level in FIFO/stream modes; number of samples retained before a trigger event in trigger mode; none in bypass. A value of 0 immediately sets the watermark status bit." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 5 | 5 |
| "`values`" | "0.2097" | "1.000000" | [] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Field-part aggregation

`bit_field` correctness = mean(0.941694, 0.920492, 0.920492) = **0.927559**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "FIFO_CTL" | "FIFO_CTL" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x38","decimal":"56","bank":"","page":"","description":"FIFO control"} | {"hex":"0x38","decimal":"56","bank":"","page":"","description":"FIFO control register address"} |
| "`description`" | "0.0693" | "1.000000" | "FIFO control." | "FIFO mode, trigger pin, and samples configuration." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.927559" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.927559)/1.0000=0.977333/1.0000=\mathbf{0.977333}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.977333) = **0.977333**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "FIFO_CTL" | "FIFO_CTL" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x38","decimal":"56","bank":"","page":"","description":"FIFO control"}] | [{"hex":"0x38","decimal":"56","bank":"","page":"","description":"FIFO control register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Controls FIFO mode, trigger interrupt pin and watermark sample count." | "FIFO control. FIFO_MODE bits select bypass, FIFO, stream, or trigger mode. Trigger bit links the trigger event to INT1 (0) or INT2 (1). Samples bits function depends on the FIFO mode (watermark level in FIFO/stream modes; samples retained before trigger in trigger mode); entering 0 immediately sets the watermark status bit in INT_SOURCE." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.977333" | "mean(0.977333)" | "mean(0.977333)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "Bypass mode, trigger INT1, zero samples; zero samples immediately sets WATERMARK and may cause undesirable trigger-mode operation." | "" |

\(Q(L_{29})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.977333 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.959929/1.0001=\mathbf{0.959833}\)


## Extracted logical register 30: `FIFO_STATUS`

v11_0 location: `registers[29]`; truth association: `truth registers[26]` (`FIFO_STATUS`).
Associated physical locations: 0x39 (57).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_STATUS` at 0x39 (57)

Locations: `truth registers[26].field_parts[0]` ↔ `v11_0 registers[29].field_parts[0]`

Truth bit field 1: `FIFO_TRIG` bits 7:7

Locations: `truth registers[26].field_parts[0].bit_field[0]` ↔ `v11_0 registers[29].field_parts[0].bit_field[0]`.
Judgment: deductions: type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "FIFO_TRIG" | "FIFO_TRIG" |
| "`field_description`" | "0.0586" | "1.000000" | "Indicates that a FIFO trigger event occurred." | "1 corresponds to a trigger event occurring; 0 means no FIFO trigger event has occurred." |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"0","value_description":"No FIFO trigger event."},{"value":"1","value_description":"FIFO trigger event occurred."}] | [{"value":"0","value_description":"No FIFO trigger event has occurred."},{"value":"1","value_description":"A trigger event has occurred."}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\)

Truth bit field 2: `ENTRIES` bits 0:5

Locations: `truth registers[26].field_parts[0].bit_field[1]` ↔ `v11_0 registers[29].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ENTRIES" | "Entries" |
| "`field_description`" | "0.0586" | "1.000000" | "Number of data values stored in FIFO." | "Reports how many data values are stored in FIFO (maximum 32 entries)." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 6 | 6 |
| "`values`" | "0.2097" | "1.000000" | [] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 3: `RESERVED` bits 6:6

Locations: `truth registers[26].field_parts[0].bit_field[2]` ↔ `v11_0 registers[29].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RESERVED" | "0" |
| "`field_description`" | "0.0586" | "1.000000" | "Reserved bits." | "Unused bit shown as 0." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | true | true |
| "`type_write_read`" | "0.0583" | "1.000000" | "" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

`bit_field` correctness = mean(0.941694, 0.920492, 0.978798) = **0.946995**.
| Field-part field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "FIFO_STATUS" | "FIFO_STATUS" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x39","decimal":"57","bank":"","page":"","description":"FIFO status"} | {"hex":"0x39","decimal":"57","bank":"","page":"","description":"FIFO status register address"} |
| "`description`" | "0.0693" | "1.000000" | "FIFO status." | "FIFO trigger flag and stored-entry count." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.946995" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.946995)/1.0000=0.983415/1.0000=\mathbf{0.983415}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.983415) = **0.983415**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v11_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "FIFO_STATUS" | "FIFO_STATUS" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x39","decimal":"57","bank":"","page":"","description":"FIFO status"}] | [{"hex":"0x39","decimal":"57","bank":"","page":"","description":"FIFO status register address"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Reports FIFO trigger status and the number of stored data values." | "Read-only FIFO status. FIFO_TRIG indicates a trigger event occurred. Entries bits report how many data values are stored in FIFO (max 32 entries; up to 33 available including the output filter entry). Data is accessed via DATAX/DATAY/DATAZ; each FIFO level is cleared after any read, so burst/multiple-byte reads are required." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.983415" | "mean(0.983415)" | "mean(0.983415)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "No trigger; zero entries" | "" |

\(Q(L_{30})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.983415 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.961746/1.0001=\mathbf{0.961650}\)


## 3. Detailed deduction inventory

Every scored deduction and recursive aggregate deduction retains exact truth and extracted JSON locations.

| # | Exact truth ↔ extracted location | Scored field | C | Truth content | v11_0 content | Specific error or omission |
|---:|---|---|---:|---|---|---|
| 1 | "truth registers[1].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "THRESH_TAP" | MISSING | "field is missing" |
| 2 | "truth registers[1].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned tap threshold, 62.5 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 3 | "truth registers[1].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 4 | "truth registers[1].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 5 | "truth registers[1].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 6 | "truth registers[1].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 7 | "truth registers[1].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 8 | "truth registers[1].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 9 | "truth registers[1].field_parts[0] ↔ v11_0 registers[1].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 10 | "truth registers[1] ↔ v11_0 registers[1]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 11 | "truth registers[1].default_value_description ↔ v11_0 registers[1].default_value_description" | `default_value_description` | 0.000000 | "0 may result in undesirable behavior if tap interrupts are enabled." | "" | "description missing or not sufficiently supported" |
| 12 | "truth registers[2].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "OFSX" | MISSING | "field is missing" |
| 13 | "truth registers[2].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Two's-complement X-axis offset, 15.6 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 14 | "truth registers[2].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 15 | "truth registers[2].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 16 | "truth registers[2].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 17 | "truth registers[2].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 18 | "truth registers[2].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 19 | "truth registers[2].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 20 | "truth registers[2].field_parts[0] ↔ v11_0 registers[2].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 21 | "truth registers[2] ↔ v11_0 registers[2]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 22 | "truth registers[3].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "OFSY" | MISSING | "field is missing" |
| 23 | "truth registers[3].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Two's-complement Y-axis offset, 15.6 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 24 | "truth registers[3].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 25 | "truth registers[3].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 26 | "truth registers[3].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 27 | "truth registers[3].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 28 | "truth registers[3].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 29 | "truth registers[3].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 30 | "truth registers[3].field_parts[0] ↔ v11_0 registers[3].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 31 | "truth registers[3] ↔ v11_0 registers[3]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 32 | "truth registers[4].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "OFSZ" | MISSING | "field is missing" |
| 33 | "truth registers[4].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Two's-complement Z-axis offset, 15.6 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 34 | "truth registers[4].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 35 | "truth registers[4].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 36 | "truth registers[4].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 37 | "truth registers[4].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 38 | "truth registers[4].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 39 | "truth registers[4].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 40 | "truth registers[4].field_parts[0] ↔ v11_0 registers[4].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 41 | "truth registers[4] ↔ v11_0 registers[4]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 42 | "truth registers[5].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "DUR" | MISSING | "field is missing" |
| 43 | "truth registers[5].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned tap duration, 625 us/LSB." | MISSING | "description missing or not sufficiently supported" |
| 44 | "truth registers[5].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 45 | "truth registers[5].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 46 | "truth registers[5].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 47 | "truth registers[5].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 48 | "truth registers[5].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 49 | "truth registers[5].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 50 | "truth registers[5].field_parts[0] ↔ v11_0 registers[5].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 51 | "truth registers[5] ↔ v11_0 registers[5]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 52 | "truth registers[5].default_value_description ↔ v11_0 registers[5].default_value_description" | `default_value_description` | 0.000000 | "0 disables the single-tap and double-tap functions." | "" | "description missing or not sufficiently supported" |
| 53 | "truth registers[6].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "Latent" | MISSING | "field is missing" |
| 54 | "truth registers[6].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned tap latency, 1.25 ms/LSB." | MISSING | "description missing or not sufficiently supported" |
| 55 | "truth registers[6].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 56 | "truth registers[6].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 57 | "truth registers[6].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 58 | "truth registers[6].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 59 | "truth registers[6].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 60 | "truth registers[6].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 61 | "truth registers[6].field_parts[0] ↔ v11_0 registers[6].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 62 | "truth registers[6] ↔ v11_0 registers[6]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 63 | "truth registers[6].default_value_description ↔ v11_0 registers[6].default_value_description" | `default_value_description` | 0.000000 | "0 disables the double-tap function." | "" | "description missing or not sufficiently supported" |
| 64 | "truth registers[7].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "Window" | MISSING | "field is missing" |
| 65 | "truth registers[7].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned tap window, 1.25 ms/LSB." | MISSING | "description missing or not sufficiently supported" |
| 66 | "truth registers[7].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 67 | "truth registers[7].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 68 | "truth registers[7].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 69 | "truth registers[7].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 70 | "truth registers[7].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 71 | "truth registers[7].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 72 | "truth registers[7].field_parts[0] ↔ v11_0 registers[7].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 73 | "truth registers[7] ↔ v11_0 registers[7]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 74 | "truth registers[7].default_value_description ↔ v11_0 registers[7].default_value_description" | `default_value_description` | 0.000000 | "0 disables the double-tap function." | "" | "description missing or not sufficiently supported" |
| 75 | "truth registers[8].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "THRESH_ACT" | MISSING | "field is missing" |
| 76 | "truth registers[8].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned activity threshold, 62.5 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 77 | "truth registers[8].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 78 | "truth registers[8].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 79 | "truth registers[8].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 80 | "truth registers[8].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 81 | "truth registers[8].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 82 | "truth registers[8].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 83 | "truth registers[8].field_parts[0] ↔ v11_0 registers[8].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 84 | "truth registers[8] ↔ v11_0 registers[8]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 85 | "truth registers[8].default_value_description ↔ v11_0 registers[8].default_value_description" | `default_value_description` | 0.000000 | "0 may result in undesirable behavior if the activity interrupt is enabled." | "" | "description missing or not sufficiently supported" |
| 86 | "truth registers[9].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "THRESH_INACT" | MISSING | "field is missing" |
| 87 | "truth registers[9].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned inactivity threshold, 62.5 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 88 | "truth registers[9].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 89 | "truth registers[9].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 90 | "truth registers[9].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 91 | "truth registers[9].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 92 | "truth registers[9].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 93 | "truth registers[9].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 94 | "truth registers[9].field_parts[0] ↔ v11_0 registers[9].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 95 | "truth registers[9] ↔ v11_0 registers[9]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 96 | "truth registers[9].default_value_description ↔ v11_0 registers[9].default_value_description" | `default_value_description` | 0.000000 | "0 may result in undesirable behavior if the inactivity interrupt is enabled." | "" | "description missing or not sufficiently supported" |
| 97 | "truth registers[10].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "TIME_INACT" | MISSING | "field is missing" |
| 98 | "truth registers[10].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned inactivity time, 1 s/LSB." | MISSING | "description missing or not sufficiently supported" |
| 99 | "truth registers[10].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 100 | "truth registers[10].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 101 | "truth registers[10].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 102 | "truth registers[10].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 103 | "truth registers[10].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 104 | "truth registers[10].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 105 | "truth registers[10].field_parts[0] ↔ v11_0 registers[10].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 106 | "truth registers[10] ↔ v11_0 registers[10]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 107 | "truth registers[10].default_value_description ↔ v11_0 registers[10].default_value_description" | `default_value_description` | 0.000000 | "0 results in an interrupt when acceleration is below THRESH_INACT." | "" | "description missing or not sufficiently supported" |
| 108 | "truth registers[11].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "ACT_ACDC" | "ACT ac/dc" | "strict fact mismatch; truth=\"ACT_ACDC\" candidate=\"ACT ac/dc\"" |
| 109 | "truth registers[11].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 110 | "truth registers[11].field_parts[0].bit_field[1]" | `name_or_parameter` | 0.000000 | "ACT_X_ENABLE" | "ACT_X enable" | "strict fact mismatch; truth=\"ACT_X_ENABLE\" candidate=\"ACT_X enable\"" |
| 111 | "truth registers[11].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 112 | "truth registers[11].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 113 | "truth registers[11].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "ACT_Y_ENABLE" | "ACT_Y enable" | "strict fact mismatch; truth=\"ACT_Y_ENABLE\" candidate=\"ACT_Y enable\"" |
| 114 | "truth registers[11].field_parts[0].bit_field[2]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 115 | "truth registers[11].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 116 | "truth registers[11].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "ACT_Z_ENABLE" | "ACT_Z enable" | "strict fact mismatch; truth=\"ACT_Z_ENABLE\" candidate=\"ACT_Z enable\"" |
| 117 | "truth registers[11].field_parts[0].bit_field[3]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 118 | "truth registers[11].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 119 | "truth registers[11].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "INACT_ACDC" | "INACT ac/dc" | "strict fact mismatch; truth=\"INACT_ACDC\" candidate=\"INACT ac/dc\"" |
| 120 | "truth registers[11].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 121 | "truth registers[11].field_parts[0].bit_field[5]" | `name_or_parameter` | 0.000000 | "INACT_X_ENABLE" | "INACT_X enable" | "strict fact mismatch; truth=\"INACT_X_ENABLE\" candidate=\"INACT_X enable\"" |
| 122 | "truth registers[11].field_parts[0].bit_field[5]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 123 | "truth registers[11].field_parts[0].bit_field[5]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 124 | "truth registers[11].field_parts[0].bit_field[6]" | `name_or_parameter` | 0.000000 | "INACT_Y_ENABLE" | "INACT_Y enable" | "strict fact mismatch; truth=\"INACT_Y_ENABLE\" candidate=\"INACT_Y enable\"" |
| 125 | "truth registers[11].field_parts[0].bit_field[6]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 126 | "truth registers[11].field_parts[0].bit_field[6]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 127 | "truth registers[11].field_parts[0].bit_field[7]" | `name_or_parameter` | 0.000000 | "INACT_Z_ENABLE" | "INACT_Z enable" | "strict fact mismatch; truth=\"INACT_Z_ENABLE\" candidate=\"INACT_Z enable\"" |
| 128 | "truth registers[11].field_parts[0].bit_field[7]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 129 | "truth registers[11].field_parts[0].bit_field[7]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 130 | "truth registers[11].field_parts[0] ↔ v11_0 registers[11].field_parts[0]" | `bit_field` | 0.763201 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 131 | "truth registers[11] ↔ v11_0 registers[11]" | `field_parts` | 0.925906 | "mean(0.925906)" | "mean(0.925906)" | "recursive mean of field-part scores" |
| 132 | "truth registers[11].default_value_description ↔ v11_0 registers[11].default_value_description" | `default_value_description` | 0.000000 | "DC-coupled; all axes disabled" | "" | "description missing or not sufficiently supported" |
| 133 | "truth registers[12].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "THRESH_FF" | MISSING | "field is missing" |
| 134 | "truth registers[12].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned free-fall threshold, 62.5 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 135 | "truth registers[12].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 136 | "truth registers[12].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 137 | "truth registers[12].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 138 | "truth registers[12].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 139 | "truth registers[12].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 140 | "truth registers[12].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 141 | "truth registers[12].field_parts[0] ↔ v11_0 registers[12].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 142 | "truth registers[12] ↔ v11_0 registers[12]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 143 | "truth registers[12].default_value_description ↔ v11_0 registers[12].default_value_description" | `default_value_description` | 0.000000 | "0 mg may result in undesirable behavior if the free-fall interrupt is enabled." | "" | "description missing or not sufficiently supported" |
| 144 | "truth registers[13].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "TIME_FF" | MISSING | "field is missing" |
| 145 | "truth registers[13].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned free-fall time, 5 ms/LSB." | MISSING | "description missing or not sufficiently supported" |
| 146 | "truth registers[13].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 147 | "truth registers[13].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 148 | "truth registers[13].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 149 | "truth registers[13].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 150 | "truth registers[13].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 151 | "truth registers[13].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 152 | "truth registers[13].field_parts[0] ↔ v11_0 registers[13].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 153 | "truth registers[13] ↔ v11_0 registers[13]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 154 | "truth registers[13].default_value_description ↔ v11_0 registers[13].default_value_description" | `default_value_description` | 0.000000 | "0 may result in undesirable behavior if the free-fall interrupt is enabled." | "" | "description missing or not sufficiently supported" |
| 155 | "truth registers[14].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "SUPPRESS" | "Suppress" | "strict fact mismatch; truth=\"SUPPRESS\" candidate=\"Suppress\"" |
| 156 | "truth registers[14].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"Do not suppress."},{"value":"1","value_description":"Suppress double-tap detection."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 157 | "truth registers[14].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 158 | "truth registers[14].field_parts[0].bit_field[1]" | `name_or_parameter` | 0.000000 | "TAP_X_ENABLE" | "TAP_X enable" | "strict fact mismatch; truth=\"TAP_X_ENABLE\" candidate=\"TAP_X enable\"" |
| 159 | "truth registers[14].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude X axis from tap detection."},{"value":"1","value_description":"Enable X-axis participation in tap detection."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 160 | "truth registers[14].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 161 | "truth registers[14].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "TAP_Y_ENABLE" | "TAP_Y enable" | "strict fact mismatch; truth=\"TAP_Y_ENABLE\" candidate=\"TAP_Y enable\"" |
| 162 | "truth registers[14].field_parts[0].bit_field[2]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Y axis from tap detection."},{"value":"1","value_description":"Enable Y-axis participation in tap detection."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 163 | "truth registers[14].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 164 | "truth registers[14].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "TAP_Z_ENABLE" | "TAP_Z enable" | "strict fact mismatch; truth=\"TAP_Z_ENABLE\" candidate=\"TAP_Z enable\"" |
| 165 | "truth registers[14].field_parts[0].bit_field[3]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Z axis from tap detection."},{"value":"1","value_description":"Enable Z-axis participation in tap detection."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 166 | "truth registers[14].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 167 | "truth registers[14].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "RESERVED" | "0" | "strict fact mismatch; truth=\"RESERVED\" candidate=\"0\"" |
| 168 | "truth registers[14].field_parts[0] ↔ v11_0 registers[14].field_parts[0]" | `bit_field` | 0.764376 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 169 | "truth registers[14] ↔ v11_0 registers[14]" | `field_parts` | 0.926273 | "mean(0.926273)" | "mean(0.926273)" | "recursive mean of field-part scores" |
| 170 | "truth registers[14].default_value_description ↔ v11_0 registers[14].default_value_description" | `default_value_description` | 0.000000 | "All tap axes disabled; suppress disabled" | "" | "description missing or not sufficiently supported" |
| 171 | "truth registers[15].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "ACT_X_SOURCE" | "ACT_X source" | "strict fact mismatch; truth=\"ACT_X_SOURCE\" candidate=\"ACT_X source\"" |
| 172 | "truth registers[15].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"X axis not involved in activity."},{"value":"1","value_description":"X axis involved in activity."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 173 | "truth registers[15].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 174 | "truth registers[15].field_parts[0].bit_field[1]" | `name_or_parameter` | 0.000000 | "ACT_Y_SOURCE" | "ACT_Y source" | "strict fact mismatch; truth=\"ACT_Y_SOURCE\" candidate=\"ACT_Y source\"" |
| 175 | "truth registers[15].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Y axis not involved in activity."},{"value":"1","value_description":"Y axis involved in activity."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 176 | "truth registers[15].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 177 | "truth registers[15].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "ACT_Z_SOURCE" | "ACT_Z source" | "strict fact mismatch; truth=\"ACT_Z_SOURCE\" candidate=\"ACT_Z source\"" |
| 178 | "truth registers[15].field_parts[0].bit_field[2]" | `values` | 0.000000 | [{"value":"0","value_description":"Z axis not involved in activity."},{"value":"1","value_description":"Z axis involved in activity."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 179 | "truth registers[15].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 180 | "truth registers[15].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "ASLEEP" | "Asleep" | "strict fact mismatch; truth=\"ASLEEP\" candidate=\"Asleep\"" |
| 181 | "truth registers[15].field_parts[0].bit_field[3]" | `values` | 0.000000 | [{"value":"0","value_description":"Not asleep."},{"value":"1","value_description":"Asleep."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 182 | "truth registers[15].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 183 | "truth registers[15].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "TAP_X_SOURCE" | "TAP_X source" | "strict fact mismatch; truth=\"TAP_X_SOURCE\" candidate=\"TAP_X source\"" |
| 184 | "truth registers[15].field_parts[0].bit_field[4]" | `values` | 0.000000 | [{"value":"0","value_description":"X axis not involved in tap."},{"value":"1","value_description":"X axis involved in tap."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 185 | "truth registers[15].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 186 | "truth registers[15].field_parts[0].bit_field[5]" | `name_or_parameter` | 0.000000 | "TAP_Y_SOURCE" | "TAP_Y source" | "strict fact mismatch; truth=\"TAP_Y_SOURCE\" candidate=\"TAP_Y source\"" |
| 187 | "truth registers[15].field_parts[0].bit_field[5]" | `values` | 0.000000 | [{"value":"0","value_description":"Y axis not involved in tap."},{"value":"1","value_description":"Y axis involved in tap."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 188 | "truth registers[15].field_parts[0].bit_field[5]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 189 | "truth registers[15].field_parts[0].bit_field[6]" | `name_or_parameter` | 0.000000 | "TAP_Z_SOURCE" | "TAP_Z source" | "strict fact mismatch; truth=\"TAP_Z_SOURCE\" candidate=\"TAP_Z source\"" |
| 190 | "truth registers[15].field_parts[0].bit_field[6]" | `values` | 0.000000 | [{"value":"0","value_description":"Z axis not involved in tap."},{"value":"1","value_description":"Z axis involved in tap."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 191 | "truth registers[15].field_parts[0].bit_field[6]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 192 | "truth registers[15].field_parts[0].bit_field[7]" | `name_or_parameter` | 0.000000 | "RESERVED" | "0" | "strict fact mismatch; truth=\"RESERVED\" candidate=\"0\"" |
| 193 | "truth registers[15].field_parts[0] ↔ v11_0 registers[15].field_parts[0]" | `bit_field` | 0.744274 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 194 | "truth registers[15] ↔ v11_0 registers[15]" | `field_parts` | 0.919983 | "mean(0.919983)" | "mean(0.919983)" | "recursive mean of field-part scores" |
| 195 | "truth registers[15].default_value_description ↔ v11_0 registers[15].default_value_description" | `default_value_description` | 0.000000 | "No event source; not asleep" | "" | "description missing or not sufficiently supported" |
| 196 | "truth registers[16].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 197 | "truth registers[16].field_parts[0].bit_field[1]" | `name_or_parameter` | 0.000000 | "RATE" | "Rate" | "strict fact mismatch; truth=\"RATE\" candidate=\"Rate\"" |
| 198 | "truth registers[16].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0000 (0x00)","value_description":"0.10 Hz output data rate; 0.05 Hz bandwidth."},{"value":"0001 (0x01)","value_description":"0.20 Hz output data rate; 0.10 Hz bandwidth."},{"value":"0010 (0x02)","value_description":"0.39 Hz output data rate; 0.20 Hz bandwidth."},{"value":"0011 (0x03)","value_description":"0.78 Hz output data rate; 0.39 Hz bandwidth."},{"value":"0100 (0x04)","value_description":"1.56 Hz output data rate; 0.78 Hz bandwidth."},{"value":"0101 (0x05)","value_description":"3.13 Hz output data rate; 1.56 Hz bandwidth."},{"value":"0110 (0x06)","value_description":"6.25 Hz output data rate; 3.13 Hz bandwidth."},{"value":"0111 (0x07)","value_description":"12.5 Hz output data rate; 6.25 Hz bandwidth; low-power mode table entry."},{"value":"1000 (0x08)","value_description":"25 Hz output data rate; 12.5 Hz bandwidth; low-power mode table entry."},{"value":"1001 (0x09)","value_description":"50 Hz output data rate; 25 Hz bandwidth; low-power mode table entry."},{"value":"1010 (0x0A)","value_description":"100 Hz output data rate; 50 Hz bandwidth; default; low-power mode table entry."},{"value":"1011 (0x0B)","value_description":"200 Hz output data rate; 100 Hz bandwidth; low-power mode table entry."},{"value":"1100 (0x0C)","value_description":"400 Hz output data rate; 200 Hz bandwidth; low-power mode table entry."},{"value":"1101 (0x0D)","value_description":"800 Hz output data rate; 400 Hz bandwidth."},{"value":"1110 (0x0E)","value_description":"1600 Hz output data rate; 800 Hz bandwidth."},{"value":"1111 (0x0F)","value_description":"3200 Hz output data rate; 1600 Hz bandwidth."}] | [{"value":"0x0A","value_description":"Default; 100 Hz output data rate."}] | "strict value-code set mismatch; missing codes=[0, 1, 11, 12, 13, 14, 15, 2, 3, 4, 5, 6, 7, 8, 9], extra codes=[]" |
| 199 | "truth registers[16].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 200 | "truth registers[16].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "RESERVED" | "0" | "strict fact mismatch; truth=\"RESERVED\" candidate=\"0\"" |
| 201 | "truth registers[16].field_parts[0] ↔ v11_0 registers[16].field_parts[0]" | `bit_field` | 0.877088 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 202 | "truth registers[16] ↔ v11_0 registers[16]" | `field_parts` | 0.961541 | "mean(0.961541)" | "mean(0.961541)" | "recursive mean of field-part scores" |
| 203 | "truth registers[16].default_value_description ↔ v11_0 registers[16].default_value_description" | `default_value_description` | 0.500000 | "100 Hz, normal power" | "Rate default 0x0A = 100 Hz output data rate." | "description is relevant but incomplete" |
| 204 | "truth registers[17].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "LINK" | "Link" | "strict fact mismatch; truth=\"LINK\" candidate=\"Link\"" |
| 205 | "truth registers[17].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"Activity and inactivity functions operate concurrently."},{"value":"1","value_description":"Activity and inactivity functions are serially linked."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 206 | "truth registers[17].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 207 | "truth registers[17].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Automatic sleep disabled."},{"value":"1","value_description":"Automatic sleep enabled when linked inactivity is detected."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 208 | "truth registers[17].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 209 | "truth registers[17].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "MEASURE" | "Measure" | "strict fact mismatch; truth=\"MEASURE\" candidate=\"Measure\"" |
| 210 | "truth registers[17].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 211 | "truth registers[17].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "SLEEP" | "Sleep" | "strict fact mismatch; truth=\"SLEEP\" candidate=\"Sleep\"" |
| 212 | "truth registers[17].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 213 | "truth registers[17].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "WAKEUP" | "Wakeup" | "strict fact mismatch; truth=\"WAKEUP\" candidate=\"Wakeup\"" |
| 214 | "truth registers[17].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 215 | "truth registers[17].field_parts[0].bit_field[5]" | `name_or_parameter` | 0.000000 | "RESERVED" | "0" | "strict fact mismatch; truth=\"RESERVED\" candidate=\"0\"" |
| 216 | "truth registers[17].field_parts[0] ↔ v11_0 registers[17].field_parts[0]" | `bit_field` | 0.863836 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 217 | "truth registers[17] ↔ v11_0 registers[17]" | `field_parts` | 0.957394 | "mean(0.957394)" | "mean(0.957394)" | "recursive mean of field-part scores" |
| 218 | "truth registers[17].default_value_description ↔ v11_0 registers[17].default_value_description" | `default_value_description` | 0.000000 | "Standby, normal mode" | "" | "description missing or not sufficiently supported" |
| 219 | "truth registers[18].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 220 | "truth registers[18].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 221 | "truth registers[18].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 222 | "truth registers[18].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 223 | "truth registers[18].field_parts[0].bit_field[2]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 224 | "truth registers[18].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 225 | "truth registers[18].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "ACTIVITY" | "Activity" | "strict fact mismatch; truth=\"ACTIVITY\" candidate=\"Activity\"" |
| 226 | "truth registers[18].field_parts[0].bit_field[3]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 227 | "truth registers[18].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 228 | "truth registers[18].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "INACTIVITY" | "Inactivity" | "strict fact mismatch; truth=\"INACTIVITY\" candidate=\"Inactivity\"" |
| 229 | "truth registers[18].field_parts[0].bit_field[4]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 230 | "truth registers[18].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 231 | "truth registers[18].field_parts[0].bit_field[5]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 232 | "truth registers[18].field_parts[0].bit_field[5]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 233 | "truth registers[18].field_parts[0].bit_field[6]" | `name_or_parameter` | 0.000000 | "WATERMARK" | "Watermark" | "strict fact mismatch; truth=\"WATERMARK\" candidate=\"Watermark\"" |
| 234 | "truth registers[18].field_parts[0].bit_field[6]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 235 | "truth registers[18].field_parts[0].bit_field[6]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 236 | "truth registers[18].field_parts[0].bit_field[7]" | `name_or_parameter` | 0.000000 | "OVERRUN" | "Overrun" | "strict fact mismatch; truth=\"OVERRUN\" candidate=\"Overrun\"" |
| 237 | "truth registers[18].field_parts[0].bit_field[7]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 238 | "truth registers[18].field_parts[0].bit_field[7]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 239 | "truth registers[18].field_parts[0] ↔ v11_0 registers[18].field_parts[0]" | `bit_field` | 0.721372 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 240 | "truth registers[18] ↔ v11_0 registers[18]" | `field_parts` | 0.912817 | "mean(0.912817)" | "mean(0.912817)" | "recursive mean of field-part scores" |
| 241 | "truth registers[18].default_value_description ↔ v11_0 registers[18].default_value_description" | `default_value_description` | 0.000000 | "All interrupts disabled" | "" | "description missing or not sufficiently supported" |
| 242 | "truth registers[19].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 243 | "truth registers[19].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 244 | "truth registers[19].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 245 | "truth registers[19].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "ACTIVITY" | "Activity" | "strict fact mismatch; truth=\"ACTIVITY\" candidate=\"Activity\"" |
| 246 | "truth registers[19].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 247 | "truth registers[19].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "INACTIVITY" | "Inactivity" | "strict fact mismatch; truth=\"INACTIVITY\" candidate=\"Inactivity\"" |
| 248 | "truth registers[19].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 249 | "truth registers[19].field_parts[0].bit_field[5]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 250 | "truth registers[19].field_parts[0].bit_field[6]" | `name_or_parameter` | 0.000000 | "WATERMARK" | "Watermark" | "strict fact mismatch; truth=\"WATERMARK\" candidate=\"Watermark\"" |
| 251 | "truth registers[19].field_parts[0].bit_field[6]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 252 | "truth registers[19].field_parts[0].bit_field[7]" | `name_or_parameter` | 0.000000 | "OVERRUN" | "Overrun" | "strict fact mismatch; truth=\"OVERRUN\" candidate=\"Overrun\"" |
| 253 | "truth registers[19].field_parts[0].bit_field[7]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 254 | "truth registers[19].field_parts[0] ↔ v11_0 registers[19].field_parts[0]" | `bit_field` | 0.931093 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 255 | "truth registers[19] ↔ v11_0 registers[19]" | `field_parts` | 0.978439 | "mean(0.978439)" | "mean(0.978439)" | "recursive mean of field-part scores" |
| 256 | "truth registers[19].default_value_description ↔ v11_0 registers[19].default_value_description" | `default_value_description` | 0.000000 | "All interrupts mapped to INT1" | "" | "description missing or not sufficiently supported" |
| 257 | "truth registers[20].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 258 | "truth registers[20].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 259 | "truth registers[20].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 260 | "truth registers[20].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 261 | "truth registers[20].field_parts[0].bit_field[2]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 262 | "truth registers[20].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 263 | "truth registers[20].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "ACTIVITY" | "Activity" | "strict fact mismatch; truth=\"ACTIVITY\" candidate=\"Activity\"" |
| 264 | "truth registers[20].field_parts[0].bit_field[3]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 265 | "truth registers[20].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 266 | "truth registers[20].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "INACTIVITY" | "Inactivity" | "strict fact mismatch; truth=\"INACTIVITY\" candidate=\"Inactivity\"" |
| 267 | "truth registers[20].field_parts[0].bit_field[4]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 268 | "truth registers[20].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 269 | "truth registers[20].field_parts[0].bit_field[5]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 270 | "truth registers[20].field_parts[0].bit_field[5]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 271 | "truth registers[20].field_parts[0].bit_field[6]" | `name_or_parameter` | 0.000000 | "WATERMARK" | "Watermark" | "strict fact mismatch; truth=\"WATERMARK\" candidate=\"Watermark\"" |
| 272 | "truth registers[20].field_parts[0].bit_field[6]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 273 | "truth registers[20].field_parts[0].bit_field[6]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 274 | "truth registers[20].field_parts[0].bit_field[7]" | `name_or_parameter` | 0.000000 | "OVERRUN" | "Overrun" | "strict fact mismatch; truth=\"OVERRUN\" candidate=\"Overrun\"" |
| 275 | "truth registers[20].field_parts[0].bit_field[7]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 276 | "truth registers[20].field_parts[0].bit_field[7]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 277 | "truth registers[20].field_parts[0] ↔ v11_0 registers[20].field_parts[0]" | `bit_field` | 0.721372 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 278 | "truth registers[20] ↔ v11_0 registers[20]" | `field_parts` | 0.912817 | "mean(0.912817)" | "mean(0.912817)" | "recursive mean of field-part scores" |
| 279 | "truth registers[20].default_value_description ↔ v11_0 registers[20].default_value_description" | `default_value_description` | 0.000000 | "Watermark status bit set in reset value per register map" | "" | "description missing or not sufficiently supported" |
| 280 | "truth registers[21].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 281 | "truth registers[21].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 282 | "truth registers[21].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 283 | "truth registers[21].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 284 | "truth registers[21].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "JUSTIFY" | "Justify" | "strict fact mismatch; truth=\"JUSTIFY\" candidate=\"Justify\"" |
| 285 | "truth registers[21].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 286 | "truth registers[21].field_parts[0].bit_field[5]" | `name_or_parameter` | 0.000000 | "RANGE" | "Range" | "strict fact mismatch; truth=\"RANGE\" candidate=\"Range\"" |
| 287 | "truth registers[21].field_parts[0].bit_field[5]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 288 | "truth registers[21].field_parts[0].bit_field[6]" | `name_or_parameter` | 0.000000 | "RESERVED" | "0" | "strict fact mismatch; truth=\"RESERVED\" candidate=\"0\"" |
| 289 | "truth registers[21].field_parts[0] ↔ v11_0 registers[21].field_parts[0]" | `bit_field` | 0.940937 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 290 | "truth registers[21] ↔ v11_0 registers[21]" | `field_parts` | 0.981519 | "mean(0.981519)" | "mean(0.981519)" | "recursive mean of field-part scores" |
| 291 | "truth registers[21].default_value_description ↔ v11_0 registers[21].default_value_description" | `default_value_description` | 0.000000 | "10-bit, +/-2 g, right-justified, four-wire SPI, active-high interrupts" | "" | "description missing or not sufficiently supported" |
| 292 | "truth registers[22].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "DATAX0" | MISSING | "field is missing" |
| 293 | "truth registers[22].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Least significant byte of two's-complement X-axis output data." | MISSING | "description missing or not sufficiently supported" |
| 294 | "truth registers[22].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 295 | "truth registers[22].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 296 | "truth registers[22].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 297 | "truth registers[22].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 298 | "truth registers[22].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 299 | "truth registers[22].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "R" | MISSING | "field is missing" |
| 300 | "truth registers[22].field_parts[0] ↔ v11_0 registers[22].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 301 | "truth registers[22] ↔ v11_0 registers[22]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 302 | "truth registers[22].default_value_description ↔ v11_0 registers[22].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 303 | "truth registers[22].field_parts[1].bit_field[0]" | `name_or_parameter` | 0.000000 | "DATAX1" | MISSING | "field is missing" |
| 304 | "truth registers[22].field_parts[1].bit_field[0]" | `field_description` | 0.000000 | "Most significant byte of two's-complement X-axis output data." | MISSING | "description missing or not sufficiently supported" |
| 305 | "truth registers[22].field_parts[1].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 306 | "truth registers[22].field_parts[1].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 307 | "truth registers[22].field_parts[1].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 308 | "truth registers[22].field_parts[1].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 309 | "truth registers[22].field_parts[1].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 310 | "truth registers[22].field_parts[1].bit_field[0]" | `type_write_read` | 0.000000 | "R" | MISSING | "field is missing" |
| 311 | "truth registers[22].field_parts[1] ↔ v11_0 registers[23].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 312 | "truth registers[22] ↔ v11_0 registers[23]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 313 | "truth registers[22].default_value_description ↔ v11_0 registers[23].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 314 | "truth registers[23].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "DATAY0" | MISSING | "field is missing" |
| 315 | "truth registers[23].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Least significant byte of two's-complement Y-axis output data." | MISSING | "description missing or not sufficiently supported" |
| 316 | "truth registers[23].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 317 | "truth registers[23].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 318 | "truth registers[23].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 319 | "truth registers[23].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 320 | "truth registers[23].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 321 | "truth registers[23].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "R" | MISSING | "field is missing" |
| 322 | "truth registers[23].field_parts[0] ↔ v11_0 registers[24].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 323 | "truth registers[23] ↔ v11_0 registers[24]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 324 | "truth registers[23].default_value_description ↔ v11_0 registers[24].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 325 | "truth registers[23].field_parts[1].bit_field[0]" | `name_or_parameter` | 0.000000 | "DATAY1" | MISSING | "field is missing" |
| 326 | "truth registers[23].field_parts[1].bit_field[0]" | `field_description` | 0.000000 | "Most significant byte of two's-complement Y-axis output data." | MISSING | "description missing or not sufficiently supported" |
| 327 | "truth registers[23].field_parts[1].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 328 | "truth registers[23].field_parts[1].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 329 | "truth registers[23].field_parts[1].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 330 | "truth registers[23].field_parts[1].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 331 | "truth registers[23].field_parts[1].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 332 | "truth registers[23].field_parts[1].bit_field[0]" | `type_write_read` | 0.000000 | "R" | MISSING | "field is missing" |
| 333 | "truth registers[23].field_parts[1] ↔ v11_0 registers[25].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 334 | "truth registers[23] ↔ v11_0 registers[25]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 335 | "truth registers[23].default_value_description ↔ v11_0 registers[25].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 336 | "truth registers[24].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "DATAZ0" | MISSING | "field is missing" |
| 337 | "truth registers[24].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Least significant byte of two's-complement Z-axis output data." | MISSING | "description missing or not sufficiently supported" |
| 338 | "truth registers[24].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 339 | "truth registers[24].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 340 | "truth registers[24].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 341 | "truth registers[24].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 342 | "truth registers[24].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 343 | "truth registers[24].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "R" | MISSING | "field is missing" |
| 344 | "truth registers[24].field_parts[0] ↔ v11_0 registers[26].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 345 | "truth registers[24] ↔ v11_0 registers[26]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 346 | "truth registers[24].default_value_description ↔ v11_0 registers[26].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 347 | "truth registers[24].field_parts[1].bit_field[0]" | `name_or_parameter` | 0.000000 | "DATAZ1" | MISSING | "field is missing" |
| 348 | "truth registers[24].field_parts[1].bit_field[0]" | `field_description` | 0.000000 | "Most significant byte of two's-complement Z-axis output data." | MISSING | "description missing or not sufficiently supported" |
| 349 | "truth registers[24].field_parts[1].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 350 | "truth registers[24].field_parts[1].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 351 | "truth registers[24].field_parts[1].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 352 | "truth registers[24].field_parts[1].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 353 | "truth registers[24].field_parts[1].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 354 | "truth registers[24].field_parts[1].bit_field[0]" | `type_write_read` | 0.000000 | "R" | MISSING | "field is missing" |
| 355 | "truth registers[24].field_parts[1] ↔ v11_0 registers[27].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 356 | "truth registers[24] ↔ v11_0 registers[27]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 357 | "truth registers[24].default_value_description ↔ v11_0 registers[27].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 358 | "truth registers[25].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 359 | "truth registers[25].field_parts[0].bit_field[1]" | `name_or_parameter` | 0.000000 | "TRIGGER" | "Trigger" | "strict fact mismatch; truth=\"TRIGGER\" candidate=\"Trigger\"" |
| 360 | "truth registers[25].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 361 | "truth registers[25].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "SAMPLES" | "Samples" | "strict fact mismatch; truth=\"SAMPLES\" candidate=\"Samples\"" |
| 362 | "truth registers[25].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 363 | "truth registers[25].field_parts[0] ↔ v11_0 registers[28].field_parts[0]" | `bit_field` | 0.927559 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 364 | "truth registers[25] ↔ v11_0 registers[28]" | `field_parts` | 0.977333 | "mean(0.977333)" | "mean(0.977333)" | "recursive mean of field-part scores" |
| 365 | "truth registers[25].default_value_description ↔ v11_0 registers[28].default_value_description" | `default_value_description` | 0.000000 | "Bypass mode, trigger INT1, zero samples; zero samples immediately sets WATERMARK and may cause undesirable trigger-mode operation." | "" | "description missing or not sufficiently supported" |
| 366 | "truth registers[26].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 367 | "truth registers[26].field_parts[0].bit_field[1]" | `name_or_parameter` | 0.000000 | "ENTRIES" | "Entries" | "strict fact mismatch; truth=\"ENTRIES\" candidate=\"Entries\"" |
| 368 | "truth registers[26].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 369 | "truth registers[26].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "RESERVED" | "0" | "strict fact mismatch; truth=\"RESERVED\" candidate=\"0\"" |
| 370 | "truth registers[26].field_parts[0] ↔ v11_0 registers[29].field_parts[0]" | `bit_field` | 0.946995 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 371 | "truth registers[26] ↔ v11_0 registers[29]" | `field_parts` | 0.983415 | "mean(0.983415)" | "mean(0.983415)" | "recursive mean of field-part scores" |
| 372 | "truth registers[26].default_value_description ↔ v11_0 registers[29].default_value_description" | `default_value_description` | 0.000000 | "No trigger; zero entries" | "" | "description missing or not sufficiently supported" |

## 4. Empty-field audit

- Simultaneously empty truth and candidate primitive fields credited with 1.0: 14.
- type_write_read: 6 empty/empty comparison(s).
- values: 8 empty/empty comparison(s).

## 5. Missing/extra physical locations and representation check

- No truth physical location is missing.
- No extra extracted physical location is present.
- Numeric address matching uses normalized hex/decimal plus bank and page; nested address descriptions do not override a correct address key.
- Split byte grouping is accepted, but all matched direct fields and bit fields remain strictly scored.

## 6. Physical-register aggregation and calculation conclusion

| Truth physical register | Address | Associated extracted logical register(s) | q_R |
|---|---:|---|---:|
| `DEVID` | 0x00 (0) | `registers[0]` `DEVID` Q=1.000000 | 1.000000 |
| `THRESH_TAP` | 0x1D (29) | `registers[1]` `THRESH_TAP` Q=0.873149 | 0.873149 |
| `OFSX` | 0x1E (30) | `registers[2]` `OFSX` Q=0.906546 | 0.906546 |
| `OFSY` | 0x1F (31) | `registers[3]` `OFSY` Q=0.906546 | 0.906546 |
| `OFSZ` | 0x20 (32) | `registers[4]` `OFSZ` Q=0.906546 | 0.906546 |
| `DUR` | 0x21 (33) | `registers[5]` `DUR` Q=0.873149 | 0.873149 |
| `Latent` | 0x22 (34) | `registers[6]` `Latent` Q=0.873149 | 0.873149 |
| `Window` | 0x23 (35) | `registers[7]` `Window` Q=0.873149 | 0.873149 |
| `THRESH_ACT` | 0x24 (36) | `registers[8]` `THRESH_ACT` Q=0.873149 | 0.873149 |
| `THRESH_INACT` | 0x25 (37) | `registers[9]` `THRESH_INACT` Q=0.873149 | 0.873149 |
| `TIME_INACT` | 0x26 (38) | `registers[10]` `TIME_INACT` Q=0.873149 | 0.873149 |
| `ACT_INACT_CTL` | 0x27 (39) | `registers[11]` `ACT_INACT_CTL` Q=0.944474 | 0.944474 |
| `THRESH_FF` | 0x28 (40) | `registers[12]` `THRESH_FF` Q=0.873149 | 0.873149 |
| `TIME_FF` | 0x29 (41) | `registers[13]` `TIME_FF` Q=0.873149 | 0.873149 |
| `TAP_AXES` | 0x2A (42) | `registers[14]` `TAP_AXES` Q=0.944583 | 0.944583 |
| `ACT_TAP_STATUS` | 0x2B (43) | `registers[15]` `ACT_TAP_STATUS` Q=0.942705 | 0.942705 |
| `BW_RATE` | 0x2C (44) | `registers[16]` `BW_RATE` Q=0.971815 | 0.971815 |
| `POWER_CTL` | 0x2D (45) | `registers[17]` `POWER_CTL` Q=0.953878 | 0.953878 |
| `INT_ENABLE` | 0x2E (46) | `registers[18]` `INT_ENABLE` Q=0.940564 | 0.940564 |
| `INT_MAP` | 0x2F (47) | `registers[19]` `INT_MAP` Q=0.960164 | 0.960164 |
| `INT_SOURCE` | 0x30 (48) | `registers[20]` `INT_SOURCE` Q=0.940564 | 0.940564 |
| `DATA_FORMAT` | 0x31 (49) | `registers[21]` `DATA_FORMAT` Q=0.961084 | 0.961084 |
| `DATAX` | 0x32 (50) | `registers[22]` `DATAX0` Q=0.873149 | 0.873149 |
| `DATAX` | 0x33 (51) | `registers[23]` `DATAX1` Q=0.873149 | 0.873149 |
| `DATAY` | 0x34 (52) | `registers[24]` `DATAY0` Q=0.873149 | 0.873149 |
| `DATAY` | 0x35 (53) | `registers[25]` `DATAY1` Q=0.873149 | 0.873149 |
| `DATAZ` | 0x36 (54) | `registers[26]` `DATAZ0` Q=0.873149 | 0.873149 |
| `DATAZ` | 0x37 (55) | `registers[27]` `DATAZ1` Q=0.873149 | 0.873149 |
| `FIFO_CTL` | 0x38 (56) | `registers[28]` `FIFO_CTL` Q=0.959833 | 0.959833 |
| `FIFO_STATUS` | 0x39 (57) | `registers[29]` `FIFO_STATUS` Q=0.961650 | 0.961650 |

Σ q_R = 27.298194942 over n=30 truth physical registers.

\(S_{final}=(10/30×27.298194942)×(30/(30+0))=\mathbf{9.099398314}\,/\,10\)

The final ADXL345 v11_0 score is **9.099398314 / 10**.
