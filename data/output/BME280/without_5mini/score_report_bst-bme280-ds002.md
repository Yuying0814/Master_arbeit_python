# BME280 without detailed score — revised AGENTS.md rules

## 1. Scoring basis

- Truth file: `BME280/truth_BME280.json`; evaluated map: `BME280/without/bst-bme280-ds002.json`.
- The truth contains 46 unique physical-register locations, identified by numeric address together with bank and page; the hexadecimal and decimal address forms are one location.
- Every extracted logical register is calculated independently from the bottom up: bit-field Q → field-part Q → logical-register Q(L). `category`, `index`, `is_multi_address`, and `source` are excluded from scoring.
- Objective facts (logical/field names, numeric addresses, bit ranges, widths, value-code coverage, reserved status, and access type) are scored strictly. Descriptions are judged by functional meaning; correct non-contradictory additional wording is accepted.
- Truth and extracted fields that are both empty receive credit. Reserved fields may use an empty name or the literal label `Reserved`.
- The four truth fixed-zero fields in each `press_xlsb`/`temp_xlsb` are evaluated as one merged 3:0 target because the rules allow equivalent merge/split representations; geometry and fixed-zero semantics are still scored.
- Rounded AHP weights are normalized by `0.9999` at bit-field level, `1.0000` at field-part level, and `1.0001` at logical-register level.

## 2. Extracted logical-register calculations

### Extracted logical register 1: `id`

Location: `without registers[0]`; truth association: `truth registers[17]` (`id`).
Associated physical locations: 0xD0 (208).

#### Field part 1: `id` at 0xD0 (208)

Locations: `truth registers[17].field_parts[0]` ↔ `without registers[0].field_parts[0]`.

**Truth bit field 1: `chip_id[7:0]` bits 7:0**

Locations: `truth registers[17].field_parts[0].bit_field[0]` ↔ `without registers[0].field_parts[0].bit_field[0]`. Judgment: truth value cases are missing from the extracted bit field.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | chip_id[7:0] | chip_id[7:0] | correct |
| `field_description` | 0.0586 | 1.000000 | Chip identification number. | Chip identification number; read value is 0x60 for BME280. | correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 | correct |
| `values` | 0.2097 | 0.000000 | [{"value":"0x60","value_description":"BME280 chip identification number."}] | [] | incorrect or missing |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | R | R | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Field-part aggregation**

`bit_field` = mean(0.790279) = **0.790279**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | id | id | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xD0","decimal":"208","bank":"","page":"","description":"Chip identification register."} | {"hex":"0xD0","decimal":"208","bank":"","page":"","description":"Chip identification register (chip_id[7:0])"} | correct |
| `description` | 0.0693 | 1.000000 | Chip identification register. | Chip ID (MSB..LSB) | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | R | R | correct |
| `bit_field` | 0.3129 | 0.790279 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.790279)/1.0000=0.934378/1.0000=\mathbf{0.934378}\).

### Logical-register aggregation

`field_parts` = mean(0.934378) = **0.934378**.

| Logical-register field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name` | 0.0225 | 1.000000 | id | id | correct |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0xD0","decimal":"208","bank":"","page":"","description":"Chip identification register."}] | [{"hex":"0xD0","decimal":"208","bank":"","page":"","description":"Chip identification register (chip_id[7:0])"}] | correct |
| `register_description` | 0.0564 | 1.000000 | Contains the chip identification number chip_id[7:0], which is 0x60. | Chip identification number (chip_id[7:0]) used to identify the device; read after power-on-reset. | correct |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0590 | 1.000000 | R | R | correct |
| `field_parts` | 0.2987 | 0.934378 | recursive truth field-part collection | recursive extracted field-part collection | mean of independently scored field parts |
| `default_value` | 0.0667 | 1.000000 | 0x60 | 0x60 | correct |
| `default_value_description` | 0.0334 | 1.000000 | "" | Reset/read value shown in memory map (chip_id = 0x60). | correct |

\(Q(L_{0})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.934378 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.980499/1.0001=\mathbf{0.980401}\).

### Extracted logical register 2: `reset`

Location: `without registers[1]`; truth association: `truth registers[25]` (`reset`).
Associated physical locations: 0xE0 (224).

#### Field part 1: `reset` at 0xE0 (224)

Locations: `truth registers[25].field_parts[0]` ↔ `without registers[1].field_parts[0]`.

**Truth bit field 1: `reset[7:0]` bits 7:0**

Locations: `truth registers[25].field_parts[0].bit_field[0]` ↔ `without registers[1].field_parts[0].bit_field[0]`. Judgment: 0xB6 is present, but the truth's 'other values than 0xB6: no effect' case is omitted.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | reset[7:0] | reset[7:0] | correct |
| `field_description` | 0.0586 | 1.000000 | Soft reset word. | Soft reset word. Writing 0xB6 triggers a device reset; other values have no effect. Read value is always 0x00. | correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 | correct |
| `values` | 0.2097 | 0.500000 | [{"value":"0xB6","value_description":"Resets the device using the complete power-on-reset procedure."},{"value":"other values than 0xB6","value_description":"No effect."}] | [{"value":"0xB6","value_description":"Write this value to perform a soft reset (full power-on-reset)."}] | partially correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | W | W | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.500000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.895050/0.9999=\mathbf{0.895140}\).

**Field-part aggregation**

`bit_field` = mean(0.895140) = **0.895140**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | reset | reset | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xE0","decimal":"224","bank":"","page":"","description":"Soft reset register."} | {"hex":"0xE0","decimal":"224","bank":"","page":"","description":"Soft reset register"} | correct |
| `description` | 0.0693 | 1.000000 | Soft reset register. | Write 0xB6 to trigger soft reset; reading returns 0x00. | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | W | W | correct |
| `bit_field` | 0.3129 | 0.895140 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.895140)/1.0000=0.967189/1.0000=\mathbf{0.967189}\).

### Logical-register aggregation

`field_parts` = mean(0.967189) = **0.967189**.

| Logical-register field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name` | 0.0225 | 1.000000 | reset | reset | correct |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0xE0","decimal":"224","bank":"","page":"","description":"Soft reset register."}] | [{"hex":"0xE0","decimal":"224","bank":"","page":"","description":"Soft reset register (write 0xB6 triggers full power-on-reset)"}] | correct |
| `register_description` | 0.0564 | 0.500000 | Writing 0xB6 performs a complete power-on-reset procedure; other written values have no effect. | Soft reset register; writing 0xB6 triggers device reset (full power-on-reset). Read returns 0x00. | partially correct |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0590 | 1.000000 | W | W | correct |
| `field_parts` | 0.2987 | 0.967189 | recursive truth field-part collection | recursive extracted field-part collection | mean of independently scored field parts |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| `default_value_description` | 0.0334 | 0.500000 | The readout value is always 0x00. | Readback/reset state shown in memory map. | partially correct |

\(Q(L_{1})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.967189 + 0.0667×1.000000 + 0.0334×0.500000)/1.0001=0.945399/1.0001=\mathbf{0.945305}\).

### Extracted logical register 3: `ctrl_hum`

Location: `without registers[2]`; truth association: `truth registers[24]` (`ctrl_hum`).
Associated physical locations: 0xF2 (242).

#### Field part 1: `ctrl_hum` at 0xF2 (242)

Locations: `truth registers[24].field_parts[0]` ↔ `without registers[2].field_parts[0]`.

**Truth bit field 1: `` bits 7:3**

Locations: `truth registers[24].field_parts[0].bit_field[0]` ↔ `without registers[2].field_parts[0].bit_field[0]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | "" | Reserved | correct |
| `field_description` | 0.0586 | 1.000000 | "" | "" | correct |
| `bit_start` | 0.2594 | 1.000000 | 3 | 3 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 5 | 5 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 1.000000 | True | True | correct |
| `type_write_read` | 0.0583 | 1.000000 | "" | "" | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `osrs_h[2:0]` bits 2:0**

Locations: `truth registers[24].field_parts[0].bit_field[1]` ↔ `without registers[2].field_parts[0].bit_field[1]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | osrs_h[2:0] | osrs_h[2:0] | correct |
| `field_description` | 0.0586 | 1.000000 | Controls oversampling of humidity data. | Controls oversampling of humidity data. | correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 2 | 2 | correct |
| `bit_width` | 0.0583 | 1.000000 | 3 | 3 | correct |
| `values` | 0.2097 | 1.000000 | [{"value":"000","value_description":"Skipped (output set to 0x8000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}] | [{"value":"000","value_description":"Skipped (output set to 0x8000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101..111","value_description":"oversampling ×16 (101 and other codes)"}] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` = mean(1.000000, 1.000000) = **1.000000**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | ctrl_hum | ctrl_hum | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xF2","decimal":"242","bank":"","page":"","description":"Humidity control register."} | {"hex":"0xF2","decimal":"242","bank":"","page":"","description":"Humidity oversampling control register"} | correct |
| `description` | 0.0693 | 1.000000 | Humidity data acquisition control register. | Controls humidity oversampling (osrs_h[2:0]). | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW | correct |
| `bit_field` | 0.3129 | 1.000000 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

### Logical-register aggregation

`field_parts` = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name` | 0.0225 | 1.000000 | ctrl_hum | ctrl_hum | correct |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0xF2","decimal":"242","bank":"","page":"","description":"Humidity control register."}] | [{"hex":"0xF2","decimal":"242","bank":"","page":"","description":"Controls humidity oversampling (osrs_h[2:0]); changes take effect after writing ctrl_meas"}] | correct |
| `register_description` | 0.0564 | 1.000000 | Sets humidity data acquisition options; changes become effective only after a write to ctrl_meas. | Sets humidity data acquisition options (humidity oversampling). Changes become effective after a write to ctrl_meas. | correct |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW | correct |
| `field_parts` | 0.2987 | 1.000000 | recursive truth field-part collection | recursive extracted field-part collection | mean of independently scored field parts |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| `default_value_description` | 0.0334 | 1.000000 | "" | Reset state shown in memory map (ctrl_hum = 0x00); changes become effective after writing ctrl_meas. | correct |

\(Q(L_{2})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

### Extracted logical register 4: `status`

Location: `without registers[3]`; truth association: `truth registers[23]` (`status`).
Associated physical locations: 0xF3 (243).

#### Field part 1: `status` at 0xF3 (243)

Locations: `truth registers[23].field_parts[0]` ↔ `without registers[3].field_parts[0]`.

**Truth bit field 1: `` bits 7:4**

Locations: `truth registers[23].field_parts[0].bit_field[0]` ↔ `without registers[3].field_parts[0].bit_field[0]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | "" | Reserved | correct |
| `field_description` | 0.0586 | 1.000000 | "" | "" | correct |
| `bit_start` | 0.2594 | 1.000000 | 4 | 4 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 4 | 4 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 1.000000 | True | True | correct |
| `type_write_read` | 0.0583 | 1.000000 | "" | "" | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `measuring[0]` bits 3:3**

Locations: `truth registers[23].field_parts[0].bit_field[1]` ↔ `without registers[3].field_parts[0].bit_field[1]`. Judgment: truth value cases are missing from the extracted bit field.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | measuring[0] | measuring[0] | correct |
| `field_description` | 0.0586 | 1.000000 | Indicates whether a conversion is running. | Set to '1' whenever a conversion is running; cleared to '0' when results are transferred to data registers. | correct |
| `bit_start` | 0.2594 | 1.000000 | 3 | 3 | correct |
| `bit_end` | 0.2594 | 1.000000 | 3 | 3 | correct |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 | correct |
| `values` | 0.2097 | 0.000000 | [{"value":"1","value_description":"A conversion is running."},{"value":"0","value_description":"No conversion is running; the bit returns to 0 after the results have been transferred to the data registers."}] | [] | incorrect or missing |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | R | R | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 3: `` bits 2:1**

Locations: `truth registers[23].field_parts[0].bit_field[2]` ↔ `without registers[3].field_parts[0].bit_field[2]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | "" | Reserved | correct |
| `field_description` | 0.0586 | 1.000000 | "" | "" | correct |
| `bit_start` | 0.2594 | 1.000000 | 1 | 1 | correct |
| `bit_end` | 0.2594 | 1.000000 | 2 | 2 | correct |
| `bit_width` | 0.0583 | 1.000000 | 2 | 2 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 1.000000 | True | True | correct |
| `type_write_read` | 0.0583 | 1.000000 | "" | "" | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `im_update[0]` bits 0:0**

Locations: `truth registers[23].field_parts[0].bit_field[3]` ↔ `without registers[3].field_parts[0].bit_field[3]`. Judgment: copying behavior is described, but the truth's power-on-reset/before-every-conversion timing is omitted; truth value cases are missing from the extracted bit field.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | im_update[0] | im_update[0] | correct |
| `field_description` | 0.0586 | 0.500000 | Indicates whether NVM data are being copied to image registers. The data are copied at power-on reset and before every conversion. | Set to '1' when NVM data are being copied to image registers and back to '0' when copying is done. | partially correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 | correct |
| `values` | 0.2097 | 0.000000 | [{"value":"1","value_description":"NVM data are being copied to image registers."},{"value":"0","value_description":"Copying is done."}] | [] | incorrect or missing |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | R | R | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.760900/0.9999=\mathbf{0.760976}\).

**Field-part aggregation**

`bit_field` = mean(1.000000, 0.790279, 1.000000, 0.760976) = **0.887814**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | status | status | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xF3","decimal":"243","bank":"","page":"","description":"Device status register."} | {"hex":"0xF3","decimal":"243","bank":"","page":"","description":"Device status"} | correct |
| `description` | 0.0693 | 1.000000 | Device status register. | Status bits for measurement and NVM image update. | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | R | R | correct |
| `bit_field` | 0.3129 | 0.887814 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.887814)/1.0000=0.964897/1.0000=\mathbf{0.964897}\).

### Logical-register aggregation

`field_parts` = mean(0.964897) = **0.964897**.

| Logical-register field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name` | 0.0225 | 1.000000 | status | status | correct |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0xF3","decimal":"243","bank":"","page":"","description":"Device status register."}] | [{"hex":"0xF3","decimal":"243","bank":"","page":"","description":"Status register containing measuring and im_update bits"}] | correct |
| `register_description` | 0.0564 | 1.000000 | Contains bits indicating conversion activity and NVM-to-image-register copying status. | Status register: indicates if a conversion is running (measuring) and if NVM data are being copied to image registers (im_update). | correct |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0590 | 1.000000 | R | R | correct |
| `field_parts` | 0.2987 | 0.964897 | recursive truth field-part collection | recursive extracted field-part collection | mean of independently scored field parts |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| `default_value_description` | 0.0334 | 1.000000 | "" | Reset state shown in memory map. | correct |

\(Q(L_{3})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.964897 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.989615/1.0001=\mathbf{0.989516}\).

### Extracted logical register 5: `ctrl_meas`

Location: `without registers[4]`; truth association: `truth registers[22]` (`ctrl_meas`).
Associated physical locations: 0xF4 (244).

#### Field part 1: `ctrl_meas` at 0xF4 (244)

Locations: `truth registers[22].field_parts[0]` ↔ `without registers[4].field_parts[0]`.

**Truth bit field 1: `osrs_t[2:0]` bits 7:5**

Locations: `truth registers[22].field_parts[0].bit_field[0]` ↔ `without registers[4].field_parts[0].bit_field[0]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | osrs_t[2:0] | osrs_t[2:0] | correct |
| `field_description` | 0.0586 | 1.000000 | Controls oversampling of temperature data. | Controls oversampling of temperature data. | correct |
| `bit_start` | 0.2594 | 1.000000 | 5 | 5 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 3 | 3 | correct |
| `values` | 0.2097 | 1.000000 | [{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}] | [{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101..111","value_description":"oversampling ×16 (101 and other codes)"}] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `osrs_p[2:0]` bits 4:2**

Locations: `truth registers[22].field_parts[0].bit_field[1]` ↔ `without registers[4].field_parts[0].bit_field[1]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | osrs_p[2:0] | osrs_p[2:0] | correct |
| `field_description` | 0.0586 | 1.000000 | Controls oversampling of pressure data. | Controls oversampling of pressure data. | correct |
| `bit_start` | 0.2594 | 1.000000 | 2 | 2 | correct |
| `bit_end` | 0.2594 | 1.000000 | 4 | 4 | correct |
| `bit_width` | 0.0583 | 1.000000 | 3 | 3 | correct |
| `values` | 0.2097 | 1.000000 | [{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101, others","value_description":"oversampling ×16"}] | [{"value":"000","value_description":"Skipped (output set to 0x80000)"},{"value":"001","value_description":"oversampling ×1"},{"value":"010","value_description":"oversampling ×2"},{"value":"011","value_description":"oversampling ×4"},{"value":"100","value_description":"oversampling ×8"},{"value":"101..111","value_description":"oversampling ×16 (101 and other codes)"}] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `mode[1:0]` bits 1:0**

Locations: `truth registers[22].field_parts[0].bit_field[2]` ↔ `without registers[4].field_parts[0].bit_field[2]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | mode[1:0] | mode[1:0] | correct |
| `field_description` | 0.0586 | 1.000000 | Controls the sensor mode of the device. | Controls sensor mode: sleep, forced, normal. | correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 1 | 1 | correct |
| `bit_width` | 0.0583 | 1.000000 | 2 | 2 | correct |
| `values` | 0.2097 | 1.000000 | [{"value":"00","value_description":"Sleep mode"},{"value":"01 and 10","value_description":"Forced mode"},{"value":"11","value_description":"Normal mode"}] | [{"value":"00","value_description":"Sleep mode"},{"value":"01..10","value_description":"Forced mode (01 and 10)"},{"value":"11","value_description":"Normal mode"}] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` = mean(1.000000, 1.000000, 1.000000) = **1.000000**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | ctrl_meas | ctrl_meas | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xF4","decimal":"244","bank":"","page":"","description":"Measurement control register."} | {"hex":"0xF4","decimal":"244","bank":"","page":"","description":"Temperature/pressure control and mode"} | correct |
| `description` | 0.0693 | 1.000000 | Pressure and temperature data acquisition control register. | Controls temperature oversampling (osrs_t[2:0]), pressure oversampling (osrs_p[2:0]) and sensor mode (mode[1:0]). | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW | correct |
| `bit_field` | 0.3129 | 1.000000 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

### Logical-register aggregation

`field_parts` = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name` | 0.0225 | 1.000000 | ctrl_meas | ctrl_meas | correct |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0xF4","decimal":"244","bank":"","page":"","description":"Measurement control register."}] | [{"hex":"0xF4","decimal":"244","bank":"","page":"","description":"Controls temperature and pressure data acquisition and sensor mode (osrs_t, osrs_p, mode)"}] | correct |
| `register_description` | 0.0564 | 1.000000 | Sets pressure and temperature data acquisition options and must be written after changing ctrl_hum for those changes to become effective. | Sets pressure and temperature oversampling and sensor mode. Must be written after changing ctrl_hum for humidity changes to take effect. | correct |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW | correct |
| `field_parts` | 0.2987 | 1.000000 | recursive truth field-part collection | recursive extracted field-part collection | mean of independently scored field parts |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| `default_value_description` | 0.0334 | 1.000000 | "" | Reset state shown in memory map (ctrl_meas = 0x00). | correct |

\(Q(L_{4})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

### Extracted logical register 6: `config`

Location: `without registers[5]`; truth association: `truth registers[18]` (`config`).
Associated physical locations: 0xF5 (245).

#### Field part 1: `config` at 0xF5 (245)

Locations: `truth registers[18].field_parts[0]` ↔ `without registers[5].field_parts[0]`.

**Truth bit field 1: `t_sb[2:0]` bits 7:5**

Locations: `truth registers[18].field_parts[0].bit_field[0]` ↔ `without registers[5].field_parts[0].bit_field[0]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | t_sb[2:0] | t_sb[2:0] | correct |
| `field_description` | 0.0586 | 1.000000 | Controls inactive duration t_standby in normal mode. | Controls inactive duration (t_standby) in normal mode. | correct |
| `bit_start` | 0.2594 | 1.000000 | 5 | 5 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 3 | 3 | correct |
| `values` | 0.2097 | 1.000000 | [{"value":"000","value_description":"0.5 ms"},{"value":"001","value_description":"62.5 ms"},{"value":"010","value_description":"125 ms"},{"value":"011","value_description":"250 ms"},{"value":"100","value_description":"500 ms"},{"value":"101","value_description":"1000 ms"},{"value":"110","value_description":"10 ms"},{"value":"111","value_description":"20 ms"}] | [{"value":"000","value_description":"t_standby = 0.5 ms"},{"value":"001","value_description":"t_standby = 62.5 ms"},{"value":"010","value_description":"t_standby = 125 ms"},{"value":"011","value_description":"t_standby = 250 ms"},{"value":"100","value_description":"t_standby = 500 ms"},{"value":"101","value_description":"t_standby = 1000 ms"},{"value":"110","value_description":"t_standby = 10 ms"},{"value":"111","value_description":"t_standby = 20 ms"}] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `filter[2:0]` bits 4:2**

Locations: `truth registers[18].field_parts[0].bit_field[1]` ↔ `without registers[5].field_parts[0].bit_field[1]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | filter[2:0] | filter[2:0] | correct |
| `field_description` | 0.0586 | 1.000000 | Controls the time constant of the IIR filter. | Controls IIR filter time constant (filter coefficient). | correct |
| `bit_start` | 0.2594 | 1.000000 | 2 | 2 | correct |
| `bit_end` | 0.2594 | 1.000000 | 4 | 4 | correct |
| `bit_width` | 0.0583 | 1.000000 | 3 | 3 | correct |
| `values` | 0.2097 | 1.000000 | [{"value":"000","value_description":"Filter off"},{"value":"001","value_description":"Filter coefficient 2"},{"value":"010","value_description":"Filter coefficient 4"},{"value":"011","value_description":"Filter coefficient 8"},{"value":"100, others","value_description":"Filter coefficient 16"}] | [{"value":"000","value_description":"Filter off"},{"value":"001","value_description":"Filter coefficient = 2"},{"value":"010","value_description":"Filter coefficient = 4"},{"value":"011","value_description":"Filter coefficient = 8"},{"value":"100..111","value_description":"Filter coefficient = 16 (100 and other codes)"}] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `` bits 1:1**

Locations: `truth registers[18].field_parts[0].bit_field[2]` ↔ `without registers[5].field_parts[0].bit_field[2]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | "" | Reserved | correct |
| `field_description` | 0.0586 | 1.000000 | "" | "" | correct |
| `bit_start` | 0.2594 | 1.000000 | 1 | 1 | correct |
| `bit_end` | 0.2594 | 1.000000 | 1 | 1 | correct |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 1.000000 | True | True | correct |
| `type_write_read` | 0.0583 | 1.000000 | "" | "" | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `spi3w_en[0]` bits 0:0**

Locations: `truth registers[18].field_parts[0].bit_field[3]` ↔ `without registers[5].field_parts[0].bit_field[3]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | spi3w_en[0] | spi3w_en[0] | correct |
| `field_description` | 0.0586 | 1.000000 | Enables the 3-wire SPI interface when set to '1'. | Enables 3-wire SPI interface when set to '1'. | correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_width` | 0.0583 | 1.000000 | 1 | 1 | correct |
| `values` | 0.2097 | 1.000000 | [{"value":"1","value_description":"3-wire SPI interface enabled."}] | [{"value":"0","value_description":"3-wire SPI disabled (default)"},{"value":"1","value_description":"3-wire SPI enabled"}] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | RW | RW | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` = mean(1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | config | config | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xF5","decimal":"245","bank":"","page":"","description":"Configuration register."} | {"hex":"0xF5","decimal":"245","bank":"","page":"","description":"Filter, standby and interface configuration"} | correct |
| `description` | 0.0693 | 1.000000 | Rate, filter and interface configuration register. | Controls t_standby, IIR filter coefficient and 3-wire SPI enable. | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW | correct |
| `bit_field` | 0.3129 | 1.000000 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

### Logical-register aggregation

`field_parts` = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name` | 0.0225 | 1.000000 | config | config | correct |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0xF5","decimal":"245","bank":"","page":"","description":"Configuration register."}] | [{"hex":"0xF5","decimal":"245","bank":"","page":"","description":"Configuration register: standby time (t_sb), IIR filter (filter) and 3-wire SPI enable (spi3w_en)"}] | correct |
| `register_description` | 0.0564 | 0.500000 | Sets the rate, filter and interface options of the device; writes in normal mode may be ignored. In sleep mode writes are not ignored. | Sets standby time in normal mode (t_sb), IIR filter coefficient (filter) and enables 3-wire SPI when set (spi3w_en). Writes in normal mode may be ignored. | partially correct |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW | correct |
| `field_parts` | 0.2987 | 1.000000 | recursive truth field-part collection | recursive extracted field-part collection | mean of independently scored field parts |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 | correct |
| `default_value_description` | 0.0334 | 1.000000 | "" | Reset state shown in memory map (config = 0x00). Writes in normal mode may be ignored. | correct |

\(Q(L_{5})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

### Extracted logical register 7: `press`

Location: `without registers[6]`; truth association: `truth registers[21]` (`press`).
Associated physical locations: 0xF7 (247), 0xF8 (248), 0xF9 (249).

#### Field part 1: `press_msb` at 0xF7 (247)

Locations: `truth registers[21].field_parts[0]` ↔ `without registers[6].field_parts[0]`.

**Truth bit field 1: `press_msb[7:0]` bits 7:0**

Locations: `truth registers[21].field_parts[0].bit_field[0]` ↔ `without registers[6].field_parts[0].bit_field[0]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | press_msb[7:0] | press_msb[7:0] | correct |
| `field_description` | 0.0586 | 1.000000 | MSB part up[19:12] of the raw pressure measurement output. | Contains up[19:12] — MSB part of 20-bit raw pressure. | correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | R | R | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | press_msb | press_msb | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xF7","decimal":"247","bank":"","page":"","description":"Pressure MSB."} | {"hex":"0xF7","decimal":"247","bank":"","page":"","description":"MSB byte of raw pressure (up[19:12])"} | correct |
| `description` | 0.0693 | 1.000000 | MSB part up[19:12] of the raw pressure output. | MSB part of raw pressure measurement (up[19:12]). | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | R | R | correct |
| `bit_field` | 0.3129 | 1.000000 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

#### Field part 2: `press_lsb` at 0xF8 (248)

Locations: `truth registers[21].field_parts[1]` ↔ `without registers[6].field_parts[1]`.

**Truth bit field 1: `press_lsb[7:0]` bits 7:0**

Locations: `truth registers[21].field_parts[1].bit_field[0]` ↔ `without registers[6].field_parts[1].bit_field[0]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | press_lsb[7:0] | press_lsb[7:0] | correct |
| `field_description` | 0.0586 | 1.000000 | LSB part up[11:4] of the raw pressure measurement output. | Contains up[11:4] — middle byte of 20-bit raw pressure. | correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | R | R | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | press_lsb | press_lsb | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xF8","decimal":"248","bank":"","page":"","description":"Pressure LSB."} | {"hex":"0xF8","decimal":"248","bank":"","page":"","description":"LSB byte of raw pressure (up[11:4])"} | correct |
| `description` | 0.0693 | 1.000000 | LSB part up[11:4] of the raw pressure output. | LSB part of raw pressure measurement (up[11:4]). | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | R | R | correct |
| `bit_field` | 0.3129 | 1.000000 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

#### Field part 3: `press_xlsb` at 0xF9 (249)

Locations: `truth registers[21].field_parts[2]` ↔ `without registers[6].field_parts[2]`.

**Truth bit field 1: `press_xlsb[3:0]` bits 7:4**

Locations: `truth registers[21].field_parts[2].bit_field[0]` ↔ `without registers[6].field_parts[2].bit_field[0]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | press_xlsb[3:0] | press_xlsb[3:0] | correct |
| `field_description` | 0.0586 | 1.000000 | XLSB part up[3:0] of the raw pressure measurement output. | Contains up[3:0] in bits 7:4 (XLSB of 20-bit raw pressure). Contents depend on resolution/filtering. | correct |
| `bit_start` | 0.2594 | 1.000000 | 4 | 4 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 4 | 4 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | R | R | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `0` bits 3:0**

Locations: `truth registers[21].field_parts[2].bit_field[1]`, `truth registers[21].field_parts[2].bit_field[2]`, `truth registers[21].field_parts[2].bit_field[3]`, `truth registers[21].field_parts[2].bit_field[4]` ↔ `without registers[6].field_parts[2].bit_field[1]`; grouping-equivalent merged truth target from `truth registers[21].field_parts[2].bit_field[1]`, `truth registers[21].field_parts[2].bit_field[2]`, `truth registers[21].field_parts[2].bit_field[3]`, `truth registers[21].field_parts[2].bit_field[4]`. Judgment: truth fixed-zero bits are labelled 0, but the extracted merged field is labelled Reserved; the merged lower-nibble description identifies unused bits but does not state that they are fixed zero; truth is_reserved=False, extracted=True.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | 0 | Reserved | incorrect or missing |
| `field_description` | 0.0586 | 0.500000 | Shown as 0 in the memory map. | Lower nibble; content depends on resolution and is not used for up[3:0]. | partially correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 3 | 3 | correct |
| `bit_width` | 0.0583 | 1.000000 | 4 | 4 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 0.000000 | False | True | incorrect or missing |
| `type_write_read` | 0.0583 | 1.000000 | "" | "" | correct |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×0.000000 + 0.0583×1.000000)/0.9999=0.874400/0.9999=\mathbf{0.874487}\).

**Field-part aggregation**

`bit_field` = mean(1.000000, 0.874487) = **0.937244**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | press_xlsb | press_xlsb | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xF9","decimal":"249","bank":"","page":"","description":"Pressure XLSB in bits 7:4."} | {"hex":"0xF9","decimal":"249","bank":"","page":"","description":"XLSB nibble of raw pressure (up[3:0] stored in bits7:4)"} | correct |
| `description` | 0.0693 | 1.000000 | XLSB part up[3:0] in bits 7:4. | XLSB part of raw pressure measurement (up[3:0] in bits7:4). | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | R | R | correct |
| `bit_field` | 0.3129 | 0.937244 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.937244)/1.0000=0.980364/1.0000=\mathbf{0.980364}\).

### Logical-register aggregation

`field_parts` = mean(1.000000, 1.000000, 0.980364) = **0.993455**.

| Logical-register field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name` | 0.0225 | 1.000000 | press | press | correct |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0xF7","decimal":"247","bank":"","page":"","description":"Pressure MSB."},{"hex":"0xF8","decimal":"248","bank":"","page":"","description":"Pressure LSB."},{"hex":"0xF9","decimal":"249","bank":"","page":"","description":"Pressure XLSB in bits 7:4."}] | [{"hex":"0xF7","decimal":"247","bank":"","page":"","description":"press_msb: contains up[19:12] (MSB part of raw pressure data)"},{"hex":"0xF8","decimal":"248","bank":"","page":"","description":"press_lsb: contains up[11:4] (LSB part of raw pressure data)"},{"hex":"0xF9","decimal":"249","bank":"","page":"","description":"press_xlsb (bits7:4): contains up[3:0] (XLSB part of raw pressure data)"}] | correct |
| `register_description` | 0.0564 | 1.000000 | Contains the unsigned 20-bit raw pressure measurement output up[19:0]. | Raw pressure measurement output up[19:0] provided across three registers (press_msb, press_lsb, press_xlsb). Combined unsigned 20-bit value. | correct |
| `width_bits` | 0.0590 | 1.000000 | 20 | 20 | correct |
| `type_write_read` | 0.0590 | 1.000000 | R | R | correct |
| `field_parts` | 0.2987 | 0.993455 | recursive truth field-part collection | recursive extracted field-part collection | mean of independently scored field parts |
| `default_value` | 0.0667 | 1.000000 | 0x80000 | 0x80000 | correct |
| `default_value_description` | 0.0334 | 1.000000 | "" | Reset states per bytes: press_msb=0x80, press_lsb=0x00, press_xlsb=0x00 -> combined 20-bit default 0x80000 (as shown in memory map). | correct |

\(Q(L_{6})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.993455 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.998145/1.0001=\mathbf{0.998045}\).

### Extracted logical register 8: `temp`

Location: `without registers[7]`; truth association: `truth registers[20]` (`temp`).
Associated physical locations: 0xFA (250), 0xFB (251), 0xFC (252).

#### Field part 1: `temp_msb` at 0xFA (250)

Locations: `truth registers[20].field_parts[0]` ↔ `without registers[7].field_parts[0]`.

**Truth bit field 1: `temp_msb[7:0]` bits 7:0**

Locations: `truth registers[20].field_parts[0].bit_field[0]` ↔ `without registers[7].field_parts[0].bit_field[0]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | temp_msb[7:0] | temp_msb[7:0] | correct |
| `field_description` | 0.0586 | 1.000000 | MSB part ut[19:12] of the raw temperature measurement output. | Contains ut[19:12] — MSB part of 20-bit raw temperature. | correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | R | R | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | temp_msb | temp_msb | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xFA","decimal":"250","bank":"","page":"","description":"Temperature MSB."} | {"hex":"0xFA","decimal":"250","bank":"","page":"","description":"MSB byte of raw temperature (ut[19:12])"} | correct |
| `description` | 0.0693 | 1.000000 | MSB part ut[19:12] of the raw temperature output. | MSB part of raw temperature measurement (ut[19:12]). | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | R | R | correct |
| `bit_field` | 0.3129 | 1.000000 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

#### Field part 2: `temp_lsb` at 0xFB (251)

Locations: `truth registers[20].field_parts[1]` ↔ `without registers[7].field_parts[1]`.

**Truth bit field 1: `temp_lsb[7:0]` bits 7:0**

Locations: `truth registers[20].field_parts[1].bit_field[0]` ↔ `without registers[7].field_parts[1].bit_field[0]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | temp_lsb[7:0] | temp_lsb[7:0] | correct |
| `field_description` | 0.0586 | 1.000000 | LSB part ut[11:4] of the raw temperature measurement output. | Contains ut[11:4] — middle byte of 20-bit raw temperature. | correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | R | R | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | temp_lsb | temp_lsb | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xFB","decimal":"251","bank":"","page":"","description":"Temperature LSB."} | {"hex":"0xFB","decimal":"251","bank":"","page":"","description":"LSB byte of raw temperature (ut[11:4])"} | correct |
| `description` | 0.0693 | 1.000000 | LSB part ut[11:4] of the raw temperature output. | LSB part of raw temperature measurement (ut[11:4]). | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | R | R | correct |
| `bit_field` | 0.3129 | 1.000000 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

#### Field part 3: `temp_xlsb` at 0xFC (252)

Locations: `truth registers[20].field_parts[2]` ↔ `without registers[7].field_parts[2]`.

**Truth bit field 1: `temp_xlsb[3:0]` bits 7:4**

Locations: `truth registers[20].field_parts[2].bit_field[0]` ↔ `without registers[7].field_parts[2].bit_field[0]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | temp_xlsb[3:0] | temp_xlsb[3:0] | correct |
| `field_description` | 0.0586 | 1.000000 | XLSB part ut[3:0] of the raw temperature measurement output. | Contains ut[3:0] in bits 7:4 (XLSB of 20-bit raw temperature). | correct |
| `bit_start` | 0.2594 | 1.000000 | 4 | 4 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 4 | 4 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | R | R | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `0` bits 3:0**

Locations: `truth registers[20].field_parts[2].bit_field[1]`, `truth registers[20].field_parts[2].bit_field[2]`, `truth registers[20].field_parts[2].bit_field[3]`, `truth registers[20].field_parts[2].bit_field[4]` ↔ `without registers[7].field_parts[2].bit_field[1]`; grouping-equivalent merged truth target from `truth registers[20].field_parts[2].bit_field[1]`, `truth registers[20].field_parts[2].bit_field[2]`, `truth registers[20].field_parts[2].bit_field[3]`, `truth registers[20].field_parts[2].bit_field[4]`. Judgment: truth fixed-zero bits are labelled 0, but the extracted merged field is labelled Reserved; the merged lower-nibble description identifies unused bits but does not state that they are fixed zero; truth is_reserved=False, extracted=True.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 0.000000 | 0 | Reserved | incorrect or missing |
| `field_description` | 0.0586 | 0.500000 | Shown as 0 in the memory map. | Lower nibble; not used for ut[3:0]. | partially correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 3 | 3 | correct |
| `bit_width` | 0.0583 | 1.000000 | 4 | 4 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 0.000000 | False | True | incorrect or missing |
| `type_write_read` | 0.0583 | 1.000000 | "" | "" | correct |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×0.000000 + 0.0583×1.000000)/0.9999=0.874400/0.9999=\mathbf{0.874487}\).

**Field-part aggregation**

`bit_field` = mean(1.000000, 0.874487) = **0.937244**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | temp_xlsb | temp_xlsb | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xFC","decimal":"252","bank":"","page":"","description":"Temperature XLSB in bits 7:4."} | {"hex":"0xFC","decimal":"252","bank":"","page":"","description":"XLSB nibble of raw temperature (ut[3:0] stored in bits7:4)"} | correct |
| `description` | 0.0693 | 1.000000 | XLSB part ut[3:0] in bits 7:4. | XLSB part of raw temperature measurement (ut[3:0] in bits7:4). | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | R | R | correct |
| `bit_field` | 0.3129 | 0.937244 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.937244)/1.0000=0.980364/1.0000=\mathbf{0.980364}\).

### Logical-register aggregation

`field_parts` = mean(1.000000, 1.000000, 0.980364) = **0.993455**.

| Logical-register field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name` | 0.0225 | 1.000000 | temp | temp | correct |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0xFA","decimal":"250","bank":"","page":"","description":"Temperature MSB."},{"hex":"0xFB","decimal":"251","bank":"","page":"","description":"Temperature LSB."},{"hex":"0xFC","decimal":"252","bank":"","page":"","description":"Temperature XLSB in bits 7:4."}] | [{"hex":"0xFA","decimal":"250","bank":"","page":"","description":"temp_msb: contains ut[19:12] (MSB part of raw temperature data)"},{"hex":"0xFB","decimal":"251","bank":"","page":"","description":"temp_lsb: contains ut[11:4] (LSB part of raw temperature data)"},{"hex":"0xFC","decimal":"252","bank":"","page":"","description":"temp_xlsb (bits7:4): contains ut[3:0] (XLSB part of raw temperature data)"}] | correct |
| `register_description` | 0.0564 | 1.000000 | Contains the unsigned 20-bit raw temperature measurement output ut[19:0]. | Raw temperature measurement output ut[19:0] provided across three registers (temp_msb, temp_lsb, temp_xlsb). Combined unsigned 20-bit value used for compensation. | correct |
| `width_bits` | 0.0590 | 1.000000 | 20 | 20 | correct |
| `type_write_read` | 0.0590 | 1.000000 | R | R | correct |
| `field_parts` | 0.2987 | 0.993455 | recursive truth field-part collection | recursive extracted field-part collection | mean of independently scored field parts |
| `default_value` | 0.0667 | 1.000000 | 0x80000 | 0x80000 | correct |
| `default_value_description` | 0.0334 | 1.000000 | "" | Reset states per bytes: temp_msb=0x80, temp_lsb=0x00, temp_xlsb=0x00 -> combined 20-bit default 0x80000 (as shown in memory map). | correct |

\(Q(L_{7})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.993455 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.998145/1.0001=\mathbf{0.998045}\).

### Extracted logical register 9: `hum`

Location: `without registers[8]`; truth association: `truth registers[19]` (`hum`).
Associated physical locations: 0xFD (253), 0xFE (254).

#### Field part 1: `hum_msb` at 0xFD (253)

Locations: `truth registers[19].field_parts[0]` ↔ `without registers[8].field_parts[0]`.

**Truth bit field 1: `hum_msb[7:0]` bits 7:0**

Locations: `truth registers[19].field_parts[0].bit_field[0]` ↔ `without registers[8].field_parts[0].bit_field[0]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | hum_msb[7:0] | hum_msb[7:0] | correct |
| `field_description` | 0.0586 | 1.000000 | MSB part uh[15:8] of the raw humidity measurement output. | Contains uh[15:8] — MSB part of 16-bit raw humidity. | correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | R | R | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | hum_msb | hum_msb | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xFD","decimal":"253","bank":"","page":"","description":"Humidity MSB."} | {"hex":"0xFD","decimal":"253","bank":"","page":"","description":"MSB byte of raw humidity (uh[15:8])"} | correct |
| `description` | 0.0693 | 1.000000 | MSB part uh[15:8] of the raw humidity output. | MSB part of raw humidity measurement (uh[15:8]). | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | R | R | correct |
| `bit_field` | 0.3129 | 1.000000 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

#### Field part 2: `hum_lsb` at 0xFE (254)

Locations: `truth registers[19].field_parts[1]` ↔ `without registers[8].field_parts[1]`.

**Truth bit field 1: `hum_lsb[7:0]` bits 7:0**

Locations: `truth registers[19].field_parts[1].bit_field[0]` ↔ `without registers[8].field_parts[1].bit_field[0]`. Judgment: semantically complete and correct.

| Scored field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name_or_parameter` | 0.0212 | 1.000000 | hum_lsb[7:0] | hum_lsb[7:0] | correct |
| `field_description` | 0.0586 | 1.000000 | LSB part uh[7:0] of the raw humidity measurement output. | Contains uh[7:0] — LSB part of 16-bit raw humidity. | correct |
| `bit_start` | 0.2594 | 1.000000 | 0 | 0 | correct |
| `bit_end` | 0.2594 | 1.000000 | 7 | 7 | correct |
| `bit_width` | 0.0583 | 1.000000 | 8 | 8 | correct |
| `values` | 0.2097 | 1.000000 | [] | [] | correct |
| `is_reserved` | 0.0750 | 1.000000 | False | False | correct |
| `type_write_read` | 0.0583 | 1.000000 | R | R | correct |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `register_name` | 0.0280 | 1.000000 | hum_lsb | hum_lsb | correct |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0xFE","decimal":"254","bank":"","page":"","description":"Humidity LSB."} | {"hex":"0xFE","decimal":"254","bank":"","page":"","description":"LSB byte of raw humidity (uh[7:0])"} | correct |
| `description` | 0.0693 | 1.000000 | LSB part uh[7:0] of the raw humidity output. | LSB part of raw humidity measurement (uh[7:0]). | correct |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 | correct |
| `type_write_read` | 0.0605 | 1.000000 | R | R | correct |
| `bit_field` | 0.3129 | 1.000000 | recursive truth-target bit-field collection | recursive extracted bit-field collection | mean of the bottom-up bit-field scores |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

### Logical-register aggregation

`field_parts` = mean(1.000000, 1.000000) = **1.000000**.

| Logical-register field | Weight | C | Truth content | without content | Assessment |
|---|---:|---:|---|---|---|
| `name` | 0.0225 | 1.000000 | hum | hum | correct |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0xFD","decimal":"253","bank":"","page":"","description":"Humidity MSB."},{"hex":"0xFE","decimal":"254","bank":"","page":"","description":"Humidity LSB."}] | [{"hex":"0xFD","decimal":"253","bank":"","page":"","description":"hum_msb: contains uh[15:8] (MSB part of raw humidity data)"},{"hex":"0xFE","decimal":"254","bank":"","page":"","description":"hum_lsb: contains uh[7:0] (LSB part of raw humidity data)"}] | correct |
| `register_description` | 0.0564 | 1.000000 | Contains the unsigned 16-bit raw humidity measurement output uh[15:0]. | Raw humidity measurement output uh[15:0] provided across two registers (hum_msb, hum_lsb). Combined unsigned 16-bit value used for humidity compensation. | correct |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 | correct |
| `type_write_read` | 0.0590 | 1.000000 | R | R | correct |
| `field_parts` | 0.2987 | 1.000000 | recursive truth field-part collection | recursive extracted field-part collection | mean of independently scored field parts |
| `default_value` | 0.0667 | 1.000000 | 0x8000 | 0x8000 | correct |
| `default_value_description` | 0.0334 | 1.000000 | "" | Reset states per bytes: hum_msb=0x80, hum_lsb=0x00 -> combined 16-bit default 0x8000 (as shown in memory map). | correct |

\(Q(L_{8})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## 3. Ground-truth physical-register scores

For every truth physical location, `q_R` is the mean of the associated extracted logical-register scores. Missing truth locations receive `q_R=0`; extra extracted physical locations are counted in `x`.

| Truth physical address | Truth owner(s) | Associated extracted logical registers and Q(L) | q_R |
|---|---|---|---:|
| 0x88 (136) | dig_T1 (`truth registers[0].field_parts[0]`) | none → 0 | 0.000000 |
| 0x89 (137) | dig_T1 (`truth registers[0].field_parts[1]`) | none → 0 | 0.000000 |
| 0x8A (138) | dig_T2 (`truth registers[1].field_parts[0]`) | none → 0 | 0.000000 |
| 0x8B (139) | dig_T2 (`truth registers[1].field_parts[1]`) | none → 0 | 0.000000 |
| 0x8C (140) | dig_T3 (`truth registers[2].field_parts[0]`) | none → 0 | 0.000000 |
| 0x8D (141) | dig_T3 (`truth registers[2].field_parts[1]`) | none → 0 | 0.000000 |
| 0x8E (142) | dig_P1 (`truth registers[3].field_parts[0]`) | none → 0 | 0.000000 |
| 0x8F (143) | dig_P1 (`truth registers[3].field_parts[1]`) | none → 0 | 0.000000 |
| 0x90 (144) | dig_P2 (`truth registers[4].field_parts[0]`) | none → 0 | 0.000000 |
| 0x91 (145) | dig_P2 (`truth registers[4].field_parts[1]`) | none → 0 | 0.000000 |
| 0x92 (146) | dig_P3 (`truth registers[5].field_parts[0]`) | none → 0 | 0.000000 |
| 0x93 (147) | dig_P3 (`truth registers[5].field_parts[1]`) | none → 0 | 0.000000 |
| 0x94 (148) | dig_P4 (`truth registers[6].field_parts[0]`) | none → 0 | 0.000000 |
| 0x95 (149) | dig_P4 (`truth registers[6].field_parts[1]`) | none → 0 | 0.000000 |
| 0x96 (150) | dig_P5 (`truth registers[7].field_parts[0]`) | none → 0 | 0.000000 |
| 0x97 (151) | dig_P5 (`truth registers[7].field_parts[1]`) | none → 0 | 0.000000 |
| 0x98 (152) | dig_P6 (`truth registers[8].field_parts[0]`) | none → 0 | 0.000000 |
| 0x99 (153) | dig_P6 (`truth registers[8].field_parts[1]`) | none → 0 | 0.000000 |
| 0x9A (154) | dig_P7 (`truth registers[9].field_parts[0]`) | none → 0 | 0.000000 |
| 0x9B (155) | dig_P7 (`truth registers[9].field_parts[1]`) | none → 0 | 0.000000 |
| 0x9C (156) | dig_P8 (`truth registers[10].field_parts[0]`) | none → 0 | 0.000000 |
| 0x9D (157) | dig_P8 (`truth registers[10].field_parts[1]`) | none → 0 | 0.000000 |
| 0x9E (158) | dig_P9 (`truth registers[11].field_parts[0]`) | none → 0 | 0.000000 |
| 0x9F (159) | dig_P9 (`truth registers[11].field_parts[1]`) | none → 0 | 0.000000 |
| 0xA1 (161) | dig_H1 (`truth registers[12].field_parts[0]`) | none → 0 | 0.000000 |
| 0xD0 (208) | id (`truth registers[17].field_parts[0]`) | without registers[0] `id`=0.980401 | 0.980401 |
| 0xE0 (224) | reset (`truth registers[25].field_parts[0]`) | without registers[1] `reset`=0.945305 | 0.945305 |
| 0xE1 (225) | dig_H2 (`truth registers[13].field_parts[0]`) | none → 0 | 0.000000 |
| 0xE2 (226) | dig_H2 (`truth registers[13].field_parts[1]`) | none → 0 | 0.000000 |
| 0xE3 (227) | dig_H3 (`truth registers[14].field_parts[0]`) | none → 0 | 0.000000 |
| 0xE4 (228) | dig_H4 (`truth registers[15].field_parts[0]`) | none → 0 | 0.000000 |
| 0xE5 (229) | dig_H4 (`truth registers[15].field_parts[1]`); dig_H5 (`truth registers[26].field_parts[0]`) | none → 0 | 0.000000 |
| 0xE6 (230) | dig_H5 (`truth registers[26].field_parts[1]`) | none → 0 | 0.000000 |
| 0xE7 (231) | dig_H6 (`truth registers[16].field_parts[0]`) | none → 0 | 0.000000 |
| 0xF2 (242) | ctrl_hum (`truth registers[24].field_parts[0]`) | without registers[2] `ctrl_hum`=1.000000 | 1.000000 |
| 0xF3 (243) | status (`truth registers[23].field_parts[0]`) | without registers[3] `status`=0.989516 | 0.989516 |
| 0xF4 (244) | ctrl_meas (`truth registers[22].field_parts[0]`) | without registers[4] `ctrl_meas`=1.000000 | 1.000000 |
| 0xF5 (245) | config (`truth registers[18].field_parts[0]`) | without registers[5] `config`=0.971803 | 0.971803 |
| 0xF7 (247) | press (`truth registers[21].field_parts[0]`) | without registers[6] `press`=0.998045 | 0.998045 |
| 0xF8 (248) | press (`truth registers[21].field_parts[1]`) | without registers[6] `press`=0.998045 | 0.998045 |
| 0xF9 (249) | press (`truth registers[21].field_parts[2]`) | without registers[6] `press`=0.998045 | 0.998045 |
| 0xFA (250) | temp (`truth registers[20].field_parts[0]`) | without registers[7] `temp`=0.998045 | 0.998045 |
| 0xFB (251) | temp (`truth registers[20].field_parts[1]`) | without registers[7] `temp`=0.998045 | 0.998045 |
| 0xFC (252) | temp (`truth registers[20].field_parts[2]`) | without registers[7] `temp`=0.998045 | 0.998045 |
| 0xFD (253) | hum (`truth registers[19].field_parts[0]`) | without registers[8] `hum`=1.000000 | 1.000000 |
| 0xFE (254) | hum (`truth registers[19].field_parts[1]`) | without registers[8] `hum`=1.000000 | 1.000000 |

### Missing truth logical-register items

These truth logical registers have no extracted logical-register item with the same name. Their physical locations are absent or, in the shared-address case, are still not covered by a truth-owner extraction; their physical-register contributions are therefore represented as `q_R=0` in the table above.

| Truth logical register | Truth path | Truth physical locations |
|---|---|---|
| `dig_T1` | `truth registers[0]` | 0x88 (136), 0x89 (137) |
| `dig_T2` | `truth registers[1]` | 0x8A (138), 0x8B (139) |
| `dig_T3` | `truth registers[2]` | 0x8C (140), 0x8D (141) |
| `dig_P1` | `truth registers[3]` | 0x8E (142), 0x8F (143) |
| `dig_P2` | `truth registers[4]` | 0x90 (144), 0x91 (145) |
| `dig_P3` | `truth registers[5]` | 0x92 (146), 0x93 (147) |
| `dig_P4` | `truth registers[6]` | 0x94 (148), 0x95 (149) |
| `dig_P5` | `truth registers[7]` | 0x96 (150), 0x97 (151) |
| `dig_P6` | `truth registers[8]` | 0x98 (152), 0x99 (153) |
| `dig_P7` | `truth registers[9]` | 0x9A (154), 0x9B (155) |
| `dig_P8` | `truth registers[10]` | 0x9C (156), 0x9D (157) |
| `dig_P9` | `truth registers[11]` | 0x9E (158), 0x9F (159) |
| `dig_H1` | `truth registers[12]` | 0xA1 (161) |
| `dig_H2` | `truth registers[13]` | 0xE1 (225), 0xE2 (226) |
| `dig_H3` | `truth registers[14]` | 0xE3 (227) |
| `dig_H4` | `truth registers[15]` | 0xE4 (228), 0xE5 (229) |
| `dig_H6` | `truth registers[16]` | 0xE7 (231) |
| `dig_H5` | `truth registers[26]` | 0xE5 (229), 0xE6 (230) |

\(\sum_{R=1}^{46}q_R=\mathbf{13.875294577}.\)

`n=46` unique truth physical locations, `m=14` matched extracted physical locations, `x=0` extra extracted physical locations.

\(\frac{m}{m+x}=\frac{14}{14+0}=1.000000.\)

\[S_{final}=\left(\frac{10}{46}\times 13.875294577\right)\times\frac{14}{14+0}=\boxed{\mathbf{3.016368386/10}}\]

## 4. Detailed errors, omissions, and exact locations

1. **Missing truth physical and logical coverage:** `without registers[0]` through `without registers[8]` cover 14 truth physical locations, while 32 truth locations are absent. The missing physical locations and all 18 missing calibration logical-register items (`dig_T1`–`dig_H6`) are listed with exact truth paths in the tables above. Each missing physical location receives `q_R=0`, and no extracted Q(L) exists for those missing truth logical-register items.
2. **Chip-ID values omitted:** `without registers[0].field_parts[0].bit_field[0].values` is empty, while truth requires value `0x60` (`truth registers[17].field_parts[0].bit_field[0].values`). Therefore `values C=0` for this bit field.
3. **Reset value cases incomplete:** `without registers[1].field_parts[0].bit_field[0].values` contains `0xB6` but omits truth's `other values than 0xB6 → No effect` case. The resulting `values C=0.5`. At `without registers[1].register_description`, the no-effect behavior is also omitted (`C=0.5`); at `without registers[1].default_value_description`, the concrete always-`0x00` readback is omitted (`C=0.5`).
4. **Status value cases omitted:** `without registers[3].field_parts[0].bit_field[1].values` for `measuring[0]` and `without registers[3].field_parts[0].bit_field[3].values` for `im_update[0]` are empty, while truth provides both 1/0 cases, so each `values` field receives `C=0`. The `im_update[0]` description at `without registers[3].field_parts[0].bit_field[3].field_description` describes copying and completion but omits the truth's power-on-reset/before-every-conversion timing, so `C=0.5`.
5. **Fixed-zero XLSB semantics:** `without registers[6].field_parts[2].bit_field[1]` and `without registers[7].field_parts[2].bit_field[1]` merge truth's four separate fixed-zero bits 3:0, which is an allowed grouping representation, but label the range `Reserved` and set `is_reserved=true`. Truth marks the bits as `name_or_parameter=0`, `is_reserved=false`, empty `type_write_read`, and description `Shown as 0 in the memory map`. Consequently name, field description, and reserved-status correctness are reduced; the exact bottom-up effects are shown in both XLSB calculations.
6. **No extra-location penalty:** every extracted physical address is a truth physical address; therefore `x=0`. The allowed merged 3:0 representation in the two XLSB field parts is not counted as an extra physical register or an invented physical location.

## 5. Quality and invented-field checks

- `name`, numeric physical address, bit start/end/width, logical/field widths, access types, and reserved classifications were checked as objective facts; the detailed tables show every C value.
- `101..111` is accepted as functionally equivalent to truth's `101, others` for the oversampling/filter fields, and `01..10` is accepted as the equivalent forced-mode representation.
- The extracted `spi3w_en` values include both 0 and 1; the added 0 is a valid disabled state and introduces no functional deviation, so it is credited.
- Correct additional wording in descriptions and default-value descriptions is not penalized. The reset and status omissions that change completeness are explicitly scored as partial or missing above.
- No extracted bit-field object remains unmatched by a truth target after the permitted fixed-zero merge handling.

## 6. Calculation summary

| without register | Associated locations | Q(L) |
|---|---|---:|
| without registers[0] `id` | 0xD0 (208) | 0.980401 |
| without registers[1] `reset` | 0xE0 (224) | 0.945305 |
| without registers[2] `ctrl_hum` | 0xF2 (242) | 1.000000 |
| without registers[3] `status` | 0xF3 (243) | 0.989516 |
| without registers[4] `ctrl_meas` | 0xF4 (244) | 1.000000 |
| without registers[5] `config` | 0xF5 (245) | 0.971803 |
| without registers[6] `press` | 0xF7 (247), 0xF8 (248), 0xF9 (249) | 0.998045 |
| without registers[7] `temp` | 0xFA (250), 0xFB (251), 0xFC (252) | 0.998045 |
| without registers[8] `hum` | 0xFD (253), 0xFE (254) | 1.000000 |

Final score: **3.016368386/10**.
