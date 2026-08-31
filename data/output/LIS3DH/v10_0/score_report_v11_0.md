# LIS3DH v11.0 detailed score — updated truth type_write_read

## Extracted logical register 1: `STATUS_REG_AUX`

v11 location: `registers[0]`; truth association: `registers[0]` (`STATUS_REG_AUX`).

Associated physical locations: 0x07 (7).


### Bottom layer: bit fields, then field parts

#### Field part 1: `STATUS_REG_AUX` at 0x07 (7)

Locations: `truth registers[0].field_parts` ↔ `v11 registers[0].field_parts[0]`.

**Truth bit field 1: `321OR` bits 7:7**

Locations: `truth registers[0].field_parts.bit_field[0]` ↔ `v11 registers[0].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 321OR | 321OR |
| `field_description` | 0.0586 | 1.0 | 1, 2 and 3-axis data overrun. | 1, 2 and 3-axis data overrun. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}] | [{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"a new set of data has overwritten the previous set"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `3OR` bits 6:6**

Locations: `truth registers[0].field_parts.bit_field[1]` ↔ `v11 registers[0].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 3OR | 3OR |
| `field_description` | 0.0586 | 1.0 | 3-axis data overrun. | 3-axis data overrun. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 3-axis has overwritten the previous data."}] | [{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the 3-axis has overwritten the previous data"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `2OR` bits 5:5**

Locations: `truth registers[0].field_parts.bit_field[2]` ↔ `v11 registers[0].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 2OR | 2OR |
| `field_description` | 0.0586 | 1.0 | 2-axis data overrun. | 2-axis data overrun. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 2-axis has overwritten the previous data."}] | [{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the 2-axis has overwritten the previous data"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `1OR` bits 4:4**

Locations: `truth registers[0].field_parts.bit_field[3]` ↔ `v11 registers[0].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 1OR | 1OR |
| `field_description` | 0.0586 | 1.0 | 1-axis data overrun. | 1-axis data overrun. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 1-axis has overwritten the previous data."}] | [{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the 1-axis has overwritten the previous data"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `321DA` bits 3:3**

Locations: `truth registers[0].field_parts.bit_field[4]` ↔ `v11 registers[0].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 321DA | 321DA |
| `field_description` | 0.0586 | 1.0 | 1, 2 and 3-axis new data available. | 1, 2 and 3-axis new data available. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}] | [{"value":"0","value_description":"a new set of data is not yet available"},{"value":"1","value_description":"a new set of data is available"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 6: `3DA` bits 2:2**

Locations: `truth registers[0].field_parts.bit_field[5]` ↔ `v11 registers[0].field_parts[0].bit_field[5]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 3DA | 3DA |
| `field_description` | 0.0586 | 1.0 | 3-axis new data available. | 3-axis new data available. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"New data for the 3-axis is not yet available."},{"value":"1","value_description":"New data for the 3-axis is available."}] | [{"value":"0","value_description":"new data for the 3-axis is not yet available"},{"value":"1","value_description":"new data for the 3-axis is available"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 7: `2DA` bits 1:1**

Locations: `truth registers[0].field_parts.bit_field[6]` ↔ `v11 registers[0].field_parts[0].bit_field[6]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 2DA | 2DA |
| `field_description` | 0.0586 | 1.0 | 2-axis new data available. | 2-axis new data available. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"New data for the 2-axis is not yet available."},{"value":"1","value_description":"New data for the 2-axis is available."}] | [{"value":"0","value_description":"new data for the 2-axis is not yet available"},{"value":"1","value_description":"new data for the 2-axis is available"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 8: `1DA` bits 0:0**

Locations: `truth registers[0].field_parts.bit_field[7]` ↔ `v11 registers[0].field_parts[0].bit_field[7]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 1DA | 1DA |
| `field_description` | 0.0586 | 1.0 | 1-axis new data available. | 1-axis new data available. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"New data for the 1-axis is not yet available."},{"value":"1","value_description":"New data for the 1-axis is available."}] | [{"value":"0","value_description":"new data for the 1-axis is not yet available"},{"value":"1","value_description":"new data for the 1-axis is available"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.941694.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | STATUS_REG_AUX | STATUS_REG_AUX |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} | {"hex":"0x07","decimal":"7","bank":"","page":"","description":"Auxiliary (ADC) status register address"} |
| `description` | 0.0693 | 1.000000 | "" | Auxiliary ADC status flags |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | [{"name_or_parameter":"321OR","field_description":"1, 2 and 3-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3OR","field_description":"3-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 3-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2OR","field_description":"2-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 2-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1OR","field_description":"1-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 1-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"321DA","field_description":"1, 2 and 3-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3DA","field_description":"3-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 3-axis is not yet available."},{"value":"1","value_description":"New data for the 3-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2DA","field_description":"2-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 2-axis is not yet available."},{"value":"1","value_description":"New data for the 2-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1DA","field_description":"1-axis new data available.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 1-axis is not yet available."},{"value":"1","value_description":"New data for the 1-axis is available."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"321OR","field_description":"1, 2 and 3-axis data overrun. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"a new set of data has overwritten the previous set"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"3OR","field_description":"3-axis data overrun. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the 3-axis has overwritten the previous data"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"2OR","field_description":"2-axis data overrun. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the 2-axis has overwritten the previous data"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"1OR","field_description":"1-axis data overrun. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the 1-axis has overwritten the previous data"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"321DA","field_description":"1, 2 and 3-axis new data available. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"a new set of data is not yet available"},{"value":"1","value_description":"a new set of data is available"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"3DA","field_description":"3-axis new data available. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"new data for the 3-axis is not yet available"},{"value":"1","value_description":"new data for the 3-axis is available"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"2DA","field_description":"2-axis new data available. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"new data for the 2-axis is not yet available"},{"value":"1","value_description":"new data for the 2-axis is available"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"1DA","field_description":"1-axis new data available. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"new data for the 1-axis is not yet available"},{"value":"1","value_description":"new data for the 1-axis is available"}],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.981756}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.981756) = **0.981756**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | STATUS_REG_AUX | STATUS_REG_AUX |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":"Auxiliary (ADC) status register address"}] |
| `register_description` | 0.0564 | 1.000000 | Reports auxiliary ADC data-overrun and new-data availability status. | Status register for the auxiliary ADC channels. Reports overrun (xOR) and new-data-available (xDA) flags for ADC channels 1, 2 and 3. Used together with the OUT_ADCx_L/OUT_ADCx_H result registers; auxiliary ADC configuration is described in Section 3.7 (retrieve temperature/ADC enabling and conversion details from Section 3.7 and Table 5). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.981756 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 0.000000 | "" | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | All documented bit fields default to 0. |

\(Q(L_{1})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.927951/1.0001=\mathbf{0.927858}\).

## Extracted logical register 2: `OUT_ADC1_L`

v11 location: `registers[1]`; truth association: `registers[1]` (`OUT_ADC1_L (08h), OUT_ADC1_H (09h)`).

Associated physical locations: 0x08 (8).


### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC1_L` at 0x08 (8)

Locations: `truth registers[1].field_parts[0]` ↔ `v11 registers[1].field_parts[0]`.

No truth bit fields are defined for this field part; empty extraction receives bit_field C=1, non-empty extraction receives C=0.

**Field-part aggregation**

`bit_field` correctness = 1.000000.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC1_L | OUT_ADC1_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"Low byte of auxiliary ADC channel 1 conversion."} | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"ADC channel 1 conversion result low byte"} |
| `description` | 0.0693 | 1.000000 | Low byte of auxiliary ADC channel 1 conversion. | ADC channel 1 conversion result low byte (left-aligned 2's complement) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_ADC1_L | OUT_ADC1_L |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"Low byte of auxiliary ADC channel 1 conversion."} | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":"ADC channel 1 conversion result low byte"}] |
| `register_description` | 0.0564 | 1.000000 | Auxiliary 10-bit ADC channel 1 conversion, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 1 conversion result, low byte. Output data are 2's complement left-aligned; input range 1200 mV ±400 mV. ADC resolution is 10 bits in high-resolution/normal mode (LPen=0 in CTRL_REG1) and 8 bits in low-power mode. The auxiliary ADC must be enabled with ADC_EN (bit 7) in TEMP_CFG_REG (1Fh) and BDU (bit 7) in CTRL_REG4 (23h); sampling frequency equals ODR in CTRL_REG1 (20h). Refer to Section 3.7 for setup and conversion details. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{2})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 3: `OUT_ADC1_H`

v11 location: `registers[2]`; truth association: `registers[1]` (`OUT_ADC1_L (08h), OUT_ADC1_H (09h)`).

Associated physical locations: 0x09 (9).


### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC1_H` at 0x09 (9)

Locations: `truth registers[1].field_parts[1]` ↔ `v11 registers[2].field_parts[0]`.

No truth bit fields are defined for this field part; empty extraction receives bit_field C=1, non-empty extraction receives C=0.

**Field-part aggregation**

`bit_field` correctness = 1.000000.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC1_H | OUT_ADC1_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"High byte of auxiliary ADC channel 1 conversion."} | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"ADC channel 1 conversion result high byte"} |
| `description` | 0.0693 | 1.000000 | High byte of auxiliary ADC channel 1 conversion. | ADC channel 1 conversion result high byte (left-aligned 2's complement) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_ADC1_H | OUT_ADC1_H |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"High byte of auxiliary ADC channel 1 conversion."} | [{"hex":"0x09","decimal":"9","bank":"","page":"","description":"ADC channel 1 conversion result high byte"}] |
| `register_description` | 0.0564 | 1.000000 | Auxiliary 10-bit ADC channel 1 conversion, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 1 conversion result, high byte. Paired with OUT_ADC1_L (08h); data are 2's complement left-aligned. Refer to Section 3.7 for auxiliary ADC setup. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{3})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 4: `OUT_ADC2_L`

v11 location: `registers[3]`; truth association: `registers[2]` (`OUT_ADC2_L (0Ah), OUT_ADC2_H (0Bh)`).

Associated physical locations: 0x0A (10).


### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC2_L` at 0x0A (10)

Locations: `truth registers[2].field_parts[0]` ↔ `v11 registers[3].field_parts[0]`.

No truth bit fields are defined for this field part; empty extraction receives bit_field C=1, non-empty extraction receives C=0.

**Field-part aggregation**

`bit_field` correctness = 1.000000.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC2_L | OUT_ADC2_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Low byte of auxiliary ADC channel 2 conversion."} | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":"ADC channel 2 conversion result low byte"} |
| `description` | 0.0693 | 1.000000 | Low byte of auxiliary ADC channel 2 conversion. | ADC channel 2 conversion result low byte (left-aligned 2's complement) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_ADC2_L | OUT_ADC2_L |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Low byte of auxiliary ADC channel 2 conversion."} | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"ADC channel 2 conversion result low byte"}] |
| `register_description` | 0.0564 | 1.000000 | Auxiliary 10-bit ADC channel 2 conversion, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 2 conversion result, low byte. Data are 2's complement left-aligned. Refer to Section 3.7 for auxiliary ADC setup and enabling. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{4})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 5: `OUT_ADC2_H`

v11 location: `registers[4]`; truth association: `registers[2]` (`OUT_ADC2_L (0Ah), OUT_ADC2_H (0Bh)`).

Associated physical locations: 0x0B (11).


### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC2_H` at 0x0B (11)

Locations: `truth registers[2].field_parts[1]` ↔ `v11 registers[4].field_parts[0]`.

No truth bit fields are defined for this field part; empty extraction receives bit_field C=1, non-empty extraction receives C=0.

**Field-part aggregation**

`bit_field` correctness = 1.000000.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC2_H | OUT_ADC2_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"High byte of auxiliary ADC channel 2 conversion."} | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"ADC channel 2 conversion result high byte"} |
| `description` | 0.0693 | 1.000000 | High byte of auxiliary ADC channel 2 conversion. | ADC channel 2 conversion result high byte (left-aligned 2's complement) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_ADC2_H | OUT_ADC2_H |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"High byte of auxiliary ADC channel 2 conversion."} | [{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"ADC channel 2 conversion result high byte"}] |
| `register_description` | 0.0564 | 0.500000 | Auxiliary 10-bit ADC channel 2 conversion, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 2 conversion result, high byte. Paired with OUT_ADC2_L (0Ah). Refer to Section 3.7 for auxiliary ADC setup. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{5})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 6: `OUT_ADC3_L`

v11 location: `registers[5]`; truth association: `registers[3]` (`OUT_ADC3_L (0Ch), OUT_ADC3_H (0Dh)`).

Associated physical locations: 0x0C (12).


### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC3_L` at 0x0C (12)

Locations: `truth registers[3].field_parts[0]` ↔ `v11 registers[5].field_parts[0]`.

No truth bit fields are defined for this field part; empty extraction receives bit_field C=1, non-empty extraction receives C=0.

**Field-part aggregation**

`bit_field` correctness = 1.000000.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC3_L | OUT_ADC3_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output."} | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"ADC channel 3 / temperature sensor result low byte"} |
| `description` | 0.0693 | 0.500000 | Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output. | ADC channel 3 or temperature sensor result low byte (left-aligned 2's complement) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.500000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{0.965350}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.965350) = **0.965350**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_ADC3_L | OUT_ADC3_L |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output."} | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"ADC channel 3 / temperature sensor result low byte"}] |
| `register_description` | 0.0564 | 1.000000 | Auxiliary 10-bit ADC channel 3 conversion or temperature-sensor data output, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 3 conversion result low byte, or temperature sensor data output when channel 3 is connected to the temperature sensor (TEMP_EN bit 6 of TEMP_CFG_REG (1Fh) = 1). Data are 2's complement left-aligned. Refer to Section 3.7 and Table 5 (Temperature sensor characteristics) for the conversion factor. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.965350 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{6})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.965350 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.989750/1.0001=\mathbf{0.989651}\).

## Extracted logical register 7: `OUT_ADC3_H`

v11 location: `registers[6]`; truth association: `registers[3]` (`OUT_ADC3_L (0Ch), OUT_ADC3_H (0Dh)`).

Associated physical locations: 0x0D (13).


### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_ADC3_H` at 0x0D (13)

Locations: `truth registers[3].field_parts[1]` ↔ `v11 registers[6].field_parts[0]`.

No truth bit fields are defined for this field part; empty extraction receives bit_field C=1, non-empty extraction receives C=0.

**Field-part aggregation**

`bit_field` correctness = 1.000000.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_ADC3_H | OUT_ADC3_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"High byte of auxiliary ADC channel 3 conversion or temperature-sensor output."} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"ADC channel 3 / temperature sensor result high byte"} |
| `description` | 0.0693 | 0.500000 | High byte of auxiliary ADC channel 3 conversion or temperature-sensor output. | ADC channel 3 or temperature sensor result high byte (left-aligned 2's complement) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×0.500000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{0.965350}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.965350) = **0.965350**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_ADC3_H | OUT_ADC3_H |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"High byte of auxiliary ADC channel 3 conversion or temperature-sensor output."} | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"ADC channel 3 / temperature sensor result high byte"}] |
| `register_description` | 0.0564 | 0.500000 | Auxiliary 10-bit ADC channel 3 conversion or temperature-sensor data output, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 3 conversion result high byte, or temperature sensor data output high byte when the temperature sensor is enabled on channel 3. Paired with OUT_ADC3_L (0Ch). Refer to Section 3.7 and Table 5 for the temperature conversion factor. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.965350 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{7})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.965350 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.961550/1.0001=\mathbf{0.961454}\).

## Extracted logical register 8: `WHO_AM_I`

v11 location: `registers[7]`; truth association: `registers[4]` (`WHO_AM_I`).

Associated physical locations: 0x0F (15).


### Bottom layer: bit fields, then field parts

#### Field part 1: `WHO_AM_I` at 0x0F (15)

Locations: `truth registers[4].field_parts` ↔ `v11 registers[7].field_parts[0]`.

No truth bit fields are defined for this field part; empty extraction receives bit_field C=1, non-empty extraction receives C=0.

**Field-part aggregation**

`bit_field` correctness = 1.000000.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":""} | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Device identification register address"} |
| `description` | 0.0693 | 1.000000 | "" | Fixed device identification value |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":""} | [{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Device identification register address"}] |
| `register_description` | 0.0564 | 1.000000 | Device identification register. | Device identification register (dummy register); fixed content 00110011. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00110011 | 00110011 |
| `default_value_description` | 0.0334 | 1.000000 | "" | Fixed identification value; Comment in register map: Dummy register. |

\(Q(L_{8})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 9: `CTRL_REG0`

v11 location: `registers[8]`; truth association: `registers[5]` (`CTRL_REG0`).

Associated physical locations: 0x1E (30).


### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG0` at 0x1E (30)

Locations: `truth registers[5].field_parts` ↔ `v11 registers[8].field_parts[0]`.

**Truth bit field 1: `SDO_PU_DISC` bits 7:7**

Locations: `truth registers[5].field_parts.bit_field[0]` ↔ `v11 registers[8].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SDO_PU_DISC | SDO_PU_DISC |
| `field_description` | 0.0586 | 1.0 | Disconnect SDO/SA0 pull-up. | Disconnect SDO/SA0 pull-up. Default value: 00010000 |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":0,"value_description":"SDO/SA0 internal pull-up connected."},{"value":1,"value_description":"SDO/SA0 internal pull-up disconnected."}] | [{"value":"0","value_description":"pull-up connected to SDO/SA0 pin"},{"value":"1","value_description":"pull-up disconnected to SDO/SA0 pin"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `bit6` bits 6:6**

Locations: `truth registers[5].field_parts.bit_field[1]` ↔ missing. Judgment: truth bit field is missing from the extraction.

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

Locations: `truth registers[5].field_parts.bit_field[2]` ↔ missing. Judgment: truth bit field is missing from the extraction.

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

Locations: `truth registers[5].field_parts.bit_field[3]` ↔ missing. Judgment: truth bit field is missing from the extraction.

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

Locations: `truth registers[5].field_parts.bit_field[4]` ↔ missing. Judgment: truth bit field is missing from the extraction.

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

Locations: `truth registers[5].field_parts.bit_field[5]` ↔ missing. Judgment: truth bit field is missing from the extraction.

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

Locations: `truth registers[5].field_parts.bit_field[6]` ↔ missing. Judgment: truth bit field is missing from the extraction.

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

Locations: `truth registers[5].field_parts.bit_field[7]` ↔ missing. Judgment: truth bit field is missing from the extraction.

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

Additional v11 bit field not matched to a truth range: `v11 registers[8].field_parts[0].bit_field[1]` (`Reserved`, bits 6:0). It is reported but not credited.

**Field-part aggregation**

`bit_field` correctness = 0.117712.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG0 | CTRL_REG0 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":""} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Control register 0 address"} |
| `description` | 0.0693 | 1.000000 | "" | SDO/SA0 pull-up control and fixed-operation bits |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.117712 | [{"name_or_parameter":"SDO_PU_DISC","field_description":"Disconnect SDO/SA0 pull-up.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":0,"value_description":"SDO/SA0 internal pull-up connected."},{"value":1,"value_description":"SDO/SA0 internal pull-up disconnected."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"bit6","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":6,"bit_end":6,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit5","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":5,"bit_end":5,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit4","field_description":"This bit must be set to 1 for correct operation of the device.","bit_start":4,"bit_end":4,"bit_width":1,"values":{"value":1,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit3","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":3,"bit_end":3,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit2","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":2,"bit_end":2,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit1","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":1,"bit_end":1,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit0","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":0,"bit_end":0,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""}] | [{"name_or_parameter":"SDO_PU_DISC","field_description":"Disconnect SDO/SA0 pull-up. Default value: 00010000","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"pull-up connected to SDO/SA0 pin"},{"value":"1","value_description":"pull-up disconnected to SDO/SA0 pin"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Reserved","field_description":"Bits 6:0 fixed for correct operation. Leave bits 0 through 6 at the default value; bit 4 must be set to 1, the other low bits to 0.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.117712=\mathbf{0.723932}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.723932) = **0.723932**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG0 | CTRL_REG0 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":""} | [{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Control register 0 address"}] |
| `register_description` | 0.0564 | 0.500000 | Controls disconnection of the internal SDO/SA0 pull-up. | Control register 0. Bit 7 (SDO_PU_DISC) disconnects the SDO/SA0 pull-up. Bits 0 through 6 must be left at their default values to ensure correct operation; bit 4 must be set to 1 and the remaining low bits to 0. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.723932 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00010000 | 00010000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | Bits 0-6 must remain at default; bit 4 fixed to 1 for correct operation. |

\(Q(L_{9})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.723932 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.889438/1.0001=\mathbf{0.889350}\).

## Extracted logical register 10: `TEMP_CFG_REG`

v11 location: `registers[9]`; truth association: `registers[6]` (`TEMP_CFG_REG`).

Associated physical locations: 0x1F (31).


### Bottom layer: bit fields, then field parts

#### Field part 1: `TEMP_CFG_REG` at 0x1F (31)

Locations: `truth registers[6].field_parts` ↔ `v11 registers[9].field_parts[0]`.

**Truth bit field 1: `ADC_EN` bits 7:7**

Locations: `truth registers[6].field_parts.bit_field[0]` ↔ `v11 registers[9].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ADC_EN | ADC_EN |
| `field_description` | 0.0586 | 1.0 | ADC enable. | ADC enable. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"ADC disabled."},{"value":"1","value_description":"ADC enabled."}] | [{"value":"0","value_description":"ADC disabled"},{"value":"1","value_description":"ADC enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `TEMP_EN` bits 6:6**

Locations: `truth registers[6].field_parts.bit_field[1]` ↔ `v11 registers[9].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_EN | TEMP_EN |
| `field_description` | 0.0586 | 1.0 | Temperature sensor enable. | Temperature sensor (T) enable. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Temperature sensor disabled."},{"value":"1","value_description":"Temperature sensor enabled."}] | [{"value":"0","value_description":"T disabled"},{"value":"1","value_description":"T enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `0` bits 5:0**

Locations: `truth registers[6].field_parts.bit_field[2]` ↔ `v11 registers[9].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | 0 | Reserved |
| `field_description` | 0.0586 | 1.0 | "" | Bits 5:0 shown as 0 in the register bit table; no function described. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×0.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.978700/0.9999=\mathbf{0.978798}\).

**Field-part aggregation**

`bit_field` correctness = 0.954062.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TEMP_CFG_REG | TEMP_CFG_REG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":""} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Temperature/ADC configuration register address"} |
| `description` | 0.0693 | 1.000000 | "" | ADC and temperature sensor enable |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.954062 | [{"name_or_parameter":"ADC_EN","field_description":"ADC enable.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"ADC disabled."},{"value":"1","value_description":"ADC enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TEMP_EN","field_description":"Temperature sensor enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Temperature sensor disabled."},{"value":"1","value_description":"Temperature sensor enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"0","field_description":"","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"ADC_EN","field_description":"ADC enable. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"ADC disabled"},{"value":"1","value_description":"ADC enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"TEMP_EN","field_description":"Temperature sensor (T) enable. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"T disabled"},{"value":"1","value_description":"T enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Reserved","field_description":"Bits 5:0 shown as 0 in the register bit table; no function described.","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.954062=\mathbf{0.985626}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.985626) = **0.985626**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TEMP_CFG_REG | TEMP_CFG_REG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":""} | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Temperature/ADC configuration register address"}] |
| `register_description` | 0.0564 | 1.000000 | Enables the auxiliary ADC and temperature sensor. | Temperature sensor and auxiliary ADC enable register. ADC_EN (bit 7) enables the auxiliary ADC and TEMP_EN (bit 6) enables the temperature sensor on ADC channel 3. Auxiliary ADC operation additionally requires BDU (bit 7) in CTRL_REG4 (23h); sampling frequency equals ODR in CTRL_REG1 (20h). Refer to Section 3.7 for the auxiliary ADC and temperature sensor workflow. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.985626 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{10})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.985626 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.995806/1.0001=\mathbf{0.995707}\).

## Extracted logical register 11: `CTRL_REG1`

v11 location: `registers[10]`; truth association: `registers[7]` (`CTRL_REG1`).

Associated physical locations: 0x20 (32).


### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG1` at 0x20 (32)

Locations: `truth registers[7].field_parts` ↔ `v11 registers[10].field_parts[0]`.

**Truth bit field 1: `ODR[3:0]` bits 7:4**

Locations: `truth registers[7].field_parts.bit_field[0]` ↔ `v11 registers[10].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ODR[3:0] | ODR[3:0] |
| `field_description` | 0.0586 | 0.5 | Data-rate and power-mode selection. | Data rate selection. Default value: 0000 |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 0.5 | [{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}] | [{"value":"0000","value_description":"power-down mode"},{"value":"others","value_description":"Refer to Table 31: Data rate configuration (page 34) for HR/Normal/Low-power mode frequencies"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.5 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.807450/0.9999=\mathbf{0.807531}\).

**Truth bit field 2: `LPen` bits 3:3**

Locations: `truth registers[7].field_parts.bit_field[1]` ↔ `v11 registers[10].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LPen | LPen |
| `field_description` | 0.0586 | 1.0 | Low-power mode enable. | Low-power mode enable. Default value: 0 (refer to Section 3.2.1: High-resolution, normal mode, low-power mode) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"High-resolution mode / normal mode."},{"value":"1","value_description":"Low-power mode."}] | [{"value":"0","value_description":"high-resolution mode / normal mode"},{"value":"1","value_description":"low-power mode"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `Zen` bits 2:2**

Locations: `truth registers[7].field_parts.bit_field[2]` ↔ `v11 registers[10].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Zen | Zen |
| `field_description` | 0.0586 | 1.0 | Z-axis enable. | Z-axis enable. Default value: 1 |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Z-axis disabled."},{"value":"1","value_description":"Z-axis enabled."}] | [{"value":"0","value_description":"Z-axis disabled"},{"value":"1","value_description":"Z-axis enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `Yen` bits 1:1**

Locations: `truth registers[7].field_parts.bit_field[3]` ↔ `v11 registers[10].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Yen | Yen |
| `field_description` | 0.0586 | 1.0 | Y-axis enable. | Y-axis enable. Default value: 1 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Y-axis disabled."},{"value":"1","value_description":"Y-axis enabled."}] | [{"value":"0","value_description":"Y-axis disabled"},{"value":"1","value_description":"Y-axis enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `Xen` bits 0:0**

Locations: `truth registers[7].field_parts.bit_field[4]` ↔ `v11 registers[10].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Xen | Xen |
| `field_description` | 0.0586 | 1.0 | X-axis enable. | X-axis enable. Default value: 1 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"X-axis disabled."},{"value":"1","value_description":"X-axis enabled."}] | [{"value":"0","value_description":"X-axis disabled"},{"value":"1","value_description":"X-axis enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.914861.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG1 | CTRL_REG1 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":""} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Control register 1 address"} |
| `description` | 0.0693 | 1.000000 | "" | Data rate, power mode and axis enable control |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.914861 | [{"name_or_parameter":"ODR[3:0]","field_description":"Data-rate and power-mode selection.","bit_start":4,"bit_end":7,"bit_width":4,"values":[{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LPen","field_description":"Low-power mode enable.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution mode / normal mode."},{"value":"1","value_description":"Low-power mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Zen","field_description":"Z-axis enable.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Z-axis disabled."},{"value":"1","value_description":"Z-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Yen","field_description":"Y-axis enable.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Y-axis disabled."},{"value":"1","value_description":"Y-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Xen","field_description":"X-axis enable.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"X-axis disabled."},{"value":"1","value_description":"X-axis enabled."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"ODR[3:0]","field_description":"Data rate selection. Default value: 0000","bit_start":4,"bit_end":7,"bit_width":4,"values":[{"value":"0000","value_description":"power-down mode"},{"value":"others","value_description":"Refer to Table 31: Data rate configuration (page 34) for HR/Normal/Low-power mode frequencies"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"LPen","field_description":"Low-power mode enable. Default value: 0 (refer to Section 3.2.1: High-resolution, normal mode, low-power mode)","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"high-resolution mode / normal mode"},{"value":"1","value_description":"low-power mode"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Zen","field_description":"Z-axis enable. Default value: 1","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Z-axis disabled"},{"value":"1","value_description":"Z-axis enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Yen","field_description":"Y-axis enable. Default value: 1","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Y-axis disabled"},{"value":"1","value_description":"Y-axis enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Xen","field_description":"X-axis enable. Default value: 1","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"X-axis disabled"},{"value":"1","value_description":"X-axis enabled"}],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.914861=\mathbf{0.973360}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.973360) = **0.973360**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG1 | CTRL_REG1 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":""} | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Control register 1 address"}] |
| `register_description` | 0.0564 | 1.000000 | Selects output data rate and power mode and enables the X, Y and Z axes. | Control register 1: ODR[3:0] selects power mode and output data rate, LPen enables low-power mode, and Xen/Yen/Zen enable the X/Y/Z axes. ODR encoding and power-mode frequencies are defined in Table 31 (Data rate configuration) on page 34; retrieve that table for the full frequency list. LPen also affects auxiliary ADC resolution (Section 3.7). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.973360 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000111 | 00000111 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{11})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.973360 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.992143/1.0001=\mathbf{0.992043}\).

## Extracted logical register 12: `CTRL_REG2`

v11 location: `registers[11]`; truth association: `registers[8]` (`CTRL_REG2`).

Associated physical locations: 0x21 (33).


### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG2` at 0x21 (33)

Locations: `truth registers[8].field_parts` ↔ `v11 registers[11].field_parts[0]`.

**Truth bit field 1: `HPM[1:0]` bits 7:6**

Locations: `truth registers[8].field_parts.bit_field[0]` ↔ `v11 registers[11].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | HPM[1:0] | HPM[1:0] |
| `field_description` | 0.0586 | 1.0 | High-pass filter mode selection. | High-pass filter mode selection. Default value: 00 |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"Normal mode, reset by reading REFERENCE (26h)."},{"value":"01","value_description":"Reference signal for filtering."},{"value":"10","value_description":"Normal mode."},{"value":"11","value_description":"Autoreset on interrupt event."}] | [{"value":"00","value_description":"Normal mode (reset by reading REFERENCE (26h))"},{"value":"01","value_description":"Reference signal for filtering"},{"value":"10","value_description":"Normal mode"},{"value":"11","value_description":"Autoreset on interrupt event"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `HPCF[2:1]` bits 5:4**

Locations: `truth registers[8].field_parts.bit_field[1]` ↔ `v11 registers[11].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | HPCF[2:1] | HPCF[2:1] |
| `field_description` | 0.0586 | 1.0 | High-pass filter cutoff-frequency selection. | High-pass filter cutoff frequency selection |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `FDS` bits 3:3**

Locations: `truth registers[8].field_parts.bit_field[2]` ↔ `v11 registers[11].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FDS | FDS |
| `field_description` | 0.0586 | 1.0 | Filtered data selection. | Filtered data selection. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Internal filter bypassed."},{"value":"1","value_description":"Data from the internal filter sent to the output register and FIFO."}] | [{"value":"0","value_description":"internal filter bypassed"},{"value":"1","value_description":"data from internal filter sent to output register and FIFO"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `HPCLICK` bits 2:2**

Locations: `truth registers[8].field_parts.bit_field[3]` ↔ `v11 registers[11].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | HPCLICK | HPCLICK |
| `field_description` | 0.0586 | 1.0 | High-pass filter enable for the CLICK function. | High-pass filter enabled for CLICK function |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | [{"value":"0","value_description":"filter bypassed"},{"value":"1","value_description":"filter enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `HP_IA2` bits 1:1**

Locations: `truth registers[8].field_parts.bit_field[4]` ↔ `v11 registers[11].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | HP_IA2 | HP_IA2 |
| `field_description` | 0.0586 | 1.0 | High-pass filter enable for the AOI function on interrupt 2. | High-pass filter enabled for AOI function on interrupt 2 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | [{"value":"0","value_description":"filter bypassed"},{"value":"1","value_description":"filter enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 6: `HP_IA1` bits 0:0**

Locations: `truth registers[8].field_parts.bit_field[5]` ↔ `v11 registers[11].field_parts[0].bit_field[5]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | HP_IA1 | HP_IA1 |
| `field_description` | 0.0586 | 1.0 | High-pass filter enable for the AOI function on interrupt 1. | High-pass filter enabled for AOI function on interrupt 1 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}] | [{"value":"0","value_description":"filter bypassed"},{"value":"1","value_description":"filter enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.941694.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG2 | CTRL_REG2 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":""} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"Control register 2 address"} |
| `description` | 0.0693 | 1.000000 | "" | High-pass filter mode, cutoff and routing control |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | [{"name_or_parameter":"HPM[1:0]","field_description":"High-pass filter mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode, reset by reading REFERENCE (26h)."},{"value":"01","value_description":"Reference signal for filtering."},{"value":"10","value_description":"Normal mode."},{"value":"11","value_description":"Autoreset on interrupt event."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCF[2:1]","field_description":"High-pass filter cutoff-frequency selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FDS","field_description":"Filtered data selection.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Internal filter bypassed."},{"value":"1","value_description":"Data from the internal filter sent to the output register and FIFO."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCLICK","field_description":"High-pass filter enable for the CLICK function.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA2","field_description":"High-pass filter enable for the AOI function on interrupt 2.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA1","field_description":"High-pass filter enable for the AOI function on interrupt 1.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"HPM[1:0]","field_description":"High-pass filter mode selection. Default value: 00","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode (reset by reading REFERENCE (26h))"},{"value":"01","value_description":"Reference signal for filtering"},{"value":"10","value_description":"Normal mode"},{"value":"11","value_description":"Autoreset on interrupt event"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"HPCF[2:1]","field_description":"High-pass filter cutoff frequency selection","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"FDS","field_description":"Filtered data selection. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"internal filter bypassed"},{"value":"1","value_description":"data from internal filter sent to output register and FIFO"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"HPCLICK","field_description":"High-pass filter enabled for CLICK function","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"filter bypassed"},{"value":"1","value_description":"filter enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"HP_IA2","field_description":"High-pass filter enabled for AOI function on interrupt 2","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"filter bypassed"},{"value":"1","value_description":"filter enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"HP_IA1","field_description":"High-pass filter enabled for AOI function on interrupt 1","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"filter bypassed"},{"value":"1","value_description":"filter enabled"}],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.981756}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.981756) = **0.981756**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG2 | CTRL_REG2 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":""} | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"Control register 2 address"}] |
| `register_description` | 0.0564 | 1.000000 | Configures the high-pass filter and its routing to output, FIFO, click and interrupt functions. | Control register 2: high-pass filter configuration. HPM[1:0] selects the high-pass filter mode (modes in Table 34, page 35), HPCF[2:1] selects the cutoff frequency, FDS routes filtered data to the output registers and FIFO, and HPCLICK/HP_IA2/HP_IA1 enable the high-pass filter for the CLICK and interrupt AOI functions. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.981756 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{12})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.994651/1.0001=\mathbf{0.994551}\).

## Extracted logical register 13: `CTRL_REG3`

v11 location: `registers[12]`; truth association: `registers[9]` (`CTRL_REG3`).

Associated physical locations: 0x22 (34).


### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG3` at 0x22 (34)

Locations: `truth registers[9].field_parts` ↔ `v11 registers[12].field_parts[0]`.

**Truth bit field 1: `I1_CLICK` bits 7:7**

Locations: `truth registers[9].field_parts.bit_field[0]` ↔ `v11 registers[12].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I1_CLICK | I1_CLICK |
| `field_description` | 0.0586 | 1.0 | Click interrupt on INT1. | Click interrupt on INT1. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `I1_IA1` bits 6:6**

Locations: `truth registers[9].field_parts.bit_field[1]` ↔ `v11 registers[12].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I1_IA1 | I1_IA1 |
| `field_description` | 0.0586 | 1.0 | IA1 interrupt on INT1. | IA1 interrupt on INT1. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `I1_IA2` bits 5:5**

Locations: `truth registers[9].field_parts.bit_field[2]` ↔ `v11 registers[12].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I1_IA2 | I1_IA2 |
| `field_description` | 0.0586 | 1.0 | IA2 interrupt on INT1. | IA2 interrupt on INT1. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `I1_ZYXDA` bits 4:4**

Locations: `truth registers[9].field_parts.bit_field[3]` ↔ `v11 registers[12].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I1_ZYXDA | I1_ZYXDA |
| `field_description` | 0.0586 | 1.0 | ZYXDA interrupt on INT1. | ZYXDA interrupt on INT1. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `I1_321DA` bits 3:3**

Locations: `truth registers[9].field_parts.bit_field[4]` ↔ `v11 registers[12].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I1_321DA | I1_321DA |
| `field_description` | 0.0586 | 1.0 | 321DA interrupt on INT1. | 321DA interrupt on INT1. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 6: `I1_WTM` bits 2:2**

Locations: `truth registers[9].field_parts.bit_field[5]` ↔ `v11 registers[12].field_parts[0].bit_field[5]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I1_WTM | I1_WTM |
| `field_description` | 0.0586 | 1.0 | FIFO watermark interrupt on INT1. | FIFO watermark interrupt on INT1. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 7: `I1_OVERRUN` bits 1:1**

Locations: `truth registers[9].field_parts.bit_field[6]` ↔ `v11 registers[12].field_parts[0].bit_field[6]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I1_OVERRUN | I1_OVERRUN |
| `field_description` | 0.0586 | 1.0 | FIFO overrun interrupt on INT1. | FIFO overrun interrupt on INT1. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}] | [{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 8: `--` bits 0:0**

Locations: `truth registers[9].field_parts.bit_field[7]` ↔ `v11 registers[12].field_parts[0].bit_field[7]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | -- | -- |
| `field_description` | 0.0586 | 1.0 | "" | Bit 0 shown as '--' in the register bit table; no function described. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = 0.948982.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG3 | CTRL_REG3 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x22","decimal":"34","bank":"","page":"","description":""} | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Control register 3 address"} |
| `description` | 0.0693 | 1.000000 | "" | INT1 pin interrupt source enables |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.948982 | [{"name_or_parameter":"I1_CLICK","field_description":"Click interrupt on INT1.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA1","field_description":"IA1 interrupt on INT1.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA2","field_description":"IA2 interrupt on INT1.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_ZYXDA","field_description":"ZYXDA interrupt on INT1.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_321DA","field_description":"321DA interrupt on INT1.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_WTM","field_description":"FIFO watermark interrupt on INT1.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_OVERRUN","field_description":"FIFO overrun interrupt on INT1.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"I1_CLICK","field_description":"Click interrupt on INT1. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I1_IA1","field_description":"IA1 interrupt on INT1. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I1_IA2","field_description":"IA2 interrupt on INT1. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I1_ZYXDA","field_description":"ZYXDA interrupt on INT1. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I1_321DA","field_description":"321DA interrupt on INT1. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I1_WTM","field_description":"FIFO watermark interrupt on INT1. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I1_OVERRUN","field_description":"FIFO overrun interrupt on INT1. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"--","field_description":"Bit 0 shown as '--' in the register bit table; no function described.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.948982=\mathbf{0.984037}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.984037) = **0.984037**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG3 | CTRL_REG3 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x22","decimal":"34","bank":"","page":"","description":""} | [{"hex":"0x22","decimal":"34","bank":"","page":"","description":"Control register 3 address"}] |
| `register_description` | 0.0564 | 0.500000 | Routes click, inertial, data-ready, FIFO watermark and FIFO overrun interrupts to INT1. | Control register 3: enables the interrupt sources routed to the INT1 pin (click, IA1, IA2, ZYXDA, 321DA, FIFO watermark and FIFO overrun). FIFO watermark/overrun behavior is described with FIFO_CTRL_REG (2Eh) and FIFO_SRC_REG (2Fh) in Section 5.1. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.984037 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{13})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.984037 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.967132/1.0001=\mathbf{0.967035}\).

## Extracted logical register 14: `CTRL_REG4`

v11 location: `registers[13]`; truth association: `registers[10]` (`CTRL_REG4`).

Associated physical locations: 0x23 (35).


### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG4` at 0x23 (35)

Locations: `truth registers[10].field_parts` ↔ `v11 registers[13].field_parts[0]`.

**Truth bit field 1: `BDU` bits 7:7**

Locations: `truth registers[10].field_parts.bit_field[0]` ↔ `v11 registers[13].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | BDU | BDU |
| `field_description` | 0.0586 | 1.0 | Block data update. | Block data update. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Continuous update."},{"value":"1","value_description":"Output registers are not updated until MSB and LSB have been read."}] | [{"value":"0","value_description":"continuous update"},{"value":"1","value_description":"output registers not updated until MSB and LSB reading"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `BLE` bits 6:6**

Locations: `truth registers[10].field_parts.bit_field[1]` ↔ `v11 registers[13].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | BLE | BLE |
| `field_description` | 0.0586 | 1.0 | Big/little endian data selection; available only in high-resolution mode. | Big/little endian data selection. Default value 0. The BLE function can be activated only in high-resolution mode. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Data LSB at lower address."},{"value":"1","value_description":"Data MSB at lower address."}] | [{"value":"0","value_description":"Data LSB @ lower address"},{"value":"1","value_description":"Data MSB @ lower address"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `FS[1:0]` bits 5:4**

Locations: `truth registers[10].field_parts.bit_field[2]` ↔ `v11 registers[13].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FS[1:0] | FS[1:0] |
| `field_description` | 0.0586 | 1.0 | Full-scale selection. | Full-scale selection. Default value: 00 |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"±2 g."},{"value":"01","value_description":"±4 g."},{"value":"10","value_description":"±8 g."},{"value":"11","value_description":"±16 g."}] | [{"value":"00","value_description":"±2 g"},{"value":"01","value_description":"±4 g"},{"value":"10","value_description":"±8 g"},{"value":"11","value_description":"±16 g"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `HR` bits 3:3**

Locations: `truth registers[10].field_parts.bit_field[3]` ↔ `v11 registers[13].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | HR | HR |
| `field_description` | 0.0586 | 1.0 | High-resolution output mode. | High-resolution output mode. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"High-resolution disabled."},{"value":"1","value_description":"High-resolution enabled."}] | [{"value":"0","value_description":"high-resolution disabled"},{"value":"1","value_description":"high-resolution enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `ST[1:0]` bits 2:1**

Locations: `truth registers[10].field_parts.bit_field[4]` ↔ `v11 registers[13].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ST[1:0] | ST[1:0] |
| `field_description` | 0.0586 | 1.0 | Self-test enable. | Self-test enable. Default value: 00 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 0.5 | [{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}] | [{"value":"00","value_description":"self-test disabled (Normal mode)"},{"value":"other","value_description":"See Table 39: Self-test mode configuration (page 36): 01 Self-test 0, 10 Self-test 1, 11 --"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.5 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.836750/0.9999=\mathbf{0.836834}\).

**Truth bit field 6: `SIM` bits 0:0**

Locations: `truth registers[10].field_parts.bit_field[5]` ↔ `v11 registers[13].field_parts[0].bit_field[5]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SIM | SIM |
| `field_description` | 0.0586 | 1.0 | SPI serial-interface mode selection. | SPI serial interface mode selection. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}] | [{"value":"0","value_description":"4-wire interface"},{"value":"1","value_description":"3-wire interface"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.924217.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG4 | CTRL_REG4 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x23","decimal":"35","bank":"","page":"","description":""} | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"Control register 4 address"} |
| `description` | 0.0693 | 1.000000 | "" | BDU, endianness, full-scale, resolution, self-test and SPI mode control |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.924217 | [{"name_or_parameter":"BDU","field_description":"Block data update.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Continuous update."},{"value":"1","value_description":"Output registers are not updated until MSB and LSB have been read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BLE","field_description":"Big/little endian data selection; available only in high-resolution mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Data LSB at lower address."},{"value":"1","value_description":"Data MSB at lower address."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FS[1:0]","field_description":"Full-scale selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[{"value":"00","value_description":"±2 g."},{"value":"01","value_description":"±4 g."},{"value":"10","value_description":"±8 g."},{"value":"11","value_description":"±16 g."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HR","field_description":"High-resolution output mode.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution disabled."},{"value":"1","value_description":"High-resolution enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ST[1:0]","field_description":"Self-test enable.","bit_start":1,"bit_end":2,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SIM","field_description":"SPI serial-interface mode selection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"BDU","field_description":"Block data update. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"continuous update"},{"value":"1","value_description":"output registers not updated until MSB and LSB reading"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"BLE","field_description":"Big/little endian data selection. Default value 0. The BLE function can be activated only in high-resolution mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Data LSB @ lower address"},{"value":"1","value_description":"Data MSB @ lower address"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"FS[1:0]","field_description":"Full-scale selection. Default value: 00","bit_start":4,"bit_end":5,"bit_width":2,"values":[{"value":"00","value_description":"±2 g"},{"value":"01","value_description":"±4 g"},{"value":"10","value_description":"±8 g"},{"value":"11","value_description":"±16 g"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"HR","field_description":"High-resolution output mode. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"high-resolution disabled"},{"value":"1","value_description":"high-resolution enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ST[1:0]","field_description":"Self-test enable. Default value: 00","bit_start":1,"bit_end":2,"bit_width":2,"values":[{"value":"00","value_description":"self-test disabled (Normal mode)"},{"value":"other","value_description":"See Table 39: Self-test mode configuration (page 36): 01 Self-test 0, 10 Self-test 1, 11 --"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"SIM","field_description":"SPI serial interface mode selection. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"4-wire interface"},{"value":"1","value_description":"3-wire interface"}],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.924217=\mathbf{0.976288}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.976288) = **0.976288**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG4 | CTRL_REG4 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x23","decimal":"35","bank":"","page":"","description":""} | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"Control register 4 address"}] |
| `register_description` | 0.0564 | 1.000000 | Configures block data update, byte order, full scale, high-resolution mode, self-test and SPI interface mode. | Control register 4: BDU controls block data update of the output registers, BLE selects big/little-endian data order (activatable only in high-resolution mode), FS[1:0] selects full scale, HR enables high-resolution output mode, ST[1:0] selects the self-test mode (Table 39, page 36), and SIM selects the SPI interface mode. BDU must be set to 1 to use the auxiliary ADC (Section 3.7). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.976288 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{14})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.976288 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.993017/1.0001=\mathbf{0.992918}\).

## Extracted logical register 15: `CTRL_REG5`

v11 location: `registers[14]`; truth association: `registers[11]` (`CTRL_REG5`).

Associated physical locations: 0x24 (36).


### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG5` at 0x24 (36)

Locations: `truth registers[11].field_parts` ↔ `v11 registers[14].field_parts[0]`.

**Truth bit field 1: `BOOT` bits 7:7**

Locations: `truth registers[11].field_parts.bit_field[0]` ↔ `v11 registers[14].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | BOOT | BOOT |
| `field_description` | 0.0586 | 1.0 | Reboot memory content. | Reboot memory content. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Normal mode."},{"value":"1","value_description":"Reboot memory content."}] | [{"value":"0","value_description":"normal mode"},{"value":"1","value_description":"reboot memory content"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `FIFO_EN` bits 6:6**

Locations: `truth registers[11].field_parts.bit_field[1]` ↔ `v11 registers[14].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_EN | FIFO_EN |
| `field_description` | 0.0586 | 1.0 | FIFO enable. | FIFO enable. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"FIFO disabled."},{"value":"1","value_description":"FIFO enabled."}] | [{"value":"0","value_description":"FIFO disable"},{"value":"1","value_description":"FIFO enable"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `--` bits 5:4**

Locations: `truth registers[11].field_parts.bit_field[2]` ↔ missing. Judgment: truth bit field is missing from the extraction.

| Scored field | Weight | C | Truth content | Extracted content |
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

Locations: `truth registers[11].field_parts.bit_field[3]` ↔ `v11 registers[14].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LIR_INT1 | LIR_INT1 |
| `field_description` | 0.0586 | 1.0 | Latch interrupt request on INT1_SRC; reading INT1_SRC clears it. | Latch interrupt request on INT1_SRC register, with INT1_SRC (31h) cleared by reading INT1_SRC itself. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}] | [{"value":"0","value_description":"interrupt request not latched"},{"value":"1","value_description":"interrupt request latched"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `D4D_INT1` bits 2:2**

Locations: `truth registers[11].field_parts.bit_field[4]` ↔ `v11 registers[14].field_parts[0].bit_field[5]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | D4D_INT1 | D4D_INT1 |
| `field_description` | 0.0586 | 1.0 | Enable 4D detection on INT1 when the INT1_CFG 6D bit is set. | 4D enable: 4D detection is enabled on INT1 when 6D bit on INT1_CFG is set to 1 |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 6: `LIR_INT2` bits 1:1**

Locations: `truth registers[11].field_parts.bit_field[5]` ↔ `v11 registers[14].field_parts[0].bit_field[6]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LIR_INT2 | LIR_INT2 |
| `field_description` | 0.0586 | 1.0 | Latch interrupt request on INT2_SRC; reading INT2_SRC clears it. | Latch interrupt request on INT2_SRC (35h) register, with INT2_SRC cleared by reading INT2_SRC itself. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}] | [{"value":"0","value_description":"interrupt request not latched"},{"value":"1","value_description":"interrupt request latched"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 7: `D4D_INT2` bits 0:0**

Locations: `truth registers[11].field_parts.bit_field[6]` ↔ `v11 registers[14].field_parts[0].bit_field[7]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | D4D_INT2 | D4D_INT2 |
| `field_description` | 0.0586 | 1.0 | Enable 4D detection on INT2 when the INT2_CFG 6D bit is set. | 4D enable: 4D detection is enabled on INT2 pin when 6D bit on INT2_CFG (34h) is set to 1 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

Additional v11 bit field not matched to a truth range: `v11 registers[14].field_parts[0].bit_field[2]` (`--`, bits 5:5). It is reported but not credited.

Additional v11 bit field not matched to a truth range: `v11 registers[14].field_parts[0].bit_field[3]` (`--`, bits 4:4). It is reported but not credited.

**Field-part aggregation**

`bit_field` correctness = 0.807166.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG5 | CTRL_REG5 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x24","decimal":"36","bank":"","page":"","description":""} | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Control register 5 address"} |
| `description` | 0.0693 | 1.000000 | "" | Boot, FIFO enable and interrupt latch/4D control |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.807166 | [{"name_or_parameter":"BOOT","field_description":"Reboot memory content.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Normal mode."},{"value":"1","value_description":"Reboot memory content."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FIFO_EN","field_description":"FIFO enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"FIFO disabled."},{"value":"1","value_description":"FIFO enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT1","field_description":"Latch interrupt request on INT1_SRC; reading INT1_SRC clears it.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT1","field_description":"Enable 4D detection on INT1 when the INT1_CFG 6D bit is set.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT2","field_description":"Latch interrupt request on INT2_SRC; reading INT2_SRC clears it.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT2","field_description":"Enable 4D detection on INT2 when the INT2_CFG 6D bit is set.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"BOOT","field_description":"Reboot memory content. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"normal mode"},{"value":"1","value_description":"reboot memory content"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"FIFO_EN","field_description":"FIFO enable. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"FIFO disable"},{"value":"1","value_description":"FIFO enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"--","field_description":"Bit 5 shown as '--' in the register bit table; no function described.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"--","field_description":"Bit 4 shown as '--' in the register bit table; no function described.","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"LIR_INT1","field_description":"Latch interrupt request on INT1_SRC register, with INT1_SRC (31h) cleared by reading INT1_SRC itself. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"interrupt request not latched"},{"value":"1","value_description":"interrupt request latched"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"D4D_INT1","field_description":"4D enable: 4D detection is enabled on INT1 when 6D bit on INT1_CFG is set to 1","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"LIR_INT2","field_description":"Latch interrupt request on INT2_SRC (35h) register, with INT2_SRC cleared by reading INT2_SRC itself. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"interrupt request not latched"},{"value":"1","value_description":"interrupt request latched"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"D4D_INT2","field_description":"4D enable: 4D detection is enabled on INT2 pin when 6D bit on INT2_CFG (34h) is set to 1","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.807166=\mathbf{0.939662}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.939662) = **0.939662**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG5 | CTRL_REG5 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x24","decimal":"36","bank":"","page":"","description":""} | [{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Control register 5 address"}] |
| `register_description` | 0.0564 | 1.000000 | Controls memory reboot, FIFO enable, interrupt latching and 4D detection. | Control register 5: BOOT reboots memory content, FIFO_EN enables the FIFO buffer (required before selecting FIFO modes in FIFO_CTRL_REG (2Eh)), LIR_INT1/LIR_INT2 latch the interrupt requests on INT1_SRC/INT2_SRC, and D4D_INT1/D4D_INT2 enable 4D detection when the 6D bit is set in INT1_CFG/INT2_CFG. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.939662 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{15})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.939662 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.982077/1.0001=\mathbf{0.981979}\).

## Extracted logical register 16: `CTRL_REG6`

v11 location: `registers[15]`; truth association: `registers[12]` (`CTRL_REG6`).

Associated physical locations: 0x25 (37).


### Bottom layer: bit fields, then field parts

#### Field part 1: `CTRL_REG6` at 0x25 (37)

Locations: `truth registers[12].field_parts` ↔ `v11 registers[15].field_parts[0]`.

**Truth bit field 1: `I2_CLICK` bits 7:7**

Locations: `truth registers[12].field_parts.bit_field[0]` ↔ `v11 registers[15].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2_CLICK | I2_CLICK |
| `field_description` | 0.0586 | 1.0 | Click interrupt on INT2 pin. | Click interrupt on INT2 pin. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}] | [{"value":"0","value_description":"disabled"},{"value":"1","value_description":"enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `I2_IA1` bits 6:6**

Locations: `truth registers[12].field_parts.bit_field[1]` ↔ `v11 registers[15].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2_IA1 | I2_IA1 |
| `field_description` | 0.0586 | 1.0 | Enable interrupt 1 function on INT2 pin. | Enable interrupt 1 function on INT2 pin. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}] | [{"value":"0","value_description":"function disabled"},{"value":"1","value_description":"function enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | I2_CLICK | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `I2_IA2` bits 5:5**

Locations: `truth registers[12].field_parts.bit_field[2]` ↔ `v11 registers[15].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2_IA2 | I2_IA2 |
| `field_description` | 0.0586 | 1.0 | Enable interrupt 2 function on INT2 pin. | Enable interrupt 2 function on INT2 pin. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}] | [{"value":"0","value_description":"function disabled"},{"value":"1","value_description":"function enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | I2_CLICK | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `I2_BOOT` bits 4:4**

Locations: `truth registers[12].field_parts.bit_field[3]` ↔ `v11 registers[15].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2_BOOT | I2_BOOT |
| `field_description` | 0.0586 | 1.0 | Enable boot on INT2 pin. | Enable boot on INT2 pin. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}] | [{"value":"0","value_description":"disabled"},{"value":"1","value_description":"enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | I2_CLICK | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `I2_ACT` bits 3:3**

Locations: `truth registers[12].field_parts.bit_field[4]` ↔ `v11 registers[15].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2_ACT | I2_ACT |
| `field_description` | 0.0586 | 1.0 | Enable activity interrupt on INT2 pin. | Enable activity interrupt on INT2 pin. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}] | [{"value":"0","value_description":"disabled"},{"value":"1","value_description":"enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | I2_CLICK | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 6: `--` bits 2:2**

Locations: `truth registers[12].field_parts.bit_field[5]` ↔ `v11 registers[15].field_parts[0].bit_field[5]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | -- | -- |
| `field_description` | 0.0586 | 1.0 | "" | Bit 2 shown as '--' in the register bit table; no function described. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | I2_CLICK | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 7: `INT_POLARITY` bits 1:1**

Locations: `truth registers[12].field_parts.bit_field[6]` ↔ `v11 registers[15].field_parts[0].bit_field[6]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | INT_POLARITY | INT_POLARITY |
| `field_description` | 0.0586 | 1.0 | INT1 and INT2 pin polarity. | INT1 and INT2 pin polarity. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Active-high."},{"value":"1","value_description":"Active-low."}] | [{"value":"0","value_description":"active-high"},{"value":"1","value_description":"active-low"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | I2_CLICK | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 8: `-` bits 0:0**

Locations: `truth registers[12].field_parts.bit_field[7]` ↔ `v11 registers[15].field_parts[0].bit_field[7]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | "" | Bit 0 shown as '-' in the register bit table; no function described. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = 0.948982.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CTRL_REG6 | CTRL_REG6 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x25","decimal":"37","bank":"","page":"","description":""} | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"Control register 6 address"} |
| `description` | 0.0693 | 1.000000 | "" | INT2 pin interrupt source enables and interrupt polarity |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.948982 | [{"name_or_parameter":"I2_CLICK","field_description":"Click interrupt on INT2 pin.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I2_IA1","field_description":"Enable interrupt 1 function on INT2 pin.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_IA2","field_description":"Enable interrupt 2 function on INT2 pin.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_BOOT","field_description":"Enable boot on INT2 pin.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_ACT","field_description":"Enable activity interrupt on INT2 pin.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"--","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"I2_CLICK"},{"name_or_parameter":"INT_POLARITY","field_description":"INT1 and INT2 pin polarity.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Active-high."},{"value":"1","value_description":"Active-low."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"I2_CLICK","field_description":"Click interrupt on INT2 pin. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"disabled"},{"value":"1","value_description":"enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I2_IA1","field_description":"Enable interrupt 1 function on INT2 pin. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"function disabled"},{"value":"1","value_description":"function enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I2_IA2","field_description":"Enable interrupt 2 function on INT2 pin. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"function disabled"},{"value":"1","value_description":"function enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I2_BOOT","field_description":"Enable boot on INT2 pin. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"disabled"},{"value":"1","value_description":"enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I2_ACT","field_description":"Enable activity interrupt on INT2 pin. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"disabled"},{"value":"1","value_description":"enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"--","field_description":"Bit 2 shown as '--' in the register bit table; no function described.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"INT_POLARITY","field_description":"INT1 and INT2 pin polarity. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"active-high"},{"value":"1","value_description":"active-low"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"-","field_description":"Bit 0 shown as '-' in the register bit table; no function described.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.948982=\mathbf{0.984037}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.984037) = **0.984037**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CTRL_REG6 | CTRL_REG6 |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x25","decimal":"37","bank":"","page":"","description":""} | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":"Control register 6 address"}] |
| `register_description` | 0.0564 | 1.000000 | Routes click, inertial, boot and activity signals to INT2 and sets interrupt-pin polarity. | Control register 6: enables the interrupt sources routed to the INT2 pin (click, IA1, IA2, boot, activity) and sets the INT1/INT2 pin polarity. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.984037 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{16})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.984037 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.995332/1.0001=\mathbf{0.995232}\).

## Extracted logical register 17: `REFERENCE`

v11 location: `registers[16]`; truth association: `registers[13]` (`REFERENCE`).

Associated physical locations: 0x26 (38).


### Bottom layer: bit fields, then field parts

#### Field part 1: `REFERENCE` at 0x26 (38)

Locations: `truth registers[13].field_parts` ↔ `v11 registers[16].field_parts[0]`.

**Truth bit field 1: `Ref[7:0]` bits 7:0**

Locations: `truth registers[13].field_parts.bit_field[0]` ↔ `v11 registers[16].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Ref[7:0] | Ref[7:0] |
| `field_description` | 0.0586 | 1.0 | Reference value for interrupt generation. | Reference value for Interrupt generation. Default value: 0000 0000 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | Ref[7:0] | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.941694.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | REFERENCE | REFERENCE |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x26","decimal":"38","bank":"","page":"","description":""} | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Reference register address"} |
| `description` | 0.0693 | 1.000000 | "" | Interrupt generation reference value |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | {"name_or_parameter":"Ref[7:0]","field_description":"Reference value for interrupt generation.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"Ref[7:0]"} | [{"name_or_parameter":"Ref[7:0]","field_description":"Reference value for Interrupt generation. Default value: 0000 0000","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.981756}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.981756) = **0.981756**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | REFERENCE | REFERENCE |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x26","decimal":"38","bank":"","page":"","description":""} | [{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Reference register address"}] |
| `register_description` | 0.0564 | 0.500000 | Stores the reference value used for interrupt generation and reference-signal filtering. | Reference value for interrupt generation (Ref[7:0]). Also used by the high-pass filter normal mode, which is reset by reading REFERENCE (see CTRL_REG2 HPM[1:0], Table 34). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.981756 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | Default written in description as 0000 0000. |

\(Q(L_{17})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.966451/1.0001=\mathbf{0.966354}\).

## Extracted logical register 18: `STATUS_REG`

v11 location: `registers[17]`; truth association: `registers[14]` (`STATUS_REG`).

Associated physical locations: 0x27 (39).


### Bottom layer: bit fields, then field parts

#### Field part 1: `STATUS_REG` at 0x27 (39)

Locations: `truth registers[14].field_parts` ↔ `v11 registers[17].field_parts[0]`.

**Truth bit field 1: `ZYXOR` bits 7:7**

Locations: `truth registers[14].field_parts.bit_field[0]` ↔ `v11 registers[17].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZYXOR | ZYXOR |
| `field_description` | 0.0586 | 1.0 | X, Y and Z-axis data overrun. | X, Y and Z-axis data overrun. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}] | [{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"a new set of data has overwritten the previous set"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `ZOR` bits 6:6**

Locations: `truth registers[14].field_parts.bit_field[1]` ↔ `v11 registers[17].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZOR | ZOR |
| `field_description` | 0.0586 | 1.0 | Z-axis data overrun. | Z-axis data overrun. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Z-axis data has overwritten the previous data."}] | [{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"a new data for the Z-axis has overwritten the previous data"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `YOR` bits 5:5**

Locations: `truth registers[14].field_parts.bit_field[2]` ↔ `v11 registers[17].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YOR | YOR |
| `field_description` | 0.0586 | 1.0 | Y-axis data overrun. | Y-axis data overrun. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Y-axis data has overwritten the previous data."}] | [{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the Y-axis has overwritten the previous data"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `XOR` bits 4:4**

Locations: `truth registers[14].field_parts.bit_field[3]` ↔ `v11 registers[17].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XOR | XOR |
| `field_description` | 0.0586 | 1.0 | X-axis data overrun. | X-axis data overrun. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New X-axis data has overwritten the previous data."}] | [{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the X-axis has overwritten the previous data"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `ZYXDA` bits 3:3**

Locations: `truth registers[14].field_parts.bit_field[4]` ↔ `v11 registers[17].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZYXDA | ZYXDA |
| `field_description` | 0.0586 | 1.0 | X, Y and Z-axis new data available. | X, Y and Z-axis new data available. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}] | [{"value":"0","value_description":"a new set of data is not yet available"},{"value":"1","value_description":"a new set of data is available"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 6: `ZDA` bits 2:2**

Locations: `truth registers[14].field_parts.bit_field[5]` ↔ `v11 registers[17].field_parts[0].bit_field[5]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZDA | ZDA |
| `field_description` | 0.0586 | 1.0 | Z-axis new data available. | Z-axis new data available. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"New Z-axis data is not yet available."},{"value":"1","value_description":"New Z-axis data is available."}] | [{"value":"0","value_description":"new data for the Z-axis is not yet available"},{"value":"1","value_description":"new data for the Z-axis is available"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 7: `YDA` bits 1:1**

Locations: `truth registers[14].field_parts.bit_field[6]` ↔ `v11 registers[17].field_parts[0].bit_field[6]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YDA | YDA |
| `field_description` | 0.0586 | 1.0 | Y-axis new data available. | Y-axis new data available. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"New Y-axis data is not yet available."},{"value":"1","value_description":"New Y-axis data is available."}] | [{"value":"0","value_description":"new data for the Y-axis is not yet available"},{"value":"1","value_description":"new data for the Y-axis is available"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 8: `XDA` bits 0:0**

Locations: `truth registers[14].field_parts.bit_field[7]` ↔ `v11 registers[17].field_parts[0].bit_field[7]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XDA | XDA |
| `field_description` | 0.0586 | 1.0 | "" | Bit shown in the STATUS register bit table (X-axis new data available); description row not present in the provided description table. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.941694.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | STATUS_REG | STATUS_REG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x27","decimal":"39","bank":"","page":"","description":""} | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"Accelerometer status register address"} |
| `description` | 0.0693 | 1.000000 | "" | Acceleration data overrun and data-available flags |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | [{"name_or_parameter":"ZYXOR","field_description":"X, Y and Z-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZOR","field_description":"Z-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Z-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YOR","field_description":"Y-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Y-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XOR","field_description":"X-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New X-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZYXDA","field_description":"X, Y and Z-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZDA","field_description":"Z-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New Z-axis data is not yet available."},{"value":"1","value_description":"New Z-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YDA","field_description":"Y-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New Y-axis data is not yet available."},{"value":"1","value_description":"New Y-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XDA","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"ZYXOR","field_description":"X, Y and Z-axis data overrun. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"a new set of data has overwritten the previous set"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZOR","field_description":"Z-axis data overrun. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"a new data for the Z-axis has overwritten the previous data"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YOR","field_description":"Y-axis data overrun. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the Y-axis has overwritten the previous data"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XOR","field_description":"X-axis data overrun. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the X-axis has overwritten the previous data"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZYXDA","field_description":"X, Y and Z-axis new data available. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"a new set of data is not yet available"},{"value":"1","value_description":"a new set of data is available"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZDA","field_description":"Z-axis new data available. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"new data for the Z-axis is not yet available"},{"value":"1","value_description":"new data for the Z-axis is available"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YDA","field_description":"Y-axis new data available. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"new data for the Y-axis is not yet available"},{"value":"1","value_description":"new data for the Y-axis is available"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XDA","field_description":"Bit shown in the STATUS register bit table (X-axis new data available); description row not present in the provided description table.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.981756}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.981756) = **0.981756**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | STATUS_REG | STATUS_REG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x27","decimal":"39","bank":"","page":"","description":""} | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Accelerometer status register address"}] |
| `register_description` | 0.0564 | 0.500000 | Reports acceleration-axis data-overrun and new-data availability status. | Accelerometer data status register: ZYXOR/ZOR/YOR/XOR report data overrun and ZYXDA/ZDA/YDA/XDA report new data availability for the X, Y and Z axes. Related to the OUT_X/OUT_Y/OUT_Z data registers and the Data-Ready (DRDY) signal (Section: Terminology and functionality). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.981756 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{18})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.966451/1.0001=\mathbf{0.966354}\).

## Extracted logical register 19: `OUT_X_L`

v11 location: `registers[18]`; truth association: `registers[15]` (`OUT_X_L (28h), OUT_X_H (29h)`).

Associated physical locations: 0x28 (40).


### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_X_L` at 0x28 (40)

Locations: `truth registers[15].field_parts[0]` ↔ `v11 registers[18].field_parts[0]`.

No truth bit fields are defined for this field part; empty extraction receives bit_field C=1, non-empty extraction receives C=0.

**Field-part aggregation**

`bit_field` correctness = 1.000000.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_X_L | OUT_X_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of X-axis acceleration data."} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"X-axis acceleration data low byte"} |
| `description` | 0.0693 | 1.000000 | Low byte of X-axis acceleration data. | X-axis acceleration data low byte (two's complement left-justified) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_X_L | OUT_X_L |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of X-axis acceleration data."} | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"X-axis acceleration data low byte"}] |
| `register_description` | 0.0564 | 1.000000 | X-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO X-axis data when FIFO is active. | X-axis acceleration data low byte. The value is expressed as two's complement left-justified; paired with OUT_X_H (29h). When the FIFO is enabled, reads from these output registers return FIFO data and the read address auto-increments and rolls back to 0x28 after 0x2D (Section 5.1.5). Refer to Section 3.2.1 for high-resolution/normal/low-power mode data format. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{19})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 20: `OUT_X_H`

v11 location: `registers[19]`; truth association: `registers[15]` (`OUT_X_L (28h), OUT_X_H (29h)`).

Associated physical locations: 0x29 (41).


### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_X_H` at 0x29 (41)

Locations: `truth registers[15].field_parts[1]` ↔ `v11 registers[19].field_parts[0]`.

No truth bit fields are defined for this field part; empty extraction receives bit_field C=1, non-empty extraction receives C=0.

**Field-part aggregation**

`bit_field` correctness = 1.000000.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_X_H | OUT_X_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"High byte of X-axis acceleration data."} | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"X-axis acceleration data high byte"} |
| `description` | 0.0693 | 1.000000 | High byte of X-axis acceleration data. | X-axis acceleration data high byte (two's complement left-justified) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_X_H | OUT_X_H |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x29","decimal":"41","bank":"","page":"","description":"High byte of X-axis acceleration data."} | [{"hex":"0x29","decimal":"41","bank":"","page":"","description":"X-axis acceleration data high byte"}] |
| `register_description` | 0.0564 | 0.500000 | X-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO X-axis data when FIFO is active. | X-axis acceleration data high byte, two's complement left-justified; paired with OUT_X_L (28h). Also provides FIFO output data when FIFO modes are active (Section 5.1.5). Refer to Section 3.2.1 for the operating-mode data format. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{20})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 21: `OUT_Y_L`

v11 location: `registers[20]`; truth association: `registers[16]` (`OUT_Y_L (2Ah), OUT_Y_H (2Bh)`).

Associated physical locations: 0x2A (42).


### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_Y_L` at 0x2A (42)

Locations: `truth registers[16].field_parts[0]` ↔ `v11 registers[20].field_parts[0]`.

No truth bit fields are defined for this field part; empty extraction receives bit_field C=1, non-empty extraction receives C=0.

**Field-part aggregation**

`bit_field` correctness = 1.000000.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Y_L | OUT_Y_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Low byte of Y-axis acceleration data."} | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Y-axis acceleration data low byte"} |
| `description` | 0.0693 | 1.000000 | Low byte of Y-axis acceleration data. | Y-axis acceleration data low byte (two's complement left-justified) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_Y_L | OUT_Y_L |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Low byte of Y-axis acceleration data."} | [{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Y-axis acceleration data low byte"}] |
| `register_description` | 0.0564 | 0.500000 | Y-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Y-axis data when FIFO is active. | Y-axis acceleration data low byte, two's complement left-justified; paired with OUT_Y_H (2Bh). Provides FIFO output data when FIFO modes are active (Section 5.1.5). Refer to Section 3.2.1 for the operating-mode data format. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{21})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 22: `OUT_Y_H`

v11 location: `registers[21]`; truth association: `registers[16]` (`OUT_Y_L (2Ah), OUT_Y_H (2Bh)`).

Associated physical locations: 0x2B (43).


### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_Y_H` at 0x2B (43)

Locations: `truth registers[16].field_parts[1]` ↔ `v11 registers[21].field_parts[0]`.

No truth bit fields are defined for this field part; empty extraction receives bit_field C=1, non-empty extraction receives C=0.

**Field-part aggregation**

`bit_field` correctness = 1.000000.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Y_H | OUT_Y_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"High byte of Y-axis acceleration data."} | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Y-axis acceleration data high byte"} |
| `description` | 0.0693 | 1.000000 | High byte of Y-axis acceleration data. | Y-axis acceleration data high byte (two's complement left-justified) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_Y_H | OUT_Y_H |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"High byte of Y-axis acceleration data."} | [{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Y-axis acceleration data high byte"}] |
| `register_description` | 0.0564 | 0.500000 | Y-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Y-axis data when FIFO is active. | Y-axis acceleration data high byte, two's complement left-justified; paired with OUT_Y_L (2Ah). Provides FIFO output data when FIFO modes are active (Section 5.1.5). Refer to Section 3.2.1 for the operating-mode data format. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{22})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 23: `OUT_Z_L`

v11 location: `registers[22]`; truth association: `registers[17]` (`OUT_Z_L (2Ch), OUT_Z_H (2Dh)`).

Associated physical locations: 0x2C (44).


### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_Z_L` at 0x2C (44)

Locations: `truth registers[17].field_parts[0]` ↔ `v11 registers[22].field_parts[0]`.

No truth bit fields are defined for this field part; empty extraction receives bit_field C=1, non-empty extraction receives C=0.

**Field-part aggregation**

`bit_field` correctness = 1.000000.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Z_L | OUT_Z_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Low byte of Z-axis acceleration data."} | {"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Z-axis acceleration data low byte"} |
| `description` | 0.0693 | 1.000000 | Low byte of Z-axis acceleration data. | Z-axis acceleration data low byte (two's complement left-justified) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_Z_L | OUT_Z_L |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Low byte of Z-axis acceleration data."} | [{"hex":"0x2C","decimal":"44","bank":"","page":"","description":"Z-axis acceleration data low byte"}] |
| `register_description` | 0.0564 | 0.500000 | Z-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Z-axis data when FIFO is active. | Z-axis acceleration data low byte, two's complement left-justified; paired with OUT_Z_H (2Dh). Provides FIFO output data when FIFO modes are active (Section 5.1.5). Refer to Section 3.2.1 for the operating-mode data format. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{23})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 24: `OUT_Z_H`

v11 location: `registers[23]`; truth association: `registers[17]` (`OUT_Z_L (2Ch), OUT_Z_H (2Dh)`).

Associated physical locations: 0x2D (45).


### Bottom layer: bit fields, then field parts

#### Field part 1: `OUT_Z_H` at 0x2D (45)

Locations: `truth registers[17].field_parts[1]` ↔ `v11 registers[23].field_parts[0]`.

No truth bit fields are defined for this field part; empty extraction receives bit_field C=1, non-empty extraction receives C=0.

**Field-part aggregation**

`bit_field` correctness = 1.000000.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | OUT_Z_H | OUT_Z_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"High byte of Z-axis acceleration data."} | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Z-axis acceleration data high byte"} |
| `description` | 0.0693 | 1.000000 | High byte of Z-axis acceleration data. | Z-axis acceleration data high byte (two's complement left-justified) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | [] | [] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | OUT_Z_H | OUT_Z_H |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x2D","decimal":"45","bank":"","page":"","description":"High byte of Z-axis acceleration data."} | [{"hex":"0x2D","decimal":"45","bank":"","page":"","description":"Z-axis acceleration data high byte"}] |
| `register_description` | 0.0564 | 0.500000 | Z-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Z-axis data when FIFO is active. | Z-axis acceleration data high byte, two's complement left-justified; paired with OUT_Z_L (2Ch). Provides FIFO output data when FIFO modes are active; the auto-incremented read address rolls back to 0x28 after 0x2D (Section 5.1.5). Refer to Section 3.2.1 for the operating-mode data format. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{24})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.971900/1.0001=\mathbf{0.971803}\).

## Extracted logical register 25: `FIFO_CTRL_REG`

v11 location: `registers[24]`; truth association: `registers[18]` (`FIFO_CTRL_REG`).

Associated physical locations: 0x2E (46).


### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_CTRL_REG` at 0x2E (46)

Locations: `truth registers[18].field_parts` ↔ `v11 registers[24].field_parts[0]`.

**Truth bit field 1: `FM[1:0]` bits 7:6**

Locations: `truth registers[18].field_parts.bit_field[0]` ↔ `v11 registers[24].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FM[1:0] | FM[1:0] |
| `field_description` | 0.0586 | 1.0 | FIFO mode selection. | FIFO mode selection. Default value: 00 |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"Bypass mode."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Stream-to-FIFO mode."}] | [{"value":"00","value_description":"Bypass mode"},{"value":"01","value_description":"FIFO mode"},{"value":"10","value_description":"Stream mode"},{"value":"11","value_description":"Stream-to-FIFO"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `TR` bits 5:5**

Locations: `truth registers[18].field_parts.bit_field[1]` ↔ `v11 registers[24].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TR | TR |
| `field_description` | 0.0586 | 0.5 | Trigger selection for Stream-to-FIFO mode. | Trigger selection. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Triggering signal on INT1."},{"value":"1","value_description":"Triggering signal on INT2."}] | [{"value":"0","value_description":"trigger event allows triggering signal on INT1"},{"value":"1","value_description":"trigger event allows triggering signal on INT2"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Truth bit field 3: `FTH[4:0]` bits 4:0**

Locations: `truth registers[18].field_parts.bit_field[2]` ↔ `v11 registers[24].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FTH[4:0] | FTH[4:0] |
| `field_description` | 0.0586 | 1.0 | Programmable FIFO watermark threshold. | FIFO watermark threshold. Default value: 00000 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.931927.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | FIFO_CTRL_REG | FIFO_CTRL_REG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":""} | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":"FIFO control register address"} |
| `description` | 0.0693 | 1.000000 | "" | FIFO mode, trigger selection and watermark threshold |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.931927 | [{"name_or_parameter":"FM[1:0]","field_description":"FIFO mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass mode."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Stream-to-FIFO mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TR","field_description":"Trigger selection for Stream-to-FIFO mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Triggering signal on INT1."},{"value":"1","value_description":"Triggering signal on INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FTH[4:0]","field_description":"Programmable FIFO watermark threshold.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"FM[1:0]","field_description":"FIFO mode selection. Default value: 00","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass mode"},{"value":"01","value_description":"FIFO mode"},{"value":"10","value_description":"Stream mode"},{"value":"11","value_description":"Stream-to-FIFO"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"TR","field_description":"Trigger selection. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"trigger event allows triggering signal on INT1"},{"value":"1","value_description":"trigger event allows triggering signal on INT2"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"FTH[4:0]","field_description":"FIFO watermark threshold. Default value: 00000","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.931927=\mathbf{0.978700}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.978700) = **0.978700**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | FIFO_CTRL_REG | FIFO_CTRL_REG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":""} | [{"hex":"0x2E","decimal":"46","bank":"","page":"","description":"FIFO control register address"}] |
| `register_description` | 0.0564 | 1.000000 | Selects FIFO operating mode, Stream-to-FIFO trigger source and FIFO watermark threshold. | FIFO control register: FM[1:0] selects the FIFO operating mode (Bypass, FIFO, Stream, Stream-to-FIFO; Table 50, page 39), TR selects whether the Stream-to-FIFO trigger signal uses the INT1 or INT2 pin, and FTH[4:0] sets the programmable FIFO watermark level. The FIFO must first be enabled with FIFO_EN in CTRL_REG5 (24h). Mode behavior and the watermark/overrun/empty interaction with FIFO_SRC_REG (2Fh) are described in Section 5.1; in Stream mode the number of samples to read at the watermark interrupt is up to FTH+1. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.978700 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{25})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.978700 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.993738/1.0001=\mathbf{0.993638}\).

## Extracted logical register 26: `FIFO_SRC_REG`

v11 location: `registers[25]`; truth association: `registers[19]` (`FIFO_SRC_REG`).

Associated physical locations: 0x2F (47).


### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_SRC_REG` at 0x2F (47)

Locations: `truth registers[19].field_parts` ↔ `v11 registers[25].field_parts[0]`.

**Truth bit field 1: `WTM` bits 7:7**

Locations: `truth registers[19].field_parts.bit_field[0]` ↔ `v11 registers[25].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WTM | WTM |
| `field_description` | 0.0586 | 1.0 | Set high when FIFO content exceeds the watermark level. | WTM bit is set high when FIFO content exceeds watermark level |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `OVRN_FIFO` bits 6:6**

Locations: `truth registers[19].field_parts.bit_field[1]` ↔ `v11 registers[25].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | OVRN_FIFO | OVRN_FIFO |
| `field_description` | 0.0586 | 1.0 | Set high when the FIFO is full with 32 unread samples; clears when the first sample set is read. | OVRN bit is set high when FIFO buffer is full (32 unread samples); at the following ODR a new sample set replaces the oldest FIFO value. The OVRN bit is set to 0 when the first sample set has been read |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `EMPTY` bits 5:5**

Locations: `truth registers[19].field_parts.bit_field[2]` ↔ `v11 registers[25].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | EMPTY | EMPTY |
| `field_description` | 0.0586 | 1.0 | Set high when all FIFO samples have been read and the FIFO is empty. | EMPTY flag is set high when all FIFO samples have been read and FIFO is empty |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `FSS [4:0]` bits 4:0**

Locations: `truth registers[19].field_parts.bit_field[3]` ↔ `v11 registers[25].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FSS [4:0] | FSS[4:0] |
| `field_description` | 0.0586 | 1.0 | Current number of unread sample sets stored in the FIFO. | Current number of unread samples stored in the FIFO buffer; increases at ODR frequency until full and decreases each time one sample set is retrieved from FIFO |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.941694.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | FIFO_SRC_REG | FIFO_SRC_REG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":""} | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":"FIFO status/source register address"} |
| `description` | 0.0693 | 1.000000 | "" | FIFO watermark, overrun, empty and sample-count status |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | [{"name_or_parameter":"WTM","field_description":"Set high when FIFO content exceeds the watermark level.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"OVRN_FIFO","field_description":"Set high when the FIFO is full with 32 unread samples; clears when the first sample set is read.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"EMPTY","field_description":"Set high when all FIFO samples have been read and the FIFO is empty.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FSS [4:0]","field_description":"Current number of unread sample sets stored in the FIFO.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"WTM","field_description":"WTM bit is set high when FIFO content exceeds watermark level","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"OVRN_FIFO","field_description":"OVRN bit is set high when FIFO buffer is full (32 unread samples); at the following ODR a new sample set replaces the oldest FIFO value. The OVRN bit is set to 0 when the first sample set has been read","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"EMPTY","field_description":"EMPTY flag is set high when all FIFO samples have been read and FIFO is empty","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"FSS[4:0]","field_description":"Current number of unread samples stored in the FIFO buffer; increases at ODR frequency until full and decreases each time one sample set is retrieved from FIFO","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.981756}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.981756) = **0.981756**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | FIFO_SRC_REG | FIFO_SRC_REG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":""} | [{"hex":"0x2F","decimal":"47","bank":"","page":"","description":"FIFO status/source register address"}] |
| `register_description` | 0.0564 | 1.000000 | Reports FIFO watermark, overrun, empty status and the number of unread FIFO samples. | FIFO status register: WTM indicates the FIFO content exceeded the watermark level (FTH[4:0] in FIFO_CTRL_REG), OVRN_FIFO indicates the buffer is full (32 unread samples) and slots are being overwritten, EMPTY indicates all samples have been read, and FSS[4:0] holds the current number of unread samples. Detailed set/clear conditions are described in Section 5.1. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.981756 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{26})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.994651/1.0001=\mathbf{0.994551}\).

## Extracted logical register 27: `INT1_CFG`

v11 location: `registers[26]`; truth association: `registers[20]` (`INT1_CFG`).

Associated physical locations: 0x30 (48).


### Bottom layer: bit fields, then field parts

#### Field part 1: `INT1_CFG` at 0x30 (48)

Locations: `truth registers[20].field_parts` ↔ `v11 registers[26].field_parts[0]`.

**Truth bit field 1: `AOI-6D` bits 7:6**

Locations: `truth registers[20].field_parts.bit_field[0]` ↔ missing. Judgment: truth bit field is missing from the extraction.

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

Locations: `truth registers[20].field_parts.bit_field[1]` ↔ `v11 registers[26].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZHIE | ZHIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Z high event or direction recognition. | Enable interrupt generation on Z high event or on Direction recognition. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `ZLIE` bits 4:4**

Locations: `truth registers[20].field_parts.bit_field[2]` ↔ `v11 registers[26].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZLIE | ZLIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Z low event or direction recognition. | Enable interrupt generation on Z low event or on Direction recognition. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `YHIE` bits 3:3**

Locations: `truth registers[20].field_parts.bit_field[3]` ↔ `v11 registers[26].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YHIE | YHIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Y high event or direction recognition. | Enable interrupt generation on Y high event or on Direction recognition. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `YLIE` bits 2:2**

Locations: `truth registers[20].field_parts.bit_field[4]` ↔ `v11 registers[26].field_parts[0].bit_field[5]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YLIE | YLIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Y low event or direction recognition. | Enable interrupt generation on Y low event or on Direction recognition. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 6: `XHIE` bits 1:1**

Locations: `truth registers[20].field_parts.bit_field[5]` ↔ `v11 registers[26].field_parts[0].bit_field[6]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XHIE | XHIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on X high event or direction recognition. | Enable interrupt generation on X high event or on Direction recognition. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 7: `XLIE` bits 0:0**

Locations: `truth registers[20].field_parts.bit_field[6]` ↔ `v11 registers[26].field_parts[0].bit_field[7]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XLIE | XLIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on X low event or direction recognition. | Enable interrupt generation on X low event or on Direction recognition. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

Additional v11 bit field not matched to a truth range: `v11 registers[26].field_parts[0].bit_field[0]` (`AOI`, bits 7:7). It is reported but not credited.

Additional v11 bit field not matched to a truth range: `v11 registers[26].field_parts[0].bit_field[1]` (`6D`, bits 6:6). It is reported but not credited.

**Field-part aggregation**

`bit_field` correctness = 0.807166.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT1_CFG | INT1_CFG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x30","decimal":"48","bank":"","page":"","description":""} | {"hex":"0x30","decimal":"48","bank":"","page":"","description":"Interrupt 1 configuration register address"} |
| `description` | 0.0693 | 1.000000 | "" | Interrupt 1 mode and per-axis event enables |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.807166 | [{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event or direction recognition.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event or direction recognition.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event or direction recognition.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event or direction recognition.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event or direction recognition.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event or direction recognition.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"AOI","field_description":"And/Or combination of Interrupt events. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"00 (AOI-6D)","value_description":"OR combination of interrupt events"},{"value":"01 (AOI-6D)","value_description":"6-direction movement recognition"},{"value":"10 (AOI-6D)","value_description":"AND combination of interrupt events"},{"value":"11 (AOI-6D)","value_description":"6-direction position recognition"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"6D","field_description":"6 direction detection function enabled. Default value: 0 (refer to Table 55: Interrupt mode, page 41)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event or on Direction recognition. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event or on Direction recognition. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event or on Direction recognition. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event or on Direction recognition. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event or on Direction recognition. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event or on Direction recognition. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.807166=\mathbf{0.939662}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.939662) = **0.939662**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT1_CFG | INT1_CFG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x30","decimal":"48","bank":"","page":"","description":""} | [{"hex":"0x30","decimal":"48","bank":"","page":"","description":"Interrupt 1 configuration register address"}] |
| `register_description` | 0.0564 | 1.000000 | Configures interrupt 1 event combination, direction recognition and axis high/low event enables. Its content is loaded at boot, and writing is possible only after system boot. | Interrupt 1 configuration register: AOI and 6D select the interrupt mode (OR/AND combination and 6-direction movement/position recognition; Table 55, page 41), and ZHIE/ZLIE/YHIE/YLIE/XHIE/XLIE enable interrupt generation on high/low events or direction recognition per axis. AOI-6D='01' is movement recognition (interrupt when orientation moves from an unknown zone to a known zone, held for one ODR); AOI-6D='11' is direction recognition (interrupt while orientation is inside a known zone). Content of this register is loaded at boot; a write is possible only after system boot. Latching is controlled by LIR_INT1 in CTRL_REG5 (24h). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.939662 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | Content loaded at boot; write possible only after system boot. |

\(Q(L_{27})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.939662 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.982077/1.0001=\mathbf{0.981979}\).

## Extracted logical register 28: `INT1_SRC`

v11 location: `registers[27]`; truth association: `registers[21]` (`INT1_SRC`).

Associated physical locations: 0x31 (49).


### Bottom layer: bit fields, then field parts

#### Field part 1: `INT1_SRC` at 0x31 (49)

Locations: `truth registers[21].field_parts` ↔ `v11 registers[27].field_parts[0]`.

**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[21].field_parts.bit_field[0]` ↔ `v11 registers[27].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 0 | 0 |
| `field_description` | 0.0586 | 1.0 | "" | Bit 7 shown as 0 in the register bit table; no function described. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `IA` bits 6:6**

Locations: `truth registers[21].field_parts.bit_field[1]` ↔ `v11 registers[27].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | IA | IA |
| `field_description` | 0.0586 | 1.0 | Interrupt active. | Interrupt active. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | [{"value":"0","value_description":"no interrupt has been generated"},{"value":"1","value_description":"one or more interrupts have been generated"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `ZH` bits 5:5**

Locations: `truth registers[21].field_parts.bit_field[2]` ↔ `v11 registers[27].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZH | ZH |
| `field_description` | 0.0586 | 0.5 | Z high event status. | Z high. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z high event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Truth bit field 4: `ZL` bits 4:4**

Locations: `truth registers[21].field_parts.bit_field[3]` ↔ `v11 registers[27].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZL | ZL |
| `field_description` | 0.0586 | 0.5 | Z low event status. | Z low. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z low event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Truth bit field 5: `YH` bits 3:3**

Locations: `truth registers[21].field_parts.bit_field[4]` ↔ `v11 registers[27].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YH | YH |
| `field_description` | 0.0586 | 0.5 | Y high event status. | Y high. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y high event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Truth bit field 6: `YL` bits 2:2**

Locations: `truth registers[21].field_parts.bit_field[5]` ↔ `v11 registers[27].field_parts[0].bit_field[5]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YL | YL |
| `field_description` | 0.0586 | 0.5 | Y low event status. | Y low. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y low event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Truth bit field 7: `XH` bits 1:1**

Locations: `truth registers[21].field_parts.bit_field[6]` ↔ `v11 registers[27].field_parts[0].bit_field[6]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XH | XH |
| `field_description` | 0.0586 | 0.5 | X high event status. | X high. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X high event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Truth bit field 8: `XL` bits 0:0**

Locations: `truth registers[21].field_parts.bit_field[7]` ↔ `v11 registers[27].field_parts[0].bit_field[7]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XL | XL |
| `field_description` | 0.0586 | 0.5 | X low event status. | X low. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X low event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Field-part aggregation**

`bit_field` correctness = 0.927005.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT1_SRC | INT1_SRC |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x31","decimal":"49","bank":"","page":"","description":""} | {"hex":"0x31","decimal":"49","bank":"","page":"","description":"Interrupt 1 source register address"} |
| `description` | 0.0693 | 1.000000 | "" | Interrupt 1 active flag and axis event source flags |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.927005 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"0","field_description":"Bit 7 shown as 0 in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt has been generated"},{"value":"1","value_description":"one or more interrupts have been generated"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZH","field_description":"Z high. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZL","field_description":"Z low. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z low event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YH","field_description":"Y high. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YL","field_description":"Y low. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y low event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XH","field_description":"X high. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XL","field_description":"X low. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X low event has occurred"}],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.927005=\mathbf{0.977160}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.977160) = **0.977160**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT1_SRC | INT1_SRC |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x31","decimal":"49","bank":"","page":"","description":""} | [{"hex":"0x31","decimal":"49","bank":"","page":"","description":"Interrupt 1 source register address"}] |
| `register_description` | 0.0564 | 1.000000 | Reports interrupt 1 source and axis-event status. Reading clears the IA bit and INT1 signal and refreshes latched data. | Interrupt 1 source register (read-only). IA reports that one or more interrupts have been generated and ZH/ZL/YH/YL/XH/XL report the corresponding axis high/low events. Reading this address clears the IA bit (and the interrupt signal on the INT1 pin) and allows data refresh if the latched option (LIR_INT1 in CTRL_REG5) was chosen. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.977160 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | Read-only; reading clears IA and the INT1 pin interrupt. |

\(Q(L_{28})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.977160 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.993278/1.0001=\mathbf{0.993178}\).

## Extracted logical register 29: `INT1_THS`

v11 location: `registers[28]`; truth association: `registers[22]` (`INT1_THS`).

Associated physical locations: 0x32 (50).


### Bottom layer: bit fields, then field parts

#### Field part 1: `INT1_THS` at 0x32 (50)

Locations: `truth registers[22].field_parts` ↔ `v11 registers[28].field_parts[0]`.

**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[22].field_parts.bit_field[0]` ↔ `v11 registers[28].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 0 | 0 |
| `field_description` | 0.0586 | 1.0 | "" | Bit 7 shown as 0 in the register bit table; no function described. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `THS[6:0]` bits 6:0**

Locations: `truth registers[22].field_parts.bit_field[1]` ↔ `v11 registers[28].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THS[6:0] | THS[6:0] |
| `field_description` | 0.0586 | 1.0 | Interrupt 1 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g. | Interrupt 1 threshold. Default value: 000 0000. 1 LSb = 16 mg @ FS=±2 g; 32 mg @ FS=±4 g; 62 mg @ FS=±8 g; 186 mg @ FS=±16 g |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.970847.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT1_THS | INT1_THS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x32","decimal":"50","bank":"","page":"","description":""} | {"hex":"0x32","decimal":"50","bank":"","page":"","description":"Interrupt 1 threshold register address"} |
| `description` | 0.0693 | 1.000000 | "" | Interrupt 1 threshold value |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 1 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"0","field_description":"Bit 7 shown as 0 in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 1 threshold. Default value: 000 0000. 1 LSb = 16 mg @ FS=±2 g; 32 mg @ FS=±4 g; 62 mg @ FS=±8 g; 186 mg @ FS=±16 g","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.970847=\mathbf{0.990878}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.990878) = **0.990878**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT1_THS | INT1_THS |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x32","decimal":"50","bank":"","page":"","description":""} | [{"hex":"0x32","decimal":"50","bank":"","page":"","description":"Interrupt 1 threshold register address"}] |
| `register_description` | 0.0564 | 0.500000 | Sets the interrupt 1 acceleration threshold. | Interrupt 1 threshold register (THS[6:0]). Threshold step depends on the full scale selected by FS[1:0] in CTRL_REG4 (23h): 1 LSb = 16 mg @ FS=±2 g, 32 mg @ FS=±4 g, 62 mg @ FS=±8 g, 186 mg @ FS=±16 g. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.990878 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{29})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.990878 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.969175/1.0001=\mathbf{0.969078}\).

## Extracted logical register 30: `INT1_DURATION`

v11 location: `registers[29]`; truth association: `registers[23]` (`INT1_DURATION`).

Associated physical locations: 0x33 (51).


### Bottom layer: bit fields, then field parts

#### Field part 1: `INT1_DURATION` at 0x33 (51)

Locations: `truth registers[23].field_parts` ↔ `v11 registers[29].field_parts[0]`.

**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[23].field_parts.bit_field[0]` ↔ `v11 registers[29].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 0 | 0 |
| `field_description` | 0.0586 | 1.0 | "" | Bit 7 shown as 0 in the register bit table; no function described. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `D[6:0]` bits 6:0**

Locations: `truth registers[23].field_parts.bit_field[1]` ↔ `v11 registers[29].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | D[6:0] | D[6:0] |
| `field_description` | 0.0586 | 1.0 | Duration value; 1 LSb equals 1/ODR. | Duration value. Default value: 000 0000. 1 LSb = 1/ODR |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.970847.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT1_DURATION | INT1_DURATION |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x33","decimal":"51","bank":"","page":"","description":""} | {"hex":"0x33","decimal":"51","bank":"","page":"","description":"Interrupt 1 duration register address"} |
| `description` | 0.0693 | 1.000000 | "" | Interrupt 1 minimum event duration |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"0","field_description":"Bit 7 shown as 0 in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value. Default value: 000 0000. 1 LSb = 1/ODR","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.970847=\mathbf{0.990878}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.990878) = **0.990878**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT1_DURATION | INT1_DURATION |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x33","decimal":"51","bank":"","page":"","description":""} | [{"hex":"0x33","decimal":"51","bank":"","page":"","description":"Interrupt 1 duration register address"}] |
| `register_description` | 0.0564 | 1.000000 | Sets the minimum interrupt event duration; duration is measured as N/ODR. | Interrupt 1 duration register (D[6:0]). Sets the minimum duration of the interrupt event to be recognized; duration time is measured in N/ODR where N is the content of the duration register (1 LSb = 1/ODR), so steps and maximum values depend on the ODR chosen in CTRL_REG1 (20h). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.990878 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{30})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.990878 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.997375/1.0001=\mathbf{0.997276}\).

## Extracted logical register 31: `INT2_CFG`

v11 location: `registers[30]`; truth association: `registers[24]` (`INT2_CFG`).

Associated physical locations: 0x34 (52).


### Bottom layer: bit fields, then field parts

#### Field part 1: `INT2_CFG` at 0x34 (52)

Locations: `truth registers[24].field_parts` ↔ `v11 registers[30].field_parts[0]`.

**Truth bit field 1: `AOI-6D` bits 7:6**

Locations: `truth registers[24].field_parts.bit_field[0]` ↔ missing. Judgment: truth bit field is missing from the extraction.

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

Locations: `truth registers[24].field_parts.bit_field[1]` ↔ `v11 registers[30].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZHIE | ZHIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Z high event. | Enable interrupt generation on Z high event. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `ZLIE` bits 4:4**

Locations: `truth registers[24].field_parts.bit_field[2]` ↔ `v11 registers[30].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZLIE | ZLIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Z low event. | Enable interrupt generation on Z low event. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value lower than preset threshold"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `YHIE` bits 3:3**

Locations: `truth registers[24].field_parts.bit_field[3]` ↔ `v11 registers[30].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YHIE | YHIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Y high event. | Enable interrupt generation on Y high event. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `YLIE` bits 2:2**

Locations: `truth registers[24].field_parts.bit_field[4]` ↔ `v11 registers[30].field_parts[0].bit_field[5]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YLIE | YLIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on Y low event. | Enable interrupt generation on Y low event. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value lower than preset threshold"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 6: `XHIE` bits 1:1**

Locations: `truth registers[24].field_parts.bit_field[5]` ↔ `v11 registers[30].field_parts[0].bit_field[6]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XHIE | XHIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on X high event. | Enable interrupt generation on X high event. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 7: `XLIE` bits 0:0**

Locations: `truth registers[24].field_parts.bit_field[6]` ↔ `v11 registers[30].field_parts[0].bit_field[7]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XLIE | XLIE |
| `field_description` | 0.0586 | 1.0 | Enable interrupt generation on X low event. | Enable interrupt generation on X low event. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value lower than preset threshold"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

Additional v11 bit field not matched to a truth range: `v11 registers[30].field_parts[0].bit_field[0]` (`AOI`, bits 7:7). It is reported but not credited.

Additional v11 bit field not matched to a truth range: `v11 registers[30].field_parts[0].bit_field[1]` (`6D`, bits 6:6). It is reported but not credited.

**Field-part aggregation**

`bit_field` correctness = 0.807166.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT2_CFG | INT2_CFG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x34","decimal":"52","bank":"","page":"","description":""} | {"hex":"0x34","decimal":"52","bank":"","page":"","description":"Interrupt 2 configuration register address"} |
| `description` | 0.0693 | 1.000000 | "" | Interrupt 2 mode and per-axis event enables |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.807166 | [{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"AOI","field_description":"AND/OR combination of interrupt events. Default value: 0 (see Table 64, page 43)","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"00 (AOI-6D)","value_description":"OR combination of interrupt events"},{"value":"01 (AOI-6D)","value_description":"6-direction movement recognition"},{"value":"10 (AOI-6D)","value_description":"AND combination of interrupt events"},{"value":"11 (AOI-6D)","value_description":"6-direction position recognition"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"6D","field_description":"6-direction detection function enabled. Default value: 0 (refer to Table 64, page 43)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value lower than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value lower than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value lower than preset threshold"}],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.807166=\mathbf{0.939662}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.939662) = **0.939662**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT2_CFG | INT2_CFG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x34","decimal":"52","bank":"","page":"","description":""} | [{"hex":"0x34","decimal":"52","bank":"","page":"","description":"Interrupt 2 configuration register address"}] |
| `register_description` | 0.0564 | 0.500000 | Configures interrupt 2 event combination, direction recognition and axis high/low event enables. Its content is loaded at boot, and writing is possible only after system boot. | Interrupt 2 configuration register: AOI and 6D select the interrupt mode (OR/AND combination and 6-direction movement/position recognition; Table 64, page 43), and ZHIE/ZLIE/YHIE/YLIE/XHIE/XLIE enable interrupt generation on measured acceleration higher/lower than the preset threshold per axis. AOI-6D='01' is movement recognition (interrupt held for one ODR); AOI-6D='11' is direction recognition (interrupt held while inside the zone). Content is loaded at boot; a write is possible only after system boot. Latching is controlled by LIR_INT2 in CTRL_REG5 (24h). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.939662 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | Content loaded at boot; write possible only after system boot. |

\(Q(L_{31})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.939662 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.953877/1.0001=\mathbf{0.953782}\).

## Extracted logical register 32: `INT2_SRC`

v11 location: `registers[31]`; truth association: `registers[25]` (`INT2_SRC`).

Associated physical locations: 0x35 (53).


### Bottom layer: bit fields, then field parts

#### Field part 1: `INT2_SRC` at 0x35 (53)

Locations: `truth registers[25].field_parts` ↔ `v11 registers[31].field_parts[0]`.

**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[25].field_parts.bit_field[0]` ↔ `v11 registers[31].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 0 | 0 |
| `field_description` | 0.0586 | 1.0 | "" | Bit 7 shown as 0 in the register bit table; no function described. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `IA` bits 6:6**

Locations: `truth registers[25].field_parts.bit_field[1]` ↔ `v11 registers[31].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | IA | IA |
| `field_description` | 0.0586 | 1.0 | Interrupt active. | Interrupt active. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | [{"value":"0","value_description":"no interrupt has been generated"},{"value":"1","value_description":"one or more interrupts have been generated"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `ZH` bits 5:5**

Locations: `truth registers[25].field_parts.bit_field[2]` ↔ `v11 registers[31].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZH | ZH |
| `field_description` | 0.0586 | 0.5 | Z high event status. | Z high. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z high event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Truth bit field 4: `ZL` bits 4:4**

Locations: `truth registers[25].field_parts.bit_field[3]` ↔ `v11 registers[31].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZL | ZL |
| `field_description` | 0.0586 | 0.5 | Z low event status. | Z low. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z low event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Truth bit field 5: `YH` bits 3:3**

Locations: `truth registers[25].field_parts.bit_field[4]` ↔ `v11 registers[31].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YH | YH |
| `field_description` | 0.0586 | 0.5 | Y high event status. | Y high. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y high event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Truth bit field 6: `YL` bits 2:2**

Locations: `truth registers[25].field_parts.bit_field[5]` ↔ `v11 registers[31].field_parts[0].bit_field[5]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YL | YL |
| `field_description` | 0.0586 | 0.5 | Y low event status. | Y low. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y low event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Truth bit field 7: `XH` bits 1:1**

Locations: `truth registers[25].field_parts.bit_field[6]` ↔ `v11 registers[31].field_parts[0].bit_field[6]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XH | XH |
| `field_description` | 0.0586 | 0.5 | X high event status. | X high. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X high event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Truth bit field 8: `XL` bits 0:0**

Locations: `truth registers[25].field_parts.bit_field[7]` ↔ `v11 registers[31].field_parts[0].bit_field[7]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XL | XL |
| `field_description` | 0.0586 | 0.5 | X low event status. | X low. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X low event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Field-part aggregation**

`bit_field` correctness = 0.927005.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT2_SRC | INT2_SRC |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x35","decimal":"53","bank":"","page":"","description":""} | {"hex":"0x35","decimal":"53","bank":"","page":"","description":"Interrupt 2 source register address"} |
| `description` | 0.0693 | 1.000000 | "" | Interrupt 2 active flag and axis event source flags |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.927005 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"0","field_description":"Bit 7 shown as 0 in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt has been generated"},{"value":"1","value_description":"one or more interrupts have been generated"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZH","field_description":"Z high. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZL","field_description":"Z low. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z low event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YH","field_description":"Y high. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YL","field_description":"Y low. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y low event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XH","field_description":"X high. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XL","field_description":"X low. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X low event has occurred"}],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.927005=\mathbf{0.977160}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.977160) = **0.977160**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT2_SRC | INT2_SRC |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x35","decimal":"53","bank":"","page":"","description":""} | [{"hex":"0x35","decimal":"53","bank":"","page":"","description":"Interrupt 2 source register address"}] |
| `register_description` | 0.0564 | 1.000000 | Reports interrupt 2 source and axis-event status. Reading clears the IA bit and INT2 signal and refreshes latched data. | Interrupt 2 source register (read-only). IA reports that one or more interrupts have been generated and ZH/ZL/YH/YL/XH/XL report the corresponding axis high/low events. Reading this address clears the IA bit (and the interrupt signal on the INT2 pin) and allows data refresh if the latched option (LIR_INT2 in CTRL_REG5) was chosen. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.977160 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | Read-only; reading clears IA and the INT2 pin interrupt. |

\(Q(L_{32})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.977160 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.993278/1.0001=\mathbf{0.993178}\).

## Extracted logical register 33: `INT2_THS`

v11 location: `registers[32]`; truth association: `registers[26]` (`INT2_THS`).

Associated physical locations: 0x36 (54).


### Bottom layer: bit fields, then field parts

#### Field part 1: `INT2_THS` at 0x36 (54)

Locations: `truth registers[26].field_parts` ↔ `v11 registers[32].field_parts[0]`.

**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[26].field_parts.bit_field[0]` ↔ `v11 registers[32].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 0 | 0 |
| `field_description` | 0.0586 | 1.0 | "" | Bit 7 shown as 0 in the register bit table; no function described. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `THS[6:0]` bits 6:0**

Locations: `truth registers[26].field_parts.bit_field[1]` ↔ `v11 registers[32].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THS[6:0] | THS[6:0] |
| `field_description` | 0.0586 | 1.0 | Interrupt 2 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g. | Interrupt 2 threshold. Default value: 000 0000. 1 LSb = 16 mg @ FS=±2 g; 32 mg @ FS=±4 g; 62 mg @ FS=±8 g; 186 mg @ FS=±16 g |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.970847.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT2_THS | INT2_THS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x36","decimal":"54","bank":"","page":"","description":""} | {"hex":"0x36","decimal":"54","bank":"","page":"","description":"Interrupt 2 threshold register address"} |
| `description` | 0.0693 | 1.000000 | "" | Interrupt 2 threshold value |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 2 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"0","field_description":"Bit 7 shown as 0 in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 2 threshold. Default value: 000 0000. 1 LSb = 16 mg @ FS=±2 g; 32 mg @ FS=±4 g; 62 mg @ FS=±8 g; 186 mg @ FS=±16 g","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.970847=\mathbf{0.990878}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.990878) = **0.990878**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT2_THS | INT2_THS |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x36","decimal":"54","bank":"","page":"","description":""} | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":"Interrupt 2 threshold register address"}] |
| `register_description` | 0.0564 | 0.500000 | Sets the interrupt 2 acceleration threshold. | Interrupt 2 threshold register (THS[6:0]). Threshold step depends on the full scale selected by FS[1:0] in CTRL_REG4 (23h): 1 LSb = 16 mg @ FS=±2 g, 32 mg @ FS=±4 g, 62 mg @ FS=±8 g, 186 mg @ FS=±16 g. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.990878 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{33})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.990878 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.969175/1.0001=\mathbf{0.969078}\).

## Extracted logical register 34: `INT2_DURATION`

v11 location: `registers[33]`; truth association: `registers[27]` (`INT2_DURATION`).

Associated physical locations: 0x37 (55).


### Bottom layer: bit fields, then field parts

#### Field part 1: `INT2_DURATION` at 0x37 (55)

Locations: `truth registers[27].field_parts` ↔ `v11 registers[33].field_parts[0]`.

**Truth bit field 1: `0` bits 7:7**

Locations: `truth registers[27].field_parts.bit_field[0]` ↔ `v11 registers[33].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | 0 | 0 |
| `field_description` | 0.0586 | 1.0 | "" | Bit 7 shown as 0 in the register bit table; no function described. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `D[6:0]` bits 6:0**

Locations: `truth registers[27].field_parts.bit_field[1]` ↔ `v11 registers[33].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | D[6:0] | D[6:0] |
| `field_description` | 0.0586 | 1.0 | Duration value; 1 LSb equals 1/ODR. | Duration value. Default value: 000 0000. 1 LSb = 1/ODR |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.970847.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT2_DURATION | INT2_DURATION |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x37","decimal":"55","bank":"","page":"","description":""} | {"hex":"0x37","decimal":"55","bank":"","page":"","description":"Interrupt 2 duration register address"} |
| `description` | 0.0693 | 1.000000 | "" | Interrupt 2 minimum event duration |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"0","field_description":"Bit 7 shown as 0 in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value. Default value: 000 0000. 1 LSb = 1/ODR","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.970847=\mathbf{0.990878}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.990878) = **0.990878**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT2_DURATION | INT2_DURATION |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x37","decimal":"55","bank":"","page":"","description":""} | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":"Interrupt 2 duration register address"}] |
| `register_description` | 0.0564 | 1.000000 | Sets the minimum duration of an interrupt 2 event; duration is measured as N/ODR. | Interrupt 2 duration register (D[6:0]). Sets the minimum duration of the Interrupt 2 event to be recognized; duration time is measured in N/ODR where N is the content of the duration register (1 LSb = 1/ODR), so steps and maximum values depend on the ODR chosen. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.990878 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{34})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.990878 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.997375/1.0001=\mathbf{0.997276}\).

## Extracted logical register 35: `CLICK_CFG`

v11 location: `registers[34]`; truth association: `registers[28]` (`CLICK_CFG`).

Associated physical locations: 0x38 (56).


### Bottom layer: bit fields, then field parts

#### Field part 1: `CLICK_CFG` at 0x38 (56)

Locations: `truth registers[28].field_parts` ↔ `v11 registers[34].field_parts[0]`.

**Truth bit field 1: `--` bits 7:6**

Locations: `truth registers[28].field_parts.bit_field[0]` ↔ missing. Judgment: truth bit field is missing from the extraction.

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

Locations: `truth registers[28].field_parts.bit_field[1]` ↔ `v11 registers[34].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZD | ZD |
| `field_description` | 0.0586 | 1.0 | Enable double-click interrupt on Z-axis. | Enable interrupt double click on Z-axis. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `ZS` bits 4:4**

Locations: `truth registers[28].field_parts.bit_field[2]` ↔ `v11 registers[34].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZS | ZS |
| `field_description` | 0.0586 | 1.0 | Enable single-click interrupt on Z-axis. | Enable interrupt single click on Z-axis. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `YD` bits 3:3**

Locations: `truth registers[28].field_parts.bit_field[3]` ↔ `v11 registers[34].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YD | YD |
| `field_description` | 0.0586 | 1.0 | Enable double-click interrupt on Y-axis. | Enable interrupt double click on Y-axis. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `YS` bits 2:2**

Locations: `truth registers[28].field_parts.bit_field[4]` ↔ `v11 registers[34].field_parts[0].bit_field[5]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YS | YS |
| `field_description` | 0.0586 | 1.0 | Enable single-click interrupt on Y-axis. | Enable interrupt single click on Y-axis. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 6: `XD` bits 1:1**

Locations: `truth registers[28].field_parts.bit_field[5]` ↔ `v11 registers[34].field_parts[0].bit_field[6]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XD | XD |
| `field_description` | 0.0586 | 1.0 | Enable double-click interrupt on X-axis. | Enable interrupt double click on X-axis. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 7: `XS` bits 0:0**

Locations: `truth registers[28].field_parts.bit_field[6]` ↔ `v11 registers[34].field_parts[0].bit_field[7]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XS | XS |
| `field_description` | 0.0586 | 1.0 | Enable single-click interrupt on X-axis. | Enable interrupt single click on X-axis. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}] | [{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

Additional v11 bit field not matched to a truth range: `v11 registers[34].field_parts[0].bit_field[0]` (`--`, bits 7:7). It is reported but not credited.

Additional v11 bit field not matched to a truth range: `v11 registers[34].field_parts[0].bit_field[1]` (`--`, bits 6:6). It is reported but not credited.

**Field-part aggregation**

`bit_field` correctness = 0.807166.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CLICK_CFG | CLICK_CFG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x38","decimal":"56","bank":"","page":"","description":""} | {"hex":"0x38","decimal":"56","bank":"","page":"","description":"Click configuration register address"} |
| `description` | 0.0693 | 1.000000 | "" | Single/double click interrupt enables per axis |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.807166 | [{"name_or_parameter":"--","field_description":"","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"ZD","field_description":"Enable double-click interrupt on Z-axis.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZS","field_description":"Enable single-click interrupt on Z-axis.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YD","field_description":"Enable double-click interrupt on Y-axis.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YS","field_description":"Enable single-click interrupt on Y-axis.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XD","field_description":"Enable double-click interrupt on X-axis.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XS","field_description":"Enable single-click interrupt on X-axis.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"--","field_description":"Bit 7 shown as '--' in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"--","field_description":"Bit 6 shown as '--' in the register bit table; no function described.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"ZD","field_description":"Enable interrupt double click on Z-axis. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZS","field_description":"Enable interrupt single click on Z-axis. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YD","field_description":"Enable interrupt double click on Y-axis. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YS","field_description":"Enable interrupt single click on Y-axis. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XD","field_description":"Enable interrupt double click on X-axis. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XS","field_description":"Enable interrupt single click on X-axis. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.807166=\mathbf{0.939662}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.939662) = **0.939662**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CLICK_CFG | CLICK_CFG |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x38","decimal":"56","bank":"","page":"","description":""} | [{"hex":"0x38","decimal":"56","bank":"","page":"","description":"Click configuration register address"}] |
| `register_description` | 0.0564 | 0.500000 | Enables single-click and double-click interrupt detection for the X, Y and Z axes. | Click interrupt configuration register: enables single-click (XS/YS/ZS) and double-click (XD/YD/ZD) interrupt requests per axis on measured acceleration higher than the preset threshold. Click threshold/timing are set by CLICK_THS (3Ah), TIME_LIMIT (3Bh), TIME_LATENCY (3Ch) and TIME_WINDOW (3Dh). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.939662 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{35})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.939662 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.953877/1.0001=\mathbf{0.953782}\).

## Extracted logical register 36: `CLICK_SRC`

v11 location: `registers[35]`; truth association: `registers[29]` (`CLICK_SRC`).

Associated physical locations: 0x39 (57).


### Bottom layer: bit fields, then field parts

#### Field part 1: `CLICK_SRC` at 0x39 (57)

Locations: `truth registers[29].field_parts` ↔ `v11 registers[35].field_parts[0]`.

**Truth bit field 1: `""` bits 7:7**

Locations: `truth registers[29].field_parts.bit_field[0]` ↔ `v11 registers[35].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "" | "" |
| `field_description` | 0.0586 | 1.0 | "" | Bit 7 cell is blank in the register bit table; no function described. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `IA` bits 6:6**

Locations: `truth registers[29].field_parts.bit_field[1]` ↔ `v11 registers[35].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | IA | IA |
| `field_description` | 0.0586 | 1.0 | Interrupt active. | Interrupt active. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}] | [{"value":"0","value_description":"no interrupt has been generated"},{"value":"1","value_description":"one or more interrupts have been generated"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `DCLICK` bits 5:5**

Locations: `truth registers[29].field_parts.bit_field[2]` ↔ `v11 registers[35].field_parts[0].bit_field[2]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DCLICK | DCLICK |
| `field_description` | 0.0586 | 1.0 | Double-click enable. | Double-click enable. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Double-click detection disabled."},{"value":"1","value_description":"Double-click detection enabled."}] | [{"value":"0","value_description":"double-click detection disabled"},{"value":"1","value_description":"double-click detection enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `SCLICK` bits 4:4**

Locations: `truth registers[29].field_parts.bit_field[3]` ↔ `v11 registers[35].field_parts[0].bit_field[3]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SCLICK | SCLICK |
| `field_description` | 0.0586 | 1.0 | Single-click enable. | Single-click enable. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Single-click detection disabled."},{"value":"1","value_description":"Single-click detection enabled."}] | [{"value":"0","value_description":"Single-click detection disabled"},{"value":"1","value_description":"single-click detection enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `Sign` bits 3:3**

Locations: `truth registers[29].field_parts.bit_field[4]` ↔ `v11 registers[35].field_parts[0].bit_field[4]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Sign | Sign |
| `field_description` | 0.0586 | 1.0 | Click sign. | Click sign |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Positive detection."},{"value":"1","value_description":"Negative detection."}] | [{"value":"0","value_description":"positive detection"},{"value":"1","value_description":"negative detection"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 6: `Z` bits 2:2**

Locations: `truth registers[29].field_parts.bit_field[5]` ↔ `v11 registers[35].field_parts[0].bit_field[5]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Z | Z |
| `field_description` | 0.0586 | 1.0 | Z click detection. | Z click detection. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z high event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 7: `Y` bits 1:1**

Locations: `truth registers[29].field_parts.bit_field[6]` ↔ `v11 registers[35].field_parts[0].bit_field[6]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Y | Y |
| `field_description` | 0.0586 | 1.0 | Y click detection. | Y click detection. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y high event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 8: `X` bits 0:0**

Locations: `truth registers[29].field_parts.bit_field[7]` ↔ `v11 registers[35].field_parts[0].bit_field[7]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | X | X |
| `field_description` | 0.0586 | 1.0 | X click detection. | X click detection. Default value: 0 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}] | [{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X high event has occurred"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.948982.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CLICK_SRC | CLICK_SRC |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x39","decimal":"57","bank":"","page":"","description":""} | {"hex":"0x39","decimal":"57","bank":"","page":"","description":"Click source register address"} |
| `description` | 0.0693 | 1.000000 | "" | Click interrupt source and detection flags |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.948982 | [{"name_or_parameter":"","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"DCLICK","field_description":"Double-click enable.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Double-click detection disabled."},{"value":"1","value_description":"Double-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SCLICK","field_description":"Single-click enable.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Single-click detection disabled."},{"value":"1","value_description":"Single-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Sign","field_description":"Click sign.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Positive detection."},{"value":"1","value_description":"Negative detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Z","field_description":"Z click detection.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Y","field_description":"Y click detection.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"X","field_description":"X click detection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"","field_description":"Bit 7 cell is blank in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt has been generated"},{"value":"1","value_description":"one or more interrupts have been generated"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"DCLICK","field_description":"Double-click enable. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"double-click detection disabled"},{"value":"1","value_description":"double-click detection enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"SCLICK","field_description":"Single-click enable. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Single-click detection disabled"},{"value":"1","value_description":"single-click detection enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Sign","field_description":"Click sign","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"positive detection"},{"value":"1","value_description":"negative detection"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Z","field_description":"Z click detection. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Y","field_description":"Y click detection. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"X","field_description":"X click detection. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X high event has occurred"}],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.948982=\mathbf{0.984037}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.984037) = **0.984037**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CLICK_SRC | CLICK_SRC |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x39","decimal":"57","bank":"","page":"","description":""} | [{"hex":"0x39","decimal":"57","bank":"","page":"","description":"Click source register address"}] |
| `register_description` | 0.0564 | 1.000000 | Reports click-interrupt activity, single/double-click detection, sign and detected axis. | Click source register (read-only): IA reports click interrupt activity, DCLICK/SCLICK report double/single-click detection status, Sign reports the click sign, and X/Y/Z report per-axis click detection. Related to the LIR_Click bit in CLICK_THS (3Ah), which controls whether the interrupt is held until CLICK_SRC is read. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.984037 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | "" | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{36})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.984037 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.995332/1.0001=\mathbf{0.995232}\).

## Extracted logical register 37: `CLICK_THS`

v11 location: `registers[36]`; truth association: `registers[30]` (`CLICK_THS`).

Associated physical locations: 0x3A (58).


### Bottom layer: bit fields, then field parts

#### Field part 1: `CLICK_THS` at 0x3A (58)

Locations: `truth registers[30].field_parts` ↔ `v11 registers[36].field_parts[0]`.

**Truth bit field 1: `LIR_Click` bits 7:7**

Locations: `truth registers[30].field_parts.bit_field[0]` ↔ `v11 registers[36].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LIR_Click | LIR_Click |
| `field_description` | 0.0586 | 0.5 | Controls click-interrupt latching. | If not set, the interrupt is kept high for the duration of the latency window; if set, the interrupt is kept high until the CLICK_SRC (39h) register is read |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.5 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.702600/0.9999=\mathbf{0.702670}\).

**Truth bit field 2: `Ths[6:0]` bits 6:0**

Locations: `truth registers[30].field_parts.bit_field[1]` ↔ `v11 registers[36].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Ths[6:0] | Ths[6:0] |
| `field_description` | 0.0586 | 1.0 | Click threshold. | Click threshold. Default value: 000 0000 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.822182.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CLICK_THS | CLICK_THS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":""} | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":"Click threshold register address"} |
| `description` | 0.0693 | 1.000000 | "" | Click threshold and click interrupt latch control |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.822182 | [{"name_or_parameter":"LIR_Click","field_description":"Controls click-interrupt latching.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Ths[6:0]","field_description":"Click threshold.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"LIR_Click","field_description":"If not set, the interrupt is kept high for the duration of the latency window; if set, the interrupt is kept high until the CLICK_SRC (39h) register is read","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Ths[6:0]","field_description":"Click threshold. Default value: 000 0000","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.822182=\mathbf{0.944361}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.944361) = **0.944361**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CLICK_THS | CLICK_THS |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":""} | [{"hex":"0x3A","decimal":"58","bank":"","page":"","description":"Click threshold register address"}] |
| `register_description` | 0.0564 | 1.000000 | Sets the click threshold and click-interrupt latch behavior. | Click threshold register: Ths[6:0] sets the click threshold and LIR_Click controls click interrupt latching (if not set, the interrupt stays high for the latency window; if set, it stays high until CLICK_SRC (39h) is read). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.944361 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{37})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.944361 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.983481/1.0001=\mathbf{0.983382}\).

## Extracted logical register 38: `TIME_LIMIT`

v11 location: `registers[37]`; truth association: `registers[31]` (`TIME_LIMIT`).

Associated physical locations: 0x3B (59).


### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_LIMIT` at 0x3B (59)

Locations: `truth registers[31].field_parts` ↔ `v11 registers[37].field_parts[0]`.

**Truth bit field 1: `-` bits 7:7**

Locations: `truth registers[31].field_parts.bit_field[0]` ↔ `v11 registers[37].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | "" | Bit 7 shown as '-' in the register bit table; no function described. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `TLI[6:0]` bits 6:0**

Locations: `truth registers[31].field_parts.bit_field[1]` ↔ `v11 registers[37].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TLI[6:0] | TLI[6:0] |
| `field_description` | 0.0586 | 1.0 | Click time limit. | Click time limit. Default value: 000 0000 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.970847.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TIME_LIMIT | TIME_LIMIT |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":""} | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":"Click time limit register address"} |
| `description` | 0.0693 | 1.000000 | "" | Click time limit value |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | [{"name_or_parameter":"-","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"TLI[6:0]","field_description":"Click time limit.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"-","field_description":"Bit 7 shown as '-' in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"TLI[6:0]","field_description":"Click time limit. Default value: 000 0000","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.970847=\mathbf{0.990878}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.990878) = **0.990878**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TIME_LIMIT | TIME_LIMIT |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":""} | [{"hex":"0x3B","decimal":"59","bank":"","page":"","description":"Click time limit register address"}] |
| `register_description` | 0.0564 | 0.500000 | Sets the click time limit. | Click time limit register (TLI[6:0]) for click detection timing. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.990878 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{38})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.990878 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.969175/1.0001=\mathbf{0.969078}\).

## Extracted logical register 39: `TIME_LATENCY`

v11 location: `registers[38]`; truth association: `registers[32]` (`TIME_LATENCY`).

Associated physical locations: 0x3C (60).


### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_LATENCY` at 0x3C (60)

Locations: `truth registers[32].field_parts` ↔ `v11 registers[38].field_parts[0]`.

**Truth bit field 1: `TLA[7:0]` bits 7:0**

Locations: `truth registers[32].field_parts.bit_field[0]` ↔ `v11 registers[38].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TLA[7:0] | TLA[7:0] |
| `field_description` | 0.0586 | 1.0 | Click time latency. | Click time latency. Default value: 0000 0000 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.941694.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TIME_LATENCY | TIME_LATENCY |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":""} | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Click time latency register address"} |
| `description` | 0.0693 | 1.000000 | "" | Click time latency value |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | {"name_or_parameter":"TLA[7:0]","field_description":"Click time latency.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [{"name_or_parameter":"TLA[7:0]","field_description":"Click time latency. Default value: 0000 0000","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.981756}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.981756) = **0.981756**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TIME_LATENCY | TIME_LATENCY |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":""} | [{"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Click time latency register address"}] |
| `register_description` | 0.0564 | 0.500000 | Sets the click time latency. | Click time latency register (TLA[7:0]) for click detection timing. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.981756 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{39})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.966451/1.0001=\mathbf{0.966354}\).

## Extracted logical register 40: `TIME_WINDOW`

v11 location: `registers[39]`; truth association: `registers[33]` (`TIME_WINDOW`).

Associated physical locations: 0x3D (61).


### Bottom layer: bit fields, then field parts

#### Field part 1: `TIME_WINDOW` at 0x3D (61)

Locations: `truth registers[33].field_parts` ↔ `v11 registers[39].field_parts[0]`.

**Truth bit field 1: `TW[7:0]` bits 7:0**

Locations: `truth registers[33].field_parts.bit_field[0]` ↔ `v11 registers[39].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TW[7:0] | TW[7:0] |
| `field_description` | 0.0586 | 1.0 | Click time window. | Click time window |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.941694.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TIME_WINDOW | TIME_WINDOW |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":""} | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"Click time window register address"} |
| `description` | 0.0693 | 1.000000 | "" | Click time window value |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | {"name_or_parameter":"TW[7:0]","field_description":"Click time window.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [{"name_or_parameter":"TW[7:0]","field_description":"Click time window","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.981756}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.981756) = **0.981756**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TIME_WINDOW | TIME_WINDOW |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":""} | [{"hex":"0x3D","decimal":"61","bank":"","page":"","description":"Click time window register address"}] |
| `register_description` | 0.0564 | 0.500000 | Sets the click time window. | Click time window register (TW[7:0]) for click detection timing. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.981756 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{40})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.966451/1.0001=\mathbf{0.966354}\).

## Extracted logical register 41: `ACT_THS`

v11 location: `registers[40]`; truth association: `registers[34]` (`ACT_THS`).

Associated physical locations: 0x3E (62).


### Bottom layer: bit fields, then field parts

#### Field part 1: `ACT_THS` at 0x3E (62)

Locations: `truth registers[34].field_parts` ↔ `v11 registers[40].field_parts[0]`.

**Truth bit field 1: `--` bits 7:7**

Locations: `truth registers[34].field_parts.bit_field[0]` ↔ `v11 registers[40].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | -- | -- |
| `field_description` | 0.0586 | 1.0 | "" | Bit 7 shown as '--' in the register bit table; no function described. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `Acth[6:0]` bits 6:0**

Locations: `truth registers[34].field_parts.bit_field[1]` ↔ `v11 registers[40].field_parts[0].bit_field[1]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Acth[6:0] | Acth[6:0] |
| `field_description` | 0.0586 | 1.0 | Sleep-to-wake and return-to-sleep activation threshold in low-power mode. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g. | Sleep-to-wake, return-to-sleep activation threshold in low-power mode. 1 LSb = 16 mg @ FS=±2 g; 32 mg @ FS=±4 g; 62 mg @ FS=±8 g; 186 mg @ FS=±16 g |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.970847.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACT_THS | ACT_THS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":""} | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Activity threshold register address"} |
| `description` | 0.0693 | 1.000000 | "" | Sleep-to-wake / return-to-sleep activation threshold |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | [{"name_or_parameter":"--","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Acth[6:0]","field_description":"Sleep-to-wake and return-to-sleep activation threshold in low-power mode. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"--","field_description":"Bit 7 shown as '--' in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Acth[6:0]","field_description":"Sleep-to-wake, return-to-sleep activation threshold in low-power mode. 1 LSb = 16 mg @ FS=±2 g; 32 mg @ FS=±4 g; 62 mg @ FS=±8 g; 186 mg @ FS=±16 g","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.970847=\mathbf{0.990878}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.990878) = **0.990878**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACT_THS | ACT_THS |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":""} | [{"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Activity threshold register address"}] |
| `register_description` | 0.0564 | 1.000000 | Sets the sleep-to-wake and return-to-sleep activation threshold in low-power mode. | Sleep-to-wake / return-to-sleep activation threshold in low-power mode (Acth[6:0]). Step depends on full scale: 1 LSb = 16 mg @ FS=±2 g, 32 mg @ FS=±4 g, 62 mg @ FS=±8 g, 186 mg @ FS=±16 g. Used with ACT_DUR (3Fh) for activity-based sleep/wake; the activity interrupt can be routed to INT2 via I2_ACT in CTRL_REG6 (25h). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.990878 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{41})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.990878 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.997375/1.0001=\mathbf{0.997276}\).

## Extracted logical register 42: `ACT_DUR`

v11 location: `registers[41]`; truth association: `registers[35]` (`ACT_DUR`).

Associated physical locations: 0x3F (63).


### Bottom layer: bit fields, then field parts

#### Field part 1: `ACT_DUR` at 0x3F (63)

Locations: `truth registers[35].field_parts` ↔ `v11 registers[41].field_parts[0]`.

**Truth bit field 1: `ActD[7:0]` bits 7:0**

Locations: `truth registers[35].field_parts.bit_field[0]` ↔ `v11 registers[41].field_parts[0].bit_field[0]`. Judgment: bottom-up comparison of all bit-field fields.

| Scored field | Weight | C | Truth content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ActD[7:0] | ActD[7:0] |
| `field_description` | 0.0586 | 1.0 | Sleep-to-wake and return-to-sleep duration; 1 LSb = (8*1[LSb]+1)/ODR. | Sleep-to-wake, return-to-sleep duration. 1 LSb = (8*1[LSb]+1)/ODR |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

`bit_field` correctness = 0.941694.


| Field-part field | Weight | Correctness | Truth content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACT_DUR | ACT_DUR |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3F","decimal":"63","bank":"","page":"","description":""} | {"hex":"0x3F","decimal":"63","bank":"","page":"","description":"Activity duration register address"} |
| `description` | 0.0693 | 1.000000 | "" | Sleep-to-wake / return-to-sleep duration |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | {"name_or_parameter":"ActD[7:0]","field_description":"Sleep-to-wake and return-to-sleep duration; 1 LSb = (8*1[LSb]+1)/ODR.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [{"name_or_parameter":"ActD[7:0]","field_description":"Sleep-to-wake, return-to-sleep duration. 1 LSb = (8*1[LSb]+1)/ODR","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":""}] |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.981756}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.981756) = **0.981756**.


| Logical-register field | Weight | Correctness | Truth comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACT_DUR | ACT_DUR |
| `physical_address` | 0.4044 | 1.000000 | {"hex":"0x3F","decimal":"63","bank":"","page":"","description":""} | [{"hex":"0x3F","decimal":"63","bank":"","page":"","description":"Activity duration register address"}] |
| `register_description` | 0.0564 | 0.500000 | Sets the sleep-to-wake and return-to-sleep duration. | Sleep-to-wake / return-to-sleep duration register (ActD[7:0]); 1 LSb = (8*1[LSb]+1)/ODR. Used with ACT_THS (3Eh) for activity-based sleep/wake timing. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.981756 | corresponding truth field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 00000000 | 00000000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{42})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×0.500000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.966451/1.0001=\mathbf{0.966354}\).


## 2. Ground-truth physical-register scores

| Physical address | Associated extracted logical registers | q_R |
|---|---|---:|
| 0x07 (7) | v11 registers[0] `STATUS_REG_AUX`=0.927858 | 0.927858 |
| 0x08 (8) | v11 registers[1] `OUT_ADC1_L`=1.000000 | 1.000000 |
| 0x09 (9) | v11 registers[2] `OUT_ADC1_H`=1.000000 | 1.000000 |
| 0x0A (10) | v11 registers[3] `OUT_ADC2_L`=1.000000 | 1.000000 |
| 0x0B (11) | v11 registers[4] `OUT_ADC2_H`=0.971803 | 0.971803 |
| 0x0C (12) | v11 registers[5] `OUT_ADC3_L`=0.989651 | 0.989651 |
| 0x0D (13) | v11 registers[6] `OUT_ADC3_H`=0.961454 | 0.961454 |
| 0x0F (15) | v11 registers[7] `WHO_AM_I`=1.000000 | 1.000000 |
| 0x1E (30) | v11 registers[8] `CTRL_REG0`=0.889350 | 0.889350 |
| 0x1F (31) | v11 registers[9] `TEMP_CFG_REG`=0.995707 | 0.995707 |
| 0x20 (32) | v11 registers[10] `CTRL_REG1`=0.992043 | 0.992043 |
| 0x21 (33) | v11 registers[11] `CTRL_REG2`=0.994551 | 0.994551 |
| 0x22 (34) | v11 registers[12] `CTRL_REG3`=0.967035 | 0.967035 |
| 0x23 (35) | v11 registers[13] `CTRL_REG4`=0.992918 | 0.992918 |
| 0x24 (36) | v11 registers[14] `CTRL_REG5`=0.981979 | 0.981979 |
| 0x25 (37) | v11 registers[15] `CTRL_REG6`=0.995232 | 0.995232 |
| 0x26 (38) | v11 registers[16] `REFERENCE`=0.966354 | 0.966354 |
| 0x27 (39) | v11 registers[17] `STATUS_REG`=0.966354 | 0.966354 |
| 0x28 (40) | v11 registers[18] `OUT_X_L`=1.000000 | 1.000000 |
| 0x29 (41) | v11 registers[19] `OUT_X_H`=0.971803 | 0.971803 |
| 0x2A (42) | v11 registers[20] `OUT_Y_L`=0.971803 | 0.971803 |
| 0x2B (43) | v11 registers[21] `OUT_Y_H`=0.971803 | 0.971803 |
| 0x2C (44) | v11 registers[22] `OUT_Z_L`=0.971803 | 0.971803 |
| 0x2D (45) | v11 registers[23] `OUT_Z_H`=0.971803 | 0.971803 |
| 0x2E (46) | v11 registers[24] `FIFO_CTRL_REG`=0.993638 | 0.993638 |
| 0x2F (47) | v11 registers[25] `FIFO_SRC_REG`=0.994551 | 0.994551 |
| 0x30 (48) | v11 registers[26] `INT1_CFG`=0.981979 | 0.981979 |
| 0x31 (49) | v11 registers[27] `INT1_SRC`=0.993178 | 0.993178 |
| 0x32 (50) | v11 registers[28] `INT1_THS`=0.969078 | 0.969078 |
| 0x33 (51) | v11 registers[29] `INT1_DURATION`=0.997276 | 0.997276 |
| 0x34 (52) | v11 registers[30] `INT2_CFG`=0.953782 | 0.953782 |
| 0x35 (53) | v11 registers[31] `INT2_SRC`=0.993178 | 0.993178 |
| 0x36 (54) | v11 registers[32] `INT2_THS`=0.969078 | 0.969078 |
| 0x37 (55) | v11 registers[33] `INT2_DURATION`=0.997276 | 0.997276 |
| 0x38 (56) | v11 registers[34] `CLICK_CFG`=0.953782 | 0.953782 |
| 0x39 (57) | v11 registers[35] `CLICK_SRC`=0.995232 | 0.995232 |
| 0x3A (58) | v11 registers[36] `CLICK_THS`=0.983382 | 0.983382 |
| 0x3B (59) | v11 registers[37] `TIME_LIMIT`=0.969078 | 0.969078 |
| 0x3C (60) | v11 registers[38] `TIME_LATENCY`=0.966354 | 0.966354 |
| 0x3D (61) | v11 registers[39] `TIME_WINDOW`=0.966354 | 0.966354 |
| 0x3E (62) | v11 registers[40] `ACT_THS`=0.997276 | 0.997276 |
| 0x3F (63) | v11 registers[41] `ACT_DUR`=0.966354 | 0.966354 |

`Σq_R = 41.092129041`, `n=42`, `m=42`, `x=0`.


\(S_{raw}=(10/42)×41.092129041=\mathbf{9.783840248}.\)

\(S_{final}=S_{raw}×m/(m+x)= 9.783840248×42/(42+0)=\mathbf{9.783840248}/10.\)


## 3. Detailed deduction inventory

- Matched truth physical locations: `42/42`; missing truth physical locations: `0`; extra extracted physical locations counted in `x`: `0`.

- Every type_write_read value is compared strictly; empty truth and empty extraction receive C=1, while missing or mismatched values receive C=0.


| Location | Field | C | Truth content | Extracted content | Exact deduction reason |
|---|---|---:|---|---|---|
| `v11 registers[0].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[0].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[0].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[0].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[0].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[0].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[0].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[0].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[0].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"321OR","field_description":"1, 2 and 3-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3OR","field_description":"3-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 3-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2OR","field_description":"2-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 2-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1OR","field_description":"1-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New data for the 1-axis has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"321DA","field_description":"1, 2 and 3-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"3DA","field_description":"3-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 3-axis is not yet available."},{"value":"1","value_description":"New data for the 3-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2DA","field_description":"2-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 2-axis is not yet available."},{"value":"1","value_description":"New data for the 2-axis is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"1DA","field_description":"1-axis new data available.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"New data for the 1-axis is not yet available."},{"value":"1","value_description":"New data for the 1-axis is available."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"321OR","field_description":"1, 2 and 3-axis data overrun. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"a new set of data has overwritten the previous set"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"3OR","field_description":"3-axis data overrun. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the 3-axis has overwritten the previous data"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"2OR","field_description":"2-axis data overrun. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the 2-axis has overwritten the previous data"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"1OR","field_description":"1-axis data overrun. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the 1-axis has overwritten the previous data"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"321DA","field_description":"1, 2 and 3-axis new data available. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"a new set of data is not yet available"},{"value":"1","value_description":"a new set of data is available"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"3DA","field_description":"3-axis new data available. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"new data for the 3-axis is not yet available"},{"value":"1","value_description":"new data for the 3-axis is available"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"2DA","field_description":"2-axis new data available. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"new data for the 2-axis is not yet available"},{"value":"1","value_description":"new data for the 2-axis is available"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"1DA","field_description":"1-axis new data available. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"new data for the 1-axis is not yet available"},{"value":"1","value_description":"new data for the 1-axis is available"}],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[0]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[0]` | `default_value` | 0.0 | "" | 00000000 | field differs or is incomplete |
| `v11 registers[4]` | `register_description` | 0.5 | Auxiliary 10-bit ADC channel 2 conversion, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 2 conversion result, high byte. Paired with OUT_ADC2_L (0Ah). Refer to Section 3.7 for auxiliary ADC setup. | field differs or is incomplete |
| `v11 registers[5].field_parts[0]` | `description` | 0.5 | Low byte of auxiliary ADC channel 3 conversion or temperature-sensor output. | ADC channel 3 or temperature sensor result low byte (left-aligned 2's complement) | field differs or is incomplete |
| `v11 registers[5]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[6].field_parts[0]` | `description` | 0.5 | High byte of auxiliary ADC channel 3 conversion or temperature-sensor output. | ADC channel 3 or temperature sensor result high byte (left-aligned 2's complement) | field differs or is incomplete |
| `v11 registers[6]` | `register_description` | 0.5 | Auxiliary 10-bit ADC channel 3 conversion or temperature-sensor data output, expressed in 2's complement left-aligned format. | Auxiliary 10-bit ADC channel 3 conversion result high byte, or temperature sensor data output high byte when the temperature sensor is enabled on channel 3. Paired with OUT_ADC3_L (0Ch). Refer to Section 3.7 and Table 5 for the temperature conversion factor. | field differs or is incomplete |
| `v11 registers[6]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[8].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `truth registers[5].field_parts.bit_field[1]` | `name_or_parameter` | 0.0 | bit6 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[1]` | `field_description` | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[1]` | `bit_start` | 0.0 | 6 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[1]` | `bit_end` | 0.0 | 6 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[1]` | `bit_width` | 0.0 | 1 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[1]` | `values` | 0.0 | {"value":0,"value_description":""} | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[1]` | `is_reserved` | 0.0 | false | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[1]` | `type_write_read` | 0.0 | "" | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[2]` | `name_or_parameter` | 0.0 | bit5 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[2]` | `field_description` | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[2]` | `bit_start` | 0.0 | 5 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[2]` | `bit_width` | 0.0 | 1 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[2]` | `values` | 0.0 | {"value":0,"value_description":""} | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[2]` | `is_reserved` | 0.0 | false | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[2]` | `type_write_read` | 0.0 | "" | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[3]` | `name_or_parameter` | 0.0 | bit4 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[3]` | `field_description` | 0.0 | This bit must be set to 1 for correct operation of the device. | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[3]` | `bit_start` | 0.0 | 4 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[3]` | `bit_end` | 0.0 | 4 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[3]` | `bit_width` | 0.0 | 1 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[3]` | `values` | 0.0 | {"value":1,"value_description":""} | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[3]` | `is_reserved` | 0.0 | false | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[3]` | `type_write_read` | 0.0 | "" | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[4]` | `name_or_parameter` | 0.0 | bit3 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[4]` | `field_description` | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[4]` | `bit_start` | 0.0 | 3 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[4]` | `bit_end` | 0.0 | 3 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[4]` | `bit_width` | 0.0 | 1 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[4]` | `values` | 0.0 | {"value":0,"value_description":""} | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[4]` | `is_reserved` | 0.0 | false | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[4]` | `type_write_read` | 0.0 | "" | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[5]` | `name_or_parameter` | 0.0 | bit2 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[5]` | `field_description` | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[5]` | `bit_start` | 0.0 | 2 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[5]` | `bit_end` | 0.0 | 2 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[5]` | `bit_width` | 0.0 | 1 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[5]` | `values` | 0.0 | {"value":0,"value_description":""} | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[5]` | `is_reserved` | 0.0 | false | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[5]` | `type_write_read` | 0.0 | "" | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[6]` | `name_or_parameter` | 0.0 | bit1 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[6]` | `field_description` | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[6]` | `bit_start` | 0.0 | 1 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[6]` | `bit_end` | 0.0 | 1 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[6]` | `bit_width` | 0.0 | 1 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[6]` | `values` | 0.0 | {"value":0,"value_description":""} | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[6]` | `is_reserved` | 0.0 | false | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[6]` | `type_write_read` | 0.0 | "" | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[7]` | `name_or_parameter` | 0.0 | bit0 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[7]` | `field_description` | 0.0 | This bit must be set to 0 for correct operation of the device. | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[7]` | `bit_start` | 0.0 | 0 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[7]` | `bit_end` | 0.0 | 0 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[7]` | `bit_width` | 0.0 | 1 | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[7]` | `values` | 0.0 | {"value":0,"value_description":""} | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[7]` | `is_reserved` | 0.0 | false | MISSING | missing truth bit field |
| `truth registers[5].field_parts.bit_field[7]` | `type_write_read` | 0.0 | "" | MISSING | missing truth bit field |
| `v11 registers[8].field_parts[0].bit_field[1]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"Reserved","field_description":"Bits 6:0 fixed for correct operation. Leave bits 0 through 6 at the default value; bit 4 must be set to 1, the other low bits to 0.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":true,"type_write_read":""} | extra/invented bit field |
| `v11 registers[8].field_parts[0]` | `bit_field` | 0.1 | [{"name_or_parameter":"SDO_PU_DISC","field_description":"Disconnect SDO/SA0 pull-up.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":0,"value_description":"SDO/SA0 internal pull-up connected."},{"value":1,"value_description":"SDO/SA0 internal pull-up disconnected."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"bit6","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":6,"bit_end":6,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit5","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":5,"bit_end":5,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit4","field_description":"This bit must be set to 1 for correct operation of the device.","bit_start":4,"bit_end":4,"bit_width":1,"values":{"value":1,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit3","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":3,"bit_end":3,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit2","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":2,"bit_end":2,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit1","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":1,"bit_end":1,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""},{"name_or_parameter":"bit0","field_description":"This bit must be set to 0 for correct operation of the device.","bit_start":0,"bit_end":0,"bit_width":1,"values":{"value":0,"value_description":""},"is_reserved":false,"type_write_read":""}] | [{"name_or_parameter":"SDO_PU_DISC","field_description":"Disconnect SDO/SA0 pull-up. Default value: 00010000","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"pull-up connected to SDO/SA0 pin"},{"value":"1","value_description":"pull-up disconnected to SDO/SA0 pin"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Reserved","field_description":"Bits 6:0 fixed for correct operation. Leave bits 0 through 6 at the default value; bit 4 must be set to 1, the other low bits to 0.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":true,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[8]` | `register_description` | 0.5 | Controls disconnection of the internal SDO/SA0 pull-up. | Control register 0. Bit 7 (SDO_PU_DISC) disconnects the SDO/SA0 pull-up. Bits 0 through 6 must be left at their default values to ensure correct operation; bit 4 must be set to 1 and the remaining low bits to 0. | field differs or is incomplete |
| `v11 registers[8]` | `field_parts` | 0.7 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[9].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[9].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[9].field_parts[0].bit_field[2]` | `name_or_parameter` | 0.0 | 0 | Reserved | field differs or is incomplete |
| `v11 registers[9].field_parts[0]` | `bit_field` | 1.0 | [{"name_or_parameter":"ADC_EN","field_description":"ADC enable.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"ADC disabled."},{"value":"1","value_description":"ADC enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TEMP_EN","field_description":"Temperature sensor enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Temperature sensor disabled."},{"value":"1","value_description":"Temperature sensor enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"0","field_description":"","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"ADC_EN","field_description":"ADC enable. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"ADC disabled"},{"value":"1","value_description":"ADC enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"TEMP_EN","field_description":"Temperature sensor (T) enable. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"T disabled"},{"value":"1","value_description":"T enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Reserved","field_description":"Bits 5:0 shown as 0 in the register bit table; no function described.","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[9]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[10].field_parts[0].bit_field[0]` | `field_description` | 0.5 | Data-rate and power-mode selection. | Data rate selection. Default value: 0000 | field differs or is incomplete |
| `v11 registers[10].field_parts[0].bit_field[0]` | `values` | 0.5 | [{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}] | [{"value":"0000","value_description":"power-down mode"},{"value":"others","value_description":"Refer to Table 31: Data rate configuration (page 34) for HR/Normal/Low-power mode frequencies"}] | field differs or is incomplete |
| `v11 registers[10].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[10].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[10].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[10].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[10].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[10].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"ODR[3:0]","field_description":"Data-rate and power-mode selection.","bit_start":4,"bit_end":7,"bit_width":4,"values":[{"value":"0000","value_description":"Power-down mode."},{"value":"0001","value_description":"HR / Normal / Low-power mode, 1 Hz."},{"value":"0010","value_description":"HR / Normal / Low-power mode, 10 Hz."},{"value":"0011","value_description":"HR / Normal / Low-power mode, 25 Hz."},{"value":"0100","value_description":"HR / Normal / Low-power mode, 50 Hz."},{"value":"0101","value_description":"HR / Normal / Low-power mode, 100 Hz."},{"value":"0110","value_description":"HR / Normal / Low-power mode, 200 Hz."},{"value":"0111","value_description":"HR / Normal / Low-power mode, 400 Hz."},{"value":"1000","value_description":"Low-power mode, 1.60 kHz."},{"value":"1001","value_description":"HR / normal, 1.344 kHz; low-power mode, 5.376 kHz."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LPen","field_description":"Low-power mode enable.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution mode / normal mode."},{"value":"1","value_description":"Low-power mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Zen","field_description":"Z-axis enable.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Z-axis disabled."},{"value":"1","value_description":"Z-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Yen","field_description":"Y-axis enable.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Y-axis disabled."},{"value":"1","value_description":"Y-axis enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Xen","field_description":"X-axis enable.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"X-axis disabled."},{"value":"1","value_description":"X-axis enabled."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"ODR[3:0]","field_description":"Data rate selection. Default value: 0000","bit_start":4,"bit_end":7,"bit_width":4,"values":[{"value":"0000","value_description":"power-down mode"},{"value":"others","value_description":"Refer to Table 31: Data rate configuration (page 34) for HR/Normal/Low-power mode frequencies"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"LPen","field_description":"Low-power mode enable. Default value: 0 (refer to Section 3.2.1: High-resolution, normal mode, low-power mode)","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"high-resolution mode / normal mode"},{"value":"1","value_description":"low-power mode"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Zen","field_description":"Z-axis enable. Default value: 1","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Z-axis disabled"},{"value":"1","value_description":"Z-axis enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Yen","field_description":"Y-axis enable. Default value: 1","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Y-axis disabled"},{"value":"1","value_description":"Y-axis enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Xen","field_description":"X-axis enable. Default value: 1","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"X-axis disabled"},{"value":"1","value_description":"X-axis enabled"}],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[10]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[11].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[11].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[11].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[11].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[11].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[11].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[11].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"HPM[1:0]","field_description":"High-pass filter mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode, reset by reading REFERENCE (26h)."},{"value":"01","value_description":"Reference signal for filtering."},{"value":"10","value_description":"Normal mode."},{"value":"11","value_description":"Autoreset on interrupt event."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCF[2:1]","field_description":"High-pass filter cutoff-frequency selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FDS","field_description":"Filtered data selection.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Internal filter bypassed."},{"value":"1","value_description":"Data from the internal filter sent to the output register and FIFO."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HPCLICK","field_description":"High-pass filter enable for the CLICK function.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA2","field_description":"High-pass filter enable for the AOI function on interrupt 2.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HP_IA1","field_description":"High-pass filter enable for the AOI function on interrupt 1.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Filter bypassed."},{"value":"1","value_description":"Filter enabled."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"HPM[1:0]","field_description":"High-pass filter mode selection. Default value: 00","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode (reset by reading REFERENCE (26h))"},{"value":"01","value_description":"Reference signal for filtering"},{"value":"10","value_description":"Normal mode"},{"value":"11","value_description":"Autoreset on interrupt event"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"HPCF[2:1]","field_description":"High-pass filter cutoff frequency selection","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"FDS","field_description":"Filtered data selection. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"internal filter bypassed"},{"value":"1","value_description":"data from internal filter sent to output register and FIFO"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"HPCLICK","field_description":"High-pass filter enabled for CLICK function","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"filter bypassed"},{"value":"1","value_description":"filter enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"HP_IA2","field_description":"High-pass filter enabled for AOI function on interrupt 2","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"filter bypassed"},{"value":"1","value_description":"filter enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"HP_IA1","field_description":"High-pass filter enabled for AOI function on interrupt 1","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"filter bypassed"},{"value":"1","value_description":"filter enabled"}],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[11]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[12].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[12].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[12].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[12].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[12].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[12].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[12].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[12].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"I1_CLICK","field_description":"Click interrupt on INT1.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA1","field_description":"IA1 interrupt on INT1.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_IA2","field_description":"IA2 interrupt on INT1.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_ZYXDA","field_description":"ZYXDA interrupt on INT1.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_321DA","field_description":"321DA interrupt on INT1.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_WTM","field_description":"FIFO watermark interrupt on INT1.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I1_OVERRUN","field_description":"FIFO overrun interrupt on INT1.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable."},{"value":"1","value_description":"Enable."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"I1_CLICK","field_description":"Click interrupt on INT1. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I1_IA1","field_description":"IA1 interrupt on INT1. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I1_IA2","field_description":"IA2 interrupt on INT1. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I1_ZYXDA","field_description":"ZYXDA interrupt on INT1. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I1_321DA","field_description":"321DA interrupt on INT1. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I1_WTM","field_description":"FIFO watermark interrupt on INT1. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I1_OVERRUN","field_description":"FIFO overrun interrupt on INT1. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"disable"},{"value":"1","value_description":"enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"--","field_description":"Bit 0 shown as '--' in the register bit table; no function described.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[12]` | `register_description` | 0.5 | Routes click, inertial, data-ready, FIFO watermark and FIFO overrun interrupts to INT1. | Control register 3: enables the interrupt sources routed to the INT1 pin (click, IA1, IA2, ZYXDA, 321DA, FIFO watermark and FIFO overrun). FIFO watermark/overrun behavior is described with FIFO_CTRL_REG (2Eh) and FIFO_SRC_REG (2Fh) in Section 5.1. | field differs or is incomplete |
| `v11 registers[12]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[13].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[13].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[13].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[13].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[13].field_parts[0].bit_field[4]` | `values` | 0.5 | [{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}] | [{"value":"00","value_description":"self-test disabled (Normal mode)"},{"value":"other","value_description":"See Table 39: Self-test mode configuration (page 36): 01 Self-test 0, 10 Self-test 1, 11 --"}] | field differs or is incomplete |
| `v11 registers[13].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[13].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[13].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"BDU","field_description":"Block data update.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Continuous update."},{"value":"1","value_description":"Output registers are not updated until MSB and LSB have been read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"BLE","field_description":"Big/little endian data selection; available only in high-resolution mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Data LSB at lower address."},{"value":"1","value_description":"Data MSB at lower address."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FS[1:0]","field_description":"Full-scale selection.","bit_start":4,"bit_end":5,"bit_width":2,"values":[{"value":"00","value_description":"±2 g."},{"value":"01","value_description":"±4 g."},{"value":"10","value_description":"±8 g."},{"value":"11","value_description":"±16 g."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"HR","field_description":"High-resolution output mode.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"High-resolution disabled."},{"value":"1","value_description":"High-resolution enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ST[1:0]","field_description":"Self-test enable.","bit_start":1,"bit_end":2,"bit_width":2,"values":[{"value":"00","value_description":"Normal mode; self-test disabled."},{"value":"01","value_description":"Self-test 0."},{"value":"10","value_description":"Self-test 1."},{"value":"11","value_description":"--"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SIM","field_description":"SPI serial-interface mode selection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"4-wire interface."},{"value":"1","value_description":"3-wire interface."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"BDU","field_description":"Block data update. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"continuous update"},{"value":"1","value_description":"output registers not updated until MSB and LSB reading"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"BLE","field_description":"Big/little endian data selection. Default value 0. The BLE function can be activated only in high-resolution mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Data LSB @ lower address"},{"value":"1","value_description":"Data MSB @ lower address"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"FS[1:0]","field_description":"Full-scale selection. Default value: 00","bit_start":4,"bit_end":5,"bit_width":2,"values":[{"value":"00","value_description":"±2 g"},{"value":"01","value_description":"±4 g"},{"value":"10","value_description":"±8 g"},{"value":"11","value_description":"±16 g"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"HR","field_description":"High-resolution output mode. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"high-resolution disabled"},{"value":"1","value_description":"high-resolution enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ST[1:0]","field_description":"Self-test enable. Default value: 00","bit_start":1,"bit_end":2,"bit_width":2,"values":[{"value":"00","value_description":"self-test disabled (Normal mode)"},{"value":"other","value_description":"See Table 39: Self-test mode configuration (page 36): 01 Self-test 0, 10 Self-test 1, 11 --"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"SIM","field_description":"SPI serial interface mode selection. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"4-wire interface"},{"value":"1","value_description":"3-wire interface"}],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[13]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[14].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[14].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `truth registers[11].field_parts.bit_field[2]` | `name_or_parameter` | 0.0 | -- | MISSING | missing truth bit field |
| `truth registers[11].field_parts.bit_field[2]` | `field_description` | 0.0 | "" | MISSING | missing truth bit field |
| `truth registers[11].field_parts.bit_field[2]` | `bit_start` | 0.0 | 4 | MISSING | missing truth bit field |
| `truth registers[11].field_parts.bit_field[2]` | `bit_end` | 0.0 | 5 | MISSING | missing truth bit field |
| `truth registers[11].field_parts.bit_field[2]` | `bit_width` | 0.0 | 2 | MISSING | missing truth bit field |
| `truth registers[11].field_parts.bit_field[2]` | `values` | 0.0 | [] | MISSING | missing truth bit field |
| `truth registers[11].field_parts.bit_field[2]` | `is_reserved` | 0.0 | true | MISSING | missing truth bit field |
| `truth registers[11].field_parts.bit_field[2]` | `type_write_read` | 0.0 | RW | MISSING | missing truth bit field |
| `v11 registers[14].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[14].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[14].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[14].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[14].field_parts[0].bit_field[2]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"--","field_description":"Bit 5 shown as '--' in the register bit table; no function described.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | extra/invented bit field |
| `v11 registers[14].field_parts[0].bit_field[3]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"--","field_description":"Bit 4 shown as '--' in the register bit table; no function described.","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | extra/invented bit field |
| `v11 registers[14].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"BOOT","field_description":"Reboot memory content.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Normal mode."},{"value":"1","value_description":"Reboot memory content."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FIFO_EN","field_description":"FIFO enable.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"FIFO disabled."},{"value":"1","value_description":"FIFO enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"--","field_description":"","bit_start":4,"bit_end":5,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT1","field_description":"Latch interrupt request on INT1_SRC; reading INT1_SRC clears it.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT1","field_description":"Enable 4D detection on INT1 when the INT1_CFG 6D bit is set.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"LIR_INT2","field_description":"Latch interrupt request on INT2_SRC; reading INT2_SRC clears it.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt request not latched."},{"value":"1","value_description":"Interrupt request latched."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"D4D_INT2","field_description":"Enable 4D detection on INT2 when the INT2_CFG 6D bit is set.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"BOOT","field_description":"Reboot memory content. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"normal mode"},{"value":"1","value_description":"reboot memory content"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"FIFO_EN","field_description":"FIFO enable. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"FIFO disable"},{"value":"1","value_description":"FIFO enable"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"--","field_description":"Bit 5 shown as '--' in the register bit table; no function described.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"--","field_description":"Bit 4 shown as '--' in the register bit table; no function described.","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"LIR_INT1","field_description":"Latch interrupt request on INT1_SRC register, with INT1_SRC (31h) cleared by reading INT1_SRC itself. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"interrupt request not latched"},{"value":"1","value_description":"interrupt request latched"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"D4D_INT1","field_description":"4D enable: 4D detection is enabled on INT1 when 6D bit on INT1_CFG is set to 1","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"LIR_INT2","field_description":"Latch interrupt request on INT2_SRC (35h) register, with INT2_SRC cleared by reading INT2_SRC itself. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"interrupt request not latched"},{"value":"1","value_description":"interrupt request latched"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"D4D_INT2","field_description":"4D enable: 4D detection is enabled on INT2 pin when 6D bit on INT2_CFG (34h) is set to 1","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[14]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[15].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[15].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | I2_CLICK | "" | type_write_read mismatch |
| `v11 registers[15].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | I2_CLICK | "" | type_write_read mismatch |
| `v11 registers[15].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | I2_CLICK | "" | type_write_read mismatch |
| `v11 registers[15].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | I2_CLICK | "" | type_write_read mismatch |
| `v11 registers[15].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | I2_CLICK | "" | type_write_read mismatch |
| `v11 registers[15].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | I2_CLICK | "" | type_write_read mismatch |
| `v11 registers[15].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"I2_CLICK","field_description":"Click interrupt on INT2 pin.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"I2_IA1","field_description":"Enable interrupt 1 function on INT2 pin.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_IA2","field_description":"Enable interrupt 2 function on INT2 pin.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"Function enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_BOOT","field_description":"Enable boot on INT2 pin.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"I2_ACT","field_description":"Enable activity interrupt on INT2 pin.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disabled."},{"value":"1","value_description":"Enabled."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"--","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"I2_CLICK"},{"name_or_parameter":"INT_POLARITY","field_description":"INT1 and INT2 pin polarity.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Active-high."},{"value":"1","value_description":"Active-low."}],"is_reserved":false,"type_write_read":"I2_CLICK"},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | [{"name_or_parameter":"I2_CLICK","field_description":"Click interrupt on INT2 pin. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"disabled"},{"value":"1","value_description":"enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I2_IA1","field_description":"Enable interrupt 1 function on INT2 pin. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"function disabled"},{"value":"1","value_description":"function enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I2_IA2","field_description":"Enable interrupt 2 function on INT2 pin. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"function disabled"},{"value":"1","value_description":"function enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I2_BOOT","field_description":"Enable boot on INT2 pin. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"disabled"},{"value":"1","value_description":"enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"I2_ACT","field_description":"Enable activity interrupt on INT2 pin. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"disabled"},{"value":"1","value_description":"enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"--","field_description":"Bit 2 shown as '--' in the register bit table; no function described.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"INT_POLARITY","field_description":"INT1 and INT2 pin polarity. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"active-high"},{"value":"1","value_description":"active-low"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"-","field_description":"Bit 0 shown as '-' in the register bit table; no function described.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[15]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[16].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | Ref[7:0] | "" | type_write_read mismatch |
| `v11 registers[16].field_parts[0]` | `bit_field` | 0.9 | {"name_or_parameter":"Ref[7:0]","field_description":"Reference value for interrupt generation.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"Ref[7:0]"} | [{"name_or_parameter":"Ref[7:0]","field_description":"Reference value for Interrupt generation. Default value: 0000 0000","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[16]` | `register_description` | 0.5 | Stores the reference value used for interrupt generation and reference-signal filtering. | Reference value for interrupt generation (Ref[7:0]). Also used by the high-pass filter normal mode, which is reset by reading REFERENCE (see CTRL_REG2 HPM[1:0], Table 34). | field differs or is incomplete |
| `v11 registers[16]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[17].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[17].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[17].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[17].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[17].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[17].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[17].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[17].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[17].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"ZYXOR","field_description":"X, Y and Z-axis data overrun.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"A new set of data has overwritten the previous set."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZOR","field_description":"Z-axis data overrun.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Z-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YOR","field_description":"Y-axis data overrun.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New Y-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XOR","field_description":"X-axis data overrun.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No overrun has occurred."},{"value":"1","value_description":"New X-axis data has overwritten the previous data."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZYXDA","field_description":"X, Y and Z-axis new data available.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"A new set of data is not yet available."},{"value":"1","value_description":"A new set of data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZDA","field_description":"Z-axis new data available.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"New Z-axis data is not yet available."},{"value":"1","value_description":"New Z-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YDA","field_description":"Y-axis new data available.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"New Y-axis data is not yet available."},{"value":"1","value_description":"New Y-axis data is available."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XDA","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"ZYXOR","field_description":"X, Y and Z-axis data overrun. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"a new set of data has overwritten the previous set"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZOR","field_description":"Z-axis data overrun. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"a new data for the Z-axis has overwritten the previous data"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YOR","field_description":"Y-axis data overrun. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the Y-axis has overwritten the previous data"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XOR","field_description":"X-axis data overrun. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"no overrun has occurred"},{"value":"1","value_description":"new data for the X-axis has overwritten the previous data"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZYXDA","field_description":"X, Y and Z-axis new data available. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"a new set of data is not yet available"},{"value":"1","value_description":"a new set of data is available"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZDA","field_description":"Z-axis new data available. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"new data for the Z-axis is not yet available"},{"value":"1","value_description":"new data for the Z-axis is available"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YDA","field_description":"Y-axis new data available. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"new data for the Y-axis is not yet available"},{"value":"1","value_description":"new data for the Y-axis is available"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XDA","field_description":"Bit shown in the STATUS register bit table (X-axis new data available); description row not present in the provided description table.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[17]` | `register_description` | 0.5 | Reports acceleration-axis data-overrun and new-data availability status. | Accelerometer data status register: ZYXOR/ZOR/YOR/XOR report data overrun and ZYXDA/ZDA/YDA/XDA report new data availability for the X, Y and Z axes. Related to the OUT_X/OUT_Y/OUT_Z data registers and the Data-Ready (DRDY) signal (Section: Terminology and functionality). | field differs or is incomplete |
| `v11 registers[17]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[19]` | `register_description` | 0.5 | X-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO X-axis data when FIFO is active. | X-axis acceleration data high byte, two's complement left-justified; paired with OUT_X_L (28h). Also provides FIFO output data when FIFO modes are active (Section 5.1.5). Refer to Section 3.2.1 for the operating-mode data format. | field differs or is incomplete |
| `v11 registers[20]` | `register_description` | 0.5 | Y-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Y-axis data when FIFO is active. | Y-axis acceleration data low byte, two's complement left-justified; paired with OUT_Y_H (2Bh). Provides FIFO output data when FIFO modes are active (Section 5.1.5). Refer to Section 3.2.1 for the operating-mode data format. | field differs or is incomplete |
| `v11 registers[21]` | `register_description` | 0.5 | Y-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Y-axis data when FIFO is active. | Y-axis acceleration data high byte, two's complement left-justified; paired with OUT_Y_L (2Ah). Provides FIFO output data when FIFO modes are active (Section 5.1.5). Refer to Section 3.2.1 for the operating-mode data format. | field differs or is incomplete |
| `v11 registers[22]` | `register_description` | 0.5 | Z-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Z-axis data when FIFO is active. | Z-axis acceleration data low byte, two's complement left-justified; paired with OUT_Z_H (2Dh). Provides FIFO output data when FIFO modes are active (Section 5.1.5). Refer to Section 3.2.1 for the operating-mode data format. | field differs or is incomplete |
| `v11 registers[23]` | `register_description` | 0.5 | Z-axis acceleration data expressed as a two's-complement left-justified value; also presents FIFO Z-axis data when FIFO is active. | Z-axis acceleration data high byte, two's complement left-justified; paired with OUT_Z_L (2Ch). Provides FIFO output data when FIFO modes are active; the auto-incremented read address rolls back to 0x28 after 0x2D (Section 5.1.5). Refer to Section 3.2.1 for the operating-mode data format. | field differs or is incomplete |
| `v11 registers[24].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[24].field_parts[0].bit_field[1]` | `field_description` | 0.5 | Trigger selection for Stream-to-FIFO mode. | Trigger selection. Default value: 0 | field differs or is incomplete |
| `v11 registers[24].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[24].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[24].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"FM[1:0]","field_description":"FIFO mode selection.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass mode."},{"value":"01","value_description":"FIFO mode."},{"value":"10","value_description":"Stream mode."},{"value":"11","value_description":"Stream-to-FIFO mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"TR","field_description":"Trigger selection for Stream-to-FIFO mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Triggering signal on INT1."},{"value":"1","value_description":"Triggering signal on INT2."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FTH[4:0]","field_description":"Programmable FIFO watermark threshold.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"FM[1:0]","field_description":"FIFO mode selection. Default value: 00","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"Bypass mode"},{"value":"01","value_description":"FIFO mode"},{"value":"10","value_description":"Stream mode"},{"value":"11","value_description":"Stream-to-FIFO"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"TR","field_description":"Trigger selection. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"trigger event allows triggering signal on INT1"},{"value":"1","value_description":"trigger event allows triggering signal on INT2"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"FTH[4:0]","field_description":"FIFO watermark threshold. Default value: 00000","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[24]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[25].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[25].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[25].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[25].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[25].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"WTM","field_description":"Set high when FIFO content exceeds the watermark level.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"OVRN_FIFO","field_description":"Set high when the FIFO is full with 32 unread samples; clears when the first sample set is read.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"EMPTY","field_description":"Set high when all FIFO samples have been read and the FIFO is empty.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"FSS [4:0]","field_description":"Current number of unread sample sets stored in the FIFO.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"WTM","field_description":"WTM bit is set high when FIFO content exceeds watermark level","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"OVRN_FIFO","field_description":"OVRN bit is set high when FIFO buffer is full (32 unread samples); at the following ODR a new sample set replaces the oldest FIFO value. The OVRN bit is set to 0 when the first sample set has been read","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"EMPTY","field_description":"EMPTY flag is set high when all FIFO samples have been read and FIFO is empty","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"FSS[4:0]","field_description":"Current number of unread samples stored in the FIFO buffer; increases at ODR frequency until full and decreases each time one sample set is retrieved from FIFO","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[25]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[20].field_parts.bit_field[0]` | `name_or_parameter` | 0.0 | AOI-6D | MISSING | missing truth bit field |
| `truth registers[20].field_parts.bit_field[0]` | `field_description` | 0.0 | Interrupt event-combination and 6-direction recognition mode. | MISSING | missing truth bit field |
| `truth registers[20].field_parts.bit_field[0]` | `bit_start` | 0.0 | 6 | MISSING | missing truth bit field |
| `truth registers[20].field_parts.bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | missing truth bit field |
| `truth registers[20].field_parts.bit_field[0]` | `bit_width` | 0.0 | 2 | MISSING | missing truth bit field |
| `truth registers[20].field_parts.bit_field[0]` | `values` | 0.0 | [{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}] | MISSING | missing truth bit field |
| `truth registers[20].field_parts.bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | missing truth bit field |
| `truth registers[20].field_parts.bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | missing truth bit field |
| `v11 registers[26].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[26].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[26].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[26].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[26].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[26].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[26].field_parts[0].bit_field[0]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"AOI","field_description":"And/Or combination of Interrupt events. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"00 (AOI-6D)","value_description":"OR combination of interrupt events"},{"value":"01 (AOI-6D)","value_description":"6-direction movement recognition"},{"value":"10 (AOI-6D)","value_description":"AND combination of interrupt events"},{"value":"11 (AOI-6D)","value_description":"6-direction position recognition"}],"is_reserved":false,"type_write_read":""} | extra/invented bit field |
| `v11 registers[26].field_parts[0].bit_field[1]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"6D","field_description":"6 direction detection function enabled. Default value: 0 (refer to Table 55: Interrupt mode, page 41)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""} | extra/invented bit field |
| `v11 registers[26].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event or direction recognition.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event or direction recognition.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event or direction recognition.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event or direction recognition.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event or direction recognition.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event or direction recognition.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"AOI","field_description":"And/Or combination of Interrupt events. Default value: 0","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"00 (AOI-6D)","value_description":"OR combination of interrupt events"},{"value":"01 (AOI-6D)","value_description":"6-direction movement recognition"},{"value":"10 (AOI-6D)","value_description":"AND combination of interrupt events"},{"value":"11 (AOI-6D)","value_description":"6-direction position recognition"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"6D","field_description":"6 direction detection function enabled. Default value: 0 (refer to Table 55: Interrupt mode, page 41)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event or on Direction recognition. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event or on Direction recognition. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event or on Direction recognition. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event or on Direction recognition. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event or on Direction recognition. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event or on Direction recognition. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request"}],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[26]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[27].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[27].field_parts[0].bit_field[2]` | `field_description` | 0.5 | Z high event status. | Z high. Default value: 0 | field differs or is incomplete |
| `v11 registers[27].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[27].field_parts[0].bit_field[3]` | `field_description` | 0.5 | Z low event status. | Z low. Default value: 0 | field differs or is incomplete |
| `v11 registers[27].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[27].field_parts[0].bit_field[4]` | `field_description` | 0.5 | Y high event status. | Y high. Default value: 0 | field differs or is incomplete |
| `v11 registers[27].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[27].field_parts[0].bit_field[5]` | `field_description` | 0.5 | Y low event status. | Y low. Default value: 0 | field differs or is incomplete |
| `v11 registers[27].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[27].field_parts[0].bit_field[6]` | `field_description` | 0.5 | X high event status. | X high. Default value: 0 | field differs or is incomplete |
| `v11 registers[27].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[27].field_parts[0].bit_field[7]` | `field_description` | 0.5 | X low event status. | X low. Default value: 0 | field differs or is incomplete |
| `v11 registers[27].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[27].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"0","field_description":"Bit 7 shown as 0 in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt has been generated"},{"value":"1","value_description":"one or more interrupts have been generated"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZH","field_description":"Z high. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZL","field_description":"Z low. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z low event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YH","field_description":"Y high. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YL","field_description":"Y low. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y low event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XH","field_description":"X high. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XL","field_description":"X low. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X low event has occurred"}],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[27]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[28].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[28].field_parts[0]` | `bit_field` | 1.0 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 1 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"0","field_description":"Bit 7 shown as 0 in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 1 threshold. Default value: 000 0000. 1 LSb = 16 mg @ FS=±2 g; 32 mg @ FS=±4 g; 62 mg @ FS=±8 g; 186 mg @ FS=±16 g","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[28]` | `register_description` | 0.5 | Sets the interrupt 1 acceleration threshold. | Interrupt 1 threshold register (THS[6:0]). Threshold step depends on the full scale selected by FS[1:0] in CTRL_REG4 (23h): 1 LSb = 16 mg @ FS=±2 g, 32 mg @ FS=±4 g, 62 mg @ FS=±8 g, 186 mg @ FS=±16 g. | field differs or is incomplete |
| `v11 registers[28]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[29].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[29].field_parts[0]` | `bit_field` | 1.0 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"0","field_description":"Bit 7 shown as 0 in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value. Default value: 000 0000. 1 LSb = 1/ODR","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[29]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[24].field_parts.bit_field[0]` | `name_or_parameter` | 0.0 | AOI-6D | MISSING | missing truth bit field |
| `truth registers[24].field_parts.bit_field[0]` | `field_description` | 0.0 | Interrupt event-combination and 6-direction recognition mode. | MISSING | missing truth bit field |
| `truth registers[24].field_parts.bit_field[0]` | `bit_start` | 0.0 | 6 | MISSING | missing truth bit field |
| `truth registers[24].field_parts.bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | missing truth bit field |
| `truth registers[24].field_parts.bit_field[0]` | `bit_width` | 0.0 | 2 | MISSING | missing truth bit field |
| `truth registers[24].field_parts.bit_field[0]` | `values` | 0.0 | [{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}] | MISSING | missing truth bit field |
| `truth registers[24].field_parts.bit_field[0]` | `is_reserved` | 0.0 | false | MISSING | missing truth bit field |
| `truth registers[24].field_parts.bit_field[0]` | `type_write_read` | 0.0 | RW | MISSING | missing truth bit field |
| `v11 registers[30].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[30].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[30].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[30].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[30].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[30].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[30].field_parts[0].bit_field[0]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"AOI","field_description":"AND/OR combination of interrupt events. Default value: 0 (see Table 64, page 43)","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"00 (AOI-6D)","value_description":"OR combination of interrupt events"},{"value":"01 (AOI-6D)","value_description":"6-direction movement recognition"},{"value":"10 (AOI-6D)","value_description":"AND combination of interrupt events"},{"value":"11 (AOI-6D)","value_description":"6-direction position recognition"}],"is_reserved":false,"type_write_read":""} | extra/invented bit field |
| `v11 registers[30].field_parts[0].bit_field[1]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"6D","field_description":"6-direction detection function enabled. Default value: 0 (refer to Table 64, page 43)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""} | extra/invented bit field |
| `v11 registers[30].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"AOI-6D","field_description":"Interrupt event-combination and 6-direction recognition mode.","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"00","value_description":"OR combination of interrupt events."},{"value":"01","value_description":"6-direction movement recognition."},{"value":"10","value_description":"AND combination of interrupt events."},{"value":"11","value_description":"6-direction position recognition."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is above the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration is below the threshold."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"AOI","field_description":"AND/OR combination of interrupt events. Default value: 0 (see Table 64, page 43)","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"00 (AOI-6D)","value_description":"OR combination of interrupt events"},{"value":"01 (AOI-6D)","value_description":"6-direction movement recognition"},{"value":"10 (AOI-6D)","value_description":"AND combination of interrupt events"},{"value":"11 (AOI-6D)","value_description":"6-direction position recognition"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"6D","field_description":"6-direction detection function enabled. Default value: 0 (refer to Table 64, page 43)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZHIE","field_description":"Enable interrupt generation on Z high event. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZLIE","field_description":"Enable interrupt generation on Z low event. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value lower than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YHIE","field_description":"Enable interrupt generation on Y high event. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YLIE","field_description":"Enable interrupt generation on Y low event. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value lower than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XHIE","field_description":"Enable interrupt generation on X high event. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XLIE","field_description":"Enable interrupt generation on X low event. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value lower than preset threshold"}],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[30]` | `register_description` | 0.5 | Configures interrupt 2 event combination, direction recognition and axis high/low event enables. Its content is loaded at boot, and writing is possible only after system boot. | Interrupt 2 configuration register: AOI and 6D select the interrupt mode (OR/AND combination and 6-direction movement/position recognition; Table 64, page 43), and ZHIE/ZLIE/YHIE/YLIE/XHIE/XLIE enable interrupt generation on measured acceleration higher/lower than the preset threshold per axis. AOI-6D='01' is movement recognition (interrupt held for one ODR); AOI-6D='11' is direction recognition (interrupt held while inside the zone). Content is loaded at boot; a write is possible only after system boot. Latching is controlled by LIR_INT2 in CTRL_REG5 (24h). | field differs or is incomplete |
| `v11 registers[30]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[31].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[31].field_parts[0].bit_field[2]` | `field_description` | 0.5 | Z high event status. | Z high. Default value: 0 | field differs or is incomplete |
| `v11 registers[31].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[31].field_parts[0].bit_field[3]` | `field_description` | 0.5 | Z low event status. | Z low. Default value: 0 | field differs or is incomplete |
| `v11 registers[31].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[31].field_parts[0].bit_field[4]` | `field_description` | 0.5 | Y high event status. | Y high. Default value: 0 | field differs or is incomplete |
| `v11 registers[31].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[31].field_parts[0].bit_field[5]` | `field_description` | 0.5 | Y low event status. | Y low. Default value: 0 | field differs or is incomplete |
| `v11 registers[31].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[31].field_parts[0].bit_field[6]` | `field_description` | 0.5 | X high event status. | X high. Default value: 0 | field differs or is incomplete |
| `v11 registers[31].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[31].field_parts[0].bit_field[7]` | `field_description` | 0.5 | X low event status. | X low. Default value: 0 | field differs or is incomplete |
| `v11 registers[31].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[31].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZH","field_description":"Z high event status.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ZL","field_description":"Z low event status.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YH","field_description":"Y high event status.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"YL","field_description":"Y low event status.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y low event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XH","field_description":"X high event status.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"XL","field_description":"X low event status.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X low event has occurred."}],"is_reserved":false,"type_write_read":"R"}] | [{"name_or_parameter":"0","field_description":"Bit 7 shown as 0 in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt has been generated"},{"value":"1","value_description":"one or more interrupts have been generated"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZH","field_description":"Z high. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZL","field_description":"Z low. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z low event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YH","field_description":"Y high. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YL","field_description":"Y low. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y low event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XH","field_description":"X high. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XL","field_description":"X low. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X low event has occurred"}],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[31]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[32].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[32].field_parts[0]` | `bit_field` | 1.0 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 2 threshold. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"0","field_description":"Bit 7 shown as 0 in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THS[6:0]","field_description":"Interrupt 2 threshold. Default value: 000 0000. 1 LSb = 16 mg @ FS=±2 g; 32 mg @ FS=±4 g; 62 mg @ FS=±8 g; 186 mg @ FS=±16 g","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[32]` | `register_description` | 0.5 | Sets the interrupt 2 acceleration threshold. | Interrupt 2 threshold register (THS[6:0]). Threshold step depends on the full scale selected by FS[1:0] in CTRL_REG4 (23h): 1 LSb = 16 mg @ FS=±2 g, 32 mg @ FS=±4 g, 62 mg @ FS=±8 g, 186 mg @ FS=±16 g. | field differs or is incomplete |
| `v11 registers[32]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[33].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[33].field_parts[0]` | `bit_field` | 1.0 | [{"name_or_parameter":"0","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value; 1 LSb equals 1/ODR.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"0","field_description":"Bit 7 shown as 0 in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"D[6:0]","field_description":"Duration value. Default value: 000 0000. 1 LSb = 1/ODR","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[33]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `truth registers[28].field_parts.bit_field[0]` | `name_or_parameter` | 0.0 | -- | MISSING | missing truth bit field |
| `truth registers[28].field_parts.bit_field[0]` | `field_description` | 0.0 | "" | MISSING | missing truth bit field |
| `truth registers[28].field_parts.bit_field[0]` | `bit_start` | 0.0 | 6 | MISSING | missing truth bit field |
| `truth registers[28].field_parts.bit_field[0]` | `bit_end` | 0.0 | 7 | MISSING | missing truth bit field |
| `truth registers[28].field_parts.bit_field[0]` | `bit_width` | 0.0 | 2 | MISSING | missing truth bit field |
| `truth registers[28].field_parts.bit_field[0]` | `values` | 0.0 | [] | MISSING | missing truth bit field |
| `truth registers[28].field_parts.bit_field[0]` | `is_reserved` | 0.0 | true | MISSING | missing truth bit field |
| `truth registers[28].field_parts.bit_field[0]` | `type_write_read` | 0.0 | "" | MISSING | missing truth bit field |
| `v11 registers[34].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[34].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[34].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[34].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[34].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[34].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[34].field_parts[0].bit_field[0]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"--","field_description":"Bit 7 shown as '--' in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | extra/invented bit field |
| `v11 registers[34].field_parts[0].bit_field[1]` | `bit_field` | 0.0 | MISSING | {"name_or_parameter":"--","field_description":"Bit 6 shown as '--' in the register bit table; no function described.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""} | extra/invented bit field |
| `v11 registers[34].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"--","field_description":"","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"ZD","field_description":"Enable double-click interrupt on Z-axis.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"ZS","field_description":"Enable single-click interrupt on Z-axis.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YD","field_description":"Enable double-click interrupt on Y-axis.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"YS","field_description":"Enable single-click interrupt on Y-axis.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XD","field_description":"Enable double-click interrupt on X-axis.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"XS","field_description":"Enable single-click interrupt on X-axis.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Disable interrupt request."},{"value":"1","value_description":"Enable interrupt request when measured acceleration exceeds the threshold."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"--","field_description":"Bit 7 shown as '--' in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"--","field_description":"Bit 6 shown as '--' in the register bit table; no function described.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"ZD","field_description":"Enable interrupt double click on Z-axis. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"ZS","field_description":"Enable interrupt single click on Z-axis. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YD","field_description":"Enable interrupt double click on Y-axis. Default value: 0","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"YS","field_description":"Enable interrupt single click on Y-axis. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XD","field_description":"Enable interrupt double click on X-axis. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"XS","field_description":"Enable interrupt single click on X-axis. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"disable interrupt request"},{"value":"1","value_description":"enable interrupt request on measured accel. value higher than preset threshold"}],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[34]` | `register_description` | 0.5 | Enables single-click and double-click interrupt detection for the X, Y and Z axes. | Click interrupt configuration register: enables single-click (XS/YS/ZS) and double-click (XD/YD/ZD) interrupt requests per axis on measured acceleration higher than the preset threshold. Click threshold/timing are set by CLICK_THS (3Ah), TIME_LIMIT (3Bh), TIME_LATENCY (3Ch) and TIME_WINDOW (3Dh). | field differs or is incomplete |
| `v11 registers[34]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[35].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | R | "" | type_write_read mismatch |
| `v11 registers[35].field_parts[0].bit_field[2]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[35].field_parts[0].bit_field[3]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[35].field_parts[0].bit_field[4]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[35].field_parts[0].bit_field[5]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[35].field_parts[0].bit_field[6]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[35].field_parts[0].bit_field[7]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[35].field_parts[0]` | `bit_field` | 0.9 | [{"name_or_parameter":"","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt has been generated."},{"value":"1","value_description":"One or more interrupts have been generated."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"DCLICK","field_description":"Double-click enable.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"Double-click detection disabled."},{"value":"1","value_description":"Double-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"SCLICK","field_description":"Single-click enable.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Single-click detection disabled."},{"value":"1","value_description":"Single-click detection enabled."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Sign","field_description":"Click sign.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Positive detection."},{"value":"1","value_description":"Negative detection."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Z","field_description":"Z click detection.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Z high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Y","field_description":"Y click detection.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"Y high event has occurred."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"X","field_description":"X click detection.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"No interrupt."},{"value":"1","value_description":"X high event has occurred."}],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"","field_description":"Bit 7 cell is blank in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"IA","field_description":"Interrupt active. Default value: 0","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt has been generated"},{"value":"1","value_description":"one or more interrupts have been generated"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"DCLICK","field_description":"Double-click enable. Default value: 0","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"double-click detection disabled"},{"value":"1","value_description":"double-click detection enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"SCLICK","field_description":"Single-click enable. Default value: 0","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Single-click detection disabled"},{"value":"1","value_description":"single-click detection enabled"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Sign","field_description":"Click sign","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"positive detection"},{"value":"1","value_description":"negative detection"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Z","field_description":"Z click detection. Default value: 0","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Z high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Y","field_description":"Y click detection. Default value: 0","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"Y high event has occurred"}],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"X","field_description":"X click detection. Default value: 0","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"no interrupt"},{"value":"1","value_description":"X high event has occurred"}],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[35]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[36].field_parts[0].bit_field[0]` | `field_description` | 0.5 | Controls click-interrupt latching. | If not set, the interrupt is kept high for the duration of the latency window; if set, the interrupt is kept high until the CLICK_SRC (39h) register is read | field differs or is incomplete |
| `v11 registers[36].field_parts[0].bit_field[0]` | `values` | 0.0 | [{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}] | [] | field differs or is incomplete |
| `v11 registers[36].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[36].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[36].field_parts[0]` | `bit_field` | 0.8 | [{"name_or_parameter":"LIR_Click","field_description":"Controls click-interrupt latching.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Interrupt remains high for the latency-window duration."},{"value":"1","value_description":"Interrupt remains high until CLICK_SRC is read."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Ths[6:0]","field_description":"Click threshold.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"LIR_Click","field_description":"If not set, the interrupt is kept high for the duration of the latency window; if set, the interrupt is kept high until the CLICK_SRC (39h) register is read","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":""},{"name_or_parameter":"Ths[6:0]","field_description":"Click threshold. Default value: 000 0000","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[36]` | `field_parts` | 0.9 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[37].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[37].field_parts[0]` | `bit_field` | 1.0 | [{"name_or_parameter":"-","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"TLI[6:0]","field_description":"Click time limit.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"-","field_description":"Bit 7 shown as '-' in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"TLI[6:0]","field_description":"Click time limit. Default value: 000 0000","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[37]` | `register_description` | 0.5 | Sets the click time limit. | Click time limit register (TLI[6:0]) for click detection timing. | field differs or is incomplete |
| `v11 registers[37]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[38].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[38].field_parts[0]` | `bit_field` | 0.9 | {"name_or_parameter":"TLA[7:0]","field_description":"Click time latency.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [{"name_or_parameter":"TLA[7:0]","field_description":"Click time latency. Default value: 0000 0000","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[38]` | `register_description` | 0.5 | Sets the click time latency. | Click time latency register (TLA[7:0]) for click detection timing. | field differs or is incomplete |
| `v11 registers[38]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[39].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[39].field_parts[0]` | `bit_field` | 0.9 | {"name_or_parameter":"TW[7:0]","field_description":"Click time window.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [{"name_or_parameter":"TW[7:0]","field_description":"Click time window","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[39]` | `register_description` | 0.5 | Sets the click time window. | Click time window register (TW[7:0]) for click detection timing. | field differs or is incomplete |
| `v11 registers[39]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[40].field_parts[0].bit_field[1]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[40].field_parts[0]` | `bit_field` | 1.0 | [{"name_or_parameter":"--","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Acth[6:0]","field_description":"Sleep-to-wake and return-to-sleep activation threshold in low-power mode. 1 LSb is 16 mg at ±2 g, 32 mg at ±4 g, 62 mg at ±8 g, and 186 mg at ±16 g.","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":"RW"}] | [{"name_or_parameter":"--","field_description":"Bit 7 shown as '--' in the register bit table; no function described.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Acth[6:0]","field_description":"Sleep-to-wake, return-to-sleep activation threshold in low-power mode. 1 LSb = 16 mg @ FS=±2 g; 32 mg @ FS=±4 g; 62 mg @ FS=±8 g; 186 mg @ FS=±16 g","bit_start":0,"bit_end":6,"bit_width":7,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[40]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |
| `v11 registers[41].field_parts[0].bit_field[0]` | `type_write_read` | 0.0 | RW | "" | type_write_read mismatch |
| `v11 registers[41].field_parts[0]` | `bit_field` | 0.9 | {"name_or_parameter":"ActD[7:0]","field_description":"Sleep-to-wake and return-to-sleep duration; 1 LSb = (8*1[LSb]+1)/ODR.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"} | [{"name_or_parameter":"ActD[7:0]","field_description":"Sleep-to-wake, return-to-sleep duration. 1 LSb = (8*1[LSb]+1)/ODR","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":""}] | field differs or is incomplete |
| `v11 registers[41]` | `register_description` | 0.5 | Sets the sleep-to-wake and return-to-sleep duration. | Sleep-to-wake / return-to-sleep duration register (ActD[7:0]); 1 LSb = (8*1[LSb]+1)/ODR. Used with ACT_THS (3Eh) for activity-based sleep/wake timing. | field differs or is incomplete |
| `v11 registers[41]` | `field_parts` | 1.0 | corresponding truth field-part collection | extracted field-part collection | field differs or is incomplete |

## 4. Invented-field and representation check

- Numeric physical addresses are normalized by `(decimal/hex numeric value, bank, page)`; address descriptions do not affect identity.

- Equivalent logical-register merge/split groupings are not penalized solely for grouping; field content is compared at the corresponding physical address.

- Reserved-bit names/descriptions may be empty; structural ranges, reserved status, values, access types, and widths remain scored.



