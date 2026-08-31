# BME280 v17.0 detailed score — revised AGENTS.md rules

## 1. Scoring basis

- Truth file: BME280/truth_BME280.json; evaluated map: BME280/v17_0/register_map.json.
- Calculation is bottom-up for every extracted logical register: bit fields, physical field parts, then logical-register Q(L).
- Only logical_register, field_part, and bit_field are recursive. category is excluded.
- Objective facts (numeric addresses with bank/page, bit ranges, widths, value codes, reserved status, and access type) are strict.
- Descriptions are judged for functional equivalence; generic or incomplete descriptions receive partial credit, while missing or contradictory descriptions receive 0 where the function is absent.
- Existing fields that are empty in both truth and extraction receive credit, including empty values and empty type_write_read on reserved/fixed-zero fields.
- Equivalent logical-register merge/split grouping is not penalized solely for representation. The merged calibration groups and the merged/split raw-output registers are therefore associated with their truth physical locations.
- The fixed-zero bits in temp_xlsb and press_xlsb may be evaluated as one 4-bit target only when their geometry and fixed-zero semantics are preserved; v17 has the ranges reversed and marks the data nibble as reserved, so those objective/semantic errors are scored.
- Rounded AHP weights are normalized by 0.9999 for bit fields, 1.0000 for field parts, and 1.0001 for logical registers.

## Extracted logical-register calculations

## Extracted logical register 1: id

v17 location: registers[0]; truth association: truth registers[17] (id).
Associated physical locations: 0xD0 (208).

### Bottom layer: bit fields, then field parts

#### Field part 1: id at 0xD0 (208)

Locations: truth registers[17].field_parts[0] ↔ v17 registers[0].field_parts[0].

**Truth bit field 1: chip_id[7:0] bits 7:0**

Locations: truth registers[17].field_parts[0].bit_field[0] ↔ v17 registers[0].field_parts[0].bit_field[0]. Judgment: truth values are missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | chip_id[7:0] | chip_id[7:0] | correct |
| field_description | 0.0586 | 1.000000 | Chip identification number. | Chip identification number. Default value is 0x60. | correct |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 0.000000 | [{"value":"0x60","value_description":"BME280 chip identification number."}] | [] | truth values are missing |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.790200 / 0.9999 = 0.790279

**Field-part aggregation**

bit_field correctness = mean(0.790279) = 0.790279.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | id | id | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xD0","decimal":"208","bank":"","page":"","description":"Chip identification register."} | {"hex":"0xD0","decimal":"208","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 0.000000 | Chip identification register. | "" | description missing |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.790279 | truth-target bit-field collection | [{"name_or_parameter":"chip_id[7:0]","field_description":"Chip identification number. Default value is 0x60.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.790279) / 1.0000 = 0.865078 / 1.0000 = 0.865078

### Extracted logical-register aggregation

field_parts correctness = mean(0.865078) = 0.865078.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | id | id | correct |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0xD0","decimal":"208","bank":"","page":"","description":"Chip identification register."}] | [{"hex":"0xD0","decimal":"208","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 1.000000 | Contains the chip identification number chip_id[7:0], which is 0x60. | The "id" register contains the chip identification number chip_id[7:0], which is 0x60. This number can be read as soon as the device finished the power-on-reset. | correct |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.865078 | corresponding truth field-part collection | [{"register_name":"id","physical_address":{"hex":"0xD0","decimal":"208","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"chip_id[7:0]","field_description":"Chip identification number. Default value is 0x60.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | 0x60 | 0x60 | correct |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.865078 + 0.0667×1.000000 + 0.0334×1.000000) / 1.0001 = 0.959799 / 1.0001 = 0.959703

## Extracted logical register 2: reset

v17 location: registers[1]; truth association: truth registers[25] (reset).
Associated physical locations: 0xE0 (224).

### Bottom layer: bit fields, then field parts

#### Field part 1: reset at 0xE0 (224)

Locations: truth registers[25].field_parts[0] ↔ v17 registers[1].field_parts[0].

**Truth bit field 1: reset[7:0] bits 7:0**

Locations: truth registers[25].field_parts[0].bit_field[0] ↔ v17 registers[1].field_parts[0].bit_field[0]. Judgment: some truth value codes are present but the set is incomplete.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | reset[7:0] | reset[7:0] | correct |
| field_description | 0.0586 | 1.000000 | Soft reset word. | Soft reset word. Writing 0xB6 resets the device. Read value is always 0x00. | correct |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 0.500000 | [{"value":"0xB6","value_description":"Resets the device using the complete power-on-reset procedure."},{"value":"other values than 0xB6","value_description":"No effect."}] | [{"value":"0xB6","value_description":"Device reset using power-on-reset procedure"}] | some truth value codes are present but the set is incomplete |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | W | W | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.500000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.895050 / 0.9999 = 0.895140

**Field-part aggregation**

bit_field correctness = mean(0.895140) = 0.895140.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | reset | reset | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xE0","decimal":"224","bank":"","page":"","description":"Soft reset register."} | {"hex":"0xE0","decimal":"224","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 0.000000 | Soft reset register. | "" | description missing |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | W | W | correct |
| bit_field | 0.3129 | 0.895140 | truth-target bit-field collection | [{"name_or_parameter":"reset[7:0]","field_description":"Soft reset word. Writing 0xB6 resets the device. Read value is always 0x00.","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"0xB6","value_description":"Device reset using power-on-reset procedure"}],"is_reserved":false,"type_write_read":"W"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.895140) / 1.0000 = 0.897889 / 1.0000 = 0.897889

### Extracted logical-register aggregation

field_parts correctness = mean(0.897889) = 0.897889.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | reset | reset | correct |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0xE0","decimal":"224","bank":"","page":"","description":"Soft reset register."}] | [{"hex":"0xE0","decimal":"224","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 1.000000 | Writing 0xB6 performs a complete power-on-reset procedure; other written values have no effect. | The "reset" register contains the soft reset word reset[7:0]. If the value 0xB6 is written to the register, the device is reset using the complete power-on-reset procedure. Writing other values than 0xB6 has no effect. The readout value is always 0x00. | correct |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | W | W | correct |
| field_parts | 0.2987 | 0.897889 | corresponding truth field-part collection | [{"register_name":"reset","physical_address":{"hex":"0xE0","decimal":"224","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"W","bit_field":[{"name_or_parameter":"reset[7:0]","field_description":"Soft reset word. Writing 0xB6 resets the device. Read value is always 0x00.","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"0xB6","value_description":"Device reset using power-on-reset procedure"}],"is_reserved":false,"type_write_read":"W"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 0.000000 | 0x00 | "" | truth default_value='0x00', extracted='' |
| default_value_description | 0.0334 | 0.000000 | The readout value is always 0x00. | "" | default-value description missing |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.897889 + 0.0667×0.000000 + 0.0334×0.000000) / 1.0001 = 0.869499 / 1.0001 = 0.869413

## Extracted logical register 3: calib00_calib25

v17 location: registers[2]; equivalent calibration grouping association: dig_H1, dig_P1, dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8, dig_P9, dig_T1, dig_T2, dig_T3.
Associated physical locations: 0x88 (136), 0x89 (137), 0x8A (138), 0x8B (139), 0x8C (140), 0x8D (141), 0x8E (142), 0x8F (143), 0x90 (144), 0x91 (145), 0x92 (146), 0x93 (147), 0x94 (148), 0x95 (149), 0x96 (150), 0x97 (151), 0x98 (152), 0x99 (153), 0x9A (154), 0x9B (155), 0x9C (156), 0x9D (157), 0x9E (158), 0x9F (159), 0xA1 (161).

### Bottom layer: bit fields, then field parts

#### Field part 1: dig_T1[7:0] at 0x88 (136)

Locations: truth registers[0].field_parts[0] ↔ v17 registers[2].field_parts[0].

**Truth bit field 1: dig_T1 [7:0] bits 7:0**

Locations: truth registers[0].field_parts[0].bit_field[0] ↔ v17 registers[2].field_parts[0].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_T1 [7:0] | dig_T1[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Low byte of dig_T1. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_T1 [7:0] | dig_T1[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x88","decimal":"136","bank":"","page":"","description":"Low byte of dig_T1."} | {"hex":"0x88","decimal":"136","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | Low byte, dig_T1[7:0]. | LSB of dig_T1 (unsigned short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_T1[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 2: dig_T1[15:8] at 0x89 (137)

Locations: truth registers[0].field_parts[1] ↔ v17 registers[2].field_parts[1].

**Truth bit field 1: dig_T1 [15:8] bits 7:0**

Locations: truth registers[0].field_parts[1].bit_field[0] ↔ v17 registers[2].field_parts[1].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_T1 [15:8] | dig_T1[15:8] | correct |
| field_description | 0.0586 | 0.000000 | High byte of dig_T1. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_T1 [15:8] | dig_T1[15:8] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x89","decimal":"137","bank":"","page":"","description":"High byte of dig_T1."} | {"hex":"0x89","decimal":"137","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | High byte, dig_T1[15:8]. | MSB of dig_T1 (unsigned short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_T1[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 3: dig_T2[7:0] at 0x8A (138)

Locations: truth registers[1].field_parts[0] ↔ v17 registers[2].field_parts[2].

**Truth bit field 1: dig_T2 [7:0] bits 7:0**

Locations: truth registers[1].field_parts[0].bit_field[0] ↔ v17 registers[2].field_parts[2].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_T2 [7:0] | dig_T2[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Low byte of dig_T2. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_T2 [7:0] | dig_T2[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x8A","decimal":"138","bank":"","page":"","description":"Low byte of dig_T2."} | {"hex":"0x8A","decimal":"138","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | Low byte, dig_T2[7:0]. | LSB of dig_T2 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_T2[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 4: dig_T2[15:8] at 0x8B (139)

Locations: truth registers[1].field_parts[1] ↔ v17 registers[2].field_parts[3].

**Truth bit field 1: dig_T2 [15:8] bits 7:0**

Locations: truth registers[1].field_parts[1].bit_field[0] ↔ v17 registers[2].field_parts[3].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_T2 [15:8] | dig_T2[15:8] | correct |
| field_description | 0.0586 | 0.000000 | High byte of dig_T2. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_T2 [15:8] | dig_T2[15:8] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x8B","decimal":"139","bank":"","page":"","description":"High byte of dig_T2."} | {"hex":"0x8B","decimal":"139","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | High byte, dig_T2[15:8]. | MSB of dig_T2 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_T2[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 5: dig_T3[7:0] at 0x8C (140)

Locations: truth registers[2].field_parts[0] ↔ v17 registers[2].field_parts[4].

**Truth bit field 1: dig_T3 [7:0] bits 7:0**

Locations: truth registers[2].field_parts[0].bit_field[0] ↔ v17 registers[2].field_parts[4].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_T3 [7:0] | dig_T3[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Low byte of dig_T3. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_T3 [7:0] | dig_T3[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x8C","decimal":"140","bank":"","page":"","description":"Low byte of dig_T3."} | {"hex":"0x8C","decimal":"140","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | Low byte, dig_T3[7:0]. | LSB of dig_T3 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_T3[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 6: dig_T3[15:8] at 0x8D (141)

Locations: truth registers[2].field_parts[1] ↔ v17 registers[2].field_parts[5].

**Truth bit field 1: dig_T3 [15:8] bits 7:0**

Locations: truth registers[2].field_parts[1].bit_field[0] ↔ v17 registers[2].field_parts[5].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_T3 [15:8] | dig_T3[15:8] | correct |
| field_description | 0.0586 | 0.000000 | High byte of dig_T3. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_T3 [15:8] | dig_T3[15:8] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x8D","decimal":"141","bank":"","page":"","description":"High byte of dig_T3."} | {"hex":"0x8D","decimal":"141","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | High byte, dig_T3[15:8]. | MSB of dig_T3 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_T3[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 7: dig_P1[7:0] at 0x8E (142)

Locations: truth registers[3].field_parts[0] ↔ v17 registers[2].field_parts[6].

**Truth bit field 1: dig_P1 [7:0] bits 7:0**

Locations: truth registers[3].field_parts[0].bit_field[0] ↔ v17 registers[2].field_parts[6].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P1 [7:0] | dig_P1[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Low byte of dig_P1. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P1 [7:0] | dig_P1[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x8E","decimal":"142","bank":"","page":"","description":"Low byte of dig_P1."} | {"hex":"0x8E","decimal":"142","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | Low byte, dig_P1[7:0]. | LSB of dig_P1 (unsigned short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P1[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 8: dig_P1[15:8] at 0x8F (143)

Locations: truth registers[3].field_parts[1] ↔ v17 registers[2].field_parts[7].

**Truth bit field 1: dig_P1 [15:8] bits 7:0**

Locations: truth registers[3].field_parts[1].bit_field[0] ↔ v17 registers[2].field_parts[7].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P1 [15:8] | dig_P1[15:8] | correct |
| field_description | 0.0586 | 0.000000 | High byte of dig_P1. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P1 [15:8] | dig_P1[15:8] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x8F","decimal":"143","bank":"","page":"","description":"High byte of dig_P1."} | {"hex":"0x8F","decimal":"143","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | High byte, dig_P1[15:8]. | MSB of dig_P1 (unsigned short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P1[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 9: dig_P2[7:0] at 0x90 (144)

Locations: truth registers[4].field_parts[0] ↔ v17 registers[2].field_parts[8].

**Truth bit field 1: dig_P2 [7:0] bits 7:0**

Locations: truth registers[4].field_parts[0].bit_field[0] ↔ v17 registers[2].field_parts[8].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P2 [7:0] | dig_P2[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Low byte of dig_P2. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P2 [7:0] | dig_P2[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x90","decimal":"144","bank":"","page":"","description":"Low byte of dig_P2."} | {"hex":"0x90","decimal":"144","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | Low byte, dig_P2[7:0]. | LSB of dig_P2 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P2[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 10: dig_P2[15:8] at 0x91 (145)

Locations: truth registers[4].field_parts[1] ↔ v17 registers[2].field_parts[9].

**Truth bit field 1: dig_P2 [15:8] bits 7:0**

Locations: truth registers[4].field_parts[1].bit_field[0] ↔ v17 registers[2].field_parts[9].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P2 [15:8] | dig_P2[15:8] | correct |
| field_description | 0.0586 | 0.000000 | High byte of dig_P2. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P2 [15:8] | dig_P2[15:8] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x91","decimal":"145","bank":"","page":"","description":"High byte of dig_P2."} | {"hex":"0x91","decimal":"145","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | High byte, dig_P2[15:8]. | MSB of dig_P2 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P2[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 11: dig_P3[7:0] at 0x92 (146)

Locations: truth registers[5].field_parts[0] ↔ v17 registers[2].field_parts[10].

**Truth bit field 1: dig_P3 [7:0] bits 7:0**

Locations: truth registers[5].field_parts[0].bit_field[0] ↔ v17 registers[2].field_parts[10].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P3 [7:0] | dig_P3[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Low byte of dig_P3. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P3 [7:0] | dig_P3[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x92","decimal":"146","bank":"","page":"","description":"Low byte of dig_P3."} | {"hex":"0x92","decimal":"146","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | Low byte, dig_P3[7:0]. | LSB of dig_P3 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P3[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 12: dig_P3[15:8] at 0x93 (147)

Locations: truth registers[5].field_parts[1] ↔ v17 registers[2].field_parts[11].

**Truth bit field 1: dig_P3 [15:8] bits 7:0**

Locations: truth registers[5].field_parts[1].bit_field[0] ↔ v17 registers[2].field_parts[11].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P3 [15:8] | dig_P3[15:8] | correct |
| field_description | 0.0586 | 0.000000 | High byte of dig_P3. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P3 [15:8] | dig_P3[15:8] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x93","decimal":"147","bank":"","page":"","description":"High byte of dig_P3."} | {"hex":"0x93","decimal":"147","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | High byte, dig_P3[15:8]. | MSB of dig_P3 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P3[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 13: dig_P4[7:0] at 0x94 (148)

Locations: truth registers[6].field_parts[0] ↔ v17 registers[2].field_parts[12].

**Truth bit field 1: dig_P4 [7:0] bits 7:0**

Locations: truth registers[6].field_parts[0].bit_field[0] ↔ v17 registers[2].field_parts[12].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P4 [7:0] | dig_P4[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Low byte of dig_P4. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P4 [7:0] | dig_P4[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x94","decimal":"148","bank":"","page":"","description":"Low byte of dig_P4."} | {"hex":"0x94","decimal":"148","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | Low byte, dig_P4[7:0]. | LSB of dig_P4 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P4[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 14: dig_P4[15:8] at 0x95 (149)

Locations: truth registers[6].field_parts[1] ↔ v17 registers[2].field_parts[13].

**Truth bit field 1: dig_P4 [15:8] bits 7:0**

Locations: truth registers[6].field_parts[1].bit_field[0] ↔ v17 registers[2].field_parts[13].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P4 [15:8] | dig_P4[15:8] | correct |
| field_description | 0.0586 | 0.000000 | High byte of dig_P4. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P4 [15:8] | dig_P4[15:8] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x95","decimal":"149","bank":"","page":"","description":"High byte of dig_P4."} | {"hex":"0x95","decimal":"149","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | High byte, dig_P4[15:8]. | MSB of dig_P4 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P4[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 15: dig_P5[7:0] at 0x96 (150)

Locations: truth registers[7].field_parts[0] ↔ v17 registers[2].field_parts[14].

**Truth bit field 1: dig_P5 [7:0] bits 7:0**

Locations: truth registers[7].field_parts[0].bit_field[0] ↔ v17 registers[2].field_parts[14].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P5 [7:0] | dig_P5[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Low byte of dig_P5. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P5 [7:0] | dig_P5[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x96","decimal":"150","bank":"","page":"","description":"Low byte of dig_P5."} | {"hex":"0x96","decimal":"150","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | Low byte, dig_P5[7:0]. | LSB of dig_P5 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P5[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 16: dig_P5[15:8] at 0x97 (151)

Locations: truth registers[7].field_parts[1] ↔ v17 registers[2].field_parts[15].

**Truth bit field 1: dig_P5 [15:8] bits 7:0**

Locations: truth registers[7].field_parts[1].bit_field[0] ↔ v17 registers[2].field_parts[15].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P5 [15:8] | dig_P5[15:8] | correct |
| field_description | 0.0586 | 0.000000 | High byte of dig_P5. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P5 [15:8] | dig_P5[15:8] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x97","decimal":"151","bank":"","page":"","description":"High byte of dig_P5."} | {"hex":"0x97","decimal":"151","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | High byte, dig_P5[15:8]. | MSB of dig_P5 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P5[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 17: dig_P6[7:0] at 0x98 (152)

Locations: truth registers[8].field_parts[0] ↔ v17 registers[2].field_parts[16].

**Truth bit field 1: dig_P6 [7:0] bits 7:0**

Locations: truth registers[8].field_parts[0].bit_field[0] ↔ v17 registers[2].field_parts[16].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P6 [7:0] | dig_P6[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Low byte of dig_P6. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P6 [7:0] | dig_P6[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x98","decimal":"152","bank":"","page":"","description":"Low byte of dig_P6."} | {"hex":"0x98","decimal":"152","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | Low byte, dig_P6[7:0]. | LSB of dig_P6 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P6[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 18: dig_P6[15:8] at 0x99 (153)

Locations: truth registers[8].field_parts[1] ↔ v17 registers[2].field_parts[17].

**Truth bit field 1: dig_P6 [15:8] bits 7:0**

Locations: truth registers[8].field_parts[1].bit_field[0] ↔ v17 registers[2].field_parts[17].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P6 [15:8] | dig_P6[15:8] | correct |
| field_description | 0.0586 | 0.000000 | High byte of dig_P6. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P6 [15:8] | dig_P6[15:8] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x99","decimal":"153","bank":"","page":"","description":"High byte of dig_P6."} | {"hex":"0x99","decimal":"153","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | High byte, dig_P6[15:8]. | MSB of dig_P6 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P6[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 19: dig_P7[7:0] at 0x9A (154)

Locations: truth registers[9].field_parts[0] ↔ v17 registers[2].field_parts[18].

**Truth bit field 1: dig_P7 [7:0] bits 7:0**

Locations: truth registers[9].field_parts[0].bit_field[0] ↔ v17 registers[2].field_parts[18].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P7 [7:0] | dig_P7[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Low byte of dig_P7. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P7 [7:0] | dig_P7[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x9A","decimal":"154","bank":"","page":"","description":"Low byte of dig_P7."} | {"hex":"0x9A","decimal":"154","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | Low byte, dig_P7[7:0]. | LSB of dig_P7 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P7[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 20: dig_P7[15:8] at 0x9B (155)

Locations: truth registers[9].field_parts[1] ↔ v17 registers[2].field_parts[19].

**Truth bit field 1: dig_P7 [15:8] bits 7:0**

Locations: truth registers[9].field_parts[1].bit_field[0] ↔ v17 registers[2].field_parts[19].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P7 [15:8] | dig_P7[15:8] | correct |
| field_description | 0.0586 | 0.000000 | High byte of dig_P7. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P7 [15:8] | dig_P7[15:8] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x9B","decimal":"155","bank":"","page":"","description":"High byte of dig_P7."} | {"hex":"0x9B","decimal":"155","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | High byte, dig_P7[15:8]. | MSB of dig_P7 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P7[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 21: dig_P8[7:0] at 0x9C (156)

Locations: truth registers[10].field_parts[0] ↔ v17 registers[2].field_parts[20].

**Truth bit field 1: dig_P8 [7:0] bits 7:0**

Locations: truth registers[10].field_parts[0].bit_field[0] ↔ v17 registers[2].field_parts[20].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P8 [7:0] | dig_P8[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Low byte of dig_P8. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P8 [7:0] | dig_P8[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x9C","decimal":"156","bank":"","page":"","description":"Low byte of dig_P8."} | {"hex":"0x9C","decimal":"156","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | Low byte, dig_P8[7:0]. | LSB of dig_P8 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P8[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 22: dig_P8[15:8] at 0x9D (157)

Locations: truth registers[10].field_parts[1] ↔ v17 registers[2].field_parts[21].

**Truth bit field 1: dig_P8 [15:8] bits 7:0**

Locations: truth registers[10].field_parts[1].bit_field[0] ↔ v17 registers[2].field_parts[21].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P8 [15:8] | dig_P8[15:8] | correct |
| field_description | 0.0586 | 0.000000 | High byte of dig_P8. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P8 [15:8] | dig_P8[15:8] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x9D","decimal":"157","bank":"","page":"","description":"High byte of dig_P8."} | {"hex":"0x9D","decimal":"157","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | High byte, dig_P8[15:8]. | MSB of dig_P8 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P8[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 23: dig_P9[7:0] at 0x9E (158)

Locations: truth registers[11].field_parts[0] ↔ v17 registers[2].field_parts[22].

**Truth bit field 1: dig_P9 [7:0] bits 7:0**

Locations: truth registers[11].field_parts[0].bit_field[0] ↔ v17 registers[2].field_parts[22].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P9 [7:0] | dig_P9[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Low byte of dig_P9. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P9 [7:0] | dig_P9[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x9E","decimal":"158","bank":"","page":"","description":"Low byte of dig_P9."} | {"hex":"0x9E","decimal":"158","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | Low byte, dig_P9[7:0]. | LSB of dig_P9 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P9[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 24: dig_P9[15:8] at 0x9F (159)

Locations: truth registers[11].field_parts[1] ↔ v17 registers[2].field_parts[23].

**Truth bit field 1: dig_P9 [15:8] bits 7:0**

Locations: truth registers[11].field_parts[1].bit_field[0] ↔ v17 registers[2].field_parts[23].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_P9 [15:8] | dig_P9[15:8] | correct |
| field_description | 0.0586 | 0.000000 | High byte of dig_P9. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_P9 [15:8] | dig_P9[15:8] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0x9F","decimal":"159","bank":"","page":"","description":"High byte of dig_P9."} | {"hex":"0x9F","decimal":"159","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | High byte, dig_P9[15:8]. | MSB of dig_P9 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P9[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 25: dig_H1[7:0] at 0xA1 (161)

Locations: truth registers[12].field_parts[0] ↔ v17 registers[2].field_parts[24].

**Truth bit field 1: dig_H1 [7:0] bits 7:0**

Locations: truth registers[12].field_parts[0].bit_field[0] ↔ v17 registers[2].field_parts[24].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_H1 [7:0] | dig_H1[7:0] | correct |
| field_description | 0.0586 | 0.000000 | dig_H1 humidity compensation parameter. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_H1 [7:0] | dig_H1[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xA1","decimal":"161","bank":"","page":"","description":"dig_H1[7:0]."} | {"hex":"0xA1","decimal":"161","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | 8-bit dig_H1 parameter. | LSB of dig_H1 (unsigned char) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_H1[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

### Extracted logical-register aggregation

field_parts correctness = mean(0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662, 0.981662) = 0.981662.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | equivalent calibration grouping of dig_T1, dig_T2, dig_T3, dig_P1, dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8, dig_P9, dig_H1 | calib00_calib25 | correct |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0x88","decimal":"136","bank":"","page":""},{"hex":"0x89","decimal":"137","bank":"","page":""},{"hex":"0x8A","decimal":"138","bank":"","page":""},{"hex":"0x8B","decimal":"139","bank":"","page":""},{"hex":"0x8C","decimal":"140","bank":"","page":""},{"hex":"0x8D","decimal":"141","bank":"","page":""},{"hex":"0x8E","decimal":"142","bank":"","page":""},{"hex":"0x8F","decimal":"143","bank":"","page":""},{"hex":"0x90","decimal":"144","bank":"","page":""},{"hex":"0x91","decimal":"145","bank":"","page":""},{"hex":"0x92","decimal":"146","bank":"","page":""},{"hex":"0x93","decimal":"147","bank":"","page":""},{"hex":"0x94","decimal":"148","bank":"","page":""},{"hex":"0x95","decimal":"149","bank":"","page":""},{"hex":"0x96","decimal":"150","bank":"","page":""},{"hex":"0x97","decimal":"151","bank":"","page":""},{"hex":"0x98","decimal":"152","bank":"","page":""},{"hex":"0x99","decimal":"153","bank":"","page":""},{"hex":"0x9A","decimal":"154","bank":"","page":""},{"hex":"0x9B","decimal":"155","bank":"","page":""},{"hex":"0x9C","decimal":"156","bank":"","page":""},{"hex":"0x9D","decimal":"157","bank":"","page":""},{"hex":"0x9E","decimal":"158","bank":"","page":""},{"hex":"0x9F","decimal":"159","bank":"","page":""},{"hex":"0xA1","decimal":"161","bank":"","page":""}] | [{"hex":"0x88","decimal":"136","bank":"","page":"","description":""},{"hex":"0x89","decimal":"137","bank":"","page":"","description":""},{"hex":"0x8A","decimal":"138","bank":"","page":"","description":""},{"hex":"0x8B","decimal":"139","bank":"","page":"","description":""},{"hex":"0x8C","decimal":"140","bank":"","page":"","description":""},{"hex":"0x8D","decimal":"141","bank":"","page":"","description":""},{"hex":"0x8E","decimal":"142","bank":"","page":"","description":""},{"hex":"0x8F","decimal":"143","bank":"","page":"","description":""},{"hex":"0x90","decimal":"144","bank":"","page":"","description":""},{"hex":"0x91","decimal":"145","bank":"","page":"","description":""},{"hex":"0x92","decimal":"146","bank":"","page":"","description":""},{"hex":"0x93","decimal":"147","bank":"","page":"","description":""},{"hex":"0x94","decimal":"148","bank":"","page":"","description":""},{"hex":"0x95","decimal":"149","bank":"","page":"","description":""},{"hex":"0x96","decimal":"150","bank":"","page":"","description":""},{"hex":"0x97","decimal":"151","bank":"","page":"","description":""},{"hex":"0x98","decimal":"152","bank":"","page":"","description":""},{"hex":"0x99","decimal":"153","bank":"","page":"","description":""},{"hex":"0x9A","decimal":"154","bank":"","page":"","description":""},{"hex":"0x9B","decimal":"155","bank":"","page":"","description":""},{"hex":"0x9C","decimal":"156","bank":"","page":"","description":""},{"hex":"0x9D","decimal":"157","bank":"","page":"","description":""},{"hex":"0x9E","decimal":"158","bank":"","page":"","description":""},{"hex":"0x9F","decimal":"159","bank":"","page":"","description":""},{"hex":"0xA1","decimal":"161","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 0.500000 | ["Unsigned 16-bit temperature compensation parameter stored in non-volatile memory.","Signed 16-bit temperature compensation parameter stored in non-volatile memory.","Signed 16-bit temperature compensation parameter stored in non-volatile memory.","Unsigned 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Unsigned 8-bit humidity compensation parameter stored in non-volatile memory."] | Calibration data registers for temperature and pressure compensation parameters (dig_T1...dig_P9). Each 16-bit compensation word is stored as two 8-bit registers. Memory addresses 0x88 to 0xA1. | generic grouped calibration description omits some individual signedness/storage detail |
| width_bits | 0.0590 | 0.000000 | 200 | ∅ | truth comparison width_bits=200, extracted=None |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.981662 | corresponding truth field-part collection | [{"register_name":"dig_T1[7:0]","physical_address":{"hex":"0x88","decimal":"136","bank":"","page":"","description":""},"description":"LSB of dig_T1 (unsigned short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_T1[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_T1[15:8]","physical_address":{"hex":"0x89","decimal":"137","bank":"","page":"","description":""},"description":"MSB of dig_T1 (unsigned short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_T1[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_T2[7:0]","physical_address":{"hex":"0x8A","decimal":"138","bank":"","page":"","description":""},"description":"LSB of dig_T2 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_T2[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_T2[15:8]","physical_address":{"hex":"0x8B","decimal":"139","bank":"","page":"","description":""},"description":"MSB of dig_T2 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_T2[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_T3[7:0]","physical_address":{"hex":"0x8C","decimal":"140","bank":"","page":"","description":""},"description":"LSB of dig_T3 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_T3[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_T3[15:8]","physical_address":{"hex":"0x8D","decimal":"141","bank":"","page":"","description":""},"description":"MSB of dig_T3 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_T3[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P1[7:0]","physical_address":{"hex":"0x8E","decimal":"142","bank":"","page":"","description":""},"description":"LSB of dig_P1 (unsigned short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P1[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P1[15:8]","physical_address":{"hex":"0x8F","decimal":"143","bank":"","page":"","description":""},"description":"MSB of dig_P1 (unsigned short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P1[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P2[7:0]","physical_address":{"hex":"0x90","decimal":"144","bank":"","page":"","description":""},"description":"LSB of dig_P2 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P2[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P2[15:8]","physical_address":{"hex":"0x91","decimal":"145","bank":"","page":"","description":""},"description":"MSB of dig_P2 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P2[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P3[7:0]","physical_address":{"hex":"0x92","decimal":"146","bank":"","page":"","description":""},"description":"LSB of dig_P3 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P3[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P3[15:8]","physical_address":{"hex":"0x93","decimal":"147","bank":"","page":"","description":""},"description":"MSB of dig_P3 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P3[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P4[7:0]","physical_address":{"hex":"0x94","decimal":"148","bank":"","page":"","description":""},"description":"LSB of dig_P4 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P4[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P4[15:8]","physical_address":{"hex":"0x95","decimal":"149","bank":"","page":"","description":""},"description":"MSB of dig_P4 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P4[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P5[7:0]","physical_address":{"hex":"0x96","decimal":"150","bank":"","page":"","description":""},"description":"LSB of dig_P5 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P5[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P5[15:8]","physical_address":{"hex":"0x97","decimal":"151","bank":"","page":"","description":""},"description":"MSB of dig_P5 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P5[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P6[7:0]","physical_address":{"hex":"0x98","decimal":"152","bank":"","page":"","description":""},"description":"LSB of dig_P6 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P6[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P6[15:8]","physical_address":{"hex":"0x99","decimal":"153","bank":"","page":"","description":""},"description":"MSB of dig_P6 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P6[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P7[7:0]","physical_address":{"hex":"0x9A","decimal":"154","bank":"","page":"","description":""},"description":"LSB of dig_P7 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P7[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P7[15:8]","physical_address":{"hex":"0x9B","decimal":"155","bank":"","page":"","description":""},"description":"MSB of dig_P7 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P7[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P8[7:0]","physical_address":{"hex":"0x9C","decimal":"156","bank":"","page":"","description":""},"description":"LSB of dig_P8 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P8[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P8[15:8]","physical_address":{"hex":"0x9D","decimal":"157","bank":"","page":"","description":""},"description":"MSB of dig_P8 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P8[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P9[7:0]","physical_address":{"hex":"0x9E","decimal":"158","bank":"","page":"","description":""},"description":"LSB of dig_P9 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P9[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P9[15:8]","physical_address":{"hex":"0x9F","decimal":"159","bank":"","page":"","description":""},"description":"MSB of dig_P9 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P9[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H1[7:0]","physical_address":{"hex":"0xA1","decimal":"161","bank":"","page":"","description":""},"description":"LSB of dig_H1 (unsigned char)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H1[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | "" | "" | correct |
| default_value_description | 0.0334 | 0.000000 | Individual factory-programmed calibration value. | "" | default-value description missing |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×0.000000 + 0.0590×1.000000 + 0.2987×0.981662 + 0.0667×1.000000 + 0.0334×0.000000) / 1.0001 = 0.874023 / 1.0001 = 0.873935

## Extracted logical register 4: calib26_calib41

v17 location: registers[3]; equivalent calibration grouping association: dig_H2, dig_H3, dig_H4, dig_H5, dig_H6.
Associated physical locations: 0xE1 (225), 0xE2 (226), 0xE3 (227), 0xE4 (228), 0xE5 (229), 0xE6 (230), 0xE7 (231).

### Bottom layer: bit fields, then field parts

#### Field part 1: dig_H2[7:0] at 0xE1 (225)

Locations: truth registers[13].field_parts[0] ↔ v17 registers[3].field_parts[0].

**Truth bit field 1: dig_H2 [7:0] bits 7:0**

Locations: truth registers[13].field_parts[0].bit_field[0] ↔ v17 registers[3].field_parts[0].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_H2 [7:0] | dig_H2[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Low byte of dig_H2. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_H2 [7:0] | dig_H2[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xE1","decimal":"225","bank":"","page":"","description":"Low byte of dig_H2."} | {"hex":"0xE1","decimal":"225","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | Low byte, dig_H2[7:0]. | LSB of dig_H2 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_H2[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 2: dig_H2[15:8] at 0xE2 (226)

Locations: truth registers[13].field_parts[1] ↔ v17 registers[3].field_parts[1].

**Truth bit field 1: dig_H2 [15:8] bits 7:0**

Locations: truth registers[13].field_parts[1].bit_field[0] ↔ v17 registers[3].field_parts[1].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_H2 [15:8] | dig_H2[15:8] | correct |
| field_description | 0.0586 | 0.000000 | High byte of dig_H2. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_H2 [15:8] | dig_H2[15:8] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xE2","decimal":"226","bank":"","page":"","description":"High byte of dig_H2."} | {"hex":"0xE2","decimal":"226","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | High byte, dig_H2[15:8]. | MSB of dig_H2 (signed short) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_H2[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 3: dig_H3[7:0] at 0xE3 (227)

Locations: truth registers[14].field_parts[0] ↔ v17 registers[3].field_parts[2].

**Truth bit field 1: dig_H3 [7:0] bits 7:0**

Locations: truth registers[14].field_parts[0].bit_field[0] ↔ v17 registers[3].field_parts[2].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_H3 [7:0] | dig_H3[7:0] | correct |
| field_description | 0.0586 | 0.000000 | dig_H3 humidity compensation parameter. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_H3 [7:0] | dig_H3[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xE3","decimal":"227","bank":"","page":"","description":"dig_H3[7:0]."} | {"hex":"0xE3","decimal":"227","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | 8-bit dig_H3 parameter. | LSB of dig_H3 (unsigned char) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_H3[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 4: dig_H4[11:4] at 0xE4 (228)

Locations: truth registers[15].field_parts[0] ↔ v17 registers[3].field_parts[3].

**Truth bit field 1: dig_H4 [11:4] bits 7:0**

Locations: truth registers[15].field_parts[0].bit_field[0] ↔ v17 registers[3].field_parts[3].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_H4 [11:4] | dig_H4[11:4] | correct |
| field_description | 0.0586 | 0.000000 | Upper eight bits of the 12-bit dig_H4 parameter. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_H4 [11:4] | dig_H4[11:4] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xE4","decimal":"228","bank":"","page":"","description":"Upper eight bits of dig_H4."} | {"hex":"0xE4","decimal":"228","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | dig_H4[11:4]. | Upper nibble of dig_H4 (signed short, bits 11:4) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_H4[11:4]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

#### Field part 5: dig_H4[3:0] / dig_H5[11:4] at 0xE5 (229)

Locations: truth registers[15].field_parts[1], truth registers[26].field_parts[0] ↔ v17 registers[3].field_parts[4].

**Truth bit field 1: dig_H4 [3:0] bits 3:0**

Locations: truth registers[15].field_parts[1].bit_field[0] ↔ v17 registers[3].field_parts[4].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_H4 [3:0] | dig_H4[3:0] | correct |
| field_description | 0.0586 | 0.000000 | Lower four bits of the 12-bit dig_H4 parameter. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 3 | 3 | correct |
| bit_width | 0.0583 | 1.000000 | 4 | 4 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Truth bit field 2: dig_H5 [3:0] bits 7:4**

Locations: truth registers[26].field_parts[0].bit_field[0] ↔ v17 registers[3].field_parts[4].bit_field[1]. Judgment: truth name 'dig_H5 [3:0]' differs from extracted 'dig_H5[11:4]'; description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 0.000000 | dig_H5 [3:0] | dig_H5[11:4] | truth name 'dig_H5 [3:0]' differs from extracted 'dig_H5[11:4]'; description missing |
| field_description | 0.0586 | 0.000000 | Lower four bits of the 12-bit dig_H5 parameter. | "" | truth name 'dig_H5 [3:0]' differs from extracted 'dig_H5[11:4]'; description missing |
| bit_start | 0.2594 | 1.000000 | 4 | 4 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 4 | 4 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×0.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.920100 / 0.9999 = 0.920192

**Field-part aggregation**

bit_field correctness = mean(0.941394, 0.920192) = 0.930793.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 0.000000 | dig_H4 [3:0] + dig_H5 [3:0] | dig_H4[3:0] / dig_H5[11:4] | truth register_name='dig_H4 [3:0] + dig_H5 [3:0]', extracted='dig_H4[3:0] / dig_H5[11:4]' |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xE5","decimal":"229","bank":"","page":"","description":"Lower four bits of dig_H4 in bits 3:0."} | {"hex":"0xE5","decimal":"229","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 0.000000 | dig_H4[3:0] stored in address bits 3:0. + dig_H5[3:0] stored in address bits 7:4. | Lower nibble of dig_H4 (bits 3:0) and upper nibble of dig_H5 (bits 11:4) | description gives the wrong bit range for 'dig_H5 [3:0]' |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.930793 | truth-target bit-field collection | [{"name_or_parameter":"dig_H4[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"dig_H5[11:4]","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×0.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.930793) / 1.0000 = 0.881045 / 1.0000 = 0.881045

#### Field part 6: dig_H5[3:0] at 0xE6 (230)

Locations: truth registers[26].field_parts[1] ↔ v17 registers[3].field_parts[5].

**Truth bit field 1: dig_H5 [11:4] bits 7:0**

Locations: truth registers[26].field_parts[1].bit_field[0] ↔ v17 MISSING. Judgment: missing extracted bit-field object.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 0.000000 | dig_H5 [11:4] | ∅ | missing extracted bit-field object |
| field_description | 0.0586 | 0.000000 | Upper eight bits of the 12-bit dig_H5 parameter. | ∅ | missing extracted bit-field object |
| bit_start | 0.2594 | 0.000000 | 0 | ∅ | missing extracted bit-field object |
| bit_end | 0.2594 | 0.000000 | 7 | ∅ | missing extracted bit-field object |
| bit_width | 0.0583 | 0.000000 | 8 | ∅ | missing extracted bit-field object |
| values | 0.2097 | 0.000000 | [] | ∅ | missing extracted bit-field object |
| is_reserved | 0.0750 | 0.000000 | False | ∅ | missing extracted bit-field object |
| type_write_read | 0.0583 | 0.000000 | R | ∅ | missing extracted bit-field object |

Q(bit_field) = (0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000) / 0.9999 = 0.000000 / 0.9999 = 0.000000

**Field-part aggregation**

bit_field correctness = mean(0.000000) = 0.000000.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 0.000000 | dig_H5 [11:4] | dig_H5[3:0] | truth register_name='dig_H5 [11:4]', extracted='dig_H5[3:0]' |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xE6","decimal":"230","bank":"","page":"","description":"Upper eight bits of dig_H5."} | {"hex":"0xE6","decimal":"230","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 0.000000 | dig_H5[11:4]. | Lower nibble of dig_H5 (signed short, bits 3:0) | description gives the wrong bit range for 'dig_H5 [11:4]' |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.000000 | truth-target bit-field collection | [{"name_or_parameter":"dig_H5[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×0.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000) / 1.0000 = 0.589800 / 1.0000 = 0.589800

#### Field part 7: dig_H6[7:0] at 0xE7 (231)

Locations: truth registers[16].field_parts[0] ↔ v17 registers[3].field_parts[6].

**Truth bit field 1: dig_H6 bits 7:0**

Locations: truth registers[16].field_parts[0].bit_field[0] ↔ v17 registers[3].field_parts[6].bit_field[0]. Judgment: explicit full-byte range is equivalent to truth's bare parameter name; description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | dig_H6 | dig_H6[7:0] | correct |
| field_description | 0.0586 | 0.000000 | Signed 8-bit humidity compensation parameter. | "" | explicit full-byte range is equivalent to truth's bare parameter name; description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | dig_H6 | dig_H6[7:0] | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xE7","decimal":"231","bank":"","page":"","description":"dig_H6 humidity compensation parameter."} | {"hex":"0xE7","decimal":"231","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | 8-bit dig_H6 parameter. | LSB of dig_H6 (signed char) | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_H6[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

### Extracted logical-register aggregation

field_parts correctness = mean(0.981662, 0.981662, 0.981662, 0.981662, 0.881045, 0.589800, 0.981662) = 0.911308.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | equivalent calibration grouping of dig_H2, dig_H3, dig_H4, dig_H5, dig_H6 | calib26_calib41 | correct |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0xE1","decimal":"225","bank":"","page":""},{"hex":"0xE2","decimal":"226","bank":"","page":""},{"hex":"0xE3","decimal":"227","bank":"","page":""},{"hex":"0xE4","decimal":"228","bank":"","page":""},{"hex":"0xE5","decimal":"229","bank":"","page":""},{"hex":"0xE6","decimal":"230","bank":"","page":""},{"hex":"0xE7","decimal":"231","bank":"","page":""}] | [{"hex":"0xE1","decimal":"225","bank":"","page":"","description":""},{"hex":"0xE2","decimal":"226","bank":"","page":"","description":""},{"hex":"0xE3","decimal":"227","bank":"","page":"","description":""},{"hex":"0xE4","decimal":"228","bank":"","page":"","description":""},{"hex":"0xE5","decimal":"229","bank":"","page":"","description":""},{"hex":"0xE6","decimal":"230","bank":"","page":"","description":""},{"hex":"0xE7","decimal":"231","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 0.500000 | ["Signed 16-bit humidity compensation parameter stored in non-volatile memory.","Unsigned 8-bit humidity compensation parameter stored in non-volatile memory.","Signed 12-bit humidity compensation parameter stored across 0xE4 and the low nibble of 0xE5.","Signed 12-bit humidity compensation parameter stored across the high nibble of 0xE5 and 0xE6.","Signed 8-bit humidity compensation parameter stored in non-volatile memory."] | Calibration data registers for humidity compensation parameters (dig_H2...dig_H6). Memory addresses 0xE1 to 0xE7. | generic grouped calibration description omits some individual signedness/storage detail |
| width_bits | 0.0590 | 0.000000 | 56 | ∅ | truth comparison width_bits=56, extracted=None |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.911308 | corresponding truth field-part collection | [{"register_name":"dig_H2[7:0]","physical_address":{"hex":"0xE1","decimal":"225","bank":"","page":"","description":""},"description":"LSB of dig_H2 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H2[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H2[15:8]","physical_address":{"hex":"0xE2","decimal":"226","bank":"","page":"","description":""},"description":"MSB of dig_H2 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H2[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H3[7:0]","physical_address":{"hex":"0xE3","decimal":"227","bank":"","page":"","description":""},"description":"LSB of dig_H3 (unsigned char)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H3[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H4[11:4]","physical_address":{"hex":"0xE4","decimal":"228","bank":"","page":"","description":""},"description":"Upper nibble of dig_H4 (signed short, bits 11:4)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H4[11:4]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H4[3:0] / dig_H5[11:4]","physical_address":{"hex":"0xE5","decimal":"229","bank":"","page":"","description":""},"description":"Lower nibble of dig_H4 (bits 3:0) and upper nibble of dig_H5 (bits 11:4)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H4[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"dig_H5[11:4]","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H5[3:0]","physical_address":{"hex":"0xE6","decimal":"230","bank":"","page":"","description":""},"description":"Lower nibble of dig_H5 (signed short, bits 3:0)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H5[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H6[7:0]","physical_address":{"hex":"0xE7","decimal":"231","bank":"","page":"","description":""},"description":"LSB of dig_H6 (signed char)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H6[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | "" | "" | correct |
| default_value_description | 0.0334 | 0.000000 | Individual factory-programmed calibration value. | "" | default-value description missing |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×0.000000 + 0.0590×1.000000 + 0.2987×0.911308 + 0.0667×1.000000 + 0.0334×0.000000) / 1.0001 = 0.853008 / 1.0001 = 0.852922

## Extracted logical register 5: ctrl_hum

v17 location: registers[4]; truth association: truth registers[24] (ctrl_hum).
Associated physical locations: 0xF2 (242).

### Bottom layer: bit fields, then field parts

#### Field part 1: ctrl_hum at 0xF2 (242)

Locations: truth registers[24].field_parts[0] ↔ v17 registers[4].field_parts[0].

**Truth bit field 1:  bits 7:3**

Locations: truth registers[24].field_parts[0].bit_field[0] ↔ v17 registers[4].field_parts[0].bit_field[1]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | "" | Reserved | correct |
| field_description | 0.0586 | 1.000000 | "" | "" | correct |
| bit_start | 0.2594 | 1.000000 | 3 | 3 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 5 | 5 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | True | True | correct |
| type_write_read | 0.0583 | 1.000000 | "" | "" | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Truth bit field 2: osrs_h[2:0] bits 2:0**

Locations: truth registers[24].field_parts[0].bit_field[1] ↔ v17 registers[4].field_parts[0].bit_field[0]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | osrs_h[2:0] | osrs_h[2:0] | correct |
| field_description | 0.0586 | 1.000000 | Controls oversampling of humidity data. | Controls oversampling of humidity data. | correct |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 2 | 2 | correct |
| bit_width | 0.0583 | 1.000000 | 3 | 3 | correct |
| values | 0.2097 | 1.000000 | [{"value":"000","value_description":"Skipped (output set to 0x8000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}] | [{"value":"000","value_description":"Skipped (output set to 0x8000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | RW | RW | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000) = 1.000000.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | ctrl_hum | ctrl_hum | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xF2","decimal":"242","bank":"","page":"","description":"Humidity control register."} | {"hex":"0xF2","decimal":"242","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 0.000000 | Humidity data acquisition control register. | "" | description missing |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | RW | RW | correct |
| bit_field | 0.3129 | 1.000000 | truth-target bit-field collection | [{"name_or_parameter":"osrs_h[2:0]","field_description":"Controls oversampling of humidity data.","bit_start":0,"bit_end":2,"bit_width":3,"values":[{"value":"000","value_description":"Skipped (output set to 0x8000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"","bit_start":3,"bit_end":7,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""}] | correct |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000) / 1.0000 = 0.930700 / 1.0000 = 0.930700

### Extracted logical-register aggregation

field_parts correctness = mean(0.930700) = 0.930700.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | ctrl_hum | ctrl_hum | correct |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0xF2","decimal":"242","bank":"","page":"","description":"Humidity control register."}] | [{"hex":"0xF2","decimal":"242","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 1.000000 | Sets humidity data acquisition options; changes become effective only after a write to ctrl_meas. | The "ctrl_hum" register sets the humidity data acquisition options of the device. Changes to this register only become effective after a write operation to "ctrl_meas". | correct |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | RW | RW | correct |
| field_parts | 0.2987 | 0.930700 | corresponding truth field-part collection | [{"register_name":"ctrl_hum","physical_address":{"hex":"0xF2","decimal":"242","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"osrs_h[2:0]","field_description":"Controls oversampling of humidity data.","bit_start":0,"bit_end":2,"bit_width":3,"values":[{"value":"000","value_description":"Skipped (output set to 0x8000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"","bit_start":3,"bit_end":7,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.930700 + 0.0667×1.000000 + 0.0334×1.000000) / 1.0001 = 0.979400 / 1.0001 = 0.979302

## Extracted logical register 6: status

v17 location: registers[5]; truth association: truth registers[23] (status).
Associated physical locations: 0xF3 (243).

### Bottom layer: bit fields, then field parts

#### Field part 1: status at 0xF3 (243)

Locations: truth registers[23].field_parts[0] ↔ v17 registers[5].field_parts[0].

**Truth bit field 1:  bits 7:4**

Locations: truth registers[23].field_parts[0].bit_field[0] ↔ v17 MISSING. Judgment: missing extracted bit-field object.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 0.000000 | "" | ∅ | missing extracted bit-field object |
| field_description | 0.0586 | 0.000000 | "" | ∅ | missing extracted bit-field object |
| bit_start | 0.2594 | 0.000000 | 4 | ∅ | missing extracted bit-field object |
| bit_end | 0.2594 | 0.000000 | 7 | ∅ | missing extracted bit-field object |
| bit_width | 0.0583 | 0.000000 | 4 | ∅ | missing extracted bit-field object |
| values | 0.2097 | 0.000000 | [] | ∅ | missing extracted bit-field object |
| is_reserved | 0.0750 | 0.000000 | True | ∅ | missing extracted bit-field object |
| type_write_read | 0.0583 | 0.000000 | "" | ∅ | missing extracted bit-field object |

Q(bit_field) = (0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000) / 0.9999 = 0.000000 / 0.9999 = 0.000000

**Truth bit field 2: measuring[0] bits 3:3**

Locations: truth registers[23].field_parts[0].bit_field[1] ↔ v17 registers[5].field_parts[0].bit_field[3]. Judgment: truth values are missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | measuring[0] | measuring[0] | correct |
| field_description | 0.0586 | 1.000000 | Indicates whether a conversion is running. | Automatically set to '1' whenever a conversion is running and back to '0' when the results have been transferred to the data registers. | correct |
| bit_start | 0.2594 | 1.000000 | 3 | 3 | correct |
| bit_end | 0.2594 | 1.000000 | 3 | 3 | correct |
| bit_width | 0.0583 | 1.000000 | 1 | 1 | correct |
| values | 0.2097 | 0.000000 | [{"value":"1","value_description":"A conversion is running."},{"value":"0","value_description":"No conversion is running; the bit returns to 0 after the results have been transferred to the data registers."}] | [] | truth values are missing |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.790200 / 0.9999 = 0.790279

**Truth bit field 3:  bits 2:1**

Locations: truth registers[23].field_parts[0].bit_field[2] ↔ v17 MISSING. Judgment: missing extracted bit-field object.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 0.000000 | "" | ∅ | missing extracted bit-field object |
| field_description | 0.0586 | 0.000000 | "" | ∅ | missing extracted bit-field object |
| bit_start | 0.2594 | 0.000000 | 1 | ∅ | missing extracted bit-field object |
| bit_end | 0.2594 | 0.000000 | 2 | ∅ | missing extracted bit-field object |
| bit_width | 0.0583 | 0.000000 | 2 | ∅ | missing extracted bit-field object |
| values | 0.2097 | 0.000000 | [] | ∅ | missing extracted bit-field object |
| is_reserved | 0.0750 | 0.000000 | True | ∅ | missing extracted bit-field object |
| type_write_read | 0.0583 | 0.000000 | "" | ∅ | missing extracted bit-field object |

Q(bit_field) = (0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000) / 0.9999 = 0.000000 / 0.9999 = 0.000000

**Truth bit field 4: im_update[0] bits 0:0**

Locations: truth registers[23].field_parts[0].bit_field[3] ↔ v17 registers[5].field_parts[0].bit_field[0]. Judgment: truth name 'im_update[0]' differs from extracted 'Reserved'; description missing; truth values are missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted=''.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 0.000000 | im_update[0] | Reserved | truth name 'im_update[0]' differs from extracted 'Reserved'; description missing; truth values are missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| field_description | 0.0586 | 0.000000 | Indicates whether NVM data are being copied to image registers. The data are copied at power-on reset and before every conversion. | "" | truth name 'im_update[0]' differs from extracted 'Reserved'; description missing; truth values are missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_width | 0.0583 | 1.000000 | 1 | 1 | correct |
| values | 0.2097 | 0.000000 | [{"value":"1","value_description":"NVM data are being copied to image registers."},{"value":"0","value_description":"Copying is done."}] | [] | truth name 'im_update[0]' differs from extracted 'Reserved'; description missing; truth values are missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| is_reserved | 0.0750 | 0.000000 | False | True | truth name 'im_update[0]' differs from extracted 'Reserved'; description missing; truth values are missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| type_write_read | 0.0583 | 0.000000 | R | "" | truth name 'im_update[0]' differs from extracted 'Reserved'; description missing; truth values are missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |

Q(bit_field) = (0.0212×0.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000) / 0.9999 = 0.577100 / 0.9999 = 0.577158

**Field-part aggregation**

bit_field correctness = mean(0.000000, 0.790279, 0.000000, 0.577158) = 0.341859.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | status | status | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xF3","decimal":"243","bank":"","page":"","description":"Device status register."} | {"hex":"0xF3","decimal":"243","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 0.000000 | Device status register. | "" | description missing |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.341859 | truth-target bit-field collection | [{"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Reserved","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Reserved","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"measuring[0]","field_description":"Automatically set to '1' whenever a conversion is running and back to '0' when the results have been transferred to the data registers.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":6,"bit_width":3,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"im_update[0]","field_description":"Automatically set to '1' when the NVM data are being copied to image registers and back to '0' when the copying is done. The data are copied at power-on-reset and before every conversion.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.341859) / 1.0000 = 0.724768 / 1.0000 = 0.724768

### Extracted logical-register aggregation

field_parts correctness = mean(0.724768) = 0.724768.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | status | status | correct |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0xF3","decimal":"243","bank":"","page":"","description":"Device status register."}] | [{"hex":"0xF3","decimal":"243","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 0.500000 | Contains bits indicating conversion activity and NVM-to-image-register copying status. | The "status" register contains two bits which indicate the status of the device. | status purpose is identified but the individual conversion/copy meanings are incomplete |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.724768 | corresponding truth field-part collection | [{"register_name":"status","physical_address":{"hex":"0xF3","decimal":"243","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Reserved","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Reserved","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"measuring[0]","field_description":"Automatically set to '1' whenever a conversion is running and back to '0' when the results have been transferred to the data registers.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":6,"bit_width":3,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"im_update[0]","field_description":"Automatically set to '1' when the NVM data are being copied to image registers and back to '0' when the copying is done. The data are copied at power-on-reset and before every conversion.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.724768 + 0.0667×1.000000 + 0.0334×1.000000) / 1.0001 = 0.889688 / 1.0001 = 0.889599

## Extracted logical register 7: ctrl_meas

v17 location: registers[6]; truth association: truth registers[22] (ctrl_meas).
Associated physical locations: 0xF4 (244).

### Bottom layer: bit fields, then field parts

#### Field part 1: ctrl_meas at 0xF4 (244)

Locations: truth registers[22].field_parts[0] ↔ v17 registers[6].field_parts[0].

**Truth bit field 1: osrs_t[2:0] bits 7:5**

Locations: truth registers[22].field_parts[0].bit_field[0] ↔ v17 registers[6].field_parts[0].bit_field[0]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | osrs_t[2:0] | osrs_t[2:0] | correct |
| field_description | 0.0586 | 1.000000 | Controls oversampling of temperature data. | Controls oversampling of temperature data. | correct |
| bit_start | 0.2594 | 1.000000 | 5 | 5 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 3 | 3 | correct |
| values | 0.2097 | 1.000000 | [{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}] | [{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | RW | RW | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Truth bit field 2: osrs_p[2:0] bits 4:2**

Locations: truth registers[22].field_parts[0].bit_field[1] ↔ v17 registers[6].field_parts[0].bit_field[1]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | osrs_p[2:0] | osrs_p[2:0] | correct |
| field_description | 0.0586 | 1.000000 | Controls oversampling of pressure data. | Controls oversampling of pressure data. | correct |
| bit_start | 0.2594 | 1.000000 | 2 | 2 | correct |
| bit_end | 0.2594 | 1.000000 | 4 | 4 | correct |
| bit_width | 0.0583 | 1.000000 | 3 | 3 | correct |
| values | 0.2097 | 1.000000 | [{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}] | [{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | RW | RW | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Truth bit field 3: mode[1:0] bits 1:0**

Locations: truth registers[22].field_parts[0].bit_field[2] ↔ v17 registers[6].field_parts[0].bit_field[2]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | mode[1:0] | mode[1:0] | correct |
| field_description | 0.0586 | 1.000000 | Controls the sensor mode of the device. | Controls the sensor mode of the device. | correct |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 1 | 1 | correct |
| bit_width | 0.0583 | 1.000000 | 2 | 2 | correct |
| values | 0.2097 | 1.000000 | [{"value":"00","value_description":"Sleep mode"},{"value":"01 and 10","value_description":"Forced mode"},{"value":"11","value_description":"Normal mode"}] | [{"value":"00","value_description":"Sleep mode"},{"value":"01 and 10","value_description":"Forced mode"},{"value":"11","value_description":"Normal mode"}] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | RW | RW | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000) = 1.000000.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | ctrl_meas | ctrl_meas | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xF4","decimal":"244","bank":"","page":"","description":"Measurement control register."} | {"hex":"0xF4","decimal":"244","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 0.000000 | Pressure and temperature data acquisition control register. | "" | description missing |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | RW | RW | correct |
| bit_field | 0.3129 | 1.000000 | truth-target bit-field collection | [{"name_or_parameter":"osrs_t[2:0]","field_description":"Controls oversampling of temperature data.","bit_start":5,"bit_end":7,"bit_width":3,"values":[{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"osrs_p[2:0]","field_description":"Controls oversampling of pressure data.","bit_start":2,"bit_end":4,"bit_width":3,"values":[{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"mode[1:0]","field_description":"Controls the sensor mode of the device.","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"00","value_description":"Sleep mode"},{"value":"01 and 10","value_description":"Forced mode"},{"value":"11","value_description":"Normal mode"}],"is_reserved":false,"type_write_read":"RW"}] | correct |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000) / 1.0000 = 0.930700 / 1.0000 = 0.930700

### Extracted logical-register aggregation

field_parts correctness = mean(0.930700) = 0.930700.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | ctrl_meas | ctrl_meas | correct |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0xF4","decimal":"244","bank":"","page":"","description":"Measurement control register."}] | [{"hex":"0xF4","decimal":"244","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 1.000000 | Sets pressure and temperature data acquisition options and must be written after changing ctrl_hum for those changes to become effective. | The "ctrl_meas" register sets the pressure and temperature data acquisition options of the device. The register needs to be written after changing "ctrl_hum" for the changes to become effective. | correct |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | RW | RW | correct |
| field_parts | 0.2987 | 0.930700 | corresponding truth field-part collection | [{"register_name":"ctrl_meas","physical_address":{"hex":"0xF4","decimal":"244","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"osrs_t[2:0]","field_description":"Controls oversampling of temperature data.","bit_start":5,"bit_end":7,"bit_width":3,"values":[{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"osrs_p[2:0]","field_description":"Controls oversampling of pressure data.","bit_start":2,"bit_end":4,"bit_width":3,"values":[{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"mode[1:0]","field_description":"Controls the sensor mode of the device.","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"00","value_description":"Sleep mode"},{"value":"01 and 10","value_description":"Forced mode"},{"value":"11","value_description":"Normal mode"}],"is_reserved":false,"type_write_read":"RW"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.930700 + 0.0667×1.000000 + 0.0334×1.000000) / 1.0001 = 0.979400 / 1.0001 = 0.979302

## Extracted logical register 8: config

v17 location: registers[7]; truth association: truth registers[18] (config).
Associated physical locations: 0xF5 (245).

### Bottom layer: bit fields, then field parts

#### Field part 1: config at 0xF5 (245)

Locations: truth registers[18].field_parts[0] ↔ v17 registers[7].field_parts[0].

**Truth bit field 1: t_sb[2:0] bits 7:5**

Locations: truth registers[18].field_parts[0].bit_field[0] ↔ v17 registers[7].field_parts[0].bit_field[0]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | t_sb[2:0] | t_sb[2:0] | correct |
| field_description | 0.0586 | 1.000000 | Controls inactive duration t_standby in normal mode. | Controls inactive duration t_standby in normal mode. | correct |
| bit_start | 0.2594 | 1.000000 | 5 | 5 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 3 | 3 | correct |
| values | 0.2097 | 1.000000 | [{"value":"000","value_description":"0.5 ms"},{"value":"001","value_description":"62.5 ms"},{"value":"010","value_description":"125 ms"},{"value":"011","value_description":"250 ms"},{"value":"100","value_description":"500 ms"},{"value":"101","value_description":"1000 ms"},{"value":"110","value_description":"10 ms"},{"value":"111","value_description":"20 ms"}] | [{"value":"000","value_description":"0.5 ms"},{"value":"001","value_description":"62.5 ms"},{"value":"010","value_description":"125 ms"},{"value":"011","value_description":"250 ms"},{"value":"100","value_description":"500 ms"},{"value":"101","value_description":"1000 ms"},{"value":"110","value_description":"10 ms"},{"value":"111","value_description":"20 ms"}] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | RW | RW | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Truth bit field 2: filter[2:0] bits 4:2**

Locations: truth registers[18].field_parts[0].bit_field[1] ↔ v17 registers[7].field_parts[0].bit_field[1]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | filter[2:0] | filter[2:0] | correct |
| field_description | 0.0586 | 1.000000 | Controls the time constant of the IIR filter. | Controls the time constant of the IIR filter. | correct |
| bit_start | 0.2594 | 1.000000 | 2 | 2 | correct |
| bit_end | 0.2594 | 1.000000 | 4 | 4 | correct |
| bit_width | 0.0583 | 1.000000 | 3 | 3 | correct |
| values | 0.2097 | 1.000000 | [{"value":"000","value_description":"Filter off"},{"value":"001","value_description":"Filter coefficient 2"},{"value":"010","value_description":"Filter coefficient 4"},{"value":"011","value_description":"Filter coefficient 8"},{"value":"100, others","value_description":"Filter coefficient 16"}] | [{"value":"000","value_description":"Filter off"},{"value":"001","value_description":"2"},{"value":"010","value_description":"4"},{"value":"011","value_description":"8"},{"value":"100, others","value_description":"16"}] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | RW | RW | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Truth bit field 3:  bits 1:1**

Locations: truth registers[18].field_parts[0].bit_field[2] ↔ v17 registers[7].field_parts[0].bit_field[2]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | "" | Reserved | correct |
| field_description | 0.0586 | 1.000000 | "" | "" | correct |
| bit_start | 0.2594 | 1.000000 | 1 | 1 | correct |
| bit_end | 0.2594 | 1.000000 | 1 | 1 | correct |
| bit_width | 0.0583 | 1.000000 | 1 | 1 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | True | True | correct |
| type_write_read | 0.0583 | 1.000000 | "" | "" | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Truth bit field 4: spi3w_en[0] bits 0:0**

Locations: truth registers[18].field_parts[0].bit_field[3] ↔ v17 registers[7].field_parts[0].bit_field[3]. Judgment: truth values are missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | spi3w_en[0] | spi3w_en[0] | correct |
| field_description | 0.0586 | 1.000000 | Enables the 3-wire SPI interface when set to '1'. | Enables 3-wire SPI interface when set to '1'. | correct |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_width | 0.0583 | 1.000000 | 1 | 1 | correct |
| values | 0.2097 | 0.000000 | [{"value":"1","value_description":"3-wire SPI interface enabled."}] | [] | truth values are missing |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | RW | RW | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.790200 / 0.9999 = 0.790279

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 0.790279) = 0.947570.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | config | config | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xF5","decimal":"245","bank":"","page":"","description":"Configuration register."} | {"hex":"0xF5","decimal":"245","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 0.000000 | Rate, filter and interface configuration register. | "" | description missing |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | RW | RW | correct |
| bit_field | 0.3129 | 0.947570 | truth-target bit-field collection | [{"name_or_parameter":"t_sb[2:0]","field_description":"Controls inactive duration t_standby in normal mode.","bit_start":5,"bit_end":7,"bit_width":3,"values":[{"value":"000","value_description":"0.5 ms"},{"value":"001","value_description":"62.5 ms"},{"value":"010","value_description":"125 ms"},{"value":"011","value_description":"250 ms"},{"value":"100","value_description":"500 ms"},{"value":"101","value_description":"1000 ms"},{"value":"110","value_description":"10 ms"},{"value":"111","value_description":"20 ms"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"filter[2:0]","field_description":"Controls the time constant of the IIR filter.","bit_start":2,"bit_end":4,"bit_width":3,"values":[{"value":"000","value_description":"Filter off"},{"value":"001","value_description":"2"},{"value":"010","value_description":"4"},{"value":"011","value_description":"8"},{"value":"100, others","value_description":"16"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"spi3w_en[0]","field_description":"Enables 3-wire SPI interface when set to '1'.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.947570) / 1.0000 = 0.914295 / 1.0000 = 0.914295

### Extracted logical-register aggregation

field_parts correctness = mean(0.914295) = 0.914295.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | config | config | correct |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0xF5","decimal":"245","bank":"","page":"","description":"Configuration register."}] | [{"hex":"0xF5","decimal":"245","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 1.000000 | Sets the rate, filter and interface options of the device; writes in normal mode may be ignored. In sleep mode writes are not ignored. | The "config" register sets the rate, filter and interface options of the device. Writes to the "config" register in normal mode may be ignored. In sleep mode writes are not ignored. | correct |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | RW | RW | correct |
| field_parts | 0.2987 | 0.914295 | corresponding truth field-part collection | [{"register_name":"config","physical_address":{"hex":"0xF5","decimal":"245","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"t_sb[2:0]","field_description":"Controls inactive duration t_standby in normal mode.","bit_start":5,"bit_end":7,"bit_width":3,"values":[{"value":"000","value_description":"0.5 ms"},{"value":"001","value_description":"62.5 ms"},{"value":"010","value_description":"125 ms"},{"value":"011","value_description":"250 ms"},{"value":"100","value_description":"500 ms"},{"value":"101","value_description":"1000 ms"},{"value":"110","value_description":"10 ms"},{"value":"111","value_description":"20 ms"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"filter[2:0]","field_description":"Controls the time constant of the IIR filter.","bit_start":2,"bit_end":4,"bit_width":3,"values":[{"value":"000","value_description":"Filter off"},{"value":"001","value_description":"2"},{"value":"010","value_description":"4"},{"value":"011","value_description":"8"},{"value":"100, others","value_description":"16"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"spi3w_en[0]","field_description":"Enables 3-wire SPI interface when set to '1'.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.914295 + 0.0667×1.000000 + 0.0334×1.000000) / 1.0001 = 0.974500 / 1.0001 = 0.974402

## Extracted logical register 9: press

v17 location: registers[8]; truth association: truth registers[21] (press).
Associated physical locations: 0xF7 (247), 0xF8 (248), 0xF9 (249).

### Bottom layer: bit fields, then field parts

#### Field part 1: press_msb at 0xF7 (247)

Locations: truth registers[21].field_parts[0] ↔ v17 registers[8].field_parts[0].

**Truth bit field 1: press_msb[7:0] bits 7:0**

Locations: truth registers[21].field_parts[0].bit_field[0] ↔ v17 registers[8].field_parts[0].bit_field[0]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | press_msb[7:0] | press_msb[7:0] | correct |
| field_description | 0.0586 | 1.000000 | MSB part up[19:12] of the raw pressure measurement output. | MSB part up[19:12] of the raw pressure measurement output data. | correct |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Field-part aggregation**

bit_field correctness = mean(1.000000) = 1.000000.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | press_msb | press_msb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xF7","decimal":"247","bank":"","page":"","description":"Pressure MSB."} | {"hex":"0xF7","decimal":"247","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | MSB part up[19:12] of the raw pressure output. | Contains the MSB part up[19:12] of the raw pressure measurement output data. | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 1.000000 | truth-target bit-field collection | [{"name_or_parameter":"press_msb[7:0]","field_description":"MSB part up[19:12] of the raw pressure measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | correct |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000) / 1.0000 = 1.000000 / 1.0000 = 1.000000

#### Field part 2: press_lsb at 0xF8 (248)

Locations: truth registers[21].field_parts[1] ↔ v17 registers[8].field_parts[1].

**Truth bit field 1: press_lsb[7:0] bits 7:0**

Locations: truth registers[21].field_parts[1].bit_field[0] ↔ v17 registers[8].field_parts[1].bit_field[0]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | press_lsb[7:0] | press_lsb[7:0] | correct |
| field_description | 0.0586 | 1.000000 | LSB part up[11:4] of the raw pressure measurement output. | LSB part up[11:4] of the raw pressure measurement output data. | correct |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Field-part aggregation**

bit_field correctness = mean(1.000000) = 1.000000.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | press_lsb | press_lsb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xF8","decimal":"248","bank":"","page":"","description":"Pressure LSB."} | {"hex":"0xF8","decimal":"248","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | LSB part up[11:4] of the raw pressure output. | Contains the LSB part up[11:4] of the raw pressure measurement output data. | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 1.000000 | truth-target bit-field collection | [{"name_or_parameter":"press_lsb[7:0]","field_description":"LSB part up[11:4] of the raw pressure measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | correct |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000) / 1.0000 = 1.000000 / 1.0000 = 1.000000

#### Field part 3: press_xlsb at 0xF9 (249)

Locations: truth registers[21].field_parts[2] ↔ v17 registers[8].field_parts[2].

**Truth bit field 1: press_xlsb[3:0] bits 7:4**

Locations: truth registers[21].field_parts[2].bit_field[0] ↔ v17 registers[8].field_parts[2].bit_field[1]. Judgment: truth name 'press_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted=''.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 0.000000 | press_xlsb[3:0] | Reserved | truth name 'press_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| field_description | 0.0586 | 0.000000 | XLSB part up[3:0] of the raw pressure measurement output. | "" | truth name 'press_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| bit_start | 0.2594 | 1.000000 | 4 | 4 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 4 | 4 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 0.000000 | False | True | truth name 'press_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| type_write_read | 0.0583 | 0.000000 | R | "" | truth name 'press_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |

Q(bit_field) = (0.0212×0.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×0.000000 + 0.0583×0.000000) / 0.9999 = 0.786800 / 0.9999 = 0.786879

**Truth bit field 2: 0 bits 3:0**

Locations: truth registers[21].field_parts[2].bit_field[1], truth registers[21].field_parts[2].bit_field[2], truth registers[21].field_parts[2].bit_field[3], truth registers[21].field_parts[2].bit_field[4] ↔ v17 registers[8].field_parts[2].bit_field[0]. Judgment: truth fixed-zero label is '0', extracted label is 'press_xlsb[3:0]'; type_write_read truth='', extracted='R'.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 0.000000 | 0 | press_xlsb[3:0] | truth fixed-zero label is '0', extracted label is 'press_xlsb[3:0]'; type_write_read truth='', extracted='R' |
| field_description | 0.0586 | 1.000000 | Shown as 0 in the memory map. | XLSB part up[3:0] of the raw pressure measurement output data. Bits 7:4 are unused. | correct |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 3 | 3 | correct |
| bit_width | 0.0583 | 1.000000 | 4 | 4 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 0.000000 | "" | R | truth fixed-zero label is '0', extracted label is 'press_xlsb[3:0]'; type_write_read truth='', extracted='R' |

Q(bit_field) = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000) / 0.9999 = 0.920400 / 0.9999 = 0.920492

**Field-part aggregation**

bit_field correctness = mean(0.786879, 0.920492) = 0.853685.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | press_xlsb | press_xlsb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xF9","decimal":"249","bank":"","page":"","description":"Pressure XLSB in bits 7:4."} | {"hex":"0xF9","decimal":"249","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 0.500000 | XLSB part up[3:0] in bits 7:4. | Contains the XLSB part up[3:0] of the raw pressure measurement output data. Contents depend on temperature resolution. | XLSB function is present but bit-location/dependency wording is incomplete or contradictory |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.853685 | truth-target bit-field collection | [{"name_or_parameter":"press_xlsb[3:0]","field_description":"XLSB part up[3:0] of the raw pressure measurement output data. Bits 7:4 are unused.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.500000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.853685) / 1.0000 = 0.919568 / 1.0000 = 0.919568

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000, 0.919568) = 0.973189.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | press | press | correct |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0xF7","decimal":"247","bank":"","page":"","description":"Pressure MSB."},{"hex":"0xF8","decimal":"248","bank":"","page":"","description":"Pressure LSB."},{"hex":"0xF9","decimal":"249","bank":"","page":"","description":"Pressure XLSB in bits 7:4."}] | [{"hex":"0xF7","decimal":"247","bank":"","page":"","description":""},{"hex":"0xF8","decimal":"248","bank":"","page":"","description":""},{"hex":"0xF9","decimal":"249","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 1.000000 | Contains the unsigned 20-bit raw pressure measurement output up[19:0]. | The "press" register contains the raw pressure measurement output data up[19:0]. For details on how to read out the pressure and temperature information from the device, please consult chapter 4. | correct |
| width_bits | 0.0590 | 1.000000 | 20 | 20 | correct |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.973189 | corresponding truth field-part collection | [{"register_name":"press_msb","physical_address":{"hex":"0xF7","decimal":"247","bank":"","page":"","description":""},"description":"Contains the MSB part up[19:12] of the raw pressure measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"press_msb[7:0]","field_description":"MSB part up[19:12] of the raw pressure measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"press_lsb","physical_address":{"hex":"0xF8","decimal":"248","bank":"","page":"","description":""},"description":"Contains the LSB part up[11:4] of the raw pressure measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"press_lsb[7:0]","field_description":"LSB part up[11:4] of the raw pressure measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"press_xlsb","physical_address":{"hex":"0xF9","decimal":"249","bank":"","page":"","description":""},"description":"Contains the XLSB part up[3:0] of the raw pressure measurement output data. Contents depend on temperature resolution.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"press_xlsb[3:0]","field_description":"XLSB part up[3:0] of the raw pressure measurement output data. Bits 7:4 are unused.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 0.000000 | 0x80000 | "" | truth default_value='0x80000', extracted='' |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.973189 + 0.0667×0.000000 + 0.0334×1.000000) / 1.0001 = 0.925392 / 1.0001 = 0.925299

## Extracted logical register 10: temp

v17 location: registers[9]; truth association: truth registers[20] (temp).
Associated physical locations: 0xFA (250), 0xFB (251), 0xFC (252).

### Bottom layer: bit fields, then field parts

#### Field part 1: temp_msb at 0xFA (250)

Locations: truth registers[20].field_parts[0] ↔ v17 registers[9].field_parts[0].

**Truth bit field 1: temp_msb[7:0] bits 7:0**

Locations: truth registers[20].field_parts[0].bit_field[0] ↔ v17 registers[9].field_parts[0].bit_field[0]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | temp_msb[7:0] | temp_msb[7:0] | correct |
| field_description | 0.0586 | 1.000000 | MSB part ut[19:12] of the raw temperature measurement output. | MSB part ut[19:12] of the raw temperature measurement output data. | correct |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Field-part aggregation**

bit_field correctness = mean(1.000000) = 1.000000.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | temp_msb | temp_msb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xFA","decimal":"250","bank":"","page":"","description":"Temperature MSB."} | {"hex":"0xFA","decimal":"250","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | MSB part ut[19:12] of the raw temperature output. | Contains the MSB part ut[19:12] of the raw temperature measurement output data. | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 1.000000 | truth-target bit-field collection | [{"name_or_parameter":"temp_msb[7:0]","field_description":"MSB part ut[19:12] of the raw temperature measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | correct |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000) / 1.0000 = 1.000000 / 1.0000 = 1.000000

#### Field part 2: temp_lsb at 0xFB (251)

Locations: truth registers[20].field_parts[1] ↔ v17 registers[9].field_parts[1].

**Truth bit field 1: temp_lsb[7:0] bits 7:0**

Locations: truth registers[20].field_parts[1].bit_field[0] ↔ v17 registers[9].field_parts[1].bit_field[0]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | temp_lsb[7:0] | temp_lsb[7:0] | correct |
| field_description | 0.0586 | 1.000000 | LSB part ut[11:4] of the raw temperature measurement output. | LSB part ut[11:4] of the raw temperature measurement output data. | correct |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Field-part aggregation**

bit_field correctness = mean(1.000000) = 1.000000.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | temp_lsb | temp_lsb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xFB","decimal":"251","bank":"","page":"","description":"Temperature LSB."} | {"hex":"0xFB","decimal":"251","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | LSB part ut[11:4] of the raw temperature output. | Contains the LSB part ut[11:4] of the raw temperature measurement output data. | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 1.000000 | truth-target bit-field collection | [{"name_or_parameter":"temp_lsb[7:0]","field_description":"LSB part ut[11:4] of the raw temperature measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | correct |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000) / 1.0000 = 1.000000 / 1.0000 = 1.000000

#### Field part 3: temp_xlsb at 0xFC (252)

Locations: truth registers[20].field_parts[2] ↔ v17 registers[9].field_parts[2].

**Truth bit field 1: temp_xlsb[3:0] bits 7:4**

Locations: truth registers[20].field_parts[2].bit_field[0] ↔ v17 registers[9].field_parts[2].bit_field[1]. Judgment: truth name 'temp_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted=''.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 0.000000 | temp_xlsb[3:0] | Reserved | truth name 'temp_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| field_description | 0.0586 | 0.000000 | XLSB part ut[3:0] of the raw temperature measurement output. | "" | truth name 'temp_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| bit_start | 0.2594 | 1.000000 | 4 | 4 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 4 | 4 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 0.000000 | False | True | truth name 'temp_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| type_write_read | 0.0583 | 0.000000 | R | "" | truth name 'temp_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |

Q(bit_field) = (0.0212×0.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×0.000000 + 0.0583×0.000000) / 0.9999 = 0.786800 / 0.9999 = 0.786879

**Truth bit field 2: 0 bits 3:0**

Locations: truth registers[20].field_parts[2].bit_field[1], truth registers[20].field_parts[2].bit_field[2], truth registers[20].field_parts[2].bit_field[3], truth registers[20].field_parts[2].bit_field[4] ↔ v17 registers[9].field_parts[2].bit_field[0]. Judgment: truth fixed-zero label is '0', extracted label is 'temp_xlsb[3:0]'; type_write_read truth='', extracted='R'.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 0.000000 | 0 | temp_xlsb[3:0] | truth fixed-zero label is '0', extracted label is 'temp_xlsb[3:0]'; type_write_read truth='', extracted='R' |
| field_description | 0.0586 | 1.000000 | Shown as 0 in the memory map. | XLSB part ut[3:0] of the raw temperature measurement output data. Bits 7:4 are unused. | correct |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 3 | 3 | correct |
| bit_width | 0.0583 | 1.000000 | 4 | 4 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 0.000000 | "" | R | truth fixed-zero label is '0', extracted label is 'temp_xlsb[3:0]'; type_write_read truth='', extracted='R' |

Q(bit_field) = (0.0212×0.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000) / 0.9999 = 0.920400 / 0.9999 = 0.920492

**Field-part aggregation**

bit_field correctness = mean(0.786879, 0.920492) = 0.853685.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | temp_xlsb | temp_xlsb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xFC","decimal":"252","bank":"","page":"","description":"Temperature XLSB in bits 7:4."} | {"hex":"0xFC","decimal":"252","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 0.500000 | XLSB part ut[3:0] in bits 7:4. | Contains the XLSB part ut[3:0] of the raw temperature measurement output data. Contents depend on pressure resolution. | XLSB function is present but bit-location/dependency wording is incomplete or contradictory |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.853685 | truth-target bit-field collection | [{"name_or_parameter":"temp_xlsb[3:0]","field_description":"XLSB part ut[3:0] of the raw temperature measurement output data. Bits 7:4 are unused.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.500000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.853685) / 1.0000 = 0.919568 / 1.0000 = 0.919568

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000, 0.919568) = 0.973189.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | temp | temp | correct |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0xFA","decimal":"250","bank":"","page":"","description":"Temperature MSB."},{"hex":"0xFB","decimal":"251","bank":"","page":"","description":"Temperature LSB."},{"hex":"0xFC","decimal":"252","bank":"","page":"","description":"Temperature XLSB in bits 7:4."}] | [{"hex":"0xFA","decimal":"250","bank":"","page":"","description":""},{"hex":"0xFB","decimal":"251","bank":"","page":"","description":""},{"hex":"0xFC","decimal":"252","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 1.000000 | Contains the unsigned 20-bit raw temperature measurement output ut[19:0]. | The "temp" register contains the raw temperature measurement output data ut[19:0]. For details on how to read out the pressure and temperature information from the device, please consult chapter 4. | correct |
| width_bits | 0.0590 | 1.000000 | 20 | 20 | correct |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.973189 | corresponding truth field-part collection | [{"register_name":"temp_msb","physical_address":{"hex":"0xFA","decimal":"250","bank":"","page":"","description":""},"description":"Contains the MSB part ut[19:12] of the raw temperature measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"temp_msb[7:0]","field_description":"MSB part ut[19:12] of the raw temperature measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"temp_lsb","physical_address":{"hex":"0xFB","decimal":"251","bank":"","page":"","description":""},"description":"Contains the LSB part ut[11:4] of the raw temperature measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"temp_lsb[7:0]","field_description":"LSB part ut[11:4] of the raw temperature measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"temp_xlsb","physical_address":{"hex":"0xFC","decimal":"252","bank":"","page":"","description":""},"description":"Contains the XLSB part ut[3:0] of the raw temperature measurement output data. Contents depend on pressure resolution.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"temp_xlsb[3:0]","field_description":"XLSB part ut[3:0] of the raw temperature measurement output data. Bits 7:4 are unused.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 0.000000 | 0x80000 | "" | truth default_value='0x80000', extracted='' |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.973189 + 0.0667×0.000000 + 0.0334×1.000000) / 1.0001 = 0.925392 / 1.0001 = 0.925299

## Extracted logical register 11: hum

v17 location: registers[10]; truth association: truth registers[19] (hum).
Associated physical locations: 0xFD (253), 0xFE (254).

### Bottom layer: bit fields, then field parts

#### Field part 1: hum_msb at 0xFD (253)

Locations: truth registers[19].field_parts[0] ↔ v17 registers[10].field_parts[0].

**Truth bit field 1: hum_msb[7:0] bits 7:0**

Locations: truth registers[19].field_parts[0].bit_field[0] ↔ v17 registers[10].field_parts[0].bit_field[0]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | hum_msb[7:0] | hum_msb[7:0] | correct |
| field_description | 0.0586 | 1.000000 | MSB part uh[15:8] of the raw humidity measurement output. | MSB part uh[15:8] of the raw humidity measurement output data. | correct |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Field-part aggregation**

bit_field correctness = mean(1.000000) = 1.000000.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | hum_msb | hum_msb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xFD","decimal":"253","bank":"","page":"","description":"Humidity MSB."} | {"hex":"0xFD","decimal":"253","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | MSB part uh[15:8] of the raw humidity output. | Contains the MSB part uh[15:8] of the raw humidity measurement output data. | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 1.000000 | truth-target bit-field collection | [{"name_or_parameter":"hum_msb[7:0]","field_description":"MSB part uh[15:8] of the raw humidity measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | correct |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000) / 1.0000 = 1.000000 / 1.0000 = 1.000000

#### Field part 2: hum_lsb at 0xFE (254)

Locations: truth registers[19].field_parts[1] ↔ v17 registers[10].field_parts[1].

**Truth bit field 1: hum_lsb[7:0] bits 7:0**

Locations: truth registers[19].field_parts[1].bit_field[0] ↔ v17 registers[10].field_parts[1].bit_field[0]. Judgment: all deepest fields correct.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | hum_lsb[7:0] | hum_lsb[7:0] | correct |
| field_description | 0.0586 | 1.000000 | LSB part uh[7:0] of the raw humidity measurement output. | LSB part uh[7:0] of the raw humidity measurement output data. | correct |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.999900 / 0.9999 = 1.000000

**Field-part aggregation**

bit_field correctness = mean(1.000000) = 1.000000.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | hum_lsb | hum_lsb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xFE","decimal":"254","bank":"","page":"","description":"Humidity LSB."} | {"hex":"0xFE","decimal":"254","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | LSB part uh[7:0] of the raw humidity output. | Contains the LSB part uh[7:0] of the raw humidity measurement output data. | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 1.000000 | truth-target bit-field collection | [{"name_or_parameter":"hum_lsb[7:0]","field_description":"LSB part uh[7:0] of the raw humidity measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | correct |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000) / 1.0000 = 1.000000 / 1.0000 = 1.000000

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000) = 1.000000.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | hum | hum | correct |
| physical_address | 0.4044 | 1.000000 | [{"hex":"0xFD","decimal":"253","bank":"","page":"","description":"Humidity MSB."},{"hex":"0xFE","decimal":"254","bank":"","page":"","description":"Humidity LSB."}] | [{"hex":"0xFD","decimal":"253","bank":"","page":"","description":""},{"hex":"0xFE","decimal":"254","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 1.000000 | Contains the unsigned 16-bit raw humidity measurement output uh[15:0]. | The "hum" register contains the raw humidity measurement output data uh[15:0]. | correct |
| width_bits | 0.0590 | 1.000000 | 16 | 16 | correct |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 1.000000 | corresponding truth field-part collection | [{"register_name":"hum_msb","physical_address":{"hex":"0xFD","decimal":"253","bank":"","page":"","description":""},"description":"Contains the MSB part uh[15:8] of the raw humidity measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"hum_msb[7:0]","field_description":"MSB part uh[15:8] of the raw humidity measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"hum_lsb","physical_address":{"hex":"0xFE","decimal":"254","bank":"","page":"","description":""},"description":"Contains the LSB part uh[7:0] of the raw humidity measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"hum_lsb[7:0]","field_description":"LSB part uh[7:0] of the raw humidity measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | correct |
| default_value | 0.0667 | 0.000000 | 0x8000 | "" | truth default_value='0x8000', extracted='' |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×0.000000 + 0.0334×1.000000) / 1.0001 = 0.933400 / 1.0001 = 0.933307

## Extracted logical register 12: press_msb

v17 location: registers[11]; equivalent split association with truth press physical part.
Associated physical locations: 0xF7 (247).

### Bottom layer: bit fields, then field parts

#### Field part 1: press_msb at 0xF7 (247)

Locations: truth registers[21].field_parts[0] ↔ v17 registers[11].field_parts[0].

**Truth bit field 1: press_msb[7:0] bits 7:0**

Locations: truth registers[21].field_parts[0].bit_field[0] ↔ v17 registers[11].field_parts[0].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | press_msb[7:0] | press_msb[7:0] | correct |
| field_description | 0.0586 | 0.000000 | MSB part up[19:12] of the raw pressure measurement output. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | press_msb | press_msb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xF7","decimal":"247","bank":"","page":"","description":"Pressure MSB."} | {"hex":"0xF7","decimal":"247","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | MSB part up[19:12] of the raw pressure output. | Contains the MSB part up[19:12] of the raw pressure measurement output data. | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"press_msb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

### Extracted logical-register aggregation

field_parts correctness = mean(0.981662) = 0.981662.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | press_msb | press_msb | correct |
| physical_address | 0.4044 | 1.000000 | {"hex":"0xF7","decimal":"247","bank":"","page":"","description":"Pressure MSB."} | [{"hex":"0xF7","decimal":"247","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 0.000000 | MSB part up[19:12] of the raw pressure output. | "" | register description missing |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.981662 | corresponding truth field-part collection | [{"register_name":"press_msb","physical_address":{"hex":"0xF7","decimal":"247","bank":"","page":"","description":""},"description":"Contains the MSB part up[19:12] of the raw pressure measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"press_msb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | 0x80 | 0x80 | correct |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981662 + 0.0667×1.000000 + 0.0334×1.000000) / 1.0001 = 0.938223 / 1.0001 = 0.938129

## Extracted logical register 13: press_lsb

v17 location: registers[12]; equivalent split association with truth press physical part.
Associated physical locations: 0xF8 (248).

### Bottom layer: bit fields, then field parts

#### Field part 1: press_lsb at 0xF8 (248)

Locations: truth registers[21].field_parts[1] ↔ v17 registers[12].field_parts[0].

**Truth bit field 1: press_lsb[7:0] bits 7:0**

Locations: truth registers[21].field_parts[1].bit_field[0] ↔ v17 registers[12].field_parts[0].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | press_lsb[7:0] | press_lsb[7:0] | correct |
| field_description | 0.0586 | 0.000000 | LSB part up[11:4] of the raw pressure measurement output. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | press_lsb | press_lsb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xF8","decimal":"248","bank":"","page":"","description":"Pressure LSB."} | {"hex":"0xF8","decimal":"248","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | LSB part up[11:4] of the raw pressure output. | Contains the LSB part up[11:4] of the raw pressure measurement output data. | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"press_lsb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

### Extracted logical-register aggregation

field_parts correctness = mean(0.981662) = 0.981662.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | press_lsb | press_lsb | correct |
| physical_address | 0.4044 | 1.000000 | {"hex":"0xF8","decimal":"248","bank":"","page":"","description":"Pressure LSB."} | [{"hex":"0xF8","decimal":"248","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 0.000000 | LSB part up[11:4] of the raw pressure output. | "" | register description missing |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.981662 | corresponding truth field-part collection | [{"register_name":"press_lsb","physical_address":{"hex":"0xF8","decimal":"248","bank":"","page":"","description":""},"description":"Contains the LSB part up[11:4] of the raw pressure measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"press_lsb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981662 + 0.0667×1.000000 + 0.0334×1.000000) / 1.0001 = 0.938223 / 1.0001 = 0.938129

## Extracted logical register 14: press_xlsb

v17 location: registers[13]; equivalent split association with truth press physical part.
Associated physical locations: 0xF9 (249).

### Bottom layer: bit fields, then field parts

#### Field part 1: press_xlsb at 0xF9 (249)

Locations: truth registers[21].field_parts[2] ↔ v17 registers[13].field_parts[0].

**Truth bit field 1: press_xlsb[3:0] bits 7:4**

Locations: truth registers[21].field_parts[2].bit_field[0] ↔ v17 registers[13].field_parts[0].bit_field[0]. Judgment: truth name 'press_xlsb[3:0]' differs from extracted 'press_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted=''.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 0.000000 | press_xlsb[3:0] | press_xlsb[7:4] | truth name 'press_xlsb[3:0]' differs from extracted 'press_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| field_description | 0.0586 | 0.000000 | XLSB part up[3:0] of the raw pressure measurement output. | "" | truth name 'press_xlsb[3:0]' differs from extracted 'press_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| bit_start | 0.2594 | 1.000000 | 4 | 4 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 4 | 4 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 0.000000 | False | True | truth name 'press_xlsb[3:0]' differs from extracted 'press_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| type_write_read | 0.0583 | 0.000000 | R | "" | truth name 'press_xlsb[3:0]' differs from extracted 'press_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |

Q(bit_field) = (0.0212×0.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×0.000000 + 0.0583×0.000000) / 0.9999 = 0.786800 / 0.9999 = 0.786879

**Truth bit field 2: 0 bits 3:0**

Locations: truth registers[21].field_parts[2].bit_field[1], truth registers[21].field_parts[2].bit_field[2], truth registers[21].field_parts[2].bit_field[3], truth registers[21].field_parts[2].bit_field[4] ↔ v17 registers[13].field_parts[0].bit_field[1]. Judgment: truth fixed-zero label is '0', extracted label is 'press_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R'.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 0.000000 | 0 | press_xlsb[3:0] | truth fixed-zero label is '0', extracted label is 'press_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R' |
| field_description | 0.0586 | 0.000000 | Shown as 0 in the memory map. | "" | truth fixed-zero label is '0', extracted label is 'press_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R' |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 3 | 3 | correct |
| bit_width | 0.0583 | 1.000000 | 4 | 4 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 0.000000 | "" | R | truth fixed-zero label is '0', extracted label is 'press_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R' |

Q(bit_field) = (0.0212×0.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000) / 0.9999 = 0.861800 / 0.9999 = 0.861886

**Field-part aggregation**

bit_field correctness = mean(0.786879, 0.861886) = 0.824382.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | press_xlsb | press_xlsb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xF9","decimal":"249","bank":"","page":"","description":"Pressure XLSB in bits 7:4."} | {"hex":"0xF9","decimal":"249","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 0.500000 | XLSB part up[3:0] in bits 7:4. | Contains the XLSB part up[3:0] of the raw pressure measurement output data. Contents depend on temperature resolution. | XLSB function is present but bit-location/dependency wording is incomplete or contradictory |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.824382 | truth-target bit-field collection | [{"name_or_parameter":"press_xlsb[7:4]","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"press_xlsb[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.500000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.824382) / 1.0000 = 0.910399 / 1.0000 = 0.910399

### Extracted logical-register aggregation

field_parts correctness = mean(0.910399) = 0.910399.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | press_xlsb | press_xlsb | correct |
| physical_address | 0.4044 | 1.000000 | {"hex":"0xF9","decimal":"249","bank":"","page":"","description":"Pressure XLSB in bits 7:4."} | [{"hex":"0xF9","decimal":"249","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 0.000000 | XLSB part up[3:0] in bits 7:4. | "" | register description missing |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.910399 | corresponding truth field-part collection | [{"register_name":"press_xlsb","physical_address":{"hex":"0xF9","decimal":"249","bank":"","page":"","description":""},"description":"Contains the XLSB part up[3:0] of the raw pressure measurement output data. Contents depend on temperature resolution.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"press_xlsb[7:4]","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"press_xlsb[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.910399 + 0.0667×1.000000 + 0.0334×1.000000) / 1.0001 = 0.916936 / 1.0001 = 0.916845

## Extracted logical register 15: temp_msb

v17 location: registers[14]; equivalent split association with truth temp physical part.
Associated physical locations: 0xFA (250).

### Bottom layer: bit fields, then field parts

#### Field part 1: temp_msb at 0xFA (250)

Locations: truth registers[20].field_parts[0] ↔ v17 registers[14].field_parts[0].

**Truth bit field 1: temp_msb[7:0] bits 7:0**

Locations: truth registers[20].field_parts[0].bit_field[0] ↔ v17 registers[14].field_parts[0].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | temp_msb[7:0] | temp_msb[7:0] | correct |
| field_description | 0.0586 | 0.000000 | MSB part ut[19:12] of the raw temperature measurement output. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | temp_msb | temp_msb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xFA","decimal":"250","bank":"","page":"","description":"Temperature MSB."} | {"hex":"0xFA","decimal":"250","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | MSB part ut[19:12] of the raw temperature output. | Contains the MSB part ut[19:12] of the raw temperature measurement output data. | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"temp_msb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

### Extracted logical-register aggregation

field_parts correctness = mean(0.981662) = 0.981662.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | temp_msb | temp_msb | correct |
| physical_address | 0.4044 | 1.000000 | {"hex":"0xFA","decimal":"250","bank":"","page":"","description":"Temperature MSB."} | [{"hex":"0xFA","decimal":"250","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 0.000000 | MSB part ut[19:12] of the raw temperature output. | "" | register description missing |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.981662 | corresponding truth field-part collection | [{"register_name":"temp_msb","physical_address":{"hex":"0xFA","decimal":"250","bank":"","page":"","description":""},"description":"Contains the MSB part ut[19:12] of the raw temperature measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"temp_msb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | 0x80 | 0x80 | correct |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981662 + 0.0667×1.000000 + 0.0334×1.000000) / 1.0001 = 0.938223 / 1.0001 = 0.938129

## Extracted logical register 16: temp_lsb

v17 location: registers[15]; equivalent split association with truth temp physical part.
Associated physical locations: 0xFB (251).

### Bottom layer: bit fields, then field parts

#### Field part 1: temp_lsb at 0xFB (251)

Locations: truth registers[20].field_parts[1] ↔ v17 registers[15].field_parts[0].

**Truth bit field 1: temp_lsb[7:0] bits 7:0**

Locations: truth registers[20].field_parts[1].bit_field[0] ↔ v17 registers[15].field_parts[0].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | temp_lsb[7:0] | temp_lsb[7:0] | correct |
| field_description | 0.0586 | 0.000000 | LSB part ut[11:4] of the raw temperature measurement output. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | temp_lsb | temp_lsb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xFB","decimal":"251","bank":"","page":"","description":"Temperature LSB."} | {"hex":"0xFB","decimal":"251","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | LSB part ut[11:4] of the raw temperature output. | Contains the LSB part ut[11:4] of the raw temperature measurement output data. | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"temp_lsb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

### Extracted logical-register aggregation

field_parts correctness = mean(0.981662) = 0.981662.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | temp_lsb | temp_lsb | correct |
| physical_address | 0.4044 | 1.000000 | {"hex":"0xFB","decimal":"251","bank":"","page":"","description":"Temperature LSB."} | [{"hex":"0xFB","decimal":"251","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 0.000000 | LSB part ut[11:4] of the raw temperature output. | "" | register description missing |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.981662 | corresponding truth field-part collection | [{"register_name":"temp_lsb","physical_address":{"hex":"0xFB","decimal":"251","bank":"","page":"","description":""},"description":"Contains the LSB part ut[11:4] of the raw temperature measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"temp_lsb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981662 + 0.0667×1.000000 + 0.0334×1.000000) / 1.0001 = 0.938223 / 1.0001 = 0.938129

## Extracted logical register 17: temp_xlsb

v17 location: registers[16]; equivalent split association with truth temp physical part.
Associated physical locations: 0xFC (252).

### Bottom layer: bit fields, then field parts

#### Field part 1: temp_xlsb at 0xFC (252)

Locations: truth registers[20].field_parts[2] ↔ v17 registers[16].field_parts[0].

**Truth bit field 1: temp_xlsb[3:0] bits 7:4**

Locations: truth registers[20].field_parts[2].bit_field[0] ↔ v17 registers[16].field_parts[0].bit_field[0]. Judgment: truth name 'temp_xlsb[3:0]' differs from extracted 'temp_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted=''.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 0.000000 | temp_xlsb[3:0] | temp_xlsb[7:4] | truth name 'temp_xlsb[3:0]' differs from extracted 'temp_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| field_description | 0.0586 | 0.000000 | XLSB part ut[3:0] of the raw temperature measurement output. | "" | truth name 'temp_xlsb[3:0]' differs from extracted 'temp_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| bit_start | 0.2594 | 1.000000 | 4 | 4 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 4 | 4 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 0.000000 | False | True | truth name 'temp_xlsb[3:0]' differs from extracted 'temp_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| type_write_read | 0.0583 | 0.000000 | R | "" | truth name 'temp_xlsb[3:0]' differs from extracted 'temp_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |

Q(bit_field) = (0.0212×0.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×0.000000 + 0.0583×0.000000) / 0.9999 = 0.786800 / 0.9999 = 0.786879

**Truth bit field 2: 0 bits 3:0**

Locations: truth registers[20].field_parts[2].bit_field[1], truth registers[20].field_parts[2].bit_field[2], truth registers[20].field_parts[2].bit_field[3], truth registers[20].field_parts[2].bit_field[4] ↔ v17 registers[16].field_parts[0].bit_field[1]. Judgment: truth fixed-zero label is '0', extracted label is 'temp_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R'.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 0.000000 | 0 | temp_xlsb[3:0] | truth fixed-zero label is '0', extracted label is 'temp_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R' |
| field_description | 0.0586 | 0.000000 | Shown as 0 in the memory map. | "" | truth fixed-zero label is '0', extracted label is 'temp_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R' |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 3 | 3 | correct |
| bit_width | 0.0583 | 1.000000 | 4 | 4 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 0.000000 | "" | R | truth fixed-zero label is '0', extracted label is 'temp_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R' |

Q(bit_field) = (0.0212×0.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000) / 0.9999 = 0.861800 / 0.9999 = 0.861886

**Field-part aggregation**

bit_field correctness = mean(0.786879, 0.861886) = 0.824382.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | temp_xlsb | temp_xlsb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xFC","decimal":"252","bank":"","page":"","description":"Temperature XLSB in bits 7:4."} | {"hex":"0xFC","decimal":"252","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 0.500000 | XLSB part ut[3:0] in bits 7:4. | Contains the XLSB part ut[3:0] of the raw temperature measurement output data. Contents depend on pressure resolution. | XLSB function is present but bit-location/dependency wording is incomplete or contradictory |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.824382 | truth-target bit-field collection | [{"name_or_parameter":"temp_xlsb[7:4]","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"temp_xlsb[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.500000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.824382) / 1.0000 = 0.910399 / 1.0000 = 0.910399

### Extracted logical-register aggregation

field_parts correctness = mean(0.910399) = 0.910399.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | temp_xlsb | temp_xlsb | correct |
| physical_address | 0.4044 | 1.000000 | {"hex":"0xFC","decimal":"252","bank":"","page":"","description":"Temperature XLSB in bits 7:4."} | [{"hex":"0xFC","decimal":"252","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 0.000000 | XLSB part ut[3:0] in bits 7:4. | "" | register description missing |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.910399 | corresponding truth field-part collection | [{"register_name":"temp_xlsb","physical_address":{"hex":"0xFC","decimal":"252","bank":"","page":"","description":""},"description":"Contains the XLSB part ut[3:0] of the raw temperature measurement output data. Contents depend on pressure resolution.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"temp_xlsb[7:4]","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"temp_xlsb[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.910399 + 0.0667×1.000000 + 0.0334×1.000000) / 1.0001 = 0.916936 / 1.0001 = 0.916845

## Extracted logical register 18: hum_msb

v17 location: registers[17]; equivalent split association with truth hum physical part.
Associated physical locations: 0xFD (253).

### Bottom layer: bit fields, then field parts

#### Field part 1: hum_msb at 0xFD (253)

Locations: truth registers[19].field_parts[0] ↔ v17 registers[17].field_parts[0].

**Truth bit field 1: hum_msb[7:0] bits 7:0**

Locations: truth registers[19].field_parts[0].bit_field[0] ↔ v17 registers[17].field_parts[0].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | hum_msb[7:0] | hum_msb[7:0] | correct |
| field_description | 0.0586 | 0.000000 | MSB part uh[15:8] of the raw humidity measurement output. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | hum_msb | hum_msb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xFD","decimal":"253","bank":"","page":"","description":"Humidity MSB."} | {"hex":"0xFD","decimal":"253","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | MSB part uh[15:8] of the raw humidity output. | Contains the MSB part uh[15:8] of the raw humidity measurement output data. | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"hum_msb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

### Extracted logical-register aggregation

field_parts correctness = mean(0.981662) = 0.981662.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | hum_msb | hum_msb | correct |
| physical_address | 0.4044 | 1.000000 | {"hex":"0xFD","decimal":"253","bank":"","page":"","description":"Humidity MSB."} | [{"hex":"0xFD","decimal":"253","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 0.000000 | MSB part uh[15:8] of the raw humidity output. | "" | register description missing |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.981662 | corresponding truth field-part collection | [{"register_name":"hum_msb","physical_address":{"hex":"0xFD","decimal":"253","bank":"","page":"","description":""},"description":"Contains the MSB part uh[15:8] of the raw humidity measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"hum_msb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | 0x80 | 0x80 | correct |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981662 + 0.0667×1.000000 + 0.0334×1.000000) / 1.0001 = 0.938223 / 1.0001 = 0.938129

## Extracted logical register 19: hum_lsb

v17 location: registers[18]; equivalent split association with truth hum physical part.
Associated physical locations: 0xFE (254).

### Bottom layer: bit fields, then field parts

#### Field part 1: hum_lsb at 0xFE (254)

Locations: truth registers[19].field_parts[1] ↔ v17 registers[18].field_parts[0].

**Truth bit field 1: hum_lsb[7:0] bits 7:0**

Locations: truth registers[19].field_parts[1].bit_field[0] ↔ v17 registers[18].field_parts[0].bit_field[0]. Judgment: description missing.

| Scored field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name_or_parameter | 0.0212 | 1.000000 | hum_lsb[7:0] | hum_lsb[7:0] | correct |
| field_description | 0.0586 | 0.000000 | LSB part uh[7:0] of the raw humidity measurement output. | "" | description missing |
| bit_start | 0.2594 | 1.000000 | 0 | 0 | correct |
| bit_end | 0.2594 | 1.000000 | 7 | 7 | correct |
| bit_width | 0.0583 | 1.000000 | 8 | 8 | correct |
| values | 0.2097 | 1.000000 | [] | [] | correct |
| is_reserved | 0.0750 | 1.000000 | False | False | correct |
| type_write_read | 0.0583 | 1.000000 | R | R | correct |

Q(bit_field) = (0.0212×1.000000 + 0.0586×0.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000) / 0.9999 = 0.941300 / 0.9999 = 0.941394

**Field-part aggregation**

bit_field correctness = mean(0.941394) = 0.941394.

| Field-part field | Weight | C | Truth content | v17 content | Assessment |
|---|---:|---:|---|---|---|
| register_name | 0.0280 | 1.000000 | hum_lsb | hum_lsb | correct |
| physical_address | 0.4688 | 1.000000 | {"hex":"0xFE","decimal":"254","bank":"","page":"","description":"Humidity LSB."} | {"hex":"0xFE","decimal":"254","bank":"","page":"","description":""} | correct |
| description | 0.0693 | 1.000000 | LSB part uh[7:0] of the raw humidity output. | Contains the LSB part uh[7:0] of the raw humidity measurement output data. | correct |
| width_bits | 0.0605 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0605 | 1.000000 | R | R | correct |
| bit_field | 0.3129 | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"hum_lsb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |

Q(field_part) = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941394) / 1.0000 = 0.981662 / 1.0000 = 0.981662

### Extracted logical-register aggregation

field_parts correctness = mean(0.981662) = 0.981662.

| Logical-register field | Weight | C | Truth comparison target | v17 content | Assessment |
|---|---:|---:|---|---|---|
| name | 0.0225 | 1.000000 | hum_lsb | hum_lsb | correct |
| physical_address | 0.4044 | 1.000000 | {"hex":"0xFE","decimal":"254","bank":"","page":"","description":"Humidity LSB."} | [{"hex":"0xFE","decimal":"254","bank":"","page":"","description":""}] | correct |
| register_description | 0.0564 | 0.000000 | LSB part uh[7:0] of the raw humidity output. | "" | register description missing |
| width_bits | 0.0590 | 1.000000 | 8 | 8 | correct |
| type_write_read | 0.0590 | 1.000000 | R | R | correct |
| field_parts | 0.2987 | 0.981662 | corresponding truth field-part collection | [{"register_name":"hum_lsb","physical_address":{"hex":"0xFE","decimal":"254","bank":"","page":"","description":""},"description":"Contains the LSB part uh[7:0] of the raw humidity measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"hum_lsb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| default_value | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| default_value_description | 0.0334 | 1.000000 | "" | "" | correct |

Q(logical_register) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981662 + 0.0667×1.000000 + 0.0334×1.000000) / 1.0001 = 0.938223 / 1.0001 = 0.938129

## 2. Physical-register aggregation

- Each q_R is calculated from the mean Q(L) of extracted logical registers associated with that truth physical location.
- The shared 0xE5 location is counted once as a physical location. The calibration group containing it contributes one Q(L) to q_R.

| Truth physical location | Associated extracted logical registers | q_R |
|---|---|---:|
| 0x88 (136) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x89 (137) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x8A (138) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x8B (139) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x8C (140) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x8D (141) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x8E (142) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x8F (143) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x90 (144) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x91 (145) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x92 (146) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x93 (147) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x94 (148) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x95 (149) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x96 (150) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x97 (151) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x98 (152) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x99 (153) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x9A (154) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x9B (155) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x9C (156) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x9D (157) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x9E (158) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0x9F (159) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0xA1 (161) | v17 registers[2] calib00_calib25=0.873935 | 0.873935 |
| 0xD0 (208) | v17 registers[0] id=0.959703 | 0.959703 |
| 0xE0 (224) | v17 registers[1] reset=0.869413 | 0.869413 |
| 0xE1 (225) | v17 registers[3] calib26_calib41=0.852922 | 0.852922 |
| 0xE2 (226) | v17 registers[3] calib26_calib41=0.852922 | 0.852922 |
| 0xE3 (227) | v17 registers[3] calib26_calib41=0.852922 | 0.852922 |
| 0xE4 (228) | v17 registers[3] calib26_calib41=0.852922 | 0.852922 |
| 0xE5 (229) | v17 registers[3] calib26_calib41=0.852922 | 0.852922 |
| 0xE6 (230) | v17 registers[3] calib26_calib41=0.852922 | 0.852922 |
| 0xE7 (231) | v17 registers[3] calib26_calib41=0.852922 | 0.852922 |
| 0xF2 (242) | v17 registers[4] ctrl_hum=0.979302 | 0.979302 |
| 0xF3 (243) | v17 registers[5] status=0.889599 | 0.889599 |
| 0xF4 (244) | v17 registers[6] ctrl_meas=0.979302 | 0.979302 |
| 0xF5 (245) | v17 registers[7] config=0.974402 | 0.974402 |
| 0xF7 (247) | v17 registers[8] press=0.925299; v17 registers[11] press_msb=0.938129 | 0.931714 |
| 0xF8 (248) | v17 registers[8] press=0.925299; v17 registers[12] press_lsb=0.938129 | 0.931714 |
| 0xF9 (249) | v17 registers[8] press=0.925299; v17 registers[13] press_xlsb=0.916845 | 0.921072 |
| 0xFA (250) | v17 registers[9] temp=0.925299; v17 registers[14] temp_msb=0.938129 | 0.931714 |
| 0xFB (251) | v17 registers[9] temp=0.925299; v17 registers[15] temp_lsb=0.938129 | 0.931714 |
| 0xFC (252) | v17 registers[9] temp=0.925299; v17 registers[16] temp_xlsb=0.916845 | 0.921072 |
| 0xFD (253) | v17 registers[10] hum=0.933307; v17 registers[17] hum_msb=0.938129 | 0.935718 |
| 0xFE (254) | v17 registers[10] hum=0.933307; v17 registers[18] hum_lsb=0.938129 | 0.935718 |

Each q_R is the mean of the displayed associated Q(L) values; missing truth physical locations receive q_R=0.

### Final score

- Unique truth physical registers n = 46.
- Matched extracted physical locations m = 46.
- Extra extracted physical locations x = 0.
- Sum of q_R = 40.910990821.

S_final = (10 / 46) × 40.910990821 × (46 / (46 + 0)) = 8.893693657

## 3. Detailed deduction inventory

The following entries have C<1.000000. The complete truth/v17 content for every listed field is also present in the bottom-up tables above.

| Exact v17 location | Field | C | Truth content | v17 content | Why it is wrong or incomplete |
|---|---|---:|---|---|---|
| registers[0].field_parts[0].bit_field[0].values | values | 0.000000 | [{"value":"0x60","value_description":"BME280 chip identification number."}] | [] | truth values are missing |
| registers[0].field_parts[0].description | description | 0.000000 | Chip identification register. | "" | description missing |
| registers[0].field_parts[0].bit_field | bit_field | 0.790279 | truth-target bit-field collection | [{"name_or_parameter":"chip_id[7:0]","field_description":"Chip identification number. Default value is 0x60.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[0].field_parts | field_parts | 0.865078 | corresponding truth field-part collection | [{"register_name":"id","physical_address":{"hex":"0xD0","decimal":"208","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"chip_id[7:0]","field_description":"Chip identification number. Default value is 0x60.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| registers[1].field_parts[0].bit_field[0].values | values | 0.500000 | [{"value":"0xB6","value_description":"Resets the device using the complete power-on-reset procedure."},{"value":"other values than 0xB6","value_description":"No effect."}] | [{"value":"0xB6","value_description":"Device reset using power-on-reset procedure"}] | some truth value codes are present but the set is incomplete |
| registers[1].field_parts[0].description | description | 0.000000 | Soft reset register. | "" | description missing |
| registers[1].field_parts[0].bit_field | bit_field | 0.895140 | truth-target bit-field collection | [{"name_or_parameter":"reset[7:0]","field_description":"Soft reset word. Writing 0xB6 resets the device. Read value is always 0x00.","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"0xB6","value_description":"Device reset using power-on-reset procedure"}],"is_reserved":false,"type_write_read":"W"}] | mean of all truth-target bit-field scores |
| registers[1].field_parts | field_parts | 0.897889 | corresponding truth field-part collection | [{"register_name":"reset","physical_address":{"hex":"0xE0","decimal":"224","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"W","bit_field":[{"name_or_parameter":"reset[7:0]","field_description":"Soft reset word. Writing 0xB6 resets the device. Read value is always 0x00.","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"0xB6","value_description":"Device reset using power-on-reset procedure"}],"is_reserved":false,"type_write_read":"W"}]}] | mean of the independently scored extracted field parts |
| registers[1].default_value | default_value | 0.000000 | 0x00 | "" | truth default_value='0x00', extracted='' |
| registers[1].default_value_description | default_value_description | 0.000000 | The readout value is always 0x00. | "" | default-value description missing |
| registers[2].field_parts[0].bit_field[0].field_description | field_description | 0.000000 | Low byte of dig_T1. | "" | description missing |
| registers[2].field_parts[0].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_T1[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[1].bit_field[0].field_description | field_description | 0.000000 | High byte of dig_T1. | "" | description missing |
| registers[2].field_parts[1].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_T1[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[2].bit_field[0].field_description | field_description | 0.000000 | Low byte of dig_T2. | "" | description missing |
| registers[2].field_parts[2].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_T2[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[3].bit_field[0].field_description | field_description | 0.000000 | High byte of dig_T2. | "" | description missing |
| registers[2].field_parts[3].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_T2[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[4].bit_field[0].field_description | field_description | 0.000000 | Low byte of dig_T3. | "" | description missing |
| registers[2].field_parts[4].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_T3[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[5].bit_field[0].field_description | field_description | 0.000000 | High byte of dig_T3. | "" | description missing |
| registers[2].field_parts[5].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_T3[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[6].bit_field[0].field_description | field_description | 0.000000 | Low byte of dig_P1. | "" | description missing |
| registers[2].field_parts[6].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P1[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[7].bit_field[0].field_description | field_description | 0.000000 | High byte of dig_P1. | "" | description missing |
| registers[2].field_parts[7].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P1[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[8].bit_field[0].field_description | field_description | 0.000000 | Low byte of dig_P2. | "" | description missing |
| registers[2].field_parts[8].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P2[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[9].bit_field[0].field_description | field_description | 0.000000 | High byte of dig_P2. | "" | description missing |
| registers[2].field_parts[9].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P2[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[10].bit_field[0].field_description | field_description | 0.000000 | Low byte of dig_P3. | "" | description missing |
| registers[2].field_parts[10].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P3[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[11].bit_field[0].field_description | field_description | 0.000000 | High byte of dig_P3. | "" | description missing |
| registers[2].field_parts[11].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P3[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[12].bit_field[0].field_description | field_description | 0.000000 | Low byte of dig_P4. | "" | description missing |
| registers[2].field_parts[12].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P4[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[13].bit_field[0].field_description | field_description | 0.000000 | High byte of dig_P4. | "" | description missing |
| registers[2].field_parts[13].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P4[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[14].bit_field[0].field_description | field_description | 0.000000 | Low byte of dig_P5. | "" | description missing |
| registers[2].field_parts[14].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P5[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[15].bit_field[0].field_description | field_description | 0.000000 | High byte of dig_P5. | "" | description missing |
| registers[2].field_parts[15].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P5[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[16].bit_field[0].field_description | field_description | 0.000000 | Low byte of dig_P6. | "" | description missing |
| registers[2].field_parts[16].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P6[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[17].bit_field[0].field_description | field_description | 0.000000 | High byte of dig_P6. | "" | description missing |
| registers[2].field_parts[17].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P6[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[18].bit_field[0].field_description | field_description | 0.000000 | Low byte of dig_P7. | "" | description missing |
| registers[2].field_parts[18].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P7[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[19].bit_field[0].field_description | field_description | 0.000000 | High byte of dig_P7. | "" | description missing |
| registers[2].field_parts[19].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P7[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[20].bit_field[0].field_description | field_description | 0.000000 | Low byte of dig_P8. | "" | description missing |
| registers[2].field_parts[20].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P8[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[21].bit_field[0].field_description | field_description | 0.000000 | High byte of dig_P8. | "" | description missing |
| registers[2].field_parts[21].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P8[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[22].bit_field[0].field_description | field_description | 0.000000 | Low byte of dig_P9. | "" | description missing |
| registers[2].field_parts[22].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P9[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[23].bit_field[0].field_description | field_description | 0.000000 | High byte of dig_P9. | "" | description missing |
| registers[2].field_parts[23].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_P9[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].field_parts[24].bit_field[0].field_description | field_description | 0.000000 | dig_H1 humidity compensation parameter. | "" | description missing |
| registers[2].field_parts[24].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_H1[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[2].register_description | register_description | 0.500000 | ["Unsigned 16-bit temperature compensation parameter stored in non-volatile memory.","Signed 16-bit temperature compensation parameter stored in non-volatile memory.","Signed 16-bit temperature compensation parameter stored in non-volatile memory.","Unsigned 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Signed 16-bit pressure compensation parameter stored in non-volatile memory.","Unsigned 8-bit humidity compensation parameter stored in non-volatile memory."] | Calibration data registers for temperature and pressure compensation parameters (dig_T1...dig_P9). Each 16-bit compensation word is stored as two 8-bit registers. Memory addresses 0x88 to 0xA1. | generic grouped calibration description omits some individual signedness/storage detail |
| registers[2].width_bits | width_bits | 0.000000 | 200 | ∅ | truth comparison width_bits=200, extracted=None |
| registers[2].field_parts | field_parts | 0.981662 | corresponding truth field-part collection | [{"register_name":"dig_T1[7:0]","physical_address":{"hex":"0x88","decimal":"136","bank":"","page":"","description":""},"description":"LSB of dig_T1 (unsigned short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_T1[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_T1[15:8]","physical_address":{"hex":"0x89","decimal":"137","bank":"","page":"","description":""},"description":"MSB of dig_T1 (unsigned short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_T1[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_T2[7:0]","physical_address":{"hex":"0x8A","decimal":"138","bank":"","page":"","description":""},"description":"LSB of dig_T2 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_T2[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_T2[15:8]","physical_address":{"hex":"0x8B","decimal":"139","bank":"","page":"","description":""},"description":"MSB of dig_T2 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_T2[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_T3[7:0]","physical_address":{"hex":"0x8C","decimal":"140","bank":"","page":"","description":""},"description":"LSB of dig_T3 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_T3[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_T3[15:8]","physical_address":{"hex":"0x8D","decimal":"141","bank":"","page":"","description":""},"description":"MSB of dig_T3 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_T3[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P1[7:0]","physical_address":{"hex":"0x8E","decimal":"142","bank":"","page":"","description":""},"description":"LSB of dig_P1 (unsigned short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P1[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P1[15:8]","physical_address":{"hex":"0x8F","decimal":"143","bank":"","page":"","description":""},"description":"MSB of dig_P1 (unsigned short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P1[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P2[7:0]","physical_address":{"hex":"0x90","decimal":"144","bank":"","page":"","description":""},"description":"LSB of dig_P2 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P2[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P2[15:8]","physical_address":{"hex":"0x91","decimal":"145","bank":"","page":"","description":""},"description":"MSB of dig_P2 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P2[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P3[7:0]","physical_address":{"hex":"0x92","decimal":"146","bank":"","page":"","description":""},"description":"LSB of dig_P3 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P3[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P3[15:8]","physical_address":{"hex":"0x93","decimal":"147","bank":"","page":"","description":""},"description":"MSB of dig_P3 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P3[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P4[7:0]","physical_address":{"hex":"0x94","decimal":"148","bank":"","page":"","description":""},"description":"LSB of dig_P4 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P4[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P4[15:8]","physical_address":{"hex":"0x95","decimal":"149","bank":"","page":"","description":""},"description":"MSB of dig_P4 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P4[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P5[7:0]","physical_address":{"hex":"0x96","decimal":"150","bank":"","page":"","description":""},"description":"LSB of dig_P5 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P5[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P5[15:8]","physical_address":{"hex":"0x97","decimal":"151","bank":"","page":"","description":""},"description":"MSB of dig_P5 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P5[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P6[7:0]","physical_address":{"hex":"0x98","decimal":"152","bank":"","page":"","description":""},"description":"LSB of dig_P6 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P6[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P6[15:8]","physical_address":{"hex":"0x99","decimal":"153","bank":"","page":"","description":""},"description":"MSB of dig_P6 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P6[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P7[7:0]","physical_address":{"hex":"0x9A","decimal":"154","bank":"","page":"","description":""},"description":"LSB of dig_P7 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P7[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P7[15:8]","physical_address":{"hex":"0x9B","decimal":"155","bank":"","page":"","description":""},"description":"MSB of dig_P7 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P7[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P8[7:0]","physical_address":{"hex":"0x9C","decimal":"156","bank":"","page":"","description":""},"description":"LSB of dig_P8 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P8[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P8[15:8]","physical_address":{"hex":"0x9D","decimal":"157","bank":"","page":"","description":""},"description":"MSB of dig_P8 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P8[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P9[7:0]","physical_address":{"hex":"0x9E","decimal":"158","bank":"","page":"","description":""},"description":"LSB of dig_P9 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P9[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_P9[15:8]","physical_address":{"hex":"0x9F","decimal":"159","bank":"","page":"","description":""},"description":"MSB of dig_P9 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_P9[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H1[7:0]","physical_address":{"hex":"0xA1","decimal":"161","bank":"","page":"","description":""},"description":"LSB of dig_H1 (unsigned char)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H1[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| registers[2].default_value_description | default_value_description | 0.000000 | Individual factory-programmed calibration value. | "" | default-value description missing |
| registers[3].field_parts[0].bit_field[0].field_description | field_description | 0.000000 | Low byte of dig_H2. | "" | description missing |
| registers[3].field_parts[0].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_H2[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[3].field_parts[1].bit_field[0].field_description | field_description | 0.000000 | High byte of dig_H2. | "" | description missing |
| registers[3].field_parts[1].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_H2[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[3].field_parts[2].bit_field[0].field_description | field_description | 0.000000 | dig_H3 humidity compensation parameter. | "" | description missing |
| registers[3].field_parts[2].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_H3[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[3].field_parts[3].bit_field[0].field_description | field_description | 0.000000 | Upper eight bits of the 12-bit dig_H4 parameter. | "" | description missing |
| registers[3].field_parts[3].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_H4[11:4]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[3].field_parts[4].bit_field[0].field_description | field_description | 0.000000 | Lower four bits of the 12-bit dig_H4 parameter. | "" | description missing |
| registers[3].field_parts[4].bit_field[1].name_or_parameter | name_or_parameter | 0.000000 | dig_H5 [3:0] | dig_H5[11:4] | truth name 'dig_H5 [3:0]' differs from extracted 'dig_H5[11:4]'; description missing |
| registers[3].field_parts[4].bit_field[1].field_description | field_description | 0.000000 | Lower four bits of the 12-bit dig_H5 parameter. | "" | truth name 'dig_H5 [3:0]' differs from extracted 'dig_H5[11:4]'; description missing |
| registers[3].field_parts[4].register_name | register_name | 0.000000 | dig_H4 [3:0] + dig_H5 [3:0] | dig_H4[3:0] / dig_H5[11:4] | truth register_name='dig_H4 [3:0] + dig_H5 [3:0]', extracted='dig_H4[3:0] / dig_H5[11:4]' |
| registers[3].field_parts[4].description | description | 0.000000 | dig_H4[3:0] stored in address bits 3:0. + dig_H5[3:0] stored in address bits 7:4. | Lower nibble of dig_H4 (bits 3:0) and upper nibble of dig_H5 (bits 11:4) | description gives the wrong bit range for 'dig_H5 [3:0]' |
| registers[3].field_parts[4].bit_field | bit_field | 0.930793 | truth-target bit-field collection | [{"name_or_parameter":"dig_H4[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"dig_H5[11:4]","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[3].field_parts[5].name_or_parameter | name_or_parameter | 0.000000 | dig_H5 [11:4] | ∅ | missing extracted bit-field object |
| registers[3].field_parts[5].field_description | field_description | 0.000000 | Upper eight bits of the 12-bit dig_H5 parameter. | ∅ | missing extracted bit-field object |
| registers[3].field_parts[5].bit_start | bit_start | 0.000000 | 0 | ∅ | missing extracted bit-field object |
| registers[3].field_parts[5].bit_end | bit_end | 0.000000 | 7 | ∅ | missing extracted bit-field object |
| registers[3].field_parts[5].bit_width | bit_width | 0.000000 | 8 | ∅ | missing extracted bit-field object |
| registers[3].field_parts[5].values | values | 0.000000 | [] | ∅ | missing extracted bit-field object |
| registers[3].field_parts[5].is_reserved | is_reserved | 0.000000 | False | ∅ | missing extracted bit-field object |
| registers[3].field_parts[5].type_write_read | type_write_read | 0.000000 | R | ∅ | missing extracted bit-field object |
| registers[3].field_parts[5].register_name | register_name | 0.000000 | dig_H5 [11:4] | dig_H5[3:0] | truth register_name='dig_H5 [11:4]', extracted='dig_H5[3:0]' |
| registers[3].field_parts[5].description | description | 0.000000 | dig_H5[11:4]. | Lower nibble of dig_H5 (signed short, bits 3:0) | description gives the wrong bit range for 'dig_H5 [11:4]' |
| registers[3].field_parts[5].bit_field | bit_field | 0.000000 | truth-target bit-field collection | [{"name_or_parameter":"dig_H5[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[3].field_parts[6].bit_field[0].field_description | field_description | 0.000000 | Signed 8-bit humidity compensation parameter. | "" | explicit full-byte range is equivalent to truth's bare parameter name; description missing |
| registers[3].field_parts[6].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"dig_H6[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[3].register_description | register_description | 0.500000 | ["Signed 16-bit humidity compensation parameter stored in non-volatile memory.","Unsigned 8-bit humidity compensation parameter stored in non-volatile memory.","Signed 12-bit humidity compensation parameter stored across 0xE4 and the low nibble of 0xE5.","Signed 12-bit humidity compensation parameter stored across the high nibble of 0xE5 and 0xE6.","Signed 8-bit humidity compensation parameter stored in non-volatile memory."] | Calibration data registers for humidity compensation parameters (dig_H2...dig_H6). Memory addresses 0xE1 to 0xE7. | generic grouped calibration description omits some individual signedness/storage detail |
| registers[3].width_bits | width_bits | 0.000000 | 56 | ∅ | truth comparison width_bits=56, extracted=None |
| registers[3].field_parts | field_parts | 0.911308 | corresponding truth field-part collection | [{"register_name":"dig_H2[7:0]","physical_address":{"hex":"0xE1","decimal":"225","bank":"","page":"","description":""},"description":"LSB of dig_H2 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H2[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H2[15:8]","physical_address":{"hex":"0xE2","decimal":"226","bank":"","page":"","description":""},"description":"MSB of dig_H2 (signed short)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H2[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H3[7:0]","physical_address":{"hex":"0xE3","decimal":"227","bank":"","page":"","description":""},"description":"LSB of dig_H3 (unsigned char)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H3[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H4[11:4]","physical_address":{"hex":"0xE4","decimal":"228","bank":"","page":"","description":""},"description":"Upper nibble of dig_H4 (signed short, bits 11:4)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H4[11:4]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H4[3:0] / dig_H5[11:4]","physical_address":{"hex":"0xE5","decimal":"229","bank":"","page":"","description":""},"description":"Lower nibble of dig_H4 (bits 3:0) and upper nibble of dig_H5 (bits 11:4)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H4[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"dig_H5[11:4]","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H5[3:0]","physical_address":{"hex":"0xE6","decimal":"230","bank":"","page":"","description":""},"description":"Lower nibble of dig_H5 (signed short, bits 3:0)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H5[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"dig_H6[7:0]","physical_address":{"hex":"0xE7","decimal":"231","bank":"","page":"","description":""},"description":"LSB of dig_H6 (signed char)","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"dig_H6[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| registers[3].default_value_description | default_value_description | 0.000000 | Individual factory-programmed calibration value. | "" | default-value description missing |
| registers[4].field_parts[0].description | description | 0.000000 | Humidity data acquisition control register. | "" | description missing |
| registers[4].field_parts | field_parts | 0.930700 | corresponding truth field-part collection | [{"register_name":"ctrl_hum","physical_address":{"hex":"0xF2","decimal":"242","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"osrs_h[2:0]","field_description":"Controls oversampling of humidity data.","bit_start":0,"bit_end":2,"bit_width":3,"values":[{"value":"000","value_description":"Skipped (output set to 0x8000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"","bit_start":3,"bit_end":7,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""}]}] | mean of the independently scored extracted field parts |
| registers[5].field_parts[0].name_or_parameter | name_or_parameter | 0.000000 | "" | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].field_description | field_description | 0.000000 | "" | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].bit_start | bit_start | 0.000000 | 4 | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].bit_end | bit_end | 0.000000 | 7 | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].bit_width | bit_width | 0.000000 | 4 | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].values | values | 0.000000 | [] | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].is_reserved | is_reserved | 0.000000 | True | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].type_write_read | type_write_read | 0.000000 | "" | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].bit_field[3].values | values | 0.000000 | [{"value":"1","value_description":"A conversion is running."},{"value":"0","value_description":"No conversion is running; the bit returns to 0 after the results have been transferred to the data registers."}] | [] | truth values are missing |
| registers[5].field_parts[0].name_or_parameter | name_or_parameter | 0.000000 | "" | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].field_description | field_description | 0.000000 | "" | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].bit_start | bit_start | 0.000000 | 1 | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].bit_end | bit_end | 0.000000 | 2 | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].bit_width | bit_width | 0.000000 | 2 | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].values | values | 0.000000 | [] | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].is_reserved | is_reserved | 0.000000 | True | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].type_write_read | type_write_read | 0.000000 | "" | ∅ | missing extracted bit-field object |
| registers[5].field_parts[0].bit_field[0].name_or_parameter | name_or_parameter | 0.000000 | im_update[0] | Reserved | truth name 'im_update[0]' differs from extracted 'Reserved'; description missing; truth values are missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[5].field_parts[0].bit_field[0].field_description | field_description | 0.000000 | Indicates whether NVM data are being copied to image registers. The data are copied at power-on reset and before every conversion. | "" | truth name 'im_update[0]' differs from extracted 'Reserved'; description missing; truth values are missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[5].field_parts[0].bit_field[0].values | values | 0.000000 | [{"value":"1","value_description":"NVM data are being copied to image registers."},{"value":"0","value_description":"Copying is done."}] | [] | truth name 'im_update[0]' differs from extracted 'Reserved'; description missing; truth values are missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[5].field_parts[0].bit_field[0].is_reserved | is_reserved | 0.000000 | False | True | truth name 'im_update[0]' differs from extracted 'Reserved'; description missing; truth values are missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[5].field_parts[0].bit_field[0].type_write_read | type_write_read | 0.000000 | R | "" | truth name 'im_update[0]' differs from extracted 'Reserved'; description missing; truth values are missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[5].field_parts[0].description | description | 0.000000 | Device status register. | "" | description missing |
| registers[5].field_parts[0].bit_field | bit_field | 0.341859 | truth-target bit-field collection | [{"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Reserved","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Reserved","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"measuring[0]","field_description":"Automatically set to '1' whenever a conversion is running and back to '0' when the results have been transferred to the data registers.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":6,"bit_width":3,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"im_update[0]","field_description":"Automatically set to '1' when the NVM data are being copied to image registers and back to '0' when the copying is done. The data are copied at power-on-reset and before every conversion.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[5].register_description | register_description | 0.500000 | Contains bits indicating conversion activity and NVM-to-image-register copying status. | The "status" register contains two bits which indicate the status of the device. | status purpose is identified but the individual conversion/copy meanings are incomplete |
| registers[5].field_parts | field_parts | 0.724768 | corresponding truth field-part collection | [{"register_name":"status","physical_address":{"hex":"0xF3","decimal":"243","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Reserved","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Reserved","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"measuring[0]","field_description":"Automatically set to '1' whenever a conversion is running and back to '0' when the results have been transferred to the data registers.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":6,"bit_width":3,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"im_update[0]","field_description":"Automatically set to '1' when the NVM data are being copied to image registers and back to '0' when the copying is done. The data are copied at power-on-reset and before every conversion.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| registers[6].field_parts[0].description | description | 0.000000 | Pressure and temperature data acquisition control register. | "" | description missing |
| registers[6].field_parts | field_parts | 0.930700 | corresponding truth field-part collection | [{"register_name":"ctrl_meas","physical_address":{"hex":"0xF4","decimal":"244","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"osrs_t[2:0]","field_description":"Controls oversampling of temperature data.","bit_start":5,"bit_end":7,"bit_width":3,"values":[{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"osrs_p[2:0]","field_description":"Controls oversampling of pressure data.","bit_start":2,"bit_end":4,"bit_width":3,"values":[{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"mode[1:0]","field_description":"Controls the sensor mode of the device.","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"00","value_description":"Sleep mode"},{"value":"01 and 10","value_description":"Forced mode"},{"value":"11","value_description":"Normal mode"}],"is_reserved":false,"type_write_read":"RW"}]}] | mean of the independently scored extracted field parts |
| registers[7].field_parts[0].bit_field[3].values | values | 0.000000 | [{"value":"1","value_description":"3-wire SPI interface enabled."}] | [] | truth values are missing |
| registers[7].field_parts[0].description | description | 0.000000 | Rate, filter and interface configuration register. | "" | description missing |
| registers[7].field_parts[0].bit_field | bit_field | 0.947570 | truth-target bit-field collection | [{"name_or_parameter":"t_sb[2:0]","field_description":"Controls inactive duration t_standby in normal mode.","bit_start":5,"bit_end":7,"bit_width":3,"values":[{"value":"000","value_description":"0.5 ms"},{"value":"001","value_description":"62.5 ms"},{"value":"010","value_description":"125 ms"},{"value":"011","value_description":"250 ms"},{"value":"100","value_description":"500 ms"},{"value":"101","value_description":"1000 ms"},{"value":"110","value_description":"10 ms"},{"value":"111","value_description":"20 ms"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"filter[2:0]","field_description":"Controls the time constant of the IIR filter.","bit_start":2,"bit_end":4,"bit_width":3,"values":[{"value":"000","value_description":"Filter off"},{"value":"001","value_description":"2"},{"value":"010","value_description":"4"},{"value":"011","value_description":"8"},{"value":"100, others","value_description":"16"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"spi3w_en[0]","field_description":"Enables 3-wire SPI interface when set to '1'.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | mean of all truth-target bit-field scores |
| registers[7].field_parts | field_parts | 0.914295 | corresponding truth field-part collection | [{"register_name":"config","physical_address":{"hex":"0xF5","decimal":"245","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"t_sb[2:0]","field_description":"Controls inactive duration t_standby in normal mode.","bit_start":5,"bit_end":7,"bit_width":3,"values":[{"value":"000","value_description":"0.5 ms"},{"value":"001","value_description":"62.5 ms"},{"value":"010","value_description":"125 ms"},{"value":"011","value_description":"250 ms"},{"value":"100","value_description":"500 ms"},{"value":"101","value_description":"1000 ms"},{"value":"110","value_description":"10 ms"},{"value":"111","value_description":"20 ms"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"filter[2:0]","field_description":"Controls the time constant of the IIR filter.","bit_start":2,"bit_end":4,"bit_width":3,"values":[{"value":"000","value_description":"Filter off"},{"value":"001","value_description":"2"},{"value":"010","value_description":"4"},{"value":"011","value_description":"8"},{"value":"100, others","value_description":"16"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"spi3w_en[0]","field_description":"Enables 3-wire SPI interface when set to '1'.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] | mean of the independently scored extracted field parts |
| registers[8].field_parts[2].bit_field[1].name_or_parameter | name_or_parameter | 0.000000 | press_xlsb[3:0] | Reserved | truth name 'press_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[8].field_parts[2].bit_field[1].field_description | field_description | 0.000000 | XLSB part up[3:0] of the raw pressure measurement output. | "" | truth name 'press_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[8].field_parts[2].bit_field[1].is_reserved | is_reserved | 0.000000 | False | True | truth name 'press_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[8].field_parts[2].bit_field[1].type_write_read | type_write_read | 0.000000 | R | "" | truth name 'press_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[8].field_parts[2].bit_field[0].name_or_parameter | name_or_parameter | 0.000000 | 0 | press_xlsb[3:0] | truth fixed-zero label is '0', extracted label is 'press_xlsb[3:0]'; type_write_read truth='', extracted='R' |
| registers[8].field_parts[2].bit_field[0].type_write_read | type_write_read | 0.000000 | "" | R | truth fixed-zero label is '0', extracted label is 'press_xlsb[3:0]'; type_write_read truth='', extracted='R' |
| registers[8].field_parts[2].description | description | 0.500000 | XLSB part up[3:0] in bits 7:4. | Contains the XLSB part up[3:0] of the raw pressure measurement output data. Contents depend on temperature resolution. | XLSB function is present but bit-location/dependency wording is incomplete or contradictory |
| registers[8].field_parts[2].bit_field | bit_field | 0.853685 | truth-target bit-field collection | [{"name_or_parameter":"press_xlsb[3:0]","field_description":"XLSB part up[3:0] of the raw pressure measurement output data. Bits 7:4 are unused.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}] | mean of all truth-target bit-field scores |
| registers[8].field_parts | field_parts | 0.973189 | corresponding truth field-part collection | [{"register_name":"press_msb","physical_address":{"hex":"0xF7","decimal":"247","bank":"","page":"","description":""},"description":"Contains the MSB part up[19:12] of the raw pressure measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"press_msb[7:0]","field_description":"MSB part up[19:12] of the raw pressure measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"press_lsb","physical_address":{"hex":"0xF8","decimal":"248","bank":"","page":"","description":""},"description":"Contains the LSB part up[11:4] of the raw pressure measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"press_lsb[7:0]","field_description":"LSB part up[11:4] of the raw pressure measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"press_xlsb","physical_address":{"hex":"0xF9","decimal":"249","bank":"","page":"","description":""},"description":"Contains the XLSB part up[3:0] of the raw pressure measurement output data. Contents depend on temperature resolution.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"press_xlsb[3:0]","field_description":"XLSB part up[3:0] of the raw pressure measurement output data. Bits 7:4 are unused.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}]}] | mean of the independently scored extracted field parts |
| registers[8].default_value | default_value | 0.000000 | 0x80000 | "" | truth default_value='0x80000', extracted='' |
| registers[9].field_parts[2].bit_field[1].name_or_parameter | name_or_parameter | 0.000000 | temp_xlsb[3:0] | Reserved | truth name 'temp_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[9].field_parts[2].bit_field[1].field_description | field_description | 0.000000 | XLSB part ut[3:0] of the raw temperature measurement output. | "" | truth name 'temp_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[9].field_parts[2].bit_field[1].is_reserved | is_reserved | 0.000000 | False | True | truth name 'temp_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[9].field_parts[2].bit_field[1].type_write_read | type_write_read | 0.000000 | R | "" | truth name 'temp_xlsb[3:0]' differs from extracted 'Reserved'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[9].field_parts[2].bit_field[0].name_or_parameter | name_or_parameter | 0.000000 | 0 | temp_xlsb[3:0] | truth fixed-zero label is '0', extracted label is 'temp_xlsb[3:0]'; type_write_read truth='', extracted='R' |
| registers[9].field_parts[2].bit_field[0].type_write_read | type_write_read | 0.000000 | "" | R | truth fixed-zero label is '0', extracted label is 'temp_xlsb[3:0]'; type_write_read truth='', extracted='R' |
| registers[9].field_parts[2].description | description | 0.500000 | XLSB part ut[3:0] in bits 7:4. | Contains the XLSB part ut[3:0] of the raw temperature measurement output data. Contents depend on pressure resolution. | XLSB function is present but bit-location/dependency wording is incomplete or contradictory |
| registers[9].field_parts[2].bit_field | bit_field | 0.853685 | truth-target bit-field collection | [{"name_or_parameter":"temp_xlsb[3:0]","field_description":"XLSB part ut[3:0] of the raw temperature measurement output data. Bits 7:4 are unused.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}] | mean of all truth-target bit-field scores |
| registers[9].field_parts | field_parts | 0.973189 | corresponding truth field-part collection | [{"register_name":"temp_msb","physical_address":{"hex":"0xFA","decimal":"250","bank":"","page":"","description":""},"description":"Contains the MSB part ut[19:12] of the raw temperature measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"temp_msb[7:0]","field_description":"MSB part ut[19:12] of the raw temperature measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"temp_lsb","physical_address":{"hex":"0xFB","decimal":"251","bank":"","page":"","description":""},"description":"Contains the LSB part ut[11:4] of the raw temperature measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"temp_lsb[7:0]","field_description":"LSB part ut[11:4] of the raw temperature measurement output data.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"temp_xlsb","physical_address":{"hex":"0xFC","decimal":"252","bank":"","page":"","description":""},"description":"Contains the XLSB part ut[3:0] of the raw temperature measurement output data. Contents depend on pressure resolution.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"temp_xlsb[3:0]","field_description":"XLSB part ut[3:0] of the raw temperature measurement output data. Bits 7:4 are unused.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}]}] | mean of the independently scored extracted field parts |
| registers[9].default_value | default_value | 0.000000 | 0x80000 | "" | truth default_value='0x80000', extracted='' |
| registers[10].default_value | default_value | 0.000000 | 0x8000 | "" | truth default_value='0x8000', extracted='' |
| registers[11].field_parts[0].bit_field[0].field_description | field_description | 0.000000 | MSB part up[19:12] of the raw pressure measurement output. | "" | description missing |
| registers[11].field_parts[0].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"press_msb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[11].register_description | register_description | 0.000000 | MSB part up[19:12] of the raw pressure output. | "" | register description missing |
| registers[11].field_parts | field_parts | 0.981662 | corresponding truth field-part collection | [{"register_name":"press_msb","physical_address":{"hex":"0xF7","decimal":"247","bank":"","page":"","description":""},"description":"Contains the MSB part up[19:12] of the raw pressure measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"press_msb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| registers[12].field_parts[0].bit_field[0].field_description | field_description | 0.000000 | LSB part up[11:4] of the raw pressure measurement output. | "" | description missing |
| registers[12].field_parts[0].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"press_lsb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[12].register_description | register_description | 0.000000 | LSB part up[11:4] of the raw pressure output. | "" | register description missing |
| registers[12].field_parts | field_parts | 0.981662 | corresponding truth field-part collection | [{"register_name":"press_lsb","physical_address":{"hex":"0xF8","decimal":"248","bank":"","page":"","description":""},"description":"Contains the LSB part up[11:4] of the raw pressure measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"press_lsb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| registers[13].field_parts[0].bit_field[0].name_or_parameter | name_or_parameter | 0.000000 | press_xlsb[3:0] | press_xlsb[7:4] | truth name 'press_xlsb[3:0]' differs from extracted 'press_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[13].field_parts[0].bit_field[0].field_description | field_description | 0.000000 | XLSB part up[3:0] of the raw pressure measurement output. | "" | truth name 'press_xlsb[3:0]' differs from extracted 'press_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[13].field_parts[0].bit_field[0].is_reserved | is_reserved | 0.000000 | False | True | truth name 'press_xlsb[3:0]' differs from extracted 'press_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[13].field_parts[0].bit_field[0].type_write_read | type_write_read | 0.000000 | R | "" | truth name 'press_xlsb[3:0]' differs from extracted 'press_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[13].field_parts[0].bit_field[1].name_or_parameter | name_or_parameter | 0.000000 | 0 | press_xlsb[3:0] | truth fixed-zero label is '0', extracted label is 'press_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R' |
| registers[13].field_parts[0].bit_field[1].field_description | field_description | 0.000000 | Shown as 0 in the memory map. | "" | truth fixed-zero label is '0', extracted label is 'press_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R' |
| registers[13].field_parts[0].bit_field[1].type_write_read | type_write_read | 0.000000 | "" | R | truth fixed-zero label is '0', extracted label is 'press_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R' |
| registers[13].field_parts[0].description | description | 0.500000 | XLSB part up[3:0] in bits 7:4. | Contains the XLSB part up[3:0] of the raw pressure measurement output data. Contents depend on temperature resolution. | XLSB function is present but bit-location/dependency wording is incomplete or contradictory |
| registers[13].field_parts[0].bit_field | bit_field | 0.824382 | truth-target bit-field collection | [{"name_or_parameter":"press_xlsb[7:4]","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"press_xlsb[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[13].register_description | register_description | 0.000000 | XLSB part up[3:0] in bits 7:4. | "" | register description missing |
| registers[13].field_parts | field_parts | 0.910399 | corresponding truth field-part collection | [{"register_name":"press_xlsb","physical_address":{"hex":"0xF9","decimal":"249","bank":"","page":"","description":""},"description":"Contains the XLSB part up[3:0] of the raw pressure measurement output data. Contents depend on temperature resolution.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"press_xlsb[7:4]","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"press_xlsb[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| registers[14].field_parts[0].bit_field[0].field_description | field_description | 0.000000 | MSB part ut[19:12] of the raw temperature measurement output. | "" | description missing |
| registers[14].field_parts[0].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"temp_msb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[14].register_description | register_description | 0.000000 | MSB part ut[19:12] of the raw temperature output. | "" | register description missing |
| registers[14].field_parts | field_parts | 0.981662 | corresponding truth field-part collection | [{"register_name":"temp_msb","physical_address":{"hex":"0xFA","decimal":"250","bank":"","page":"","description":""},"description":"Contains the MSB part ut[19:12] of the raw temperature measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"temp_msb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| registers[15].field_parts[0].bit_field[0].field_description | field_description | 0.000000 | LSB part ut[11:4] of the raw temperature measurement output. | "" | description missing |
| registers[15].field_parts[0].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"temp_lsb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[15].register_description | register_description | 0.000000 | LSB part ut[11:4] of the raw temperature output. | "" | register description missing |
| registers[15].field_parts | field_parts | 0.981662 | corresponding truth field-part collection | [{"register_name":"temp_lsb","physical_address":{"hex":"0xFB","decimal":"251","bank":"","page":"","description":""},"description":"Contains the LSB part ut[11:4] of the raw temperature measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"temp_lsb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| registers[16].field_parts[0].bit_field[0].name_or_parameter | name_or_parameter | 0.000000 | temp_xlsb[3:0] | temp_xlsb[7:4] | truth name 'temp_xlsb[3:0]' differs from extracted 'temp_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[16].field_parts[0].bit_field[0].field_description | field_description | 0.000000 | XLSB part ut[3:0] of the raw temperature measurement output. | "" | truth name 'temp_xlsb[3:0]' differs from extracted 'temp_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[16].field_parts[0].bit_field[0].is_reserved | is_reserved | 0.000000 | False | True | truth name 'temp_xlsb[3:0]' differs from extracted 'temp_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[16].field_parts[0].bit_field[0].type_write_read | type_write_read | 0.000000 | R | "" | truth name 'temp_xlsb[3:0]' differs from extracted 'temp_xlsb[7:4]'; description missing; is_reserved truth=False, extracted=True; type_write_read truth='R', extracted='' |
| registers[16].field_parts[0].bit_field[1].name_or_parameter | name_or_parameter | 0.000000 | 0 | temp_xlsb[3:0] | truth fixed-zero label is '0', extracted label is 'temp_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R' |
| registers[16].field_parts[0].bit_field[1].field_description | field_description | 0.000000 | Shown as 0 in the memory map. | "" | truth fixed-zero label is '0', extracted label is 'temp_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R' |
| registers[16].field_parts[0].bit_field[1].type_write_read | type_write_read | 0.000000 | "" | R | truth fixed-zero label is '0', extracted label is 'temp_xlsb[3:0]'; description missing; type_write_read truth='', extracted='R' |
| registers[16].field_parts[0].description | description | 0.500000 | XLSB part ut[3:0] in bits 7:4. | Contains the XLSB part ut[3:0] of the raw temperature measurement output data. Contents depend on pressure resolution. | XLSB function is present but bit-location/dependency wording is incomplete or contradictory |
| registers[16].field_parts[0].bit_field | bit_field | 0.824382 | truth-target bit-field collection | [{"name_or_parameter":"temp_xlsb[7:4]","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"temp_xlsb[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[16].register_description | register_description | 0.000000 | XLSB part ut[3:0] in bits 7:4. | "" | register description missing |
| registers[16].field_parts | field_parts | 0.910399 | corresponding truth field-part collection | [{"register_name":"temp_xlsb","physical_address":{"hex":"0xFC","decimal":"252","bank":"","page":"","description":""},"description":"Contains the XLSB part ut[3:0] of the raw temperature measurement output data. Contents depend on pressure resolution.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"temp_xlsb[7:4]","field_description":"","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"temp_xlsb[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| registers[17].field_parts[0].bit_field[0].field_description | field_description | 0.000000 | MSB part uh[15:8] of the raw humidity measurement output. | "" | description missing |
| registers[17].field_parts[0].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"hum_msb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[17].register_description | register_description | 0.000000 | MSB part uh[15:8] of the raw humidity output. | "" | register description missing |
| registers[17].field_parts | field_parts | 0.981662 | corresponding truth field-part collection | [{"register_name":"hum_msb","physical_address":{"hex":"0xFD","decimal":"253","bank":"","page":"","description":""},"description":"Contains the MSB part uh[15:8] of the raw humidity measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"hum_msb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |
| registers[18].field_parts[0].bit_field[0].field_description | field_description | 0.000000 | LSB part uh[7:0] of the raw humidity measurement output. | "" | description missing |
| registers[18].field_parts[0].bit_field | bit_field | 0.941394 | truth-target bit-field collection | [{"name_or_parameter":"hum_lsb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] | mean of all truth-target bit-field scores |
| registers[18].register_description | register_description | 0.000000 | LSB part uh[7:0] of the raw humidity output. | "" | register description missing |
| registers[18].field_parts | field_parts | 0.981662 | corresponding truth field-part collection | [{"register_name":"hum_lsb","physical_address":{"hex":"0xFE","decimal":"254","bank":"","page":"","description":""},"description":"Contains the LSB part uh[7:0] of the raw humidity measurement output data.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"hum_lsb[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] | mean of the independently scored extracted field parts |

### Unmatched extracted bit fields (audit-only)

These extracted nested objects have no exact truth bit-field target. They are listed to make the location and content discrepancy explicit, but they are not independently added to the weighted truth-target score or to x.

| Exact v17 location | Extracted content | Assessment |
|---|---|---|
| registers[3].field_parts[5].bit_field[0] | {"name_or_parameter":"dig_H5[3:0]","field_description":"","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"} | no exact truth bit-field target at this range/name; truth target ranges are 0:7 |
| registers[5].field_parts[0].bit_field[1] | {"name_or_parameter":"Reserved","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | no exact truth bit-field target at this range/name; truth target ranges are 4:7, 3:3, 1:2, 0:0 |
| registers[5].field_parts[0].bit_field[2] | {"name_or_parameter":"Reserved","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | no exact truth bit-field target at this range/name; truth target ranges are 4:7, 3:3, 1:2, 0:0 |
| registers[5].field_parts[0].bit_field[4] | {"name_or_parameter":"Reserved","field_description":"","bit_start":4,"bit_end":6,"bit_width":3,"values":[],"is_reserved":true,"type_write_read":""} | no exact truth bit-field target at this range/name; truth target ranges are 4:7, 3:3, 1:2, 0:0 |
| registers[5].field_parts[0].bit_field[5] | {"name_or_parameter":"im_update[0]","field_description":"Automatically set to '1' when the NVM data are being copied to image registers and back to '0' when the copying is done. The data are copied at power-on-reset and before every conversion.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"} | no exact truth bit-field target at this range/name; truth target ranges are 4:7, 3:3, 1:2, 0:0 |

## 4. Invented-field check

- All 46 matched extracted physical locations are truth locations and no extra physical location was found; therefore x=0 and the extra-location penalty is 1.000000.
- Calibration merge, raw-register merge, and raw-register split are equivalent grouping representations and are not penalized solely for grouping. The duplicate raw split entries are nevertheless independently scored as logical registers and their Q(L) values are averaged at each shared physical location.
- The v17 press_xlsb/temp_xlsb bit-range reversal is not treated as an invented physical address; it is scored directly through the strict bit_start/bit_end/name/is_reserved/type fields and the corresponding descriptions.
- 5 extracted bit-field objects have no exact truth target; they are shown in the audit-only table above and do not create extra physical locations.
- No fields outside the AGENTS.md weight lists, including category, contribute to the score.
