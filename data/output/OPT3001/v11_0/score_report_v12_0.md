# OPT3001 v12.0 detailed score — revised AGENTS.md rules

## 1. Scoring basis

- `n=6`, based on the six unique truth physical keys `(numeric address, bank, page)`: `0x00`, `0x01`, `0x02`, `0x03`, `0x7E`, and `0x7F`.
- Every one of the 6 extracted v12.0 logical registers is calculated independently, bottom-up: truth bit fields → field part → extracted logical register `Q(L)`.
- For each truth physical register, `q_R` is the mean of all associated extracted logical-register scores. If there is no associated extracted logical register, `q_R=0`.
- Objective facts (numeric address/bank/page, bit positions, bit width, access type, reset/default values, reserved state, and value codes) are judged strictly. Numeric reset forms such as `0000h` and `0x0000` are equivalent representations of the same value. Description-like fields are accepted when functionally equivalent; materially incomplete descriptions receive `0.5`.
- `values` is inspected down to each value code and value description. Equivalent binary suffixes/grouping are accepted, but missing or unsupported codes receive partial/no credit.
- Rounded weights are normalized by `0.9999` at bit-field level and `1.0001` at logical-register level; field-part weights sum to 1.

## Extracted logical register 1: `Result`

v12.0 location: `registers[0]`; truth association: `registers[0]` (`Result Register`).
Associated physical locations: 0x00 (0).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Result` at 0x00 (0)

Locations: `truth registers[0].field_parts[0]` ↔ `v12_0 registers[0].field_parts[0]`.

**Truth bit field 1: `E[3:0]` bits 15:12**

Locations: `truth registers[0].field_parts[0].bit_field[0]` ↔ `v12_0 registers[0].field_parts[0].bit_field[0]`. Judgment: values is empty; missing all truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | E[3:0] | E[3:0] |
| `field_description` | 0.0586 | 1.0 | Exponent bits that determine the full-scale range and LSB size. | Exponent. These bits are the exponent bits. Full-scale range and LSB size as a function of exponent level provided in Table 8. |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 0.0 | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 2: `R[11:0]` bits 11:0**

Locations: `truth registers[0].field_parts[0].bit_field[1]` ↔ `v12_0 registers[0].field_parts[0].bit_field[1]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | R[11:0] | R[11:0] |
| `field_description` | 0.0586 | 1.0 | Fractional result in straight binary coding from zero to full-scale. | Fractional result. These bits are the result in straight binary coding (zero to full-scale). |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 11 | 11 |
| `bit_width` | 0.0583 | 1.0 | 12 | 12 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(0.790279, 1.000000) = **0.895140**. Direct judgment: all five direct field-part fields are semantically or objectively correct.

| Field-part field | Weight | Correctness | Truth content | extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Result Register | Result |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":""} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.0 | "" | "" |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.895140 | truth bit-field set | matched extracted bit-field set |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.895140=\mathbf{0.967189}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.967189) = **0.967189**. Judgment: all seven direct logical-register fields are semantically or objectively correct.

| Logical-register field | Weight | Correctness | Truth comparison target | extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Result Register | Result |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":""}] | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Contains the result of the most recent light-to-digital conversion as a 4-bit exponent and 12-bit fractional result. | Contains the result of the most recent light to digital conversion. This 16-bit register has two fields: a 4-bit exponent (E[3:0]) and a 12-bit mantissa (R[11:0]). Lux calculation formula: lux = 0.01 × 2^(E[3:0]) × R[11:0]. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.967189 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | 0000h | 0x0000 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{1})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.967189 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.990299/1.0001=\mathbf{0.990200}\).

## Extracted logical register 2: `Configuration`

v12.0 location: `registers[1]`; truth association: `registers[1]` (`Configuration Register`).
Associated physical locations: 0x01 (1).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Configuration` at 0x01 (1)

Locations: `truth registers[1].field_parts[0]` ↔ `v12_0 registers[1].field_parts[0]`.

**Truth bit field 1: `RN[3:0]` bits 15:12**

Locations: `truth registers[1].field_parts[0].bit_field[0]` ↔ `v12_0 registers[1].field_parts[0].bit_field[0]`. Judgment: values is incomplete; missing truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011', '1101', '1110', '1111'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | RN[3:0] | RN[3:0] |
| `field_description` | 0.0586 | 1.0 | Selects the device full-scale lux range; 1100b selects automatic full-scale setting mode. | Range number field (read or write). Selects the full-scale lux range of the device. Format is same as result register exponent field (E[3:0]). When RN[3:0] = 1100b, device operates in automatic full-scale setting mode. Codes 1101b, 1110b, and 1111b are reserved. |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 0.5 | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."},{"value":"1100b","value_description":"Automatic full-scale setting mode."},{"value":"1101b","value_description":"Reserved for future use."},{"value":"1110b","value_description":"Reserved for future use."},{"value":"1111b","value_description":"Reserved for future use."}] | [{"value":"1100b","value_description":"Automatic full-scale setting mode"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.5 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.895050/0.9999=\mathbf{0.895140}\).

**Truth bit field 2: `CT` bits 11:11**

Locations: `truth registers[1].field_parts[0].bit_field[1]` ↔ `v12_0 registers[1].field_parts[0].bit_field[1]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | CT | CT |
| `field_description` | 0.0586 | 1.0 | Selects the light-to-digital conversion time. | Conversion time field (read or write). 0 = 100 ms, 1 = 800 ms. Longer integration time allows for lower noise measurement and fully specified lux resolution. |
| `bit_start` | 0.2594 | 1.0 | 11 | 11 |
| `bit_end` | 0.2594 | 1.0 | 11 | 11 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"100 ms conversion time."},{"value":"1","value_description":"800 ms conversion time."}] | [{"value":"0","value_description":"100 ms"},{"value":"1","value_description":"800 ms"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `M[1:0]` bits 10:9**

Locations: `truth registers[1].field_parts[0].bit_field[2]` ↔ `v12_0 registers[1].field_parts[0].bit_field[2]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | M[1:0] | M[1:0] |
| `field_description` | 0.0586 | 1.0 | Controls shutdown, single-shot, or continuous conversion operation. | Mode of conversion operation field (read or write). 00 = Shutdown, 01 = Single-shot, 10/11 = Continuous conversions. Default is shutdown mode. |
| `bit_start` | 0.2594 | 1.0 | 9 | 9 |
| `bit_end` | 0.2594 | 1.0 | 10 | 10 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"Shutdown."},{"value":"01","value_description":"Single-shot conversion."},{"value":"10, 11","value_description":"Continuous conversions."}] | [{"value":"00b","value_description":"Shutdown (default)"},{"value":"01b","value_description":"Single-shot"},{"value":"10b","value_description":"Continuous conversions"},{"value":"11b","value_description":"Continuous conversions"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `OVF` bits 8:8**

Locations: `truth registers[1].field_parts[0].bit_field[3]` ↔ `v12_0 registers[1].field_parts[0].bit_field[3]`. Judgment: values is empty; missing all truth codes ['0', '1'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | OVF | OVF |
| `field_description` | 0.0586 | 1.0 | Indicates an overflow condition in the data conversion process. | Overflow flag field (read-only). Indicates when an overflow condition occurs in the data conversion process, typically because light exceeds programmed full-scale range. |
| `bit_start` | 0.2594 | 1.0 | 8 | 8 |
| `bit_end` | 0.2594 | 1.0 | 8 | 8 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overflow condition."},{"value":"1","value_description":"Overflow condition occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 5: `CRF` bits 7:7**

Locations: `truth registers[1].field_parts[0].bit_field[4]` ↔ `v12_0 registers[1].field_parts[0].bit_field[4]`. Judgment: values is empty; missing all truth codes ['0', '1'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | CRF | CRF |
| `field_description` | 0.0586 | 1.0 | Indicates that a conversion has completed. | Conversion ready field (read-only). Set to 1 at the end of a conversion and cleared when configuration register is read or written with any value except shutdown mode. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Cleared after the configuration register is read or written with a non-shutdown value."},{"value":"1","value_description":"A conversion has completed."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 6: `FH` bits 6:6**

Locations: `truth registers[1].field_parts[0].bit_field[5]` ↔ `v12_0 registers[1].field_parts[0].bit_field[5]`. Judgment: values is empty; missing all truth codes ['0', '1'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FH | FH |
| `field_description` | 0.0586 | 1.0 | Identifies that the conversion result exceeded the high-limit level for the configured fault count. | Flag high field (read-only). Set to 1 when result is larger than high-limit register for consecutive number of measurements defined by fault count field. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"High-limit fault is not reported."},{"value":"1","value_description":"Result exceeded the high-limit level for the configured consecutive measurement count."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 7: `FL` bits 5:5**

Locations: `truth registers[1].field_parts[0].bit_field[6]` ↔ `v12_0 registers[1].field_parts[0].bit_field[6]`. Judgment: values is empty; missing all truth codes ['0', '1'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FL | FL |
| `field_description` | 0.0586 | 1.0 | Identifies that the conversion result was below the low-limit level for the configured fault count. | Flag low field (read-only). Set to 1 when result is smaller than low-limit register for consecutive number of measurements defined by fault count field. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Low-limit fault is not reported."},{"value":"1","value_description":"Result was below the low-limit level for the configured consecutive measurement count."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 8: `L` bits 4:4**

Locations: `truth registers[1].field_parts[0].bit_field[7]` ↔ `v12_0 registers[1].field_parts[0].bit_field[7]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | L | L |
| `field_description` | 0.0586 | 1.0 | Selects transparent hysteresis-style or latched window-style interrupt reporting. | Latch field (read or write). Controls interrupt reporting mechanisms (INT pin, FH, FL). 0 = Transparent hysteresis-style comparison, 1 = Latched window-style comparison. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Transparent hysteresis-style comparison operation."},{"value":"1","value_description":"Latched window-style comparison operation."}] | [{"value":"0","value_description":"Transparent hysteresis-style comparison"},{"value":"1","value_description":"Latched window-style comparison"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 9: `POL` bits 3:3**

Locations: `truth registers[1].field_parts[0].bit_field[8]` ↔ `v12_0 registers[1].field_parts[0].bit_field[8]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | POL | POL |
| `field_description` | 0.0586 | 1.0 | Controls the polarity or active state of the INT pin. | Polarity field (read or write). Controls polarity of INT pin. 0 = Active low, 1 = Active high. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"INT pin reports active low."},{"value":"1","value_description":"INT pin reports active high."}] | [{"value":"0","value_description":"INT pin active low"},{"value":"1","value_description":"INT pin active high"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 10: `ME` bits 2:2**

Locations: `truth registers[1].field_parts[0].bit_field[9]` ↔ `v12_0 registers[1].field_parts[0].bit_field[9]`. Judgment: values is empty; missing all truth codes ['1'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ME | ME |
| `field_description` | 0.0586 | 1.0 | Forces the result exponent to 0000b when enabled with a manually selected full-scale range. | Mask exponent field (read or write). Forces result register exponent field to 0000b when full-scale range is manually set and ME = 1. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"1","value_description":"Masks the result-register exponent to 0000b when RN[3:0] is less than 1100b."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 11: `FC[1:0]` bits 1:0**

Locations: `truth registers[1].field_parts[0].bit_field[10]` ↔ `v12_0 registers[1].field_parts[0].bit_field[10]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FC[1:0] | FC[1:0] |
| `field_description` | 0.0586 | 1.0 | Selects how many consecutive fault events trigger the interrupt reporting mechanisms. | Fault count field (read or write). Number of consecutive fault events required to trigger interrupt reporting mechanisms. 00 = 1, 01 = 2, 10 = 4, 11 = 8. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"One fault count."},{"value":"01","value_description":"Two fault counts."},{"value":"10","value_description":"Four fault counts."},{"value":"11","value_description":"Eight fault counts."}] | [{"value":"00b","value_description":"One fault count (default)"},{"value":"01b","value_description":"Two fault counts"},{"value":"10b","value_description":"Four fault counts"},{"value":"11b","value_description":"Eight fault counts"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(0.895140, 1.000000, 1.000000, 0.790279, 0.790279, 0.790279, 0.790279, 1.000000, 1.000000, 0.790279, 1.000000) = **0.895140**. Direct judgment: all five direct field-part fields are semantically or objectively correct.

| Field-part field | Weight | Correctness | Truth content | extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Configuration Register | Configuration |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":""} | {"hex":"0x01","decimal":"1","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.0 | "" | "" |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.895140 | truth bit-field set | matched extracted bit-field set |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.895140=\mathbf{0.967189}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.967189) = **0.967189**. Judgment: register_description is materially incomplete: it lists covered settings but omits that writing during an active conversion aborts that conversion.

| Logical-register field | Weight | Correctness | Truth comparison target | extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Configuration Register | Configuration |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":""}] | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.5 | Controls the major operational modes of the device; writing it during an active conversion aborts that conversion. | Controls the major operational modes of the device. Includes range selection, conversion time, mode of operation, overflow flag, conversion ready flag, flag high/low fields, latch control, polarity, mask exponent, and fault count settings. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.967189 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | C810h | 0xC810 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{2})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.967189 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.962099/1.0001=\mathbf{0.962003}\).

## Extracted logical register 3: `Low Limit`

v12.0 location: `registers[2]`; truth association: `registers[2]` (`Low-Limit Register`).
Associated physical locations: 0x02 (2).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Low Limit` at 0x02 (2)

Locations: `truth registers[2].field_parts[0]` ↔ `v12_0 registers[2].field_parts[0]`.

**Truth bit field 1: `LE[3:0]` bits 15:12**

Locations: `truth registers[2].field_parts[0].bit_field[0]` ↔ `v12_0 registers[2].field_parts[0].bit_field[0]`. Judgment: values is empty; missing all truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011', 'LE[3:2]=11'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LE[3:0] | LE[3:0] |
| `field_description` | 0.0586 | 1.0 | Exponent bits for the low-limit lux threshold. | Exponent. These bits are the exponent bits. Full-scale range and LSB size as a function of exponent level provided in Table 12. |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 0.0 | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."},{"value":"LE[3:2] = 11b","value_description":"Enables end-of-conversion mode."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 2: `TL[11:0]` bits 11:0**

Locations: `truth registers[2].field_parts[0].bit_field[1]` ↔ `v12_0 registers[2].field_parts[0].bit_field[1]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TL[11:0] | TL[11:0] |
| `field_description` | 0.0586 | 1.0 | Low-limit result in straight binary coding from zero to full-scale. | Result. These bits are the result in straight binary coding (zero to full-scale). |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 11 | 11 |
| `bit_width` | 0.0583 | 1.0 | 12 | 12 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(0.790279, 1.000000) = **0.895140**. Direct judgment: all five direct field-part fields are semantically or objectively correct.

| Field-part field | Weight | Correctness | Truth content | extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Low-Limit Register | Low Limit |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x02","decimal":"2","bank":"","page":"","description":""} | {"hex":"0x02","decimal":"2","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.0 | "" | "" |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.895140 | truth bit-field set | matched extracted bit-field set |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.895140=\mathbf{0.967189}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.967189) = **0.967189**. Judgment: strict default/reset value mismatch or missing value.

| Logical-register field | Weight | Correctness | Truth comparison target | extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Low-Limit Register | Low Limit |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":""}] | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Sets the lower comparison limit for the INT pin, flag high field, and flag low field interrupt-reporting mechanisms. | Sets the lower comparison limit for interrupt reporting mechanisms (INT pin, FH, FL). Format nearly identical to result register with exponent (LE[3:0]) and result (TL[11:0]). Lux threshold formula: lux = 0.01 × 2^(LE[3:0]) × TL[11:0]. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.967189 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 0.0 | 0000h (C0000h in datasheet is typo) | 0xC000 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{3})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.967189 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.923599/1.0001=\mathbf{0.923507}\).

## Extracted logical register 4: `High Limit`

v12.0 location: `registers[3]`; truth association: `registers[3]` (`High-Limit Register`).
Associated physical locations: 0x03 (3).

### Bottom layer: bit fields, then field parts

#### Field part 1: `High Limit` at 0x03 (3)

Locations: `truth registers[3].field_parts[0]` ↔ `v12_0 registers[3].field_parts[0]`.

**Truth bit field 1: `HE[3:0]` bits 15:12**

Locations: `truth registers[3].field_parts[0].bit_field[0]` ↔ `v12_0 registers[3].field_parts[0].bit_field[0]`. Judgment: field_description is materially incomplete: it identifies the exponent field but does not explicitly state the high-limit lux-threshold function; values is empty; missing all truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | HE[3:0] | HE[3:0] |
| `field_description` | 0.0586 | 0.5 | Exponent bits for the high-limit lux threshold. | Exponent. These bits are the exponent bits. |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 0.0 | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.760900/0.9999=\mathbf{0.760976}\).

**Truth bit field 2: `TH[11:0]` bits 11:0**

Locations: `truth registers[3].field_parts[0].bit_field[1]` ↔ `v12_0 registers[3].field_parts[0].bit_field[1]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TH[11:0] | TH[11:0] |
| `field_description` | 0.0586 | 1.0 | High-limit result in straight binary coding from zero to full-scale. | Result. These bits are the result in straight binary coding (zero to full-scale). |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 11 | 11 |
| `bit_width` | 0.0583 | 1.0 | 12 | 12 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(0.760976, 1.000000) = **0.880488**. Direct judgment: all five direct field-part fields are semantically or objectively correct.

| Field-part field | Weight | Correctness | Truth content | extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | High-Limit Register | High Limit |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x03","decimal":"3","bank":"","page":"","description":""} | {"hex":"0x03","decimal":"3","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.0 | "" | "" |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.880488 | truth bit-field set | matched extracted bit-field set |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.880488=\mathbf{0.962605}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.962605) = **0.962605**. Judgment: all seven direct logical-register fields are semantically or objectively correct.

| Logical-register field | Weight | Correctness | Truth comparison target | extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | High-Limit Register | High Limit |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":""}] | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Sets the upper comparison limit for the INT pin, flag high field, and flag low field interrupt-reporting mechanisms. | Sets the upper comparison limit for interrupt reporting mechanisms (INT pin, FH, FL). Format almost identical to low-limit and result registers with exponent (HE[3:0]) and result (TH[11:0]). Lux threshold formula similar to Equation 4. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.962605 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | BFFFh | 0xBFFF |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{4})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.962605 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.988930/1.0001=\mathbf{0.988831}\).

## Extracted logical register 5: `Manufacturer ID`

v12.0 location: `registers[4]`; truth association: `registers[4]` (`Manufacturer ID Register`).
Associated physical locations: 0x7E (126).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Manufacturer ID` at 0x7E (126)

Locations: `truth registers[4].field_parts[0]` ↔ `v12_0 registers[4].field_parts[0]`.

**Truth bit field 1: `ID[15:0]` bits 15:0**

Locations: `truth registers[4].field_parts[0].bit_field[0]` ↔ `v12_0 registers[4].field_parts[0].bit_field[0]`. Judgment: values is empty; missing all truth codes ['5449'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ID[15:0] | ID[15:0] |
| `field_description` | 0.0586 | 1.0 | Manufacturer ID; reads 5449h, which represents TI in ASCII code. | Manufacturer ID. The manufacturer ID reads 5449h. In ASCII code, this register reads TI. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 16 | 16 |
| `values` | 0.2097 | 0.0 | [{"value":"5449h","value_description":"Manufacturer ID; TI in ASCII code."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Field-part aggregation**

`bit_field` correctness = mean(0.790279) = **0.790279**. Direct judgment: all five direct field-part fields are semantically or objectively correct.

| Field-part field | Weight | Correctness | Truth content | extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Manufacturer ID Register | Manufacturer ID |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x7E","decimal":"126","bank":"","page":"","description":""} | {"hex":"0x7E","decimal":"126","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.0 | "" | "" |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.790279 | truth bit-field set | matched extracted bit-field set |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.790279=\mathbf{0.934378}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.934378) = **0.934378**. Judgment: extracted default-value description is missing.

| Logical-register field | Weight | Correctness | Truth comparison target | extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Manufacturer ID Register | Manufacturer ID |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x7E","decimal":"126","bank":"","page":"","description":""}] | [{"hex":"0x7E","decimal":"126","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Intended to help uniquely identify the device by providing the manufacturer ID. | Uniquely identifies the device manufacturer. Reads as 5449h (ASCII: 'TI'). |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.934378 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | 5449h | 0x5449 |
| `default_value_description` | 0.0334 | 0.0 | The register reads 5449h, which reads TI in ASCII code. | "" |

\(Q(L_{5})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.934378 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.947099/1.0001=\mathbf{0.947004}\).

## Extracted logical register 6: `Device ID`

v12.0 location: `registers[5]`; truth association: `registers[5]` (`Device ID Register`).
Associated physical locations: 0x7F (127).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Device ID` at 0x7F (127)

Locations: `truth registers[5].field_parts[0]` ↔ `v12_0 registers[5].field_parts[0]`.

**Truth bit field 1: `DID[15:0]` bits 15:0**

Locations: `truth registers[5].field_parts[0].bit_field[0]` ↔ `v12_0 registers[5].field_parts[0].bit_field[0]`. Judgment: values is empty; missing all truth codes ['3001'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DID[15:0] | DID[15:0] |
| `field_description` | 0.0586 | 1.0 | Device ID; reads 3001h. | Device ID. The device ID reads 3001h. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 16 | 16 |
| `values` | 0.2097 | 0.0 | [{"value":"3001h","value_description":"Device ID."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Field-part aggregation**

`bit_field` correctness = mean(0.790279) = **0.790279**. Direct judgment: all five direct field-part fields are semantically or objectively correct.

| Field-part field | Weight | Correctness | Truth content | extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Device ID Register | Device ID |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x7F","decimal":"127","bank":"","page":"","description":""} | {"hex":"0x7F","decimal":"127","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.0 | "" | "" |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.790279 | truth bit-field set | matched extracted bit-field set |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.790279=\mathbf{0.934378}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.934378) = **0.934378**. Judgment: extracted default-value description is missing.

| Logical-register field | Weight | Correctness | Truth comparison target | extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Device ID Register | Device ID |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x7F","decimal":"127","bank":"","page":"","description":""}] | [{"hex":"0x7F","decimal":"127","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Intended to help uniquely identify the device by providing the device ID. | Uniquely identifies the device. Reads as 3001h. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.934378 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | 3001h | 0x3001 |
| `default_value_description` | 0.0334 | 0.0 | The device ID register reads 3001h. | "" |

\(Q(L_{6})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.934378 + 0.0667×1.000000 + 0.0334×0.000000)/1.0001=0.947099/1.0001=\mathbf{0.947004}\).

## 2. Ground-truth physical-register scores

For every truth physical register, \(q_R=\frac{1}{|L_R|}\sum_{L\in L_R}Q(L)\).

| Truth physical address | Associated extracted logical registers and Q(L) | q_R |
|---|---|---:|
| 0x00 (0) | v12.0 registers[0] `Result`=0.990200 | 0.990200 |
| 0x01 (1) | v12.0 registers[1] `Configuration`=0.962003 | 0.962003 |
| 0x02 (2) | v12.0 registers[2] `Low Limit`=0.923507 | 0.923507 |
| 0x03 (3) | v12.0 registers[3] `High Limit`=0.988831 | 0.988831 |
| 0x7E (126) | v12.0 registers[4] `Manufacturer ID`=0.947004 | 0.947004 |
| 0x7F (127) | v12.0 registers[5] `Device ID`=0.947004 | 0.947004 |

\(\sum_{R=1}^{6}q_R=\mathbf{5.758549974}\).

\(m=6,\ x=0,\ \frac{m}{m+x}=\frac{6}{6+0}=1.000000\).

\[S_{final}=\left(\frac{10}{6}\times 5.758549974\right)\times\frac{6}{6+0}=\boxed{\mathbf{9.597583290/10}}\]

## 3. Detailed deduction inventory

Each row identifies the exact truth/extracted path, the complete compared contents, the field correctness `C`, and the specific deduction reason.

| # | Exact location | Truth content | Extracted content | C | Error / omission reason |
|---:|---|---|---|---:|---|
| 1 | `truth registers[0].field_parts[0].bit_field[0].values ↔ v12_0 registers[0].field_parts[0].bit_field[0].values` | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."}] | [] | 0.0 | values is empty; missing all truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011'] |
| 2 | `truth registers[1].field_parts[0].bit_field[0].values ↔ v12_0 registers[1].field_parts[0].bit_field[0].values` | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."},{"value":"1100b","value_description":"Automatic full-scale setting mode."},{"value":"1101b","value_description":"Reserved for future use."},{"value":"1110b","value_description":"Reserved for future use."},{"value":"1111b","value_description":"Reserved for future use."}] | [{"value":"1100b","value_description":"Automatic full-scale setting mode"}] | 0.5 | values is incomplete; missing truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011', '1101', '1110', '1111'] |
| 3 | `truth registers[1].field_parts[0].bit_field[3].values ↔ v12_0 registers[1].field_parts[0].bit_field[3].values` | [{"value":"0","value_description":"No overflow condition."},{"value":"1","value_description":"Overflow condition occurred."}] | [] | 0.0 | values is empty; missing all truth codes ['0', '1'] |
| 4 | `truth registers[1].field_parts[0].bit_field[4].values ↔ v12_0 registers[1].field_parts[0].bit_field[4].values` | [{"value":"0","value_description":"Cleared after the configuration register is read or written with a non-shutdown value."},{"value":"1","value_description":"A conversion has completed."}] | [] | 0.0 | values is empty; missing all truth codes ['0', '1'] |
| 5 | `truth registers[1].field_parts[0].bit_field[5].values ↔ v12_0 registers[1].field_parts[0].bit_field[5].values` | [{"value":"0","value_description":"High-limit fault is not reported."},{"value":"1","value_description":"Result exceeded the high-limit level for the configured consecutive measurement count."}] | [] | 0.0 | values is empty; missing all truth codes ['0', '1'] |
| 6 | `truth registers[1].field_parts[0].bit_field[6].values ↔ v12_0 registers[1].field_parts[0].bit_field[6].values` | [{"value":"0","value_description":"Low-limit fault is not reported."},{"value":"1","value_description":"Result was below the low-limit level for the configured consecutive measurement count."}] | [] | 0.0 | values is empty; missing all truth codes ['0', '1'] |
| 7 | `truth registers[1].field_parts[0].bit_field[9].values ↔ v12_0 registers[1].field_parts[0].bit_field[9].values` | [{"value":"1","value_description":"Masks the result-register exponent to 0000b when RN[3:0] is less than 1100b."}] | [] | 0.0 | values is empty; missing all truth codes ['1'] |
| 8 | `truth registers[1].register_description ↔ v12_0 registers[1].register_description` | Controls the major operational modes of the device; writing it during an active conversion aborts that conversion. | Controls the major operational modes of the device. Includes range selection, conversion time, mode of operation, overflow flag, conversion ready flag, flag high/low fields, latch control, polarity, mask exponent, and fault count settings. | 0.5 | register_description is materially incomplete: it lists covered settings but omits that writing during an active conversion aborts that conversion |
| 9 | `truth registers[2].field_parts[0].bit_field[0].values ↔ v12_0 registers[2].field_parts[0].bit_field[0].values` | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."},{"value":"LE[3:2] = 11b","value_description":"Enables end-of-conversion mode."}] | [] | 0.0 | values is empty; missing all truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011', 'LE[3:2]=11'] |
| 10 | `truth registers[2].default_value ↔ v12_0 registers[2].default_value` | 0000h (C0000h in datasheet is typo) | 0xC000 | 0.0 | strict default/reset value mismatch or missing value |
| 11 | `truth registers[3].field_parts[0].bit_field[0].field_description ↔ v12_0 registers[3].field_parts[0].bit_field[0].field_description` | Exponent bits for the high-limit lux threshold. | Exponent. These bits are the exponent bits. | 0.5 | field_description is materially incomplete: it identifies the exponent field but does not explicitly state the high-limit lux-threshold function |
| 12 | `truth registers[3].field_parts[0].bit_field[0].values ↔ v12_0 registers[3].field_parts[0].bit_field[0].values` | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."}] | [] | 0.0 | values is empty; missing all truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011'] |
| 13 | `truth registers[4].field_parts[0].bit_field[0].values ↔ v12_0 registers[4].field_parts[0].bit_field[0].values` | [{"value":"5449h","value_description":"Manufacturer ID; TI in ASCII code."}] | [] | 0.0 | values is empty; missing all truth codes ['5449'] |
| 14 | `truth registers[4].default_value_description ↔ v12_0 registers[4].default_value_description` | The register reads 5449h, which reads TI in ASCII code. | "" | 0.0 | extracted default-value description is missing |
| 15 | `truth registers[5].field_parts[0].bit_field[0].values ↔ v12_0 registers[5].field_parts[0].bit_field[0].values` | [{"value":"3001h","value_description":"Device ID."}] | [] | 0.0 | values is empty; missing all truth codes ['3001'] |
| 16 | `truth registers[5].default_value_description ↔ v12_0 registers[5].default_value_description` | The device ID register reads 3001h. | "" | 0.0 | extracted default-value description is missing |

## 4. Invented-field check

- No extra physical address was extracted; `x=0`.
- No unmatched logical register, field part, bit-field range, or unsupported schema field was found.
- Non-contradictory descriptive additions are accepted. They do not compensate for a missing or incorrect objective field.
