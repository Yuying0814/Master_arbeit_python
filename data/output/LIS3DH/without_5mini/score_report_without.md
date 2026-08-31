# LIS3DH without detailed score — updated truth type_write_read

## 1. Scoring basis

- Truth file: `LIS3DH/truth.json`; evaluated map: `LIS3DH/without/lis3dh.json`.
- `n` is the number of unique truth physical registers keyed by numeric address, bank and page.
- Each extracted logical register is calculated bottom-up from all truth bit-fields to field-part scores and then to `Q(L)`; missing truth bit-fields receive C=0 for every listed field.
- For each truth physical register, `q_R` is the mean of all associated extracted logical-register scores; missing physical registers receive q_R=0.
- The rounded AHP weights are normalized by 0.9999 for bit-fields and 1.0001 for logical registers; field-part weights sum to 1.

## Extracted logical register 1: `STATUS_REG_AUX`

without location: `registers[0]`; truth association: `registers[0]` (`STATUS_REG_AUX`)

Associated physical locations: 0x07 (7).

### Bottom layer: bit fields, then field parts

#### Field part 1: `STATUS_REG_AUX` at 0x07 (7)

Locations: `truth registers[0].field_parts[0]` ↔ `without registers[0].field_parts[0]`.


**Truth bit field 1: `321OR` bits 7:7**

Locations: `truth registers[0].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 321OR | MISSING |
| `field_description` | 0.0586 | 0.0 | 1, 2 and 3-axis data overrun. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `3OR` bits 6:6**

Locations: `truth registers[0].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 3OR | MISSING |
| `field_description` | 0.0586 | 0.0 | 3-axis data overrun. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 3-axis has overwritten the previous data."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `2OR` bits 5:5**

Locations: `truth registers[0].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 2OR | MISSING |
| `field_description` | 0.0586 | 0.0 | 2-axis data overrun. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 2-axis has overwritten the previous data."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `1OR` bits 4:4**

Locations: `truth registers[0].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 1OR | MISSING |
| `field_description` | 0.0586 | 0.0 | 1-axis data overrun. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 1-axis has overwritten the previous data."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `321DA` bits 3:3**

Locations: `truth registers[0].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 321DA | MISSING |
| `field_description` | 0.0586 | 0.0 | 1, 2 and 3-axis new data available. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `3DA` bits 2:2**

Locations: `truth registers[0].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 3DA | MISSING |
| `field_description` | 0.0586 | 0.0 | 3-axis new data available. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"New data for the 3-axis is not yet available."},{"value":"1","value_description":"New data for the 3-axis is available."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 7: `2DA` bits 1:1**

Locations: `truth registers[0].field_parts[0].bit_field[6]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 2DA | MISSING |
| `field_description` | 0.0586 | 0.0 | 2-axis new data available. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"New data for the 2-axis is not yet available."},{"value":"1","value_description":"New data for the 2-axis is available."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 8: `1DA` bits 0:0**

Locations: `truth registers[0].field_parts[0].bit_field[7]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 1DA | MISSING |
| `field_description` | 0.0586 | 0.0 | 1-axis new data available. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"New data for the 1-axis is not yet available."},{"value":"1","value_description":"New data for the 1-axis is available."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | STATUS_REG_AUX | STATUS_REG_AUX |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} | {"hex":"0x07","decimal":"7","bank":"","page":"","description":"Status register (aux)"} |
| `description` | 0.0693 | 1.000000 | "" | Auxiliary status flags (overrun/new data) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"321OR","field_description":"1, 2 and 3-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3OR","field_description":"3-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 3-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2OR","field_description":"2-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 2-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1OR","field_description":"1-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 1-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"321DA","field_description":"1, 2 and 3-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3DA","field_description":"3-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 3-axis is not yet available."},{"value":"1","value_description":"New data for the 3-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2DA","field_description":"2-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 2-axis is not yet available."},{"value":"1","value_description":"New data for the 2-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1DA","field_description":"1-axis new data available.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 1-axis is not yet available."},{"value":"1","value_description":"New data for the 1-axis is available."}],"is_reserved":false,"type_write_read":"R"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | STATUS_REG_AUX | STATUS_REG_AUX |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":"Auxiliary status register address"}] |
| `register_description` | 0.0564 | 1.000000 | Reports auxiliary ADC data-overrun and new-data availability status. | Auxiliary status flags for ADC channels: data overrun and new data available indicators for ADC1/2/3. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"STATUS_REG_AUX","physical_address":{"hex":"0x07","decimal":"7","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"321OR","field_description":"1, 2 and 3-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3OR","field_description":"3-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 3-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2OR","field_description":"2-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 2-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1OR","field_description":"1-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 1-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"321DA","field_description":"1, 2 and 3-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3DA","field_description":"3-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 3-axis is not yet available."},{"value":"1","value_description":"New data for the 3-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2DA","field_description":"2-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 2-axis is not yet available."},{"value":"1","value_description":"New data for the 2-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1DA","field_description":"1-axis new data available.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 1-axis is not yet available."},{"value":"1","value_description":"New data for the 1-axis is available."}],"is_reserved":false,"type_write_read":"R"}]} | [{"register_name":"STATUS_REG_AUX","physical_address":{"hex":"0x07","decimal":"7","bank":"","page":"","description":"Status register (aux)"},"description":"Auxiliary status flags (overrun/new data)","width_bits":8,"type_write_read":"R","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{1})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 2: `OUT_ADC1_L / OUT_ADC1_H`

without location: `registers[1]`; truth association: `registers[1]` (`OUT_ADC1_L (08h), OUT_ADC1_H (09h)`)

Associated physical locations: 0x08 (8), 0x09 (9).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC1_L` at 0x08 (8)

Locations: `truth registers[1].field_parts[0]` ↔ `without registers[1].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC1_L | OUT_ADC1_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"Low byte of auxiliary ADC channel 1 conversion."} | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"ADC1 low byte (LSB)"} |
| `description` | 0.0693 | 0.500000 | Low byte of auxiliary ADC channel 1 conversion. | Low byte of ADC1 conversion result |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×0.5 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{0.965350}\).

#### Field part 2: `OUT_ADC1_H` at 0x09 (9)

Locations: `truth registers[1].field_parts[1]` ↔ `without registers[1].field_parts[1]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC1_H | OUT_ADC1_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"High byte of auxiliary ADC channel 1 conversion."} | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"ADC1 high byte (MSB)"} |
| `description` | 0.0693 | 0.500000 | High byte of auxiliary ADC channel 1 conversion. | High byte of ADC1 conversion result |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×0.5 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{0.965350}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.965350, 0.965350) = **0.965350**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_ADC1_L (08h), OUT_ADC1_H (09h) | OUT_ADC1_L / OUT_ADC1_H |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":"Low byte of auxiliary ADC channel 1 conversion."},{"hex":"0x09","decimal":"9","bank":"","page":"","description":"High byte of auxiliary ADC channel 1 conversion."}] | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":"OUT_ADC1 low byte"},{"hex":"0x09","decimal":"9","bank":"","page":"","description":"OUT_ADC1 high byte"}] |
| `register_description` | 0.0564 | 1.000000 | Auxiliary 10-bit ADC channel 1 conversion, expressed in 2's complement left-aligned format. | Auxiliary ADC channel 1 conversion output (10-bit ADC data in two 8-bit registers, left-aligned). |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.965350 | [{"register_name":"OUT_ADC1_L","physical_address":{"hex":"0x08","decimal":"8","bank":"","page":"","description":"Low byte of auxiliary ADC channel 1 conversion."},"description":"Low byte of auxiliary ADC channel 1 conversion.","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_ADC1_H","physical_address":{"hex":"0x09","decimal":"9","bank":"","page":"","description":"High byte of auxiliary ADC channel 1 conversion."},"description":"High byte of auxiliary ADC channel 1 conversion.","width_bits":8,"type_write_read":"R","bit_field":[]}] | [{"register_name":"OUT_ADC1_L","physical_address":{"hex":"0x08","decimal":"8","bank":"","page":"","description":"ADC1 low byte (LSB)"},"description":"Low byte of ADC1 conversion result","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_ADC1_H","physical_address":{"hex":"0x09","decimal":"9","bank":"","page":"","description":"ADC1 high byte (MSB)"},"description":"High byte of ADC1 conversion result","width_bits":8,"type_write_read":"R","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{2})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.989750/1.0001=\mathbf{0.989651}\).

## Extracted logical register 3: `OUT_ADC2_L / OUT_ADC2_H`

without location: `registers[2]`; truth association: `registers[2]` (`OUT_ADC2_L (0Ah), OUT_ADC2_H (0Bh)`)

Associated physical locations: 0x0A (10), 0x0B (11).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC2_L` at 0x0A (10)

Locations: `truth registers[2].field_parts[0]` ↔ `without registers[2].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC2_L | OUT_ADC2_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Low byte of auxiliary ADC channel 2 conversion."} | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":"ADC2 low byte (LSB)"} |
| `description` | 0.0693 | 0.500000 | Low byte of auxiliary ADC channel 2 conversion. | Low byte of ADC2 conversion result |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×0.5 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{0.965350}\).

#### Field part 2: `OUT_ADC2_H` at 0x0B (11)

Locations: `truth registers[2].field_parts[1]` ↔ `without registers[2].field_parts[1]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC2_H | OUT_ADC2_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"High byte of auxiliary ADC channel 2 conversion."} | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"ADC2 high byte (MSB)"} |
| `description` | 0.0693 | 0.500000 | High byte of auxiliary ADC channel 2 conversion. | High byte of ADC2 conversion result |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×0.5 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{0.965350}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.965350, 0.965350) = **0.965350**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_ADC2_L (0Ah), OUT_ADC2_H (0Bh) | OUT_ADC2_L / OUT_ADC2_H |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Low byte of auxiliary ADC channel 2 conversion."},{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"High byte of auxiliary ADC channel 2 conversion."}] | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"OUT_ADC2 low byte"},{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"OUT_ADC2 high byte"}] |
| `register_description` | 0.0564 | 0.500000 | Auxiliary 10-bit ADC channel 2 conversion, expressed in 2's complement left-aligned format. | Auxiliary ADC channel 2 conversion output (two 8-bit registers, left-aligned). |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.965350 | [{"register_name":"OUT_ADC2_L","physical_address":{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Low byte of auxiliary ADC channel 2 conversion."},"description":"Low byte of auxiliary ADC channel 2 conversion.","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_ADC2_H","physical_address":{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"High byte of auxiliary ADC channel 2 conversion."},"description":"High byte of auxiliary ADC channel 2 conversion.","width_bits":8,"type_write_read":"R","bit_field":[]}] | [{"register_name":"OUT_ADC2_L","physical_address":{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"ADC2 low byte (LSB)"},"description":"Low byte of ADC2 conversion result","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_ADC2_H","physical_address":{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"ADC2 high byte (MSB)"},"description":"High byte of ADC2 conversion result","width_bits":8,"type_write_read":"R","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{3})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.961550/1.0001=\mathbf{0.961454}\).

## Extracted logical register 4: `OUT_ADC3_L / OUT_ADC3_H`

without location: `registers[3]`; truth association: `registers[3]` (`OUT_ADC3_L (0Ch), OUT_ADC3_H (0Dh)`)

Associated physical locations: 0x0C (12), 0x0D (13).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC3_L` at 0x0C (12)

Locations: `truth registers[3].field_parts[0]` ↔ `without registers[3].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC3_L | OUT_ADC3_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output."} | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"ADC3 low byte (LSB)"} |
| `description` | 0.0693 | 0.500000 | Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output. | Low byte of ADC3 conversion result or temperature LSB |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×0.5 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{0.965350}\).

#### Field part 2: `OUT_ADC3_H` at 0x0D (13)

Locations: `truth registers[3].field_parts[1]` ↔ `without registers[3].field_parts[1]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC3_H | OUT_ADC3_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"High byte of auxiliary ADC channel 3 conversion or temperature-sensor output."} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"ADC3 high byte (MSB)"} |
| `description` | 0.0693 | 0.500000 | High byte of auxiliary ADC channel 3 conversion or temperature-sensor output. | High byte of ADC3 conversion result or temperature MSB |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×0.5 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{0.965350}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.965350, 0.965350) = **0.965350**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_ADC3_L (0Ch), OUT_ADC3_H (0Dh) | OUT_ADC3_L / OUT_ADC3_H |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output."},{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"High byte of auxiliary ADC channel 3 conversion or temperature-sensor output."}] | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"OUT_ADC3 low byte"},{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"OUT_ADC3 high byte"}] |
| `register_description` | 0.0564 | 1.000000 | Auxiliary 10-bit ADC channel 3 conversion or temperature-sensor data output, expressed in 2's complement left-aligned format. | Auxiliary ADC channel 3 conversion output or temperature sensor output when enabled (two 8-bit registers, left-aligned). |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.965350 | [{"register_name":"OUT_ADC3_L","physical_address":{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output."},"description":"Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output.","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_ADC3_H","physical_address":{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"High byte of auxiliary ADC channel 3 conversion or temperature-sensor output."},"description":"High byte of auxiliary ADC channel 3 conversion or temperature-sensor output.","width_bits":8,"type_write_read":"R","bit_field":[]}] | [{"register_name":"OUT_ADC3_L","physical_address":{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"ADC3 low byte (LSB)"},"description":"Low byte of ADC3 conversion result or temperature LSB","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_ADC3_H","physical_address":{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"ADC3 high byte (MSB)"},"description":"High byte of ADC3 conversion result or temperature MSB","width_bits":8,"type_write_read":"R","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{4})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.989750/1.0001=\mathbf{0.989651}\).

## Extracted logical register 5: `WHO_AM_I`

without location: `registers[4]`; truth association: `registers[4]` (`WHO_AM_I`)

Associated physical locations: 0x0F (15).

### Bottom layer: bit fields, then field parts

#### Field part 1: `WHO_AM_I` at 0x0F (15)

Locations: `truth registers[4].field_parts[0]` ↔ `without registers[4].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":""} | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Device ID register"} |
| `description` | 0.0693 | 1.000000 | "" | Read-only device identification value |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":""} | [{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Device identification register"}] |
| `register_description` | 0.0564 | 1.000000 | Device identification register. | Device identification register (dummy register) returning fixed ID. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | {"register_name":"WHO_AM_I","physical_address":{"hex":"0x0F","decimal":"15","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[]} | [{"register_name":"WHO_AM_I","physical_address":{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Device ID register"},"description":"Read-only device identification value","width_bits":8,"type_write_read":"R","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00110011 | 00110011 |
| `default_value_description` | 0.0334 | 1.000000 | "" | Dummy register value (device ID) |

\(Q(L_{5})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 6: `CTRL_REG0`

without location: `registers[5]`; truth association: `registers[5]` (`CTRL_REG0`)

Associated physical locations: 0x1E (30).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG0` at 0x1E (30)

Locations: `truth registers[5].field_parts[0]` ↔ `without registers[5].field_parts[0]`.


**Truth bit field 1: `SDO_PU_DISC` bits 7:7**

Locations: `truth registers[5].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | SDO_PU_DISC | MISSING |
| `field_description` | 0.0586 | 0.0 | Disconnect SDO/SA0 pull-up. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":0,"value_description":"SDO/SA0 internal pull-up connected."},{"value":1,"value_description":"SDO/SA0 internal pull-up disconnected."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `bit6` bits 6:6**

Locations: `truth registers[5].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | bit6 | MISSING |
| `field_description` | 0.0586 | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | {"value":0,"value_description":""} | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `bit5` bits 5:5**

Locations: `truth registers[5].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | bit5 | MISSING |
| `field_description` | 0.0586 | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | {"value":0,"value_description":""} | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `bit4` bits 4:4**

Locations: `truth registers[5].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | bit4 | MISSING |
| `field_description` | 0.0586 | 0.0 | This bit must be set to 1 for correct operation of the device. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | {"value":1,"value_description":""} | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `bit3` bits 3:3**

Locations: `truth registers[5].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | bit3 | MISSING |
| `field_description` | 0.0586 | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | {"value":0,"value_description":""} | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `bit2` bits 2:2**

Locations: `truth registers[5].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | bit2 | MISSING |
| `field_description` | 0.0586 | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | {"value":0,"value_description":""} | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 7: `bit1` bits 1:1**

Locations: `truth registers[5].field_parts[0].bit_field[6]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | bit1 | MISSING |
| `field_description` | 0.0586 | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | {"value":0,"value_description":""} | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 8: `bit0` bits 0:0**

Locations: `truth registers[5].field_parts[0].bit_field[7]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | bit0 | MISSING |
| `field_description` | 0.0586 | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | {"value":0,"value_description":""} | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG0 | CTRL_REG0 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":""} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Control register 0"} |
| `description` | 0.0693 | 1.000000 | "" | Control of SDO/SA0 pull-up (SDO_PU_DISC) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"SDO_PU_DISC","field_description":"Disconnect SDO/SA0 pull-up.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":0,"value_description":"SDO/SA0 internal pull-up connected."},{"value":1,"value_description":"SDO/SA0 internal pull-up disconnected."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"bit6","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":6,"bit_end":6,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit5","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":5,"bit_end":5,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit4","field_description":"This bit must be set to 1 for correct operation of the device.","bit_start":4,"bit_end":4,"bit_width":1,"values":{"value":1,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit3","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":3,"bit_end":3,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit2","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":2,"bit_end":2,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit1","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":1,"bit_end":1,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit0","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":0,"bit_end":0,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG0 | CTRL_REG0 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":""} | [{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Control register 0"}] |
| `register_description` | 0.0564 | 0.500000 | Controls disconnection of the internal SDO/SA0 pull-up. | Control register 0: contains SDO/SA0 pull-up disconnect bit (SDO_PU_DISC) and related control; recommended to leave bits 0–6 at default for correct operation. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"CTRL_REG0","physical_address":{"hex":"0x1E","decimal":"30","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"SDO_PU_DISC","field_description":"Disconnect SDO/SA0 pull-up.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":0,"value_description":"SDO/SA0 internal pull-up connected."},{"value":1,"value_description":"SDO/SA0 internal pull-up disconnected."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"bit6","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":6,"bit_end":6,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit5","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":5,"bit_end":5,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit4","field_description":"This bit must be set to 1 for correct operation of the device.","bit_start":4,"bit_end":4,"bit_width":1,"values":{"value":1,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit3","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":3,"bit_end":3,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit2","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":2,"bit_end":2,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit1","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":1,"bit_end":1,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit0","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":0,"bit_end":0,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""}]} | [{"register_name":"CTRL_REG0","physical_address":{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Control register 0"},"description":"Control of SDO/SA0 pull-up (SDO_PU_DISC)","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00010000 | 00010000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{6})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 7: `TEMP_CFG_REG`

without location: `registers[6]`; truth association: `registers[6]` (`TEMP_CFG_REG`)

Associated physical locations: 0x1F (31).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TEMP_CFG_REG` at 0x1F (31)

Locations: `truth registers[6].field_parts[0]` ↔ `without registers[6].field_parts[0]`.


**Truth bit field 1: `ADC_EN` bits 7:7**

Locations: `truth registers[6].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ADC_EN | MISSING |
| `field_description` | 0.0586 | 0.0 | ADC enable. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"ADC disabled."},{"value":"1","value_description":"ADC enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `TEMP_EN` bits 6:6**

Locations: `truth registers[6].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | TEMP_EN | MISSING |
| `field_description` | 0.0586 | 0.0 | Temperature sensor enable. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Temperature sensor disabled."},{"value":"1","value_description":"Temperature sensor enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `0` bits 5:0**

Locations: `truth registers[6].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 0 | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 6 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TEMP_CFG_REG | TEMP_CFG_REG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":""} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Temperature and ADC config"} |
| `description` | 0.0693 | 1.000000 | "" | Enable/disable ADC and temperature sensor (ADC_EN, TEMP_EN) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"ADC_EN","field_description":"ADC enable.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"ADC disabled."},{"value":"1","value_description":"ADC enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TEMP_EN","field_description":"Temperature sensor enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Temperature sensor disabled."},{"value":"1","value_description":"Temperature sensor enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"0","field_description":"","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TEMP_CFG_REG | TEMP_CFG_REG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":""} | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Temperature / ADC configuration register"}] |
| `register_description` | 0.0564 | 1.000000 | Enables the auxiliary ADC and temperature sensor. | Temperature and auxiliary ADC configuration: ADC_EN and TEMP_EN bits enable ADC and temperature sensor/ADC3 channel. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"TEMP_CFG_REG","physical_address":{"hex":"0x1F","decimal":"31","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"ADC_EN","field_description":"ADC enable.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"ADC disabled."},{"value":"1","value_description":"ADC enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TEMP_EN","field_description":"Temperature sensor enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Temperature sensor disabled."},{"value":"1","value_description":"Temperature sensor enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"0","field_description":"","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""}]} | [{"register_name":"TEMP_CFG_REG","physical_address":{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Temperature and ADC config"},"description":"Enable/disable ADC and temperature sensor (ADC_EN, TEMP_EN)","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{7})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 8: `CTRL_REG1`

without location: `registers[7]`; truth association: `registers[7]` (`CTRL_REG1`)

Associated physical locations: 0x20 (32).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG1` at 0x20 (32)

Locations: `truth registers[7].field_parts[0]` ↔ `without registers[7].field_parts[0]`.


**Truth bit field 1: `ODR[3:0]` bits 7:4**

Locations: `truth registers[7].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ODR[3:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Data-rate and power-mode selection. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 4 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `LPen` bits 3:3**

Locations: `truth registers[7].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | LPen | MISSING |
| `field_description` | 0.0586 | 0.0 | Low-power mode enable. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"High-resolution mode / normal mode."},{"value":"1","value_description":"Low-power mode."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `Zen` bits 2:2**

Locations: `truth registers[7].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Zen | MISSING |
| `field_description` | 0.0586 | 0.0 | Z-axis enable. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Z-axis disabled."},{"value":"1","value_description":"Z-axis enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `Yen` bits 1:1**

Locations: `truth registers[7].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Yen | MISSING |
| `field_description` | 0.0586 | 0.0 | Y-axis enable. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Y-axis disabled."},{"value":"1","value_description":"Y-axis enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `Xen` bits 0:0**

Locations: `truth registers[7].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Xen | MISSING |
| `field_description` | 0.0586 | 0.0 | X-axis enable. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"X-axis disabled."},{"value":"1","value_description":"X-axis enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG1 | CTRL_REG1 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":""} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"ODR and axis enable register"} |
| `description` | 0.0693 | 1.000000 | "" | Sets ODR, low-power mode and axis enable/disable |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"ODR[3:0]","field_description":"Data-rate and power-mode selection.","bit_start":4,"bit_end":7,"bit_width":4,"values":[{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LPen","field_description":"Low-power mode enable.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution mode / normal mode."},{"value":"1","value_description":"Low-power mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Zen","field_description":"Z-axis enable.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Z-axis disabled."},{"value":"1","value_description":"Z-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Yen","field_description":"Y-axis enable.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Y-axis disabled."},{"value":"1","value_description":"Y-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Xen","field_description":"X-axis enable.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"X-axis disabled."},{"value":"1","value_description":"X-axis enabled."}],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG1 | CTRL_REG1 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":""} | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Control register 1"}] |
| `register_description` | 0.0564 | 0.500000 | Selects output data rate and power mode and enables the X, Y and Z axes. | Control register 1: data rate (ODR[3:0]), low-power enable (LPen), and axis enable bits (Xen, Yen, Zen) to set power mode, ODR and enabled axes. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"CTRL_REG1","physical_address":{"hex":"0x20","decimal":"32","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"ODR[3:0]","field_description":"Data-rate and power-mode selection.","bit_start":4,"bit_end":7,"bit_width":4,"values":[{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LPen","field_description":"Low-power mode enable.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution mode / normal mode."},{"value":"1","value_description":"Low-power mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Zen","field_description":"Z-axis enable.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Z-axis disabled."},{"value":"1","value_description":"Z-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Yen","field_description":"Y-axis enable.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Y-axis disabled."},{"value":"1","value_description":"Y-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Xen","field_description":"X-axis enable.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"X-axis disabled."},{"value":"1","value_description":"X-axis enabled."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CTRL_REG1","physical_address":{"hex":"0x20","decimal":"32","bank":"","page":"","description":"ODR and axis enable register"},"description":"Sets ODR, low-power mode and axis enable/disable","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000111 | 00000111 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{8})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 9: `CTRL_REG2`

without location: `registers[8]`; truth association: `registers[8]` (`CTRL_REG2`)

Associated physical locations: 0x21 (33).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG2` at 0x21 (33)

Locations: `truth registers[8].field_parts[0]` ↔ `without registers[8].field_parts[0]`.


**Truth bit field 1: `HPM[1:0]` bits 7:6**

Locations: `truth registers[8].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | HPM[1:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | High-pass filter mode selection. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 2 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"00","value_description":"Normal mode, reset by reading REFERENCE (26h)."},{"value":"01","value_description":"Reference signal for filtering."},{"value":"10","value_description":"Normal mode."},{"value":"11","value_description":"Autoreset on interrupt event."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `HPCF[2:1]` bits 5:4**

Locations: `truth registers[8].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | HPCF[2:1] | MISSING |
| `field_description` | 0.0586 | 0.0 | High-pass filter cutoff-frequency selection. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 2 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `FDS` bits 3:3**

Locations: `truth registers[8].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | FDS | MISSING |
| `field_description` | 0.0586 | 0.0 | Filtered data selection. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Internal filter bypassed."},{"value":"1","value_description":"Data from the internal filter sent to the output register and FIFO."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `HPCLICK` bits 2:2**

Locations: `truth registers[8].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | HPCLICK | MISSING |
| `field_description` | 0.0586 | 0.0 | High-pass filter enable for the CLICK function. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `HP_IA2` bits 1:1**

Locations: `truth registers[8].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | HP_IA2 | MISSING |
| `field_description` | 0.0586 | 0.0 | High-pass filter enable for the AOI function on interrupt 2. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `HP_IA1` bits 0:0**

Locations: `truth registers[8].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | HP_IA1 | MISSING |
| `field_description` | 0.0586 | 0.0 | High-pass filter enable for the AOI function on interrupt 1. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG2 | CTRL_REG2 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":""} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"High-pass filter and filter options"} |
| `description` | 0.0693 | 1.000000 | "" | High-pass filter mode/cutoff and filter routing configuration |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"HPM[1:0]","field_description":"High-pass filter mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode, reset by reading REFERENCE (26h)."},{"value":"01","value_description":"Reference signal for filtering."},{"value":"10","value_description":"Normal mode."},{"value":"11","value_description":"Autoreset on interrupt event."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCF[2:1]","field_description":"High-pass filter cutoff-frequency selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FDS","field_description":"Filtered data selection.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Internal filter bypassed."},{"value":"1","value_description":"Data from the internal filter sent to the output register and FIFO."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCLICK","field_description":"High-pass filter enable for the CLICK function.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA2","field_description":"High-pass filter enable for the AOI function on interrupt 2.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA1","field_description":"High-pass filter enable for the AOI function on interrupt 1.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG2 | CTRL_REG2 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":""} | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"Control register 2"}] |
| `register_description` | 0.0564 | 0.500000 | Configures the high-pass filter and its routing to output, FIFO, click and interrupt functions. | Control register 2: high-pass filter configuration, filtered data selection and related filter options. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"CTRL_REG2","physical_address":{"hex":"0x21","decimal":"33","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"HPM[1:0]","field_description":"High-pass filter mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode, reset by reading REFERENCE (26h)."},{"value":"01","value_description":"Reference signal for filtering."},{"value":"10","value_description":"Normal mode."},{"value":"11","value_description":"Autoreset on interrupt event."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCF[2:1]","field_description":"High-pass filter cutoff-frequency selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FDS","field_description":"Filtered data selection.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Internal filter bypassed."},{"value":"1","value_description":"Data from the internal filter sent to the output register and FIFO."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCLICK","field_description":"High-pass filter enable for the CLICK function.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA2","field_description":"High-pass filter enable for the AOI function on interrupt 2.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA1","field_description":"High-pass filter enable for the AOI function on interrupt 1.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CTRL_REG2","physical_address":{"hex":"0x21","decimal":"33","bank":"","page":"","description":"High-pass filter and filter options"},"description":"High-pass filter mode/cutoff and filter routing configuration","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{9})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 10: `CTRL_REG3`

without location: `registers[9]`; truth association: `registers[9]` (`CTRL_REG3`)

Associated physical locations: 0x22 (34).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG3` at 0x22 (34)

Locations: `truth registers[9].field_parts[0]` ↔ `without registers[9].field_parts[0]`.


**Truth bit field 1: `I1_CLICK` bits 7:7**

Locations: `truth registers[9].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I1_CLICK | MISSING |
| `field_description` | 0.0586 | 0.0 | Click interrupt on INT1. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `I1_IA1` bits 6:6**

Locations: `truth registers[9].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I1_IA1 | MISSING |
| `field_description` | 0.0586 | 0.0 | IA1 interrupt on INT1. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `I1_IA2` bits 5:5**

Locations: `truth registers[9].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I1_IA2 | MISSING |
| `field_description` | 0.0586 | 0.0 | IA2 interrupt on INT1. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `I1_ZYXDA` bits 4:4**

Locations: `truth registers[9].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I1_ZYXDA | MISSING |
| `field_description` | 0.0586 | 0.0 | ZYXDA interrupt on INT1. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `I1_321DA` bits 3:3**

Locations: `truth registers[9].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I1_321DA | MISSING |
| `field_description` | 0.0586 | 0.0 | 321DA interrupt on INT1. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `I1_WTM` bits 2:2**

Locations: `truth registers[9].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I1_WTM | MISSING |
| `field_description` | 0.0586 | 0.0 | FIFO watermark interrupt on INT1. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 7: `I1_OVERRUN` bits 1:1**

Locations: `truth registers[9].field_parts[0].bit_field[6]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I1_OVERRUN | MISSING |
| `field_description` | 0.0586 | 0.0 | FIFO overrun interrupt on INT1. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 8: `--` bits 0:0**

Locations: `truth registers[9].field_parts[0].bit_field[7]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | -- | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG3 | CTRL_REG3 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x22","decimal":"34","bank":"","page":"","description":""} | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"INT1 interrupt enables and routing"} |
| `description` | 0.0693 | 1.000000 | "" | INT1 pin interrupt enable bits and function selection |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"I1_CLICK","field_description":"Click interrupt on INT1.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA1","field_description":"IA1 interrupt on INT1.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA2","field_description":"IA2 interrupt on INT1.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_ZYXDA","field_description":"ZYXDA interrupt on INT1.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_321DA","field_description":"321DA interrupt on INT1.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_WTM","field_description":"FIFO watermark interrupt on INT1.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_OVERRUN","field_description":"FIFO overrun interrupt on INT1.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG3 | CTRL_REG3 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x22","decimal":"34","bank":"","page":"","description":""} | [{"hex":"0x22","decimal":"34","bank":"","page":"","description":"Control register 3 (INT1 routing)"}] |
| `register_description` | 0.0564 | 0.500000 | Routes click, inertial, data-ready, FIFO watermark and FIFO overrun interrupts to INT1. | Control register 3: interrupt configuration for INT1 (enable bits for click, IA1/IA2, ZYXDA, FIFO watermark, overrun, etc.). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"CTRL_REG3","physical_address":{"hex":"0x22","decimal":"34","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"I1_CLICK","field_description":"Click interrupt on INT1.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA1","field_description":"IA1 interrupt on INT1.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA2","field_description":"IA2 interrupt on INT1.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_ZYXDA","field_description":"ZYXDA interrupt on INT1.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_321DA","field_description":"321DA interrupt on INT1.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_WTM","field_description":"FIFO watermark interrupt on INT1.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_OVERRUN","field_description":"FIFO overrun interrupt on INT1.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}]} | [{"register_name":"CTRL_REG3","physical_address":{"hex":"0x22","decimal":"34","bank":"","page":"","description":"INT1 interrupt enables and routing"},"description":"INT1 pin interrupt enable bits and function selection","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{10})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 11: `CTRL_REG4`

without location: `registers[10]`; truth association: `registers[10]` (`CTRL_REG4`)

Associated physical locations: 0x23 (35).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG4` at 0x23 (35)

Locations: `truth registers[10].field_parts[0]` ↔ `without registers[10].field_parts[0]`.


**Truth bit field 1: `BDU` bits 7:7**

Locations: `truth registers[10].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | BDU | MISSING |
| `field_description` | 0.0586 | 0.0 | Block data update. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Continuous update."},{"value":"1","value_description":"Output registers are not updated until MSB and LSB have been read."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `BLE` bits 6:6**

Locations: `truth registers[10].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | BLE | MISSING |
| `field_description` | 0.0586 | 0.0 | Big/little endian data selection; available only in high-resolution mode. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Data LSB at lower address."},{"value":"1","value_description":"Data MSB at lower address."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `FS[1:0]` bits 5:4**

Locations: `truth registers[10].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | FS[1:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Full-scale selection. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 2 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"00","value_description":"±2 g."},{"value":"01","value_description":"±4 g."},{"value":"10","value_description":"±8 g."},{"value":"11","value_description":"±16 g."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `HR` bits 3:3**

Locations: `truth registers[10].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | HR | MISSING |
| `field_description` | 0.0586 | 0.0 | High-resolution output mode. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"High-resolution disabled."},{"value":"1","value_description":"High-resolution enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `ST[1:0]` bits 2:1**

Locations: `truth registers[10].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ST[1:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Self-test enable. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 2 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `SIM` bits 0:0**

Locations: `truth registers[10].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | SIM | MISSING |
| `field_description` | 0.0586 | 0.0 | SPI serial-interface mode selection. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG4 | CTRL_REG4 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x23","decimal":"35","bank":"","page":"","description":""} | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"Full-scale, resolution and interface modes"} |
| `description` | 0.0693 | 1.000000 | "" | Configure FS, HR, BDU, BLE, self-test and SPI 3/4-wire |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"BDU","field_description":"Block data update.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Continuous update."},{"value":"1","value_description":"Output registers are not updated until MSB and LSB have been read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BLE","field_description":"Big/little endian data selection; available only in high-resolution mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Data LSB at lower address."},{"value":"1","value_description":"Data MSB at lower address."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FS[1:0]","field_description":"Full-scale selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[{"value":"00","value_description":"±2 g."},{"value":"01","value_description":"±4 g."},{"value":"10","value_description":"±8 g."},{"value":"11","value_description":"±16 g."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HR","field_description":"High-resolution output mode.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution disabled."},{"value":"1","value_description":"High-resolution enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ST[1:0]","field_description":"Self-test enable.","bit_start":1,"bit_end":2,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SIM","field_description":"SPI serial-interface mode selection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG4 | CTRL_REG4 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x23","decimal":"35","bank":"","page":"","description":""} | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"Control register 4"}] |
| `register_description` | 0.0564 | 1.000000 | Configures block data update, byte order, full scale, high-resolution mode, self-test and SPI interface mode. | Control register 4: block data update (BDU), endianness (BLE), full-scale selection (FS[1:0]), high-resolution (HR), self-test (ST[1:0]), and SPI mode (SIM). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"CTRL_REG4","physical_address":{"hex":"0x23","decimal":"35","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"BDU","field_description":"Block data update.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Continuous update."},{"value":"1","value_description":"Output registers are not updated until MSB and LSB have been read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BLE","field_description":"Big/little endian data selection; available only in high-resolution mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Data LSB at lower address."},{"value":"1","value_description":"Data MSB at lower address."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FS[1:0]","field_description":"Full-scale selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[{"value":"00","value_description":"±2 g."},{"value":"01","value_description":"±4 g."},{"value":"10","value_description":"±8 g."},{"value":"11","value_description":"±16 g."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HR","field_description":"High-resolution output mode.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution disabled."},{"value":"1","value_description":"High-resolution enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ST[1:0]","field_description":"Self-test enable.","bit_start":1,"bit_end":2,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SIM","field_description":"SPI serial-interface mode selection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CTRL_REG4","physical_address":{"hex":"0x23","decimal":"35","bank":"","page":"","description":"Full-scale, resolution and interface modes"},"description":"Configure FS, HR, BDU, BLE, self-test and SPI 3/4-wire","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{11})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 12: `CTRL_REG5`

without location: `registers[11]`; truth association: `registers[11]` (`CTRL_REG5`)

Associated physical locations: 0x24 (36).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG5` at 0x24 (36)

Locations: `truth registers[11].field_parts[0]` ↔ `without registers[11].field_parts[0]`.


**Truth bit field 1: `BOOT` bits 7:7**

Locations: `truth registers[11].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | BOOT | MISSING |
| `field_description` | 0.0586 | 0.0 | Reboot memory content. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Normal mode."},{"value":"1","value_description":"Reboot memory content."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `FIFO_EN` bits 6:6**

Locations: `truth registers[11].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | FIFO_EN | MISSING |
| `field_description` | 0.0586 | 0.0 | FIFO enable. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"FIFO disabled."},{"value":"1","value_description":"FIFO enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `--` bits 5:4**

Locations: `truth registers[11].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | -- | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 2 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `LIR_INT1` bits 3:3**

Locations: `truth registers[11].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | LIR_INT1 | MISSING |
| `field_description` | 0.0586 | 0.0 | Latch interrupt request on INT1_SRC; reading INT1_SRC clears it. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `D4D_INT1` bits 2:2**

Locations: `truth registers[11].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | D4D_INT1 | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable 4D detection on INT1 when the INT1_CFG 6D bit is set. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `LIR_INT2` bits 1:1**

Locations: `truth registers[11].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | LIR_INT2 | MISSING |
| `field_description` | 0.0586 | 0.0 | Latch interrupt request on INT2_SRC; reading INT2_SRC clears it. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 7: `D4D_INT2` bits 0:0**

Locations: `truth registers[11].field_parts[0].bit_field[6]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | D4D_INT2 | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable 4D detection on INT2 when the INT2_CFG 6D bit is set. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG5 | CTRL_REG5 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x24","decimal":"36","bank":"","page":"","description":""} | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"FIFO, reboot and interrupt latch controls"} |
| `description` | 0.0693 | 1.000000 | "" | Controls FIFO enable, reboot, latch and 4D interrupt options |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"BOOT","field_description":"Reboot memory content.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Normal mode."},{"value":"1","value_description":"Reboot memory content."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FIFO_EN","field_description":"FIFO enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"FIFO disabled."},{"value":"1","value_description":"FIFO enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT1","field_description":"Latch interrupt request on INT1_SRC; reading INT1_SRC clears it.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT1","field_description":"Enable 4D detection on INT1 when the INT1_CFG 6D bit is set.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT2","field_description":"Latch interrupt request on INT2_SRC; reading INT2_SRC clears it.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT2","field_description":"Enable 4D detection on INT2 when the INT2_CFG 6D bit is set.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG5 | CTRL_REG5 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x24","decimal":"36","bank":"","page":"","description":""} | [{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Control register 5"}] |
| `register_description` | 0.0564 | 1.000000 | Controls memory reboot, FIFO enable, interrupt latching and 4D detection. | Control register 5: FIFO enable, reboot memory, interrupt latch options and 4D enable bits for INT1/INT2. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"CTRL_REG5","physical_address":{"hex":"0x24","decimal":"36","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"BOOT","field_description":"Reboot memory content.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Normal mode."},{"value":"1","value_description":"Reboot memory content."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FIFO_EN","field_description":"FIFO enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"FIFO disabled."},{"value":"1","value_description":"FIFO enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT1","field_description":"Latch interrupt request on INT1_SRC; reading INT1_SRC clears it.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT1","field_description":"Enable 4D detection on INT1 when the INT1_CFG 6D bit is set.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT2","field_description":"Latch interrupt request on INT2_SRC; reading INT2_SRC clears it.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT2","field_description":"Enable 4D detection on INT2 when the INT2_CFG 6D bit is set.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CTRL_REG5","physical_address":{"hex":"0x24","decimal":"36","bank":"","page":"","description":"FIFO, reboot and interrupt latch controls"},"description":"Controls FIFO enable, reboot, latch and 4D interrupt options","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{12})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 13: `CTRL_REG6`

without location: `registers[12]`; truth association: `registers[12]` (`CTRL_REG6`)

Associated physical locations: 0x25 (37).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG6` at 0x25 (37)

Locations: `truth registers[12].field_parts[0]` ↔ `without registers[12].field_parts[0]`.


**Truth bit field 1: `I2_CLICK` bits 7:7**

Locations: `truth registers[12].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I2_CLICK | MISSING |
| `field_description` | 0.0586 | 0.0 | Click interrupt on INT2 pin. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `I2_IA1` bits 6:6**

Locations: `truth registers[12].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I2_IA1 | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt 1 function on INT2 pin. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | I2_CLICK | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `I2_IA2` bits 5:5**

Locations: `truth registers[12].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I2_IA2 | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt 2 function on INT2 pin. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | I2_CLICK | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `I2_BOOT` bits 4:4**

Locations: `truth registers[12].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I2_BOOT | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable boot on INT2 pin. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | I2_CLICK | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `I2_ACT` bits 3:3**

Locations: `truth registers[12].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I2_ACT | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable activity interrupt on INT2 pin. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | I2_CLICK | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `--` bits 2:2**

Locations: `truth registers[12].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | -- | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | I2_CLICK | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 7: `INT_POLARITY` bits 1:1**

Locations: `truth registers[12].field_parts[0].bit_field[6]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | INT_POLARITY | MISSING |
| `field_description` | 0.0586 | 0.0 | INT1 and INT2 pin polarity. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Active-high."},{"value":"1","value_description":"Active-low."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | I2_CLICK | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 8: `-` bits 0:0**

Locations: `truth registers[12].field_parts[0].bit_field[7]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | - | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG6 | CTRL_REG6 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x25","decimal":"37","bank":"","page":"","description":""} | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"INT2 interrupt enables and polarity"} |
| `description` | 0.0693 | 1.000000 | "" | Configure INT2 functions and pin polarity |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"I2_CLICK","field_description":"Click interrupt on INT2 pin.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I2_IA1","field_description":"Enable interrupt 1 function on INT2 pin.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_IA2","field_description":"Enable interrupt 2 function on INT2 pin.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_BOOT","field_description":"Enable boot on INT2 pin.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_ACT","field_description":"Enable activity interrupt on INT2 pin.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"--","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"I2_CLICK"},{"name_or_parameter":"INT_POLARITY","field_description":"INT1 and INT2 pin polarity.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Active-high."},{"value":"1","value_description":"Active-low."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG6 | CTRL_REG6 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x25","decimal":"37","bank":"","page":"","description":""} | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":"Control register 6 (INT2 routing)"}] |
| `register_description` | 0.0564 | 1.000000 | Routes click, inertial, boot and activity signals to INT2 and sets interrupt-pin polarity. | Control register 6: interrupt enable bits routed to INT2 (click, IA1/IA2, boot, activity) and INT pin polarity configuration. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"CTRL_REG6","physical_address":{"hex":"0x25","decimal":"37","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"I2_CLICK","field_description":"Click interrupt on INT2 pin.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I2_IA1","field_description":"Enable interrupt 1 function on INT2 pin.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_IA2","field_description":"Enable interrupt 2 function on INT2 pin.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_BOOT","field_description":"Enable boot on INT2 pin.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_ACT","field_description":"Enable activity interrupt on INT2 pin.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"--","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"I2_CLICK"},{"name_or_parameter":"INT_POLARITY","field_description":"INT1 and INT2 pin polarity.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Active-high."},{"value":"1","value_description":"Active-low."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}]} | [{"register_name":"CTRL_REG6","physical_address":{"hex":"0x25","decimal":"37","bank":"","page":"","description":"INT2 interrupt enables and polarity"},"description":"Configure INT2 functions and pin polarity","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{13})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 14: `REFERENCE`

without location: `registers[13]`; truth association: `registers[13]` (`REFERENCE`)

Associated physical locations: 0x26 (38).

### Bottom layer: bit fields, then field parts

#### Field part 1: `REFERENCE` at 0x26 (38)

Locations: `truth registers[13].field_parts[0]` ↔ `without registers[13].field_parts[0]`.


**Truth bit field 1: `Ref[7:0]` bits 7:0**

Locations: `truth registers[13].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Ref[7:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Reference value for interrupt generation. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 8 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | Ref[7:0] | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | REFERENCE | REFERENCE |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x26","decimal":"38","bank":"","page":"","description":""} | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Reference value (8-bit)"} |
| `description` | 0.0693 | 1.000000 | "" | Reference value for interrupt generation |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | {"name_or_parameter":"Ref[7:0]","field_description":"Reference value for interrupt generation.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"Ref[7:0]"} | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | REFERENCE | REFERENCE |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x26","decimal":"38","bank":"","page":"","description":""} | [{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Reference register for interrupt generation"}] |
| `register_description` | 0.0564 | 0.500000 | Stores the reference value used for interrupt generation and reference-signal filtering. | Reference value used by the high-pass filter or interrupt generation (REFERENCE register). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"REFERENCE","physical_address":{"hex":"0x26","decimal":"38","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":{"name_or_parameter":"Ref[7:0]","field_description":"Reference value for interrupt generation.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"Ref[7:0]"}} | [{"register_name":"REFERENCE","physical_address":{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Reference value (8-bit)"},"description":"Reference value for interrupt generation","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | Reference value for interrupts (default all zeros) |

\(Q(L_{14})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 15: `STATUS_REG`

without location: `registers[14]`; truth association: `registers[14]` (`STATUS_REG`)

Associated physical locations: 0x27 (39).

### Bottom layer: bit fields, then field parts

#### Field part 1: `STATUS_REG` at 0x27 (39)

Locations: `truth registers[14].field_parts[0]` ↔ `without registers[14].field_parts[0]`.


**Truth bit field 1: `ZYXOR` bits 7:7**

Locations: `truth registers[14].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZYXOR | MISSING |
| `field_description` | 0.0586 | 0.0 | X, Y and Z-axis data overrun. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `ZOR` bits 6:6**

Locations: `truth registers[14].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZOR | MISSING |
| `field_description` | 0.0586 | 0.0 | Z-axis data overrun. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Z-axis data has overwritten the previous data."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `YOR` bits 5:5**

Locations: `truth registers[14].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YOR | MISSING |
| `field_description` | 0.0586 | 0.0 | Y-axis data overrun. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Y-axis data has overwritten the previous data."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `XOR` bits 4:4**

Locations: `truth registers[14].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | XOR | MISSING |
| `field_description` | 0.0586 | 0.0 | X-axis data overrun. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New X-axis data has overwritten the previous data."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `ZYXDA` bits 3:3**

Locations: `truth registers[14].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZYXDA | MISSING |
| `field_description` | 0.0586 | 0.0 | X, Y and Z-axis new data available. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `ZDA` bits 2:2**

Locations: `truth registers[14].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZDA | MISSING |
| `field_description` | 0.0586 | 0.0 | Z-axis new data available. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"New Z-axis data is not yet available."},{"value":"1","value_description":"New Z-axis data is available."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 7: `YDA` bits 1:1**

Locations: `truth registers[14].field_parts[0].bit_field[6]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YDA | MISSING |
| `field_description` | 0.0586 | 0.0 | Y-axis new data available. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"New Y-axis data is not yet available."},{"value":"1","value_description":"New Y-axis data is available."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 8: `XDA` bits 0:0**

Locations: `truth registers[14].field_parts[0].bit_field[7]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | XDA | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | STATUS_REG | STATUS_REG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x27","decimal":"39","bank":"","page":"","description":""} | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"Status register (main)"} |
| `description` | 0.0693 | 1.000000 | "" | Overrun and new-data flags for X/Y/Z axes |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"ZYXOR","field_description":"X, Y and Z-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZOR","field_description":"Z-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Z-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YOR","field_description":"Y-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Y-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XOR","field_description":"X-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New X-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZYXDA","field_description":"X, Y and Z-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZDA","field_description":"Z-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New Z-axis data is not yet available."},{"value":"1","value_description":"New Z-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YDA","field_description":"Y-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New Y-axis data is not yet available."},{"value":"1","value_description":"New Y-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XDA","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | STATUS_REG | STATUS_REG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x27","decimal":"39","bank":"","page":"","description":""} | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Main status register"}] |
| `register_description` | 0.0564 | 1.000000 | Reports acceleration-axis data-overrun and new-data availability status. | Main status register: data overrun and new data available flags for X/Y/Z axis output registers. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"STATUS_REG","physical_address":{"hex":"0x27","decimal":"39","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"ZYXOR","field_description":"X, Y and Z-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZOR","field_description":"Z-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Z-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YOR","field_description":"Y-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Y-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XOR","field_description":"X-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New X-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZYXDA","field_description":"X, Y and Z-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZDA","field_description":"Z-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New Z-axis data is not yet available."},{"value":"1","value_description":"New Z-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YDA","field_description":"Y-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New Y-axis data is not yet available."},{"value":"1","value_description":"New Y-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XDA","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}]} | [{"register_name":"STATUS_REG","physical_address":{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Status register (main)"},"description":"Overrun and new-data flags for X/Y/Z axes","width_bits":8,"type_write_read":"R","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{15})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 16: `OUT_X_L / OUT_X_H`

without location: `registers[15]`; truth association: `registers[15]` (`OUT_X_L (28h), OUT_X_H (29h)`)

Associated physical locations: 0x28 (40), 0x29 (41).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_X_L` at 0x28 (40)

Locations: `truth registers[15].field_parts[0]` ↔ `without registers[15].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_X_L | OUT_X_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of X-axis acceleration data."} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"X-axis low byte (LSB)"} |
| `description` | 0.0693 | 1.000000 | Low byte of X-axis acceleration data. | Low byte of X-axis acceleration output |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

#### Field part 2: `OUT_X_H` at 0x29 (41)

Locations: `truth registers[15].field_parts[1]` ↔ `without registers[15].field_parts[1]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_X_H | OUT_X_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"High byte of X-axis acceleration data."} | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"X-axis high byte (MSB)"} |
| `description` | 0.0693 | 1.000000 | High byte of X-axis acceleration data. | High byte of X-axis acceleration output |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 1.000000) = **1.000000**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_X_L (28h), OUT_X_H (29h) | OUT_X_L / OUT_X_H |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of X-axis acceleration data."},{"hex":"0x29","decimal":"41","bank":"","page":"","description":"High byte of X-axis acceleration data."}] | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"OUT_X low byte"},{"hex":"0x29","decimal":"41","bank":"","page":"","description":"OUT_X high byte"}] |
| `register_description` | 0.0564 | 0.500000 | X-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO X-axis data when FIFO is active. | X-axis acceleration output, two's complement left-justified across low and high bytes (OUT_X_L, OUT_X_H). |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | [{"register_name":"OUT_X_L","physical_address":{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of X-axis acceleration data."},"description":"Low byte of X-axis acceleration data.","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_X_H","physical_address":{"hex":"0x29","decimal":"41","bank":"","page":"","description":"High byte of X-axis acceleration data."},"description":"High byte of X-axis acceleration data.","width_bits":8,"type_write_read":"R","bit_field":[]}] | [{"register_name":"OUT_X_L","physical_address":{"hex":"0x28","decimal":"40","bank":"","page":"","description":"X-axis low byte (LSB)"},"description":"Low byte of X-axis acceleration output","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_X_H","physical_address":{"hex":"0x29","decimal":"41","bank":"","page":"","description":"X-axis high byte (MSB)"},"description":"High byte of X-axis acceleration output","width_bits":8,"type_write_read":"R","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{16})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 17: `OUT_Y_L / OUT_Y_H`

without location: `registers[16]`; truth association: `registers[16]` (`OUT_Y_L (2Ah), OUT_Y_H (2Bh)`)

Associated physical locations: 0x2A (42), 0x2B (43).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_Y_L` at 0x2A (42)

Locations: `truth registers[16].field_parts[0]` ↔ `without registers[16].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Y_L | OUT_Y_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Low byte of Y-axis acceleration data."} | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Y-axis low byte (LSB)"} |
| `description` | 0.0693 | 1.000000 | Low byte of Y-axis acceleration data. | Low byte of Y-axis acceleration output |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

#### Field part 2: `OUT_Y_H` at 0x2B (43)

Locations: `truth registers[16].field_parts[1]` ↔ `without registers[16].field_parts[1]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Y_H | OUT_Y_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"High byte of Y-axis acceleration data."} | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Y-axis high byte (MSB)"} |
| `description` | 0.0693 | 1.000000 | High byte of Y-axis acceleration data. | High byte of Y-axis acceleration output |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 1.000000) = **1.000000**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_Y_L (2Ah), OUT_Y_H (2Bh) | OUT_Y_L / OUT_Y_H |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Low byte of Y-axis acceleration data."},{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"High byte of Y-axis acceleration data."}] | [{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"OUT_Y low byte"},{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"OUT_Y high byte"}] |
| `register_description` | 0.0564 | 0.500000 | Y-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Y-axis data when FIFO is active. | Y-axis acceleration output, two's complement left-justified across low and high bytes (OUT_Y_L, OUT_Y_H). |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | [{"register_name":"OUT_Y_L","physical_address":{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Low byte of Y-axis acceleration data."},"description":"Low byte of Y-axis acceleration data.","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_Y_H","physical_address":{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"High byte of Y-axis acceleration data."},"description":"High byte of Y-axis acceleration data.","width_bits":8,"type_write_read":"R","bit_field":[]}] | [{"register_name":"OUT_Y_L","physical_address":{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Y-axis low byte (LSB)"},"description":"Low byte of Y-axis acceleration output","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_Y_H","physical_address":{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Y-axis high byte (MSB)"},"description":"High byte of Y-axis acceleration output","width_bits":8,"type_write_read":"R","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{17})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 18: `OUT_Z_L / OUT_Z_H`

without location: `registers[17]`; truth association: `registers[17]` (`OUT_Z_L (2Ch), OUT_Z_H (2Dh)`)

Associated physical locations: 0x2C (44), 0x2D (45).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_Z_L` at 0x2C (44)

Locations: `truth registers[17].field_parts[0]` ↔ `without registers[17].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Z_L | OUT_Z_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Low byte of Z-axis acceleration data."} | {"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Z-axis low byte (LSB)"} |
| `description` | 0.0693 | 1.000000 | Low byte of Z-axis acceleration data. | Low byte of Z-axis acceleration output |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

#### Field part 2: `OUT_Z_H` at 0x2D (45)

Locations: `truth registers[17].field_parts[1]` ↔ `without registers[17].field_parts[1]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Z_H | OUT_Z_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"High byte of Z-axis acceleration data."} | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Z-axis high byte (MSB)"} |
| `description` | 0.0693 | 1.000000 | High byte of Z-axis acceleration data. | High byte of Z-axis acceleration output |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 1.000000) = **1.000000**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_Z_L (2Ch), OUT_Z_H (2Dh) | OUT_Z_L / OUT_Z_H |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Low byte of Z-axis acceleration data."},{"hex":"0x2D","decimal":"45","bank":"","page":"","description":"High byte of Z-axis acceleration data."}] | [{"hex":"0x2C","decimal":"44","bank":"","page":"","description":"OUT_Z low byte"},{"hex":"0x2D","decimal":"45","bank":"","page":"","description":"OUT_Z high byte"}] |
| `register_description` | 0.0564 | 0.500000 | Z-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Z-axis data when FIFO is active. | Z-axis acceleration output, two's complement left-justified across low and high bytes (OUT_Z_L, OUT_Z_H). |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | [{"register_name":"OUT_Z_L","physical_address":{"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Low byte of Z-axis acceleration data."},"description":"Low byte of Z-axis acceleration data.","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_Z_H","physical_address":{"hex":"0x2D","decimal":"45","bank":"","page":"","description":"High byte of Z-axis acceleration data."},"description":"High byte of Z-axis acceleration data.","width_bits":8,"type_write_read":"R","bit_field":[]}] | [{"register_name":"OUT_Z_L","physical_address":{"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Z-axis low byte (LSB)"},"description":"Low byte of Z-axis acceleration output","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_Z_H","physical_address":{"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Z-axis high byte (MSB)"},"description":"High byte of Z-axis acceleration output","width_bits":8,"type_write_read":"R","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{18})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 19: `FIFO_CTRL_REG`

without location: `registers[18]`; truth association: `registers[18]` (`FIFO_CTRL_REG`)

Associated physical locations: 0x2E (46).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_CTRL_REG` at 0x2E (46)

Locations: `truth registers[18].field_parts[0]` ↔ `without registers[18].field_parts[0]`.


**Truth bit field 1: `FM[1:0]` bits 7:6**

Locations: `truth registers[18].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | FM[1:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | FIFO mode selection. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 2 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"00","value_description":"Bypass mode."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Stream-to-FIFO mode."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `TR` bits 5:5**

Locations: `truth registers[18].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | TR | MISSING |
| `field_description` | 0.0586 | 0.0 | Trigger selection for Stream-to-FIFO mode. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Triggering signal on INT1."},{"value":"1","value_description":"Triggering signal on INT2."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `FTH[4:0]` bits 4:0**

Locations: `truth registers[18].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | FTH[4:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Programmable FIFO watermark threshold. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 5 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | FIFO_CTRL_REG | FIFO_CTRL_REG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":""} | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":"FIFO mode and threshold control"} |
| `description` | 0.0693 | 1.000000 | "" | Select FIFO mode (Bypass/FIFO/Stream/Stream-to-FIFO), trigger pin and watermark threshold |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"FM[1:0]","field_description":"FIFO mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass mode."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Stream-to-FIFO mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TR","field_description":"Trigger selection for Stream-to-FIFO mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Triggering signal on INT1."},{"value":"1","value_description":"Triggering signal on INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FTH[4:0]","field_description":"Programmable FIFO watermark threshold.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | FIFO_CTRL_REG | FIFO_CTRL_REG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":""} | [{"hex":"0x2E","decimal":"46","bank":"","page":"","description":"FIFO control register"}] |
| `register_description` | 0.0564 | 1.000000 | Selects FIFO operating mode, Stream-to-FIFO trigger source and FIFO watermark threshold. | FIFO control register: select FIFO operating mode (FM[1:0]), trigger (TR) and watermark threshold (FTH[4:0]). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"FIFO_CTRL_REG","physical_address":{"hex":"0x2E","decimal":"46","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"FM[1:0]","field_description":"FIFO mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass mode."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Stream-to-FIFO mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TR","field_description":"Trigger selection for Stream-to-FIFO mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Triggering signal on INT1."},{"value":"1","value_description":"Triggering signal on INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FTH[4:0]","field_description":"Programmable FIFO watermark threshold.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"FIFO_CTRL_REG","physical_address":{"hex":"0x2E","decimal":"46","bank":"","page":"","description":"FIFO mode and threshold control"},"description":"Select FIFO mode (Bypass/FIFO/Stream/Stream-to-FIFO), trigger pin and watermark threshold","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{19})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 20: `FIFO_SRC_REG`

without location: `registers[19]`; truth association: `registers[19]` (`FIFO_SRC_REG`)

Associated physical locations: 0x2F (47).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_SRC_REG` at 0x2F (47)

Locations: `truth registers[19].field_parts[0]` ↔ `without registers[19].field_parts[0]`.


**Truth bit field 1: `WTM` bits 7:7**

Locations: `truth registers[19].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | WTM | MISSING |
| `field_description` | 0.0586 | 0.0 | Set high when FIFO content exceeds the watermark level. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `OVRN_FIFO` bits 6:6**

Locations: `truth registers[19].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | OVRN_FIFO | MISSING |
| `field_description` | 0.0586 | 0.0 | Set high when the FIFO is full with 32 unread samples; clears when the first sample set is read. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `EMPTY` bits 5:5**

Locations: `truth registers[19].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | EMPTY | MISSING |
| `field_description` | 0.0586 | 0.0 | Set high when all FIFO samples have been read and the FIFO is empty. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `FSS [4:0]` bits 4:0**

Locations: `truth registers[19].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | FSS [4:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Current number of unread sample sets stored in the FIFO. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 5 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | FIFO_SRC_REG | FIFO_SRC_REG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":""} | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":"FIFO status and sample count"} |
| `description` | 0.0693 | 1.000000 | "" | FIFO status flags and unread sample count |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"WTM","field_description":"Set high when FIFO content exceeds the watermark level.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"OVRN_FIFO","field_description":"Set high when the FIFO is full with 32 unread samples; clears when the first sample set is read.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"EMPTY","field_description":"Set high when all FIFO samples have been read and the FIFO is empty.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FSS [4:0]","field_description":"Current number of unread sample sets stored in the FIFO.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | FIFO_SRC_REG | FIFO_SRC_REG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":""} | [{"hex":"0x2F","decimal":"47","bank":"","page":"","description":"FIFO source register"}] |
| `register_description` | 0.0564 | 1.000000 | Reports FIFO watermark, overrun, empty status and the number of unread FIFO samples. | FIFO source register: contains FIFO status flags (WTM, OVRN_FIFO, EMPTY) and FSS[4:0] current number of unread samples. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"FIFO_SRC_REG","physical_address":{"hex":"0x2F","decimal":"47","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"WTM","field_description":"Set high when FIFO content exceeds the watermark level.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"OVRN_FIFO","field_description":"Set high when the FIFO is full with 32 unread samples; clears when the first sample set is read.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"EMPTY","field_description":"Set high when all FIFO samples have been read and the FIFO is empty.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FSS [4:0]","field_description":"Current number of unread sample sets stored in the FIFO.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R"}]} | [{"register_name":"FIFO_SRC_REG","physical_address":{"hex":"0x2F","decimal":"47","bank":"","page":"","description":"FIFO status and sample count"},"description":"FIFO status flags and unread sample count","width_bits":8,"type_write_read":"R","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{20})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 21: `INT1_CFG`

without location: `registers[20]`; truth association: `registers[20]` (`INT1_CFG`)

Associated physical locations: 0x30 (48).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT1_CFG` at 0x30 (48)

Locations: `truth registers[20].field_parts[0]` ↔ `without registers[20].field_parts[0]`.


**Truth bit field 1: `AOI-6D` bits 7:6**

Locations: `truth registers[20].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | AOI-6D | MISSING |
| `field_description` | 0.0586 | 0.0 | Interrupt event-combination and 6-direction recognition mode. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 2 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `ZHIE` bits 5:5**

Locations: `truth registers[20].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZHIE | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt generation on Z high event or direction recognition. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `ZLIE` bits 4:4**

Locations: `truth registers[20].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZLIE | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt generation on Z low event or direction recognition. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `YHIE` bits 3:3**

Locations: `truth registers[20].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YHIE | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt generation on Y high event or direction recognition. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `YLIE` bits 2:2**

Locations: `truth registers[20].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YLIE | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt generation on Y low event or direction recognition. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `XHIE` bits 1:1**

Locations: `truth registers[20].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | XHIE | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt generation on X high event or direction recognition. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 7: `XLIE` bits 0:0**

Locations: `truth registers[20].field_parts[0].bit_field[6]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | XLIE | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt generation on X low event or direction recognition. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT1_CFG | INT1_CFG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x30","decimal":"48","bank":"","page":"","description":""} | {"hex":"0x30","decimal":"48","bank":"","page":"","description":"INT1 event configuration"} |
| `description` | 0.0693 | 1.000000 | "" | Configure interrupt combination mode, 6D and axis event enables for INT1 |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event or direction recognition.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event or direction recognition.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event or direction recognition.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event or direction recognition.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event or direction recognition.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event or direction recognition.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT1_CFG | INT1_CFG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x30","decimal":"48","bank":"","page":"","description":""} | [{"hex":"0x30","decimal":"48","bank":"","page":"","description":"Interrupt 1 configuration register"}] |
| `register_description` | 0.0564 | 0.500000 | Configures interrupt 1 event combination, direction recognition and axis high/low event enables. Its content is loaded at boot, and writing is possible only after system boot. | Interrupt 1 configuration: AOI and 6D selection and axis high/low event enable bits for INT1 (X/Y/Z). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"INT1_CFG","physical_address":{"hex":"0x30","decimal":"48","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event or direction recognition.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event or direction recognition.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event or direction recognition.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event or direction recognition.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event or direction recognition.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event or direction recognition.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"INT1_CFG","physical_address":{"hex":"0x30","decimal":"48","bank":"","page":"","description":"INT1 event configuration"},"description":"Configure interrupt combination mode, 6D and axis event enables for INT1","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{21})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 22: `INT1_SRC`

without location: `registers[21]`; truth association: `registers[21]` (`INT1_SRC`)

Associated physical locations: 0x31 (49).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT1_SRC` at 0x31 (49)

Locations: `truth registers[21].field_parts[0]` ↔ `without registers[21].field_parts[0]`.


**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[21].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 0 | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `IA` bits 6:6**

Locations: `truth registers[21].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | IA | MISSING |
| `field_description` | 0.0586 | 0.0 | Interrupt active. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `ZH` bits 5:5**

Locations: `truth registers[21].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZH | MISSING |
| `field_description` | 0.0586 | 0.0 | Z high event status. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `ZL` bits 4:4**

Locations: `truth registers[21].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZL | MISSING |
| `field_description` | 0.0586 | 0.0 | Z low event status. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `YH` bits 3:3**

Locations: `truth registers[21].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YH | MISSING |
| `field_description` | 0.0586 | 0.0 | Y high event status. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `YL` bits 2:2**

Locations: `truth registers[21].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YL | MISSING |
| `field_description` | 0.0586 | 0.0 | Y low event status. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 7: `XH` bits 1:1**

Locations: `truth registers[21].field_parts[0].bit_field[6]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | XH | MISSING |
| `field_description` | 0.0586 | 0.0 | X high event status. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 8: `XL` bits 0:0**

Locations: `truth registers[21].field_parts[0].bit_field[7]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | XL | MISSING |
| `field_description` | 0.0586 | 0.0 | X low event status. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT1_SRC | INT1_SRC |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x31","decimal":"49","bank":"","page":"","description":""} | {"hex":"0x31","decimal":"49","bank":"","page":"","description":"INT1 source flags"} |
| `description` | 0.0693 | 1.000000 | "" | Indicates active INT1 sources; reading clears IA when latched |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT1_SRC | INT1_SRC |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x31","decimal":"49","bank":"","page":"","description":""} | [{"hex":"0x31","decimal":"49","bank":"","page":"","description":"Interrupt 1 source register (read-only)"}] |
| `register_description` | 0.0564 | 0.500000 | Reports interrupt 1 source and axis-event status. Reading clears the IA bit and INT1 signal and refreshes latched data. | Interrupt 1 source register (read-only): reports which INT1 event occurred (IA, ZH/ZL, YH/YL, XH/XL). Reading clears IA if latched option selected. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"INT1_SRC","physical_address":{"hex":"0x31","decimal":"49","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}]} | [{"register_name":"INT1_SRC","physical_address":{"hex":"0x31","decimal":"49","bank":"","page":"","description":"INT1 source flags"},"description":"Indicates active INT1 sources; reading clears IA when latched","width_bits":8,"type_write_read":"R","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{22})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 23: `INT1_THS`

without location: `registers[22]`; truth association: `registers[22]` (`INT1_THS`)

Associated physical locations: 0x32 (50).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT1_THS` at 0x32 (50)

Locations: `truth registers[22].field_parts[0]` ↔ `without registers[22].field_parts[0]`.


**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[22].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 0 | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `THS[6:0]` bits 6:0**

Locations: `truth registers[22].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | THS[6:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Interrupt 1 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 7 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT1_THS | INT1_THS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x32","decimal":"50","bank":"","page":"","description":""} | {"hex":"0x32","decimal":"50","bank":"","page":"","description":"INT1 threshold (7-bit)"} |
| `description` | 0.0693 | 1.000000 | "" | Threshold for INT1 event detection; LSb weight depends on FS |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 1 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT1_THS | INT1_THS |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x32","decimal":"50","bank":"","page":"","description":""} | [{"hex":"0x32","decimal":"50","bank":"","page":"","description":"Interrupt 1 threshold register"}] |
| `register_description` | 0.0564 | 0.500000 | Sets the interrupt 1 acceleration threshold. | Interrupt 1 threshold (THS[6:0]). LSB weight depends on selected full-scale (16 mg @ ±2g, 32 mg @ ±4g, 62 mg @ ±8g, 186 mg @ ±16g). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"INT1_THS","physical_address":{"hex":"0x32","decimal":"50","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 1 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"INT1_THS","physical_address":{"hex":"0x32","decimal":"50","bank":"","page":"","description":"INT1 threshold (7-bit)"},"description":"Threshold for INT1 event detection; LSb weight depends on FS","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{23})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 24: `INT1_DURATION`

without location: `registers[23]`; truth association: `registers[23]` (`INT1_DURATION`)

Associated physical locations: 0x33 (51).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT1_DURATION` at 0x33 (51)

Locations: `truth registers[23].field_parts[0]` ↔ `without registers[23].field_parts[0]`.


**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[23].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 0 | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `D[6:0]` bits 6:0**

Locations: `truth registers[23].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | D[6:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Duration value; 1 LSb equals 1/ODR. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 7 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT1_DURATION | INT1_DURATION |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x33","decimal":"51","bank":"","page":"","description":""} | {"hex":"0x33","decimal":"51","bank":"","page":"","description":"INT1 duration (7-bit)"} |
| `description` | 0.0693 | 1.000000 | "" | Duration threshold for INT1 (1 LSb = 1/ODR) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT1_DURATION | INT1_DURATION |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x33","decimal":"51","bank":"","page":"","description":""} | [{"hex":"0x33","decimal":"51","bank":"","page":"","description":"Interrupt 1 duration register"}] |
| `register_description` | 0.0564 | 1.000000 | Sets the minimum interrupt event duration; duration is measured as N/ODR. | Interrupt 1 duration (D[6:0]) measured in N/ODR where N is register content; sets minimum event duration to be recognized. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"INT1_DURATION","physical_address":{"hex":"0x33","decimal":"51","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"INT1_DURATION","physical_address":{"hex":"0x33","decimal":"51","bank":"","page":"","description":"INT1 duration (7-bit)"},"description":"Duration threshold for INT1 (1 LSb = 1/ODR)","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{24})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 25: `INT2_CFG`

without location: `registers[24]`; truth association: `registers[24]` (`INT2_CFG`)

Associated physical locations: 0x34 (52).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT2_CFG` at 0x34 (52)

Locations: `truth registers[24].field_parts[0]` ↔ `without registers[24].field_parts[0]`.


**Truth bit field 1: `AOI-6D` bits 7:6**

Locations: `truth registers[24].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | AOI-6D | MISSING |
| `field_description` | 0.0586 | 0.0 | Interrupt event-combination and 6-direction recognition mode. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 2 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `ZHIE` bits 5:5**

Locations: `truth registers[24].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZHIE | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt generation on Z high event. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `ZLIE` bits 4:4**

Locations: `truth registers[24].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZLIE | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt generation on Z low event. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `YHIE` bits 3:3**

Locations: `truth registers[24].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YHIE | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt generation on Y high event. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `YLIE` bits 2:2**

Locations: `truth registers[24].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YLIE | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt generation on Y low event. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `XHIE` bits 1:1**

Locations: `truth registers[24].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | XHIE | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt generation on X high event. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 7: `XLIE` bits 0:0**

Locations: `truth registers[24].field_parts[0].bit_field[6]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | XLIE | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable interrupt generation on X low event. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT2_CFG | INT2_CFG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x34","decimal":"52","bank":"","page":"","description":""} | {"hex":"0x34","decimal":"52","bank":"","page":"","description":"INT2 event configuration"} |
| `description` | 0.0693 | 1.000000 | "" | Configure interrupt combination mode, 6D and axis event enables for INT2 |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT2_CFG | INT2_CFG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x34","decimal":"52","bank":"","page":"","description":""} | [{"hex":"0x34","decimal":"52","bank":"","page":"","description":"Interrupt 2 configuration register"}] |
| `register_description` | 0.0564 | 0.500000 | Configures interrupt 2 event combination, direction recognition and axis high/low event enables. Its content is loaded at boot, and writing is possible only after system boot. | Interrupt 2 configuration: AOI and 6D selection and axis high/low event enable bits for INT2 (X/Y/Z). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"INT2_CFG","physical_address":{"hex":"0x34","decimal":"52","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"INT2_CFG","physical_address":{"hex":"0x34","decimal":"52","bank":"","page":"","description":"INT2 event configuration"},"description":"Configure interrupt combination mode, 6D and axis event enables for INT2","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{25})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 26: `INT2_SRC`

without location: `registers[25]`; truth association: `registers[25]` (`INT2_SRC`)

Associated physical locations: 0x35 (53).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT2_SRC` at 0x35 (53)

Locations: `truth registers[25].field_parts[0]` ↔ `without registers[25].field_parts[0]`.


**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[25].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 0 | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `IA` bits 6:6**

Locations: `truth registers[25].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | IA | MISSING |
| `field_description` | 0.0586 | 0.0 | Interrupt active. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `ZH` bits 5:5**

Locations: `truth registers[25].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZH | MISSING |
| `field_description` | 0.0586 | 0.0 | Z high event status. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `ZL` bits 4:4**

Locations: `truth registers[25].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZL | MISSING |
| `field_description` | 0.0586 | 0.0 | Z low event status. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `YH` bits 3:3**

Locations: `truth registers[25].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YH | MISSING |
| `field_description` | 0.0586 | 0.0 | Y high event status. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `YL` bits 2:2**

Locations: `truth registers[25].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YL | MISSING |
| `field_description` | 0.0586 | 0.0 | Y low event status. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 7: `XH` bits 1:1**

Locations: `truth registers[25].field_parts[0].bit_field[6]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | XH | MISSING |
| `field_description` | 0.0586 | 0.0 | X high event status. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 8: `XL` bits 0:0**

Locations: `truth registers[25].field_parts[0].bit_field[7]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | XL | MISSING |
| `field_description` | 0.0586 | 0.0 | X low event status. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT2_SRC | INT2_SRC |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x35","decimal":"53","bank":"","page":"","description":""} | {"hex":"0x35","decimal":"53","bank":"","page":"","description":"INT2 source flags"} |
| `description` | 0.0693 | 1.000000 | "" | Indicates active INT2 sources; reading clears IA when latched |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT2_SRC | INT2_SRC |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x35","decimal":"53","bank":"","page":"","description":""} | [{"hex":"0x35","decimal":"53","bank":"","page":"","description":"Interrupt 2 source register (read-only)"}] |
| `register_description` | 0.0564 | 0.500000 | Reports interrupt 2 source and axis-event status. Reading clears the IA bit and INT2 signal and refreshes latched data. | Interrupt 2 source register (read-only): reports which INT2 event occurred (IA, ZH/ZL, YH/YL, XH/XL). Reading clears IA if latched option selected. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"INT2_SRC","physical_address":{"hex":"0x35","decimal":"53","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}]} | [{"register_name":"INT2_SRC","physical_address":{"hex":"0x35","decimal":"53","bank":"","page":"","description":"INT2 source flags"},"description":"Indicates active INT2 sources; reading clears IA when latched","width_bits":8,"type_write_read":"R","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{26})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 27: `INT2_THS`

without location: `registers[26]`; truth association: `registers[26]` (`INT2_THS`)

Associated physical locations: 0x36 (54).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT2_THS` at 0x36 (54)

Locations: `truth registers[26].field_parts[0]` ↔ `without registers[26].field_parts[0]`.


**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[26].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 0 | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `THS[6:0]` bits 6:0**

Locations: `truth registers[26].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | THS[6:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Interrupt 2 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 7 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT2_THS | INT2_THS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x36","decimal":"54","bank":"","page":"","description":""} | {"hex":"0x36","decimal":"54","bank":"","page":"","description":"INT2 threshold (7-bit)"} |
| `description` | 0.0693 | 1.000000 | "" | Threshold for INT2 event detection; LSb weight depends on FS |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 2 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT2_THS | INT2_THS |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x36","decimal":"54","bank":"","page":"","description":""} | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":"Interrupt 2 threshold register"}] |
| `register_description` | 0.0564 | 0.500000 | Sets the interrupt 2 acceleration threshold. | Interrupt 2 threshold (THS[6:0]). LSB weight depends on selected full-scale (same scaling as INT1_THS). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"INT2_THS","physical_address":{"hex":"0x36","decimal":"54","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 2 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"INT2_THS","physical_address":{"hex":"0x36","decimal":"54","bank":"","page":"","description":"INT2 threshold (7-bit)"},"description":"Threshold for INT2 event detection; LSb weight depends on FS","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{27})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 28: `INT2_DURATION`

without location: `registers[27]`; truth association: `registers[27]` (`INT2_DURATION`)

Associated physical locations: 0x37 (55).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT2_DURATION` at 0x37 (55)

Locations: `truth registers[27].field_parts[0]` ↔ `without registers[27].field_parts[0]`.


**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[27].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 0 | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `D[6:0]` bits 6:0**

Locations: `truth registers[27].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | D[6:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Duration value; 1 LSb equals 1/ODR. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 7 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT2_DURATION | INT2_DURATION |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x37","decimal":"55","bank":"","page":"","description":""} | {"hex":"0x37","decimal":"55","bank":"","page":"","description":"INT2 duration (7-bit)"} |
| `description` | 0.0693 | 1.000000 | "" | Duration threshold for INT2 (1 LSb = 1/ODR) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT2_DURATION | INT2_DURATION |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x37","decimal":"55","bank":"","page":"","description":""} | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":"Interrupt 2 duration register"}] |
| `register_description` | 0.0564 | 1.000000 | Sets the minimum duration of an interrupt 2 event; duration is measured as N/ODR. | Interrupt 2 duration (D[6:0]) measured in N/ODR where N is register content; sets minimum event duration to be recognized for INT2. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"INT2_DURATION","physical_address":{"hex":"0x37","decimal":"55","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"INT2_DURATION","physical_address":{"hex":"0x37","decimal":"55","bank":"","page":"","description":"INT2 duration (7-bit)"},"description":"Duration threshold for INT2 (1 LSb = 1/ODR)","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{28})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 29: `CLICK_CFG`

without location: `registers[28]`; truth association: `registers[28]` (`CLICK_CFG`)

Associated physical locations: 0x38 (56).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CLICK_CFG` at 0x38 (56)

Locations: `truth registers[28].field_parts[0]` ↔ `without registers[28].field_parts[0]`.


**Truth bit field 1: `--` bits 7:6**

Locations: `truth registers[28].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | -- | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 2 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `ZD` bits 5:5**

Locations: `truth registers[28].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZD | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable double-click interrupt on Z-axis. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `ZS` bits 4:4**

Locations: `truth registers[28].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZS | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable single-click interrupt on Z-axis. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `YD` bits 3:3**

Locations: `truth registers[28].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YD | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable double-click interrupt on Y-axis. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `YS` bits 2:2**

Locations: `truth registers[28].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YS | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable single-click interrupt on Y-axis. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `XD` bits 1:1**

Locations: `truth registers[28].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | XD | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable double-click interrupt on X-axis. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 7: `XS` bits 0:0**

Locations: `truth registers[28].field_parts[0].bit_field[6]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | XS | MISSING |
| `field_description` | 0.0586 | 0.0 | Enable single-click interrupt on X-axis. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CLICK_CFG | CLICK_CFG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x38","decimal":"56","bank":"","page":"","description":""} | {"hex":"0x38","decimal":"56","bank":"","page":"","description":"Click detection enable bits"} |
| `description` | 0.0693 | 1.000000 | "" | Enable single/double click detection on X/Y/Z axes |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"--","field_description":"","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"ZD","field_description":"Enable double-click interrupt on Z-axis.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZS","field_description":"Enable single-click interrupt on Z-axis.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YD","field_description":"Enable double-click interrupt on Y-axis.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YS","field_description":"Enable single-click interrupt on Y-axis.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XD","field_description":"Enable double-click interrupt on X-axis.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XS","field_description":"Enable single-click interrupt on X-axis.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CLICK_CFG | CLICK_CFG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x38","decimal":"56","bank":"","page":"","description":""} | [{"hex":"0x38","decimal":"56","bank":"","page":"","description":"Click configuration register"}] |
| `register_description` | 0.0564 | 0.500000 | Enables single-click and double-click interrupt detection for the X, Y and Z axes. | Click configuration: enable single/double click detection per axis (XS/YS/ZS for single, XD/YD/ZD for double). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"CLICK_CFG","physical_address":{"hex":"0x38","decimal":"56","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"--","field_description":"","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"ZD","field_description":"Enable double-click interrupt on Z-axis.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZS","field_description":"Enable single-click interrupt on Z-axis.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YD","field_description":"Enable double-click interrupt on Y-axis.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YS","field_description":"Enable single-click interrupt on Y-axis.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XD","field_description":"Enable double-click interrupt on X-axis.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XS","field_description":"Enable single-click interrupt on X-axis.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CLICK_CFG","physical_address":{"hex":"0x38","decimal":"56","bank":"","page":"","description":"Click detection enable bits"},"description":"Enable single/double click detection on X/Y/Z axes","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{29})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 30: `CLICK_SRC`

without location: `registers[29]`; truth association: `registers[29]` (`CLICK_SRC`)

Associated physical locations: 0x39 (57).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CLICK_SRC` at 0x39 (57)

Locations: `truth registers[29].field_parts[0]` ↔ `without registers[29].field_parts[0]`.


**Truth bit field 1: `""` bits 7:7**

Locations: `truth registers[29].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `IA` bits 6:6**

Locations: `truth registers[29].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | IA | MISSING |
| `field_description` | 0.0586 | 0.0 | Interrupt active. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 3: `DCLICK` bits 5:5**

Locations: `truth registers[29].field_parts[0].bit_field[2]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | DCLICK | MISSING |
| `field_description` | 0.0586 | 0.0 | Double-click enable. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Double-click detection disabled."},{"value":"1","value_description":"Double-click detection enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 4: `SCLICK` bits 4:4**

Locations: `truth registers[29].field_parts[0].bit_field[3]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | SCLICK | MISSING |
| `field_description` | 0.0586 | 0.0 | Single-click enable. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Single-click detection disabled."},{"value":"1","value_description":"Single-click detection enabled."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 5: `Sign` bits 3:3**

Locations: `truth registers[29].field_parts[0].bit_field[4]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Sign | MISSING |
| `field_description` | 0.0586 | 0.0 | Click sign. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Positive detection."},{"value":"1","value_description":"Negative detection."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 6: `Z` bits 2:2**

Locations: `truth registers[29].field_parts[0].bit_field[5]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Z | MISSING |
| `field_description` | 0.0586 | 0.0 | Z click detection. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 7: `Y` bits 1:1**

Locations: `truth registers[29].field_parts[0].bit_field[6]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Y | MISSING |
| `field_description` | 0.0586 | 0.0 | Y click detection. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 8: `X` bits 0:0**

Locations: `truth registers[29].field_parts[0].bit_field[7]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | X | MISSING |
| `field_description` | 0.0586 | 0.0 | X click detection. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CLICK_SRC | CLICK_SRC |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x39","decimal":"57","bank":"","page":"","description":""} | {"hex":"0x39","decimal":"57","bank":"","page":"","description":"Click source flags"} |
| `description` | 0.0693 | 1.000000 | "" | Reports click event (single/double), sign and axis; IA indicates interrupt active |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"DCLICK","field_description":"Double-click enable.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Double-click detection disabled."},{"value":"1","value_description":"Double-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SCLICK","field_description":"Single-click enable.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Single-click detection disabled."},{"value":"1","value_description":"Single-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Sign","field_description":"Click sign.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Positive detection."},{"value":"1","value_description":"Negative detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Z","field_description":"Z click detection.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Y","field_description":"Y click detection.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"X","field_description":"X click detection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CLICK_SRC | CLICK_SRC |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x39","decimal":"57","bank":"","page":"","description":""} | [{"hex":"0x39","decimal":"57","bank":"","page":"","description":"Click source register (read-only)"}] |
| `register_description` | 0.0564 | 0.500000 | Reports click-interrupt activity, single/double-click detection, sign and detected axis. | Click source register (read-only): indicates click event status (single/double click, sign and axis). Reading clears status if latched option used. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"CLICK_SRC","physical_address":{"hex":"0x39","decimal":"57","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"DCLICK","field_description":"Double-click enable.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Double-click detection disabled."},{"value":"1","value_description":"Double-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SCLICK","field_description":"Single-click enable.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Single-click detection disabled."},{"value":"1","value_description":"Single-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Sign","field_description":"Click sign.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Positive detection."},{"value":"1","value_description":"Negative detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Z","field_description":"Z click detection.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Y","field_description":"Y click detection.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"X","field_description":"X click detection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CLICK_SRC","physical_address":{"hex":"0x39","decimal":"57","bank":"","page":"","description":"Click source flags"},"description":"Reports click event (single/double), sign and axis; IA indicates interrupt active","width_bits":8,"type_write_read":"R","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{30})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 31: `CLICK_THS`

without location: `registers[30]`; truth association: `registers[30]` (`CLICK_THS`)

Associated physical locations: 0x3A (58).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CLICK_THS` at 0x3A (58)

Locations: `truth registers[30].field_parts[0]` ↔ `without registers[30].field_parts[0]`.


**Truth bit field 1: `LIR_Click` bits 7:7**

Locations: `truth registers[30].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | LIR_Click | MISSING |
| `field_description` | 0.0586 | 0.0 | Controls click-interrupt latching. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `Ths[6:0]` bits 6:0**

Locations: `truth registers[30].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Ths[6:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Click threshold. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 7 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CLICK_THS | CLICK_THS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":""} | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":"Click threshold and latch control"} |
| `description` | 0.0693 | 1.000000 | "" | Click threshold and latch control (LIR_Click) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"LIR_Click","field_description":"Controls click-interrupt latching.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Ths[6:0]","field_description":"Click threshold.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CLICK_THS | CLICK_THS |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":""} | [{"hex":"0x3A","decimal":"58","bank":"","page":"","description":"Click threshold register"}] |
| `register_description` | 0.0564 | 1.000000 | Sets the click threshold and click-interrupt latch behavior. | Click threshold register (Ths[6:0]) and LIR_Click control: threshold for click detection and interrupt latching behavior. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"CLICK_THS","physical_address":{"hex":"0x3A","decimal":"58","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"LIR_Click","field_description":"Controls click-interrupt latching.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Ths[6:0]","field_description":"Click threshold.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CLICK_THS","physical_address":{"hex":"0x3A","decimal":"58","bank":"","page":"","description":"Click threshold and latch control"},"description":"Click threshold and latch control (LIR_Click)","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{31})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 32: `TIME_LIMIT`

without location: `registers[31]`; truth association: `registers[31]` (`TIME_LIMIT`)

Associated physical locations: 0x3B (59).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_LIMIT` at 0x3B (59)

Locations: `truth registers[31].field_parts[0]` ↔ `without registers[31].field_parts[0]`.


**Truth bit field 1: `-` bits 7:7**

Locations: `truth registers[31].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | - | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `TLI[6:0]` bits 6:0**

Locations: `truth registers[31].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | TLI[6:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Click time limit. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 7 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TIME_LIMIT | TIME_LIMIT |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":""} | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":"Click time limit (7-bit)"} |
| `description` | 0.0693 | 1.000000 | "" | Time limit for click detection |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"-","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"TLI[6:0]","field_description":"Click time limit.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TIME_LIMIT | TIME_LIMIT |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":""} | [{"hex":"0x3B","decimal":"59","bank":"","page":"","description":"Click time limit register"}] |
| `register_description` | 0.0564 | 1.000000 | Sets the click time limit. | Click time limit register: sets maximum time for click recognition (TLI[6:0]). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"TIME_LIMIT","physical_address":{"hex":"0x3B","decimal":"59","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"-","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"TLI[6:0]","field_description":"Click time limit.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"TIME_LIMIT","physical_address":{"hex":"0x3B","decimal":"59","bank":"","page":"","description":"Click time limit (7-bit)"},"description":"Time limit for click detection","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{32})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 33: `TIME_LATENCY`

without location: `registers[32]`; truth association: `registers[32]` (`TIME_LATENCY`)

Associated physical locations: 0x3C (60).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_LATENCY` at 0x3C (60)

Locations: `truth registers[32].field_parts[0]` ↔ `without registers[32].field_parts[0]`.


**Truth bit field 1: `TLA[7:0]` bits 7:0**

Locations: `truth registers[32].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | TLA[7:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Click time latency. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 8 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TIME_LATENCY | TIME_LATENCY |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":""} | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Click time latency (8-bit)"} |
| `description` | 0.0693 | 1.000000 | "" | Latency window for click detection |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | {"name_or_parameter":"TLA[7:0]","field_description":"Click time latency.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TIME_LATENCY | TIME_LATENCY |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":""} | [{"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Click time latency register"}] |
| `register_description` | 0.0564 | 1.000000 | Sets the click time latency. | Click time latency register (TLA[7:0]): latency between clicked events or between click recognition and next detection window. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"TIME_LATENCY","physical_address":{"hex":"0x3C","decimal":"60","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":{"name_or_parameter":"TLA[7:0]","field_description":"Click time latency.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}} | [{"register_name":"TIME_LATENCY","physical_address":{"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Click time latency (8-bit)"},"description":"Latency window for click detection","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{33})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 34: `TIME_WINDOW`

without location: `registers[33]`; truth association: `registers[33]` (`TIME_WINDOW`)

Associated physical locations: 0x3D (61).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_WINDOW` at 0x3D (61)

Locations: `truth registers[33].field_parts[0]` ↔ `without registers[33].field_parts[0]`.


**Truth bit field 1: `TW[7:0]` bits 7:0**

Locations: `truth registers[33].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | TW[7:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Click time window. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 8 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TIME_WINDOW | TIME_WINDOW |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":""} | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"Click time window (8-bit)"} |
| `description` | 0.0693 | 1.000000 | "" | Time window for click/double-click detection |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | {"name_or_parameter":"TW[7:0]","field_description":"Click time window.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TIME_WINDOW | TIME_WINDOW |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":""} | [{"hex":"0x3D","decimal":"61","bank":"","page":"","description":"Click time window register"}] |
| `register_description` | 0.0564 | 1.000000 | Sets the click time window. | Click time window register (TW[7:0]) used in click/double-click detection timing. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"TIME_WINDOW","physical_address":{"hex":"0x3D","decimal":"61","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":{"name_or_parameter":"TW[7:0]","field_description":"Click time window.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}} | [{"register_name":"TIME_WINDOW","physical_address":{"hex":"0x3D","decimal":"61","bank":"","page":"","description":"Click time window (8-bit)"},"description":"Time window for click/double-click detection","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 0.000000 | 00000000 | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{34})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×0.0 + 0.0334×1.0)/1.0001=0.839937/1.0001=\mathbf{0.839853}\).

## Extracted logical register 35: `ACT_THS`

without location: `registers[34]`; truth association: `registers[34]` (`ACT_THS`)

Associated physical locations: 0x3E (62).

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACT_THS` at 0x3E (62)

Locations: `truth registers[34].field_parts[0]` ↔ `without registers[34].field_parts[0]`.


**Truth bit field 1: `--` bits 7:7**

Locations: `truth registers[34].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | -- | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Truth bit field 2: `Acth[6:0]` bits 6:0**

Locations: `truth registers[34].field_parts[0].bit_field[1]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Acth[6:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Sleep-to-wake and return-to-sleep activation threshold in low-power mode. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 7 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACT_THS | ACT_THS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":""} | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Activity threshold (7-bit)"} |
| `description` | 0.0693 | 1.000000 | "" | Threshold for automatic sleep/wake detection; LSb weight depends on FS |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"--","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Acth[6:0]","field_description":"Sleep-to-wake and return-to-sleep activation threshold in low-power mode. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACT_THS | ACT_THS |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":""} | [{"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Sleep-to-wake activity threshold register"}] |
| `register_description` | 0.0564 | 0.500000 | Sets the sleep-to-wake and return-to-sleep activation threshold in low-power mode. | Activity threshold for sleep-to-wake/return-to-sleep function (Acth[6:0]). LSb weight depends on FS (16 mg @ ±2g etc.). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"ACT_THS","physical_address":{"hex":"0x3E","decimal":"62","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"--","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Acth[6:0]","field_description":"Sleep-to-wake and return-to-sleep activation threshold in low-power mode. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"ACT_THS","physical_address":{"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Activity threshold (7-bit)"},"description":"Threshold for automatic sleep/wake detection; LSb weight depends on FS","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{35})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.878437/1.0001=\mathbf{0.878349}\).

## Extracted logical register 36: `ACT_DUR`

without location: `registers[35]`; truth association: `registers[35]` (`ACT_DUR`)

Associated physical locations: 0x3F (63).

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACT_DUR` at 0x3F (63)

Locations: `truth registers[35].field_parts[0]` ↔ `without registers[35].field_parts[0]`.


**Truth bit field 1: `ActD[7:0]` bits 7:0**

Locations: `truth registers[35].field_parts[0].bit_field[0]` ↔ `missing`. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ActD[7:0] | MISSING |
| `field_description` | 0.0586 | 0.0 | Sleep-to-wake and return-to-sleep duration; 1 LSb = (8*1[LSb]+1)/ODR. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 8 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | false | MISSING |
| `type_write_read` | 0.0583 | 0.0 | RW | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | without content |
|---:|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACT_DUR | ACT_DUR |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3F","decimal":"63","bank":"","page":"","description":""} | {"hex":"0x3F","decimal":"63","bank":"","page":"","description":"Activity duration (8-bit)"} |
| `description` | 0.0693 | 1.000000 | "" | Duration parameter for activity detection (sleep/wake) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.000000 | {"name_or_parameter":"ActD[7:0]","field_description":"Sleep-to-wake and return-to-sleep duration; 1 LSb = (8*1[LSb]+1)/ODR.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACT_DUR | ACT_DUR |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3F","decimal":"63","bank":"","page":"","description":""} | [{"hex":"0x3F","decimal":"63","bank":"","page":"","description":"Sleep-to-wake activity duration register"}] |
| `register_description` | 0.0564 | 1.000000 | Sets the sleep-to-wake and return-to-sleep duration. | Activity duration (ActD[7:0]) for sleep-to-wake/return-to-sleep; 1 LSb defined as (8*1[LSb]+1)/ODR per datasheet note. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.687100 | {"register_name":"ACT_DUR","physical_address":{"hex":"0x3F","decimal":"63","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":{"name_or_parameter":"ActD[7:0]","field_description":"Sleep-to-wake and return-to-sleep duration; 1 LSb = (8*1[LSb]+1)/ODR.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}} | [{"register_name":"ACT_DUR","physical_address":{"hex":"0x3F","decimal":"63","bank":"","page":"","description":"Activity duration (8-bit)"},"description":"Duration parameter for activity detection (sleep/wake)","width_bits":8,"type_write_read":"RW","bit_field":[]}] |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{36})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).


## 2. Ground-truth physical-register scores

| Physical address | Associated extracted logical registers | q_R |
|---|---|---:|
| 0x07 (7) | without registers[0] `STATUS_REG_AUX`=0.906546 | 0.906546 |
| 0x08 (8) | without registers[1] `OUT_ADC1_L / OUT_ADC1_H`=0.989651 | 0.989651 |
| 0x09 (9) | without registers[1] `OUT_ADC1_L / OUT_ADC1_H`=0.989651 | 0.989651 |
| 0x0A (10) | without registers[2] `OUT_ADC2_L / OUT_ADC2_H`=0.961454 | 0.961454 |
| 0x0B (11) | without registers[2] `OUT_ADC2_L / OUT_ADC2_H`=0.961454 | 0.961454 |
| 0x0C (12) | without registers[3] `OUT_ADC3_L / OUT_ADC3_H`=0.989651 | 0.989651 |
| 0x0D (13) | without registers[3] `OUT_ADC3_L / OUT_ADC3_H`=0.989651 | 0.989651 |
| 0x0F (15) | without registers[4] `WHO_AM_I`=1.000000 | 1.000000 |
| 0x1E (30) | without registers[5] `CTRL_REG0`=0.878349 | 0.878349 |
| 0x1F (31) | without registers[6] `TEMP_CFG_REG`=0.906546 | 0.906546 |
| 0x20 (32) | without registers[7] `CTRL_REG1`=0.878349 | 0.878349 |
| 0x21 (33) | without registers[8] `CTRL_REG2`=0.878349 | 0.878349 |
| 0x22 (34) | without registers[9] `CTRL_REG3`=0.878349 | 0.878349 |
| 0x23 (35) | without registers[10] `CTRL_REG4`=0.906546 | 0.906546 |
| 0x24 (36) | without registers[11] `CTRL_REG5`=0.906546 | 0.906546 |
| 0x25 (37) | without registers[12] `CTRL_REG6`=0.906546 | 0.906546 |
| 0x26 (38) | without registers[13] `REFERENCE`=0.878349 | 0.878349 |
| 0x27 (39) | without registers[14] `STATUS_REG`=0.906546 | 0.906546 |
| 0x28 (40) | without registers[15] `OUT_X_L / OUT_X_H`=0.971803 | 0.971803 |
| 0x29 (41) | without registers[15] `OUT_X_L / OUT_X_H`=0.971803 | 0.971803 |
| 0x2A (42) | without registers[16] `OUT_Y_L / OUT_Y_H`=0.971803 | 0.971803 |
| 0x2B (43) | without registers[16] `OUT_Y_L / OUT_Y_H`=0.971803 | 0.971803 |
| 0x2C (44) | without registers[17] `OUT_Z_L / OUT_Z_H`=0.971803 | 0.971803 |
| 0x2D (45) | without registers[17] `OUT_Z_L / OUT_Z_H`=0.971803 | 0.971803 |
| 0x2E (46) | without registers[18] `FIFO_CTRL_REG`=0.906546 | 0.906546 |
| 0x2F (47) | without registers[19] `FIFO_SRC_REG`=0.906546 | 0.906546 |
| 0x30 (48) | without registers[20] `INT1_CFG`=0.878349 | 0.878349 |
| 0x31 (49) | without registers[21] `INT1_SRC`=0.878349 | 0.878349 |
| 0x32 (50) | without registers[22] `INT1_THS`=0.878349 | 0.878349 |
| 0x33 (51) | without registers[23] `INT1_DURATION`=0.906546 | 0.906546 |
| 0x34 (52) | without registers[24] `INT2_CFG`=0.878349 | 0.878349 |
| 0x35 (53) | without registers[25] `INT2_SRC`=0.878349 | 0.878349 |
| 0x36 (54) | without registers[26] `INT2_THS`=0.878349 | 0.878349 |
| 0x37 (55) | without registers[27] `INT2_DURATION`=0.906546 | 0.906546 |
| 0x38 (56) | without registers[28] `CLICK_CFG`=0.878349 | 0.878349 |
| 0x39 (57) | without registers[29] `CLICK_SRC`=0.878349 | 0.878349 |
| 0x3A (58) | without registers[30] `CLICK_THS`=0.906546 | 0.906546 |
| 0x3B (59) | without registers[31] `TIME_LIMIT`=0.906546 | 0.906546 |
| 0x3C (60) | without registers[32] `TIME_LATENCY`=0.906546 | 0.906546 |
| 0x3D (61) | without registers[33] `TIME_WINDOW`=0.839853 | 0.839853 |
| 0x3E (62) | without registers[34] `ACT_THS`=0.878349 | 0.878349 |
| 0x3F (63) | without registers[35] `ACT_DUR`=0.906546 | 0.906546 |

`Σq_R = 38.540712529`, `n=42`, `m=42`, `x=0`.

\(S_{raw}=(10/42)×38.540712529=\mathbf{9.176360126}.\)

\(S_{final}=S_{raw}×m/(m+x)= 9.176360126×42/(42+0)=\mathbf{9.176360126}/10.\)


## 3. Detailed deduction inventory

Matched truth physical locations: `42/42`; missing: `0`; extra extracted physical locations x=`0`.

| Location | Field | C | Truth content | without content | Exact deduction reason |
|---|---|---:|---|---|---|
| `truth registers[0].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | 321OR | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[0]` | `field_description` | 0.0 | 1, 2 and 3-axis data overrun. | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}] | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | 3OR | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[1]` | `field_description` | 0.0 | 3-axis data overrun. | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 3-axis has overwritten the previous data."}] | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | 2OR | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[2]` | `field_description` | 0.0 | 2-axis data overrun. | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 2-axis has overwritten the previous data."}] | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | 1OR | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[3]` | `field_description` | 0.0 | 1-axis data overrun. | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 1-axis has overwritten the previous data."}] | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | 321DA | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[4]` | `field_description` | 0.0 | 1, 2 and 3-axis new data available. | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}] | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | 3DA | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[5]` | `field_description` | 0.0 | 3-axis new data available. | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"New data for the 3-axis is not yet available."},{"value":"1","value_description":"New data for the 3-axis is available."}] | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.0 | 2DA | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[6]` | `field_description` | 0.0 | 2-axis new data available. | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[6]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[6]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[6]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"New data for the 2-axis is not yet available."},{"value":"1","value_description":"New data for the 2-axis is available."}] | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[6]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.0 | 1DA | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[7]` | `field_description` | 0.0 | 1-axis new data available. | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[7]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[7]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[7]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[7]` | `values` | 0.0 | [{"value":"0","value_description":"New data for the 1-axis is not yet available."},{"value":"1","value_description":"New data for the 1-axis is available."}] | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[7]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[0].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `without registers[0].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"321OR","field_description":"1, 2 and 3-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3OR","field_description":"3-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 3-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2OR","field_description":"2-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 2-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1OR","field_description":"1-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 1-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"321DA","field_description":"1, 2 and 3-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3DA","field_description":"3-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 3-axis is not yet available."},{"value":"1","value_description":"New data for the 3-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2DA","field_description":"2-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 2-axis is not yet available."},{"value":"1","value_description":"New data for the 2-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1DA","field_description":"1-axis new data available.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 1-axis is not yet available."},{"value":"1","value_description":"New data for the 1-axis is available."}],"is_reserved":false,"type_write_read":"R"}] | [] | field differs or is incomplete |
| `without registers[0]` | `field_parts` | 0.7 | {"register_name":"STATUS_REG_AUX","physical_address":{"hex":"0x07","decimal":"7","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"321OR","field_description":"1, 2 and 3-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3OR","field_description":"3-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 3-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2OR","field_description":"2-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 2-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1OR","field_description":"1-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 1-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"321DA","field_description":"1, 2 and 3-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3DA","field_description":"3-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 3-axis is not yet available."},{"value":"1","value_description":"New data for the 3-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2DA","field_description":"2-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 2-axis is not yet available."},{"value":"1","value_description":"New data for the 2-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1DA","field_description":"1-axis new data available.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 1-axis is not yet available."},{"value":"1","value_description":"New data for the 1-axis is available."}],"is_reserved":false,"type_write_read":"R"}]} | [{"register_name":"STATUS_REG_AUX","physical_address":{"hex":"0x07","decimal":"7","bank":"","page":"","description":"Status register (aux)"},"description":"Auxiliary status flags (overrun/new data)","width_bits":8,"type_write_read":"R","bit_field":[]}] | field differs or is incomplete |
| `without registers[1].field_parts[0]` | `description` | 0.5 | Low byte of auxiliary ADC channel 1 conversion. | Low byte of ADC1 conversion result | field differs or is incomplete |
| `without registers[1].field_parts[1]` | `description` | 0.5 | High byte of auxiliary ADC channel 1 conversion. | High byte of ADC1 conversion result | field differs or is incomplete |
| `without registers[1]` | `field_parts` | 1.0 | [{"register_name":"OUT_ADC1_L","physical_address":{"hex":"0x08","decimal":"8","bank":"","page":"","description":"Low byte of auxiliary ADC channel 1 conversion."},"description":"Low byte of auxiliary ADC channel 1 conversion.","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_ADC1_H","physical_address":{"hex":"0x09","decimal":"9","bank":"","page":"","description":"High byte of auxiliary ADC channel 1 conversion."},"description":"High byte of auxiliary ADC channel 1 conversion.","width_bits":8,"type_write_read":"R","bit_field":[]}] | [{"register_name":"OUT_ADC1_L","physical_address":{"hex":"0x08","decimal":"8","bank":"","page":"","description":"ADC1 low byte (LSB)"},"description":"Low byte of ADC1 conversion result","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_ADC1_H","physical_address":{"hex":"0x09","decimal":"9","bank":"","page":"","description":"ADC1 high byte (MSB)"},"description":"High byte of ADC1 conversion result","width_bits":8,"type_write_read":"R","bit_field":[]}] | field differs or is incomplete |
| `without registers[2].field_parts[0]` | `description` | 0.5 | Low byte of auxiliary ADC channel 2 conversion. | Low byte of ADC2 conversion result | field differs or is incomplete |
| `without registers[2].field_parts[1]` | `description` | 0.5 | High byte of auxiliary ADC channel 2 conversion. | High byte of ADC2 conversion result | field differs or is incomplete |
| `without registers[2]` | `register_description` | 0.5 | Auxiliary 10-bit ADC channel 2 conversion, expressed in 2's complement left-aligned format. | Auxiliary ADC channel 2 conversion output (two 8-bit registers, left-aligned). | field differs or is incomplete |
| `without registers[2]` | `field_parts` | 1.0 | [{"register_name":"OUT_ADC2_L","physical_address":{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Low byte of auxiliary ADC channel 2 conversion."},"description":"Low byte of auxiliary ADC channel 2 conversion.","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_ADC2_H","physical_address":{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"High byte of auxiliary ADC channel 2 conversion."},"description":"High byte of auxiliary ADC channel 2 conversion.","width_bits":8,"type_write_read":"R","bit_field":[]}] | [{"register_name":"OUT_ADC2_L","physical_address":{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"ADC2 low byte (LSB)"},"description":"Low byte of ADC2 conversion result","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_ADC2_H","physical_address":{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"ADC2 high byte (MSB)"},"description":"High byte of ADC2 conversion result","width_bits":8,"type_write_read":"R","bit_field":[]}] | field differs or is incomplete |
| `without registers[3].field_parts[0]` | `description` | 0.5 | Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output. | Low byte of ADC3 conversion result or temperature LSB | field differs or is incomplete |
| `without registers[3].field_parts[1]` | `description` | 0.5 | High byte of auxiliary ADC channel 3 conversion or temperature-sensor output. | High byte of ADC3 conversion result or temperature MSB | field differs or is incomplete |
| `without registers[3]` | `field_parts` | 1.0 | [{"register_name":"OUT_ADC3_L","physical_address":{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output."},"description":"Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output.","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_ADC3_H","physical_address":{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"High byte of auxiliary ADC channel 3 conversion or temperature-sensor output."},"description":"High byte of auxiliary ADC channel 3 conversion or temperature-sensor output.","width_bits":8,"type_write_read":"R","bit_field":[]}] | [{"register_name":"OUT_ADC3_L","physical_address":{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"ADC3 low byte (LSB)"},"description":"Low byte of ADC3 conversion result or temperature LSB","width_bits":8,"type_write_read":"R","bit_field":[]},{"register_name":"OUT_ADC3_H","physical_address":{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"ADC3 high byte (MSB)"},"description":"High byte of ADC3 conversion result or temperature MSB","width_bits":8,"type_write_read":"R","bit_field":[]}] | field differs or is incomplete |
| `truth registers[5].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | SDO_PU_DISC | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Disconnect SDO/SA0 pull-up. | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":0,"value_description":"SDO/SA0 internal pull-up connected."},{"value":1,"value_description":"SDO/SA0 internal pull-up disconnected."}] | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | bit6 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[1]` | `field_description` | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[1]` | `values` | 0.0 | {"value":0,"value_description":""} | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | bit5 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[2]` | `field_description` | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[2]` | `values` | 0.0 | {"value":0,"value_description":""} | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | bit4 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[3]` | `field_description` | 0.0 | This bit must be set to 1 for correct operation of the device. | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[3]` | `values` | 0.0 | {"value":1,"value_description":""} | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | bit3 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[4]` | `field_description` | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[4]` | `values` | 0.0 | {"value":0,"value_description":""} | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | bit2 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[5]` | `field_description` | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[5]` | `values` | 0.0 | {"value":0,"value_description":""} | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.0 | bit1 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[6]` | `field_description` | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[6]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[6]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[6]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[6]` | `values` | 0.0 | {"value":0,"value_description":""} | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[6]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.0 | bit0 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[7]` | `field_description` | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[7]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[7]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[7]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[7]` | `values` | 0.0 | {"value":0,"value_description":""} | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[7]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[5].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `without registers[5].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"SDO_PU_DISC","field_description":"Disconnect SDO/SA0 pull-up.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":0,"value_description":"SDO/SA0 internal pull-up connected."},{"value":1,"value_description":"SDO/SA0 internal pull-up disconnected."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"bit6","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":6,"bit_end":6,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit5","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":5,"bit_end":5,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit4","field_description":"This bit must be set to 1 for correct operation of the device.","bit_start":4,"bit_end":4,"bit_width":1,"values":{"value":1,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit3","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":3,"bit_end":3,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit2","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":2,"bit_end":2,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit1","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":1,"bit_end":1,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit0","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":0,"bit_end":0,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""}] | [] | field differs or is incomplete |
| `without registers[5]` | `register_description` | 0.5 | Controls disconnection of the internal SDO/SA0 pull-up. | Control register 0: contains SDO/SA0 pull-up disconnect bit (SDO_PU_DISC) and related control; recommended to leave bits 0–6 at default for correct operation. | field differs or is incomplete |
| `without registers[5]` | `field_parts` | 0.7 | {"register_name":"CTRL_REG0","physical_address":{"hex":"0x1E","decimal":"30","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"SDO_PU_DISC","field_description":"Disconnect SDO/SA0 pull-up.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":0,"value_description":"SDO/SA0 internal pull-up connected."},{"value":1,"value_description":"SDO/SA0 internal pull-up disconnected."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"bit6","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":6,"bit_end":6,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit5","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":5,"bit_end":5,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit4","field_description":"This bit must be set to 1 for correct operation of the device.","bit_start":4,"bit_end":4,"bit_width":1,"values":{"value":1,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit3","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":3,"bit_end":3,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit2","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":2,"bit_end":2,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit1","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":1,"bit_end":1,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit0","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":0,"bit_end":0,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""}]} | [{"register_name":"CTRL_REG0","physical_address":{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Control register 0"},"description":"Control of SDO/SA0 pull-up (SDO_PU_DISC)","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[6].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | ADC_EN | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[0]` | `field_description` | 0.0 | ADC enable. | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"ADC disabled."},{"value":"1","value_description":"ADC enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | TEMP_EN | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Temperature sensor enable. | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Temperature sensor disabled."},{"value":"1","value_description":"Temperature sensor enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `without registers[6].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"ADC_EN","field_description":"ADC enable.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"ADC disabled."},{"value":"1","value_description":"ADC enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TEMP_EN","field_description":"Temperature sensor enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Temperature sensor disabled."},{"value":"1","value_description":"Temperature sensor enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"0","field_description":"","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""}] | [] | field differs or is incomplete |
| `without registers[6]` | `field_parts` | 0.7 | {"register_name":"TEMP_CFG_REG","physical_address":{"hex":"0x1F","decimal":"31","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"ADC_EN","field_description":"ADC enable.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"ADC disabled."},{"value":"1","value_description":"ADC enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TEMP_EN","field_description":"Temperature sensor enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Temperature sensor disabled."},{"value":"1","value_description":"Temperature sensor enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"0","field_description":"","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""}]} | [{"register_name":"TEMP_CFG_REG","physical_address":{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Temperature and ADC config"},"description":"Enable/disable ADC and temperature sensor (ADC_EN, TEMP_EN)","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[7].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | ODR[3:0] | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Data-rate and power-mode selection. | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}] | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | LPen | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Low-power mode enable. | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"High-resolution mode / normal mode."},{"value":"1","value_description":"Low-power mode."}] | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | Zen | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[2]` | `field_description` | 0.0 | Z-axis enable. | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Z-axis disabled."},{"value":"1","value_description":"Z-axis enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | Yen | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[3]` | `field_description` | 0.0 | Y-axis enable. | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Y-axis disabled."},{"value":"1","value_description":"Y-axis enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | Xen | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[4]` | `field_description` | 0.0 | X-axis enable. | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"X-axis disabled."},{"value":"1","value_description":"X-axis enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[7].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[7].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"ODR[3:0]","field_description":"Data-rate and power-mode selection.","bit_start":4,"bit_end":7,"bit_width":4,"values":[{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LPen","field_description":"Low-power mode enable.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution mode / normal mode."},{"value":"1","value_description":"Low-power mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Zen","field_description":"Z-axis enable.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Z-axis disabled."},{"value":"1","value_description":"Z-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Yen","field_description":"Y-axis enable.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Y-axis disabled."},{"value":"1","value_description":"Y-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Xen","field_description":"X-axis enable.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"X-axis disabled."},{"value":"1","value_description":"X-axis enabled."}],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[7]` | `register_description` | 0.5 | Selects output data rate and power mode and enables the X, Y and Z axes. | Control register 1: data rate (ODR[3:0]), low-power enable (LPen), and axis enable bits (Xen, Yen, Zen) to set power mode, ODR and enabled axes. | field differs or is incomplete |
| `without registers[7]` | `field_parts` | 0.7 | {"register_name":"CTRL_REG1","physical_address":{"hex":"0x20","decimal":"32","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"ODR[3:0]","field_description":"Data-rate and power-mode selection.","bit_start":4,"bit_end":7,"bit_width":4,"values":[{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LPen","field_description":"Low-power mode enable.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution mode / normal mode."},{"value":"1","value_description":"Low-power mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Zen","field_description":"Z-axis enable.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Z-axis disabled."},{"value":"1","value_description":"Z-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Yen","field_description":"Y-axis enable.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Y-axis disabled."},{"value":"1","value_description":"Y-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Xen","field_description":"X-axis enable.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"X-axis disabled."},{"value":"1","value_description":"X-axis enabled."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CTRL_REG1","physical_address":{"hex":"0x20","decimal":"32","bank":"","page":"","description":"ODR and axis enable register"},"description":"Sets ODR, low-power mode and axis enable/disable","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[8].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | HPM[1:0] | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[0]` | `field_description` | 0.0 | High-pass filter mode selection. | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"00","value_description":"Normal mode, reset by reading REFERENCE (26h)."},{"value":"01","value_description":"Reference signal for filtering."},{"value":"10","value_description":"Normal mode."},{"value":"11","value_description":"Autoreset on interrupt event."}] | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | HPCF[2:1] | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[1]` | `field_description` | 0.0 | High-pass filter cutoff-frequency selection. | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[1]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | FDS | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[2]` | `field_description` | 0.0 | Filtered data selection. | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Internal filter bypassed."},{"value":"1","value_description":"Data from the internal filter sent to the output register and FIFO."}] | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | HPCLICK | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[3]` | `field_description` | 0.0 | High-pass filter enable for the CLICK function. | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | HP_IA2 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[4]` | `field_description` | 0.0 | High-pass filter enable for the AOI function on interrupt 2. | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | HP_IA1 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[5]` | `field_description` | 0.0 | High-pass filter enable for the AOI function on interrupt 1. | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[8].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[8].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"HPM[1:0]","field_description":"High-pass filter mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode, reset by reading REFERENCE (26h)."},{"value":"01","value_description":"Reference signal for filtering."},{"value":"10","value_description":"Normal mode."},{"value":"11","value_description":"Autoreset on interrupt event."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCF[2:1]","field_description":"High-pass filter cutoff-frequency selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FDS","field_description":"Filtered data selection.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Internal filter bypassed."},{"value":"1","value_description":"Data from the internal filter sent to the output register and FIFO."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCLICK","field_description":"High-pass filter enable for the CLICK function.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA2","field_description":"High-pass filter enable for the AOI function on interrupt 2.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA1","field_description":"High-pass filter enable for the AOI function on interrupt 1.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[8]` | `register_description` | 0.5 | Configures the high-pass filter and its routing to output, FIFO, click and interrupt functions. | Control register 2: high-pass filter configuration, filtered data selection and related filter options. | field differs or is incomplete |
| `without registers[8]` | `field_parts` | 0.7 | {"register_name":"CTRL_REG2","physical_address":{"hex":"0x21","decimal":"33","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"HPM[1:0]","field_description":"High-pass filter mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode, reset by reading REFERENCE (26h)."},{"value":"01","value_description":"Reference signal for filtering."},{"value":"10","value_description":"Normal mode."},{"value":"11","value_description":"Autoreset on interrupt event."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCF[2:1]","field_description":"High-pass filter cutoff-frequency selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FDS","field_description":"Filtered data selection.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Internal filter bypassed."},{"value":"1","value_description":"Data from the internal filter sent to the output register and FIFO."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCLICK","field_description":"High-pass filter enable for the CLICK function.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA2","field_description":"High-pass filter enable for the AOI function on interrupt 2.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA1","field_description":"High-pass filter enable for the AOI function on interrupt 1.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CTRL_REG2","physical_address":{"hex":"0x21","decimal":"33","bank":"","page":"","description":"High-pass filter and filter options"},"description":"High-pass filter mode/cutoff and filter routing configuration","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | I1_CLICK | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Click interrupt on INT1. | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | I1_IA1 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[1]` | `field_description` | 0.0 | IA1 interrupt on INT1. | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | I1_IA2 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[2]` | `field_description` | 0.0 | IA2 interrupt on INT1. | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | I1_ZYXDA | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[3]` | `field_description` | 0.0 | ZYXDA interrupt on INT1. | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | I1_321DA | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[4]` | `field_description` | 0.0 | 321DA interrupt on INT1. | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | I1_WTM | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[5]` | `field_description` | 0.0 | FIFO watermark interrupt on INT1. | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.0 | I1_OVERRUN | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[6]` | `field_description` | 0.0 | FIFO overrun interrupt on INT1. | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[6]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[6]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[6]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[6]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.0 | -- | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[7]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[7]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[7]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[7]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[7]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[7]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[9].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `without registers[9].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"I1_CLICK","field_description":"Click interrupt on INT1.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA1","field_description":"IA1 interrupt on INT1.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA2","field_description":"IA2 interrupt on INT1.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_ZYXDA","field_description":"ZYXDA interrupt on INT1.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_321DA","field_description":"321DA interrupt on INT1.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_WTM","field_description":"FIFO watermark interrupt on INT1.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_OVERRUN","field_description":"FIFO overrun interrupt on INT1.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [] | field differs or is incomplete |
| `without registers[9]` | `register_description` | 0.5 | Routes click, inertial, data-ready, FIFO watermark and FIFO overrun interrupts to INT1. | Control register 3: interrupt configuration for INT1 (enable bits for click, IA1/IA2, ZYXDA, FIFO watermark, overrun, etc.). | field differs or is incomplete |
| `without registers[9]` | `field_parts` | 0.7 | {"register_name":"CTRL_REG3","physical_address":{"hex":"0x22","decimal":"34","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"I1_CLICK","field_description":"Click interrupt on INT1.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA1","field_description":"IA1 interrupt on INT1.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA2","field_description":"IA2 interrupt on INT1.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_ZYXDA","field_description":"ZYXDA interrupt on INT1.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_321DA","field_description":"321DA interrupt on INT1.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_WTM","field_description":"FIFO watermark interrupt on INT1.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_OVERRUN","field_description":"FIFO overrun interrupt on INT1.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}]} | [{"register_name":"CTRL_REG3","physical_address":{"hex":"0x22","decimal":"34","bank":"","page":"","description":"INT1 interrupt enables and routing"},"description":"INT1 pin interrupt enable bits and function selection","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[10].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | BDU | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Block data update. | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"Continuous update."},{"value":"1","value_description":"Output registers are not updated until MSB and LSB have been read."}] | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | BLE | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Big/little endian data selection; available only in high-resolution mode. | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Data LSB at lower address."},{"value":"1","value_description":"Data MSB at lower address."}] | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | FS[1:0] | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[2]` | `field_description` | 0.0 | Full-scale selection. | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"00","value_description":"±2 g."},{"value":"01","value_description":"±4 g."},{"value":"10","value_description":"±8 g."},{"value":"11","value_description":"±16 g."}] | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | HR | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[3]` | `field_description` | 0.0 | High-resolution output mode. | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"High-resolution disabled."},{"value":"1","value_description":"High-resolution enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | ST[1:0] | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[4]` | `field_description` | 0.0 | Self-test enable. | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}] | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | SIM | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[5]` | `field_description` | 0.0 | SPI serial-interface mode selection. | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}] | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[10].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[10].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"BDU","field_description":"Block data update.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Continuous update."},{"value":"1","value_description":"Output registers are not updated until MSB and LSB have been read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BLE","field_description":"Big/little endian data selection; available only in high-resolution mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Data LSB at lower address."},{"value":"1","value_description":"Data MSB at lower address."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FS[1:0]","field_description":"Full-scale selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[{"value":"00","value_description":"±2 g."},{"value":"01","value_description":"±4 g."},{"value":"10","value_description":"±8 g."},{"value":"11","value_description":"±16 g."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HR","field_description":"High-resolution output mode.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution disabled."},{"value":"1","value_description":"High-resolution enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ST[1:0]","field_description":"Self-test enable.","bit_start":1,"bit_end":2,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SIM","field_description":"SPI serial-interface mode selection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[10]` | `field_parts` | 0.7 | {"register_name":"CTRL_REG4","physical_address":{"hex":"0x23","decimal":"35","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"BDU","field_description":"Block data update.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Continuous update."},{"value":"1","value_description":"Output registers are not updated until MSB and LSB have been read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BLE","field_description":"Big/little endian data selection; available only in high-resolution mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Data LSB at lower address."},{"value":"1","value_description":"Data MSB at lower address."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FS[1:0]","field_description":"Full-scale selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[{"value":"00","value_description":"±2 g."},{"value":"01","value_description":"±4 g."},{"value":"10","value_description":"±8 g."},{"value":"11","value_description":"±16 g."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HR","field_description":"High-resolution output mode.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution disabled."},{"value":"1","value_description":"High-resolution enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ST[1:0]","field_description":"Self-test enable.","bit_start":1,"bit_end":2,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SIM","field_description":"SPI serial-interface mode selection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CTRL_REG4","physical_address":{"hex":"0x23","decimal":"35","bank":"","page":"","description":"Full-scale, resolution and interface modes"},"description":"Configure FS, HR, BDU, BLE, self-test and SPI 3/4-wire","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[11].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | BOOT | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Reboot memory content. | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"Normal mode."},{"value":"1","value_description":"Reboot memory content."}] | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | FIFO_EN | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[1]` | `field_description` | 0.0 | FIFO enable. | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"FIFO disabled."},{"value":"1","value_description":"FIFO enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | -- | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[2]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[2]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | LIR_INT1 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[3]` | `field_description` | 0.0 | Latch interrupt request on INT1_SRC; reading INT1_SRC clears it. | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}] | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | D4D_INT1 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[4]` | `field_description` | 0.0 | Enable 4D detection on INT1 when the INT1_CFG 6D bit is set. | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[4]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | LIR_INT2 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[5]` | `field_description` | 0.0 | Latch interrupt request on INT2_SRC; reading INT2_SRC clears it. | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}] | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.0 | D4D_INT2 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[6]` | `field_description` | 0.0 | Enable 4D detection on INT2 when the INT2_CFG 6D bit is set. | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[6]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[6]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[6]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[6]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[6]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[11].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[11].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"BOOT","field_description":"Reboot memory content.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Normal mode."},{"value":"1","value_description":"Reboot memory content."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FIFO_EN","field_description":"FIFO enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"FIFO disabled."},{"value":"1","value_description":"FIFO enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT1","field_description":"Latch interrupt request on INT1_SRC; reading INT1_SRC clears it.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT1","field_description":"Enable 4D detection on INT1 when the INT1_CFG 6D bit is set.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT2","field_description":"Latch interrupt request on INT2_SRC; reading INT2_SRC clears it.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT2","field_description":"Enable 4D detection on INT2 when the INT2_CFG 6D bit is set.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[11]` | `field_parts` | 0.7 | {"register_name":"CTRL_REG5","physical_address":{"hex":"0x24","decimal":"36","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"BOOT","field_description":"Reboot memory content.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Normal mode."},{"value":"1","value_description":"Reboot memory content."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FIFO_EN","field_description":"FIFO enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"FIFO disabled."},{"value":"1","value_description":"FIFO enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT1","field_description":"Latch interrupt request on INT1_SRC; reading INT1_SRC clears it.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT1","field_description":"Enable 4D detection on INT1 when the INT1_CFG 6D bit is set.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT2","field_description":"Latch interrupt request on INT2_SRC; reading INT2_SRC clears it.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT2","field_description":"Enable 4D detection on INT2 when the INT2_CFG 6D bit is set.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CTRL_REG5","physical_address":{"hex":"0x24","decimal":"36","bank":"","page":"","description":"FIFO, reboot and interrupt latch controls"},"description":"Controls FIFO enable, reboot, latch and 4D interrupt options","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[12].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | I2_CLICK | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Click interrupt on INT2 pin. | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | I2_IA1 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Enable interrupt 1 function on INT2 pin. | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | I2_CLICK | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | I2_IA2 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[2]` | `field_description` | 0.0 | Enable interrupt 2 function on INT2 pin. | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | I2_CLICK | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | I2_BOOT | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[3]` | `field_description` | 0.0 | Enable boot on INT2 pin. | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | I2_CLICK | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | I2_ACT | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[4]` | `field_description` | 0.0 | Enable activity interrupt on INT2 pin. | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | I2_CLICK | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | -- | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[5]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[5]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | I2_CLICK | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.0 | INT_POLARITY | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[6]` | `field_description` | 0.0 | INT1 and INT2 pin polarity. | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[6]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[6]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[6]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"Active-high."},{"value":"1","value_description":"Active-low."}] | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[6]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | I2_CLICK | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.0 | - | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[7]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[7]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[7]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[7]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[7]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[7]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[12].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `without registers[12].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"I2_CLICK","field_description":"Click interrupt on INT2 pin.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I2_IA1","field_description":"Enable interrupt 1 function on INT2 pin.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_IA2","field_description":"Enable interrupt 2 function on INT2 pin.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_BOOT","field_description":"Enable boot on INT2 pin.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_ACT","field_description":"Enable activity interrupt on INT2 pin.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"--","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"I2_CLICK"},{"name_or_parameter":"INT_POLARITY","field_description":"INT1 and INT2 pin polarity.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Active-high."},{"value":"1","value_description":"Active-low."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [] | field differs or is incomplete |
| `without registers[12]` | `field_parts` | 0.7 | {"register_name":"CTRL_REG6","physical_address":{"hex":"0x25","decimal":"37","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"I2_CLICK","field_description":"Click interrupt on INT2 pin.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I2_IA1","field_description":"Enable interrupt 1 function on INT2 pin.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_IA2","field_description":"Enable interrupt 2 function on INT2 pin.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_BOOT","field_description":"Enable boot on INT2 pin.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_ACT","field_description":"Enable activity interrupt on INT2 pin.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"--","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"I2_CLICK"},{"name_or_parameter":"INT_POLARITY","field_description":"INT1 and INT2 pin polarity.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Active-high."},{"value":"1","value_description":"Active-low."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}]} | [{"register_name":"CTRL_REG6","physical_address":{"hex":"0x25","decimal":"37","bank":"","page":"","description":"INT2 interrupt enables and polarity"},"description":"Configure INT2 functions and pin polarity","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[13].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | Ref[7:0] | MISSING | truth bit field missing from extraction |
| `truth registers[13].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Reference value for interrupt generation. | MISSING | truth bit field missing from extraction |
| `truth registers[13].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[13].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[13].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 8 | MISSING | truth bit field missing from extraction |
| `truth registers[13].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[13].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[13].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | Ref[7:0] | MISSING | truth bit field missing from extraction |
| `without registers[13].field_parts[0]` | `bit_field` | 0.0 | {"name_or_parameter":"Ref[7:0]","field_description":"Reference value for interrupt generation.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"Ref[7:0]"} | [] | field differs or is incomplete |
| `without registers[13]` | `register_description` | 0.5 | Stores the reference value used for interrupt generation and reference-signal filtering. | Reference value used by the high-pass filter or interrupt generation (REFERENCE register). | field differs or is incomplete |
| `without registers[13]` | `field_parts` | 0.7 | {"register_name":"REFERENCE","physical_address":{"hex":"0x26","decimal":"38","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":{"name_or_parameter":"Ref[7:0]","field_description":"Reference value for interrupt generation.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"Ref[7:0]"}} | [{"register_name":"REFERENCE","physical_address":{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Reference value (8-bit)"},"description":"Reference value for interrupt generation","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[14].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | ZYXOR | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[0]` | `field_description` | 0.0 | X, Y and Z-axis data overrun. | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}] | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | ZOR | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Z-axis data overrun. | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Z-axis data has overwritten the previous data."}] | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | YOR | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[2]` | `field_description` | 0.0 | Y-axis data overrun. | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Y-axis data has overwritten the previous data."}] | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | XOR | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[3]` | `field_description` | 0.0 | X-axis data overrun. | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New X-axis data has overwritten the previous data."}] | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | ZYXDA | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[4]` | `field_description` | 0.0 | X, Y and Z-axis new data available. | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}] | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | ZDA | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[5]` | `field_description` | 0.0 | Z-axis new data available. | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"New Z-axis data is not yet available."},{"value":"1","value_description":"New Z-axis data is available."}] | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.0 | YDA | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[6]` | `field_description` | 0.0 | Y-axis new data available. | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[6]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[6]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[6]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"New Y-axis data is not yet available."},{"value":"1","value_description":"New Y-axis data is available."}] | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[6]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.0 | XDA | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[7]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[7]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[7]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[7]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[7]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[7]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[14].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `without registers[14].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"ZYXOR","field_description":"X, Y and Z-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZOR","field_description":"Z-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Z-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YOR","field_description":"Y-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Y-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XOR","field_description":"X-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New X-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZYXDA","field_description":"X, Y and Z-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZDA","field_description":"Z-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New Z-axis data is not yet available."},{"value":"1","value_description":"New Z-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YDA","field_description":"Y-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New Y-axis data is not yet available."},{"value":"1","value_description":"New Y-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XDA","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] | [] | field differs or is incomplete |
| `without registers[14]` | `field_parts` | 0.7 | {"register_name":"STATUS_REG","physical_address":{"hex":"0x27","decimal":"39","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"ZYXOR","field_description":"X, Y and Z-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZOR","field_description":"Z-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Z-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YOR","field_description":"Y-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Y-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XOR","field_description":"X-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New X-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZYXDA","field_description":"X, Y and Z-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZDA","field_description":"Z-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New Z-axis data is not yet available."},{"value":"1","value_description":"New Z-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YDA","field_description":"Y-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New Y-axis data is not yet available."},{"value":"1","value_description":"New Y-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XDA","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}]} | [{"register_name":"STATUS_REG","physical_address":{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Status register (main)"},"description":"Overrun and new-data flags for X/Y/Z axes","width_bits":8,"type_write_read":"R","bit_field":[]}] | field differs or is incomplete |
| `without registers[15]` | `register_description` | 0.5 | X-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO X-axis data when FIFO is active. | X-axis acceleration output, two's complement left-justified across low and high bytes (OUT_X_L, OUT_X_H). | field differs or is incomplete |
| `without registers[16]` | `register_description` | 0.5 | Y-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Y-axis data when FIFO is active. | Y-axis acceleration output, two's complement left-justified across low and high bytes (OUT_Y_L, OUT_Y_H). | field differs or is incomplete |
| `without registers[17]` | `register_description` | 0.5 | Z-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Z-axis data when FIFO is active. | Z-axis acceleration output, two's complement left-justified across low and high bytes (OUT_Z_L, OUT_Z_H). | field differs or is incomplete |
| `truth registers[18].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | FM[1:0] | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[0]` | `field_description` | 0.0 | FIFO mode selection. | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"00","value_description":"Bypass mode."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Stream-to-FIFO mode."}] | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | TR | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Trigger selection for Stream-to-FIFO mode. | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Triggering signal on INT1."},{"value":"1","value_description":"Triggering signal on INT2."}] | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | FTH[4:0] | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[2]` | `field_description` | 0.0 | Programmable FIFO watermark threshold. | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[2]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[18].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[18].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"FM[1:0]","field_description":"FIFO mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass mode."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Stream-to-FIFO mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TR","field_description":"Trigger selection for Stream-to-FIFO mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Triggering signal on INT1."},{"value":"1","value_description":"Triggering signal on INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FTH[4:0]","field_description":"Programmable FIFO watermark threshold.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[18]` | `field_parts` | 0.7 | {"register_name":"FIFO_CTRL_REG","physical_address":{"hex":"0x2E","decimal":"46","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"FM[1:0]","field_description":"FIFO mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass mode."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Stream-to-FIFO mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TR","field_description":"Trigger selection for Stream-to-FIFO mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Triggering signal on INT1."},{"value":"1","value_description":"Triggering signal on INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FTH[4:0]","field_description":"Programmable FIFO watermark threshold.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"FIFO_CTRL_REG","physical_address":{"hex":"0x2E","decimal":"46","bank":"","page":"","description":"FIFO mode and threshold control"},"description":"Select FIFO mode (Bypass/FIFO/Stream/Stream-to-FIFO), trigger pin and watermark threshold","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[19].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | WTM | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Set high when FIFO content exceeds the watermark level. | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | OVRN_FIFO | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Set high when the FIFO is full with 32 unread samples; clears when the first sample set is read. | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[1]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | EMPTY | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[2]` | `field_description` | 0.0 | Set high when all FIFO samples have been read and the FIFO is empty. | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[2]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | FSS [4:0] | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[3]` | `field_description` | 0.0 | Current number of unread sample sets stored in the FIFO. | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[3]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[19].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `without registers[19].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"WTM","field_description":"Set high when FIFO content exceeds the watermark level.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"OVRN_FIFO","field_description":"Set high when the FIFO is full with 32 unread samples; clears when the first sample set is read.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"EMPTY","field_description":"Set high when all FIFO samples have been read and the FIFO is empty.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FSS [4:0]","field_description":"Current number of unread sample sets stored in the FIFO.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R"}] | [] | field differs or is incomplete |
| `without registers[19]` | `field_parts` | 0.7 | {"register_name":"FIFO_SRC_REG","physical_address":{"hex":"0x2F","decimal":"47","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"WTM","field_description":"Set high when FIFO content exceeds the watermark level.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"OVRN_FIFO","field_description":"Set high when the FIFO is full with 32 unread samples; clears when the first sample set is read.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"EMPTY","field_description":"Set high when all FIFO samples have been read and the FIFO is empty.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FSS [4:0]","field_description":"Current number of unread sample sets stored in the FIFO.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R"}]} | [{"register_name":"FIFO_SRC_REG","physical_address":{"hex":"0x2F","decimal":"47","bank":"","page":"","description":"FIFO status and sample count"},"description":"FIFO status flags and unread sample count","width_bits":8,"type_write_read":"R","bit_field":[]}] | field differs or is incomplete |
| `truth registers[20].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | AOI-6D | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Interrupt event-combination and 6-direction recognition mode. | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}] | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | ZHIE | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Enable interrupt generation on Z high event or direction recognition. | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | ZLIE | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[2]` | `field_description` | 0.0 | Enable interrupt generation on Z low event or direction recognition. | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | YHIE | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[3]` | `field_description` | 0.0 | Enable interrupt generation on Y high event or direction recognition. | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | YLIE | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[4]` | `field_description` | 0.0 | Enable interrupt generation on Y low event or direction recognition. | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | XHIE | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[5]` | `field_description` | 0.0 | Enable interrupt generation on X high event or direction recognition. | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.0 | XLIE | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[6]` | `field_description` | 0.0 | Enable interrupt generation on X low event or direction recognition. | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[6]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[6]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[6]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[6]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[20].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event or direction recognition.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event or direction recognition.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event or direction recognition.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event or direction recognition.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event or direction recognition.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event or direction recognition.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[20]` | `register_description` | 0.5 | Configures interrupt 1 event combination, direction recognition and axis high/low event enables. Its content is loaded at boot, and writing is possible only after system boot. | Interrupt 1 configuration: AOI and 6D selection and axis high/low event enable bits for INT1 (X/Y/Z). | field differs or is incomplete |
| `without registers[20]` | `field_parts` | 0.7 | {"register_name":"INT1_CFG","physical_address":{"hex":"0x30","decimal":"48","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event or direction recognition.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event or direction recognition.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event or direction recognition.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event or direction recognition.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event or direction recognition.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event or direction recognition.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"INT1_CFG","physical_address":{"hex":"0x30","decimal":"48","bank":"","page":"","description":"INT1 event configuration"},"description":"Configure interrupt combination mode, 6D and axis event enables for INT1","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[21].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[0]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | IA | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Interrupt active. | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | ZH | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[2]` | `field_description` | 0.0 | Z high event status. | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | ZL | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[3]` | `field_description` | 0.0 | Z low event status. | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | YH | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[4]` | `field_description` | 0.0 | Y high event status. | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | YL | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[5]` | `field_description` | 0.0 | Y low event status. | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.0 | XH | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[6]` | `field_description` | 0.0 | X high event status. | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[6]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[6]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[6]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[6]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.0 | XL | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[7]` | `field_description` | 0.0 | X low event status. | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[7]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[7]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[7]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[7]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[7]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[21].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `without registers[21].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}] | [] | field differs or is incomplete |
| `without registers[21]` | `register_description` | 0.5 | Reports interrupt 1 source and axis-event status. Reading clears the IA bit and INT1 signal and refreshes latched data. | Interrupt 1 source register (read-only): reports which INT1 event occurred (IA, ZH/ZL, YH/YL, XH/XL). Reading clears IA if latched option selected. | field differs or is incomplete |
| `without registers[21]` | `field_parts` | 0.7 | {"register_name":"INT1_SRC","physical_address":{"hex":"0x31","decimal":"49","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}]} | [{"register_name":"INT1_SRC","physical_address":{"hex":"0x31","decimal":"49","bank":"","page":"","description":"INT1 source flags"},"description":"Indicates active INT1 sources; reading clears IA when latched","width_bits":8,"type_write_read":"R","bit_field":[]}] | field differs or is incomplete |
| `truth registers[22].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[0]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | THS[6:0] | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Interrupt 1 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g. | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[1]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[22].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[22].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 1 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[22]` | `register_description` | 0.5 | Sets the interrupt 1 acceleration threshold. | Interrupt 1 threshold (THS[6:0]). LSB weight depends on selected full-scale (16 mg @ ±2g, 32 mg @ ±4g, 62 mg @ ±8g, 186 mg @ ±16g). | field differs or is incomplete |
| `without registers[22]` | `field_parts` | 0.7 | {"register_name":"INT1_THS","physical_address":{"hex":"0x32","decimal":"50","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 1 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"INT1_THS","physical_address":{"hex":"0x32","decimal":"50","bank":"","page":"","description":"INT1 threshold (7-bit)"},"description":"Threshold for INT1 event detection; LSb weight depends on FS","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[23].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[0]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | D[6:0] | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Duration value; 1 LSb equals 1/ODR. | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[1]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[23].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[23].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[23]` | `field_parts` | 0.7 | {"register_name":"INT1_DURATION","physical_address":{"hex":"0x33","decimal":"51","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"INT1_DURATION","physical_address":{"hex":"0x33","decimal":"51","bank":"","page":"","description":"INT1 duration (7-bit)"},"description":"Duration threshold for INT1 (1 LSb = 1/ODR)","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[24].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | AOI-6D | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Interrupt event-combination and 6-direction recognition mode. | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}] | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | ZHIE | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Enable interrupt generation on Z high event. | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | ZLIE | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[2]` | `field_description` | 0.0 | Enable interrupt generation on Z low event. | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | YHIE | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[3]` | `field_description` | 0.0 | Enable interrupt generation on Y high event. | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | YLIE | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[4]` | `field_description` | 0.0 | Enable interrupt generation on Y low event. | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | XHIE | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[5]` | `field_description` | 0.0 | Enable interrupt generation on X high event. | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.0 | XLIE | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[6]` | `field_description` | 0.0 | Enable interrupt generation on X low event. | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[6]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[6]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[6]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[6]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[24].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[24]` | `register_description` | 0.5 | Configures interrupt 2 event combination, direction recognition and axis high/low event enables. Its content is loaded at boot, and writing is possible only after system boot. | Interrupt 2 configuration: AOI and 6D selection and axis high/low event enable bits for INT2 (X/Y/Z). | field differs or is incomplete |
| `without registers[24]` | `field_parts` | 0.7 | {"register_name":"INT2_CFG","physical_address":{"hex":"0x34","decimal":"52","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"INT2_CFG","physical_address":{"hex":"0x34","decimal":"52","bank":"","page":"","description":"INT2 event configuration"},"description":"Configure interrupt combination mode, 6D and axis event enables for INT2","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[25].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[0]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | IA | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Interrupt active. | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | ZH | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[2]` | `field_description` | 0.0 | Z high event status. | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | ZL | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[3]` | `field_description` | 0.0 | Z low event status. | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | YH | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[4]` | `field_description` | 0.0 | Y high event status. | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | YL | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[5]` | `field_description` | 0.0 | Y low event status. | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.0 | XH | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[6]` | `field_description` | 0.0 | X high event status. | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[6]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[6]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[6]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[6]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.0 | XL | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[7]` | `field_description` | 0.0 | X low event status. | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[7]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[7]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[7]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[7]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[7]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[25].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `without registers[25].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}] | [] | field differs or is incomplete |
| `without registers[25]` | `register_description` | 0.5 | Reports interrupt 2 source and axis-event status. Reading clears the IA bit and INT2 signal and refreshes latched data. | Interrupt 2 source register (read-only): reports which INT2 event occurred (IA, ZH/ZL, YH/YL, XH/XL). Reading clears IA if latched option selected. | field differs or is incomplete |
| `without registers[25]` | `field_parts` | 0.7 | {"register_name":"INT2_SRC","physical_address":{"hex":"0x35","decimal":"53","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}]} | [{"register_name":"INT2_SRC","physical_address":{"hex":"0x35","decimal":"53","bank":"","page":"","description":"INT2 source flags"},"description":"Indicates active INT2 sources; reading clears IA when latched","width_bits":8,"type_write_read":"R","bit_field":[]}] | field differs or is incomplete |
| `truth registers[26].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[0]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | THS[6:0] | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Interrupt 2 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g. | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[1]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[26].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[26].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 2 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[26]` | `register_description` | 0.5 | Sets the interrupt 2 acceleration threshold. | Interrupt 2 threshold (THS[6:0]). LSB weight depends on selected full-scale (same scaling as INT1_THS). | field differs or is incomplete |
| `without registers[26]` | `field_parts` | 0.7 | {"register_name":"INT2_THS","physical_address":{"hex":"0x36","decimal":"54","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 2 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"INT2_THS","physical_address":{"hex":"0x36","decimal":"54","bank":"","page":"","description":"INT2 threshold (7-bit)"},"description":"Threshold for INT2 event detection; LSb weight depends on FS","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[27].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[0]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | D[6:0] | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Duration value; 1 LSb equals 1/ODR. | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[1]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[27].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[27].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[27]` | `field_parts` | 0.7 | {"register_name":"INT2_DURATION","physical_address":{"hex":"0x37","decimal":"55","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"INT2_DURATION","physical_address":{"hex":"0x37","decimal":"55","bank":"","page":"","description":"INT2 duration (7-bit)"},"description":"Duration threshold for INT2 (1 LSb = 1/ODR)","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[28].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | -- | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | ZD | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Enable double-click interrupt on Z-axis. | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | ZS | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[2]` | `field_description` | 0.0 | Enable single-click interrupt on Z-axis. | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | YD | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[3]` | `field_description` | 0.0 | Enable double-click interrupt on Y-axis. | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | YS | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[4]` | `field_description` | 0.0 | Enable single-click interrupt on Y-axis. | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | XD | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[5]` | `field_description` | 0.0 | Enable double-click interrupt on X-axis. | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.0 | XS | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[6]` | `field_description` | 0.0 | Enable single-click interrupt on X-axis. | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[6]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[6]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[6]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[6]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[28].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"--","field_description":"","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"ZD","field_description":"Enable double-click interrupt on Z-axis.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZS","field_description":"Enable single-click interrupt on Z-axis.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YD","field_description":"Enable double-click interrupt on Y-axis.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YS","field_description":"Enable single-click interrupt on Y-axis.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XD","field_description":"Enable double-click interrupt on X-axis.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XS","field_description":"Enable single-click interrupt on X-axis.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[28]` | `register_description` | 0.5 | Enables single-click and double-click interrupt detection for the X, Y and Z axes. | Click configuration: enable single/double click detection per axis (XS/YS/ZS for single, XD/YD/ZD for double). | field differs or is incomplete |
| `without registers[28]` | `field_parts` | 0.7 | {"register_name":"CLICK_CFG","physical_address":{"hex":"0x38","decimal":"56","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"--","field_description":"","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"ZD","field_description":"Enable double-click interrupt on Z-axis.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZS","field_description":"Enable single-click interrupt on Z-axis.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YD","field_description":"Enable double-click interrupt on Y-axis.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YS","field_description":"Enable single-click interrupt on Y-axis.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XD","field_description":"Enable double-click interrupt on X-axis.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XS","field_description":"Enable single-click interrupt on X-axis.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CLICK_CFG","physical_address":{"hex":"0x38","decimal":"56","bank":"","page":"","description":"Click detection enable bits"},"description":"Enable single/double click detection on X/Y/Z axes","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[29].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[0]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | IA | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Interrupt active. | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | R | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | DCLICK | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[2]` | `field_description` | 0.0 | Double-click enable. | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Double-click detection disabled."},{"value":"1","value_description":"Double-click detection enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | SCLICK | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[3]` | `field_description` | 0.0 | Single-click enable. | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[3]` | `bit_start` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[3]` | `bit_end` | 0.0 | 4 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Single-click detection disabled."},{"value":"1","value_description":"Single-click detection enabled."}] | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | Sign | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[4]` | `field_description` | 0.0 | Click sign. | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[4]` | `bit_start` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[4]` | `bit_end` | 0.0 | 3 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"Positive detection."},{"value":"1","value_description":"Negative detection."}] | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.0 | Z | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[5]` | `field_description` | 0.0 | Z click detection. | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[5]` | `bit_start` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[5]` | `bit_end` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.0 | Y | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[6]` | `field_description` | 0.0 | Y click detection. | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[6]` | `bit_start` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[6]` | `bit_end` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[6]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[6]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.0 | X | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[7]` | `field_description` | 0.0 | X click detection. | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[7]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[7]` | `bit_end` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[7]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[7]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[7]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[29].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[29].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"DCLICK","field_description":"Double-click enable.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Double-click detection disabled."},{"value":"1","value_description":"Double-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SCLICK","field_description":"Single-click enable.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Single-click detection disabled."},{"value":"1","value_description":"Single-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Sign","field_description":"Click sign.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Positive detection."},{"value":"1","value_description":"Negative detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Z","field_description":"Z click detection.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Y","field_description":"Y click detection.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"X","field_description":"X click detection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[29]` | `register_description` | 0.5 | Reports click-interrupt activity, single/double-click detection, sign and detected axis. | Click source register (read-only): indicates click event status (single/double click, sign and axis). Reading clears status if latched option used. | field differs or is incomplete |
| `without registers[29]` | `field_parts` | 0.7 | {"register_name":"CLICK_SRC","physical_address":{"hex":"0x39","decimal":"57","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"DCLICK","field_description":"Double-click enable.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Double-click detection disabled."},{"value":"1","value_description":"Double-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SCLICK","field_description":"Single-click enable.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Single-click detection disabled."},{"value":"1","value_description":"Single-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Sign","field_description":"Click sign.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Positive detection."},{"value":"1","value_description":"Negative detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Z","field_description":"Z click detection.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Y","field_description":"Y click detection.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"X","field_description":"X click detection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CLICK_SRC","physical_address":{"hex":"0x39","decimal":"57","bank":"","page":"","description":"Click source flags"},"description":"Reports click event (single/double), sign and axis; IA indicates interrupt active","width_bits":8,"type_write_read":"R","bit_field":[]}] | field differs or is incomplete |
| `truth registers[30].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | LIR_Click | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Controls click-interrupt latching. | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}] | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | Ths[6:0] | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Click threshold. | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[1]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[30].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[30].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"LIR_Click","field_description":"Controls click-interrupt latching.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Ths[6:0]","field_description":"Click threshold.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[30]` | `field_parts` | 0.7 | {"register_name":"CLICK_THS","physical_address":{"hex":"0x3A","decimal":"58","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"LIR_Click","field_description":"Controls click-interrupt latching.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Ths[6:0]","field_description":"Click threshold.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"CLICK_THS","physical_address":{"hex":"0x3A","decimal":"58","bank":"","page":"","description":"Click threshold and latch control"},"description":"Click threshold and latch control (LIR_Click)","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[31].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | - | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | TLI[6:0] | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Click time limit. | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[1]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[31].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"-","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"TLI[6:0]","field_description":"Click time limit.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[31]` | `field_parts` | 0.7 | {"register_name":"TIME_LIMIT","physical_address":{"hex":"0x3B","decimal":"59","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"-","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"TLI[6:0]","field_description":"Click time limit.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"TIME_LIMIT","physical_address":{"hex":"0x3B","decimal":"59","bank":"","page":"","description":"Click time limit (7-bit)"},"description":"Time limit for click detection","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[32].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | TLA[7:0] | MISSING | truth bit field missing from extraction |
| `truth registers[32].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Click time latency. | MISSING | truth bit field missing from extraction |
| `truth registers[32].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[32].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[32].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 8 | MISSING | truth bit field missing from extraction |
| `truth registers[32].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[32].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[32].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[32].field_parts[0]` | `bit_field` | 0.0 | {"name_or_parameter":"TLA[7:0]","field_description":"Click time latency.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [] | field differs or is incomplete |
| `without registers[32]` | `field_parts` | 0.7 | {"register_name":"TIME_LATENCY","physical_address":{"hex":"0x3C","decimal":"60","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":{"name_or_parameter":"TLA[7:0]","field_description":"Click time latency.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}} | [{"register_name":"TIME_LATENCY","physical_address":{"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Click time latency (8-bit)"},"description":"Latency window for click detection","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[33].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | TW[7:0] | MISSING | truth bit field missing from extraction |
| `truth registers[33].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Click time window. | MISSING | truth bit field missing from extraction |
| `truth registers[33].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[33].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[33].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 8 | MISSING | truth bit field missing from extraction |
| `truth registers[33].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[33].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[33].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[33].field_parts[0]` | `bit_field` | 0.0 | {"name_or_parameter":"TW[7:0]","field_description":"Click time window.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [] | field differs or is incomplete |
| `without registers[33]` | `field_parts` | 0.7 | {"register_name":"TIME_WINDOW","physical_address":{"hex":"0x3D","decimal":"61","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":{"name_or_parameter":"TW[7:0]","field_description":"Click time window.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}} | [{"register_name":"TIME_WINDOW","physical_address":{"hex":"0x3D","decimal":"61","bank":"","page":"","description":"Click time window (8-bit)"},"description":"Time window for click/double-click detection","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `without registers[33]` | `default_value` | 0.0 | 00000000 | "" | field differs or is incomplete |
| `truth registers[34].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | -- | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | Acth[6:0] | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[1]` | `field_description` | 0.0 | Sleep-to-wake and return-to-sleep activation threshold in low-power mode. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g. | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[1]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[34].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"--","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Acth[6:0]","field_description":"Sleep-to-wake and return-to-sleep activation threshold in low-power mode. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [] | field differs or is incomplete |
| `without registers[34]` | `register_description` | 0.5 | Sets the sleep-to-wake and return-to-sleep activation threshold in low-power mode. | Activity threshold for sleep-to-wake/return-to-sleep function (Acth[6:0]). LSb weight depends on FS (16 mg @ ±2g etc.). | field differs or is incomplete |
| `without registers[34]` | `field_parts` | 0.7 | {"register_name":"ACT_THS","physical_address":{"hex":"0x3E","decimal":"62","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"--","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Acth[6:0]","field_description":"Sleep-to-wake and return-to-sleep activation threshold in low-power mode. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}]} | [{"register_name":"ACT_THS","physical_address":{"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Activity threshold (7-bit)"},"description":"Threshold for automatic sleep/wake detection; LSb weight depends on FS","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |
| `truth registers[35].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | ActD[7:0] | MISSING | truth bit field missing from extraction |
| `truth registers[35].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Sleep-to-wake and return-to-sleep duration; 1 LSb = (8*1[LSb]+1)/ODR. | MISSING | truth bit field missing from extraction |
| `truth registers[35].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[35].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[35].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 8 | MISSING | truth bit field missing from extraction |
| `truth registers[35].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[35].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[35].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `without registers[35].field_parts[0]` | `bit_field` | 0.0 | {"name_or_parameter":"ActD[7:0]","field_description":"Sleep-to-wake and return-to-sleep duration; 1 LSb = (8*1[LSb]+1)/ODR.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [] | field differs or is incomplete |
| `without registers[35]` | `field_parts` | 0.7 | {"register_name":"ACT_DUR","physical_address":{"hex":"0x3F","decimal":"63","bank":"","page":"","description":""},"description":"","width_bits":8,"type_write_read":"RW","bit_field":{"name_or_parameter":"ActD[7:0]","field_description":"Sleep-to-wake and return-to-sleep duration; 1 LSb = (8*1[LSb]+1)/ODR.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}} | [{"register_name":"ACT_DUR","physical_address":{"hex":"0x3F","decimal":"63","bank":"","page":"","description":"Activity duration (8-bit)"},"description":"Duration parameter for activity detection (sleep/wake)","width_bits":8,"type_write_read":"RW","bit_field":[]}] | field differs or is incomplete |

## 4. Invented-field and representation check

- Numeric physical addresses are normalized by `(numeric address, bank, page)`; hexadecimal and decimal spellings identify the same location.
- The slash-separated names for the two-byte ADC/axis outputs are treated as equivalent to the truth comma-separated names with address annotations; grouping is not penalized solely for representation.
- Reserved-bit names/descriptions may be empty; structural ranges, reserved status, values, access types, and widths remain scored.
- `type_write_read` is compared strictly; matching empty values would receive C=1, while missing or mismatched values receive C=0.



