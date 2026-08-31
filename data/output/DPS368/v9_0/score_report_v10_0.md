# DPS368 v10.0 detailed score - revised AGENTS.md rules

## 1. Scoring basis

- n=33 unique truth physical registers are scored by numeric address plus bank and page; hexadecimal and decimal address strings are the same numeric location.
- Every extracted logical register is calculated bottom-up: truth bit fields -> field part -> logical register Q(L). The merged data and COEF representations are evaluated over every covered truth physical part; grouping alone is not penalized.
- q_R is the mean of every associated extracted logical-register score; missing truth physical registers receive q_R=0.
- Objective facts are strict: addresses, bank/page, widths, bit boundaries, reserved classification, access types, and value codes. COEF_SRCE is accepted as the canonical logical-name shorthand for Coefficient Source. Descriptions are judged semantically; functional paraphrases receive C=1.
- The rounded AHP weights sum to 0.9999 for bit fields, 1.0000 for field parts, and 1.0001 for logical registers; formulas below use these denominators.
- type_write_read rule: both empty receives C=1.0; invented values receive C=0; concrete truth values must match exactly. Empty/empty cases are credited and are not deduction errors.

## Extracted logical register 1: Pressure Data

v10 registers[0]; truth association: truth registers[0] (Pressure Data (PRS_Bn)).
Associated physical locations: 0x00 (0), 0x01 (1), 0x02 (2).

### Bottom layer: bit fields, then field parts

#### Field part 1: PRS_B2 at 0x00 (0)

Locations: truth registers[0].field_parts[0]  registers[0].field_parts[0].

Truth bit field 1: PRS[23:16] bits 0:7

Locations: truth registers[0].field_parts[0].bit_field[0]  registers[0].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | PRS[23:16] | PRS[23:16] |
| `field_description` | 0.0586 | 1.0 | MSB of 24 bit 2's complement pressure data. | MSB of 24 bit 2´s complement pressure data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: register_name C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | PRS_B2 | PSR_B2 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Highest byte of the 24-bit pressure value."} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"PSR_B2 - Pressure (MSB data)"} |
| `description` | 0.0693 | 1.000000 | Highest byte; pressure MSB data. | Pressure (MSB data) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=0.972000/1.0000=\\mathbf{0.972000}\\)

#### Field part 2: PRS_B1 at 0x01 (1)

Locations: truth registers[0].field_parts[1]  registers[0].field_parts[1].

Truth bit field 1: PRS[15:8] bits 0:7

Locations: truth registers[0].field_parts[1].bit_field[0]  registers[0].field_parts[1].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | PRS[15:8] | PRS[15:8] |
| `field_description` | 0.0586 | 1.0 | Middle byte of 24 bit 2's complement pressure data. | LSB of 24 bit 2´s complement pressure data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: register_name C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | PRS_B1 | PSR_B1 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"Middle byte of the 24-bit pressure value."} | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"PSR_B1 - Pressure (LSB data)"} |
| `description` | 0.0693 | 1.000000 | Middle byte of the pressure value. | Pressure (LSB data) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=0.972000/1.0000=\\mathbf{0.972000}\\)

#### Field part 3: PRS_B0 at 0x02 (2)

Locations: truth registers[0].field_parts[2]  registers[0].field_parts[2].

Truth bit field 1: PRS[7:0] bits 0:7

Locations: truth registers[0].field_parts[2].bit_field[0]  registers[0].field_parts[2].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | PRS[7:0] | PRS[7:0] |
| `field_description` | 0.0586 | 1.0 | XLSB of 24 bit 2's complement pressure data. | XLSB of 24 bit 2´s complement pressure data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: register_name C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | PRS_B0 | PSR_B0 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"Lowest byte of the 24-bit pressure value."} | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"PSR_B0 - Pressure (XLSB data)"} |
| `description` | 0.0693 | 1.000000 | Lowest byte; pressure XLSB data. | Pressure (XLSB data) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=0.972000/1.0000=\\mathbf{0.972000}\\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.972000, 0.972000, 0.972000) = **0.972000**.
Direct judgment: name C=0.0; default_value_description C=0.0

| Logical-register field | Weight | C | Truth comparison target | v10 content |
| --- | ---: | ---: | --- | --- |
| `name` | 0.0225 | 0.000000 | Pressure Data (PRS_Bn) | Pressure Data |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Highest byte of the 24-bit pressure value."},{"hex":"0x01","decimal":"1","bank":"","page":"","description":"Middle byte of the 24-bit pressure value."},{"hex":"0x02","decimal":"2","bank":"","page":"","description":"Lowest byte of the 24-bit pressure value."}] | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"PSR_B2 - Pressure (MSB data)"},{"hex":"0x01","decimal":"1","bank":"","page":"","description":"PSR_B1 - Pressure (LSB data)"},{"hex":"0x02","decimal":"2","bank":"","page":"","description":"PSR_B0 - Pressure (XLSB data)"}] |
| `register_description` | 0.0564 | 1.000000 | Contains the 24-bit 2's complement pressure measurement value; when FIFO is enabled, it contains FIFO pressure and/or temperature results. | Contains the 24-bit 2's complement pressure measurement value. If the FIFO is enabled, the register contains the FIFO pressure and/or temperature results. Otherwise, the register contains the pressure measurement results and will not be cleared after read. |
| `width_bits` | 0.0590 | 1.000000 | 24 | 24 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `default_value` | 0.0667 | 1.000000 | 0x000000 | 0x000000 |
| `default_value_description` | 0.0334 | 0.000000 | "" | Reset state 00h for each byte. |
| `field_parts` | 0.2987 | 0.972000 | mean(0.972000, 0.972000, 0.972000) | mean(0.972000, 0.972000, 0.972000) |

\\(Q(L_1)=(0.0225*0.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.0667*1.000000 + 0.0334*0.000000 + 0.2987*0.972000)/1.0001=0.935836/1.0001=\\mathbf{0.935743}\\)

## Extracted logical register 2: Temperature Data

v10 registers[1]; truth association: truth registers[1] (Temperature Data (TMP_Tn)).
Associated physical locations: 0x03 (3), 0x04 (4), 0x05 (5).

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_B2 at 0x03 (3)

Locations: truth registers[1].field_parts[0]  registers[1].field_parts[0].

Truth bit field 1: TMP[23:16] bits 0:7

Locations: truth registers[1].field_parts[0].bit_field[0]  registers[1].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | TMP[23:16] | TMP[23:16] |
| `field_description` | 0.0586 | 1.0 | MSB of 24 bit 2's complement temperature data. | MSB of 24 bit 2´s complement temperature data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 1.000000 | TMP_B2 | TMP_B2 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"Highest byte of the 24-bit temperature value."} | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"TMP_B2 - Temperature (MSB data)"} |
| `description` | 0.0693 | 1.000000 | Highest byte; temperature MSB data. | Temperature (MSB data) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\\mathbf{1.000000}\\)

#### Field part 2: TMP_B1 at 0x04 (4)

Locations: truth registers[1].field_parts[1]  registers[1].field_parts[1].

Truth bit field 1: TMP[15:8] bits 0:7

Locations: truth registers[1].field_parts[1].bit_field[0]  registers[1].field_parts[1].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | TMP[15:8] | TMP[15:8] |
| `field_description` | 0.0586 | 1.0 | Middle byte of 24 bit 2's complement temperature data. | LSB of 24 bit 2´s complement temperature data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 1.000000 | TMP_B1 | TMP_B1 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Middle byte of the 24-bit temperature value."} | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"TMP_B1 - Temperature (LSB data)"} |
| `description` | 0.0693 | 1.000000 | Middle byte of the temperature value. | Temperature (LSB data) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\\mathbf{1.000000}\\)

#### Field part 3: TMP_B0 at 0x05 (5)

Locations: truth registers[1].field_parts[2]  registers[1].field_parts[2].

Truth bit field 1: TMP[7:0] bits 0:7

Locations: truth registers[1].field_parts[2].bit_field[0]  registers[1].field_parts[2].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | TMP[7:0] | TMP[7:0] |
| `field_description` | 0.0586 | 1.0 | XLSB of 24 bit 2's complement temperature data. | XLSB of 24 bit 2´s complement temperature data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 1.000000 | TMP_B0 | TMP_B0 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Lowest byte of the 24-bit temperature value."} | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"TMP_B0 - Temperature (XLSB data)"} |
| `description` | 0.0693 | 1.000000 | Lowest byte; temperature XLSB data. | Temperature (XLSB data) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\\mathbf{1.000000}\\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: name C=0.0; default_value_description C=0.0

| Logical-register field | Weight | C | Truth comparison target | v10 content |
| --- | ---: | ---: | --- | --- |
| `name` | 0.0225 | 0.000000 | Temperature Data (TMP_Tn) | Temperature Data |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"Highest byte of the 24-bit temperature value."},{"hex":"0x04","decimal":"4","bank":"","page":"","description":"Middle byte of the 24-bit temperature value."},{"hex":"0x05","decimal":"5","bank":"","page":"","description":"Lowest byte of the 24-bit temperature value."}] | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"TMP_B2 - Temperature (MSB data)"},{"hex":"0x04","decimal":"4","bank":"","page":"","description":"TMP_B1 - Temperature (LSB data)"},{"hex":"0x05","decimal":"5","bank":"","page":"","description":"TMP_B0 - Temperature (XLSB data)"}] |
| `register_description` | 0.0564 | 1.000000 | Contains the 24-bit 2's complement temperature measurement value and is not cleared after read; FIFO operation can affect the result data. | Contains the 24-bit 2's complement temperature measurement value (unless the FIFO is enabled) and will not be cleared after the read. |
| `width_bits` | 0.0590 | 1.000000 | 24 | 24 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `default_value` | 0.0667 | 1.000000 | 0x000000 | 0x000000 |
| `default_value_description` | 0.0334 | 0.000000 | "" | Reset state 00h for each byte. |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000, 1.000000, 1.000000) | mean(1.000000, 1.000000, 1.000000) |

\\(Q(L_2)=(0.0225*0.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.0667*1.000000 + 0.0334*0.000000 + 0.2987*1.000000)/1.0001=0.944200/1.0001=\\mathbf{0.944106}\\)

## Extracted logical register 3: PRS_CFG

v10 registers[2]; truth association: truth registers[2] (PRS_CFG).
Associated physical locations: 0x06 (6).

### Bottom layer: bit fields, then field parts

#### Field part 1: PRS_CFG at 0x06 (6)

Locations: truth registers[2].field_parts[0]  registers[2].field_parts[0].

Truth bit field 1: - bits 7:7

Locations: truth registers[2].field_parts[0].bit_field[0]  registers[2].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 2: PM_RATE[2:0] bits 4:6

Locations: truth registers[2].field_parts[0].bit_field[1]  registers[2].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | PM_RATE[2:0] | PM_RATE[2:0] |
| `field_description` | 0.0586 | 1.0 | Pressure measurement rate in Background mode. | Pressure measurement rate. Applicable for measurements in Background mode only. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"000","value_description":"1 measurement per second"},{"value":"001","value_description":"2 measurements per second"},{"value":"010","value_description":"4 measurements per second"},{"value":"011","value_description":"8 measurements per second"},{"value":"100","value_description":"16 measurements per second"},{"value":"101","value_description":"32 measurements per second"},{"value":"110","value_description":"64 measurements per second"},{"value":"111","value_description":"128 measurements per second"}] | [{"value":"000","value_description":"1 measurements pr. sec."},{"value":"001","value_description":"2 measurements pr. sec."},{"value":"010","value_description":"4 measurements pr. sec."},{"value":"011","value_description":"8 measurements pr. sec."},{"value":"100","value_description":"16 measurements pr. sec."},{"value":"101","value_description":"32 measurements pr. sec."},{"value":"110","value_description":"64 measurements pr. sec."},{"value":"111","value_description":"128 measurements pr. sec."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 3: PM_PRC[3:0] bits 0:3

Locations: truth registers[2].field_parts[0].bit_field[2]  registers[2].field_parts[0].bit_field[2].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | PM_PRC[3:0] | PM_PRC[3:0] |
| `field_description` | 0.0586 | 1.0 | Pressure oversampling rate; settings above 8 times require use with the pressure result bit shift. | Pressure oversampling rate. Note: Use in combination with a bit shift. See Interrupt and FIFO configuration (CFG_REG) register. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard)"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times (High Precision)"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] | [{"value":"0000","value_description":"Single (Low Precision)"},{"value":"0001","value_description":"2 times (Low Power)"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times (Standard)"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times (High Precision)"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 1.000000 | PRS_CFG | PRS_CFG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x06","decimal":"6","bank":"","page":"","description":""} | {"hex":"0x06","decimal":"6","bank":"","page":"","description":"Pressure measurement configuration"} |
| `description` | 0.0693 | 1.000000 | Pressure measurement configuration. | Pressure measurement configuration |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\\mathbf{1.000000}\\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v10 content |
| --- | ---: | ---: | --- | --- |
| `name` | 0.0225 | 1.000000 | PRS_CFG | PRS_CFG |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":""}] | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":"Pressure measurement configuration"}] |
| `register_description` | 0.0564 | 1.000000 | Configures pressure measurement rate and resolution. | Configuration of pressure measurement rate (PM_RATE) and resolution (PM_PRC). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `default_value` | 0.0667 | 1.000000 | 00H | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |

\\(Q(L_3)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.0667*1.000000 + 0.0334*1.000000 + 0.2987*1.000000)/1.0001=1.000100/1.0001=\\mathbf{1.000000}\\)

## Extracted logical register 4: TMP_CFG

v10 registers[3]; truth association: truth registers[3] (TMP_CFG).
Associated physical locations: 0x07 (7).

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_CFG at 0x07 (7)

Locations: truth registers[3].field_parts[0]  registers[3].field_parts[0].

Truth bit field 1: TMP_EXT bits 7:7

Locations: truth registers[3].field_parts[0].bit_field[0]  registers[3].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | TMP_EXT | TMP_EXT |
| `field_description` | 0.0586 | 1.0 | Selects the temperature sensor used for measurement. | Temperature measurement sensor selection. Note: It is highly recommended to use the same temperature sensor as the source of the calibration coefficients. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Internal sensor in ASIC"},{"value":"1","value_description":"External sensor in pressure sensor MEMS element"}] | [{"value":"0","value_description":"Internal sensor (in ASIC)"},{"value":"1","value_description":"External sensor (in pressure sensor MEMS element)"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 2: TMP_RATE[2:0] bits 4:6

Locations: truth registers[3].field_parts[0].bit_field[1]  registers[3].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | TMP_RATE[2:0] | TMP_RATE[2:0] |
| `field_description` | 0.0586 | 1.0 | Temperature measurement rate in Background mode. | Temperature measurement rate. Applicable for measurements in Background mode only. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"000","value_description":"1 measurement per second"},{"value":"001","value_description":"2 measurements per second"},{"value":"010","value_description":"4 measurements per second"},{"value":"011","value_description":"8 measurements per second"},{"value":"100","value_description":"16 measurements per second"},{"value":"101","value_description":"32 measurements per second"},{"value":"110","value_description":"64 measurements per second"},{"value":"111","value_description":"128 measurements per second"}] | [{"value":"000","value_description":"1 measurement pr. sec."},{"value":"001","value_description":"2 measurements pr. sec."},{"value":"010","value_description":"4 measurements pr. sec."},{"value":"011","value_description":"8 measurements pr. sec."},{"value":"100","value_description":"16 measurements pr. sec."},{"value":"101","value_description":"32 measurements pr. sec."},{"value":"110","value_description":"64 measurements pr. sec."},{"value":"111","value_description":"128 measurements pr. sec."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 3: TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo) bits 0:3

Locations: truth registers[3].field_parts[0].bit_field[2]  registers[3].field_parts[0].bit_field[2].
Judgment: name_or_parameter C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 0.0 | TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo) | TMP_PRC[2:0] |
| `field_description` | 0.0586 | 1.0 | Temperature oversampling and precision. | Temperature oversampling (precision). Note: Following are optional, and may not be relevant. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [{"value":"0000","value_description":"Single (Default), measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] | [{"value":"0000","value_description":"single (Default) - Measurement time 3.6 ms"},{"value":"0001","value_description":"2 times"},{"value":"0010","value_description":"4 times"},{"value":"0011","value_description":"8 times"},{"value":"0100","value_description":"16 times"},{"value":"0101","value_description":"32 times"},{"value":"0110","value_description":"64 times"},{"value":"0111","value_description":"128 times"},{"value":"1xxx","value_description":"Reserved"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*0.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.978700/0.9999=\\mathbf{0.978798}\\)

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 0.978798) = **0.992933**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 1.000000 | TMP_CFG | TMP_CFG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} | {"hex":"0x07","decimal":"7","bank":"","page":"","description":"Temperature measurement configuration"} |
| `description` | 0.0693 | 1.000000 | Temperature measurement configuration. | Temperature measurement configuration |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.992933 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.992933)/1.0000=0.997789/1.0000=\\mathbf{0.997789}\\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.997789) = **0.997789**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v10 content |
| --- | ---: | ---: | --- | --- |
| `name` | 0.0225 | 1.000000 | TMP_CFG | TMP_CFG |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":""}] | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":"Temperature measurement configuration"}] |
| `register_description` | 0.0564 | 1.000000 | Configures temperature measurement rate and resolution. | Configuration of temperature measurement rate (TMP_RATE) and resolution (TMP_PRC). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `default_value` | 0.0667 | 1.000000 | 00H | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |
| `field_parts` | 0.2987 | 0.997789 | mean(0.997789) | mean(0.997789) |

\\(Q(L_4)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.0667*1.000000 + 0.0334*1.000000 + 0.2987*0.997789)/1.0001=0.999439/1.0001=\\mathbf{0.999340}\\)

## Extracted logical register 5: MEAS_CFG

v10 registers[4]; truth association: truth registers[4] (MEAS_CFG).
Associated physical locations: 0x08 (8).

### Bottom layer: bit fields, then field parts

#### Field part 1: MEAS_CFG at 0x08 (8)

Locations: truth registers[4].field_parts[0]  registers[4].field_parts[0].

Truth bit field 1: COEF_RDY bits 7:7

Locations: truth registers[4].field_parts[0].bit_field[0]  registers[4].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | COEF_RDY | COEF_RDY |
| `field_description` | 0.0586 | 1.0 | Indicates whether coefficients have been loaded into the coefficient registers after start-up. | Coefficients will be read to the Coefficients Registers after start-up. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Coefficients are not available yet"},{"value":"1","value_description":"Coefficients are available"}] | [{"value":"0","value_description":"Coefficients are not available yet."},{"value":"1","value_description":"Coefficients are available."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 2: SENSOR_RDY bits 6:6

Locations: truth registers[4].field_parts[0].bit_field[1]  registers[4].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | SENSOR_RDY | SENSOR_RDY |
| `field_description` | 0.0586 | 1.0 | Indicates completion of pressure sensor self-initialization after start-up. | The pressure sensor is running through self initialization after start-up. It is recommend not to start measurements until the sensor has completed the self initialization. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Sensor initialization not complete"},{"value":"1","value_description":"Sensor initialization complete"}] | [{"value":"0","value_description":"Sensor initialization not complete"},{"value":"1","value_description":"Sensor initialization complete"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 3: TMP_RDY bits 5:5

Locations: truth registers[4].field_parts[0].bit_field[2]  registers[4].field_parts[0].bit_field[2].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | TMP_RDY | TMP_RDY |
| `field_description` | 0.0586 | 1.0 | Temperature measurement ready status; cleared when the temperature measurement is read. | Temperature measurement ready. Cleared when temperature measurement is read. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"New temperature measurement is ready"}] | [{"value":"1","value_description":"New temperature measurement is ready."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 4: PRS_RDY bits 4:4

Locations: truth registers[4].field_parts[0].bit_field[3]  registers[4].field_parts[0].bit_field[3].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | PRS_RDY | PRS_RDY |
| `field_description` | 0.0586 | 1.0 | Pressure measurement ready status; cleared when the pressure measurement is read. | Pressure measurement ready. Cleared when pressurement measurement is read. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"New pressure measurement is ready"}] | [{"value":"1","value_description":"New pressure measurement is ready."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 5: - bits 3:3

Locations: truth registers[4].field_parts[0].bit_field[4]  registers[4].field_parts[0].bit_field[4].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 6: MEAS_CTRL bits 0:2

Locations: truth registers[4].field_parts[0].bit_field[5]  registers[4].field_parts[0].bit_field[5].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | MEAS_CTRL | MEAS_CTRL |
| `field_description` | 0.0586 | 1.0 | Sets the measurement mode and type. | Set measurement mode and type. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"000","value_description":"Standby: idle or stop background measurement"},{"value":"001","value_description":"Command mode: pressure measurement"},{"value":"010","value_description":"Command mode: temperature measurement"},{"value":"011","value_description":"Not available"},{"value":"100","value_description":"Not available"},{"value":"101","value_description":"Background mode: continuous pressure measurement"},{"value":"110","value_description":"Background mode: continuous temperature measurement"},{"value":"111","value_description":"Background mode: continuous pressure and temperature measurement"}] | [{"value":"000","value_description":"Idle / Stop background measurement"},{"value":"001","value_description":"Pressure measurement"},{"value":"010","value_description":"Temperature measurement"},{"value":"011","value_description":"na"},{"value":"100","value_description":"na"},{"value":"101","value_description":"Continuous pressure measurement"},{"value":"110","value_description":"Continuous temperature measurement"},{"value":"111","value_description":"Continuous pressure and temperature measurement"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 1.000000 | MEAS_CFG | MEAS_CFG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x08","decimal":"8","bank":"","page":"","description":""} | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"Measurement configuration"} |
| `description` | 0.0693 | 1.000000 | Measurement configuration and readiness status. | Measurement configuration |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\\mathbf{1.000000}\\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v10 content |
| --- | ---: | ---: | --- | --- |
| `name` | 0.0225 | 1.000000 | MEAS_CFG | MEAS_CFG |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":""}] | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":"Measurement configuration"}] |
| `register_description` | 0.0564 | 1.000000 | Sets the measurement operating mode and reports sensor, coefficient, pressure, and temperature readiness. | Setup measurement mode. Contains coefficient ready, sensor ready, temperature ready, and pressure ready flags. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `default_value` | 0.0667 | 1.000000 | C0H | 0xC0 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |

\\(Q(L_5)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.0667*1.000000 + 0.0334*1.000000 + 0.2987*1.000000)/1.0001=1.000100/1.0001=\\mathbf{1.000000}\\)

## Extracted logical register 6: CFG_REG

v10 registers[5]; truth association: truth registers[5] (CFG_REG).
Associated physical locations: 0x09 (9).

### Bottom layer: bit fields, then field parts

#### Field part 1: CFG_REG at 0x09 (9)

Locations: truth registers[5].field_parts[0]  registers[5].field_parts[0].

Truth bit field 1: INT_HL bits 7:7

Locations: truth registers[5].field_parts[0].bit_field[0]  registers[5].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | INT_HL | INT_HL |
| `field_description` | 0.0586 | 1.0 | Interrupt active level on the SDO pin. | Interrupt (on SDO pin) active level. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Active low"},{"value":"1","value_description":"Active high"}] | [{"value":"0","value_description":"Active low."},{"value":"1","value_description":"Active high."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 2: INT_FIFO bits 6:6

Locations: truth registers[5].field_parts[0].bit_field[1]  registers[5].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | INT_FIFO | INT_FIFO |
| `field_description` | 0.0586 | 1.0 | Controls interrupt generation when the FIFO is full. | Generate interrupt when the FIFO is full. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 3: INT_TMP bits 5:5

Locations: truth registers[5].field_parts[0].bit_field[2]  registers[5].field_parts[0].bit_field[2].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | INT_TMP | INT_TMP |
| `field_description` | 0.0586 | 1.0 | Controls interrupt generation when a temperature measurement is ready. | Generate interrupt when a temperature measurement is ready. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 4: INT_PRS bits 4:4

Locations: truth registers[5].field_parts[0].bit_field[3]  registers[5].field_parts[0].bit_field[3].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | INT_PRS | INT_PRS |
| `field_description` | 0.0586 | 1.0 | Controls interrupt generation when a pressure measurement is ready. | Generate interrupt when a pressure measurement is ready. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 5: T_SHIFT bits 3:3

Locations: truth registers[5].field_parts[0].bit_field[4]  registers[5].field_parts[0].bit_field[4].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | T_SHIFT | T_SHIFT |
| `field_description` | 0.0586 | 1.0 | Temperature result bit shift; must be enabled when oversampling is greater than 8 times. | Temperature result bit-shift. Must be set to '1' when the oversampling rate is >8 times. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No shift"},{"value":"1","value_description":"Shift result right in data register"}] | [{"value":"0","value_description":"no shift."},{"value":"1","value_description":"shift result right in data register."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 6: P_SHIFT bits 2:2

Locations: truth registers[5].field_parts[0].bit_field[5]  registers[5].field_parts[0].bit_field[5].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | P_SHIFT | P_SHIFT |
| `field_description` | 0.0586 | 1.0 | Pressure result bit shift; must be enabled when oversampling is greater than 8 times. | Pressure result bit-shift. Must be set to '1' when the oversampling rate is >8 times. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No shift"},{"value":"1","value_description":"Shift result right in data register"}] | [{"value":"0","value_description":"no shift."},{"value":"1","value_description":"shift result right in data register."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 7: FIFO_EN bits 1:1

Locations: truth registers[5].field_parts[0].bit_field[6]  registers[5].field_parts[0].bit_field[6].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_EN | FIFO_EN |
| `field_description` | 0.0586 | 1.0 | Enables the FIFO. | Enable the FIFO. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable"},{"value":"1","value_description":"Enable"}] | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 8: SPI_MODE bits 0:0

Locations: truth registers[5].field_parts[0].bit_field[7]  registers[5].field_parts[0].bit_field[7].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | SPI_MODE | SPI_MODE |
| `field_description` | 0.0586 | 1.0 | Selects the SPI interface mode. | Set SPI mode. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"4-wire interface"},{"value":"1","value_description":"3-wire interface"}] | [{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 1.000000 | CFG_REG | CFG_REG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x09","decimal":"9","bank":"","page":"","description":""} | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"Configuration register"} |
| `description` | 0.0693 | 1.000000 | Interrupt, result-shift, FIFO, and SPI configuration. | Configuration register |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*1.000000)/1.0000=1.000000/1.0000=\\mathbf{1.000000}\\)

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v10 content |
| --- | ---: | ---: | --- | --- |
| `name` | 0.0225 | 1.000000 | CFG_REG | CFG_REG |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x09","decimal":"9","bank":"","page":"","description":""}] | [{"hex":"0x09","decimal":"9","bank":"","page":"","description":"Configuration register"}] |
| `register_description` | 0.0564 | 1.000000 | Configures interrupts, measurement data shifts, FIFO enable, and SPI interface mode. | Configuration of interrupts, measurement data shift, and FIFO enable. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `default_value` | 0.0667 | 1.000000 | 00H | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |
| `field_parts` | 0.2987 | 1.000000 | mean(1.000000) | mean(1.000000) |

\\(Q(L_6)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.0667*1.000000 + 0.0334*1.000000 + 0.2987*1.000000)/1.0001=1.000100/1.0001=\\mathbf{1.000000}\\)

## Extracted logical register 7: INT_STS

v10 registers[6]; truth association: truth registers[6] (INT_STS).
Associated physical locations: 0x0A (10).

### Bottom layer: bit fields, then field parts

#### Field part 1: INT_STS at 0x0A (10)

Locations: truth registers[6].field_parts[0]  registers[6].field_parts[0].

Truth bit field 1: - bits 3:7

Locations: truth registers[6].field_parts[0].bit_field[0]  registers[6].field_parts[0].bit_field[0].
Judgment: bit_start C=0.0; bit_end C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 0.0 | 3 | 7 |
| `bit_end` | 0.2594 | 0.0 | 7 | 3 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.481100/0.9999=\\mathbf{0.481148}\\)

Truth bit field 2: INT_FIFO_FULL bits 2:2

Locations: truth registers[6].field_parts[0].bit_field[1]  registers[6].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | INT_FIFO_FULL | INT_FIFO_FULL |
| `field_description` | 0.0586 | 1.0 | FIFO interrupt status. | Status of FIFO interrupt |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 3: INT_TMP bits 1:1

Locations: truth registers[6].field_parts[0].bit_field[2]  registers[6].field_parts[0].bit_field[2].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | INT_TMP | INT_TMP |
| `field_description` | 0.0586 | 1.0 | Temperature measurement interrupt status. | Status of temperature measurement interrupt |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 4: INT_PRS bits 0:0

Locations: truth registers[6].field_parts[0].bit_field[3]  registers[6].field_parts[0].bit_field[3].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | INT_PRS | INT_PRS |
| `field_description` | 0.0586 | 1.0 | Pressure measurement interrupt status. | Status of pressure measurement interrupt |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] | [{"value":"0","value_description":"Interrupt not active"},{"value":"1","value_description":"Interrupt active"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

**Field-part aggregation**

bit_field correctness = mean(0.481148, 1.000000, 1.000000, 1.000000) = **0.870287**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 1.000000 | INT_STS | INT_STS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":""} | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Interrupt status"} |
| `description` | 0.0693 | 1.000000 | Interrupt status. | Interrupt status |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.870287 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.870287)/1.0000=0.959413/1.0000=\\mathbf{0.959413}\\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.959413) = **0.959413**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v10 content |
| --- | ---: | ---: | --- | --- |
| `name` | 0.0225 | 1.000000 | INT_STS | INT_STS |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":""}] | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Interrupt status"}] |
| `register_description` | 0.0564 | 1.000000 | Reports FIFO, temperature measurement, and pressure measurement interrupt status; cleared on read. | Interrupt status register. The register is cleared on read. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `default_value` | 0.0667 | 1.000000 | 00H | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |
| `field_parts` | 0.2987 | 0.959413 | mean(0.959413) | mean(0.959413) |

\\(Q(L_7)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.0667*1.000000 + 0.0334*1.000000 + 0.2987*0.959413)/1.0001=0.987977/1.0001=\\mathbf{0.987878}\\)

## Extracted logical register 8: FIFO_STS

v10 registers[7]; truth association: truth registers[7] (FIFO_STS).
Associated physical locations: 0x0B (11).

### Bottom layer: bit fields, then field parts

#### Field part 1: FIFO_STS at 0x0B (11)

Locations: truth registers[7].field_parts[0]  registers[7].field_parts[0].

Truth bit field 1: - bits 2:7

Locations: truth registers[7].field_parts[0].bit_field[0]  registers[7].field_parts[0].bit_field[0].
Judgment: bit_start C=0.0; bit_end C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 0.0 | 2 | 7 |
| `bit_end` | 0.2594 | 0.0 | 7 | 2 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.481100/0.9999=\\mathbf{0.481148}\\)

Truth bit field 2: FIFO_FULL bits 1:1

Locations: truth registers[7].field_parts[0].bit_field[1]  registers[7].field_parts[0].bit_field[1].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_FULL | FIFO_FULL |
| `field_description` | 0.0586 | 1.0 | FIFO full status. | FIFO full status. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"FIFO is not full"},{"value":"1","value_description":"FIFO is full"}] | [{"value":"0","value_description":"The FIFO is not full"},{"value":"1","value_description":"The FIFO is full"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 3: FIFO_EMPTY bits 0:0

Locations: truth registers[7].field_parts[0].bit_field[2]  registers[7].field_parts[0].bit_field[2].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_EMPTY | FIFO_EMPTY |
| `field_description` | 0.0586 | 1.0 | FIFO empty status. | FIFO empty status. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"FIFO is not empty"},{"value":"1","value_description":"FIFO is empty"}] | [{"value":"0","value_description":"The FIFO is not empty"},{"value":"1","value_description":"The FIFO is empty"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

**Field-part aggregation**

bit_field correctness = mean(0.481148, 1.000000, 1.000000) = **0.827049**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 1.000000 | FIFO_STS | FIFO_STS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":""} | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"FIFO status register"} |
| `description` | 0.0693 | 1.000000 | FIFO status. | FIFO status register |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.827049 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.827049)/1.0000=0.945884/1.0000=\\mathbf{0.945884}\\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.945884) = **0.945884**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v10 content |
| --- | ---: | ---: | --- | --- |
| `name` | 0.0225 | 1.000000 | FIFO_STS | FIFO_STS |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x0B","decimal":"11","bank":"","page":"","description":""}] | [{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"FIFO status register"}] |
| `register_description` | 0.0564 | 1.000000 | Reports whether the FIFO is full or empty. | FIFO status register. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `default_value` | 0.0667 | 1.000000 | 00H | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |
| `field_parts` | 0.2987 | 0.945884 | mean(0.945884) | mean(0.945884) |

\\(Q(L_8)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.0667*1.000000 + 0.0334*1.000000 + 0.2987*0.945884)/1.0001=0.983935/1.0001=\\mathbf{0.983837}\\)

## Extracted logical register 9: RESET

v10 registers[8]; truth association: truth registers[8] (RESET).
Associated physical locations: 0x0C (12).

### Bottom layer: bit fields, then field parts

#### Field part 1: RESET at 0x0C (12)

Locations: truth registers[8].field_parts[0]  registers[8].field_parts[0].

Truth bit field 1: FIFO_FLUSH bits 7:7

Locations: truth registers[8].field_parts[0].bit_field[0]  registers[8].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_FLUSH | FIFO_FLUSH |
| `field_description` | 0.0586 | 1.0 | Flushes the FIFO; after reading all FIFO data, write 1 to clear old data. | FIFO flush. After reading out all data from the FIFO, write '1' to clear all old data. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Empty FIFO"}] | [{"value":"1","value_description":"Empty FIFO"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | W | W |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 2: - bits 4:6

Locations: truth registers[8].field_parts[0].bit_field[1]  registers[8].field_parts[0].bit_field[1].
Judgment: bit_start C=0.0; bit_end C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 0.0 | 4 | 6 |
| `bit_end` | 0.2594 | 0.0 | 6 | 4 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.481100/0.9999=\\mathbf{0.481148}\\)

Truth bit field 3: SOFT_RST bits 0:3

Locations: truth registers[8].field_parts[0].bit_field[2]  registers[8].field_parts[0].bit_field[2].
Judgment: bit_start C=0.0; bit_end C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | SOFT_RST | SOFT_RST |
| `field_description` | 0.0586 | 1.0 | Generates a soft reset using the same sequence as power-on reset. | Write '1001' to generate a soft reset. A soft reset will run though the same sequences as in power-on reset. |
| `bit_start` | 0.2594 | 0.0 | 0 | 3 |
| `bit_end` | 0.2594 | 0.0 | 3 | 0 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [{"value":"1001","value_description":"Generate a soft reset"}] | [{"value":"1001","value_description":"Generate soft reset"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | W | W |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.481100/0.9999=\\mathbf{0.481148}\\)

**Field-part aggregation**

bit_field correctness = mean(1.000000, 0.481148, 0.481148) = **0.654099**.
Direct judgment: all direct field-part fields are correct.

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 1.000000 | RESET | RESET |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":""} | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"FIFO flush and soft reset"} |
| `description` | 0.0693 | 1.000000 | FIFO flush and soft reset control. | FIFO flush and soft reset |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | W | W |
| `bit_field` | 0.3129 | 0.654099 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*1.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.654099)/1.0000=0.891767/1.0000=\\mathbf{0.891767}\\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.891767) = **0.891767**.
Direct judgment: all direct logical-register fields are correct.

| Logical-register field | Weight | C | Truth comparison target | v10 content |
| --- | ---: | ---: | --- | --- |
| `name` | 0.0225 | 1.000000 | RESET | RESET |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":""}] | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"FIFO flush and soft reset"}] |
| `register_description` | 0.0564 | 1.000000 | Flushes the FIFO or generates a soft reset. | Flush FIFO or generate soft reset. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | W | W |
| `default_value` | 0.0667 | 1.000000 | 00H | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |
| `field_parts` | 0.2987 | 0.891767 | mean(0.891767) | mean(0.891767) |

\\(Q(L_9)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.0667*1.000000 + 0.0334*1.000000 + 0.2987*0.891767)/1.0001=0.967771/1.0001=\\mathbf{0.967674}\\)

## Extracted logical register 10: Product ID

v10 registers[9]; truth association: truth registers[9] (Product and Revision ID (ID)).
Associated physical locations: 0x0D (13).

### Bottom layer: bit fields, then field parts

#### Field part 1: ID at 0x0D (13)

Locations: truth registers[9].field_parts[0]  registers[9].field_parts[0].

Truth bit field 1: REV_ID bits 4:7

Locations: truth registers[9].field_parts[0].bit_field[0]  registers[9].field_parts[0].bit_field[0].
Judgment: bit_start C=0.0; bit_end C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | REV_ID | REV_ID |
| `field_description` | 0.0586 | 1.0 | Revision ID. | Revision ID |
| `bit_start` | 0.2594 | 0.0 | 4 | 7 |
| `bit_end` | 0.2594 | 0.0 | 7 | 4 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.481100/0.9999=\\mathbf{0.481148}\\)

Truth bit field 2: PROD_ID bits 0:3

Locations: truth registers[9].field_parts[0].bit_field[1]  registers[9].field_parts[0].bit_field[1].
Judgment: bit_start C=0.0; bit_end C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | PROD_ID | PROD_ID |
| `field_description` | 0.0586 | 1.0 | Product ID. | Product ID |
| `bit_start` | 0.2594 | 0.0 | 0 | 3 |
| `bit_end` | 0.2594 | 0.0 | 3 | 0 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.481100/0.9999=\\mathbf{0.481148}\\)

**Field-part aggregation**

bit_field correctness = mean(0.481148, 0.481148) = **0.481148**.
Direct judgment: register_name C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | ID | Product ID |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":""} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Product and revision ID"} |
| `description` | 0.0693 | 1.000000 | Product and revision identification. | Product and revision ID |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.481148 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.481148)/1.0000=0.809651/1.0000=\\mathbf{0.809651}\\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.809651) = **0.809651**.
Direct judgment: name C=0.0

| Logical-register field | Weight | C | Truth comparison target | v10 content |
| --- | ---: | ---: | --- | --- |
| `name` | 0.0225 | 0.000000 | Product and Revision ID (ID) | Product ID |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":""}] | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Product and revision ID"}] |
| `register_description` | 0.0564 | 1.000000 | Contains the product and revision identifiers. | Product and Revision ID. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `default_value` | 0.0667 | 1.000000 | 0x10 / 10H (0x10H in datasheet is typo) | 0x10 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |
| `field_parts` | 0.2987 | 0.809651 | mean(0.809651) | mean(0.809651) |

\\(Q(L_10)=(0.0225*0.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.0667*1.000000 + 0.0334*1.000000 + 0.2987*0.809651)/1.0001=0.920743/1.0001=\\mathbf{0.920651}\\)

## Extracted logical register 11: COEF

v10 registers[10]; truth association: truth registers[10] (COEF).
Associated physical locations: 0x10 (16), 0x11 (17), 0x12 (18), 0x13 (19), 0x14 (20), 0x15 (21), 0x16 (22), 0x17 (23), 0x18 (24), 0x19 (25), 0x1A (26), 0x1B (27), 0x1C (28), 0x1D (29), 0x1E (30), 0x1F (31), 0x20 (32), 0x21 (33).

### Bottom layer: bit fields, then field parts

#### Field part 1: c0 at 0x10 (16)

Locations: truth registers[10].field_parts[0]  registers[10].field_parts[0].

Truth bit field 1: c0 [11:4] bits 0:7

Locations: truth registers[10].field_parts[0].bit_field[0]  registers[10].field_parts[0].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c0 [11:4] | c0 [11:4] |
| `field_description` | 0.0586 | 0.0 | Bits 11:4 of coefficient c0. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c0 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"c0 bits 11:4."} | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"c0 [11:4]"} |
| `description` | 0.0693 | 1.000000 | Upper eight bits of coefficient c0. | c0 [11:4] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 2: c0/c1 at 0x11 (17)

Locations: truth registers[10].field_parts[1]  registers[10].field_parts[1].

Truth bit field 1: c0 [3:0] bits 4:7

Locations: truth registers[10].field_parts[1].bit_field[0]  registers[10].field_parts[1].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c0 [3:0] | c0 [3:0] |
| `field_description` | 0.0586 | 0.0 | Bits 3:0 of coefficient c0. | "" |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

Truth bit field 2: c1 [11:8] bits 0:3

Locations: truth registers[10].field_parts[1].bit_field[1]  registers[10].field_parts[1].bit_field[1].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c1 [11:8] | c1 [11:8] |
| `field_description` | 0.0586 | 0.0 | Bits 11:8 of coefficient c1. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088, 0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c0/c1 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Contains c0 bits 3:0 and c1 bits 11:8."} | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"c0 [3:0] / c1 [11:8]"} |
| `description` | 0.0693 | 1.000000 | Lower four bits of c0 and upper four bits of c1. | c0 [3:0] / c1 [11:8] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 3: c1 at 0x12 (18)

Locations: truth registers[10].field_parts[2]  registers[10].field_parts[2].

Truth bit field 1: c1[7:0] bits 0:7

Locations: truth registers[10].field_parts[2].bit_field[0]  registers[10].field_parts[2].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c1[7:0] | c1[7:0] |
| `field_description` | 0.0586 | 0.0 | Bits 7:0 of coefficient c1. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c1 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"c1 bits 7:0."} | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"c1[7:0]"} |
| `description` | 0.0693 | 1.000000 | Lower eight bits of coefficient c1. | c1[7:0] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 4: c00 at 0x13 (19)

Locations: truth registers[10].field_parts[3]  registers[10].field_parts[3].

Truth bit field 1: c00 [19:12] bits 0:7

Locations: truth registers[10].field_parts[3].bit_field[0]  registers[10].field_parts[3].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c00 [19:12] | c00 [19:12] |
| `field_description` | 0.0586 | 0.0 | Bits 19:12 of coefficient c00. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c00 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"c00 bits 19:12."} | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"c00 [19:12]"} |
| `description` | 0.0693 | 1.000000 | Upper eight bits of coefficient c00. | c00 [19:12] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 5: c00 at 0x14 (20)

Locations: truth registers[10].field_parts[4]  registers[10].field_parts[4].

Truth bit field 1: c00 [11:4] bits 0:7

Locations: truth registers[10].field_parts[4].bit_field[0]  registers[10].field_parts[4].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c00 [11:4] | c00 [11:4] |
| `field_description` | 0.0586 | 0.0 | Bits 11:4 of coefficient c00. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c00 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"c00 bits 11:4."} | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"c00 [11:4]"} |
| `description` | 0.0693 | 1.000000 | Middle eight bits of coefficient c00. | c00 [11:4] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 6: c00/c10 at 0x15 (21)

Locations: truth registers[10].field_parts[5]  registers[10].field_parts[5].

Truth bit field 1: c00 [3:0] bits 4:7

Locations: truth registers[10].field_parts[5].bit_field[0]  registers[10].field_parts[5].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c00 [3:0] | c00 [3:0] |
| `field_description` | 0.0586 | 0.0 | Bits 3:0 of coefficient c00. | "" |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

Truth bit field 2: c10 [19:16] bits 0:3

Locations: truth registers[10].field_parts[5].bit_field[1]  registers[10].field_parts[5].bit_field[1].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c10 [19:16] | c10 [19:16] |
| `field_description` | 0.0586 | 0.0 | Bits 19:16 of coefficient c10. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088, 0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c00/c10 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Contains c00 bits 3:0 and c10 bits 19:16."} | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"c00 [3:0] / c10 [19:16]"} |
| `description` | 0.0693 | 1.000000 | Lower four bits of c00 and upper four bits of c10. | c00 [3:0] / c10 [19:16] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 7: c10 at 0x16 (22)

Locations: truth registers[10].field_parts[6]  registers[10].field_parts[6].

Truth bit field 1: c10 [15:8] bits 0:7

Locations: truth registers[10].field_parts[6].bit_field[0]  registers[10].field_parts[6].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c10 [15:8] | c10 [15:8] |
| `field_description` | 0.0586 | 0.0 | Bits 15:8 of coefficient c10. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c10 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"c10 bits 15:8."} | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"c10 [15:8]"} |
| `description` | 0.0693 | 1.000000 | Middle eight bits of coefficient c10. | c10 [15:8] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 8: c10 at 0x17 (23)

Locations: truth registers[10].field_parts[7]  registers[10].field_parts[7].

Truth bit field 1: c10 [7:0] bits 0:7

Locations: truth registers[10].field_parts[7].bit_field[0]  registers[10].field_parts[7].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c10 [7:0] | c10 [7:0] |
| `field_description` | 0.0586 | 0.0 | Bits 7:0 of coefficient c10. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c10 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"c10 bits 7:0."} | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"c10 [7:0]"} |
| `description` | 0.0693 | 1.000000 | Lower eight bits of coefficient c10. | c10 [7:0] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 9: c01 at 0x18 (24)

Locations: truth registers[10].field_parts[8]  registers[10].field_parts[8].

Truth bit field 1: c01 [15:8] bits 0:7

Locations: truth registers[10].field_parts[8].bit_field[0]  registers[10].field_parts[8].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c01 [15:8] | c01 [15:8] |
| `field_description` | 0.0586 | 0.0 | Bits 15:8 of coefficient c01. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c01 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"c01 bits 15:8."} | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"c01 [15:8]"} |
| `description` | 0.0693 | 1.000000 | Upper eight bits of coefficient c01. | c01 [15:8] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 10: c01 at 0x19 (25)

Locations: truth registers[10].field_parts[9]  registers[10].field_parts[9].

Truth bit field 1: c01 [7:0] bits 0:7

Locations: truth registers[10].field_parts[9].bit_field[0]  registers[10].field_parts[9].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c01 [7:0] | c01 [7:0] |
| `field_description` | 0.0586 | 0.0 | Bits 7:0 of coefficient c01. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c01 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x19","decimal":"25","bank":"","page":"","description":"c01 bits 7:0."} | {"hex":"0x19","decimal":"25","bank":"","page":"","description":"c01 [7:0]"} |
| `description` | 0.0693 | 1.000000 | Lower eight bits of coefficient c01. | c01 [7:0] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 11: c11 at 0x1A (26)

Locations: truth registers[10].field_parts[10]  registers[10].field_parts[10].

Truth bit field 1: c11 [15:8] bits 0:7

Locations: truth registers[10].field_parts[10].bit_field[0]  registers[10].field_parts[10].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c11 [15:8] | c11 [15:8] |
| `field_description` | 0.0586 | 0.0 | Bits 15:8 of coefficient c11. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c11 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"c11 bits 15:8."} | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"c11 [15:8]"} |
| `description` | 0.0693 | 1.000000 | Upper eight bits of coefficient c11. | c11 [15:8] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 12: c11 at 0x1B (27)

Locations: truth registers[10].field_parts[11]  registers[10].field_parts[11].

Truth bit field 1: c11 [7:0] bits 0:7

Locations: truth registers[10].field_parts[11].bit_field[0]  registers[10].field_parts[11].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c11 [7:0] | c11 [7:0] |
| `field_description` | 0.0586 | 0.0 | Bits 7:0 of coefficient c11. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c11 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"c11 bits 7:0."} | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"c11 [7:0]"} |
| `description` | 0.0693 | 1.000000 | Lower eight bits of coefficient c11. | c11 [7:0] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 13: c20 at 0x1C (28)

Locations: truth registers[10].field_parts[12]  registers[10].field_parts[12].

Truth bit field 1: c20 [15:8] bits 0:7

Locations: truth registers[10].field_parts[12].bit_field[0]  registers[10].field_parts[12].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c20 [15:8] | c20 [15:8] |
| `field_description` | 0.0586 | 0.0 | Bits 15:8 of coefficient c20. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c20 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"c20 bits 15:8."} | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"c20 [15:8]"} |
| `description` | 0.0693 | 1.000000 | Upper eight bits of coefficient c20. | c20 [15:8] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 14: c20 at 0x1D (29)

Locations: truth registers[10].field_parts[13]  registers[10].field_parts[13].

Truth bit field 1: c20 [7:0] bits 0:7

Locations: truth registers[10].field_parts[13].bit_field[0]  registers[10].field_parts[13].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c20 [7:0] | c20 [7:0] |
| `field_description` | 0.0586 | 0.0 | Bits 7:0 of coefficient c20. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c20 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"c20 bits 7:0."} | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"c20 [7:0]"} |
| `description` | 0.0693 | 1.000000 | Lower eight bits of coefficient c20. | c20 [7:0] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 15: c21 at 0x1E (30)

Locations: truth registers[10].field_parts[14]  registers[10].field_parts[14].

Truth bit field 1: c21 [15:8] bits 0:7

Locations: truth registers[10].field_parts[14].bit_field[0]  registers[10].field_parts[14].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c21 [15:8] | c21 [15:8] |
| `field_description` | 0.0586 | 0.0 | Bits 15:8 of coefficient c21. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c21 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"c21 bits 15:8."} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"c21 [15:8]"} |
| `description` | 0.0693 | 1.000000 | Upper eight bits of coefficient c21. | c21 [15:8] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 16: c21 at 0x1F (31)

Locations: truth registers[10].field_parts[15]  registers[10].field_parts[15].

Truth bit field 1: c21 [7:0] bits 0:7

Locations: truth registers[10].field_parts[15].bit_field[0]  registers[10].field_parts[15].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c21 [7:0] | c21 [7:0] |
| `field_description` | 0.0586 | 0.0 | Bits 7:0 of coefficient c21. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c21 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"c21 bits 7:0."} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"c21 [7:0]"} |
| `description` | 0.0693 | 1.000000 | Lower eight bits of coefficient c21. | c21 [7:0] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 17: c30 at 0x20 (32)

Locations: truth registers[10].field_parts[16]  registers[10].field_parts[16].

Truth bit field 1: c30 [15:8] bits 0:7

Locations: truth registers[10].field_parts[16].bit_field[0]  registers[10].field_parts[16].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c30 [15:8] | c30 [15:8] |
| `field_description` | 0.0586 | 0.0 | Bits 15:8 of coefficient c30. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c30 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"c30 bits 15:8."} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"c30 [15:8]"} |
| `description` | 0.0693 | 1.000000 | Upper eight bits of coefficient c30. | c30 [15:8] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

#### Field part 18: c30 at 0x21 (33)

Locations: truth registers[10].field_parts[17]  registers[10].field_parts[17].

Truth bit field 1: c30 [7:0] bits 0:7

Locations: truth registers[10].field_parts[17].bit_field[0]  registers[10].field_parts[17].bit_field[0].
Judgment: field_description C=0.0; type_write_read C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | c30 [7:0] | c30 [7:0] |
| `field_description` | 0.0586 | 0.0 | Bits 7:0 of coefficient c30. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*0.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*0.000000)/0.9999=0.883000/0.9999=\\mathbf{0.883088}\\)

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**.
Direct judgment: register_name C=0.0; type_write_read C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | c30 | COEF |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"c30 bits 7:0."} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"c30 [7:0]"} |
| `description` | 0.0693 | 1.000000 | Lower eight bits of coefficient c30. | c30 [7:0] |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.000000 | R | "" |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*0.000000 + 0.3129*0.883088)/1.0000=0.874918/1.0000=\\mathbf{0.874918}\\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918) = **0.874918**.
Direct judgment: type_write_read C=0.0; default_value_description C=0.0

| Logical-register field | Weight | C | Truth comparison target | v10 content |
| --- | ---: | ---: | --- | --- |
| `name` | 0.0225 | 1.000000 | COEF | COEF |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x10","decimal":"16","bank":"","page":"","description":"c0 bits 11:4."},{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Contains c0 bits 3:0 and c1 bits 11:8."},{"hex":"0x12","decimal":"18","bank":"","page":"","description":"c1 bits 7:0."},{"hex":"0x13","decimal":"19","bank":"","page":"","description":"c00 bits 19:12."},{"hex":"0x14","decimal":"20","bank":"","page":"","description":"c00 bits 11:4."},{"hex":"0x15","decimal":"21","bank":"","page":"","description":"Contains c00 bits 3:0 and c10 bits 19:16."},{"hex":"0x16","decimal":"22","bank":"","page":"","description":"c10 bits 15:8."},{"hex":"0x17","decimal":"23","bank":"","page":"","description":"c10 bits 7:0."},{"hex":"0x18","decimal":"24","bank":"","page":"","description":"c01 bits 15:8."},{"hex":"0x19","decimal":"25","bank":"","page":"","description":"c01 bits 7:0."},{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"c11 bits 15:8."},{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"c11 bits 7:0."},{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"c20 bits 15:8."},{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"c20 bits 7:0."},{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"c21 bits 15:8."},{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"c21 bits 7:0."},{"hex":"0x20","decimal":"32","bank":"","page":"","description":"c30 bits 15:8."},{"hex":"0x21","decimal":"33","bank":"","page":"","description":"c30 bits 7:0."}] | [{"hex":"0x10","decimal":"16","bank":"","page":"","description":"c0 [11:4]"},{"hex":"0x11","decimal":"17","bank":"","page":"","description":"c0 [3:0] / c1 [11:8]"},{"hex":"0x12","decimal":"18","bank":"","page":"","description":"c1[7:0]"},{"hex":"0x13","decimal":"19","bank":"","page":"","description":"c00 [19:12]"},{"hex":"0x14","decimal":"20","bank":"","page":"","description":"c00 [11:4]"},{"hex":"0x15","decimal":"21","bank":"","page":"","description":"c00 [3:0] / c10 [19:16]"},{"hex":"0x16","decimal":"22","bank":"","page":"","description":"c10 [15:8]"},{"hex":"0x17","decimal":"23","bank":"","page":"","description":"c10 [7:0]"},{"hex":"0x18","decimal":"24","bank":"","page":"","description":"c01 [15:8]"},{"hex":"0x19","decimal":"25","bank":"","page":"","description":"c01 [7:0]"},{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"c11 [15:8]"},{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"c11 [7:0]"},{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"c20 [15:8]"},{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"c20 [7:0]"},{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"c21 [15:8]"},{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"c21 [7:0]"},{"hex":"0x20","decimal":"32","bank":"","page":"","description":"c30 [15:8]"},{"hex":"0x21","decimal":"33","bank":"","page":"","description":"c30 [7:0]"}] |
| `register_description` | 0.0564 | 1.000000 | Contains 2's complement calibration coefficients used to calculate compensated pressure and temperature values. | The Calibration Coefficients register contains the 2's complement coefficients used to calculate compensated pressure and temperature values. Documentation provides decimal conversion formulas (e.g., C0, C20). |
| `width_bits` | 0.0590 | 1.000000 | 144 | 144 |
| `type_write_read` | 0.0590 | 0.000000 | R | "" |
| `default_value` | 0.0667 | 1.000000 | XXh | XXh |
| `default_value_description` | 0.0334 | 0.000000 | "" | Reset state XXh for each byte. |
| `field_parts` | 0.2987 | 0.874918 | mean(0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918) | mean(0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918, 0.874918) |

\\(Q(L_11)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*0.000000 + 0.0667*1.000000 + 0.0334*0.000000 + 0.2987*0.874918)/1.0001=0.870338/1.0001=\\mathbf{0.870251}\\)

## Extracted logical register 12: COEF_SRCE

v10 registers[11]; truth association: truth registers[11] (Coefficient Source).
Associated physical locations: 0x28 (40).

### Bottom layer: bit fields, then field parts

#### Field part 1: TMP_COEF_SRCE at 0x28 (40)

Locations: truth registers[11].field_parts[0]  registers[11].field_parts[0].

Truth bit field 1: TMP_COEF_SRCE bits 7:7

Locations: truth registers[11].field_parts[0].bit_field[0]  registers[11].field_parts[0].bit_field[0].
Judgment: all eight scored bit-field fields are correct.

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | TMP_COEF_SRCE | TMP_COEF_SRCE |
| `field_description` | 0.0586 | 1.0 | Identifies the temperature sensor on which the calibration coefficients are based. | Temperature coefficients are based on internal or external sensor. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Internal temperature sensor of ASIC"},{"value":"1","value_description":"External temperature sensor of pressure sensor MEMS element"}] | [{"value":"0","value_description":"Internal temperature sensor (of ASIC)"},{"value":"1","value_description":"External temperature sensor (of pressure sensor MEMS element)"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*1.000000 + 0.2594*1.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.999900/0.9999=\\mathbf{1.000000}\\)

Truth bit field 2: - bits 0:6

Locations: truth registers[11].field_parts[0].bit_field[1]  registers[11].field_parts[0].bit_field[1].
Judgment: bit_start C=0.0; bit_end C=0.0

| Scored field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved |
| `bit_start` | 0.2594 | 0.0 | 0 | 6 |
| `bit_end` | 0.2594 | 0.0 | 6 | 0 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\\(Q_BF=(0.0212*1.000000 + 0.0586*1.000000 + 0.2594*0.000000 + 0.2594*0.000000 + 0.0583*1.000000 + 0.2097*1.000000 + 0.0750*1.000000 + 0.0583*1.000000)/0.9999=0.481100/0.9999=\\mathbf{0.481148}\\)

**Field-part aggregation**

bit_field correctness = mean(1.000000, 0.481148) = **0.740574**.
Direct judgment: register_name C=0.0

| Field-part field | Weight | C | Truth content | v10 content |
| --- | ---: | ---: | --- | --- |
| `register_name` | 0.0280 | 0.000000 | TMP_COEF_SRCE | COEF_SRCE |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":""} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Temperature Coefficients Source"} |
| `description` | 0.0693 | 1.000000 | Temperature coefficient source selection status. | Temperature Coefficients Source |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.740574 | truth bit-field set | extracted bit-field set |

\\(Q_FP=(0.0280*0.000000 + 0.4688*1.000000 + 0.0693*1.000000 + 0.0605*1.000000 + 0.0605*1.000000 + 0.3129*0.740574)/1.0000=0.890826/1.0000=\\mathbf{0.890826}\\)

### Extracted logical-register aggregation

field_parts correctness = mean(0.890826) = **0.890826**.
Direct judgment: default_value_description C=0.0

| Logical-register field | Weight | C | Truth comparison target | v10 content |
| --- | ---: | ---: | --- | --- |
| `name` | 0.0225 | 1.000000 | Coefficient Source | COEF_SRCE |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":""}] | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Temperature Coefficients Source"}] |
| `register_description` | 0.0564 | 1.000000 | States whether the calibration coefficients are based on the ASIC temperature sensor or the pressure-sensor MEMS temperature sensor. | States which internal temperature sensor the calibration coefficients are based on. The coefficients are only valid for one sensor and it is highly recommended to use the same temperature sensor in the application. This is set-up in the Temperature Configuration register. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `default_value` | 0.0667 | 1.000000 | XXH | XXh |
| `default_value_description` | 0.0334 | 0.000000 | "" | Reset value XXh. |
| `field_parts` | 0.2987 | 0.890826 | mean(0.890826) | mean(0.890826) |

\\(Q(L_12)=(0.0225*1.000000 + 0.4044*1.000000 + 0.0564*1.000000 + 0.0590*1.000000 + 0.0590*1.000000 + 0.0667*1.000000 + 0.0334*0.000000 + 0.2987*0.890826)/1.0001=0.934090/1.0001=\\mathbf{0.933996}\\)

## 2. Ground-truth physical-register scores

| Truth physical location | Truth logical / field part | Associated extracted logical register(s) | q_R |
| --- | --- | --- | ---: |
| 0x00 (0) | Pressure Data (PRS_Bn) / PRS_B2 | registers[0] (Pressure Data, Q=0.935743) | 0.935743 |
| 0x01 (1) | Pressure Data (PRS_Bn) / PRS_B1 | registers[0] (Pressure Data, Q=0.935743) | 0.935743 |
| 0x02 (2) | Pressure Data (PRS_Bn) / PRS_B0 | registers[0] (Pressure Data, Q=0.935743) | 0.935743 |
| 0x03 (3) | Temperature Data (TMP_Tn) / TMP_B2 | registers[1] (Temperature Data, Q=0.944106) | 0.944106 |
| 0x04 (4) | Temperature Data (TMP_Tn) / TMP_B1 | registers[1] (Temperature Data, Q=0.944106) | 0.944106 |
| 0x05 (5) | Temperature Data (TMP_Tn) / TMP_B0 | registers[1] (Temperature Data, Q=0.944106) | 0.944106 |
| 0x06 (6) | PRS_CFG / PRS_CFG | registers[2] (PRS_CFG, Q=1.000000) | 1.000000 |
| 0x07 (7) | TMP_CFG / TMP_CFG | registers[3] (TMP_CFG, Q=0.999340) | 0.999340 |
| 0x08 (8) | MEAS_CFG / MEAS_CFG | registers[4] (MEAS_CFG, Q=1.000000) | 1.000000 |
| 0x09 (9) | CFG_REG / CFG_REG | registers[5] (CFG_REG, Q=1.000000) | 1.000000 |
| 0x0A (10) | INT_STS / INT_STS | registers[6] (INT_STS, Q=0.987878) | 0.987878 |
| 0x0B (11) | FIFO_STS / FIFO_STS | registers[7] (FIFO_STS, Q=0.983837) | 0.983837 |
| 0x0C (12) | RESET / RESET | registers[8] (RESET, Q=0.967674) | 0.967674 |
| 0x0D (13) | Product and Revision ID (ID) / ID | registers[9] (Product ID, Q=0.920651) | 0.920651 |
| 0x10 (16) | COEF / c0 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x11 (17) | COEF / c0/c1 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x12 (18) | COEF / c1 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x13 (19) | COEF / c00 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x14 (20) | COEF / c00 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x15 (21) | COEF / c00/c10 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x16 (22) | COEF / c10 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x17 (23) | COEF / c10 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x18 (24) | COEF / c01 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x19 (25) | COEF / c01 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x1A (26) | COEF / c11 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x1B (27) | COEF / c11 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x1C (28) | COEF / c20 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x1D (29) | COEF / c20 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x1E (30) | COEF / c21 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x1F (31) | COEF / c21 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x20 (32) | COEF / c30 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x21 (33) | COEF / c30 | registers[10] (COEF, Q=0.870251) | 0.870251 |
| 0x28 (40) | Coefficient Source / TMP_COEF_SRCE | registers[11] (COEF_SRCE, Q=0.933996) | 0.933996 |

- `sum(q_R)` q_R = 30.097440293 across 33 truth physical registers.
- Matched physical registers `m=33`; extra extracted physical registers `x=0`; extra penalty `33/(33+0)` = **1.000000000**.
- Final score: `S_final=(10/33 * 30.097440293) * (33/(33+0))` = **9.120436453 / 10**.

## 3. Detailed deduction inventory

| # | Exact location | Field | C | Truth content | Extracted content | Specific error |
| ---: | --- | --- | ---: | --- | --- | --- |
| 1 | truth registers[0].field_parts[0]  registers[0].field_parts[0] | register_name | 0.000000 | PRS_B2 | PSR_B2 | objective name/parameter differs: truth=PRS_B2, extracted=PSR_B2 |
| 2 | truth registers[0].field_parts[1]  registers[0].field_parts[1] | register_name | 0.000000 | PRS_B1 | PSR_B1 | objective name/parameter differs: truth=PRS_B1, extracted=PSR_B1 |
| 3 | truth registers[0].field_parts[2]  registers[0].field_parts[2] | register_name | 0.000000 | PRS_B0 | PSR_B0 | objective name/parameter differs: truth=PRS_B0, extracted=PSR_B0 |
| 4 | truth registers[0]  registers[0] | name | 0.000000 | Pressure Data (PRS_Bn) | Pressure Data | objective name/parameter differs: truth=Pressure Data (PRS_Bn), extracted=Pressure Data |
| 5 | truth registers[0]  registers[0] | default_value_description | 0.000000 | "" | Reset state 00h for each byte. | default-value description is missing or incorrect: truth="", extracted=Reset state 00h for each byte. |
| 6 | truth registers[0]  registers[0] | field_parts | 0.972000 | recursive | aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above |
| 7 | truth registers[1]  registers[1] | name | 0.000000 | Temperature Data (TMP_Tn) | Temperature Data | objective name/parameter differs: truth=Temperature Data (TMP_Tn), extracted=Temperature Data |
| 8 | truth registers[1]  registers[1] | default_value_description | 0.000000 | "" | Reset state 00h for each byte. | default-value description is missing or incorrect: truth="", extracted=Reset state 00h for each byte. |
| 9 | truth registers[3].field_parts[0].bit_field[2]  registers[3].field_parts[0].bit_field[2] | name_or_parameter | 0.000000 | TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo) | TMP_PRC[2:0] | objective name/parameter differs: truth=TMP_PRC[3:0](TMP_PRC[2:0] in datasheet is typo), extracted=TMP_PRC[2:0] |
| 10 | truth registers[3].field_parts[0]  registers[3].field_parts[0] | bit_field | 0.992933 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 11 | truth registers[3]  registers[3] | field_parts | 0.997789 | recursive | aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above |
| 12 | truth registers[6].field_parts[0].bit_field[0]  registers[6].field_parts[0].bit_field[0] | bit_start | 0.000000 | 3 | 7 | objective bit boundary differs: truth=3, extracted=7 |
| 13 | truth registers[6].field_parts[0].bit_field[0]  registers[6].field_parts[0].bit_field[0] | bit_end | 0.000000 | 7 | 3 | objective bit boundary differs: truth=7, extracted=3 |
| 14 | truth registers[6].field_parts[0]  registers[6].field_parts[0] | bit_field | 0.870287 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 15 | truth registers[6]  registers[6] | field_parts | 0.959413 | recursive | aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above |
| 16 | truth registers[7].field_parts[0].bit_field[0]  registers[7].field_parts[0].bit_field[0] | bit_start | 0.000000 | 2 | 7 | objective bit boundary differs: truth=2, extracted=7 |
| 17 | truth registers[7].field_parts[0].bit_field[0]  registers[7].field_parts[0].bit_field[0] | bit_end | 0.000000 | 7 | 2 | objective bit boundary differs: truth=7, extracted=2 |
| 18 | truth registers[7].field_parts[0]  registers[7].field_parts[0] | bit_field | 0.827049 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 19 | truth registers[7]  registers[7] | field_parts | 0.945884 | recursive | aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above |
| 20 | truth registers[8].field_parts[0].bit_field[1]  registers[8].field_parts[0].bit_field[1] | bit_start | 0.000000 | 4 | 6 | objective bit boundary differs: truth=4, extracted=6 |
| 21 | truth registers[8].field_parts[0].bit_field[1]  registers[8].field_parts[0].bit_field[1] | bit_end | 0.000000 | 6 | 4 | objective bit boundary differs: truth=6, extracted=4 |
| 22 | truth registers[8].field_parts[0].bit_field[2]  registers[8].field_parts[0].bit_field[2] | bit_start | 0.000000 | 0 | 3 | objective bit boundary differs: truth=0, extracted=3 |
| 23 | truth registers[8].field_parts[0].bit_field[2]  registers[8].field_parts[0].bit_field[2] | bit_end | 0.000000 | 3 | 0 | objective bit boundary differs: truth=3, extracted=0 |
| 24 | truth registers[8].field_parts[0]  registers[8].field_parts[0] | bit_field | 0.654099 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 25 | truth registers[8]  registers[8] | field_parts | 0.891767 | recursive | aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above |
| 26 | truth registers[9].field_parts[0].bit_field[0]  registers[9].field_parts[0].bit_field[0] | bit_start | 0.000000 | 4 | 7 | objective bit boundary differs: truth=4, extracted=7 |
| 27 | truth registers[9].field_parts[0].bit_field[0]  registers[9].field_parts[0].bit_field[0] | bit_end | 0.000000 | 7 | 4 | objective bit boundary differs: truth=7, extracted=4 |
| 28 | truth registers[9].field_parts[0].bit_field[1]  registers[9].field_parts[0].bit_field[1] | bit_start | 0.000000 | 0 | 3 | objective bit boundary differs: truth=0, extracted=3 |
| 29 | truth registers[9].field_parts[0].bit_field[1]  registers[9].field_parts[0].bit_field[1] | bit_end | 0.000000 | 3 | 0 | objective bit boundary differs: truth=3, extracted=0 |
| 30 | truth registers[9].field_parts[0]  registers[9].field_parts[0] | register_name | 0.000000 | ID | Product ID | objective name/parameter differs: truth=ID, extracted=Product ID |
| 31 | truth registers[9].field_parts[0]  registers[9].field_parts[0] | bit_field | 0.481148 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 32 | truth registers[9]  registers[9] | name | 0.000000 | Product and Revision ID (ID) | Product ID | objective name/parameter differs: truth=Product and Revision ID (ID), extracted=Product ID |
| 33 | truth registers[9]  registers[9] | field_parts | 0.809651 | recursive | aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above |
| 34 | truth registers[10].field_parts[0].bit_field[0]  registers[10].field_parts[0].bit_field[0] | field_description | 0.000000 | Bits 11:4 of coefficient c0. | "" | objective field differs: truth=Bits 11:4 of coefficient c0., extracted="" |
| 35 | truth registers[10].field_parts[0].bit_field[0]  registers[10].field_parts[0].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 36 | truth registers[10].field_parts[0]  registers[10].field_parts[0] | register_name | 0.000000 | c0 | COEF | objective name/parameter differs: truth=c0, extracted=COEF |
| 37 | truth registers[10].field_parts[0]  registers[10].field_parts[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 38 | truth registers[10].field_parts[0]  registers[10].field_parts[0] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 39 | truth registers[10].field_parts[1].bit_field[0]  registers[10].field_parts[1].bit_field[0] | field_description | 0.000000 | Bits 3:0 of coefficient c0. | "" | objective field differs: truth=Bits 3:0 of coefficient c0., extracted="" |
| 40 | truth registers[10].field_parts[1].bit_field[0]  registers[10].field_parts[1].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 41 | truth registers[10].field_parts[1].bit_field[1]  registers[10].field_parts[1].bit_field[1] | field_description | 0.000000 | Bits 11:8 of coefficient c1. | "" | objective field differs: truth=Bits 11:8 of coefficient c1., extracted="" |
| 42 | truth registers[10].field_parts[1].bit_field[1]  registers[10].field_parts[1].bit_field[1] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 43 | truth registers[10].field_parts[1]  registers[10].field_parts[1] | register_name | 0.000000 | c0/c1 | COEF | objective name/parameter differs: truth=c0/c1, extracted=COEF |
| 44 | truth registers[10].field_parts[1]  registers[10].field_parts[1] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 45 | truth registers[10].field_parts[1]  registers[10].field_parts[1] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 46 | truth registers[10].field_parts[2].bit_field[0]  registers[10].field_parts[2].bit_field[0] | field_description | 0.000000 | Bits 7:0 of coefficient c1. | "" | objective field differs: truth=Bits 7:0 of coefficient c1., extracted="" |
| 47 | truth registers[10].field_parts[2].bit_field[0]  registers[10].field_parts[2].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 48 | truth registers[10].field_parts[2]  registers[10].field_parts[2] | register_name | 0.000000 | c1 | COEF | objective name/parameter differs: truth=c1, extracted=COEF |
| 49 | truth registers[10].field_parts[2]  registers[10].field_parts[2] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 50 | truth registers[10].field_parts[2]  registers[10].field_parts[2] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 51 | truth registers[10].field_parts[3].bit_field[0]  registers[10].field_parts[3].bit_field[0] | field_description | 0.000000 | Bits 19:12 of coefficient c00. | "" | objective field differs: truth=Bits 19:12 of coefficient c00., extracted="" |
| 52 | truth registers[10].field_parts[3].bit_field[0]  registers[10].field_parts[3].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 53 | truth registers[10].field_parts[3]  registers[10].field_parts[3] | register_name | 0.000000 | c00 | COEF | objective name/parameter differs: truth=c00, extracted=COEF |
| 54 | truth registers[10].field_parts[3]  registers[10].field_parts[3] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 55 | truth registers[10].field_parts[3]  registers[10].field_parts[3] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 56 | truth registers[10].field_parts[4].bit_field[0]  registers[10].field_parts[4].bit_field[0] | field_description | 0.000000 | Bits 11:4 of coefficient c00. | "" | objective field differs: truth=Bits 11:4 of coefficient c00., extracted="" |
| 57 | truth registers[10].field_parts[4].bit_field[0]  registers[10].field_parts[4].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 58 | truth registers[10].field_parts[4]  registers[10].field_parts[4] | register_name | 0.000000 | c00 | COEF | objective name/parameter differs: truth=c00, extracted=COEF |
| 59 | truth registers[10].field_parts[4]  registers[10].field_parts[4] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 60 | truth registers[10].field_parts[4]  registers[10].field_parts[4] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 61 | truth registers[10].field_parts[5].bit_field[0]  registers[10].field_parts[5].bit_field[0] | field_description | 0.000000 | Bits 3:0 of coefficient c00. | "" | objective field differs: truth=Bits 3:0 of coefficient c00., extracted="" |
| 62 | truth registers[10].field_parts[5].bit_field[0]  registers[10].field_parts[5].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 63 | truth registers[10].field_parts[5].bit_field[1]  registers[10].field_parts[5].bit_field[1] | field_description | 0.000000 | Bits 19:16 of coefficient c10. | "" | objective field differs: truth=Bits 19:16 of coefficient c10., extracted="" |
| 64 | truth registers[10].field_parts[5].bit_field[1]  registers[10].field_parts[5].bit_field[1] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 65 | truth registers[10].field_parts[5]  registers[10].field_parts[5] | register_name | 0.000000 | c00/c10 | COEF | objective name/parameter differs: truth=c00/c10, extracted=COEF |
| 66 | truth registers[10].field_parts[5]  registers[10].field_parts[5] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 67 | truth registers[10].field_parts[5]  registers[10].field_parts[5] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 68 | truth registers[10].field_parts[6].bit_field[0]  registers[10].field_parts[6].bit_field[0] | field_description | 0.000000 | Bits 15:8 of coefficient c10. | "" | objective field differs: truth=Bits 15:8 of coefficient c10., extracted="" |
| 69 | truth registers[10].field_parts[6].bit_field[0]  registers[10].field_parts[6].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 70 | truth registers[10].field_parts[6]  registers[10].field_parts[6] | register_name | 0.000000 | c10 | COEF | objective name/parameter differs: truth=c10, extracted=COEF |
| 71 | truth registers[10].field_parts[6]  registers[10].field_parts[6] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 72 | truth registers[10].field_parts[6]  registers[10].field_parts[6] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 73 | truth registers[10].field_parts[7].bit_field[0]  registers[10].field_parts[7].bit_field[0] | field_description | 0.000000 | Bits 7:0 of coefficient c10. | "" | objective field differs: truth=Bits 7:0 of coefficient c10., extracted="" |
| 74 | truth registers[10].field_parts[7].bit_field[0]  registers[10].field_parts[7].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 75 | truth registers[10].field_parts[7]  registers[10].field_parts[7] | register_name | 0.000000 | c10 | COEF | objective name/parameter differs: truth=c10, extracted=COEF |
| 76 | truth registers[10].field_parts[7]  registers[10].field_parts[7] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 77 | truth registers[10].field_parts[7]  registers[10].field_parts[7] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 78 | truth registers[10].field_parts[8].bit_field[0]  registers[10].field_parts[8].bit_field[0] | field_description | 0.000000 | Bits 15:8 of coefficient c01. | "" | objective field differs: truth=Bits 15:8 of coefficient c01., extracted="" |
| 79 | truth registers[10].field_parts[8].bit_field[0]  registers[10].field_parts[8].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 80 | truth registers[10].field_parts[8]  registers[10].field_parts[8] | register_name | 0.000000 | c01 | COEF | objective name/parameter differs: truth=c01, extracted=COEF |
| 81 | truth registers[10].field_parts[8]  registers[10].field_parts[8] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 82 | truth registers[10].field_parts[8]  registers[10].field_parts[8] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 83 | truth registers[10].field_parts[9].bit_field[0]  registers[10].field_parts[9].bit_field[0] | field_description | 0.000000 | Bits 7:0 of coefficient c01. | "" | objective field differs: truth=Bits 7:0 of coefficient c01., extracted="" |
| 84 | truth registers[10].field_parts[9].bit_field[0]  registers[10].field_parts[9].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 85 | truth registers[10].field_parts[9]  registers[10].field_parts[9] | register_name | 0.000000 | c01 | COEF | objective name/parameter differs: truth=c01, extracted=COEF |
| 86 | truth registers[10].field_parts[9]  registers[10].field_parts[9] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 87 | truth registers[10].field_parts[9]  registers[10].field_parts[9] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 88 | truth registers[10].field_parts[10].bit_field[0]  registers[10].field_parts[10].bit_field[0] | field_description | 0.000000 | Bits 15:8 of coefficient c11. | "" | objective field differs: truth=Bits 15:8 of coefficient c11., extracted="" |
| 89 | truth registers[10].field_parts[10].bit_field[0]  registers[10].field_parts[10].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 90 | truth registers[10].field_parts[10]  registers[10].field_parts[10] | register_name | 0.000000 | c11 | COEF | objective name/parameter differs: truth=c11, extracted=COEF |
| 91 | truth registers[10].field_parts[10]  registers[10].field_parts[10] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 92 | truth registers[10].field_parts[10]  registers[10].field_parts[10] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 93 | truth registers[10].field_parts[11].bit_field[0]  registers[10].field_parts[11].bit_field[0] | field_description | 0.000000 | Bits 7:0 of coefficient c11. | "" | objective field differs: truth=Bits 7:0 of coefficient c11., extracted="" |
| 94 | truth registers[10].field_parts[11].bit_field[0]  registers[10].field_parts[11].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 95 | truth registers[10].field_parts[11]  registers[10].field_parts[11] | register_name | 0.000000 | c11 | COEF | objective name/parameter differs: truth=c11, extracted=COEF |
| 96 | truth registers[10].field_parts[11]  registers[10].field_parts[11] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 97 | truth registers[10].field_parts[11]  registers[10].field_parts[11] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 98 | truth registers[10].field_parts[12].bit_field[0]  registers[10].field_parts[12].bit_field[0] | field_description | 0.000000 | Bits 15:8 of coefficient c20. | "" | objective field differs: truth=Bits 15:8 of coefficient c20., extracted="" |
| 99 | truth registers[10].field_parts[12].bit_field[0]  registers[10].field_parts[12].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 100 | truth registers[10].field_parts[12]  registers[10].field_parts[12] | register_name | 0.000000 | c20 | COEF | objective name/parameter differs: truth=c20, extracted=COEF |
| 101 | truth registers[10].field_parts[12]  registers[10].field_parts[12] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 102 | truth registers[10].field_parts[12]  registers[10].field_parts[12] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 103 | truth registers[10].field_parts[13].bit_field[0]  registers[10].field_parts[13].bit_field[0] | field_description | 0.000000 | Bits 7:0 of coefficient c20. | "" | objective field differs: truth=Bits 7:0 of coefficient c20., extracted="" |
| 104 | truth registers[10].field_parts[13].bit_field[0]  registers[10].field_parts[13].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 105 | truth registers[10].field_parts[13]  registers[10].field_parts[13] | register_name | 0.000000 | c20 | COEF | objective name/parameter differs: truth=c20, extracted=COEF |
| 106 | truth registers[10].field_parts[13]  registers[10].field_parts[13] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 107 | truth registers[10].field_parts[13]  registers[10].field_parts[13] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 108 | truth registers[10].field_parts[14].bit_field[0]  registers[10].field_parts[14].bit_field[0] | field_description | 0.000000 | Bits 15:8 of coefficient c21. | "" | objective field differs: truth=Bits 15:8 of coefficient c21., extracted="" |
| 109 | truth registers[10].field_parts[14].bit_field[0]  registers[10].field_parts[14].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 110 | truth registers[10].field_parts[14]  registers[10].field_parts[14] | register_name | 0.000000 | c21 | COEF | objective name/parameter differs: truth=c21, extracted=COEF |
| 111 | truth registers[10].field_parts[14]  registers[10].field_parts[14] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 112 | truth registers[10].field_parts[14]  registers[10].field_parts[14] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 113 | truth registers[10].field_parts[15].bit_field[0]  registers[10].field_parts[15].bit_field[0] | field_description | 0.000000 | Bits 7:0 of coefficient c21. | "" | objective field differs: truth=Bits 7:0 of coefficient c21., extracted="" |
| 114 | truth registers[10].field_parts[15].bit_field[0]  registers[10].field_parts[15].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 115 | truth registers[10].field_parts[15]  registers[10].field_parts[15] | register_name | 0.000000 | c21 | COEF | objective name/parameter differs: truth=c21, extracted=COEF |
| 116 | truth registers[10].field_parts[15]  registers[10].field_parts[15] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 117 | truth registers[10].field_parts[15]  registers[10].field_parts[15] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 118 | truth registers[10].field_parts[16].bit_field[0]  registers[10].field_parts[16].bit_field[0] | field_description | 0.000000 | Bits 15:8 of coefficient c30. | "" | objective field differs: truth=Bits 15:8 of coefficient c30., extracted="" |
| 119 | truth registers[10].field_parts[16].bit_field[0]  registers[10].field_parts[16].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 120 | truth registers[10].field_parts[16]  registers[10].field_parts[16] | register_name | 0.000000 | c30 | COEF | objective name/parameter differs: truth=c30, extracted=COEF |
| 121 | truth registers[10].field_parts[16]  registers[10].field_parts[16] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 122 | truth registers[10].field_parts[16]  registers[10].field_parts[16] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 123 | truth registers[10].field_parts[17].bit_field[0]  registers[10].field_parts[17].bit_field[0] | field_description | 0.000000 | Bits 7:0 of coefficient c30. | "" | objective field differs: truth=Bits 7:0 of coefficient c30., extracted="" |
| 124 | truth registers[10].field_parts[17].bit_field[0]  registers[10].field_parts[17].bit_field[0] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 125 | truth registers[10].field_parts[17]  registers[10].field_parts[17] | register_name | 0.000000 | c30 | COEF | objective name/parameter differs: truth=c30, extracted=COEF |
| 126 | truth registers[10].field_parts[17]  registers[10].field_parts[17] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 127 | truth registers[10].field_parts[17]  registers[10].field_parts[17] | bit_field | 0.883088 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 128 | truth registers[10]  registers[10] | type_write_read | 0.000000 | R | "" | truth type_write_read=R, but extraction has "" |
| 129 | truth registers[10]  registers[10] | default_value_description | 0.000000 | "" | Reset state XXh for each byte. | default-value description is missing or incorrect: truth="", extracted=Reset state XXh for each byte. |
| 130 | truth registers[10]  registers[10] | field_parts | 0.874918 | recursive | aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above |
| 131 | truth registers[11].field_parts[0].bit_field[1]  registers[11].field_parts[0].bit_field[1] | bit_start | 0.000000 | 0 | 6 | objective bit boundary differs: truth=0, extracted=6 |
| 132 | truth registers[11].field_parts[0].bit_field[1]  registers[11].field_parts[0].bit_field[1] | bit_end | 0.000000 | 6 | 0 | objective bit boundary differs: truth=6, extracted=0 |
| 133 | truth registers[11].field_parts[0]  registers[11].field_parts[0] | register_name | 0.000000 | TMP_COEF_SRCE | COEF_SRCE | objective name/parameter differs: truth=TMP_COEF_SRCE, extracted=COEF_SRCE |
| 134 | truth registers[11].field_parts[0]  registers[11].field_parts[0] | bit_field | 0.740574 | recursive | aggregated recursive score is below 1; see bottom-up bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up bit-field calculations above |
| 135 | truth registers[11]  registers[11] | default_value_description | 0.000000 | "" | Reset value XXh. | default-value description is missing or incorrect: truth="", extracted=Reset value XXh. |
| 136 | truth registers[11]  registers[11] | field_parts | 0.890826 | recursive | aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above | objective field differs: truth=recursive, extracted=aggregated recursive score is below 1; see bottom-up field-part/bit-field calculations above |

### Missing and extra physical locations

- No truth physical location is missing.
- No extra extracted physical location.

- No unmatched extracted bit field remains after the accepted merge and reserved-range checks.

## 4. Empty type_write_read audit

- Audited scored logical-register, field-part, and bit-field access-type comparisons: 105.
- Truth/extraction both empty: C=1.0 in 6 comparisons. These cases were explicitly credited and did not enter the deduction inventory.
- Truth empty but extraction nonempty: 0 comparisons; these are inventions and receive C=0.
- Truth concrete but extraction empty: 39 comparisons; these are omissions and receive C=0.
- Both concrete: 60 comparisons; exact matches receive C=1.
- Credited empty/empty locations:
  - truth registers[2].field_parts[0].bit_field[0]  registers[2].field_parts[0].bit_field[0] -> C=1.0.
  - truth registers[4].field_parts[0].bit_field[4]  registers[4].field_parts[0].bit_field[4] -> C=1.0.
  - truth registers[6].field_parts[0].bit_field[0]  registers[6].field_parts[0].bit_field[0] -> C=1.0.
  - truth registers[7].field_parts[0].bit_field[0]  registers[7].field_parts[0].bit_field[0] -> C=1.0.
  - truth registers[8].field_parts[0].bit_field[1]  registers[8].field_parts[0].bit_field[1] -> C=1.0.
  - truth registers[11].field_parts[0].bit_field[1]  registers[11].field_parts[0].bit_field[1] -> C=1.0.
- Truth-empty/nonempty type_write_read cases: 0; all such cases are listed in the audit and scored C=0.

## 5. Invented-field and representation check

- The separate extra-physical-register penalty is applied exactly once through x; no extra physical address was extracted.
- Merged pressure/temperature data entries and merged COEF are evaluated over all covered truth physical parts; grouping alone is not penalized.
- COEF_SRCE is accepted only as the logical-name shorthand for Coefficient Source.
- PSR_Bn versus PRS_Bn, Product ID versus Product and Revision ID (ID), COEF field-part names versus c0/c1/c00..., and COEF_SRCE field-part name versus TMP_COEF_SRCE remain strict objective differences.
- Reserved-bit name/description emptiness is permitted; bit boundaries and reserved classification remain strict.
- No fields outside the scored AGENTS.md field list enter the numerical score.

## 6. Calculation conclusion

All 12 extracted logical-register items were reviewed, including merged data and COEF representations; every field part and every bit field is shown bottom-up above. The final DPS368 v10_0 score is **9.120436453 / 10**.

