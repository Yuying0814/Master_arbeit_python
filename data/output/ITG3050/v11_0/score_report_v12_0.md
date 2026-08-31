# ITG3050 v12.0 detailed score — revised AGENTS.md rules

## 1. Scoring basis

- `n=34`, based on unique truth physical keys `(numeric address, bank, page)`; `physical_address.hex` and `physical_address.decimal` are normalized as the same address.
- Every one of the 23 extracted v12_0 logical registers is calculated independently from its truth physical targets: bit fields → field part → logical register `Q(L)`.
- A v12_0 logical register covering multiple truth physical addresses is evaluated once. Its single Q(L) is then associated with every covered truth physical register; the merge itself is not penalized.
- Bit-field targets are matched by exact bit_start/bit_end range. A split of one truth bit range into several v12_0 ranges is reported as an unmatched grouping and does not receive credit merely from coverage; only logical-register merge/split equivalence is exempted by AGENTS.md.
- Description-like scored fields (register_description, description, field_description, and default_value_description) are judged semantically: nonempty wording with preserved meaning is accepted, while missing descriptions normally receive C=0. For reserved bit fields, omitting name_or_parameter and field_description is explicitly accepted. Nested physical_address.description is scored leniently: equivalent/general wording receives C=1, while a missing description with matching numeric address receives C=0.5.
- Objective facts (names except the reserved-bit omission, numeric address/bank/page, widths, exact bit ranges, value codes, is_reserved, access types, and default values) are strict. Numeric-string value codes and singleton object/list representations are normalized when they encode the same fact. When value codes match, non-functional/general wording differences in value_description receive credit.
- For bit-field type_write_read, both empty truth/extracted values are treated as C=1; a one-sided empty/nonempty value or a concrete mismatch is strict.
- Only the AGENTS.md weighted fields are scored; category, index, is_multi_address, source, and all other unlisted fields are excluded.
- Rounded weights are normalized by 0.9999 at bit-field level and 1.0001 at logical-register level; field-part weights sum to 1.0000.

## Extracted logical register 1: `WHO_AM_I`

v12_0 location: `registers[0]`; truth association: `registers[0] (WHO_AM_I)`.
Associated physical locations: 0x00 (0).

### Bottom layer: bit fields, then field parts

#### Field part 1: `WHO_AM_I` at 0x00 (0)

Locations: `truth registers[0].field_parts` ↔ `v12_0 registers[0].field_parts[0]`.

**Truth bit field 1: `I2C_IF_DIS` bits 7:7**

Locations: `truth registers[0].field_parts.bit_field[0]` ↔ `v12_0 registers[0].field_parts[0].bit_field[0]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_IF_DIS | I2C_IF_DIS |
| `field_description` | 0.0586 | 1.0 | Setting this bit disables I²C access mode. | Setting this bit disables I²C access mode. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `ID` bits 6:1**

Locations: `truth registers[0].field_parts.bit_field[1]` ↔ `v12_0 registers[0].field_parts[0].bit_field[1]`. Judgment: truth value enumeration is missing from v12_0; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ID | ID |
| `field_description` | 0.0586 | 1.0 | Contains the 6-bit I²C address of the device. The Power-On-Reset value of Bit6:Bit1 is 110 100. | Contains the 6-bit I²C address of the device. The Power-On-Reset value of Bit6:Bit1 is 110100. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 0.0 | {"value":"110 100","value_description":"Power-On-Reset value of Bit6:Bit1"} | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.731900/0.9999=\mathbf{0.731973}\).

**Truth bit field 3: `Reserved` bits 0:0**

Locations: `truth registers[0].field_parts.bit_field[2]` ↔ `v12_0 registers[0].field_parts[0].bit_field[2]`. Judgment: truth value enumeration is missing from v12_0.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Bit0 is reserved (may be 0 or 1). | Bit0 is reserved. (May be 0 or 1) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":0,"value_description":""},{"value":1,"value_description":""}] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.731973, 0.790279) = **0.821315**. Direct judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Contains device ID and I²C interface disable bit"} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | Device ID and I²C interface control | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.821315 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.821315=\mathbf{0.640390}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.640390) = **0.640390**. Judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4044 | 0.5 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Contains device ID and I²C interface disable bit"} | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | This register is used to verify the identity of the device, and to enable/disable the I²C interface. | Used to verify the identity of the device, and to enable/disable the I²C interface. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.640390 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | ["68h","69h"] | 0x68 or 0x69 |
| `default_value_description` | 0.0334 | 1.0 | [] | "" |

\(Q(L_{1})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.640390 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.623784/1.0001=\mathbf{0.623722}\).

## Extracted logical register 2: `X_OFFS_USR`

v12_0 location: `registers[1]`; truth association: `registers[1] (X_OFFS_USRH)`, `registers[2] (X_OFFS_USRL)`.
Associated physical locations: 0x0C (12), 0x0D (13).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v12_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `X_OFFS_USRH` at 0x0C (12)

Locations: `truth registers[1].field_parts` ↔ `v12_0 registers[1].field_parts[0]`.

**Truth bit field 1: `X_OFFS_H` bits 7:0**

Locations: `truth registers[1].field_parts.bit_field` ↔ `v12_0 registers[1].field_parts[0].bit_field[0]`. Judgment: name_or_parameter is objectively different; field_description is missing; truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | X_OFFS_H | X_OFF_H |
| `field_description` | 0.0586 | 0.0 | High byte of 16-bit X gyro offset (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.861800/0.9999=\mathbf{0.861886}\).

**Field-part aggregation**

bit_field correctness = mean(0.861886) = **0.861886**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | X_OFFS_USRH | X_OFFS_USRH |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"High byte of X gyro offset (X_OFFS_H)"} | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit X gyro offset (two's complement). | High byte of X gyro offset |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.861886 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.861886=\mathbf{0.956784}\).

#### Field part 2: `X_OFFS_USRL` at 0x0D (13)

Locations: `truth registers[2].field_parts` ↔ `v12_0 registers[1].field_parts[1]`.

**Truth bit field 1: `X_OFFS_L` bits 7:0**

Locations: `truth registers[2].field_parts.bit_field` ↔ `v12_0 registers[1].field_parts[1].bit_field[0]`. Judgment: name_or_parameter is objectively different; field_description is missing; truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | X_OFFS_L | X_OFF_L |
| `field_description` | 0.0586 | 0.0 | Low byte of 16-bit X gyro offset (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.861800/0.9999=\mathbf{0.861886}\).

**Field-part aggregation**

bit_field correctness = mean(0.861886) = **0.861886**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | X_OFFS_USRL | X_OFFS_USRL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Low byte of X gyro offset (X_OFFS_L)"} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit X gyro offset (two's complement). | Low byte of X gyro offset |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.861886 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.861886=\mathbf{0.956784}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.956784, 0.956784) = **0.956784**. Judgment: equivalent multi-physical logical-register grouping accepted.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | X_OFFS_USRH + X_OFFS_USRL | X_OFFS_USR |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"High byte of X gyro offset (X_OFFS_H)"},{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Low byte of X gyro offset (X_OFFS_L)"}] | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"High byte"},{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Low byte"}] |
| `register_description` | 0.0564 | 1.0 | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). \| These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | 16-bit offset (high and low bytes) of X gyro offset (2's complement). Used to remove DC bias from the sensor outputs. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.956784 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | "" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{2})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.956784 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.987191/1.0001=\mathbf{0.987093}\).

## Extracted logical register 3: `Y_OFFS_USR`

v12_0 location: `registers[2]`; truth association: `registers[3] (Y_OFFS_USRH)`, `registers[4] (Y_OFFS_USRL)`.
Associated physical locations: 0x0E (14), 0x0F (15).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v12_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Y_OFFS_USRH` at 0x0E (14)

Locations: `truth registers[3].field_parts` ↔ `v12_0 registers[2].field_parts[0]`.

**Truth bit field 1: `Y_OFFS_H` bits 7:0**

Locations: `truth registers[3].field_parts.bit_field` ↔ `v12_0 registers[2].field_parts[0].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Y_OFFS_H | Y_OFFS_H |
| `field_description` | 0.0586 | 0.0 | High byte of 16-bit Y gyro offset (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Y_OFFS_USRH | Y_OFFS_USRH |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0E","decimal":"14","bank":"","page":"","description":"High byte of Y gyro offset (Y_OFFS_H)"} | {"hex":"0x0E","decimal":"14","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Y gyro offset (two's complement). | High byte of Y gyro offset |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

#### Field part 2: `Y_OFFS_USRL` at 0x0F (15)

Locations: `truth registers[4].field_parts` ↔ `v12_0 registers[2].field_parts[1]`.

**Truth bit field 1: `Y_OFFS_L` bits 7:0**

Locations: `truth registers[4].field_parts.bit_field` ↔ `v12_0 registers[2].field_parts[1].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Y_OFFS_L | Y_OFFS_L |
| `field_description` | 0.0586 | 0.0 | Low byte of 16-bit Y gyro offset (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Y_OFFS_USRL | Y_OFFS_USRL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Low byte of Y gyro offset (Y_OFFS_L)"} | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Y gyro offset (two's complement). | Low byte of Y gyro offset |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.963418, 0.963418) = **0.963418**. Judgment: equivalent multi-physical logical-register grouping accepted.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Y_OFFS_USRH + Y_OFFS_USRL | Y_OFFS_USR |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x0E","decimal":"14","bank":"","page":"","description":"High byte of Y gyro offset (Y_OFFS_H)"},{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Low byte of Y gyro offset (Y_OFFS_L)"}] | [{"hex":"0x0E","decimal":"14","bank":"","page":"","description":"High byte"},{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Low byte"}] |
| `register_description` | 0.0564 | 1.0 | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). \| These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | 16-bit offset (high and low bytes) of Y gyro offset (2's complement). Used to remove DC bias from the sensor outputs. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.963418 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | "" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{3})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.963418 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.989173/1.0001=\mathbf{0.989074}\).

## Extracted logical register 4: `Z_OFFS_USR`

v12_0 location: `registers[3]`; truth association: `registers[5] (Z_OFFS_USRH)`, `registers[6] (Z_OFFS_USRL)`.
Associated physical locations: 0x10 (16), 0x11 (17).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v12_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Z_OFFS_USRH` at 0x10 (16)

Locations: `truth registers[5].field_parts` ↔ `v12_0 registers[3].field_parts[0]`.

**Truth bit field 1: `Z_OFFS_H` bits 7:0**

Locations: `truth registers[5].field_parts.bit_field` ↔ `v12_0 registers[3].field_parts[0].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Z_OFFS_H | Z_OFFS_H |
| `field_description` | 0.0586 | 0.0 | High byte of 16-bit Z gyro offset (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Z_OFFS_USRH | Z_OFFS_USRH |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"High byte of Z gyro offset (Z_OFFS_H)"} | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Z gyro offset (two's complement). | High byte of Z gyro offset |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

#### Field part 2: `Z_OFFS_USRL` at 0x11 (17)

Locations: `truth registers[6].field_parts` ↔ `v12_0 registers[3].field_parts[1]`.

**Truth bit field 1: `Z_OFFS_L` bits 7:0**

Locations: `truth registers[6].field_parts.bit_field` ↔ `v12_0 registers[3].field_parts[1].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Z_OFFS_L | Z_OFFS_L |
| `field_description` | 0.0586 | 0.0 | Low byte of 16-bit Z gyro offset (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Z_OFFS_USRL | Z_OFFS_USRL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Low byte of Z gyro offset (Z_OFFS_L)"} | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Z gyro offset (two's complement). | Low byte of Z gyro offset |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.963418, 0.963418) = **0.963418**. Judgment: equivalent multi-physical logical-register grouping accepted.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Z_OFFS_USRH + Z_OFFS_USRL | Z_OFFS_USR |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x10","decimal":"16","bank":"","page":"","description":"High byte of Z gyro offset (Z_OFFS_H)"},{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Low byte of Z gyro offset (Z_OFFS_L)"}] | [{"hex":"0x10","decimal":"16","bank":"","page":"","description":"High byte"},{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Low byte"}] |
| `register_description` | 0.0564 | 1.0 | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). \| These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | 16-bit offset (high and low bytes) of Z gyro offset (2's complement). Used to remove DC bias from the sensor outputs. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.963418 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | "" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{4})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.963418 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.989173/1.0001=\mathbf{0.989074}\).

## Extracted logical register 5: `FIFO_EN`

v12_0 location: `registers[4]`; truth association: `registers[7] (FIFO_EN)`.
Associated physical locations: 0x12 (18).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_EN` at 0x12 (18)

Locations: `truth registers[7].field_parts` ↔ `v12_0 registers[4].field_parts[0]`.

**Truth bit field 1: `TEMP_OUT` bits 7:7**

Locations: `truth registers[7].field_parts.bit_field[0]` ↔ `v12_0 registers[4].field_parts[0].bit_field[0]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_OUT | TEMP_OUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Temperature reading into FIFO. | Setting this inserts the Temperature reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `GYRO_XOUT` bits 6:6**

Locations: `truth registers[7].field_parts.bit_field[1]` ↔ `v12_0 registers[4].field_parts[0].bit_field[1]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_XOUT | GYRO_XOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the X Gyro reading into FIFO. | Setting this inserts the X Gyro reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `GYRO_YOUT` bits 5:5**

Locations: `truth registers[7].field_parts.bit_field[2]` ↔ `v12_0 registers[4].field_parts[0].bit_field[2]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_YOUT | GYRO_YOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Y Gyro reading into FIFO. | Setting this inserts the Y Gyro reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `GYRO_ZOUT` bits 4:4**

Locations: `truth registers[7].field_parts.bit_field[3]` ↔ `v12_0 registers[4].field_parts[0].bit_field[3]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_ZOUT | GYRO_ZOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Z Gyro reading into FIFO. | Setting this inserts the Z Gyro reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `AUX_XOUT` bits 3:3**

Locations: `truth registers[7].field_parts.bit_field[4]` ↔ `v12_0 registers[4].field_parts[0].bit_field[4]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_XOUT | AUX_XOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the X Accelerometer reading into FIFO. | Setting this inserts the X Accelerometer reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 6: `AUX_YOUT` bits 2:2**

Locations: `truth registers[7].field_parts.bit_field[5]` ↔ `v12_0 registers[4].field_parts[0].bit_field[5]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_YOUT | AUX_YOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Y Accelerometer reading into FIFO. | Setting this inserts the Y Accelerometer reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 7: `AUX_ZOUT` bits 1:1**

Locations: `truth registers[7].field_parts.bit_field[6]` ↔ `v12_0 registers[4].field_parts[0].bit_field[6]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_ZOUT | AUX_ZOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Z Accelerometer reading into FIFO. | Setting this inserts the Z Accelerometer reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 8: `FIFO_FOOTER` bits 0:0**

Locations: `truth registers[7].field_parts.bit_field[7]` ↔ `v12_0 registers[4].field_parts[0].bit_field[7]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_FOOTER | FIFO_FOOTER |
| `field_description` | 0.0586 | 1.0 | Last word (2 bytes) for FIFO read; described in more detail in register 60. | Last word (2 bytes) for FIFO read. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**. Direct judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | FIFO_EN | FIFO_EN |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"FIFO enable bits (select which sensor data are written into FIFO)"} | {"hex":"0x12","decimal":"18","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | Enable selection for data inserted into FIFO; each bit inserts the listed data into the FIFO when set. | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.678056}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**. Judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | FIFO_EN | FIFO_EN |
| `physical_address` | 0.4044 | 0.5 | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"FIFO enable bits (select which sensor data are written into FIFO)"} | [{"hex":"0x12","decimal":"18","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Determines what data goes into the ITG-3050 FIFO (512 byte FIFO); sensor data is automatically placed into the FIFO after each ADC sampling period. | Determines what data goes into the ITG-3050 FIFO. Sensor data is automatically placed into the FIFO after each ADC sampling period. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x00 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{5})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.635035/1.0001=\mathbf{0.634972}\).

## Extracted logical register 6: `AUX_VDDIO`

v12_0 location: `registers[5]`; truth association: `registers[8] (AUX_VDDIO)`.
Associated physical locations: 0x13 (19).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_VDDIO` at 0x13 (19)

Locations: `truth registers[8].field_parts` ↔ `v12_0 registers[5].field_parts[0]`.

**Truth bit field 1: `Reserved` bits 7:3**

Locations: `truth registers[8].field_parts.bit_field[0]` ↔ `v12_0: missing`. Judgment: truth bit-field target has no exact v12_0 bit range.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Reserved | MISSING |
| `field_description` | 0.0586 | 0.0 | Load zeros into bits 7..3 (must be 0). | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 5 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 2: `AUX_VDDIO` bits 2:2**

Locations: `truth registers[8].field_parts.bit_field[1]` ↔ `v12_0 registers[5].field_parts[0].bit_field[2]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_VDDIO | AUX_VDDIO |
| `field_description` | 0.0586 | 1.0 | I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1=VDD, 0=VLOGIC. | I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1=VDD, 0=VLOGIC. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `Reserved` bits 1:0**

Locations: `truth registers[8].field_parts.bit_field[2]` ↔ `v12_0: missing`. Judgment: truth bit-field target has no exact v12_0 bit range.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Reserved | MISSING |
| `field_description` | 0.0586 | 0.0 | Load zeros into bits 1..0 (must be 0). | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 2 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

Additional v12_0 bit field not matched to an exact truth range: `v12_0 registers[5].field_parts[0].bit_field[0]` (Reserved, bits 7:6). It is reported but not credited.
Additional v12_0 bit field not matched to an exact truth range: `v12_0 registers[5].field_parts[0].bit_field[1]` (Reserved, bits 5:4). It is reported but not credited.
Additional v12_0 bit field not matched to an exact truth range: `v12_0 registers[5].field_parts[0].bit_field[3]` (Reserved, bits 1:1). It is reported but not credited.
Additional v12_0 bit field not matched to an exact truth range: `v12_0 registers[5].field_parts[0].bit_field[4]` (Reserved, bits 0:0). It is reported but not credited.
**Field-part aggregation**

bit_field correctness = mean(0.000000, 0.941694, 0.000000) = **0.313898**. Direct judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_VDDIO | AUX_VDDIO |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Auxiliary I/O voltage selection bit"} | {"hex":"0x13","decimal":"19","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | I/O logic level selection for the secondary I²C bus lines; other bits must be written as zeros. | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.313898 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.313898=\mathbf{0.481619}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.481619) = **0.481619**. Judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_VDDIO | AUX_VDDIO |
| `physical_address` | 0.4044 | 0.5 | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Auxiliary I/O voltage selection bit"} | [{"hex":"0x13","decimal":"19","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Determines the I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1 = VDD, 0 = VLOGIC. | Determines the I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1=VDD, 0=VLOGIC. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.481619 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x00 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{6})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.481619 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.576360/1.0001=\mathbf{0.576302}\).

## Extracted logical register 7: `AUX_SLV_ADDR`

v12_0 location: `registers[6]`; truth association: `registers[9] (AUX_SLV_ADDR)`.
Associated physical locations: 0x14 (20).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_SLV_ADDR` at 0x14 (20)

Locations: `truth registers[9].field_parts` ↔ `v12_0 registers[6].field_parts[0]`.

**Truth bit field 1: `CLKOUT_EN` bits 7:7**

Locations: `truth registers[9].field_parts.bit_field[0]` ↔ `v12_0 registers[6].field_parts[0].bit_field[0]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | CLKOUT_EN | CLKOUT_EN |
| `field_description` | 0.0586 | 1.0 | 1 = reference clock output is provided at CLKOUT pin; 0 = function disabled. | 1 – reference clock output is provided at CLKOUT pin. 0 – function is disabled. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `AUX_ID` bits 6:0**

Locations: `truth registers[9].field_parts.bit_field[1]` ↔ `v12_0 registers[6].field_parts[0].bit_field[1]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_ID | AUX_ID |
| `field_description` | 0.0586 | 1.0 | Contains the I²C address of the external accelerometer device (bits 6:0). | Contains the I²C address of the device, which can also be changed by writing to this register. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694) = **0.941694**. Direct judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_SLV_ADDR | AUX_SLV_ADDR |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Auxiliary device 7-bit slave address and CLKOUT enable"} | {"hex":"0x14","decimal":"20","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | CLKOUT enable and auxiliary device address (AUX_ID). | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.678056}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**. Judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_SLV_ADDR | AUX_SLV_ADDR |
| `physical_address` | 0.4044 | 0.5 | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Auxiliary device 7-bit slave address and CLKOUT enable"} | [{"hex":"0x14","decimal":"20","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Contains the 7-bit slave address of the external accelerometer device and the CLKOUT enable bit. Used by the ITG-3050 when acting as I²C master for the auxiliary sensor. | Contains the 7-bit slave address of the external accelerometer device. This address is used to access the accel device so that its sensor reading can be automatically read during each sample period. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x00 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{7})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.635035/1.0001=\mathbf{0.634972}\).

## Extracted logical register 8: `SMPLRT_DIV`

v12_0 location: `registers[7]`; truth association: `registers[10] (SMPLRT_DIV)`.
Associated physical locations: 0x15 (21).

### Bottom layer: bit fields, then field parts

#### Field part 1: `SMPLRT_DIV` at 0x15 (21)

Locations: `truth registers[10].field_parts` ↔ `v12_0 registers[7].field_parts[0]`.

**Truth bit field 1: `SMPLRT_DIV` bits 7:0**

Locations: `truth registers[10].field_parts.bit_field` ↔ `v12_0 registers[7].field_parts[0].bit_field[0]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SMPLRT_DIV | SMPLRT_DIV |
| `field_description` | 0.0586 | 1.0 | Sample rate divider. F_sample = F_internal / (divider + 1). | Sample rate divider: 0 to 255. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**. Direct judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | SMPLRT_DIV | SMPLRT_DIV |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Sample rate divider"} | {"hex":"0x15","decimal":"21","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | Sample rate divider (0-255). | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.678056}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**. Judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | SMPLRT_DIV | SMPLRT_DIV |
| `physical_address` | 0.4044 | 0.5 | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Sample rate divider"} | [{"hex":"0x15","decimal":"21","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Determines the sample rate of the ITG-3050 gyros. F_sample = F_internal / (divider + 1), where F_internal is either 1kHz or 8kHz (set by DLPF_CFG). | Determines the sample rate of the ITG-3050 gyros. The sample rate is given by F_sample = F_internal / (divider + 1), where F_internal is either 1kHz or 8kHz. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x00 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{8})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.635035/1.0001=\mathbf{0.634972}\).

## Extracted logical register 9: `DLPF_FS_SYNC`

v12_0 location: `registers[8]`; truth association: `registers[11] (DLPF_FS_SYNC)`.
Associated physical locations: 0x16 (22).

### Bottom layer: bit fields, then field parts

#### Field part 1: `DLPF_FS_SYNC` at 0x16 (22)

Locations: `truth registers[11].field_parts` ↔ `v12_0 registers[8].field_parts[0]`.

**Truth bit field 1: `EXT_SYNC_SET` bits 7:5**

Locations: `truth registers[11].field_parts.bit_field[0]` ↔ `v12_0 registers[8].field_parts[0].bit_field[0]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | EXT_SYNC_SET | EXT_SYNC_SET |
| `field_description` | 0.0586 | 1.0 | Routing for the external frame synchronization input bit. | Routing for the external frame synchronization input bit. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No sync (default)"},{"value":"1","value_description":"TEMP_OUT_L[0]"},{"value":"2","value_description":"GYRO_XOUT_L[0]"},{"value":"3","value_description":"GYRO_YOUT_L[0]"},{"value":"4","value_description":"GYRO_ZOUT_L[0]"},{"value":"5","value_description":"AUX_XOUT_L[0]"},{"value":"6","value_description":"AUX_YOUT_L[0]"},{"value":"7","value_description":"AUX_ZOUT_L[0]"}] | [{"value":"0","value_description":"No sync (default)"},{"value":"1","value_description":"TEMP_OUT_L[0]"},{"value":"2","value_description":"GYRO_XOUT_L[0]"},{"value":"3","value_description":"GYRO_YOUT_L[0]"},{"value":"4","value_description":"GYRO_ZOUT_L[0]"},{"value":"5","value_description":"AUX_XOUT_L[0]"},{"value":"6","value_description":"AUX_YOUT_L[0]"},{"value":"7","value_description":"AUX_ZOUT_L[0]"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `FS_SEL` bits 4:3**

Locations: `truth registers[11].field_parts.bit_field[1]` ↔ `v12_0 registers[8].field_parts[0].bit_field[1]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FS_SEL | FS_SEL |
| `field_description` | 0.0586 | 1.0 | Full scale selection for gyro sensor data. | Full scale selection for gyro sensor data. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"±250°/sec"},{"value":"1","value_description":"±500°/sec"},{"value":"2","value_description":"±1000°/sec"},{"value":"3","value_description":"±2000°/sec"}] | [{"value":"0","value_description":"±250°/sec"},{"value":"1","value_description":"±500°/sec"},{"value":"2","value_description":"±1000°/sec"},{"value":"3","value_description":"±2000°/sec"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `DLPF_CFG` bits 2:0**

Locations: `truth registers[11].field_parts.bit_field[2]` ↔ `v12_0 registers[8].field_parts[0].bit_field[2]`. Judgment: objective value-code set matches; value-description wording has no functional deviation and is accepted; truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DLPF_CFG | DLPF_CFG |
| `field_description` | 0.0586 | 1.0 | Digital low pass filter configuration; also determines internal analog sampling rate. | Digital low pass filter configuration. Also determines the internal analog sampling rate. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Low pass filter bandwidth 256Hz; Analog sample rate 8kHz"},{"value":"1","value_description":"Low pass filter bandwidth 188Hz; Analog sample rate 1kHz"},{"value":"2","value_description":"Low pass filter bandwidth 98Hz; Analog sample rate 1kHz"},{"value":"3","value_description":"Low pass filter bandwidth 42Hz; Analog sample rate 1kHz"},{"value":"4","value_description":"Low pass filter bandwidth 20Hz; Analog sample rate 1kHz"},{"value":"5","value_description":"Low pass filter bandwidth 10Hz; Analog sample rate 1kHz"},{"value":"6","value_description":"Low pass filter bandwidth 5Hz; Analog sample rate 1kHz"}] | [{"value":"0","value_description":"Low Pass Filter Bandwidth: 256Hz, Analog Sample Rate: 8kHz"},{"value":"1","value_description":"Low Pass Filter Bandwidth: 188Hz, Analog Sample Rate: 1kHz"},{"value":"2","value_description":"Low Pass Filter Bandwidth: 98Hz, Analog Sample Rate: 1kHz"},{"value":"3","value_description":"Low Pass Filter Bandwidth: 42Hz, Analog Sample Rate: 1kHz"},{"value":"4","value_description":"Low Pass Filter Bandwidth: 20Hz, Analog Sample Rate: 1kHz"},{"value":"5","value_description":"Low Pass Filter Bandwidth: 10Hz, Analog Sample Rate: 1kHz"},{"value":"6","value_description":"Low Pass Filter Bandwidth: 5Hz, Analog Sample Rate: 1kHz"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694) = **0.941694**. Direct judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | DLPF_FS_SYNC | DLPF_FS_SYNC |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"DLPF_CFG, FS_SEL, and EXT_SYNC_SET configuration"} | {"hex":"0x16","decimal":"22","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | EXT_SYNC_SET (bits7:5), FS_SEL (bits4:3), DLPF_CFG (bits2:0). | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.678056}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**. Judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | DLPF_FS_SYNC | DLPF_FS_SYNC |
| `physical_address` | 0.4044 | 0.5 | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"DLPF_CFG, FS_SEL, and EXT_SYNC_SET configuration"} | [{"hex":"0x16","decimal":"22","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Configures external sync routing (EXT_SYNC_SET), full-scale range (FS_SEL), and digital low-pass filter (DLPF_CFG). | Configures several parameters related to the sensor acquisition: EXT_SYNC_SET, FS_SEL, DLPF_CFG. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x00 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{9})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.635035/1.0001=\mathbf{0.634972}\).

## Extracted logical register 10: `INT_CFG`

v12_0 location: `registers[9]`; truth association: `registers[12] (INT_CFG)`.
Associated physical locations: 0x17 (23).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_CFG` at 0x17 (23)

Locations: `truth registers[12].field_parts` ↔ `v12_0 registers[9].field_parts[0]`.

**Truth bit field 1: `ACTL` bits 7:7**

Locations: `truth registers[12].field_parts.bit_field[0]` ↔ `v12_0 registers[9].field_parts[0].bit_field[0]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACTL | ACTL |
| `field_description` | 0.0586 | 1.0 | Logic level for INT output pin - 1=active low, 0=active high. | Logic level for INT output pin – 1=active low, 0=active high. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `OPEN` bits 6:6**

Locations: `truth registers[12].field_parts.bit_field[1]` ↔ `v12_0 registers[9].field_parts[0].bit_field[1]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | OPEN | OPEN |
| `field_description` | 0.0586 | 1.0 | Drive type for INT output pin - 1=open drain, 0=push-pull. | Drive type for INT output pin – 1=open drain, 0=push-pull. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `LATCH_INT_EN` bits 5:5**

Locations: `truth registers[12].field_parts.bit_field[2]` ↔ `v12_0 registers[9].field_parts[0].bit_field[2]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LATCH_INT_EN | LATCH_INT_EN |
| `field_description` | 0.0586 | 1.0 | "Latch mode - 1=latch until interrupt is cleared, 0=50\u0000us pulse." | Latch mode – 1=latch until interrupt is cleared, 0=50us pulse. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `INT_ANYRD_2CLEAR` bits 4:4**

Locations: `truth registers[12].field_parts.bit_field[3]` ↔ `v12_0 registers[9].field_parts[0].bit_field[3]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | INT_ANYRD_2CLEAR | INT_ANYRD_2CLEAR |
| `field_description` | 0.0586 | 1.0 | Interrupt status register clear method - 1=clear by reading any register, 0=clear by reading interrupt status register (26) only. | Interrupt status register clear method – 1=clear by reading any register, 0=clear by reading interrupt status register (26) only. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `Reserved` bits 3:3**

Locations: `truth registers[12].field_parts.bit_field[4]` ↔ `v12_0 registers[9].field_parts[0].bit_field[4]`. Judgment: reserved-bit name/description omission is permitted.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | No function defined for this bit (reserved). | "" |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 6: `ITG_RDY_EN` bits 2:2**

Locations: `truth registers[12].field_parts.bit_field[5]` ↔ `v12_0 registers[9].field_parts[0].bit_field[5]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ITG_RDY_EN | ITG_RDY_EN |
| `field_description` | 0.0586 | 1.0 | Enable interrupt when device is ready (PLL ready after changing clock source). | Enable interrupt when device is ready (PLL ready after changing clock source). |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 7: `Reserved` bits 1:1**

Locations: `truth registers[12].field_parts.bit_field[6]` ↔ `v12_0 registers[9].field_parts[0].bit_field[6]`. Judgment: reserved-bit name/description omission is permitted.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | No function defined for this bit (reserved). | "" |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 8: `RAW_RDY_EN` bits 0:0**

Locations: `truth registers[12].field_parts.bit_field[7]` ↔ `v12_0 registers[9].field_parts[0].bit_field[7]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | RAW_RDY_EN | RAW_RDY_EN |
| `field_description` | 0.0586 | 1.0 | Enable interrupt when data is available (raw data ready). | Enable interrupt when data is available. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694, 1.000000, 0.941694, 1.000000, 0.941694) = **0.956271**. Direct judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | INT_CFG | INT_CFG |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Interrupt configuration"} | {"hex":"0x17","decimal":"23","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | Interrupt pin configuration, latch mode, and interrupt enables. | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.956271 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.956271=\mathbf{0.682617}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.682617) = **0.682617**. Judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | INT_CFG | INT_CFG |
| `physical_address` | 0.4044 | 0.5 | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Interrupt configuration"} | [{"hex":"0x17","decimal":"23","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Configures the interrupt operation: INT pin polarity and drive type, latch/clear behavior, and which sources generate interrupts. | Configures the interrupt operation of the ITG-3050. The interrupt output pin (INT) configuration, latching/clearing method, and triggers can be set. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.682617 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x00 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{10})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.682617 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.636398/1.0001=\mathbf{0.636334}\).

## Extracted logical register 11: `AUX_ADDR`

v12_0 location: `registers[10]`; truth association: `registers[13] (AUX_ADDR)`.
Associated physical locations: 0x18 (24).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_ADDR` at 0x18 (24)

Locations: `truth registers[13].field_parts` ↔ `v12_0 registers[10].field_parts[0]`.

**Truth bit field 1: `BURST_ADDR` bits 7:0**

Locations: `truth registers[13].field_parts.bit_field` ↔ `v12_0 registers[10].field_parts[0].bit_field[0]`. Judgment: truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | BURST_ADDR | BURST_ADDR |
| `field_description` | 0.0586 | 1.0 | Burst-mode read starting address for external accelerometer attached to secondary I2C bus. | Burst-mode read starting address for external accelerometer attached to secondary I2C bus of the ITG-3050. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**. Direct judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_ADDR | AUX_ADDR |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Auxiliary accelerometer burst read starting address (BURST_ADDR)"} | {"hex":"0x18","decimal":"24","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | Burst-mode read starting address for external accelerometer (BURST_ADDR). | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.941694 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.678056}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**. Judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_ADDR | AUX_ADDR |
| `physical_address` | 0.4044 | 0.5 | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Auxiliary accelerometer burst read starting address (BURST_ADDR)"} | [{"hex":"0x18","decimal":"24","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Configures the burst-mode-read starting address for an accelerometer attached to the secondary I2C bus of the ITG-3050. | Configures the burst-mode-read starting address for an accelerometer attached to the secondary I2C bus of the ITG-3050. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.678056 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x00 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{11})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.635035/1.0001=\mathbf{0.634972}\).

## Extracted logical register 12: `INT_STATUS`

v12_0 location: `registers[11]`; truth association: `registers[14] (INT_STATUS)`.
Associated physical locations: 0x1A (26).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_STATUS` at 0x1A (26)

Locations: `truth registers[14].field_parts` ↔ `v12_0 registers[11].field_parts[0]`.

**Truth bit field 1: `Reserved` bits 7:3**

Locations: `truth registers[14].field_parts.bit_field[0]` ↔ `v12_0: missing`. Judgment: truth bit-field target has no exact v12_0 bit range.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Reserved | MISSING |
| `field_description` | 0.0586 | 0.0 | No function defined for these bits (reserved). | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 5 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 2: `ITG_RDY` bits 2:2**

Locations: `truth registers[14].field_parts.bit_field[1]` ↔ `v12_0 registers[11].field_parts[0].bit_field[1]`. Judgment: truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ITG_RDY | ITG_RDY |
| `field_description` | 0.0586 | 1.0 | PLL ready. | PLL ready. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `Reserved` bits 1:1**

Locations: `truth registers[14].field_parts.bit_field[2]` ↔ `v12_0 registers[11].field_parts[0].bit_field[2]`. Judgment: reserved-bit name/description omission is permitted.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | No function defined for this bit (reserved). | "" |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `RAW_DATA_RDY` bits 0:0**

Locations: `truth registers[14].field_parts.bit_field[3]` ↔ `v12_0 registers[11].field_parts[0].bit_field[3]`. Judgment: truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | RAW_DATA_RDY | RAW_DATA_RDY |
| `field_description` | 0.0586 | 1.0 | Raw data or FIFO data is ready. | Raw data or FIFO data is ready. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

Additional v12_0 bit field not matched to an exact truth range: `v12_0 registers[11].field_parts[0].bit_field[0]` (Reserved, bits 3:7). It is reported but not credited.
**Field-part aggregation**

bit_field correctness = mean(0.000000, 0.941694, 1.000000, 0.941694) = **0.720847**. Direct judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | INT_STATUS | INT_STATUS |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Interrupt status"} | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | Interrupt status bits. | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.720847 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.720847=\mathbf{0.608953}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.608953) = **0.608953**. Judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | INT_STATUS | INT_STATUS |
| `physical_address` | 0.4044 | 0.5 | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Interrupt status"} | [{"hex":"0x1A","decimal":"26","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Indicates the status of interrupt sources. Bits are set when corresponding interrupt sources are triggered. Interrupt status bits are cleared as determined by INT_ANYRD_2CLEAR. | Used to determine the status of the ITG-3050 interrupt. Whenever one of the interrupt sources is triggered, the corresponding bit will be set. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.608953 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x00 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{12})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.608953 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.614394/1.0001=\mathbf{0.614333}\).

## Extracted logical register 13: `TEMP_OUT`

v12_0 location: `registers[12]`; truth association: `registers[15] (TEMP_OUT_H)`, `registers[16] (TEMP_OUT_L)`.
Associated physical locations: 0x1B (27), 0x1C (28).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v12_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `TEMP_OUT_H` at 0x1B (27)

Locations: `truth registers[15].field_parts` ↔ `v12_0 registers[12].field_parts[0]`.

**Truth bit field 1: `TEMP_OUT_H` bits 7:0**

Locations: `truth registers[15].field_parts.bit_field` ↔ `v12_0 registers[12].field_parts[0].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_OUT_H | TEMP_OUT_H |
| `field_description` | 0.0586 | 0.0 | High byte of 16-bit temperature data (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TEMP_OUT_H | TEMP_OUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"High byte of temperature output (TEMP_OUT_H)"} | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit temperature data (two's complement). | High byte of temperature output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

#### Field part 2: `TEMP_OUT_L` at 0x1C (28)

Locations: `truth registers[16].field_parts` ↔ `v12_0 registers[12].field_parts[1]`.

**Truth bit field 1: `TEMP_OUT_L` bits 7:0**

Locations: `truth registers[16].field_parts.bit_field` ↔ `v12_0 registers[12].field_parts[1].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_OUT_L | TEMP_OUT_L |
| `field_description` | 0.0586 | 0.0 | Low byte of 16-bit temperature data (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TEMP_OUT_L | TEMP_OUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Low byte of temperature output (TEMP_OUT_L)"} | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit temperature data (two's complement). | Low byte of temperature output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.963418, 0.963418) = **0.963418**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | TEMP_OUT_H + TEMP_OUT_L | TEMP_OUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"High byte of temperature output (TEMP_OUT_H)"},{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Low byte of temperature output (TEMP_OUT_L)"}] | [{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"High byte"},{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Low byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit temperature data (two's complement). \| Low byte of 16-bit temperature data (two's complement). | 16-bit temperature data (2's complement data format). |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.963418 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x0000 |
| `default_value_description` | 0.0334 | 1.0 | "" | *Default Value applies if sensor is disabled. |

\(Q(L_{13})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.963418 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.922473/1.0001=\mathbf{0.922381}\).

## Extracted logical register 14: `GYRO_XOUT`

v12_0 location: `registers[13]`; truth association: `registers[17] (GYRO_XOUT_H)`, `registers[18] (GYRO_XOUT_L)`.
Associated physical locations: 0x1D (29), 0x1E (30).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v12_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_XOUT_H` at 0x1D (29)

Locations: `truth registers[17].field_parts` ↔ `v12_0 registers[13].field_parts[0]`.

**Truth bit field 1: `GYRO_XOUT_H` bits 7:0**

Locations: `truth registers[17].field_parts.bit_field` ↔ `v12_0 registers[13].field_parts[0].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_XOUT_H | GYRO_XOUT_H |
| `field_description` | 0.0586 | 0.0 | High byte of 16-bit X gyro output (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_XOUT_H | GYRO_XOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"High byte of X gyro output (GYRO_XOUT_H)"} | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit X gyro output (two's complement). | High byte of X gyro output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

#### Field part 2: `GYRO_XOUT_L` at 0x1E (30)

Locations: `truth registers[18].field_parts` ↔ `v12_0 registers[13].field_parts[1]`.

**Truth bit field 1: `GYRO_XOUT_L` bits 7:0**

Locations: `truth registers[18].field_parts.bit_field` ↔ `v12_0 registers[13].field_parts[1].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_XOUT_L | GYRO_XOUT_L |
| `field_description` | 0.0586 | 0.0 | Low byte of 16-bit X gyro output (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_XOUT_L | GYRO_XOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Low byte of X gyro output (GYRO_XOUT_L)"} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit X gyro output (two's complement). | Low byte of X gyro output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.963418, 0.963418) = **0.963418**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | GYRO_XOUT_H + GYRO_XOUT_L | GYRO_XOUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"High byte of X gyro output (GYRO_XOUT_H)"},{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Low byte of X gyro output (GYRO_XOUT_L)"}] | [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"High byte"},{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Low byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit X gyro output data (two's complement). \| Low byte of 16-bit X gyro output data (two's complement). | 16-bit X gyro output data (2's complement data format). |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.963418 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x0000 |
| `default_value_description` | 0.0334 | 1.0 | "" | *Default Value applies if sensor is disabled. |

\(Q(L_{14})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.963418 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.922473/1.0001=\mathbf{0.922381}\).

## Extracted logical register 15: `GYRO_YOUT`

v12_0 location: `registers[14]`; truth association: `registers[19] (GYRO_YOUT_H)`, `registers[20] (GYRO_YOUT_L)`.
Associated physical locations: 0x1F (31), 0x20 (32).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v12_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_YOUT_H` at 0x1F (31)

Locations: `truth registers[19].field_parts` ↔ `v12_0 registers[14].field_parts[0]`.

**Truth bit field 1: `GYRO_YOUT_H` bits 7:0**

Locations: `truth registers[19].field_parts.bit_field` ↔ `v12_0 registers[14].field_parts[0].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_YOUT_H | GYRO_YOUT_H |
| `field_description` | 0.0586 | 0.0 | High byte of 16-bit Y gyro output (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_YOUT_H | GYRO_YOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"High byte of Y gyro output (GYRO_YOUT_H)"} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Y gyro output (two's complement). | High byte of Y gyro output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

#### Field part 2: `GYRO_YOUT_L` at 0x20 (32)

Locations: `truth registers[20].field_parts` ↔ `v12_0 registers[14].field_parts[1]`.

**Truth bit field 1: `GYRO_YOUT_L` bits 7:0**

Locations: `truth registers[20].field_parts.bit_field` ↔ `v12_0 registers[14].field_parts[1].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_YOUT_L | GYRO_YOUT_L |
| `field_description` | 0.0586 | 0.0 | Low byte of 16-bit Y gyro output (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_YOUT_L | GYRO_YOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Low byte of Y gyro output (GYRO_YOUT_L)"} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Y gyro output (two's complement). | Low byte of Y gyro output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.963418, 0.963418) = **0.963418**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | GYRO_YOUT_H + GYRO_YOUT_L | GYRO_YOUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"High byte of Y gyro output (GYRO_YOUT_H)"},{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Low byte of Y gyro output (GYRO_YOUT_L)"}] | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"High byte"},{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Low byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit Y gyro output data (two's complement). \| Low byte of 16-bit Y gyro output data (two's complement). | 16-bit Y gyro output data (2's complement data format). |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.963418 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x0000 |
| `default_value_description` | 0.0334 | 1.0 | "" | *Default Value applies if sensor is disabled. |

\(Q(L_{15})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.963418 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.922473/1.0001=\mathbf{0.922381}\).

## Extracted logical register 16: `GYRO_ZOUT`

v12_0 location: `registers[15]`; truth association: `registers[21] (GYRO_ZOUT_H)`, `registers[22] (GYRO_ZOUT_L)`.
Associated physical locations: 0x21 (33), 0x22 (34).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v12_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_ZOUT_H` at 0x21 (33)

Locations: `truth registers[21].field_parts` ↔ `v12_0 registers[15].field_parts[0]`.

**Truth bit field 1: `GYRO_ZOUT_H` bits 7:0**

Locations: `truth registers[21].field_parts.bit_field` ↔ `v12_0 registers[15].field_parts[0].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_ZOUT_H | GYRO_ZOUT_H |
| `field_description` | 0.0586 | 0.0 | High byte of 16-bit Z gyro output (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_ZOUT_H | GYRO_ZOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"High byte of Z gyro output (GYRO_ZOUT_H)"} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Z gyro output (two's complement). | High byte of Z gyro output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

#### Field part 2: `GYRO_ZOUT_L` at 0x22 (34)

Locations: `truth registers[22].field_parts` ↔ `v12_0 registers[15].field_parts[1]`.

**Truth bit field 1: `GYRO_ZOUT_L` bits 7:0**

Locations: `truth registers[22].field_parts.bit_field` ↔ `v12_0 registers[15].field_parts[1].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_ZOUT_L | GYRO_ZOUT_L |
| `field_description` | 0.0586 | 0.0 | Low byte of 16-bit Z gyro output (two's complement). | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_ZOUT_L | GYRO_ZOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Low byte of Z gyro output (GYRO_ZOUT_L)"} | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Z gyro output (two's complement). | Low byte of Z gyro output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.963418, 0.963418) = **0.963418**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | GYRO_ZOUT_H + GYRO_ZOUT_L | GYRO_ZOUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"High byte of Z gyro output (GYRO_ZOUT_H)"},{"hex":"0x22","decimal":"34","bank":"","page":"","description":"Low byte of Z gyro output (GYRO_ZOUT_L)"}] | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"High byte"},{"hex":"0x22","decimal":"34","bank":"","page":"","description":"Low byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit Z gyro output data (two's complement). \| Low byte of 16-bit Z gyro output data (two's complement). | 16-bit Z gyro output data (2's complement data format). |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.963418 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x0000 |
| `default_value_description` | 0.0334 | 1.0 | "" | *Default Value applies if sensor is disabled. |

\(Q(L_{16})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.963418 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.922473/1.0001=\mathbf{0.922381}\).

## Extracted logical register 17: `AUX_XOUT`

v12_0 location: `registers[16]`; truth association: `registers[23] (AUX_XOUT_H)`, `registers[24] (AUX_XOUT_L)`.
Associated physical locations: 0x23 (35), 0x24 (36).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v12_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_XOUT_H` at 0x23 (35)

Locations: `truth registers[23].field_parts` ↔ `v12_0 registers[16].field_parts[0]`.

**Truth bit field 1: `AUX_XOUT_H` bits 7:0**

Locations: `truth registers[23].field_parts.bit_field` ↔ `v12_0 registers[16].field_parts[0].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_XOUT_H | AUX_XOUT_H |
| `field_description` | 0.0586 | 0.0 | High byte of 16-bit X auxiliary (accel) output. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_XOUT_H | AUX_XOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte of X auxiliary (accel) output (AUX_XOUT_H)"} | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit X auxiliary (accel) output. | High byte of X aux output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

#### Field part 2: `AUX_XOUT_L` at 0x24 (36)

Locations: `truth registers[24].field_parts` ↔ `v12_0 registers[16].field_parts[1]`.

**Truth bit field 1: `AUX_XOUT_L` bits 7:0**

Locations: `truth registers[24].field_parts.bit_field` ↔ `v12_0 registers[16].field_parts[1].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_XOUT_L | AUX_XOUT_L |
| `field_description` | 0.0586 | 0.0 | Low byte of 16-bit X auxiliary (accel) output. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_XOUT_L | AUX_XOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low byte of X auxiliary (accel) output (AUX_XOUT_L)"} | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit X auxiliary (accel) output. | Low byte of X aux output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.963418, 0.963418) = **0.963418**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_XOUT_H + AUX_XOUT_L | AUX_XOUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte of X auxiliary (accel) output (AUX_XOUT_H)"},{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low byte of X auxiliary (accel) output (AUX_XOUT_L)"}] | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte"},{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit auxiliary X-axis output (as available from auxiliary device). \| Low byte of 16-bit auxiliary X-axis output (as available from auxiliary device). | 16-bit X aux (accel) output data (as available from aux). |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.963418 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x0000 |
| `default_value_description` | 0.0334 | 1.0 | "" | *Default Value applies if sensor is disabled. |

\(Q(L_{17})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.963418 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.922473/1.0001=\mathbf{0.922381}\).

## Extracted logical register 18: `AUX_YOUT`

v12_0 location: `registers[17]`; truth association: `registers[25] (AUX_YOUT_H)`, `registers[26] (AUX_YOUT_L)`.
Associated physical locations: 0x25 (37), 0x26 (38).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v12_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_YOUT_H` at 0x25 (37)

Locations: `truth registers[25].field_parts` ↔ `v12_0 registers[17].field_parts[0]`.

**Truth bit field 1: `AUX_YOUT_H` bits 7:0**

Locations: `truth registers[25].field_parts.bit_field` ↔ `v12_0 registers[17].field_parts[0].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_YOUT_H | AUX_YOUT_H |
| `field_description` | 0.0586 | 0.0 | High byte of 16-bit Y auxiliary (accel) output. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_YOUT_H | AUX_YOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"High byte of Y auxiliary (accel) output (AUX_YOUT_H)"} | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Y auxiliary (accel) output. | High byte of Y aux output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

#### Field part 2: `AUX_YOUT_L` at 0x26 (38)

Locations: `truth registers[26].field_parts` ↔ `v12_0 registers[17].field_parts[1]`.

**Truth bit field 1: `AUX_YOUT_L` bits 7:0**

Locations: `truth registers[26].field_parts.bit_field` ↔ `v12_0 registers[17].field_parts[1].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_YOUT_L | AUX_YOUT_L |
| `field_description` | 0.0586 | 0.0 | Low byte of 16-bit Y auxiliary (accel) output. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_YOUT_L | AUX_YOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Low byte of Y auxiliary (accel) output (AUX_YOUT_L)"} | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Y auxiliary (accel) output. | Low byte of Y aux output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.963418, 0.963418) = **0.963418**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_YOUT_H + AUX_YOUT_L | AUX_YOUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":"High byte of Y auxiliary (accel) output (AUX_YOUT_H)"},{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Low byte of Y auxiliary (accel) output (AUX_YOUT_L)"}] | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":"High byte"},{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Low byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit auxiliary Y-axis output (as available from auxiliary device). \| Low byte of 16-bit auxiliary Y-axis output (as available from auxiliary device). | 16-bit Y aux (accel) output data (as available from aux). |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.963418 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x0000 |
| `default_value_description` | 0.0334 | 1.0 | "" | *Default Value applies if sensor is disabled. |

\(Q(L_{18})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.963418 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.922473/1.0001=\mathbf{0.922381}\).

## Extracted logical register 19: `AUX_ZOUT`

v12_0 location: `registers[18]`; truth association: `registers[27] (AUX_ZOUT_H)`, `registers[28] (AUX_ZOUT_L)`.
Associated physical locations: 0x27 (39), 0x28 (40).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v12_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_ZOUT_H` at 0x27 (39)

Locations: `truth registers[27].field_parts` ↔ `v12_0 registers[18].field_parts[0]`.

**Truth bit field 1: `AUX_ZOUT_H` bits 7:0**

Locations: `truth registers[27].field_parts.bit_field` ↔ `v12_0 registers[18].field_parts[0].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_ZOUT_H | AUX_ZOUT_H |
| `field_description` | 0.0586 | 0.0 | High byte of 16-bit Z auxiliary (accel) output. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_ZOUT_H | AUX_ZOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"High byte of Z auxiliary (accel) output (AUX_ZOUT_H)"} | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Z auxiliary (accel) output. | High byte of Z aux output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

#### Field part 2: `AUX_ZOUT_L` at 0x28 (40)

Locations: `truth registers[28].field_parts` ↔ `v12_0 registers[18].field_parts[1]`.

**Truth bit field 1: `AUX_ZOUT_L` bits 7:0**

Locations: `truth registers[28].field_parts.bit_field` ↔ `v12_0 registers[18].field_parts[1].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_ZOUT_L | AUX_ZOUT_L |
| `field_description` | 0.0586 | 0.0 | Low byte of 16-bit Z auxiliary (accel) output. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_ZOUT_L | AUX_ZOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of Z auxiliary (accel) output (AUX_ZOUT_L)"} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Z auxiliary (accel) output. | Low byte of Z aux output |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.963418, 0.963418) = **0.963418**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_ZOUT_H + AUX_ZOUT_L | AUX_ZOUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"High byte of Z auxiliary (accel) output (AUX_ZOUT_H)"},{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of Z auxiliary (accel) output (AUX_ZOUT_L)"}] | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"High byte"},{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit auxiliary Z-axis output (as available from auxiliary device). \| Low byte of 16-bit auxiliary Z-axis output (as available from auxiliary device). | 16-bit Z aux (accel) output data (as available from aux). |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.963418 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x0000 |
| `default_value_description` | 0.0334 | 1.0 | "" | *Default Value applies if sensor is disabled. |

\(Q(L_{19})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.963418 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.922473/1.0001=\mathbf{0.922381}\).

## Extracted logical register 20: `FIFO_COUNT`

v12_0 location: `registers[19]`; truth association: `registers[29] (FIFO_COUNTH)`, `registers[30] (FIFO_COUNTL)`.
Associated physical locations: 0x3A (58), 0x3B (59).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v12_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_COUNTH` at 0x3A (58)

Locations: `truth registers[29].field_parts` ↔ `v12_0 registers[19].field_parts[0]`.

**Truth bit field 1: `Reserved` bits 7:2**

Locations: `truth registers[29].field_parts.bit_field[0]` ↔ `v12_0: missing`. Judgment: truth bit-field target has no exact v12_0 bit range.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Reserved | MISSING |
| `field_description` | 0.0586 | 0.0 | No function defined for these bits (reserved). | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 6 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 2: `FIFO_COUNT_H` bits 1:0**

Locations: `truth registers[29].field_parts.bit_field[1]` ↔ `v12_0: missing`. Judgment: truth bit-field target has no exact v12_0 bit range.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | FIFO_COUNT_H | MISSING |
| `field_description` | 0.0586 | 0.0 | High bits of the number of bytes currently in FIFO. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 2 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | False | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

Additional v12_0 bit field not matched to an exact truth range: `v12_0 registers[19].field_parts[0].bit_field[0]` (Reserved, bits 7:6). It is reported but not credited.
Additional v12_0 bit field not matched to an exact truth range: `v12_0 registers[19].field_parts[0].bit_field[1]` (FIFO_COUNT_H, bits 5:0). It is reported but not credited.
**Field-part aggregation**

bit_field correctness = mean(0.000000, 0.000000) = **0.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | FIFO_COUNTH | FIFO_COUNTH |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":"FIFO byte count high part (FIFO_COUNT_H)"} | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":"High byte"} |
| `description` | 0.0693 | 1.0 | High portion of FIFO byte count. | High byte of FIFO count |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.000000 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000=\mathbf{0.687100}\).

#### Field part 2: `FIFO_COUNTL` at 0x3B (59)

Locations: `truth registers[30].field_parts` ↔ `v12_0 registers[19].field_parts[1]`.

**Truth bit field 1: `FIFO_COUNT_L` bits 7:0**

Locations: `truth registers[30].field_parts.bit_field` ↔ `v12_0 registers[19].field_parts[1].bit_field[0]`. Judgment: field_description is missing; truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_COUNT_L | FIFO_COUNT_L |
| `field_description` | 0.0586 | 0.0 | Low byte of the number of bytes currently in FIFO. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.883000/0.9999=\mathbf{0.883088}\).

**Field-part aggregation**

bit_field correctness = mean(0.883088) = **0.883088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | FIFO_COUNTL | FIFO_COUNTL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":"FIFO byte count low part (FIFO_COUNT_L)"} | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":"Low byte"} |
| `description` | 0.0693 | 1.0 | Low portion of FIFO byte count. | Low byte of FIFO count |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.883088 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.883088=\mathbf{0.963418}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.687100, 0.963418) = **0.825259**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | FIFO_COUNTH + FIFO_COUNTL | FIFO_COUNT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x3A","decimal":"58","bank":"","page":"","description":"FIFO byte count high part (FIFO_COUNT_H)"},{"hex":"0x3B","decimal":"59","bank":"","page":"","description":"FIFO byte count low part (FIFO_COUNT_L)"}] | [{"hex":"0x3A","decimal":"58","bank":"","page":"","description":"High byte"},{"hex":"0x3B","decimal":"59","bank":"","page":"","description":"Low byte"}] |
| `register_description` | 0.0564 | 1.0 | Indicates how many bytes of valid data are contained in the FIFO (high part). \| Indicates how many bytes of valid data are contained in the FIFO (low part). | Indicates how many bytes of valid data are contained in the FIFO. The FIFO can contain up to 512 bytes of data. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.825259 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x0000 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{20})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.825259 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.881205/1.0001=\mathbf{0.881117}\).

## Extracted logical register 21: `FIFO_R`

v12_0 location: `registers[20]`; truth association: `registers[31] (FIFO_R)`.
Associated physical locations: 0x3C (60).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_R` at 0x3C (60)

Locations: `truth registers[31].field_parts` ↔ `v12_0 registers[20].field_parts[0]`.

**Truth bit field 1: `FIFO_DATA` bits 7:0**

Locations: `truth registers[31].field_parts.bit_field` ↔ `v12_0 registers[20].field_parts[0].bit_field[0]`. Judgment: truth type_write_read='R', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_DATA | FIFO_DATA |
| `field_description` | 0.0586 | 1.0 | FIFO data byte. | Contains the FIFO data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**. Direct judgment: register_name is objectively different; numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 0.0 | FIFO_DATA | FIFO_R |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"FIFO data output (FIFO_DATA)"} | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | FIFO output data byte; reading this register fetches the next byte from FIFO. | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.941694 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×0.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.650056}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.650056) = **0.650056**. Judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | FIFO_R | FIFO_R |
| `physical_address` | 0.4044 | 0.5 | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"FIFO data output (FIFO_DATA)"} | [{"hex":"0x3C","decimal":"60","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Output register of the FIFO. Each read returns the oldest contents of the FIFO buffer; a burst read is required to read multiple bytes. | Output register of the FIFO. Each read of this register gets the oldest contents of the ITG-3050 FIFO buffer. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.650056 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x00 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{21})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.650056 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.626672/1.0001=\mathbf{0.626609}\).

## Extracted logical register 22: `USER_CTRL`

v12_0 location: `registers[21]`; truth association: `registers[32] (USER_CTRL)`.
Associated physical locations: 0x3D (61).

### Bottom layer: bit fields, then field parts

#### Field part 1: `USER_CTRL` at 0x3D (61)

Locations: `truth registers[32].field_parts` ↔ `v12_0 registers[21].field_parts[0]`.

**Truth bit field 1: `Reserved` bits 7:7**

Locations: `truth registers[32].field_parts.bit_field[0]` ↔ `v12_0 registers[21].field_parts[0].bit_field[0]`. Judgment: reserved-bit name/description omission is permitted.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | No function defined for this bit (reserved). | "" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `FIFO_EN` bits 6:6**

Locations: `truth registers[32].field_parts.bit_field[1]` ↔ `v12_0 registers[21].field_parts[0].bit_field[1]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_EN | FIFO_EN |
| `field_description` | 0.0586 | 1.0 | Enable FIFO operation for sensor data. | Enable FIFO operation for sensor data. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `AUX_IF_EN` bits 5:5**

Locations: `truth registers[32].field_parts.bit_field[2]` ↔ `v12_0 registers[21].field_parts[0].bit_field[2]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_IF_EN | AUX_IF_EN |
| `field_description` | 0.0586 | 1.0 | Enable 3rd-party accelerometer interface via I²C. Clear this bit to enable bypass mode (host direct access to accel). | Enable 3rd-party accelerometer interface via I²C. Clear this bit to enable Bypass Mode - allows host processor direct access to the 3rd-party accelerometer. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `Reserved` bits 4:4**

Locations: `truth registers[32].field_parts.bit_field[3]` ↔ `v12_0 registers[21].field_parts[0].bit_field[3]`. Judgment: reserved-bit name/description omission is permitted.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | No function defined for this bit (reserved). | "" |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 5: `AUX_IF_RST` bits 3:3**

Locations: `truth registers[32].field_parts.bit_field[4]` ↔ `v12_0 registers[21].field_parts[0].bit_field[4]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_IF_RST | AUX_IF_RST |
| `field_description` | 0.0586 | 1.0 | Reset third-party accelerometer interface function; set this only after changing AUX_IF_EN to 0. | Reset third-party accelerometer interface function; set this only after changing AUX_IF_EN to 0. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 6: `Reserved` bits 2:2**

Locations: `truth registers[32].field_parts.bit_field[5]` ↔ `v12_0 registers[21].field_parts[0].bit_field[5]`. Judgment: reserved-bit name/description omission is permitted.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | No function defined for this bit (reserved). | "" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 7: `FIFO_RST` bits 1:1**

Locations: `truth registers[32].field_parts.bit_field[6]` ↔ `v12_0 registers[21].field_parts[0].bit_field[6]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_RST | FIFO_RST |
| `field_description` | 0.0586 | 1.0 | Reset FIFO function; set this to clear FIFO or when changing FIFO_EN. | Reset FIFO function; set this to clear FIFO or when changing FIFO_EN. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 8: `GYRO_RST` bits 0:0**

Locations: `truth registers[32].field_parts.bit_field[7]` ↔ `v12_0 registers[21].field_parts[0].bit_field[7]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_RST | GYRO_RST |
| `field_description` | 0.0586 | 1.0 | Reset gyro analog and digital functions. | Reset gyro analog and digital functions. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000, 0.941694, 0.941694, 1.000000, 0.941694, 1.000000, 0.941694, 0.941694) = **0.963559**. Direct judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | USER_CTRL | USER_CTRL |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"User control (enable/reset auxiliary functions and FIFO)"} | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | Control and reset bits for FIFO and auxiliary interface functions. | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.963559 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.963559=\mathbf{0.684898}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.684898) = **0.684898**. Judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | USER_CTRL | USER_CTRL |
| `physical_address` | 0.4044 | 0.5 | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"User control (enable/reset auxiliary functions and FIFO)"} | [{"hex":"0x3D","decimal":"61","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Used to enable/disable and reset various modes and functions (FIFO, AUX I2C master interface, gyro reset). Reset bits are auto-cleared after reset. | Used to enable various modes on the ITG-3050, as well as reset these functions. When AUX_IF_EN is set to 1, I²C Master Mode is enabled. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.684898 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x00 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{22})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.684898 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.637079/1.0001=\mathbf{0.637015}\).

## Extracted logical register 23: `PWR_MGM`

v12_0 location: `registers[22]`; truth association: `registers[33] (PWR_MGM)`.
Associated physical locations: 0x3E (62).

### Bottom layer: bit fields, then field parts

#### Field part 1: `PWR_MGM` at 0x3E (62)

Locations: `truth registers[33].field_parts` ↔ `v12_0 registers[22].field_parts[0]`.

**Truth bit field 1: `H_RESET` bits 7:7**

Locations: `truth registers[33].field_parts.bit_field[0]` ↔ `v12_0 registers[22].field_parts[0].bit_field[0]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | H_RESET | H_RESET |
| `field_description` | 0.0586 | 1.0 | Reset device and internal registers to the power-up-default settings. | Reset device and internal registers to the power-up-default settings. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `SLEEP` bits 6:6**

Locations: `truth registers[33].field_parts.bit_field[1]` ↔ `v12_0 registers[22].field_parts[0].bit_field[1]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SLEEP | SLEEP |
| `field_description` | 0.0586 | 1.0 | Enable low power sleep mode. | Enable low power sleep mode. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 3: `STBY_XG` bits 5:5**

Locations: `truth registers[33].field_parts.bit_field[2]` ↔ `v12_0 registers[22].field_parts[0].bit_field[2]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_XG | STBY_XG |
| `field_description` | 0.0586 | 1.0 | Put gyro X in standby mode (1=standby, 0=normal). | Put gyro X in standby mode (1=standby, 0=normal). |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 4: `STBY_YG` bits 4:4**

Locations: `truth registers[33].field_parts.bit_field[3]` ↔ `v12_0 registers[22].field_parts[0].bit_field[3]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_YG | STBY_YG |
| `field_description` | 0.0586 | 1.0 | Put gyro Y in standby mode (1=standby, 0=normal). | Put gyro Y in standby mode (1=standby, 0=normal). |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 5: `STBY_ZG` bits 3:3**

Locations: `truth registers[33].field_parts.bit_field[4]` ↔ `v12_0 registers[22].field_parts[0].bit_field[4]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_ZG | STBY_ZG |
| `field_description` | 0.0586 | 1.0 | Put gyro Z in standby mode (1=standby, 0=normal). | Put gyro Z in standby mode (1=standby, 0=normal). |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 6: `CLK_SEL` bits 2:0**

Locations: `truth registers[33].field_parts.bit_field[5]` ↔ `v12_0 registers[22].field_parts[0].bit_field[5]`. Judgment: truth type_write_read='RW', v12_0 has ''.

| Scored field | Weight | C | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | CLK_SEL | CLK_SEL |
| `field_description` | 0.0586 | 1.0 | Select device clock source. | Select device clock source. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Internal oscillator"},{"value":"1","value_description":"PLL with X Gyro reference"},{"value":"2","value_description":"PLL with Y Gyro reference"},{"value":"3","value_description":"PLL with Z Gyro reference"},{"value":"4","value_description":"PLL with external 32.768kHz reference"},{"value":"5","value_description":"PLL with external 19.2MHz reference"},{"value":"6","value_description":"Reserved"},{"value":"7","value_description":"Stop clock and synchronous reset clock state"}] | [{"value":"0","value_description":"Internal oscillator"},{"value":"1","value_description":"PLL with X Gyro reference"},{"value":"2","value_description":"PLL with Y Gyro reference"},{"value":"3","value_description":"PLL with Z Gyro reference"},{"value":"4","value_description":"PLL with external 32.768kHz reference"},{"value":"5","value_description":"PLL with external 19.2MHz reference"},{"value":"6","value_description":"Reserved"},{"value":"7","value_description":"Stop clock and synchronous reset clock state"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**. Direct judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing.

| Field-part field | Weight | Correctness | Truth content | v12_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | PWR_MGM | PWR_MGM |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Power management and clock select"} | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | Power control bits, standby selections, and clock source selection. | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | truth bit-field targets | matched exact v12_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694=\mathbf{0.678056}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**. Judgment: numeric address/bank/page matches; address description is incomplete but receives partial credit; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v12_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | PWR_MGM | PWR_MGM |
| `physical_address` | 0.4044 | 0.5 | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Power management and clock select"} | [{"hex":"0x3E","decimal":"62","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | Manages power control, clock source selection, standby modes, and device reset. | Used to manage the power control, select the clock source, and to issue a master reset to the device. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0x00 |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{23})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.635035/1.0001=\mathbf{0.634972}\).

## 2. Ground-truth physical-register scores

For every truth physical register, \(q_R=\frac{1}{|L_R|}\sum_{L\in L_R}Q(L)\). A merged v12_0 logical register contributes its one Q(L) to each physical address it covers.

| Truth physical address | Associated extracted logical registers and Q(L) | q_R |
|---|---|---:|
| 0x00 (0) | v12_0 registers[0] `WHO_AM_I`=0.623722 | 0.623722 |
| 0x0C (12) | v12_0 registers[1] `X_OFFS_USR`=0.987093 | 0.987093 |
| 0x0D (13) | v12_0 registers[1] `X_OFFS_USR`=0.987093 | 0.987093 |
| 0x0E (14) | v12_0 registers[2] `Y_OFFS_USR`=0.989074 | 0.989074 |
| 0x0F (15) | v12_0 registers[2] `Y_OFFS_USR`=0.989074 | 0.989074 |
| 0x10 (16) | v12_0 registers[3] `Z_OFFS_USR`=0.989074 | 0.989074 |
| 0x11 (17) | v12_0 registers[3] `Z_OFFS_USR`=0.989074 | 0.989074 |
| 0x12 (18) | v12_0 registers[4] `FIFO_EN`=0.634972 | 0.634972 |
| 0x13 (19) | v12_0 registers[5] `AUX_VDDIO`=0.576302 | 0.576302 |
| 0x14 (20) | v12_0 registers[6] `AUX_SLV_ADDR`=0.634972 | 0.634972 |
| 0x15 (21) | v12_0 registers[7] `SMPLRT_DIV`=0.634972 | 0.634972 |
| 0x16 (22) | v12_0 registers[8] `DLPF_FS_SYNC`=0.634972 | 0.634972 |
| 0x17 (23) | v12_0 registers[9] `INT_CFG`=0.636334 | 0.636334 |
| 0x18 (24) | v12_0 registers[10] `AUX_ADDR`=0.634972 | 0.634972 |
| 0x1A (26) | v12_0 registers[11] `INT_STATUS`=0.614333 | 0.614333 |
| 0x1B (27) | v12_0 registers[12] `TEMP_OUT`=0.922381 | 0.922381 |
| 0x1C (28) | v12_0 registers[12] `TEMP_OUT`=0.922381 | 0.922381 |
| 0x1D (29) | v12_0 registers[13] `GYRO_XOUT`=0.922381 | 0.922381 |
| 0x1E (30) | v12_0 registers[13] `GYRO_XOUT`=0.922381 | 0.922381 |
| 0x1F (31) | v12_0 registers[14] `GYRO_YOUT`=0.922381 | 0.922381 |
| 0x20 (32) | v12_0 registers[14] `GYRO_YOUT`=0.922381 | 0.922381 |
| 0x21 (33) | v12_0 registers[15] `GYRO_ZOUT`=0.922381 | 0.922381 |
| 0x22 (34) | v12_0 registers[15] `GYRO_ZOUT`=0.922381 | 0.922381 |
| 0x23 (35) | v12_0 registers[16] `AUX_XOUT`=0.922381 | 0.922381 |
| 0x24 (36) | v12_0 registers[16] `AUX_XOUT`=0.922381 | 0.922381 |
| 0x25 (37) | v12_0 registers[17] `AUX_YOUT`=0.922381 | 0.922381 |
| 0x26 (38) | v12_0 registers[17] `AUX_YOUT`=0.922381 | 0.922381 |
| 0x27 (39) | v12_0 registers[18] `AUX_ZOUT`=0.922381 | 0.922381 |
| 0x28 (40) | v12_0 registers[18] `AUX_ZOUT`=0.922381 | 0.922381 |
| 0x3A (58) | v12_0 registers[19] `FIFO_COUNT`=0.881117 | 0.881117 |
| 0x3B (59) | v12_0 registers[19] `FIFO_COUNT`=0.881117 | 0.881117 |
| 0x3C (60) | v12_0 registers[20] `FIFO_R`=0.626609 | 0.626609 |
| 0x3D (61) | v12_0 registers[21] `USER_CTRL`=0.637015 | 0.637015 |
| 0x3E (62) | v12_0 registers[22] `PWR_MGM`=0.634972 | 0.634972 |

\(\sum_{R=1}^{34}q_R=\mathbf{28.130193379}\).

\(m=34,\ x=0,\ \frac{m}{m+x}=\frac{34}{34+0}=1.000000\).

Missing truth physical addresses: none.
Extra extracted physical addresses: none.

\[S_{final}=\left(\frac{10}{34}\times 28.130193379\right)\times\frac{34}{34+0}=\boxed{\mathbf{8.273586288/10}}\]

## 3. Detailed deduction inventory

The following entries are the exact scored deviations. The preceding sections contain the complete bottom-up table for every logical register, field part, and truth bit-field target.

### 3.1 Objective-fact errors and omissions

| Exact location | Field | Truth content | v12_0 content | C | Judgment |
|---|---|---|---|---:|---|
| `v12_0 registers[0].field_parts[0].bit_field[0]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[0].field_parts[0].bit_field[1]` | `values` | {"value":"110 100","value_description":"Power-On-Reset value of Bit6:Bit1"} | [] | 0.0 | truth value enumeration is missing from v12_0 |
| `v12_0 registers[0].field_parts[0].bit_field[1]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[0].field_parts[0].bit_field[2]` | `values` | [{"value":0,"value_description":""},{"value":1,"value_description":""}] | [] | 0.0 | truth value enumeration is missing from v12_0 |
| `v12_0 registers[0].field_parts[0]` | `physical_address` | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Contains device ID and I²C interface disable bit"} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":""} | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[0].field_parts[0]` | `description` | Device ID and I²C interface control | "" | 0.0 | numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing |
| `v12_0 registers[0]` | `physical_address` | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Contains device ID and I²C interface disable bit"} | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":""}] | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[0]` | `default_value` | ["68h","69h"] | 0x68 or 0x69 | 0.0 | default value does not match the truth |
| `v12_0 registers[1].field_parts[0].bit_field[0]` | `name_or_parameter` | X_OFFS_H | X_OFF_H | 0.0 | name_or_parameter is objectively different; field_description is missing; truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[1].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit X gyro offset (two's complement). | "" | 0.0 | name_or_parameter is objectively different; field_description is missing; truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[1].field_parts[0].bit_field[0]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[1].field_parts[1].bit_field[0]` | `name_or_parameter` | X_OFFS_L | X_OFF_L | 0.0 | name_or_parameter is objectively different; field_description is missing; truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[1].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit X gyro offset (two's complement). | "" | 0.0 | name_or_parameter is objectively different; field_description is missing; truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[1].field_parts[1].bit_field[0]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[2].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Y gyro offset (two's complement). | "" | 0.0 | field_description is missing; truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[2].field_parts[0].bit_field[0]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[2].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit Y gyro offset (two's complement). | "" | 0.0 | field_description is missing; truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[2].field_parts[1].bit_field[0]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[3].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Z gyro offset (two's complement). | "" | 0.0 | field_description is missing; truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[3].field_parts[0].bit_field[0]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[3].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit Z gyro offset (two's complement). | "" | 0.0 | field_description is missing; truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[3].field_parts[1].bit_field[0]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[4].field_parts[0].bit_field[0]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[4].field_parts[0].bit_field[1]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[4].field_parts[0].bit_field[2]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[4].field_parts[0].bit_field[3]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[4].field_parts[0].bit_field[4]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[4].field_parts[0].bit_field[5]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[4].field_parts[0].bit_field[6]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[4].field_parts[0].bit_field[7]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[4].field_parts[0]` | `physical_address` | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"FIFO enable bits (select which sensor data are written into FIFO)"} | {"hex":"0x12","decimal":"18","bank":"","page":"","description":""} | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[4].field_parts[0]` | `description` | Enable selection for data inserted into FIFO; each bit inserts the listed data into the FIFO when set. | "" | 0.0 | numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing |
| `v12_0 registers[4]` | `physical_address` | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"FIFO enable bits (select which sensor data are written into FIFO)"} | [{"hex":"0x12","decimal":"18","bank":"","page":"","description":""}] | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[4]` | `default_value` | 00h | 0x00 | 0.0 | default value does not match the truth |
| `truth registers[8].field_parts.bit_field[0]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[0]` | `field_description` | Load zeros into bits 7..3 (must be 0). | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[0]` | `bit_start` | 3 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[0]` | `bit_end` | 7 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[0]` | `bit_width` | 5 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[0]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[0]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[0]` | `type_write_read` | "" | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `v12_0 registers[5].field_parts[0].bit_field[2]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `truth registers[8].field_parts.bit_field[2]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[2]` | `field_description` | Load zeros into bits 1..0 (must be 0). | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[2]` | `bit_start` | 0 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[2]` | `bit_end` | 1 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[2]` | `bit_width` | 2 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[2]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[2]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[8].field_parts.bit_field[2]` | `type_write_read` | "" | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `v12_0 registers[5].field_parts[0]` | `physical_address` | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Auxiliary I/O voltage selection bit"} | {"hex":"0x13","decimal":"19","bank":"","page":"","description":""} | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[5].field_parts[0]` | `description` | I/O logic level selection for the secondary I²C bus lines; other bits must be written as zeros. | "" | 0.0 | numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing |
| `v12_0 registers[5]` | `physical_address` | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Auxiliary I/O voltage selection bit"} | [{"hex":"0x13","decimal":"19","bank":"","page":"","description":""}] | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[5]` | `default_value` | 00h | 0x00 | 0.0 | default value does not match the truth |
| `v12_0 registers[6].field_parts[0].bit_field[0]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[6].field_parts[0].bit_field[1]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[6].field_parts[0]` | `physical_address` | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Auxiliary device 7-bit slave address and CLKOUT enable"} | {"hex":"0x14","decimal":"20","bank":"","page":"","description":""} | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[6].field_parts[0]` | `description` | CLKOUT enable and auxiliary device address (AUX_ID). | "" | 0.0 | numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing |
| `v12_0 registers[6]` | `physical_address` | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Auxiliary device 7-bit slave address and CLKOUT enable"} | [{"hex":"0x14","decimal":"20","bank":"","page":"","description":""}] | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[6]` | `default_value` | 00h | 0x00 | 0.0 | default value does not match the truth |
| `v12_0 registers[7].field_parts[0].bit_field[0]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[7].field_parts[0]` | `physical_address` | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Sample rate divider"} | {"hex":"0x15","decimal":"21","bank":"","page":"","description":""} | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[7].field_parts[0]` | `description` | Sample rate divider (0-255). | "" | 0.0 | numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing |
| `v12_0 registers[7]` | `physical_address` | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Sample rate divider"} | [{"hex":"0x15","decimal":"21","bank":"","page":"","description":""}] | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[7]` | `default_value` | 00h | 0x00 | 0.0 | default value does not match the truth |
| `v12_0 registers[8].field_parts[0].bit_field[0]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[8].field_parts[0].bit_field[1]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[8].field_parts[0].bit_field[2]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[8].field_parts[0]` | `physical_address` | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"DLPF_CFG, FS_SEL, and EXT_SYNC_SET configuration"} | {"hex":"0x16","decimal":"22","bank":"","page":"","description":""} | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[8].field_parts[0]` | `description` | EXT_SYNC_SET (bits7:5), FS_SEL (bits4:3), DLPF_CFG (bits2:0). | "" | 0.0 | numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing |
| `v12_0 registers[8]` | `physical_address` | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"DLPF_CFG, FS_SEL, and EXT_SYNC_SET configuration"} | [{"hex":"0x16","decimal":"22","bank":"","page":"","description":""}] | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[8]` | `default_value` | 00h | 0x00 | 0.0 | default value does not match the truth |
| `v12_0 registers[9].field_parts[0].bit_field[0]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[9].field_parts[0].bit_field[1]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[9].field_parts[0].bit_field[2]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[9].field_parts[0].bit_field[3]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[9].field_parts[0].bit_field[5]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[9].field_parts[0].bit_field[7]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[9].field_parts[0]` | `physical_address` | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Interrupt configuration"} | {"hex":"0x17","decimal":"23","bank":"","page":"","description":""} | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[9].field_parts[0]` | `description` | Interrupt pin configuration, latch mode, and interrupt enables. | "" | 0.0 | numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing |
| `v12_0 registers[9]` | `physical_address` | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Interrupt configuration"} | [{"hex":"0x17","decimal":"23","bank":"","page":"","description":""}] | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[9]` | `default_value` | 00h | 0x00 | 0.0 | default value does not match the truth |
| `v12_0 registers[10].field_parts[0].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[10].field_parts[0]` | `physical_address` | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Auxiliary accelerometer burst read starting address (BURST_ADDR)"} | {"hex":"0x18","decimal":"24","bank":"","page":"","description":""} | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[10].field_parts[0]` | `description` | Burst-mode read starting address for external accelerometer (BURST_ADDR). | "" | 0.0 | numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing |
| `v12_0 registers[10]` | `physical_address` | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Auxiliary accelerometer burst read starting address (BURST_ADDR)"} | [{"hex":"0x18","decimal":"24","bank":"","page":"","description":""}] | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[10]` | `default_value` | 00h | 0x00 | 0.0 | default value does not match the truth |
| `truth registers[14].field_parts.bit_field[0]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[14].field_parts.bit_field[0]` | `field_description` | No function defined for these bits (reserved). | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[14].field_parts.bit_field[0]` | `bit_start` | 3 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[14].field_parts.bit_field[0]` | `bit_end` | 7 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[14].field_parts.bit_field[0]` | `bit_width` | 5 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[14].field_parts.bit_field[0]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[14].field_parts.bit_field[0]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[14].field_parts.bit_field[0]` | `type_write_read` | R | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `v12_0 registers[11].field_parts[0].bit_field[1]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[11].field_parts[0].bit_field[3]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[11].field_parts[0]` | `physical_address` | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Interrupt status"} | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":""} | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[11].field_parts[0]` | `description` | Interrupt status bits. | "" | 0.0 | numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing |
| `v12_0 registers[11]` | `physical_address` | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Interrupt status"} | [{"hex":"0x1A","decimal":"26","bank":"","page":"","description":""}] | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[11]` | `default_value` | 00h | 0x00 | 0.0 | default value does not match the truth |
| `v12_0 registers[12].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit temperature data (two's complement). | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[12].field_parts[0].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[12].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit temperature data (two's complement). | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[12].field_parts[1].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[12]` | `default_value` | 00h | 0x0000 | 0.0 | default value does not match the truth |
| `v12_0 registers[13].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit X gyro output (two's complement). | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[13].field_parts[0].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[13].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit X gyro output (two's complement). | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[13].field_parts[1].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[13]` | `default_value` | 00h | 0x0000 | 0.0 | default value does not match the truth |
| `v12_0 registers[14].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Y gyro output (two's complement). | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[14].field_parts[0].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[14].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit Y gyro output (two's complement). | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[14].field_parts[1].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[14]` | `default_value` | 00h | 0x0000 | 0.0 | default value does not match the truth |
| `v12_0 registers[15].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Z gyro output (two's complement). | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[15].field_parts[0].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[15].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit Z gyro output (two's complement). | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[15].field_parts[1].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[15]` | `default_value` | 00h | 0x0000 | 0.0 | default value does not match the truth |
| `v12_0 registers[16].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit X auxiliary (accel) output. | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[16].field_parts[0].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[16].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit X auxiliary (accel) output. | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[16].field_parts[1].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[16]` | `default_value` | 00h | 0x0000 | 0.0 | default value does not match the truth |
| `v12_0 registers[17].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Y auxiliary (accel) output. | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[17].field_parts[0].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[17].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit Y auxiliary (accel) output. | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[17].field_parts[1].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[17]` | `default_value` | 00h | 0x0000 | 0.0 | default value does not match the truth |
| `v12_0 registers[18].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Z auxiliary (accel) output. | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[18].field_parts[0].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[18].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit Z auxiliary (accel) output. | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[18].field_parts[1].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[18]` | `default_value` | 00h | 0x0000 | 0.0 | default value does not match the truth |
| `truth registers[29].field_parts.bit_field[0]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[0]` | `field_description` | No function defined for these bits (reserved). | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[0]` | `bit_start` | 2 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[0]` | `bit_end` | 7 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[0]` | `bit_width` | 6 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[0]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[0]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[0]` | `type_write_read` | "" | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[1]` | `name_or_parameter` | FIFO_COUNT_H | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[1]` | `field_description` | High bits of the number of bytes currently in FIFO. | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[1]` | `bit_start` | 0 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[1]` | `bit_end` | 1 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[1]` | `bit_width` | 2 | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[1]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[1]` | `is_reserved` | False | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `truth registers[29].field_parts.bit_field[1]` | `type_write_read` | R | ∅ | 0.0 | truth bit-field target has no exact v12_0 bit range |
| `v12_0 registers[19].field_parts[1].bit_field[0]` | `field_description` | Low byte of the number of bytes currently in FIFO. | "" | 0.0 | field_description is missing; truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[19].field_parts[1].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[19]` | `default_value` | 00h | 0x0000 | 0.0 | default value does not match the truth |
| `v12_0 registers[20].field_parts[0].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v12_0 has '' |
| `v12_0 registers[20].field_parts[0]` | `register_name` | FIFO_DATA | FIFO_R | 0.0 | register_name is objectively different; numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing |
| `v12_0 registers[20].field_parts[0]` | `physical_address` | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"FIFO data output (FIFO_DATA)"} | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":""} | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[20].field_parts[0]` | `description` | FIFO output data byte; reading this register fetches the next byte from FIFO. | "" | 0.0 | register_name is objectively different; numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing |
| `v12_0 registers[20]` | `physical_address` | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"FIFO data output (FIFO_DATA)"} | [{"hex":"0x3C","decimal":"60","bank":"","page":"","description":""}] | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[20]` | `default_value` | 00h | 0x00 | 0.0 | default value does not match the truth |
| `v12_0 registers[21].field_parts[0].bit_field[1]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[21].field_parts[0].bit_field[2]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[21].field_parts[0].bit_field[4]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[21].field_parts[0].bit_field[6]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[21].field_parts[0].bit_field[7]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[21].field_parts[0]` | `physical_address` | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"User control (enable/reset auxiliary functions and FIFO)"} | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":""} | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[21].field_parts[0]` | `description` | Control and reset bits for FIFO and auxiliary interface functions. | "" | 0.0 | numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing |
| `v12_0 registers[21]` | `physical_address` | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"User control (enable/reset auxiliary functions and FIFO)"} | [{"hex":"0x3D","decimal":"61","bank":"","page":"","description":""}] | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[21]` | `default_value` | 00h | 0x00 | 0.0 | default value does not match the truth |
| `v12_0 registers[22].field_parts[0].bit_field[0]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[22].field_parts[0].bit_field[1]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[22].field_parts[0].bit_field[2]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[22].field_parts[0].bit_field[3]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[22].field_parts[0].bit_field[4]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[22].field_parts[0].bit_field[5]` | `type_write_read` | RW | "" | 0.0 | truth type_write_read='RW', v12_0 has '' |
| `v12_0 registers[22].field_parts[0]` | `physical_address` | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Power management and clock select"} | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":""} | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[22].field_parts[0]` | `description` | Power control bits, standby selections, and clock source selection. | "" | 0.0 | numeric address/bank/page matches; address description is incomplete but receives partial credit; field-part description is missing |
| `v12_0 registers[22]` | `physical_address` | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Power management and clock select"} | [{"hex":"0x3E","decimal":"62","bank":"","page":"","description":""}] | 0.5 | numeric address/bank/page matches; address description is incomplete but receives partial credit |
| `v12_0 registers[22]` | `default_value` | 00h | 0x00 | 0.0 | default value does not match the truth |

### 3.2 Unmatched v12_0 bit ranges

These v12_0 bit fields do not have an exact truth bit_start/bit_end target. They are reported for auditability and are not independently credited or added to the physical-register extra-address penalty. For reserved entries, placeholder/omitted names and descriptions are allowed; the remaining deduction is only the unmatched exact-range grouping.

| v12_0 location | Truth part target | v12_0 name | v12_0 range |
|---|---|---|---|
| `v12_0 registers[5].field_parts[0].bit_field[0]` | `truth registers[8].field_parts` | Reserved | 7:6 |
| `v12_0 registers[5].field_parts[0].bit_field[1]` | `truth registers[8].field_parts` | Reserved | 5:4 |
| `v12_0 registers[5].field_parts[0].bit_field[3]` | `truth registers[8].field_parts` | Reserved | 1:1 |
| `v12_0 registers[5].field_parts[0].bit_field[4]` | `truth registers[8].field_parts` | Reserved | 0:0 |
| `v12_0 registers[11].field_parts[0].bit_field[0]` | `truth registers[14].field_parts` | Reserved | 3:7 |
| `v12_0 registers[19].field_parts[0].bit_field[0]` | `truth registers[29].field_parts` | Reserved | 7:6 |
| `v12_0 registers[19].field_parts[0].bit_field[1]` | `truth registers[29].field_parts` | FIFO_COUNT_H | 5:0 |

### 3.3 Description differences accepted under the requested leniency

Nonempty descriptions whose meaning is preserved are not deducted; missing descriptions remain in section 3.1.

| Truth location | v12_0 location | Field | Truth content | v12_0 content | Result |
|---|---|---|---|---|---|
| `truth registers[0].field_parts.bit_field[1]` | `v12_0 registers[0].field_parts[0].bit_field[1]` | `field_description` | Contains the 6-bit I²C address of the device. The Power-On-Reset value of Bit6:Bit1 is 110 100. | Contains the 6-bit I²C address of the device. The Power-On-Reset value of Bit6:Bit1 is 110100. | C=1.0, semantically equivalent |
| `truth registers[0].field_parts.bit_field[2]` | `v12_0 registers[0].field_parts[0].bit_field[2]` | `field_description` | Bit0 is reserved (may be 0 or 1). | Bit0 is reserved. (May be 0 or 1) | C=1.0, semantically equivalent |
| `truth registers[0].register_description` | `v12_0 registers[0].register_description` | `register_description` | This register is used to verify the identity of the device, and to enable/disable the I²C interface. | Used to verify the identity of the device, and to enable/disable the I²C interface. | C=1.0, semantically equivalent |
| `truth registers[1].field_parts` | `v12_0 registers[1].field_parts[0]` | `description` | High byte of 16-bit X gyro offset (two's complement). | High byte of X gyro offset | C=1.0, semantically equivalent |
| `truth registers[2].field_parts` | `v12_0 registers[1].field_parts[1]` | `description` | Low byte of 16-bit X gyro offset (two's complement). | Low byte of X gyro offset | C=1.0, semantically equivalent |
| `truth registers[1].register_description` | `v12_0 registers[1].register_description` | `register_description` | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). \| These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | 16-bit offset (high and low bytes) of X gyro offset (2's complement). Used to remove DC bias from the sensor outputs. | C=1.0, semantically equivalent |
| `truth registers[3].field_parts` | `v12_0 registers[2].field_parts[0]` | `description` | High byte of 16-bit Y gyro offset (two's complement). | High byte of Y gyro offset | C=1.0, semantically equivalent |
| `truth registers[4].field_parts` | `v12_0 registers[2].field_parts[1]` | `description` | Low byte of 16-bit Y gyro offset (two's complement). | Low byte of Y gyro offset | C=1.0, semantically equivalent |
| `truth registers[3].register_description` | `v12_0 registers[2].register_description` | `register_description` | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). \| These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | 16-bit offset (high and low bytes) of Y gyro offset (2's complement). Used to remove DC bias from the sensor outputs. | C=1.0, semantically equivalent |
| `truth registers[5].field_parts` | `v12_0 registers[3].field_parts[0]` | `description` | High byte of 16-bit Z gyro offset (two's complement). | High byte of Z gyro offset | C=1.0, semantically equivalent |
| `truth registers[6].field_parts` | `v12_0 registers[3].field_parts[1]` | `description` | Low byte of 16-bit Z gyro offset (two's complement). | Low byte of Z gyro offset | C=1.0, semantically equivalent |
| `truth registers[5].register_description` | `v12_0 registers[3].register_description` | `register_description` | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). \| These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | 16-bit offset (high and low bytes) of Z gyro offset (2's complement). Used to remove DC bias from the sensor outputs. | C=1.0, semantically equivalent |
| `truth registers[7].field_parts.bit_field[7]` | `v12_0 registers[4].field_parts[0].bit_field[7]` | `field_description` | Last word (2 bytes) for FIFO read; described in more detail in register 60. | Last word (2 bytes) for FIFO read. | C=1.0, semantically equivalent |
| `truth registers[7].register_description` | `v12_0 registers[4].register_description` | `register_description` | Determines what data goes into the ITG-3050 FIFO (512 byte FIFO); sensor data is automatically placed into the FIFO after each ADC sampling period. | Determines what data goes into the ITG-3050 FIFO. Sensor data is automatically placed into the FIFO after each ADC sampling period. | C=1.0, semantically equivalent |
| `truth registers[8].register_description` | `v12_0 registers[5].register_description` | `register_description` | Determines the I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1 = VDD, 0 = VLOGIC. | Determines the I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1=VDD, 0=VLOGIC. | C=1.0, semantically equivalent |
| `truth registers[9].field_parts.bit_field[0]` | `v12_0 registers[6].field_parts[0].bit_field[0]` | `field_description` | 1 = reference clock output is provided at CLKOUT pin; 0 = function disabled. | 1 – reference clock output is provided at CLKOUT pin. 0 – function is disabled. | C=1.0, semantically equivalent |
| `truth registers[9].field_parts.bit_field[1]` | `v12_0 registers[6].field_parts[0].bit_field[1]` | `field_description` | Contains the I²C address of the external accelerometer device (bits 6:0). | Contains the I²C address of the device, which can also be changed by writing to this register. | C=1.0, semantically equivalent |
| `truth registers[9].register_description` | `v12_0 registers[6].register_description` | `register_description` | Contains the 7-bit slave address of the external accelerometer device and the CLKOUT enable bit. Used by the ITG-3050 when acting as I²C master for the auxiliary sensor. | Contains the 7-bit slave address of the external accelerometer device. This address is used to access the accel device so that its sensor reading can be automatically read during each sample period. | C=1.0, semantically equivalent |
| `truth registers[10].field_parts.bit_field` | `v12_0 registers[7].field_parts[0].bit_field[0]` | `field_description` | Sample rate divider. F_sample = F_internal / (divider + 1). | Sample rate divider: 0 to 255. | C=1.0, semantically equivalent |
| `truth registers[10].register_description` | `v12_0 registers[7].register_description` | `register_description` | Determines the sample rate of the ITG-3050 gyros. F_sample = F_internal / (divider + 1), where F_internal is either 1kHz or 8kHz (set by DLPF_CFG). | Determines the sample rate of the ITG-3050 gyros. The sample rate is given by F_sample = F_internal / (divider + 1), where F_internal is either 1kHz or 8kHz. | C=1.0, semantically equivalent |
| `truth registers[11].field_parts.bit_field[2]` | `v12_0 registers[8].field_parts[0].bit_field[2]` | `field_description` | Digital low pass filter configuration; also determines internal analog sampling rate. | Digital low pass filter configuration. Also determines the internal analog sampling rate. | C=1.0, semantically equivalent |
| `truth registers[11].register_description` | `v12_0 registers[8].register_description` | `register_description` | Configures external sync routing (EXT_SYNC_SET), full-scale range (FS_SEL), and digital low-pass filter (DLPF_CFG). | Configures several parameters related to the sensor acquisition: EXT_SYNC_SET, FS_SEL, DLPF_CFG. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[0]` | `v12_0 registers[9].field_parts[0].bit_field[0]` | `field_description` | Logic level for INT output pin - 1=active low, 0=active high. | Logic level for INT output pin – 1=active low, 0=active high. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[1]` | `v12_0 registers[9].field_parts[0].bit_field[1]` | `field_description` | Drive type for INT output pin - 1=open drain, 0=push-pull. | Drive type for INT output pin – 1=open drain, 0=push-pull. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[2]` | `v12_0 registers[9].field_parts[0].bit_field[2]` | `field_description` | "Latch mode - 1=latch until interrupt is cleared, 0=50\u0000us pulse." | Latch mode – 1=latch until interrupt is cleared, 0=50us pulse. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[3]` | `v12_0 registers[9].field_parts[0].bit_field[3]` | `field_description` | Interrupt status register clear method - 1=clear by reading any register, 0=clear by reading interrupt status register (26) only. | Interrupt status register clear method – 1=clear by reading any register, 0=clear by reading interrupt status register (26) only. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[4]` | `v12_0 registers[9].field_parts[0].bit_field[4]` | `field_description` | No function defined for this bit (reserved). | "" | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[6]` | `v12_0 registers[9].field_parts[0].bit_field[6]` | `field_description` | No function defined for this bit (reserved). | "" | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[7]` | `v12_0 registers[9].field_parts[0].bit_field[7]` | `field_description` | Enable interrupt when data is available (raw data ready). | Enable interrupt when data is available. | C=1.0, semantically equivalent |
| `truth registers[12].register_description` | `v12_0 registers[9].register_description` | `register_description` | Configures the interrupt operation: INT pin polarity and drive type, latch/clear behavior, and which sources generate interrupts. | Configures the interrupt operation of the ITG-3050. The interrupt output pin (INT) configuration, latching/clearing method, and triggers can be set. | C=1.0, semantically equivalent |
| `truth registers[13].field_parts.bit_field` | `v12_0 registers[10].field_parts[0].bit_field[0]` | `field_description` | Burst-mode read starting address for external accelerometer attached to secondary I2C bus. | Burst-mode read starting address for external accelerometer attached to secondary I2C bus of the ITG-3050. | C=1.0, semantically equivalent |
| `truth registers[14].field_parts.bit_field[2]` | `v12_0 registers[11].field_parts[0].bit_field[2]` | `field_description` | No function defined for this bit (reserved). | "" | C=1.0, semantically equivalent |
| `truth registers[14].register_description` | `v12_0 registers[11].register_description` | `register_description` | Indicates the status of interrupt sources. Bits are set when corresponding interrupt sources are triggered. Interrupt status bits are cleared as determined by INT_ANYRD_2CLEAR. | Used to determine the status of the ITG-3050 interrupt. Whenever one of the interrupt sources is triggered, the corresponding bit will be set. | C=1.0, semantically equivalent |
| `truth registers[15].field_parts` | `v12_0 registers[12].field_parts[0]` | `description` | High byte of 16-bit temperature data (two's complement). | High byte of temperature output | C=1.0, semantically equivalent |
| `truth registers[16].field_parts` | `v12_0 registers[12].field_parts[1]` | `description` | Low byte of 16-bit temperature data (two's complement). | Low byte of temperature output | C=1.0, semantically equivalent |
| `truth registers[15].register_description` | `v12_0 registers[12].register_description` | `register_description` | High byte of 16-bit temperature data (two's complement). \| Low byte of 16-bit temperature data (two's complement). | 16-bit temperature data (2's complement data format). | C=1.0, semantically equivalent |
| `truth registers[17].field_parts` | `v12_0 registers[13].field_parts[0]` | `description` | High byte of 16-bit X gyro output (two's complement). | High byte of X gyro output | C=1.0, semantically equivalent |
| `truth registers[18].field_parts` | `v12_0 registers[13].field_parts[1]` | `description` | Low byte of 16-bit X gyro output (two's complement). | Low byte of X gyro output | C=1.0, semantically equivalent |
| `truth registers[17].register_description` | `v12_0 registers[13].register_description` | `register_description` | High byte of 16-bit X gyro output data (two's complement). \| Low byte of 16-bit X gyro output data (two's complement). | 16-bit X gyro output data (2's complement data format). | C=1.0, semantically equivalent |
| `truth registers[19].field_parts` | `v12_0 registers[14].field_parts[0]` | `description` | High byte of 16-bit Y gyro output (two's complement). | High byte of Y gyro output | C=1.0, semantically equivalent |
| `truth registers[20].field_parts` | `v12_0 registers[14].field_parts[1]` | `description` | Low byte of 16-bit Y gyro output (two's complement). | Low byte of Y gyro output | C=1.0, semantically equivalent |
| `truth registers[19].register_description` | `v12_0 registers[14].register_description` | `register_description` | High byte of 16-bit Y gyro output data (two's complement). \| Low byte of 16-bit Y gyro output data (two's complement). | 16-bit Y gyro output data (2's complement data format). | C=1.0, semantically equivalent |
| `truth registers[21].field_parts` | `v12_0 registers[15].field_parts[0]` | `description` | High byte of 16-bit Z gyro output (two's complement). | High byte of Z gyro output | C=1.0, semantically equivalent |
| `truth registers[22].field_parts` | `v12_0 registers[15].field_parts[1]` | `description` | Low byte of 16-bit Z gyro output (two's complement). | Low byte of Z gyro output | C=1.0, semantically equivalent |
| `truth registers[21].register_description` | `v12_0 registers[15].register_description` | `register_description` | High byte of 16-bit Z gyro output data (two's complement). \| Low byte of 16-bit Z gyro output data (two's complement). | 16-bit Z gyro output data (2's complement data format). | C=1.0, semantically equivalent |
| `truth registers[23].field_parts` | `v12_0 registers[16].field_parts[0]` | `description` | High byte of 16-bit X auxiliary (accel) output. | High byte of X aux output | C=1.0, semantically equivalent |
| `truth registers[24].field_parts` | `v12_0 registers[16].field_parts[1]` | `description` | Low byte of 16-bit X auxiliary (accel) output. | Low byte of X aux output | C=1.0, semantically equivalent |
| `truth registers[23].register_description` | `v12_0 registers[16].register_description` | `register_description` | High byte of 16-bit auxiliary X-axis output (as available from auxiliary device). \| Low byte of 16-bit auxiliary X-axis output (as available from auxiliary device). | 16-bit X aux (accel) output data (as available from aux). | C=1.0, semantically equivalent |
| `truth registers[25].field_parts` | `v12_0 registers[17].field_parts[0]` | `description` | High byte of 16-bit Y auxiliary (accel) output. | High byte of Y aux output | C=1.0, semantically equivalent |
| `truth registers[26].field_parts` | `v12_0 registers[17].field_parts[1]` | `description` | Low byte of 16-bit Y auxiliary (accel) output. | Low byte of Y aux output | C=1.0, semantically equivalent |
| `truth registers[25].register_description` | `v12_0 registers[17].register_description` | `register_description` | High byte of 16-bit auxiliary Y-axis output (as available from auxiliary device). \| Low byte of 16-bit auxiliary Y-axis output (as available from auxiliary device). | 16-bit Y aux (accel) output data (as available from aux). | C=1.0, semantically equivalent |
| `truth registers[27].field_parts` | `v12_0 registers[18].field_parts[0]` | `description` | High byte of 16-bit Z auxiliary (accel) output. | High byte of Z aux output | C=1.0, semantically equivalent |
| `truth registers[28].field_parts` | `v12_0 registers[18].field_parts[1]` | `description` | Low byte of 16-bit Z auxiliary (accel) output. | Low byte of Z aux output | C=1.0, semantically equivalent |
| `truth registers[27].register_description` | `v12_0 registers[18].register_description` | `register_description` | High byte of 16-bit auxiliary Z-axis output (as available from auxiliary device). \| Low byte of 16-bit auxiliary Z-axis output (as available from auxiliary device). | 16-bit Z aux (accel) output data (as available from aux). | C=1.0, semantically equivalent |
| `truth registers[29].field_parts` | `v12_0 registers[19].field_parts[0]` | `description` | High portion of FIFO byte count. | High byte of FIFO count | C=1.0, semantically equivalent |
| `truth registers[30].field_parts` | `v12_0 registers[19].field_parts[1]` | `description` | Low portion of FIFO byte count. | Low byte of FIFO count | C=1.0, semantically equivalent |
| `truth registers[29].register_description` | `v12_0 registers[19].register_description` | `register_description` | Indicates how many bytes of valid data are contained in the FIFO (high part). \| Indicates how many bytes of valid data are contained in the FIFO (low part). | Indicates how many bytes of valid data are contained in the FIFO. The FIFO can contain up to 512 bytes of data. | C=1.0, semantically equivalent |
| `truth registers[31].field_parts.bit_field` | `v12_0 registers[20].field_parts[0].bit_field[0]` | `field_description` | FIFO data byte. | Contains the FIFO data. | C=1.0, semantically equivalent |
| `truth registers[31].register_description` | `v12_0 registers[20].register_description` | `register_description` | Output register of the FIFO. Each read returns the oldest contents of the FIFO buffer; a burst read is required to read multiple bytes. | Output register of the FIFO. Each read of this register gets the oldest contents of the ITG-3050 FIFO buffer. | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[0]` | `v12_0 registers[21].field_parts[0].bit_field[0]` | `field_description` | No function defined for this bit (reserved). | "" | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[2]` | `v12_0 registers[21].field_parts[0].bit_field[2]` | `field_description` | Enable 3rd-party accelerometer interface via I²C. Clear this bit to enable bypass mode (host direct access to accel). | Enable 3rd-party accelerometer interface via I²C. Clear this bit to enable Bypass Mode - allows host processor direct access to the 3rd-party accelerometer. | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[3]` | `v12_0 registers[21].field_parts[0].bit_field[3]` | `field_description` | No function defined for this bit (reserved). | "" | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[5]` | `v12_0 registers[21].field_parts[0].bit_field[5]` | `field_description` | No function defined for this bit (reserved). | "" | C=1.0, semantically equivalent |
| `truth registers[32].register_description` | `v12_0 registers[21].register_description` | `register_description` | Used to enable/disable and reset various modes and functions (FIFO, AUX I2C master interface, gyro reset). Reset bits are auto-cleared after reset. | Used to enable various modes on the ITG-3050, as well as reset these functions. When AUX_IF_EN is set to 1, I²C Master Mode is enabled. | C=1.0, semantically equivalent |
| `truth registers[33].register_description` | `v12_0 registers[22].register_description` | `register_description` | Manages power control, clock source selection, standby modes, and device reset. | Used to manage the power control, select the clock source, and to issue a master reset to the device. | C=1.0, semantically equivalent |

### 3.4 Representation normalizations that receive no penalty

- Numeric physical addresses are matched by numeric address, bank, and page; hex spelling, decimal spelling, object-versus-list shape, and semantically equivalent/general nested address-description wording are accepted. When the truth has an address description but the extracted description is empty, the matching numeric address receives C=0.5 for that field.
- Singleton numeric strings such as value code 0 and numeric value 0 are treated as the same objective code.
- Multi-physical logical-register merges such as X_OFFS_H/L, TEMP_OUT_H/L, and FIFO_COUNT_H/L are accepted as grouping equivalents; their one Q(L) is not recalculated separately for each part.

### 3.5 Coverage and extra-physical-register check

- Truth physical-register coverage: 34/34 matched; missing truth locations: 0.
- Extra extracted physical locations: 0; physical-address penalty factor = 1.000000.
- Extracted logical registers: 23; merged multi-physical logical registers: 11.

## 4. Invented-field check

- No extracted physical address lies outside the truth physical-address set.
- Unmatched extracted bit ranges are listed in section 3.2; they are not credited without an exact truth bit_start/bit_end target.
- Added v12_0 value enumerations on fields whose truth values are empty are objective unsupported facts and are scored as C=0 in section 3.1.
- Bit-field type_write_read is C=1 when both sides are empty; one-sided or concrete mismatches remain strict. The concrete truth type on INT_STATUS reserved bits is also absent from any exact v12_0 target.

