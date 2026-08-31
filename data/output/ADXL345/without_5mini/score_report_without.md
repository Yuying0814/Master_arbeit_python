# ADXL345 without detailed score — revised AGENTS.md rules

## 1. Scoring basis

- Truth file: `ADXL345/ground_truth.json`; evaluated map: `ADXL345/without/adxl345.json`.
- The truth contains 27 logical-register entries and 30 unique physical-register locations. The extracted map contains 30 logical-register entries and 30 unique extracted physical locations.
- n=30 is based on unique physical keys (numeric address, bank, page); hexadecimal and decimal representations of one numeric address are equivalent.
- m=30 truth physical locations are matched and x=0 extra extracted physical locations are counted. The extra-location factor is m/(m+x)=1.000000000.
- Every extracted logical register is calculated bottom-up: exact bit-range bit fields, then field parts, then the logical register. The resulting logical-register Q is then associated with each truth physical location covered by that logical register.
- `DATAX0`/`DATAX1`, `DATAY0`/`DATAY1`, and `DATAZ0`/`DATAZ1` are accepted as split representations of the corresponding truth logical registers. For these split entries, direct logical fields are compared with the corresponding truth physical field part where appropriate; the parent logical description and default-value description remain the comparison context. The split itself is not penalized.
- Descriptions are judged semantically: a functionally equivalent paraphrase receives 1.0, relevant but incomplete information receives 0.5, and a missing or contradictory description receives 0.0. The non-empty descriptions in this map preserve the truth function and are credited; the blank default-value descriptions are not credited because truth descriptions are non-empty.
- Objective facts are strict: names/parameters, numeric addresses plus bank/page, widths, exact bit boundaries, reserved flags, access types, default values, and value-code sets. Value-code notation and order are normalized; value-description wording does not override a code-set mismatch.
- Simultaneously empty truth and candidate primitive fields receive 1.0. Reserved bit names and descriptions may be empty. `category`, `index`, `is_multi_address`, `source`, and all other unlisted fields are excluded.
- AHP weights are applied exactly as specified in AGENTS.md; rounded weight sums are normalized by the level sums 0.9999 (bit field), 1.0000 (field part), and 1.0001 (logical register).

### Score summary

| Quantity | Value |
|---|---|
| n (unique truth physical-register locations) | 30 |
| truth logical-register entries | 27 |
| extracted logical-register entries | 30 |
| m (matched truth physical locations) | 30 |
| x (extra extracted physical locations) | 0 |
| Σ q_R | 28.846995859 |
| mean q_R | 0.961566529 |
| extra-location factor m/(m+x) | 1.000000000 |
| S_final | **9.615665286 / 10** |

Calculation:

`S_final = (10/30 × 28.846995859) × (30/(30+0)) = **9.615665286 / 10**`.

## Extracted logical register 1: `DEVID`

without location: registers[0]; truth association: truth registers[0] (`DEVID`).
Associated physical locations: 0x00 (0).

### Bottom layer: bit fields, then field parts

#### Field part 1: `DEVID` at 0x00 (0)

Locations: `truth registers[0].field_parts[0]` ↔ `without registers[0].field_parts[0]`.

**Truth bit field 1: `DEVID` bits 0:7**

Locations: `truth registers[0].field_parts[0].bit_field[0]` ↔ `without registers[0].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DEVID | DEVID |
| `field_description` | 0.0586 | 1.000000 | Device identification code. | Fixed device ID code (0xE5). |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [{"value":"0xE5","value_description":"ADXL345 device ID."}] | [{"value":"0xE5","value_description":"Device ID"}] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | DEVID | DEVID |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Device ID"} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Device ID register address"} |
| `description` | 0.0693 | 1.000000 | Fixed device ID register. | Device ID (fixed) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"DEVID","field_description":"Device identification code.","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"0xE5","value_description":"ADXL345 device ID."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"DEVID","field_description":"Fixed device ID code (0xE5).","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"0xE5","value_description":"Device ID"}],"is_reserved":false,"type_write_read":"R"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | DEVID | DEVID |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Device ID"}] | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Device ID register address"}] |
| `register_description` | 0.0564 | 1.000000 | Fixed device ID code of 0xE5. | Read-only device ID register containing the fixed device code (0xE5). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"DEVID","physical_address":{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Device ID register address"},"description":"Device ID (fixed)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"DEVID","field_description":"Fixed device ID code (0xE5).","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"0xE5","value_description":"Device ID"}],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.000000 | 11100101 | 11100101 |
| `default_value_description` | 0.0334 | 0.000000 | 0xE5 | "" |

`Q(L_1) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 2: `THRESH_TAP`

without location: registers[1]; truth association: truth registers[1] (`THRESH_TAP`).
Associated physical locations: 0x1D (29).

### Bottom layer: bit fields, then field parts

#### Field part 1: `THRESH_TAP` at 0x1D (29)

Locations: `truth registers[1].field_parts[0]` ↔ `without registers[1].field_parts[0]`.

**Truth bit field 1: `THRESH_TAP` bits 0:7**

Locations: `truth registers[1].field_parts[0].bit_field[0]` ↔ `without registers[1].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | THRESH_TAP | THRESH_TAP |
| `field_description` | 0.0586 | 1.000000 | Unsigned tap threshold, 62.5 mg/LSB. | Tap detection threshold (unsigned). Scale = 62.5 mg/LSB. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | THRESH_TAP | THRESH_TAP |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Tap threshold"} | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Tap threshold register"} |
| `description` | 0.0693 | 1.000000 | Tap threshold. | Tap threshold, unsigned (62.5 mg/LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"THRESH_TAP","field_description":"Unsigned tap threshold, 62.5 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"THRESH_TAP","field_description":"Tap detection threshold (unsigned). Scale = 62.5 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | THRESH_TAP | THRESH_TAP |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Tap threshold"}] | [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Tap threshold register"}] |
| `register_description` | 0.0564 | 1.000000 | Unsigned threshold magnitude for tap interrupts; scale factor 62.5 mg/LSB. | Tap threshold (unsigned). Scale factor 62.5 mg/LSB. Value of 0 may cause undesirable behavior when tap interrupts are enabled. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"THRESH_TAP","physical_address":{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Tap threshold register"},"description":"Tap threshold, unsigned (62.5 mg/LSB)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THRESH_TAP","field_description":"Tap detection threshold (unsigned). Scale = 62.5 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 may result in undesirable behavior if tap interrupts are enabled. | "" |

`Q(L_2) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 3: `OFSX`

without location: registers[2]; truth association: truth registers[2] (`OFSX`).
Associated physical locations: 0x1E (30).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OFSX` at 0x1E (30)

Locations: `truth registers[2].field_parts[0]` ↔ `without registers[2].field_parts[0]`.

**Truth bit field 1: `OFSX` bits 0:7**

Locations: `truth registers[2].field_parts[0].bit_field[0]` ↔ `without registers[2].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | OFSX | OFSX |
| `field_description` | 0.0586 | 1.000000 | Two's-complement X-axis offset, 15.6 mg/LSB. | X-axis offset adjustment, 8-bit two's complement. Scale = 15.6 mg/LSB. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | OFSX | OFSX |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"X-axis offset"} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"X-axis offset register"} |
| `description` | 0.0693 | 1.000000 | X-axis offset adjustment. | X-axis offset (twos complement, 15.6 mg/LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"OFSX","field_description":"Two's-complement X-axis offset, 15.6 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"OFSX","field_description":"X-axis offset adjustment, 8-bit two's complement. Scale = 15.6 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | OFSX | OFSX |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"X-axis offset"}] | [{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"X-axis offset register"}] |
| `register_description` | 0.0564 | 1.000000 | Two's-complement X-axis offset adjustment, 15.6 mg/LSB. | User-set X-axis offset (twos complement). Scale factor 15.6 mg/LSB. Value added to acceleration data. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"OFSX","physical_address":{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"X-axis offset register"},"description":"X-axis offset (twos complement, 15.6 mg/LSB)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"OFSX","field_description":"X-axis offset adjustment, 8-bit two's complement. Scale = 15.6 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 | "" |

`Q(L_3) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 4: `OFSY`

without location: registers[3]; truth association: truth registers[3] (`OFSY`).
Associated physical locations: 0x1F (31).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OFSY` at 0x1F (31)

Locations: `truth registers[3].field_parts[0]` ↔ `without registers[3].field_parts[0]`.

**Truth bit field 1: `OFSY` bits 0:7**

Locations: `truth registers[3].field_parts[0].bit_field[0]` ↔ `without registers[3].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | OFSY | OFSY |
| `field_description` | 0.0586 | 1.000000 | Two's-complement Y-axis offset, 15.6 mg/LSB. | Y-axis offset adjustment, 8-bit two's complement. Scale = 15.6 mg/LSB. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | OFSY | OFSY |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Y-axis offset"} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Y-axis offset register"} |
| `description` | 0.0693 | 1.000000 | Y-axis offset adjustment. | Y-axis offset (twos complement, 15.6 mg/LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"OFSY","field_description":"Two's-complement Y-axis offset, 15.6 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"OFSY","field_description":"Y-axis offset adjustment, 8-bit two's complement. Scale = 15.6 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | OFSY | OFSY |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Y-axis offset"}] | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Y-axis offset register"}] |
| `register_description` | 0.0564 | 1.000000 | Two's-complement Y-axis offset adjustment, 15.6 mg/LSB. | User-set Y-axis offset (twos complement). Scale factor 15.6 mg/LSB. Value added to acceleration data. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"OFSY","physical_address":{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Y-axis offset register"},"description":"Y-axis offset (twos complement, 15.6 mg/LSB)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"OFSY","field_description":"Y-axis offset adjustment, 8-bit two's complement. Scale = 15.6 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 | "" |

`Q(L_4) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 5: `OFSZ`

without location: registers[4]; truth association: truth registers[4] (`OFSZ`).
Associated physical locations: 0x20 (32).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OFSZ` at 0x20 (32)

Locations: `truth registers[4].field_parts[0]` ↔ `without registers[4].field_parts[0]`.

**Truth bit field 1: `OFSZ` bits 0:7**

Locations: `truth registers[4].field_parts[0].bit_field[0]` ↔ `without registers[4].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | OFSZ | OFSZ |
| `field_description` | 0.0586 | 1.000000 | Two's-complement Z-axis offset, 15.6 mg/LSB. | Z-axis offset adjustment, 8-bit two's complement. Scale = 15.6 mg/LSB. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | OFSZ | OFSZ |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Z-axis offset"} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Z-axis offset register"} |
| `description` | 0.0693 | 1.000000 | Z-axis offset adjustment. | Z-axis offset (twos complement, 15.6 mg/LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"OFSZ","field_description":"Two's-complement Z-axis offset, 15.6 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"OFSZ","field_description":"Z-axis offset adjustment, 8-bit two's complement. Scale = 15.6 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | OFSZ | OFSZ |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Z-axis offset"}] | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Z-axis offset register"}] |
| `register_description` | 0.0564 | 1.000000 | Two's-complement Z-axis offset adjustment, 15.6 mg/LSB. | User-set Z-axis offset (twos complement). Scale factor 15.6 mg/LSB. Value added to acceleration data. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"OFSZ","physical_address":{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Z-axis offset register"},"description":"Z-axis offset (twos complement, 15.6 mg/LSB)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"OFSZ","field_description":"Z-axis offset adjustment, 8-bit two's complement. Scale = 15.6 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 | "" |

`Q(L_5) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 6: `DUR`

without location: registers[5]; truth association: truth registers[5] (`DUR`).
Associated physical locations: 0x21 (33).

### Bottom layer: bit fields, then field parts

#### Field part 1: `DUR` at 0x21 (33)

Locations: `truth registers[5].field_parts[0]` ↔ `without registers[5].field_parts[0]`.

**Truth bit field 1: `DUR` bits 0:7**

Locations: `truth registers[5].field_parts[0].bit_field[0]` ↔ `without registers[5].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DUR | DUR |
| `field_description` | 0.0586 | 1.000000 | Unsigned tap duration, 625 us/LSB. | Maximum tap duration. Scale = 625 µs/LSB. 0 disables tap functions. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | DUR | DUR |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"Tap duration"} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"Tap duration register"} |
| `description` | 0.0693 | 1.000000 | Maximum tap duration. | Tap duration (unsigned, 625 µs/LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"DUR","field_description":"Unsigned tap duration, 625 us/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"DUR","field_description":"Maximum tap duration. Scale = 625 µs/LSB. 0 disables tap functions.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | DUR | DUR |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"Tap duration"}] | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"Tap duration register"}] |
| `register_description` | 0.0564 | 1.000000 | Unsigned maximum tap duration; 625 us/LSB. Zero disables tap functions. | Maximum time an event must be above THRESH_TAP to qualify as a tap. Unsigned. Scale = 625 µs/LSB. Value 0 disables single/double tap. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"DUR","physical_address":{"hex":"0x21","decimal":"33","bank":"","page":"","description":"Tap duration register"},"description":"Tap duration (unsigned, 625 µs/LSB)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"DUR","field_description":"Maximum tap duration. Scale = 625 µs/LSB. 0 disables tap functions.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 disables the single-tap and double-tap functions. | "" |

`Q(L_6) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 7: `Latent`

without location: registers[6]; truth association: truth registers[6] (`Latent`).
Associated physical locations: 0x22 (34).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Latent` at 0x22 (34)

Locations: `truth registers[6].field_parts[0]` ↔ `without registers[6].field_parts[0]`.

**Truth bit field 1: `Latent` bits 0:7**

Locations: `truth registers[6].field_parts[0].bit_field[0]` ↔ `without registers[6].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | Latent | Latent |
| `field_description` | 0.0586 | 1.000000 | Unsigned tap latency, 1.25 ms/LSB. | Wait time from first tap to start of double-tap window. Scale = 1.25 ms/LSB. 0 disables double tap. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | Latent | Latent |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Tap latency"} | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Tap latency register"} |
| `description` | 0.0693 | 1.000000 | Tap latency. | Tap latency (unsigned, 1.25 ms/LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"Latent","field_description":"Unsigned tap latency, 1.25 ms/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"Latent","field_description":"Wait time from first tap to start of double-tap window. Scale = 1.25 ms/LSB. 0 disables double tap.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | Latent | Latent |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x22","decimal":"34","bank":"","page":"","description":"Tap latency"}] | [{"hex":"0x22","decimal":"34","bank":"","page":"","description":"Tap latency register"}] |
| `register_description` | 0.0564 | 1.000000 | Unsigned wait time from first tap to the start of the second-tap window; 1.25 ms/LSB. | Tap latency: wait time from detection of first tap to start of window for detecting second tap. Unsigned. Scale = 1.25 ms/LSB. Value 0 disables double tap. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"Latent","physical_address":{"hex":"0x22","decimal":"34","bank":"","page":"","description":"Tap latency register"},"description":"Tap latency (unsigned, 1.25 ms/LSB)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Latent","field_description":"Wait time from first tap to start of double-tap window. Scale = 1.25 ms/LSB. 0 disables double tap.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 disables the double-tap function. | "" |

`Q(L_7) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 8: `Window`

without location: registers[7]; truth association: truth registers[7] (`Window`).
Associated physical locations: 0x23 (35).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Window` at 0x23 (35)

Locations: `truth registers[7].field_parts[0]` ↔ `without registers[7].field_parts[0]`.

**Truth bit field 1: `Window` bits 0:7**

Locations: `truth registers[7].field_parts[0].bit_field[0]` ↔ `without registers[7].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | Window | Window |
| `field_description` | 0.0586 | 1.000000 | Unsigned tap window, 1.25 ms/LSB. | Time after latency during which a second tap may begin. Scale = 1.25 ms/LSB. 0 disables double tap. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | Window | Window |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"Tap window"} | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"Tap window register"} |
| `description` | 0.0693 | 1.000000 | Tap window. | Tap window (unsigned, 1.25 ms/LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"Window","field_description":"Unsigned tap window, 1.25 ms/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"Window","field_description":"Time after latency during which a second tap may begin. Scale = 1.25 ms/LSB. 0 disables double tap.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | Window | Window |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"Tap window"}] | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"Tap window register"}] |
| `register_description` | 0.0564 | 1.000000 | Unsigned duration after latency during which a second tap can begin; 1.25 ms/LSB. | Tap window: amount of time after latency during which a second tap can begin. Unsigned. Scale = 1.25 ms/LSB. Value 0 disables double tap. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"Window","physical_address":{"hex":"0x23","decimal":"35","bank":"","page":"","description":"Tap window register"},"description":"Tap window (unsigned, 1.25 ms/LSB)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Window","field_description":"Time after latency during which a second tap may begin. Scale = 1.25 ms/LSB. 0 disables double tap.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 disables the double-tap function. | "" |

`Q(L_8) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 9: `THRESH_ACT`

without location: registers[8]; truth association: truth registers[8] (`THRESH_ACT`).
Associated physical locations: 0x24 (36).

### Bottom layer: bit fields, then field parts

#### Field part 1: `THRESH_ACT` at 0x24 (36)

Locations: `truth registers[8].field_parts[0]` ↔ `without registers[8].field_parts[0]`.

**Truth bit field 1: `THRESH_ACT` bits 0:7**

Locations: `truth registers[8].field_parts[0].bit_field[0]` ↔ `without registers[8].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | THRESH_ACT | THRESH_ACT |
| `field_description` | 0.0586 | 1.000000 | Unsigned activity threshold, 62.5 mg/LSB. | Activity detection threshold. Scale = 62.5 mg/LSB. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | THRESH_ACT | THRESH_ACT |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Activity threshold"} | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Activity threshold register"} |
| `description` | 0.0693 | 1.000000 | Activity threshold. | Activity threshold (unsigned, 62.5 mg/LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"THRESH_ACT","field_description":"Unsigned activity threshold, 62.5 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"THRESH_ACT","field_description":"Activity detection threshold. Scale = 62.5 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | THRESH_ACT | THRESH_ACT |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Activity threshold"}] | [{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Activity threshold register"}] |
| `register_description` | 0.0564 | 1.000000 | Unsigned activity threshold; 62.5 mg/LSB. | Activity threshold (unsigned). Scale factor 62.5 mg/LSB. Value 0 may cause undesirable behavior if activity interrupt enabled. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"THRESH_ACT","physical_address":{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Activity threshold register"},"description":"Activity threshold (unsigned, 62.5 mg/LSB)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THRESH_ACT","field_description":"Activity detection threshold. Scale = 62.5 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 may result in undesirable behavior if the activity interrupt is enabled. | "" |

`Q(L_9) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 10: `THRESH_INACT`

without location: registers[9]; truth association: truth registers[9] (`THRESH_INACT`).
Associated physical locations: 0x25 (37).

### Bottom layer: bit fields, then field parts

#### Field part 1: `THRESH_INACT` at 0x25 (37)

Locations: `truth registers[9].field_parts[0]` ↔ `without registers[9].field_parts[0]`.

**Truth bit field 1: `THRESH_INACT` bits 0:7**

Locations: `truth registers[9].field_parts[0].bit_field[0]` ↔ `without registers[9].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | THRESH_INACT | THRESH_INACT |
| `field_description` | 0.0586 | 1.000000 | Unsigned inactivity threshold, 62.5 mg/LSB. | Inactivity threshold. Scale = 62.5 mg/LSB. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | THRESH_INACT | THRESH_INACT |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"Inactivity threshold"} | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"Inactivity threshold register"} |
| `description` | 0.0693 | 1.000000 | Inactivity threshold. | Inactivity threshold (unsigned, 62.5 mg/LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"THRESH_INACT","field_description":"Unsigned inactivity threshold, 62.5 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"THRESH_INACT","field_description":"Inactivity threshold. Scale = 62.5 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | THRESH_INACT | THRESH_INACT |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":"Inactivity threshold"}] | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":"Inactivity threshold register"}] |
| `register_description` | 0.0564 | 1.000000 | Unsigned inactivity threshold; 62.5 mg/LSB. | Inactivity threshold (unsigned). Scale factor 62.5 mg/LSB. Value 0 may cause undesirable behavior if inactivity interrupt enabled. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"THRESH_INACT","physical_address":{"hex":"0x25","decimal":"37","bank":"","page":"","description":"Inactivity threshold register"},"description":"Inactivity threshold (unsigned, 62.5 mg/LSB)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THRESH_INACT","field_description":"Inactivity threshold. Scale = 62.5 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 may result in undesirable behavior if the inactivity interrupt is enabled. | "" |

`Q(L_10) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 11: `TIME_INACT`

without location: registers[10]; truth association: truth registers[10] (`TIME_INACT`).
Associated physical locations: 0x26 (38).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_INACT` at 0x26 (38)

Locations: `truth registers[10].field_parts[0]` ↔ `without registers[10].field_parts[0]`.

**Truth bit field 1: `TIME_INACT` bits 0:7**

Locations: `truth registers[10].field_parts[0].bit_field[0]` ↔ `without registers[10].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | TIME_INACT | TIME_INACT |
| `field_description` | 0.0586 | 1.000000 | Unsigned inactivity time, 1 s/LSB. | Time acceleration must be below THRESH_INACT to declare inactivity. Scale = 1 s/LSB. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | TIME_INACT | TIME_INACT |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Inactivity time"} | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Inactivity time register"} |
| `description` | 0.0693 | 1.000000 | Inactivity time. | Inactivity time (unsigned, 1 s/LSB), uses filtered data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"TIME_INACT","field_description":"Unsigned inactivity time, 1 s/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"TIME_INACT","field_description":"Time acceleration must be below THRESH_INACT to declare inactivity. Scale = 1 s/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | TIME_INACT | TIME_INACT |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Inactivity time"}] | [{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Inactivity time register"}] |
| `register_description` | 0.0564 | 1.000000 | Unsigned time acceleration must remain below THRESH_INACT; 1 s/LSB. | Inactivity time (unsigned). Scale factor 1 sec/LSB. Uses filtered output data; at least one output sample required for trigger. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"TIME_INACT","physical_address":{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Inactivity time register"},"description":"Inactivity time (unsigned, 1 s/LSB), uses filtered data","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"TIME_INACT","field_description":"Time acceleration must be below THRESH_INACT to declare inactivity. Scale = 1 s/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 results in an interrupt when acceleration is below THRESH_INACT. | "" |

`Q(L_11) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 12: `ACT_INACT_CTL`

without location: registers[11]; truth association: truth registers[11] (`ACT_INACT_CTL`).
Associated physical locations: 0x27 (39).

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACT_INACT_CTL` at 0x27 (39)

Locations: `truth registers[11].field_parts[0]` ↔ `without registers[11].field_parts[0]`.

**Truth bit field 1: `ACT_ACDC` bits 7:7**

Locations: `truth registers[11].field_parts[0].bit_field[0]` ↔ `without registers[11].field_parts[0].bit_field[0]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | ACT_ACDC | ACT ac/dc |
| `field_description` | 0.0586 | 1.000000 | Activity coupling: 0 dc-coupled, 1 ac-coupled. | Selects DC-coupled (0) or AC-coupled (1) operation for activity detection. |
| `bit_start` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 1.000000 | [{"value":"0","value_description":"DC-coupled activity detection."},{"value":"1","value_description":"AC-coupled activity detection."}] | [{"value":"0","value_description":"DC-coupled"},{"value":"1","value_description":"AC-coupled"}] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Truth bit field 2: `ACT_X_ENABLE` bits 6:6**

Locations: `truth registers[11].field_parts[0].bit_field[1]` ↔ `without registers[11].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | ACT_X_ENABLE | ACT_X enable |
| `field_description` | 0.0586 | 1.000000 | Enable X-axis activity participation. | Enable X-axis for activity detection (1 = enabled). |
| `bit_start` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_end` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 3: `ACT_Y_ENABLE` bits 5:5**

Locations: `truth registers[11].field_parts[0].bit_field[2]` ↔ `without registers[11].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | ACT_Y_ENABLE | ACT_Y enable |
| `field_description` | 0.0586 | 1.000000 | Enable Y-axis activity participation. | Enable Y-axis for activity detection (1 = enabled). |
| `bit_start` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_end` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 4: `ACT_Z_ENABLE` bits 4:4**

Locations: `truth registers[11].field_parts[0].bit_field[3]` ↔ `without registers[11].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | ACT_Z_ENABLE | ACT_Z enable |
| `field_description` | 0.0586 | 1.000000 | Enable Z-axis activity participation. | Enable Z-axis for activity detection (1 = enabled). |
| `bit_start` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_end` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 5: `INACT_ACDC` bits 3:3**

Locations: `truth registers[11].field_parts[0].bit_field[4]` ↔ `without registers[11].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | INACT_ACDC | INACT ac/dc |
| `field_description` | 0.0586 | 1.000000 | Inactivity coupling: 0 dc-coupled, 1 ac-coupled. | Selects DC-coupled (0) or AC-coupled (1) operation for inactivity detection. |
| `bit_start` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_end` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 1.000000 | [{"value":"0","value_description":"DC-coupled inactivity detection."},{"value":"1","value_description":"AC-coupled inactivity detection."}] | [{"value":"0","value_description":"DC-coupled"},{"value":"1","value_description":"AC-coupled"}] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Truth bit field 6: `INACT_X_ENABLE` bits 2:2**

Locations: `truth registers[11].field_parts[0].bit_field[5]` ↔ `without registers[11].field_parts[0].bit_field[5]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | INACT_X_ENABLE | INACT_X enable |
| `field_description` | 0.0586 | 1.000000 | Enable X-axis inactivity participation. | Enable X-axis for inactivity detection (1 = enabled). |
| `bit_start` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_end` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 7: `INACT_Y_ENABLE` bits 1:1**

Locations: `truth registers[11].field_parts[0].bit_field[6]` ↔ `without registers[11].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | INACT_Y_ENABLE | INACT_Y enable |
| `field_description` | 0.0586 | 1.000000 | Enable Y-axis inactivity participation. | Enable Y-axis for inactivity detection (1 = enabled). |
| `bit_start` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_end` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 8: `INACT_Z_ENABLE` bits 0:0**

Locations: `truth registers[11].field_parts[0].bit_field[7]` ↔ `without registers[11].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | INACT_Z_ENABLE | INACT_Z enable |
| `field_description` | 0.0586 | 1.000000 | Enable Z-axis inactivity participation. | Enable Z-axis for inactivity detection (1 = enabled). |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Field-part aggregation**

bit_field correctness = mean(0.978797880, 0.769076908, 0.769076908, 0.769076908, 0.978797880, 0.769076908, 0.769076908, 0.769076908) = **0.821507151**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | ACT_INACT_CTL | ACT_INACT_CTL |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"Axis enable control for activity and inactivity detection"} | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"Axis enable and AC/DC coupling control for activity/inactivity detection"} |
| `description` | 0.0693 | 1.000000 | Activity/inactivity axis control. | AC/DC selection and per-axis enable for activity and inactivity detection |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.821507 | [{"name_or_parameter":"ACT_ACDC","field_description":"Activity coupling: 0 dc-coupled, 1 ac-coupled.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"DC-coupled activity detection."},{"value":"1","value_description":"AC-coupled activity detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ACT_X_ENABLE","field_description":"Enable X-axis activity participation.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ACT_Y_ENABLE","field_description":"Enable Y-axis activity participation.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ACT_Z_ENABLE","field_description":"Enable Z-axis activity participation.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACT_ACDC","field_description":"Inactivity coupling: 0 dc-coupled, 1 ac-coupled.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"DC-coupled inactivity detection."},{"value":"1","value_description":"AC-coupled inactivity detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACT_X_ENABLE","field_description":"Enable X-axis inactivity participation.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACT_Y_ENABLE","field_description":"Enable Y-axis inactivity participation.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACT_Z_ENABLE","field_description":"Enable Z-axis inactivity participation.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"ACT ac/dc","field_description":"Selects DC-coupled (0) or AC-coupled (1) operation for activity detection.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"DC-coupled"},{"value":"1","value_description":"AC-coupled"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ACT_X enable","field_description":"Enable X-axis for activity detection (1 = enabled).","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ACT_Y enable","field_description":"Enable Y-axis for activity detection (1 = enabled).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ACT_Z enable","field_description":"Enable Z-axis for activity detection (1 = enabled).","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACT ac/dc","field_description":"Selects DC-coupled (0) or AC-coupled (1) operation for inactivity detection.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"DC-coupled"},{"value":"1","value_description":"AC-coupled"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACT_X enable","field_description":"Enable X-axis for inactivity detection (1 = enabled).","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACT_Y enable","field_description":"Enable Y-axis for inactivity detection (1 = enabled).","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACT_Z enable","field_description":"Enable Z-axis for inactivity detection (1 = enabled).","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.821507)/1.0000 = 0.944149587/1.0000 = **0.944149587**`.

### Extracted logical-register aggregation

field_parts correctness = mean(0.944149587) = **0.944149587**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | ACT_INACT_CTL | ACT_INACT_CTL |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Axis enable control for activity and inactivity detection"}] | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Axis enable and AC/DC coupling control for activity/inactivity detection"}] |
| `register_description` | 0.0564 | 1.000000 | Axis and AC/DC coupling control for activity and inactivity detection. | Controls AC/DC coupling for activity/inactivity and per-axis enable for activity and inactivity detection. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.944150 | mean(0.944149587) | [{"register_name":"ACT_INACT_CTL","physical_address":{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Axis enable and AC/DC coupling control for activity/inactivity detection"},"description":"AC/DC selection and per-axis enable for activity and inactivity detection","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"ACT ac/dc","field_description":"Selects DC-coupled (0) or AC-coupled (1) operation for activity detection.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"DC-coupled"},{"value":"1","value_description":"AC-coupled"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ACT_X enable","field_description":"Enable X-axis for activity detection (1 = enabled).","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ACT_Y enable","field_description":"Enable Y-axis for activity detection (1 = enabled).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ACT_Z enable","field_description":"Enable Z-axis for activity detection (1 = enabled).","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACT ac/dc","field_description":"Selects DC-coupled (0) or AC-coupled (1) operation for inactivity detection.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"DC-coupled"},{"value":"1","value_description":"AC-coupled"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACT_X enable","field_description":"Enable X-axis for inactivity detection (1 = enabled).","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACT_Y enable","field_description":"Enable Y-axis for inactivity detection (1 = enabled).","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACT_Z enable","field_description":"Enable Z-axis for inactivity detection (1 = enabled).","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | DC-coupled; all axes disabled | "" |

`Q(L_12) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.944150 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.950017482/1.0001 = **0.949922490**`.

## Extracted logical register 13: `THRESH_FF`

without location: registers[12]; truth association: truth registers[12] (`THRESH_FF`).
Associated physical locations: 0x28 (40).

### Bottom layer: bit fields, then field parts

#### Field part 1: `THRESH_FF` at 0x28 (40)

Locations: `truth registers[12].field_parts[0]` ↔ `without registers[12].field_parts[0]`.

**Truth bit field 1: `THRESH_FF` bits 0:7**

Locations: `truth registers[12].field_parts[0].bit_field[0]` ↔ `without registers[12].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | THRESH_FF | THRESH_FF |
| `field_description` | 0.0586 | 1.000000 | Unsigned free-fall threshold, 62.5 mg/LSB. | Free-fall detection threshold. Scale = 62.5 mg/LSB. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | THRESH_FF | THRESH_FF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Free-fall threshold"} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Free-fall threshold register"} |
| `description` | 0.0693 | 1.000000 | Free-fall threshold. | Free-fall threshold (unsigned, 62.5 mg/LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"THRESH_FF","field_description":"Unsigned free-fall threshold, 62.5 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"THRESH_FF","field_description":"Free-fall detection threshold. Scale = 62.5 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | THRESH_FF | THRESH_FF |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Free-fall threshold"}] | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Free-fall threshold register"}] |
| `register_description` | 0.0564 | 1.000000 | Unsigned free-fall threshold; 62.5 mg/LSB. | Free-fall threshold (unsigned). Scale = 62.5 mg/LSB. Values between 300 mg and 600 mg (0x05–0x09) recommended. Value 0 may cause undesirable behavior. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"THRESH_FF","physical_address":{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Free-fall threshold register"},"description":"Free-fall threshold (unsigned, 62.5 mg/LSB)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THRESH_FF","field_description":"Free-fall detection threshold. Scale = 62.5 mg/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 mg may result in undesirable behavior if the free-fall interrupt is enabled. | "" |

`Q(L_13) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 14: `TIME_FF`

without location: registers[13]; truth association: truth registers[13] (`TIME_FF`).
Associated physical locations: 0x29 (41).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_FF` at 0x29 (41)

Locations: `truth registers[13].field_parts[0]` ↔ `without registers[13].field_parts[0]`.

**Truth bit field 1: `TIME_FF` bits 0:7**

Locations: `truth registers[13].field_parts[0].bit_field[0]` ↔ `without registers[13].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | TIME_FF | TIME_FF |
| `field_description` | 0.0586 | 1.000000 | Unsigned free-fall time, 5 ms/LSB. | Minimum time all axes must be below THRESH_FF to trigger free-fall. Scale = 5 ms/LSB. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | TIME_FF | TIME_FF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"Free-fall time"} | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"Free-fall time register"} |
| `description` | 0.0693 | 1.000000 | Free-fall time. | Free-fall time (unsigned, 5 ms/LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"TIME_FF","field_description":"Unsigned free-fall time, 5 ms/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"TIME_FF","field_description":"Minimum time all axes must be below THRESH_FF to trigger free-fall. Scale = 5 ms/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | TIME_FF | TIME_FF |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x29","decimal":"41","bank":"","page":"","description":"Free-fall time"}] | [{"hex":"0x29","decimal":"41","bank":"","page":"","description":"Free-fall time register"}] |
| `register_description` | 0.0564 | 1.000000 | Unsigned minimum free-fall time; 5 ms/LSB. | Free-fall time (unsigned). Scale = 5 ms/LSB. Value 0 may cause undesirable behavior. Values between 100 ms and 350 ms (0x14–0x46) recommended. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"TIME_FF","physical_address":{"hex":"0x29","decimal":"41","bank":"","page":"","description":"Free-fall time register"},"description":"Free-fall time (unsigned, 5 ms/LSB)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"TIME_FF","field_description":"Minimum time all axes must be below THRESH_FF to trigger free-fall. Scale = 5 ms/LSB.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 may result in undesirable behavior if the free-fall interrupt is enabled. | "" |

`Q(L_14) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 15: `TAP_AXES`

without location: registers[14]; truth association: truth registers[14] (`TAP_AXES`).
Associated physical locations: 0x2A (42).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TAP_AXES` at 0x2A (42)

Locations: `truth registers[14].field_parts[0]` ↔ `without registers[14].field_parts[0]`.

**Truth bit field 1: `SUPPRESS` bits 3:3**

Locations: `truth registers[14].field_parts[0].bit_field[0]` ↔ `without registers[14].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | SUPPRESS | Suppress |
| `field_description` | 0.0586 | 1.000000 | Suppress double-tap detection for acceleration above THRESH_TAP between taps. | Suppress double tap detection if an event above THRESH_TAP occurs between taps. |
| `bit_start` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_end` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Do not suppress."},{"value":"1","value_description":"Suppress double-tap detection."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 2: `TAP_X_ENABLE` bits 2:2**

Locations: `truth registers[14].field_parts[0].bit_field[1]` ↔ `without registers[14].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | TAP_X_ENABLE | TAP_X enable |
| `field_description` | 0.0586 | 1.000000 | Enable X-axis tap participation. | Enable X-axis for tap detection (1 = enabled). |
| `bit_start` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_end` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Exclude X axis from tap detection."},{"value":"1","value_description":"Enable X-axis participation in tap detection."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 3: `TAP_Y_ENABLE` bits 1:1**

Locations: `truth registers[14].field_parts[0].bit_field[2]` ↔ `without registers[14].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | TAP_Y_ENABLE | TAP_Y enable |
| `field_description` | 0.0586 | 1.000000 | Enable Y-axis tap participation. | Enable Y-axis for tap detection (1 = enabled). |
| `bit_start` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_end` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Exclude Y axis from tap detection."},{"value":"1","value_description":"Enable Y-axis participation in tap detection."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 4: `TAP_Z_ENABLE` bits 0:0**

Locations: `truth registers[14].field_parts[0].bit_field[3]` ↔ `without registers[14].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | TAP_Z_ENABLE | TAP_Z enable |
| `field_description` | 0.0586 | 1.000000 | Enable Z-axis tap participation. | Enable Z-axis for tap detection (1 = enabled). |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Exclude Z axis from tap detection."},{"value":"1","value_description":"Enable Z-axis participation in tap detection."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 5: `RESERVED` bits 4:7**

Locations: `truth registers[14].field_parts[0].bit_field[4]` ↔ `without registers[14].field_parts[0].bit_field[0]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | RESERVED | Reserved |
| `field_description` | 0.0586 | 1.000000 | Reserved bits; do not access. | "" |
| `bit_start` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 4 | 4 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | true | true |
| `type_write_read` | 0.0583 | 1.000000 | "" | "" |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Field-part aggregation**

bit_field correctness = mean(0.769076908, 0.769076908, 0.769076908, 0.769076908, 0.978797880) = **0.811021102**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | TAP_AXES | TAP_AXES |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Axis control for single tap/double tap"} | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Tap axis control register"} |
| `description` | 0.0693 | 1.000000 | Tap-axis control. | Axis participation in tap detection and suppress bit |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.811021 | [{"name_or_parameter":"SUPPRESS","field_description":"Suppress double-tap detection for acceleration above THRESH_TAP between taps.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Do not suppress."},{"value":"1","value_description":"Suppress double-tap detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TAP_X_ENABLE","field_description":"Enable X-axis tap participation.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Exclude X axis from tap detection."},{"value":"1","value_description":"Enable X-axis participation in tap detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TAP_Y_ENABLE","field_description":"Enable Y-axis tap participation.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Exclude Y axis from tap detection."},{"value":"1","value_description":"Enable Y-axis participation in tap detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TAP_Z_ENABLE","field_description":"Enable Z-axis tap participation.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Exclude Z axis from tap detection."},{"value":"1","value_description":"Enable Z-axis participation in tap detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"RESERVED","field_description":"Reserved bits; do not access.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Suppress","field_description":"Suppress double tap detection if an event above THRESH_TAP occurs between taps.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TAP_X enable","field_description":"Enable X-axis for tap detection (1 = enabled).","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TAP_Y enable","field_description":"Enable Y-axis for tap detection (1 = enabled).","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TAP_Z enable","field_description":"Enable Z-axis for tap detection (1 = enabled).","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.811021)/1.0000 = 0.940868503/1.0000 = **0.940868503**`.

### Extracted logical-register aggregation

field_parts correctness = mean(0.940868503) = **0.940868503**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | TAP_AXES | TAP_AXES |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Axis control for single tap/double tap"}] | [{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Tap axis control register"}] |
| `register_description` | 0.0564 | 1.000000 | Axis control and suppress control for single-tap/double-tap detection. | Controls axis participation in tap detection and suppress feature for double-tap. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.940869 | mean(0.940868503) | [{"register_name":"TAP_AXES","physical_address":{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Tap axis control register"},"description":"Axis participation in tap detection and suppress bit","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Suppress","field_description":"Suppress double tap detection if an event above THRESH_TAP occurs between taps.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TAP_X enable","field_description":"Enable X-axis for tap detection (1 = enabled).","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TAP_Y enable","field_description":"Enable Y-axis for tap detection (1 = enabled).","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TAP_Z enable","field_description":"Enable Z-axis for tap detection (1 = enabled).","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | All tap axes disabled; suppress disabled | "" |

`Q(L_15) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.940869 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.949037422/1.0001 = **0.948942528**`.

## Extracted logical register 16: `ACT_TAP_STATUS`

without location: registers[15]; truth association: truth registers[15] (`ACT_TAP_STATUS`).
Associated physical locations: 0x2B (43).

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACT_TAP_STATUS` at 0x2B (43)

Locations: `truth registers[15].field_parts[0]` ↔ `without registers[15].field_parts[0]`.

**Truth bit field 1: `ACT_X_SOURCE` bits 6:6**

Locations: `truth registers[15].field_parts[0].bit_field[0]` ↔ `without registers[15].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | ACT_X_SOURCE | ACT_X source |
| `field_description` | 0.0586 | 1.000000 | X axis involved in activity event. | Indicates X-axis involvement in activity event (1 = involved). |
| `bit_start` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_end` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"X axis not involved in activity."},{"value":"1","value_description":"X axis involved in activity."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 2: `ACT_Y_SOURCE` bits 5:5**

Locations: `truth registers[15].field_parts[0].bit_field[1]` ↔ `without registers[15].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | ACT_Y_SOURCE | ACT_Y source |
| `field_description` | 0.0586 | 1.000000 | Y axis involved in activity event. | Indicates Y-axis involvement in activity event (1 = involved). |
| `bit_start` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_end` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Y axis not involved in activity."},{"value":"1","value_description":"Y axis involved in activity."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 3: `ACT_Z_SOURCE` bits 4:4**

Locations: `truth registers[15].field_parts[0].bit_field[2]` ↔ `without registers[15].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | ACT_Z_SOURCE | ACT_Z source |
| `field_description` | 0.0586 | 1.000000 | Z axis involved in activity event. | Indicates Z-axis involvement in activity event (1 = involved). |
| `bit_start` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_end` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Z axis not involved in activity."},{"value":"1","value_description":"Z axis involved in activity."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 4: `ASLEEP` bits 3:3**

Locations: `truth registers[15].field_parts[0].bit_field[3]` ↔ `without registers[15].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | ASLEEP | Asleep |
| `field_description` | 0.0586 | 1.000000 | Sleep status: 1 asleep, 0 not asleep. | Indicates device is asleep (1) when auto-sleep is configured. |
| `bit_start` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_end` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Not asleep."},{"value":"1","value_description":"Asleep."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 5: `TAP_X_SOURCE` bits 2:2**

Locations: `truth registers[15].field_parts[0].bit_field[4]` ↔ `without registers[15].field_parts[0].bit_field[5]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | TAP_X_SOURCE | TAP_X source |
| `field_description` | 0.0586 | 1.000000 | X axis involved in tap event. | Indicates X-axis was source of tap event (1 = involved). |
| `bit_start` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_end` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"X axis not involved in tap."},{"value":"1","value_description":"X axis involved in tap."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 6: `TAP_Y_SOURCE` bits 1:1**

Locations: `truth registers[15].field_parts[0].bit_field[5]` ↔ `without registers[15].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | TAP_Y_SOURCE | TAP_Y source |
| `field_description` | 0.0586 | 1.000000 | Y axis involved in tap event. | Indicates Y-axis was source of tap event (1 = involved). |
| `bit_start` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_end` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Y axis not involved in tap."},{"value":"1","value_description":"Y axis involved in tap."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 7: `TAP_Z_SOURCE` bits 0:0**

Locations: `truth registers[15].field_parts[0].bit_field[6]` ↔ `without registers[15].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | TAP_Z_SOURCE | TAP_Z source |
| `field_description` | 0.0586 | 1.000000 | Z axis involved in tap event. | Indicates Z-axis was source of tap event (1 = involved). |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Z axis not involved in tap."},{"value":"1","value_description":"Z axis involved in tap."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 8: `RESERVED` bits 7:7**

Locations: `truth registers[15].field_parts[0].bit_field[7]` ↔ `without registers[15].field_parts[0].bit_field[0]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | RESERVED | Reserved |
| `field_description` | 0.0586 | 1.000000 | Reserved bit. | "" |
| `bit_start` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | true | true |
| `type_write_read` | 0.0583 | 1.000000 | "" | "" |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Field-part aggregation**

bit_field correctness = mean(0.769076908, 0.769076908, 0.769076908, 0.769076908, 0.769076908, 0.769076908, 0.769076908, 0.978797880) = **0.795292029**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | ACT_TAP_STATUS | ACT_TAP_STATUS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Source of single tap/double tap"} | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Activity and tap status register"} |
| `description` | 0.0693 | 1.000000 | Activity and tap source status. | Source bits for activity and tap, and asleep indicator |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.795292 | [{"name_or_parameter":"ACT_X_SOURCE","field_description":"X axis involved in activity event.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"X axis not involved in activity."},{"value":"1","value_description":"X axis involved in activity."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ACT_Y_SOURCE","field_description":"Y axis involved in activity event.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Y axis not involved in activity."},{"value":"1","value_description":"Y axis involved in activity."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ACT_Z_SOURCE","field_description":"Z axis involved in activity event.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Z axis not involved in activity."},{"value":"1","value_description":"Z axis involved in activity."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ASLEEP","field_description":"Sleep status: 1 asleep, 0 not asleep.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Not asleep."},{"value":"1","value_description":"Asleep."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"TAP_X_SOURCE","field_description":"X axis involved in tap event.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"X axis not involved in tap."},{"value":"1","value_description":"X axis involved in tap."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"TAP_Y_SOURCE","field_description":"Y axis involved in tap event.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Y axis not involved in tap."},{"value":"1","value_description":"Y axis involved in tap."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"TAP_Z_SOURCE","field_description":"Z axis involved in tap event.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Z axis not involved in tap."},{"value":"1","value_description":"Z axis involved in tap."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"RESERVED","field_description":"Reserved bit.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"Reserved","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"ACT_X source","field_description":"Indicates X-axis involvement in activity event (1 = involved).","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ACT_Y source","field_description":"Indicates Y-axis involvement in activity event (1 = involved).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ACT_Z source","field_description":"Indicates Z-axis involvement in activity event (1 = involved).","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Asleep","field_description":"Indicates device is asleep (1) when auto-sleep is configured.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"TAP_X source","field_description":"Indicates X-axis was source of tap event (1 = involved).","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"TAP_Y source","field_description":"Indicates Y-axis was source of tap event (1 = involved).","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"TAP_Z source","field_description":"Indicates Z-axis was source of tap event (1 = involved).","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.795292)/1.0000 = 0.935946876/1.0000 = **0.935946876**`.

### Extracted logical-register aggregation

field_parts correctness = mean(0.935946876) = **0.935946876**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | ACT_TAP_STATUS | ACT_TAP_STATUS |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Source of single tap/double tap"}] | [{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Activity and tap source/status register"}] |
| `register_description` | 0.0564 | 1.000000 | Reports the first axis involved in a tap or activity event and asleep status. | Read-only status indicating which axis caused activity/tap and asleep status. Bits overwritten with new data when new sample available. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.935947 | mean(0.935946876) | [{"register_name":"ACT_TAP_STATUS","physical_address":{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Activity and tap status register"},"description":"Source bits for activity and tap, and asleep indicator","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Reserved","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"ACT_X source","field_description":"Indicates X-axis involvement in activity event (1 = involved).","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ACT_Y source","field_description":"Indicates Y-axis involvement in activity event (1 = involved).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ACT_Z source","field_description":"Indicates Z-axis involvement in activity event (1 = involved).","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Asleep","field_description":"Indicates device is asleep (1) when auto-sleep is configured.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"TAP_X source","field_description":"Indicates X-axis was source of tap event (1 = involved).","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"TAP_Y source","field_description":"Indicates Y-axis was source of tap event (1 = involved).","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"TAP_Z source","field_description":"Indicates Z-axis was source of tap event (1 = involved).","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | No event source; not asleep | "" |

`Q(L_16) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.935947 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.947567332/1.0001 = **0.947472585**`.

## Extracted logical register 17: `BW_RATE`

without location: registers[16]; truth association: truth registers[16] (`BW_RATE`).
Associated physical locations: 0x2C (44).

### Bottom layer: bit fields, then field parts

#### Field part 1: `BW_RATE` at 0x2C (44)

Locations: `truth registers[16].field_parts[0]` ↔ `without registers[16].field_parts[0]`.

**Truth bit field 1: `LOW_POWER` bits 4:4**

Locations: `truth registers[16].field_parts[0].bit_field[0]` ↔ `without registers[16].field_parts[0].bit_field[1]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | LOW_POWER | LOW_POWER |
| `field_description` | 0.0586 | 1.000000 | Power mode selection. | Selects reduced power operation when set (1). |
| `bit_start` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_end` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 1.000000 | [{"value":"0","value_description":"Normal operation."},{"value":"1","value_description":"Reduced-power operation."}] | [{"value":"0","value_description":"Normal operation"},{"value":"1","value_description":"Reduced power operation (higher noise)"}] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Truth bit field 2: `RATE` bits 0:3**

Locations: `truth registers[16].field_parts[0].bit_field[1]` ↔ `without registers[16].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | RATE | Rate |
| `field_description` | 0.0586 | 1.000000 | Output data rate and bandwidth selection; see Table 7 and Table 8 on datasheet page 13. | Output data rate/bandwidth selection (Rate bits D3:D0). See Table 7 for mapping of rate codes to ODR/bandwidth. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_width` | 0.0583 | 1.000000 | 4 | 4 |
| `values` | 0.2097 | 0.000000 | [{"value":"0000 (0x00)","value_description":"0.10 Hz output data rate; 0.05 Hz bandwidth."},{"value":"0001 (0x01)","value_description":"0.20 Hz output data rate; 0.10 Hz bandwidth."},{"value":"0010 (0x02)","value_description":"0.39 Hz output data rate; 0.20 Hz bandwidth."},{"value":"0011 (0x03)","value_description":"0.78 Hz output data rate; 0.39 Hz bandwidth."},{"value":"0100 (0x04)","value_description":"1.56 Hz output data rate; 0.78 Hz bandwidth."},{"value":"0101 (0x05)","value_description":"3.13 Hz output data rate; 1.56 Hz bandwidth."},{"value":"0110 (0x06)","value_description":"6.25 Hz output data rate; 3.13 Hz bandwidth."},{"value":"0111 (0x07)","value_description":"12.5 Hz output data rate; 6.25 Hz bandwidth; low-power mode table entry."},{"value":"1000 (0x08)","value_description":"25 Hz output data rate; 12.5 Hz bandwidth; low-power mode table entry."},{"value":"1001 (0x09)","value_description":"50 Hz output data rate; 25 Hz bandwidth; low-power mode table entry."},{"value":"1010 (0x0A)","value_description":"100 Hz output data rate; 50 Hz bandwidth; default; low-power mode table entry."},{"value":"1011 (0x0B)","value_description":"200 Hz output data rate; 100 Hz bandwidth; low-power mode table entry."},{"value":"1100 (0x0C)","value_description":"400 Hz output data rate; 200 Hz bandwidth; low-power mode table entry."},{"value":"1101 (0x0D)","value_description":"800 Hz output data rate; 400 Hz bandwidth."},{"value":"1110 (0x0E)","value_description":"1600 Hz output data rate; 800 Hz bandwidth."},{"value":"1111 (0x0F)","value_description":"3200 Hz output data rate; 1600 Hz bandwidth."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 3: `RESERVED` bits 5:7**

Locations: `truth registers[16].field_parts[0].bit_field[2]` ↔ `without registers[16].field_parts[0].bit_field[0]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | RESERVED | Reserved |
| `field_description` | 0.0586 | 1.000000 | Reserved bits. | "" |
| `bit_start` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 3 | 3 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | true | true |
| `type_write_read` | 0.0583 | 1.000000 | "" | "" |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000, 0.769076908, 0.978797880) = **0.915958262**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | BW_RATE | BW_RATE |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Data rate and power mode control"} | {"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Data rate and power mode control register"} |
| `description` | 0.0693 | 1.000000 | Data rate and power mode control. | Data rate and power mode control (LOW_POWER + Rate bits) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.915958 | [{"name_or_parameter":"LOW_POWER","field_description":"Power mode selection.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Normal operation."},{"value":"1","value_description":"Reduced-power operation."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"RATE","field_description":"Output data rate and bandwidth selection; see Table 7 and Table 8 on datasheet page 13.","bit_start":0,"bit_end":3,"bit_width":4,"values":[{"value":"0000 (0x00)","value_description":"0.10 Hz output data rate; 0.05 Hz bandwidth."},{"value":"0001 (0x01)","value_description":"0.20 Hz output data rate; 0.10 Hz bandwidth."},{"value":"0010 (0x02)","value_description":"0.39 Hz output data rate; 0.20 Hz bandwidth."},{"value":"0011 (0x03)","value_description":"0.78 Hz output data rate; 0.39 Hz bandwidth."},{"value":"0100 (0x04)","value_description":"1.56 Hz output data rate; 0.78 Hz bandwidth."},{"value":"0101 (0x05)","value_description":"3.13 Hz output data rate; 1.56 Hz bandwidth."},{"value":"0110 (0x06)","value_description":"6.25 Hz output data rate; 3.13 Hz bandwidth."},{"value":"0111 (0x07)","value_description":"12.5 Hz output data rate; 6.25 Hz bandwidth; low-power mode table entry."},{"value":"1000 (0x08)","value_description":"25 Hz output data rate; 12.5 Hz bandwidth; low-power mode table entry."},{"value":"1001 (0x09)","value_description":"50 Hz output data rate; 25 Hz bandwidth; low-power mode table entry."},{"value":"1010 (0x0A)","value_description":"100 Hz output data rate; 50 Hz bandwidth; default; low-power mode table entry."},{"value":"1011 (0x0B)","value_description":"200 Hz output data rate; 100 Hz bandwidth; low-power mode table entry."},{"value":"1100 (0x0C)","value_description":"400 Hz output data rate; 200 Hz bandwidth; low-power mode table entry."},{"value":"1101 (0x0D)","value_description":"800 Hz output data rate; 400 Hz bandwidth."},{"value":"1110 (0x0E)","value_description":"1600 Hz output data rate; 800 Hz bandwidth."},{"value":"1111 (0x0F)","value_description":"3200 Hz output data rate; 1600 Hz bandwidth."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"RESERVED","field_description":"Reserved bits.","bit_start":5,"bit_end":7,"bit_width":3,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"Reserved","field_description":"","bit_start":5,"bit_end":7,"bit_width":3,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"LOW_POWER","field_description":"Selects reduced power operation when set (1).","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Normal operation"},{"value":"1","value_description":"Reduced power operation (higher noise)"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Rate","field_description":"Output data rate/bandwidth selection (Rate bits D3:D0). See Table 7 for mapping of rate codes to ODR/bandwidth.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.915958)/1.0000 = 0.973703340/1.0000 = **0.973703340**`.

### Extracted logical-register aggregation

field_parts correctness = mean(0.973703340) = **0.973703340**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | BW_RATE | BW_RATE |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Data rate and power mode control"}] | [{"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Data rate and power mode control register"}] |
| `register_description` | 0.0564 | 1.000000 | Controls output data rate, bandwidth and low-power mode. | Selects device bandwidth and output data rate. Bit D4 selects low-power mode (0 = normal, 1 = reduced power). Rate bits (D3:D0) select ODR per Table 7. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.973703 | mean(0.973703340) | [{"register_name":"BW_RATE","physical_address":{"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Data rate and power mode control register"},"description":"Data rate and power mode control (LOW_POWER + Rate bits)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Reserved","field_description":"","bit_start":5,"bit_end":7,"bit_width":3,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"LOW_POWER","field_description":"Selects reduced power operation when set (1).","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Normal operation"},{"value":"1","value_description":"Reduced power operation (higher noise)"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Rate","field_description":"Output data rate/bandwidth selection (Rate bits D3:D0). See Table 7 for mapping of rate codes to ODR/bandwidth.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00001010 | 00001010 |
| `default_value_description` | 0.0334 | 0.000000 | 100 Hz, normal power | "" |

`Q(L_17) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.973703 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.958845188/1.0001 = **0.958749313**`.

## Extracted logical register 18: `POWER_CTL`

without location: registers[17]; truth association: truth registers[17] (`POWER_CTL`).
Associated physical locations: 0x2D (45).

### Bottom layer: bit fields, then field parts

#### Field part 1: `POWER_CTL` at 0x2D (45)

Locations: `truth registers[17].field_parts[0]` ↔ `without registers[17].field_parts[0]`.

**Truth bit field 1: `LINK` bits 5:5**

Locations: `truth registers[17].field_parts[0].bit_field[0]` ↔ `without registers[17].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | LINK | Link |
| `field_description` | 0.0586 | 1.000000 | Serially links activity and inactivity functions. | Serially links activity and inactivity functions (1 = link). |
| `bit_start` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_end` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Activity and inactivity functions operate concurrently."},{"value":"1","value_description":"Activity and inactivity functions are serially linked."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 2: `AUTO_SLEEP` bits 4:4**

Locations: `truth registers[17].field_parts[0].bit_field[1]` ↔ `without registers[17].field_parts[0].bit_field[2]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | AUTO_SLEEP | AUTO_SLEEP |
| `field_description` | 0.0586 | 1.000000 | Enables automatic sleep when linked inactivity is detected. | Enable automatic switching to sleep when inactivity detected and link bit set (1 = enabled). |
| `bit_start` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_end` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Automatic sleep disabled."},{"value":"1","value_description":"Automatic sleep enabled when linked inactivity is detected."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 3: `MEASURE` bits 3:3**

Locations: `truth registers[17].field_parts[0].bit_field[2]` ↔ `without registers[17].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | MEASURE | Measure |
| `field_description` | 0.0586 | 1.000000 | 0 standby, 1 measurement mode. | Measurement mode (1 = measurement, 0 = standby). |
| `bit_start` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_end` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 1.000000 | [{"value":"0","value_description":"Standby mode."},{"value":"1","value_description":"Measurement mode."}] | [{"value":"0","value_description":"Standby mode"},{"value":"1","value_description":"Measurement mode"}] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Truth bit field 4: `SLEEP` bits 2:2**

Locations: `truth registers[17].field_parts[0].bit_field[3]` ↔ `without registers[17].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | SLEEP | Sleep |
| `field_description` | 0.0586 | 1.000000 | 0 normal, 1 sleep mode. | Sleep mode control (1 = sleep). In sleep, only activity function operates; sampling rate set by wakeup bits. |
| `bit_start` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_end` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Normal operation."},{"value":"1","value_description":"Sleep mode."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 5: `WAKEUP` bits 0:1**

Locations: `truth registers[17].field_parts[0].bit_field[4]` ↔ `without registers[17].field_parts[0].bit_field[5]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | WAKEUP | Wakeup |
| `field_description` | 0.0586 | 1.000000 | Sleep-mode reading frequency. | Wakeup bits D1:D0: sampling frequency in sleep mode per Table 27. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_width` | 0.0583 | 1.000000 | 2 | 2 |
| `values` | 0.2097 | 1.000000 | [{"value":"00","value_description":"8 Hz."},{"value":"01","value_description":"4 Hz."},{"value":"10","value_description":"2 Hz."},{"value":"11","value_description":"1 Hz."}] | [{"value":"00","value_description":"8 Hz"},{"value":"01","value_description":"4 Hz"},{"value":"10","value_description":"2 Hz"},{"value":"11","value_description":"1 Hz"}] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Truth bit field 6: `RESERVED` bits 6:7**

Locations: `truth registers[17].field_parts[0].bit_field[5]` ↔ `without registers[17].field_parts[0].bit_field[0]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | RESERVED | Reserved |
| `field_description` | 0.0586 | 1.000000 | Reserved bits. | "" |
| `bit_start` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 2 | 2 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | true | true |
| `type_write_read` | 0.0583 | 1.000000 | "" | "" |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Field-part aggregation**

bit_field correctness = mean(0.769076908, 0.790279028, 0.978797880, 0.769076908, 0.978797880, 0.978797880) = **0.877471080**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | POWER_CTL | POWER_CTL |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Power-saving features control"} | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Power-saving and measurement control register"} |
| `description` | 0.0693 | 1.000000 | Power-control bits. | Power control: link, auto-sleep, measure, sleep, wakeup frequency |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.877471 | [{"name_or_parameter":"LINK","field_description":"Serially links activity and inactivity functions.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Activity and inactivity functions operate concurrently."},{"value":"1","value_description":"Activity and inactivity functions are serially linked."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"AUTO_SLEEP","field_description":"Enables automatic sleep when linked inactivity is detected.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Automatic sleep disabled."},{"value":"1","value_description":"Automatic sleep enabled when linked inactivity is detected."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"MEASURE","field_description":"0 standby, 1 measurement mode.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Standby mode."},{"value":"1","value_description":"Measurement mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SLEEP","field_description":"0 normal, 1 sleep mode.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Normal operation."},{"value":"1","value_description":"Sleep mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"WAKEUP","field_description":"Sleep-mode reading frequency.","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"00","value_description":"8 Hz."},{"value":"01","value_description":"4 Hz."},{"value":"10","value_description":"2 Hz."},{"value":"11","value_description":"1 Hz."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"RESERVED","field_description":"Reserved bits.","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"Reserved","field_description":"","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Link","field_description":"Serially links activity and inactivity functions (1 = link).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"AUTO_SLEEP","field_description":"Enable automatic switching to sleep when inactivity detected and link bit set (1 = enabled).","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Measure","field_description":"Measurement mode (1 = measurement, 0 = standby).","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Standby mode"},{"value":"1","value_description":"Measurement mode"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Sleep","field_description":"Sleep mode control (1 = sleep). In sleep, only activity function operates; sampling rate set by wakeup bits.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Wakeup","field_description":"Wakeup bits D1:D0: sampling frequency in sleep mode per Table 27.","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"00","value_description":"8 Hz"},{"value":"01","value_description":"4 Hz"},{"value":"10","value_description":"2 Hz"},{"value":"11","value_description":"1 Hz"}],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.877471)/1.0000 = 0.961660701/1.0000 = **0.961660701**`.

### Extracted logical-register aggregation

field_parts correctness = mean(0.961660701) = **0.961660701**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | POWER_CTL | POWER_CTL |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Power-saving features control"}] | [{"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Power-saving and measurement control register"}] |
| `register_description` | 0.0564 | 1.000000 | Controls link, autosleep, measurement, sleep and wakeup behavior. | Controls power features: link, auto-sleep, measure (measurement/standby), sleep, and wakeup sampling frequency bits. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.961661 | mean(0.961660701) | [{"register_name":"POWER_CTL","physical_address":{"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Power-saving and measurement control register"},"description":"Power control: link, auto-sleep, measure, sleep, wakeup frequency","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Reserved","field_description":"","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Link","field_description":"Serially links activity and inactivity functions (1 = link).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"AUTO_SLEEP","field_description":"Enable automatic switching to sleep when inactivity detected and link bit set (1 = enabled).","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Measure","field_description":"Measurement mode (1 = measurement, 0 = standby).","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Standby mode"},{"value":"1","value_description":"Measurement mode"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Sleep","field_description":"Sleep mode control (1 = sleep). In sleep, only activity function operates; sampling rate set by wakeup bits.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Wakeup","field_description":"Wakeup bits D1:D0: sampling frequency in sleep mode per Table 27.","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"00","value_description":"8 Hz"},{"value":"01","value_description":"4 Hz"},{"value":"10","value_description":"2 Hz"},{"value":"11","value_description":"1 Hz"}],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | Standby, normal mode | "" |

`Q(L_18) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.961661 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.955248051/1.0001 = **0.955152536**`.

## Extracted logical register 19: `INT_ENABLE`

without location: registers[18]; truth association: truth registers[18] (`INT_ENABLE`).
Associated physical locations: 0x2E (46).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_ENABLE` at 0x2E (46)

Locations: `truth registers[18].field_parts[0]` ↔ `without registers[18].field_parts[0]`.

**Truth bit field 1: `DATA_READY` bits 7:7**

Locations: `truth registers[18].field_parts[0].bit_field[0]` ↔ `without registers[18].field_parts[0].bit_field[0]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DATA_READY | DATA_READY |
| `field_description` | 0.0586 | 1.000000 | Enable DATA_READY interrupt output. | Enable DATA_READY interrupt output. |
| `bit_start` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 2: `SINGLE_TAP` bits 6:6**

Locations: `truth registers[18].field_parts[0].bit_field[1]` ↔ `without registers[18].field_parts[0].bit_field[1]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | SINGLE_TAP | SINGLE_TAP |
| `field_description` | 0.0586 | 1.000000 | Enable single-tap interrupt. | Enable single tap interrupt output. |
| `bit_start` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_end` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 3: `DOUBLE_TAP` bits 5:5**

Locations: `truth registers[18].field_parts[0].bit_field[2]` ↔ `without registers[18].field_parts[0].bit_field[2]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DOUBLE_TAP | DOUBLE_TAP |
| `field_description` | 0.0586 | 1.000000 | Enable double-tap interrupt. | Enable double tap interrupt output. |
| `bit_start` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_end` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 4: `ACTIVITY` bits 4:4**

Locations: `truth registers[18].field_parts[0].bit_field[3]` ↔ `without registers[18].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | ACTIVITY | Activity |
| `field_description` | 0.0586 | 1.000000 | Enable activity interrupt. | Enable activity interrupt output. |
| `bit_start` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_end` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 5: `INACTIVITY` bits 3:3**

Locations: `truth registers[18].field_parts[0].bit_field[4]` ↔ `without registers[18].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | INACTIVITY | Inactivity |
| `field_description` | 0.0586 | 1.000000 | Enable inactivity interrupt. | Enable inactivity interrupt output. |
| `bit_start` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_end` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 6: `FREE_FALL` bits 2:2**

Locations: `truth registers[18].field_parts[0].bit_field[5]` ↔ `without registers[18].field_parts[0].bit_field[5]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | FREE_FALL | FREE_FALL |
| `field_description` | 0.0586 | 1.000000 | Enable free-fall interrupt. | Enable free-fall interrupt output. |
| `bit_start` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_end` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 7: `WATERMARK` bits 1:1**

Locations: `truth registers[18].field_parts[0].bit_field[6]` ↔ `without registers[18].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | WATERMARK | Watermark |
| `field_description` | 0.0586 | 1.000000 | Enable watermark interrupt output. | Enable FIFO watermark interrupt output. |
| `bit_start` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_end` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 8: `OVERRUN` bits 0:0**

Locations: `truth registers[18].field_parts[0].bit_field[7]` ↔ `without registers[18].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | OVERRUN | Overrun |
| `field_description` | 0.0586 | 1.000000 | Enable overrun interrupt output. | Enable data overrun interrupt output. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Field-part aggregation**

bit_field correctness = mean(0.790279028, 0.790279028, 0.790279028, 0.769076908, 0.769076908, 0.790279028, 0.769076908, 0.769076908) = **0.779677968**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | INT_ENABLE | INT_ENABLE |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":"Interrupt enable control"} | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":"Interrupt enable control register"} |
| `description` | 0.0693 | 1.000000 | Interrupt enable control. | Enable bits for interrupt sources |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.779678 | [{"name_or_parameter":"DATA_READY","field_description":"Enable DATA_READY interrupt output.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SINGLE_TAP","field_description":"Enable single-tap interrupt.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"DOUBLE_TAP","field_description":"Enable double-tap interrupt.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ACTIVITY","field_description":"Enable activity interrupt.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACTIVITY","field_description":"Enable inactivity interrupt.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FREE_FALL","field_description":"Enable free-fall interrupt.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"WATERMARK","field_description":"Enable watermark interrupt output.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"OVERRUN","field_description":"Enable overrun interrupt output.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"DATA_READY","field_description":"Enable DATA_READY interrupt output.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SINGLE_TAP","field_description":"Enable single tap interrupt output.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"DOUBLE_TAP","field_description":"Enable double tap interrupt output.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Activity","field_description":"Enable activity interrupt output.","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Inactivity","field_description":"Enable inactivity interrupt output.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FREE_FALL","field_description":"Enable free-fall interrupt output.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Watermark","field_description":"Enable FIFO watermark interrupt output.","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Overrun","field_description":"Enable data overrun interrupt output.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.779678)/1.0000 = 0.931061236/1.0000 = **0.931061236**`.

### Extracted logical-register aggregation

field_parts correctness = mean(0.931061236) = **0.931061236**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | INT_ENABLE | INT_ENABLE |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x2E","decimal":"46","bank":"","page":"","description":"Interrupt enable control"}] | [{"hex":"0x2E","decimal":"46","bank":"","page":"","description":"Interrupt enable control register"}] |
| `register_description` | 0.0564 | 1.000000 | Enables interrupt generation for the listed functions. | Enables specific interrupt sources to drive the interrupt outputs. Setting bit = 1 enables that interrupt output. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.931061 | mean(0.931061236) | [{"register_name":"INT_ENABLE","physical_address":{"hex":"0x2E","decimal":"46","bank":"","page":"","description":"Interrupt enable control register"},"description":"Enable bits for interrupt sources","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"DATA_READY","field_description":"Enable DATA_READY interrupt output.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SINGLE_TAP","field_description":"Enable single tap interrupt output.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"DOUBLE_TAP","field_description":"Enable double tap interrupt output.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Activity","field_description":"Enable activity interrupt output.","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Inactivity","field_description":"Enable inactivity interrupt output.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FREE_FALL","field_description":"Enable free-fall interrupt output.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Watermark","field_description":"Enable FIFO watermark interrupt output.","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Overrun","field_description":"Enable data overrun interrupt output.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | All interrupts disabled | "" |

`Q(L_19) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.931061 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.946107991/1.0001 = **0.946013390**`.

## Extracted logical register 20: `INT_MAP`

without location: registers[19]; truth association: truth registers[19] (`INT_MAP`).
Associated physical locations: 0x2F (47).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_MAP` at 0x2F (47)

Locations: `truth registers[19].field_parts[0]` ↔ `without registers[19].field_parts[0]`.

**Truth bit field 1: `DATA_READY` bits 7:7**

Locations: `truth registers[19].field_parts[0].bit_field[0]` ↔ `without registers[19].field_parts[0].bit_field[0]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DATA_READY | DATA_READY |
| `field_description` | 0.0586 | 1.000000 | Interrupt pin mapping. | Maps DATA_READY interrupt to INT2 when set (1). |
| `bit_start` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 2: `SINGLE_TAP` bits 6:6**

Locations: `truth registers[19].field_parts[0].bit_field[1]` ↔ `without registers[19].field_parts[0].bit_field[1]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | SINGLE_TAP | SINGLE_TAP |
| `field_description` | 0.0586 | 1.000000 | Interrupt pin mapping. | Maps SINGLE_TAP interrupt to INT2 when set (1). |
| `bit_start` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_end` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 3: `DOUBLE_TAP` bits 5:5**

Locations: `truth registers[19].field_parts[0].bit_field[2]` ↔ `without registers[19].field_parts[0].bit_field[2]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DOUBLE_TAP | DOUBLE_TAP |
| `field_description` | 0.0586 | 1.000000 | Interrupt pin mapping. | Maps DOUBLE_TAP interrupt to INT2 when set (1). |
| `bit_start` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_end` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 4: `ACTIVITY` bits 4:4**

Locations: `truth registers[19].field_parts[0].bit_field[3]` ↔ `without registers[19].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | ACTIVITY | Activity |
| `field_description` | 0.0586 | 1.000000 | Interrupt pin mapping. | Maps Activity interrupt to INT2 when set (1). |
| `bit_start` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_end` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 5: `INACTIVITY` bits 3:3**

Locations: `truth registers[19].field_parts[0].bit_field[4]` ↔ `without registers[19].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | INACTIVITY | Inactivity |
| `field_description` | 0.0586 | 1.000000 | Interrupt pin mapping. | Maps Inactivity interrupt to INT2 when set (1). |
| `bit_start` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_end` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 6: `FREE_FALL` bits 2:2**

Locations: `truth registers[19].field_parts[0].bit_field[5]` ↔ `without registers[19].field_parts[0].bit_field[5]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | FREE_FALL | FREE_FALL |
| `field_description` | 0.0586 | 1.000000 | Interrupt pin mapping. | Maps FREE_FALL interrupt to INT2 when set (1). |
| `bit_start` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_end` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 7: `WATERMARK` bits 1:1**

Locations: `truth registers[19].field_parts[0].bit_field[6]` ↔ `without registers[19].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | WATERMARK | Watermark |
| `field_description` | 0.0586 | 1.000000 | Interrupt pin mapping. | Maps Watermark interrupt to INT2 when set (1). |
| `bit_start` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_end` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 8: `OVERRUN` bits 0:0**

Locations: `truth registers[19].field_parts[0].bit_field[7]` ↔ `without registers[19].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | OVERRUN | Overrun |
| `field_description` | 0.0586 | 1.000000 | Interrupt pin mapping. | Maps Overrun interrupt to INT2 when set (1). |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Field-part aggregation**

bit_field correctness = mean(0.790279028, 0.790279028, 0.790279028, 0.769076908, 0.769076908, 0.790279028, 0.769076908, 0.769076908) = **0.779677968**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | INT_MAP | INT_MAP |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":"Interrupt mapping control"} | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":"Interrupt mapping control register"} |
| `description` | 0.0693 | 1.000000 | Interrupt mapping. | Map interrupts to INT1 or INT2 (0 = INT1, 1 = INT2) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.779678 | [{"name_or_parameter":"DATA_READY","field_description":"Interrupt pin mapping.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SINGLE_TAP","field_description":"Interrupt pin mapping.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"DOUBLE_TAP","field_description":"Interrupt pin mapping.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ACTIVITY","field_description":"Interrupt pin mapping.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INACTIVITY","field_description":"Interrupt pin mapping.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FREE_FALL","field_description":"Interrupt pin mapping.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"WATERMARK","field_description":"Interrupt pin mapping.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"OVERRUN","field_description":"Interrupt pin mapping.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"DATA_READY","field_description":"Maps DATA_READY interrupt to INT2 when set (1).","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SINGLE_TAP","field_description":"Maps SINGLE_TAP interrupt to INT2 when set (1).","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"DOUBLE_TAP","field_description":"Maps DOUBLE_TAP interrupt to INT2 when set (1).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Activity","field_description":"Maps Activity interrupt to INT2 when set (1).","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Inactivity","field_description":"Maps Inactivity interrupt to INT2 when set (1).","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FREE_FALL","field_description":"Maps FREE_FALL interrupt to INT2 when set (1).","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Watermark","field_description":"Maps Watermark interrupt to INT2 when set (1).","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Overrun","field_description":"Maps Overrun interrupt to INT2 when set (1).","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.779678)/1.0000 = 0.931061236/1.0000 = **0.931061236**`.

### Extracted logical-register aggregation

field_parts correctness = mean(0.931061236) = **0.931061236**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | INT_MAP | INT_MAP |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x2F","decimal":"47","bank":"","page":"","description":"Interrupt mapping control"}] | [{"hex":"0x2F","decimal":"47","bank":"","page":"","description":"Interrupt mapping control register"}] |
| `register_description` | 0.0564 | 1.000000 | Maps each interrupt to INT1 or INT2; 0 selects INT1 and 1 selects INT2. | Selects destination interrupt pin for each interrupt (0 -> INT1, 1 -> INT2). All selected interrupts for a pin are OR'ed. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.931061 | mean(0.931061236) | [{"register_name":"INT_MAP","physical_address":{"hex":"0x2F","decimal":"47","bank":"","page":"","description":"Interrupt mapping control register"},"description":"Map interrupts to INT1 or INT2 (0 = INT1, 1 = INT2)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"DATA_READY","field_description":"Maps DATA_READY interrupt to INT2 when set (1).","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SINGLE_TAP","field_description":"Maps SINGLE_TAP interrupt to INT2 when set (1).","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"DOUBLE_TAP","field_description":"Maps DOUBLE_TAP interrupt to INT2 when set (1).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Activity","field_description":"Maps Activity interrupt to INT2 when set (1).","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Inactivity","field_description":"Maps Inactivity interrupt to INT2 when set (1).","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FREE_FALL","field_description":"Maps FREE_FALL interrupt to INT2 when set (1).","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Watermark","field_description":"Maps Watermark interrupt to INT2 when set (1).","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Overrun","field_description":"Maps Overrun interrupt to INT2 when set (1).","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | All interrupts mapped to INT1 | "" |

`Q(L_20) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.931061 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.946107991/1.0001 = **0.946013390**`.

## Extracted logical register 21: `INT_SOURCE`

without location: registers[20]; truth association: truth registers[20] (`INT_SOURCE`).
Associated physical locations: 0x30 (48).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_SOURCE` at 0x30 (48)

Locations: `truth registers[20].field_parts[0]` ↔ `without registers[20].field_parts[0]`.

**Truth bit field 1: `DATA_READY` bits 7:7**

Locations: `truth registers[20].field_parts[0].bit_field[0]` ↔ `without registers[20].field_parts[0].bit_field[0]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DATA_READY | DATA_READY |
| `field_description` | 0.0586 | 1.000000 | DATA_READY event occurred. | New data available. |
| `bit_start` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 2: `SINGLE_TAP` bits 6:6**

Locations: `truth registers[20].field_parts[0].bit_field[1]` ↔ `without registers[20].field_parts[0].bit_field[1]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | SINGLE_TAP | SINGLE_TAP |
| `field_description` | 0.0586 | 1.000000 | Single-tap event occurred. | Single tap event occurred. |
| `bit_start` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_end` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 3: `DOUBLE_TAP` bits 5:5**

Locations: `truth registers[20].field_parts[0].bit_field[2]` ↔ `without registers[20].field_parts[0].bit_field[2]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DOUBLE_TAP | DOUBLE_TAP |
| `field_description` | 0.0586 | 1.000000 | Double-tap event occurred. | Double tap event occurred. |
| `bit_start` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_end` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 4: `ACTIVITY` bits 4:4**

Locations: `truth registers[20].field_parts[0].bit_field[3]` ↔ `without registers[20].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | ACTIVITY | Activity |
| `field_description` | 0.0586 | 1.000000 | Activity event occurred. | Activity event occurred. |
| `bit_start` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_end` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 5: `INACTIVITY` bits 3:3**

Locations: `truth registers[20].field_parts[0].bit_field[4]` ↔ `without registers[20].field_parts[0].bit_field[4]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | INACTIVITY | Inactivity |
| `field_description` | 0.0586 | 1.000000 | Inactivity event occurred. | Inactivity event occurred. |
| `bit_start` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_end` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 6: `FREE_FALL` bits 2:2**

Locations: `truth registers[20].field_parts[0].bit_field[5]` ↔ `without registers[20].field_parts[0].bit_field[5]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | FREE_FALL | FREE_FALL |
| `field_description` | 0.0586 | 1.000000 | Free-fall event occurred. | Free-fall event occurred. |
| `bit_start` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_end` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 7: `WATERMARK` bits 1:1**

Locations: `truth registers[20].field_parts[0].bit_field[6]` ↔ `without registers[20].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | WATERMARK | Watermark |
| `field_description` | 0.0586 | 1.000000 | FIFO watermark event occurred. | FIFO watermark condition occurred. |
| `bit_start` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_end` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 8: `OVERRUN` bits 0:0**

Locations: `truth registers[20].field_parts[0].bit_field[7]` ↔ `without registers[20].field_parts[0].bit_field[7]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | OVERRUN | Overrun |
| `field_description` | 0.0586 | 1.000000 | FIFO overrun event occurred. | Data overrun occurred. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Field-part aggregation**

bit_field correctness = mean(0.790279028, 0.790279028, 0.790279028, 0.769076908, 0.769076908, 0.790279028, 0.769076908, 0.769076908) = **0.779677968**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | INT_SOURCE | INT_SOURCE |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x30","decimal":"48","bank":"","page":"","description":"Source of interrupts"} | {"hex":"0x30","decimal":"48","bank":"","page":"","description":"Interrupt source register (read only)"} |
| `description` | 0.0693 | 1.000000 | Interrupt source status. | Indicates which interrupts have occurred (read to clear as described). |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.779678 | [{"name_or_parameter":"DATA_READY","field_description":"DATA_READY event occurred.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"SINGLE_TAP","field_description":"Single-tap event occurred.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"DOUBLE_TAP","field_description":"Double-tap event occurred.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ACTIVITY","field_description":"Activity event occurred.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"INACTIVITY","field_description":"Inactivity event occurred.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"FREE_FALL","field_description":"Free-fall event occurred.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"WATERMARK","field_description":"FIFO watermark event occurred.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"OVERRUN","field_description":"FIFO overrun event occurred.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"DATA_READY","field_description":"New data available.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"SINGLE_TAP","field_description":"Single tap event occurred.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"DOUBLE_TAP","field_description":"Double tap event occurred.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Activity","field_description":"Activity event occurred.","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Inactivity","field_description":"Inactivity event occurred.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"FREE_FALL","field_description":"Free-fall event occurred.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Watermark","field_description":"FIFO watermark condition occurred.","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Overrun","field_description":"Data overrun occurred.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.779678)/1.0000 = 0.931061236/1.0000 = **0.931061236**`.

### Extracted logical-register aggregation

field_parts correctness = mean(0.931061236) = **0.931061236**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | INT_SOURCE | INT_SOURCE |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x30","decimal":"48","bank":"","page":"","description":"Source of interrupts"}] | [{"hex":"0x30","decimal":"48","bank":"","page":"","description":"Interrupt source register (read only)"}] |
| `register_description` | 0.0564 | 1.000000 | Reports which interrupt functions have triggered; event bits are cleared by reading this register or data registers as specified. | Read-only status of interrupt sources (bit = 1 indicates event). DATA_READY, watermark, and overrun bits set regardless of INT_ENABLE; cleared by reads as specified. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.931061 | mean(0.931061236) | [{"register_name":"INT_SOURCE","physical_address":{"hex":"0x30","decimal":"48","bank":"","page":"","description":"Interrupt source register (read only)"},"description":"Indicates which interrupts have occurred (read to clear as described).","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"DATA_READY","field_description":"New data available.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"SINGLE_TAP","field_description":"Single tap event occurred.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"DOUBLE_TAP","field_description":"Double tap event occurred.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Activity","field_description":"Activity event occurred.","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Inactivity","field_description":"Inactivity event occurred.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"FREE_FALL","field_description":"Free-fall event occurred.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Watermark","field_description":"FIFO watermark condition occurred.","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Overrun","field_description":"Data overrun occurred.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000010 | 00000010 |
| `default_value_description` | 0.0334 | 0.000000 | Watermark status bit set in reset value per register map | "" |

`Q(L_21) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.931061 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.946107991/1.0001 = **0.946013390**`.

## Extracted logical register 22: `DATA_FORMAT`

without location: registers[21]; truth association: truth registers[21] (`DATA_FORMAT`).
Associated physical locations: 0x31 (49).

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATA_FORMAT` at 0x31 (49)

Locations: `truth registers[21].field_parts[0]` ↔ `without registers[21].field_parts[0]`.

**Truth bit field 1: `SELF_TEST` bits 7:7**

Locations: `truth registers[21].field_parts[0].bit_field[0]` ↔ `without registers[21].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | SELF_TEST | SELF_TEST |
| `field_description` | 0.0586 | 1.000000 | Applies self-test force when set. | Apply self-test force when set (1). |
| `bit_start` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 1.000000 | [{"value":"0","value_description":"Self-test force disabled."},{"value":"1","value_description":"Self-test force enabled."}] | [{"value":"0","value_description":"Self-test disabled"},{"value":"1","value_description":"Self-test enabled"}] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Truth bit field 2: `SPI` bits 6:6**

Locations: `truth registers[21].field_parts[0].bit_field[1]` ↔ `without registers[21].field_parts[0].bit_field[1]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | SPI | SPI |
| `field_description` | 0.0586 | 1.000000 | SPI mode selection: 0 four-wire, 1 three-wire. | Select SPI mode: 1 = 3-wire, 0 = 4-wire. |
| `bit_start` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_end` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 1.000000 | [{"value":"0","value_description":"Four-wire SPI mode."},{"value":"1","value_description":"Three-wire SPI mode."}] | [{"value":"0","value_description":"4-wire SPI"},{"value":"1","value_description":"3-wire SPI"}] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Truth bit field 3: `INT_INVERT` bits 5:5**

Locations: `truth registers[21].field_parts[0].bit_field[2]` ↔ `without registers[21].field_parts[0].bit_field[2]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | INT_INVERT | INT_INVERT |
| `field_description` | 0.0586 | 1.000000 | Interrupt polarity: 0 active high, 1 active low. | Interrupt polarity: 0 = active high, 1 = active low. |
| `bit_start` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_end` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 1.000000 | [{"value":"0","value_description":"Active-high interrupts."},{"value":"1","value_description":"Active-low interrupts."}] | [{"value":"0","value_description":"Interrupts active high"},{"value":"1","value_description":"Interrupts active low"}] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Truth bit field 4: `FULL_RES` bits 3:3**

Locations: `truth registers[21].field_parts[0].bit_field[3]` ↔ `without registers[21].field_parts[0].bit_field[4]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | FULL_RES | FULL_RES |
| `field_description` | 0.0586 | 1.000000 | Full-resolution mode selection. | Full resolution mode when set (output resolution increases with range to maintain 4 mg/LSB). |
| `bit_start` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_end` | 0.2594 | 1.000000 | 3 | 3 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 1.000000 | [{"value":"0","value_description":"10-bit mode."},{"value":"1","value_description":"Full-resolution mode."}] | [{"value":"0","value_description":"10-bit fixed mode"},{"value":"1","value_description":"Full-resolution mode"}] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Truth bit field 5: `JUSTIFY` bits 2:2**

Locations: `truth registers[21].field_parts[0].bit_field[4]` ↔ `without registers[21].field_parts[0].bit_field[5]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | JUSTIFY | Justify |
| `field_description` | 0.0586 | 1.000000 | Data justification: 0 right-justified with sign extension, 1 left-justified. | Data justification: 0 = right-justified (sign-extended), 1 = left-justified (MSB). |
| `bit_start` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_end` | 0.2594 | 1.000000 | 2 | 2 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 1.000000 | [{"value":"0","value_description":"Right-justified with sign extension."},{"value":"1","value_description":"Left-justified."}] | [{"value":"0","value_description":"Right-justified (sign-extended)"},{"value":"1","value_description":"Left-justified (MSB)"}] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Truth bit field 6: `RANGE` bits 0:1**

Locations: `truth registers[21].field_parts[0].bit_field[5]` ↔ `without registers[21].field_parts[0].bit_field[6]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | RANGE | Range |
| `field_description` | 0.0586 | 1.000000 | Measurement range selection. | g range selection (D1:D0): 00=±2g, 01=±4g, 10=±8g, 11=±16g. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 1 | 1 |
| `bit_width` | 0.0583 | 1.000000 | 2 | 2 |
| `values` | 0.2097 | 1.000000 | [{"value":"00","value_description":"+/-2 g."},{"value":"01","value_description":"+/-4 g."},{"value":"10","value_description":"+/-8 g."},{"value":"11","value_description":"+/-16 g."}] | [{"value":"00","value_description":"±2 g"},{"value":"01","value_description":"±4 g"},{"value":"10","value_description":"±8 g"},{"value":"11","value_description":"±16 g"}] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Truth bit field 7: `RESERVED` bits 4:4**

Locations: `truth registers[21].field_parts[0].bit_field[6]` ↔ `without registers[21].field_parts[0].bit_field[3]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | RESERVED | Reserved |
| `field_description` | 0.0586 | 1.000000 | Reserved bit. | "" |
| `bit_start` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_end` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | true | true |
| `type_write_read` | 0.0583 | 1.000000 | "" | "" |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000, 1.000000000, 1.000000000, 1.000000000, 0.978797880, 0.978797880, 0.978797880) = **0.990913377**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | DATA_FORMAT | DATA_FORMAT |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x31","decimal":"49","bank":"","page":"","description":"Data format control"} | {"hex":"0x31","decimal":"49","bank":"","page":"","description":"Data format control register"} |
| `description` | 0.0693 | 1.000000 | Data format control. | Controls self-test, SPI mode, interrupt polarity, resolution, justification and range |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.990913 | [{"name_or_parameter":"SELF_TEST","field_description":"Applies self-test force when set.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Self-test force disabled."},{"value":"1","value_description":"Self-test force enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SPI","field_description":"SPI mode selection: 0 four-wire, 1 three-wire.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Four-wire SPI mode."},{"value":"1","value_description":"Three-wire SPI mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INT_INVERT","field_description":"Interrupt polarity: 0 active high, 1 active low.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Active-high interrupts."},{"value":"1","value_description":"Active-low interrupts."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FULL_RES","field_description":"Full-resolution mode selection.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"10-bit mode."},{"value":"1","value_description":"Full-resolution mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"JUSTIFY","field_description":"Data justification: 0 right-justified with sign extension, 1 left-justified.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Right-justified with sign extension."},{"value":"1","value_description":"Left-justified."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"RANGE","field_description":"Measurement range selection.","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"00","value_description":"+/-2 g."},{"value":"01","value_description":"+/-4 g."},{"value":"10","value_description":"+/-8 g."},{"value":"11","value_description":"+/-16 g."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"RESERVED","field_description":"Reserved bit.","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"SELF_TEST","field_description":"Apply self-test force when set (1).","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Self-test disabled"},{"value":"1","value_description":"Self-test enabled"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SPI","field_description":"Select SPI mode: 1 = 3-wire, 0 = 4-wire.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"4-wire SPI"},{"value":"1","value_description":"3-wire SPI"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INT_INVERT","field_description":"Interrupt polarity: 0 = active high, 1 = active low.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Interrupts active high"},{"value":"1","value_description":"Interrupts active low"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"FULL_RES","field_description":"Full resolution mode when set (output resolution increases with range to maintain 4 mg/LSB).","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"10-bit fixed mode"},{"value":"1","value_description":"Full-resolution mode"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Justify","field_description":"Data justification: 0 = right-justified (sign-extended), 1 = left-justified (MSB).","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Right-justified (sign-extended)"},{"value":"1","value_description":"Left-justified (MSB)"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Range","field_description":"g range selection (D1:D0): 00=±2g, 01=±4g, 10=±8g, 11=±16g.","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"00","value_description":"±2 g"},{"value":"01","value_description":"±4 g"},{"value":"10","value_description":"±8 g"},{"value":"11","value_description":"±16 g"}],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.990913)/1.0000 = 0.997156796/1.0000 = **0.997156796**`.

### Extracted logical-register aggregation

field_parts correctness = mean(0.997156796) = **0.997156796**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | DATA_FORMAT | DATA_FORMAT |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x31","decimal":"49","bank":"","page":"","description":"Data format control"}] | [{"hex":"0x31","decimal":"49","bank":"","page":"","description":"Data format control register"}] |
| `register_description` | 0.0564 | 1.000000 | Controls the presentation of output data. | Controls data presentation: self-test, SPI mode, interrupt polarity, full-resolution, justify, and range selection. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.997157 | mean(0.997156796) | [{"register_name":"DATA_FORMAT","physical_address":{"hex":"0x31","decimal":"49","bank":"","page":"","description":"Data format control register"},"description":"Controls self-test, SPI mode, interrupt polarity, resolution, justification and range","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"SELF_TEST","field_description":"Apply self-test force when set (1).","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Self-test disabled"},{"value":"1","value_description":"Self-test enabled"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SPI","field_description":"Select SPI mode: 1 = 3-wire, 0 = 4-wire.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"4-wire SPI"},{"value":"1","value_description":"3-wire SPI"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"INT_INVERT","field_description":"Interrupt polarity: 0 = active high, 1 = active low.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Interrupts active high"},{"value":"1","value_description":"Interrupts active low"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"FULL_RES","field_description":"Full resolution mode when set (output resolution increases with range to maintain 4 mg/LSB).","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"10-bit fixed mode"},{"value":"1","value_description":"Full-resolution mode"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Justify","field_description":"Data justification: 0 = right-justified (sign-extended), 1 = left-justified (MSB).","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Right-justified (sign-extended)"},{"value":"1","value_description":"Left-justified (MSB)"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Range","field_description":"g range selection (D1:D0): 00=±2g, 01=±4g, 10=±8g, 11=±16g.","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"00","value_description":"±2 g"},{"value":"01","value_description":"±4 g"},{"value":"10","value_description":"±8 g"},{"value":"11","value_description":"±16 g"}],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 10-bit, +/-2 g, right-justified, four-wire SPI, active-high interrupts | "" |

`Q(L_22) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.997157 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.965850735/1.0001 = **0.965754159**`.

## Extracted logical register 23: `DATAX0`

without location: registers[22]; truth association: truth registers[22] (`DATAX`).
Associated physical locations: 0x32 (50).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part; grouping itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATAX0` at 0x32 (50)

Locations: `truth registers[22].field_parts[0]` ↔ `without registers[22].field_parts[0]`.

**Truth bit field 1: `DATAX0` bits 0:7**

Locations: `truth registers[22].field_parts[0].bit_field[0]` ↔ `without registers[22].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DATAX0 | DATAX0 |
| `field_description` | 0.0586 | 1.000000 | Least significant byte of two's-complement X-axis output data. | Least significant byte of X-axis two's complement output. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | DATAX0 | DATAX0 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x32","decimal":"50","bank":"","page":"","description":"X-Axis Data 0"} | {"hex":"0x32","decimal":"50","bank":"","page":"","description":"X-axis data least significant byte"} |
| `description` | 0.0693 | 1.000000 | Least significant byte of X-axis output data. | X-axis data 0 (LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"DATAX0","field_description":"Least significant byte of two's-complement X-axis output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"DATAX0","field_description":"Least significant byte of X-axis two's complement output.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | DATAX0 | DATAX0 |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x32","decimal":"50","bank":"","page":"","description":"X-Axis Data 0"}] | [{"hex":"0x32","decimal":"50","bank":"","page":"","description":"X-axis data least significant byte"}] |
| `register_description` | 0.0564 | 1.000000 | DATAX0 and DATAX1 hold the 16-bit two's-complement X-axis output data; DATAX0 is the least significant byte and DATAX1 is the most significant byte. | X-axis output data, least significant byte. Output is 16-bit two's complement; DATAX0 = LSB. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"DATAX0","physical_address":{"hex":"0x32","decimal":"50","bank":"","page":"","description":"X-axis data least significant byte"},"description":"X-axis data 0 (LSB)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"DATAX0","field_description":"Least significant byte of X-axis two's complement output.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.000000 | corresponding split part of parent default 0000000000000000 → 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 | "" |

`Q(L_23) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 24: `DATAX1`

without location: registers[23]; truth association: truth registers[22] (`DATAX`).
Associated physical locations: 0x33 (51).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part; grouping itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATAX1` at 0x33 (51)

Locations: `truth registers[22].field_parts[1]` ↔ `without registers[23].field_parts[0]`.

**Truth bit field 1: `DATAX1` bits 0:7**

Locations: `truth registers[22].field_parts[1].bit_field[0]` ↔ `without registers[23].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DATAX1 | DATAX1 |
| `field_description` | 0.0586 | 1.000000 | Most significant byte of two's-complement X-axis output data. | Most significant byte of X-axis two's complement output. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | DATAX1 | DATAX1 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x33","decimal":"51","bank":"","page":"","description":"X-Axis Data 1"} | {"hex":"0x33","decimal":"51","bank":"","page":"","description":"X-axis data most significant byte"} |
| `description` | 0.0693 | 1.000000 | Most significant byte of X-axis output data. | X-axis data 1 (MSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"DATAX1","field_description":"Most significant byte of two's-complement X-axis output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"DATAX1","field_description":"Most significant byte of X-axis two's complement output.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | DATAX1 | DATAX1 |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x33","decimal":"51","bank":"","page":"","description":"X-Axis Data 1"}] | [{"hex":"0x33","decimal":"51","bank":"","page":"","description":"X-axis data most significant byte"}] |
| `register_description` | 0.0564 | 1.000000 | DATAX0 and DATAX1 hold the 16-bit two's-complement X-axis output data; DATAX0 is the least significant byte and DATAX1 is the most significant byte. | X-axis output data, most significant byte. Output is 16-bit two's complement; DATAX1 = MSB. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"DATAX1","physical_address":{"hex":"0x33","decimal":"51","bank":"","page":"","description":"X-axis data most significant byte"},"description":"X-axis data 1 (MSB)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"DATAX1","field_description":"Most significant byte of X-axis two's complement output.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.000000 | corresponding split part of parent default 0000000000000000 → 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 | "" |

`Q(L_24) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 25: `DATAY0`

without location: registers[24]; truth association: truth registers[23] (`DATAY`).
Associated physical locations: 0x34 (52).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part; grouping itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATAY0` at 0x34 (52)

Locations: `truth registers[23].field_parts[0]` ↔ `without registers[24].field_parts[0]`.

**Truth bit field 1: `DATAY0` bits 0:7**

Locations: `truth registers[23].field_parts[0].bit_field[0]` ↔ `without registers[24].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DATAY0 | DATAY0 |
| `field_description` | 0.0586 | 1.000000 | Least significant byte of two's-complement Y-axis output data. | Least significant byte of Y-axis two's complement output. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | DATAY0 | DATAY0 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x34","decimal":"52","bank":"","page":"","description":"Y-Axis Data 0"} | {"hex":"0x34","decimal":"52","bank":"","page":"","description":"Y-axis data least significant byte"} |
| `description` | 0.0693 | 1.000000 | Least significant byte of Y-axis output data. | Y-axis data 0 (LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"DATAY0","field_description":"Least significant byte of two's-complement Y-axis output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"DATAY0","field_description":"Least significant byte of Y-axis two's complement output.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | DATAY0 | DATAY0 |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x34","decimal":"52","bank":"","page":"","description":"Y-Axis Data 0"}] | [{"hex":"0x34","decimal":"52","bank":"","page":"","description":"Y-axis data least significant byte"}] |
| `register_description` | 0.0564 | 1.000000 | Two's-complement Y-axis output data; DATAY0 is least significant and DATAY1 most significant. | Y-axis output data, least significant byte. Output is 16-bit two's complement; DATAY0 = LSB. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"DATAY0","physical_address":{"hex":"0x34","decimal":"52","bank":"","page":"","description":"Y-axis data least significant byte"},"description":"Y-axis data 0 (LSB)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"DATAY0","field_description":"Least significant byte of Y-axis two's complement output.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.000000 | corresponding split part of parent default 0000000000000000 → 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 | "" |

`Q(L_25) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 26: `DATAY1`

without location: registers[25]; truth association: truth registers[23] (`DATAY`).
Associated physical locations: 0x35 (53).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part; grouping itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATAY1` at 0x35 (53)

Locations: `truth registers[23].field_parts[1]` ↔ `without registers[25].field_parts[0]`.

**Truth bit field 1: `DATAY1` bits 0:7**

Locations: `truth registers[23].field_parts[1].bit_field[0]` ↔ `without registers[25].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DATAY1 | DATAY1 |
| `field_description` | 0.0586 | 1.000000 | Most significant byte of two's-complement Y-axis output data. | Most significant byte of Y-axis two's complement output. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | DATAY1 | DATAY1 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x35","decimal":"53","bank":"","page":"","description":"Y-Axis Data 1"} | {"hex":"0x35","decimal":"53","bank":"","page":"","description":"Y-axis data most significant byte"} |
| `description` | 0.0693 | 1.000000 | Most significant byte of Y-axis output data. | Y-axis data 1 (MSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"DATAY1","field_description":"Most significant byte of two's-complement Y-axis output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"DATAY1","field_description":"Most significant byte of Y-axis two's complement output.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | DATAY1 | DATAY1 |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x35","decimal":"53","bank":"","page":"","description":"Y-Axis Data 1"}] | [{"hex":"0x35","decimal":"53","bank":"","page":"","description":"Y-axis data most significant byte"}] |
| `register_description` | 0.0564 | 1.000000 | Two's-complement Y-axis output data; DATAY0 is least significant and DATAY1 most significant. | Y-axis output data, most significant byte. Output is 16-bit two's complement; DATAY1 = MSB. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"DATAY1","physical_address":{"hex":"0x35","decimal":"53","bank":"","page":"","description":"Y-axis data most significant byte"},"description":"Y-axis data 1 (MSB)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"DATAY1","field_description":"Most significant byte of Y-axis two's complement output.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.000000 | corresponding split part of parent default 0000000000000000 → 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 | "" |

`Q(L_26) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 27: `DATAZ0`

without location: registers[26]; truth association: truth registers[24] (`DATAZ`).
Associated physical locations: 0x36 (54).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part; grouping itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATAZ0` at 0x36 (54)

Locations: `truth registers[24].field_parts[0]` ↔ `without registers[26].field_parts[0]`.

**Truth bit field 1: `DATAZ0` bits 0:7**

Locations: `truth registers[24].field_parts[0].bit_field[0]` ↔ `without registers[26].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DATAZ0 | DATAZ0 |
| `field_description` | 0.0586 | 1.000000 | Least significant byte of two's-complement Z-axis output data. | Least significant byte of Z-axis two's complement output. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | DATAZ0 | DATAZ0 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x36","decimal":"54","bank":"","page":"","description":"Z-Axis Data 0"} | {"hex":"0x36","decimal":"54","bank":"","page":"","description":"Z-axis data least significant byte"} |
| `description` | 0.0693 | 1.000000 | Least significant byte of Z-axis output data. | Z-axis data 0 (LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"DATAZ0","field_description":"Least significant byte of two's-complement Z-axis output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"DATAZ0","field_description":"Least significant byte of Z-axis two's complement output.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | DATAZ0 | DATAZ0 |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":"Z-Axis Data 0"}] | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":"Z-axis data least significant byte"}] |
| `register_description` | 0.0564 | 1.000000 | Two's-complement Z-axis output data; DATAZ0 is least significant and DATAZ1 most significant. | Z-axis output data, least significant byte. Output is 16-bit two's complement; DATAZ0 = LSB. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"DATAZ0","physical_address":{"hex":"0x36","decimal":"54","bank":"","page":"","description":"Z-axis data least significant byte"},"description":"Z-axis data 0 (LSB)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"DATAZ0","field_description":"Least significant byte of Z-axis two's complement output.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.000000 | corresponding split part of parent default 0000000000000000 → 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 | "" |

`Q(L_27) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 28: `DATAZ1`

without location: registers[27]; truth association: truth registers[24] (`DATAZ`).
Associated physical locations: 0x37 (55).
Accepted split representation: direct logical fields are compared with the corresponding truth physical field part; grouping itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DATAZ1` at 0x37 (55)

Locations: `truth registers[24].field_parts[1]` ↔ `without registers[27].field_parts[0]`.

**Truth bit field 1: `DATAZ1` bits 0:7**

Locations: `truth registers[24].field_parts[1].bit_field[0]` ↔ `without registers[27].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | DATAZ1 | DATAZ1 |
| `field_description` | 0.0586 | 1.000000 | Most significant byte of two's-complement Z-axis output data. | Most significant byte of Z-axis two's complement output. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000) = **1.000000000**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | DATAZ1 | DATAZ1 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x37","decimal":"55","bank":"","page":"","description":"Z-Axis Data 1"} | {"hex":"0x37","decimal":"55","bank":"","page":"","description":"Z-axis data most significant byte"} |
| `description` | 0.0693 | 1.000000 | Most significant byte of Z-axis output data. | Z-axis data 1 (MSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"DATAZ1","field_description":"Most significant byte of two's-complement Z-axis output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"DATAZ1","field_description":"Most significant byte of Z-axis two's complement output.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000000/1.0000 = **1.000000000**`.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000000) = **1.000000000**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | DATAZ1 | DATAZ1 |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":"Z-Axis Data 1"}] | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":"Z-axis data most significant byte"}] |
| `register_description` | 0.0564 | 1.000000 | Two's-complement Z-axis output data; DATAZ0 is least significant and DATAZ1 most significant. | Z-axis output data, most significant byte. Output is 16-bit two's complement; DATAZ1 = MSB. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000000) | [{"register_name":"DATAZ1","physical_address":{"hex":"0x37","decimal":"55","bank":"","page":"","description":"Z-axis data most significant byte"},"description":"Z-axis data 1 (MSB)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"DATAZ1","field_description":"Most significant byte of Z-axis two's complement output.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.000000 | corresponding split part of parent default 0000000000000000 → 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | 0 | "" |

`Q(L_28) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.966700000/1.0001 = **0.966603340**`.

## Extracted logical register 29: `FIFO_CTL`

without location: registers[28]; truth association: truth registers[25] (`FIFO_CTL`).
Associated physical locations: 0x38 (56).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_CTL` at 0x38 (56)

Locations: `truth registers[25].field_parts[0]` ↔ `without registers[28].field_parts[0]`.

**Truth bit field 1: `FIFO_MODE` bits 6:7**

Locations: `truth registers[25].field_parts[0].bit_field[0]` ↔ `without registers[28].field_parts[0].bit_field[0]`.
Judgment: objective facts match; description/value wording accepted semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | FIFO_MODE | FIFO_MODE |
| `field_description` | 0.0586 | 1.000000 | FIFO operating mode. | FIFO mode selection (D7:D6): 00=Bypass, 01=FIFO, 10=Stream, 11=Trigger. |
| `bit_start` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 2 | 2 |
| `values` | 0.2097 | 1.000000 | [{"value":"00","value_description":"Bypass."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Trigger mode."}] | [{"value":"00","value_description":"Bypass: FIFO is bypassed."},{"value":"01","value_description":"FIFO: Collects up to 32 values then stops."},{"value":"10","value_description":"Stream: Holds last 32 values, overwrites oldest."},{"value":"11","value_description":"Trigger: Retains pre-trigger samples then collects until full."}] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900000/0.9999 = **1.000000000**`.

**Truth bit field 2: `TRIGGER` bits 5:5**

Locations: `truth registers[25].field_parts[0].bit_field[1]` ↔ `without registers[28].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter, values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | TRIGGER | Trigger |
| `field_description` | 0.0586 | 1.000000 | Trigger interrupt pin selection: 0 INT1, 1 INT2. | Selects which interrupt (INT1/INT2) is used for trigger event when in trigger mode (0 = INT1, 1 = INT2). |
| `bit_start` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_end` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"Trigger event linked to INT1."},{"value":"1","value_description":"Trigger event linked to INT2."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.769000000/0.9999 = **0.769076908**`.

**Truth bit field 3: `SAMPLES` bits 0:4**

Locations: `truth registers[25].field_parts[0].bit_field[2]` ↔ `without registers[28].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | SAMPLES | Samples |
| `field_description` | 0.0586 | 1.000000 | Number of FIFO entries for watermark or pre-trigger samples; zero immediately sets watermark. | Sample count bits (D4:D0). Function depends on FIFO mode: watermark level for FIFO/Stream, number of pre-trigger samples for Trigger. |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 4 | 4 |
| `bit_width` | 0.0583 | 1.000000 | 5 | 5 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Field-part aggregation**

bit_field correctness = mean(1.000000000, 0.769076908, 0.978797880) = **0.915958262**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | FIFO_CTL | FIFO_CTL |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x38","decimal":"56","bank":"","page":"","description":"FIFO control"} | {"hex":"0x38","decimal":"56","bank":"","page":"","description":"FIFO control register"} |
| `description` | 0.0693 | 1.000000 | FIFO control. | FIFO mode, trigger selection, and samples (watermark/trigger count) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.915958 | [{"name_or_parameter":"FIFO_MODE","field_description":"FIFO operating mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Trigger mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TRIGGER","field_description":"Trigger interrupt pin selection: 0 INT1, 1 INT2.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Trigger event linked to INT1."},{"value":"1","value_description":"Trigger event linked to INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SAMPLES","field_description":"Number of FIFO entries for watermark or pre-trigger samples; zero immediately sets watermark.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"FIFO_MODE","field_description":"FIFO mode selection (D7:D6): 00=Bypass, 01=FIFO, 10=Stream, 11=Trigger.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass: FIFO is bypassed."},{"value":"01","value_description":"FIFO: Collects up to 32 values then stops."},{"value":"10","value_description":"Stream: Holds last 32 values, overwrites oldest."},{"value":"11","value_description":"Trigger: Retains pre-trigger samples then collects until full."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Trigger","field_description":"Selects which interrupt (INT1/INT2) is used for trigger event when in trigger mode (0 = INT1, 1 = INT2).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Samples","field_description":"Sample count bits (D4:D0). Function depends on FIFO mode: watermark level for FIFO/Stream, number of pre-trigger samples for Trigger.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.915958)/1.0000 = 0.973703340/1.0000 = **0.973703340**`.

### Extracted logical-register aggregation

field_parts correctness = mean(0.973703340) = **0.973703340**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | FIFO_CTL | FIFO_CTL |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x38","decimal":"56","bank":"","page":"","description":"FIFO control"}] | [{"hex":"0x38","decimal":"56","bank":"","page":"","description":"FIFO control register"}] |
| `register_description` | 0.0564 | 1.000000 | Controls FIFO mode, trigger interrupt pin and watermark sample count. | Configures FIFO mode (bypass, FIFO, stream, trigger), trigger mapping and sample count (watermark/triggers). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.973703 | mean(0.973703340) | [{"register_name":"FIFO_CTL","physical_address":{"hex":"0x38","decimal":"56","bank":"","page":"","description":"FIFO control register"},"description":"FIFO mode, trigger selection, and samples (watermark/trigger count)","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"FIFO_MODE","field_description":"FIFO mode selection (D7:D6): 00=Bypass, 01=FIFO, 10=Stream, 11=Trigger.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass: FIFO is bypassed."},{"value":"01","value_description":"FIFO: Collects up to 32 values then stops."},{"value":"10","value_description":"Stream: Holds last 32 values, overwrites oldest."},{"value":"11","value_description":"Trigger: Retains pre-trigger samples then collects until full."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Trigger","field_description":"Selects which interrupt (INT1/INT2) is used for trigger event when in trigger mode (0 = INT1, 1 = INT2).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Samples","field_description":"Sample count bits (D4:D0). Function depends on FIFO mode: watermark level for FIFO/Stream, number of pre-trigger samples for Trigger.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | Bypass mode, trigger INT1, zero samples; zero samples immediately sets WATERMARK and may cause undesirable trigger-mode operation. | "" |

`Q(L_29) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.973703 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.958845188/1.0001 = **0.958749313**`.

## Extracted logical register 30: `FIFO_STATUS`

without location: registers[29]; truth association: truth registers[26] (`FIFO_STATUS`).
Associated physical locations: 0x39 (57).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_STATUS` at 0x39 (57)

Locations: `truth registers[26].field_parts[0]` ↔ `without registers[29].field_parts[0]`.

**Truth bit field 1: `FIFO_TRIG` bits 7:7**

Locations: `truth registers[26].field_parts[0].bit_field[0]` ↔ `without registers[29].field_parts[0].bit_field[0]`.
Judgment: deductions: values.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | FIFO_TRIG | FIFO_TRIG |
| `field_description` | 0.0586 | 1.000000 | Indicates that a FIFO trigger event occurred. | Indicates a FIFO trigger event occurred (1 = triggered). |
| `bit_start` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 0.000000 | [{"value":"0","value_description":"No FIFO trigger event."},{"value":"1","value_description":"FIFO trigger event occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200000/0.9999 = **0.790279028**`.

**Truth bit field 2: `ENTRIES` bits 0:5**

Locations: `truth registers[26].field_parts[0].bit_field[1]` ↔ `without registers[29].field_parts[0].bit_field[2]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | ENTRIES | Entries |
| `field_description` | 0.0586 | 1.000000 | Number of data values stored in FIFO. | Number of FIFO entries currently stored (D5:D0). |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 |
| `bit_end` | 0.2594 | 1.000000 | 5 | 5 |
| `bit_width` | 0.0583 | 1.000000 | 6 | 6 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | false | false |
| `type_write_read` | 0.0583 | 1.000000 | R | R |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Truth bit field 3: `RESERVED` bits 6:6**

Locations: `truth registers[26].field_parts[0].bit_field[2]` ↔ `without registers[29].field_parts[0].bit_field[1]`.
Judgment: deductions: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | RESERVED | Reserved |
| `field_description` | 0.0586 | 1.000000 | Reserved bits. | "" |
| `bit_start` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_end` | 0.2594 | 1.000000 | 6 | 6 |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 |
| `values` | 0.2097 | 1.000000 | [] | [] |
| `is_reserved` | 0.0750 | 1.000000 | true | true |
| `type_write_read` | 0.0583 | 1.000000 | "" | "" |

`Q_BF = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.978700000/0.9999 = **0.978797880**`.

**Field-part aggregation**

bit_field correctness = mean(0.790279028, 0.978797880, 0.978797880) = **0.915958262**.

| Field-part field | Weight | C | Truth content | without content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.000000 | FIFO_STATUS | FIFO_STATUS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x39","decimal":"57","bank":"","page":"","description":"FIFO status"} | {"hex":"0x39","decimal":"57","bank":"","page":"","description":"FIFO status register (read only)"} |
| `description` | 0.0693 | 1.000000 | FIFO status. | FIFO trigger flag and number of entries stored |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.915958 | [{"name_or_parameter":"FIFO_TRIG","field_description":"Indicates that a FIFO trigger event occurred.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No FIFO trigger event."},{"value":"1","value_description":"FIFO trigger event occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ENTRIES","field_description":"Number of data values stored in FIFO.","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"RESERVED","field_description":"Reserved bits.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"FIFO_TRIG","field_description":"Indicates a FIFO trigger event occurred (1 = triggered).","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Entries","field_description":"Number of FIFO entries currently stored (D5:D0).","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R"}] |

`Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.915958)/1.0000 = 0.973703340/1.0000 = **0.973703340**`.

### Extracted logical-register aggregation

field_parts correctness = mean(0.973703340) = **0.973703340**.

Direct judgment: deductions: default_value_description.

| Logical-register field | Weight | C | Truth target | without content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.000000 | FIFO_STATUS | FIFO_STATUS |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x39","decimal":"57","bank":"","page":"","description":"FIFO status"}] | [{"hex":"0x39","decimal":"57","bank":"","page":"","description":"FIFO status register (read only)"}] |
| `register_description` | 0.0564 | 1.000000 | Reports FIFO trigger status and the number of stored data values. | Read-only FIFO status: FIFO_TRIG indicates trigger occurred; Entries bits report number of FIFO entries stored (max 32). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.973703 | mean(0.973703340) | [{"register_name":"FIFO_STATUS","physical_address":{"hex":"0x39","decimal":"57","bank":"","page":"","description":"FIFO status register (read only)"},"description":"FIFO trigger flag and number of entries stored","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"FIFO_TRIG","field_description":"Indicates a FIFO trigger event occurred (1 = triggered).","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Entries","field_description":"Number of FIFO entries currently stored (D5:D0).","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 0.000000 | No trigger; zero entries | "" |

`Q(L_30) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.973703 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001 = 0.958845188/1.0001 = **0.958749313**`.

## 2. Detailed deviations, omissions, and diagnostics

The following table lists every non-recursive scored error or omission. Recursive bit_field and field_parts effects are listed separately below and are already included in each bottom-up calculation above.

| # | Truth location | without location | Field | C | Truth content | without content | Specific reason |
|---|---|---|---|---|---|---|---|
| 1 | `truth registers[0]` | `without registers[0]` | `default_value_description` | 0.000000 | 0xE5 | "" | description missing or strict direct logical-register field mismatch |
| 2 | `truth registers[1]` | `without registers[1]` | `default_value_description` | 0.000000 | 0 may result in undesirable behavior if tap interrupts are enabled. | "" | description missing or strict direct logical-register field mismatch |
| 3 | `truth registers[2]` | `without registers[2]` | `default_value_description` | 0.000000 | 0 | "" | description missing or strict direct logical-register field mismatch |
| 4 | `truth registers[3]` | `without registers[3]` | `default_value_description` | 0.000000 | 0 | "" | description missing or strict direct logical-register field mismatch |
| 5 | `truth registers[4]` | `without registers[4]` | `default_value_description` | 0.000000 | 0 | "" | description missing or strict direct logical-register field mismatch |
| 6 | `truth registers[5]` | `without registers[5]` | `default_value_description` | 0.000000 | 0 disables the single-tap and double-tap functions. | "" | description missing or strict direct logical-register field mismatch |
| 7 | `truth registers[6]` | `without registers[6]` | `default_value_description` | 0.000000 | 0 disables the double-tap function. | "" | description missing or strict direct logical-register field mismatch |
| 8 | `truth registers[7]` | `without registers[7]` | `default_value_description` | 0.000000 | 0 disables the double-tap function. | "" | description missing or strict direct logical-register field mismatch |
| 9 | `truth registers[8]` | `without registers[8]` | `default_value_description` | 0.000000 | 0 may result in undesirable behavior if the activity interrupt is enabled. | "" | description missing or strict direct logical-register field mismatch |
| 10 | `truth registers[9]` | `without registers[9]` | `default_value_description` | 0.000000 | 0 may result in undesirable behavior if the inactivity interrupt is enabled. | "" | description missing or strict direct logical-register field mismatch |
| 11 | `truth registers[10]` | `without registers[10]` | `default_value_description` | 0.000000 | 0 results in an interrupt when acceleration is below THRESH_INACT. | "" | description missing or strict direct logical-register field mismatch |
| 12 | `truth registers[11].field_parts[0].bit_field[0]` | `without registers[11].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.000000 | ACT_ACDC | ACT ac/dc | strict objective name mismatch; names are not case/format-normalized |
| 13 | `truth registers[11].field_parts[0].bit_field[1]` | `without registers[11].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.000000 | ACT_X_ENABLE | ACT_X enable | strict objective name mismatch; names are not case/format-normalized |
| 14 | `truth registers[11].field_parts[0].bit_field[1]` | `without registers[11].field_parts[0].bit_field[1]` | `values` | 0.000000 | [{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 15 | `truth registers[11].field_parts[0].bit_field[2]` | `without registers[11].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.000000 | ACT_Y_ENABLE | ACT_Y enable | strict objective name mismatch; names are not case/format-normalized |
| 16 | `truth registers[11].field_parts[0].bit_field[2]` | `without registers[11].field_parts[0].bit_field[2]` | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 17 | `truth registers[11].field_parts[0].bit_field[3]` | `without registers[11].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.000000 | ACT_Z_ENABLE | ACT_Z enable | strict objective name mismatch; names are not case/format-normalized |
| 18 | `truth registers[11].field_parts[0].bit_field[3]` | `without registers[11].field_parts[0].bit_field[3]` | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 19 | `truth registers[11].field_parts[0].bit_field[4]` | `without registers[11].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.000000 | INACT_ACDC | INACT ac/dc | strict objective name mismatch; names are not case/format-normalized |
| 20 | `truth registers[11].field_parts[0].bit_field[5]` | `without registers[11].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.000000 | INACT_X_ENABLE | INACT_X enable | strict objective name mismatch; names are not case/format-normalized |
| 21 | `truth registers[11].field_parts[0].bit_field[5]` | `without registers[11].field_parts[0].bit_field[5]` | `values` | 0.000000 | [{"value":"0","value_description":"Exclude X axis."},{"value":"1","value_description":"Enable X axis."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 22 | `truth registers[11].field_parts[0].bit_field[6]` | `without registers[11].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.000000 | INACT_Y_ENABLE | INACT_Y enable | strict objective name mismatch; names are not case/format-normalized |
| 23 | `truth registers[11].field_parts[0].bit_field[6]` | `without registers[11].field_parts[0].bit_field[6]` | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Y axis."},{"value":"1","value_description":"Enable Y axis."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 24 | `truth registers[11].field_parts[0].bit_field[7]` | `without registers[11].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.000000 | INACT_Z_ENABLE | INACT_Z enable | strict objective name mismatch; names are not case/format-normalized |
| 25 | `truth registers[11].field_parts[0].bit_field[7]` | `without registers[11].field_parts[0].bit_field[7]` | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Z axis."},{"value":"1","value_description":"Enable Z axis."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 26 | `truth registers[11]` | `without registers[11]` | `default_value_description` | 0.000000 | DC-coupled; all axes disabled | "" | description missing or strict direct logical-register field mismatch |
| 27 | `truth registers[12]` | `without registers[12]` | `default_value_description` | 0.000000 | 0 mg may result in undesirable behavior if the free-fall interrupt is enabled. | "" | description missing or strict direct logical-register field mismatch |
| 28 | `truth registers[13]` | `without registers[13]` | `default_value_description` | 0.000000 | 0 may result in undesirable behavior if the free-fall interrupt is enabled. | "" | description missing or strict direct logical-register field mismatch |
| 29 | `truth registers[14].field_parts[0].bit_field[0]` | `without registers[14].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.000000 | SUPPRESS | Suppress | strict objective name mismatch; names are not case/format-normalized |
| 30 | `truth registers[14].field_parts[0].bit_field[0]` | `without registers[14].field_parts[0].bit_field[1]` | `values` | 0.000000 | [{"value":"0","value_description":"Do not suppress."},{"value":"1","value_description":"Suppress double-tap detection."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 31 | `truth registers[14].field_parts[0].bit_field[1]` | `without registers[14].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.000000 | TAP_X_ENABLE | TAP_X enable | strict objective name mismatch; names are not case/format-normalized |
| 32 | `truth registers[14].field_parts[0].bit_field[1]` | `without registers[14].field_parts[0].bit_field[2]` | `values` | 0.000000 | [{"value":"0","value_description":"Exclude X axis from tap detection."},{"value":"1","value_description":"Enable X-axis participation in tap detection."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 33 | `truth registers[14].field_parts[0].bit_field[2]` | `without registers[14].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.000000 | TAP_Y_ENABLE | TAP_Y enable | strict objective name mismatch; names are not case/format-normalized |
| 34 | `truth registers[14].field_parts[0].bit_field[2]` | `without registers[14].field_parts[0].bit_field[3]` | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Y axis from tap detection."},{"value":"1","value_description":"Enable Y-axis participation in tap detection."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 35 | `truth registers[14].field_parts[0].bit_field[3]` | `without registers[14].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.000000 | TAP_Z_ENABLE | TAP_Z enable | strict objective name mismatch; names are not case/format-normalized |
| 36 | `truth registers[14].field_parts[0].bit_field[3]` | `without registers[14].field_parts[0].bit_field[4]` | `values` | 0.000000 | [{"value":"0","value_description":"Exclude Z axis from tap detection."},{"value":"1","value_description":"Enable Z-axis participation in tap detection."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 37 | `truth registers[14].field_parts[0].bit_field[4]` | `without registers[14].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.000000 | RESERVED | Reserved | strict objective name mismatch; names are not case/format-normalized |
| 38 | `truth registers[14]` | `without registers[14]` | `default_value_description` | 0.000000 | All tap axes disabled; suppress disabled | "" | description missing or strict direct logical-register field mismatch |
| 39 | `truth registers[15].field_parts[0].bit_field[0]` | `without registers[15].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.000000 | ACT_X_SOURCE | ACT_X source | strict objective name mismatch; names are not case/format-normalized |
| 40 | `truth registers[15].field_parts[0].bit_field[0]` | `without registers[15].field_parts[0].bit_field[1]` | `values` | 0.000000 | [{"value":"0","value_description":"X axis not involved in activity."},{"value":"1","value_description":"X axis involved in activity."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 41 | `truth registers[15].field_parts[0].bit_field[1]` | `without registers[15].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.000000 | ACT_Y_SOURCE | ACT_Y source | strict objective name mismatch; names are not case/format-normalized |
| 42 | `truth registers[15].field_parts[0].bit_field[1]` | `without registers[15].field_parts[0].bit_field[2]` | `values` | 0.000000 | [{"value":"0","value_description":"Y axis not involved in activity."},{"value":"1","value_description":"Y axis involved in activity."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 43 | `truth registers[15].field_parts[0].bit_field[2]` | `without registers[15].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.000000 | ACT_Z_SOURCE | ACT_Z source | strict objective name mismatch; names are not case/format-normalized |
| 44 | `truth registers[15].field_parts[0].bit_field[2]` | `without registers[15].field_parts[0].bit_field[3]` | `values` | 0.000000 | [{"value":"0","value_description":"Z axis not involved in activity."},{"value":"1","value_description":"Z axis involved in activity."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 45 | `truth registers[15].field_parts[0].bit_field[3]` | `without registers[15].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.000000 | ASLEEP | Asleep | strict objective name mismatch; names are not case/format-normalized |
| 46 | `truth registers[15].field_parts[0].bit_field[3]` | `without registers[15].field_parts[0].bit_field[4]` | `values` | 0.000000 | [{"value":"0","value_description":"Not asleep."},{"value":"1","value_description":"Asleep."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 47 | `truth registers[15].field_parts[0].bit_field[4]` | `without registers[15].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.000000 | TAP_X_SOURCE | TAP_X source | strict objective name mismatch; names are not case/format-normalized |
| 48 | `truth registers[15].field_parts[0].bit_field[4]` | `without registers[15].field_parts[0].bit_field[5]` | `values` | 0.000000 | [{"value":"0","value_description":"X axis not involved in tap."},{"value":"1","value_description":"X axis involved in tap."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 49 | `truth registers[15].field_parts[0].bit_field[5]` | `without registers[15].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.000000 | TAP_Y_SOURCE | TAP_Y source | strict objective name mismatch; names are not case/format-normalized |
| 50 | `truth registers[15].field_parts[0].bit_field[5]` | `without registers[15].field_parts[0].bit_field[6]` | `values` | 0.000000 | [{"value":"0","value_description":"Y axis not involved in tap."},{"value":"1","value_description":"Y axis involved in tap."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 51 | `truth registers[15].field_parts[0].bit_field[6]` | `without registers[15].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.000000 | TAP_Z_SOURCE | TAP_Z source | strict objective name mismatch; names are not case/format-normalized |
| 52 | `truth registers[15].field_parts[0].bit_field[6]` | `without registers[15].field_parts[0].bit_field[7]` | `values` | 0.000000 | [{"value":"0","value_description":"Z axis not involved in tap."},{"value":"1","value_description":"Z axis involved in tap."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 53 | `truth registers[15].field_parts[0].bit_field[7]` | `without registers[15].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.000000 | RESERVED | Reserved | strict objective name mismatch; names are not case/format-normalized |
| 54 | `truth registers[15]` | `without registers[15]` | `default_value_description` | 0.000000 | No event source; not asleep | "" | description missing or strict direct logical-register field mismatch |
| 55 | `truth registers[16].field_parts[0].bit_field[1]` | `without registers[16].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.000000 | RATE | Rate | strict objective name mismatch; names are not case/format-normalized |
| 56 | `truth registers[16].field_parts[0].bit_field[1]` | `without registers[16].field_parts[0].bit_field[2]` | `values` | 0.000000 | [{"value":"0000 (0x00)","value_description":"0.10 Hz output data rate; 0.05 Hz bandwidth."},{"value":"0001 (0x01)","value_description":"0.20 Hz output data rate; 0.10 Hz bandwidth."},{"value":"0010 (0x02)","value_description":"0.39 Hz output data rate; 0.20 Hz bandwidth."},{"value":"0011 (0x03)","value_description":"0.78 Hz output data rate; 0.39 Hz bandwidth."},{"value":"0100 (0x04)","value_description":"1.56 Hz output data rate; 0.78 Hz bandwidth."},{"value":"0101 (0x05)","value_description":"3.13 Hz output data rate; 1.56 Hz bandwidth."},{"value":"0110 (0x06)","value_description":"6.25 Hz output data rate; 3.13 Hz bandwidth."},{"value":"0111 (0x07)","value_description":"12.5 Hz output data rate; 6.25 Hz bandwidth; low-power mode table entry."},{"value":"1000 (0x08)","value_description":"25 Hz output data rate; 12.5 Hz bandwidth; low-power mode table entry."},{"value":"1001 (0x09)","value_description":"50 Hz output data rate; 25 Hz bandwidth; low-power mode table entry."},{"value":"1010 (0x0A)","value_description":"100 Hz output data rate; 50 Hz bandwidth; default; low-power mode table entry."},{"value":"1011 (0x0B)","value_description":"200 Hz output data rate; 100 Hz bandwidth; low-power mode table entry."},{"value":"1100 (0x0C)","value_description":"400 Hz output data rate; 200 Hz bandwidth; low-power mode table entry."},{"value":"1101 (0x0D)","value_description":"800 Hz output data rate; 400 Hz bandwidth."},{"value":"1110 (0x0E)","value_description":"1600 Hz output data rate; 800 Hz bandwidth."},{"value":"1111 (0x0F)","value_description":"3200 Hz output data rate; 1600 Hz bandwidth."}] | [] | strict value-code set mismatch; missing codes=['0', '1', '10', '11', '12', '13', '14', '15', '2', '3', '4', '5', '6', '7', '8', '9'], extra codes=[] |
| 57 | `truth registers[16].field_parts[0].bit_field[2]` | `without registers[16].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.000000 | RESERVED | Reserved | strict objective name mismatch; names are not case/format-normalized |
| 58 | `truth registers[16]` | `without registers[16]` | `default_value_description` | 0.000000 | 100 Hz, normal power | "" | description missing or strict direct logical-register field mismatch |
| 59 | `truth registers[17].field_parts[0].bit_field[0]` | `without registers[17].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.000000 | LINK | Link | strict objective name mismatch; names are not case/format-normalized |
| 60 | `truth registers[17].field_parts[0].bit_field[0]` | `without registers[17].field_parts[0].bit_field[1]` | `values` | 0.000000 | [{"value":"0","value_description":"Activity and inactivity functions operate concurrently."},{"value":"1","value_description":"Activity and inactivity functions are serially linked."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 61 | `truth registers[17].field_parts[0].bit_field[1]` | `without registers[17].field_parts[0].bit_field[2]` | `values` | 0.000000 | [{"value":"0","value_description":"Automatic sleep disabled."},{"value":"1","value_description":"Automatic sleep enabled when linked inactivity is detected."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 62 | `truth registers[17].field_parts[0].bit_field[2]` | `without registers[17].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.000000 | MEASURE | Measure | strict objective name mismatch; names are not case/format-normalized |
| 63 | `truth registers[17].field_parts[0].bit_field[3]` | `without registers[17].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.000000 | SLEEP | Sleep | strict objective name mismatch; names are not case/format-normalized |
| 64 | `truth registers[17].field_parts[0].bit_field[3]` | `without registers[17].field_parts[0].bit_field[4]` | `values` | 0.000000 | [{"value":"0","value_description":"Normal operation."},{"value":"1","value_description":"Sleep mode."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 65 | `truth registers[17].field_parts[0].bit_field[4]` | `without registers[17].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.000000 | WAKEUP | Wakeup | strict objective name mismatch; names are not case/format-normalized |
| 66 | `truth registers[17].field_parts[0].bit_field[5]` | `without registers[17].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.000000 | RESERVED | Reserved | strict objective name mismatch; names are not case/format-normalized |
| 67 | `truth registers[17]` | `without registers[17]` | `default_value_description` | 0.000000 | Standby, normal mode | "" | description missing or strict direct logical-register field mismatch |
| 68 | `truth registers[18].field_parts[0].bit_field[0]` | `without registers[18].field_parts[0].bit_field[0]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 69 | `truth registers[18].field_parts[0].bit_field[1]` | `without registers[18].field_parts[0].bit_field[1]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 70 | `truth registers[18].field_parts[0].bit_field[2]` | `without registers[18].field_parts[0].bit_field[2]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 71 | `truth registers[18].field_parts[0].bit_field[3]` | `without registers[18].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.000000 | ACTIVITY | Activity | strict objective name mismatch; names are not case/format-normalized |
| 72 | `truth registers[18].field_parts[0].bit_field[3]` | `without registers[18].field_parts[0].bit_field[3]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 73 | `truth registers[18].field_parts[0].bit_field[4]` | `without registers[18].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.000000 | INACTIVITY | Inactivity | strict objective name mismatch; names are not case/format-normalized |
| 74 | `truth registers[18].field_parts[0].bit_field[4]` | `without registers[18].field_parts[0].bit_field[4]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 75 | `truth registers[18].field_parts[0].bit_field[5]` | `without registers[18].field_parts[0].bit_field[5]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 76 | `truth registers[18].field_parts[0].bit_field[6]` | `without registers[18].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.000000 | WATERMARK | Watermark | strict objective name mismatch; names are not case/format-normalized |
| 77 | `truth registers[18].field_parts[0].bit_field[6]` | `without registers[18].field_parts[0].bit_field[6]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 78 | `truth registers[18].field_parts[0].bit_field[7]` | `without registers[18].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.000000 | OVERRUN | Overrun | strict objective name mismatch; names are not case/format-normalized |
| 79 | `truth registers[18].field_parts[0].bit_field[7]` | `without registers[18].field_parts[0].bit_field[7]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding interrupt disabled."},{"value":"1","value_description":"Corresponding interrupt enabled."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 80 | `truth registers[18]` | `without registers[18]` | `default_value_description` | 0.000000 | All interrupts disabled | "" | description missing or strict direct logical-register field mismatch |
| 81 | `truth registers[19].field_parts[0].bit_field[0]` | `without registers[19].field_parts[0].bit_field[0]` | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 82 | `truth registers[19].field_parts[0].bit_field[1]` | `without registers[19].field_parts[0].bit_field[1]` | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 83 | `truth registers[19].field_parts[0].bit_field[2]` | `without registers[19].field_parts[0].bit_field[2]` | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 84 | `truth registers[19].field_parts[0].bit_field[3]` | `without registers[19].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.000000 | ACTIVITY | Activity | strict objective name mismatch; names are not case/format-normalized |
| 85 | `truth registers[19].field_parts[0].bit_field[3]` | `without registers[19].field_parts[0].bit_field[3]` | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 86 | `truth registers[19].field_parts[0].bit_field[4]` | `without registers[19].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.000000 | INACTIVITY | Inactivity | strict objective name mismatch; names are not case/format-normalized |
| 87 | `truth registers[19].field_parts[0].bit_field[4]` | `without registers[19].field_parts[0].bit_field[4]` | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 88 | `truth registers[19].field_parts[0].bit_field[5]` | `without registers[19].field_parts[0].bit_field[5]` | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 89 | `truth registers[19].field_parts[0].bit_field[6]` | `without registers[19].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.000000 | WATERMARK | Watermark | strict objective name mismatch; names are not case/format-normalized |
| 90 | `truth registers[19].field_parts[0].bit_field[6]` | `without registers[19].field_parts[0].bit_field[6]` | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 91 | `truth registers[19].field_parts[0].bit_field[7]` | `without registers[19].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.000000 | OVERRUN | Overrun | strict objective name mismatch; names are not case/format-normalized |
| 92 | `truth registers[19].field_parts[0].bit_field[7]` | `without registers[19].field_parts[0].bit_field[7]` | `values` | 0.000000 | [{"value":"0","value_description":"Interrupt sent to INT1."},{"value":"1","value_description":"Interrupt sent to INT2."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 93 | `truth registers[19]` | `without registers[19]` | `default_value_description` | 0.000000 | All interrupts mapped to INT1 | "" | description missing or strict direct logical-register field mismatch |
| 94 | `truth registers[20].field_parts[0].bit_field[0]` | `without registers[20].field_parts[0].bit_field[0]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 95 | `truth registers[20].field_parts[0].bit_field[1]` | `without registers[20].field_parts[0].bit_field[1]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 96 | `truth registers[20].field_parts[0].bit_field[2]` | `without registers[20].field_parts[0].bit_field[2]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 97 | `truth registers[20].field_parts[0].bit_field[3]` | `without registers[20].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.000000 | ACTIVITY | Activity | strict objective name mismatch; names are not case/format-normalized |
| 98 | `truth registers[20].field_parts[0].bit_field[3]` | `without registers[20].field_parts[0].bit_field[3]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 99 | `truth registers[20].field_parts[0].bit_field[4]` | `without registers[20].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.000000 | INACTIVITY | Inactivity | strict objective name mismatch; names are not case/format-normalized |
| 100 | `truth registers[20].field_parts[0].bit_field[4]` | `without registers[20].field_parts[0].bit_field[4]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 101 | `truth registers[20].field_parts[0].bit_field[5]` | `without registers[20].field_parts[0].bit_field[5]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 102 | `truth registers[20].field_parts[0].bit_field[6]` | `without registers[20].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.000000 | WATERMARK | Watermark | strict objective name mismatch; names are not case/format-normalized |
| 103 | `truth registers[20].field_parts[0].bit_field[6]` | `without registers[20].field_parts[0].bit_field[6]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 104 | `truth registers[20].field_parts[0].bit_field[7]` | `without registers[20].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.000000 | OVERRUN | Overrun | strict objective name mismatch; names are not case/format-normalized |
| 105 | `truth registers[20].field_parts[0].bit_field[7]` | `without registers[20].field_parts[0].bit_field[7]` | `values` | 0.000000 | [{"value":"0","value_description":"Corresponding event has not occurred."},{"value":"1","value_description":"Corresponding event has occurred."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 106 | `truth registers[20]` | `without registers[20]` | `default_value_description` | 0.000000 | Watermark status bit set in reset value per register map | "" | description missing or strict direct logical-register field mismatch |
| 107 | `truth registers[21].field_parts[0].bit_field[4]` | `without registers[21].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.000000 | JUSTIFY | Justify | strict objective name mismatch; names are not case/format-normalized |
| 108 | `truth registers[21].field_parts[0].bit_field[5]` | `without registers[21].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.000000 | RANGE | Range | strict objective name mismatch; names are not case/format-normalized |
| 109 | `truth registers[21].field_parts[0].bit_field[6]` | `without registers[21].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.000000 | RESERVED | Reserved | strict objective name mismatch; names are not case/format-normalized |
| 110 | `truth registers[21]` | `without registers[21]` | `default_value_description` | 0.000000 | 10-bit, +/-2 g, right-justified, four-wire SPI, active-high interrupts | "" | description missing or strict direct logical-register field mismatch |
| 111 | `truth registers[22] (effective split target field_part[0])` | `without registers[22]` | `default_value_description` | 0.000000 | 0 | "" | description missing or strict direct logical-register field mismatch |
| 112 | `truth registers[22] (effective split target field_part[1])` | `without registers[23]` | `default_value_description` | 0.000000 | 0 | "" | description missing or strict direct logical-register field mismatch |
| 113 | `truth registers[23] (effective split target field_part[0])` | `without registers[24]` | `default_value_description` | 0.000000 | 0 | "" | description missing or strict direct logical-register field mismatch |
| 114 | `truth registers[23] (effective split target field_part[1])` | `without registers[25]` | `default_value_description` | 0.000000 | 0 | "" | description missing or strict direct logical-register field mismatch |
| 115 | `truth registers[24] (effective split target field_part[0])` | `without registers[26]` | `default_value_description` | 0.000000 | 0 | "" | description missing or strict direct logical-register field mismatch |
| 116 | `truth registers[24] (effective split target field_part[1])` | `without registers[27]` | `default_value_description` | 0.000000 | 0 | "" | description missing or strict direct logical-register field mismatch |
| 117 | `truth registers[25].field_parts[0].bit_field[1]` | `without registers[28].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.000000 | TRIGGER | Trigger | strict objective name mismatch; names are not case/format-normalized |
| 118 | `truth registers[25].field_parts[0].bit_field[1]` | `without registers[28].field_parts[0].bit_field[1]` | `values` | 0.000000 | [{"value":"0","value_description":"Trigger event linked to INT1."},{"value":"1","value_description":"Trigger event linked to INT2."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 119 | `truth registers[25].field_parts[0].bit_field[2]` | `without registers[28].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.000000 | SAMPLES | Samples | strict objective name mismatch; names are not case/format-normalized |
| 120 | `truth registers[25]` | `without registers[28]` | `default_value_description` | 0.000000 | Bypass mode, trigger INT1, zero samples; zero samples immediately sets WATERMARK and may cause undesirable trigger-mode operation. | "" | description missing or strict direct logical-register field mismatch |
| 121 | `truth registers[26].field_parts[0].bit_field[0]` | `without registers[29].field_parts[0].bit_field[0]` | `values` | 0.000000 | [{"value":"0","value_description":"No FIFO trigger event."},{"value":"1","value_description":"FIFO trigger event occurred."}] | [] | strict value-code set mismatch; missing codes=['0', '1'], extra codes=[] |
| 122 | `truth registers[26].field_parts[0].bit_field[1]` | `without registers[29].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.000000 | ENTRIES | Entries | strict objective name mismatch; names are not case/format-normalized |
| 123 | `truth registers[26].field_parts[0].bit_field[2]` | `without registers[29].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.000000 | RESERVED | Reserved | strict objective name mismatch; names are not case/format-normalized |
| 124 | `truth registers[26]` | `without registers[29]` | `default_value_description` | 0.000000 | No trigger; zero entries | "" | description missing or strict direct logical-register field mismatch |

### Recursive deductions

| Truth location | without location | Recursive field | C | Truth aggregation target | without aggregation | Specific reason |
|---|---|---|---|---|---|---|
| `truth registers[11].field_parts[0]` | `without registers[11].field_parts[0]` | `bit_field` | 0.821507151 | truth bit-field set | extracted bit-field set | recursive mean of exact-range bit-field scores |
| `truth registers[14].field_parts[0]` | `without registers[14].field_parts[0]` | `bit_field` | 0.811021102 | truth bit-field set | extracted bit-field set | recursive mean of exact-range bit-field scores |
| `truth registers[15].field_parts[0]` | `without registers[15].field_parts[0]` | `bit_field` | 0.795292029 | truth bit-field set | extracted bit-field set | recursive mean of exact-range bit-field scores |
| `truth registers[16].field_parts[0]` | `without registers[16].field_parts[0]` | `bit_field` | 0.915958262 | truth bit-field set | extracted bit-field set | recursive mean of exact-range bit-field scores |
| `truth registers[17].field_parts[0]` | `without registers[17].field_parts[0]` | `bit_field` | 0.877471080 | truth bit-field set | extracted bit-field set | recursive mean of exact-range bit-field scores |
| `truth registers[18].field_parts[0]` | `without registers[18].field_parts[0]` | `bit_field` | 0.779677968 | truth bit-field set | extracted bit-field set | recursive mean of exact-range bit-field scores |
| `truth registers[19].field_parts[0]` | `without registers[19].field_parts[0]` | `bit_field` | 0.779677968 | truth bit-field set | extracted bit-field set | recursive mean of exact-range bit-field scores |
| `truth registers[20].field_parts[0]` | `without registers[20].field_parts[0]` | `bit_field` | 0.779677968 | truth bit-field set | extracted bit-field set | recursive mean of exact-range bit-field scores |
| `truth registers[21].field_parts[0]` | `without registers[21].field_parts[0]` | `bit_field` | 0.990913377 | truth bit-field set | extracted bit-field set | recursive mean of exact-range bit-field scores |
| `truth registers[25].field_parts[0]` | `without registers[28].field_parts[0]` | `bit_field` | 0.915958262 | truth bit-field set | extracted bit-field set | recursive mean of exact-range bit-field scores |
| `truth registers[26].field_parts[0]` | `without registers[29].field_parts[0]` | `bit_field` | 0.915958262 | truth bit-field set | extracted bit-field set | recursive mean of exact-range bit-field scores |
| `truth registers[11]` | `without registers[11]` | `field_parts` | 0.944149587 | mean of corresponding truth physical field-part scores | mean of extracted physical field-part scores | recursive mean of field-part scores |
| `truth registers[14]` | `without registers[14]` | `field_parts` | 0.940868503 | mean of corresponding truth physical field-part scores | mean of extracted physical field-part scores | recursive mean of field-part scores |
| `truth registers[15]` | `without registers[15]` | `field_parts` | 0.935946876 | mean of corresponding truth physical field-part scores | mean of extracted physical field-part scores | recursive mean of field-part scores |
| `truth registers[16]` | `without registers[16]` | `field_parts` | 0.973703340 | mean of corresponding truth physical field-part scores | mean of extracted physical field-part scores | recursive mean of field-part scores |
| `truth registers[17]` | `without registers[17]` | `field_parts` | 0.961660701 | mean of corresponding truth physical field-part scores | mean of extracted physical field-part scores | recursive mean of field-part scores |
| `truth registers[18]` | `without registers[18]` | `field_parts` | 0.931061236 | mean of corresponding truth physical field-part scores | mean of extracted physical field-part scores | recursive mean of field-part scores |
| `truth registers[19]` | `without registers[19]` | `field_parts` | 0.931061236 | mean of corresponding truth physical field-part scores | mean of extracted physical field-part scores | recursive mean of field-part scores |
| `truth registers[20]` | `without registers[20]` | `field_parts` | 0.931061236 | mean of corresponding truth physical field-part scores | mean of extracted physical field-part scores | recursive mean of field-part scores |
| `truth registers[21]` | `without registers[21]` | `field_parts` | 0.997156796 | mean of corresponding truth physical field-part scores | mean of extracted physical field-part scores | recursive mean of field-part scores |
| `truth registers[25]` | `without registers[28]` | `field_parts` | 0.973703340 | mean of corresponding truth physical field-part scores | mean of extracted physical field-part scores | recursive mean of field-part scores |
| `truth registers[26]` | `without registers[29]` | `field_parts` | 0.973703340 | mean of corresponding truth physical field-part scores | mean of extracted physical field-part scores | recursive mean of field-part scores |

### Error summary

| Error field | Count |
|---|---|
| `default_value_description` | 30 |
| `name_or_parameter` | 47 |
| `values` | 47 |

- There are 47 strict bit-name mismatches. The candidate uses humanized/case-different labels such as ACT ac/dc, ACT_X enable, Trigger, Entries, or Reserved; these do not equal the truth objective names and are therefore not normalized to credit.
- There are 47 strict value-code-set omissions/mismatches. The detailed table gives every exact bit-field location and the complete truth/candidate value lists; an empty candidate list does not receive credit against a non-empty truth code set.
- There are 30 missing logical-register default-value descriptions. The candidate content is empty at each listed location while truth contains a non-empty reset/default interpretation, so each receives C=0.0.
- The candidate's non-empty register, field-part, bit-field, and value descriptions preserve the functional meaning of the truth and are credited under the lenient description rule. Empty descriptions on reserved bits are allowed by the rules; the reserved objective name itself remains strict when a non-empty non-identical label is supplied.
- No extracted bit range is extra or unaligned; all candidate bit ranges have an exact truth range at the same physical part.

## 3. Empty-field audit

- Simultaneously empty truth and candidate scored primitive fields credited with 1.0: 32.
- `type_write_read`: 6 empty/empty comparison(s).
- `values`: 26 empty/empty comparison(s).
- Reserved bit descriptions that are empty only on the candidate side are covered by the reserved-bit allowance; they are not counted as simultaneous-empty comparisons.

## 4. Physical-register aggregation and final score

| Truth physical register | Address | Associated extracted logical register(s) | q_R |
|---|---|---|---|
| `DEVID` | 0x00 (0) | registers[0] `DEVID` Q=0.966603340 | 0.966603340 |
| `THRESH_TAP` | 0x1D (29) | registers[1] `THRESH_TAP` Q=0.966603340 | 0.966603340 |
| `OFSX` | 0x1E (30) | registers[2] `OFSX` Q=0.966603340 | 0.966603340 |
| `OFSY` | 0x1F (31) | registers[3] `OFSY` Q=0.966603340 | 0.966603340 |
| `OFSZ` | 0x20 (32) | registers[4] `OFSZ` Q=0.966603340 | 0.966603340 |
| `DUR` | 0x21 (33) | registers[5] `DUR` Q=0.966603340 | 0.966603340 |
| `Latent` | 0x22 (34) | registers[6] `Latent` Q=0.966603340 | 0.966603340 |
| `Window` | 0x23 (35) | registers[7] `Window` Q=0.966603340 | 0.966603340 |
| `THRESH_ACT` | 0x24 (36) | registers[8] `THRESH_ACT` Q=0.966603340 | 0.966603340 |
| `THRESH_INACT` | 0x25 (37) | registers[9] `THRESH_INACT` Q=0.966603340 | 0.966603340 |
| `TIME_INACT` | 0x26 (38) | registers[10] `TIME_INACT` Q=0.966603340 | 0.966603340 |
| `ACT_INACT_CTL` | 0x27 (39) | registers[11] `ACT_INACT_CTL` Q=0.949922490 | 0.949922490 |
| `THRESH_FF` | 0x28 (40) | registers[12] `THRESH_FF` Q=0.966603340 | 0.966603340 |
| `TIME_FF` | 0x29 (41) | registers[13] `TIME_FF` Q=0.966603340 | 0.966603340 |
| `TAP_AXES` | 0x2A (42) | registers[14] `TAP_AXES` Q=0.948942528 | 0.948942528 |
| `ACT_TAP_STATUS` | 0x2B (43) | registers[15] `ACT_TAP_STATUS` Q=0.947472585 | 0.947472585 |
| `BW_RATE` | 0x2C (44) | registers[16] `BW_RATE` Q=0.958749313 | 0.958749313 |
| `POWER_CTL` | 0x2D (45) | registers[17] `POWER_CTL` Q=0.955152536 | 0.955152536 |
| `INT_ENABLE` | 0x2E (46) | registers[18] `INT_ENABLE` Q=0.946013390 | 0.946013390 |
| `INT_MAP` | 0x2F (47) | registers[19] `INT_MAP` Q=0.946013390 | 0.946013390 |
| `INT_SOURCE` | 0x30 (48) | registers[20] `INT_SOURCE` Q=0.946013390 | 0.946013390 |
| `DATA_FORMAT` | 0x31 (49) | registers[21] `DATA_FORMAT` Q=0.965754159 | 0.965754159 |
| `DATAX` | 0x32 (50) | registers[22] `DATAX0` Q=0.966603340 | 0.966603340 |
| `DATAX` | 0x33 (51) | registers[23] `DATAX1` Q=0.966603340 | 0.966603340 |
| `DATAY` | 0x34 (52) | registers[24] `DATAY0` Q=0.966603340 | 0.966603340 |
| `DATAY` | 0x35 (53) | registers[25] `DATAY1` Q=0.966603340 | 0.966603340 |
| `DATAZ` | 0x36 (54) | registers[26] `DATAZ0` Q=0.966603340 | 0.966603340 |
| `DATAZ` | 0x37 (55) | registers[27] `DATAZ1` Q=0.966603340 | 0.966603340 |
| `FIFO_CTL` | 0x38 (56) | registers[28] `FIFO_CTL` Q=0.958749313 | 0.958749313 |
| `FIFO_STATUS` | 0x39 (57) | registers[29] `FIFO_STATUS` Q=0.958749313 | 0.958749313 |

Σ q_R = 28.846995859 over n=30 unique truth physical-register locations.

m=30, x=0, and m/(m+x)=1.000000000. No missing truth physical location and no extra extracted physical location is present.

`S_final = (10/30 × 28.846995859) × (30/(30+0)) = **9.615665286 / 10**`.

The final ADXL345 without score is **9.615665286 / 10**.
