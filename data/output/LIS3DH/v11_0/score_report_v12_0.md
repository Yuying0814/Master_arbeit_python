# LIS3DH v12.0 detailed score — updated truth type_write_read

## Extracted logical register 1: `STATUS_REG_AUX`

v12 location: `registers[0]`; truth association: `registers[0]` (`STATUS_REG_AUX`).

Associated physical locations: 0x07 (7).

### Bottom layer: bit fields, then field parts

#### Field part 1: `STATUS_REG_AUX` at 0x07 (7)

Locations: `truth registers[0].field_parts[0]` ↔ `v12 registers[0].field_parts[0]`.


**Truth bit field 1: `321OR` bits 7:7**

Locations: `truth registers[0].field_parts[0].bit_field[0]` ↔ `v12 registers[0].field_parts[0].bit_field[7]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 321OR | 321OR |
| `field_description` | 0.0586 | 1.0 | 1, 2 and 3-axis data overrun. | 1, 2 and 3-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: a new set of data has overwritten the previous set) |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 2: `3OR` bits 6:6**

Locations: `truth registers[0].field_parts[0].bit_field[1]` ↔ `v12 registers[0].field_parts[0].bit_field[6]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 3OR | 3OR |
| `field_description` | 0.0586 | 1.0 | 3-axis data overrun. | 3-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the 3-axis has overwritten the previous data) |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 3-axis has overwritten the previous data."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 3: `2OR` bits 5:5**

Locations: `truth registers[0].field_parts[0].bit_field[2]` ↔ `v12 registers[0].field_parts[0].bit_field[5]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 2OR | 2OR |
| `field_description` | 0.0586 | 1.0 | 2-axis data overrun. | 2-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the 2-axis has overwritten the previous data) |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 2-axis has overwritten the previous data."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 4: `1OR` bits 4:4**

Locations: `truth registers[0].field_parts[0].bit_field[3]` ↔ `v12 registers[0].field_parts[0].bit_field[4]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 1OR | 1OR |
| `field_description` | 0.0586 | 1.0 | 1-axis data overrun. | 1-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the 1-axis has overwritten the previous data) |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 1-axis has overwritten the previous data."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 5: `321DA` bits 3:3**

Locations: `truth registers[0].field_parts[0].bit_field[4]` ↔ `v12 registers[0].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 321DA | 321DA |
| `field_description` | 0.0586 | 1.0 | 1, 2 and 3-axis new data available. | 1, 2 and 3-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 6: `3DA` bits 2:2**

Locations: `truth registers[0].field_parts[0].bit_field[5]` ↔ `v12 registers[0].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 3DA | 3DA |
| `field_description` | 0.0586 | 1.0 | 3-axis new data available. | 3-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available) |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"New data for the 3-axis is not yet available."},{"value":"1","value_description":"New data for the 3-axis is available."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 7: `2DA` bits 1:1**

Locations: `truth registers[0].field_parts[0].bit_field[6]` ↔ `v12 registers[0].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 2DA | 2DA |
| `field_description` | 0.0586 | 1.0 | 2-axis new data available. | 2-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available) |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"New data for the 2-axis is not yet available."},{"value":"1","value_description":"New data for the 2-axis is available."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 8: `1DA` bits 0:0**

Locations: `truth registers[0].field_parts[0].bit_field[7]` ↔ `v12 registers[0].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 1DA | 1DA |
| `field_description` | 0.0586 | 1.0 | 1-axis new data available. | 1-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"New data for the 1-axis is not yet available."},{"value":"1","value_description":"New data for the 1-axis is available."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Field-part aggregation**

`bit_field` correctness = 0.790279.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | STATUS_REG_AUX | STATUS_REG_AUX |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.790279 | [{"name_or_parameter":"321OR","field_description":"1, 2 and 3-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3OR","field_description":"3-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 3-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2OR","field_description":"2-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 2-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1OR","field_description":"1-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 1-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"321DA","field_description":"1, 2 and 3-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3DA","field_description":"3-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 3-axis is not yet available."},{"value":"1","value_description":"New data for the 3-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2DA","field_description":"2-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 2-axis is not yet available."},{"value":"1","value_description":"New data for the 2-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1DA","field_description":"1-axis new data available.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 1-axis is not yet available."},{"value":"1","value_description":"New data for the 1-axis is available."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"1DA","field_description":"1-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2DA","field_description":"2-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3DA","field_description":"3-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"321DA","field_description":"1, 2 and 3-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1OR","field_description":"1-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the 1-axis has overwritten the previous data)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2OR","field_description":"2-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the 2-axis has overwritten the previous data)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3OR","field_description":"3-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the 3-axis has overwritten the previous data)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"321OR","field_description":"1, 2 and 3-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: a new set of data has overwritten the previous set)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.8)=\mathbf{0.934378}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.934378) = **0.934378**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | STATUS_REG_AUX | STATUS_REG_AUX |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Reports auxiliary ADC data-overrun and new-data availability status. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.934378 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{1})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.9 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.924099/1.0001=\mathbf{0.924006}\).

## Extracted logical register 2: `OUT_ADC1_L`

v12 location: `registers[1]`; truth association: `registers[1]` (`OUT_ADC1_L (08h), OUT_ADC1_H (09h)`).

Associated physical locations: 0x08 (8), 0x09 (9).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC1_L` at 0x08 (8)

Locations: `truth registers[1].field_parts[0]` ↔ `v12 registers[1].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC1_L | OUT_ADC1_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"Low byte of auxiliary ADC channel 1 conversion."} | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.000000 | Low byte of auxiliary ADC channel 1 conversion. | Low byte of auxiliary ADC channel 1 |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

#### Field part 2: `OUT_ADC1_H` at 0x09 (9)

Locations: `truth registers[1].field_parts[1]` ↔ `v12 registers[1].field_parts[1]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC1_H | OUT_ADC1_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"High byte of auxiliary ADC channel 1 conversion."} | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.000000 | High byte of auxiliary ADC channel 1 conversion. | High byte of auxiliary ADC channel 1 |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 0.500000 | OUT_ADC1_L (08h), OUT_ADC1_H (09h) | OUT_ADC1_L |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":"Low byte of auxiliary ADC channel 1 conversion."},{"hex":"0x09","decimal":"9","bank":"","page":"","description":"High byte of auxiliary ADC channel 1 conversion."}] | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":"Low byte"},{"hex":"0x09","decimal":"9","bank":"","page":"","description":"High byte"}] |
| `register_description` | 0.0564 | 0.500000 | Auxiliary 10-bit ADC channel 1 conversion, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 1 conversion. |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{2})=(0.0225×0.5 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.960650/1.0001=\mathbf{0.960554}\).

## Extracted logical register 3: `OUT_ADC1_H`

v12 location: `registers[2]`; truth association: `registers[1]` (`OUT_ADC1_L (08h), OUT_ADC1_H (09h)`).

Associated physical locations: 0x09 (9).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC1_H` at 0x09 (9)

Locations: `truth registers[1].field_parts[1]` ↔ `v12 registers[2].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC1_H | OUT_ADC1_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"High byte of auxiliary ADC channel 1 conversion."} | {"hex":"0x09","decimal":"9","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | High byte of auxiliary ADC channel 1 conversion. | High byte of auxiliary ADC channel 1 |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_ADC1_H | OUT_ADC1_H |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"High byte of auxiliary ADC channel 1 conversion."} | [{"hex":"0x09","decimal":"9","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Auxiliary 10-bit ADC channel 1 conversion, expressed in 2's complement left-aligned format. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{3})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.943700/1.0001=\mathbf{0.943606}\).

## Extracted logical register 4: `OUT_ADC2_L`

v12 location: `registers[3]`; truth association: `registers[2]` (`OUT_ADC2_L (0Ah), OUT_ADC2_H (0Bh)`).

Associated physical locations: 0x0A (10), 0x0B (11).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC2_L` at 0x0A (10)

Locations: `truth registers[2].field_parts[0]` ↔ `v12 registers[3].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC2_L | OUT_ADC2_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Low byte of auxiliary ADC channel 2 conversion."} | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.000000 | Low byte of auxiliary ADC channel 2 conversion. | Low byte of auxiliary ADC channel 2 |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

#### Field part 2: `OUT_ADC2_H` at 0x0B (11)

Locations: `truth registers[2].field_parts[1]` ↔ `v12 registers[3].field_parts[1]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC2_H | OUT_ADC2_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"High byte of auxiliary ADC channel 2 conversion."} | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.000000 | High byte of auxiliary ADC channel 2 conversion. | High byte of auxiliary ADC channel 2 |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 0.500000 | OUT_ADC2_L (0Ah), OUT_ADC2_H (0Bh) | OUT_ADC2_L |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Low byte of auxiliary ADC channel 2 conversion."},{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"High byte of auxiliary ADC channel 2 conversion."}] | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Low byte"},{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"High byte"}] |
| `register_description` | 0.0564 | 0.500000 | Auxiliary 10-bit ADC channel 2 conversion, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 2 conversion. |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{4})=(0.0225×0.5 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.960650/1.0001=\mathbf{0.960554}\).

## Extracted logical register 5: `OUT_ADC2_H`

v12 location: `registers[4]`; truth association: `registers[2]` (`OUT_ADC2_L (0Ah), OUT_ADC2_H (0Bh)`).

Associated physical locations: 0x0B (11).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC2_H` at 0x0B (11)

Locations: `truth registers[2].field_parts[1]` ↔ `v12 registers[4].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC2_H | OUT_ADC2_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"High byte of auxiliary ADC channel 2 conversion."} | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | High byte of auxiliary ADC channel 2 conversion. | High byte of auxiliary ADC channel 2 |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_ADC2_H | OUT_ADC2_H |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"High byte of auxiliary ADC channel 2 conversion."} | [{"hex":"0x0B","decimal":"11","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Auxiliary 10-bit ADC channel 2 conversion, expressed in 2's complement left-aligned format. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{5})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.943700/1.0001=\mathbf{0.943606}\).

## Extracted logical register 6: `OUT_ADC3_L`

v12 location: `registers[5]`; truth association: `registers[3]` (`OUT_ADC3_L (0Ch), OUT_ADC3_H (0Dh)`).

Associated physical locations: 0x0C (12), 0x0D (13).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC3_L` at 0x0C (12)

Locations: `truth registers[3].field_parts[0]` ↔ `v12 registers[5].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC3_L | OUT_ADC3_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output."} | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.000000 | Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output. | Low byte of auxiliary ADC channel 3 or temperature sensor data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

#### Field part 2: `OUT_ADC3_H` at 0x0D (13)

Locations: `truth registers[3].field_parts[1]` ↔ `v12 registers[5].field_parts[1]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC3_H | OUT_ADC3_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"High byte of auxiliary ADC channel 3 conversion or temperature-sensor output."} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.000000 | High byte of auxiliary ADC channel 3 conversion or temperature-sensor output. | High byte of auxiliary ADC channel 3 or temperature sensor data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 0.500000 | OUT_ADC3_L (0Ch), OUT_ADC3_H (0Dh) | OUT_ADC3_L |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output."},{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"High byte of auxiliary ADC channel 3 conversion or temperature-sensor output."}] | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Low byte"},{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"High byte"}] |
| `register_description` | 0.0564 | 0.500000 | Auxiliary 10-bit ADC channel 3 conversion or temperature-sensor data output, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 3 conversion or temperature sensor data output. |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{6})=(0.0225×0.5 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.960650/1.0001=\mathbf{0.960554}\).

## Extracted logical register 7: `OUT_ADC3_H`

v12 location: `registers[6]`; truth association: `registers[3]` (`OUT_ADC3_L (0Ch), OUT_ADC3_H (0Dh)`).

Associated physical locations: 0x0D (13).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC3_H` at 0x0D (13)

Locations: `truth registers[3].field_parts[1]` ↔ `v12 registers[6].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC3_H | OUT_ADC3_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"High byte of auxiliary ADC channel 3 conversion or temperature-sensor output."} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | High byte of auxiliary ADC channel 3 conversion or temperature-sensor output. | High byte of auxiliary ADC channel 3 or temperature sensor data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_ADC3_H | OUT_ADC3_H |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"High byte of auxiliary ADC channel 3 conversion or temperature-sensor output."} | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Auxiliary 10-bit ADC channel 3 conversion or temperature-sensor data output, expressed in 2's complement left-aligned format. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{7})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.943700/1.0001=\mathbf{0.943606}\).

## Extracted logical register 8: `WHO_AM_I`

v12 location: `registers[7]`; truth association: `registers[4]` (`WHO_AM_I`).

Associated physical locations: 0x0F (15).

### Bottom layer: bit fields, then field parts

#### Field part 1: `WHO_AM_I` at 0x0F (15)

Locations: `truth registers[4].field_parts[0]` ↔ `v12 registers[7].field_parts[0]`.

Additional extracted bit field `v12 registers[7].field_parts[0].bit_field[0]` (`Device ID`, bits 7:0) is not matched to a truth range and receives no credit.


**Field-part aggregation**

`bit_field` correctness = 0.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":""} | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | Device identification value |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.000000 | [] | [{"name_or_parameter":"Device ID","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"00110011","value_description":"Default device identification value"}],"is_reserved":false,"type_write_read":"R"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":""} | [{"hex":"0x0F","decimal":"15","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Device identification register. | Device identification register. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.687100 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00110011 | 00110011 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{8})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

## Extracted logical register 9: `CTRL_REG0`

v12 location: `registers[8]`; truth association: `registers[5]` (`CTRL_REG0`).

Associated physical locations: 0x1E (30).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG0` at 0x1E (30)

Locations: `truth registers[5].field_parts[0]` ↔ `v12 registers[8].field_parts[0]`.


**Truth bit field 1: `SDO_PU_DISC` bits 7:7**

Locations: `truth registers[5].field_parts[0].bit_field[0]` ↔ `v12 registers[8].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SDO_PU_DISC | SDO_PU_DISC |
| `field_description` | 0.0586 | 1.0 | Disconnect SDO/SA0 pull-up. | Disconnect SDO/SA0 pull-up. Default value: 0 (0: pull-up connected to SDO/SA0 pin; 1: pull-up disconnected to SDO/SA0 pin) |
| `bit_start` | 0.2594 | 0.0 | 7 | 2 |
| `bit_end` | 0.2594 | 0.0 | 7 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":0,"value_description":"SDO/SA0 internal pull-up connected."},{"value":1,"value_description":"SDO/SA0 internal pull-up disconnected."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.271400/0.9999=\mathbf{0.271427}\).


**Truth bit field 2: `bit6` bits 6:6**

Locations: `truth registers[5].field_parts[0].bit_field[1]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[5].field_parts[0].bit_field[2]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[5].field_parts[0].bit_field[3]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[5].field_parts[0].bit_field[4]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[5].field_parts[0].bit_field[5]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[5].field_parts[0].bit_field[6]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[5].field_parts[0].bit_field[7]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

`bit_field` correctness = 0.033928.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG0 | CTRL_REG0 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":""} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.033928 | [{"name_or_parameter":"SDO_PU_DISC","field_description":"Disconnect SDO/SA0 pull-up.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":0,"value_description":"SDO/SA0 internal pull-up connected."},{"value":1,"value_description":"SDO/SA0 internal pull-up disconnected."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"bit6","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":6,"bit_end":6,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit5","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":5,"bit_end":5,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit4","field_description":"This bit must be set to 1 for correct operation of the device.","bit_start":4,"bit_end":4,"bit_width":1,"values":{"value":1,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit3","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":3,"bit_end":3,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit2","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":2,"bit_end":2,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit1","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":1,"bit_end":1,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit0","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":0,"bit_end":0,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""}] | [{"name_or_parameter":"SDO_PU_DISC","field_description":"Disconnect SDO/SA0 pull-up. Default value: 0 (0: pull-up connected to SDO/SA0 pin; 1: pull-up disconnected to SDO/SA0 pin)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.0)=\mathbf{0.697716}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.697716) = **0.697716**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG0 | CTRL_REG0 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":""} | [{"hex":"0x1E","decimal":"30","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Controls disconnection of the internal SDO/SA0 pull-up. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.697716 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00010000 | 00010000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{9})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.853408/1.0001=\mathbf{0.853322}\).

## Extracted logical register 10: `TEMP_CFG_REG`

v12 location: `registers[9]`; truth association: `registers[6]` (`TEMP_CFG_REG`).

Associated physical locations: 0x1F (31).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TEMP_CFG_REG` at 0x1F (31)

Locations: `truth registers[6].field_parts[0]` ↔ `v12 registers[9].field_parts[0]`.


**Truth bit field 1: `ADC_EN` bits 7:7**

Locations: `truth registers[6].field_parts[0].bit_field[0]` ↔ `v12 registers[9].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ADC_EN | ADC_EN |
| `field_description` | 0.0586 | 1.0 | ADC enable. | ADC enable. Default value: 0 (0: ADC disabled; 1: ADC enabled) |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"ADC disabled."},{"value":"1","value_description":"ADC enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 2: `TEMP_EN` bits 6:6**

Locations: `truth registers[6].field_parts[0].bit_field[1]` ↔ `v12 registers[9].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_EN | TEMP_EN |
| `field_description` | 0.0586 | 1.0 | Temperature sensor enable. | Temperature sensor (T) enable. Default value: 0 (0: T disabled; 1: T enabled) |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Temperature sensor disabled."},{"value":"1","value_description":"Temperature sensor enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 3: `0` bits 5:0**

Locations: `truth registers[6].field_parts[0].bit_field[2]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

`bit_field` correctness = 0.526853.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TEMP_CFG_REG | TEMP_CFG_REG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":""} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.526853 | [{"name_or_parameter":"ADC_EN","field_description":"ADC enable.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"ADC disabled."},{"value":"1","value_description":"ADC enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TEMP_EN","field_description":"Temperature sensor enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Temperature sensor disabled."},{"value":"1","value_description":"Temperature sensor enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"0","field_description":"","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"ADC_EN","field_description":"ADC enable. Default value: 0 (0: ADC disabled; 1: ADC enabled)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TEMP_EN","field_description":"Temperature sensor (T) enable. Default value: 0 (0: T disabled; 1: T enabled)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.5)=\mathbf{0.851952}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.851952) = **0.851952**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TEMP_CFG_REG | TEMP_CFG_REG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":""} | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Enables the auxiliary ADC and temperature sensor. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.851952 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{10})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.9 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.899478/1.0001=\mathbf{0.899388}\).

## Extracted logical register 11: `CTRL_REG1`

v12 location: `registers[10]`; truth association: `registers[7]` (`CTRL_REG1`).

Associated physical locations: 0x20 (32).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG1` at 0x20 (32)

Locations: `truth registers[7].field_parts[0]` ↔ `v12 registers[10].field_parts[0]`.


**Truth bit field 1: `ODR[3:0]` bits 7:4**

Locations: `truth registers[7].field_parts[0].bit_field[0]` ↔ `v12 registers[10].field_parts[0].bit_field[4]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ODR[3:0] | ODR[3:0] |
| `field_description` | 0.0586 | 0.5 | Data-rate and power-mode selection. | Data rate selection. Default value: 0111 (Refer to Table 32: Data rate configuration for ODR mappings). |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 0.0 | [{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.760900/0.9999=\mathbf{0.760976}\).


**Truth bit field 2: `LPen` bits 3:3**

Locations: `truth registers[7].field_parts[0].bit_field[1]` ↔ `v12 registers[10].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LPen | LPen |
| `field_description` | 0.0586 | 1.0 | Low-power mode enable. | Low-power mode enable. Default value: 0 (0: high-resolution mode / normal mode, 1: low-power mode). Refer to Section 3.2.1: High-resolution, normal mode, low-power mode. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"High-resolution mode / normal mode."},{"value":"1","value_description":"Low-power mode."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 3: `Zen` bits 2:2**

Locations: `truth registers[7].field_parts[0].bit_field[2]` ↔ `v12 registers[10].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Zen | Zen |
| `field_description` | 0.0586 | 1.0 | Z-axis enable. | Z-axis enable. Default value: 1 (0: Z-axis disabled; 1: Z-axis enabled) |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Z-axis disabled."},{"value":"1","value_description":"Z-axis enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 4: `Yen` bits 1:1**

Locations: `truth registers[7].field_parts[0].bit_field[3]` ↔ `v12 registers[10].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Yen | Yen |
| `field_description` | 0.0586 | 1.0 | Y-axis enable. | Y-axis enable. Default value: 1 (0: Y-axis disabled; 1: Y-axis enabled) |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Y-axis disabled."},{"value":"1","value_description":"Y-axis enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 5: `Xen` bits 0:0**

Locations: `truth registers[7].field_parts[0].bit_field[4]` ↔ `v12 registers[10].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Xen | Xen |
| `field_description` | 0.0586 | 1.0 | X-axis enable. | X-axis enable. Default value: 1 (0: X-axis disabled; 1: X-axis enabled) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"X-axis disabled."},{"value":"1","value_description":"X-axis enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Field-part aggregation**

`bit_field` correctness = 0.784418.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG1 | CTRL_REG1 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":""} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.784418 | [{"name_or_parameter":"ODR[3:0]","field_description":"Data-rate and power-mode selection.","bit_start":4,"bit_end":7,"bit_width":4,"values":[{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LPen","field_description":"Low-power mode enable.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution mode / normal mode."},{"value":"1","value_description":"Low-power mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Zen","field_description":"Z-axis enable.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Z-axis disabled."},{"value":"1","value_description":"Z-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Yen","field_description":"Y-axis enable.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Y-axis disabled."},{"value":"1","value_description":"Y-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Xen","field_description":"X-axis enable.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"X-axis disabled."},{"value":"1","value_description":"X-axis enabled."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"Xen","field_description":"X-axis enable. Default value: 1 (0: X-axis disabled; 1: X-axis enabled)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Yen","field_description":"Y-axis enable. Default value: 1 (0: Y-axis disabled; 1: Y-axis enabled)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Zen","field_description":"Z-axis enable. Default value: 1 (0: Z-axis disabled; 1: Z-axis enabled)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LPen","field_description":"Low-power mode enable. Default value: 0 (0: high-resolution mode / normal mode, 1: low-power mode). Refer to Section 3.2.1: High-resolution, normal mode, low-power mode.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ODR[3:0]","field_description":"Data rate selection. Default value: 0111 (Refer to Table 32: Data rate configuration for ODR mappings).","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.8)=\mathbf{0.932545}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.932545) = **0.932545**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG1 | CTRL_REG1 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":""} | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Selects output data rate and power mode and enables the X, Y and Z axes. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.932545 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000111 | 00000111 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{11})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.9 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.923551/1.0001=\mathbf{0.923459}\).

## Extracted logical register 12: `CTRL_REG2`

v12 location: `registers[11]`; truth association: `registers[8]` (`CTRL_REG2`).

Associated physical locations: 0x21 (33).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG2` at 0x21 (33)

Locations: `truth registers[8].field_parts[0]` ↔ `v12 registers[11].field_parts[0]`.


**Truth bit field 1: `HPM[1:0]` bits 7:6**

Locations: `truth registers[8].field_parts[0].bit_field[0]` ↔ `v12 registers[11].field_parts[0].bit_field[5]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | HPM[1:0] | HPM[1:0] |
| `field_description` | 0.0586 | 1.0 | High-pass filter mode selection. | High-pass filter mode selection. Default value: 00 (Refer to Table 35: High-pass filter mode configuration). |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 0.0 | [{"value":"00","value_description":"Normal mode, reset by reading REFERENCE (26h)."},{"value":"01","value_description":"Reference signal for filtering."},{"value":"10","value_description":"Normal mode."},{"value":"11","value_description":"Autoreset on interrupt event."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 2: `HPCF[2:1]` bits 5:4**

Locations: `truth registers[8].field_parts[0].bit_field[1]` ↔ `v12 registers[11].field_parts[0].bit_field[4]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | HPCF[2:1] | HPCF[2:1] |
| `field_description` | 0.0586 | 1.0 | High-pass filter cutoff-frequency selection. | High-pass filter cutoff frequency selection. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Truth bit field 3: `FDS` bits 3:3**

Locations: `truth registers[8].field_parts[0].bit_field[2]` ↔ `v12 registers[11].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FDS | FDS |
| `field_description` | 0.0586 | 1.0 | Filtered data selection. | Filtered data selection. Default value: 0 (0: internal filter bypassed; 1: data from internal filter sent to output register and FIFO) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Internal filter bypassed."},{"value":"1","value_description":"Data from the internal filter sent to the output register and FIFO."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 4: `HPCLICK` bits 2:2**

Locations: `truth registers[8].field_parts[0].bit_field[3]` ↔ `v12 registers[11].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | HPCLICK | HPCLICK |
| `field_description` | 0.0586 | 1.0 | High-pass filter enable for the CLICK function. | High-pass filter enabled for CLICK function (0: filter bypassed; 1: filter enabled) |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 5: `HP_IA2` bits 1:1**

Locations: `truth registers[8].field_parts[0].bit_field[4]` ↔ `v12 registers[11].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | HP_IA2 | HP_IA2 |
| `field_description` | 0.0586 | 1.0 | High-pass filter enable for the AOI function on interrupt 2. | High-pass filter enabled for AOI function on interrupt 2 (0: filter bypassed; 1: filter enabled) |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 6: `HP_IA1` bits 0:0**

Locations: `truth registers[8].field_parts[0].bit_field[5]` ↔ `v12 registers[11].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | HP_IA1 | HP_IA1 |
| `field_description` | 0.0586 | 1.0 | High-pass filter enable for the AOI function on interrupt 1. | High-pass filter enabled for AOI function on interrupt 1 (0: filter bypassed; 1: filter enabled) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Field-part aggregation**

`bit_field` correctness = 0.825233.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG2 | CTRL_REG2 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":""} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.825233 | [{"name_or_parameter":"HPM[1:0]","field_description":"High-pass filter mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode, reset by reading REFERENCE (26h)."},{"value":"01","value_description":"Reference signal for filtering."},{"value":"10","value_description":"Normal mode."},{"value":"11","value_description":"Autoreset on interrupt event."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCF[2:1]","field_description":"High-pass filter cutoff-frequency selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FDS","field_description":"Filtered data selection.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Internal filter bypassed."},{"value":"1","value_description":"Data from the internal filter sent to the output register and FIFO."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCLICK","field_description":"High-pass filter enable for the CLICK function.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA2","field_description":"High-pass filter enable for the AOI function on interrupt 2.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA1","field_description":"High-pass filter enable for the AOI function on interrupt 1.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"HP_IA1","field_description":"High-pass filter enabled for AOI function on interrupt 1 (0: filter bypassed; 1: filter enabled)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA2","field_description":"High-pass filter enabled for AOI function on interrupt 2 (0: filter bypassed; 1: filter enabled)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCLICK","field_description":"High-pass filter enabled for CLICK function (0: filter bypassed; 1: filter enabled)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FDS","field_description":"Filtered data selection. Default value: 0 (0: internal filter bypassed; 1: data from internal filter sent to output register and FIFO)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCF[2:1]","field_description":"High-pass filter cutoff frequency selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPM[1:0]","field_description":"High-pass filter mode selection. Default value: 00 (Refer to Table 35: High-pass filter mode configuration).","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.8)=\mathbf{0.945315}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.945315) = **0.945315**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG2 | CTRL_REG2 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":""} | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Configures the high-pass filter and its routing to output, FIFO, click and interrupt functions. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.945315 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{12})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.9 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.927366/1.0001=\mathbf{0.927273}\).

## Extracted logical register 13: `CTRL_REG3`

v12 location: `registers[12]`; truth association: `registers[9]` (`CTRL_REG3`).

Associated physical locations: 0x22 (34).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG3` at 0x22 (34)

Locations: `truth registers[9].field_parts[0]` ↔ `v12 registers[12].field_parts[0]`.


**Truth bit field 1: `I1_CLICK` bits 7:7**

Locations: `truth registers[9].field_parts[0].bit_field[0]` ↔ `v12 registers[12].field_parts[0].bit_field[7]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I1_CLICK | -- |
| `field_description` | 0.0586 | 0.0 | Click interrupt on INT1. | "" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] |
| `is_reserved` | 0.0750 | 0.0 | false | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.577100/0.9999=\mathbf{0.577158}\).


**Truth bit field 2: `I1_IA1` bits 6:6**

Locations: `truth registers[9].field_parts[0].bit_field[1]` ↔ `v12 registers[12].field_parts[0].bit_field[6]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.5 | I1_IA1 | I1_CLICK |
| `field_description` | 0.0586 | 1.0 | IA1 interrupt on INT1. | Click interrupt on INT1. Default value: 0 (0: disable; 1: enable) |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×0.5 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.779600/0.9999=\mathbf{0.779678}\).


**Truth bit field 3: `I1_IA2` bits 5:5**

Locations: `truth registers[9].field_parts[0].bit_field[2]` ↔ `v12 registers[12].field_parts[0].bit_field[5]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.5 | I1_IA2 | I1_IA1 |
| `field_description` | 0.0586 | 1.0 | IA2 interrupt on INT1. | IA1 interrupt on INT1. Default value: 0 (0: disable; 1: enable) |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×0.5 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.779600/0.9999=\mathbf{0.779678}\).


**Truth bit field 4: `I1_ZYXDA` bits 4:4**

Locations: `truth registers[9].field_parts[0].bit_field[3]` ↔ `v12 registers[12].field_parts[0].bit_field[4]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.5 | I1_ZYXDA | I1_IA2 |
| `field_description` | 0.0586 | 1.0 | ZYXDA interrupt on INT1. | IA2 interrupt on INT1. Default value: 0 (0: disable; 1: enable) |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×0.5 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.779600/0.9999=\mathbf{0.779678}\).


**Truth bit field 5: `I1_321DA` bits 3:3**

Locations: `truth registers[9].field_parts[0].bit_field[4]` ↔ `v12 registers[12].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.5 | I1_321DA | I1_ZYXDA |
| `field_description` | 0.0586 | 1.0 | 321DA interrupt on INT1. | ZYXDA interrupt on INT1. Default value: 0 (0: disable; 1: enable) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×0.5 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.779600/0.9999=\mathbf{0.779678}\).


**Truth bit field 6: `I1_WTM` bits 2:2**

Locations: `truth registers[9].field_parts[0].bit_field[5]` ↔ `v12 registers[12].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.5 | I1_WTM | I1_321DA |
| `field_description` | 0.0586 | 0.5 | FIFO watermark interrupt on INT1. | 321DA interrupt on INT1. Default value: 0 (0: disable; 1: enable) |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×0.5 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.750300/0.9999=\mathbf{0.750375}\).


**Truth bit field 7: `I1_OVERRUN` bits 1:1**

Locations: `truth registers[9].field_parts[0].bit_field[6]` ↔ `v12 registers[12].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.5 | I1_OVERRUN | I1_WTM |
| `field_description` | 0.0586 | 1.0 | FIFO overrun interrupt on INT1. | FIFO watermark interrupt on INT1. Default value: 0 (0: disable; 1: enable) |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×0.5 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.779600/0.9999=\mathbf{0.779678}\).


**Truth bit field 8: `--` bits 0:0**

Locations: `truth registers[9].field_parts[0].bit_field[7]` ↔ `v12 registers[12].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | -- | I1_OVERRUN |
| `field_description` | 0.0586 | 1.0 | "" | FIFO overrun interrupt on INT1. Default value: 0 (0: disable; 1: enable) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 0.0 | true | false |
| `type_write_read` | 0.0583 | 0.0 | "" | RW |

\(Q_{BF}=(0.0212×0.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.845400/0.9999=\mathbf{0.845485}\).


**Field-part aggregation**

`bit_field` correctness = 0.758926.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG3 | CTRL_REG3 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x22","decimal":"34","bank":"","page":"","description":""} | {"hex":"0x22","decimal":"34","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.758926 | [{"name_or_parameter":"I1_CLICK","field_description":"Click interrupt on INT1.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA1","field_description":"IA1 interrupt on INT1.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA2","field_description":"IA2 interrupt on INT1.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_ZYXDA","field_description":"ZYXDA interrupt on INT1.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_321DA","field_description":"321DA interrupt on INT1.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_WTM","field_description":"FIFO watermark interrupt on INT1.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_OVERRUN","field_description":"FIFO overrun interrupt on INT1.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"I1_OVERRUN","field_description":"FIFO overrun interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_WTM","field_description":"FIFO watermark interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_321DA","field_description":"321DA interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_ZYXDA","field_description":"ZYXDA interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA2","field_description":"IA2 interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA1","field_description":"IA1 interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_CLICK","field_description":"Click interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.8)=\mathbf{0.924568}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.924568) = **0.924568**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG3 | CTRL_REG3 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x22","decimal":"34","bank":"","page":"","description":""} | [{"hex":"0x22","decimal":"34","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Routes click, inertial, data-ready, FIFO watermark and FIFO overrun interrupts to INT1. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.924568 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{13})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.9 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.921168/1.0001=\mathbf{0.921076}\).

## Extracted logical register 14: `CTRL_REG4`

v12 location: `registers[13]`; truth association: `registers[10]` (`CTRL_REG4`).

Associated physical locations: 0x23 (35).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG4` at 0x23 (35)

Locations: `truth registers[10].field_parts[0]` ↔ `v12 registers[13].field_parts[0]`.


**Truth bit field 1: `BDU` bits 7:7**

Locations: `truth registers[10].field_parts[0].bit_field[0]` ↔ `v12 registers[13].field_parts[0].bit_field[5]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | BDU | BDU |
| `field_description` | 0.0586 | 1.0 | Block data update. | Block data update. Default value: 0 (0: continuous update; 1: output registers not updated until MSB and LSB reading) |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Continuous update."},{"value":"1","value_description":"Output registers are not updated until MSB and LSB have been read."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 2: `BLE` bits 6:6**

Locations: `truth registers[10].field_parts[0].bit_field[1]` ↔ `v12 registers[13].field_parts[0].bit_field[4]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | BLE | BLE |
| `field_description` | 0.0586 | 1.0 | Big/little endian data selection; available only in high-resolution mode. | Big/little endian data selection. Default value: 0 (0: Data LSB @ lower address; 1: Data MSB @ lower address). The BLE function can be activated only in high-resolution mode. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Data LSB at lower address."},{"value":"1","value_description":"Data MSB at lower address."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 3: `FS[1:0]` bits 5:4**

Locations: `truth registers[10].field_parts[0].bit_field[2]` ↔ `v12 registers[13].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FS[1:0] | FS[1:0] |
| `field_description` | 0.0586 | 1.0 | Full-scale selection. | Full-scale selection. Default value: 00 (00: ±2 g; 01: ±4 g; 10: ±8 g; 11: ±16 g) |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 0.0 | [{"value":"00","value_description":"±2 g."},{"value":"01","value_description":"±4 g."},{"value":"10","value_description":"±8 g."},{"value":"11","value_description":"±16 g."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 4: `HR` bits 3:3**

Locations: `truth registers[10].field_parts[0].bit_field[3]` ↔ `v12 registers[13].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | HR | HR |
| `field_description` | 0.0586 | 1.0 | High-resolution output mode. | High-resolution output mode. Default value: 0 (0: high-resolution disabled; 1: high-resolution enabled) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"High-resolution disabled."},{"value":"1","value_description":"High-resolution enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 5: `ST[1:0]` bits 2:1**

Locations: `truth registers[10].field_parts[0].bit_field[4]` ↔ `v12 registers[13].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ST[1:0] | ST[1:0] |
| `field_description` | 0.0586 | 1.0 | Self-test enable. | Self-test enable. Default value: 00 (Refer to Table 40: Self-test mode configuration). |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 0.0 | [{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 6: `SIM` bits 0:0**

Locations: `truth registers[10].field_parts[0].bit_field[5]` ↔ `v12 registers[13].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SIM | SIM |
| `field_description` | 0.0586 | 1.0 | SPI serial-interface mode selection. | SPI serial interface mode selection. Default value: 0 (0: 4-wire interface; 1: 3-wire interface) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Field-part aggregation**

`bit_field` correctness = 0.790279.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG4 | CTRL_REG4 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x23","decimal":"35","bank":"","page":"","description":""} | {"hex":"0x23","decimal":"35","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.790279 | [{"name_or_parameter":"BDU","field_description":"Block data update.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Continuous update."},{"value":"1","value_description":"Output registers are not updated until MSB and LSB have been read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BLE","field_description":"Big/little endian data selection; available only in high-resolution mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Data LSB at lower address."},{"value":"1","value_description":"Data MSB at lower address."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FS[1:0]","field_description":"Full-scale selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[{"value":"00","value_description":"±2 g."},{"value":"01","value_description":"±4 g."},{"value":"10","value_description":"±8 g."},{"value":"11","value_description":"±16 g."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HR","field_description":"High-resolution output mode.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution disabled."},{"value":"1","value_description":"High-resolution enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ST[1:0]","field_description":"Self-test enable.","bit_start":1,"bit_end":2,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SIM","field_description":"SPI serial-interface mode selection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"SIM","field_description":"SPI serial interface mode selection. Default value: 0 (0: 4-wire interface; 1: 3-wire interface)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ST[1:0]","field_description":"Self-test enable. Default value: 00 (Refer to Table 40: Self-test mode configuration).","bit_start":1,"bit_end":2,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HR","field_description":"High-resolution output mode. Default value: 0 (0: high-resolution disabled; 1: high-resolution enabled)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FS[1:0]","field_description":"Full-scale selection. Default value: 00 (00: ±2 g; 01: ±4 g; 10: ±8 g; 11: ±16 g)","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BLE","field_description":"Big/little endian data selection. Default value: 0 (0: Data LSB @ lower address; 1: Data MSB @ lower address). The BLE function can be activated only in high-resolution mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BDU","field_description":"Block data update. Default value: 0 (0: continuous update; 1: output registers not updated until MSB and LSB reading)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.8)=\mathbf{0.934378}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.934378) = **0.934378**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG4 | CTRL_REG4 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x23","decimal":"35","bank":"","page":"","description":""} | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Configures block data update, byte order, full scale, high-resolution mode, self-test and SPI interface mode. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.934378 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{14})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.9 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.924099/1.0001=\mathbf{0.924006}\).

## Extracted logical register 15: `CTRL_REG5`

v12 location: `registers[14]`; truth association: `registers[11]` (`CTRL_REG5`).

Associated physical locations: 0x24 (36).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG5` at 0x24 (36)

Locations: `truth registers[11].field_parts[0]` ↔ `v12 registers[14].field_parts[0]`.


**Truth bit field 1: `BOOT` bits 7:7**

Locations: `truth registers[11].field_parts[0].bit_field[0]` ↔ `v12 registers[14].field_parts[0].bit_field[6]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | BOOT | BOOT |
| `field_description` | 0.0586 | 1.0 | Reboot memory content. | Reboot memory content. Default value: 0 (0: normal mode; 1: reboot memory content) |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Normal mode."},{"value":"1","value_description":"Reboot memory content."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 2: `FIFO_EN` bits 6:6**

Locations: `truth registers[11].field_parts[0].bit_field[1]` ↔ `v12 registers[14].field_parts[0].bit_field[5]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_EN | FIFO_EN |
| `field_description` | 0.0586 | 1.0 | FIFO enable. | FIFO enable. Default value: 0 (0: FIFO disable; 1: FIFO enable) |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"FIFO disabled."},{"value":"1","value_description":"FIFO enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 3: `--` bits 5:4**

Locations: `truth registers[11].field_parts[0].bit_field[2]` ↔ `v12 registers[14].field_parts[0].bit_field[4]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | -- | -- |
| `field_description` | 0.0586 | 1.0 | "" | "" |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).


**Truth bit field 4: `LIR_INT1` bits 3:3**

Locations: `truth registers[11].field_parts[0].bit_field[3]` ↔ `v12 registers[14].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LIR_INT1 | LIR_INT1 |
| `field_description` | 0.0586 | 1.0 | Latch interrupt request on INT1_SRC; reading INT1_SRC clears it. | Latch interrupt request on INT1_SRC register, with INT1_SRC (31h) register cleared by reading INT1_SRC (31h) itself. Default value: 0 (0: interrupt request not latched; 1: interrupt request latched) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 5: `D4D_INT1` bits 2:2**

Locations: `truth registers[11].field_parts[0].bit_field[4]` ↔ `v12 registers[14].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | D4D_INT1 | D4D_INT1 |
| `field_description` | 0.0586 | 1.0 | Enable 4D detection on INT1 when the INT1_CFG 6D bit is set. | 4D enable: 4D detection is enabled on INT1 when 6D bit on INT1_CFG is set to 1. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Truth bit field 6: `LIR_INT2` bits 1:1**

Locations: `truth registers[11].field_parts[0].bit_field[5]` ↔ `v12 registers[14].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LIR_INT2 | LIR_INT2 |
| `field_description` | 0.0586 | 1.0 | Latch interrupt request on INT2_SRC; reading INT2_SRC clears it. | Latch interrupt request on INT2_SRC (35h) register, with INT2_SRC (35h) register cleared by reading INT2_SRC (35h) itself. Default value: 0 (0: interrupt request not latched; 1: interrupt request latched) |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 7: `D4D_INT2` bits 0:0**

Locations: `truth registers[11].field_parts[0].bit_field[6]` ↔ `v12 registers[14].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | D4D_INT2 | D4D_INT2 |
| `field_description` | 0.0586 | 1.0 | Enable 4D detection on INT2 when the INT2_CFG 6D bit is set. | 4D enable: 4D detection is enabled on INT2 pin when 6D bit on INT2_CFG (34h) is set to 1. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.871830.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG5 | CTRL_REG5 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x24","decimal":"36","bank":"","page":"","description":""} | {"hex":"0x24","decimal":"36","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.871830 | [{"name_or_parameter":"BOOT","field_description":"Reboot memory content.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Normal mode."},{"value":"1","value_description":"Reboot memory content."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FIFO_EN","field_description":"FIFO enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"FIFO disabled."},{"value":"1","value_description":"FIFO enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT1","field_description":"Latch interrupt request on INT1_SRC; reading INT1_SRC clears it.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT1","field_description":"Enable 4D detection on INT1 when the INT1_CFG 6D bit is set.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT2","field_description":"Latch interrupt request on INT2_SRC; reading INT2_SRC clears it.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT2","field_description":"Enable 4D detection on INT2 when the INT2_CFG 6D bit is set.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"D4D_INT2","field_description":"4D enable: 4D detection is enabled on INT2 pin when 6D bit on INT2_CFG (34h) is set to 1.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT2","field_description":"Latch interrupt request on INT2_SRC (35h) register, with INT2_SRC (35h) register cleared by reading INT2_SRC (35h) itself. Default value: 0 (0: interrupt request not latched; 1: interrupt request latched)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT1","field_description":"4D enable: 4D detection is enabled on INT1 when 6D bit on INT1_CFG is set to 1.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT1","field_description":"Latch interrupt request on INT1_SRC register, with INT1_SRC (31h) register cleared by reading INT1_SRC (31h) itself. Default value: 0 (0: interrupt request not latched; 1: interrupt request latched)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"FIFO_EN","field_description":"FIFO enable. Default value: 0 (0: FIFO disable; 1: FIFO enable)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BOOT","field_description":"Reboot memory content. Default value: 0 (0: normal mode; 1: reboot memory content)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.9)=\mathbf{0.959896}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.959896) = **0.959896**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG5 | CTRL_REG5 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x24","decimal":"36","bank":"","page":"","description":""} | [{"hex":"0x24","decimal":"36","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Controls memory reboot, FIFO enable, interrupt latching and 4D detection. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.959896 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{15})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.931721/1.0001=\mathbf{0.931628}\).

## Extracted logical register 16: `CTRL_REG6`

v12 location: `registers[15]`; truth association: `registers[12]` (`CTRL_REG6`).

Associated physical locations: 0x25 (37).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG6` at 0x25 (37)

Locations: `truth registers[12].field_parts[0]` ↔ `v12 registers[15].field_parts[0]`.


**Truth bit field 1: `I2_CLICK` bits 7:7**

Locations: `truth registers[12].field_parts[0].bit_field[0]` ↔ `v12 registers[15].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.5 | I2_CLICK | I2_ACT |
| `field_description` | 0.0586 | 1.0 | Click interrupt on INT2 pin. | Enable activity interrupt on INT2 pin. Default value: 0 (0: disabled; 1: enabled) |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×0.5 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.779600/0.9999=\mathbf{0.779678}\).


**Truth bit field 2: `I2_IA1` bits 6:6**

Locations: `truth registers[12].field_parts[0].bit_field[1]` ↔ `v12 registers[15].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | I2_IA1 | INT_POLARITY |
| `field_description` | 0.0586 | 0.5 | Enable interrupt 1 function on INT2 pin. | INT1 and INT2 pin polarity. Default value: 0 (0: active-high; 1: active-low) |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | I2_CLICK | RW |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.681400/0.9999=\mathbf{0.681468}\).


**Truth bit field 3: `I2_IA2` bits 5:5**

Locations: `truth registers[12].field_parts[0].bit_field[2]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[12].field_parts[0].bit_field[3]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[12].field_parts[0].bit_field[4]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[12].field_parts[0].bit_field[5]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[12].field_parts[0].bit_field[6]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[12].field_parts[0].bit_field[7]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Additional extracted bit field `v12 registers[15].field_parts[0].bit_field[0]` (`-`, bits 5:0) is not matched to a truth range and receives no credit.


**Field-part aggregation**

`bit_field` correctness = 0.182643.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG6 | CTRL_REG6 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x25","decimal":"37","bank":"","page":"","description":""} | {"hex":"0x25","decimal":"37","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.182643 | [{"name_or_parameter":"I2_CLICK","field_description":"Click interrupt on INT2 pin.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I2_IA1","field_description":"Enable interrupt 1 function on INT2 pin.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_IA2","field_description":"Enable interrupt 2 function on INT2 pin.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_BOOT","field_description":"Enable boot on INT2 pin.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_ACT","field_description":"Enable activity interrupt on INT2 pin.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"--","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"I2_CLICK"},{"name_or_parameter":"INT_POLARITY","field_description":"INT1 and INT2 pin polarity.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Active-high."},{"value":"1","value_description":"Active-low."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"INT_POLARITY","field_description":"INT1 and INT2 pin polarity. Default value: 0 (0: active-high; 1: active-low)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I2_ACT","field_description":"Enable activity interrupt on INT2 pin. Default value: 0 (0: disabled; 1: enabled)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.2)=\mathbf{0.744249}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.744249) = **0.744249**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG6 | CTRL_REG6 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x25","decimal":"37","bank":"","page":"","description":""} | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Routes click, inertial, boot and activity signals to INT2 and sets interrupt-pin polarity. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.744249 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{16})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.7 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.867307/1.0001=\mathbf{0.867220}\).

## Extracted logical register 17: `REFERENCE`

v12 location: `registers[16]`; truth association: `registers[13]` (`REFERENCE`).

Associated physical locations: 0x26 (38).

### Bottom layer: bit fields, then field parts

#### Field part 1: `REFERENCE` at 0x26 (38)

Locations: `truth registers[13].field_parts[0]` ↔ `v12 registers[16].field_parts[0]`.


**Truth bit field 1: `Ref[7:0]` bits 7:0**

Locations: `truth registers[13].field_parts[0].bit_field[0]` ↔ `v12 registers[16].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Ref[7:0] | Ref[7:0] |
| `field_description` | 0.0586 | 1.0 | Reference value for interrupt generation. | Reference value for Interrupt generation. Default value: 00000000 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | Ref[7:0] | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).


**Field-part aggregation**

`bit_field` correctness = 0.941694.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | REFERENCE | REFERENCE |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x26","decimal":"38","bank":"","page":"","description":""} | {"hex":"0x26","decimal":"38","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | {"name_or_parameter":"Ref[7:0]","field_description":"Reference value for interrupt generation.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"Ref[7:0]"} | [{"name_or_parameter":"Ref[7:0]","field_description":"Reference value for Interrupt generation. Default value: 00000000","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.9)=\mathbf{0.981756}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.981756) = **0.981756**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | REFERENCE | REFERENCE |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x26","decimal":"38","bank":"","page":"","description":""} | [{"hex":"0x26","decimal":"38","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Stores the reference value used for interrupt generation and reference-signal filtering. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.981756 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{17})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.938251/1.0001=\mathbf{0.938157}\).

## Extracted logical register 18: `STATUS_REG`

v12 location: `registers[17]`; truth association: `registers[14]` (`STATUS_REG`).

Associated physical locations: 0x27 (39).

### Bottom layer: bit fields, then field parts

#### Field part 1: `STATUS_REG` at 0x27 (39)

Locations: `truth registers[14].field_parts[0]` ↔ `v12 registers[17].field_parts[0]`.


**Truth bit field 1: `ZYXOR` bits 7:7**

Locations: `truth registers[14].field_parts[0].bit_field[0]` ↔ `v12 registers[17].field_parts[0].bit_field[7]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZYXOR | ZYXOR |
| `field_description` | 0.0586 | 1.0 | X, Y and Z-axis data overrun. | X, Y and Z-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: a new set of data has overwritten the previous set) |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 2: `ZOR` bits 6:6**

Locations: `truth registers[14].field_parts[0].bit_field[1]` ↔ `v12 registers[17].field_parts[0].bit_field[6]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZOR | ZOR |
| `field_description` | 0.0586 | 1.0 | Z-axis data overrun. | Z-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the Z-axis has overwritten the previous data) |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Z-axis data has overwritten the previous data."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 3: `YOR` bits 5:5**

Locations: `truth registers[14].field_parts[0].bit_field[2]` ↔ `v12 registers[17].field_parts[0].bit_field[5]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YOR | YOR |
| `field_description` | 0.0586 | 1.0 | Y-axis data overrun. | Y-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the Y-axis has overwritten the previous data) |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Y-axis data has overwritten the previous data."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 4: `XOR` bits 4:4**

Locations: `truth registers[14].field_parts[0].bit_field[3]` ↔ `v12 registers[17].field_parts[0].bit_field[4]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XOR | XOR |
| `field_description` | 0.0586 | 1.0 | X-axis data overrun. | X-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: a new set of data has overwritten the previous set) |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New X-axis data has overwritten the previous data."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 5: `ZYXDA` bits 3:3**

Locations: `truth registers[14].field_parts[0].bit_field[4]` ↔ `v12 registers[17].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZYXDA | ZYXDA |
| `field_description` | 0.0586 | 1.0 | X, Y and Z-axis new data available. | X, Y and Z-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 6: `ZDA` bits 2:2**

Locations: `truth registers[14].field_parts[0].bit_field[5]` ↔ `v12 registers[17].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZDA | ZDA |
| `field_description` | 0.0586 | 1.0 | Z-axis new data available. | Z-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available) |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"New Z-axis data is not yet available."},{"value":"1","value_description":"New Z-axis data is available."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 7: `YDA` bits 1:1**

Locations: `truth registers[14].field_parts[0].bit_field[6]` ↔ `v12 registers[17].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YDA | YDA |
| `field_description` | 0.0586 | 1.0 | Y-axis new data available. | Y-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available) |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"New Y-axis data is not yet available."},{"value":"1","value_description":"New Y-axis data is available."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 8: `XDA` bits 0:0**

Locations: `truth registers[14].field_parts[0].bit_field[7]` ↔ `v12 registers[17].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XDA | XDA |
| `field_description` | 0.0586 | 1.0 | "" | X-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.816494.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | STATUS_REG | STATUS_REG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x27","decimal":"39","bank":"","page":"","description":""} | {"hex":"0x27","decimal":"39","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.816494 | [{"name_or_parameter":"ZYXOR","field_description":"X, Y and Z-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZOR","field_description":"Z-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Z-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YOR","field_description":"Y-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Y-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XOR","field_description":"X-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New X-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZYXDA","field_description":"X, Y and Z-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZDA","field_description":"Z-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New Z-axis data is not yet available."},{"value":"1","value_description":"New Z-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YDA","field_description":"Y-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New Y-axis data is not yet available."},{"value":"1","value_description":"New Y-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XDA","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"XDA","field_description":"X-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YDA","field_description":"Y-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZDA","field_description":"Z-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZYXDA","field_description":"X, Y and Z-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XOR","field_description":"X-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: a new set of data has overwritten the previous set)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YOR","field_description":"Y-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the Y-axis has overwritten the previous data)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZOR","field_description":"Z-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the Z-axis has overwritten the previous data)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZYXOR","field_description":"X, Y and Z-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: a new set of data has overwritten the previous set)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.8)=\mathbf{0.942581}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.942581) = **0.942581**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | STATUS_REG | STATUS_REG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x27","decimal":"39","bank":"","page":"","description":""} | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Reports acceleration-axis data-overrun and new-data availability status. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.942581 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{18})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.9 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.926549/1.0001=\mathbf{0.926456}\).

## Extracted logical register 19: `OUT_X_L`

v12 location: `registers[18]`; truth association: `registers[15]` (`OUT_X_L (28h), OUT_X_H (29h)`).

Associated physical locations: 0x28 (40), 0x29 (41).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_X_L` at 0x28 (40)

Locations: `truth registers[15].field_parts[0]` ↔ `v12 registers[18].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_X_L | OUT_X_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of X-axis acceleration data."} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.000000 | Low byte of X-axis acceleration data. | Low byte of X-axis acceleration data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

#### Field part 2: `OUT_X_H` at 0x29 (41)

Locations: `truth registers[15].field_parts[1]` ↔ `v12 registers[18].field_parts[1]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_X_H | OUT_X_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"High byte of X-axis acceleration data."} | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.000000 | High byte of X-axis acceleration data. | High byte of X-axis acceleration data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 0.500000 | OUT_X_L (28h), OUT_X_H (29h) | OUT_X_L |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of X-axis acceleration data."},{"hex":"0x29","decimal":"41","bank":"","page":"","description":"High byte of X-axis acceleration data."}] | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte"},{"hex":"0x29","decimal":"41","bank":"","page":"","description":"High byte"}] |
| `register_description` | 0.0564 | 0.500000 | X-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO X-axis data when FIFO is active. | X-axis acceleration data. The value is expressed as two's complement left-justified. |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{19})=(0.0225×0.5 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.960650/1.0001=\mathbf{0.960554}\).

## Extracted logical register 20: `OUT_X_H`

v12 location: `registers[19]`; truth association: `registers[15]` (`OUT_X_L (28h), OUT_X_H (29h)`).

Associated physical locations: 0x29 (41).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_X_H` at 0x29 (41)

Locations: `truth registers[15].field_parts[1]` ↔ `v12 registers[19].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_X_H | OUT_X_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"High byte of X-axis acceleration data."} | {"hex":"0x29","decimal":"41","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | High byte of X-axis acceleration data. | High byte of X-axis acceleration data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_X_H | OUT_X_H |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"High byte of X-axis acceleration data."} | [{"hex":"0x29","decimal":"41","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | X-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO X-axis data when FIFO is active. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{20})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.943700/1.0001=\mathbf{0.943606}\).

## Extracted logical register 21: `OUT_Y_L`

v12 location: `registers[20]`; truth association: `registers[16]` (`OUT_Y_L (2Ah), OUT_Y_H (2Bh)`).

Associated physical locations: 0x2A (42), 0x2B (43).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_Y_L` at 0x2A (42)

Locations: `truth registers[16].field_parts[0]` ↔ `v12 registers[20].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Y_L | OUT_Y_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Low byte of Y-axis acceleration data."} | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.000000 | Low byte of Y-axis acceleration data. | Low byte of Y-axis acceleration data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

#### Field part 2: `OUT_Y_H` at 0x2B (43)

Locations: `truth registers[16].field_parts[1]` ↔ `v12 registers[20].field_parts[1]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Y_H | OUT_Y_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"High byte of Y-axis acceleration data."} | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.000000 | High byte of Y-axis acceleration data. | High byte of Y-axis acceleration data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 0.500000 | OUT_Y_L (2Ah), OUT_Y_H (2Bh) | OUT_Y_L |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Low byte of Y-axis acceleration data."},{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"High byte of Y-axis acceleration data."}] | [{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Low byte"},{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"High byte"}] |
| `register_description` | 0.0564 | 0.500000 | Y-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Y-axis data when FIFO is active. | Y-axis acceleration data. The value is expressed as two's complement left-justified. |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{21})=(0.0225×0.5 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.960650/1.0001=\mathbf{0.960554}\).

## Extracted logical register 22: `OUT_Y_H`

v12 location: `registers[21]`; truth association: `registers[16]` (`OUT_Y_L (2Ah), OUT_Y_H (2Bh)`).

Associated physical locations: 0x2B (43).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_Y_H` at 0x2B (43)

Locations: `truth registers[16].field_parts[1]` ↔ `v12 registers[21].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Y_H | OUT_Y_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"High byte of Y-axis acceleration data."} | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | High byte of Y-axis acceleration data. | High byte of Y-axis acceleration data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_Y_H | OUT_Y_H |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"High byte of Y-axis acceleration data."} | [{"hex":"0x2B","decimal":"43","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Y-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Y-axis data when FIFO is active. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{22})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.943700/1.0001=\mathbf{0.943606}\).

## Extracted logical register 23: `OUT_Z_L`

v12 location: `registers[22]`; truth association: `registers[17]` (`OUT_Z_L (2Ch), OUT_Z_H (2Dh)`).

Associated physical locations: 0x2C (44), 0x2D (45).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_Z_L` at 0x2C (44)

Locations: `truth registers[17].field_parts[0]` ↔ `v12 registers[22].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Z_L | OUT_Z_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Low byte of Z-axis acceleration data."} | {"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.000000 | Low byte of Z-axis acceleration data. | Low byte of Z-axis acceleration data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

#### Field part 2: `OUT_Z_H` at 0x2D (45)

Locations: `truth registers[17].field_parts[1]` ↔ `v12 registers[22].field_parts[1]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Z_H | OUT_Z_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"High byte of Z-axis acceleration data."} | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.000000 | High byte of Z-axis acceleration data. | High byte of Z-axis acceleration data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 0.500000 | OUT_Z_L (2Ch), OUT_Z_H (2Dh) | OUT_Z_L |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Low byte of Z-axis acceleration data."},{"hex":"0x2D","decimal":"45","bank":"","page":"","description":"High byte of Z-axis acceleration data."}] | [{"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Low byte"},{"hex":"0x2D","decimal":"45","bank":"","page":"","description":"High byte"}] |
| `register_description` | 0.0564 | 0.500000 | Z-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Z-axis data when FIFO is active. | Z-axis acceleration data. The value is expressed as two's complement left-justified. |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{23})=(0.0225×0.5 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.960650/1.0001=\mathbf{0.960554}\).

## Extracted logical register 24: `OUT_Z_H`

v12 location: `registers[23]`; truth association: `registers[17]` (`OUT_Z_L (2Ch), OUT_Z_H (2Dh)`).

Associated physical locations: 0x2D (45).

### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_Z_H` at 0x2D (45)

Locations: `truth registers[17].field_parts[1]` ↔ `v12 registers[23].field_parts[0]`.


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Z_H | OUT_Z_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"High byte of Z-axis acceleration data."} | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | High byte of Z-axis acceleration data. | High byte of Z-axis acceleration data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_Z_H | OUT_Z_H |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"High byte of Z-axis acceleration data."} | [{"hex":"0x2D","decimal":"45","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.000000 | Z-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Z-axis data when FIFO is active. | "" |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{24})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.943700/1.0001=\mathbf{0.943606}\).

## Extracted logical register 25: `FIFO_CTRL_REG`

v12 location: `registers[24]`; truth association: `registers[18]` (`FIFO_CTRL_REG`).

Associated physical locations: 0x2E (46).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_CTRL_REG` at 0x2E (46)

Locations: `truth registers[18].field_parts[0]` ↔ `v12 registers[24].field_parts[0]`.


**Truth bit field 1: `FM[1:0]` bits 7:6**

Locations: `truth registers[18].field_parts[0].bit_field[0]` ↔ `v12 registers[24].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FM[1:0] | FM[1:0] |
| `field_description` | 0.0586 | 1.0 | FIFO mode selection. | FIFO mode selection. Default value: 00 (00: Bypass; 01: FIFO; 10: Stream; 11: Stream-to-FIFO). Refer to Table 51 for mode details. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"Bypass mode."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Stream-to-FIFO mode."}] | [{"value":"00","value_description":"Bypass mode"},{"value":"01","value_description":"FIFO mode"},{"value":"10","value_description":"Stream mode"},{"value":"11","value_description":"Stream-to-FIFO mode"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Truth bit field 2: `TR` bits 5:5**

Locations: `truth registers[18].field_parts[0].bit_field[1]` ↔ `v12 registers[24].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TR | TR |
| `field_description` | 0.0586 | 0.5 | Trigger selection for Stream-to-FIFO mode. | Trigger selection. Default value: 0 (0: trigger event allows triggering signal on INT1; 1: trigger event allows triggering signal on INT2) |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Triggering signal on INT1."},{"value":"1","value_description":"Triggering signal on INT2."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.760900/0.9999=\mathbf{0.760976}\).


**Truth bit field 3: `FTH[4:0]` bits 4:0**

Locations: `truth registers[18].field_parts[0].bit_field[2]` ↔ `v12 registers[24].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FTH[4:0] | FTH[4:0] |
| `field_description` | 0.0586 | 0.5 | Programmable FIFO watermark threshold. | FIFO threshold level. Default value: 00000. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.970600/0.9999=\mathbf{0.970697}\).


**Field-part aggregation**

`bit_field` correctness = 0.910558.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | FIFO_CTRL_REG | FIFO_CTRL_REG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":""} | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.910558 | [{"name_or_parameter":"FM[1:0]","field_description":"FIFO mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass mode."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Stream-to-FIFO mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TR","field_description":"Trigger selection for Stream-to-FIFO mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Triggering signal on INT1."},{"value":"1","value_description":"Triggering signal on INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FTH[4:0]","field_description":"Programmable FIFO watermark threshold.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"FTH[4:0]","field_description":"FIFO threshold level. Default value: 00000.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TR","field_description":"Trigger selection. Default value: 0 (0: trigger event allows triggering signal on INT1; 1: trigger event allows triggering signal on INT2)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FM[1:0]","field_description":"FIFO mode selection. Default value: 00 (00: Bypass; 01: FIFO; 10: Stream; 11: Stream-to-FIFO). Refer to Table 51 for mode details.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass mode"},{"value":"01","value_description":"FIFO mode"},{"value":"10","value_description":"Stream mode"},{"value":"11","value_description":"Stream-to-FIFO mode"}],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.9)=\mathbf{0.972014}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.972014) = **0.972014**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | FIFO_CTRL_REG | FIFO_CTRL_REG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":""} | [{"hex":"0x2E","decimal":"46","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Selects FIFO operating mode, Stream-to-FIFO trigger source and FIFO watermark threshold. | FIFO mode selection and watermark configuration. FIFO_EN bit in CTRL_REG5 (24h) must be set to '1' to enable the FIFO buffer. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.972014 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{25})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.963540/1.0001=\mathbf{0.963444}\).

## Extracted logical register 26: `FIFO_SRC_REG`

v12 location: `registers[25]`; truth association: `registers[19]` (`FIFO_SRC_REG`).

Associated physical locations: 0x2F (47).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_SRC_REG` at 0x2F (47)

Locations: `truth registers[19].field_parts[0]` ↔ `v12 registers[25].field_parts[0]`.


**Truth bit field 1: `WTM` bits 7:7**

Locations: `truth registers[19].field_parts[0].bit_field[0]` ↔ `v12 registers[25].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WTM | WTM |
| `field_description` | 0.0586 | 1.0 | Set high when FIFO content exceeds the watermark level. | Set high when FIFO content exceeds watermark level. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).


**Truth bit field 2: `OVRN_FIFO` bits 6:6**

Locations: `truth registers[19].field_parts[0].bit_field[1]` ↔ `v12 registers[25].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | OVRN_FIFO | OVRN_FIFO |
| `field_description` | 0.0586 | 1.0 | Set high when the FIFO is full with 32 unread samples; clears when the first sample set is read. | Set high when FIFO buffer is full (32 unread samples). Cleared when the first sample set has been read. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).


**Truth bit field 3: `EMPTY` bits 5:5**

Locations: `truth registers[19].field_parts[0].bit_field[2]` ↔ `v12 registers[25].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | EMPTY | EMPTY |
| `field_description` | 0.0586 | 1.0 | Set high when all FIFO samples have been read and the FIFO is empty. | Flag set high when all FIFO samples have been read and FIFO is empty. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).


**Truth bit field 4: `FSS [4:0]` bits 4:0**

Locations: `truth registers[19].field_parts[0].bit_field[3]` ↔ `v12 registers[25].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FSS [4:0] | FSS[4:0] |
| `field_description` | 0.0586 | 1.0 | Current number of unread sample sets stored in the FIFO. | Current number of unread samples stored in the FIFO buffer. Increases at ODR frequency until full, decreases when sample sets are retrieved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.956271.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | FIFO_SRC_REG | FIFO_SRC_REG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":""} | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.956271 | [{"name_or_parameter":"WTM","field_description":"Set high when FIFO content exceeds the watermark level.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"OVRN_FIFO","field_description":"Set high when the FIFO is full with 32 unread samples; clears when the first sample set is read.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"EMPTY","field_description":"Set high when all FIFO samples have been read and the FIFO is empty.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FSS [4:0]","field_description":"Current number of unread sample sets stored in the FIFO.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"FSS[4:0]","field_description":"Current number of unread samples stored in the FIFO buffer. Increases at ODR frequency until full, decreases when sample sets are retrieved.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"EMPTY","field_description":"Flag set high when all FIFO samples have been read and FIFO is empty.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"OVRN_FIFO","field_description":"Set high when FIFO buffer is full (32 unread samples). Cleared when the first sample set has been read.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"WTM","field_description":"Set high when FIFO content exceeds watermark level.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{0.986317}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.986317) = **0.986317**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | FIFO_SRC_REG | FIFO_SRC_REG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":""} | [{"hex":"0x2F","decimal":"47","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Reports FIFO watermark, overrun, empty status and the number of unread FIFO samples. | FIFO status register. Contains flags indicating FIFO watermark, overrun, and empty conditions. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.986317 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{26})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.967813/1.0001=\mathbf{0.967716}\).

## Extracted logical register 27: `INT1_CFG`

v12 location: `registers[26]`; truth association: `registers[20]` (`INT1_CFG`).

Associated physical locations: 0x30 (48).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT1_CFG` at 0x30 (48)

Locations: `truth registers[20].field_parts[0]` ↔ `v12 registers[26].field_parts[0]`.


**Truth bit field 1: `AOI-6D` bits 7:6**

Locations: `truth registers[20].field_parts[0].bit_field[0]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[20].field_parts[0].bit_field[1]` ↔ `v12 registers[26].field_parts[0].bit_field[5]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZHIE | ZHIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Z high event or direction recognition. | Enable interrupt generation on Z high event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request) |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 3: `ZLIE` bits 4:4**

Locations: `truth registers[20].field_parts[0].bit_field[2]` ↔ `v12 registers[26].field_parts[0].bit_field[4]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZLIE | ZLIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Z low event or direction recognition. | Enable interrupt generation on Z low event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request) |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 4: `YHIE` bits 3:3**

Locations: `truth registers[20].field_parts[0].bit_field[3]` ↔ `v12 registers[26].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YHIE | YHIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Y high event or direction recognition. | Enable interrupt generation on Y high event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 5: `YLIE` bits 2:2**

Locations: `truth registers[20].field_parts[0].bit_field[4]` ↔ `v12 registers[26].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YLIE | YLIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Y low event or direction recognition. | Enable interrupt generation on Y low event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request) |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 6: `XHIE` bits 1:1**

Locations: `truth registers[20].field_parts[0].bit_field[5]` ↔ `v12 registers[26].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XHIE | XHIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on X high event or direction recognition. | Enable interrupt generation on X high event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request) |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 7: `XLIE` bits 0:0**

Locations: `truth registers[20].field_parts[0].bit_field[6]` ↔ `v12 registers[26].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XLIE | XLIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on X low event or direction recognition. | Enable interrupt generation on X low event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

Additional extracted bit field `v12 registers[26].field_parts[0].bit_field[6]` (`6D`, bits 6:6) is not matched to a truth range and receives no credit.

Additional extracted bit field `v12 registers[26].field_parts[0].bit_field[7]` (`AOI`, bits 7:7) is not matched to a truth range and receives no credit.


**Field-part aggregation**

`bit_field` correctness = 0.677382.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT1_CFG | INT1_CFG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x30","decimal":"48","bank":"","page":"","description":""} | {"hex":"0x30","decimal":"48","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.677382 | [{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event or direction recognition.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event or direction recognition.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event or direction recognition.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event or direction recognition.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event or direction recognition.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event or direction recognition.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"6D","field_description":"6-direction detection function enabled. Default value: 0. Refer to Table 56: Interrupt mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"AOI","field_description":"And/Or combination of Interrupt events. Default value: 0. Refer to Table 56: Interrupt mode.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.7)=\mathbf{0.899053}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.899053) = **0.899053**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT1_CFG | INT1_CFG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x30","decimal":"48","bank":"","page":"","description":""} | [{"hex":"0x30","decimal":"48","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Configures interrupt 1 event combination, direction recognition and axis high/low event enables. Its content is loaded at boot, and writing is possible only after system boot. | Interrupt 1 configuration register. Content is loaded at boot. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.899053 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{27})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.9 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.941747/1.0001=\mathbf{0.941653}\).

## Extracted logical register 28: `INT1_SRC`

v12 location: `registers[27]`; truth association: `registers[21]` (`INT1_SRC`).

Associated physical locations: 0x31 (49).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT1_SRC` at 0x31 (49)

Locations: `truth registers[21].field_parts[0]` ↔ `v12 registers[27].field_parts[0]`.


**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[21].field_parts[0].bit_field[0]` ↔ `v12 registers[27].field_parts[0].bit_field[7]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 0 | 0 |
| `field_description` | 0.0586 | 1.0 | "" | "" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Truth bit field 2: `IA` bits 6:6**

Locations: `truth registers[21].field_parts[0].bit_field[1]` ↔ `v12 registers[27].field_parts[0].bit_field[6]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | IA | IA |
| `field_description` | 0.0586 | 1.0 | Interrupt active. | Interrupt active. Default value: 0 (0: no interrupt has been generated; 1: one or more interrupts have been generated) |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 3: `ZH` bits 5:5**

Locations: `truth registers[21].field_parts[0].bit_field[2]` ↔ `v12 registers[27].field_parts[0].bit_field[5]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZH | ZH |
| `field_description` | 0.0586 | 1.0 | Z high event status. | Z high. Default value: 0 (0: no interrupt; 1: Z high event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 4: `ZL` bits 4:4**

Locations: `truth registers[21].field_parts[0].bit_field[3]` ↔ `v12 registers[27].field_parts[0].bit_field[4]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZL | ZL |
| `field_description` | 0.0586 | 1.0 | Z low event status. | Z low. Default value: 0 (0: no interrupt; 1: Z low event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 5: `YH` bits 3:3**

Locations: `truth registers[21].field_parts[0].bit_field[4]` ↔ `v12 registers[27].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YH | YH |
| `field_description` | 0.0586 | 1.0 | Y high event status. | Y high. Default value: 0 (0: no interrupt; 1: Y high event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 6: `YL` bits 2:2**

Locations: `truth registers[21].field_parts[0].bit_field[5]` ↔ `v12 registers[27].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YL | YL |
| `field_description` | 0.0586 | 1.0 | Y low event status. | Y low. Default value: 0 (0: no interrupt; 1: Y low event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 7: `XH` bits 1:1**

Locations: `truth registers[21].field_parts[0].bit_field[6]` ↔ `v12 registers[27].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XH | XH |
| `field_description` | 0.0586 | 1.0 | X high event status. | X high. Default value: 0 (0: no interrupt; 1: X high event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 8: `XL` bits 0:0**

Locations: `truth registers[21].field_parts[0].bit_field[7]` ↔ `v12 registers[27].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XL | XL |
| `field_description` | 0.0586 | 1.0 | X low event status. | X low. Default value: 0 (0: no interrupt; 1: X low event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Field-part aggregation**

`bit_field` correctness = 0.816494.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT1_SRC | INT1_SRC |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x31","decimal":"49","bank":"","page":"","description":""} | {"hex":"0x31","decimal":"49","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.816494 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"XL","field_description":"X low. Default value: 0 (0: no interrupt; 1: X low event has occurred)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high. Default value: 0 (0: no interrupt; 1: X high event has occurred)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low. Default value: 0 (0: no interrupt; 1: Y low event has occurred)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high. Default value: 0 (0: no interrupt; 1: Y high event has occurred)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low. Default value: 0 (0: no interrupt; 1: Z low event has occurred)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high. Default value: 0 (0: no interrupt; 1: Z high event has occurred)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"IA","field_description":"Interrupt active. Default value: 0 (0: no interrupt has been generated; 1: one or more interrupts have been generated)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.8)=\mathbf{0.942581}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.942581) = **0.942581**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT1_SRC | INT1_SRC |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x31","decimal":"49","bank":"","page":"","description":""} | [{"hex":"0x31","decimal":"49","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Reports interrupt 1 source and axis-event status. Reading clears the IA bit and INT1 signal and refreshes latched data. | Interrupt 1 source register. Read-only. Reading clears the IA bit and interrupt signal on INT1 pin. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.942581 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{28})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.9 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.954749/1.0001=\mathbf{0.954653}\).

## Extracted logical register 29: `INT1_THS`

v12 location: `registers[28]`; truth association: `registers[22]` (`INT1_THS`).

Associated physical locations: 0x32 (50).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT1_THS` at 0x32 (50)

Locations: `truth registers[22].field_parts[0]` ↔ `v12 registers[28].field_parts[0]`.


**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[22].field_parts[0].bit_field[0]` ↔ `v12 registers[28].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 0 | 0 |
| `field_description` | 0.0586 | 1.0 | "" | "" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Truth bit field 2: `THS[6:0]` bits 6:0**

Locations: `truth registers[22].field_parts[0].bit_field[1]` ↔ `v12 registers[28].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THS[6:0] | THS[6:0] |
| `field_description` | 0.0586 | 1.0 | Interrupt 1 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g. | Interrupt 1 threshold. Default value: 0000000. 1 LSb = 16 mg @ FS = ±2 g; 32 mg @ ±4 g; 62 mg @ ±8 g; 186 mg @ ±16 g. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT1_THS | INT1_THS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x32","decimal":"50","bank":"","page":"","description":""} | {"hex":"0x32","decimal":"50","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 1 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 1 threshold. Default value: 0000000. 1 LSb = 16 mg @ FS = ±2 g; 32 mg @ ±4 g; 62 mg @ ±8 g; 186 mg @ ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT1_THS | INT1_THS |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x32","decimal":"50","bank":"","page":"","description":""} | [{"hex":"0x32","decimal":"50","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Sets the interrupt 1 acceleration threshold. | Interrupt 1 threshold configuration. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{29})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 30: `INT1_DURATION`

v12 location: `registers[29]`; truth association: `registers[23]` (`INT1_DURATION`).

Associated physical locations: 0x33 (51).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT1_DURATION` at 0x33 (51)

Locations: `truth registers[23].field_parts[0]` ↔ `v12 registers[29].field_parts[0]`.


**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[23].field_parts[0].bit_field[0]` ↔ `v12 registers[29].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 0 | 0 |
| `field_description` | 0.0586 | 1.0 | "" | "" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Truth bit field 2: `D[6:0]` bits 6:0**

Locations: `truth registers[23].field_parts[0].bit_field[1]` ↔ `v12 registers[29].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | D[6:0] | D[6:0] |
| `field_description` | 0.0586 | 1.0 | Duration value; 1 LSb equals 1/ODR. | Duration value. Default value: 0000000. 1 LSb = 1/ODR. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT1_DURATION | INT1_DURATION |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x33","decimal":"51","bank":"","page":"","description":""} | {"hex":"0x33","decimal":"51","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"D[6:0]","field_description":"Duration value. Default value: 0000000. 1 LSb = 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT1_DURATION | INT1_DURATION |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x33","decimal":"51","bank":"","page":"","description":""} | [{"hex":"0x33","decimal":"51","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Sets the minimum interrupt event duration; duration is measured as N/ODR. | Interrupt 1 duration configuration. Duration time is measured in N/ODR, where N is the content of the duration register. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{30})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 31: `INT2_CFG`

v12 location: `registers[30]`; truth association: `registers[24]` (`INT2_CFG`).

Associated physical locations: 0x34 (52).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT2_CFG` at 0x34 (52)

Locations: `truth registers[24].field_parts[0]` ↔ `v12 registers[30].field_parts[0]`.


**Truth bit field 1: `AOI-6D` bits 7:6**

Locations: `truth registers[24].field_parts[0].bit_field[0]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[24].field_parts[0].bit_field[1]` ↔ `v12 registers[30].field_parts[0].bit_field[5]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZHIE | ZHIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Z high event. | Enable interrupt generation on Z high event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold) |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 3: `ZLIE` bits 4:4**

Locations: `truth registers[24].field_parts[0].bit_field[2]` ↔ `v12 registers[30].field_parts[0].bit_field[4]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZLIE | ZLIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Z low event. | Enable interrupt generation on Z low event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value lower than preset threshold) |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 4: `YHIE` bits 3:3**

Locations: `truth registers[24].field_parts[0].bit_field[3]` ↔ `v12 registers[30].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YHIE | YHIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Y high event. | Enable interrupt generation on Y high event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 5: `YLIE` bits 2:2**

Locations: `truth registers[24].field_parts[0].bit_field[4]` ↔ `v12 registers[30].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YLIE | YLIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Y low event. | Enable interrupt generation on Y low event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value lower than preset threshold) |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 6: `XHIE` bits 1:1**

Locations: `truth registers[24].field_parts[0].bit_field[5]` ↔ `v12 registers[30].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XHIE | XHIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on X high event. | Enable interrupt generation on X high event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold) |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 7: `XLIE` bits 0:0**

Locations: `truth registers[24].field_parts[0].bit_field[6]` ↔ `v12 registers[30].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XLIE | XLIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on X low event. | Enable interrupt generation on X low event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value lower than preset threshold) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

Additional extracted bit field `v12 registers[30].field_parts[0].bit_field[6]` (`6D`, bits 6:6) is not matched to a truth range and receives no credit.

Additional extracted bit field `v12 registers[30].field_parts[0].bit_field[7]` (`AOI`, bits 7:7) is not matched to a truth range and receives no credit.


**Field-part aggregation**

`bit_field` correctness = 0.677382.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT2_CFG | INT2_CFG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x34","decimal":"52","bank":"","page":"","description":""} | {"hex":"0x34","decimal":"52","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.677382 | [{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value lower than preset threshold)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value lower than preset threshold)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value lower than preset threshold)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"6D","field_description":"6-direction detection function enabled. Default value: 0. Refer to Table 65: Interrupt mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"AOI","field_description":"AND/OR combination of interrupt events. Default value: 0 (see Table 65).","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.7)=\mathbf{0.899053}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.899053) = **0.899053**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT2_CFG | INT2_CFG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x34","decimal":"52","bank":"","page":"","description":""} | [{"hex":"0x34","decimal":"52","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Configures interrupt 2 event combination, direction recognition and axis high/low event enables. Its content is loaded at boot, and writing is possible only after system boot. | Interrupt 2 configuration register. Content is loaded at boot. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.899053 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{31})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.9 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.941747/1.0001=\mathbf{0.941653}\).

## Extracted logical register 32: `INT2_SRC`

v12 location: `registers[31]`; truth association: `registers[25]` (`INT2_SRC`).

Associated physical locations: 0x35 (53).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT2_SRC` at 0x35 (53)

Locations: `truth registers[25].field_parts[0]` ↔ `v12 registers[31].field_parts[0]`.


**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[25].field_parts[0].bit_field[0]` ↔ `v12 registers[31].field_parts[0].bit_field[7]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 0 | 0 |
| `field_description` | 0.0586 | 1.0 | "" | "" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Truth bit field 2: `IA` bits 6:6**

Locations: `truth registers[25].field_parts[0].bit_field[1]` ↔ `v12 registers[31].field_parts[0].bit_field[6]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | IA | IA |
| `field_description` | 0.0586 | 1.0 | Interrupt active. | Interrupt active. Default value: 0 (0: no interrupt has been generated; 1: one or more interrupts have been generated) |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 3: `ZH` bits 5:5**

Locations: `truth registers[25].field_parts[0].bit_field[2]` ↔ `v12 registers[31].field_parts[0].bit_field[5]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZH | ZH |
| `field_description` | 0.0586 | 1.0 | Z high event status. | Z high. Default value: 0 (0: no interrupt; 1: Z high event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 4: `ZL` bits 4:4**

Locations: `truth registers[25].field_parts[0].bit_field[3]` ↔ `v12 registers[31].field_parts[0].bit_field[4]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZL | ZL |
| `field_description` | 0.0586 | 1.0 | Z low event status. | Z low. Default value: 0 (0: no interrupt; 1: Z low event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 5: `YH` bits 3:3**

Locations: `truth registers[25].field_parts[0].bit_field[4]` ↔ `v12 registers[31].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YH | YH |
| `field_description` | 0.0586 | 1.0 | Y high event status. | Y high. Default value: 0 (0: no interrupt; 1: Y high event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 6: `YL` bits 2:2**

Locations: `truth registers[25].field_parts[0].bit_field[5]` ↔ `v12 registers[31].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YL | YL |
| `field_description` | 0.0586 | 1.0 | Y low event status. | Y low. Default value: 0 (0: no interrupt; 1: Y low event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 7: `XH` bits 1:1**

Locations: `truth registers[25].field_parts[0].bit_field[6]` ↔ `v12 registers[31].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XH | XH |
| `field_description` | 0.0586 | 1.0 | X high event status. | X high. Default value: 0 (0: no interrupt; 1: X high event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 8: `XL` bits 0:0**

Locations: `truth registers[25].field_parts[0].bit_field[7]` ↔ `v12 registers[31].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XL | XL |
| `field_description` | 0.0586 | 1.0 | X low event status. | X low. Default value: 0 (0: no interrupt; 1: X low event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Field-part aggregation**

`bit_field` correctness = 0.816494.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT2_SRC | INT2_SRC |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x35","decimal":"53","bank":"","page":"","description":""} | {"hex":"0x35","decimal":"53","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.816494 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"XL","field_description":"X low. Default value: 0 (0: no interrupt; 1: X low event has occurred)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high. Default value: 0 (0: no interrupt; 1: X high event has occurred)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low. Default value: 0 (0: no interrupt; 1: Y low event has occurred)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high. Default value: 0 (0: no interrupt; 1: Y high event has occurred)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low. Default value: 0 (0: no interrupt; 1: Z low event has occurred)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high. Default value: 0 (0: no interrupt; 1: Z high event has occurred)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"IA","field_description":"Interrupt active. Default value: 0 (0: no interrupt has been generated; 1: one or more interrupts have been generated)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.8)=\mathbf{0.942581}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.942581) = **0.942581**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT2_SRC | INT2_SRC |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x35","decimal":"53","bank":"","page":"","description":""} | [{"hex":"0x35","decimal":"53","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Reports interrupt 2 source and axis-event status. Reading clears the IA bit and INT2 signal and refreshes latched data. | Interrupt 2 source register. Read-only. Reading clears the IA bit and interrupt signal on INT2 pin. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.942581 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{32})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.9 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.954749/1.0001=\mathbf{0.954653}\).

## Extracted logical register 33: `INT2_THS`

v12 location: `registers[32]`; truth association: `registers[26]` (`INT2_THS`).

Associated physical locations: 0x36 (54).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT2_THS` at 0x36 (54)

Locations: `truth registers[26].field_parts[0]` ↔ `v12 registers[32].field_parts[0]`.


**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[26].field_parts[0].bit_field[0]` ↔ `v12 registers[32].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 0 | 0 |
| `field_description` | 0.0586 | 1.0 | "" | "" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Truth bit field 2: `THS[6:0]` bits 6:0**

Locations: `truth registers[26].field_parts[0].bit_field[1]` ↔ `v12 registers[32].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THS[6:0] | THS[6:0] |
| `field_description` | 0.0586 | 1.0 | Interrupt 2 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g. | Interrupt 2 threshold. Default value: 0000000. 1 LSb = 16 mg @ FS = ±2 g; 32 mg @ ±4 g; 62 mg @ ±8 g; 186 mg @ ±16 g. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT2_THS | INT2_THS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x36","decimal":"54","bank":"","page":"","description":""} | {"hex":"0x36","decimal":"54","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 2 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 2 threshold. Default value: 0000000. 1 LSb = 16 mg @ FS = ±2 g; 32 mg @ ±4 g; 62 mg @ ±8 g; 186 mg @ ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT2_THS | INT2_THS |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x36","decimal":"54","bank":"","page":"","description":""} | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Sets the interrupt 2 acceleration threshold. | Interrupt 2 threshold configuration. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{33})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 34: `INT2_DURATION`

v12 location: `registers[33]`; truth association: `registers[27]` (`INT2_DURATION`).

Associated physical locations: 0x37 (55).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT2_DURATION` at 0x37 (55)

Locations: `truth registers[27].field_parts[0]` ↔ `v12 registers[33].field_parts[0]`.


**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[27].field_parts[0].bit_field[0]` ↔ `v12 registers[33].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 0 | 0 |
| `field_description` | 0.0586 | 1.0 | "" | "" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Truth bit field 2: `D[6:0]` bits 6:0**

Locations: `truth registers[27].field_parts[0].bit_field[1]` ↔ `v12 registers[33].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | D[6:0] | D[6:0] |
| `field_description` | 0.0586 | 1.0 | Duration value; 1 LSb equals 1/ODR. | Duration value. Default value: 0000000. 1 LSb = 1/ODR. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT2_DURATION | INT2_DURATION |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x37","decimal":"55","bank":"","page":"","description":""} | {"hex":"0x37","decimal":"55","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"D[6:0]","field_description":"Duration value. Default value: 0000000. 1 LSb = 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT2_DURATION | INT2_DURATION |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x37","decimal":"55","bank":"","page":"","description":""} | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Sets the minimum duration of an interrupt 2 event; duration is measured as N/ODR. | Interrupt 2 duration configuration. Duration time is measured in N/ODR, where N is the content of the duration register. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{34})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 35: `CLICK_CFG`

v12 location: `registers[34]`; truth association: `registers[28]` (`CLICK_CFG`).

Associated physical locations: 0x38 (56).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CLICK_CFG` at 0x38 (56)

Locations: `truth registers[28].field_parts[0]` ↔ `v12 registers[34].field_parts[0]`.


**Truth bit field 1: `--` bits 7:6**

Locations: `truth registers[28].field_parts[0].bit_field[0]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[28].field_parts[0].bit_field[1]` ↔ `v12 registers[34].field_parts[0].bit_field[4]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZD | YD |
| `field_description` | 0.0586 | 1.0 | Enable double-click interrupt on Z-axis. | Enable interrupt double click on Y-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold) |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×0.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.769000/0.9999=\mathbf{0.769077}\).


**Truth bit field 3: `ZS` bits 4:4**

Locations: `truth registers[28].field_parts[0].bit_field[2]` ↔ `v12 registers[34].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ZS | YS |
| `field_description` | 0.0586 | 1.0 | Enable single-click interrupt on Z-axis. | Enable interrupt single click on Y-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold) |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×0.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.769000/0.9999=\mathbf{0.769077}\).


**Truth bit field 4: `YD` bits 3:3**

Locations: `truth registers[28].field_parts[0].bit_field[3]` ↔ `v12 registers[34].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YD | XD |
| `field_description` | 0.0586 | 0.0 | Enable double-click interrupt on Y-axis. | Enable interrupt double click on X-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.710400/0.9999=\mathbf{0.710471}\).


**Truth bit field 5: `YS` bits 2:2**

Locations: `truth registers[28].field_parts[0].bit_field[4]` ↔ `v12 registers[34].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | YS | XS |
| `field_description` | 0.0586 | 0.0 | Enable single-click interrupt on Y-axis. | Enable interrupt single click on X-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold) |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.710400/0.9999=\mathbf{0.710471}\).


**Truth bit field 6: `XD` bits 1:1**

Locations: `truth registers[28].field_parts[0].bit_field[5]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[28].field_parts[0].bit_field[6]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Additional extracted bit field `v12 registers[34].field_parts[0].bit_field[0]` (`--`, bits 1:0) is not matched to a truth range and receives no credit.

Additional extracted bit field `v12 registers[34].field_parts[0].bit_field[5]` (`ZS`, bits 6:6) is not matched to a truth range and receives no credit.

Additional extracted bit field `v12 registers[34].field_parts[0].bit_field[6]` (`ZD`, bits 7:7) is not matched to a truth range and receives no credit.


**Field-part aggregation**

`bit_field` correctness = 0.422728.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CLICK_CFG | CLICK_CFG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x38","decimal":"56","bank":"","page":"","description":""} | {"hex":"0x38","decimal":"56","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.422728 | [{"name_or_parameter":"--","field_description":"","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"ZD","field_description":"Enable double-click interrupt on Z-axis.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZS","field_description":"Enable single-click interrupt on Z-axis.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YD","field_description":"Enable double-click interrupt on Y-axis.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YS","field_description":"Enable single-click interrupt on Y-axis.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XD","field_description":"Enable double-click interrupt on X-axis.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XS","field_description":"Enable single-click interrupt on X-axis.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"XS","field_description":"Enable interrupt single click on X-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XD","field_description":"Enable interrupt double click on X-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YS","field_description":"Enable interrupt single click on Y-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YD","field_description":"Enable interrupt double click on Y-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZS","field_description":"Enable interrupt single click on Z-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZD","field_description":"Enable interrupt double click on Z-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.4)=\mathbf{0.819372}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.819372) = **0.819372**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CLICK_CFG | CLICK_CFG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x38","decimal":"56","bank":"","page":"","description":""} | [{"hex":"0x38","decimal":"56","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Enables single-click and double-click interrupt detection for the X, Y and Z axes. | Click interrupt configuration. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.819372 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{35})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.8 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.917946/1.0001=\mathbf{0.917855}\).

## Extracted logical register 36: `CLICK_SRC`

v12 location: `registers[35]`; truth association: `registers[29]` (`CLICK_SRC`).

Associated physical locations: 0x39 (57).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CLICK_SRC` at 0x39 (57)

Locations: `truth registers[29].field_parts[0]` ↔ `v12 registers[35].field_parts[0]`.


**Truth bit field 1: `""` bits 7:7**

Locations: `truth registers[29].field_parts[0].bit_field[0]` ↔ `v12 registers[35].field_parts[0].bit_field[7]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "" | "" |
| `field_description` | 0.0586 | 1.0 | "" | "" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Truth bit field 2: `IA` bits 6:6**

Locations: `truth registers[29].field_parts[0].bit_field[1]` ↔ `v12 registers[35].field_parts[0].bit_field[6]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | IA | IA |
| `field_description` | 0.0586 | 1.0 | Interrupt active. | Interrupt active. Default value: 0 (0: no interrupt has been generated; 1: one or more interrupts have been generated) |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).


**Truth bit field 3: `DCLICK` bits 5:5**

Locations: `truth registers[29].field_parts[0].bit_field[2]` ↔ `v12 registers[35].field_parts[0].bit_field[5]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DCLICK | DCLICK |
| `field_description` | 0.0586 | 1.0 | Double-click enable. | Double-click enable. Default value: 0 (0: double-click detection disabled, 1: double-click detection enabled) |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Double-click detection disabled."},{"value":"1","value_description":"Double-click detection enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.731900/0.9999=\mathbf{0.731973}\).


**Truth bit field 4: `SCLICK` bits 4:4**

Locations: `truth registers[29].field_parts[0].bit_field[3]` ↔ `v12 registers[35].field_parts[0].bit_field[4]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SCLICK | SCLICK |
| `field_description` | 0.0586 | 1.0 | Single-click enable. | Single-click enable. Default value: 0 (0: Single-click detection disabled, 1: single-click detection enabled) |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Single-click detection disabled."},{"value":"1","value_description":"Single-click detection enabled."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.731900/0.9999=\mathbf{0.731973}\).


**Truth bit field 5: `Sign` bits 3:3**

Locations: `truth registers[29].field_parts[0].bit_field[4]` ↔ `v12 registers[35].field_parts[0].bit_field[3]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Sign | Sign |
| `field_description` | 0.0586 | 1.0 | Click sign. | Click sign (0: positive detection, 1: negative detection) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Positive detection."},{"value":"1","value_description":"Negative detection."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.731900/0.9999=\mathbf{0.731973}\).


**Truth bit field 6: `Z` bits 2:2**

Locations: `truth registers[29].field_parts[0].bit_field[5]` ↔ `v12 registers[35].field_parts[0].bit_field[2]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Z | Z |
| `field_description` | 0.0586 | 1.0 | Z click detection. | Z click detection. Default value: 0 (0: no interrupt, 1: Z high event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.731900/0.9999=\mathbf{0.731973}\).


**Truth bit field 7: `Y` bits 1:1**

Locations: `truth registers[29].field_parts[0].bit_field[6]` ↔ `v12 registers[35].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Y | Y |
| `field_description` | 0.0586 | 1.0 | Y click detection. | Y click detection. Default value: 0 (0: no interrupt, 1: Y high event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.731900/0.9999=\mathbf{0.731973}\).


**Truth bit field 8: `X` bits 0:0**

Locations: `truth registers[29].field_parts[0].bit_field[7]` ↔ `v12 registers[35].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | X | X |
| `field_description` | 0.0586 | 1.0 | X click detection. | X click detection. Default value: 0 (0: no interrupt, 1: X high event has occurred) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.731900/0.9999=\mathbf{0.731973}\).


**Field-part aggregation**

`bit_field` correctness = 0.772765.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CLICK_SRC | CLICK_SRC |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x39","decimal":"57","bank":"","page":"","description":""} | {"hex":"0x39","decimal":"57","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.772765 | [{"name_or_parameter":"","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"DCLICK","field_description":"Double-click enable.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Double-click detection disabled."},{"value":"1","value_description":"Double-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SCLICK","field_description":"Single-click enable.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Single-click detection disabled."},{"value":"1","value_description":"Single-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Sign","field_description":"Click sign.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Positive detection."},{"value":"1","value_description":"Negative detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Z","field_description":"Z click detection.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Y","field_description":"Y click detection.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"X","field_description":"X click detection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"X","field_description":"X click detection. Default value: 0 (0: no interrupt, 1: X high event has occurred)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Y","field_description":"Y click detection. Default value: 0 (0: no interrupt, 1: Y high event has occurred)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Z","field_description":"Z click detection. Default value: 0 (0: no interrupt, 1: Z high event has occurred)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Sign","field_description":"Click sign (0: positive detection, 1: negative detection)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"SCLICK","field_description":"Single-click enable. Default value: 0 (0: Single-click detection disabled, 1: single-click detection enabled)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"DCLICK","field_description":"Double-click enable. Default value: 0 (0: double-click detection disabled, 1: double-click detection enabled)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"IA","field_description":"Interrupt active. Default value: 0 (0: no interrupt has been generated; 1: one or more interrupts have been generated)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.8)=\mathbf{0.928898}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.928898) = **0.928898**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CLICK_SRC | CLICK_SRC |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x39","decimal":"57","bank":"","page":"","description":""} | [{"hex":"0x39","decimal":"57","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Reports click-interrupt activity, single/double-click detection, sign and detected axis. | Click interrupt source register. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.928898 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{36})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.9 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.950662/1.0001=\mathbf{0.950567}\).

## Extracted logical register 37: `CLICK_THS`

v12 location: `registers[36]`; truth association: `registers[30]` (`CLICK_THS`).

Associated physical locations: 0x3A (58).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CLICK_THS` at 0x3A (58)

Locations: `truth registers[30].field_parts[0]` ↔ `v12 registers[36].field_parts[0]`.


**Truth bit field 1: `LIR_Click` bits 7:7**

Locations: `truth registers[30].field_parts[0].bit_field[0]` ↔ `v12 registers[36].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LIR_Click | LIR_Click |
| `field_description` | 0.0586 | 0.5 | Controls click-interrupt latching. | If the LIR_Click bit is not set, the interrupt is kept high for the duration of the latency window. If the LIR_Click bit is set, the interrupt is kept high until the CLICK_SRC (39h) register is read. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.760900/0.9999=\mathbf{0.760976}\).


**Truth bit field 2: `Ths[6:0]` bits 6:0**

Locations: `truth registers[30].field_parts[0].bit_field[1]` ↔ `v12 registers[36].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Ths[6:0] | Ths[6:0] |
| `field_description` | 0.0586 | 1.0 | Click threshold. | Click threshold. Default value: 0000000 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Field-part aggregation**

`bit_field` correctness = 0.880488.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CLICK_THS | CLICK_THS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":""} | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.880488 | [{"name_or_parameter":"LIR_Click","field_description":"Controls click-interrupt latching.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Ths[6:0]","field_description":"Click threshold.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"Ths[6:0]","field_description":"Click threshold. Default value: 0000000","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_Click","field_description":"If the LIR_Click bit is not set, the interrupt is kept high for the duration of the latency window. If the LIR_Click bit is set, the interrupt is kept high until the CLICK_SRC (39h) register is read.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.9)=\mathbf{0.962605}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.962605) = **0.962605**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CLICK_THS | CLICK_THS |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":""} | [{"hex":"0x3A","decimal":"58","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Sets the click threshold and click-interrupt latch behavior. | Click threshold configuration. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.962605 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{37})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.960730/1.0001=\mathbf{0.960634}\).

## Extracted logical register 38: `TIME_LIMIT`

v12 location: `registers[37]`; truth association: `registers[31]` (`TIME_LIMIT`).

Associated physical locations: 0x3B (59).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_LIMIT` at 0x3B (59)

Locations: `truth registers[31].field_parts[0]` ↔ `v12 registers[37].field_parts[0]`.


**Truth bit field 1: `-` bits 7:7**

Locations: `truth registers[31].field_parts[0].bit_field[0]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[31].field_parts[0].bit_field[1]` ↔ `v12 registers[37].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TLI[6:0] | TLI[6:0] |
| `field_description` | 0.0586 | 1.0 | Click time limit. | Click time limit. Default value: 0000000 |
| `bit_start` | 0.2594 | 0.0 | 0 | 1 |
| `bit_end` | 0.2594 | 0.0 | 6 | 7 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.481100/0.9999=\mathbf{0.481148}\).

Additional extracted bit field `v12 registers[37].field_parts[0].bit_field[0]` (`-`, bits 0:0) is not matched to a truth range and receives no credit.


**Field-part aggregation**

`bit_field` correctness = 0.240574.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TIME_LIMIT | TIME_LIMIT |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":""} | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.240574 | [{"name_or_parameter":"-","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"TLI[6:0]","field_description":"Click time limit.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"TLI[6:0]","field_description":"Click time limit. Default value: 0000000","bit_start":1,"bit_end":7,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.2)=\mathbf{0.762376}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.762376) = **0.762376**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TIME_LIMIT | TIME_LIMIT |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":""} | [{"hex":"0x3B","decimal":"59","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Sets the click time limit. | Click time limit configuration. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.762376 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{38})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.8 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.900922/1.0001=\mathbf{0.900832}\).

## Extracted logical register 39: `TIME_LATENCY`

v12 location: `registers[38]`; truth association: `registers[32]` (`TIME_LATENCY`).

Associated physical locations: 0x3C (60).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_LATENCY` at 0x3C (60)

Locations: `truth registers[32].field_parts[0]` ↔ `v12 registers[38].field_parts[0]`.


**Truth bit field 1: `TLA[7:0]` bits 7:0**

Locations: `truth registers[32].field_parts[0].bit_field[0]` ↔ `v12 registers[38].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TLA[7:0] | TLA[7:0] |
| `field_description` | 0.0586 | 1.0 | Click time latency. | Click time latency. Default value: 00000000 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TIME_LATENCY | TIME_LATENCY |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":""} | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | {"name_or_parameter":"TLA[7:0]","field_description":"Click time latency.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [{"name_or_parameter":"TLA[7:0]","field_description":"Click time latency. Default value: 00000000","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TIME_LATENCY | TIME_LATENCY |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":""} | [{"hex":"0x3C","decimal":"60","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Sets the click time latency. | Click time latency configuration. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{39})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 40: `TIME_WINDOW`

v12 location: `registers[39]`; truth association: `registers[33]` (`TIME_WINDOW`).

Associated physical locations: 0x3D (61).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_WINDOW` at 0x3D (61)

Locations: `truth registers[33].field_parts[0]` ↔ `v12 registers[39].field_parts[0]`.


**Truth bit field 1: `TW[7:0]` bits 7:0**

Locations: `truth registers[33].field_parts[0].bit_field[0]` ↔ `v12 registers[39].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TW[7:0] | TW[7:0] |
| `field_description` | 0.0586 | 1.0 | Click time window. | Click time window. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TIME_WINDOW | TIME_WINDOW |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":""} | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | {"name_or_parameter":"TW[7:0]","field_description":"Click time window.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [{"name_or_parameter":"TW[7:0]","field_description":"Click time window.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TIME_WINDOW | TIME_WINDOW |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":""} | [{"hex":"0x3D","decimal":"61","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Sets the click time window. | Click time window configuration. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 0.000000 | 00000000 | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{40})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×0.0 + 0.0334×1.0)/1.0001=0.905200/1.0001=\mathbf{0.905109}\).

## Extracted logical register 41: `ACT_THS`

v12 location: `registers[40]`; truth association: `registers[34]` (`ACT_THS`).

Associated physical locations: 0x3E (62).

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACT_THS` at 0x3E (62)

Locations: `truth registers[34].field_parts[0]` ↔ `v12 registers[40].field_parts[0]`.


**Truth bit field 1: `--` bits 7:7**

Locations: `truth registers[34].field_parts[0].bit_field[0]` ↔ `missing`.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[34].field_parts[0].bit_field[1]` ↔ `v12 registers[40].field_parts[0].bit_field[1]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Acth[6:0] | Acth[6:0] |
| `field_description` | 0.0586 | 1.0 | Sleep-to-wake and return-to-sleep activation threshold in low-power mode. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g. | Sleep-to-wake, return-to-sleep activation threshold in low-power mode. 1 LSb = 16 mg @ FS = ±2 g; 32 mg @ ±4 g; 62 mg @ ±8 g; 186 mg @ ±16 g. |
| `bit_start` | 0.2594 | 0.0 | 0 | 2 |
| `bit_end` | 0.2594 | 0.0 | 6 | 7 |
| `bit_width` | 0.0583 | 0.0 | 7 | 6 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.422800/0.9999=\mathbf{0.422842}\).

Additional extracted bit field `v12 registers[40].field_parts[0].bit_field[0]` (`--`, bits 1:0) is not matched to a truth range and receives no credit.


**Field-part aggregation**

`bit_field` correctness = 0.211421.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACT_THS | ACT_THS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":""} | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.211421 | [{"name_or_parameter":"--","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Acth[6:0]","field_description":"Sleep-to-wake and return-to-sleep activation threshold in low-power mode. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Acth[6:0]","field_description":"Sleep-to-wake, return-to-sleep activation threshold in low-power mode. 1 LSb = 16 mg @ FS = ±2 g; 32 mg @ ±4 g; 62 mg @ ±8 g; 186 mg @ ±16 g.","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.2)=\mathbf{0.753254}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.753254) = **0.753254**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACT_THS | ACT_THS |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":""} | [{"hex":"0x3E","decimal":"62","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 0.500000 | Sets the sleep-to-wake and return-to-sleep activation threshold in low-power mode. | Sleep-to-wake and return-to-sleep activation threshold configuration. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.753254 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{41})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×0.5 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.8 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.898197/1.0001=\mathbf{0.898107}\).

## Extracted logical register 42: `ACT_DUR`

v12 location: `registers[41]`; truth association: `registers[35]` (`ACT_DUR`).

Associated physical locations: 0x3F (63).

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACT_DUR` at 0x3F (63)

Locations: `truth registers[35].field_parts[0]` ↔ `v12 registers[41].field_parts[0]`.


**Truth bit field 1: `ActD[7:0]` bits 7:0**

Locations: `truth registers[35].field_parts[0].bit_field[0]` ↔ `v12 registers[41].field_parts[0].bit_field[0]`.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ActD[7:0] | ActD[7:0] |
| `field_description` | 0.0586 | 1.0 | Sleep-to-wake and return-to-sleep duration; 1 LSb = (8*1[LSb]+1)/ODR. | Sleep-to-wake, return-to-sleep duration. 1 LSb = (8*1[LSb]+1)/ODR. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).


**Field-part aggregation**

`bit_field` correctness = 1.000000.

| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACT_DUR | ACT_DUR |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3F","decimal":"63","bank":"","page":"","description":""} | {"hex":"0x3F","decimal":"63","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | "" | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | {"name_or_parameter":"ActD[7:0]","field_description":"Sleep-to-wake and return-to-sleep duration; 1 LSb = (8*1[LSb]+1)/ODR.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [{"name_or_parameter":"ActD[7:0]","field_description":"Sleep-to-wake, return-to-sleep duration. 1 LSb = (8*1[LSb]+1)/ODR.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.0)=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACT_DUR | ACT_DUR |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3F","decimal":"63","bank":"","page":"","description":""} | [{"hex":"0x3F","decimal":"63","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Sets the sleep-to-wake and return-to-sleep duration. | Sleep-to-wake and return-to-sleep duration configuration. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{42})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.0 + 0.0667×1.0 + 0.0334×1.0)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).


## 2. Ground-truth physical-register scores

| Physical address | Associated extracted logical registers | q_R |
|---|---|---:|
| 0x07 (7) | v12 registers[0] `STATUS_REG_AUX`=0.924006 | 0.924006 |
| 0x08 (8) | v12 registers[1] `OUT_ADC1_L`=0.960554 | 0.960554 |
| 0x09 (9) | v12 registers[1] `OUT_ADC1_L`=0.960554; v12 registers[2] `OUT_ADC1_H`=0.943606 | 0.952080 |
| 0x0A (10) | v12 registers[3] `OUT_ADC2_L`=0.960554 | 0.960554 |
| 0x0B (11) | v12 registers[3] `OUT_ADC2_L`=0.960554; v12 registers[4] `OUT_ADC2_H`=0.943606 | 0.952080 |
| 0x0C (12) | v12 registers[5] `OUT_ADC3_L`=0.960554 | 0.960554 |
| 0x0D (13) | v12 registers[5] `OUT_ADC3_L`=0.960554; v12 registers[6] `OUT_ADC3_H`=0.943606 | 0.952080 |
| 0x0F (15) | v12 registers[7] `WHO_AM_I`=0.906546 | 0.906546 |
| 0x1E (30) | v12 registers[8] `CTRL_REG0`=0.853322 | 0.853322 |
| 0x1F (31) | v12 registers[9] `TEMP_CFG_REG`=0.899388 | 0.899388 |
| 0x20 (32) | v12 registers[10] `CTRL_REG1`=0.923459 | 0.923459 |
| 0x21 (33) | v12 registers[11] `CTRL_REG2`=0.927273 | 0.927273 |
| 0x22 (34) | v12 registers[12] `CTRL_REG3`=0.921076 | 0.921076 |
| 0x23 (35) | v12 registers[13] `CTRL_REG4`=0.924006 | 0.924006 |
| 0x24 (36) | v12 registers[14] `CTRL_REG5`=0.931628 | 0.931628 |
| 0x25 (37) | v12 registers[15] `CTRL_REG6`=0.867220 | 0.867220 |
| 0x26 (38) | v12 registers[16] `REFERENCE`=0.938157 | 0.938157 |
| 0x27 (39) | v12 registers[17] `STATUS_REG`=0.926456 | 0.926456 |
| 0x28 (40) | v12 registers[18] `OUT_X_L`=0.960554 | 0.960554 |
| 0x29 (41) | v12 registers[18] `OUT_X_L`=0.960554; v12 registers[19] `OUT_X_H`=0.943606 | 0.952080 |
| 0x2A (42) | v12 registers[20] `OUT_Y_L`=0.960554 | 0.960554 |
| 0x2B (43) | v12 registers[20] `OUT_Y_L`=0.960554; v12 registers[21] `OUT_Y_H`=0.943606 | 0.952080 |
| 0x2C (44) | v12 registers[22] `OUT_Z_L`=0.960554 | 0.960554 |
| 0x2D (45) | v12 registers[22] `OUT_Z_L`=0.960554; v12 registers[23] `OUT_Z_H`=0.943606 | 0.952080 |
| 0x2E (46) | v12 registers[24] `FIFO_CTRL_REG`=0.963444 | 0.963444 |
| 0x2F (47) | v12 registers[25] `FIFO_SRC_REG`=0.967716 | 0.967716 |
| 0x30 (48) | v12 registers[26] `INT1_CFG`=0.941653 | 0.941653 |
| 0x31 (49) | v12 registers[27] `INT1_SRC`=0.954653 | 0.954653 |
| 0x32 (50) | v12 registers[28] `INT1_THS`=0.971803 | 0.971803 |
| 0x33 (51) | v12 registers[29] `INT1_DURATION`=0.971803 | 0.971803 |
| 0x34 (52) | v12 registers[30] `INT2_CFG`=0.941653 | 0.941653 |
| 0x35 (53) | v12 registers[31] `INT2_SRC`=0.954653 | 0.954653 |
| 0x36 (54) | v12 registers[32] `INT2_THS`=0.971803 | 0.971803 |
| 0x37 (55) | v12 registers[33] `INT2_DURATION`=0.971803 | 0.971803 |
| 0x38 (56) | v12 registers[34] `CLICK_CFG`=0.917855 | 0.917855 |
| 0x39 (57) | v12 registers[35] `CLICK_SRC`=0.950567 | 0.950567 |
| 0x3A (58) | v12 registers[36] `CLICK_THS`=0.960634 | 0.960634 |
| 0x3B (59) | v12 registers[37] `TIME_LIMIT`=0.900832 | 0.900832 |
| 0x3C (60) | v12 registers[38] `TIME_LATENCY`=0.971803 | 0.971803 |
| 0x3D (61) | v12 registers[39] `TIME_WINDOW`=0.905109 | 0.905109 |
| 0x3E (62) | v12 registers[40] `ACT_THS`=0.898107 | 0.898107 |
| 0x3F (63) | v12 registers[41] `ACT_DUR`=1.000000 | 1.000000 |

`Σq_R = 39.534231638`, `n=42`, `m=42`, `x=0`.

\(S_{raw}=(10/42)×39.534231638=\mathbf{9.412912295}.\)

\(S_{final}=S_{raw}×m/(m+x)= 9.412912295×42/(42+0)=\mathbf{9.412912295}/10.\)


## 3. Detailed deduction inventory

Matched truth physical locations: `42/42`; missing: `0`; extra extracted physical locations x=`0`.


| Location | Field | C | Truth content | Extracted content | Exact deduction reason |
|---|---|---:|---|---|---|
| `truth registers[0].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}] | [] | field differs or is incomplete |
| `truth registers[0].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 3-axis has overwritten the previous data."}] | [] | field differs or is incomplete |
| `truth registers[0].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 2-axis has overwritten the previous data."}] | [] | field differs or is incomplete |
| `truth registers[0].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 1-axis has overwritten the previous data."}] | [] | field differs or is incomplete |
| `truth registers[0].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}] | [] | field differs or is incomplete |
| `truth registers[0].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"New data for the 3-axis is not yet available."},{"value":"1","value_description":"New data for the 3-axis is available."}] | [] | field differs or is incomplete |
| `truth registers[0].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"New data for the 2-axis is not yet available."},{"value":"1","value_description":"New data for the 2-axis is available."}] | [] | field differs or is incomplete |
| `truth registers[0].field_parts[0].bit_field[7]` | `values` | 0.0 | [{"value":"0","value_description":"New data for the 1-axis is not yet available."},{"value":"1","value_description":"New data for the 1-axis is available."}] | [] | field differs or is incomplete |
| `v12 registers[0].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"321OR","field_description":"1, 2 and 3-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3OR","field_description":"3-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 3-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2OR","field_description":"2-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 2-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1OR","field_description":"1-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 1-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"321DA","field_description":"1, 2 and 3-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3DA","field_description":"3-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 3-axis is not yet available."},{"value":"1","value_description":"New data for the 3-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2DA","field_description":"2-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 2-axis is not yet available."},{"value":"1","value_description":"New data for the 2-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1DA","field_description":"1-axis new data available.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 1-axis is not yet available."},{"value":"1","value_description":"New data for the 1-axis is available."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"1DA","field_description":"1-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2DA","field_description":"2-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3DA","field_description":"3-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"321DA","field_description":"1, 2 and 3-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1OR","field_description":"1-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the 1-axis has overwritten the previous data)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2OR","field_description":"2-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the 2-axis has overwritten the previous data)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3OR","field_description":"3-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the 3-axis has overwritten the previous data)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"321OR","field_description":"1, 2 and 3-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: a new set of data has overwritten the previous set)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] | field differs or is incomplete |
| `v12 registers[0]` | `register_description` | 0.0 | Reports auxiliary ADC data-overrun and new-data availability status. | "" | field differs or is incomplete |
| `v12 registers[0]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v12 registers[1]` | `name` | 0.5 | OUT_ADC1_L (08h), OUT_ADC1_H (09h) | OUT_ADC1_L | field differs or is incomplete |
| `v12 registers[1]` | `register_description` | 0.5 | Auxiliary 10-bit ADC channel 1 conversion, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 1 conversion. | field differs or is incomplete |
| `v12 registers[2]` | `register_description` | 0.0 | Auxiliary 10-bit ADC channel 1 conversion, expressed in 2's complement left-aligned format. | "" | field differs or is incomplete |
| `v12 registers[3]` | `name` | 0.5 | OUT_ADC2_L (0Ah), OUT_ADC2_H (0Bh) | OUT_ADC2_L | field differs or is incomplete |
| `v12 registers[3]` | `register_description` | 0.5 | Auxiliary 10-bit ADC channel 2 conversion, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 2 conversion. | field differs or is incomplete |
| `v12 registers[4]` | `register_description` | 0.0 | Auxiliary 10-bit ADC channel 2 conversion, expressed in 2's complement left-aligned format. | "" | field differs or is incomplete |
| `v12 registers[5]` | `name` | 0.5 | OUT_ADC3_L (0Ch), OUT_ADC3_H (0Dh) | OUT_ADC3_L | field differs or is incomplete |
| `v12 registers[5]` | `register_description` | 0.5 | Auxiliary 10-bit ADC channel 3 conversion or temperature-sensor data output, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 3 conversion or temperature sensor data output. | field differs or is incomplete |
| `v12 registers[6]` | `register_description` | 0.0 | Auxiliary 10-bit ADC channel 3 conversion or temperature-sensor data output, expressed in 2's complement left-aligned format. | "" | field differs or is incomplete |
| `v12 registers[7].field_parts[0]` | `bit_field` | 0.0 | [] | [{"name_or_parameter":"Device ID","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"00110011","value_description":"Default device identification value"}],"is_reserved":false,"type_write_read":"R"}] | field differs or is incomplete |
| `v12 registers[7].field_parts[0].bit_field[0]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"Device ID","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"00110011","value_description":"Default device identification value"}],"is_reserved":false,"type_write_read":"R"} | extra/invented bit field |
| `v12 registers[7]` | `field_parts` | 0.7 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[5].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | 2 | field differs or is incomplete |
| `truth registers[5].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | 2 | field differs or is incomplete |
| `truth registers[5].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":0,"value_description":"SDO/SA0 internal pull-up connected."},{"value":1,"value_description":"SDO/SA0 internal pull-up disconnected."}] | [] | field differs or is incomplete |
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
| `v12 registers[8].field_parts[0]` | `bit_field` | 0.0 | [{"name_or_parameter":"SDO_PU_DISC","field_description":"Disconnect SDO/SA0 pull-up.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":0,"value_description":"SDO/SA0 internal pull-up connected."},{"value":1,"value_description":"SDO/SA0 internal pull-up disconnected."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"bit6","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":6,"bit_end":6,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit5","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":5,"bit_end":5,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit4","field_description":"This bit must be set to 1 for correct operation of the device.","bit_start":4,"bit_end":4,"bit_width":1,"values":{"value":1,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit3","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":3,"bit_end":3,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit2","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":2,"bit_end":2,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit1","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":1,"bit_end":1,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit0","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":0,"bit_end":0,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""}] | [{"name_or_parameter":"SDO_PU_DISC","field_description":"Disconnect SDO/SA0 pull-up. Default value: 0 (0: pull-up connected to SDO/SA0 pin; 1: pull-up disconnected to SDO/SA0 pin)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[8]` | `register_description` | 0.0 | Controls disconnection of the internal SDO/SA0 pull-up. | "" | field differs or is incomplete |
| `v12 registers[8]` | `field_parts` | 0.7 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[6].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"ADC disabled."},{"value":"1","value_description":"ADC enabled."}] | [] | field differs or is incomplete |
| `truth registers[6].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Temperature sensor disabled."},{"value":"1","value_description":"Temperature sensor enabled."}] | [] | field differs or is incomplete |
| `truth registers[6].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `bit_start` | 0.0 | 0 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `bit_width` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[6].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `v12 registers[9].field_parts[0]` | `bit_field` | 0.5 | [{"name_or_parameter":"ADC_EN","field_description":"ADC enable.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"ADC disabled."},{"value":"1","value_description":"ADC enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TEMP_EN","field_description":"Temperature sensor enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Temperature sensor disabled."},{"value":"1","value_description":"Temperature sensor enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"0","field_description":"","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"ADC_EN","field_description":"ADC enable. Default value: 0 (0: ADC disabled; 1: ADC enabled)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TEMP_EN","field_description":"Temperature sensor (T) enable. Default value: 0 (0: T disabled; 1: T enabled)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[9]` | `register_description` | 0.0 | Enables the auxiliary ADC and temperature sensor. | "" | field differs or is incomplete |
| `v12 registers[9]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[7].field_parts[0].bit_field[0]` | `field_description` | 0.5 | Data-rate and power-mode selection. | Data rate selection. Default value: 0111 (Refer to Table 32: Data rate configuration for ODR mappings). | field differs or is incomplete |
| `truth registers[7].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}] | [] | field differs or is incomplete |
| `truth registers[7].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"High-resolution mode / normal mode."},{"value":"1","value_description":"Low-power mode."}] | [] | field differs or is incomplete |
| `truth registers[7].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Z-axis disabled."},{"value":"1","value_description":"Z-axis enabled."}] | [] | field differs or is incomplete |
| `truth registers[7].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Y-axis disabled."},{"value":"1","value_description":"Y-axis enabled."}] | [] | field differs or is incomplete |
| `truth registers[7].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"X-axis disabled."},{"value":"1","value_description":"X-axis enabled."}] | [] | field differs or is incomplete |
| `v12 registers[10].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"ODR[3:0]","field_description":"Data-rate and power-mode selection.","bit_start":4,"bit_end":7,"bit_width":4,"values":[{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LPen","field_description":"Low-power mode enable.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution mode / normal mode."},{"value":"1","value_description":"Low-power mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Zen","field_description":"Z-axis enable.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Z-axis disabled."},{"value":"1","value_description":"Z-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Yen","field_description":"Y-axis enable.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Y-axis disabled."},{"value":"1","value_description":"Y-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Xen","field_description":"X-axis enable.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"X-axis disabled."},{"value":"1","value_description":"X-axis enabled."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"Xen","field_description":"X-axis enable. Default value: 1 (0: X-axis disabled; 1: X-axis enabled)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Yen","field_description":"Y-axis enable. Default value: 1 (0: Y-axis disabled; 1: Y-axis enabled)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Zen","field_description":"Z-axis enable. Default value: 1 (0: Z-axis disabled; 1: Z-axis enabled)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LPen","field_description":"Low-power mode enable. Default value: 0 (0: high-resolution mode / normal mode, 1: low-power mode). Refer to Section 3.2.1: High-resolution, normal mode, low-power mode.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ODR[3:0]","field_description":"Data rate selection. Default value: 0111 (Refer to Table 32: Data rate configuration for ODR mappings).","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[10]` | `register_description` | 0.0 | Selects output data rate and power mode and enables the X, Y and Z axes. | "" | field differs or is incomplete |
| `v12 registers[10]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[8].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"00","value_description":"Normal mode, reset by reading REFERENCE (26h)."},{"value":"01","value_description":"Reference signal for filtering."},{"value":"10","value_description":"Normal mode."},{"value":"11","value_description":"Autoreset on interrupt event."}] | [] | field differs or is incomplete |
| `truth registers[8].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Internal filter bypassed."},{"value":"1","value_description":"Data from the internal filter sent to the output register and FIFO."}] | [] | field differs or is incomplete |
| `truth registers[8].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | [] | field differs or is incomplete |
| `truth registers[8].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | [] | field differs or is incomplete |
| `truth registers[8].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | [] | field differs or is incomplete |
| `v12 registers[11].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"HPM[1:0]","field_description":"High-pass filter mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode, reset by reading REFERENCE (26h)."},{"value":"01","value_description":"Reference signal for filtering."},{"value":"10","value_description":"Normal mode."},{"value":"11","value_description":"Autoreset on interrupt event."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCF[2:1]","field_description":"High-pass filter cutoff-frequency selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FDS","field_description":"Filtered data selection.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Internal filter bypassed."},{"value":"1","value_description":"Data from the internal filter sent to the output register and FIFO."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCLICK","field_description":"High-pass filter enable for the CLICK function.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA2","field_description":"High-pass filter enable for the AOI function on interrupt 2.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA1","field_description":"High-pass filter enable for the AOI function on interrupt 1.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"HP_IA1","field_description":"High-pass filter enabled for AOI function on interrupt 1 (0: filter bypassed; 1: filter enabled)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA2","field_description":"High-pass filter enabled for AOI function on interrupt 2 (0: filter bypassed; 1: filter enabled)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCLICK","field_description":"High-pass filter enabled for CLICK function (0: filter bypassed; 1: filter enabled)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FDS","field_description":"Filtered data selection. Default value: 0 (0: internal filter bypassed; 1: data from internal filter sent to output register and FIFO)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCF[2:1]","field_description":"High-pass filter cutoff frequency selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPM[1:0]","field_description":"High-pass filter mode selection. Default value: 00 (Refer to Table 35: High-pass filter mode configuration).","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[11]` | `register_description` | 0.0 | Configures the high-pass filter and its routing to output, FIFO, click and interrupt functions. | "" | field differs or is incomplete |
| `v12 registers[11]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | I1_CLICK | -- | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Click interrupt on INT1. | "" | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | true | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `truth registers[9].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.5 | I1_IA1 | I1_CLICK | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.5 | I1_IA2 | I1_IA1 | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.5 | I1_ZYXDA | I1_IA2 | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.5 | I1_321DA | I1_ZYXDA | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[5]` | `name_or_parameter` | 0.5 | I1_WTM | I1_321DA | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[5]` | `field_description` | 0.5 | FIFO watermark interrupt on INT1. | 321DA interrupt on INT1. Default value: 0 (0: disable; 1: enable) | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[6]` | `name_or_parameter` | 0.5 | I1_OVERRUN | I1_WTM | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [] | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[7]` | `name_or_parameter` | 0.0 | -- | I1_OVERRUN | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[7]` | `is_reserved` | 0.0 | true | false | field differs or is incomplete |
| `truth registers[9].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | "" | RW | type_write_read mismatch |
| `v12 registers[12].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"I1_CLICK","field_description":"Click interrupt on INT1.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA1","field_description":"IA1 interrupt on INT1.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA2","field_description":"IA2 interrupt on INT1.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_ZYXDA","field_description":"ZYXDA interrupt on INT1.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_321DA","field_description":"321DA interrupt on INT1.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_WTM","field_description":"FIFO watermark interrupt on INT1.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_OVERRUN","field_description":"FIFO overrun interrupt on INT1.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"I1_OVERRUN","field_description":"FIFO overrun interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_WTM","field_description":"FIFO watermark interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_321DA","field_description":"321DA interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_ZYXDA","field_description":"ZYXDA interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA2","field_description":"IA2 interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA1","field_description":"IA1 interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_CLICK","field_description":"Click interrupt on INT1. Default value: 0 (0: disable; 1: enable)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | field differs or is incomplete |
| `v12 registers[12]` | `register_description` | 0.0 | Routes click, inertial, data-ready, FIFO watermark and FIFO overrun interrupts to INT1. | "" | field differs or is incomplete |
| `v12 registers[12]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[10].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"Continuous update."},{"value":"1","value_description":"Output registers are not updated until MSB and LSB have been read."}] | [] | field differs or is incomplete |
| `truth registers[10].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Data LSB at lower address."},{"value":"1","value_description":"Data MSB at lower address."}] | [] | field differs or is incomplete |
| `truth registers[10].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"00","value_description":"±2 g."},{"value":"01","value_description":"±4 g."},{"value":"10","value_description":"±8 g."},{"value":"11","value_description":"±16 g."}] | [] | field differs or is incomplete |
| `truth registers[10].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"High-resolution disabled."},{"value":"1","value_description":"High-resolution enabled."}] | [] | field differs or is incomplete |
| `truth registers[10].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}] | [] | field differs or is incomplete |
| `truth registers[10].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}] | [] | field differs or is incomplete |
| `v12 registers[13].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"BDU","field_description":"Block data update.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Continuous update."},{"value":"1","value_description":"Output registers are not updated until MSB and LSB have been read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BLE","field_description":"Big/little endian data selection; available only in high-resolution mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Data LSB at lower address."},{"value":"1","value_description":"Data MSB at lower address."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FS[1:0]","field_description":"Full-scale selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[{"value":"00","value_description":"±2 g."},{"value":"01","value_description":"±4 g."},{"value":"10","value_description":"±8 g."},{"value":"11","value_description":"±16 g."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HR","field_description":"High-resolution output mode.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution disabled."},{"value":"1","value_description":"High-resolution enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ST[1:0]","field_description":"Self-test enable.","bit_start":1,"bit_end":2,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SIM","field_description":"SPI serial-interface mode selection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"SIM","field_description":"SPI serial interface mode selection. Default value: 0 (0: 4-wire interface; 1: 3-wire interface)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ST[1:0]","field_description":"Self-test enable. Default value: 00 (Refer to Table 40: Self-test mode configuration).","bit_start":1,"bit_end":2,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HR","field_description":"High-resolution output mode. Default value: 0 (0: high-resolution disabled; 1: high-resolution enabled)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FS[1:0]","field_description":"Full-scale selection. Default value: 00 (00: ±2 g; 01: ±4 g; 10: ±8 g; 11: ±16 g)","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BLE","field_description":"Big/little endian data selection. Default value: 0 (0: Data LSB @ lower address; 1: Data MSB @ lower address). The BLE function can be activated only in high-resolution mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BDU","field_description":"Block data update. Default value: 0 (0: continuous update; 1: output registers not updated until MSB and LSB reading)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[13]` | `register_description` | 0.0 | Configures block data update, byte order, full scale, high-resolution mode, self-test and SPI interface mode. | "" | field differs or is incomplete |
| `v12 registers[13]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[11].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"Normal mode."},{"value":"1","value_description":"Reboot memory content."}] | [] | field differs or is incomplete |
| `truth registers[11].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"FIFO disabled."},{"value":"1","value_description":"FIFO enabled."}] | [] | field differs or is incomplete |
| `truth registers[11].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `truth registers[11].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}] | [] | field differs or is incomplete |
| `truth registers[11].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}] | [] | field differs or is incomplete |
| `v12 registers[14].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"BOOT","field_description":"Reboot memory content.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Normal mode."},{"value":"1","value_description":"Reboot memory content."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FIFO_EN","field_description":"FIFO enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"FIFO disabled."},{"value":"1","value_description":"FIFO enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT1","field_description":"Latch interrupt request on INT1_SRC; reading INT1_SRC clears it.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT1","field_description":"Enable 4D detection on INT1 when the INT1_CFG 6D bit is set.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT2","field_description":"Latch interrupt request on INT2_SRC; reading INT2_SRC clears it.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT2","field_description":"Enable 4D detection on INT2 when the INT2_CFG 6D bit is set.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"D4D_INT2","field_description":"4D enable: 4D detection is enabled on INT2 pin when 6D bit on INT2_CFG (34h) is set to 1.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT2","field_description":"Latch interrupt request on INT2_SRC (35h) register, with INT2_SRC (35h) register cleared by reading INT2_SRC (35h) itself. Default value: 0 (0: interrupt request not latched; 1: interrupt request latched)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT1","field_description":"4D enable: 4D detection is enabled on INT1 when 6D bit on INT1_CFG is set to 1.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT1","field_description":"Latch interrupt request on INT1_SRC register, with INT1_SRC (31h) register cleared by reading INT1_SRC (31h) itself. Default value: 0 (0: interrupt request not latched; 1: interrupt request latched)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"FIFO_EN","field_description":"FIFO enable. Default value: 0 (0: FIFO disable; 1: FIFO enable)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BOOT","field_description":"Reboot memory content. Default value: 0 (0: normal mode; 1: reboot memory content)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[14]` | `register_description` | 0.0 | Controls memory reboot, FIFO enable, interrupt latching and 4D detection. | "" | field differs or is incomplete |
| `v12 registers[14]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[12].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.5 | I2_CLICK | I2_ACT | field differs or is incomplete |
| `truth registers[12].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}] | [] | field differs or is incomplete |
| `truth registers[12].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | I2_IA1 | INT_POLARITY | field differs or is incomplete |
| `truth registers[12].field_parts[0].bit_field[1]` | `field_description` | 0.5 | Enable interrupt 1 function on INT2 pin. | INT1 and INT2 pin polarity. Default value: 0 (0: active-high; 1: active-low) | field differs or is incomplete |
| `truth registers[12].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}] | [] | field differs or is incomplete |
| `truth registers[12].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | I2_CLICK | RW | type_write_read mismatch |
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
| `v12 registers[15].field_parts[0]` | `bit_field` | 0.2 | [{"name_or_parameter":"I2_CLICK","field_description":"Click interrupt on INT2 pin.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I2_IA1","field_description":"Enable interrupt 1 function on INT2 pin.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_IA2","field_description":"Enable interrupt 2 function on INT2 pin.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_BOOT","field_description":"Enable boot on INT2 pin.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_ACT","field_description":"Enable activity interrupt on INT2 pin.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"--","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"I2_CLICK"},{"name_or_parameter":"INT_POLARITY","field_description":"INT1 and INT2 pin polarity.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Active-high."},{"value":"1","value_description":"Active-low."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"INT_POLARITY","field_description":"INT1 and INT2 pin polarity. Default value: 0 (0: active-high; 1: active-low)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I2_ACT","field_description":"Enable activity interrupt on INT2 pin. Default value: 0 (0: disabled; 1: enabled)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[15].field_parts[0].bit_field[0]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""} | extra/invented bit field |
| `v12 registers[15]` | `register_description` | 0.0 | Routes click, inertial, boot and activity signals to INT2 and sets interrupt-pin polarity. | "" | field differs or is incomplete |
| `v12 registers[15]` | `field_parts` | 0.7 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[13].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | Ref[7:0] | RW | type_write_read mismatch |
| `v12 registers[16].field_parts[0]` | `bit_field` | 0.9 | {"name_or_parameter":"Ref[7:0]","field_description":"Reference value for interrupt generation.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"Ref[7:0]"} | [{"name_or_parameter":"Ref[7:0]","field_description":"Reference value for Interrupt generation. Default value: 00000000","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[16]` | `register_description` | 0.0 | Stores the reference value used for interrupt generation and reference-signal filtering. | "" | field differs or is incomplete |
| `v12 registers[16]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[14].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}] | [] | field differs or is incomplete |
| `truth registers[14].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Z-axis data has overwritten the previous data."}] | [] | field differs or is incomplete |
| `truth registers[14].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Y-axis data has overwritten the previous data."}] | [] | field differs or is incomplete |
| `truth registers[14].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New X-axis data has overwritten the previous data."}] | [] | field differs or is incomplete |
| `truth registers[14].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}] | [] | field differs or is incomplete |
| `truth registers[14].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"New Z-axis data is not yet available."},{"value":"1","value_description":"New Z-axis data is available."}] | [] | field differs or is incomplete |
| `truth registers[14].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"New Y-axis data is not yet available."},{"value":"1","value_description":"New Y-axis data is available."}] | [] | field differs or is incomplete |
| `v12 registers[17].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"ZYXOR","field_description":"X, Y and Z-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZOR","field_description":"Z-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Z-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YOR","field_description":"Y-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Y-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XOR","field_description":"X-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New X-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZYXDA","field_description":"X, Y and Z-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZDA","field_description":"Z-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New Z-axis data is not yet available."},{"value":"1","value_description":"New Z-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YDA","field_description":"Y-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New Y-axis data is not yet available."},{"value":"1","value_description":"New Y-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XDA","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"XDA","field_description":"X-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YDA","field_description":"Y-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZDA","field_description":"Z-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZYXDA","field_description":"X, Y and Z-axis new data available. Default value: 0 (0: a new set of data is not yet available; 1: a new set of data is available)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XOR","field_description":"X-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: a new set of data has overwritten the previous set)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YOR","field_description":"Y-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the Y-axis has overwritten the previous data)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZOR","field_description":"Z-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: new data for the Z-axis has overwritten the previous data)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZYXOR","field_description":"X, Y and Z-axis data overrun. Default value: 0 (0: no overrun has occurred; 1: a new set of data has overwritten the previous set)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] | field differs or is incomplete |
| `v12 registers[17]` | `register_description` | 0.0 | Reports acceleration-axis data-overrun and new-data availability status. | "" | field differs or is incomplete |
| `v12 registers[17]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v12 registers[18]` | `name` | 0.5 | OUT_X_L (28h), OUT_X_H (29h) | OUT_X_L | field differs or is incomplete |
| `v12 registers[18]` | `register_description` | 0.5 | X-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO X-axis data when FIFO is active. | X-axis acceleration data. The value is expressed as two's complement left-justified. | field differs or is incomplete |
| `v12 registers[19]` | `register_description` | 0.0 | X-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO X-axis data when FIFO is active. | "" | field differs or is incomplete |
| `v12 registers[20]` | `name` | 0.5 | OUT_Y_L (2Ah), OUT_Y_H (2Bh) | OUT_Y_L | field differs or is incomplete |
| `v12 registers[20]` | `register_description` | 0.5 | Y-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Y-axis data when FIFO is active. | Y-axis acceleration data. The value is expressed as two's complement left-justified. | field differs or is incomplete |
| `v12 registers[21]` | `register_description` | 0.0 | Y-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Y-axis data when FIFO is active. | "" | field differs or is incomplete |
| `v12 registers[22]` | `name` | 0.5 | OUT_Z_L (2Ch), OUT_Z_H (2Dh) | OUT_Z_L | field differs or is incomplete |
| `v12 registers[22]` | `register_description` | 0.5 | Z-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Z-axis data when FIFO is active. | Z-axis acceleration data. The value is expressed as two's complement left-justified. | field differs or is incomplete |
| `v12 registers[23]` | `register_description` | 0.0 | Z-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Z-axis data when FIFO is active. | "" | field differs or is incomplete |
| `truth registers[18].field_parts[0].bit_field[1]` | `field_description` | 0.5 | Trigger selection for Stream-to-FIFO mode. | Trigger selection. Default value: 0 (0: trigger event allows triggering signal on INT1; 1: trigger event allows triggering signal on INT2) | field differs or is incomplete |
| `truth registers[18].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Triggering signal on INT1."},{"value":"1","value_description":"Triggering signal on INT2."}] | [] | field differs or is incomplete |
| `truth registers[18].field_parts[0].bit_field[2]` | `field_description` | 0.5 | Programmable FIFO watermark threshold. | FIFO threshold level. Default value: 00000. | field differs or is incomplete |
| `v12 registers[24].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"FM[1:0]","field_description":"FIFO mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass mode."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Stream-to-FIFO mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TR","field_description":"Trigger selection for Stream-to-FIFO mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Triggering signal on INT1."},{"value":"1","value_description":"Triggering signal on INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FTH[4:0]","field_description":"Programmable FIFO watermark threshold.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"FTH[4:0]","field_description":"FIFO threshold level. Default value: 00000.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TR","field_description":"Trigger selection. Default value: 0 (0: trigger event allows triggering signal on INT1; 1: trigger event allows triggering signal on INT2)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FM[1:0]","field_description":"FIFO mode selection. Default value: 00 (00: Bypass; 01: FIFO; 10: Stream; 11: Stream-to-FIFO). Refer to Table 51 for mode details.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass mode"},{"value":"01","value_description":"FIFO mode"},{"value":"10","value_description":"Stream mode"},{"value":"11","value_description":"Stream-to-FIFO mode"}],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[24]` | `register_description` | 0.5 | Selects FIFO operating mode, Stream-to-FIFO trigger source and FIFO watermark threshold. | FIFO mode selection and watermark configuration. FIFO_EN bit in CTRL_REG5 (24h) must be set to '1' to enable the FIFO buffer. | field differs or is incomplete |
| `v12 registers[24]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[19].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | R | type_write_read mismatch |
| `truth registers[19].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | R | type_write_read mismatch |
| `truth registers[19].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | R | type_write_read mismatch |
| `v12 registers[25].field_parts[0]` | `bit_field` | 1.0 | [{"name_or_parameter":"WTM","field_description":"Set high when FIFO content exceeds the watermark level.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"OVRN_FIFO","field_description":"Set high when the FIFO is full with 32 unread samples; clears when the first sample set is read.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"EMPTY","field_description":"Set high when all FIFO samples have been read and the FIFO is empty.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FSS [4:0]","field_description":"Current number of unread sample sets stored in the FIFO.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"FSS[4:0]","field_description":"Current number of unread samples stored in the FIFO buffer. Increases at ODR frequency until full, decreases when sample sets are retrieved.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"EMPTY","field_description":"Flag set high when all FIFO samples have been read and FIFO is empty.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"OVRN_FIFO","field_description":"Set high when FIFO buffer is full (32 unread samples). Cleared when the first sample set has been read.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"WTM","field_description":"Set high when FIFO content exceeds watermark level.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] | field differs or is incomplete |
| `v12 registers[25]` | `register_description` | 0.5 | Reports FIFO watermark, overrun, empty status and the number of unread FIFO samples. | FIFO status register. Contains flags indicating FIFO watermark, overrun, and empty conditions. | field differs or is incomplete |
| `v12 registers[25]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[20].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | AOI-6D | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Interrupt event-combination and 6-direction recognition mode. | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}] | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[20].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [] | field differs or is incomplete |
| `truth registers[20].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [] | field differs or is incomplete |
| `truth registers[20].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [] | field differs or is incomplete |
| `truth registers[20].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [] | field differs or is incomplete |
| `truth registers[20].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [] | field differs or is incomplete |
| `truth registers[20].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [] | field differs or is incomplete |
| `v12 registers[26].field_parts[0]` | `bit_field` | 0.7 | [{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event or direction recognition.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event or direction recognition.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event or direction recognition.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event or direction recognition.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event or direction recognition.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event or direction recognition.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event or on Direction recognition. Default value: 0 (0: disable interrupt request; 1: enable interrupt request)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"6D","field_description":"6-direction detection function enabled. Default value: 0. Refer to Table 56: Interrupt mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"AOI","field_description":"And/Or combination of Interrupt events. Default value: 0. Refer to Table 56: Interrupt mode.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[26].field_parts[0].bit_field[6]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"6D","field_description":"6-direction detection function enabled. Default value: 0. Refer to Table 56: Interrupt mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"} | extra/invented bit field |
| `v12 registers[26].field_parts[0].bit_field[7]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"AOI","field_description":"And/Or combination of Interrupt events. Default value: 0. Refer to Table 56: Interrupt mode.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"} | extra/invented bit field |
| `v12 registers[26]` | `register_description` | 0.5 | Configures interrupt 1 event combination, direction recognition and axis high/low event enables. Its content is loaded at boot, and writing is possible only after system boot. | Interrupt 1 configuration register. Content is loaded at boot. | field differs or is incomplete |
| `v12 registers[26]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[21].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | [] | field differs or is incomplete |
| `truth registers[21].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | [] | field differs or is incomplete |
| `truth registers[21].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}] | [] | field differs or is incomplete |
| `truth registers[21].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | [] | field differs or is incomplete |
| `truth registers[21].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}] | [] | field differs or is incomplete |
| `truth registers[21].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | [] | field differs or is incomplete |
| `truth registers[21].field_parts[0].bit_field[7]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}] | [] | field differs or is incomplete |
| `v12 registers[27].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"XL","field_description":"X low. Default value: 0 (0: no interrupt; 1: X low event has occurred)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high. Default value: 0 (0: no interrupt; 1: X high event has occurred)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low. Default value: 0 (0: no interrupt; 1: Y low event has occurred)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high. Default value: 0 (0: no interrupt; 1: Y high event has occurred)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low. Default value: 0 (0: no interrupt; 1: Z low event has occurred)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high. Default value: 0 (0: no interrupt; 1: Z high event has occurred)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"IA","field_description":"Interrupt active. Default value: 0 (0: no interrupt has been generated; 1: one or more interrupts have been generated)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | field differs or is incomplete |
| `v12 registers[27]` | `register_description` | 0.5 | Reports interrupt 1 source and axis-event status. Reading clears the IA bit and INT1 signal and refreshes latched data. | Interrupt 1 source register. Read-only. Reading clears the IA bit and interrupt signal on INT1 pin. | field differs or is incomplete |
| `v12 registers[27]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v12 registers[28]` | `register_description` | 0.5 | Sets the interrupt 1 acceleration threshold. | Interrupt 1 threshold configuration. | field differs or is incomplete |
| `v12 registers[29]` | `register_description` | 0.5 | Sets the minimum interrupt event duration; duration is measured as N/ODR. | Interrupt 1 duration configuration. Duration time is measured in N/ODR, where N is the content of the duration register. | field differs or is incomplete |
| `truth registers[24].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | AOI-6D | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `field_description` | 0.0 | Interrupt event-combination and 6-direction recognition mode. | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}] | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | truth bit field missing from extraction |
| `truth registers[24].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | [] | field differs or is incomplete |
| `truth registers[24].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | [] | field differs or is incomplete |
| `truth registers[24].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | [] | field differs or is incomplete |
| `truth registers[24].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | [] | field differs or is incomplete |
| `truth registers[24].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | [] | field differs or is incomplete |
| `truth registers[24].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | [] | field differs or is incomplete |
| `v12 registers[30].field_parts[0]` | `bit_field` | 0.7 | [{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value lower than preset threshold)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value lower than preset threshold)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value lower than preset threshold)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"6D","field_description":"6-direction detection function enabled. Default value: 0. Refer to Table 65: Interrupt mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"AOI","field_description":"AND/OR combination of interrupt events. Default value: 0 (see Table 65).","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[30].field_parts[0].bit_field[6]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"6D","field_description":"6-direction detection function enabled. Default value: 0. Refer to Table 65: Interrupt mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"} | extra/invented bit field |
| `v12 registers[30].field_parts[0].bit_field[7]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"AOI","field_description":"AND/OR combination of interrupt events. Default value: 0 (see Table 65).","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"} | extra/invented bit field |
| `v12 registers[30]` | `register_description` | 0.5 | Configures interrupt 2 event combination, direction recognition and axis high/low event enables. Its content is loaded at boot, and writing is possible only after system boot. | Interrupt 2 configuration register. Content is loaded at boot. | field differs or is incomplete |
| `v12 registers[30]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[25].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | [] | field differs or is incomplete |
| `truth registers[25].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | [] | field differs or is incomplete |
| `truth registers[25].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}] | [] | field differs or is incomplete |
| `truth registers[25].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | [] | field differs or is incomplete |
| `truth registers[25].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}] | [] | field differs or is incomplete |
| `truth registers[25].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | [] | field differs or is incomplete |
| `truth registers[25].field_parts[0].bit_field[7]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}] | [] | field differs or is incomplete |
| `v12 registers[31].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"XL","field_description":"X low. Default value: 0 (0: no interrupt; 1: X low event has occurred)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high. Default value: 0 (0: no interrupt; 1: X high event has occurred)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low. Default value: 0 (0: no interrupt; 1: Y low event has occurred)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high. Default value: 0 (0: no interrupt; 1: Y high event has occurred)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low. Default value: 0 (0: no interrupt; 1: Z low event has occurred)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high. Default value: 0 (0: no interrupt; 1: Z high event has occurred)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"IA","field_description":"Interrupt active. Default value: 0 (0: no interrupt has been generated; 1: one or more interrupts have been generated)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | field differs or is incomplete |
| `v12 registers[31]` | `register_description` | 0.5 | Reports interrupt 2 source and axis-event status. Reading clears the IA bit and INT2 signal and refreshes latched data. | Interrupt 2 source register. Read-only. Reading clears the IA bit and interrupt signal on INT2 pin. | field differs or is incomplete |
| `v12 registers[31]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v12 registers[32]` | `register_description` | 0.5 | Sets the interrupt 2 acceleration threshold. | Interrupt 2 threshold configuration. | field differs or is incomplete |
| `v12 registers[33]` | `register_description` | 0.5 | Sets the minimum duration of an interrupt 2 event; duration is measured as N/ODR. | Interrupt 2 duration configuration. Duration time is measured in N/ODR, where N is the content of the duration register. | field differs or is incomplete |
| `truth registers[28].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | -- | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 6 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 2 | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[28].field_parts[0].bit_field[1]` | `name_or_parameter` | 0.0 | ZD | YD | field differs or is incomplete |
| `truth registers[28].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [] | field differs or is incomplete |
| `truth registers[28].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | ZS | YS | field differs or is incomplete |
| `truth registers[28].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [] | field differs or is incomplete |
| `truth registers[28].field_parts[0].bit_field[3]` | `name_or_parameter` | 0.0 | YD | XD | field differs or is incomplete |
| `truth registers[28].field_parts[0].bit_field[3]` | `field_description` | 0.0 | Enable double-click interrupt on Y-axis. | Enable interrupt double click on X-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold) | field differs or is incomplete |
| `truth registers[28].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [] | field differs or is incomplete |
| `truth registers[28].field_parts[0].bit_field[4]` | `name_or_parameter` | 0.0 | YS | XS | field differs or is incomplete |
| `truth registers[28].field_parts[0].bit_field[4]` | `field_description` | 0.0 | Enable single-click interrupt on Y-axis. | Enable interrupt single click on X-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold) | field differs or is incomplete |
| `truth registers[28].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [] | field differs or is incomplete |
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
| `v12 registers[34].field_parts[0]` | `bit_field` | 0.4 | [{"name_or_parameter":"--","field_description":"","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"ZD","field_description":"Enable double-click interrupt on Z-axis.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZS","field_description":"Enable single-click interrupt on Z-axis.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YD","field_description":"Enable double-click interrupt on Y-axis.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YS","field_description":"Enable single-click interrupt on Y-axis.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XD","field_description":"Enable double-click interrupt on X-axis.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XS","field_description":"Enable single-click interrupt on X-axis.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"XS","field_description":"Enable interrupt single click on X-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XD","field_description":"Enable interrupt double click on X-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YS","field_description":"Enable interrupt single click on Y-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YD","field_description":"Enable interrupt double click on Y-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZS","field_description":"Enable interrupt single click on Z-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZD","field_description":"Enable interrupt double click on Z-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[34].field_parts[0].bit_field[0]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""} | extra/invented bit field |
| `v12 registers[34].field_parts[0].bit_field[5]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"ZS","field_description":"Enable interrupt single click on Z-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"} | extra/invented bit field |
| `v12 registers[34].field_parts[0].bit_field[6]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"ZD","field_description":"Enable interrupt double click on Z-axis. Default value: 0 (0: disable interrupt request; 1: enable interrupt request on measured accel. value higher than preset threshold)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"} | extra/invented bit field |
| `v12 registers[34]` | `register_description` | 0.5 | Enables single-click and double-click interrupt detection for the X, Y and Z axes. | Click interrupt configuration. | field differs or is incomplete |
| `v12 registers[34]` | `field_parts` | 0.8 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[29].field_parts[0].bit_field[1]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | [] | field differs or is incomplete |
| `truth registers[29].field_parts[0].bit_field[2]` | `values` | 0.0 | [{"value":"0","value_description":"Double-click detection disabled."},{"value":"1","value_description":"Double-click detection enabled."}] | [] | field differs or is incomplete |
| `truth registers[29].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | R | type_write_read mismatch |
| `truth registers[29].field_parts[0].bit_field[3]` | `values` | 0.0 | [{"value":"0","value_description":"Single-click detection disabled."},{"value":"1","value_description":"Single-click detection enabled."}] | [] | field differs or is incomplete |
| `truth registers[29].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | R | type_write_read mismatch |
| `truth registers[29].field_parts[0].bit_field[4]` | `values` | 0.0 | [{"value":"0","value_description":"Positive detection."},{"value":"1","value_description":"Negative detection."}] | [] | field differs or is incomplete |
| `truth registers[29].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | R | type_write_read mismatch |
| `truth registers[29].field_parts[0].bit_field[5]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | [] | field differs or is incomplete |
| `truth registers[29].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | R | type_write_read mismatch |
| `truth registers[29].field_parts[0].bit_field[6]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | [] | field differs or is incomplete |
| `truth registers[29].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | RW | R | type_write_read mismatch |
| `truth registers[29].field_parts[0].bit_field[7]` | `values` | 0.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | [] | field differs or is incomplete |
| `truth registers[29].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | RW | R | type_write_read mismatch |
| `v12 registers[35].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"DCLICK","field_description":"Double-click enable.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Double-click detection disabled."},{"value":"1","value_description":"Double-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SCLICK","field_description":"Single-click enable.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Single-click detection disabled."},{"value":"1","value_description":"Single-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Sign","field_description":"Click sign.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Positive detection."},{"value":"1","value_description":"Negative detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Z","field_description":"Z click detection.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Y","field_description":"Y click detection.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"X","field_description":"X click detection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"X","field_description":"X click detection. Default value: 0 (0: no interrupt, 1: X high event has occurred)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Y","field_description":"Y click detection. Default value: 0 (0: no interrupt, 1: Y high event has occurred)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Z","field_description":"Z click detection. Default value: 0 (0: no interrupt, 1: Z high event has occurred)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Sign","field_description":"Click sign (0: positive detection, 1: negative detection)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"SCLICK","field_description":"Single-click enable. Default value: 0 (0: Single-click detection disabled, 1: single-click detection enabled)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"DCLICK","field_description":"Double-click enable. Default value: 0 (0: double-click detection disabled, 1: double-click detection enabled)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"IA","field_description":"Interrupt active. Default value: 0 (0: no interrupt has been generated; 1: one or more interrupts have been generated)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | field differs or is incomplete |
| `v12 registers[35]` | `register_description` | 0.5 | Reports click-interrupt activity, single/double-click detection, sign and detected axis. | Click interrupt source register. | field differs or is incomplete |
| `v12 registers[35]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[30].field_parts[0].bit_field[0]` | `field_description` | 0.5 | Controls click-interrupt latching. | If the LIR_Click bit is not set, the interrupt is kept high for the duration of the latency window. If the LIR_Click bit is set, the interrupt is kept high until the CLICK_SRC (39h) register is read. | field differs or is incomplete |
| `truth registers[30].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}] | [] | field differs or is incomplete |
| `v12 registers[36].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"LIR_Click","field_description":"Controls click-interrupt latching.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Ths[6:0]","field_description":"Click threshold.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"Ths[6:0]","field_description":"Click threshold. Default value: 0000000","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_Click","field_description":"If the LIR_Click bit is not set, the interrupt is kept high for the duration of the latency window. If the LIR_Click bit is set, the interrupt is kept high until the CLICK_SRC (39h) register is read.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[36]` | `register_description` | 0.5 | Sets the click threshold and click-interrupt latch behavior. | Click threshold configuration. | field differs or is incomplete |
| `v12 registers[36]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[31].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | - | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[31].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 0 | 1 | field differs or is incomplete |
| `truth registers[31].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | 7 | field differs or is incomplete |
| `v12 registers[37].field_parts[0]` | `bit_field` | 0.2 | [{"name_or_parameter":"-","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"TLI[6:0]","field_description":"Click time limit.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"TLI[6:0]","field_description":"Click time limit. Default value: 0000000","bit_start":1,"bit_end":7,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[37].field_parts[0].bit_field[0]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | extra/invented bit field |
| `v12 registers[37]` | `register_description` | 0.5 | Sets the click time limit. | Click time limit configuration. | field differs or is incomplete |
| `v12 registers[37]` | `field_parts` | 0.8 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v12 registers[38]` | `register_description` | 0.5 | Sets the click time latency. | Click time latency configuration. | field differs or is incomplete |
| `v12 registers[39]` | `register_description` | 0.5 | Sets the click time window. | Click time window configuration. | field differs or is incomplete |
| `v12 registers[39]` | `default_value` | 0.0 | 00000000 | "" | field differs or is incomplete |
| `truth registers[34].field_parts[0].bit_field[0]` | `name_or_parameter` | 0.0 | -- | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `field_description` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `bit_start` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `bit_width` | 0.0 | 1 | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `values` | 0.0 | [] | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | truth bit field missing from extraction |
| `truth registers[34].field_parts[0].bit_field[1]` | `bit_start` | 0.0 | 0 | 2 | field differs or is incomplete |
| `truth registers[34].field_parts[0].bit_field[1]` | `bit_end` | 0.0 | 6 | 7 | field differs or is incomplete |
| `truth registers[34].field_parts[0].bit_field[1]` | `bit_width` | 0.0 | 7 | 6 | field differs or is incomplete |
| `v12 registers[40].field_parts[0]` | `bit_field` | 0.2 | [{"name_or_parameter":"--","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Acth[6:0]","field_description":"Sleep-to-wake and return-to-sleep activation threshold in low-power mode. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Acth[6:0]","field_description":"Sleep-to-wake, return-to-sleep activation threshold in low-power mode. 1 LSb = 16 mg @ FS = ±2 g; 32 mg @ ±4 g; 62 mg @ ±8 g; 186 mg @ ±16 g.","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"RW"}] | field differs or is incomplete |
| `v12 registers[40].field_parts[0].bit_field[0]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""} | extra/invented bit field |
| `v12 registers[40]` | `register_description` | 0.5 | Sets the sleep-to-wake and return-to-sleep activation threshold in low-power mode. | Sleep-to-wake and return-to-sleep activation threshold configuration. | field differs or is incomplete |
| `v12 registers[40]` | `field_parts` | 0.8 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |

## 4. Invented-field and representation check

- Numeric physical addresses are normalized by `(numeric address, bank, page)`; hexadecimal and decimal spellings identify the same location.
- Equivalent logical-register merge/split representations are associated by their physical addresses and are not penalized solely for grouping.
- Reserved-bit names/descriptions may be empty; structural ranges, reserved status, values, access types, and widths remain scored.
- `type_write_read` is compared strictly at bit-field level; matching empty values receive C=1, while missing or mismatched values receive C=0.



