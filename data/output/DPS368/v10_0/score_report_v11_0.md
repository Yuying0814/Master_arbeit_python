# DPS368 v11.0 detailed score - revised AGENTS.md rules

## 1. Scoring basis

- n=33 unique truth physical registers are scored by numeric address plus bank and page; hexadecimal and decimal address strings are treated as the same number.
- Every extracted logical register with a truth physical association is calculated bottom-up: truth bit fields -> field part -> logical register Q(L). Extra logical registers are documented separately and do not enter the truth-physical-register mean.
- For each truth physical register, q_R is the mean of every associated extracted logical-register score. Missing truth physical registers receive q_R=0.
- Equivalent logical-register merge/split representations are not penalized solely for grouping. v11's six data-byte logical entries are compared with their corresponding truth physical bytes, and the merged COEF entry is compared across all 18 truth physical parts.
- Objective facts are strict: numeric addresses, bank/page, widths, bit boundaries, reserved classification, access types, names/parameters, defaults, and functional value codes. Descriptions are judged semantically; a nonempty paraphrase can receive 1, a functionally incomplete description 0.5, and missing/incorrect content 0.
- The rounded AHP weights sum to 0.9999 for bit fields, 1.0000 for field parts, and 1.0001 for logical registers; the displayed formulas normalize by those denominators.
- type_write_read audit rule: when truth and extraction are both empty, C=1.0; when truth is empty but extraction invents a value, C=0; when truth has a concrete value, it must match exactly. Empty/empty access-type fields below are credited and are not listed as errors.
- default_value_description is directly scored. In v11 truth is empty for every logical register while the extraction supplies reset-state text for all 16 entries; these 16 additions receive C=0.
- The logical name COEF_SRCE is accepted as the canonical abbreviation of truth Coefficient Source, consistent with prior DPS368 reports. The spelling changes PRS -> PSR, the ID abbreviation, and the TMP_PRC[2:0] name omission are not treated as equivalent objective names.

## Extracted logical register 1: PSR_B2

v11 registers[0]; truth association: truth registers[0] (Pressure Data (PRS_Bn)).
Associated physical locations: 0x00 (0).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: PRS_B2 at 0x00 (0)

Locations: truth registers[0].field_parts[0]  registers[0].field_parts[0].

Truth bit field 1: PRS[23:16] bits 0:7

Locations: truth registers[0].field_parts[0].bit_field[0]  registers[0].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | PRS[23:16] | PRS[23:16] |
| field_description | 0.0586 | 1.0 | MSB of 24 bit 2's complement pressure data. | MSB of 24 bit 2´s complement pressure data. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: register_name C=0.0.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | PRS_B2 | PSR_B2 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Highest byte of the 24-bit pressure value."} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Pressure (MSB data), address 00H, reset 00H."} |
| description | 0.0693 | 1.000000 | Highest byte; pressure MSB data. | The highest byte of the three bytes measured pressure value. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=0.972000/1.0000=\mathbf{0.972000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.972000) = **0.972000**.
Direct judgment: name C=0.0; default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 0.000000 | PRS_B2 | PSR_B2 |
| physical_address | 0.4044 | 1.000000 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Highest byte of the 24-bit pressure value."} | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Highest byte (MSB) of the three-byte measured pressure value."}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement pressure measurement value; when FIFO is enabled, it contains FIFO pressure and/or temperature results. | Pressure Data register (PRS_Bn) highest byte. Contains bits 23:16 of the 24 bit (3 byte) 2's complement pressure measurement value. If the FIFO is enabled, the PRS_Bn registers contain the FIFO pressure and/or temperature results; otherwise they contain the pressure measurement result and are not cleared after read. When FIFO is enabled the pressure result register updates to the next FIFO value after each read and returns 0x800000 once the FIFO is empty. All measurement data can be read in a single command using auto-increment read. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 0.972000 | mean(0.972000) | mean(0.972000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 00h |
| default_value_description | 0.0334 | 0.000000 | "" | Reset state 00h per Register Map and register description. |

\(Q(L_1)=(0.0225*0.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.972000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.935836/1.0001=\mathbf{0.935743}\)

## Extracted logical register 2: PSR_B1

v11 registers[1]; truth association: truth registers[0] (Pressure Data (PRS_Bn)).
Associated physical locations: 0x01 (1).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 2: PRS_B1 at 0x01 (1)

Locations: truth registers[0].field_parts[1]  registers[1].field_parts[0].

Truth bit field 1: PRS[15:8] bits 0:7

Locations: truth registers[0].field_parts[1].bit_field[0]  registers[1].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | PRS[15:8] | PRS[15:8] |
| field_description | 0.0586 | 1.0 | Middle byte of 24 bit 2's complement pressure data. | LSB of 24 bit 2´s complement pressure data. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: register_name C=0.0.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | PRS_B1 | PSR_B1 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"Middle byte of the 24-bit pressure value."} | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"Pressure (LSB data), address 01H, reset 00H."} |
| description | 0.0693 | 1.000000 | Middle byte of the pressure value. | The middle byte of the three bytes measured pressure value. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=0.972000/1.0000=\mathbf{0.972000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.972000) = **0.972000**.
Direct judgment: name C=0.0; default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 0.000000 | PRS_B1 | PSR_B1 |
| physical_address | 0.4044 | 1.000000 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"Middle byte of the 24-bit pressure value."} | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":"Middle byte of the three-byte measured pressure value."}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement pressure measurement value; when FIFO is enabled, it contains FIFO pressure and/or temperature results. | Pressure Data register (PRS_Bn) middle byte. Contains bits 15:8 of the 24 bit (3 byte) 2's complement pressure measurement value (FIFO results when FIFO is enabled). |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 0.972000 | mean(0.972000) | mean(0.972000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 00h |
| default_value_description | 0.0334 | 0.000000 | "" | Reset state 00h. |

\(Q(L_2)=(0.0225*0.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.972000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.935836/1.0001=\mathbf{0.935743}\)

## Extracted logical register 3: PSR_B0

v11 registers[2]; truth association: truth registers[0] (Pressure Data (PRS_Bn)).
Associated physical locations: 0x02 (2).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 3: PRS_B0 at 0x02 (2)

Locations: truth registers[0].field_parts[2]  registers[2].field_parts[0].

Truth bit field 1: PRS[7:0] bits 0:7

Locations: truth registers[0].field_parts[2].bit_field[0]  registers[2].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | PRS[7:0] | PRS[7:0] |
| field_description | 0.0586 | 1.0 | XLSB of 24 bit 2's complement pressure data. | XLSB of 24 bit 2´s complement pressure data. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: register_name C=0.0.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 0.000000 | PRS_B0 | PSR_B0 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"Lowest byte of the 24-bit pressure value."} | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"Pressure (XLSB data), address 02H, reset 00H."} |
| description | 0.0693 | 1.000000 | Lowest byte; pressure XLSB data. | The lowest byte of the three bytes measured pressure value. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=0.972000/1.0000=\mathbf{0.972000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.972000) = **0.972000**.
Direct judgment: name C=0.0; default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 0.000000 | PRS_B0 | PSR_B0 |
| physical_address | 0.4044 | 1.000000 | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"Lowest byte of the 24-bit pressure value."} | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":"Lowest byte (XLSB) of the three-byte measured pressure value."}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement pressure measurement value; when FIFO is enabled, it contains FIFO pressure and/or temperature results. | Pressure Data register (PRS_Bn) lowest byte. Contains bits 7:0 of the 24 bit (3 byte) 2's complement pressure measurement value (FIFO results when FIFO is enabled). When FIFO is used, the sensor sets the least significant bit of the result to 1 for a pressure measurement and 0 for a temperature measurement. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 0.972000 | mean(0.972000) | mean(0.972000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 00h |
| default_value_description | 0.0334 | 0.000000 | "" | Reset state 00h. |

\(Q(L_3)=(0.0225*0.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.972000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.935836/1.0001=\mathbf{0.935743}\)

## Extracted logical register 4: TMP_B2

v11 registers[3]; truth association: truth registers[1] (Temperature Data (TMP_Tn)).
Associated physical locations: 0x03 (3).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_B2 at 0x03 (3)

Locations: truth registers[1].field_parts[0]  registers[3].field_parts[0].

Truth bit field 1: TMP[23:16] bits 0:7

Locations: truth registers[1].field_parts[0].bit_field[0]  registers[3].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | TMP[23:16] | TMP[23:16] |
| field_description | 0.0586 | 1.0 | MSB of 24 bit 2's complement temperature data. | MSB of 24 bit 2´s complement temperature data. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | TMP_B2 | TMP_B2 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"Highest byte of the 24-bit temperature value."} | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"Temperature (MSB data), address 03H, reset 00H."} |
| description | 0.0693 | 1.000000 | Highest byte; temperature MSB data. | The highest byte of the three bytes measured temperature value. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | TMP_B2 | TMP_B2 |
| physical_address | 0.4044 | 1.000000 | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"Highest byte of the 24-bit temperature value."} | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"Highest byte (MSB) of the three-byte measured temperature value."}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement temperature measurement value and is not cleared after read; FIFO operation can affect the result data. | Temperature Data register (TMP_Tn) highest byte. Contains bits 23:16 of the 24 bit (3 byte) 2's complement temperature measurement value (unless the FIFO is enabled; see FIFO operation) and is not cleared after read. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 00h |
| default_value_description | 0.0334 | 0.000000 | "" | Reset state 00h. |

\(Q(L_4)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.966700/1.0001=\mathbf{0.966603}\)

## Extracted logical register 5: TMP_B1

v11 registers[4]; truth association: truth registers[1] (Temperature Data (TMP_Tn)).
Associated physical locations: 0x04 (4).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 2: TMP_B1 at 0x04 (4)

Locations: truth registers[1].field_parts[1]  registers[4].field_parts[0].

Truth bit field 1: TMP[15:8] bits 0:7

Locations: truth registers[1].field_parts[1].bit_field[0]  registers[4].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | TMP[15:8] | TMP[15:8] |
| field_description | 0.0586 | 1.0 | Middle byte of 24 bit 2's complement temperature data. | LSB of 24 bit 2´s complement temperature data. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | TMP_B1 | TMP_B1 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Middle byte of the 24-bit temperature value."} | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Temperature (LSB data), address 04H, reset 00H."} |
| description | 0.0693 | 1.000000 | Middle byte of the temperature value. | The middle byte of the three bytes measured temperature value. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | TMP_B1 | TMP_B1 |
| physical_address | 0.4044 | 1.000000 | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Middle byte of the 24-bit temperature value."} | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":"Middle byte of the three-byte measured temperature value."}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement temperature measurement value and is not cleared after read; FIFO operation can affect the result data. | Temperature Data register (TMP_Tn) middle byte. Contains bits 15:8 of the 24 bit (3 byte) 2's complement temperature measurement value. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 00h |
| default_value_description | 0.0334 | 0.000000 | "" | Reset state 00h. |

\(Q(L_5)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.966700/1.0001=\mathbf{0.966603}\)

## Extracted logical register 6: TMP_B0

v11 registers[5]; truth association: truth registers[1] (Temperature Data (TMP_Tn)).
Associated physical locations: 0x05 (5).
Accepted data-byte split: direct logical fields are compared with the corresponding truth physical byte, while the split itself is not penalized.

### Bottom layer: bit fields, then field parts

#### Field part 3: TMP_B0 at 0x05 (5)

Locations: truth registers[1].field_parts[2]  registers[5].field_parts[0].

Truth bit field 1: TMP[7:0] bits 0:7

Locations: truth registers[1].field_parts[2].bit_field[0]  registers[5].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | TMP[7:0] | TMP[7:0] |
| field_description | 0.0586 | 1.0 | XLSB of 24 bit 2's complement temperature data. | XLSB of 24 bit 2´s complement temperature data. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | TMP_B0 | TMP_B0 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Lowest byte of the 24-bit temperature value."} | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Temperature (XLSB data), address 05H, reset 00H."} |
| description | 0.0693 | 1.000000 | Lowest byte; temperature XLSB data. | The lowest part of the three bytes measured temperature value. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | TMP_B0 | TMP_B0 |
| physical_address | 0.4044 | 1.000000 | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Lowest byte of the 24-bit temperature value."} | [{"hex":"0x05","decimal":"5","bank":"","page":"","description":"Lowest byte (XLSB) of the three-byte measured temperature value."}] |
| register_description | 0.0564 | 1.000000 | Contains the 24-bit 2's complement temperature measurement value and is not cleared after read; FIFO operation can affect the result data. | Temperature Data register (TMP_Tn) lowest byte. Contains bits 7:0 of the 24 bit (3 byte) 2's complement temperature measurement value. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 0x00 | 00h |
| default_value_description | 0.0334 | 0.000000 | "" | Reset state 00h. |

\(Q(L_6)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.966700/1.0001=\mathbf{0.966603}\)

## Extracted logical register 7: PRS_CFG

v11 registers[6]; truth association: truth registers[2] (PRS_CFG).
Associated physical locations: 0x06 (6).

### Bottom layer: bit fields, then field parts

#### Field part 1: PRS_CFG at 0x06 (6)

Locations: truth registers[2].field_parts[0]  registers[6].field_parts[0].

Truth bit field 1: - bits 7:7

Locations: truth registers[2].field_parts[0].bit_field[0]  registers[6].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | - | - |
| field_description | 0.0586 | 1.0 | Reserved. | Reserved. |
| bit_start | 0.2594 | 1.0 | 7 | 7 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | true | true |
| type_write_read | 0.0583 | 1.0 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: PM_RATE[2:0] bits 4:6

Locations: truth registers[2].field_parts[0].bit_field[1]  registers[6].field_parts[0].bit_field[1].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | PM_RATE[2:0] | PM_RATE[2:0] |
| field_description | 0.0586 | 1.0 | Pressure measurement rate in Background mode. | Pressure measurement rate. Applicable for measurements in Background mode only. |
| bit_start | 0.2594 | 1.0 | 4 | 4 |
| bit_end | 0.2594 | 1.0 | 6 | 6 |
| bit_width | 0.0583 | 1.0 | 3 | 3 |
| values | 0.2097 | 1.0 | [{"value":"000","value_description":"1 measurement per second"},{"value":"001","value_description":"2 measurements per second"},{"value":"010","value_description":"4 measurements per second"},{"value":"011","value_description":"8 measurements per second"},{"value":"100","value_description":"16 measurements per second"},{"value":"101","value_description":"32 measurements per second"},{"value":"110","value_description":"64 measurements per second"},{"value":"111","value_description":"128 measurements per second"}] | [{"value":"000","value_description":"1 measurements pr. sec."},{"value":"001","value_description":"2 measurements pr. sec."},{"value":"010","value_description":"4 measurements pr. sec."},{"value":"011","value_description":"8 measurements pr. sec."},{"value":"100","value_description":"16 measurements pr. sec."},{"value":"101","value_description":"32 measurements pr. sec."},{"value":"110","value_description":"64 measurements pr. sec."},{"value":"111","value_description":"128 measurements pr. sec."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: PM_PRC[3:0] bits 0:3

Locations: truth registers[2].field_parts[0].bit_field[2]  registers[6].field_parts[0].bit_field[2].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | PM_PRC[3:0] | PM_PRC[3:0] |
| field_description | 0.0586 | 1.0 | Pressure oversampling rate; settings above 8 times require use with the pressure result bit shift. | Pressure oversampling rate. Values marked *) must be used in combination with a bit shift (see CFG_REG). |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 3 | 3 |
| bit_width | 0.0583 | 1.0 | 4 | 4 |
| values | 0.2097 | 1.0 | [{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard)"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times (High Precision)"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] | [{"value":"0000","value_description":"Single. (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)."},{"value":"0010","value_description":"4 times."},{"value":"0011","value_description":"8 times."},{"value":"0100","value_description":"16 times (Standard). *) Use with bit shift (CFG_REG)."},{"value":"0101","value_description":"32 times. *) Use with bit shift (CFG_REG)."},{"value":"0110","value_description":"64 times (High Precision). *) Use with bit shift (CFG_REG)."},{"value":"0111","value_description":"128 times. *) Use with bit shift (CFG_REG)."},{"value":"1xxx","value_description":"Reserved"}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | PRS_CFG | PRS_CFG |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x06","decimal":"6","bank":"","page":"","description":""} | {"hex":"0x06","decimal":"6","bank":"","page":"","description":"Pressure measurement configuration, address 06H, reset 00H."} |
| description | 0.0693 | 1.000000 | Pressure measurement configuration. | Pressure measurement rate and resolution configuration. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | RW | RW |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | PRS_CFG | PRS_CFG |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":""}] | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":"Pressure measurement configuration register."}] |
| register_description | 0.0564 | 1.000000 | Configures pressure measurement rate and resolution. | Configuration of pressure measurement rate (PM_RATE) and resolution/oversampling (PM_PRC). PM_RATE applies in Background mode only. Oversampling rates above 8 times (PM_PRC 0100-0111, marked *) must be used in combination with a result bit shift; see Interrupt and FIFO configuration (CFG_REG) register (P_SHIFT). Precision (PaRMS), measurement time, and estimated current consumption versus oversampling/rate are given in Table 16 and Table 17; when temperature measurements are also performed, valid combinations are limited to Rate_temperature x Measurement Time_temperature + Rate_pressure x Measurement Time_pressure < 1 second. Example configurations for use cases are given in Table 10 (address 0x06). |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | RW | RW |
| field_parts | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 00H | 00h |
| default_value_description | 0.0334 | 0.000000 | "" | Reset state 00h. |

\(Q(L_7)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.966700/1.0001=\mathbf{0.966603}\)

## Extracted logical register 8: TMP_CFG

v11 registers[7]; truth association: truth registers[3] (TMP_CFG).
Associated physical locations: 0x07 (7).

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_CFG at 0x07 (7)

Locations: truth registers[3].field_parts[0]  registers[7].field_parts[0].

Truth bit field 1: TMP_EXT bits 7:7

Locations: truth registers[3].field_parts[0].bit_field[0]  registers[7].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | TMP_EXT | TMP_EXT |
| field_description | 0.0586 | 1.0 | Selects the temperature sensor used for measurement. | Temperature measurement source. It is highly recommended to use the same temperature sensor as the source of the calibration coefficients (see Coefficient Source register). |
| bit_start | 0.2594 | 1.0 | 7 | 7 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"Internal sensor in ASIC"},{"value":"1","value_description":"External sensor in pressure sensor MEMS element"}] | [{"value":"0","value_description":"Internal sensor (in ASIC)"},{"value":"1","value_description":"External sensor (in pressure sensor MEMS element)"}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: TMP_RATE[2:0] bits 4:6

Locations: truth registers[3].field_parts[0].bit_field[1]  registers[7].field_parts[0].bit_field[1].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | TMP_RATE[2:0] | TMP_RATE[2:0] |
| field_description | 0.0586 | 1.0 | Temperature measurement rate in Background mode. | Temperature measurement rate. Applicable for measurements in Background mode only. |
| bit_start | 0.2594 | 1.0 | 4 | 4 |
| bit_end | 0.2594 | 1.0 | 6 | 6 |
| bit_width | 0.0583 | 1.0 | 3 | 3 |
| values | 0.2097 | 1.0 | [{"value":"000","value_description":"1 measurement per second"},{"value":"001","value_description":"2 measurements per second"},{"value":"010","value_description":"4 measurements per second"},{"value":"011","value_description":"8 measurements per second"},{"value":"100","value_description":"16 measurements per second"},{"value":"101","value_description":"32 measurements per second"},{"value":"110","value_description":"64 measurements per second"},{"value":"111","value_description":"128 measurements per second"}] | [{"value":"000","value_description":"1 measurement pr. sec."},{"value":"001","value_description":"2 measurements pr. sec."},{"value":"010","value_description":"4 measurements pr. sec."},{"value":"011","value_description":"8 measurements pr. sec."},{"value":"100","value_description":"16 measurements pr. sec."},{"value":"101","value_description":"32 measurements pr. sec."},{"value":"110","value_description":"64 measurements pr. sec."},{"value":"111","value_description":"128 measurements pr. sec."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo) bits 0:3

Locations: truth registers[3].field_parts[0].bit_field[2]  registers[7].field_parts[0].bit_field[2].
Judgment: 7 of 8 scored bit-field fields are correct; name_or_parameter C=0.0.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 0.0 | TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo) | TMP_PRC[2:0] |
| field_description | 0.0586 | 1.0 | Temperature oversampling and precision. | Temperature oversampling (precision). Non-default options are optional and may not be relevant. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 3 | 3 |
| bit_width | 0.0583 | 1.0 | 4 | 4 |
| values | 0.2097 | 1.0 | [{"value":"0000","value_description":"Single (Default), measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] | [{"value":"0000","value_description":"single. (Default) - Measurement time 3.6 ms."},{"value":"0001","value_description":"2 times."},{"value":"0010","value_description":"4 times."},{"value":"0011","value_description":"8 times."},{"value":"0100","value_description":"16 times."},{"value":"0101","value_description":"32 times."},{"value":"0110","value_description":"64 times."},{"value":"0111","value_description":"128 times."},{"value":"1xxx","value_description":"Reserved."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\mathbf{0.978798}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 0.978798) = **0.992933**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | TMP_CFG | TMP_CFG |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} | {"hex":"0x07","decimal":"7","bank":"","page":"","description":"Temperature measurement configuration, address 07H, reset 00H."} |
| description | 0.0693 | 1.000000 | Temperature measurement configuration. | Temperature sensor source, measurement rate and oversampling configuration. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | RW | RW |
| bit_field | 0.3129 | 0.992933 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.992933)/1.0000=0.997789/1.0000=\mathbf{0.997789}\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.997789) = **0.997789**.
Direct judgment: default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | TMP_CFG | TMP_CFG |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":""}] | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":"Temperature measurement configuration register."}] |
| register_description | 0.0564 | 1.000000 | Configures temperature measurement rate and resolution. | Configuration of temperature measurement rate (TMP_RATE) and resolution/oversampling (TMP_PRC), and selection of the temperature sensor (TMP_EXT). TMP_RATE applies in Background mode only. It is highly recommended to use the same temperature sensor as the source of the calibration coefficients; see the Coefficient Source (COEF_SRCE) register. Example configurations are given in Table 10 (address 0x07). |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | RW | RW |
| field_parts | 0.2987 | 0.997789 | mean(0.997789) | mean(0.997789) |
| default_value | 0.0667 | 1.000000 | 00H | 00h |
| default_value_description | 0.0334 | 0.000000 | "" | Reset state 00h. |

\(Q(L_8)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*0.997789 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.966039/1.0001=\mathbf{0.965943}\)

## Extracted logical register 9: MEAS_CFG

v11 registers[8]; truth association: truth registers[4] (MEAS_CFG).
Associated physical locations: 0x08 (8).

### Bottom layer: bit fields, then field parts

#### Field part 1: MEAS_CFG at 0x08 (8)

Locations: truth registers[4].field_parts[0]  registers[8].field_parts[0].

Truth bit field 1: COEF_RDY bits 7:7

Locations: truth registers[4].field_parts[0].bit_field[0]  registers[8].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | COEF_RDY | COEF_RDY |
| field_description | 0.0586 | 1.0 | Indicates whether coefficients have been loaded into the coefficient registers after start-up. | Coefficients will be read to the Coefficients Registers after start-up. |
| bit_start | 0.2594 | 1.0 | 7 | 7 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"Coefficients are not available yet"},{"value":"1","value_description":"Coefficients are available"}] | [{"value":"0","value_description":"Coefficients are not available yet."},{"value":"1","value_description":"Coefficients are available."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: SENSOR_RDY bits 6:6

Locations: truth registers[4].field_parts[0].bit_field[1]  registers[8].field_parts[0].bit_field[1].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | SENSOR_RDY | SENSOR_RDY |
| field_description | 0.0586 | 1.0 | Indicates completion of pressure sensor self-initialization after start-up. | The pressure sensor is running through self initialization after start-up. It is recommend not to start measurements until the sensor has completed the self initialization. |
| bit_start | 0.2594 | 1.0 | 6 | 6 |
| bit_end | 0.2594 | 1.0 | 6 | 6 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"Sensor initialization not complete"},{"value":"1","value_description":"Sensor initialization complete"}] | [{"value":"0","value_description":"Sensor initialization not complete"},{"value":"1","value_description":"Sensor initialization complete"}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: TMP_RDY bits 5:5

Locations: truth registers[4].field_parts[0].bit_field[2]  registers[8].field_parts[0].bit_field[2].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | TMP_RDY | TMP_RDY |
| field_description | 0.0586 | 1.0 | Temperature measurement ready status; cleared when the temperature measurement is read. | Temperature measurement ready. Cleared when temperature measurement is read. |
| bit_start | 0.2594 | 1.0 | 5 | 5 |
| bit_end | 0.2594 | 1.0 | 5 | 5 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"1","value_description":"New temperature measurement is ready"}] | [{"value":"1","value_description":"New temperature measurement is ready."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 4: PRS_RDY bits 4:4

Locations: truth registers[4].field_parts[0].bit_field[3]  registers[8].field_parts[0].bit_field[3].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | PRS_RDY | PRS_RDY |
| field_description | 0.0586 | 1.0 | Pressure measurement ready status; cleared when the pressure measurement is read. | Pressure measurement ready. Cleared when pressure measurement is read. |
| bit_start | 0.2594 | 1.0 | 4 | 4 |
| bit_end | 0.2594 | 1.0 | 4 | 4 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"1","value_description":"New pressure measurement is ready"}] | [{"value":"1","value_description":"New pressure measurement is ready."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 5: - bits 3:3

Locations: truth registers[4].field_parts[0].bit_field[4]  registers[8].field_parts[0].bit_field[4].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | - | - |
| field_description | 0.0586 | 1.0 | Reserved. | Reserved. |
| bit_start | 0.2594 | 1.0 | 3 | 3 |
| bit_end | 0.2594 | 1.0 | 3 | 3 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | true | true |
| type_write_read | 0.0583 | 1.0 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 6: MEAS_CTRL bits 0:2

Locations: truth registers[4].field_parts[0].bit_field[5]  registers[8].field_parts[0].bit_field[5].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | MEAS_CTRL | MEAS_CTRL |
| field_description | 0.0586 | 1.0 | Sets the measurement mode and type. | Set measurement mode and type (Standby, Command, or Background mode). |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 2 | 2 |
| bit_width | 0.0583 | 1.0 | 3 | 3 |
| values | 0.2097 | 1.0 | [{"value":"000","value_description":"Standby: idle or stop background measurement"},{"value":"001","value_description":"Command mode: pressure measurement"},{"value":"010","value_description":"Command mode: temperature measurement"},{"value":"011","value_description":"Not available"},{"value":"100","value_description":"Not available"},{"value":"101","value_description":"Background mode: continuous pressure measurement"},{"value":"110","value_description":"Background mode: continuous temperature measurement"},{"value":"111","value_description":"Background mode: continuous pressure and temperature measurement"}] | [{"value":"000","value_description":"Idle / Stop background measurement (Standby Mode)"},{"value":"001","value_description":"Pressure measurement (Command Mode)"},{"value":"010","value_description":"Temperature measurement (Command Mode)"},{"value":"011","value_description":"na."},{"value":"100","value_description":"na."},{"value":"101","value_description":"Continous pressure measurement (Background Mode)"},{"value":"110","value_description":"Continous temperature measurement (Background Mode)"},{"value":"111","value_description":"Continous pressure and temperature measurement (Background Mode)"}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | MEAS_CFG | MEAS_CFG |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x08","decimal":"8","bank":"","page":"","description":""} | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"Measurement configuration, address 08H, reset C0H."} |
| description | 0.0693 | 1.000000 | Measurement configuration and readiness status. | Measurement mode control and ready status. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | RW | RW |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | MEAS_CFG | MEAS_CFG |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":""}] | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":"Sensor operating mode and status register."}] |
| register_description | 0.0564 | 1.000000 | Sets the measurement operating mode and reports sensor, coefficient, pressure, and temperature readiness. | Sets the measurement mode and type (MEAS_CTRL: standby, command, or background mode for pressure/temperature) and reports ready status (COEF_RDY, SENSOR_RDY, TMP_RDY, PRS_RDY). It is recommended not to start measurements until sensor self-initialization is complete (SENSOR_RDY=1). Use case examples start background measurements via this register (address 0x08). |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | RW | RW |
| field_parts | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | C0H | C0h |
| default_value_description | 0.0334 | 0.000000 | "" | Reset state C0h (COEF_RDY and SENSOR_RDY set after reset). |

\(Q(L_9)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.966700/1.0001=\mathbf{0.966603}\)

## Extracted logical register 10: CFG_REG

v11 registers[9]; truth association: truth registers[5] (CFG_REG).
Associated physical locations: 0x09 (9).

### Bottom layer: bit fields, then field parts

#### Field part 1: CFG_REG at 0x09 (9)

Locations: truth registers[5].field_parts[0]  registers[9].field_parts[0].

Truth bit field 1: INT_HL bits 7:7

Locations: truth registers[5].field_parts[0].bit_field[0]  registers[9].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | INT_HL | INT_HL |
| field_description | 0.0586 | 1.0 | Interrupt active level on the SDO pin. | Interrupt (on SDO pin) active level. |
| bit_start | 0.2594 | 1.0 | 7 | 7 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"Active low"},{"value":"1","value_description":"Active high"}] | [{"value":"0","value_description":"Active low."},{"value":"1","value_description":"Active high."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: INT_FIFO bits 6:6

Locations: truth registers[5].field_parts[0].bit_field[1]  registers[9].field_parts[0].bit_field[1].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | INT_FIFO | INT_FIFO |
| field_description | 0.0586 | 1.0 | Controls interrupt generation when the FIFO is full. | Generate interrupt when the FIFO is full. |
| bit_start | 0.2594 | 1.0 | 6 | 6 |
| bit_end | 0.2594 | 1.0 | 6 | 6 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: INT_TMP bits 5:5

Locations: truth registers[5].field_parts[0].bit_field[2]  registers[9].field_parts[0].bit_field[2].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | INT_TMP | INT_TMP |
| field_description | 0.0586 | 1.0 | Controls interrupt generation when a temperature measurement is ready. | Generate interrupt when a temperature measurement is ready. |
| bit_start | 0.2594 | 1.0 | 5 | 5 |
| bit_end | 0.2594 | 1.0 | 5 | 5 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 4: INT_PRS bits 4:4

Locations: truth registers[5].field_parts[0].bit_field[3]  registers[9].field_parts[0].bit_field[3].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | INT_PRS | INT_PRS |
| field_description | 0.0586 | 1.0 | Controls interrupt generation when a pressure measurement is ready. | Generate interrupt when a pressure measurement is ready. |
| bit_start | 0.2594 | 1.0 | 4 | 4 |
| bit_end | 0.2594 | 1.0 | 4 | 4 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 5: T_SHIFT bits 3:3

Locations: truth registers[5].field_parts[0].bit_field[4]  registers[9].field_parts[0].bit_field[4].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | T_SHIFT | T_SHIFT |
| field_description | 0.0586 | 1.0 | Temperature result bit shift; must be enabled when oversampling is greater than 8 times. | Temperature result bit-shift. Must be set to '1' when the oversampling rate is >8 times. |
| bit_start | 0.2594 | 1.0 | 3 | 3 |
| bit_end | 0.2594 | 1.0 | 3 | 3 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"No shift"},{"value":"1","value_description":"Shift result right in data register"}] | [{"value":"0","value_description":"no shift."},{"value":"1","value_description":"shift result right in data register."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 6: P_SHIFT bits 2:2

Locations: truth registers[5].field_parts[0].bit_field[5]  registers[9].field_parts[0].bit_field[5].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | P_SHIFT | P_SHIFT |
| field_description | 0.0586 | 1.0 | Pressure result bit shift; must be enabled when oversampling is greater than 8 times. | Pressure result bit-shift. Must be set to '1' when the oversampling rate is >8 times. |
| bit_start | 0.2594 | 1.0 | 2 | 2 |
| bit_end | 0.2594 | 1.0 | 2 | 2 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"No shift"},{"value":"1","value_description":"Shift result right in data register"}] | [{"value":"0","value_description":"no shift."},{"value":"1","value_description":"shift result right in data register."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 7: FIFO_EN bits 1:1

Locations: truth registers[5].field_parts[0].bit_field[6]  registers[9].field_parts[0].bit_field[6].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | FIFO_EN | FIFO_EN |
| field_description | 0.0586 | 1.0 | Enables the FIFO. | Enable the FIFO. |
| bit_start | 0.2594 | 1.0 | 1 | 1 |
| bit_end | 0.2594 | 1.0 | 1 | 1 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 8: SPI_MODE bits 0:0

Locations: truth registers[5].field_parts[0].bit_field[7]  registers[9].field_parts[0].bit_field[7].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | SPI_MODE | SPI_MODE |
| field_description | 0.0586 | 1.0 | Selects the SPI interface mode. | Set SPI mode. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 0 | 0 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"4-wire interface"},{"value":"1","value_description":"3-wire interface"}] | [{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | RW | RW |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | CFG_REG | CFG_REG |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x09","decimal":"9","bank":"","page":"","description":""} | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"Configuration register, address 09H, reset 00H."} |
| description | 0.0693 | 1.000000 | Interrupt, result-shift, FIFO, and SPI configuration. | Interrupt, data shift, FIFO enable and SPI mode configuration. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | RW | RW |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | CFG_REG | CFG_REG |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x09","decimal":"9","bank":"","page":"","description":""}] | [{"hex":"0x09","decimal":"9","bank":"","page":"","description":"Interrupt and FIFO configuration register."}] |
| register_description | 0.0564 | 1.000000 | Configures interrupts, measurement data shifts, FIFO enable, and SPI interface mode. | Configuration of interrupts (active level and FIFO/temperature/pressure interrupt enables), measurement data shift (T_SHIFT/P_SHIFT, must be set to 1 when the oversampling rate is >8 times; used together with PRS_CFG/TMP_CFG precision settings), FIFO enable, and SPI mode. The FIFO is enabled in this register; if INT_FIFO is set, an interrupt is generated when the FIFO is full. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | RW | RW |
| field_parts | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 00H | 00h |
| default_value_description | 0.0334 | 0.000000 | "" | Reset state 00h. |

\(Q(L_10)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.966700/1.0001=\mathbf{0.966603}\)

## Extracted logical register 11: INT_STS

v11 registers[10]; truth association: truth registers[6] (INT_STS).
Associated physical locations: 0x0A (10).

### Bottom layer: bit fields, then field parts

#### Field part 1: INT_STS at 0x0A (10)

Locations: truth registers[6].field_parts[0]  registers[10].field_parts[0].

Truth bit field 1: - bits 3:7

Locations: truth registers[6].field_parts[0].bit_field[0]  registers[10].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | - | - |
| field_description | 0.0586 | 1.0 | Reserved. | Reserved. |
| bit_start | 0.2594 | 1.0 | 3 | 3 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 5 | 5 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | true | true |
| type_write_read | 0.0583 | 1.0 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: INT_FIFO_FULL bits 2:2

Locations: truth registers[6].field_parts[0].bit_field[1]  registers[10].field_parts[0].bit_field[1].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | INT_FIFO_FULL | INT_FIFO_FULL |
| field_description | 0.0586 | 1.0 | FIFO interrupt status. | Status of FIFO interrupt. |
| bit_start | 0.2594 | 1.0 | 2 | 2 |
| bit_end | 0.2594 | 1.0 | 2 | 2 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: INT_TMP bits 1:1

Locations: truth registers[6].field_parts[0].bit_field[2]  registers[10].field_parts[0].bit_field[2].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | INT_TMP | INT_TMP |
| field_description | 0.0586 | 1.0 | Temperature measurement interrupt status. | Status of temperature measurement interrupt. |
| bit_start | 0.2594 | 1.0 | 1 | 1 |
| bit_end | 0.2594 | 1.0 | 1 | 1 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 4: INT_PRS bits 0:0

Locations: truth registers[6].field_parts[0].bit_field[3]  registers[10].field_parts[0].bit_field[3].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | INT_PRS | INT_PRS |
| field_description | 0.0586 | 1.0 | Pressure measurement interrupt status. | Status of pressure measurement interrupt. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 0 | 0 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | INT_STS | INT_STS |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":""} | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Interrupt status, address 0AH, reset 00H."} |
| description | 0.0693 | 1.000000 | Interrupt status. | Interrupt status (cleared on read). |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | INT_STS | INT_STS |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":""}] | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Interrupt status register."}] |
| register_description | 0.0564 | 1.000000 | Reports FIFO, temperature measurement, and pressure measurement interrupt status; cleared on read. | Interrupt status register for FIFO full, temperature measurement ready, and pressure measurement ready interrupts. The register is cleared on read. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 00H | 00h |
| default_value_description | 0.0334 | 0.000000 | "" | Reset state 00h. |

\(Q(L_11)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.966700/1.0001=\mathbf{0.966603}\)

## Extracted logical register 12: FIFO_STS

v11 registers[11]; truth association: truth registers[7] (FIFO_STS).
Associated physical locations: 0x0B (11).

### Bottom layer: bit fields, then field parts

#### Field part 1: FIFO_STS at 0x0B (11)

Locations: truth registers[7].field_parts[0]  registers[11].field_parts[0].

Truth bit field 1: - bits 2:7

Locations: truth registers[7].field_parts[0].bit_field[0]  registers[11].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | - | - |
| field_description | 0.0586 | 1.0 | Reserved. | Reserved. |
| bit_start | 0.2594 | 1.0 | 2 | 2 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 6 | 6 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | true | true |
| type_write_read | 0.0583 | 1.0 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: FIFO_FULL bits 1:1

Locations: truth registers[7].field_parts[0].bit_field[1]  registers[11].field_parts[0].bit_field[1].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | FIFO_FULL | FIFO_FULL |
| field_description | 0.0586 | 1.0 | FIFO full status. | FIFO full status. |
| bit_start | 0.2594 | 1.0 | 1 | 1 |
| bit_end | 0.2594 | 1.0 | 1 | 1 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"FIFO is not full"},{"value":"1","value_description":"FIFO is full"}] | [{"value":"0","value_description":"The FIFO is not full"},{"value":"1","value_description":"The FIFO is full"}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: FIFO_EMPTY bits 0:0

Locations: truth registers[7].field_parts[0].bit_field[2]  registers[11].field_parts[0].bit_field[2].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | FIFO_EMPTY | FIFO_EMPTY |
| field_description | 0.0586 | 1.0 | FIFO empty status. | FIFO empty status. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 0 | 0 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"FIFO is not empty"},{"value":"1","value_description":"FIFO is empty"}] | [{"value":"0","value_description":"The FIFO is not empty"},{"value":"1","value_description":"The FIFO is empty"}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | FIFO_STS | FIFO_STS |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":""} | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"FIFO status register, address 0BH, reset 00H."} |
| description | 0.0693 | 1.000000 | FIFO status. | FIFO full/empty status. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | FIFO_STS | FIFO_STS |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x0B","decimal":"11","bank":"","page":"","description":""}] | [{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"FIFO status register."}] |
| register_description | 0.0564 | 1.000000 | Reports whether the FIFO is full or empty. | FIFO status register. FIFO_FULL is set when the FIFO is full (the FIFO stops recording measurement results when full; if CFG_REG INT_FIFO is set an interrupt is also generated). FIFO_EMPTY is set when the FIFO is empty; after all FIFO values have been read, subsequent reads of the result register return 0x800000. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 00H | 00h |
| default_value_description | 0.0334 | 0.000000 | "" | Reset state 00h. |

\(Q(L_12)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.966700/1.0001=\mathbf{0.966603}\)

## Extracted logical register 13: RESET

v11 registers[12]; truth association: truth registers[8] (RESET).
Associated physical locations: 0x0C (12).

### Bottom layer: bit fields, then field parts

#### Field part 1: RESET at 0x0C (12)

Locations: truth registers[8].field_parts[0]  registers[12].field_parts[0].

Truth bit field 1: FIFO_FLUSH bits 7:7

Locations: truth registers[8].field_parts[0].bit_field[0]  registers[12].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | FIFO_FLUSH | FIFO_FLUSH |
| field_description | 0.0586 | 1.0 | Flushes the FIFO; after reading all FIFO data, write 1 to clear old data. | FIFO flush. After reading out all data from the FIFO, write '1' to clear all old data. |
| bit_start | 0.2594 | 1.0 | 7 | 7 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"1","value_description":"Empty FIFO"}] | [{"value":"1","value_description":"Empty FIFO"}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | W | W |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: - bits 4:6

Locations: truth registers[8].field_parts[0].bit_field[1]  registers[12].field_parts[0].bit_field[1].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | - | - |
| field_description | 0.0586 | 1.0 | Reserved. | Reserved. |
| bit_start | 0.2594 | 1.0 | 4 | 4 |
| bit_end | 0.2594 | 1.0 | 6 | 6 |
| bit_width | 0.0583 | 1.0 | 3 | 3 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | true | true |
| type_write_read | 0.0583 | 1.0 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 3: SOFT_RST bits 0:3

Locations: truth registers[8].field_parts[0].bit_field[2]  registers[12].field_parts[0].bit_field[2].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | SOFT_RST | SOFT_RST |
| field_description | 0.0586 | 1.0 | Generates a soft reset using the same sequence as power-on reset. | Write '1001' to generate a soft reset. A soft reset will run though the same sequences as in power-on reset. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 3 | 3 |
| bit_width | 0.0583 | 1.0 | 4 | 4 |
| values | 0.2097 | 1.0 | [{"value":"1001","value_description":"Generate a soft reset"}] | [{"value":"1001","value_description":"Generate a soft reset (same sequence as power-on reset)."}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | W | W |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | RESET | RESET |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":""} | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"FIFO flush and soft reset, address 0CH, reset 00H."} |
| description | 0.0693 | 1.000000 | FIFO flush and soft reset control. | FIFO flush and soft reset control. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | W | W |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | RESET | RESET |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":""}] | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Soft reset and FIFO flush register."}] |
| register_description | 0.0564 | 1.000000 | Flushes the FIFO or generates a soft reset. | Flush FIFO or generate soft reset. Write SOFT_RST='1001' to generate a soft reset that runs through the same sequence as power-on reset; write FIFO_FLUSH='1' to empty the FIFO after reading out all data. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | W | W |
| field_parts | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 00H | 00h |
| default_value_description | 0.0334 | 0.000000 | "" | Reset state 00h. |

\(Q(L_13)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.966700/1.0001=\mathbf{0.966603}\)

## Extracted logical register 14: ID

v11 registers[13]; truth association: truth registers[9] (Product and Revision ID (ID)).
Associated physical locations: 0x0D (13).

### Bottom layer: bit fields, then field parts

#### Field part 1: ID at 0x0D (13)

Locations: truth registers[9].field_parts[0]  registers[13].field_parts[0].

Truth bit field 1: REV_ID bits 4:7

Locations: truth registers[9].field_parts[0].bit_field[0]  registers[13].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | REV_ID | REV_ID |
| field_description | 0.0586 | 1.0 | Revision ID. | Revision ID |
| bit_start | 0.2594 | 1.0 | 4 | 4 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 4 | 4 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: PROD_ID bits 0:3

Locations: truth registers[9].field_parts[0].bit_field[1]  registers[13].field_parts[0].bit_field[1].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | PROD_ID | PROD_ID |
| field_description | 0.0586 | 1.0 | Product ID. | Product ID |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 3 | 3 |
| bit_width | 0.0583 | 1.0 | 4 | 4 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | ID | ID |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":""} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Product and revision ID, address 0DH, reset 0x10H."} |
| description | 0.0693 | 1.000000 | Product and revision identification. | Product and Revision ID. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: name C=0.0; default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 0.000000 | Product and Revision ID (ID) | ID |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":""}] | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Product and revision ID register."}] |
| register_description | 0.0564 | 1.000000 | Contains the product and revision identifiers. | Product and Revision ID. Register Map lists this entry as 'Product ID' at address 0x0D. |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | 0x10 / 10H (0x10H in datasheet is typo) | 0x10H |
| default_value_description | 0.0334 | 0.000000 | "" | Reset value 0x10H (Register Map reset state 10h). |

\(Q(L_14)=(0.0225*0.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.944200/1.0001=\mathbf{0.944106}\)

## Extracted logical register 15: COEF

v11 registers[14]; truth association: truth registers[10] (COEF).
Associated physical locations: 0x10 (16), 0x11 (17), 0x12 (18), 0x13 (19), 0x14 (20), 0x15 (21), 0x16 (22), 0x17 (23), 0x18 (24), 0x19 (25), 0x1A (26), 0x1B (27), 0x1C (28), 0x1D (29), 0x1E (30), 0x1F (31), 0x20 (32), 0x21 (33).
Accepted coefficient merge: the single extracted logical register covers all 18 truth physical coefficient parts; bit fields are compared within each physical part.

### Bottom layer: bit fields, then field parts

#### Field part 1: c0 at 0x10 (16)

Locations: truth registers[10].field_parts[0]  registers[14].field_parts[0].

Truth bit field 1: c0 [11:4] bits 0:7

Locations: truth registers[10].field_parts[0].bit_field[0]  registers[14].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c0 [11:4] | c0 [11:4] |
| field_description | 0.0586 | 1.0 | Bits 11:4 of coefficient c0. | Calibration coefficient c0 bits 11:4. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c0 | c0 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"c0 bits 11:4."} | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"Coefficient c0 bits [11:4]."} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c0. | Calibration coefficient c0 [11:4]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 2: c0/c1 at 0x11 (17)

Locations: truth registers[10].field_parts[1]  registers[14].field_parts[1].

Truth bit field 1: c0 [3:0] bits 4:7

Locations: truth registers[10].field_parts[1].bit_field[0]  registers[14].field_parts[1].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c0 [3:0] | c0 [3:0] |
| field_description | 0.0586 | 1.0 | Bits 3:0 of coefficient c0. | Calibration coefficient c0 bits 3:0. |
| bit_start | 0.2594 | 1.0 | 4 | 4 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 4 | 4 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: c1 [11:8] bits 0:3

Locations: truth registers[10].field_parts[1].bit_field[1]  registers[14].field_parts[1].bit_field[1].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c1 [11:8] | c1 [11:8] |
| field_description | 0.0586 | 1.0 | Bits 11:8 of coefficient c1. | Calibration coefficient c1 bits 11:8. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 3 | 3 |
| bit_width | 0.0583 | 1.0 | 4 | 4 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c0/c1 | c0/c1 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Contains c0 bits 3:0 and c1 bits 11:8."} | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Coefficient c0 [3:0] and c1 [11:8]."} |
| description | 0.0693 | 1.000000 | Lower four bits of c0 and upper four bits of c1. | Calibration coefficients c0 [3:0] (bits 7:4) and c1 [11:8] (bits 3:0). |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 3: c1 at 0x12 (18)

Locations: truth registers[10].field_parts[2]  registers[14].field_parts[2].

Truth bit field 1: c1[7:0] bits 0:7

Locations: truth registers[10].field_parts[2].bit_field[0]  registers[14].field_parts[2].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c1[7:0] | c1[7:0] |
| field_description | 0.0586 | 1.0 | Bits 7:0 of coefficient c1. | Calibration coefficient c1 bits 7:0. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c1 | c1 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"c1 bits 7:0."} | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"Coefficient c1 bits [7:0]."} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c1. | Calibration coefficient c1 [7:0]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 4: c00 at 0x13 (19)

Locations: truth registers[10].field_parts[3]  registers[14].field_parts[3].

Truth bit field 1: c00 [19:12] bits 0:7

Locations: truth registers[10].field_parts[3].bit_field[0]  registers[14].field_parts[3].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c00 [19:12] | c00 [19:12] |
| field_description | 0.0586 | 1.0 | Bits 19:12 of coefficient c00. | Calibration coefficient c00 bits 19:12. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c00 | c00 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"c00 bits 19:12."} | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Coefficient c00 bits [19:12]."} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c00. | Calibration coefficient c00 [19:12]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 5: c00 at 0x14 (20)

Locations: truth registers[10].field_parts[4]  registers[14].field_parts[4].

Truth bit field 1: c00 [11:4] bits 0:7

Locations: truth registers[10].field_parts[4].bit_field[0]  registers[14].field_parts[4].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c00 [11:4] | c00 [11:4] |
| field_description | 0.0586 | 1.0 | Bits 11:4 of coefficient c00. | Calibration coefficient c00 bits 11:4. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c00 | c00 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"c00 bits 11:4."} | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Coefficient c00 bits [11:4]."} |
| description | 0.0693 | 1.000000 | Middle eight bits of coefficient c00. | Calibration coefficient c00 [11:4]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 6: c00/c10 at 0x15 (21)

Locations: truth registers[10].field_parts[5]  registers[14].field_parts[5].

Truth bit field 1: c00 [3:0] bits 4:7

Locations: truth registers[10].field_parts[5].bit_field[0]  registers[14].field_parts[5].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c00 [3:0] | c00 [3:0] |
| field_description | 0.0586 | 1.0 | Bits 3:0 of coefficient c00. | Calibration coefficient c00 bits 3:0. |
| bit_start | 0.2594 | 1.0 | 4 | 4 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 4 | 4 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: c10 [19:16] bits 0:3

Locations: truth registers[10].field_parts[5].bit_field[1]  registers[14].field_parts[5].bit_field[1].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c10 [19:16] | c10 [19:16] |
| field_description | 0.0586 | 1.0 | Bits 19:16 of coefficient c10. | Calibration coefficient c10 bits 19:16. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 3 | 3 |
| bit_width | 0.0583 | 1.0 | 4 | 4 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c00/c10 | c00/c10 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Contains c00 bits 3:0 and c10 bits 19:16."} | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Coefficient c00 [3:0] and c10 [19:16]."} |
| description | 0.0693 | 1.000000 | Lower four bits of c00 and upper four bits of c10. | Calibration coefficients c00 [3:0] (bits 7:4) and c10 [19:16] (bits 3:0). |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 7: c10 at 0x16 (22)

Locations: truth registers[10].field_parts[6]  registers[14].field_parts[6].

Truth bit field 1: c10 [15:8] bits 0:7

Locations: truth registers[10].field_parts[6].bit_field[0]  registers[14].field_parts[6].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c10 [15:8] | c10 [15:8] |
| field_description | 0.0586 | 1.0 | Bits 15:8 of coefficient c10. | Calibration coefficient c10 bits 15:8. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c10 | c10 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"c10 bits 15:8."} | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"Coefficient c10 bits [15:8]."} |
| description | 0.0693 | 1.000000 | Middle eight bits of coefficient c10. | Calibration coefficient c10 [15:8]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 8: c10 at 0x17 (23)

Locations: truth registers[10].field_parts[7]  registers[14].field_parts[7].

Truth bit field 1: c10 [7:0] bits 0:7

Locations: truth registers[10].field_parts[7].bit_field[0]  registers[14].field_parts[7].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c10 [7:0] | c10 [7:0] |
| field_description | 0.0586 | 1.0 | Bits 7:0 of coefficient c10. | Calibration coefficient c10 bits 7:0. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c10 | c10 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"c10 bits 7:0."} | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Coefficient c10 bits [7:0]."} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c10. | Calibration coefficient c10 [7:0]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 9: c01 at 0x18 (24)

Locations: truth registers[10].field_parts[8]  registers[14].field_parts[8].

Truth bit field 1: c01 [15:8] bits 0:7

Locations: truth registers[10].field_parts[8].bit_field[0]  registers[14].field_parts[8].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c01 [15:8] | c01 [15:8] |
| field_description | 0.0586 | 1.0 | Bits 15:8 of coefficient c01. | Calibration coefficient c01 bits 15:8. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c01 | c01 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"c01 bits 15:8."} | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Coefficient c01 bits [15:8]."} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c01. | Calibration coefficient c01 [15:8]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 10: c01 at 0x19 (25)

Locations: truth registers[10].field_parts[9]  registers[14].field_parts[9].

Truth bit field 1: c01 [7:0] bits 0:7

Locations: truth registers[10].field_parts[9].bit_field[0]  registers[14].field_parts[9].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c01 [7:0] | c01 [7:0] |
| field_description | 0.0586 | 1.0 | Bits 7:0 of coefficient c01. | Calibration coefficient c01 bits 7:0. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c01 | c01 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x19","decimal":"25","bank":"","page":"","description":"c01 bits 7:0."} | {"hex":"0x19","decimal":"25","bank":"","page":"","description":"Coefficient c01 bits [7:0]."} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c01. | Calibration coefficient c01 [7:0]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 11: c11 at 0x1A (26)

Locations: truth registers[10].field_parts[10]  registers[14].field_parts[10].

Truth bit field 1: c11 [15:8] bits 0:7

Locations: truth registers[10].field_parts[10].bit_field[0]  registers[14].field_parts[10].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c11 [15:8] | c11 [15:8] |
| field_description | 0.0586 | 1.0 | Bits 15:8 of coefficient c11. | Calibration coefficient c11 bits 15:8. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c11 | c11 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"c11 bits 15:8."} | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Coefficient c11 bits [15:8]."} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c11. | Calibration coefficient c11 [15:8]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 12: c11 at 0x1B (27)

Locations: truth registers[10].field_parts[11]  registers[14].field_parts[11].

Truth bit field 1: c11 [7:0] bits 0:7

Locations: truth registers[10].field_parts[11].bit_field[0]  registers[14].field_parts[11].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c11 [7:0] | c11 [7:0] |
| field_description | 0.0586 | 1.0 | Bits 7:0 of coefficient c11. | Calibration coefficient c11 bits 7:0. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c11 | c11 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"c11 bits 7:0."} | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Coefficient c11 bits [7:0]."} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c11. | Calibration coefficient c11 [7:0]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 13: c20 at 0x1C (28)

Locations: truth registers[10].field_parts[12]  registers[14].field_parts[12].

Truth bit field 1: c20 [15:8] bits 0:7

Locations: truth registers[10].field_parts[12].bit_field[0]  registers[14].field_parts[12].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c20 [15:8] | c20 [15:8] |
| field_description | 0.0586 | 1.0 | Bits 15:8 of coefficient c20. | Calibration coefficient c20 bits 15:8. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c20 | c20 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"c20 bits 15:8."} | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Coefficient c20 bits [15:8]."} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c20. | Calibration coefficient c20 [15:8]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 14: c20 at 0x1D (29)

Locations: truth registers[10].field_parts[13]  registers[14].field_parts[13].

Truth bit field 1: c20 [7:0] bits 0:7

Locations: truth registers[10].field_parts[13].bit_field[0]  registers[14].field_parts[13].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c20 [7:0] | c20 [7:0] |
| field_description | 0.0586 | 1.0 | Bits 7:0 of coefficient c20. | Calibration coefficient c20 bits 7:0. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c20 | c20 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"c20 bits 7:0."} | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Coefficient c20 bits [7:0]."} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c20. | Calibration coefficient c20 [7:0]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 15: c21 at 0x1E (30)

Locations: truth registers[10].field_parts[14]  registers[14].field_parts[14].

Truth bit field 1: c21 [15:8] bits 0:7

Locations: truth registers[10].field_parts[14].bit_field[0]  registers[14].field_parts[14].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c21 [15:8] | c21 [15:8] |
| field_description | 0.0586 | 1.0 | Bits 15:8 of coefficient c21. | Calibration coefficient c21 bits 15:8. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c21 | c21 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"c21 bits 15:8."} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Coefficient c21 bits [15:8]."} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c21. | Calibration coefficient c21 [15:8]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 16: c21 at 0x1F (31)

Locations: truth registers[10].field_parts[15]  registers[14].field_parts[15].

Truth bit field 1: c21 [7:0] bits 0:7

Locations: truth registers[10].field_parts[15].bit_field[0]  registers[14].field_parts[15].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c21 [7:0] | c21 [7:0] |
| field_description | 0.0586 | 1.0 | Bits 7:0 of coefficient c21. | Calibration coefficient c21 bits 7:0. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c21 | c21 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"c21 bits 7:0."} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Coefficient c21 bits [7:0]."} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c21. | Calibration coefficient c21 [7:0]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 17: c30 at 0x20 (32)

Locations: truth registers[10].field_parts[16]  registers[14].field_parts[16].

Truth bit field 1: c30 [15:8] bits 0:7

Locations: truth registers[10].field_parts[16].bit_field[0]  registers[14].field_parts[16].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c30 [15:8] | c30 [15:8] |
| field_description | 0.0586 | 1.0 | Bits 15:8 of coefficient c30. | Calibration coefficient c30 bits 15:8. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c30 | c30 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"c30 bits 15:8."} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Coefficient c30 bits [15:8]."} |
| description | 0.0693 | 1.000000 | Upper eight bits of coefficient c30. | Calibration coefficient c30 [15:8]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

#### Field part 18: c30 at 0x21 (33)

Locations: truth registers[10].field_parts[17]  registers[14].field_parts[17].

Truth bit field 1: c30 [7:0] bits 0:7

Locations: truth registers[10].field_parts[17].bit_field[0]  registers[14].field_parts[17].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | c30 [7:0] | c30 [7:0] |
| field_description | 0.0586 | 1.0 | Bits 7:0 of coefficient c30. | Calibration coefficient c30 bits 7:0. |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 8 | 8 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | c30 | c30 |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"c30 bits 7:0."} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"Coefficient c30 bits [7:0]."} |
| description | 0.0693 | 1.000000 | Lower eight bits of coefficient c30. | Calibration coefficient c30 [7:0]. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: width_bits C=0.0; default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | COEF | COEF |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x10","decimal":"16","bank":"","page":"","description":"c0 bits 11:4."},{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Contains c0 bits 3:0 and c1 bits 11:8."},{"hex":"0x12","decimal":"18","bank":"","page":"","description":"c1 bits 7:0."},{"hex":"0x13","decimal":"19","bank":"","page":"","description":"c00 bits 19:12."},{"hex":"0x14","decimal":"20","bank":"","page":"","description":"c00 bits 11:4."},{"hex":"0x15","decimal":"21","bank":"","page":"","description":"Contains c00 bits 3:0 and c10 bits 19:16."},{"hex":"0x16","decimal":"22","bank":"","page":"","description":"c10 bits 15:8."},{"hex":"0x17","decimal":"23","bank":"","page":"","description":"c10 bits 7:0."},{"hex":"0x18","decimal":"24","bank":"","page":"","description":"c01 bits 15:8."},{"hex":"0x19","decimal":"25","bank":"","page":"","description":"c01 bits 7:0."},{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"c11 bits 15:8."},{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"c11 bits 7:0."},{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"c20 bits 15:8."},{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"c20 bits 7:0."},{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"c21 bits 15:8."},{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"c21 bits 7:0."},{"hex":"0x20","decimal":"32","bank":"","page":"","description":"c30 bits 15:8."},{"hex":"0x21","decimal":"33","bank":"","page":"","description":"c30 bits 7:0."}] | [{"hex":"0x10","decimal":"16","bank":"","page":"","description":"Calibration coefficient c0 bits [11:4]."},{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Calibration coefficients c0 bits [3:0] (high nibble) and c1 bits [11:8] (low nibble)."},{"hex":"0x12","decimal":"18","bank":"","page":"","description":"Calibration coefficient c1 bits [7:0]."},{"hex":"0x13","decimal":"19","bank":"","page":"","description":"Calibration coefficient c00 bits [19:12]."},{"hex":"0x14","decimal":"20","bank":"","page":"","description":"Calibration coefficient c00 bits [11:4]."},{"hex":"0x15","decimal":"21","bank":"","page":"","description":"Calibration coefficients c00 bits [3:0] (high nibble) and c10 bits [19:16] (low nibble)."},{"hex":"0x16","decimal":"22","bank":"","page":"","description":"Calibration coefficient c10 bits [15:8]."},{"hex":"0x17","decimal":"23","bank":"","page":"","description":"Calibration coefficient c10 bits [7:0]."},{"hex":"0x18","decimal":"24","bank":"","page":"","description":"Calibration coefficient c01 bits [15:8]."},{"hex":"0x19","decimal":"25","bank":"","page":"","description":"Calibration coefficient c01 bits [7:0]."},{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Calibration coefficient c11 bits [15:8]."},{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Calibration coefficient c11 bits [7:0]."},{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Calibration coefficient c20 bits [15:8]."},{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"Calibration coefficient c20 bits [7:0]."},{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Calibration coefficient c21 bits [15:8]."},{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Calibration coefficient c21 bits [7:0]."},{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Calibration coefficient c30 bits [15:8]."},{"hex":"0x21","decimal":"33","bank":"","page":"","description":"Calibration coefficient c30 bits [7:0]."}] |
| register_description | 0.0564 | 1.000000 | Contains 2's complement calibration coefficients used to calculate compensated pressure and temperature values. | Calibration Coefficients register block (0x10-0x21) containing the 2's complement coefficients (c0, c1, c00, c10, c01, c11, c20, c21, c30) used by the application/host to compensate the measurement results for sensor non-linearities and convert them into Pa and °C values. Coefficients are loaded into the Coefficients Registers after start-up (see MEAS_CFG COEF_RDY). Example conversion to decimal: C20 := reg0x1D + reg0x1C * 2^8; if (C20 > (2^15 - 1)) C20 := C20 - 2^16. C0 := (reg0x10 * 2^4) + ((reg0x11 / 2^4) & 0x0F); if (C0 > (2^11 - 1)) C0 := C0 - 2^12. Retrieval hint: the remaining coefficient conversion formulas and the full pressure/temperature compensation calculation are described in the Calibration and Measurement Compensation section (4.9) and the sections that follow it. |
| width_bits | 0.0590 | 0.000000 | 144 | EMPTY |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) | mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) |
| default_value | 0.0667 | 1.000000 | XXh | XXh |
| default_value_description | 0.0334 | 0.000000 | "" | Register Map reset state XXh for the COEF block (0x10-0x21); individual coefficient values are device-specific calibration data. |

\(Q(L_15)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*0.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.907700/1.0001=\mathbf{0.907609}\)

## Extracted logical register 16: COEF_SRCE

v11 registers[15]; truth association: truth registers[11] (Coefficient Source).
Associated physical locations: 0x28 (40).

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_COEF_SRCE at 0x28 (40)

Locations: truth registers[11].field_parts[0]  registers[15].field_parts[0].

Truth bit field 1: TMP_COEF_SRCE bits 7:7

Locations: truth registers[11].field_parts[0].bit_field[0]  registers[15].field_parts[0].bit_field[0].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | TMP_COEF_SRCE | TMP_COEF_SRCE |
| field_description | 0.0586 | 1.0 | Identifies the temperature sensor on which the calibration coefficients are based. | Temperature coefficients are based on: |
| bit_start | 0.2594 | 1.0 | 7 | 7 |
| bit_end | 0.2594 | 1.0 | 7 | 7 |
| bit_width | 0.0583 | 1.0 | 1 | 1 |
| values | 0.2097 | 1.0 | [{"value":"0","value_description":"Internal temperature sensor of ASIC"},{"value":"1","value_description":"External temperature sensor of pressure sensor MEMS element"}] | [{"value":"0","value_description":"Internal temperature sensor (of ASIC)"},{"value":"1","value_description":"External temperature sensor (of pressure sensor MEMS element)"}] |
| is_reserved | 0.0750 | 1.0 | false | false |
| type_write_read | 0.0583 | 1.0 | R | R |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Truth bit field 2: - bits 0:6

Locations: truth registers[11].field_parts[0].bit_field[1]  registers[15].field_parts[0].bit_field[1].
Judgment:all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| name_or_parameter | 0.0212 | 1.0 | - | - |
| field_description | 0.0586 | 1.0 | Reserved. | Reserved |
| bit_start | 0.2594 | 1.0 | 0 | 0 |
| bit_end | 0.2594 | 1.0 | 6 | 6 |
| bit_width | 0.0583 | 1.0 | 7 | 7 |
| values | 0.2097 | 1.0 | [] | [] |
| is_reserved | 0.0750 | 1.0 | true | true |
| type_write_read | 0.0583 | 1.0 | "" | "" |

\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\)

Field-part aggregation

bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are semantically complete and correct.

| Field-part field | Weight | C | Truth content | v11 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.000000 | TMP_COEF_SRCE | TMP_COEF_SRCE |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":""} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Temperature Coefficients Source, address 28H, reset XXH."} |
| description | 0.0693 | 1.000000 | Temperature coefficient source selection status. | Temperature coefficients source. |
| width_bits | 0.0605 | 1.000000 | 8 | 8 |
| type_write_read | 0.0605 | 1.000000 | R | R |
| bit_field | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: default_value_description C=0.0.

| Logical-register field | Weight | C | Truth comparison target | v11 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.000000 | Coefficient Source | COEF_SRCE |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":""}] | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Temperature coefficients source register."}] |
| register_description | 0.0564 | 1.000000 | States whether the calibration coefficients are based on the ASIC temperature sensor or the pressure-sensor MEMS temperature sensor. | Coefficient Source register (detailed register title TMP_COEF_SRCE). States which internal temperature sensor the calibration coefficients are based on: the ASIC temperature sensor or the MEMS element temperature sensor. The coefficients are only valid for one sensor and it is highly recommended to use the same temperature sensor in the application; this is set up in the Temperature Configuration (TMP_CFG) register (TMP_EXT). |
| width_bits | 0.0590 | 1.000000 | 8 | 8 |
| type_write_read | 0.0590 | 1.000000 | R | R |
| field_parts | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |
| default_value | 0.0667 | 1.000000 | XXH | XXh |
| default_value_description | 0.0334 | 0.000000 | "" | Reset value XXH. |

\(Q(L_16)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.2987*1.000000 + 0.0667*1.000000 + 0.0334*0.000000)/1.0001=0.966700/1.0001=\mathbf{0.966603}\)

## 2. Ground-truth physical-register scores

| Truth physical location | Truth logical / field part | Associated extracted logical register(s) | q_R |
|---|---|---|---:|
| 0x00 (0) | Pressure Data (PRS_Bn) / PRS_B2 | registers[0] (PSR_B2, Q=0.935743) | 0.935743 |
| 0x01 (1) | Pressure Data (PRS_Bn) / PRS_B1 | registers[1] (PSR_B1, Q=0.935743) | 0.935743 |
| 0x02 (2) | Pressure Data (PRS_Bn) / PRS_B0 | registers[2] (PSR_B0, Q=0.935743) | 0.935743 |
| 0x03 (3) | Temperature Data (TMP_Tn) / TMP_B2 | registers[3] (TMP_B2, Q=0.966603) | 0.966603 |
| 0x04 (4) | Temperature Data (TMP_Tn) / TMP_B1 | registers[4] (TMP_B1, Q=0.966603) | 0.966603 |
| 0x05 (5) | Temperature Data (TMP_Tn) / TMP_B0 | registers[5] (TMP_B0, Q=0.966603) | 0.966603 |
| 0x06 (6) | PRS_CFG / PRS_CFG | registers[6] (PRS_CFG, Q=0.966603) | 0.966603 |
| 0x07 (7) | TMP_CFG / TMP_CFG | registers[7] (TMP_CFG, Q=0.965943) | 0.965943 |
| 0x08 (8) | MEAS_CFG / MEAS_CFG | registers[8] (MEAS_CFG, Q=0.966603) | 0.966603 |
| 0x09 (9) | CFG_REG / CFG_REG | registers[9] (CFG_REG, Q=0.966603) | 0.966603 |
| 0x0A (10) | INT_STS / INT_STS | registers[10] (INT_STS, Q=0.966603) | 0.966603 |
| 0x0B (11) | FIFO_STS / FIFO_STS | registers[11] (FIFO_STS, Q=0.966603) | 0.966603 |
| 0x0C (12) | RESET / RESET | registers[12] (RESET, Q=0.966603) | 0.966603 |
| 0x0D (13) | Product and Revision ID (ID) / ID | registers[13] (ID, Q=0.944106) | 0.944106 |
| 0x10 (16) | COEF / c0 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x11 (17) | COEF / c0/c1 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x12 (18) | COEF / c1 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x13 (19) | COEF / c00 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x14 (20) | COEF / c00 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x15 (21) | COEF / c00/c10 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x16 (22) | COEF / c10 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x17 (23) | COEF / c10 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x18 (24) | COEF / c01 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x19 (25) | COEF / c01 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x1A (26) | COEF / c11 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x1B (27) | COEF / c11 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x1C (28) | COEF / c20 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x1D (29) | COEF / c20 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x1E (30) | COEF / c21 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x1F (31) | COEF / c21 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x20 (32) | COEF / c30 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x21 (33) | COEF / c30 | registers[14] (COEF, Q=0.907609) | 0.907609 |
| 0x28 (40) | Coefficient Source / TMP_COEF_SRCE | registers[15] (COEF_SRCE, Q=0.966603) | 0.966603 |

- sum(q_R) = 30.720276633 across 33 truth physical registers.
- Matched physical registers m=33; extra extracted physical registers x=0; extra penalty m/(m+x) = **1.000000000**.
- Final score: S_final=(10/33 * 30.720276633) * (33/(33+0)) = **9.309174737 / 10**.

## 3. Detailed deduction inventory

The inventory below lists every direct scored field with C<1. Recursive bit_field and field_parts values are not additional deductions; their exact bottom-up consequences are shown in each logical-register calculation above.

| # | Exact location | Field | C | Truth content | Extracted content | Specific error |
|---:|---|---|---:|---|---|---|
| 1 | truth registers[0].field_parts[0]  registers[0].field_parts[0] | register_name | 0.0 | PRS_B2 | PSR_B2 | objective name/parameter differs: truth=PRS_B2, extracted=PSR_B2 |
| 2 | truth registers[0]  registers[0] | name | 0.0 | PRS_B2 | PSR_B2 | objective name/parameter differs: truth=PRS_B2, extracted=PSR_B2 |
| 3 | truth registers[0]  registers[0] | default_value_description | 0.0 | "" | Reset state 00h per Register Map and register description. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 4 | truth registers[0].field_parts[1]  registers[1].field_parts[0] | register_name | 0.0 | PRS_B1 | PSR_B1 | objective name/parameter differs: truth=PRS_B1, extracted=PSR_B1 |
| 5 | truth registers[0]  registers[1] | name | 0.0 | PRS_B1 | PSR_B1 | objective name/parameter differs: truth=PRS_B1, extracted=PSR_B1 |
| 6 | truth registers[0]  registers[1] | default_value_description | 0.0 | "" | Reset state 00h. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 7 | truth registers[0].field_parts[2]  registers[2].field_parts[0] | register_name | 0.0 | PRS_B0 | PSR_B0 | objective name/parameter differs: truth=PRS_B0, extracted=PSR_B0 |
| 8 | truth registers[0]  registers[2] | name | 0.0 | PRS_B0 | PSR_B0 | objective name/parameter differs: truth=PRS_B0, extracted=PSR_B0 |
| 9 | truth registers[0]  registers[2] | default_value_description | 0.0 | "" | Reset state 00h. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 10 | truth registers[1]  registers[3] | default_value_description | 0.0 | "" | Reset state 00h. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 11 | truth registers[1]  registers[4] | default_value_description | 0.0 | "" | Reset state 00h. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 12 | truth registers[1]  registers[5] | default_value_description | 0.0 | "" | Reset state 00h. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 13 | truth registers[2]  registers[6] | default_value_description | 0.0 | "" | Reset state 00h. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 14 | truth registers[3].field_parts[0].bit_field[2]  registers[7].field_parts[0].bit_field[2] | name_or_parameter | 0.0 | TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo) | TMP_PRC[2:0] | objective name/parameter differs: truth=TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo), extracted=TMP_PRC[2:0] |
| 15 | truth registers[3]  registers[7] | default_value_description | 0.0 | "" | Reset state 00h. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 16 | truth registers[4]  registers[8] | default_value_description | 0.0 | "" | Reset state C0h (COEF_RDY and SENSOR_RDY set after reset). | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 17 | truth registers[5]  registers[9] | default_value_description | 0.0 | "" | Reset state 00h. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 18 | truth registers[6]  registers[10] | default_value_description | 0.0 | "" | Reset state 00h. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 19 | truth registers[7]  registers[11] | default_value_description | 0.0 | "" | Reset state 00h. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 20 | truth registers[8]  registers[12] | default_value_description | 0.0 | "" | Reset state 00h. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 21 | truth registers[9]  registers[13] | name | 0.0 | Product and Revision ID (ID) | ID | objective name/parameter differs: truth=Product and Revision ID (ID), extracted=ID |
| 22 | truth registers[9]  registers[13] | default_value_description | 0.0 | "" | Reset value 0x10H (Register Map reset state 10h). | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 23 | truth registers[10]  registers[14] | width_bits | 0.0 | 144 | EMPTY | objective width differs or is missing: truth=144, extracted=EMPTY |
| 24 | truth registers[10]  registers[14] | default_value_description | 0.0 | "" | Register Map reset state XXh for the COEF block (0x10-0x21); individual coefficient values are device-specific calibration data. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |
| 25 | truth registers[11]  registers[15] | default_value_description | 0.0 | "" | Reset value XXH. | truth field is explicitly empty, but the extraction adds unsupported content; direct-field comparison therefore gives C=0 |

### Missing and extra physical locations

- No truth physical location is missing.
- No extra extracted physical location.
- No unmatched extracted bit field remains after accepted data-byte splitting and the merged coefficient representation.

## 4. Empty type_write_read audit

- Audited scored logical-register, field-part, and bit-field access-type comparisons: 109.
- Truth/extraction both empty: C=1.0 in 6 comparisons. These cases were explicitly credited and did not enter the deduction inventory.
- Truth empty but extraction nonempty: 0 comparisons; these are inventions and receive C=0.
- Truth concrete but extraction empty: 0 comparisons; these are omissions and receive C=0.
- Both concrete: 103 comparisons; exact matches receive C=1.
- Credited empty/empty locations:
  - truth registers[2].field_parts[0].bit_field[0]  registers[6].field_parts[0].bit_field[0] -> C=1.0.
  - truth registers[4].field_parts[0].bit_field[4]  registers[8].field_parts[0].bit_field[4] -> C=1.0.
  - truth registers[6].field_parts[0].bit_field[0]  registers[10].field_parts[0].bit_field[0] -> C=1.0.
  - truth registers[7].field_parts[0].bit_field[0]  registers[11].field_parts[0].bit_field[0] -> C=1.0.
  - truth registers[8].field_parts[0].bit_field[1]  registers[12].field_parts[0].bit_field[1] -> C=1.0.
  - truth registers[11].field_parts[0].bit_field[1]  registers[15].field_parts[0].bit_field[1] -> C=1.0.
- Truth-empty/nonempty type_write_read cases: 0; after the truth update, all COEF logical-register, field-part, and bit-field access types match the extracted R values.

## 5. Invented-field and representation check

- The separate extra-physical-register penalty is applied exactly once through x; an extra physical address is not silently matched to a nearby truth address.
- The six pressure/temperature byte entries are an accepted split of the two multi-address truth logical registers; the split itself is not penalized.
- The single COEF entry is an accepted merged representation of all 18 truth physical coefficient parts. Its 20 extracted coefficient bit fields align with the truth ranges; they are not invented extra bits.
- Reserved-bit name/description emptiness is permitted by AGENTS.md, and v11 reserved ranges have the same boundaries and reserved classification as truth.
- COEF_SRCE is treated as the canonical shorthand for Coefficient Source only at the logical-register name field; its physical field part is compared strictly as TMP_COEF_SRCE and matches.
- No unmatched extracted bit field remains after the accepted-equivalence checks.
- No fields outside the scored AGENTS.md field lists are included in the numerical score.

## 6. Calculation conclusion

All 16 extracted logical-register items were reviewed, including the accepted split and merged representations; every field part and every bit field is shown bottom-up above. The final DPS368 v11_0 score is **9.309174737 / 10**.

