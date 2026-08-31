# DPS368 without detailed score - revised AGENTS.md rules

## 1. Scoring basis

- n=33 unique truth physical registers are scored by numeric address together with bank and page; hexadecimal and decimal address strings are treated as the same number.
- without contains 17 extracted logical-register entries and 39 extracted physical field-part entries. Sixteen logical entries are associated with truth physical registers; one `Reserved` logical entry covers six extra addresses 0x22-0x27 and is excluded from q_R.
- The 16 associated entries contain 60 compared bit-field entries, 33 matched field parts, and 16 matched logical-register items. Bottom-up scoring is performed independently for every associated extracted logical register.
- For each truth physical register, q_R is the mean of every associated extracted logical-register score. Missing truth physical registers receive q_R=0. All 33 truth physical locations are covered.
- The six pressure/temperature byte entries are an accepted split of the two multi-address truth logical registers, and the single COEF entry is an accepted merge of all 18 truth COEF physical locations. These grouping choices are not penalized by themselves.
- Objective facts are strict: numeric addresses, bank/page, widths, bit boundaries, reserved classification, access types, names/parameters, defaults, and functional value codes. Description-only wording is judged semantically; relevant paraphrases are accepted without requiring verbatim text.
- Values with the same functional code set receive C=1. A code list with shared truth codes but an omitted or unsupported extra code receives C=0.5; a non-overlapping code set receives C=0.
- Reserved-bit name/description variants such as `-`, `Reserved`, and empty descriptive text are accepted when `is_reserved=true`; reserved classification itself remains strict.
- The rounded AHP weights sum to 0.9999 for bit fields, 1.0000 for field parts, and 1.0001 for logical registers; the displayed formulas normalize by those denominators.
- type_write_read rule: truth and extraction both empty receive C=1.0; truth empty with extracted concrete content receives C=0; truth concrete with extracted empty content receives C=0; concrete values must match exactly.
- The `Reserved` logical entry at without registers[15] has no truth association, so its six physical locations 0x22–0x27 do not contribute to q_R and are counted as six extra extracted physical registers for x.
- The logical name COEF_SRCE is accepted as the canonical abbreviation of truth Coefficient Source. Product ID versus the truth ID name, COEF address-based field-part names, COEF spacing changes in bit names, and the TMP_PRC typo-note omission remain strict objective differences.

## Extracted logical register 1: PRS_B2

without registers[0]; truth association: truth registers[0] (Pressure Data (PRS_Bn)).
Associated physical locations: 0x00 (0).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: PRS_B2 at 0x00 (0)

Locations: truth registers[0].field_parts[0] / without registers[0].field_parts[0].

Truth bit field 1: PRS[23:16] bits 0:7

Locations: truth registers[0].field_parts[0].bit_field[0] / without registers[0].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | PRS[23:16] | PRS[23:16] |
| field_description | 0.0586 | 1.000000 | MSB of 24 bit 2's complement pressure data. | MSB of 24 bit 2´s complement pressure data. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | PRS_B2 | PRS_B2 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Highest byte of the 24-bit pressure value."} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Pressure (MSB data)"} |
| description | 0.0693 | 1.000000 | Highest byte; pressure MSB data. | MSB of 24-bit pressure result |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | PRS_B2 | PRS_B2 |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Highest byte of the 24-bit pressure value."}] | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Pressure (MSB data)"}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement pressure measurement value; when FIFO is enabled, it contains FIFO pressure and/or temperature results. | Highest byte (MSB) of the 24-bit two's complement pressure measurement value. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 00h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 2: PRS_B1

without registers[1]; truth association: truth registers[0] (Pressure Data (PRS_Bn)).
Associated physical locations: 0x01 (1).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: PRS_B1 at 0x01 (1)

Locations: truth registers[0].field_parts[1] / without registers[1].field_parts[0].

Truth bit field 1: PRS[15:8] bits 0:7

Locations: truth registers[0].field_parts[1].bit_field[0] / without registers[1].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | PRS[15:8] | PRS[15:8] |
| field_description | 0.0586 | 1.000000 | Middle byte of 24 bit 2's complement pressure data. | Middle byte of 24 bit 2´s complement pressure data. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | PRS_B1 | PRS_B1 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"Middle byte of the 24-bit pressure value."} | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"Pressure (LSB data)"} |
| description | 0.0693 | 1.000000 | Middle byte of the pressure value. | Middle byte of 24-bit pressure result |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | PRS_B1 | PRS_B1 |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":"Middle byte of the 24-bit pressure value."}] | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":"Pressure (LSB data)"}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement pressure measurement value; when FIFO is enabled, it contains FIFO pressure and/or temperature results. | Middle byte of the 24-bit two's complement pressure measurement value. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 00h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 3: PRS_B0

without registers[2]; truth association: truth registers[0] (Pressure Data (PRS_Bn)).
Associated physical locations: 0x02 (2).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: PRS_B0 at 0x02 (2)

Locations: truth registers[0].field_parts[2] / without registers[2].field_parts[0].

Truth bit field 1: PRS[7:0] bits 0:7

Locations: truth registers[0].field_parts[2].bit_field[0] / without registers[2].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | PRS[7:0] | PRS[7:0] |
| field_description | 0.0586 | 1.000000 | XLSB of 24 bit 2's complement pressure data. | XLSB of 24 bit 2´s complement pressure data. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | PRS_B0 | PRS_B0 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"Lowest byte of the 24-bit pressure value."} | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"Pressure (XLSB data)"} |
| description | 0.0693 | 1.000000 | Lowest byte; pressure XLSB data. | Lowest byte of 24-bit pressure result |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | PRS_B0 | PRS_B0 |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":"Lowest byte of the 24-bit pressure value."}] | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":"Pressure (XLSB data)"}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement pressure measurement value; when FIFO is enabled, it contains FIFO pressure and/or temperature results. | Lowest byte (XLSB) of the 24-bit two's complement pressure measurement value. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 00h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 4: TMP_B2

without registers[3]; truth association: truth registers[1] (Temperature Data (TMP_Tn)).
Associated physical locations: 0x03 (3).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_B2 at 0x03 (3)

Locations: truth registers[1].field_parts[0] / without registers[3].field_parts[0].

Truth bit field 1: TMP[23:16] bits 0:7

Locations: truth registers[1].field_parts[0].bit_field[0] / without registers[3].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP[23:16] | TMP[23:16] |
| field_description | 0.0586 | 1.000000 | MSB of 24 bit 2's complement temperature data. | MSB of 24 bit 2´s complement temperature data. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | TMP_B2 | TMP_B2 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"Highest byte of the 24-bit temperature value."} | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"Temperature (MSB data)"} |
| description | 0.0693 | 1.000000 | Highest byte; temperature MSB data. | MSB of 24-bit temperature result |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | TMP_B2 | TMP_B2 |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"Highest byte of the 24-bit temperature value."}] | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"Temperature (MSB data)"}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement temperature measurement value and is not cleared after read; FIFO operation can affect the result data. | Highest byte (MSB) of the 24-bit two's complement temperature measurement value. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 00h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 5: TMP_B1

without registers[4]; truth association: truth registers[1] (Temperature Data (TMP_Tn)).
Associated physical locations: 0x04 (4).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_B1 at 0x04 (4)

Locations: truth registers[1].field_parts[1] / without registers[4].field_parts[0].

Truth bit field 1: TMP[15:8] bits 0:7

Locations: truth registers[1].field_parts[1].bit_field[0] / without registers[4].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP[15:8] | TMP[15:8] |
| field_description | 0.0586 | 1.000000 | Middle byte of 24 bit 2's complement temperature data. | LSB of 24 bit 2´s complement temperature data. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | TMP_B1 | TMP_B1 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Middle byte of the 24-bit temperature value."} | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Temperature (LSB data)"} |
| description | 0.0693 | 1.000000 | Middle byte of the temperature value. | Middle byte of 24-bit temperature result |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | TMP_B1 | TMP_B1 |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":"Middle byte of the 24-bit temperature value."}] | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":"Temperature (LSB data)"}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement temperature measurement value and is not cleared after read; FIFO operation can affect the result data. | Middle byte of the 24-bit two's complement temperature measurement value. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 00h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 6: TMP_B0

without registers[5]; truth association: truth registers[1] (Temperature Data (TMP_Tn)).
Associated physical locations: 0x05 (5).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_B0 at 0x05 (5)

Locations: truth registers[1].field_parts[2] / without registers[5].field_parts[0].

Truth bit field 1: TMP[7:0] bits 0:7

Locations: truth registers[1].field_parts[2].bit_field[0] / without registers[5].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP[7:0] | TMP[7:0] |
| field_description | 0.0586 | 1.000000 | XLSB of 24 bit 2's complement temperature data. | XLSB of 24 bit 2´s complement temperature data. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | TMP_B0 | TMP_B0 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Lowest byte of the 24-bit temperature value."} | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Temperature (XLSB data)"} |
| description | 0.0693 | 1.000000 | Lowest byte; temperature XLSB data. | Lowest byte of 24-bit temperature result |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | TMP_B0 | TMP_B0 |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x05","decimal":"5","bank":"","page":"","description":"Lowest byte of the 24-bit temperature value."}] | [{"hex":"0x05","decimal":"5","bank":"","page":"","description":"Temperature (XLSB data)"}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement temperature measurement value and is not cleared after read; FIFO operation can affect the result data. | Lowest byte (XLSB) of the 24-bit two's complement temperature measurement value. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 00h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 7: PRS_CFG

without registers[6]; truth association: truth registers[2] (PRS_CFG).
Associated physical locations: 0x06 (6).

### Bottom layer: bit fields, then field parts

#### Field part 1: PRS_CFG at 0x06 (6)

Locations: truth registers[2].field_parts[0] / without registers[6].field_parts[0].

Truth bit field 1: - bits 7:7

Locations: truth registers[2].field_parts[0].bit_field[0] / without registers[6].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | - | Reserved |
| field_description | 0.0586 | 1.000000 | Reserved. | "" |
| bit_start | 0.2594 | 1.000000 | 7 | 7 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | true | true |
| type_write_read | 0.0583 | 1.000000 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: PM_RATE[2:0] bits 4:6

Locations: truth registers[2].field_parts[0].bit_field[1] / without registers[6].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | PM_RATE[2:0] | PM_RATE[2:0] |
| field_description | 0.0586 | 1.000000 | Pressure measurement rate in Background mode. | Pressure measurement rate (applicable in Background mode). |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 6 | 6 |
| bit_width | 0.0583 | 1.000000 | 3 | 3 |
| values | 0.2097 | 1.000000 | [{"value":"000","value_description":"1 measurement per second"},{"value":"001","value_description":"2 measurements per second"},{"value":"010","value_description":"4 measurements per second"},{"value":"011","value_description":"8 measurements per second"},{"value":"100","value_description":"16 measurements per second"},{"value":"101","value_description":"32 measurements per second"},{"value":"110","value_description":"64 measurements per second"},{"value":"111","value_description":"128 measurements per second"}] | [{"value":"000","value_description":"1 measurements pr. sec."},{"value":"001","value_description":"2 measurements pr. sec."},{"value":"010","value_description":"4 measurements pr. sec."},{"value":"011","value_description":"8 measurements pr. sec."},{"value":"100","value_description":"16 measurements pr. sec."},{"value":"101","value_description":"32 measurements pr. sec."},{"value":"110","value_description":"64 measurements pr. sec."},{"value":"111","value_description":"128 measurements pr. sec."}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: PM_PRC[3:0] bits 0:3

Locations: truth registers[2].field_parts[0].bit_field[2] / without registers[6].field_parts[0].bit_field[2].
Judgment: C=0.5: values.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | PM_PRC[3:0] | PM_PRC[3:0] |
| field_description | 0.0586 | 1.000000 | Pressure oversampling rate; settings above 8 times require use with the pressure result bit shift. | Pressure oversampling (precision). |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 0.500000 | [{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard)"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times (High Precision)"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] | [{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard) - use with shift"},{"value":"0101","value_description":"32 times - use with shift"},{"value":"0110","value_description":"64 times (High Precision) - use with shift"},{"value":"0111","value_description":"128 times - use with shift"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*0.500000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.895050/0.9999=\mathbf{0.895140}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 0.895140) = **0.965047**.
Direct judgment: all direct scored fields are correct.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | PRS_CFG | PRS_CFG |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x06","decimal":"6","bank":"","page":"","description":""} | {"hex":"0x06","decimal":"6","bank":"","page":"","description":"Pressure measurement configuration"} |
| description | 0.0693 | 1.000000 | Pressure measurement configuration. | Pressure measurement rate and oversampling configuration |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | RW | RW |
| bit_field | 0.3129 | 0.965047 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.965047)/1.0000=0.989063/1.0000=\mathbf{0.989063}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.989063) = **0.989063**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | PRS_CFG | PRS_CFG |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":""}] | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":"Pressure measurement configuration"}] |
| register_description | 0.0564 | 1.000000 | Configures pressure measurement rate and resolution. | Configures pressure measurement rate (PM_RATE) and oversampling/precision (PM_PRC). |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | RW | RW |
| field_parts | 0.2987 | 0.989063 | truth field-part set | mean(0.989063) |
| default_value | 0.0667 | 1.000000 | 00H | 00h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.989063 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.996833/1.0001=\mathbf{0.996733}\)

## Extracted logical register 8: TMP_CFG

without registers[7]; truth association: truth registers[3] (TMP_CFG).
Associated physical locations: 0x07 (7).

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_CFG at 0x07 (7)

Locations: truth registers[3].field_parts[0] / without registers[7].field_parts[0].

Truth bit field 1: TMP_EXT bits 7:7

Locations: truth registers[3].field_parts[0].bit_field[0] / without registers[7].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP_EXT | TMP_EXT |
| field_description | 0.0586 | 1.000000 | Selects the temperature sensor used for measurement. | Temperature measurement source: 0 = internal ASIC sensor, 1 = external (MEMS) sensor. |
| bit_start | 0.2594 | 1.000000 | 7 | 7 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Internal sensor in ASIC"},{"value":"1","value_description":"External sensor in pressure sensor MEMS element"}] | [{"value":"0","value_description":"Internal temperature sensor (in ASIC)"},{"value":"1","value_description":"External temperature sensor (in pressure sensor MEMS element)"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: TMP_RATE[2:0] bits 4:6

Locations: truth registers[3].field_parts[0].bit_field[1] / without registers[7].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP_RATE[2:0] | TMP_RATE[2:0] |
| field_description | 0.0586 | 1.000000 | Temperature measurement rate in Background mode. | Temperature measurement rate (applicable in Background mode). |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 6 | 6 |
| bit_width | 0.0583 | 1.000000 | 3 | 3 |
| values | 0.2097 | 1.000000 | [{"value":"000","value_description":"1 measurement per second"},{"value":"001","value_description":"2 measurements per second"},{"value":"010","value_description":"4 measurements per second"},{"value":"011","value_description":"8 measurements per second"},{"value":"100","value_description":"16 measurements per second"},{"value":"101","value_description":"32 measurements per second"},{"value":"110","value_description":"64 measurements per second"},{"value":"111","value_description":"128 measurements per second"}] | [{"value":"000","value_description":"1 measurement pr. sec."},{"value":"001","value_description":"2 measurements pr. sec."},{"value":"010","value_description":"4 measurements pr. sec."},{"value":"011","value_description":"8 measurements pr. sec."},{"value":"100","value_description":"16 measurements pr. sec."},{"value":"101","value_description":"32 measurements pr. sec."},{"value":"110","value_description":"64 measurements pr. sec."},{"value":"111","value_description":"128 measurements pr. sec."}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo) bits 0:3

Locations: truth registers[3].field_parts[0].bit_field[2] / without registers[7].field_parts[0].bit_field[2].
Judgment: C=0: name_or_parameter; C=0.5: values.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo) | TMP_PRC[3:0] |
| field_description | 0.0586 | 1.000000 | Temperature oversampling and precision. | Temperature oversampling (precision). |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 0.500000 | [{"value":"0000","value_description":"Single (Default), measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] | [{"value":"0000","value_description":"Single (default) - Measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*0.500000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.873850/0.9999=\mathbf{0.873937}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 0.873937) = **0.957979**.
Direct judgment: all direct scored fields are correct.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | TMP_CFG | TMP_CFG |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} | {"hex":"0x07","decimal":"7","bank":"","page":"","description":"Temperature measurement configuration"} |
| description | 0.0693 | 1.000000 | Temperature measurement configuration. | Temperature measurement source, rate and oversampling configuration |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | RW | RW |
| bit_field | 0.3129 | 0.957979 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.957979)/1.0000=0.986852/1.0000=\mathbf{0.986852}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.986852) = **0.986852**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | TMP_CFG | TMP_CFG |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":""}] | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":"Temperature measurement configuration"}] |
| register_description | 0.0564 | 1.000000 | Configures temperature measurement rate and resolution. | Configures temperature measurement source (TMP_EXT), rate (TMP_RATE) and oversampling/precision (TMP_PRC). |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | RW | RW |
| field_parts | 0.2987 | 0.986852 | truth field-part set | mean(0.986852) |
| default_value | 0.0667 | 1.000000 | 00H | 00h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.986852 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.996173/1.0001=\mathbf{0.996073}\)

## Extracted logical register 9: MEAS_CFG

without registers[8]; truth association: truth registers[4] (MEAS_CFG).
Associated physical locations: 0x08 (8).

### Bottom layer: bit fields, then field parts

#### Field part 1: MEAS_CFG at 0x08 (8)

Locations: truth registers[4].field_parts[0] / without registers[8].field_parts[0].

Truth bit field 1: COEF_RDY bits 7:7

Locations: truth registers[4].field_parts[0].bit_field[0] / without registers[8].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | COEF_RDY | COEF_RDY |
| field_description | 0.0586 | 1.000000 | Indicates whether coefficients have been loaded into the coefficient registers after start-up. | Coefficients available flag: 0 = not available, 1 = available. |
| bit_start | 0.2594 | 1.000000 | 7 | 7 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Coefficients are not available yet"},{"value":"1","value_description":"Coefficients are available"}] | [{"value":"0","value_description":"Coefficients are not available yet"},{"value":"1","value_description":"Coefficients are available"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: SENSOR_RDY bits 6:6

Locations: truth registers[4].field_parts[0].bit_field[1] / without registers[8].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | SENSOR_RDY | SENSOR_RDY |
| field_description | 0.0586 | 1.000000 | Indicates completion of pressure sensor self-initialization after start-up. | Sensor initialization status: 0 = not complete, 1 = complete. |
| bit_start | 0.2594 | 1.000000 | 6 | 6 |
| bit_end | 0.2594 | 1.000000 | 6 | 6 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Sensor initialization not complete"},{"value":"1","value_description":"Sensor initialization complete"}] | [{"value":"0","value_description":"Sensor initialization not complete"},{"value":"1","value_description":"Sensor initialization complete"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: TMP_RDY bits 5:5

Locations: truth registers[4].field_parts[0].bit_field[2] / without registers[8].field_parts[0].bit_field[2].
Judgment: C=0.5: values.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP_RDY | TMP_RDY |
| field_description | 0.0586 | 1.000000 | Temperature measurement ready status; cleared when the temperature measurement is read. | Temperature measurement ready; cleared when temperature is read. |
| bit_start | 0.2594 | 1.000000 | 5 | 5 |
| bit_end | 0.2594 | 1.000000 | 5 | 5 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 0.500000 | [{"value":"1","value_description":"New temperature measurement is ready"}] | [{"value":"0","value_description":"No new temperature measurement"},{"value":"1","value_description":"New temperature measurement ready"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*0.500000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.895050/0.9999=\mathbf{0.895140}\)

Truth bit field 4: PRS_RDY bits 4:4

Locations: truth registers[4].field_parts[0].bit_field[3] / without registers[8].field_parts[0].bit_field[3].
Judgment: C=0.5: values.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | PRS_RDY | PRS_RDY |
| field_description | 0.0586 | 1.000000 | Pressure measurement ready status; cleared when the pressure measurement is read. | Pressure measurement ready; cleared when pressure is read. |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 4 | 4 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 0.500000 | [{"value":"1","value_description":"New pressure measurement is ready"}] | [{"value":"0","value_description":"No new pressure measurement"},{"value":"1","value_description":"New pressure measurement ready"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*0.500000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.895050/0.9999=\mathbf{0.895140}\)

Truth bit field 5: - bits 3:3

Locations: truth registers[4].field_parts[0].bit_field[4] / without registers[8].field_parts[0].bit_field[4].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | - | Reserved |
| field_description | 0.0586 | 1.000000 | Reserved. | "" |
| bit_start | 0.2594 | 1.000000 | 3 | 3 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | true | true |
| type_write_read | 0.0583 | 1.000000 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 6: MEAS_CTRL bits 0:2

Locations: truth registers[4].field_parts[0].bit_field[5] / without registers[8].field_parts[0].bit_field[5].
Judgment: C=0: name_or_parameter; C=0.5: values.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | MEAS_CTRL | MEAS_CTRL[2:0] |
| field_description | 0.0586 | 1.000000 | Sets the measurement mode and type. | Set measurement mode and type (Standby/Command/Background). |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 2 | 2 |
| bit_width | 0.0583 | 1.000000 | 3 | 3 |
| values | 0.2097 | 0.500000 | [{"value":"000","value_description":"Standby: idle or stop background measurement"},{"value":"001","value_description":"Command mode: pressure measurement"},{"value":"010","value_description":"Command mode: temperature measurement"},{"value":"011","value_description":"Not available"},{"value":"100","value_description":"Not available"},{"value":"101","value_description":"Background mode: continuous pressure measurement"},{"value":"110","value_description":"Background mode: continuous temperature measurement"},{"value":"111","value_description":"Background mode: continuous pressure and temperature measurement"}] | [{"value":"000","value_description":"Idle / Stop background measurement (Standby)"},{"value":"001","value_description":"Command Mode: Pressure measurement"},{"value":"010","value_description":"Command Mode: Temperature measurement"},{"value":"101","value_description":"Background Mode: Continuous pressure measurement"},{"value":"110","value_description":"Background Mode: Continuous temperature measurement"},{"value":"111","value_description":"Background Mode: Continuous pressure and temperature measurement"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*0.500000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.873850/0.9999=\mathbf{0.873937}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 0.895140, 0.895140, 1.000000, 0.873937) = **0.944036**.
Direct judgment: all direct scored fields are correct.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | MEAS_CFG | MEAS_CFG |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x08","decimal":"8","bank":"","page":"","description":""} | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"Measurement configuration"} |
| description | 0.0693 | 1.000000 | Measurement configuration and readiness status. | Status flags and measurement control |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | RW | RW |
| bit_field | 0.3129 | 0.944036 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.944036)/1.0000=0.982489/1.0000=\mathbf{0.982489}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.982489) = **0.982489**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | MEAS_CFG | MEAS_CFG |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":""}] | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":"Measurement configuration"}] |
| register_description | 0.0564 | 1.000000 | Sets the measurement operating mode and reports sensor, coefficient, pressure, and temperature readiness. | Measurement-mode and status register: status bits indicate coefficient/sensor/data readiness; MEAS_CTRL selects Standby/Command/Background modes. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | RW | RW |
| field_parts | 0.2987 | 0.982489 | truth field-part set | mean(0.982489) |
| default_value | 0.0667 | 1.000000 | C0H | C0h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.982489 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.994869/1.0001=\mathbf{0.994770}\)

## Extracted logical register 10: CFG_REG

without registers[9]; truth association: truth registers[5] (CFG_REG).
Associated physical locations: 0x09 (9).

### Bottom layer: bit fields, then field parts

#### Field part 1: CFG_REG at 0x09 (9)

Locations: truth registers[5].field_parts[0] / without registers[9].field_parts[0].

Truth bit field 1: INT_HL bits 7:7

Locations: truth registers[5].field_parts[0].bit_field[0] / without registers[9].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | INT_HL | INT_HL |
| field_description | 0.0586 | 1.000000 | Interrupt active level on the SDO pin. | Interrupt (SDO pin) active level: 0 = active low, 1 = active high. |
| bit_start | 0.2594 | 1.000000 | 7 | 7 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Active low"},{"value":"1","value_description":"Active high"}] | [{"value":"0","value_description":"Active low"},{"value":"1","value_description":"Active high"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: INT_FIFO bits 6:6

Locations: truth registers[5].field_parts[0].bit_field[1] / without registers[9].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | INT_FIFO | INT_FIFO |
| field_description | 0.0586 | 1.000000 | Controls interrupt generation when the FIFO is full. | Generate interrupt when FIFO is full: 0 = Disable, 1 = Enable. |
| bit_start | 0.2594 | 1.000000 | 6 | 6 |
| bit_end | 0.2594 | 1.000000 | 6 | 6 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: INT_TMP bits 5:5

Locations: truth registers[5].field_parts[0].bit_field[2] / without registers[9].field_parts[0].bit_field[2].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | INT_TMP | INT_TMP |
| field_description | 0.0586 | 1.000000 | Controls interrupt generation when a temperature measurement is ready. | Generate interrupt when a temperature measurement is ready: 0 = Disable, 1 = Enable. |
| bit_start | 0.2594 | 1.000000 | 5 | 5 |
| bit_end | 0.2594 | 1.000000 | 5 | 5 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 4: INT_PRS bits 4:4

Locations: truth registers[5].field_parts[0].bit_field[3] / without registers[9].field_parts[0].bit_field[3].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | INT_PRS | INT_PRS |
| field_description | 0.0586 | 1.000000 | Controls interrupt generation when a pressure measurement is ready. | Generate interrupt when a pressure measurement is ready: 0 = Disable, 1 = Enable. |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 4 | 4 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 5: T_SHIFT bits 3:3

Locations: truth registers[5].field_parts[0].bit_field[4] / without registers[9].field_parts[0].bit_field[4].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | T_SHIFT | T_SHIFT |
| field_description | 0.0586 | 1.000000 | Temperature result bit shift; must be enabled when oversampling is greater than 8 times. | Temperature result bit-shift: 0 = no shift, 1 = shift right in data register. Must be '1' when oversampling > 8. |
| bit_start | 0.2594 | 1.000000 | 3 | 3 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"No shift"},{"value":"1","value_description":"Shift result right in data register"}] | [{"value":"0","value_description":"no shift"},{"value":"1","value_description":"shift result right in data register"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 6: P_SHIFT bits 2:2

Locations: truth registers[5].field_parts[0].bit_field[5] / without registers[9].field_parts[0].bit_field[5].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | P_SHIFT | P_SHIFT |
| field_description | 0.0586 | 1.000000 | Pressure result bit shift; must be enabled when oversampling is greater than 8 times. | Pressure result bit-shift: 0 = no shift, 1 = shift right in data register. Must be '1' when oversampling > 8. |
| bit_start | 0.2594 | 1.000000 | 2 | 2 |
| bit_end | 0.2594 | 1.000000 | 2 | 2 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"No shift"},{"value":"1","value_description":"Shift result right in data register"}] | [{"value":"0","value_description":"no shift"},{"value":"1","value_description":"shift result right in data register"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 7: FIFO_EN bits 1:1

Locations: truth registers[5].field_parts[0].bit_field[6] / without registers[9].field_parts[0].bit_field[6].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | FIFO_EN | FIFO_EN |
| field_description | 0.0586 | 1.000000 | Enables the FIFO. | Enable the FIFO: 0 = Disable, 1 = Enable. |
| bit_start | 0.2594 | 1.000000 | 1 | 1 |
| bit_end | 0.2594 | 1.000000 | 1 | 1 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 8: SPI_MODE bits 0:0

Locations: truth registers[5].field_parts[0].bit_field[7] / without registers[9].field_parts[0].bit_field[7].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | SPI_MODE | SPI_MODE |
| field_description | 0.0586 | 1.000000 | Selects the SPI interface mode. | Set SPI mode: 0 = 4-wire, 1 = 3-wire. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 0 | 0 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"4-wire interface"},{"value":"1","value_description":"3-wire interface"}] | [{"value":"0","value_description":"4-wire interface"},{"value":"1","value_description":"3-wire interface"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | CFG_REG | CFG_REG |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x09","decimal":"9","bank":"","page":"","description":""} | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"Configuration register (interrupt, shift, FIFO, SPI mode)"} |
| description | 0.0693 | 1.000000 | Interrupt, result-shift, FIFO, and SPI configuration. | Interrupt, FIFO and data-shift configuration |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | RW | RW |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | CFG_REG | CFG_REG |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x09","decimal":"9","bank":"","page":"","description":""}] | [{"hex":"0x09","decimal":"9","bank":"","page":"","description":"Configuration register (interrupt, shift, FIFO, SPI mode)"}] |
| register_description | 0.0564 | 1.000000 | Configures interrupts, measurement data shifts, FIFO enable, and SPI interface mode. | Configures interrupt polarity and selection, result bit-shift for high oversampling, FIFO enable, and SPI mode (3/4-wire). |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | RW | RW |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 00H | 00h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 11: INT_STS

without registers[10]; truth association: truth registers[6] (INT_STS).
Associated physical locations: 0x0A (10).

### Bottom layer: bit fields, then field parts

#### Field part 1: INT_STS at 0x0A (10)

Locations: truth registers[6].field_parts[0] / without registers[10].field_parts[0].

Truth bit field 1: - bits 3:7

Locations: truth registers[6].field_parts[0].bit_field[0] / without registers[10].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | - | Reserved |
| field_description | 0.0586 | 1.000000 | Reserved. | "" |
| bit_start | 0.2594 | 1.000000 | 3 | 3 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 5 | 5 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | true | true |
| type_write_read | 0.0583 | 1.000000 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: INT_FIFO_FULL bits 2:2

Locations: truth registers[6].field_parts[0].bit_field[1] / without registers[10].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | INT_FIFO_FULL | INT_FIFO_FULL |
| field_description | 0.0586 | 1.000000 | FIFO interrupt status. | FIFO full interrupt status: 0 = not active, 1 = active. |
| bit_start | 0.2594 | 1.000000 | 2 | 2 |
| bit_end | 0.2594 | 1.000000 | 2 | 2 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: INT_TMP bits 1:1

Locations: truth registers[6].field_parts[0].bit_field[2] / without registers[10].field_parts[0].bit_field[2].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | INT_TMP | INT_TMP |
| field_description | 0.0586 | 1.000000 | Temperature measurement interrupt status. | Temperature measurement interrupt status: 0 = not active, 1 = active. |
| bit_start | 0.2594 | 1.000000 | 1 | 1 |
| bit_end | 0.2594 | 1.000000 | 1 | 1 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 4: INT_PRS bits 0:0

Locations: truth registers[6].field_parts[0].bit_field[3] / without registers[10].field_parts[0].bit_field[3].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | INT_PRS | INT_PRS |
| field_description | 0.0586 | 1.000000 | Pressure measurement interrupt status. | Pressure measurement interrupt status: 0 = not active, 1 = active. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 0 | 0 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | INT_STS | INT_STS |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":""} | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Interrupt status"} |
| description | 0.0693 | 1.000000 | Interrupt status. | Interrupt status flags (cleared on read) |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | INT_STS | INT_STS |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":""}] | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Interrupt status"}] |
| register_description | 0.0564 | 1.000000 | Reports FIFO, temperature measurement, and pressure measurement interrupt status; cleared on read. | Interrupt status register; cleared on read. Indicates FIFO full, temperature ready, pressure ready interrupts. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 00H | 00h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 12: FIFO_STS

without registers[11]; truth association: truth registers[7] (FIFO_STS).
Associated physical locations: 0x0B (11).

### Bottom layer: bit fields, then field parts

#### Field part 1: FIFO_STS at 0x0B (11)

Locations: truth registers[7].field_parts[0] / without registers[11].field_parts[0].

Truth bit field 1: - bits 2:7

Locations: truth registers[7].field_parts[0].bit_field[0] / without registers[11].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | - | Reserved |
| field_description | 0.0586 | 1.000000 | Reserved. | "" |
| bit_start | 0.2594 | 1.000000 | 2 | 2 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 6 | 6 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | true | true |
| type_write_read | 0.0583 | 1.000000 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: FIFO_FULL bits 1:1

Locations: truth registers[7].field_parts[0].bit_field[1] / without registers[11].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | FIFO_FULL | FIFO_FULL |
| field_description | 0.0586 | 1.000000 | FIFO full status. | FIFO full flag: 0 = not full, 1 = full. |
| bit_start | 0.2594 | 1.000000 | 1 | 1 |
| bit_end | 0.2594 | 1.000000 | 1 | 1 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"FIFO is not full"},{"value":"1","value_description":"FIFO is full"}] | [{"value":"0","value_description":"The FIFO is not full"},{"value":"1","value_description":"The FIFO is full"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: FIFO_EMPTY bits 0:0

Locations: truth registers[7].field_parts[0].bit_field[2] / without registers[11].field_parts[0].bit_field[2].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | FIFO_EMPTY | FIFO_EMPTY |
| field_description | 0.0586 | 1.000000 | FIFO empty status. | FIFO empty flag: 0 = not empty, 1 = empty. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 0 | 0 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"FIFO is not empty"},{"value":"1","value_description":"FIFO is empty"}] | [{"value":"0","value_description":"The FIFO is not empty"},{"value":"1","value_description":"The FIFO is empty"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | FIFO_STS | FIFO_STS |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":""} | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"FIFO status register"} |
| description | 0.0693 | 1.000000 | FIFO status. | FIFO status flags |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | FIFO_STS | FIFO_STS |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x0B","decimal":"11","bank":"","page":"","description":""}] | [{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"FIFO status register"}] |
| register_description | 0.0564 | 1.000000 | Reports whether the FIFO is full or empty. | FIFO status flags: FIFO_FULL and FIFO_EMPTY. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 00H | 00h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 13: RESET

without registers[12]; truth association: truth registers[8] (RESET).
Associated physical locations: 0x0C (12).

### Bottom layer: bit fields, then field parts

#### Field part 1: RESET at 0x0C (12)

Locations: truth registers[8].field_parts[0] / without registers[12].field_parts[0].

Truth bit field 1: FIFO_FLUSH bits 7:7

Locations: truth registers[8].field_parts[0].bit_field[0] / without registers[12].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | FIFO_FLUSH | FIFO_FLUSH |
| field_description | 0.0586 | 1.000000 | Flushes the FIFO; after reading all FIFO data, write 1 to clear old data. | FIFO flush: write '1' to empty FIFO (use after reading out data). |
| bit_start | 0.2594 | 1.000000 | 7 | 7 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"1","value_description":"Empty FIFO"}] | [{"value":"1","value_description":"Empty FIFO"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | W | W |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: - bits 4:6

Locations: truth registers[8].field_parts[0].bit_field[1] / without registers[12].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | - | Reserved |
| field_description | 0.0586 | 1.000000 | Reserved. | "" |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 6 | 6 |
| bit_width | 0.0583 | 1.000000 | 3 | 3 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | true | true |
| type_write_read | 0.0583 | 1.000000 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: SOFT_RST bits 0:3

Locations: truth registers[8].field_parts[0].bit_field[2] / without registers[12].field_parts[0].bit_field[2].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | SOFT_RST | SOFT_RST |
| field_description | 0.0586 | 1.000000 | Generates a soft reset using the same sequence as power-on reset. | Soft reset: write '1001' to bits[3:0] to generate a soft reset (runs same sequences as POR). |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [{"value":"1001","value_description":"Generate a soft reset"}] | [{"value":"1001","value_description":"Generate a soft reset"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | W | W |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | RESET | RESET |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":""} | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Soft reset and FIFO flush"} |
| description | 0.0693 | 1.000000 | FIFO flush and soft reset control. | Control for FIFO flush and soft reset (write-only fields). |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | W | W |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | RESET | RESET |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":""}] | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Soft reset and FIFO flush"}] |
| register_description | 0.0564 | 1.000000 | Flushes the FIFO or generates a soft reset. | Write to flush FIFO or generate a soft reset. FIFO_FLUSH empties FIFO; SOFT_RST requires writing 0x9 (1001) to bits[3:0]. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | W | W |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 00H | 00h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 14: Product ID

without registers[13]; truth association: truth registers[9] (Product and Revision ID (ID)).
Associated physical locations: 0x0D (13).

### Bottom layer: bit fields, then field parts

#### Field part 1: ID at 0x0D (13)

Locations: truth registers[9].field_parts[0] / without registers[13].field_parts[0].

Truth bit field 1: REV_ID bits 4:7

Locations: truth registers[9].field_parts[0].bit_field[0] / without registers[13].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | REV_ID | REV_ID |
| field_description | 0.0586 | 1.000000 | Revision ID. | Revision ID. |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: PROD_ID bits 0:3

Locations: truth registers[9].field_parts[0].bit_field[1] / without registers[13].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | PROD_ID | PROD_ID |
| field_description | 0.0586 | 1.000000 | Product ID. | Product ID. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | ID | Product ID |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":""} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Product and revision ID"} |
| description | 0.0693 | 1.000000 | Product and revision identification. | Product and revision identifiers |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=0.972000/1.0000=\mathbf{0.972000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.972000) = **0.972000**.
Direct judgment: C=0: name.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 0.000000 | Product and Revision ID (ID) | Product ID |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":""}] | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Product and revision ID"}] |
| register_description | 0.0564 | 1.000000 | Contains the product and revision identifiers. | Product and revision identification: REV_ID in bits[7:4], PROD_ID in bits[3:0]. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 0.972000 | truth field-part set | mean(0.972000) |
| default_value | 0.0667 | 1.000000 | 0x10 / 10H (0x10H in datasheet is typo) | 10h |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*0.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.972000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.969236/1.0001=\mathbf{0.969139}\)

## Extracted logical register 15: COEF

without registers[14]; truth association: truth registers[10] (COEF).
Associated physical locations: 0x10 (16), 0x11 (17), 0x12 (18), 0x13 (19), 0x14 (20), 0x15 (21), 0x16 (22), 0x17 (23), 0x18 (24), 0x19 (25), 0x1A (26), 0x1B (27), 0x1C (28), 0x1D (29), 0x1E (30), 0x1F (31), 0x20 (32), 0x21 (33).
Accepted COEF merge: the one extracted COEF logical register is compared against all 18 truth COEF physical field parts.

### Bottom layer: bit fields, then field parts

#### Field part 1: c0 at 0x10 (16)

Locations: truth registers[10].field_parts[0] / without registers[14].field_parts[0].

Truth bit field 1: c0 [11:4] bits 0:7

Locations: truth registers[10].field_parts[0].bit_field[0] / without registers[14].field_parts[0].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c0 [11:4] | c0[11:4] |
| field_description | 0.0586 | 1.000000 | Bits 11:4 of coefficient c0. | Upper 8 bits of coefficient c0 (bits 11:4). |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c0 | COEF 0x10 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"c0 bits 11:4."} | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"Calibration coefficient c0 [11:4]"} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c0. | c0[11:4] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 2: c0/c1 at 0x11 (17)

Locations: truth registers[10].field_parts[1] / without registers[14].field_parts[1].

Truth bit field 1: c0 [3:0] bits 4:7

Locations: truth registers[10].field_parts[1].bit_field[0] / without registers[14].field_parts[1].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c0 [3:0] | c0[3:0] |
| field_description | 0.0586 | 1.000000 | Bits 3:0 of coefficient c0. | Lower 4 bits of coefficient c0. |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Truth bit field 2: c1 [11:8] bits 0:3

Locations: truth registers[10].field_parts[1].bit_field[1] / without registers[14].field_parts[1].bit_field[1].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c1 [11:8] | c1[11:8] |
| field_description | 0.0586 | 1.000000 | Bits 11:8 of coefficient c1. | Upper 4 bits of coefficient c1. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798, 0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c0/c1 | COEF 0x11 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Contains c0 bits 3:0 and c1 bits 11:8."} | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"c0[3:0] and c1[11:8]"} |
| description | 0.0693 | 1.000000 | Lower four bits of c0 and upper four bits of c1. | Lower bits of c0 and upper bits of c1 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 3: c1 at 0x12 (18)

Locations: truth registers[10].field_parts[2] / without registers[14].field_parts[2].

Truth bit field 1: c1[7:0] bits 0:7

Locations: truth registers[10].field_parts[2].bit_field[0] / without registers[14].field_parts[2].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | c1[7:0] | c1[7:0] |
| field_description | 0.0586 | 1.000000 | Bits 7:0 of coefficient c1. | Lower 8 bits of coefficient c1. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c1 | COEF 0x12 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"c1 bits 7:0."} | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"c1[7:0]"} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c1. | c1 lower 8 bits |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=0.972000/1.0000=\mathbf{0.972000}\)

#### Field part 4: c00 at 0x13 (19)

Locations: truth registers[10].field_parts[3] / without registers[14].field_parts[3].

Truth bit field 1: c00 [19:12] bits 0:7

Locations: truth registers[10].field_parts[3].bit_field[0] / without registers[14].field_parts[3].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c00 [19:12] | c00[19:12] |
| field_description | 0.0586 | 1.000000 | Bits 19:12 of coefficient c00. | Bits 19:12 of coefficient c00. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c00 | COEF 0x13 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"c00 bits 19:12."} | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"c00 [19:12]"} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c00. | c00 bits 19:12 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 5: c00 at 0x14 (20)

Locations: truth registers[10].field_parts[4] / without registers[14].field_parts[4].

Truth bit field 1: c00 [11:4] bits 0:7

Locations: truth registers[10].field_parts[4].bit_field[0] / without registers[14].field_parts[4].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c00 [11:4] | c00[11:4] |
| field_description | 0.0586 | 1.000000 | Bits 11:4 of coefficient c00. | Bits 11:4 of coefficient c00. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c00 | COEF 0x14 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"c00 bits 11:4."} | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"c00 [11:4]"} |
| description | 0.0693 | 1.000000 | Middle eight bits of coefficient c00. | c00 bits 11:4 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 6: c00/c10 at 0x15 (21)

Locations: truth registers[10].field_parts[5] / without registers[14].field_parts[5].

Truth bit field 1: c00 [3:0] bits 4:7

Locations: truth registers[10].field_parts[5].bit_field[0] / without registers[14].field_parts[5].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c00 [3:0] | c00[3:0] |
| field_description | 0.0586 | 1.000000 | Bits 3:0 of coefficient c00. | Lower 4 bits of coefficient c00. |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Truth bit field 2: c10 [19:16] bits 0:3

Locations: truth registers[10].field_parts[5].bit_field[1] / without registers[14].field_parts[5].bit_field[1].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c10 [19:16] | c10[19:16] |
| field_description | 0.0586 | 1.000000 | Bits 19:16 of coefficient c10. | Upper 4 bits of coefficient c10. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798, 0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c00/c10 | COEF 0x15 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Contains c00 bits 3:0 and c10 bits 19:16."} | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"c00[3:0] and c10[19:16]"} |
| description | 0.0693 | 1.000000 | Lower four bits of c00 and upper four bits of c10. | Lower bits of c00 and upper bits of c10 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 7: c10 at 0x16 (22)

Locations: truth registers[10].field_parts[6] / without registers[14].field_parts[6].

Truth bit field 1: c10 [15:8] bits 0:7

Locations: truth registers[10].field_parts[6].bit_field[0] / without registers[14].field_parts[6].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c10 [15:8] | c10[15:8] |
| field_description | 0.0586 | 1.000000 | Bits 15:8 of coefficient c10. | Bits 15:8 of coefficient c10. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c10 | COEF 0x16 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"c10 bits 15:8."} | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"c10 [15:8]"} |
| description | 0.0693 | 1.000000 | Middle eight bits of coefficient c10. | c10 bits 15:8 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 8: c10 at 0x17 (23)

Locations: truth registers[10].field_parts[7] / without registers[14].field_parts[7].

Truth bit field 1: c10 [7:0] bits 0:7

Locations: truth registers[10].field_parts[7].bit_field[0] / without registers[14].field_parts[7].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c10 [7:0] | c10[7:0] |
| field_description | 0.0586 | 1.000000 | Bits 7:0 of coefficient c10. | Lower 8 bits of coefficient c10. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c10 | COEF 0x17 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"c10 bits 7:0."} | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"c10 [7:0]"} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c10. | c10 bits 7:0 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 9: c01 at 0x18 (24)

Locations: truth registers[10].field_parts[8] / without registers[14].field_parts[8].

Truth bit field 1: c01 [15:8] bits 0:7

Locations: truth registers[10].field_parts[8].bit_field[0] / without registers[14].field_parts[8].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c01 [15:8] | c01[15:8] |
| field_description | 0.0586 | 1.000000 | Bits 15:8 of coefficient c01. | Bits 15:8 of coefficient c01. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c01 | COEF 0x18 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"c01 bits 15:8."} | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"c01 [15:8]"} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c01. | c01 bits 15:8 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 10: c01 at 0x19 (25)

Locations: truth registers[10].field_parts[9] / without registers[14].field_parts[9].

Truth bit field 1: c01 [7:0] bits 0:7

Locations: truth registers[10].field_parts[9].bit_field[0] / without registers[14].field_parts[9].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c01 [7:0] | c01[7:0] |
| field_description | 0.0586 | 1.000000 | Bits 7:0 of coefficient c01. | Lower 8 bits of coefficient c01. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c01 | COEF 0x19 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x19","decimal":"25","bank":"","page":"","description":"c01 bits 7:0."} | {"hex":"0x19","decimal":"25","bank":"","page":"","description":"c01 [7:0]"} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c01. | c01 bits 7:0 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 11: c11 at 0x1A (26)

Locations: truth registers[10].field_parts[10] / without registers[14].field_parts[10].

Truth bit field 1: c11 [15:8] bits 0:7

Locations: truth registers[10].field_parts[10].bit_field[0] / without registers[14].field_parts[10].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c11 [15:8] | c11[15:8] |
| field_description | 0.0586 | 1.000000 | Bits 15:8 of coefficient c11. | Bits 15:8 of coefficient c11. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c11 | COEF 0x1A |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"c11 bits 15:8."} | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"c11 [15:8]"} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c11. | c11 bits 15:8 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 12: c11 at 0x1B (27)

Locations: truth registers[10].field_parts[11] / without registers[14].field_parts[11].

Truth bit field 1: c11 [7:0] bits 0:7

Locations: truth registers[10].field_parts[11].bit_field[0] / without registers[14].field_parts[11].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c11 [7:0] | c11[7:0] |
| field_description | 0.0586 | 1.000000 | Bits 7:0 of coefficient c11. | Lower 8 bits of coefficient c11. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c11 | COEF 0x1B |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"c11 bits 7:0."} | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"c11 [7:0]"} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c11. | c11 bits 7:0 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 13: c20 at 0x1C (28)

Locations: truth registers[10].field_parts[12] / without registers[14].field_parts[12].

Truth bit field 1: c20 [15:8] bits 0:7

Locations: truth registers[10].field_parts[12].bit_field[0] / without registers[14].field_parts[12].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c20 [15:8] | c20[15:8] |
| field_description | 0.0586 | 1.000000 | Bits 15:8 of coefficient c20. | Bits 15:8 of coefficient c20. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c20 | COEF 0x1C |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"c20 bits 15:8."} | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"c20 [15:8]"} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c20. | c20 bits 15:8 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 14: c20 at 0x1D (29)

Locations: truth registers[10].field_parts[13] / without registers[14].field_parts[13].

Truth bit field 1: c20 [7:0] bits 0:7

Locations: truth registers[10].field_parts[13].bit_field[0] / without registers[14].field_parts[13].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c20 [7:0] | c20[7:0] |
| field_description | 0.0586 | 1.000000 | Bits 7:0 of coefficient c20. | Lower 8 bits of coefficient c20. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c20 | COEF 0x1D |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"c20 bits 7:0."} | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"c20 [7:0]"} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c20. | c20 bits 7:0 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 15: c21 at 0x1E (30)

Locations: truth registers[10].field_parts[14] / without registers[14].field_parts[14].

Truth bit field 1: c21 [15:8] bits 0:7

Locations: truth registers[10].field_parts[14].bit_field[0] / without registers[14].field_parts[14].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c21 [15:8] | c21[15:8] |
| field_description | 0.0586 | 1.000000 | Bits 15:8 of coefficient c21. | Bits 15:8 of coefficient c21. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c21 | COEF 0x1E |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"c21 bits 15:8."} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"c21 [15:8]"} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c21. | c21 bits 15:8 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 16: c21 at 0x1F (31)

Locations: truth registers[10].field_parts[15] / without registers[14].field_parts[15].

Truth bit field 1: c21 [7:0] bits 0:7

Locations: truth registers[10].field_parts[15].bit_field[0] / without registers[14].field_parts[15].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c21 [7:0] | c21[7:0] |
| field_description | 0.0586 | 1.000000 | Bits 7:0 of coefficient c21. | Lower 8 bits of coefficient c21. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c21 | COEF 0x1F |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"c21 bits 7:0."} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"c21 [7:0]"} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c21. | c21 bits 7:0 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 17: c30 at 0x20 (32)

Locations: truth registers[10].field_parts[16] / without registers[14].field_parts[16].

Truth bit field 1: c30 [15:8] bits 0:7

Locations: truth registers[10].field_parts[16].bit_field[0] / without registers[14].field_parts[16].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c30 [15:8] | c30[15:8] |
| field_description | 0.0586 | 1.000000 | Bits 15:8 of coefficient c30. | Bits 15:8 of coefficient c30. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c30 | COEF 0x20 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"c30 bits 15:8."} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"c30 [15:8]"} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c30. | c30 bits 15:8 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

#### Field part 18: c30 at 0x21 (33)

Locations: truth registers[10].field_parts[17] / without registers[14].field_parts[17].

Truth bit field 1: c30 [7:0] bits 0:7

Locations: truth registers[10].field_parts[17].bit_field[0] / without registers[14].field_parts[17].bit_field[0].
Judgment: C=0: name_or_parameter.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c30 [7:0] | c30[7:0] |
| field_description | 0.0586 | 1.000000 | Bits 7:0 of coefficient c30. | Lower 8 bits of coefficient c30. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798) = **0.978798**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c30 | COEF 0x21 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"c30 bits 7:0."} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"c30 [7:0]"} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c30. | c30 bits 7:0 |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.965366, 0.965366, 0.972000, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366) = **0.965734**.
Direct judgment: C=0: width_bits, default_value_description.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | COEF | COEF |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x10","decimal":"16","bank":"","page":"","description":"c0 bits 11:4."},{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Contains c0 bits 3:0 and c1 bits 11:8."},{"hex":"0x12","decimal":"18","bank":"","page":"","description":"c1 bits 7:0."},{"hex":"0x13","decimal":"19","bank":"","page":"","description":"c00 bits 19:12."},{"hex":"0x14","decimal":"20","bank":"","page":"","description":"c00 bits 11:4."},{"hex":"0x15","decimal":"21","bank":"","page":"","description":"Contains c00 bits 3:0 and c10 bits 19:16."},{"hex":"0x16","decimal":"22","bank":"","page":"","description":"c10 bits 15:8."},{"hex":"0x17","decimal":"23","bank":"","page":"","description":"c10 bits 7:0."},{"hex":"0x18","decimal":"24","bank":"","page":"","description":"c01 bits 15:8."},{"hex":"0x19","decimal":"25","bank":"","page":"","description":"c01 bits 7:0."},{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"c11 bits 15:8."},{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"c11 bits 7:0."},{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"c20 bits 15:8."},{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"c20 bits 7:0."},{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"c21 bits 15:8."},{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"c21 bits 7:0."},{"hex":"0x20","decimal":"32","bank":"","page":"","description":"c30 bits 15:8."},{"hex":"0x21","decimal":"33","bank":"","page":"","description":"c30 bits 7:0."}] | [{"hex":"0x10","decimal":"16","bank":"","page":"","description":"Calibration coefficient c0 [11:4]"},{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Calibration coefficient c0[3:0] and c1[11:8]"},{"hex":"0x12","decimal":"18","bank":"","page":"","description":"Calibration coefficient c1[7:0]"},{"hex":"0x13","decimal":"19","bank":"","page":"","description":"Calibration coefficient c00 [19:12]"},{"hex":"0x14","decimal":"20","bank":"","page":"","description":"Calibration coefficient c00 [11:4]"},{"hex":"0x15","decimal":"21","bank":"","page":"","description":"Calibration coefficient c00[3:0] and c10[19:16]"},{"hex":"0x16","decimal":"22","bank":"","page":"","description":"Calibration coefficient c10[15:8]"},{"hex":"0x17","decimal":"23","bank":"","page":"","description":"Calibration coefficient c10[7:0]"},{"hex":"0x18","decimal":"24","bank":"","page":"","description":"Calibration coefficient c01[15:8]"},{"hex":"0x19","decimal":"25","bank":"","page":"","description":"Calibration coefficient c01[7:0]"},{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Calibration coefficient c11[15:8]"},{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Calibration coefficient c11[7:0]"},{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Calibration coefficient c20[15:8]"},{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Calibration coefficient c20[7:0]"},{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Calibration coefficient c21[15:8]"},{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Calibration coefficient c21[7:0]"},{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Calibration coefficient c30[15:8]"},{"hex":"0x21","decimal":"33","bank":"","page":"","description":"Calibration coefficient c30[7:0]"}] |
| register_description | 0.0564 | 1.000000 | Contains 2's complement calibration coefficients used to calculate compensated pressure and temperature values. | Calibration coefficients (two's complement) used to compute compensated pressure and temperature values. Coefficients span addresses 0x10 through 0x21 and have specific bit layouts per byte. |
| width_bits | 0.0590 | 0.000000 | 144 | EMPTY |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 0.965734 | truth field-part set | mean(0.965366, 0.965366, 0.972000, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366, 0.965366) |
| default_value | 0.0667 | 1.000000 | XXh | XXh |
| default_value_description | 0.0334 | 0.000000 | "" | Per-byte default unspecified in source |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*0.000000 + 0.0590*1.000000 + 0.2987*0.965734 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.897465/1.0001=\mathbf{0.897375}\)

## Extracted logical register 16: Reserved (extra)

without registers[15]; no truth physical register is associated with its physical locations 0x22 (34), 0x23 (35), 0x24 (36), 0x25 (37), 0x26 (38), 0x27 (39).
This logical register is explicitly reserved and is excluded from q_R because it has no truth association. Its six physical locations are retained as audit entries and are counted as extra extracted physical registers; they are not silently matched to the truth address range.

| Extra field-part location | register_name | physical_address | description | width_bits | type_write_read | bit_field[0] scored content |
|---|---|---|---|---:|---|---|
| without registers[15].field_parts[0] | Reserved 0x22 | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Reserved"} | "" | 8 | "" | {"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":true,"type_write_read":""} |
| without registers[15].field_parts[1] | Reserved 0x23 | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"Reserved"} | "" | 8 | "" | {"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":true,"type_write_read":""} |
| without registers[15].field_parts[2] | Reserved 0x24 | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Reserved"} | "" | 8 | "" | {"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":true,"type_write_read":""} |
| without registers[15].field_parts[3] | Reserved 0x25 | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"Reserved"} | "" | 8 | "" | {"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":true,"type_write_read":""} |
| without registers[15].field_parts[4] | Reserved 0x26 | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Reserved"} | "" | 8 | "" | {"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":true,"type_write_read":""} |
| without registers[15].field_parts[5] | Reserved 0x27 | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"Reserved"} | "" | 8 | "" | {"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":true,"type_write_read":""} |

The extra bit-field records above are documented for completeness but receive no truth-relative Q(L). Their six physical locations are extra extracted physical registers and therefore contribute x=6 to the global extra-register penalty.

## Extracted logical register 17: COEF_SRCE

without registers[16]; truth association: truth registers[11] (Coefficient Source).
Associated physical locations: 0x28 (40).

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_COEF_SRCE at 0x28 (40)

Locations: truth registers[11].field_parts[0] / without registers[16].field_parts[0].

Truth bit field 1: TMP_COEF_SRCE bits 7:7

Locations: truth registers[11].field_parts[0].bit_field[0] / without registers[16].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP_COEF_SRCE | TMP_COEF_SRCE |
| field_description | 0.0586 | 1.000000 | Identifies the temperature sensor on which the calibration coefficients are based. | Temperature coefficients are based on: 0 = internal ASIC sensor, 1 = external MEMS sensor. |
| bit_start | 0.2594 | 1.000000 | 7 | 7 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Internal temperature sensor of ASIC"},{"value":"1","value_description":"External temperature sensor of pressure sensor MEMS element"}] | [{"value":"0","value_description":"Internal temperature sensor (of ASIC)"},{"value":"1","value_description":"External temperature sensor (of pressure sensor MEMS element)"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: - bits 0:6

Locations: truth registers[11].field_parts[0].bit_field[1] / without registers[16].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | - | Reserved |
| field_description | 0.0586 | 1.000000 | Reserved. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 6 | 6 |
| bit_width | 0.0583 | 1.000000 | 7 | 7 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | true | true |
| type_write_read | 0.0583 | 1.000000 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.
Direct judgment: C=0: register_name.

| Field-part field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | TMP_COEF_SRCE | COEF_SRCE |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":""} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Temperature Coefficients Source"} |
| description | 0.0693 | 1.000000 | Temperature coefficient source selection status. | Source of temperature coefficients |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | without bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=0.972000/1.0000=\mathbf{0.972000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.972000) = **0.972000**.
Direct judgment: all direct scored fields are correct.

| Logical-register field | Weight | C | Truth comparison target | without content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | Coefficient Source | COEF_SRCE |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":""}] | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Temperature Coefficients Source"}] |
| register_description | 0.0564 | 1.000000 | States whether the calibration coefficients are based on the ASIC temperature sensor or the pressure-sensor MEMS temperature sensor. | Indicates which internal temperature sensor the calibration coefficients are based on: bit7 = TMP_COEF_SRCE (0 = internal ASIC sensor, 1 = external MEMS sensor). |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 0.972000 | truth field-part set | mean(0.972000) |
| default_value | 0.0667 | 1.000000 | XXH | XXh |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.972000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.991736/1.0001=\mathbf{0.991637}\)

## 2. Physical-register aggregation and final score

| Truth physical location | Truth logical / field part | Associated extracted logical register(s) | q_R |
|---|---|---|---:|
| 0x00 (0) | Pressure Data (PRS_Bn) / PRS_B2 | without registers[0] (PRS_B2, Q=1.000000) | 1.000000 |
| 0x01 (1) | Pressure Data (PRS_Bn) / PRS_B1 | without registers[1] (PRS_B1, Q=1.000000) | 1.000000 |
| 0x02 (2) | Pressure Data (PRS_Bn) / PRS_B0 | without registers[2] (PRS_B0, Q=1.000000) | 1.000000 |
| 0x03 (3) | Temperature Data (TMP_Tn) / TMP_B2 | without registers[3] (TMP_B2, Q=1.000000) | 1.000000 |
| 0x04 (4) | Temperature Data (TMP_Tn) / TMP_B1 | without registers[4] (TMP_B1, Q=1.000000) | 1.000000 |
| 0x05 (5) | Temperature Data (TMP_Tn) / TMP_B0 | without registers[5] (TMP_B0, Q=1.000000) | 1.000000 |
| 0x06 (6) | PRS_CFG / PRS_CFG | without registers[6] (PRS_CFG, Q=0.996733) | 0.996733 |
| 0x07 (7) | TMP_CFG / TMP_CFG | without registers[7] (TMP_CFG, Q=0.996073) | 0.996073 |
| 0x08 (8) | MEAS_CFG / MEAS_CFG | without registers[8] (MEAS_CFG, Q=0.994770) | 0.994770 |
| 0x09 (9) | CFG_REG / CFG_REG | without registers[9] (CFG_REG, Q=1.000000) | 1.000000 |
| 0x0A (10) | INT_STS / INT_STS | without registers[10] (INT_STS, Q=1.000000) | 1.000000 |
| 0x0B (11) | FIFO_STS / FIFO_STS | without registers[11] (FIFO_STS, Q=1.000000) | 1.000000 |
| 0x0C (12) | RESET / RESET | without registers[12] (RESET, Q=1.000000) | 1.000000 |
| 0x0D (13) | Product and Revision ID (ID) / ID | without registers[13] (Product ID, Q=0.969139) | 0.969139 |
| 0x10 (16) | COEF / c0 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x11 (17) | COEF / c0/c1 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x12 (18) | COEF / c1 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x13 (19) | COEF / c00 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x14 (20) | COEF / c00 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x15 (21) | COEF / c00/c10 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x16 (22) | COEF / c10 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x17 (23) | COEF / c10 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x18 (24) | COEF / c01 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x19 (25) | COEF / c01 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x1A (26) | COEF / c11 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x1B (27) | COEF / c11 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x1C (28) | COEF / c20 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x1D (29) | COEF / c20 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x1E (30) | COEF / c21 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x1F (31) | COEF / c21 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x20 (32) | COEF / c30 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x21 (33) | COEF / c30 | without registers[14] (COEF, Q=0.897375) | 0.897375 |
| 0x28 (40) | Coefficient Source / TMP_COEF_SRCE | without registers[16] (COEF_SRCE, Q=0.991637) | 0.991637 |

- sum(q_R) = 31.101105530 across 33 truth physical registers.
- Matched physical registers m=33; the six extracted locations 0x22–0x27 are outside the truth physical-register set, so extra extracted physical registers x=6; extra penalty m/(m+x) = **0.846153846**.
- Final score: S_final=(10/33 * 31.101105530) * (33/(33+6)) = **7.974642444 / 10**.

## 3. Detailed deduction inventory

The inventory below lists every direct scored field with C<1 for the 16 truth-associated logical-register items. Recursive bit_field and field_parts values are not additional direct deductions; their exact bottom-up consequences are shown above. The six reserved physical locations are shown separately for auditability and are excluded from x.

| # | Exact location | Field | C | Truth content | Extracted content | Specific error |
|---:|---|---|---:|---|---|---|
| 1 | truth registers[2].field_parts[0].bit_field[2] / without registers[6].field_parts[0].bit_field[2] | values | 0.5 | [{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard)"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times (High Precision)"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] | [{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard) - use with shift"},{"value":"0101","value_description":"32 times - use with shift"},{"value":"0110","value_description":"64 times (High Precision) - use with shift"},{"value":"0111","value_description":"128 times - use with shift"}] | functional value-code list is incomplete or contains unsupported extra codes; partial credit C=0.5: truth=[{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard)"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times (High Precision)"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}], extracted=[{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard) - use with shift"},{"value":"0101","value_description":"32 times - use with shift"},{"value":"0110","value_description":"64 times (High Precision) - use with shift"},{"value":"0111","value_description":"128 times - use with shift"}] |
| 2 | truth registers[3].field_parts[0].bit_field[2] / without registers[7].field_parts[0].bit_field[2] | name_or_parameter | 0.0 | TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo) | TMP_PRC[3:0] | objective name/parameter differs or is missing: truth=TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo), extracted=TMP_PRC[3:0] |
| 3 | truth registers[3].field_parts[0].bit_field[2] / without registers[7].field_parts[0].bit_field[2] | values | 0.5 | [{"value":"0000","value_description":"Single (Default), measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] | [{"value":"0000","value_description":"Single (default) - Measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"}] | functional value-code list is incomplete or contains unsupported extra codes; partial credit C=0.5: truth=[{"value":"0000","value_description":"Single (Default), measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}], extracted=[{"value":"0000","value_description":"Single (default) - Measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"}] |
| 4 | truth registers[4].field_parts[0].bit_field[2] / without registers[8].field_parts[0].bit_field[2] | values | 0.5 | [{"value":"1","value_description":"New temperature measurement is ready"}] | [{"value":"0","value_description":"No new temperature measurement"},{"value":"1","value_description":"New temperature measurement ready"}] | functional value-code list is incomplete or contains unsupported extra codes; partial credit C=0.5: truth=[{"value":"1","value_description":"New temperature measurement is ready"}], extracted=[{"value":"0","value_description":"No new temperature measurement"},{"value":"1","value_description":"New temperature measurement ready"}] |
| 5 | truth registers[4].field_parts[0].bit_field[3] / without registers[8].field_parts[0].bit_field[3] | values | 0.5 | [{"value":"1","value_description":"New pressure measurement is ready"}] | [{"value":"0","value_description":"No new pressure measurement"},{"value":"1","value_description":"New pressure measurement ready"}] | functional value-code list is incomplete or contains unsupported extra codes; partial credit C=0.5: truth=[{"value":"1","value_description":"New pressure measurement is ready"}], extracted=[{"value":"0","value_description":"No new pressure measurement"},{"value":"1","value_description":"New pressure measurement ready"}] |
| 6 | truth registers[4].field_parts[0].bit_field[5] / without registers[8].field_parts[0].bit_field[5] | name_or_parameter | 0.0 | MEAS_CTRL | MEAS_CTRL[2:0] | objective name/parameter differs or is missing: truth=MEAS_CTRL, extracted=MEAS_CTRL[2:0] |
| 7 | truth registers[4].field_parts[0].bit_field[5] / without registers[8].field_parts[0].bit_field[5] | values | 0.5 | [{"value":"000","value_description":"Standby: idle or stop background measurement"},{"value":"001","value_description":"Command mode: pressure measurement"},{"value":"010","value_description":"Command mode: temperature measurement"},{"value":"011","value_description":"Not available"},{"value":"100","value_description":"Not available"},{"value":"101","value_description":"Background mode: continuous pressure measurement"},{"value":"110","value_description":"Background mode: continuous temperature measurement"},{"value":"111","value_description":"Background mode: continuous pressure and temperature measurement"}] | [{"value":"000","value_description":"Idle / Stop background measurement (Standby)"},{"value":"001","value_description":"Command Mode: Pressure measurement"},{"value":"010","value_description":"Command Mode: Temperature measurement"},{"value":"101","value_description":"Background Mode: Continuous pressure measurement"},{"value":"110","value_description":"Background Mode: Continuous temperature measurement"},{"value":"111","value_description":"Background Mode: Continuous pressure and temperature measurement"}] | functional value-code list is incomplete or contains unsupported extra codes; partial credit C=0.5: truth=[{"value":"000","value_description":"Standby: idle or stop background measurement"},{"value":"001","value_description":"Command mode: pressure measurement"},{"value":"010","value_description":"Command mode: temperature measurement"},{"value":"011","value_description":"Not available"},{"value":"100","value_description":"Not available"},{"value":"101","value_description":"Background mode: continuous pressure measurement"},{"value":"110","value_description":"Background mode: continuous temperature measurement"},{"value":"111","value_description":"Background mode: continuous pressure and temperature measurement"}], extracted=[{"value":"000","value_description":"Idle / Stop background measurement (Standby)"},{"value":"001","value_description":"Command Mode: Pressure measurement"},{"value":"010","value_description":"Command Mode: Temperature measurement"},{"value":"101","value_description":"Background Mode: Continuous pressure measurement"},{"value":"110","value_description":"Background Mode: Continuous temperature measurement"},{"value":"111","value_description":"Background Mode: Continuous pressure and temperature measurement"}] |
| 8 | truth registers[9] / without registers[13] | name | 0.0 | Product and Revision ID (ID) | Product ID | objective name/parameter differs or is missing: truth=Product and Revision ID (ID), extracted=Product ID |
| 9 | truth registers[9].field_parts[0] / without registers[13].field_parts[0] | register_name | 0.0 | ID | Product ID | objective name/parameter differs or is missing: truth=ID, extracted=Product ID |
| 10 | truth registers[10] / without registers[14] | width_bits | 0.0 | 144 | EMPTY | objective width_bits differs or is missing: truth=144, extracted=EMPTY |
| 11 | truth registers[10] / without registers[14] | default_value_description | 0.0 | "" | Per-byte default unspecified in source | default-value description differs or is unsupported: truth="", extracted=Per-byte default unspecified in source |
| 12 | truth registers[10].field_parts[0] / without registers[14].field_parts[0] | register_name | 0.0 | c0 | COEF 0x10 | objective name/parameter differs or is missing: truth=c0, extracted=COEF 0x10 |
| 13 | truth registers[10].field_parts[0].bit_field[0] / without registers[14].field_parts[0].bit_field[0] | name_or_parameter | 0.0 | c0 [11:4] | c0[11:4] | objective name/parameter differs or is missing: truth=c0 [11:4], extracted=c0[11:4] |
| 14 | truth registers[10].field_parts[1] / without registers[14].field_parts[1] | register_name | 0.0 | c0/c1 | COEF 0x11 | objective name/parameter differs or is missing: truth=c0/c1, extracted=COEF 0x11 |
| 15 | truth registers[10].field_parts[1].bit_field[0] / without registers[14].field_parts[1].bit_field[0] | name_or_parameter | 0.0 | c0 [3:0] | c0[3:0] | objective name/parameter differs or is missing: truth=c0 [3:0], extracted=c0[3:0] |
| 16 | truth registers[10].field_parts[1].bit_field[1] / without registers[14].field_parts[1].bit_field[1] | name_or_parameter | 0.0 | c1 [11:8] | c1[11:8] | objective name/parameter differs or is missing: truth=c1 [11:8], extracted=c1[11:8] |
| 17 | truth registers[10].field_parts[2] / without registers[14].field_parts[2] | register_name | 0.0 | c1 | COEF 0x12 | objective name/parameter differs or is missing: truth=c1, extracted=COEF 0x12 |
| 18 | truth registers[10].field_parts[3] / without registers[14].field_parts[3] | register_name | 0.0 | c00 | COEF 0x13 | objective name/parameter differs or is missing: truth=c00, extracted=COEF 0x13 |
| 19 | truth registers[10].field_parts[3].bit_field[0] / without registers[14].field_parts[3].bit_field[0] | name_or_parameter | 0.0 | c00 [19:12] | c00[19:12] | objective name/parameter differs or is missing: truth=c00 [19:12], extracted=c00[19:12] |
| 20 | truth registers[10].field_parts[4] / without registers[14].field_parts[4] | register_name | 0.0 | c00 | COEF 0x14 | objective name/parameter differs or is missing: truth=c00, extracted=COEF 0x14 |
| 21 | truth registers[10].field_parts[4].bit_field[0] / without registers[14].field_parts[4].bit_field[0] | name_or_parameter | 0.0 | c00 [11:4] | c00[11:4] | objective name/parameter differs or is missing: truth=c00 [11:4], extracted=c00[11:4] |
| 22 | truth registers[10].field_parts[5] / without registers[14].field_parts[5] | register_name | 0.0 | c00/c10 | COEF 0x15 | objective name/parameter differs or is missing: truth=c00/c10, extracted=COEF 0x15 |
| 23 | truth registers[10].field_parts[5].bit_field[0] / without registers[14].field_parts[5].bit_field[0] | name_or_parameter | 0.0 | c00 [3:0] | c00[3:0] | objective name/parameter differs or is missing: truth=c00 [3:0], extracted=c00[3:0] |
| 24 | truth registers[10].field_parts[5].bit_field[1] / without registers[14].field_parts[5].bit_field[1] | name_or_parameter | 0.0 | c10 [19:16] | c10[19:16] | objective name/parameter differs or is missing: truth=c10 [19:16], extracted=c10[19:16] |
| 25 | truth registers[10].field_parts[6] / without registers[14].field_parts[6] | register_name | 0.0 | c10 | COEF 0x16 | objective name/parameter differs or is missing: truth=c10, extracted=COEF 0x16 |
| 26 | truth registers[10].field_parts[6].bit_field[0] / without registers[14].field_parts[6].bit_field[0] | name_or_parameter | 0.0 | c10 [15:8] | c10[15:8] | objective name/parameter differs or is missing: truth=c10 [15:8], extracted=c10[15:8] |
| 27 | truth registers[10].field_parts[7] / without registers[14].field_parts[7] | register_name | 0.0 | c10 | COEF 0x17 | objective name/parameter differs or is missing: truth=c10, extracted=COEF 0x17 |
| 28 | truth registers[10].field_parts[7].bit_field[0] / without registers[14].field_parts[7].bit_field[0] | name_or_parameter | 0.0 | c10 [7:0] | c10[7:0] | objective name/parameter differs or is missing: truth=c10 [7:0], extracted=c10[7:0] |
| 29 | truth registers[10].field_parts[8] / without registers[14].field_parts[8] | register_name | 0.0 | c01 | COEF 0x18 | objective name/parameter differs or is missing: truth=c01, extracted=COEF 0x18 |
| 30 | truth registers[10].field_parts[8].bit_field[0] / without registers[14].field_parts[8].bit_field[0] | name_or_parameter | 0.0 | c01 [15:8] | c01[15:8] | objective name/parameter differs or is missing: truth=c01 [15:8], extracted=c01[15:8] |
| 31 | truth registers[10].field_parts[9] / without registers[14].field_parts[9] | register_name | 0.0 | c01 | COEF 0x19 | objective name/parameter differs or is missing: truth=c01, extracted=COEF 0x19 |
| 32 | truth registers[10].field_parts[9].bit_field[0] / without registers[14].field_parts[9].bit_field[0] | name_or_parameter | 0.0 | c01 [7:0] | c01[7:0] | objective name/parameter differs or is missing: truth=c01 [7:0], extracted=c01[7:0] |
| 33 | truth registers[10].field_parts[10] / without registers[14].field_parts[10] | register_name | 0.0 | c11 | COEF 0x1A | objective name/parameter differs or is missing: truth=c11, extracted=COEF 0x1A |
| 34 | truth registers[10].field_parts[10].bit_field[0] / without registers[14].field_parts[10].bit_field[0] | name_or_parameter | 0.0 | c11 [15:8] | c11[15:8] | objective name/parameter differs or is missing: truth=c11 [15:8], extracted=c11[15:8] |
| 35 | truth registers[10].field_parts[11] / without registers[14].field_parts[11] | register_name | 0.0 | c11 | COEF 0x1B | objective name/parameter differs or is missing: truth=c11, extracted=COEF 0x1B |
| 36 | truth registers[10].field_parts[11].bit_field[0] / without registers[14].field_parts[11].bit_field[0] | name_or_parameter | 0.0 | c11 [7:0] | c11[7:0] | objective name/parameter differs or is missing: truth=c11 [7:0], extracted=c11[7:0] |
| 37 | truth registers[10].field_parts[12] / without registers[14].field_parts[12] | register_name | 0.0 | c20 | COEF 0x1C | objective name/parameter differs or is missing: truth=c20, extracted=COEF 0x1C |
| 38 | truth registers[10].field_parts[12].bit_field[0] / without registers[14].field_parts[12].bit_field[0] | name_or_parameter | 0.0 | c20 [15:8] | c20[15:8] | objective name/parameter differs or is missing: truth=c20 [15:8], extracted=c20[15:8] |
| 39 | truth registers[10].field_parts[13] / without registers[14].field_parts[13] | register_name | 0.0 | c20 | COEF 0x1D | objective name/parameter differs or is missing: truth=c20, extracted=COEF 0x1D |
| 40 | truth registers[10].field_parts[13].bit_field[0] / without registers[14].field_parts[13].bit_field[0] | name_or_parameter | 0.0 | c20 [7:0] | c20[7:0] | objective name/parameter differs or is missing: truth=c20 [7:0], extracted=c20[7:0] |
| 41 | truth registers[10].field_parts[14] / without registers[14].field_parts[14] | register_name | 0.0 | c21 | COEF 0x1E | objective name/parameter differs or is missing: truth=c21, extracted=COEF 0x1E |
| 42 | truth registers[10].field_parts[14].bit_field[0] / without registers[14].field_parts[14].bit_field[0] | name_or_parameter | 0.0 | c21 [15:8] | c21[15:8] | objective name/parameter differs or is missing: truth=c21 [15:8], extracted=c21[15:8] |
| 43 | truth registers[10].field_parts[15] / without registers[14].field_parts[15] | register_name | 0.0 | c21 | COEF 0x1F | objective name/parameter differs or is missing: truth=c21, extracted=COEF 0x1F |
| 44 | truth registers[10].field_parts[15].bit_field[0] / without registers[14].field_parts[15].bit_field[0] | name_or_parameter | 0.0 | c21 [7:0] | c21[7:0] | objective name/parameter differs or is missing: truth=c21 [7:0], extracted=c21[7:0] |
| 45 | truth registers[10].field_parts[16] / without registers[14].field_parts[16] | register_name | 0.0 | c30 | COEF 0x20 | objective name/parameter differs or is missing: truth=c30, extracted=COEF 0x20 |
| 46 | truth registers[10].field_parts[16].bit_field[0] / without registers[14].field_parts[16].bit_field[0] | name_or_parameter | 0.0 | c30 [15:8] | c30[15:8] | objective name/parameter differs or is missing: truth=c30 [15:8], extracted=c30[15:8] |
| 47 | truth registers[10].field_parts[17] / without registers[14].field_parts[17] | register_name | 0.0 | c30 | COEF 0x21 | objective name/parameter differs or is missing: truth=c30, extracted=COEF 0x21 |
| 48 | truth registers[10].field_parts[17].bit_field[0] / without registers[14].field_parts[17].bit_field[0] | name_or_parameter | 0.0 | c30 [7:0] | c30[7:0] | objective name/parameter differs or is missing: truth=c30 [7:0], extracted=c30[7:0] |
| 49 | truth registers[11].field_parts[0] / without registers[16].field_parts[0] | register_name | 0.0 | TMP_COEF_SRCE | COEF_SRCE | objective name/parameter differs or is missing: truth=TMP_COEF_SRCE, extracted=COEF_SRCE |

- Total direct inventory rows with C<1: 49. Partial rows C=0.5 are the five functionally overlapping but incomplete/extra value-code lists; all remaining inventory rows have C=0.

### Missing and extra physical locations

- No truth physical location is missing.
- Extra extracted physical locations: 0x22 (34), 0x23 (35), 0x24 (36), 0x25 (37), 0x26 (38), 0x27 (39), all from without registers[15].
- The `Reserved` logical entry at without registers[15] covers exactly these six locations. They are outside the truth physical-register set and therefore produce x=6; their reserved status does not exempt them from the extra-physical-register penalty.

## 4. Empty type_write_read audit

- Audited scored logical-register, field-part, and bit-field access-type comparisons: 109 (16 logical + 33 field-part + 60 bit-field).
- Truth/extraction both empty: C=1.0 in 6 comparisons. These cases were explicitly credited and are not deductions.
- Truth empty but extraction concrete: 0 comparisons.
- Truth concrete but extraction empty: 0 comparisons.
- Both concrete: 103 comparisons; exact matches: 103; concrete mismatches: 0.
- COEF logical-register, field-part, and bit-field access types use R in both truth and without wherever the items correspond; the updated COEF truth access types therefore receive full credit.
- Credited empty/empty locations:
  - truth registers[2].field_parts[0].bit_field[0] / without registers[6].field_parts[0].bit_field[0] -> C=1.0.
  - truth registers[4].field_parts[0].bit_field[4] / without registers[8].field_parts[0].bit_field[4] -> C=1.0.
  - truth registers[6].field_parts[0].bit_field[0] / without registers[10].field_parts[0].bit_field[0] -> C=1.0.
  - truth registers[7].field_parts[0].bit_field[0] / without registers[11].field_parts[0].bit_field[0] -> C=1.0.
  - truth registers[8].field_parts[0].bit_field[1] / without registers[12].field_parts[0].bit_field[1] -> C=1.0.
  - truth registers[11].field_parts[0].bit_field[1] / without registers[16].field_parts[0].bit_field[1] -> C=1.0.

## 5. Invented-field and representation check

- The six explicitly reserved locations are extra extracted physical registers, so x=6 and the extra-physical-register penalty is applied; no extra physical address is silently matched to a nearby truth address.
- The six pressure/temperature byte entries are an accepted split of the two multi-address truth logical registers; their split representation is not penalized.
- The single COEF entry is an accepted merged representation of all 18 truth COEF physical parts. Its 20 coefficient bit fields align with the truth coefficient fields; all corresponding COEF access types are R.
- The `Reserved` logical entry at without registers[15] is not a truth register. Its six physical locations 0x22-0x27 are documented reserved locations, retained for auditability and counted in x.
- Reserved-bit name/description variants are accepted when `is_reserved=true`; the six genuine reserved empty/empty type_write_read comparisons receive C=1.0.
- COEF_SRCE is treated as the canonical shorthand for Coefficient Source only at the logical-register name field; its physical field part is compared strictly as TMP_COEF_SRCE and receives the name deduction.
- No fields outside the scored AGENTS.md field lists are included in the numerical score.

## 6. Calculation conclusion

All 16 truth-associated logical-register items were reviewed bottom-up, including every matched field part and all 60 compared bit fields. The additional Reserved logical item and each of its six extra physical locations are documented separately. The final DPS368 without score is **7.974642444 / 10**.
