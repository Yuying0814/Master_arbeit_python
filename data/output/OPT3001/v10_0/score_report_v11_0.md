# OPT3001 v11.0 detailed score — revised AGENTS.md rules

## 1. Scoring basis

- `n=6`, based on the six unique truth physical keys `(numeric address, bank, page)`: `0x00`, `0x01`, `0x02`, `0x03`, `0x7E`, and `0x7F`.
- Every one of the 6 extracted v11.0 logical registers is calculated independently, bottom-up: truth bit fields → field part → extracted logical register `Q(L)`.
- For each truth physical register, `q_R` is the mean of all associated extracted logical-register scores. If there is no associated extracted logical register, `q_R=0`.
- Objective facts (numeric address/bank/page, bit positions, bit width, access type, reset/default values, reserved state, and value codes) are judged strictly. Description-like fields are accepted when functionally equivalent; materially incomplete descriptions receive `0.5`.
- `values` is inspected down to each value code and value description. Equivalent binary suffixes/grouping are accepted, but missing or unsupported codes receive partial/no credit.
- Rounded weights are normalized by `0.9999` at bit-field level and `1.0001` at logical-register level; field-part weights sum to 1.

## Extracted logical register 1: `Result`

v11.0 location: `registers[0]`; truth association: `registers[0]` (`Result Register`).
Associated physical locations: 0x00 (0).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Result` at 0x00 (0)

Locations: `truth registers[0].field_parts[0]` ↔ `v11_0 registers[0].field_parts[0]`.

**Truth bit field 1: `E[3:0]` bits 15:12**

Locations: `truth registers[0].field_parts[0].bit_field[0]` ↔ `v11_0 registers[0].field_parts[0].bit_field[0]`. Judgment: values is empty; missing all truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | E[3:0] | E[3:0] |
| `field_description` | 0.0586 | 1.0 | Exponent bits that determine the full-scale range and LSB size. | Exponent. These bits are the exponent bits; the full-scale range and LSB size as a function of the exponent level are given in Table 8. |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 0.0 | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 2: `R[11:0]` bits 11:0**

Locations: `truth registers[0].field_parts[0].bit_field[1]` ↔ `v11_0 registers[0].field_parts[0].bit_field[1]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

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
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":""} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Result register offset (00h)"} |
| `description` | 0.0693 | 1.0 | "" | Read-only 16-bit conversion result register with 4-bit exponent and 12-bit fractional result |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.895140 | truth bit-field set | matched extracted bit-field set |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.895140=\mathbf{0.967189}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.967189) = **0.967189**. Judgment: all seven direct logical-register fields are semantically or objectively correct.

| Logical-register field | Weight | Correctness | Truth comparison target | extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Result Register | Result |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":""}] | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Result register offset (00h)"}] |
| `register_description` | 0.0564 | 1.0 | Contains the result of the most recent light-to-digital conversion as a 4-bit exponent and 12-bit fractional result. | Contains the result of the most recent light-to-digital conversion. The 16-bit register has two fields: a 4-bit exponent (E[3:0]) and a 12-bit mantissa/fractional result (R[11:0]). Conversion to lux: lux = 0.01 x 2^E[3:0] x R[11:0]; LSB_Size = 0.01 x 2^E[3:0] can also be taken from the full-scale range table. The exponent field can be forced to zero by enabling the exponent mask (configuration register ME = 1) with a manually programmed full-scale range (RN[3:0] < 1100b). Additional information: see Table 8 (Full-Scale Range and LSB Size as a Function of Exponent Level) and Table 9 (examples of decoding the result register into lux); see the configuration register CT field for lux resolution versus conversion time. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.967189 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | 0000h | 0000h |
| `default_value_description` | 0.0334 | 1.0 | "" | Assembled from explicit field-level reset values: E[3:0] = 0h (bits 15:12), R[11:0] = 000h (bits 11:0). |

\(Q(L_{1})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.967189 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.990299/1.0001=\mathbf{0.990200}\).

## Extracted logical register 2: `Configuration`

v11.0 location: `registers[1]`; truth association: `registers[1]` (`Configuration Register`).
Associated physical locations: 0x01 (1).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Configuration` at 0x01 (1)

Locations: `truth registers[1].field_parts[0]` ↔ `v11_0 registers[1].field_parts[0]`.

**Truth bit field 1: `RN[3:0]` bits 15:12**

Locations: `truth registers[1].field_parts[0].bit_field[0]` ↔ `v11_0 registers[1].field_parts[0].bit_field[0]`. Judgment: values is incomplete; missing truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | RN[3:0] | RN[3:0] |
| `field_description` | 0.0586 | 1.0 | Selects the device full-scale lux range; 1100b selects automatic full-scale setting mode. | Range number field. Selects the full-scale lux range of the device; format is the same as the result register exponent field E[3:0] (see Table 8). When set to 1100b (0Ch), the device operates in automatic full-scale setting mode and the automatically chosen range is reported in the result exponent (register 00h, E[3:0]). Codes 1101b, 1110b, and 1111b (0Dh, 0Eh, 0Fh) are reserved for future use. |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 0.5 | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."},{"value":"1100b","value_description":"Automatic full-scale setting mode."},{"value":"1101b","value_description":"Reserved for future use."},{"value":"1110b","value_description":"Reserved for future use."},{"value":"1111b","value_description":"Reserved for future use."}] | [{"value":"1100b","value_description":"Automatic full-scale setting mode (power-up default; 0Ch)"},{"value":"1101b","value_description":"Reserved for future use (0Dh)"},{"value":"1110b","value_description":"Reserved for future use (0Eh)"},{"value":"1111b","value_description":"Reserved for future use (0Fh)"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.5 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.895050/0.9999=\mathbf{0.895140}\).

**Truth bit field 2: `CT` bits 11:11**

Locations: `truth registers[1].field_parts[0].bit_field[1]` ↔ `v11_0 registers[1].field_parts[0].bit_field[1]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | CT | CT |
| `field_description` | 0.0586 | 1.0 | Selects the light-to-digital conversion time. | Conversion time field. Determines the length of the light-to-digital conversion process; a longer integration time allows a lower noise measurement. Conversion time relates to effective resolution: 800 ms allows fully specified lux resolution; 100 ms with full-scale ranges above 0101b for E[3:0] also allows full resolution; 100 ms with range 0101b reduces resolution by one bit, ranges 0100b-0001b by two bits, and range 0000b by three bits. The result register format and LSB weight do not change with conversion time. |
| `bit_start` | 0.2594 | 1.0 | 11 | 11 |
| `bit_end` | 0.2594 | 1.0 | 11 | 11 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"100 ms conversion time."},{"value":"1","value_description":"800 ms conversion time."}] | [{"value":"0","value_description":"100 ms conversion time"},{"value":"1","value_description":"800 ms conversion time"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `M[1:0]` bits 10:9**

Locations: `truth registers[1].field_parts[0].bit_field[2]` ↔ `v11_0 registers[1].field_parts[0].bit_field[2]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | M[1:0] | M[1:0] |
| `field_description` | 0.0586 | 1.0 | Controls shutdown, single-shot, or continuous conversion operation. | Mode of conversion operation field. Controls continuous conversion, single-shot, or low-power shutdown mode. In single-shot mode the field reads 01b while converting and is automatically set to 00b (shutdown) when the conversion completes. Entering shutdown mode does not change the state of the reporting flags (CRF, FH, FL) or the INT pin. |
| `bit_start` | 0.2594 | 1.0 | 9 | 9 |
| `bit_end` | 0.2594 | 1.0 | 10 | 10 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"Shutdown."},{"value":"01","value_description":"Single-shot conversion."},{"value":"10, 11","value_description":"Continuous conversions."}] | [{"value":"00","value_description":"Shutdown (default)"},{"value":"01","value_description":"Single-shot"},{"value":"10","value_description":"Continuous conversions"},{"value":"11","value_description":"Continuous conversions"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `OVF` bits 8:8**

Locations: `truth registers[1].field_parts[0].bit_field[3]` ↔ `v11_0 registers[1].field_parts[0].bit_field[3]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | OVF | OVF |
| `field_description` | 0.0586 | 1.0 | Indicates an overflow condition in the data conversion process. | Overflow flag field. Indicates an overflow condition in the data conversion process, typically because the input light exceeds the programmed full-scale range. Set to 1 under overflow, otherwise 0; reevaluated on every measurement. With manual range (RN[3:0] < 1100b), OVF can be set by a temporary input spike even if the result is below full-scale. With automatic range (RN[3:0] = 1100b), OVF is set only if the input exceeds the full-scale level of the entire device; on overflow the device aborts the conversion, increases the range, and starts a new conversion until no overflow or maximum range is reached. |
| `bit_start` | 0.2594 | 1.0 | 8 | 8 |
| `bit_end` | 0.2594 | 1.0 | 8 | 8 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No overflow condition."},{"value":"1","value_description":"Overflow condition occurred."}] | [{"value":"0","value_description":"No overflow condition"},{"value":"1","value_description":"Overflow condition occurred in the data conversion process"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 5: `CRF` bits 7:7**

Locations: `truth registers[1].field_parts[0].bit_field[4]` ↔ `v11_0 registers[1].field_parts[0].bit_field[4]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | CRF | CRF |
| `field_description` | 0.0586 | 1.0 | Indicates that a conversion has completed. | Conversion ready field. Set to 1 at the end of a conversion; cleared (set to 0) when the configuration register is subsequently read or written with any value except one containing shutdown mode (M[1:0] = 00b). Writing shutdown mode does not affect this field; see the Interrupt Reporting Mechanism Modes section for details. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Cleared after the configuration register is read or written with a non-shutdown value."},{"value":"1","value_description":"A conversion has completed."}] | [{"value":"0","value_description":"Conversion not complete / cleared after configuration register read or non-shutdown write"},{"value":"1","value_description":"Conversion completed"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 6: `FH` bits 6:6**

Locations: `truth registers[1].field_parts[0].bit_field[5]` ↔ `v11_0 registers[1].field_parts[0].bit_field[5]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FH | FH |
| `field_description` | 0.0586 | 1.0 | Identifies that the conversion result exceeded the high-limit level for the configured fault count. | Flag high field. Identifies that the result of a conversion is larger than a specified level of interest. Set to 1 when the result is larger than the high-limit register (address 03h) for a consecutive number of measurements defined by the fault count field FC[1:0]. See the Interrupt Reporting Mechanism Modes section for clearing and other behaviors. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"High-limit fault is not reported."},{"value":"1","value_description":"Result exceeded the high-limit level for the configured consecutive measurement count."}] | [{"value":"0","value_description":"Result not above high-limit register per fault count criterion"},{"value":"1","value_description":"Result exceeded high-limit register for FC[1:0] consecutive measurements"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 7: `FL` bits 5:5**

Locations: `truth registers[1].field_parts[0].bit_field[6]` ↔ `v11_0 registers[1].field_parts[0].bit_field[6]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FL | FL |
| `field_description` | 0.0586 | 1.0 | Identifies that the conversion result was below the low-limit level for the configured fault count. | Flag low field. Identifies that the result of a conversion is smaller than a specified level of interest. Set to 1 when the result is smaller than the low-limit register (address 02h) for a consecutive number of measurements defined by the fault count field FC[1:0]. See the Interrupt Reporting Mechanism Modes section for clearing and other behaviors. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Low-limit fault is not reported."},{"value":"1","value_description":"Result was below the low-limit level for the configured consecutive measurement count."}] | [{"value":"0","value_description":"Result not below low-limit register per fault count criterion"},{"value":"1","value_description":"Result below low-limit register for FC[1:0] consecutive measurements"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 8: `L` bits 4:4**

Locations: `truth registers[1].field_parts[0].bit_field[7]` ↔ `v11_0 registers[1].field_parts[0].bit_field[7]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | L | L |
| `field_description` | 0.0586 | 1.0 | Selects transparent hysteresis-style or latched window-style interrupt reporting. | Latch field. Controls the functionality of the interrupt reporting mechanisms (INT pin, FH, FL), selecting between latched window-style and transparent hysteresis-style comparison. When transitioning from end-of-conversion mode to standard comparison modes (LE[3:2] from 11b to 00b) while L = 1, a subsequent write of L to 0 is necessary to properly clear the INT pin; L can then be set back to 1. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Transparent hysteresis-style comparison operation."},{"value":"1","value_description":"Latched window-style comparison operation."}] | [{"value":"0","value_description":"Transparent hysteresis-style comparison operation; interrupt reporting mechanisms directly reflect the comparison of the result register with the high- and low-limit registers with no user-controlled clearing event"},{"value":"1","value_description":"Latched window-style comparison operation; interrupt reporting mechanisms latch until a user-controlled clearing event (configuration register read)"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 9: `POL` bits 3:3**

Locations: `truth registers[1].field_parts[0].bit_field[8]` ↔ `v11_0 registers[1].field_parts[0].bit_field[8]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | POL | POL |
| `field_description` | 0.0586 | 1.0 | Controls the polarity or active state of the INT pin. | Polarity field. Controls the polarity or active state of the INT pin. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"INT pin reports active low."},{"value":"1","value_description":"INT pin reports active high."}] | [{"value":"0","value_description":"INT pin reports active low, pulling the pin low upon an interrupt event"},{"value":"1","value_description":"INT pin operation is inverted; reports active high, becoming high impedance and allowing the pin to be pulled high upon an interrupt event"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 10: `ME` bits 2:2**

Locations: `truth registers[1].field_parts[0].bit_field[9]` ↔ `v11_0 registers[1].field_parts[0].bit_field[9]`. Judgment: values is partially correct; missing truth codes [], unsupported codes ['0'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ME | ME |
| `field_description` | 0.0586 | 1.0 | Forces the result exponent to 0000b when enabled with a manually selected full-scale range. | Mask exponent field. Forces the result register exponent field (register 00h, E[3:0]) to 0000b when the full-scale range is manually set (ME = 1 and RN[3:0] < 1100b), simplifying result processing. Masking applies only to the result register; result comparison with the low-limit and high-limit registers is unaffected. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.5 | [{"value":"1","value_description":"Masks the result-register exponent to 0000b when RN[3:0] is less than 1100b."}] | [{"value":"0","value_description":"Exponent masking disabled (default)"},{"value":"1","value_description":"Force result register exponent E[3:0] to 0000b when full-scale range is manually set (RN[3:0] < 1100b)"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.5 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.895050/0.9999=\mathbf{0.895140}\).

**Truth bit field 11: `FC[1:0]` bits 1:0**

Locations: `truth registers[1].field_parts[0].bit_field[10]` ↔ `v11_0 registers[1].field_parts[0].bit_field[10]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FC[1:0] | FC[1:0] |
| `field_description` | 0.0586 | 1.0 | Selects how many consecutive fault events trigger the interrupt reporting mechanisms. | Fault count field. Instructs the device how many consecutive fault events are required to trigger the interrupt reporting mechanisms: the INT pin, the flag high field (FH), and the flag low field (FL). |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"One fault count."},{"value":"01","value_description":"Two fault counts."},{"value":"10","value_description":"Four fault counts."},{"value":"11","value_description":"Eight fault counts."}] | [{"value":"00","value_description":"One fault count (default)"},{"value":"01","value_description":"Two fault counts"},{"value":"10","value_description":"Four fault counts"},{"value":"11","value_description":"Eight fault counts"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(0.895140, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 0.895140, 1.000000) = **0.980934**. Direct judgment: all five direct field-part fields are semantically or objectively correct.

| Field-part field | Weight | Correctness | Truth content | extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Configuration Register | Configuration |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":""} | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"Configuration register offset (01h)"} |
| `description` | 0.0693 | 1.0 | "" | 16-bit configuration register controlling operational modes, conversion, and interrupt reporting |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.980934 | truth bit-field set | matched extracted bit-field set |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.980934=\mathbf{0.994034}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.994034) = **0.994034**. Judgment: all seven direct logical-register fields are semantically or objectively correct.

| Logical-register field | Weight | Correctness | Truth comparison target | extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Configuration Register | Configuration |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":""}] | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":"Configuration register offset (01h)"}] |
| `register_description` | 0.0564 | 1.0 | Controls the major operational modes of the device; writing it during an active conversion aborts that conversion. | Controls the major operational modes of the device. Has 11 fields: range number (RN[3:0]), conversion time (CT), mode of conversion operation (M[1:0]), overflow flag (OVF), conversion ready flag (CRF), flag high (FH), flag low (FL), latch (L), INT pin polarity (POL), mask exponent (ME), and fault count (FC[1:0]). If a measurement conversion is in progress when this register is written, the active conversion immediately aborts; if the new configuration directs a new conversion, it is subsequently started. RN[3:0] = 1100b selects automatic full-scale setting mode where the device performs a 10-ms range assessment and adapts the full-scale range based on previous results. The L field selects latched window-style versus transparent hysteresis-style interrupt reporting; reading this register clears the INT pin and the FH/FL/CRF fields in latched modes. Additional information: see the Automatic Full-Scale Setting Mode and Interrupt Reporting Mechanism Modes sections and Tables 4 and 5 for flag setting/clearing behavior. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.994034 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | C810h | C810h |
| `default_value_description` | 0.0334 | 1.0 | "" | Whole-register power-on reset value explicitly stated: [reset = C810h]. |

\(Q(L_{2})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.994034 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.998318/1.0001=\mathbf{0.998218}\).

## Extracted logical register 3: `Low Limit`

v11.0 location: `registers[2]`; truth association: `registers[2]` (`Low-Limit Register`).
Associated physical locations: 0x02 (2).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Low Limit` at 0x02 (2)

Locations: `truth registers[2].field_parts[0]` ↔ `v11_0 registers[2].field_parts[0]`.

**Truth bit field 1: `LE[3:0]` bits 15:12**

Locations: `truth registers[2].field_parts[0].bit_field[0]` ↔ `v11_0 registers[2].field_parts[0].bit_field[0]`. Judgment: values is empty; missing all truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011', 'LE[3:2]=11'].

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LE[3:0] | LE[3:0] |
| `field_description` | 0.0586 | 1.0 | Exponent bits for the low-limit lux threshold. | Exponent. These bits are the exponent bits; Table 12 provides the full-scale range and LSB size as a function of exponent level. Setting the two most significant bits (LE[3:2]) to 11b enters end-of-conversion mode. |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 0.0 | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."},{"value":"LE[3:2] = 11b","value_description":"Enables end-of-conversion mode."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 2: `TL[11:0]` bits 11:0**

Locations: `truth registers[2].field_parts[0].bit_field[1]` ↔ `v11_0 registers[2].field_parts[0].bit_field[1]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

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
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x02","decimal":"2","bank":"","page":"","description":""} | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"Low-limit register offset (02h)"} |
| `description` | 0.0693 | 1.0 | "" | Read/write 16-bit lower comparison limit register with 4-bit exponent and 12-bit result |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.895140 | truth bit-field set | matched extracted bit-field set |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.895140=\mathbf{0.967189}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.967189) = **0.967189**. Judgment: strict default/reset value mismatch or missing value.

| Logical-register field | Weight | Correctness | Truth comparison target | extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Low-Limit Register | Low Limit |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":""}] | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":"Low-limit register offset (02h)"}] |
| `register_description` | 0.0564 | 1.0 | Sets the lower comparison limit for the INT pin, flag high field, and flag low field interrupt-reporting mechanisms. | Sets the lower comparison limit for the interrupt reporting mechanisms (INT pin, flag high field FH, flag low field FL), as described in the Interrupt Reporting Mechanism Modes section. Format is nearly identical to the result register: a 4-bit exponent LE[3:0] and a 12-bit fractional result TL[11:0]. Conversion to a lux threshold: lux = 0.01 x 2^LE[3:0] x TL[11:0]. Setting the two MSBs (LE[3:2]) to 11b enters end-of-conversion mode, where the INT pin goes active on every measurement completion. Result and limit registers are converted to lux internally for comparison and can have different exponents; with a manually set full-scale range and mask enable (ME) active, programming the manual range into LE[3:0] simplifies programming. Additional information: see Table 12 (full-scale range and LSB size as a function of exponent level); the Result Register discussion and examples also apply. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.967189 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 0.0 | 0000h (C0000h in datasheet is typo) | C0000h |
| `default_value_description` | 0.0334 | 1.0 | "" | Whole-register reset value as stated in the source heading: [reset = C0000h] (note: the field-level reset values are LE[3:0] = 0h and TL[11:0] = 000h). |

\(Q(L_{3})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.967189 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.923599/1.0001=\mathbf{0.923507}\).

## Extracted logical register 4: `High Limit`

v11.0 location: `registers[3]`; truth association: `registers[3]` (`High-Limit Register`).
Associated physical locations: 0x03 (3).

### Bottom layer: bit fields, then field parts

#### Field part 1: `High Limit` at 0x03 (3)

Locations: `truth registers[3].field_parts[0]` ↔ `v11_0 registers[3].field_parts[0]`.

**Truth bit field 1: `HE[3:0]` bits 15:12**

Locations: `truth registers[3].field_parts[0].bit_field[0]` ↔ `v11_0 registers[3].field_parts[0].bit_field[0]`. Judgment: field_description is materially incomplete: it identifies the exponent field but does not explicitly state the high-limit lux-threshold function; values is empty; missing all truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011'].

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

Locations: `truth registers[3].field_parts[0].bit_field[1]` ↔ `v11_0 registers[3].field_parts[0].bit_field[1]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

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
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x03","decimal":"3","bank":"","page":"","description":""} | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"High-limit register offset (03h)"} |
| `description` | 0.0693 | 1.0 | "" | Read/write 16-bit upper comparison limit register with 4-bit exponent and 12-bit result |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.880488 | truth bit-field set | matched extracted bit-field set |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.880488=\mathbf{0.962605}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.962605) = **0.962605**. Judgment: all seven direct logical-register fields are semantically or objectively correct.

| Logical-register field | Weight | Correctness | Truth comparison target | extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | High-Limit Register | High Limit |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":""}] | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"High-limit register offset (03h)"}] |
| `register_description` | 0.0564 | 1.0 | Sets the upper comparison limit for the INT pin, flag high field, and flag low field interrupt-reporting mechanisms. | Sets the upper comparison limit for the interrupt reporting mechanisms (INT pin, flag high field FH, flag low field FL), as described in the Interrupt Operation, INT Pin, and Interrupt Reporting Mechanisms section. Format is almost identical to the low-limit and result registers: a 4-bit exponent HE[3:0] and a 12-bit result TH[11:0]. Comparison with the result register is unaffected by the ME bit. With a manually set full-scale range and mask enable (ME) active, programming the manual range into HE[3:0] simplifies programming. The lux translation formula is similar to Equation 4 (lux = 0.01 x 2^exponent x fractional result) and the full-scale values are similar to Table 8. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.962605 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | BFFFh | BFFFh |
| `default_value_description` | 0.0334 | 1.0 | "" | Whole-register power-on reset value explicitly stated: [reset = BFFFh] (HE[3:0] = Bh, TH[11:0] = FFFh). |

\(Q(L_{4})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.962605 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.988930/1.0001=\mathbf{0.988831}\).

## Extracted logical register 5: `Manufacturer ID`

v11.0 location: `registers[4]`; truth association: `registers[4]` (`Manufacturer ID Register`).
Associated physical locations: 0x7E (126).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Manufacturer ID` at 0x7E (126)

Locations: `truth registers[4].field_parts[0]` ↔ `v11_0 registers[4].field_parts[0]`.

**Truth bit field 1: `ID[15:0]` bits 15:0**

Locations: `truth registers[4].field_parts[0].bit_field[0]` ↔ `v11_0 registers[4].field_parts[0].bit_field[0]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ID[15:0] | ID[15:0] |
| `field_description` | 0.0586 | 1.0 | Manufacturer ID; reads 5449h, which represents TI in ASCII code. | Manufacturer ID. The manufacturer ID reads 5449h. In ASCII code, this register reads TI. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 16 | 16 |
| `values` | 0.2097 | 1.0 | [{"value":"5449h","value_description":"Manufacturer ID; TI in ASCII code."}] | [{"value":"5449h","value_description":"Manufacturer ID; reads 'TI' in ASCII code"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**. Direct judgment: all five direct field-part fields are semantically or objectively correct.

| Field-part field | Weight | Correctness | Truth content | extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Manufacturer ID Register | Manufacturer ID |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x7E","decimal":"126","bank":"","page":"","description":""} | {"hex":"0x7E","decimal":"126","bank":"","page":"","description":"Manufacturer ID register offset (7Eh)"} |
| `description` | 0.0693 | 1.0 | "" | Read-only 16-bit manufacturer identification register |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field set | matched extracted bit-field set |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. Judgment: all seven direct logical-register fields are semantically or objectively correct.

| Logical-register field | Weight | Correctness | Truth comparison target | extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Manufacturer ID Register | Manufacturer ID |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x7E","decimal":"126","bank":"","page":"","description":""}] | [{"hex":"0x7E","decimal":"126","bank":"","page":"","description":"Manufacturer ID register offset (7Eh)"}] |
| `register_description` | 0.0564 | 1.0 | Intended to help uniquely identify the device by providing the manufacturer ID. | Read-only register intended to help uniquely identify the device. The manufacturer ID reads 5449h, which in ASCII code reads 'TI'. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | 5449h | 5449h |
| `default_value_description` | 0.0334 | 1.0 | The register reads 5449h, which reads TI in ASCII code. | Whole-register reset value explicitly stated: [reset = 5449h]. |

\(Q(L_{5})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 6: `Device ID`

v11.0 location: `registers[5]`; truth association: `registers[5]` (`Device ID Register`).
Associated physical locations: 0x7F (127).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Device ID` at 0x7F (127)

Locations: `truth registers[5].field_parts[0]` ↔ `v11_0 registers[5].field_parts[0]`.

**Truth bit field 1: `DID[15:0]` bits 15:0**

Locations: `truth registers[5].field_parts[0].bit_field[0]` ↔ `v11_0 registers[5].field_parts[0].bit_field[0]`. Judgment: all scored fields are complete and correct; description wording is functionally equivalent.

| Scored field | Weight | C | Truth content | extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DID[15:0] | DID[15:0] |
| `field_description` | 0.0586 | 1.0 | Device ID; reads 3001h. | Device ID. The device ID reads 3001h. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 16 | 16 |
| `values` | 0.2097 | 1.0 | [{"value":"3001h","value_description":"Device ID."}] | [{"value":"3001h","value_description":"Device ID value"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**. Direct judgment: all five direct field-part fields are semantically or objectively correct.

| Field-part field | Weight | Correctness | Truth content | extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Device ID Register | Device ID |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x7F","decimal":"127","bank":"","page":"","description":""} | {"hex":"0x7F","decimal":"127","bank":"","page":"","description":"Device ID register offset (7Fh)"} |
| `description` | 0.0693 | 1.0 | "" | Read-only 16-bit device identification register |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field set | matched extracted bit-field set |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. Judgment: all seven direct logical-register fields are semantically or objectively correct.

| Logical-register field | Weight | Correctness | Truth comparison target | extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Device ID Register | Device ID |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x7F","decimal":"127","bank":"","page":"","description":""}] | [{"hex":"0x7F","decimal":"127","bank":"","page":"","description":"Device ID register offset (7Fh)"}] |
| `register_description` | 0.0564 | 1.0 | Intended to help uniquely identify the device by providing the device ID. | Read-only register intended to help uniquely identify the device. The device ID reads 3001h. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | 3001h | 3001h |
| `default_value_description` | 0.0334 | 1.0 | The device ID register reads 3001h. | Whole-register reset value explicitly stated: [reset = 3001h]. |

\(Q(L_{6})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## 2. Ground-truth physical-register scores

For every truth physical register, \(q_R=\frac{1}{|L_R|}\sum_{L\in L_R}Q(L)\).

| Truth physical address | Associated extracted logical registers and Q(L) | q_R |
|---|---|---:|
| 0x00 (0) | v11.0 registers[0] `Result`=0.990200 | 0.990200 |
| 0x01 (1) | v11.0 registers[1] `Configuration`=0.998218 | 0.998218 |
| 0x02 (2) | v11.0 registers[2] `Low Limit`=0.923507 | 0.923507 |
| 0x03 (3) | v11.0 registers[3] `High Limit`=0.988831 | 0.988831 |
| 0x7E (126) | v11.0 registers[4] `Manufacturer ID`=1.000000 | 1.000000 |
| 0x7F (127) | v11.0 registers[5] `Device ID`=1.000000 | 1.000000 |

\(\sum_{R=1}^{6}q_R=\mathbf{5.900756825}\).

\(m=6,\ x=0,\ \frac{m}{m+x}=\frac{6}{6+0}=1.000000\).

\[S_{final}=\left(\frac{10}{6}\times 5.900756825\right)\times\frac{6}{6+0}=\boxed{\mathbf{9.834594708/10}}\]

## 3. Detailed deduction inventory

Each row identifies the exact truth/extracted path, the complete compared contents, the field correctness `C`, and the specific deduction reason.

| # | Exact location | Truth content | Extracted content | C | Error / omission reason |
|---:|---|---|---|---:|---|
| 1 | `truth registers[0].field_parts[0].bit_field[0].values` ↔ `v11_0 registers[0].field_parts[0].bit_field[0].values` | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."}] | [] | 0.0 | values is empty; missing all truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011'] |
| 2 | `truth registers[1].field_parts[0].bit_field[0].values` ↔ `v11_0 registers[1].field_parts[0].bit_field[0].values` | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."},{"value":"1100b","value_description":"Automatic full-scale setting mode."},{"value":"1101b","value_description":"Reserved for future use."},{"value":"1110b","value_description":"Reserved for future use."},{"value":"1111b","value_description":"Reserved for future use."}] | [{"value":"1100b","value_description":"Automatic full-scale setting mode (power-up default | 0.5 | 0Ch)"},{"value":"1101b","value_description":"Reserved for future use (0Dh)"},{"value":"1110b","value_description":"Reserved for future use (0Eh)"},{"value":"1111b","value_description":"Reserved for future use (0Fh)"}]; values is incomplete; missing truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011'] |
| 3 | `truth registers[1].field_parts[0].bit_field[9].values` ↔ `v11_0 registers[1].field_parts[0].bit_field[9].values` | [{"value":"1","value_description":"Masks the result-register exponent to 0000b when RN[3:0] is less than 1100b."}] | [{"value":"0","value_description":"Exponent masking disabled (default)"},{"value":"1","value_description":"Force result register exponent E[3:0] to 0000b when full-scale range is manually set (RN[3:0] < 1100b)"}] | 0.5 | values is partially correct; missing truth codes [], unsupported codes ['0'] |
| 4 | `truth registers[2].field_parts[0].bit_field[0].values` ↔ `v11_0 registers[2].field_parts[0].bit_field[0].values` | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."},{"value":"LE[3:2] = 11b","value_description":"Enables end-of-conversion mode."}] | [] | 0.0 | values is empty; missing all truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011', 'LE[3:2]=11'] |
| 5 | `truth registers[2].default_value` ↔ `v11_0 registers[2].default_value` | 0000h (C0000h in datasheet is typo) | C0000h | 0.0 | strict default/reset value mismatch or missing value |
| 6 | `truth registers[3].field_parts[0].bit_field[0].field_description` ↔ `v11_0 registers[3].field_parts[0].bit_field[0].field_description` | Exponent bits for the high-limit lux threshold. | Exponent. These bits are the exponent bits. | 0.5 | field_description is materially incomplete: it identifies the exponent field but does not explicitly state the high-limit lux-threshold function |
| 7 | `truth registers[3].field_parts[0].bit_field[0].values` ↔ `v11_0 registers[3].field_parts[0].bit_field[0].values` | [{"value":"0000b","value_description":"Full-scale range 40.95 lux; LSB size 0.01 lux per LSB."},{"value":"0001b","value_description":"Full-scale range 81.90 lux; LSB size 0.02 lux per LSB."},{"value":"0010b","value_description":"Full-scale range 163.80 lux; LSB size 0.04 lux per LSB."},{"value":"0011b","value_description":"Full-scale range 327.60 lux; LSB size 0.08 lux per LSB."},{"value":"0100b","value_description":"Full-scale range 655.20 lux; LSB size 0.16 lux per LSB."},{"value":"0101b","value_description":"Full-scale range 1310.40 lux; LSB size 0.32 lux per LSB."},{"value":"0110b","value_description":"Full-scale range 2620.80 lux; LSB size 0.64 lux per LSB."},{"value":"0111b","value_description":"Full-scale range 5241.60 lux; LSB size 1.28 lux per LSB."},{"value":"1000b","value_description":"Full-scale range 10483.20 lux; LSB size 2.56 lux per LSB."},{"value":"1001b","value_description":"Full-scale range 20966.40 lux; LSB size 5.12 lux per LSB."},{"value":"1010b","value_description":"Full-scale range 41932.80 lux; LSB size 10.24 lux per LSB."},{"value":"1011b","value_description":"Full-scale range 83865.60 lux; LSB size 20.48 lux per LSB."}] | [] | 0.0 | values is empty; missing all truth codes ['0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011'] |

## 4. Invented-field check

- No extra physical address was extracted; `x=0`.
- No unmatched logical register, field part, bit-field range, or unsupported schema field was found.
- Non-contradictory descriptive additions are accepted. They do not compensate for a missing or incorrect objective field.
