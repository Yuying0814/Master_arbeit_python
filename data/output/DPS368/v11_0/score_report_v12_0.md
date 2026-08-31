# DPS368 v12.0 detailed score - revised AGENTS.md rules

## 1. Scoring basis

- n=33 unique truth physical registers are scored by numeric address together with bank and page; hexadecimal and decimal address strings are treated as the same number.
- v12 contains 16 extracted logical-register entries, 33 extracted physical field-part entries, and 59 extracted bit-field entries. Bottom-up bit-field, field-part, and logical-register scores are calculated independently for every extracted logical-register item.
- For each truth physical register, q_R is the mean of every associated extracted logical-register score. Missing truth physical registers receive q_R=0. No truth physical register is missing in v12.
- The six pressure/temperature byte entries are an accepted split of the two multi-address truth logical registers, and the single COEF entry is an accepted merge of all 18 COEF physical locations. These grouping choices are not penalized by themselves.
- Objective facts are strict: numeric addresses, bank/page, widths, bit boundaries, reserved classification, access types, names/parameters, defaults, and functional value codes. Description-only wording is treated leniently; present semantically relevant paraphrases are accepted without requiring verbatim text.
- The rounded AHP weights sum to 0.9999 for bit fields, 1.0000 for field parts, and 1.0001 for logical registers; the displayed formulas normalize by those denominators.
- type_write_read rule: truth and extraction both empty receive C=1.0; truth empty with extracted concrete content receives C=0; truth concrete with extracted empty content receives C=0; concrete values must match exactly.
- The logical name COEF_SRCE is accepted as the canonical abbreviation of truth Coefficient Source. PSR versus PRS, Product ID versus the truth ID name, COEF address-based part names, and bit-field naming/range changes remain strict objective differences.
- Values are compared by ordered functional value codes; their prose descriptions are not required to be verbatim. Physical-address descriptions are not separately scored beyond the numeric address plus bank/page identity.

## Extracted logical register 1: PSR_B2

v12 registers[0]; truth association: truth registers[0] (Pressure Data (PRS_Bn)).
Associated physical locations: 0x00 (0).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: PRS_B2 at 0x00 (0)

Locations: truth registers[0].field_parts[0] / v12 registers[0].field_parts[0].

Truth bit field 1: PRS[23:16] bits 0:7

Locations: truth registers[0].field_parts[0].bit_field[0] / v12 registers[0].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | PRS[23:16] | PRS[23:16] |
| field_description | 0.0586 | 1.000000 | MSB of 24 bit 2's complement pressure data. | MSB of 24 bit 2's complement pressure data. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | PRS_B2 | PSR_B2 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Highest byte of the 24-bit pressure value."} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"MSB of 24-bit pressure data"} |
| description | 0.0693 | 1.000000 | Highest byte; pressure MSB data. | Pressure (MSB data) |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=0.972000/1.0000=\mathbf{0.972000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.972000) = **0.972000**.
Direct judgment: incorrect/missing direct fields: name.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 0.000000 | PRS_B2 | PSR_B2 |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Highest byte of the 24-bit pressure value."}] | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"MSB of 24-bit pressure data"}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement pressure measurement value; when FIFO is enabled, it contains FIFO pressure and/or temperature results. | The highest byte of the three bytes measured pressure value. Contains MSB of 24-bit 2's complement pressure data. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 0.972000 | truth field-part set | mean(0.972000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*0.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.972000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.969236/1.0001=\mathbf{0.969139}\)

## Extracted logical register 2: PSR_B1

v12 registers[1]; truth association: truth registers[0] (Pressure Data (PRS_Bn)).
Associated physical locations: 0x01 (1).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: PRS_B1 at 0x01 (1)

Locations: truth registers[0].field_parts[1] / v12 registers[1].field_parts[0].

Truth bit field 1: PRS[15:8] bits 0:7

Locations: truth registers[0].field_parts[1].bit_field[0] / v12 registers[1].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | PRS[15:8] | PRS[15:8] |
| field_description | 0.0586 | 1.000000 | Middle byte of 24 bit 2's complement pressure data. | LSB of 24 bit 2's complement pressure data. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | PRS_B1 | PSR_B1 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"Middle byte of the 24-bit pressure value."} | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"Middle byte of 24-bit pressure data"} |
| description | 0.0693 | 1.000000 | Middle byte of the pressure value. | Pressure (LSB data) |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=0.972000/1.0000=\mathbf{0.972000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.972000) = **0.972000**.
Direct judgment: incorrect/missing direct fields: name.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 0.000000 | PRS_B1 | PSR_B1 |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":"Middle byte of the 24-bit pressure value."}] | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":"Middle byte of 24-bit pressure data"}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement pressure measurement value; when FIFO is enabled, it contains FIFO pressure and/or temperature results. | The middle byte of the three bytes measured pressure value. Contains bits [15:8] of 24-bit 2's complement pressure data. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 0.972000 | truth field-part set | mean(0.972000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*0.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.972000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.969236/1.0001=\mathbf{0.969139}\)

## Extracted logical register 3: PSR_B0

v12 registers[2]; truth association: truth registers[0] (Pressure Data (PRS_Bn)).
Associated physical locations: 0x02 (2).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: PRS_B0 at 0x02 (2)

Locations: truth registers[0].field_parts[2] / v12 registers[2].field_parts[0].

Truth bit field 1: PRS[7:0] bits 0:7

Locations: truth registers[0].field_parts[2].bit_field[0] / v12 registers[2].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | PRS[7:0] | PRS[7:0] |
| field_description | 0.0586 | 1.000000 | XLSB of 24 bit 2's complement pressure data. | XLSB of 24 bit 2's complement pressure data. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | PRS_B0 | PSR_B0 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"Lowest byte of the 24-bit pressure value."} | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"LSB of 24-bit pressure data"} |
| description | 0.0693 | 1.000000 | Lowest byte; pressure XLSB data. | Pressure (XLSB data) |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=0.972000/1.0000=\mathbf{0.972000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.972000) = **0.972000**.
Direct judgment: incorrect/missing direct fields: name.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 0.000000 | PRS_B0 | PSR_B0 |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":"Lowest byte of the 24-bit pressure value."}] | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":"LSB of 24-bit pressure data"}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement pressure measurement value; when FIFO is enabled, it contains FIFO pressure and/or temperature results. | The lowest byte of the three bytes measured pressure value. Contains XLSB of 24-bit 2's complement pressure data. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 0.972000 | truth field-part set | mean(0.972000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*0.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.972000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.969236/1.0001=\mathbf{0.969139}\)

## Extracted logical register 4: TMP_B2

v12 registers[3]; truth association: truth registers[1] (Temperature Data (TMP_Tn)).
Associated physical locations: 0x03 (3).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_B2 at 0x03 (3)

Locations: truth registers[1].field_parts[0] / v12 registers[3].field_parts[0].

Truth bit field 1: TMP[23:16] bits 0:7

Locations: truth registers[1].field_parts[0].bit_field[0] / v12 registers[3].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP[23:16] | TMP[23:16] |
| field_description | 0.0586 | 1.000000 | MSB of 24 bit 2's complement temperature data. | MSB of 24 bit 2's complement temperature data. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | TMP_B2 | TMP_B2 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"Highest byte of the 24-bit temperature value."} | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"MSB of 24-bit temperature data"} |
| description | 0.0693 | 1.000000 | Highest byte; temperature MSB data. | Temperature (MSB data) |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | TMP_B2 | TMP_B2 |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"Highest byte of the 24-bit temperature value."}] | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"MSB of 24-bit temperature data"}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement temperature measurement value and is not cleared after read; FIFO operation can affect the result data. | The highest byte of the three bytes measured temperature value. Contains MSB of 24-bit 2's complement temperature data. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 5: TMP_B1

v12 registers[4]; truth association: truth registers[1] (Temperature Data (TMP_Tn)).
Associated physical locations: 0x04 (4).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_B1 at 0x04 (4)

Locations: truth registers[1].field_parts[1] / v12 registers[4].field_parts[0].

Truth bit field 1: TMP[15:8] bits 0:7

Locations: truth registers[1].field_parts[1].bit_field[0] / v12 registers[4].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP[15:8] | TMP[15:8] |
| field_description | 0.0586 | 1.000000 | Middle byte of 24 bit 2's complement temperature data. | LSB of 24 bit 2's complement temperature data. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | TMP_B1 | TMP_B1 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Middle byte of the 24-bit temperature value."} | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Middle byte of 24-bit temperature data"} |
| description | 0.0693 | 1.000000 | Middle byte of the temperature value. | Temperature (LSB data) |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | TMP_B1 | TMP_B1 |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":"Middle byte of the 24-bit temperature value."}] | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":"Middle byte of 24-bit temperature data"}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement temperature measurement value and is not cleared after read; FIFO operation can affect the result data. | The middle byte of the three bytes measured temperature value. Contains bits [15:8] of 24-bit 2's complement temperature data. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 6: TMP_B0

v12 registers[5]; truth association: truth registers[1] (Temperature Data (TMP_Tn)).
Associated physical locations: 0x05 (5).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_B0 at 0x05 (5)

Locations: truth registers[1].field_parts[2] / v12 registers[5].field_parts[0].

Truth bit field 1: TMP[7:0] bits 0:7

Locations: truth registers[1].field_parts[2].bit_field[0] / v12 registers[5].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP[7:0] | TMP[7:0] |
| field_description | 0.0586 | 1.000000 | XLSB of 24 bit 2's complement temperature data. | XLSB of 24 bit 2's complement temperature data. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | TMP_B0 | TMP_B0 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Lowest byte of the 24-bit temperature value."} | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"LSB of 24-bit temperature data"} |
| description | 0.0693 | 1.000000 | Lowest byte; temperature XLSB data. | Temperature (XLSB data) |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | TMP_B0 | TMP_B0 |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x05","decimal":"5","bank":"","page":"","description":"Lowest byte of the 24-bit temperature value."}] | [{"hex":"0x05","decimal":"5","bank":"","page":"","description":"LSB of 24-bit temperature data"}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement temperature measurement value and is not cleared after read; FIFO operation can affect the result data. | The lowest byte of the three bytes measured temperature value. Contains XLSB of 24-bit 2's complement temperature data. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 7: PRS_CFG

v12 registers[6]; truth association: truth registers[2] (PRS_CFG).
Associated physical locations: 0x06 (6).

### Bottom layer: bit fields, then field parts

#### Field part 1: PRS_CFG at 0x06 (6)

Locations: truth registers[2].field_parts[0] / v12 registers[6].field_parts[0].

Truth bit field 1: - bits 7:7

Locations: truth registers[2].field_parts[0].bit_field[0] / v12 registers[6].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | - | - |
| field_description | 0.0586 | 1.000000 | Reserved. | Reserved. |
| bit_start | 0.2594 | 1.000000 | 7 | 7 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | true | true |
| type_write_read | 0.0583 | 1.000000 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: PM_RATE[2:0] bits 4:6

Locations: truth registers[2].field_parts[0].bit_field[1] / v12 registers[6].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | PM_RATE[2:0] | PM_RATE[2:0] |
| field_description | 0.0586 | 1.000000 | Pressure measurement rate in Background mode. | Pressure measurement rate: 000 - 1 measurements pr. sec., 001 - 2 measurements pr. sec., 010 - 4 measurements pr. sec., 011 - 8 measurements pr. sec., 100 - 16 measurements pr. sec., 101 - 32 measurements pr. sec., 110 - 64 measurements pr. sec., 111 - 128 measurements pr. sec. Applicable for measurements in Background mode only |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 6 | 6 |
| bit_width | 0.0583 | 1.000000 | 3 | 3 |
| values | 0.2097 | 1.000000 | [{"value":"000","value_description":"1 measurement per second"},{"value":"001","value_description":"2 measurements per second"},{"value":"010","value_description":"4 measurements per second"},{"value":"011","value_description":"8 measurements per second"},{"value":"100","value_description":"16 measurements per second"},{"value":"101","value_description":"32 measurements per second"},{"value":"110","value_description":"64 measurements per second"},{"value":"111","value_description":"128 measurements per second"}] | [{"value":"000","value_description":"1 measurements per second"},{"value":"001","value_description":"2 measurements per second"},{"value":"010","value_description":"4 measurements per second"},{"value":"011","value_description":"8 measurements per second"},{"value":"100","value_description":"16 measurements per second"},{"value":"101","value_description":"32 measurements per second"},{"value":"110","value_description":"64 measurements per second"},{"value":"111","value_description":"128 measurements per second"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: PM_PRC[3:0] bits 0:3

Locations: truth registers[2].field_parts[0].bit_field[2] / v12 registers[6].field_parts[0].bit_field[2].
Judgment: incorrect/missing scored fields: values.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | PM_PRC[3:0] | PM_PRC[3:0] |
| field_description | 0.0586 | 1.000000 | Pressure oversampling rate; settings above 8 times require use with the pressure result bit shift. | Pressure oversampling rate: 0000 - Single (Low Precision), 0001 - 2 times (Low Power), 0010 - 4 times, 0011 - 8 times, 0100 - 16 times (Standard), 0101 - 32 times, 0110 - 64 times (High Precision), 0111 - 128 times. 1xxx - Reserved |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 0.000000 | [{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard)"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times (High Precision)"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] | [{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard). Note: Use in combination with a bit shift."},{"value":"0101","value_description":"32 times. Note: Use in combination with a bit shift."},{"value":"0110","value_description":"64 times (High Precision). Note: Use in combination with a bit shift."},{"value":"0111","value_description":"128 times. Note: Use in combination with a bit shift."}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*0.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.790200/0.9999=\mathbf{0.790279}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 0.790279) = **0.930093**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | PRS_CFG | PRS_CFG |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x06","decimal":"6","bank":"","page":"","description":""} | {"hex":"0x06","decimal":"6","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Pressure measurement configuration. | Pressure measurement configuration |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | RW | RW |
| bit_field | 0.3129 | 0.930093 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.930093)/1.0000=0.978126/1.0000=\mathbf{0.978126}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.978126) = **0.978126**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | PRS_CFG | PRS_CFG |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":""}] | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.000000 | Configures pressure measurement rate and resolution. | Configuration of pressure measurement rate (PM_RATE) and resolution (PM_PRC). |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | RW | RW |
| field_parts | 0.2987 | 0.978126 | truth field-part set | mean(0.978126) |
| default_value | 0.0667 | 1.000000 | 00H | 0x00 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.978126 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.993566/1.0001=\mathbf{0.993467}\)

## Extracted logical register 8: TMP_CFG

v12 registers[7]; truth association: truth registers[3] (TMP_CFG).
Associated physical locations: 0x07 (7).

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_CFG at 0x07 (7)

Locations: truth registers[3].field_parts[0] / v12 registers[7].field_parts[0].

Truth bit field 1: TMP_EXT bits 7:7

Locations: truth registers[3].field_parts[0].bit_field[0] / v12 registers[7].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP_EXT | TMP_EXT |
| field_description | 0.0586 | 1.000000 | Selects the temperature sensor used for measurement. | Temperature measurement: 0 - Internal sensor (in ASIC), 1 - External sensor (in pressure sensor MEMS element). Note: It is highly recommended to use the same temperature sensor as the source of the calibration coefficients. |
| bit_start | 0.2594 | 1.000000 | 7 | 7 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Internal sensor in ASIC"},{"value":"1","value_description":"External sensor in pressure sensor MEMS element"}] | [{"value":"0","value_description":"Internal sensor (in ASIC)"},{"value":"1","value_description":"External sensor (in pressure sensor MEMS element)"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: TMP_RATE[2:0] bits 4:6

Locations: truth registers[3].field_parts[0].bit_field[1] / v12 registers[7].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP_RATE[2:0] | TMP_RATE[2:0] |
| field_description | 0.0586 | 1.000000 | Temperature measurement rate in Background mode. | Temperature measurement rate: 000 - 1 measurement pr. sec., 001 - 2 measurements pr. sec., 010 - 4 measurements pr. sec., 011 - 8 measurements pr. sec., 100 - 16 measurements pr. sec., 101 - 32 measurements pr. sec., 110 - 64 measurements pr. sec., 111 - 128 measurements pr. sec. Applicable for measurements in Background mode only |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 6 | 6 |
| bit_width | 0.0583 | 1.000000 | 3 | 3 |
| values | 0.2097 | 1.000000 | [{"value":"000","value_description":"1 measurement per second"},{"value":"001","value_description":"2 measurements per second"},{"value":"010","value_description":"4 measurements per second"},{"value":"011","value_description":"8 measurements per second"},{"value":"100","value_description":"16 measurements per second"},{"value":"101","value_description":"32 measurements per second"},{"value":"110","value_description":"64 measurements per second"},{"value":"111","value_description":"128 measurements per second"}] | [{"value":"000","value_description":"1 measurement per second"},{"value":"001","value_description":"2 measurements per second"},{"value":"010","value_description":"4 measurements per second"},{"value":"011","value_description":"8 measurements per second"},{"value":"100","value_description":"16 measurements per second"},{"value":"101","value_description":"32 measurements per second"},{"value":"110","value_description":"64 measurements per second"},{"value":"111","value_description":"128 measurements per second"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo) bits 0:3

Locations: truth registers[3].field_parts[0].bit_field[2] / v12 registers[7].field_parts[0].bit_field[2].
Judgment: incorrect/missing scored fields: name_or_parameter, bit_start, bit_width, values, is_reserved, type_write_read.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo) | - |
| field_description | 0.0586 | 1.000000 | Temperature oversampling and precision. | Reserved. |
| bit_start | 0.2594 | 0.000000 | 0 | 3 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 0.000000 | 4 | 1 |
| values | 0.2097 | 0.000000 | [{"value":"0000","value_description":"Single (Default), measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] | [] |
| is_reserved | 0.0750 | 0.000000 | false | true |
| type_write_read | 0.0583 | 0.000000 | RW | "" |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*0.000000 + 0.2594*1.000000 + 0.0583*0.000000 + 0.2097*0.000000 + 0.0750*0.000000 + 0.0583*0.000000)/0.9999=0.318000/0.9999=\mathbf{0.318032}\)

Truth bit field 4: MISSING truth bit field

Locations: truth registers[3].field_parts[0].bit_field[3] (missing) / v12 registers[7].field_parts[0].bit_field[3].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description, bit_start, bit_end, bit_width, values, is_reserved, type_write_read.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | MISSING | TMP_PRC[3:0] |
| field_description | 0.0586 | 0.000000 | MISSING | Temperature oversampling (precision): 0000 - single. (Default) - Measurement time 3.6 ms, 0001 - 2 times, 0010 - 4 times, 0011 - 8 times, 0100 - 16 times, 0101 - 32 times, 0110 - 64 times, 0111 - 128 times. 1xxx - Reserved. |
| bit_start | 0.2594 | 0.000000 | MISSING | 0 |
| bit_end | 0.2594 | 0.000000 | MISSING | 3 |
| bit_width | 0.0583 | 0.000000 | MISSING | 4 |
| values | 0.2097 | 0.000000 | MISSING | [{"value":"0000","value_description":"Single (Default). Measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"}] |
| is_reserved | 0.0750 | 0.000000 | MISSING | false |
| type_write_read | 0.0583 | 0.000000 | MISSING | RW |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*0.000000 + 0.2097*0.000000 + 0.0750*0.000000 + 0.0583*0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 0.318032, 0.000000) = **0.579508**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | TMP_CFG | TMP_CFG |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Temperature measurement configuration. | Temperature measurement configuration |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | RW | RW |
| bit_field | 0.3129 | 0.579508 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.579508)/1.0000=0.868428/1.0000=\mathbf{0.868428}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.868428) = **0.868428**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | TMP_CFG | TMP_CFG |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":""}] | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.000000 | Configures temperature measurement rate and resolution. | Configuration of temperature measurement rate (TMP_RATE) and resolution (TMP_PRC). |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | RW | RW |
| field_parts | 0.2987 | 0.868428 | truth field-part set | mean(0.868428) |
| default_value | 0.0667 | 1.000000 | 00H | 0x00 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.868428 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.960799/1.0001=\mathbf{0.960703}\)

## Extracted logical register 9: MEAS_CFG

v12 registers[8]; truth association: truth registers[4] (MEAS_CFG).
Associated physical locations: 0x08 (8).

### Bottom layer: bit fields, then field parts

#### Field part 1: MEAS_CFG at 0x08 (8)

Locations: truth registers[4].field_parts[0] / v12 registers[8].field_parts[0].

Truth bit field 1: COEF_RDY bits 7:7

Locations: truth registers[4].field_parts[0].bit_field[0] / v12 registers[8].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | COEF_RDY | COEF_RDY |
| field_description | 0.0586 | 1.000000 | Indicates whether coefficients have been loaded into the coefficient registers after start-up. | Coefficients will be read to the Coefficients Registers after start-up: 0 - Coefficients are not available yet. 1 - Coefficients are available. |
| bit_start | 0.2594 | 1.000000 | 7 | 7 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Coefficients are not available yet"},{"value":"1","value_description":"Coefficients are available"}] | [{"value":"0","value_description":"Coefficients are not available yet"},{"value":"1","value_description":"Coefficients are available"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: SENSOR_RDY bits 6:6

Locations: truth registers[4].field_parts[0].bit_field[1] / v12 registers[8].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | SENSOR_RDY | SENSOR_RDY |
| field_description | 0.0586 | 1.000000 | Indicates completion of pressure sensor self-initialization after start-up. | The pressure sensor is running through self initialization after start-up: 0 - Sensor initialization not complete, 1 - Sensor initialization complete. It is recommend not to start measurements until the sensor has completed the self initialization. |
| bit_start | 0.2594 | 1.000000 | 6 | 6 |
| bit_end | 0.2594 | 1.000000 | 6 | 6 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Sensor initialization not complete"},{"value":"1","value_description":"Sensor initialization complete"}] | [{"value":"0","value_description":"Sensor initialization not complete"},{"value":"1","value_description":"Sensor initialization complete"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: TMP_RDY bits 5:5

Locations: truth registers[4].field_parts[0].bit_field[2] / v12 registers[8].field_parts[0].bit_field[2].
Judgment: incorrect/missing scored fields: values.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP_RDY | TMP_RDY |
| field_description | 0.0586 | 1.000000 | Temperature measurement ready status; cleared when the temperature measurement is read. | Temperature measurement ready: 1 - New temperature measurement is ready. Cleared when temperature measurement is read. |
| bit_start | 0.2594 | 1.000000 | 5 | 5 |
| bit_end | 0.2594 | 1.000000 | 5 | 5 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 0.000000 | [{"value":"1","value_description":"New temperature measurement is ready"}] | [{"value":"0","value_description":"No new temperature measurement"},{"value":"1","value_description":"New temperature measurement is ready"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*0.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.790200/0.9999=\mathbf{0.790279}\)

Truth bit field 4: PRS_RDY bits 4:4

Locations: truth registers[4].field_parts[0].bit_field[3] / v12 registers[8].field_parts[0].bit_field[3].
Judgment: incorrect/missing scored fields: values.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | PRS_RDY | PRS_RDY |
| field_description | 0.0586 | 1.000000 | Pressure measurement ready status; cleared when the pressure measurement is read. | Pressure measurement ready: 1 - New pressure measurement is ready. Cleared when pressure measurement is read. |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 4 | 4 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 0.000000 | [{"value":"1","value_description":"New pressure measurement is ready"}] | [{"value":"0","value_description":"No new pressure measurement"},{"value":"1","value_description":"New pressure measurement is ready"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*0.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.790200/0.9999=\mathbf{0.790279}\)

Truth bit field 5: - bits 3:3

Locations: truth registers[4].field_parts[0].bit_field[4] / v12 registers[8].field_parts[0].bit_field[4].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | - | - |
| field_description | 0.0586 | 1.000000 | Reserved. | Reserved. |
| bit_start | 0.2594 | 1.000000 | 3 | 3 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | true | true |
| type_write_read | 0.0583 | 1.000000 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 6: MEAS_CTRL bits 0:2

Locations: truth registers[4].field_parts[0].bit_field[5] / v12 registers[8].field_parts[0].bit_field[5].
Judgment: incorrect/missing scored fields: name_or_parameter, values.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | MEAS_CTRL | MEAS_CTRL[2:0] |
| field_description | 0.0586 | 1.000000 | Sets the measurement mode and type. | Set measurement mode and type: Standby Mode (000 - Idle / Stop background measurement), Command Mode (001 - Pressure measurement, 010 - Temperature measurement), Background Mode (101 - Continuous pressure measurement, 110 - Continuous temperature measurement, 111 - Continuous pressure and temperature measurement). |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 2 | 2 |
| bit_width | 0.0583 | 1.000000 | 3 | 3 |
| values | 0.2097 | 0.000000 | [{"value":"000","value_description":"Standby: idle or stop background measurement"},{"value":"001","value_description":"Command mode: pressure measurement"},{"value":"010","value_description":"Command mode: temperature measurement"},{"value":"011","value_description":"Not available"},{"value":"100","value_description":"Not available"},{"value":"101","value_description":"Background mode: continuous pressure measurement"},{"value":"110","value_description":"Background mode: continuous temperature measurement"},{"value":"111","value_description":"Background mode: continuous pressure and temperature measurement"}] | [{"value":"000","value_description":"Idle / Stop background measurement"},{"value":"001","value_description":"Pressure measurement"},{"value":"010","value_description":"Temperature measurement"},{"value":"101","value_description":"Continuous pressure measurement"},{"value":"110","value_description":"Continuous temperature measurement"},{"value":"111","value_description":"Continuous pressure and temperature measurement"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*0.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.769000/0.9999=\mathbf{0.769077}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 0.790279, 0.790279, 1.000000, 0.769077) = **0.891606**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | MEAS_CFG | MEAS_CFG |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x08","decimal":"8","bank":"","page":"","description":""} | {"hex":"0x08","decimal":"8","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Measurement configuration and readiness status. | Measurement configuration |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | RW | RW |
| bit_field | 0.3129 | 0.891606 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.891606)/1.0000=0.966083/1.0000=\mathbf{0.966083}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.966083) = **0.966083**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | MEAS_CFG | MEAS_CFG |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":""}] | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.000000 | Sets the measurement operating mode and reports sensor, coefficient, pressure, and temperature readiness. | Setup measurement mode. Contains status flags and control bits for measurement operations. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | RW | RW |
| field_parts | 0.2987 | 0.966083 | truth field-part set | mean(0.966083) |
| default_value | 0.0667 | 1.000000 | C0H | 0xC0 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.966083 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.989969/1.0001=\mathbf{0.989870}\)

## Extracted logical register 10: CFG_REG

v12 registers[9]; truth association: truth registers[5] (CFG_REG).
Associated physical locations: 0x09 (9).

### Bottom layer: bit fields, then field parts

#### Field part 1: CFG_REG at 0x09 (9)

Locations: truth registers[5].field_parts[0] / v12 registers[9].field_parts[0].

Truth bit field 1: INT_HL bits 7:7

Locations: truth registers[5].field_parts[0].bit_field[0] / v12 registers[9].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | INT_HL | INT_HL |
| field_description | 0.0586 | 1.000000 | Interrupt active level on the SDO pin. | Interrupt (on SDO pin) active level: 0 - Active low, 1 - Active high. |
| bit_start | 0.2594 | 1.000000 | 7 | 7 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Active low"},{"value":"1","value_description":"Active high"}] | [{"value":"0","value_description":"Active low"},{"value":"1","value_description":"Active high"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: INT_FIFO bits 6:6

Locations: truth registers[5].field_parts[0].bit_field[1] / v12 registers[9].field_parts[0].bit_field[1].
Judgment: incorrect/missing scored fields: name_or_parameter, bit_start, bit_width, values.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | INT_FIFO | INT_SEL[2:0] |
| field_description | 0.0586 | 1.000000 | Controls interrupt generation when the FIFO is full. | Interrupt selection bits (not explicitly described in provided tables, inferred from register map table). |
| bit_start | 0.2594 | 0.000000 | 6 | 4 |
| bit_end | 0.2594 | 1.000000 | 6 | 6 |
| bit_width | 0.0583 | 0.000000 | 1 | 3 |
| values | 0.2097 | 0.000000 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*0.000000 + 0.2594*1.000000 + 0.0583*0.000000 + 0.2097*0.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.451300/0.9999=\mathbf{0.451345}\)

Truth bit field 3: INT_TMP bits 5:5

Locations: truth registers[5].field_parts[0].bit_field[2] / v12 registers[9].field_parts[0].bit_field[2].
Judgment: incorrect/missing scored fields: name_or_parameter, bit_start, bit_end.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | INT_TMP | TMP_SHIFT_EN |
| field_description | 0.0586 | 1.000000 | Controls interrupt generation when a temperature measurement is ready. | Temperature result bit-shift: 0 - no shift, 1 - shift result right in data register. Note: Must be set to '1' when the oversampling rate is >8 times. |
| bit_start | 0.2594 | 0.000000 | 5 | 3 |
| bit_end | 0.2594 | 0.000000 | 5 | 3 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"No shift"},{"value":"1","value_description":"Shift result right in data register"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.459900/0.9999=\mathbf{0.459946}\)

Truth bit field 4: INT_PRS bits 4:4

Locations: truth registers[5].field_parts[0].bit_field[3] / v12 registers[9].field_parts[0].bit_field[3].
Judgment: incorrect/missing scored fields: name_or_parameter, bit_start, bit_end.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | INT_PRS | PRS_SHIFT_EN |
| field_description | 0.0586 | 1.000000 | Controls interrupt generation when a pressure measurement is ready. | Pressure result bit-shift: 0 - no shift, 1 - shift result right in data register. Note: Must be set to '1' when the oversampling rate is >8 times. |
| bit_start | 0.2594 | 0.000000 | 4 | 2 |
| bit_end | 0.2594 | 0.000000 | 4 | 2 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"No shift"},{"value":"1","value_description":"Shift result right in data register"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.459900/0.9999=\mathbf{0.459946}\)

Truth bit field 5: T_SHIFT bits 3:3

Locations: truth registers[5].field_parts[0].bit_field[4] / v12 registers[9].field_parts[0].bit_field[4].
Judgment: incorrect/missing scored fields: name_or_parameter, bit_start, bit_end.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | T_SHIFT | FIFO_EN |
| field_description | 0.0586 | 1.000000 | Temperature result bit shift; must be enabled when oversampling is greater than 8 times. | Enable the FIFO: 0 - Disable, 1 - Enable. |
| bit_start | 0.2594 | 0.000000 | 3 | 1 |
| bit_end | 0.2594 | 0.000000 | 3 | 1 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"No shift"},{"value":"1","value_description":"Shift result right in data register"}] | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.459900/0.9999=\mathbf{0.459946}\)

Truth bit field 6: P_SHIFT bits 2:2

Locations: truth registers[5].field_parts[0].bit_field[5] / v12 registers[9].field_parts[0].bit_field[5].
Judgment: incorrect/missing scored fields: name_or_parameter, bit_start, bit_end.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | P_SHIFT | SPI_MODE |
| field_description | 0.0586 | 1.000000 | Pressure result bit shift; must be enabled when oversampling is greater than 8 times. | Set SPI mode: 0 - 4-wire interface, 1 - 3-wire interface. |
| bit_start | 0.2594 | 0.000000 | 2 | 0 |
| bit_end | 0.2594 | 0.000000 | 2 | 0 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"No shift"},{"value":"1","value_description":"Shift result right in data register"}] | [{"value":"0","value_description":"4-wire interface"},{"value":"1","value_description":"3-wire interface"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | RW | RW |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.459900/0.9999=\mathbf{0.459946}\)

Truth bit field 7: FIFO_EN bits 1:1

Locations: truth registers[5].field_parts[0].bit_field[6] / v12 registers[9].field_parts[0].bit_field[6] (missing).
Judgment: incorrect/missing scored fields: name_or_parameter, field_description, bit_start, bit_end, bit_width, values, is_reserved, type_write_read.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | FIFO_EN | MISSING |
| field_description | 0.0586 | 0.000000 | Enables the FIFO. | MISSING |
| bit_start | 0.2594 | 0.000000 | 1 | MISSING |
| bit_end | 0.2594 | 0.000000 | 1 | MISSING |
| bit_width | 0.0583 | 0.000000 | 1 | MISSING |
| values | 0.2097 | 0.000000 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | MISSING |
| is_reserved | 0.0750 | 0.000000 | false | MISSING |
| type_write_read | 0.0583 | 0.000000 | RW | MISSING |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*0.000000 + 0.2097*0.000000 + 0.0750*0.000000 + 0.0583*0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Truth bit field 8: SPI_MODE bits 0:0

Locations: truth registers[5].field_parts[0].bit_field[7] / v12 registers[9].field_parts[0].bit_field[7] (missing).
Judgment: incorrect/missing scored fields: name_or_parameter, field_description, bit_start, bit_end, bit_width, values, is_reserved, type_write_read.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | SPI_MODE | MISSING |
| field_description | 0.0586 | 0.000000 | Selects the SPI interface mode. | MISSING |
| bit_start | 0.2594 | 0.000000 | 0 | MISSING |
| bit_end | 0.2594 | 0.000000 | 0 | MISSING |
| bit_width | 0.0583 | 0.000000 | 1 | MISSING |
| values | 0.2097 | 0.000000 | [{"value":"0","value_description":"4-wire interface"},{"value":"1","value_description":"3-wire interface"}] | MISSING |
| is_reserved | 0.0750 | 0.000000 | false | MISSING |
| type_write_read | 0.0583 | 0.000000 | RW | MISSING |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*0.000000 + 0.2097*0.000000 + 0.0750*0.000000 + 0.0583*0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 0.451345, 0.459946, 0.459946, 0.459946, 0.459946, 0.000000, 0.000000) = **0.411391**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | CFG_REG | CFG_REG |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x09","decimal":"9","bank":"","page":"","description":""} | {"hex":"0x09","decimal":"9","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Interrupt, result-shift, FIFO, and SPI configuration. | Configuration register |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | RW | RW |
| bit_field | 0.3129 | 0.411391 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.411391)/1.0000=0.815824/1.0000=\mathbf{0.815824}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.815824) = **0.815824**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | CFG_REG | CFG_REG |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x09","decimal":"9","bank":"","page":"","description":""}] | [{"hex":"0x09","decimal":"9","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.000000 | Configures interrupts, measurement data shifts, FIFO enable, and SPI interface mode. | Configuration of interrupts, measurement data shift, and FIFO enable. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | RW | RW |
| field_parts | 0.2987 | 0.815824 | truth field-part set | mean(0.815824) |
| default_value | 0.0667 | 1.000000 | 00H | 0x00 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.815824 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.945087/1.0001=\mathbf{0.944992}\)

## Extracted logical register 11: INT_STS

v12 registers[10]; truth association: truth registers[6] (INT_STS).
Associated physical locations: 0x0A (10).

### Bottom layer: bit fields, then field parts

#### Field part 1: INT_STS at 0x0A (10)

Locations: truth registers[6].field_parts[0] / v12 registers[10].field_parts[0].

Truth bit field 1: - bits 3:7

Locations: truth registers[6].field_parts[0].bit_field[0] / v12 registers[10].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | - | - |
| field_description | 0.0586 | 1.000000 | Reserved. | Reserved. |
| bit_start | 0.2594 | 1.000000 | 3 | 3 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 5 | 5 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | true | true |
| type_write_read | 0.0583 | 1.000000 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: INT_FIFO_FULL bits 2:2

Locations: truth registers[6].field_parts[0].bit_field[1] / v12 registers[10].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | INT_FIFO_FULL | INT_FIFO_FULL |
| field_description | 0.0586 | 1.000000 | FIFO interrupt status. | Status of FIFO interrupt: 0 - Interrupt not active, 1 - Interrupt active. |
| bit_start | 0.2594 | 1.000000 | 2 | 2 |
| bit_end | 0.2594 | 1.000000 | 2 | 2 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: INT_TMP bits 1:1

Locations: truth registers[6].field_parts[0].bit_field[2] / v12 registers[10].field_parts[0].bit_field[2].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | INT_TMP | INT_TMP |
| field_description | 0.0586 | 1.000000 | Temperature measurement interrupt status. | Status of temperature measurement interrupt: 0 - Interrupt not active, 1 - Interrupt active. |
| bit_start | 0.2594 | 1.000000 | 1 | 1 |
| bit_end | 0.2594 | 1.000000 | 1 | 1 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 4: INT_PRS bits 0:0

Locations: truth registers[6].field_parts[0].bit_field[3] / v12 registers[10].field_parts[0].bit_field[3].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | INT_PRS | INT_PRS |
| field_description | 0.0586 | 1.000000 | Pressure measurement interrupt status. | Status of pressure measurement interrupt: 0 - Interrupt not active, 1 - Interrupt active. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 0 | 0 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | INT_STS | INT_STS |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":""} | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Interrupt status. | Interrupt status |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | INT_STS | INT_STS |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":""}] | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.000000 | Reports FIFO, temperature measurement, and pressure measurement interrupt status; cleared on read. | Interrupt status register. The register is cleared on read. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 00H | 0x00 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 12: FIFO_STS

v12 registers[11]; truth association: truth registers[7] (FIFO_STS).
Associated physical locations: 0x0B (11).

### Bottom layer: bit fields, then field parts

#### Field part 1: FIFO_STS at 0x0B (11)

Locations: truth registers[7].field_parts[0] / v12 registers[11].field_parts[0].

Truth bit field 1: - bits 2:7

Locations: truth registers[7].field_parts[0].bit_field[0] / v12 registers[11].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | - | - |
| field_description | 0.0586 | 1.000000 | Reserved. | Reserved. |
| bit_start | 0.2594 | 1.000000 | 2 | 2 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 6 | 6 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | true | true |
| type_write_read | 0.0583 | 1.000000 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: FIFO_FULL bits 1:1

Locations: truth registers[7].field_parts[0].bit_field[1] / v12 registers[11].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | FIFO_FULL | FIFO_FULL |
| field_description | 0.0586 | 1.000000 | FIFO full status. | 0 - The FIFO is not full, 1 - The FIFO is full. |
| bit_start | 0.2594 | 1.000000 | 1 | 1 |
| bit_end | 0.2594 | 1.000000 | 1 | 1 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"FIFO is not full"},{"value":"1","value_description":"FIFO is full"}] | [{"value":"0","value_description":"The FIFO is not full"},{"value":"1","value_description":"The FIFO is full"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: FIFO_EMPTY bits 0:0

Locations: truth registers[7].field_parts[0].bit_field[2] / v12 registers[11].field_parts[0].bit_field[2].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | FIFO_EMPTY | FIFO_EMPTY |
| field_description | 0.0586 | 1.000000 | FIFO empty status. | 0 - The FIFO is not empty, 1 - The FIFO is empty. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 0 | 0 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"FIFO is not empty"},{"value":"1","value_description":"FIFO is empty"}] | [{"value":"0","value_description":"The FIFO is not empty"},{"value":"1","value_description":"The FIFO is empty"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | FIFO_STS | FIFO_STS |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":""} | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | FIFO status. | FIFO status register |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | FIFO_STS | FIFO_STS |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x0B","decimal":"11","bank":"","page":"","description":""}] | [{"hex":"0x0B","decimal":"11","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.000000 | Reports whether the FIFO is full or empty. | FIFO status register. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | truth field-part set | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 00H | 0x00 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\)

## Extracted logical register 13: RESET

v12 registers[12]; truth association: truth registers[8] (RESET).
Associated physical locations: 0x0C (12).

### Bottom layer: bit fields, then field parts

#### Field part 1: RESET at 0x0C (12)

Locations: truth registers[8].field_parts[0] / v12 registers[12].field_parts[0].

Truth bit field 1: FIFO_FLUSH bits 7:7

Locations: truth registers[8].field_parts[0].bit_field[0] / v12 registers[12].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | FIFO_FLUSH | FIFO_FLUSH |
| field_description | 0.0586 | 1.000000 | Flushes the FIFO; after reading all FIFO data, write 1 to clear old data. | FIFO flush: 1 - Empty FIFO. After reading out all data from the FIFO, write '1' to clear all old data. |
| bit_start | 0.2594 | 1.000000 | 7 | 7 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"1","value_description":"Empty FIFO"}] | [{"value":"1","value_description":"Empty FIFO"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | W | W |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: - bits 4:6

Locations: truth registers[8].field_parts[0].bit_field[1] / v12 registers[12].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | - | - |
| field_description | 0.0586 | 1.000000 | Reserved. | Reserved. |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 6 | 6 |
| bit_width | 0.0583 | 1.000000 | 3 | 3 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | true | true |
| type_write_read | 0.0583 | 1.000000 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: SOFT_RST bits 0:3

Locations: truth registers[8].field_parts[0].bit_field[2] / v12 registers[12].field_parts[0].bit_field[2].
Judgment: incorrect/missing scored fields: name_or_parameter.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | SOFT_RST | SOFT_RST[3:0] |
| field_description | 0.0586 | 1.000000 | Generates a soft reset using the same sequence as power-on reset. | Write '1001' to generate a soft reset. A soft reset will run through the same sequences as in power-on reset. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [{"value":"1001","value_description":"Generate a soft reset"}] | [{"value":"1001","value_description":"Generate a soft reset"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | W | W |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 0.978798) = **0.992933**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | RESET | RESET |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":""} | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | FIFO flush and soft reset control. | FIFO flush and soft reset |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | W | W |
| bit_field | 0.3129 | 0.992933 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.992933)/1.0000=0.997789/1.0000=\mathbf{0.997789}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.997789) = **0.997789**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | RESET | RESET |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":""}] | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.000000 | Flushes the FIFO or generates a soft reset. | Flush FIFO or generate soft reset. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | W | W |
| field_parts | 0.2987 | 0.997789 | truth field-part set | mean(0.997789) |
| default_value | 0.0667 | 1.000000 | 00H | 0x00 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.997789 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.999439/1.0001=\mathbf{0.999340}\)

## Extracted logical register 14: Product ID

v12 registers[13]; truth association: truth registers[9] (Product and Revision ID (ID)).
Associated physical locations: 0x0D (13).

### Bottom layer: bit fields, then field parts

#### Field part 1: ID at 0x0D (13)

Locations: truth registers[9].field_parts[0] / v12 registers[13].field_parts[0].

Truth bit field 1: REV_ID bits 4:7

Locations: truth registers[9].field_parts[0].bit_field[0] / v12 registers[13].field_parts[0].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | REV_ID | REV_ID[3:0] |
| field_description | 0.0586 | 1.000000 | Revision ID. | Revision ID. |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Truth bit field 2: PROD_ID bits 0:3

Locations: truth registers[9].field_parts[0].bit_field[1] / v12 registers[13].field_parts[0].bit_field[1].
Judgment: incorrect/missing scored fields: name_or_parameter.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | PROD_ID | PROD_ID[3:0] |
| field_description | 0.0586 | 1.000000 | Product ID. | Product ID. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(0.978798, 0.978798) = **0.978798**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | ID | Product ID |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":""} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Product and revision identification. | Product and revision ID |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.978798 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.978798)/1.0000=0.965366/1.0000=\mathbf{0.965366}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.965366) = **0.965366**.
Direct judgment: incorrect/missing direct fields: name.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 0.000000 | Product and Revision ID (ID) | Product ID |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":""}] | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.000000 | Contains the product and revision identifiers. | Product and Revision ID. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 0.965366 | truth field-part set | mean(0.965366) |
| default_value | 0.0667 | 1.000000 | 0x10 / 10H (0x10H in datasheet is typo) | 0x10 |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*0.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.965366 + 0.0667*1.000000 + 0.0334*1.000000)/1.0001=0.967255/1.0001=\mathbf{0.967158}\)

## Extracted logical register 15: COEF

v12 registers[14]; truth association: truth registers[10] (COEF).
Associated physical locations: 0x10 (16), 0x11 (17), 0x12 (18), 0x13 (19), 0x14 (20), 0x15 (21), 0x16 (22), 0x17 (23), 0x18 (24), 0x19 (25), 0x1A (26), 0x1B (27), 0x1C (28), 0x1D (29), 0x1E (30), 0x1F (31), 0x20 (32), 0x21 (33).
Accepted COEF merge: the one extracted COEF logical register is compared against all 18 truth COEF physical field parts.

### Bottom layer: bit fields, then field parts

#### Field part 1: c0 at 0x10 (16)

Locations: truth registers[10].field_parts[0] / v12 registers[14].field_parts[0].

Truth bit field 1: c0 [11:4] bits 0:7

Locations: truth registers[10].field_parts[0].bit_field[0] / v12 registers[14].field_parts[0].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c0 [11:4] | c0[11:4] |
| field_description | 0.0586 | 0.000000 | Bits 11:4 of coefficient c0. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c0 | COEF[0x10] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"c0 bits 11:4."} | {"hex":"0x10","decimal":"16","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c0. | c0 [11:4] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 2: c0/c1 at 0x11 (17)

Locations: truth registers[10].field_parts[1] / v12 registers[14].field_parts[1].

Truth bit field 1: c0 [3:0] bits 4:7

Locations: truth registers[10].field_parts[1].bit_field[0] / v12 registers[14].field_parts[1].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c0 [3:0] | c0[3:0] |
| field_description | 0.0586 | 0.000000 | Bits 3:0 of coefficient c0. | "" |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Truth bit field 2: c1 [11:8] bits 0:3

Locations: truth registers[10].field_parts[1].bit_field[1] / v12 registers[14].field_parts[1].bit_field[1].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c1 [11:8] | c1[11:8] |
| field_description | 0.0586 | 0.000000 | Bits 11:8 of coefficient c1. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192, 0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c0/c1 | COEF[0x11] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Contains c0 bits 3:0 and c1 bits 11:8."} | {"hex":"0x11","decimal":"17","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Lower four bits of c0 and upper four bits of c1. | c0 [3:0] and c1 [11:8] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 3: c1 at 0x12 (18)

Locations: truth registers[10].field_parts[2] / v12 registers[14].field_parts[2].

Truth bit field 1: c1[7:0] bits 0:7

Locations: truth registers[10].field_parts[2].bit_field[0] / v12 registers[14].field_parts[2].bit_field[0].
Judgment: incorrect/missing scored fields: field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | c1[7:0] | c1[7:0] |
| field_description | 0.0586 | 0.000000 | Bits 7:0 of coefficient c1. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.941300/0.9999=\mathbf{0.941394}\)

Field-part aggregation

bit_field correctness = mean(0.941394) = **0.941394**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c1 | COEF[0x12] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"c1 bits 7:0."} | {"hex":"0x12","decimal":"18","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c1. | c1 [7:0] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.941394 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.941394)/1.0000=0.953662/1.0000=\mathbf{0.953662}\)

#### Field part 4: c00 at 0x13 (19)

Locations: truth registers[10].field_parts[3] / v12 registers[14].field_parts[3].

Truth bit field 1: c00 [19:12] bits 0:7

Locations: truth registers[10].field_parts[3].bit_field[0] / v12 registers[14].field_parts[3].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c00 [19:12] | c00[19:12] |
| field_description | 0.0586 | 0.000000 | Bits 19:12 of coefficient c00. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c00 | COEF[0x13] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"c00 bits 19:12."} | {"hex":"0x13","decimal":"19","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c00. | c00 [19:12] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 5: c00 at 0x14 (20)

Locations: truth registers[10].field_parts[4] / v12 registers[14].field_parts[4].

Truth bit field 1: c00 [11:4] bits 0:7

Locations: truth registers[10].field_parts[4].bit_field[0] / v12 registers[14].field_parts[4].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c00 [11:4] | c00[11:4] |
| field_description | 0.0586 | 0.000000 | Bits 11:4 of coefficient c00. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c00 | COEF[0x14] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"c00 bits 11:4."} | {"hex":"0x14","decimal":"20","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Middle eight bits of coefficient c00. | c00 [11:4] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 6: c00/c10 at 0x15 (21)

Locations: truth registers[10].field_parts[5] / v12 registers[14].field_parts[5].

Truth bit field 1: c00 [3:0] bits 4:7

Locations: truth registers[10].field_parts[5].bit_field[0] / v12 registers[14].field_parts[5].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c00 [3:0] | c00[3:0] |
| field_description | 0.0586 | 0.000000 | Bits 3:0 of coefficient c00. | "" |
| bit_start | 0.2594 | 1.000000 | 4 | 4 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Truth bit field 2: c10 [19:16] bits 0:3

Locations: truth registers[10].field_parts[5].bit_field[1] / v12 registers[14].field_parts[5].bit_field[1].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c10 [19:16] | c10[19:16] |
| field_description | 0.0586 | 0.000000 | Bits 19:16 of coefficient c10. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 3 | 3 |
| bit_width | 0.0583 | 1.000000 | 4 | 4 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192, 0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c00/c10 | COEF[0x15] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Contains c00 bits 3:0 and c10 bits 19:16."} | {"hex":"0x15","decimal":"21","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Lower four bits of c00 and upper four bits of c10. | c00 [3:0] and c10 [19:16] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 7: c10 at 0x16 (22)

Locations: truth registers[10].field_parts[6] / v12 registers[14].field_parts[6].

Truth bit field 1: c10 [15:8] bits 0:7

Locations: truth registers[10].field_parts[6].bit_field[0] / v12 registers[14].field_parts[6].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c10 [15:8] | c10[15:8] |
| field_description | 0.0586 | 0.000000 | Bits 15:8 of coefficient c10. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c10 | COEF[0x16] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"c10 bits 15:8."} | {"hex":"0x16","decimal":"22","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Middle eight bits of coefficient c10. | c10 [15:8] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 8: c10 at 0x17 (23)

Locations: truth registers[10].field_parts[7] / v12 registers[14].field_parts[7].

Truth bit field 1: c10 [7:0] bits 0:7

Locations: truth registers[10].field_parts[7].bit_field[0] / v12 registers[14].field_parts[7].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c10 [7:0] | c10[7:0] |
| field_description | 0.0586 | 0.000000 | Bits 7:0 of coefficient c10. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c10 | COEF[0x17] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"c10 bits 7:0."} | {"hex":"0x17","decimal":"23","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c10. | c10 [7:0] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 9: c01 at 0x18 (24)

Locations: truth registers[10].field_parts[8] / v12 registers[14].field_parts[8].

Truth bit field 1: c01 [15:8] bits 0:7

Locations: truth registers[10].field_parts[8].bit_field[0] / v12 registers[14].field_parts[8].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c01 [15:8] | c01[15:8] |
| field_description | 0.0586 | 0.000000 | Bits 15:8 of coefficient c01. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c01 | COEF[0x18] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"c01 bits 15:8."} | {"hex":"0x18","decimal":"24","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c01. | c01 [15:8] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 10: c01 at 0x19 (25)

Locations: truth registers[10].field_parts[9] / v12 registers[14].field_parts[9].

Truth bit field 1: c01 [7:0] bits 0:7

Locations: truth registers[10].field_parts[9].bit_field[0] / v12 registers[14].field_parts[9].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c01 [7:0] | c01[7:0] |
| field_description | 0.0586 | 0.000000 | Bits 7:0 of coefficient c01. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c01 | COEF[0x19] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x19","decimal":"25","bank":"","page":"","description":"c01 bits 7:0."} | {"hex":"0x19","decimal":"25","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c01. | c01 [7:0] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 11: c11 at 0x1A (26)

Locations: truth registers[10].field_parts[10] / v12 registers[14].field_parts[10].

Truth bit field 1: c11 [15:8] bits 0:7

Locations: truth registers[10].field_parts[10].bit_field[0] / v12 registers[14].field_parts[10].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c11 [15:8] | c11[15:8] |
| field_description | 0.0586 | 0.000000 | Bits 15:8 of coefficient c11. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c11 | COEF[0x1A] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"c11 bits 15:8."} | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c11. | c11 [15:8] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 12: c11 at 0x1B (27)

Locations: truth registers[10].field_parts[11] / v12 registers[14].field_parts[11].

Truth bit field 1: c11 [7:0] bits 0:7

Locations: truth registers[10].field_parts[11].bit_field[0] / v12 registers[14].field_parts[11].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c11 [7:0] | c11[7:0] |
| field_description | 0.0586 | 0.000000 | Bits 7:0 of coefficient c11. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c11 | COEF[0x1B] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"c11 bits 7:0."} | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c11. | c11 [7:0] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 13: c20 at 0x1C (28)

Locations: truth registers[10].field_parts[12] / v12 registers[14].field_parts[12].

Truth bit field 1: c20 [15:8] bits 0:7

Locations: truth registers[10].field_parts[12].bit_field[0] / v12 registers[14].field_parts[12].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c20 [15:8] | c20[15:8] |
| field_description | 0.0586 | 0.000000 | Bits 15:8 of coefficient c20. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c20 | COEF[0x1C] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"c20 bits 15:8."} | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c20. | c20 [15:8] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 14: c20 at 0x1D (29)

Locations: truth registers[10].field_parts[13] / v12 registers[14].field_parts[13].

Truth bit field 1: c20 [7:0] bits 0:7

Locations: truth registers[10].field_parts[13].bit_field[0] / v12 registers[14].field_parts[13].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c20 [7:0] | c20[7:0] |
| field_description | 0.0586 | 0.000000 | Bits 7:0 of coefficient c20. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c20 | COEF[0x1D] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"c20 bits 7:0."} | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c20. | c20 [7:0] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 15: c21 at 0x1E (30)

Locations: truth registers[10].field_parts[14] / v12 registers[14].field_parts[14].

Truth bit field 1: c21 [15:8] bits 0:7

Locations: truth registers[10].field_parts[14].bit_field[0] / v12 registers[14].field_parts[14].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c21 [15:8] | c21[15:8] |
| field_description | 0.0586 | 0.000000 | Bits 15:8 of coefficient c21. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c21 | COEF[0x1E] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"c21 bits 15:8."} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c21. | c21 [15:8] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 16: c21 at 0x1F (31)

Locations: truth registers[10].field_parts[15] / v12 registers[14].field_parts[15].

Truth bit field 1: c21 [7:0] bits 0:7

Locations: truth registers[10].field_parts[15].bit_field[0] / v12 registers[14].field_parts[15].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c21 [7:0] | c21[7:0] |
| field_description | 0.0586 | 0.000000 | Bits 7:0 of coefficient c21. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c21 | COEF[0x1F] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"c21 bits 7:0."} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c21. | c21 [7:0] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 17: c30 at 0x20 (32)

Locations: truth registers[10].field_parts[16] / v12 registers[14].field_parts[16].

Truth bit field 1: c30 [15:8] bits 0:7

Locations: truth registers[10].field_parts[16].bit_field[0] / v12 registers[14].field_parts[16].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c30 [15:8] | c30[15:8] |
| field_description | 0.0586 | 0.000000 | Bits 15:8 of coefficient c30. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c30 | COEF[0x20] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"c30 bits 15:8."} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c30. | c30 [15:8] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

#### Field part 18: c30 at 0x21 (33)

Locations: truth registers[10].field_parts[17] / v12 registers[14].field_parts[17].

Truth bit field 1: c30 [7:0] bits 0:7

Locations: truth registers[10].field_parts[17].bit_field[0] / v12 registers[14].field_parts[17].bit_field[0].
Judgment: incorrect/missing scored fields: name_or_parameter, field_description.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.000000 | c30 [7:0] | c30[7:0] |
| field_description | 0.0586 | 0.000000 | Bits 7:0 of coefficient c30. | "" |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 8 | 8 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*0.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.920100/0.9999=\mathbf{0.920192}\)

Field-part aggregation

bit_field correctness = mean(0.920192) = **0.920192**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | c30 | COEF[0x21] |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"c30 bits 7:0."} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c30. | c30 [7:0] |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 0.920192 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.920192)/1.0000=0.947028/1.0000=\mathbf{0.947028}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.947028, 0.947028, 0.953662, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028) = **0.947397**.
Direct judgment: incorrect/missing direct fields: width_bits, default_value.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | COEF | COEF |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x10","decimal":"16","bank":"","page":"","description":"c0 bits 11:4."},{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Contains c0 bits 3:0 and c1 bits 11:8."},{"hex":"0x12","decimal":"18","bank":"","page":"","description":"c1 bits 7:0."},{"hex":"0x13","decimal":"19","bank":"","page":"","description":"c00 bits 19:12."},{"hex":"0x14","decimal":"20","bank":"","page":"","description":"c00 bits 11:4."},{"hex":"0x15","decimal":"21","bank":"","page":"","description":"Contains c00 bits 3:0 and c10 bits 19:16."},{"hex":"0x16","decimal":"22","bank":"","page":"","description":"c10 bits 15:8."},{"hex":"0x17","decimal":"23","bank":"","page":"","description":"c10 bits 7:0."},{"hex":"0x18","decimal":"24","bank":"","page":"","description":"c01 bits 15:8."},{"hex":"0x19","decimal":"25","bank":"","page":"","description":"c01 bits 7:0."},{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"c11 bits 15:8."},{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"c11 bits 7:0."},{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"c20 bits 15:8."},{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"c20 bits 7:0."},{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"c21 bits 15:8."},{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"c21 bits 7:0."},{"hex":"0x20","decimal":"32","bank":"","page":"","description":"c30 bits 15:8."},{"hex":"0x21","decimal":"33","bank":"","page":"","description":"c30 bits 7:0."}] | [{"hex":"0x10","decimal":"16","bank":"","page":"","description":""},{"hex":"0x11","decimal":"17","bank":"","page":"","description":""},{"hex":"0x12","decimal":"18","bank":"","page":"","description":""},{"hex":"0x13","decimal":"19","bank":"","page":"","description":""},{"hex":"0x14","decimal":"20","bank":"","page":"","description":""},{"hex":"0x15","decimal":"21","bank":"","page":"","description":""},{"hex":"0x16","decimal":"22","bank":"","page":"","description":""},{"hex":"0x17","decimal":"23","bank":"","page":"","description":""},{"hex":"0x18","decimal":"24","bank":"","page":"","description":""},{"hex":"0x19","decimal":"25","bank":"","page":"","description":""},{"hex":"0x1A","decimal":"26","bank":"","page":"","description":""},{"hex":"0x1B","decimal":"27","bank":"","page":"","description":""},{"hex":"0x1C","decimal":"28","bank":"","page":"","description":""},{"hex":"0x1D","decimal":"29","bank":"","page":"","description":""},{"hex":"0x1E","decimal":"30","bank":"","page":"","description":""},{"hex":"0x1F","decimal":"31","bank":"","page":"","description":""},{"hex":"0x20","decimal":"32","bank":"","page":"","description":""},{"hex":"0x21","decimal":"33","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.000000 | Contains 2's complement calibration coefficients used to calculate compensated pressure and temperature values. | The Calibration Coefficients register contains the 2's complement coefficients that are used to calculate the compensated pressure and temperature values. Note: Coefficient data spans multiple addresses and requires specific bit manipulation for decimal conversion as described in source. |
| width_bits | 0.0590 | 0.000000 | 144 | EMPTY |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 0.947397 | truth field-part set | mean(0.947028, 0.947028, 0.953662, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028, 0.947028) |
| default_value | 0.0667 | 0.000000 | XXh | "" |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*0.000000 + 0.0590*1.000000 + 0.2987*0.947397 + 0.0667*0.000000 + 0.0334*1.000000)/1.0001=0.858687/1.0001=\mathbf{0.858602}\)

## Extracted logical register 16: COEF_SRCE

v12 registers[15]; truth association: truth registers[11] (Coefficient Source).
Associated physical locations: 0x28 (40).

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_COEF_SRCE at 0x28 (40)

Locations: truth registers[11].field_parts[0] / v12 registers[15].field_parts[0].

Truth bit field 1: TMP_COEF_SRCE bits 7:7

Locations: truth registers[11].field_parts[0].bit_field[0] / v12 registers[15].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | TMP_COEF_SRCE | TMP_COEF_SRCE |
| field_description | 0.0586 | 1.000000 | Identifies the temperature sensor on which the calibration coefficients are based. | Temperature coefficients are based on: 0 - Internal temperature sensor (of ASIC), 1 - External temperature sensor (of pressure sensor MEMS element). |
| bit_start | 0.2594 | 1.000000 | 7 | 7 |
| bit_end | 0.2594 | 1.000000 | 7 | 7 |
| bit_width | 0.0583 | 1.000000 | 1 | 1 |
| values | 0.2097 | 1.000000 | [{"value":"0","value_description":"Internal temperature sensor of ASIC"},{"value":"1","value_description":"External temperature sensor of pressure sensor MEMS element"}] | [{"value":"0","value_description":"Internal temperature sensor (of ASIC)"},{"value":"1","value_description":"External temperature sensor (of pressure sensor MEMS element)"}] |
| is_reserved | 0.0750 | 1.000000 | false | false |
| type_write_read | 0.0583 | 1.000000 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: - bits 0:6

Locations: truth registers[11].field_parts[0].bit_field[1] / v12 registers[15].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.000000 | - | - |
| field_description | 0.0586 | 1.000000 | Reserved. | Reserved. |
| bit_start | 0.2594 | 1.000000 | 0 | 0 |
| bit_end | 0.2594 | 1.000000 | 6 | 6 |
| bit_width | 0.0583 | 1.000000 | 7 | 7 |
| values | 0.2097 | 1.000000 | [] | [] |
| is_reserved | 0.0750 | 1.000000 | true | true |
| type_write_read | 0.0583 | 1.000000 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.
Direct judgment: incorrect/missing direct fields: register_name.

| Field-part field | Weight | C | Truth content | v12 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | TMP_COEF_SRCE | COEF_SRCE |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":""} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":""} |
| description | 0.0693 | 1.000000 | Temperature coefficient source selection status. | Temperature Coefficients Source |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | v12 bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=0.972000/1.0000=\mathbf{0.972000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.972000) = **0.972000**.
Direct judgment: incorrect/missing direct fields: default_value.

| Logical-register field | Weight | C | Truth comparison target | v12 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | Coefficient Source | COEF_SRCE |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":""}] | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.000000 | States whether the calibration coefficients are based on the ASIC temperature sensor or the pressure-sensor MEMS temperature sensor. | States which internal temperature sensor the calibration coefficients are based on: the ASIC temperature sensor or the MEMS element temperature sensor. The coefficients are only valid for one sensor and it is highly recommended to use the same temperature sensor in the application. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 0.972000 | truth field-part set | mean(0.972000) |
| default_value | 0.0667 | 0.000000 | XXH | "" |
| default_value_description | 0.0334 | 1.000000 | "" | "" |

\(Q(L)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.972000 + 0.0667*0.000000 + 0.0334*1.000000)/1.0001=0.925036/1.0001=\mathbf{0.924944}\)

## 2. Physical-register aggregation and final score

| Truth physical location | Truth logical / field part | Associated extracted logical register(s) | q_R |
|---|---|---|---:|
| 0x00 (0) | Pressure Data (PRS_Bn) / PRS_B2 | v12 registers[0] (PSR_B2, Q=0.969139) | 0.969139 |
| 0x01 (1) | Pressure Data (PRS_Bn) / PRS_B1 | v12 registers[1] (PSR_B1, Q=0.969139) | 0.969139 |
| 0x02 (2) | Pressure Data (PRS_Bn) / PRS_B0 | v12 registers[2] (PSR_B0, Q=0.969139) | 0.969139 |
| 0x03 (3) | Temperature Data (TMP_Tn) / TMP_B2 | v12 registers[3] (TMP_B2, Q=1.000000) | 1.000000 |
| 0x04 (4) | Temperature Data (TMP_Tn) / TMP_B1 | v12 registers[4] (TMP_B1, Q=1.000000) | 1.000000 |
| 0x05 (5) | Temperature Data (TMP_Tn) / TMP_B0 | v12 registers[5] (TMP_B0, Q=1.000000) | 1.000000 |
| 0x06 (6) | PRS_CFG / PRS_CFG | v12 registers[6] (PRS_CFG, Q=0.993467) | 0.993467 |
| 0x07 (7) | TMP_CFG / TMP_CFG | v12 registers[7] (TMP_CFG, Q=0.960703) | 0.960703 |
| 0x08 (8) | MEAS_CFG / MEAS_CFG | v12 registers[8] (MEAS_CFG, Q=0.989870) | 0.989870 |
| 0x09 (9) | CFG_REG / CFG_REG | v12 registers[9] (CFG_REG, Q=0.944992) | 0.944992 |
| 0x0A (10) | INT_STS / INT_STS | v12 registers[10] (INT_STS, Q=1.000000) | 1.000000 |
| 0x0B (11) | FIFO_STS / FIFO_STS | v12 registers[11] (FIFO_STS, Q=1.000000) | 1.000000 |
| 0x0C (12) | RESET / RESET | v12 registers[12] (RESET, Q=0.999340) | 0.999340 |
| 0x0D (13) | Product and Revision ID (ID) / ID | v12 registers[13] (Product ID, Q=0.967158) | 0.967158 |
| 0x10 (16) | COEF / c0 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x11 (17) | COEF / c0/c1 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x12 (18) | COEF / c1 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x13 (19) | COEF / c00 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x14 (20) | COEF / c00 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x15 (21) | COEF / c00/c10 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x16 (22) | COEF / c10 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x17 (23) | COEF / c10 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x18 (24) | COEF / c01 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x19 (25) | COEF / c01 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x1A (26) | COEF / c11 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x1B (27) | COEF / c11 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x1C (28) | COEF / c20 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x1D (29) | COEF / c20 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x1E (30) | COEF / c21 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x1F (31) | COEF / c21 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x20 (32) | COEF / c30 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x21 (33) | COEF / c30 | v12 registers[14] (COEF, Q=0.858602) | 0.858602 |
| 0x28 (40) | Coefficient Source / TMP_COEF_SRCE | v12 registers[15] (COEF_SRCE, Q=0.924944) | 0.924944 |

- sum(q_R) = 30.142719945 across 33 truth physical registers.
- Matched physical registers m=33; extra extracted physical registers x=0; extra penalty m/(m+x) = **1.000000000**.
- Final score: S_final=(10/33 * 30.142719945) * (33/(33+0)) = **9.134157559 / 10**.

## 3. Detailed deduction inventory

The inventory below lists every direct scored field with C<1. Recursive bit_field and field_parts values are not additional deductions; their exact bottom-up consequences are shown in every logical-register calculation above.

| # | Exact location | Field | C | Truth content | Extracted content | Specific error |
|---:|---|---|---:|---|---|---|
| 1 | truth registers[0] / v12 registers[0] | name | 0.0 | PRS_B2 | PSR_B2 | objective name/parameter differs: truth=PRS_B2, extracted=PSR_B2 |
| 2 | truth registers[0].field_parts[0] / v12 registers[0].field_parts[0] | register_name | 0.0 | PRS_B2 | PSR_B2 | objective name/parameter differs: truth=PRS_B2, extracted=PSR_B2 |
| 3 | truth registers[0] / v12 registers[1] | name | 0.0 | PRS_B1 | PSR_B1 | objective name/parameter differs: truth=PRS_B1, extracted=PSR_B1 |
| 4 | truth registers[0].field_parts[1] / v12 registers[1].field_parts[0] | register_name | 0.0 | PRS_B1 | PSR_B1 | objective name/parameter differs: truth=PRS_B1, extracted=PSR_B1 |
| 5 | truth registers[0] / v12 registers[2] | name | 0.0 | PRS_B0 | PSR_B0 | objective name/parameter differs: truth=PRS_B0, extracted=PSR_B0 |
| 6 | truth registers[0].field_parts[2] / v12 registers[2].field_parts[0] | register_name | 0.0 | PRS_B0 | PSR_B0 | objective name/parameter differs: truth=PRS_B0, extracted=PSR_B0 |
| 7 | truth registers[2].field_parts[0].bit_field[2] / v12 registers[6].field_parts[0].bit_field[2] | values | 0.0 | [{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard)"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times (High Precision)"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] | [{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard). Note: Use in combination with a bit shift."},{"value":"0101","value_description":"32 times. Note: Use in combination with a bit shift."},{"value":"0110","value_description":"64 times (High Precision). Note: Use in combination with a bit shift."},{"value":"0111","value_description":"128 times. Note: Use in combination with a bit shift."}] | objective value-code set differs in count/order/content: truth=[{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard)"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times (High Precision)"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}], extracted=[{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard). Note: Use in combination with a bit shift."},{"value":"0101","value_description":"32 times. Note: Use in combination with a bit shift."},{"value":"0110","value_description":"64 times (High Precision). Note: Use in combination with a bit shift."},{"value":"0111","value_description":"128 times. Note: Use in combination with a bit shift."}] |
| 8 | truth registers[3].field_parts[0].bit_field[2] / v12 registers[7].field_parts[0].bit_field[2] | name_or_parameter | 0.0 | TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo) | - | objective name/parameter differs: truth=TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo), extracted=- |
| 9 | truth registers[3].field_parts[0].bit_field[2] / v12 registers[7].field_parts[0].bit_field[2] | bit_start | 0.0 | 0 | 3 | objective bit_start differs or is missing: truth=0, extracted=3 |
| 10 | truth registers[3].field_parts[0].bit_field[2] / v12 registers[7].field_parts[0].bit_field[2] | bit_width | 0.0 | 4 | 1 | objective bit_width differs or is missing: truth=4, extracted=1 |
| 11 | truth registers[3].field_parts[0].bit_field[2] / v12 registers[7].field_parts[0].bit_field[2] | values | 0.0 | [{"value":"0000","value_description":"Single (Default), measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] | [] | objective value-code set differs in count/order/content: truth=[{"value":"0000","value_description":"Single (Default), measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}], extracted=[] |
| 12 | truth registers[3].field_parts[0].bit_field[2] / v12 registers[7].field_parts[0].bit_field[2] | is_reserved | 0.0 | false | true | objective reserved classification differs: truth=false, extracted=true |
| 13 | truth registers[3].field_parts[0].bit_field[2] / v12 registers[7].field_parts[0].bit_field[2] | type_write_read | 0.0 | RW | "" | access type differs or is missing: truth=RW, extracted="" |
| 14 | truth registers[3].field_parts[0].bit_field[3] (missing) / v12 registers[7].field_parts[0].bit_field[3] | name_or_parameter | 0.0 | MISSING | TMP_PRC[3:0] | objective name/parameter is missing on one side: truth=MISSING, extracted=TMP_PRC[3:0] |
| 15 | truth registers[3].field_parts[0].bit_field[3] (missing) / v12 registers[7].field_parts[0].bit_field[3] | field_description | 0.0 | MISSING | Temperature oversampling (precision): 0000 - single. (Default) - Measurement time 3.6 ms, 0001 - 2 times, 0010 - 4 times, 0011 - 8 times, 0100 - 16 times, 0101 - 32 times, 0110 - 64 times, 0111 - 128 times. 1xxx - Reserved. | description is missing on one side: truth=MISSING, extracted=Temperature oversampling (precision): 0000 - single. (Default) - Measurement time 3.6 ms, 0001 - 2 times, 0010 - 4 times, 0011 - 8 times, 0100 - 16 times, 0101 - 32 times, 0110 - 64 times, 0111 - 128 times. 1xxx - Reserved. |
| 16 | truth registers[3].field_parts[0].bit_field[3] (missing) / v12 registers[7].field_parts[0].bit_field[3] | bit_start | 0.0 | MISSING | 0 | objective bit_start differs or is missing: truth=MISSING, extracted=0 |
| 17 | truth registers[3].field_parts[0].bit_field[3] (missing) / v12 registers[7].field_parts[0].bit_field[3] | bit_end | 0.0 | MISSING | 3 | objective bit_end differs or is missing: truth=MISSING, extracted=3 |
| 18 | truth registers[3].field_parts[0].bit_field[3] (missing) / v12 registers[7].field_parts[0].bit_field[3] | bit_width | 0.0 | MISSING | 4 | objective bit_width differs or is missing: truth=MISSING, extracted=4 |
| 19 | truth registers[3].field_parts[0].bit_field[3] (missing) / v12 registers[7].field_parts[0].bit_field[3] | values | 0.0 | MISSING | [{"value":"0000","value_description":"Single (Default). Measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"}] | objective value-code set differs in count/order/content: truth=MISSING, extracted=[{"value":"0000","value_description":"Single (Default). Measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"}] |
| 20 | truth registers[3].field_parts[0].bit_field[3] (missing) / v12 registers[7].field_parts[0].bit_field[3] | is_reserved | 0.0 | MISSING | false | objective reserved classification differs: truth=MISSING, extracted=false |
| 21 | truth registers[3].field_parts[0].bit_field[3] (missing) / v12 registers[7].field_parts[0].bit_field[3] | type_write_read | 0.0 | MISSING | RW | access type differs or is missing: truth=MISSING, extracted=RW |
| 22 | truth registers[4].field_parts[0].bit_field[2] / v12 registers[8].field_parts[0].bit_field[2] | values | 0.0 | [{"value":"1","value_description":"New temperature measurement is ready"}] | [{"value":"0","value_description":"No new temperature measurement"},{"value":"1","value_description":"New temperature measurement is ready"}] | objective value-code set differs in count/order/content: truth=[{"value":"1","value_description":"New temperature measurement is ready"}], extracted=[{"value":"0","value_description":"No new temperature measurement"},{"value":"1","value_description":"New temperature measurement is ready"}] |
| 23 | truth registers[4].field_parts[0].bit_field[3] / v12 registers[8].field_parts[0].bit_field[3] | values | 0.0 | [{"value":"1","value_description":"New pressure measurement is ready"}] | [{"value":"0","value_description":"No new pressure measurement"},{"value":"1","value_description":"New pressure measurement is ready"}] | objective value-code set differs in count/order/content: truth=[{"value":"1","value_description":"New pressure measurement is ready"}], extracted=[{"value":"0","value_description":"No new pressure measurement"},{"value":"1","value_description":"New pressure measurement is ready"}] |
| 24 | truth registers[4].field_parts[0].bit_field[5] / v12 registers[8].field_parts[0].bit_field[5] | name_or_parameter | 0.0 | MEAS_CTRL | MEAS_CTRL[2:0] | objective name/parameter differs: truth=MEAS_CTRL, extracted=MEAS_CTRL[2:0] |
| 25 | truth registers[4].field_parts[0].bit_field[5] / v12 registers[8].field_parts[0].bit_field[5] | values | 0.0 | [{"value":"000","value_description":"Standby: idle or stop background measurement"},{"value":"001","value_description":"Command mode: pressure measurement"},{"value":"010","value_description":"Command mode: temperature measurement"},{"value":"011","value_description":"Not available"},{"value":"100","value_description":"Not available"},{"value":"101","value_description":"Background mode: continuous pressure measurement"},{"value":"110","value_description":"Background mode: continuous temperature measurement"},{"value":"111","value_description":"Background mode: continuous pressure and temperature measurement"}] | [{"value":"000","value_description":"Idle / Stop background measurement"},{"value":"001","value_description":"Pressure measurement"},{"value":"010","value_description":"Temperature measurement"},{"value":"101","value_description":"Continuous pressure measurement"},{"value":"110","value_description":"Continuous temperature measurement"},{"value":"111","value_description":"Continuous pressure and temperature measurement"}] | objective value-code set differs in count/order/content: truth=[{"value":"000","value_description":"Standby: idle or stop background measurement"},{"value":"001","value_description":"Command mode: pressure measurement"},{"value":"010","value_description":"Command mode: temperature measurement"},{"value":"011","value_description":"Not available"},{"value":"100","value_description":"Not available"},{"value":"101","value_description":"Background mode: continuous pressure measurement"},{"value":"110","value_description":"Background mode: continuous temperature measurement"},{"value":"111","value_description":"Background mode: continuous pressure and temperature measurement"}], extracted=[{"value":"000","value_description":"Idle / Stop background measurement"},{"value":"001","value_description":"Pressure measurement"},{"value":"010","value_description":"Temperature measurement"},{"value":"101","value_description":"Continuous pressure measurement"},{"value":"110","value_description":"Continuous temperature measurement"},{"value":"111","value_description":"Continuous pressure and temperature measurement"}] |
| 26 | truth registers[5].field_parts[0].bit_field[1] / v12 registers[9].field_parts[0].bit_field[1] | name_or_parameter | 0.0 | INT_FIFO | INT_SEL[2:0] | objective name/parameter differs: truth=INT_FIFO, extracted=INT_SEL[2:0] |
| 27 | truth registers[5].field_parts[0].bit_field[1] / v12 registers[9].field_parts[0].bit_field[1] | bit_start | 0.0 | 6 | 4 | objective bit_start differs or is missing: truth=6, extracted=4 |
| 28 | truth registers[5].field_parts[0].bit_field[1] / v12 registers[9].field_parts[0].bit_field[1] | bit_width | 0.0 | 1 | 3 | objective bit_width differs or is missing: truth=1, extracted=3 |
| 29 | truth registers[5].field_parts[0].bit_field[1] / v12 registers[9].field_parts[0].bit_field[1] | values | 0.0 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [] | objective value-code set differs in count/order/content: truth=[{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}], extracted=[] |
| 30 | truth registers[5].field_parts[0].bit_field[2] / v12 registers[9].field_parts[0].bit_field[2] | name_or_parameter | 0.0 | INT_TMP | TMP_SHIFT_EN | objective name/parameter differs: truth=INT_TMP, extracted=TMP_SHIFT_EN |
| 31 | truth registers[5].field_parts[0].bit_field[2] / v12 registers[9].field_parts[0].bit_field[2] | bit_start | 0.0 | 5 | 3 | objective bit_start differs or is missing: truth=5, extracted=3 |
| 32 | truth registers[5].field_parts[0].bit_field[2] / v12 registers[9].field_parts[0].bit_field[2] | bit_end | 0.0 | 5 | 3 | objective bit_end differs or is missing: truth=5, extracted=3 |
| 33 | truth registers[5].field_parts[0].bit_field[3] / v12 registers[9].field_parts[0].bit_field[3] | name_or_parameter | 0.0 | INT_PRS | PRS_SHIFT_EN | objective name/parameter differs: truth=INT_PRS, extracted=PRS_SHIFT_EN |
| 34 | truth registers[5].field_parts[0].bit_field[3] / v12 registers[9].field_parts[0].bit_field[3] | bit_start | 0.0 | 4 | 2 | objective bit_start differs or is missing: truth=4, extracted=2 |
| 35 | truth registers[5].field_parts[0].bit_field[3] / v12 registers[9].field_parts[0].bit_field[3] | bit_end | 0.0 | 4 | 2 | objective bit_end differs or is missing: truth=4, extracted=2 |
| 36 | truth registers[5].field_parts[0].bit_field[4] / v12 registers[9].field_parts[0].bit_field[4] | name_or_parameter | 0.0 | T_SHIFT | FIFO_EN | objective name/parameter differs: truth=T_SHIFT, extracted=FIFO_EN |
| 37 | truth registers[5].field_parts[0].bit_field[4] / v12 registers[9].field_parts[0].bit_field[4] | bit_start | 0.0 | 3 | 1 | objective bit_start differs or is missing: truth=3, extracted=1 |
| 38 | truth registers[5].field_parts[0].bit_field[4] / v12 registers[9].field_parts[0].bit_field[4] | bit_end | 0.0 | 3 | 1 | objective bit_end differs or is missing: truth=3, extracted=1 |
| 39 | truth registers[5].field_parts[0].bit_field[5] / v12 registers[9].field_parts[0].bit_field[5] | name_or_parameter | 0.0 | P_SHIFT | SPI_MODE | objective name/parameter differs: truth=P_SHIFT, extracted=SPI_MODE |
| 40 | truth registers[5].field_parts[0].bit_field[5] / v12 registers[9].field_parts[0].bit_field[5] | bit_start | 0.0 | 2 | 0 | objective bit_start differs or is missing: truth=2, extracted=0 |
| 41 | truth registers[5].field_parts[0].bit_field[5] / v12 registers[9].field_parts[0].bit_field[5] | bit_end | 0.0 | 2 | 0 | objective bit_end differs or is missing: truth=2, extracted=0 |
| 42 | truth registers[5].field_parts[0].bit_field[6] / v12 registers[9].field_parts[0].bit_field[6] (missing) | name_or_parameter | 0.0 | FIFO_EN | MISSING | objective name/parameter is missing on one side: truth=FIFO_EN, extracted=MISSING |
| 43 | truth registers[5].field_parts[0].bit_field[6] / v12 registers[9].field_parts[0].bit_field[6] (missing) | field_description | 0.0 | Enables the FIFO. | MISSING | description is missing on one side: truth=Enables the FIFO., extracted=MISSING |
| 44 | truth registers[5].field_parts[0].bit_field[6] / v12 registers[9].field_parts[0].bit_field[6] (missing) | bit_start | 0.0 | 1 | MISSING | objective bit_start differs or is missing: truth=1, extracted=MISSING |
| 45 | truth registers[5].field_parts[0].bit_field[6] / v12 registers[9].field_parts[0].bit_field[6] (missing) | bit_end | 0.0 | 1 | MISSING | objective bit_end differs or is missing: truth=1, extracted=MISSING |
| 46 | truth registers[5].field_parts[0].bit_field[6] / v12 registers[9].field_parts[0].bit_field[6] (missing) | bit_width | 0.0 | 1 | MISSING | objective bit_width differs or is missing: truth=1, extracted=MISSING |
| 47 | truth registers[5].field_parts[0].bit_field[6] / v12 registers[9].field_parts[0].bit_field[6] (missing) | values | 0.0 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | MISSING | objective value-code set differs in count/order/content: truth=[{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}], extracted=MISSING |
| 48 | truth registers[5].field_parts[0].bit_field[6] / v12 registers[9].field_parts[0].bit_field[6] (missing) | is_reserved | 0.0 | false | MISSING | objective reserved classification differs: truth=false, extracted=MISSING |
| 49 | truth registers[5].field_parts[0].bit_field[6] / v12 registers[9].field_parts[0].bit_field[6] (missing) | type_write_read | 0.0 | RW | MISSING | access type differs or is missing: truth=RW, extracted=MISSING |
| 50 | truth registers[5].field_parts[0].bit_field[7] / v12 registers[9].field_parts[0].bit_field[7] (missing) | name_or_parameter | 0.0 | SPI_MODE | MISSING | objective name/parameter is missing on one side: truth=SPI_MODE, extracted=MISSING |
| 51 | truth registers[5].field_parts[0].bit_field[7] / v12 registers[9].field_parts[0].bit_field[7] (missing) | field_description | 0.0 | Selects the SPI interface mode. | MISSING | description is missing on one side: truth=Selects the SPI interface mode., extracted=MISSING |
| 52 | truth registers[5].field_parts[0].bit_field[7] / v12 registers[9].field_parts[0].bit_field[7] (missing) | bit_start | 0.0 | 0 | MISSING | objective bit_start differs or is missing: truth=0, extracted=MISSING |
| 53 | truth registers[5].field_parts[0].bit_field[7] / v12 registers[9].field_parts[0].bit_field[7] (missing) | bit_end | 0.0 | 0 | MISSING | objective bit_end differs or is missing: truth=0, extracted=MISSING |
| 54 | truth registers[5].field_parts[0].bit_field[7] / v12 registers[9].field_parts[0].bit_field[7] (missing) | bit_width | 0.0 | 1 | MISSING | objective bit_width differs or is missing: truth=1, extracted=MISSING |
| 55 | truth registers[5].field_parts[0].bit_field[7] / v12 registers[9].field_parts[0].bit_field[7] (missing) | values | 0.0 | [{"value":"0","value_description":"4-wire interface"},{"value":"1","value_description":"3-wire interface"}] | MISSING | objective value-code set differs in count/order/content: truth=[{"value":"0","value_description":"4-wire interface"},{"value":"1","value_description":"3-wire interface"}], extracted=MISSING |
| 56 | truth registers[5].field_parts[0].bit_field[7] / v12 registers[9].field_parts[0].bit_field[7] (missing) | is_reserved | 0.0 | false | MISSING | objective reserved classification differs: truth=false, extracted=MISSING |
| 57 | truth registers[5].field_parts[0].bit_field[7] / v12 registers[9].field_parts[0].bit_field[7] (missing) | type_write_read | 0.0 | RW | MISSING | access type differs or is missing: truth=RW, extracted=MISSING |
| 58 | truth registers[8].field_parts[0].bit_field[2] / v12 registers[12].field_parts[0].bit_field[2] | name_or_parameter | 0.0 | SOFT_RST | SOFT_RST[3:0] | objective name/parameter differs: truth=SOFT_RST, extracted=SOFT_RST[3:0] |
| 59 | truth registers[9] / v12 registers[13] | name | 0.0 | Product and Revision ID (ID) | Product ID | objective name/parameter differs: truth=Product and Revision ID (ID), extracted=Product ID |
| 60 | truth registers[9].field_parts[0] / v12 registers[13].field_parts[0] | register_name | 0.0 | ID | Product ID | objective name/parameter differs: truth=ID, extracted=Product ID |
| 61 | truth registers[9].field_parts[0].bit_field[0] / v12 registers[13].field_parts[0].bit_field[0] | name_or_parameter | 0.0 | REV_ID | REV_ID[3:0] | objective name/parameter differs: truth=REV_ID, extracted=REV_ID[3:0] |
| 62 | truth registers[9].field_parts[0].bit_field[1] / v12 registers[13].field_parts[0].bit_field[1] | name_or_parameter | 0.0 | PROD_ID | PROD_ID[3:0] | objective name/parameter differs: truth=PROD_ID, extracted=PROD_ID[3:0] |
| 63 | truth registers[10] / v12 registers[14] | width_bits | 0.0 | 144 | EMPTY | objective width_bits differs or is missing: truth=144, extracted=EMPTY |
| 64 | truth registers[10] / v12 registers[14] | default_value | 0.0 | XXh | "" | objective default/reset value differs or is missing: truth=XXh, extracted="" |
| 65 | truth registers[10].field_parts[0] / v12 registers[14].field_parts[0] | register_name | 0.0 | c0 | COEF[0x10] | objective name/parameter differs: truth=c0, extracted=COEF[0x10] |
| 66 | truth registers[10].field_parts[0].bit_field[0] / v12 registers[14].field_parts[0].bit_field[0] | name_or_parameter | 0.0 | c0 [11:4] | c0[11:4] | objective name/parameter differs: truth=c0 [11:4], extracted=c0[11:4] |
| 67 | truth registers[10].field_parts[0].bit_field[0] / v12 registers[14].field_parts[0].bit_field[0] | field_description | 0.0 | Bits 11:4 of coefficient c0. | "" | description is missing on one side: truth=Bits 11:4 of coefficient c0., extracted="" |
| 68 | truth registers[10].field_parts[1] / v12 registers[14].field_parts[1] | register_name | 0.0 | c0/c1 | COEF[0x11] | objective name/parameter differs: truth=c0/c1, extracted=COEF[0x11] |
| 69 | truth registers[10].field_parts[1].bit_field[0] / v12 registers[14].field_parts[1].bit_field[0] | name_or_parameter | 0.0 | c0 [3:0] | c0[3:0] | objective name/parameter differs: truth=c0 [3:0], extracted=c0[3:0] |
| 70 | truth registers[10].field_parts[1].bit_field[0] / v12 registers[14].field_parts[1].bit_field[0] | field_description | 0.0 | Bits 3:0 of coefficient c0. | "" | description is missing on one side: truth=Bits 3:0 of coefficient c0., extracted="" |
| 71 | truth registers[10].field_parts[1].bit_field[1] / v12 registers[14].field_parts[1].bit_field[1] | name_or_parameter | 0.0 | c1 [11:8] | c1[11:8] | objective name/parameter differs: truth=c1 [11:8], extracted=c1[11:8] |
| 72 | truth registers[10].field_parts[1].bit_field[1] / v12 registers[14].field_parts[1].bit_field[1] | field_description | 0.0 | Bits 11:8 of coefficient c1. | "" | description is missing on one side: truth=Bits 11:8 of coefficient c1., extracted="" |
| 73 | truth registers[10].field_parts[2] / v12 registers[14].field_parts[2] | register_name | 0.0 | c1 | COEF[0x12] | objective name/parameter differs: truth=c1, extracted=COEF[0x12] |
| 74 | truth registers[10].field_parts[2].bit_field[0] / v12 registers[14].field_parts[2].bit_field[0] | field_description | 0.0 | Bits 7:0 of coefficient c1. | "" | description is missing on one side: truth=Bits 7:0 of coefficient c1., extracted="" |
| 75 | truth registers[10].field_parts[3] / v12 registers[14].field_parts[3] | register_name | 0.0 | c00 | COEF[0x13] | objective name/parameter differs: truth=c00, extracted=COEF[0x13] |
| 76 | truth registers[10].field_parts[3].bit_field[0] / v12 registers[14].field_parts[3].bit_field[0] | name_or_parameter | 0.0 | c00 [19:12] | c00[19:12] | objective name/parameter differs: truth=c00 [19:12], extracted=c00[19:12] |
| 77 | truth registers[10].field_parts[3].bit_field[0] / v12 registers[14].field_parts[3].bit_field[0] | field_description | 0.0 | Bits 19:12 of coefficient c00. | "" | description is missing on one side: truth=Bits 19:12 of coefficient c00., extracted="" |
| 78 | truth registers[10].field_parts[4] / v12 registers[14].field_parts[4] | register_name | 0.0 | c00 | COEF[0x14] | objective name/parameter differs: truth=c00, extracted=COEF[0x14] |
| 79 | truth registers[10].field_parts[4].bit_field[0] / v12 registers[14].field_parts[4].bit_field[0] | name_or_parameter | 0.0 | c00 [11:4] | c00[11:4] | objective name/parameter differs: truth=c00 [11:4], extracted=c00[11:4] |
| 80 | truth registers[10].field_parts[4].bit_field[0] / v12 registers[14].field_parts[4].bit_field[0] | field_description | 0.0 | Bits 11:4 of coefficient c00. | "" | description is missing on one side: truth=Bits 11:4 of coefficient c00., extracted="" |
| 81 | truth registers[10].field_parts[5] / v12 registers[14].field_parts[5] | register_name | 0.0 | c00/c10 | COEF[0x15] | objective name/parameter differs: truth=c00/c10, extracted=COEF[0x15] |
| 82 | truth registers[10].field_parts[5].bit_field[0] / v12 registers[14].field_parts[5].bit_field[0] | name_or_parameter | 0.0 | c00 [3:0] | c00[3:0] | objective name/parameter differs: truth=c00 [3:0], extracted=c00[3:0] |
| 83 | truth registers[10].field_parts[5].bit_field[0] / v12 registers[14].field_parts[5].bit_field[0] | field_description | 0.0 | Bits 3:0 of coefficient c00. | "" | description is missing on one side: truth=Bits 3:0 of coefficient c00., extracted="" |
| 84 | truth registers[10].field_parts[5].bit_field[1] / v12 registers[14].field_parts[5].bit_field[1] | name_or_parameter | 0.0 | c10 [19:16] | c10[19:16] | objective name/parameter differs: truth=c10 [19:16], extracted=c10[19:16] |
| 85 | truth registers[10].field_parts[5].bit_field[1] / v12 registers[14].field_parts[5].bit_field[1] | field_description | 0.0 | Bits 19:16 of coefficient c10. | "" | description is missing on one side: truth=Bits 19:16 of coefficient c10., extracted="" |
| 86 | truth registers[10].field_parts[6] / v12 registers[14].field_parts[6] | register_name | 0.0 | c10 | COEF[0x16] | objective name/parameter differs: truth=c10, extracted=COEF[0x16] |
| 87 | truth registers[10].field_parts[6].bit_field[0] / v12 registers[14].field_parts[6].bit_field[0] | name_or_parameter | 0.0 | c10 [15:8] | c10[15:8] | objective name/parameter differs: truth=c10 [15:8], extracted=c10[15:8] |
| 88 | truth registers[10].field_parts[6].bit_field[0] / v12 registers[14].field_parts[6].bit_field[0] | field_description | 0.0 | Bits 15:8 of coefficient c10. | "" | description is missing on one side: truth=Bits 15:8 of coefficient c10., extracted="" |
| 89 | truth registers[10].field_parts[7] / v12 registers[14].field_parts[7] | register_name | 0.0 | c10 | COEF[0x17] | objective name/parameter differs: truth=c10, extracted=COEF[0x17] |
| 90 | truth registers[10].field_parts[7].bit_field[0] / v12 registers[14].field_parts[7].bit_field[0] | name_or_parameter | 0.0 | c10 [7:0] | c10[7:0] | objective name/parameter differs: truth=c10 [7:0], extracted=c10[7:0] |
| 91 | truth registers[10].field_parts[7].bit_field[0] / v12 registers[14].field_parts[7].bit_field[0] | field_description | 0.0 | Bits 7:0 of coefficient c10. | "" | description is missing on one side: truth=Bits 7:0 of coefficient c10., extracted="" |
| 92 | truth registers[10].field_parts[8] / v12 registers[14].field_parts[8] | register_name | 0.0 | c01 | COEF[0x18] | objective name/parameter differs: truth=c01, extracted=COEF[0x18] |
| 93 | truth registers[10].field_parts[8].bit_field[0] / v12 registers[14].field_parts[8].bit_field[0] | name_or_parameter | 0.0 | c01 [15:8] | c01[15:8] | objective name/parameter differs: truth=c01 [15:8], extracted=c01[15:8] |
| 94 | truth registers[10].field_parts[8].bit_field[0] / v12 registers[14].field_parts[8].bit_field[0] | field_description | 0.0 | Bits 15:8 of coefficient c01. | "" | description is missing on one side: truth=Bits 15:8 of coefficient c01., extracted="" |
| 95 | truth registers[10].field_parts[9] / v12 registers[14].field_parts[9] | register_name | 0.0 | c01 | COEF[0x19] | objective name/parameter differs: truth=c01, extracted=COEF[0x19] |
| 96 | truth registers[10].field_parts[9].bit_field[0] / v12 registers[14].field_parts[9].bit_field[0] | name_or_parameter | 0.0 | c01 [7:0] | c01[7:0] | objective name/parameter differs: truth=c01 [7:0], extracted=c01[7:0] |
| 97 | truth registers[10].field_parts[9].bit_field[0] / v12 registers[14].field_parts[9].bit_field[0] | field_description | 0.0 | Bits 7:0 of coefficient c01. | "" | description is missing on one side: truth=Bits 7:0 of coefficient c01., extracted="" |
| 98 | truth registers[10].field_parts[10] / v12 registers[14].field_parts[10] | register_name | 0.0 | c11 | COEF[0x1A] | objective name/parameter differs: truth=c11, extracted=COEF[0x1A] |
| 99 | truth registers[10].field_parts[10].bit_field[0] / v12 registers[14].field_parts[10].bit_field[0] | name_or_parameter | 0.0 | c11 [15:8] | c11[15:8] | objective name/parameter differs: truth=c11 [15:8], extracted=c11[15:8] |
| 100 | truth registers[10].field_parts[10].bit_field[0] / v12 registers[14].field_parts[10].bit_field[0] | field_description | 0.0 | Bits 15:8 of coefficient c11. | "" | description is missing on one side: truth=Bits 15:8 of coefficient c11., extracted="" |
| 101 | truth registers[10].field_parts[11] / v12 registers[14].field_parts[11] | register_name | 0.0 | c11 | COEF[0x1B] | objective name/parameter differs: truth=c11, extracted=COEF[0x1B] |
| 102 | truth registers[10].field_parts[11].bit_field[0] / v12 registers[14].field_parts[11].bit_field[0] | name_or_parameter | 0.0 | c11 [7:0] | c11[7:0] | objective name/parameter differs: truth=c11 [7:0], extracted=c11[7:0] |
| 103 | truth registers[10].field_parts[11].bit_field[0] / v12 registers[14].field_parts[11].bit_field[0] | field_description | 0.0 | Bits 7:0 of coefficient c11. | "" | description is missing on one side: truth=Bits 7:0 of coefficient c11., extracted="" |
| 104 | truth registers[10].field_parts[12] / v12 registers[14].field_parts[12] | register_name | 0.0 | c20 | COEF[0x1C] | objective name/parameter differs: truth=c20, extracted=COEF[0x1C] |
| 105 | truth registers[10].field_parts[12].bit_field[0] / v12 registers[14].field_parts[12].bit_field[0] | name_or_parameter | 0.0 | c20 [15:8] | c20[15:8] | objective name/parameter differs: truth=c20 [15:8], extracted=c20[15:8] |
| 106 | truth registers[10].field_parts[12].bit_field[0] / v12 registers[14].field_parts[12].bit_field[0] | field_description | 0.0 | Bits 15:8 of coefficient c20. | "" | description is missing on one side: truth=Bits 15:8 of coefficient c20., extracted="" |
| 107 | truth registers[10].field_parts[13] / v12 registers[14].field_parts[13] | register_name | 0.0 | c20 | COEF[0x1D] | objective name/parameter differs: truth=c20, extracted=COEF[0x1D] |
| 108 | truth registers[10].field_parts[13].bit_field[0] / v12 registers[14].field_parts[13].bit_field[0] | name_or_parameter | 0.0 | c20 [7:0] | c20[7:0] | objective name/parameter differs: truth=c20 [7:0], extracted=c20[7:0] |
| 109 | truth registers[10].field_parts[13].bit_field[0] / v12 registers[14].field_parts[13].bit_field[0] | field_description | 0.0 | Bits 7:0 of coefficient c20. | "" | description is missing on one side: truth=Bits 7:0 of coefficient c20., extracted="" |
| 110 | truth registers[10].field_parts[14] / v12 registers[14].field_parts[14] | register_name | 0.0 | c21 | COEF[0x1E] | objective name/parameter differs: truth=c21, extracted=COEF[0x1E] |
| 111 | truth registers[10].field_parts[14].bit_field[0] / v12 registers[14].field_parts[14].bit_field[0] | name_or_parameter | 0.0 | c21 [15:8] | c21[15:8] | objective name/parameter differs: truth=c21 [15:8], extracted=c21[15:8] |
| 112 | truth registers[10].field_parts[14].bit_field[0] / v12 registers[14].field_parts[14].bit_field[0] | field_description | 0.0 | Bits 15:8 of coefficient c21. | "" | description is missing on one side: truth=Bits 15:8 of coefficient c21., extracted="" |
| 113 | truth registers[10].field_parts[15] / v12 registers[14].field_parts[15] | register_name | 0.0 | c21 | COEF[0x1F] | objective name/parameter differs: truth=c21, extracted=COEF[0x1F] |
| 114 | truth registers[10].field_parts[15].bit_field[0] / v12 registers[14].field_parts[15].bit_field[0] | name_or_parameter | 0.0 | c21 [7:0] | c21[7:0] | objective name/parameter differs: truth=c21 [7:0], extracted=c21[7:0] |
| 115 | truth registers[10].field_parts[15].bit_field[0] / v12 registers[14].field_parts[15].bit_field[0] | field_description | 0.0 | Bits 7:0 of coefficient c21. | "" | description is missing on one side: truth=Bits 7:0 of coefficient c21., extracted="" |
| 116 | truth registers[10].field_parts[16] / v12 registers[14].field_parts[16] | register_name | 0.0 | c30 | COEF[0x20] | objective name/parameter differs: truth=c30, extracted=COEF[0x20] |
| 117 | truth registers[10].field_parts[16].bit_field[0] / v12 registers[14].field_parts[16].bit_field[0] | name_or_parameter | 0.0 | c30 [15:8] | c30[15:8] | objective name/parameter differs: truth=c30 [15:8], extracted=c30[15:8] |
| 118 | truth registers[10].field_parts[16].bit_field[0] / v12 registers[14].field_parts[16].bit_field[0] | field_description | 0.0 | Bits 15:8 of coefficient c30. | "" | description is missing on one side: truth=Bits 15:8 of coefficient c30., extracted="" |
| 119 | truth registers[10].field_parts[17] / v12 registers[14].field_parts[17] | register_name | 0.0 | c30 | COEF[0x21] | objective name/parameter differs: truth=c30, extracted=COEF[0x21] |
| 120 | truth registers[10].field_parts[17].bit_field[0] / v12 registers[14].field_parts[17].bit_field[0] | name_or_parameter | 0.0 | c30 [7:0] | c30[7:0] | objective name/parameter differs: truth=c30 [7:0], extracted=c30[7:0] |
| 121 | truth registers[10].field_parts[17].bit_field[0] / v12 registers[14].field_parts[17].bit_field[0] | field_description | 0.0 | Bits 7:0 of coefficient c30. | "" | description is missing on one side: truth=Bits 7:0 of coefficient c30., extracted="" |
| 122 | truth registers[11] / v12 registers[15] | default_value | 0.0 | XXH | "" | objective default/reset value differs or is missing: truth=XXH, extracted="" |
| 123 | truth registers[11].field_parts[0] / v12 registers[15].field_parts[0] | register_name | 0.0 | TMP_COEF_SRCE | COEF_SRCE | objective name/parameter differs: truth=TMP_COEF_SRCE, extracted=COEF_SRCE |

- Total direct C=0 inventory rows: 123. There are no C=0.5 rows under the applied description leniency.

### Missing and extra physical locations

- No truth physical location is missing.
- No extra extracted physical location.
- The v12 TMP_CFG field part contains one extra positional bit-field entry at v12 registers[7].field_parts[0].bit_field[3] and the v12 CFG_REG field part omits truth bit-field positions 6 and 7. These are scored as bit-field content differences inside matched physical registers; they do not change x because x counts extra physical registers.

## 4. Empty type_write_read audit

- Audited scored logical-register, field-part, and bit-field access-type comparisons: 110.
- Truth/extraction both empty: C=1.0 in 6 comparisons. These cases were explicitly credited and did not enter the deduction inventory.
- Truth empty but extraction concrete: 1 comparison(s); these are inventions and receive C=0.
- Truth concrete but extraction empty: 3 comparison(s); these are omissions and receive C=0.
- Both concrete: 100 comparisons; exact matches: 100; concrete mismatches: 0.
- COEF logical-register, field-part, and bit-field access types use R in both truth and v12 wherever the items correspond; the updated COEF truth access types therefore receive full credit.
- Credited empty/empty locations:
  - truth registers[2].field_parts[0].bit_field[0] / v12 registers[6].field_parts[0].bit_field[0] -> C=1.0.
  - truth registers[4].field_parts[0].bit_field[4] / v12 registers[8].field_parts[0].bit_field[4] -> C=1.0.
  - truth registers[6].field_parts[0].bit_field[0] / v12 registers[10].field_parts[0].bit_field[0] -> C=1.0.
  - truth registers[7].field_parts[0].bit_field[0] / v12 registers[11].field_parts[0].bit_field[0] -> C=1.0.
  - truth registers[8].field_parts[0].bit_field[1] / v12 registers[12].field_parts[0].bit_field[1] -> C=1.0.
  - truth registers[11].field_parts[0].bit_field[1] / v12 registers[15].field_parts[0].bit_field[1] -> C=1.0.
- Truth-empty/nonempty locations (C=0):
  - truth registers[3].field_parts[0].bit_field[3] (missing) / v12 registers[7].field_parts[0].bit_field[3] -> truth=EMPTY, v12=RW.
- Truth-concrete/extraction-empty locations (C=0):
  - truth registers[3].field_parts[0].bit_field[2] / v12 registers[7].field_parts[0].bit_field[2] -> truth=RW, v12="".
  - truth registers[5].field_parts[0].bit_field[6] / v12 registers[9].field_parts[0].bit_field[6] (missing) -> truth=RW, v12=EMPTY.
  - truth registers[5].field_parts[0].bit_field[7] / v12 registers[9].field_parts[0].bit_field[7] (missing) -> truth=RW, v12=EMPTY.

## 5. Invented-field and representation check

- The separate extra-physical-register penalty is applied exactly once through x=0; no extra physical address is silently matched to a nearby truth address.
- The six pressure/temperature byte entries are an accepted split of the two multi-address truth logical registers; their split representation is not penalized.
- The single COEF entry is an accepted merged representation of all 18 truth COEF physical parts. Its 20 coefficient bit fields align positionally with the truth coefficient fields; the updated R access type is matched.
- v12 has one extra positional TMP_CFG bit-field entry and omits two CFG_REG bit-field entries. These are not extra physical registers, but their direct bit-field fields receive C=0 where the corresponding truth position is missing or functionally different.
- Reserved-bit name/description emptiness is permitted by AGENTS.md. The six genuine reserved empty/empty type_write_read comparisons are credited with C=1.0.
- COEF_SRCE is treated as the canonical shorthand for Coefficient Source only at the logical-register name field; its physical field part is compared strictly as TMP_COEF_SRCE.
- No fields outside the scored AGENTS.md field lists are included in the numerical score.

## 6. Calculation conclusion

All 16 extracted logical-register items were reviewed, including the accepted split and merged representations; every matched field part and every compared bit-field position is shown bottom-up above. The final DPS368 v12_0 score is **9.134157559 / 10**.


