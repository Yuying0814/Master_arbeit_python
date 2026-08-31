# ADXL345 v12 detailed score — revised AGENTS.md rules

## 1. Scoring basis

- n=30 unique truth physical registers are scored by numeric address, bank, and page; hexadecimal and decimal representations of one numeric address are equivalent.
- m=30 truth physical locations are matched and x=0 extra extracted physical locations are counted. Extra-location factor m/(m+x)=1.000000000.
- Each matched logical register is calculated bottom-up: exact bit-range bit fields, then field parts, then the logical register. Missing truth bit fields receive zero for all primitive fields.
- Split data-byte representations are compared with the corresponding truth field part; grouping alone is not penalized.
- Descriptions are judged semantically: equivalent paraphrase 1.0, relevant but incomplete 0.5, missing or contradictory 0.0. Objective facts including names, numeric addresses, widths, bit boundaries, access types, reserved flags, default values, and value-code sets are strict.
- Value-code notation and list order are normalized. Simultaneously empty truth and candidate fields receive 1.0. Reserved bit names and descriptions may be empty. Category and unlisted fields are excluded.
- AHP weights are applied exactly as specified in AGENTS.md.

## Extracted logical register 1: `DEVID`

v12_0 location: `registers[0]`; truth association: `truth registers[0]` (`DEVID`).
Associated physical locations: 0x00 (0).

### Bottom layer: bit fields, then field parts

#### Field part 1: `DEVID` at 0x00 (0)

Locations: `truth registers[0].field_parts[0]` ↔ `v12_0 registers[0].field_parts[0]`

Truth bit field 1: `DEVID` bits 0:7

Locations: `truth registers[0].field_parts[0].bit_field[0]` ↔ `v12_0 registers[0].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "DEVID" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Device identification code." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 0 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 8 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0xE5","value_description":"ADXL345 device ID."}] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | false | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.000000) = **0.000000**.
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DEVID" | "DEVID" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Device ID"} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Fixed device ID register." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.617800/1.0000=\mathbf{0.617800}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.617800) = **0.617800**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DEVID" | "DEVID" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Device ID"}] | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Fixed device ID code of 0xE5." | "Device ID. Holds a fixed device ID code of 0xE5 (345 octal)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.617800" | "mean(0.617800)" | "mean(0.617800)" |
| "`default_value`" | "0.0667" | "1.000000" | "11100101" | "11100101" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0xE5" | "" |

\(Q(L_{1})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.617800 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.852537/1.0001=\mathbf{0.852452}\)


## Extracted logical register 2: `THRESH_TAP`

v12_0 location: `registers[1]`; truth association: `truth registers[1]` (`THRESH_TAP`).
Associated physical locations: 0x1D (29).

### Bottom layer: bit fields, then field parts

#### Field part 1: `THRESH_TAP` at 0x1D (29)

Locations: `truth registers[1].field_parts[0]` ↔ `v12_0 registers[1].field_parts[0]`

Truth bit field 1: `THRESH_TAP` bits 0:7

Locations: `truth registers[1].field_parts[0].bit_field[0]` ↔ `v12_0 registers[1].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "THRESH_TAP" | "THRESH_TAP" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Tap threshold"} | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Tap threshold." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.617800/1.0000=\mathbf{0.617800}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.617800) = **0.617800**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "THRESH_TAP" | "THRESH_TAP" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Tap threshold"}] | [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned threshold magnitude for tap interrupts; scale factor 62.5 mg/LSB." | "Tap threshold. 8-bit unsigned value. Scale factor: 62.5 mg/LSB (0xFF = 16 g)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.617800" | "mean(0.617800)" | "mean(0.617800)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 may result in undesirable behavior if tap interrupts are enabled." | "" |

\(Q(L_{2})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.617800 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.852537/1.0001=\mathbf{0.852452}\)


## Extracted logical register 3: `OFSX`

v12_0 location: `registers[2]`; truth association: `truth registers[2]` (`OFSX`).
Associated physical locations: 0x1E (30).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OFSX` at 0x1E (30)

Locations: `truth registers[2].field_parts[0]` ↔ `v12_0 registers[2].field_parts[0]`

Truth bit field 1: `OFSX` bits 0:7

Locations: `truth registers[2].field_parts[0].bit_field[0]` ↔ `v12_0 registers[2].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "OFSX" | "OFSX" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"X-axis offset"} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "X-axis offset adjustment." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.617800/1.0000=\mathbf{0.617800}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.617800) = **0.617800**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "OFSX" | "OFSX" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"X-axis offset"}] | [{"hex":"0x1E","decimal":"30","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement X-axis offset adjustment, 15.6 mg/LSB." | "X-axis offset. 8-bit twos complement format. Scale factor: 15.6 mg/LSB (0x7F = 2 g)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.617800" | "mean(0.617800)" | "mean(0.617800)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{3})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.617800 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.852537/1.0001=\mathbf{0.852452}\)


## Extracted logical register 4: `OFSY`

v12_0 location: `registers[3]`; truth association: `truth registers[3]` (`OFSY`).
Associated physical locations: 0x1F (31).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OFSY` at 0x1F (31)

Locations: `truth registers[3].field_parts[0]` ↔ `v12_0 registers[3].field_parts[0]`

Truth bit field 1: `OFSY` bits 0:7

Locations: `truth registers[3].field_parts[0].bit_field[0]` ↔ `v12_0 registers[3].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "OFSY" | "OFSY" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Y-axis offset"} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Y-axis offset adjustment." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.617800/1.0000=\mathbf{0.617800}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.617800) = **0.617800**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "OFSY" | "OFSY" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Y-axis offset"}] | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement Y-axis offset adjustment, 15.6 mg/LSB." | "Y-axis offset. 8-bit twos complement format. Scale factor: 15.6 mg/LSB (0x7F = 2 g)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.617800" | "mean(0.617800)" | "mean(0.617800)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{4})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.617800 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.852537/1.0001=\mathbf{0.852452}\)


## Extracted logical register 5: `OFSZ`

v12_0 location: `registers[4]`; truth association: `truth registers[4]` (`OFSZ`).
Associated physical locations: 0x20 (32).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OFSZ` at 0x20 (32)

Locations: `truth registers[4].field_parts[0]` ↔ `v12_0 registers[4].field_parts[0]`

Truth bit field 1: `OFSZ` bits 0:7

Locations: `truth registers[4].field_parts[0].bit_field[0]` ↔ `v12_0 registers[4].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "OFSZ" | "OFSZ" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Z-axis offset"} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Z-axis offset adjustment." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.617800/1.0000=\mathbf{0.617800}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.617800) = **0.617800**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "OFSZ" | "OFSZ" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Z-axis offset"}] | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement Z-axis offset adjustment, 15.6 mg/LSB." | "Z-axis offset. 8-bit twos complement format. Scale factor: 15.6 mg/LSB (0x7F = 2 g)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.617800" | "mean(0.617800)" | "mean(0.617800)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{5})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.617800 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.852537/1.0001=\mathbf{0.852452}\)


## Extracted logical register 6: `DUR`

v12_0 location: `registers[5]`; truth association: `truth registers[5]` (`DUR`).
Associated physical locations: 0x21 (33).

### Bottom layer: bit fields, then field parts

#### Field part 1: `DUR` at 0x21 (33)

Locations: `truth registers[5].field_parts[0]` ↔ `v12_0 registers[5].field_parts[0]`

Truth bit field 1: `DUR` bits 0:7

Locations: `truth registers[5].field_parts[0].bit_field[0]` ↔ `v12_0 registers[5].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DUR" | "DUR" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"Tap duration"} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Maximum tap duration." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.617800/1.0000=\mathbf{0.617800}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.617800) = **0.617800**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DUR" | "DUR" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"Tap duration"}] | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned maximum tap duration; 625 us/LSB. Zero disables tap functions." | "Tap duration. Unsigned time value representing the maximum time an event must be above THRESH_TAP to qualify as a tap. Scale factor: 625 µs/LSB. A value of 0 disables single/double tap functions." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.617800" | "mean(0.617800)" | "mean(0.617800)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 disables the single-tap and double-tap functions." | "" |

\(Q(L_{6})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.617800 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.852537/1.0001=\mathbf{0.852452}\)


## Extracted logical register 7: `Latent`

v12_0 location: `registers[6]`; truth association: `truth registers[6]` (`Latent`).
Associated physical locations: 0x22 (34).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Latent` at 0x22 (34)

Locations: `truth registers[6].field_parts[0]` ↔ `v12_0 registers[6].field_parts[0]`

Truth bit field 1: `Latent` bits 0:7

Locations: `truth registers[6].field_parts[0].bit_field[0]` ↔ `v12_0 registers[6].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "Latent" | "Latent" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Tap latency"} | {"hex":"0x22","decimal":"34","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Tap latency." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.617800/1.0000=\mathbf{0.617800}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.617800) = **0.617800**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "Latent" | "Latent" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x22","decimal":"34","bank":"","page":"","description":"Tap latency"}] | [{"hex":"0x22","decimal":"34","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned wait time from first tap to the start of the second-tap window; 1.25 ms/LSB." | "Tap latency. Unsigned time value representing the wait time from detection of a tap event to start of time window (defined by Window register) for second tap detection. Scale factor: 1.25 ms/LSB. A value of 0 disables double tap function." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.617800" | "mean(0.617800)" | "mean(0.617800)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 disables the double-tap function." | "" |

\(Q(L_{7})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.617800 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.852537/1.0001=\mathbf{0.852452}\)


## Extracted logical register 8: `Window`

v12_0 location: `registers[7]`; truth association: `truth registers[7]` (`Window`).
Associated physical locations: 0x23 (35).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Window` at 0x23 (35)

Locations: `truth registers[7].field_parts[0]` ↔ `v12_0 registers[7].field_parts[0]`

Truth bit field 1: `Window` bits 0:7

Locations: `truth registers[7].field_parts[0].bit_field[0]` ↔ `v12_0 registers[7].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "Window" | "Window" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"Tap window"} | {"hex":"0x23","decimal":"35","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Tap window." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.617800/1.0000=\mathbf{0.617800}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.617800) = **0.617800**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "Window" | "Window" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"Tap window"}] | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned duration after latency during which a second tap can begin; 1.25 ms/LSB." | "Tap window. Unsigned time value representing the time after expiration of latency time during which a second valid tap can begin. Scale factor: 1.25 ms/LSB. A value of 0 disables double tap function." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.617800" | "mean(0.617800)" | "mean(0.617800)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 disables the double-tap function." | "" |

\(Q(L_{8})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.617800 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.852537/1.0001=\mathbf{0.852452}\)


## Extracted logical register 9: `THRESH_ACT`

v12_0 location: `registers[8]`; truth association: `truth registers[8]` (`THRESH_ACT`).
Associated physical locations: 0x24 (36).

### Bottom layer: bit fields, then field parts

#### Field part 1: `THRESH_ACT` at 0x24 (36)

Locations: `truth registers[8].field_parts[0]` ↔ `v12_0 registers[8].field_parts[0]`

Truth bit field 1: `THRESH_ACT` bits 0:7

Locations: `truth registers[8].field_parts[0].bit_field[0]` ↔ `v12_0 registers[8].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "THRESH_ACT" | "THRESH_ACT" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Activity threshold"} | {"hex":"0x24","decimal":"36","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Activity threshold." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.617800/1.0000=\mathbf{0.617800}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.617800) = **0.617800**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "THRESH_ACT" | "THRESH_ACT" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Activity threshold"}] | [{"hex":"0x24","decimal":"36","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned activity threshold; 62.5 mg/LSB." | "Activity threshold. 8-bit unsigned value. Scale factor: 62.5 mg/LSB." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.617800" | "mean(0.617800)" | "mean(0.617800)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 may result in undesirable behavior if the activity interrupt is enabled." | "" |

\(Q(L_{9})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.617800 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.852537/1.0001=\mathbf{0.852452}\)


## Extracted logical register 10: `THRESH_INACT`

v12_0 location: `registers[9]`; truth association: `truth registers[9]` (`THRESH_INACT`).
Associated physical locations: 0x25 (37).

### Bottom layer: bit fields, then field parts

#### Field part 1: `THRESH_INACT` at 0x25 (37)

Locations: `truth registers[9].field_parts[0]` ↔ `v12_0 registers[9].field_parts[0]`

Truth bit field 1: `THRESH_INACT` bits 0:7

Locations: `truth registers[9].field_parts[0].bit_field[0]` ↔ `v12_0 registers[9].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "THRESH_INACT" | "THRESH_INACT" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"Inactivity threshold"} | {"hex":"0x25","decimal":"37","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Inactivity threshold." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.617800/1.0000=\mathbf{0.617800}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.617800) = **0.617800**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "THRESH_INACT" | "THRESH_INACT" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":"Inactivity threshold"}] | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned inactivity threshold; 62.5 mg/LSB." | "Inactivity threshold. 8-bit unsigned value. Scale factor: 62.5 mg/LSB." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.617800" | "mean(0.617800)" | "mean(0.617800)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 may result in undesirable behavior if the inactivity interrupt is enabled." | "" |

\(Q(L_{10})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.617800 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.852537/1.0001=\mathbf{0.852452}\)


## Extracted logical register 11: `TIME_INACT`

v12_0 location: `registers[10]`; truth association: `truth registers[10]` (`TIME_INACT`).
Associated physical locations: 0x26 (38).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_INACT` at 0x26 (38)

Locations: `truth registers[10].field_parts[0]` ↔ `v12_0 registers[10].field_parts[0]`

Truth bit field 1: `TIME_INACT` bits 0:7

Locations: `truth registers[10].field_parts[0].bit_field[0]` ↔ `v12_0 registers[10].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "TIME_INACT" | "TIME_INACT" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Inactivity time"} | {"hex":"0x26","decimal":"38","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Inactivity time." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.617800/1.0000=\mathbf{0.617800}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.617800) = **0.617800**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "TIME_INACT" | "TIME_INACT" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Inactivity time"}] | [{"hex":"0x26","decimal":"38","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned time acceleration must remain below THRESH_INACT; 1 s/LSB." | "Inactivity time. Unsigned value representing the time acceleration must be less than THRESH_INACT for inactivity to be declared. Scale factor: 1 sec/LSB. Uses filtered output data." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.617800" | "mean(0.617800)" | "mean(0.617800)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 results in an interrupt when acceleration is below THRESH_INACT." | "" |

\(Q(L_{11})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.617800 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.852537/1.0001=\mathbf{0.852452}\)


## Extracted logical register 12: `ACT_INACT_CTL`

v12_0 location: `registers[11]`; truth association: `truth registers[11]` (`ACT_INACT_CTL`).
Associated physical locations: 0x27 (39).

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACT_INACT_CTL` at 0x27 (39)

Locations: `truth registers[11].field_parts[0]` ↔ `v12_0 registers[11].field_parts[0]`

Truth bit field 1: `ACT_ACDC` bits 7:7

Locations: `truth registers[11].field_parts[0].bit_field[0]` ↔ `v12_0 registers[11].field_parts[0].bit_field[0]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_ACDC" | "ACT ac/dc" |
| "`field_description`" | "0.0586" | "1.000000" | "Activity coupling: 0 dc-coupled, 1 ac-coupled." | "0: dc-coupled, 1: ac-coupled for activity detection." |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"DC-coupled activity detection."},{"value":"1","value_description":"AC-coupled activity detection."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 2: `ACT_X_ENABLE` bits 6:6

Locations: `truth registers[11].field_parts[0].bit_field[1]` ↔ `v12_0 registers[11].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_X_ENABLE" | "ACT_X enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable X-axis activity participation." | "1: Enable X-axis for activity detection." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 3: `ACT_Y_ENABLE` bits 5:5

Locations: `truth registers[11].field_parts[0].bit_field[2]` ↔ `v12_0 registers[11].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_Y_ENABLE" | "ACT_Y enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable Y-axis activity participation." | "1: Enable Y-axis for activity detection." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 4: `ACT_Z_ENABLE` bits 4:4

Locations: `truth registers[11].field_parts[0].bit_field[3]` ↔ `v12_0 registers[11].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_Z_ENABLE" | "ACT_Z enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable Z-axis activity participation." | "1: Enable Z-axis for activity detection." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 5: `INACT_ACDC` bits 3:3

Locations: `truth registers[11].field_parts[0].bit_field[4]` ↔ `v12_0 registers[11].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACT_ACDC" | "INACT ac/dc" |
| "`field_description`" | "0.0586" | "1.000000" | "Inactivity coupling: 0 dc-coupled, 1 ac-coupled." | "0: dc-coupled, 1: ac-coupled for inactivity detection." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"DC-coupled inactivity detection."},{"value":"1","value_description":"AC-coupled inactivity detection."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 6: `INACT_X_ENABLE` bits 2:2

Locations: `truth registers[11].field_parts[0].bit_field[5]` ↔ `v12_0 registers[11].field_parts[0].bit_field[5]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACT_X_ENABLE" | "INACT_X enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable X-axis inactivity participation." | "1: Enable X-axis for inactivity detection." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 7: `INACT_Y_ENABLE` bits 1:1

Locations: `truth registers[11].field_parts[0].bit_field[6]` ↔ `v12_0 registers[11].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACT_Y_ENABLE" | "INACT_Y enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable Y-axis inactivity participation." | "1: Enable Y-axis for inactivity detection." |
| "`bit_start`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 8: `INACT_Z_ENABLE` bits 0:0

Locations: `truth registers[11].field_parts[0].bit_field[7]` ↔ `v12_0 registers[11].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACT_Z_ENABLE" | "INACT_Z enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable Z-axis inactivity participation." | "1: Enable Z-axis for inactivity detection." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Field-part aggregation

`bit_field` correctness = mean(0.710771, 0.710771, 0.710771, 0.710771, 0.710771, 0.710771, 0.710771, 0.710771) = **0.710771**.
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "ACT_INACT_CTL" | "ACT_INACT_CTL" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"Axis enable control for activity and inactivity detection"} | {"hex":"0x27","decimal":"39","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Activity/inactivity axis control." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.710771" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.710771)/1.0000=0.840200/1.0000=\mathbf{0.840200}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.840200) = **0.840200**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "ACT_INACT_CTL" | "ACT_INACT_CTL" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Axis enable control for activity and inactivity detection"}] | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Axis and AC/DC coupling control for activity and inactivity detection." | "Axis enable control for activity and inactivity detection. Bits D7-D4: ACT AC/DC, ACT_X/Y/Z enable. Bits D3-D0: INACT AC/DC, INACT_X/Y/Z enable." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.840200" | "mean(0.840200)" | "mean(0.840200)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "DC-coupled; all axes disabled" | "" |

\(Q(L_{12})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.840200 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.918968/1.0001=\mathbf{0.918876}\)


## Extracted logical register 13: `THRESH_FF`

v12_0 location: `registers[12]`; truth association: `truth registers[12]` (`THRESH_FF`).
Associated physical locations: 0x28 (40).

### Bottom layer: bit fields, then field parts

#### Field part 1: `THRESH_FF` at 0x28 (40)

Locations: `truth registers[12].field_parts[0]` ↔ `v12_0 registers[12].field_parts[0]`

Truth bit field 1: `THRESH_FF` bits 0:7

Locations: `truth registers[12].field_parts[0].bit_field[0]` ↔ `v12_0 registers[12].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "THRESH_FF" | "THRESH_FF" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Free-fall threshold"} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Free-fall threshold." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.617800/1.0000=\mathbf{0.617800}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.617800) = **0.617800**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "THRESH_FF" | "THRESH_FF" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Free-fall threshold"}] | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned free-fall threshold; 62.5 mg/LSB." | "Free-fall threshold. 8-bit unsigned value. Scale factor: 62.5 mg/LSB. Recommended range: 300 mg to 600 mg (0x05 to 0x09)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.617800" | "mean(0.617800)" | "mean(0.617800)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 mg may result in undesirable behavior if the free-fall interrupt is enabled." | "" |

\(Q(L_{13})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.617800 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.852537/1.0001=\mathbf{0.852452}\)


## Extracted logical register 14: `TIME_FF`

v12_0 location: `registers[13]`; truth association: `truth registers[13]` (`TIME_FF`).
Associated physical locations: 0x29 (41).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_FF` at 0x29 (41)

Locations: `truth registers[13].field_parts[0]` ↔ `v12_0 registers[13].field_parts[0]`

Truth bit field 1: `TIME_FF` bits 0:7

Locations: `truth registers[13].field_parts[0].bit_field[0]` ↔ `v12_0 registers[13].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "TIME_FF" | "TIME_FF" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"Free-fall time"} | {"hex":"0x29","decimal":"41","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Free-fall time." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.617800/1.0000=\mathbf{0.617800}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.617800) = **0.617800**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "TIME_FF" | "TIME_FF" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x29","decimal":"41","bank":"","page":"","description":"Free-fall time"}] | [{"hex":"0x29","decimal":"41","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Unsigned minimum free-fall time; 5 ms/LSB." | "Free-fall time. Unsigned value representing the minimum time all axes must be less than THRESH_FF to generate a free-fall interrupt. Scale factor: 5 ms/LSB. Recommended range: 100 ms to 350 ms (0x14 to 0x46)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.617800" | "mean(0.617800)" | "mean(0.617800)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0 may result in undesirable behavior if the free-fall interrupt is enabled." | "" |

\(Q(L_{14})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.617800 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.852537/1.0001=\mathbf{0.852452}\)


## Extracted logical register 15: `TAP_AXES`

v12_0 location: `registers[14]`; truth association: `truth registers[14]` (`TAP_AXES`).
Associated physical locations: 0x2A (42).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TAP_AXES` at 0x2A (42)

Locations: `truth registers[14].field_parts[0]` ↔ `v12_0 registers[14].field_parts[0]`

Truth bit field 1: `SUPPRESS` bits 3:3

Locations: `truth registers[14].field_parts[0].bit_field[0]` ↔ `v12_0 registers[14].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "SUPPRESS" | "Suppress" |
| "`field_description`" | "0.0586" | "1.000000" | "Suppress double-tap detection for acceleration above THRESH_TAP between taps." | "1: Suppress double tap detection if acceleration > THRESH_TAP occurs between taps." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Do not suppress."},{"value":"1","value_description":"Suppress double-tap detection."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 2: `TAP_X_ENABLE` bits 2:2

Locations: `truth registers[14].field_parts[0].bit_field[1]` ↔ `v12_0 registers[14].field_parts[0].bit_field[5]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TAP_X_ENABLE" | "TAP_X enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable X-axis tap participation." | "1: Enable X-axis for tap detection." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude X axis from tap detection."},{"value":"1","value_description":"Enable X-axis participation in tap detection."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 3: `TAP_Y_ENABLE` bits 1:1

Locations: `truth registers[14].field_parts[0].bit_field[2]` ↔ `v12_0 registers[14].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TAP_Y_ENABLE" | "TAP_Y enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable Y-axis tap participation." | "1: Enable Y-axis for tap detection." |
| "`bit_start`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude Y axis from tap detection."},{"value":"1","value_description":"Enable Y-axis participation in tap detection."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 4: `TAP_Z_ENABLE` bits 0:0

Locations: `truth registers[14].field_parts[0].bit_field[3]` ↔ `v12_0 registers[14].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TAP_Z_ENABLE" | "TAP_Z enable" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable Z-axis tap participation." | "1: Enable Z-axis for tap detection." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Exclude Z axis from tap detection."},{"value":"1","value_description":"Enable Z-axis participation in tap detection."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 5: `RESERVED` bits 4:7

Locations: `truth registers[14].field_parts[0].bit_field[4]` ↔ `v12_0 registers[14].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RESERVED" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Reserved bits; do not access." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 4 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 4 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | true | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.710771, 0.710771, 0.710771, 0.710771, 0.000000) = **0.568617**.
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "TAP_AXES" | "TAP_AXES" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Axis control for single tap/double tap"} | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Tap-axis control." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.568617" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.568617)/1.0000=0.795720/1.0000=\mathbf{0.795720}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.795720) = **0.795720**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "TAP_AXES" | "TAP_AXES" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Axis control for single tap/double tap"}] | [{"hex":"0x2A","decimal":"42","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Axis control and suppress control for single-tap/double-tap detection." | "Axis control for single/double tap. Suppress bit disables double tap detection if acceleration > THRESH_TAP occurs between taps." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.795720" | "mean(0.795720)" | "mean(0.795720)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "All tap axes disabled; suppress disabled" | "" |

\(Q(L_{15})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.795720 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.905682/1.0001=\mathbf{0.905591}\)


## Extracted logical register 16: `ACT_TAP_STATUS`

v12_0 location: `registers[15]`; truth association: `truth registers[15]` (`ACT_TAP_STATUS`).
Associated physical locations: 0x2B (43).

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACT_TAP_STATUS` at 0x2B (43)

Locations: `truth registers[15].field_parts[0]` ↔ `v12_0 registers[15].field_parts[0]`

Truth bit field 1: `ACT_X_SOURCE` bits 6:6

Locations: `truth registers[15].field_parts[0].bit_field[0]` ↔ `v12_0 registers[15].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_X_SOURCE" | "ACT_X source" |
| "`field_description`" | "0.0586" | "1.000000" | "X axis involved in activity event." | "1: X-axis involved in activity event." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"X axis not involved in activity."},{"value":"1","value_description":"X axis involved in activity."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 2: `ACT_Y_SOURCE` bits 5:5

Locations: `truth registers[15].field_parts[0].bit_field[1]` ↔ `v12_0 registers[15].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_Y_SOURCE" | "ACT_Y source" |
| "`field_description`" | "0.0586" | "1.000000" | "Y axis involved in activity event." | "1: Y-axis involved in activity event." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Y axis not involved in activity."},{"value":"1","value_description":"Y axis involved in activity."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 3: `ACT_Z_SOURCE` bits 4:4

Locations: `truth registers[15].field_parts[0].bit_field[2]` ↔ `v12_0 registers[15].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACT_Z_SOURCE" | "ACT_Z source" |
| "`field_description`" | "0.0586" | "1.000000" | "Z axis involved in activity event." | "1: Z-axis involved in activity event." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Z axis not involved in activity."},{"value":"1","value_description":"Z axis involved in activity."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 4: `ASLEEP` bits 3:3

Locations: `truth registers[15].field_parts[0].bit_field[3]` ↔ `v12_0 registers[15].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ASLEEP" | "Asleep" |
| "`field_description`" | "0.0586" | "1.000000" | "Sleep status: 1 asleep, 0 not asleep." | "1: Part is asleep (auto-sleep mode)." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Not asleep."},{"value":"1","value_description":"Asleep."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 5: `TAP_X_SOURCE` bits 2:2

Locations: `truth registers[15].field_parts[0].bit_field[4]` ↔ `v12_0 registers[15].field_parts[0].bit_field[5]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TAP_X_SOURCE" | "TAP_X source" |
| "`field_description`" | "0.0586" | "1.000000" | "X axis involved in tap event." | "1: X-axis involved in tap event." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"X axis not involved in tap."},{"value":"1","value_description":"X axis involved in tap."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 6: `TAP_Y_SOURCE` bits 1:1

Locations: `truth registers[15].field_parts[0].bit_field[5]` ↔ `v12_0 registers[15].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TAP_Y_SOURCE" | "TAP_Y source" |
| "`field_description`" | "0.0586" | "1.000000" | "Y axis involved in tap event." | "1: Y-axis involved in tap event." |
| "`bit_start`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Y axis not involved in tap."},{"value":"1","value_description":"Y axis involved in tap."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 7: `TAP_Z_SOURCE` bits 0:0

Locations: `truth registers[15].field_parts[0].bit_field[6]` ↔ `v12_0 registers[15].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TAP_Z_SOURCE" | "TAP_Z source" |
| "`field_description`" | "0.0586" | "1.000000" | "Z axis involved in tap event." | "1: Z-axis involved in tap event." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Z axis not involved in tap."},{"value":"1","value_description":"Z axis involved in tap."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 8: `RESERVED` bits 7:7

Locations: `truth registers[15].field_parts[0].bit_field[7]` ↔ `v12_0 registers[15].field_parts[0].bit_field[0]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RESERVED" | "D7" |
| "`field_description`" | "0.0586" | "1.000000" | "Reserved bit." | "Reserved" |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | true | true |
| "`type_write_read`" | "0.0583" | "1.000000" | "" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

`bit_field` correctness = mean(0.710771, 0.710771, 0.710771, 0.710771, 0.710771, 0.710771, 0.710771, 0.978798) = **0.744274**.
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "ACT_TAP_STATUS" | "ACT_TAP_STATUS" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Source of single tap/double tap"} | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Activity and tap source status." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.744274" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.744274)/1.0000=0.850683/1.0000=\mathbf{0.850683}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.850683) = **0.850683**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "ACT_TAP_STATUS" | "ACT_TAP_STATUS" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Source of single tap/double tap"}] | [{"hex":"0x2B","decimal":"43","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Reports the first axis involved in a tap or activity event and asleep status." | "Source of single/double tap. Indicates first axis involved in a tap or activity event. Asleep bit indicates if part is asleep (auto-sleep mode)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.850683" | "mean(0.850683)" | "mean(0.850683)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "No event source; not asleep" | "" |

\(Q(L_{16})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.850683 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.922099/1.0001=\mathbf{0.922007}\)


## Extracted logical register 17: `BW_RATE`

v12_0 location: `registers[16]`; truth association: `truth registers[16]` (`BW_RATE`).
Associated physical locations: 0x2C (44).

### Bottom layer: bit fields, then field parts

#### Field part 1: `BW_RATE` at 0x2C (44)

Locations: `truth registers[16].field_parts[0]` ↔ `v12_0 registers[16].field_parts[0]`

Truth bit field 1: `LOW_POWER` bits 4:4

Locations: `truth registers[16].field_parts[0].bit_field[0]` ↔ `v12_0 registers[16].field_parts[0].bit_field[3]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "LOW_POWER" | "LOW_POWER" |
| "`field_description`" | "0.0586" | "1.000000" | "Power mode selection." | "0: Normal operation, 1: Reduced power operation (higher noise)." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Normal operation."},{"value":"1","value_description":"Reduced-power operation."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 2: `RATE` bits 0:3

Locations: `truth registers[16].field_parts[0].bit_field[1]` ↔ `v12_0 registers[16].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RATE" | "Rate" |
| "`field_description`" | "0.0586" | "1.000000" | "Output data rate and bandwidth selection; see Table 7 and Table 8 on datasheet page 13." | "Selects device bandwidth and output data rate (see Table 7/8)." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 4 | 4 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0000 (0x00)","value_description":"0.10 Hz output data rate; 0.05 Hz bandwidth."},{"value":"0001 (0x01)","value_description":"0.20 Hz output data rate; 0.10 Hz bandwidth."},{"value":"0010 (0x02)","value_description":"0.39 Hz output data rate; 0.20 Hz bandwidth."},{"value":"0011 (0x03)","value_description":"0.78 Hz output data rate; 0.39 Hz bandwidth."},{"value":"0100 (0x04)","value_description":"1.56 Hz output data rate; 0.78 Hz bandwidth."},{"value":"0101 (0x05)","value_description":"3.13 Hz output data rate; 1.56 Hz bandwidth."},{"value":"0110 (0x06)","value_description":"6.25 Hz output data rate; 3.13 Hz bandwidth."},{"value":"0111 (0x07)","value_description":"12.5 Hz output data rate; 6.25 Hz bandwidth; low-power mode table entry."},{"value":"1000 (0x08)","value_description":"25 Hz output data rate; 12.5 Hz bandwidth; low-power mode table entry."},{"value":"1001 (0x09)","value_description":"50 Hz output data rate; 25 Hz bandwidth; low-power mode table entry."},{"value":"1010 (0x0A)","value_description":"100 Hz output data rate; 50 Hz bandwidth; default; low-power mode table entry."},{"value":"1011 (0x0B)","value_description":"200 Hz output data rate; 100 Hz bandwidth; low-power mode table entry."},{"value":"1100 (0x0C)","value_description":"400 Hz output data rate; 200 Hz bandwidth; low-power mode table entry."},{"value":"1101 (0x0D)","value_description":"800 Hz output data rate; 400 Hz bandwidth."},{"value":"1110 (0x0E)","value_description":"1600 Hz output data rate; 800 Hz bandwidth."},{"value":"1111 (0x0F)","value_description":"3200 Hz output data rate; 1600 Hz bandwidth."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 3: `RESERVED` bits 5:7

Locations: `truth registers[16].field_parts[0].bit_field[2]` ↔ `v12_0 registers[16].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RESERVED" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Reserved bits." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 5 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 3 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | true | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.731973, 0.710771, 0.000000) = **0.480915**.
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "BW_RATE" | "BW_RATE" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Data rate and power mode control"} | {"hex":"0x2C","decimal":"44","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Data rate and power mode control." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.480915" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.480915)/1.0000=0.768278/1.0000=\mathbf{0.768278}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.768278) = **0.768278**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "BW_RATE" | "BW_RATE" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Data rate and power mode control"}] | [{"hex":"0x2C","decimal":"44","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Controls output data rate, bandwidth and low-power mode." | "Data rate and power mode control. LOW_POWER bit selects reduced power operation. Rate bits select bandwidth and output data rate (default: 0x0A = 100 Hz)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.768278" | "mean(0.768278)" | "mean(0.768278)" |
| "`default_value`" | "0.0667" | "1.000000" | "00001010" | "00001010" |
| "`default_value_description`" | "0.0334" | "0.000000" | "100 Hz, normal power" | "" |

\(Q(L_{17})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.768278 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.897485/1.0001=\mathbf{0.897395}\)


## Extracted logical register 18: `POWER_CTL`

v12_0 location: `registers[17]`; truth association: `truth registers[17]` (`POWER_CTL`).
Associated physical locations: 0x2D (45).

### Bottom layer: bit fields, then field parts

#### Field part 1: `POWER_CTL` at 0x2D (45)

Locations: `truth registers[17].field_parts[0]` ↔ `v12_0 registers[17].field_parts[0]`

Truth bit field 1: `LINK` bits 5:5

Locations: `truth registers[17].field_parts[0].bit_field[0]` ↔ `v12_0 registers[17].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "LINK" | "Link" |
| "`field_description`" | "0.0586" | "1.000000" | "Serially links activity and inactivity functions." | "1: Serially link activity and inactivity functions (inactivity must occur before activity)." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Activity and inactivity functions operate concurrently."},{"value":"1","value_description":"Activity and inactivity functions are serially linked."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 2: `AUTO_SLEEP` bits 4:4

Locations: `truth registers[17].field_parts[0].bit_field[1]` ↔ `v12_0 registers[17].field_parts[0].bit_field[3]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "AUTO_SLEEP" | "AUTO_SLEEP" |
| "`field_description`" | "0.0586" | "1.000000" | "Enables automatic sleep when linked inactivity is detected." | "1: Enable auto-sleep if link bit is set. Device switches to sleep mode on inactivity." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Automatic sleep disabled."},{"value":"1","value_description":"Automatic sleep enabled when linked inactivity is detected."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 3: `MEASURE` bits 3:3

Locations: `truth registers[17].field_parts[0].bit_field[2]` ↔ `v12_0 registers[17].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "MEASURE" | "Measure" |
| "`field_description`" | "0.0586" | "1.000000" | "0 standby, 1 measurement mode." | "0: Standby mode, 1: Measurement mode." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Standby mode."},{"value":"1","value_description":"Measurement mode."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 4: `SLEEP` bits 2:2

Locations: `truth registers[17].field_parts[0].bit_field[3]` ↔ `v12_0 registers[17].field_parts[0].bit_field[5]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "SLEEP" | "Sleep" |
| "`field_description`" | "0.0586" | "1.000000" | "0 normal, 1 sleep mode." | "0: Normal mode, 1: Sleep mode (suppresses DATA_READY, stops FIFO)." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Normal operation."},{"value":"1","value_description":"Sleep mode."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 5: `WAKEUP` bits 0:1

Locations: `truth registers[17].field_parts[0].bit_field[4]` ↔ `v12_0 registers[17].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "WAKEUP" | "Wakeup" |
| "`field_description`" | "0.0586" | "1.000000" | "Sleep-mode reading frequency." | "Controls sampling rate in sleep mode (see Table 27)." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 2 | 2 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"00","value_description":"8 Hz."},{"value":"01","value_description":"4 Hz."},{"value":"10","value_description":"2 Hz."},{"value":"11","value_description":"1 Hz."}] | [{"value":"00","value_description":"8 Hz"},{"value":"01","value_description":"4 Hz"},{"value":"10","value_description":"2 Hz"},{"value":"11","value_description":"1 Hz"}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 6: `RESERVED` bits 6:7

Locations: `truth registers[17].field_parts[0].bit_field[5]` ↔ `v12_0 registers[17].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RESERVED" | MISSING |
| "`field_description`" | "0.0586" | "0.000000" | "Reserved bits." | MISSING |
| "`bit_start`" | "0.2594" | "0.000000" | 6 | MISSING |
| "`bit_end`" | "0.2594" | "0.000000" | 7 | MISSING |
| "`bit_width`" | "0.0583" | "0.000000" | 2 | MISSING |
| "`values`" | "0.2097" | "0.000000" | [] | MISSING |
| "`is_reserved`" | "0.0750" | "0.000000" | true | MISSING |
| "`type_write_read`" | "0.0583" | "0.000000" | "" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

`bit_field` correctness = mean(0.710771, 0.731973, 0.710771, 0.710771, 0.920492, 0.000000) = **0.630796**.
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "POWER_CTL" | "POWER_CTL" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Power-saving features control"} | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Power-control bits." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.630796" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.630796)/1.0000=0.815176/1.0000=\mathbf{0.815176}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.815176) = **0.815176**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "POWER_CTL" | "POWER_CTL" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Power-saving features control"}] | [{"hex":"0x2D","decimal":"45","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Controls link, autosleep, measurement, sleep and wakeup behavior." | "Power-saving features control. Link bit serially links activity/inactivity functions. AUTO_SLEEP enables auto-sleep if link is set. Measure bit selects measurement mode (1) or standby (0). Sleep bit enables sleep mode (1) or normal (0). Wakeup bits control sampling rate in sleep mode." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.815176" | "mean(0.815176)" | "mean(0.815176)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "Standby, normal mode" | "" |

\(Q(L_{18})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.815176 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.911493/1.0001=\mathbf{0.911402}\)


## Extracted logical register 19: `INT_ENABLE`

v12_0 location: `registers[18]`; truth association: `truth registers[18]` (`INT_ENABLE`).
Associated physical locations: 0x2E (46).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_ENABLE` at 0x2E (46)

Locations: `truth registers[18].field_parts[0]` ↔ `v12_0 registers[18].field_parts[0]`

Truth bit field 1: `DATA_READY` bits 7:7

Locations: `truth registers[18].field_parts[0].bit_field[0]` ↔ `v12_0 registers[18].field_parts[0].bit_field[0]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "DATA_READY" | "DATA_READY" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable DATA_READY interrupt output." | "1: Enable DATA_READY interrupt." |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 2: `SINGLE_TAP` bits 6:6

Locations: `truth registers[18].field_parts[0].bit_field[1]` ↔ `v12_0 registers[18].field_parts[0].bit_field[1]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "SINGLE_TAP" | "SINGLE_TAP" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable single-tap interrupt." | "1: Enable SINGLE_TAP interrupt." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 3: `DOUBLE_TAP` bits 5:5

Locations: `truth registers[18].field_parts[0].bit_field[2]` ↔ `v12_0 registers[18].field_parts[0].bit_field[2]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "DOUBLE_TAP" | "DOUBLE_TAP" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable double-tap interrupt." | "1: Enable DOUBLE_TAP interrupt." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 4: `ACTIVITY` bits 4:4

Locations: `truth registers[18].field_parts[0].bit_field[3]` ↔ `v12_0 registers[18].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACTIVITY" | "Activity" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable activity interrupt." | "1: Enable Activity interrupt." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 5: `INACTIVITY` bits 3:3

Locations: `truth registers[18].field_parts[0].bit_field[4]` ↔ `v12_0 registers[18].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACTIVITY" | "Inactivity" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable inactivity interrupt." | "1: Enable Inactivity interrupt." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 6: `FREE_FALL` bits 2:2

Locations: `truth registers[18].field_parts[0].bit_field[5]` ↔ `v12_0 registers[18].field_parts[0].bit_field[5]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "FREE_FALL" | "FREE_FALL" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable free-fall interrupt." | "1: Enable FREE_FALL interrupt." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 7: `WATERMARK` bits 1:1

Locations: `truth registers[18].field_parts[0].bit_field[6]` ↔ `v12_0 registers[18].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "WATERMARK" | "Watermark" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable watermark interrupt output." | "1: Enable Watermark interrupt." |
| "`bit_start`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 8: `OVERRUN` bits 0:0

Locations: `truth registers[18].field_parts[0].bit_field[7]` ↔ `v12_0 registers[18].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "OVERRUN" | "Overrun" |
| "`field_description`" | "0.0586" | "1.000000" | "Enable overrun interrupt output." | "1: Enable Overrun interrupt." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Field-part aggregation

`bit_field` correctness = mean(0.731973, 0.731973, 0.731973, 0.710771, 0.710771, 0.731973, 0.710771, 0.710771) = **0.721372**.
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "INT_ENABLE" | "INT_ENABLE" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":"Interrupt enable control"} | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Interrupt enable control." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.721372" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.721372)/1.0000=0.843517/1.0000=\mathbf{0.843517}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.843517) = **0.843517**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "INT_ENABLE" | "INT_ENABLE" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x2E","decimal":"46","bank":"","page":"","description":"Interrupt enable control"}] | [{"hex":"0x2E","decimal":"46","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Enables interrupt generation for the listed functions." | "Interrupt enable control. Setting bits to 1 enables respective functions to generate interrupts. DATA_READY, watermark, and overrun bits enable only the interrupt output (functions always enabled)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.843517" | "mean(0.843517)" | "mean(0.843517)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "All interrupts disabled" | "" |

\(Q(L_{19})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.843517 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.919959/1.0001=\mathbf{0.919867}\)


## Extracted logical register 20: `INT_MAP`

v12_0 location: `registers[19]`; truth association: `truth registers[19]` (`INT_MAP`).
Associated physical locations: 0x2F (47).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_MAP` at 0x2F (47)

Locations: `truth registers[19].field_parts[0]` ↔ `v12_0 registers[19].field_parts[0]`

Truth bit field 1: `DATA_READY` bits 7:7

Locations: `truth registers[19].field_parts[0].bit_field[0]` ↔ `v12_0 registers[19].field_parts[0].bit_field[0]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "DATA_READY" | "DATA_READY" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0: Route to INT1, 1: Route to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 2: `SINGLE_TAP` bits 6:6

Locations: `truth registers[19].field_parts[0].bit_field[1]` ↔ `v12_0 registers[19].field_parts[0].bit_field[1]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "SINGLE_TAP" | "SINGLE_TAP" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0: Route to INT1, 1: Route to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 3: `DOUBLE_TAP` bits 5:5

Locations: `truth registers[19].field_parts[0].bit_field[2]` ↔ `v12_0 registers[19].field_parts[0].bit_field[2]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "DOUBLE_TAP" | "DOUBLE_TAP" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0: Route to INT1, 1: Route to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 4: `ACTIVITY` bits 4:4

Locations: `truth registers[19].field_parts[0].bit_field[3]` ↔ `v12_0 registers[19].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACTIVITY" | "Activity" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0: Route to INT1, 1: Route to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 5: `INACTIVITY` bits 3:3

Locations: `truth registers[19].field_parts[0].bit_field[4]` ↔ `v12_0 registers[19].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACTIVITY" | "Inactivity" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0: Route to INT1, 1: Route to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 6: `FREE_FALL` bits 2:2

Locations: `truth registers[19].field_parts[0].bit_field[5]` ↔ `v12_0 registers[19].field_parts[0].bit_field[5]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "FREE_FALL" | "FREE_FALL" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0: Route to INT1, 1: Route to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 7: `WATERMARK` bits 1:1

Locations: `truth registers[19].field_parts[0].bit_field[6]` ↔ `v12_0 registers[19].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "WATERMARK" | "Watermark" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0: Route to INT1, 1: Route to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 8: `OVERRUN` bits 0:0

Locations: `truth registers[19].field_parts[0].bit_field[7]` ↔ `v12_0 registers[19].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "OVERRUN" | "Overrun" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt pin mapping." | "0: Route to INT1, 1: Route to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Field-part aggregation

`bit_field` correctness = mean(0.731973, 0.731973, 0.731973, 0.710771, 0.710771, 0.731973, 0.710771, 0.710771) = **0.721372**.
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "INT_MAP" | "INT_MAP" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":"Interrupt mapping control"} | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Interrupt mapping." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.721372" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.721372)/1.0000=0.843517/1.0000=\mathbf{0.843517}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.843517) = **0.843517**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "INT_MAP" | "INT_MAP" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x2F","decimal":"47","bank":"","page":"","description":"Interrupt mapping control"}] | [{"hex":"0x2F","decimal":"47","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Maps each interrupt to INT1 or INT2; 0 selects INT1 and 1 selects INT2." | "Interrupt mapping control. Bits set to 0 send interrupts to INT1 pin; bits set to 1 send interrupts to INT2 pin." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.843517" | "mean(0.843517)" | "mean(0.843517)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "All interrupts mapped to INT1" | "" |

\(Q(L_{20})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.843517 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.919959/1.0001=\mathbf{0.919867}\)


## Extracted logical register 21: `INT_SOURCE`

v12_0 location: `registers[20]`; truth association: `truth registers[20]` (`INT_SOURCE`).
Associated physical locations: 0x30 (48).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_SOURCE` at 0x30 (48)

Locations: `truth registers[20].field_parts[0]` ↔ `v12_0 registers[20].field_parts[0]`

Truth bit field 1: `DATA_READY` bits 7:7

Locations: `truth registers[20].field_parts[0].bit_field[0]` ↔ `v12_0 registers[20].field_parts[0].bit_field[0]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "DATA_READY" | "DATA_READY" |
| "`field_description`" | "0.0586" | "1.000000" | "DATA_READY event occurred." | "1: New data available." |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 2: `SINGLE_TAP` bits 6:6

Locations: `truth registers[20].field_parts[0].bit_field[1]` ↔ `v12_0 registers[20].field_parts[0].bit_field[1]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "SINGLE_TAP" | "SINGLE_TAP" |
| "`field_description`" | "0.0586" | "1.000000" | "Single-tap event occurred." | "1: Single tap detected." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 3: `DOUBLE_TAP` bits 5:5

Locations: `truth registers[20].field_parts[0].bit_field[2]` ↔ `v12_0 registers[20].field_parts[0].bit_field[2]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "DOUBLE_TAP" | "DOUBLE_TAP" |
| "`field_description`" | "0.0586" | "1.000000" | "Double-tap event occurred." | "1: Double tap detected." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 4: `ACTIVITY` bits 4:4

Locations: `truth registers[20].field_parts[0].bit_field[3]` ↔ `v12_0 registers[20].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ACTIVITY" | "Activity" |
| "`field_description`" | "0.0586" | "1.000000" | "Activity event occurred." | "1: Activity detected." |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 5: `INACTIVITY` bits 3:3

Locations: `truth registers[20].field_parts[0].bit_field[4]` ↔ `v12_0 registers[20].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "INACTIVITY" | "Inactivity" |
| "`field_description`" | "0.0586" | "1.000000" | "Inactivity event occurred." | "1: Inactivity detected." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 6: `FREE_FALL` bits 2:2

Locations: `truth registers[20].field_parts[0].bit_field[5]` ↔ `v12_0 registers[20].field_parts[0].bit_field[5]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "FREE_FALL" | "FREE_FALL" |
| "`field_description`" | "0.0586" | "1.000000" | "Free-fall event occurred." | "1: Free-fall detected." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 7: `WATERMARK` bits 1:1

Locations: `truth registers[20].field_parts[0].bit_field[6]` ↔ `v12_0 registers[20].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "WATERMARK" | "Watermark" |
| "`field_description`" | "0.0586" | "1.000000" | "FIFO watermark event occurred." | "1: FIFO watermark reached." |
| "`bit_start`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 8: `OVERRUN` bits 0:0

Locations: `truth registers[20].field_parts[0].bit_field[7]` ↔ `v12_0 registers[20].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "OVERRUN" | "Overrun" |
| "`field_description`" | "0.0586" | "1.000000" | "FIFO overrun event occurred." | "1: Data overrun occurred." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Field-part aggregation

`bit_field` correctness = mean(0.731973, 0.731973, 0.731973, 0.710771, 0.710771, 0.731973, 0.710771, 0.710771) = **0.721372**.
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "INT_SOURCE" | "INT_SOURCE" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x30","decimal":"48","bank":"","page":"","description":"Source of interrupts"} | {"hex":"0x30","decimal":"48","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Interrupt source status." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.721372" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.721372)/1.0000=0.843517/1.0000=\mathbf{0.843517}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.843517) = **0.843517**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "INT_SOURCE" | "INT_SOURCE" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x30","decimal":"48","bank":"","page":"","description":"Source of interrupts"}] | [{"hex":"0x30","decimal":"48","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Reports which interrupt functions have triggered; event bits are cleared by reading this register or data registers as specified." | "Source of interrupts. Bits set to 1 indicate triggered events. DATA_READY, watermark, and overrun bits are always set if events occur (cleared by reading DATAX/DATAY/DATAZ). Other bits cleared by reading INT_SOURCE." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.843517" | "mean(0.843517)" | "mean(0.843517)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000010" | "00000010" |
| "`default_value_description`" | "0.0334" | "0.000000" | "Watermark status bit set in reset value per register map" | "" |

\(Q(L_{21})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.843517 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.919959/1.0001=\mathbf{0.919867}\)


## Extracted logical register 22: `DATA_FORMAT`

v12_0 location: `registers[21]`; truth association: `truth registers[21]` (`DATA_FORMAT`).
Associated physical locations: 0x31 (49).

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATA_FORMAT` at 0x31 (49)

Locations: `truth registers[21].field_parts[0]` ↔ `v12_0 registers[21].field_parts[0]`

Truth bit field 1: `SELF_TEST` bits 7:7

Locations: `truth registers[21].field_parts[0].bit_field[0]` ↔ `v12_0 registers[21].field_parts[0].bit_field[0]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "SELF_TEST" | "SELF_TEST" |
| "`field_description`" | "0.0586" | "1.000000" | "Applies self-test force when set." | "1: Apply self-test force to sensor." |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Self-test force disabled."},{"value":"1","value_description":"Self-test force enabled."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 2: `SPI` bits 6:6

Locations: `truth registers[21].field_parts[0].bit_field[1]` ↔ `v12_0 registers[21].field_parts[0].bit_field[1]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "SPI" | "SPI" |
| "`field_description`" | "0.0586" | "1.000000" | "SPI mode selection: 0 four-wire, 1 three-wire." | "0: 4-wire SPI, 1: 3-wire SPI." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Four-wire SPI mode."},{"value":"1","value_description":"Three-wire SPI mode."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 3: `INT_INVERT` bits 5:5

Locations: `truth registers[21].field_parts[0].bit_field[2]` ↔ `v12_0 registers[21].field_parts[0].bit_field[2]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "INT_INVERT" | "INT_INVERT" |
| "`field_description`" | "0.0586" | "1.000000" | "Interrupt polarity: 0 active high, 1 active low." | "0: Interrupts active high, 1: Interrupts active low." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Active-high interrupts."},{"value":"1","value_description":"Active-low interrupts."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 4: `FULL_RES` bits 3:3

Locations: `truth registers[21].field_parts[0].bit_field[3]` ↔ `v12_0 registers[21].field_parts[0].bit_field[4]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "FULL_RES" | "FULL_RES" |
| "`field_description`" | "0.0586" | "1.000000" | "Full-resolution mode selection." | "0: 10-bit mode, 1: Full resolution mode (4 mg/LSB scale factor)." |
| "`bit_start`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_end`" | "0.2594" | "1.000000" | 3 | 3 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"10-bit mode."},{"value":"1","value_description":"Full-resolution mode."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 5: `JUSTIFY` bits 2:2

Locations: `truth registers[21].field_parts[0].bit_field[4]` ↔ `v12_0 registers[21].field_parts[0].bit_field[5]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "JUSTIFY" | "Justify" |
| "`field_description`" | "0.0586" | "1.000000" | "Data justification: 0 right-justified with sign extension, 1 left-justified." | "0: Right-justified with sign extension, 1: Left-justified (MSB)." |
| "`bit_start`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_end`" | "0.2594" | "1.000000" | 2 | 2 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Right-justified with sign extension."},{"value":"1","value_description":"Left-justified."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 6: `RANGE` bits 0:1

Locations: `truth registers[21].field_parts[0].bit_field[5]` ↔ `v12_0 registers[21].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RANGE" | "Range" |
| "`field_description`" | "0.0586" | "1.000000" | "Measurement range selection." | "Sets the g range (see Table 35)." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 1 | 1 |
| "`bit_width`" | "0.0583" | "1.000000" | 2 | 2 |
| "`values`" | "0.2097" | "1.000000" | [{"value":"00","value_description":"+/-2 g."},{"value":"01","value_description":"+/-4 g."},{"value":"10","value_description":"+/-8 g."},{"value":"11","value_description":"+/-16 g."}] | [{"value":"00","value_description":"±2 g"},{"value":"01","value_description":"±4 g"},{"value":"10","value_description":"±8 g"},{"value":"11","value_description":"±16 g"}] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 7: `RESERVED` bits 4:4

Locations: `truth registers[21].field_parts[0].bit_field[6]` ↔ `v12_0 registers[21].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RESERVED" | "D4" |
| "`field_description`" | "0.0586" | "1.000000" | "Reserved bit." | "Reserved" |
| "`bit_start`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | true | true |
| "`type_write_read`" | "0.0583" | "1.000000" | "" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

`bit_field` correctness = mean(0.731973, 0.731973, 0.731973, 0.731973, 0.710771, 0.920492, 0.978798) = **0.791136**.
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATA_FORMAT" | "DATA_FORMAT" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x31","decimal":"49","bank":"","page":"","description":"Data format control"} | {"hex":"0x31","decimal":"49","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "Data format control." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.791136" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.791136)/1.0000=0.865347/1.0000=\mathbf{0.865347}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.865347) = **0.865347**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATA_FORMAT" | "DATA_FORMAT" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x31","decimal":"49","bank":"","page":"","description":"Data format control"}] | [{"hex":"0x31","decimal":"49","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Controls the presentation of output data." | "Data format control. SELF_TEST applies self-test force. SPI selects 3-wire (1) or 4-wire (0) mode. INT_INVERT inverts interrupt polarity (1: active low). FULL_RES enables full resolution mode (1) or 10-bit mode (0). Justify selects left-justified (1) or right-justified (0) mode. Range bits set g range." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.865347" | "mean(0.865347)" | "mean(0.865347)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "10-bit, +/-2 g, right-justified, four-wire SPI, active-high interrupts" | "" |

\(Q(L_{22})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.865347 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.926479/1.0001=\mathbf{0.926386}\)


## Extracted logical register 23: `DATAX0`

v12_0 location: `registers[22]`; truth association: `truth registers[22]` (`DATAX`).
Associated physical locations: 0x32 (50).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATAX0` at 0x32 (50)

Locations: `truth registers[22].field_parts[0]` ↔ `v12_0 registers[22].field_parts[0]`

Truth bit field 1: `DATAX0` bits 0:7

Locations: `truth registers[22].field_parts[0].bit_field[0]` ↔ `v12_0 registers[22].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATAX0" | "DATAX0" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x32","decimal":"50","bank":"","page":"","description":"X-Axis Data 0"} | {"hex":"0x32","decimal":"50","bank":"","page":"","description":"X-Axis Data LSB"} |
| "`description`" | "0.0693" | "1.000000" | "Least significant byte of X-axis output data." | "LSB of X-axis data." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATAX0" | "DATAX0" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x32","decimal":"50","bank":"","page":"","description":"X-Axis Data 0"}] | [{"hex":"0x32","decimal":"50","bank":"","page":"","description":"X-Axis Data LSB"}] |
| "`register_description`" | "0.0564" | "1.000000" | "DATAX0 and DATAX1 hold the 16-bit two's-complement X-axis output data; DATAX0 is the least significant byte and DATAX1 is the most significant byte." | "X-axis data (LSB). Part of 16-bit two's complement output for X-axis. DATAX1 contains MSB." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "0000000000000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{23})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 24: `DATAX1`

v12_0 location: `registers[23]`; truth association: `truth registers[22]` (`DATAX`).
Associated physical locations: 0x33 (51).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part.

### Bottom layer: bit fields, then field parts

#### Field part 2: `DATAX1` at 0x33 (51)

Locations: `truth registers[22].field_parts[1]` ↔ `v12_0 registers[23].field_parts[0]`

Truth bit field 1: `DATAX1` bits 0:7

Locations: `truth registers[22].field_parts[1].bit_field[0]` ↔ `v12_0 registers[23].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATAX1" | "DATAX1" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x33","decimal":"51","bank":"","page":"","description":"X-Axis Data 1"} | {"hex":"0x33","decimal":"51","bank":"","page":"","description":"X-Axis Data MSB"} |
| "`description`" | "0.0693" | "1.000000" | "Most significant byte of X-axis output data." | "MSB of X-axis data." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATAX1" | "DATAX1" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x33","decimal":"51","bank":"","page":"","description":"X-Axis Data 1"}] | [{"hex":"0x33","decimal":"51","bank":"","page":"","description":"X-Axis Data MSB"}] |
| "`register_description`" | "0.0564" | "1.000000" | "DATAX0 and DATAX1 hold the 16-bit two's-complement X-axis output data; DATAX0 is the least significant byte and DATAX1 is the most significant byte." | "X-axis data (MSB). Part of 16-bit two's complement output for X-axis. DATAX0 contains LSB." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "0000000000000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{24})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 25: `DATAY0`

v12_0 location: `registers[24]`; truth association: `truth registers[23]` (`DATAY`).
Associated physical locations: 0x34 (52).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATAY0` at 0x34 (52)

Locations: `truth registers[23].field_parts[0]` ↔ `v12_0 registers[24].field_parts[0]`

Truth bit field 1: `DATAY0` bits 0:7

Locations: `truth registers[23].field_parts[0].bit_field[0]` ↔ `v12_0 registers[24].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATAY0" | "DATAY0" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x34","decimal":"52","bank":"","page":"","description":"Y-Axis Data 0"} | {"hex":"0x34","decimal":"52","bank":"","page":"","description":"Y-Axis Data LSB"} |
| "`description`" | "0.0693" | "1.000000" | "Least significant byte of Y-axis output data." | "LSB of Y-axis data." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATAY0" | "DATAY0" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x34","decimal":"52","bank":"","page":"","description":"Y-Axis Data 0"}] | [{"hex":"0x34","decimal":"52","bank":"","page":"","description":"Y-Axis Data LSB"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement Y-axis output data; DATAY0 is least significant and DATAY1 most significant." | "Y-axis data (LSB). Part of 16-bit two's complement output for Y-axis. DATAY1 contains MSB." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "0000000000000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{25})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 26: `DATAY1`

v12_0 location: `registers[25]`; truth association: `truth registers[23]` (`DATAY`).
Associated physical locations: 0x35 (53).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part.

### Bottom layer: bit fields, then field parts

#### Field part 2: `DATAY1` at 0x35 (53)

Locations: `truth registers[23].field_parts[1]` ↔ `v12_0 registers[25].field_parts[0]`

Truth bit field 1: `DATAY1` bits 0:7

Locations: `truth registers[23].field_parts[1].bit_field[0]` ↔ `v12_0 registers[25].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATAY1" | "DATAY1" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x35","decimal":"53","bank":"","page":"","description":"Y-Axis Data 1"} | {"hex":"0x35","decimal":"53","bank":"","page":"","description":"Y-Axis Data MSB"} |
| "`description`" | "0.0693" | "1.000000" | "Most significant byte of Y-axis output data." | "MSB of Y-axis data." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATAY1" | "DATAY1" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x35","decimal":"53","bank":"","page":"","description":"Y-Axis Data 1"}] | [{"hex":"0x35","decimal":"53","bank":"","page":"","description":"Y-Axis Data MSB"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement Y-axis output data; DATAY0 is least significant and DATAY1 most significant." | "Y-axis data (MSB). Part of 16-bit two's complement output for Y-axis. DATAY0 contains LSB." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "0000000000000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{26})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 27: `DATAZ0`

v12_0 location: `registers[26]`; truth association: `truth registers[24]` (`DATAZ`).
Associated physical locations: 0x36 (54).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATAZ0` at 0x36 (54)

Locations: `truth registers[24].field_parts[0]` ↔ `v12_0 registers[26].field_parts[0]`

Truth bit field 1: `DATAZ0` bits 0:7

Locations: `truth registers[24].field_parts[0].bit_field[0]` ↔ `v12_0 registers[26].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATAZ0" | "DATAZ0" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x36","decimal":"54","bank":"","page":"","description":"Z-Axis Data 0"} | {"hex":"0x36","decimal":"54","bank":"","page":"","description":"Z-Axis Data LSB"} |
| "`description`" | "0.0693" | "1.000000" | "Least significant byte of Z-axis output data." | "LSB of Z-axis data." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATAZ0" | "DATAZ0" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":"Z-Axis Data 0"}] | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":"Z-Axis Data LSB"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement Z-axis output data; DATAZ0 is least significant and DATAZ1 most significant." | "Z-axis data (LSB). Part of 16-bit two's complement output for Z-axis. DATAZ1 contains MSB." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "0000000000000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{27})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 28: `DATAZ1`

v12_0 location: `registers[27]`; truth association: `truth registers[24]` (`DATAZ`).
Associated physical locations: 0x37 (55).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part.

### Bottom layer: bit fields, then field parts

#### Field part 2: `DATAZ1` at 0x37 (55)

Locations: `truth registers[24].field_parts[1]` ↔ `v12_0 registers[27].field_parts[0]`

Truth bit field 1: `DATAZ1` bits 0:7

Locations: `truth registers[24].field_parts[1].bit_field[0]` ↔ `v12_0 registers[27].field_parts[0].bit_field: missing`.
Judgment: no exact candidate bit range; all primitive fields score 0.

| Scored field | Weight | C | Truth content | v12_0 content |
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
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "DATAZ1" | "DATAZ1" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x37","decimal":"55","bank":"","page":"","description":"Z-Axis Data 1"} | {"hex":"0x37","decimal":"55","bank":"","page":"","description":"Z-Axis Data MSB"} |
| "`description`" | "0.0693" | "1.000000" | "Most significant byte of Z-axis output data." | "MSB of Z-axis data." |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.000000" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "DATAZ1" | "DATAZ1" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":"Z-Axis Data 1"}] | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":"Z-Axis Data MSB"}] |
| "`register_description`" | "0.0564" | "1.000000" | "Two's-complement Z-axis output data; DATAZ0 is least significant and DATAZ1 most significant." | "Z-axis data (MSB). Part of 16-bit two's complement output for Z-axis. DATAZ0 contains LSB." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.687100" | "mean(0.687100)" | "mean(0.687100)" |
| "`default_value`" | "0.0667" | "1.000000" | "0000000000000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "0" | "" |

\(Q(L_{28})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.873237/1.0001=\mathbf{0.873149}\)


## Extracted logical register 29: `FIFO_CTL`

v12_0 location: `registers[28]`; truth association: `truth registers[25]` (`FIFO_CTL`).
Associated physical locations: 0x38 (56).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_CTL` at 0x38 (56)

Locations: `truth registers[25].field_parts[0]` ↔ `v12_0 registers[28].field_parts[0]`

Truth bit field 1: `FIFO_MODE` bits 6:7

Locations: `truth registers[25].field_parts[0].bit_field[0]` ↔ `v12_0 registers[28].field_parts[0].bit_field[0]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "FIFO_MODE" | "FIFO_MODE" |
| "`field_description`" | "0.0586" | "1.000000" | "FIFO operating mode." | "Selects FIFO mode (see Table 37)." |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 2 | 2 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"00","value_description":"Bypass."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Trigger mode."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 2: `TRIGGER` bits 5:5

Locations: `truth registers[25].field_parts[0].bit_field[1]` ↔ `v12_0 registers[28].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter, values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "TRIGGER" | "Trigger" |
| "`field_description`" | "0.0586" | "1.000000" | "Trigger interrupt pin selection: 0 INT1, 1 INT2." | "0: Link trigger to INT1, 1: Link trigger to INT2." |
| "`bit_start`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"Trigger event linked to INT1."},{"value":"1","value_description":"Trigger event linked to INT2."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.710700/0.9999=\mathbf{0.710771}\)

Truth bit field 3: `SAMPLES` bits 0:4

Locations: `truth registers[25].field_parts[0].bit_field[2]` ↔ `v12_0 registers[28].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "SAMPLES" | "Samples" |
| "`field_description`" | "0.0586" | "1.000000" | "Number of FIFO entries for watermark or pre-trigger samples; zero immediately sets watermark." | "Function depends on FIFO mode (see Table 38)." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 4 | 4 |
| "`bit_width`" | "0.0583" | "1.000000" | 5 | 5 |
| "`values`" | "0.2097" | "1.000000" | [] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "RW" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Field-part aggregation

`bit_field` correctness = mean(0.731973, 0.710771, 0.920492) = **0.787745**.
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "FIFO_CTL" | "FIFO_CTL" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x38","decimal":"56","bank":"","page":"","description":"FIFO control"} | {"hex":"0x38","decimal":"56","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "FIFO control." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "RW" | "RW" |
| "`bit_field`" | "0.3129" | "0.787745" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.787745)/1.0000=0.864286/1.0000=\mathbf{0.864286}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.864286) = **0.864286**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "FIFO_CTL" | "FIFO_CTL" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x38","decimal":"56","bank":"","page":"","description":"FIFO control"}] | [{"hex":"0x38","decimal":"56","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Controls FIFO mode, trigger interrupt pin and watermark sample count." | "FIFO control. FIFO_MODE bits select mode (bypass, FIFO, stream, trigger). Trigger bit links trigger event to INT1/INT2. Samples bits set watermark level or retention count." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "RW" | "RW" |
| "`field_parts`" | "0.2987" | "0.864286" | "mean(0.864286)" | "mean(0.864286)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "Bypass mode, trigger INT1, zero samples; zero samples immediately sets WATERMARK and may cause undesirable trigger-mode operation." | "" |

\(Q(L_{29})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.864286 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.926162/1.0001=\mathbf{0.926069}\)


## Extracted logical register 30: `FIFO_STATUS`

v12_0 location: `registers[29]`; truth association: `truth registers[26]` (`FIFO_STATUS`).
Associated physical locations: 0x39 (57).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_STATUS` at 0x39 (57)

Locations: `truth registers[26].field_parts[0]` ↔ `v12_0 registers[29].field_parts[0]`

Truth bit field 1: `FIFO_TRIG` bits 7:7

Locations: `truth registers[26].field_parts[0].bit_field[0]` ↔ `v12_0 registers[29].field_parts[0].bit_field[0]`.
Judgment: deductions: values, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "1.000000" | "FIFO_TRIG" | "FIFO_TRIG" |
| "`field_description`" | "0.0586" | "1.000000" | "Indicates that a FIFO trigger event occurred." | "1: Trigger event occurred." |
| "`bit_start`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_end`" | "0.2594" | "1.000000" | 7 | 7 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "0.000000" | [{"value":"0","value_description":"No FIFO trigger event."},{"value":"1","value_description":"FIFO trigger event occurred."}] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.731900/0.9999=\mathbf{0.731973}\)

Truth bit field 2: `ENTRIES` bits 0:5

Locations: `truth registers[26].field_parts[0].bit_field[1]` ↔ `v12_0 registers[29].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, type_write_read.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "ENTRIES" | "Entries" |
| "`field_description`" | "0.0586" | "1.000000" | "Number of data values stored in FIFO." | "Number of data values stored in FIFO (0-32)." |
| "`bit_start`" | "0.2594" | "1.000000" | 0 | 0 |
| "`bit_end`" | "0.2594" | "1.000000" | 5 | 5 |
| "`bit_width`" | "0.0583" | "1.000000" | 6 | 6 |
| "`values`" | "0.2097" | "1.000000" | [] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | false | false |
| "`type_write_read`" | "0.0583" | "0.000000" | "R" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.920400/0.9999=\mathbf{0.920492}\)

Truth bit field 3: `RESERVED` bits 6:6

Locations: `truth registers[26].field_parts[0].bit_field[2]` ↔ `v12_0 registers[29].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`name_or_parameter`" | "0.0212" | "0.000000" | "RESERVED" | "D6" |
| "`field_description`" | "0.0586" | "1.000000" | "Reserved bits." | "Reserved" |
| "`bit_start`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_end`" | "0.2594" | "1.000000" | 6 | 6 |
| "`bit_width`" | "0.0583" | "1.000000" | 1 | 1 |
| "`values`" | "0.2097" | "1.000000" | [] | [] |
| "`is_reserved`" | "0.0750" | "1.000000" | true | true |
| "`type_write_read`" | "0.0583" | "1.000000" | "" | "" |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

`bit_field` correctness = mean(0.731973, 0.920492, 0.978798) = **0.877088**.
| Field-part field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| "`register_name`" | "0.0280" | "1.000000" | "FIFO_STATUS" | "FIFO_STATUS" |
| "`physical_address`" | "0.4688" | "1.000000" | {"hex":"0x39","decimal":"57","bank":"","page":"","description":"FIFO status"} | {"hex":"0x39","decimal":"57","bank":"","page":"","description":""} |
| "`description`" | "0.0693" | "0.000000" | "FIFO status." | "" |
| "`width_bits`" | "0.0605" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0605" | "1.000000" | "R" | "R" |
| "`bit_field`" | "0.3129" | "0.877088" | "truth bit-field set" | "extracted bit-field set" |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.877088)/1.0000=0.892241/1.0000=\mathbf{0.892241}\)

Extracted logical-register aggregation

`field_parts` correctness = mean(0.892241) = **0.892241**.
Direct judgment: deductions: field_parts, default_value_description.
| Logical-register field | Weight | C | Truth target | v12_0 content |
|---|---:|---:|---|---|
| "`name`" | "0.0225" | "1.000000" | "FIFO_STATUS" | "FIFO_STATUS" |
| "`physical_address`" | "0.4044" | "1.000000" | [{"hex":"0x39","decimal":"57","bank":"","page":"","description":"FIFO status"}] | [{"hex":"0x39","decimal":"57","bank":"","page":"","description":""}] |
| "`register_description`" | "0.0564" | "1.000000" | "Reports FIFO trigger status and the number of stored data values." | "FIFO status. FIFO_TRIG bit indicates trigger event occurred (1) or not (0). Entries bits report number of data values stored in FIFO (max 32)." |
| "`width_bits`" | "0.0590" | "1.000000" | 8 | 8 |
| "`type_write_read`" | "0.0590" | "1.000000" | "R" | "R" |
| "`field_parts`" | "0.2987" | "0.892241" | "mean(0.892241)" | "mean(0.892241)" |
| "`default_value`" | "0.0667" | "1.000000" | "00000000" | "00000000" |
| "`default_value_description`" | "0.0334" | "0.000000" | "No trigger; zero entries" | "" |

\(Q(L_{30})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.892241 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.934512/1.0001=\mathbf{0.934419}\)


## 3. Detailed deduction inventory

Every scored deduction and recursive aggregate deduction retains exact truth and extracted JSON locations.

| # | Exact truth ↔ extracted location | Scored field | C | Truth content | v12_0 content | Specific error or omission |
|---:|---|---|---:|---|---|---|
| 1 | "truth registers[0].field_parts[0]" | `description` | 0.000000 | "Fixed device ID register." | "" | "description missing or not sufficiently supported" |
| 2 | "truth registers[0].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "DEVID" | MISSING | "field is missing" |
| 3 | "truth registers[0].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Device identification code." | MISSING | "description missing or not sufficiently supported" |
| 4 | "truth registers[0].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 5 | "truth registers[0].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 6 | "truth registers[0].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 7 | "truth registers[0].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0xE5","value_description":"ADXL345 device ID."}] | MISSING | "values field missing" |
| 8 | "truth registers[0].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 9 | "truth registers[0].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "R" | MISSING | "field is missing" |
| 10 | "truth registers[0].field_parts[0] ↔ v12_0 registers[0].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 11 | "truth registers[0] ↔ v12_0 registers[0]" | `field_parts` | 0.617800 | "mean(0.617800)" | "mean(0.617800)" | "recursive mean of field-part scores" |
| 12 | "truth registers[0].default_value_description ↔ v12_0 registers[0].default_value_description" | `default_value_description` | 0.000000 | "0xE5" | "" | "description missing or not sufficiently supported" |
| 13 | "truth registers[1].field_parts[0]" | `description` | 0.000000 | "Tap threshold." | "" | "description missing or not sufficiently supported" |
| 14 | "truth registers[1].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "THRESH_TAP" | MISSING | "field is missing" |
| 15 | "truth registers[1].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned tap threshold, 62.5 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 16 | "truth registers[1].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 17 | "truth registers[1].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 18 | "truth registers[1].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 19 | "truth registers[1].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 20 | "truth registers[1].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 21 | "truth registers[1].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 22 | "truth registers[1].field_parts[0] ↔ v12_0 registers[1].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 23 | "truth registers[1] ↔ v12_0 registers[1]" | `field_parts` | 0.617800 | "mean(0.617800)" | "mean(0.617800)" | "recursive mean of field-part scores" |
| 24 | "truth registers[1].default_value_description ↔ v12_0 registers[1].default_value_description" | `default_value_description` | 0.000000 | "0 may result in undesirable behavior if tap interrupts are enabled." | "" | "description missing or not sufficiently supported" |
| 25 | "truth registers[2].field_parts[0]" | `description` | 0.000000 | "X-axis offset adjustment." | "" | "description missing or not sufficiently supported" |
| 26 | "truth registers[2].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "OFSX" | MISSING | "field is missing" |
| 27 | "truth registers[2].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Two's-complement X-axis offset, 15.6 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 28 | "truth registers[2].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 29 | "truth registers[2].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 30 | "truth registers[2].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 31 | "truth registers[2].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 32 | "truth registers[2].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 33 | "truth registers[2].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 34 | "truth registers[2].field_parts[0] ↔ v12_0 registers[2].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 35 | "truth registers[2] ↔ v12_0 registers[2]" | `field_parts` | 0.617800 | "mean(0.617800)" | "mean(0.617800)" | "recursive mean of field-part scores" |
| 36 | "truth registers[2].default_value_description ↔ v12_0 registers[2].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 37 | "truth registers[3].field_parts[0]" | `description` | 0.000000 | "Y-axis offset adjustment." | "" | "description missing or not sufficiently supported" |
| 38 | "truth registers[3].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "OFSY" | MISSING | "field is missing" |
| 39 | "truth registers[3].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Two's-complement Y-axis offset, 15.6 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 40 | "truth registers[3].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 41 | "truth registers[3].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 42 | "truth registers[3].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 43 | "truth registers[3].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 44 | "truth registers[3].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 45 | "truth registers[3].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 46 | "truth registers[3].field_parts[0] ↔ v12_0 registers[3].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 47 | "truth registers[3] ↔ v12_0 registers[3]" | `field_parts` | 0.617800 | "mean(0.617800)" | "mean(0.617800)" | "recursive mean of field-part scores" |
| 48 | "truth registers[3].default_value_description ↔ v12_0 registers[3].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 49 | "truth registers[4].field_parts[0]" | `description` | 0.000000 | "Z-axis offset adjustment." | "" | "description missing or not sufficiently supported" |
| 50 | "truth registers[4].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "OFSZ" | MISSING | "field is missing" |
| 51 | "truth registers[4].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Two's-complement Z-axis offset, 15.6 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 52 | "truth registers[4].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 53 | "truth registers[4].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 54 | "truth registers[4].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 55 | "truth registers[4].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 56 | "truth registers[4].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 57 | "truth registers[4].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 58 | "truth registers[4].field_parts[0] ↔ v12_0 registers[4].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 59 | "truth registers[4] ↔ v12_0 registers[4]" | `field_parts` | 0.617800 | "mean(0.617800)" | "mean(0.617800)" | "recursive mean of field-part scores" |
| 60 | "truth registers[4].default_value_description ↔ v12_0 registers[4].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 61 | "truth registers[5].field_parts[0]" | `description` | 0.000000 | "Maximum tap duration." | "" | "description missing or not sufficiently supported" |
| 62 | "truth registers[5].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "DUR" | MISSING | "field is missing" |
| 63 | "truth registers[5].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned tap duration, 625 us/LSB." | MISSING | "description missing or not sufficiently supported" |
| 64 | "truth registers[5].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 65 | "truth registers[5].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 66 | "truth registers[5].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 67 | "truth registers[5].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 68 | "truth registers[5].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 69 | "truth registers[5].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 70 | "truth registers[5].field_parts[0] ↔ v12_0 registers[5].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 71 | "truth registers[5] ↔ v12_0 registers[5]" | `field_parts` | 0.617800 | "mean(0.617800)" | "mean(0.617800)" | "recursive mean of field-part scores" |
| 72 | "truth registers[5].default_value_description ↔ v12_0 registers[5].default_value_description" | `default_value_description` | 0.000000 | "0 disables the single-tap and double-tap functions." | "" | "description missing or not sufficiently supported" |
| 73 | "truth registers[6].field_parts[0]" | `description` | 0.000000 | "Tap latency." | "" | "description missing or not sufficiently supported" |
| 74 | "truth registers[6].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "Latent" | MISSING | "field is missing" |
| 75 | "truth registers[6].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned tap latency, 1.25 ms/LSB." | MISSING | "description missing or not sufficiently supported" |
| 76 | "truth registers[6].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 77 | "truth registers[6].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 78 | "truth registers[6].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 79 | "truth registers[6].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 80 | "truth registers[6].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 81 | "truth registers[6].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 82 | "truth registers[6].field_parts[0] ↔ v12_0 registers[6].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 83 | "truth registers[6] ↔ v12_0 registers[6]" | `field_parts` | 0.617800 | "mean(0.617800)" | "mean(0.617800)" | "recursive mean of field-part scores" |
| 84 | "truth registers[6].default_value_description ↔ v12_0 registers[6].default_value_description" | `default_value_description` | 0.000000 | "0 disables the double-tap function." | "" | "description missing or not sufficiently supported" |
| 85 | "truth registers[7].field_parts[0]" | `description` | 0.000000 | "Tap window." | "" | "description missing or not sufficiently supported" |
| 86 | "truth registers[7].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "Window" | MISSING | "field is missing" |
| 87 | "truth registers[7].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned tap window, 1.25 ms/LSB." | MISSING | "description missing or not sufficiently supported" |
| 88 | "truth registers[7].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 89 | "truth registers[7].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 90 | "truth registers[7].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 91 | "truth registers[7].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 92 | "truth registers[7].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 93 | "truth registers[7].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 94 | "truth registers[7].field_parts[0] ↔ v12_0 registers[7].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 95 | "truth registers[7] ↔ v12_0 registers[7]" | `field_parts` | 0.617800 | "mean(0.617800)" | "mean(0.617800)" | "recursive mean of field-part scores" |
| 96 | "truth registers[7].default_value_description ↔ v12_0 registers[7].default_value_description" | `default_value_description` | 0.000000 | "0 disables the double-tap function." | "" | "description missing or not sufficiently supported" |
| 97 | "truth registers[8].field_parts[0]" | `description` | 0.000000 | "Activity threshold." | "" | "description missing or not sufficiently supported" |
| 98 | "truth registers[8].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "THRESH_ACT" | MISSING | "field is missing" |
| 99 | "truth registers[8].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned activity threshold, 62.5 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 100 | "truth registers[8].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 101 | "truth registers[8].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 102 | "truth registers[8].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 103 | "truth registers[8].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 104 | "truth registers[8].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 105 | "truth registers[8].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 106 | "truth registers[8].field_parts[0] ↔ v12_0 registers[8].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 107 | "truth registers[8] ↔ v12_0 registers[8]" | `field_parts` | 0.617800 | "mean(0.617800)" | "mean(0.617800)" | "recursive mean of field-part scores" |
| 108 | "truth registers[8].default_value_description ↔ v12_0 registers[8].default_value_description" | `default_value_description` | 0.000000 | "0 may result in undesirable behavior if the activity interrupt is enabled." | "" | "description missing or not sufficiently supported" |
| 109 | "truth registers[9].field_parts[0]" | `description` | 0.000000 | "Inactivity threshold." | "" | "description missing or not sufficiently supported" |
| 110 | "truth registers[9].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "THRESH_INACT" | MISSING | "field is missing" |
| 111 | "truth registers[9].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned inactivity threshold, 62.5 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 112 | "truth registers[9].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 113 | "truth registers[9].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 114 | "truth registers[9].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 115 | "truth registers[9].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 116 | "truth registers[9].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 117 | "truth registers[9].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 118 | "truth registers[9].field_parts[0] ↔ v12_0 registers[9].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 119 | "truth registers[9] ↔ v12_0 registers[9]" | `field_parts` | 0.617800 | "mean(0.617800)" | "mean(0.617800)" | "recursive mean of field-part scores" |
| 120 | "truth registers[9].default_value_description ↔ v12_0 registers[9].default_value_description" | `default_value_description` | 0.000000 | "0 may result in undesirable behavior if the inactivity interrupt is enabled." | "" | "description missing or not sufficiently supported" |
| 121 | "truth registers[10].field_parts[0]" | `description` | 0.000000 | "Inactivity time." | "" | "description missing or not sufficiently supported" |
| 122 | "truth registers[10].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "TIME_INACT" | MISSING | "field is missing" |
| 123 | "truth registers[10].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned inactivity time, 1 s/LSB." | MISSING | "description missing or not sufficiently supported" |
| 124 | "truth registers[10].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 125 | "truth registers[10].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 126 | "truth registers[10].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 127 | "truth registers[10].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 128 | "truth registers[10].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 129 | "truth registers[10].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 130 | "truth registers[10].field_parts[0] ↔ v12_0 registers[10].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 131 | "truth registers[10] ↔ v12_0 registers[10]" | `field_parts` | 0.617800 | "mean(0.617800)" | "mean(0.617800)" | "recursive mean of field-part scores" |
| 132 | "truth registers[10].default_value_description ↔ v12_0 registers[10].default_value_description" | `default_value_description` | 0.000000 | "0 results in an interrupt when acceleration is below THRESH_INACT." | "" | "description missing or not sufficiently supported" |
| 133 | "truth registers[11].field_parts[0]" | `description` | 0.000000 | "Activity/inactivity axis control." | "" | "description missing or not sufficiently supported" |
| 134 | "truth registers[11].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "ACT_ACDC" | "ACT ac/dc" | "strict fact mismatch; truth=\"ACT_ACDC\" candidate=\"ACT ac/dc\"" |
| 135 | "truth registers[11].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"DC-coupled activity detection."},{"value":"1","value_description":"AC-coupled activity detection."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 136 | "truth registers[11].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 137 | "truth registers[11].field_parts[0].bit_field[1]" | `name_or_parameter` | 0.000000 | "ACT_X_ENABLE" | "ACT_X enable" | "strict fact mismatch; truth=\"ACT_X_ENABLE\" candidate=\"ACT_X enable\"" |
| 138 | "truth registers[11].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 139 | "truth registers[11].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 140 | "truth registers[11].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "ACT_Y_ENABLE" | "ACT_Y enable" | "strict fact mismatch; truth=\"ACT_Y_ENABLE\" candidate=\"ACT_Y enable\"" |
| 141 | "truth registers[11].field_parts[0].bit_field[2]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 142 | "truth registers[11].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 143 | "truth registers[11].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "ACT_Z_ENABLE" | "ACT_Z enable" | "strict fact mismatch; truth=\"ACT_Z_ENABLE\" candidate=\"ACT_Z enable\"" |
| 144 | "truth registers[11].field_parts[0].bit_field[3]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 145 | "truth registers[11].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 146 | "truth registers[11].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "INACT_ACDC" | "INACT ac/dc" | "strict fact mismatch; truth=\"INACT_ACDC\" candidate=\"INACT ac/dc\"" |
| 147 | "truth registers[11].field_parts[0].bit_field[4]" | `values` | 0.000000 | [{"value":"0","value_description":"DC-coupled inactivity detection."},{"value":"1","value_description":"AC-coupled inactivity detection."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 148 | "truth registers[11].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 149 | "truth registers[11].field_parts[0].bit_field[5]" | `name_or_parameter` | 0.000000 | "INACT_X_ENABLE" | "INACT_X enable" | "strict fact mismatch; truth=\"INACT_X_ENABLE\" candidate=\"INACT_X enable\"" |
| 150 | "truth registers[11].field_parts[0].bit_field[5]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 151 | "truth registers[11].field_parts[0].bit_field[5]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 152 | "truth registers[11].field_parts[0].bit_field[6]" | `name_or_parameter` | 0.000000 | "INACT_Y_ENABLE" | "INACT_Y enable" | "strict fact mismatch; truth=\"INACT_Y_ENABLE\" candidate=\"INACT_Y enable\"" |
| 153 | "truth registers[11].field_parts[0].bit_field[6]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 154 | "truth registers[11].field_parts[0].bit_field[6]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 155 | "truth registers[11].field_parts[0].bit_field[7]" | `name_or_parameter` | 0.000000 | "INACT_Z_ENABLE" | "INACT_Z enable" | "strict fact mismatch; truth=\"INACT_Z_ENABLE\" candidate=\"INACT_Z enable\"" |
| 156 | "truth registers[11].field_parts[0].bit_field[7]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 157 | "truth registers[11].field_parts[0].bit_field[7]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 158 | "truth registers[11].field_parts[0] ↔ v12_0 registers[11].field_parts[0]" | `bit_field` | 0.710771 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 159 | "truth registers[11] ↔ v12_0 registers[11]" | `field_parts` | 0.840200 | "mean(0.840200)" | "mean(0.840200)" | "recursive mean of field-part scores" |
| 160 | "truth registers[11].default_value_description ↔ v12_0 registers[11].default_value_description" | `default_value_description` | 0.000000 | "DC-coupled; all axes disabled" | "" | "description missing or not sufficiently supported" |
| 161 | "truth registers[12].field_parts[0]" | `description` | 0.000000 | "Free-fall threshold." | "" | "description missing or not sufficiently supported" |
| 162 | "truth registers[12].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "THRESH_FF" | MISSING | "field is missing" |
| 163 | "truth registers[12].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned free-fall threshold, 62.5 mg/LSB." | MISSING | "description missing or not sufficiently supported" |
| 164 | "truth registers[12].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 165 | "truth registers[12].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 166 | "truth registers[12].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 167 | "truth registers[12].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 168 | "truth registers[12].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 169 | "truth registers[12].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 170 | "truth registers[12].field_parts[0] ↔ v12_0 registers[12].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 171 | "truth registers[12] ↔ v12_0 registers[12]" | `field_parts` | 0.617800 | "mean(0.617800)" | "mean(0.617800)" | "recursive mean of field-part scores" |
| 172 | "truth registers[12].default_value_description ↔ v12_0 registers[12].default_value_description" | `default_value_description` | 0.000000 | "0 mg may result in undesirable behavior if the free-fall interrupt is enabled." | "" | "description missing or not sufficiently supported" |
| 173 | "truth registers[13].field_parts[0]" | `description` | 0.000000 | "Free-fall time." | "" | "description missing or not sufficiently supported" |
| 174 | "truth registers[13].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "TIME_FF" | MISSING | "field is missing" |
| 175 | "truth registers[13].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Unsigned free-fall time, 5 ms/LSB." | MISSING | "description missing or not sufficiently supported" |
| 176 | "truth registers[13].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 177 | "truth registers[13].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 178 | "truth registers[13].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 179 | "truth registers[13].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 180 | "truth registers[13].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 181 | "truth registers[13].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | MISSING | "field is missing" |
| 182 | "truth registers[13].field_parts[0] ↔ v12_0 registers[13].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 183 | "truth registers[13] ↔ v12_0 registers[13]" | `field_parts` | 0.617800 | "mean(0.617800)" | "mean(0.617800)" | "recursive mean of field-part scores" |
| 184 | "truth registers[13].default_value_description ↔ v12_0 registers[13].default_value_description" | `default_value_description` | 0.000000 | "0 may result in undesirable behavior if the free-fall interrupt is enabled." | "" | "description missing or not sufficiently supported" |
| 185 | "truth registers[14].field_parts[0]" | `description` | 0.000000 | "Tap-axis control." | "" | "description missing or not sufficiently supported" |
| 186 | "truth registers[14].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "SUPPRESS" | "Suppress" | "strict fact mismatch; truth=\"SUPPRESS\" candidate=\"Suppress\"" |
| 187 | "truth registers[14].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"Do not suppress."},{"value":"1","value_description":"Suppress double-tap detection."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 188 | "truth registers[14].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 189 | "truth registers[14].field_parts[0].bit_field[1]" | `name_or_parameter` | 0.000000 | "TAP_X_ENABLE" | "TAP_X enable" | "strict fact mismatch; truth=\"TAP_X_ENABLE\" candidate=\"TAP_X enable\"" |
| 190 | "truth registers[14].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude X axis from tap detection."},{"value":"1","value_description":"Enable X-axis participation in tap detection."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 191 | "truth registers[14].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 192 | "truth registers[14].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "TAP_Y_ENABLE" | "TAP_Y enable" | "strict fact mismatch; truth=\"TAP_Y_ENABLE\" candidate=\"TAP_Y enable\"" |
| 193 | "truth registers[14].field_parts[0].bit_field[2]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Y axis from tap detection."},{"value":"1","value_description":"Enable Y-axis participation in tap detection."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 194 | "truth registers[14].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 195 | "truth registers[14].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "TAP_Z_ENABLE" | "TAP_Z enable" | "strict fact mismatch; truth=\"TAP_Z_ENABLE\" candidate=\"TAP_Z enable\"" |
| 196 | "truth registers[14].field_parts[0].bit_field[3]" | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Z axis from tap detection."},{"value":"1","value_description":"Enable Z-axis participation in tap detection."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 197 | "truth registers[14].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 198 | "truth registers[14].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "RESERVED" | MISSING | "field is missing" |
| 199 | "truth registers[14].field_parts[0].bit_field[4]" | `field_description` | 0.000000 | "Reserved bits; do not access." | MISSING | "description missing or not sufficiently supported" |
| 200 | "truth registers[14].field_parts[0].bit_field[4]" | `bit_start` | 0.000000 | 4 | MISSING | "field is missing" |
| 201 | "truth registers[14].field_parts[0].bit_field[4]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 202 | "truth registers[14].field_parts[0].bit_field[4]" | `bit_width` | 0.000000 | 4 | MISSING | "field is missing" |
| 203 | "truth registers[14].field_parts[0].bit_field[4]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 204 | "truth registers[14].field_parts[0].bit_field[4]" | `is_reserved` | 0.000000 | true | MISSING | "field is missing" |
| 205 | "truth registers[14].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "" | MISSING | "field is missing" |
| 206 | "truth registers[14].field_parts[0] ↔ v12_0 registers[14].field_parts[0]" | `bit_field` | 0.568617 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 207 | "truth registers[14] ↔ v12_0 registers[14]" | `field_parts` | 0.795720 | "mean(0.795720)" | "mean(0.795720)" | "recursive mean of field-part scores" |
| 208 | "truth registers[14].default_value_description ↔ v12_0 registers[14].default_value_description" | `default_value_description` | 0.000000 | "All tap axes disabled; suppress disabled" | "" | "description missing or not sufficiently supported" |
| 209 | "truth registers[15].field_parts[0]" | `description` | 0.000000 | "Activity and tap source status." | "" | "description missing or not sufficiently supported" |
| 210 | "truth registers[15].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "ACT_X_SOURCE" | "ACT_X source" | "strict fact mismatch; truth=\"ACT_X_SOURCE\" candidate=\"ACT_X source\"" |
| 211 | "truth registers[15].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"X axis not involved in activity."},{"value":"1","value_description":"X axis involved in activity."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 212 | "truth registers[15].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 213 | "truth registers[15].field_parts[0].bit_field[1]" | `name_or_parameter` | 0.000000 | "ACT_Y_SOURCE" | "ACT_Y source" | "strict fact mismatch; truth=\"ACT_Y_SOURCE\" candidate=\"ACT_Y source\"" |
| 214 | "truth registers[15].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Y axis not involved in activity."},{"value":"1","value_description":"Y axis involved in activity."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 215 | "truth registers[15].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 216 | "truth registers[15].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "ACT_Z_SOURCE" | "ACT_Z source" | "strict fact mismatch; truth=\"ACT_Z_SOURCE\" candidate=\"ACT_Z source\"" |
| 217 | "truth registers[15].field_parts[0].bit_field[2]" | `values` | 0.000000 | [{"value":"0","value_description":"Z axis not involved in activity."},{"value":"1","value_description":"Z axis involved in activity."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 218 | "truth registers[15].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 219 | "truth registers[15].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "ASLEEP" | "Asleep" | "strict fact mismatch; truth=\"ASLEEP\" candidate=\"Asleep\"" |
| 220 | "truth registers[15].field_parts[0].bit_field[3]" | `values` | 0.000000 | [{"value":"0","value_description":"Not asleep."},{"value":"1","value_description":"Asleep."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 221 | "truth registers[15].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 222 | "truth registers[15].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "TAP_X_SOURCE" | "TAP_X source" | "strict fact mismatch; truth=\"TAP_X_SOURCE\" candidate=\"TAP_X source\"" |
| 223 | "truth registers[15].field_parts[0].bit_field[4]" | `values` | 0.000000 | [{"value":"0","value_description":"X axis not involved in tap."},{"value":"1","value_description":"X axis involved in tap."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 224 | "truth registers[15].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 225 | "truth registers[15].field_parts[0].bit_field[5]" | `name_or_parameter` | 0.000000 | "TAP_Y_SOURCE" | "TAP_Y source" | "strict fact mismatch; truth=\"TAP_Y_SOURCE\" candidate=\"TAP_Y source\"" |
| 226 | "truth registers[15].field_parts[0].bit_field[5]" | `values` | 0.000000 | [{"value":"0","value_description":"Y axis not involved in tap."},{"value":"1","value_description":"Y axis involved in tap."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 227 | "truth registers[15].field_parts[0].bit_field[5]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 228 | "truth registers[15].field_parts[0].bit_field[6]" | `name_or_parameter` | 0.000000 | "TAP_Z_SOURCE" | "TAP_Z source" | "strict fact mismatch; truth=\"TAP_Z_SOURCE\" candidate=\"TAP_Z source\"" |
| 229 | "truth registers[15].field_parts[0].bit_field[6]" | `values` | 0.000000 | [{"value":"0","value_description":"Z axis not involved in tap."},{"value":"1","value_description":"Z axis involved in tap."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 230 | "truth registers[15].field_parts[0].bit_field[6]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 231 | "truth registers[15].field_parts[0].bit_field[7]" | `name_or_parameter` | 0.000000 | "RESERVED" | "D7" | "strict fact mismatch; truth=\"RESERVED\" candidate=\"D7\"" |
| 232 | "truth registers[15].field_parts[0] ↔ v12_0 registers[15].field_parts[0]" | `bit_field` | 0.744274 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 233 | "truth registers[15] ↔ v12_0 registers[15]" | `field_parts` | 0.850683 | "mean(0.850683)" | "mean(0.850683)" | "recursive mean of field-part scores" |
| 234 | "truth registers[15].default_value_description ↔ v12_0 registers[15].default_value_description" | `default_value_description` | 0.000000 | "No event source; not asleep" | "" | "description missing or not sufficiently supported" |
| 235 | "truth registers[16].field_parts[0]" | `description` | 0.000000 | "Data rate and power mode control." | "" | "description missing or not sufficiently supported" |
| 236 | "truth registers[16].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"Normal operation."},{"value":"1","value_description":"Reduced-power operation."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 237 | "truth registers[16].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 238 | "truth registers[16].field_parts[0].bit_field[1]" | `name_or_parameter` | 0.000000 | "RATE" | "Rate" | "strict fact mismatch; truth=\"RATE\" candidate=\"Rate\"" |
| 239 | "truth registers[16].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0000 (0x00)","value_description":"0.10 Hz output data rate; 0.05 Hz bandwidth."},{"value":"0001 (0x01)","value_description":"0.20 Hz output data rate; 0.10 Hz bandwidth."},{"value":"0010 (0x02)","value_description":"0.39 Hz output data rate; 0.20 Hz bandwidth."},{"value":"0011 (0x03)","value_description":"0.78 Hz output data rate; 0.39 Hz bandwidth."},{"value":"0100 (0x04)","value_description":"1.56 Hz output data rate; 0.78 Hz bandwidth."},{"value":"0101 (0x05)","value_description":"3.13 Hz output data rate; 1.56 Hz bandwidth."},{"value":"0110 (0x06)","value_description":"6.25 Hz output data rate; 3.13 Hz bandwidth."},{"value":"0111 (0x07)","value_description":"12.5 Hz output data rate; 6.25 Hz bandwidth; low-power mode table entry."},{"value":"1000 (0x08)","value_description":"25 Hz output data rate; 12.5 Hz bandwidth; low-power mode table entry."},{"value":"1001 (0x09)","value_description":"50 Hz output data rate; 25 Hz bandwidth; low-power mode table entry."},{"value":"1010 (0x0A)","value_description":"100 Hz output data rate; 50 Hz bandwidth; default; low-power mode table entry."},{"value":"1011 (0x0B)","value_description":"200 Hz output data rate; 100 Hz bandwidth; low-power mode table entry."},{"value":"1100 (0x0C)","value_description":"400 Hz output data rate; 200 Hz bandwidth; low-power mode table entry."},{"value":"1101 (0x0D)","value_description":"800 Hz output data rate; 400 Hz bandwidth."},{"value":"1110 (0x0E)","value_description":"1600 Hz output data rate; 800 Hz bandwidth."},{"value":"1111 (0x0F)","value_description":"3200 Hz output data rate; 1600 Hz bandwidth."}] | [] | "strict value-code set mismatch; missing codes=[0, 1, 10, 11, 12, 13, 14, 15, 2, 3, 4, 5, 6, 7, 8, 9], extra codes=[]" |
| 240 | "truth registers[16].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 241 | "truth registers[16].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "RESERVED" | MISSING | "field is missing" |
| 242 | "truth registers[16].field_parts[0].bit_field[2]" | `field_description` | 0.000000 | "Reserved bits." | MISSING | "description missing or not sufficiently supported" |
| 243 | "truth registers[16].field_parts[0].bit_field[2]" | `bit_start` | 0.000000 | 5 | MISSING | "field is missing" |
| 244 | "truth registers[16].field_parts[0].bit_field[2]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 245 | "truth registers[16].field_parts[0].bit_field[2]" | `bit_width` | 0.000000 | 3 | MISSING | "field is missing" |
| 246 | "truth registers[16].field_parts[0].bit_field[2]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 247 | "truth registers[16].field_parts[0].bit_field[2]" | `is_reserved` | 0.000000 | true | MISSING | "field is missing" |
| 248 | "truth registers[16].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "" | MISSING | "field is missing" |
| 249 | "truth registers[16].field_parts[0] ↔ v12_0 registers[16].field_parts[0]" | `bit_field` | 0.480915 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 250 | "truth registers[16] ↔ v12_0 registers[16]" | `field_parts` | 0.768278 | "mean(0.768278)" | "mean(0.768278)" | "recursive mean of field-part scores" |
| 251 | "truth registers[16].default_value_description ↔ v12_0 registers[16].default_value_description" | `default_value_description` | 0.000000 | "100 Hz, normal power" | "" | "description missing or not sufficiently supported" |
| 252 | "truth registers[17].field_parts[0]" | `description` | 0.000000 | "Power-control bits." | "" | "description missing or not sufficiently supported" |
| 253 | "truth registers[17].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "LINK" | "Link" | "strict fact mismatch; truth=\"LINK\" candidate=\"Link\"" |
| 254 | "truth registers[17].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"Activity and inactivity functions operate concurrently."},{"value":"1","value_description":"Activity and inactivity functions are serially linked."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 255 | "truth registers[17].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 256 | "truth registers[17].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Automatic sleep disabled."},{"value":"1","value_description":"Automatic sleep enabled when linked inactivity is detected."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 257 | "truth registers[17].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 258 | "truth registers[17].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "MEASURE" | "Measure" | "strict fact mismatch; truth=\"MEASURE\" candidate=\"Measure\"" |
| 259 | "truth registers[17].field_parts[0].bit_field[2]" | `values` | 0.000000 | [{"value":"0","value_description":"Standby mode."},{"value":"1","value_description":"Measurement mode."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 260 | "truth registers[17].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 261 | "truth registers[17].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "SLEEP" | "Sleep" | "strict fact mismatch; truth=\"SLEEP\" candidate=\"Sleep\"" |
| 262 | "truth registers[17].field_parts[0].bit_field[3]" | `values` | 0.000000 | [{"value":"0","value_description":"Normal operation."},{"value":"1","value_description":"Sleep mode."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 263 | "truth registers[17].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 264 | "truth registers[17].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "WAKEUP" | "Wakeup" | "strict fact mismatch; truth=\"WAKEUP\" candidate=\"Wakeup\"" |
| 265 | "truth registers[17].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 266 | "truth registers[17].field_parts[0].bit_field[5]" | `name_or_parameter` | 0.000000 | "RESERVED" | MISSING | "field is missing" |
| 267 | "truth registers[17].field_parts[0].bit_field[5]" | `field_description` | 0.000000 | "Reserved bits." | MISSING | "description missing or not sufficiently supported" |
| 268 | "truth registers[17].field_parts[0].bit_field[5]" | `bit_start` | 0.000000 | 6 | MISSING | "field is missing" |
| 269 | "truth registers[17].field_parts[0].bit_field[5]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 270 | "truth registers[17].field_parts[0].bit_field[5]" | `bit_width` | 0.000000 | 2 | MISSING | "field is missing" |
| 271 | "truth registers[17].field_parts[0].bit_field[5]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 272 | "truth registers[17].field_parts[0].bit_field[5]" | `is_reserved` | 0.000000 | true | MISSING | "field is missing" |
| 273 | "truth registers[17].field_parts[0].bit_field[5]" | `type_write_read` | 0.000000 | "" | MISSING | "field is missing" |
| 274 | "truth registers[17].field_parts[0] ↔ v12_0 registers[17].field_parts[0]" | `bit_field` | 0.630796 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 275 | "truth registers[17] ↔ v12_0 registers[17]" | `field_parts` | 0.815176 | "mean(0.815176)" | "mean(0.815176)" | "recursive mean of field-part scores" |
| 276 | "truth registers[17].default_value_description ↔ v12_0 registers[17].default_value_description" | `default_value_description` | 0.000000 | "Standby, normal mode" | "" | "description missing or not sufficiently supported" |
| 277 | "truth registers[18].field_parts[0]" | `description` | 0.000000 | "Interrupt enable control." | "" | "description missing or not sufficiently supported" |
| 278 | "truth registers[18].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 279 | "truth registers[18].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 280 | "truth registers[18].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 281 | "truth registers[18].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 282 | "truth registers[18].field_parts[0].bit_field[2]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 283 | "truth registers[18].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 284 | "truth registers[18].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "ACTIVITY" | "Activity" | "strict fact mismatch; truth=\"ACTIVITY\" candidate=\"Activity\"" |
| 285 | "truth registers[18].field_parts[0].bit_field[3]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 286 | "truth registers[18].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 287 | "truth registers[18].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "INACTIVITY" | "Inactivity" | "strict fact mismatch; truth=\"INACTIVITY\" candidate=\"Inactivity\"" |
| 288 | "truth registers[18].field_parts[0].bit_field[4]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 289 | "truth registers[18].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 290 | "truth registers[18].field_parts[0].bit_field[5]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 291 | "truth registers[18].field_parts[0].bit_field[5]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 292 | "truth registers[18].field_parts[0].bit_field[6]" | `name_or_parameter` | 0.000000 | "WATERMARK" | "Watermark" | "strict fact mismatch; truth=\"WATERMARK\" candidate=\"Watermark\"" |
| 293 | "truth registers[18].field_parts[0].bit_field[6]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 294 | "truth registers[18].field_parts[0].bit_field[6]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 295 | "truth registers[18].field_parts[0].bit_field[7]" | `name_or_parameter` | 0.000000 | "OVERRUN" | "Overrun" | "strict fact mismatch; truth=\"OVERRUN\" candidate=\"Overrun\"" |
| 296 | "truth registers[18].field_parts[0].bit_field[7]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 297 | "truth registers[18].field_parts[0].bit_field[7]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 298 | "truth registers[18].field_parts[0] ↔ v12_0 registers[18].field_parts[0]" | `bit_field` | 0.721372 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 299 | "truth registers[18] ↔ v12_0 registers[18]" | `field_parts` | 0.843517 | "mean(0.843517)" | "mean(0.843517)" | "recursive mean of field-part scores" |
| 300 | "truth registers[18].default_value_description ↔ v12_0 registers[18].default_value_description" | `default_value_description` | 0.000000 | "All interrupts disabled" | "" | "description missing or not sufficiently supported" |
| 301 | "truth registers[19].field_parts[0]" | `description` | 0.000000 | "Interrupt mapping." | "" | "description missing or not sufficiently supported" |
| 302 | "truth registers[19].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 303 | "truth registers[19].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 304 | "truth registers[19].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 305 | "truth registers[19].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 306 | "truth registers[19].field_parts[0].bit_field[2]" | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 307 | "truth registers[19].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 308 | "truth registers[19].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "ACTIVITY" | "Activity" | "strict fact mismatch; truth=\"ACTIVITY\" candidate=\"Activity\"" |
| 309 | "truth registers[19].field_parts[0].bit_field[3]" | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 310 | "truth registers[19].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 311 | "truth registers[19].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "INACTIVITY" | "Inactivity" | "strict fact mismatch; truth=\"INACTIVITY\" candidate=\"Inactivity\"" |
| 312 | "truth registers[19].field_parts[0].bit_field[4]" | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 313 | "truth registers[19].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 314 | "truth registers[19].field_parts[0].bit_field[5]" | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 315 | "truth registers[19].field_parts[0].bit_field[5]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 316 | "truth registers[19].field_parts[0].bit_field[6]" | `name_or_parameter` | 0.000000 | "WATERMARK" | "Watermark" | "strict fact mismatch; truth=\"WATERMARK\" candidate=\"Watermark\"" |
| 317 | "truth registers[19].field_parts[0].bit_field[6]" | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 318 | "truth registers[19].field_parts[0].bit_field[6]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 319 | "truth registers[19].field_parts[0].bit_field[7]" | `name_or_parameter` | 0.000000 | "OVERRUN" | "Overrun" | "strict fact mismatch; truth=\"OVERRUN\" candidate=\"Overrun\"" |
| 320 | "truth registers[19].field_parts[0].bit_field[7]" | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 321 | "truth registers[19].field_parts[0].bit_field[7]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 322 | "truth registers[19].field_parts[0] ↔ v12_0 registers[19].field_parts[0]" | `bit_field` | 0.721372 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 323 | "truth registers[19] ↔ v12_0 registers[19]" | `field_parts` | 0.843517 | "mean(0.843517)" | "mean(0.843517)" | "recursive mean of field-part scores" |
| 324 | "truth registers[19].default_value_description ↔ v12_0 registers[19].default_value_description" | `default_value_description` | 0.000000 | "All interrupts mapped to INT1" | "" | "description missing or not sufficiently supported" |
| 325 | "truth registers[20].field_parts[0]" | `description` | 0.000000 | "Interrupt source status." | "" | "description missing or not sufficiently supported" |
| 326 | "truth registers[20].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 327 | "truth registers[20].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 328 | "truth registers[20].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 329 | "truth registers[20].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 330 | "truth registers[20].field_parts[0].bit_field[2]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 331 | "truth registers[20].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 332 | "truth registers[20].field_parts[0].bit_field[3]" | `name_or_parameter` | 0.000000 | "ACTIVITY" | "Activity" | "strict fact mismatch; truth=\"ACTIVITY\" candidate=\"Activity\"" |
| 333 | "truth registers[20].field_parts[0].bit_field[3]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 334 | "truth registers[20].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 335 | "truth registers[20].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "INACTIVITY" | "Inactivity" | "strict fact mismatch; truth=\"INACTIVITY\" candidate=\"Inactivity\"" |
| 336 | "truth registers[20].field_parts[0].bit_field[4]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 337 | "truth registers[20].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 338 | "truth registers[20].field_parts[0].bit_field[5]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 339 | "truth registers[20].field_parts[0].bit_field[5]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 340 | "truth registers[20].field_parts[0].bit_field[6]" | `name_or_parameter` | 0.000000 | "WATERMARK" | "Watermark" | "strict fact mismatch; truth=\"WATERMARK\" candidate=\"Watermark\"" |
| 341 | "truth registers[20].field_parts[0].bit_field[6]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 342 | "truth registers[20].field_parts[0].bit_field[6]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 343 | "truth registers[20].field_parts[0].bit_field[7]" | `name_or_parameter` | 0.000000 | "OVERRUN" | "Overrun" | "strict fact mismatch; truth=\"OVERRUN\" candidate=\"Overrun\"" |
| 344 | "truth registers[20].field_parts[0].bit_field[7]" | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 345 | "truth registers[20].field_parts[0].bit_field[7]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 346 | "truth registers[20].field_parts[0] ↔ v12_0 registers[20].field_parts[0]" | `bit_field` | 0.721372 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 347 | "truth registers[20] ↔ v12_0 registers[20]" | `field_parts` | 0.843517 | "mean(0.843517)" | "mean(0.843517)" | "recursive mean of field-part scores" |
| 348 | "truth registers[20].default_value_description ↔ v12_0 registers[20].default_value_description" | `default_value_description` | 0.000000 | "Watermark status bit set in reset value per register map" | "" | "description missing or not sufficiently supported" |
| 349 | "truth registers[21].field_parts[0]" | `description` | 0.000000 | "Data format control." | "" | "description missing or not sufficiently supported" |
| 350 | "truth registers[21].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"Self-test force disabled."},{"value":"1","value_description":"Self-test force enabled."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 351 | "truth registers[21].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 352 | "truth registers[21].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Four-wire SPI mode."},{"value":"1","value_description":"Three-wire SPI mode."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 353 | "truth registers[21].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 354 | "truth registers[21].field_parts[0].bit_field[2]" | `values` | 0.000000 | [{"value":"0","value_description":"Active-high interrupts."},{"value":"1","value_description":"Active-low interrupts."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 355 | "truth registers[21].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 356 | "truth registers[21].field_parts[0].bit_field[3]" | `values` | 0.000000 | [{"value":"0","value_description":"10-bit mode."},{"value":"1","value_description":"Full-resolution mode."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 357 | "truth registers[21].field_parts[0].bit_field[3]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 358 | "truth registers[21].field_parts[0].bit_field[4]" | `name_or_parameter` | 0.000000 | "JUSTIFY" | "Justify" | "strict fact mismatch; truth=\"JUSTIFY\" candidate=\"Justify\"" |
| 359 | "truth registers[21].field_parts[0].bit_field[4]" | `values` | 0.000000 | [{"value":"0","value_description":"Right-justified with sign extension."},{"value":"1","value_description":"Left-justified."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 360 | "truth registers[21].field_parts[0].bit_field[4]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 361 | "truth registers[21].field_parts[0].bit_field[5]" | `name_or_parameter` | 0.000000 | "RANGE" | "Range" | "strict fact mismatch; truth=\"RANGE\" candidate=\"Range\"" |
| 362 | "truth registers[21].field_parts[0].bit_field[5]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 363 | "truth registers[21].field_parts[0].bit_field[6]" | `name_or_parameter` | 0.000000 | "RESERVED" | "D4" | "strict fact mismatch; truth=\"RESERVED\" candidate=\"D4\"" |
| 364 | "truth registers[21].field_parts[0] ↔ v12_0 registers[21].field_parts[0]" | `bit_field` | 0.791136 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 365 | "truth registers[21] ↔ v12_0 registers[21]" | `field_parts` | 0.865347 | "mean(0.865347)" | "mean(0.865347)" | "recursive mean of field-part scores" |
| 366 | "truth registers[21].default_value_description ↔ v12_0 registers[21].default_value_description" | `default_value_description` | 0.000000 | "10-bit, +/-2 g, right-justified, four-wire SPI, active-high interrupts" | "" | "description missing or not sufficiently supported" |
| 367 | "truth registers[22].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "DATAX0" | MISSING | "field is missing" |
| 368 | "truth registers[22].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Least significant byte of two's-complement X-axis output data." | MISSING | "description missing or not sufficiently supported" |
| 369 | "truth registers[22].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 370 | "truth registers[22].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 371 | "truth registers[22].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 372 | "truth registers[22].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 373 | "truth registers[22].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 374 | "truth registers[22].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "R" | MISSING | "field is missing" |
| 375 | "truth registers[22].field_parts[0] ↔ v12_0 registers[22].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 376 | "truth registers[22] ↔ v12_0 registers[22]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 377 | "truth registers[22].default_value_description ↔ v12_0 registers[22].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 378 | "truth registers[22].field_parts[1].bit_field[0]" | `name_or_parameter` | 0.000000 | "DATAX1" | MISSING | "field is missing" |
| 379 | "truth registers[22].field_parts[1].bit_field[0]" | `field_description` | 0.000000 | "Most significant byte of two's-complement X-axis output data." | MISSING | "description missing or not sufficiently supported" |
| 380 | "truth registers[22].field_parts[1].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 381 | "truth registers[22].field_parts[1].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 382 | "truth registers[22].field_parts[1].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 383 | "truth registers[22].field_parts[1].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 384 | "truth registers[22].field_parts[1].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 385 | "truth registers[22].field_parts[1].bit_field[0]" | `type_write_read` | 0.000000 | "R" | MISSING | "field is missing" |
| 386 | "truth registers[22].field_parts[1] ↔ v12_0 registers[23].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 387 | "truth registers[22] ↔ v12_0 registers[23]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 388 | "truth registers[22].default_value_description ↔ v12_0 registers[23].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 389 | "truth registers[23].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "DATAY0" | MISSING | "field is missing" |
| 390 | "truth registers[23].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Least significant byte of two's-complement Y-axis output data." | MISSING | "description missing or not sufficiently supported" |
| 391 | "truth registers[23].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 392 | "truth registers[23].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 393 | "truth registers[23].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 394 | "truth registers[23].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 395 | "truth registers[23].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 396 | "truth registers[23].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "R" | MISSING | "field is missing" |
| 397 | "truth registers[23].field_parts[0] ↔ v12_0 registers[24].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 398 | "truth registers[23] ↔ v12_0 registers[24]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 399 | "truth registers[23].default_value_description ↔ v12_0 registers[24].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 400 | "truth registers[23].field_parts[1].bit_field[0]" | `name_or_parameter` | 0.000000 | "DATAY1" | MISSING | "field is missing" |
| 401 | "truth registers[23].field_parts[1].bit_field[0]" | `field_description` | 0.000000 | "Most significant byte of two's-complement Y-axis output data." | MISSING | "description missing or not sufficiently supported" |
| 402 | "truth registers[23].field_parts[1].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 403 | "truth registers[23].field_parts[1].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 404 | "truth registers[23].field_parts[1].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 405 | "truth registers[23].field_parts[1].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 406 | "truth registers[23].field_parts[1].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 407 | "truth registers[23].field_parts[1].bit_field[0]" | `type_write_read` | 0.000000 | "R" | MISSING | "field is missing" |
| 408 | "truth registers[23].field_parts[1] ↔ v12_0 registers[25].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 409 | "truth registers[23] ↔ v12_0 registers[25]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 410 | "truth registers[23].default_value_description ↔ v12_0 registers[25].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 411 | "truth registers[24].field_parts[0].bit_field[0]" | `name_or_parameter` | 0.000000 | "DATAZ0" | MISSING | "field is missing" |
| 412 | "truth registers[24].field_parts[0].bit_field[0]" | `field_description` | 0.000000 | "Least significant byte of two's-complement Z-axis output data." | MISSING | "description missing or not sufficiently supported" |
| 413 | "truth registers[24].field_parts[0].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 414 | "truth registers[24].field_parts[0].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 415 | "truth registers[24].field_parts[0].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 416 | "truth registers[24].field_parts[0].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 417 | "truth registers[24].field_parts[0].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 418 | "truth registers[24].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "R" | MISSING | "field is missing" |
| 419 | "truth registers[24].field_parts[0] ↔ v12_0 registers[26].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 420 | "truth registers[24] ↔ v12_0 registers[26]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 421 | "truth registers[24].default_value_description ↔ v12_0 registers[26].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 422 | "truth registers[24].field_parts[1].bit_field[0]" | `name_or_parameter` | 0.000000 | "DATAZ1" | MISSING | "field is missing" |
| 423 | "truth registers[24].field_parts[1].bit_field[0]" | `field_description` | 0.000000 | "Most significant byte of two's-complement Z-axis output data." | MISSING | "description missing or not sufficiently supported" |
| 424 | "truth registers[24].field_parts[1].bit_field[0]" | `bit_start` | 0.000000 | 0 | MISSING | "field is missing" |
| 425 | "truth registers[24].field_parts[1].bit_field[0]" | `bit_end` | 0.000000 | 7 | MISSING | "field is missing" |
| 426 | "truth registers[24].field_parts[1].bit_field[0]" | `bit_width` | 0.000000 | 8 | MISSING | "field is missing" |
| 427 | "truth registers[24].field_parts[1].bit_field[0]" | `values` | 0.000000 | [] | MISSING | "values field missing" |
| 428 | "truth registers[24].field_parts[1].bit_field[0]" | `is_reserved` | 0.000000 | false | MISSING | "field is missing" |
| 429 | "truth registers[24].field_parts[1].bit_field[0]" | `type_write_read` | 0.000000 | "R" | MISSING | "field is missing" |
| 430 | "truth registers[24].field_parts[1] ↔ v12_0 registers[27].field_parts[0]" | `bit_field` | 0.000000 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 431 | "truth registers[24] ↔ v12_0 registers[27]" | `field_parts` | 0.687100 | "mean(0.687100)" | "mean(0.687100)" | "recursive mean of field-part scores" |
| 432 | "truth registers[24].default_value_description ↔ v12_0 registers[27].default_value_description" | `default_value_description` | 0.000000 | "0" | "" | "description missing or not sufficiently supported" |
| 433 | "truth registers[25].field_parts[0]" | `description` | 0.000000 | "FIFO control." | "" | "description missing or not sufficiently supported" |
| 434 | "truth registers[25].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"00","value_description":"Bypass."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Trigger mode."}] | [] | "strict value-code set mismatch; missing codes=[0, 1, 2, 3], extra codes=[]" |
| 435 | "truth registers[25].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 436 | "truth registers[25].field_parts[0].bit_field[1]" | `name_or_parameter` | 0.000000 | "TRIGGER" | "Trigger" | "strict fact mismatch; truth=\"TRIGGER\" candidate=\"Trigger\"" |
| 437 | "truth registers[25].field_parts[0].bit_field[1]" | `values` | 0.000000 | [{"value":"0","value_description":"Trigger event linked to INT1."},{"value":"1","value_description":"Trigger event linked to INT2."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 438 | "truth registers[25].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 439 | "truth registers[25].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "SAMPLES" | "Samples" | "strict fact mismatch; truth=\"SAMPLES\" candidate=\"Samples\"" |
| 440 | "truth registers[25].field_parts[0].bit_field[2]" | `type_write_read` | 0.000000 | "RW" | "" | "strict fact mismatch; truth=\"RW\" candidate=\"\"" |
| 441 | "truth registers[25].field_parts[0] ↔ v12_0 registers[28].field_parts[0]" | `bit_field` | 0.787745 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 442 | "truth registers[25] ↔ v12_0 registers[28]" | `field_parts` | 0.864286 | "mean(0.864286)" | "mean(0.864286)" | "recursive mean of field-part scores" |
| 443 | "truth registers[25].default_value_description ↔ v12_0 registers[28].default_value_description" | `default_value_description` | 0.000000 | "Bypass mode, trigger INT1, zero samples; zero samples immediately sets WATERMARK and may cause undesirable trigger-mode operation." | "" | "description missing or not sufficiently supported" |
| 444 | "truth registers[26].field_parts[0]" | `description` | 0.000000 | "FIFO status." | "" | "description missing or not sufficiently supported" |
| 445 | "truth registers[26].field_parts[0].bit_field[0]" | `values` | 0.000000 | [{"value":"0","value_description":"No FIFO trigger event."},{"value":"1","value_description":"FIFO trigger event occurred."}] | [] | "strict value-code set mismatch; missing codes=[0, 1], extra codes=[]" |
| 446 | "truth registers[26].field_parts[0].bit_field[0]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 447 | "truth registers[26].field_parts[0].bit_field[1]" | `name_or_parameter` | 0.000000 | "ENTRIES" | "Entries" | "strict fact mismatch; truth=\"ENTRIES\" candidate=\"Entries\"" |
| 448 | "truth registers[26].field_parts[0].bit_field[1]" | `type_write_read` | 0.000000 | "R" | "" | "strict fact mismatch; truth=\"R\" candidate=\"\"" |
| 449 | "truth registers[26].field_parts[0].bit_field[2]" | `name_or_parameter` | 0.000000 | "RESERVED" | "D6" | "strict fact mismatch; truth=\"RESERVED\" candidate=\"D6\"" |
| 450 | "truth registers[26].field_parts[0] ↔ v12_0 registers[29].field_parts[0]" | `bit_field` | 0.877088 | "truth bit-field set" | "extracted bit-field set" | "recursive mean of exact-range bit-field scores" |
| 451 | "truth registers[26] ↔ v12_0 registers[29]" | `field_parts` | 0.892241 | "mean(0.892241)" | "mean(0.892241)" | "recursive mean of field-part scores" |
| 452 | "truth registers[26].default_value_description ↔ v12_0 registers[29].default_value_description" | `default_value_description` | 0.000000 | "No trigger; zero entries" | "" | "description missing or not sufficiently supported" |
| 453 | no truth bit-field range | `"v12_0 registers[0].field_parts[0].bit_field[0]"` | diagnostic | no exact truth range | {"name_or_parameter":"D7","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 454 | no truth bit-field range | `"v12_0 registers[0].field_parts[0].bit_field[1]"` | diagnostic | no exact truth range | {"name_or_parameter":"D6","field_description":"","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 455 | no truth bit-field range | `"v12_0 registers[0].field_parts[0].bit_field[2]"` | diagnostic | no exact truth range | {"name_or_parameter":"D5","field_description":"","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 456 | no truth bit-field range | `"v12_0 registers[0].field_parts[0].bit_field[3]"` | diagnostic | no exact truth range | {"name_or_parameter":"D4","field_description":"","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 457 | no truth bit-field range | `"v12_0 registers[0].field_parts[0].bit_field[4]"` | diagnostic | no exact truth range | {"name_or_parameter":"D3","field_description":"","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 458 | no truth bit-field range | `"v12_0 registers[0].field_parts[0].bit_field[5]"` | diagnostic | no exact truth range | {"name_or_parameter":"D2","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 459 | no truth bit-field range | `"v12_0 registers[0].field_parts[0].bit_field[6]"` | diagnostic | no exact truth range | {"name_or_parameter":"D1","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 460 | no truth bit-field range | `"v12_0 registers[0].field_parts[0].bit_field[7]"` | diagnostic | no exact truth range | {"name_or_parameter":"D0","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"11100101","value_description":"Device ID code (0xE5)"}],"is_reserved":false,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 461 | no truth bit-field range | `"v12_0 registers[14].field_parts[0].bit_field[0]"` | diagnostic | no exact truth range | {"name_or_parameter":"D7","field_description":"Reserved","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 462 | no truth bit-field range | `"v12_0 registers[14].field_parts[0].bit_field[1]"` | diagnostic | no exact truth range | {"name_or_parameter":"D6","field_description":"Reserved","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 463 | no truth bit-field range | `"v12_0 registers[14].field_parts[0].bit_field[2]"` | diagnostic | no exact truth range | {"name_or_parameter":"D5","field_description":"Reserved","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 464 | no truth bit-field range | `"v12_0 registers[14].field_parts[0].bit_field[3]"` | diagnostic | no exact truth range | {"name_or_parameter":"D4","field_description":"Reserved","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 465 | no truth bit-field range | `"v12_0 registers[16].field_parts[0].bit_field[0]"` | diagnostic | no exact truth range | {"name_or_parameter":"D7","field_description":"Reserved","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 466 | no truth bit-field range | `"v12_0 registers[16].field_parts[0].bit_field[1]"` | diagnostic | no exact truth range | {"name_or_parameter":"D6","field_description":"Reserved","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 467 | no truth bit-field range | `"v12_0 registers[16].field_parts[0].bit_field[2]"` | diagnostic | no exact truth range | {"name_or_parameter":"D5","field_description":"Reserved","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 468 | no truth bit-field range | `"v12_0 registers[17].field_parts[0].bit_field[0]"` | diagnostic | no exact truth range | {"name_or_parameter":"D7","field_description":"Reserved","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |
| 469 | no truth bit-field range | `"v12_0 registers[17].field_parts[0].bit_field[1]"` | diagnostic | no exact truth range | {"name_or_parameter":"D6","field_description":"Reserved","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | candidate bit range is not aligned to a truth range; reviewed as extra/invented |

## 4. Empty-field audit

- Simultaneously empty truth and candidate primitive fields credited with 1.0: 8.
- type_write_read: 3 empty/empty comparison(s).
- values: 5 empty/empty comparison(s).

## 5. Missing/extra physical locations and representation check

- No truth physical location is missing.
- No extra extracted physical location is present.
- Numeric address matching uses normalized hex/decimal plus bank and page; nested address descriptions do not override a correct address key.
- Split byte grouping is accepted, but all matched direct fields and bit fields remain strictly scored.

## 6. Physical-register aggregation and calculation conclusion

| Truth physical register | Address | Associated extracted logical register(s) | q_R |
|---|---:|---|---:|
| `DEVID` | 0x00 (0) | `registers[0]` `DEVID` Q=0.852452 | 0.852452 |
| `THRESH_TAP` | 0x1D (29) | `registers[1]` `THRESH_TAP` Q=0.852452 | 0.852452 |
| `OFSX` | 0x1E (30) | `registers[2]` `OFSX` Q=0.852452 | 0.852452 |
| `OFSY` | 0x1F (31) | `registers[3]` `OFSY` Q=0.852452 | 0.852452 |
| `OFSZ` | 0x20 (32) | `registers[4]` `OFSZ` Q=0.852452 | 0.852452 |
| `DUR` | 0x21 (33) | `registers[5]` `DUR` Q=0.852452 | 0.852452 |
| `Latent` | 0x22 (34) | `registers[6]` `Latent` Q=0.852452 | 0.852452 |
| `Window` | 0x23 (35) | `registers[7]` `Window` Q=0.852452 | 0.852452 |
| `THRESH_ACT` | 0x24 (36) | `registers[8]` `THRESH_ACT` Q=0.852452 | 0.852452 |
| `THRESH_INACT` | 0x25 (37) | `registers[9]` `THRESH_INACT` Q=0.852452 | 0.852452 |
| `TIME_INACT` | 0x26 (38) | `registers[10]` `TIME_INACT` Q=0.852452 | 0.852452 |
| `ACT_INACT_CTL` | 0x27 (39) | `registers[11]` `ACT_INACT_CTL` Q=0.918876 | 0.918876 |
| `THRESH_FF` | 0x28 (40) | `registers[12]` `THRESH_FF` Q=0.852452 | 0.852452 |
| `TIME_FF` | 0x29 (41) | `registers[13]` `TIME_FF` Q=0.852452 | 0.852452 |
| `TAP_AXES` | 0x2A (42) | `registers[14]` `TAP_AXES` Q=0.905591 | 0.905591 |
| `ACT_TAP_STATUS` | 0x2B (43) | `registers[15]` `ACT_TAP_STATUS` Q=0.922007 | 0.922007 |
| `BW_RATE` | 0x2C (44) | `registers[16]` `BW_RATE` Q=0.897395 | 0.897395 |
| `POWER_CTL` | 0x2D (45) | `registers[17]` `POWER_CTL` Q=0.911402 | 0.911402 |
| `INT_ENABLE` | 0x2E (46) | `registers[18]` `INT_ENABLE` Q=0.919867 | 0.919867 |
| `INT_MAP` | 0x2F (47) | `registers[19]` `INT_MAP` Q=0.919867 | 0.919867 |
| `INT_SOURCE` | 0x30 (48) | `registers[20]` `INT_SOURCE` Q=0.919867 | 0.919867 |
| `DATA_FORMAT` | 0x31 (49) | `registers[21]` `DATA_FORMAT` Q=0.926386 | 0.926386 |
| `DATAX` | 0x32 (50) | `registers[22]` `DATAX0` Q=0.873149 | 0.873149 |
| `DATAX` | 0x33 (51) | `registers[23]` `DATAX1` Q=0.873149 | 0.873149 |
| `DATAY` | 0x34 (52) | `registers[24]` `DATAY0` Q=0.873149 | 0.873149 |
| `DATAY` | 0x35 (53) | `registers[25]` `DATAY1` Q=0.873149 | 0.873149 |
| `DATAZ` | 0x36 (54) | `registers[26]` `DATAZ0` Q=0.873149 | 0.873149 |
| `DATAZ` | 0x37 (55) | `registers[27]` `DATAZ1` Q=0.873149 | 0.873149 |
| `FIFO_CTL` | 0x38 (56) | `registers[28]` `FIFO_CTL` Q=0.926069 | 0.926069 |
| `FIFO_STATUS` | 0x39 (57) | `registers[29]` `FIFO_STATUS` Q=0.934419 | 0.934419 |

Σ q_R = 26.422513290 over n=30 truth physical registers.

\(S_{final}=(10/30×26.422513290)×(30/(30+0))=\mathbf{8.807504430}\,/\,10\)

The final ADXL345 v12_0 score is **8.807504430 / 10**.
