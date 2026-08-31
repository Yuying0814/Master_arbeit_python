# ITG3050 v11.0 detailed score — revised AGENTS.md rules

## 1. Scoring basis

- `n=34`, based on unique truth physical keys `(numeric address, bank, page)`; `physical_address.hex` and `physical_address.decimal` are normalized as the same address.
- Every one of the 23 extracted v11_0 logical registers is calculated independently from its truth physical targets: bit fields → field part → logical register `Q(L)`.
- A v11_0 logical register covering multiple truth physical addresses is evaluated once. Its single Q(L) is then associated with every covered truth physical register; the merge itself is not penalized.
- Bit-field targets are matched by exact bit_start/bit_end range. A split of one truth bit range into several v11_0 ranges is reported as an unmatched grouping and does not receive credit merely from coverage; only logical-register merge/split equivalence is exempted by AGENTS.md.
- Description-like scored fields (register_description, description, field_description, and default_value_description) are judged semantically: nonempty wording with preserved meaning is accepted, while missing descriptions normally receive C=0. For reserved bit fields, omitting name_or_parameter and field_description is explicitly accepted. Nested physical_address.description is scored leniently: equivalent/general wording receives C=1, while a missing description with matching numeric address receives C=0.5.
- Objective facts (names except the reserved-bit omission, numeric address/bank/page, widths, exact bit ranges, value codes, is_reserved, access types, and default values) are strict. Numeric-string value codes and singleton object/list representations are normalized when they encode the same fact. When value codes match, non-functional/general wording differences in value_description receive credit.
- For bit-field type_write_read, both empty truth/extracted values are treated as C=1; a one-sided empty/nonempty value or a concrete mismatch is strict.
- Only the AGENTS.md weighted fields are scored; category, index, is_multi_address, source, and all other unlisted fields are excluded.
- Rounded weights are normalized by 0.9999 at bit-field level and 1.0001 at logical-register level; field-part weights sum to 1.0000.

## Extracted logical register 1: `WHO_AM_I`

v11_0 location: `registers[0]`; truth association: `registers[0] (WHO_AM_I)`.
Associated physical locations: 0x00 (0).

### Bottom layer: bit fields, then field parts

#### Field part 1: `WHO_AM_I` at 0x00 (0)

Locations: `truth registers[0].field_parts` ↔ `v11_0 registers[0].field_parts[0]`.

**Truth bit field 1: `I2C_IF_DIS` bits 7:7**

Locations: `truth registers[0].field_parts.bit_field[0]` ↔ `v11_0 registers[0].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_IF_DIS | I2C_IF_DIS |
| `field_description` | 0.0586 | 1.0 | Setting this bit disables I²C access mode. | Setting this bit disables I2C access mode. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `ID` bits 6:1**

Locations: `truth registers[0].field_parts.bit_field[1]` ↔ `v11_0 registers[0].field_parts[0].bit_field[1]`. Judgment: truth value enumeration is missing from v11_0; truth type_write_read='R', v11_0 has 'RW'.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ID | ID |
| `field_description` | 0.0586 | 1.0 | Contains the 6-bit I²C address of the device. The Power-On-Reset value of Bit6:Bit1 is 110 100. | Contains the 6-bit I2C address of the device. Power-On-Reset value of Bit6:Bit1 is 110100. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 0.0 | {"value":"110 100","value_description":"Power-On-Reset value of Bit6:Bit1"} | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.731900/0.9999=\mathbf{0.731973}\).

**Truth bit field 3: `Reserved` bits 0:0**

Locations: `truth registers[0].field_parts.bit_field[2]` ↔ `v11_0 registers[0].field_parts[0].bit_field[2]`. Judgment: reserved-bit name omission/placeholder is permitted; truth value enumeration is missing from v11_0.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | - |
| `field_description` | 0.0586 | 1.0 | Bit0 is reserved (may be 0 or 1). | Bit0 is reserved and may be 0 or 1. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":0,"value_description":""},{"value":1,"value_description":""}] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000, 0.731973, 0.790279) = **0.840751**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Contains device ID and I²C interface disable bit"} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Single-byte identity register"} |
| `description` | 0.0693 | 1.0 | Device ID and I²C interface control | Contains I2C interface disable bit and 6-bit device I2C address ID. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.840751 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.840751=\mathbf{0.950171}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.950171) = **0.950171**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Contains device ID and I²C interface disable bit"} | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Device identity and I2C interface disable register"}] |
| `register_description` | 0.0564 | 1.0 | This register is used to verify the identity of the device, and to enable/disable the I²C interface. | Verifies the identity of the device and enables/disables the I2C interface. ID contains the 6-bit I2C address of the device; I2C_IF_DIS disables I2C access mode. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.950171 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | ["68h","69h"] | 68h or 69h |
| `default_value_description` | 0.0334 | 1.0 | [] | Whole-register default shown as 68h or 69h. |

\(Q(L_{1})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.950171 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.985216/1.0001=\mathbf{0.985118}\).

## Extracted logical register 2: `X_OFFS`

v11_0 location: `registers[1]`; truth association: `registers[1] (X_OFFS_USRH)`, `registers[2] (X_OFFS_USRL)`.
Associated physical locations: 0x0C (12), 0x0D (13).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v11_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `X_OFFS_USRH` at 0x0C (12)

Locations: `truth registers[1].field_parts` ↔ `v11_0 registers[1].field_parts[0]`.

**Truth bit field 1: `X_OFFS_H` bits 7:0**

Locations: `truth registers[1].field_parts.bit_field` ↔ `v11_0 registers[1].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | X_OFFS_H | X_OFFS_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit X gyro offset (two's complement). | High byte of 16-bit X gyro offset, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | X_OFFS_USRH | X_OFFS_USRH |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"High byte of X gyro offset (X_OFFS_H)"} | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"High byte physical register"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit X gyro offset (two's complement). | High byte X_OFFS_H of the 16-bit X gyro offset. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

#### Field part 2: `X_OFFS_USRL` at 0x0D (13)

Locations: `truth registers[2].field_parts` ↔ `v11_0 registers[1].field_parts[1]`.

**Truth bit field 1: `X_OFFS_L` bits 7:0**

Locations: `truth registers[2].field_parts.bit_field` ↔ `v11_0 registers[1].field_parts[1].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | X_OFFS_L | X_OFFS_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit X gyro offset (two's complement). | Low byte of 16-bit X gyro offset, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | X_OFFS_USRL | X_OFFS_USRL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Low byte of X gyro offset (X_OFFS_L)"} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Low byte physical register"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit X gyro offset (two's complement). | Low byte X_OFFS_L of the 16-bit X gyro offset. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000) = **1.000000**. Judgment: equivalent multi-physical logical-register grouping accepted.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | X_OFFS_USRH + X_OFFS_USRL | X_OFFS |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"High byte of X gyro offset (X_OFFS_H)"},{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Low byte of X gyro offset (X_OFFS_L)"}] | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"High byte of X gyro user offset"},{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Low byte of X gyro user offset"}] |
| `register_description` | 0.0564 | 1.0 | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). \| These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | 16-bit X gyro offset in 2's complement format. Offset values are subtracted from gyro sensor values before the sensor registers; used to remove DC bias from sensor outputs. Register map physical names are X_OFFS_USRH and X_OFFS_USRL; detailed parameter name is X_OFFS_H/L. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | "" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{2})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 3: `Y_OFFS`

v11_0 location: `registers[2]`; truth association: `registers[3] (Y_OFFS_USRH)`, `registers[4] (Y_OFFS_USRL)`.
Associated physical locations: 0x0E (14), 0x0F (15).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v11_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Y_OFFS_USRH` at 0x0E (14)

Locations: `truth registers[3].field_parts` ↔ `v11_0 registers[2].field_parts[0]`.

**Truth bit field 1: `Y_OFFS_H` bits 7:0**

Locations: `truth registers[3].field_parts.bit_field` ↔ `v11_0 registers[2].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Y_OFFS_H | Y_OFFS_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit Y gyro offset (two's complement). | High byte of 16-bit Y gyro offset, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Y_OFFS_USRH | Y_OFFS_USRH |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0E","decimal":"14","bank":"","page":"","description":"High byte of Y gyro offset (Y_OFFS_H)"} | {"hex":"0x0E","decimal":"14","bank":"","page":"","description":"High byte physical register"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Y gyro offset (two's complement). | High byte Y_OFFS_H of the 16-bit Y gyro offset. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

#### Field part 2: `Y_OFFS_USRL` at 0x0F (15)

Locations: `truth registers[4].field_parts` ↔ `v11_0 registers[2].field_parts[1]`.

**Truth bit field 1: `Y_OFFS_L` bits 7:0**

Locations: `truth registers[4].field_parts.bit_field` ↔ `v11_0 registers[2].field_parts[1].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Y_OFFS_L | Y_OFFS_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit Y gyro offset (two's complement). | Low byte of 16-bit Y gyro offset, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Y_OFFS_USRL | Y_OFFS_USRL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Low byte of Y gyro offset (Y_OFFS_L)"} | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Low byte physical register"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Y gyro offset (two's complement). | Low byte Y_OFFS_L of the 16-bit Y gyro offset. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000) = **1.000000**. Judgment: equivalent multi-physical logical-register grouping accepted.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Y_OFFS_USRH + Y_OFFS_USRL | Y_OFFS |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x0E","decimal":"14","bank":"","page":"","description":"High byte of Y gyro offset (Y_OFFS_H)"},{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Low byte of Y gyro offset (Y_OFFS_L)"}] | [{"hex":"0x0E","decimal":"14","bank":"","page":"","description":"High byte of Y gyro user offset"},{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Low byte of Y gyro user offset"}] |
| `register_description` | 0.0564 | 1.0 | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). \| These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | 16-bit Y gyro offset in 2's complement format. Offset values are subtracted from gyro sensor values before the sensor registers; used to remove DC bias from sensor outputs. Register map physical names are Y_OFFS_USRH and Y_OFFS_USRL; detailed parameter name is Y_OFFS_H/L. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | "" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{3})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 4: `Z_OFFS`

v11_0 location: `registers[3]`; truth association: `registers[5] (Z_OFFS_USRH)`, `registers[6] (Z_OFFS_USRL)`.
Associated physical locations: 0x10 (16), 0x11 (17).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v11_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Z_OFFS_USRH` at 0x10 (16)

Locations: `truth registers[5].field_parts` ↔ `v11_0 registers[3].field_parts[0]`.

**Truth bit field 1: `Z_OFFS_H` bits 7:0**

Locations: `truth registers[5].field_parts.bit_field` ↔ `v11_0 registers[3].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Z_OFFS_H | Z_OFFS_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit Z gyro offset (two's complement). | High byte of 16-bit Z gyro offset, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Z_OFFS_USRH | Z_OFFS_USRH |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"High byte of Z gyro offset (Z_OFFS_H)"} | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"High byte physical register"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Z gyro offset (two's complement). | High byte Z_OFFS_H of the 16-bit Z gyro offset. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

#### Field part 2: `Z_OFFS_USRL` at 0x11 (17)

Locations: `truth registers[6].field_parts` ↔ `v11_0 registers[3].field_parts[1]`.

**Truth bit field 1: `Z_OFFS_L` bits 7:0**

Locations: `truth registers[6].field_parts.bit_field` ↔ `v11_0 registers[3].field_parts[1].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Z_OFFS_L | Z_OFFS_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit Z gyro offset (two's complement). | Low byte of 16-bit Z gyro offset, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Z_OFFS_USRL | Z_OFFS_USRL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Low byte of Z gyro offset (Z_OFFS_L)"} | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Low byte physical register"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Z gyro offset (two's complement). | Low byte Z_OFFS_L of the 16-bit Z gyro offset. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000) = **1.000000**. Judgment: equivalent multi-physical logical-register grouping accepted.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Z_OFFS_USRH + Z_OFFS_USRL | Z_OFFS |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x10","decimal":"16","bank":"","page":"","description":"High byte of Z gyro offset (Z_OFFS_H)"},{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Low byte of Z gyro offset (Z_OFFS_L)"}] | [{"hex":"0x10","decimal":"16","bank":"","page":"","description":"High byte of Z gyro user offset"},{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Low byte of Z gyro user offset"}] |
| `register_description` | 0.0564 | 1.0 | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). \| These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | 16-bit Z gyro offset in 2's complement format. Offset values are subtracted from gyro sensor values before the sensor registers; used to remove DC bias from sensor outputs. Register map physical names are Z_OFFS_USRH and Z_OFFS_USRL; detailed parameter name is Z_OFFS_H/L. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | "" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{4})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 5: `FIFO_EN`

v11_0 location: `registers[4]`; truth association: `registers[7] (FIFO_EN)`.
Associated physical locations: 0x12 (18).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_EN` at 0x12 (18)

Locations: `truth registers[7].field_parts` ↔ `v11_0 registers[4].field_parts[0]`.

**Truth bit field 1: `TEMP_OUT` bits 7:7**

Locations: `truth registers[7].field_parts.bit_field[0]` ↔ `v11_0 registers[4].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_OUT | TEMP_OUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Temperature reading into FIFO. | Setting this inserts the Temperature reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `GYRO_XOUT` bits 6:6**

Locations: `truth registers[7].field_parts.bit_field[1]` ↔ `v11_0 registers[4].field_parts[0].bit_field[1]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_XOUT | GYRO_XOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the X Gyro reading into FIFO. | Setting this inserts the X Gyro reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `GYRO_YOUT` bits 5:5**

Locations: `truth registers[7].field_parts.bit_field[2]` ↔ `v11_0 registers[4].field_parts[0].bit_field[2]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_YOUT | GYRO_YOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Y Gyro reading into FIFO. | Setting this inserts the Y Gyro reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `GYRO_ZOUT` bits 4:4**

Locations: `truth registers[7].field_parts.bit_field[3]` ↔ `v11_0 registers[4].field_parts[0].bit_field[3]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_ZOUT | GYRO_ZOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Z Gyro reading into FIFO. | Setting this inserts the Z Gyro reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 5: `AUX_XOUT` bits 3:3**

Locations: `truth registers[7].field_parts.bit_field[4]` ↔ `v11_0 registers[4].field_parts[0].bit_field[4]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_XOUT | AUX_XOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the X Accelerometer reading into FIFO. | Setting this inserts the X Accelerometer reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 6: `AUX_YOUT` bits 2:2**

Locations: `truth registers[7].field_parts.bit_field[5]` ↔ `v11_0 registers[4].field_parts[0].bit_field[5]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_YOUT | AUX_YOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Y Accelerometer reading into FIFO. | Setting this inserts the Y Accelerometer reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 7: `AUX_ZOUT` bits 1:1**

Locations: `truth registers[7].field_parts.bit_field[6]` ↔ `v11_0 registers[4].field_parts[0].bit_field[6]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_ZOUT | AUX_ZOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Z Accelerometer reading into FIFO. | Setting this inserts the Z Accelerometer reading into FIFO. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 8: `FIFO_FOOTER` bits 0:0**

Locations: `truth registers[7].field_parts.bit_field[7]` ↔ `v11_0 registers[4].field_parts[0].bit_field[7]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_FOOTER | FIFO_FOOTER |
| `field_description` | 0.0586 | 1.0 | Last word (2 bytes) for FIFO read; described in more detail in register 60. | Last word (2 bytes) for FIFO read; described in more detail in register 60. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | FIFO_EN | FIFO_EN |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"FIFO enable bits (select which sensor data are written into FIFO)"} | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"Single-byte FIFO enable register"} |
| `description` | 0.0693 | 1.0 | Enable selection for data inserted into FIFO; each bit inserts the listed data into the FIFO when set. | Selects temperature, gyro, auxiliary accel, and footer words for FIFO insertion. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | FIFO_EN | FIFO_EN |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"FIFO enable bits (select which sensor data are written into FIFO)"} | [{"hex":"0x12","decimal":"18","bank":"","page":"","description":"FIFO enable register"}] |
| `register_description` | 0.0564 | 1.0 | Determines what data goes into the ITG-3050 FIFO (512 byte FIFO); sensor data is automatically placed into the FIFO after each ADC sampling period. | Determines what data goes into the 512-byte ITG-3050 FIFO. Sensor data is placed into FIFO after each ADC sampling period; ADC sample rate is controlled by register 21. FIFO insertion order is MSB to LSB and two bytes are used per reading. FIFO_FOOTER is described with register 60. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{5})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 6: `AUX_VDDIO`

v11_0 location: `registers[5]`; truth association: `registers[8] (AUX_VDDIO)`.
Associated physical locations: 0x13 (19).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_VDDIO` at 0x13 (19)

Locations: `truth registers[8].field_parts` ↔ `v11_0 registers[5].field_parts[0]`.

**Truth bit field 1: `Reserved` bits 7:3**

Locations: `truth registers[8].field_parts.bit_field[0]` ↔ `v11_0 registers[5].field_parts[0].bit_field[0]`. Judgment: is_reserved is objectively different; reserved-bit name omission/placeholder is permitted.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | 0 |
| `field_description` | 0.0586 | 1.0 | Load zeros into bits 7..3 (must be 0). | Load zeros into Bits 3-7. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 0.0 | True | False |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×0.0 + 0.0583×1.0)/0.9999=0.924900/0.9999=\mathbf{0.924992}\).

**Truth bit field 2: `AUX_VDDIO` bits 2:2**

Locations: `truth registers[8].field_parts.bit_field[1]` ↔ `v11_0 registers[5].field_parts[0].bit_field[1]`. Judgment: v11_0 adds unsupported objective value codes where truth has none.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_VDDIO | AUX_VDDIO |
| `field_description` | 0.0586 | 1.0 | I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1=VDD, 0=VLOGIC. | I/O logic levels for secondary I2C bus clock and data lines AUX_CL and AUX_DA. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [] | [{"value":"1","value_description":"VDD"},{"value":"0","value_description":"VLOGIC"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 3: `Reserved` bits 1:0**

Locations: `truth registers[8].field_parts.bit_field[2]` ↔ `v11_0 registers[5].field_parts[0].bit_field[2]`. Judgment: is_reserved is objectively different; reserved-bit name omission/placeholder is permitted.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | 0 |
| `field_description` | 0.0586 | 1.0 | Load zeros into bits 1..0 (must be 0). | Load zeros into Bits 0 and 1. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 0.0 | True | False |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×0.0 + 0.0583×1.0)/0.9999=0.924900/0.9999=\mathbf{0.924992}\).

**Field-part aggregation**

bit_field correctness = mean(0.924992, 0.790279, 0.924992) = **0.880088**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_VDDIO | AUX_VDDIO |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Auxiliary I/O voltage selection bit"} | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Single-byte AUX VDDIO register"} |
| `description` | 0.0693 | 1.0 | I/O logic level selection for the secondary I²C bus lines; other bits must be written as zeros. | Contains AUX_VDDIO at bit 2; other shown bits are fixed zero. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.880088 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.880088=\mathbf{0.962480}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.962480) = **0.962480**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_VDDIO | AUX_VDDIO |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Auxiliary I/O voltage selection bit"} | [{"hex":"0x13","decimal":"19","bank":"","page":"","description":"AUX VDDIO configuration register"}] |
| `register_description` | 0.0564 | 1.0 | Determines the I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1 = VDD, 0 = VLOGIC. | Determines the I/O logic levels for the secondary I2C bus clock and data lines AUX_CL and AUX_DA. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.962480 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{6})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.962480 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.988893/1.0001=\mathbf{0.988794}\).

## Extracted logical register 7: `AUX_SLV_ADDR`

v11_0 location: `registers[6]`; truth association: `registers[9] (AUX_SLV_ADDR)`.
Associated physical locations: 0x14 (20).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_SLV_ADDR` at 0x14 (20)

Locations: `truth registers[9].field_parts` ↔ `v11_0 registers[6].field_parts[0]`.

**Truth bit field 1: `CLKOUT_EN` bits 7:7**

Locations: `truth registers[9].field_parts.bit_field[0]` ↔ `v11_0 registers[6].field_parts[0].bit_field[0]`. Judgment: v11_0 adds unsupported objective value codes where truth has none.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | CLKOUT_EN | CLKOUT_EN |
| `field_description` | 0.0586 | 1.0 | 1 = reference clock output is provided at CLKOUT pin; 0 = function disabled. | Controls reference clock output at CLKOUT pin. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [] | [{"value":"1","value_description":"Reference clock output is provided at CLKOUT pin"},{"value":"0","value_description":"Function is disabled"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 2: `AUX_ID` bits 6:0**

Locations: `truth registers[9].field_parts.bit_field[1]` ↔ `v11_0 registers[6].field_parts[0].bit_field[1]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_ID | AUX_ID |
| `field_description` | 0.0586 | 1.0 | Contains the I²C address of the external accelerometer device (bits 6:0). | Contains the I2C address of the external accelerometer device; can be changed by writing this register. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(0.790279, 1.000000) = **0.895140**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_SLV_ADDR | AUX_SLV_ADDR |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Auxiliary device 7-bit slave address and CLKOUT enable"} | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Single-byte AUX slave address register"} |
| `description` | 0.0693 | 1.0 | CLKOUT enable and auxiliary device address (AUX_ID). | CLKOUT_EN at bit 7 and AUX_ID 7-bit address at bits 6:0. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.895140 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.895140=\mathbf{0.967189}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.967189) = **0.967189**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_SLV_ADDR | AUX_SLV_ADDR |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Auxiliary device 7-bit slave address and CLKOUT enable"} | [{"hex":"0x14","decimal":"20","bank":"","page":"","description":"AUX slave address register"}] |
| `register_description` | 0.0564 | 1.0 | Contains the 7-bit slave address of the external accelerometer device and the CLKOUT enable bit. Used by the ITG-3050 when acting as I²C master for the auxiliary sensor. | Contains the 7-bit slave address of the external accelerometer and CLKOUT enable. The address is used to access the accel device so its sensor reading can be automatically read each sample period. For the interface to be active, AUX_IF_EN in User Control register 61 must be set; after changing this register, the accel interface must be reset via register 61. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.967189 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{7})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.967189 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.990299/1.0001=\mathbf{0.990200}\).

## Extracted logical register 8: `SMPLRT_DIV`

v11_0 location: `registers[7]`; truth association: `registers[10] (SMPLRT_DIV)`.
Associated physical locations: 0x15 (21).

### Bottom layer: bit fields, then field parts

#### Field part 1: `SMPLRT_DIV` at 0x15 (21)

Locations: `truth registers[10].field_parts` ↔ `v11_0 registers[7].field_parts[0]`.

**Truth bit field 1: `SMPLRT_DIV` bits 7:0**

Locations: `truth registers[10].field_parts.bit_field` ↔ `v11_0 registers[7].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SMPLRT_DIV | SMPLRT_DIV |
| `field_description` | 0.0586 | 1.0 | Sample rate divider. F_sample = F_internal / (divider + 1). | Sample rate divider: 0 to 255. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | SMPLRT_DIV | SMPLRT_DIV |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Sample rate divider"} | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Single-byte sample rate divider register"} |
| `description` | 0.0693 | 1.0 | Sample rate divider (0-255). | 8-bit sample rate divider. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | SMPLRT_DIV | SMPLRT_DIV |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Sample rate divider"} | [{"hex":"0x15","decimal":"21","bank":"","page":"","description":"Sample rate divider register"}] |
| `register_description` | 0.0564 | 1.0 | Determines the sample rate of the ITG-3050 gyros. F_sample = F_internal / (divider + 1), where F_internal is either 1kHz or 8kHz (set by DLPF_CFG). | Determines gyro sample rate. Internal sampling is 1 kHz or 8 kHz depending on DLPF_CFG in register 22; output sample rate is Fsample = Finternal / (divider + 1). Example: Finternal=1 kHz and divider=7 gives 125 Hz or 8 ms per sample. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{8})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 9: `DLPF_FS_SYNC`

v11_0 location: `registers[8]`; truth association: `registers[11] (DLPF_FS_SYNC)`.
Associated physical locations: 0x16 (22).

### Bottom layer: bit fields, then field parts

#### Field part 1: `DLPF_FS_SYNC` at 0x16 (22)

Locations: `truth registers[11].field_parts` ↔ `v11_0 registers[8].field_parts[0]`.

**Truth bit field 1: `EXT_SYNC_SET` bits 7:5**

Locations: `truth registers[11].field_parts.bit_field[0]` ↔ `v11_0 registers[8].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | EXT_SYNC_SET | EXT_SYNC_SET |
| `field_description` | 0.0586 | 1.0 | Routing for the external frame synchronization input bit. | Routing for the external frame synchronization input bit. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No sync (default)"},{"value":"1","value_description":"TEMP_OUT_L[0]"},{"value":"2","value_description":"GYRO_XOUT_L[0]"},{"value":"3","value_description":"GYRO_YOUT_L[0]"},{"value":"4","value_description":"GYRO_ZOUT_L[0]"},{"value":"5","value_description":"AUX_XOUT_L[0]"},{"value":"6","value_description":"AUX_YOUT_L[0]"},{"value":"7","value_description":"AUX_ZOUT_L[0]"}] | [{"value":"0","value_description":"No sync (default)"},{"value":"1","value_description":"TEMP_OUT_L[0]"},{"value":"2","value_description":"GYRO_XOUT_L[0]"},{"value":"3","value_description":"GYRO_YOUT_L[0]"},{"value":"4","value_description":"GYRO_ZOUT_L[0]"},{"value":"5","value_description":"AUX_XOUT_L[0]"},{"value":"6","value_description":"AUX_YOUT_L[0]"},{"value":"7","value_description":"AUX_ZOUT_L[0]"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `FS_SEL` bits 4:3**

Locations: `truth registers[11].field_parts.bit_field[1]` ↔ `v11_0 registers[8].field_parts[0].bit_field[1]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FS_SEL | FS_SEL |
| `field_description` | 0.0586 | 1.0 | Full scale selection for gyro sensor data. | Full scale selection for gyro sensor data. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"±250°/sec"},{"value":"1","value_description":"±500°/sec"},{"value":"2","value_description":"±1000°/sec"},{"value":"3","value_description":"±2000°/sec"}] | [{"value":"0","value_description":"±250°/sec"},{"value":"1","value_description":"±500°/sec"},{"value":"2","value_description":"±1000°/sec"},{"value":"3","value_description":"±2000°/sec"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `DLPF_CFG` bits 2:0**

Locations: `truth registers[11].field_parts.bit_field[2]` ↔ `v11_0 registers[8].field_parts[0].bit_field[2]`. Judgment: objective value-code set matches; value-description wording has no functional deviation and is accepted.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DLPF_CFG | DLPF_CFG |
| `field_description` | 0.0586 | 1.0 | Digital low pass filter configuration; also determines internal analog sampling rate. | Digital low pass filter configuration; also determines analog sample rate. Additional gain and phase response plots are shown in the DLPF characteristics figure and should be retrieved if filter response details are needed. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Low pass filter bandwidth 256Hz; Analog sample rate 8kHz"},{"value":"1","value_description":"Low pass filter bandwidth 188Hz; Analog sample rate 1kHz"},{"value":"2","value_description":"Low pass filter bandwidth 98Hz; Analog sample rate 1kHz"},{"value":"3","value_description":"Low pass filter bandwidth 42Hz; Analog sample rate 1kHz"},{"value":"4","value_description":"Low pass filter bandwidth 20Hz; Analog sample rate 1kHz"},{"value":"5","value_description":"Low pass filter bandwidth 10Hz; Analog sample rate 1kHz"},{"value":"6","value_description":"Low pass filter bandwidth 5Hz; Analog sample rate 1kHz"}] | [{"value":"0","value_description":"Low pass filter bandwidth 256Hz; analog sample rate 8kHz"},{"value":"1","value_description":"Low pass filter bandwidth 188Hz; analog sample rate 1kHz"},{"value":"2","value_description":"Low pass filter bandwidth 98Hz; analog sample rate 1kHz"},{"value":"3","value_description":"Low pass filter bandwidth 42Hz; analog sample rate 1kHz"},{"value":"4","value_description":"Low pass filter bandwidth 20Hz; analog sample rate 1kHz"},{"value":"5","value_description":"Low pass filter bandwidth 10Hz; analog sample rate 1kHz"},{"value":"6","value_description":"Low pass filter bandwidth 5Hz; analog sample rate 1kHz"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | DLPF_FS_SYNC | DLPF_FS_SYNC |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"DLPF_CFG, FS_SEL, and EXT_SYNC_SET configuration"} | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"Single-byte configuration register"} |
| `description` | 0.0693 | 1.0 | EXT_SYNC_SET (bits7:5), FS_SEL (bits4:3), DLPF_CFG (bits2:0). | EXT_SYNC_SET bits 7:5, FS_SEL bits 4:3, DLPF_CFG bits 2:0. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | DLPF_FS_SYNC | DLPF_FS_SYNC |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"DLPF_CFG, FS_SEL, and EXT_SYNC_SET configuration"} | [{"hex":"0x16","decimal":"22","bank":"","page":"","description":"DLPF, full-scale, and external sync configuration register"}] |
| `register_description` | 0.0564 | 1.0 | Configures external sync routing (EXT_SYNC_SET), full-scale range (FS_SEL), and digital low-pass filter (DLPF_CFG). | Configures external frame sync routing, gyro full-scale range, and digital low-pass filter. EXT_SYNC_SET routes FSYNC input state into the LSB of a selected sensor low-byte register. FS_SEL selects gyro full-scale range. DLPF_CFG sets low-pass bandwidth and internal analog sample rate used by SMPLRT_DIV. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{9})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 10: `INT_CFG`

v11_0 location: `registers[9]`; truth association: `registers[12] (INT_CFG)`.
Associated physical locations: 0x17 (23).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_CFG` at 0x17 (23)

Locations: `truth registers[12].field_parts` ↔ `v11_0 registers[9].field_parts[0]`.

**Truth bit field 1: `ACTL` bits 7:7**

Locations: `truth registers[12].field_parts.bit_field[0]` ↔ `v11_0 registers[9].field_parts[0].bit_field[0]`. Judgment: v11_0 adds unsupported objective value codes where truth has none.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACTL | ACTL |
| `field_description` | 0.0586 | 1.0 | Logic level for INT output pin - 1=active low, 0=active high. | Logic level for INT output pin. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [] | [{"value":"1","value_description":"Active low"},{"value":"0","value_description":"Active high"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 2: `OPEN` bits 6:6**

Locations: `truth registers[12].field_parts.bit_field[1]` ↔ `v11_0 registers[9].field_parts[0].bit_field[1]`. Judgment: v11_0 adds unsupported objective value codes where truth has none.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | OPEN | OPEN |
| `field_description` | 0.0586 | 1.0 | Drive type for INT output pin - 1=open drain, 0=push-pull. | Drive type for INT output pin. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [] | [{"value":"1","value_description":"Open drain"},{"value":"0","value_description":"Push-pull"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 3: `LATCH_INT_EN` bits 5:5**

Locations: `truth registers[12].field_parts.bit_field[2]` ↔ `v11_0 registers[9].field_parts[0].bit_field[2]`. Judgment: v11_0 adds unsupported objective value codes where truth has none.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LATCH_INT_EN | LATCH_INT_EN |
| `field_description` | 0.0586 | 1.0 | "Latch mode - 1=latch until interrupt is cleared, 0=50\u0000us pulse." | Latch mode for interrupt output. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [] | [{"value":"1","value_description":"Latch until interrupt is cleared"},{"value":"0","value_description":"50us pulse"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 4: `INT_ANYRD_2CLEAR` bits 4:4**

Locations: `truth registers[12].field_parts.bit_field[3]` ↔ `v11_0 registers[9].field_parts[0].bit_field[3]`. Judgment: v11_0 adds unsupported objective value codes where truth has none.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | INT_ANYRD_2CLEAR | INT_ANYRD_2CLEAR |
| `field_description` | 0.0586 | 1.0 | Interrupt status register clear method - 1=clear by reading any register, 0=clear by reading interrupt status register (26) only. | Interrupt status register clear method. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [] | [{"value":"1","value_description":"Clear by reading any register"},{"value":"0","value_description":"Clear by reading interrupt status register (26) only"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 5: `Reserved` bits 3:3**

Locations: `truth registers[12].field_parts.bit_field[4]` ↔ `v11_0 registers[9].field_parts[0].bit_field[4]`. Judgment: reserved-bit name omission/placeholder is permitted.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | - |
| `field_description` | 0.0586 | 1.0 | No function defined for this bit (reserved). | Undefined bit; set to zero for future compatibility. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 6: `ITG_RDY_EN` bits 2:2**

Locations: `truth registers[12].field_parts.bit_field[5]` ↔ `v11_0 registers[9].field_parts[0].bit_field[5]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ITG_RDY_EN | ITG_RDY_EN |
| `field_description` | 0.0586 | 1.0 | Enable interrupt when device is ready (PLL ready after changing clock source). | Enable interrupt when device is ready (PLL ready after changing clock source). |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 7: `Reserved` bits 1:1**

Locations: `truth registers[12].field_parts.bit_field[6]` ↔ `v11_0 registers[9].field_parts[0].bit_field[6]`. Judgment: reserved-bit name omission/placeholder is permitted.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | - |
| `field_description` | 0.0586 | 1.0 | No function defined for this bit (reserved). | Undefined bit; set to zero for future compatibility. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 8: `RAW_RDY_EN` bits 0:0**

Locations: `truth registers[12].field_parts.bit_field[7]` ↔ `v11_0 registers[9].field_parts[0].bit_field[7]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | RAW_RDY_EN | RAW_RDY_EN |
| `field_description` | 0.0586 | 1.0 | Enable interrupt when data is available (raw data ready). | Enable interrupt when data is available. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(0.790279, 0.790279, 0.790279, 0.790279, 1.000000, 1.000000, 1.000000, 1.000000) = **0.895140**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | INT_CFG | INT_CFG |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Interrupt configuration"} | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Single-byte interrupt configuration register"} |
| `description` | 0.0693 | 1.0 | Interrupt pin configuration, latch mode, and interrupt enables. | Interrupt pin configuration, clear method, and enable bits with reserved bits 3 and 1. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.895140 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.895140=\mathbf{0.967189}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.967189) = **0.967189**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | INT_CFG | INT_CFG |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Interrupt configuration"} | [{"hex":"0x17","decimal":"23","bank":"","page":"","description":"Interrupt configuration register"}] |
| `register_description` | 0.0564 | 1.0 | Configures the interrupt operation: INT pin polarity and drive type, latch/clear behavior, and which sources generate interrupts. | Configures interrupt operation: INT output pin level and drive type, interrupt latch/clear method, and interrupt trigger enables. If LATCH_INT_EN=1, INT is held active until interrupt status is cleared. RAW_RDY_EN is recommended when the application must read every sample. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.967189 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{10})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.967189 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.990299/1.0001=\mathbf{0.990200}\).

## Extracted logical register 11: `AUX_ADDR`

v11_0 location: `registers[10]`; truth association: `registers[13] (AUX_ADDR)`.
Associated physical locations: 0x18 (24).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_ADDR` at 0x18 (24)

Locations: `truth registers[13].field_parts` ↔ `v11_0 registers[10].field_parts[0]`.

**Truth bit field 1: `BURST_ADDR` bits 7:0**

Locations: `truth registers[13].field_parts.bit_field` ↔ `v11_0 registers[10].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | BURST_ADDR | BURST_ADDR |
| `field_description` | 0.0586 | 1.0 | Burst-mode read starting address for external accelerometer attached to secondary I2C bus. | Burst-mode read starting address for external accelerometer attached to secondary I2C bus; starting address the ITG-3050 could use to read from. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_ADDR | AUX_ADDR |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Auxiliary accelerometer burst read starting address (BURST_ADDR)"} | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Single-byte AUX burst address register"} |
| `description` | 0.0693 | 1.0 | Burst-mode read starting address for external accelerometer (BURST_ADDR). | Burst-mode read starting address for external accelerometer on secondary I2C bus. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_ADDR | AUX_ADDR |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Auxiliary accelerometer burst read starting address (BURST_ADDR)"} | [{"hex":"0x18","decimal":"24","bank":"","page":"","description":"AUX burst read address register"}] |
| `register_description` | 0.0564 | 1.0 | Configures the burst-mode-read starting address for an accelerometer attached to the secondary I2C bus of the ITG-3050. | Configures the burst-mode-read starting address for an accelerometer attached to the secondary I2C bus of the ITG-3050. Detailed section identifies this register as read only. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{11})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 12: `INT_STATUS`

v11_0 location: `registers[11]`; truth association: `registers[14] (INT_STATUS)`.
Associated physical locations: 0x1A (26).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_STATUS` at 0x1A (26)

Locations: `truth registers[14].field_parts` ↔ `v11_0 registers[11].field_parts[0]`.

**Truth bit field 1: `Reserved` bits 7:3**

Locations: `truth registers[14].field_parts.bit_field[0]` ↔ `v11_0 registers[11].field_parts[0].bit_field[0]`. Judgment: reserved-bit name omission/placeholder is permitted; truth type_write_read='R', v11_0 has ''.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | - |
| `field_description` | 0.0586 | 1.0 | No function defined for these bits (reserved). | Undefined bits; no function shown. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Truth bit field 2: `ITG_RDY` bits 2:2**

Locations: `truth registers[14].field_parts.bit_field[1]` ↔ `v11_0 registers[11].field_parts[0].bit_field[1]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ITG_RDY | ITG_RDY |
| `field_description` | 0.0586 | 1.0 | PLL ready. | PLL ready. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `Reserved` bits 1:1**

Locations: `truth registers[14].field_parts.bit_field[2]` ↔ `v11_0 registers[11].field_parts[0].bit_field[2]`. Judgment: reserved-bit name omission/placeholder is permitted.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | - |
| `field_description` | 0.0586 | 1.0 | No function defined for this bit (reserved). | Undefined bit; no function shown. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `RAW_DATA_RDY` bits 0:0**

Locations: `truth registers[14].field_parts.bit_field[3]` ↔ `v11_0 registers[11].field_parts[0].bit_field[3]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | RAW_DATA_RDY | RAW_DATA_RDY |
| `field_description` | 0.0586 | 1.0 | Raw data or FIFO data is ready. | Raw data or FIFO data is ready. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 1.000000, 1.000000, 1.000000) = **0.985424**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | INT_STATUS | INT_STATUS |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Interrupt status"} | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Single-byte interrupt status register"} |
| `description` | 0.0693 | 1.0 | Interrupt status bits. | Status bits ITG_RDY and RAW_DATA_RDY with other bits reserved. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.985424 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.985424=\mathbf{0.995439}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.995439) = **0.995439**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | INT_STATUS | INT_STATUS |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Interrupt status"} | [{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Interrupt status register"}] |
| `register_description` | 0.0564 | 1.0 | Indicates the status of interrupt sources. Bits are set when corresponding interrupt sources are triggered. Interrupt status bits are cleared as determined by INT_ANYRD_2CLEAR. | Determines ITG-3050 interrupt status. When an interrupt source triggers, the corresponding bit is set; INT pin polarity and latch type do not affect status bits. RAW_DATA_RDY indicates new sensor data in sensor registers 27 to 34 or FIFO register 60. Status bits clear as determined by INT_ANYRD_2CLEAR in register 23. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.995439 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{12})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.995439 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.998738/1.0001=\mathbf{0.998638}\).

## Extracted logical register 13: `TEMP_OUT`

v11_0 location: `registers[12]`; truth association: `registers[15] (TEMP_OUT_H)`, `registers[16] (TEMP_OUT_L)`.
Associated physical locations: 0x1B (27), 0x1C (28).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v11_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `TEMP_OUT_H` at 0x1B (27)

Locations: `truth registers[15].field_parts` ↔ `v11_0 registers[12].field_parts[0]`.

**Truth bit field 1: `TEMP_OUT_H` bits 7:0**

Locations: `truth registers[15].field_parts.bit_field` ↔ `v11_0 registers[12].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_OUT_H | TEMP_OUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit temperature data (two's complement). | High byte of 16-bit temperature data, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TEMP_OUT_H | TEMP_OUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"High byte of temperature output (TEMP_OUT_H)"} | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"High byte physical register"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit temperature data (two's complement). | High byte TEMP_OUT_H of 16-bit temperature data. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

#### Field part 2: `TEMP_OUT_L` at 0x1C (28)

Locations: `truth registers[16].field_parts` ↔ `v11_0 registers[12].field_parts[1]`.

**Truth bit field 1: `TEMP_OUT_L` bits 7:0**

Locations: `truth registers[16].field_parts.bit_field` ↔ `v11_0 registers[12].field_parts[1].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_OUT_L | TEMP_OUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit temperature data (two's complement). | Low byte of 16-bit temperature data, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TEMP_OUT_L | TEMP_OUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Low byte of temperature output (TEMP_OUT_L)"} | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Low byte physical register"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit temperature data (two's complement). | Low byte TEMP_OUT_L of 16-bit temperature data. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000) = **1.000000**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | TEMP_OUT_H + TEMP_OUT_L | TEMP_OUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"High byte of temperature output (TEMP_OUT_H)"},{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Low byte of temperature output (TEMP_OUT_L)"}] | [{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"High byte of temperature output"},{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Low byte of temperature output"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit temperature data (two's complement). \| Low byte of 16-bit temperature data (two's complement). | 16-bit temperature output data in 2's complement format. Sensor data is manipulated by full-scale setting register 22 and offset registers 12 to 17 before being placed into sensor registers; use interrupt function to determine when new data is available. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0000h |
| `default_value_description` | 0.0334 | 1.0 | "" | High byte then low byte; default applies if sensor is disabled. |

\(Q(L_{13})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.933400/1.0001=\mathbf{0.933307}\).

## Extracted logical register 14: `GYRO_XOUT`

v11_0 location: `registers[13]`; truth association: `registers[17] (GYRO_XOUT_H)`, `registers[18] (GYRO_XOUT_L)`.
Associated physical locations: 0x1D (29), 0x1E (30).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v11_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_XOUT_H` at 0x1D (29)

Locations: `truth registers[17].field_parts` ↔ `v11_0 registers[13].field_parts[0]`.

**Truth bit field 1: `GYRO_XOUT_H` bits 7:0**

Locations: `truth registers[17].field_parts.bit_field` ↔ `v11_0 registers[13].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_XOUT_H | GYRO_XOUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit X gyro output (two's complement). | High byte of 16-bit X gyro output data, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_XOUT_H | GYRO_XOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"High byte of X gyro output (GYRO_XOUT_H)"} | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"High byte physical register"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit X gyro output (two's complement). | High byte GYRO_XOUT_H of 16-bit X gyro output. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

#### Field part 2: `GYRO_XOUT_L` at 0x1E (30)

Locations: `truth registers[18].field_parts` ↔ `v11_0 registers[13].field_parts[1]`.

**Truth bit field 1: `GYRO_XOUT_L` bits 7:0**

Locations: `truth registers[18].field_parts.bit_field` ↔ `v11_0 registers[13].field_parts[1].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_XOUT_L | GYRO_XOUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit X gyro output (two's complement). | Low byte of 16-bit X gyro output data, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_XOUT_L | GYRO_XOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Low byte of X gyro output (GYRO_XOUT_L)"} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Low byte physical register"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit X gyro output (two's complement). | Low byte GYRO_XOUT_L of 16-bit X gyro output. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000) = **1.000000**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | GYRO_XOUT_H + GYRO_XOUT_L | GYRO_XOUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"High byte of X gyro output (GYRO_XOUT_H)"},{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Low byte of X gyro output (GYRO_XOUT_L)"}] | [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"High byte of X gyro output"},{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Low byte of X gyro output"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit X gyro output data (two's complement). \| Low byte of 16-bit X gyro output data (two's complement). | 16-bit X gyro output data in 2's complement format. Sensor data is affected by full-scale setting register 22 and offset registers 12 to 17 before being placed into sensor registers. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0000h |
| `default_value_description` | 0.0334 | 1.0 | "" | High byte then low byte; default applies if sensor is disabled. |

\(Q(L_{14})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.933400/1.0001=\mathbf{0.933307}\).

## Extracted logical register 15: `GYRO_YOUT`

v11_0 location: `registers[14]`; truth association: `registers[19] (GYRO_YOUT_H)`, `registers[20] (GYRO_YOUT_L)`.
Associated physical locations: 0x1F (31), 0x20 (32).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v11_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_YOUT_H` at 0x1F (31)

Locations: `truth registers[19].field_parts` ↔ `v11_0 registers[14].field_parts[0]`.

**Truth bit field 1: `GYRO_YOUT_H` bits 7:0**

Locations: `truth registers[19].field_parts.bit_field` ↔ `v11_0 registers[14].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_YOUT_H | GYRO_YOUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit Y gyro output (two's complement). | High byte of 16-bit Y gyro output data, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_YOUT_H | GYRO_YOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"High byte of Y gyro output (GYRO_YOUT_H)"} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"High byte physical register"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Y gyro output (two's complement). | High byte GYRO_YOUT_H of 16-bit Y gyro output. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

#### Field part 2: `GYRO_YOUT_L` at 0x20 (32)

Locations: `truth registers[20].field_parts` ↔ `v11_0 registers[14].field_parts[1]`.

**Truth bit field 1: `GYRO_YOUT_L` bits 7:0**

Locations: `truth registers[20].field_parts.bit_field` ↔ `v11_0 registers[14].field_parts[1].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_YOUT_L | GYRO_YOUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit Y gyro output (two's complement). | Low byte of 16-bit Y gyro output data, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_YOUT_L | GYRO_YOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Low byte of Y gyro output (GYRO_YOUT_L)"} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Low byte physical register"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Y gyro output (two's complement). | Low byte GYRO_YOUT_L of 16-bit Y gyro output. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000) = **1.000000**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | GYRO_YOUT_H + GYRO_YOUT_L | GYRO_YOUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"High byte of Y gyro output (GYRO_YOUT_H)"},{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Low byte of Y gyro output (GYRO_YOUT_L)"}] | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"High byte of Y gyro output"},{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Low byte of Y gyro output"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit Y gyro output data (two's complement). \| Low byte of 16-bit Y gyro output data (two's complement). | 16-bit Y gyro output data in 2's complement format. Sensor data is affected by full-scale setting register 22 and offset registers 12 to 17 before being placed into sensor registers. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0000h |
| `default_value_description` | 0.0334 | 1.0 | "" | High byte then low byte; default applies if sensor is disabled. |

\(Q(L_{15})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.933400/1.0001=\mathbf{0.933307}\).

## Extracted logical register 16: `GYRO_ZOUT`

v11_0 location: `registers[15]`; truth association: `registers[21] (GYRO_ZOUT_H)`, `registers[22] (GYRO_ZOUT_L)`.
Associated physical locations: 0x21 (33), 0x22 (34).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v11_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_ZOUT_H` at 0x21 (33)

Locations: `truth registers[21].field_parts` ↔ `v11_0 registers[15].field_parts[0]`.

**Truth bit field 1: `GYRO_ZOUT_H` bits 7:0**

Locations: `truth registers[21].field_parts.bit_field` ↔ `v11_0 registers[15].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_ZOUT_H | GYRO_ZOUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit Z gyro output (two's complement). | High byte of 16-bit Z gyro output data, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_ZOUT_H | GYRO_ZOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"High byte of Z gyro output (GYRO_ZOUT_H)"} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"High byte physical register"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Z gyro output (two's complement). | High byte GYRO_ZOUT_H of 16-bit Z gyro output. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

#### Field part 2: `GYRO_ZOUT_L` at 0x22 (34)

Locations: `truth registers[22].field_parts` ↔ `v11_0 registers[15].field_parts[1]`.

**Truth bit field 1: `GYRO_ZOUT_L` bits 7:0**

Locations: `truth registers[22].field_parts.bit_field` ↔ `v11_0 registers[15].field_parts[1].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_ZOUT_L | GYRO_ZOUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit Z gyro output (two's complement). | Low byte of 16-bit Z gyro output data, 2's complement. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_ZOUT_L | GYRO_ZOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Low byte of Z gyro output (GYRO_ZOUT_L)"} | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Low byte physical register"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Z gyro output (two's complement). | Low byte GYRO_ZOUT_L of 16-bit Z gyro output. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000) = **1.000000**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | GYRO_ZOUT_H + GYRO_ZOUT_L | GYRO_ZOUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"High byte of Z gyro output (GYRO_ZOUT_H)"},{"hex":"0x22","decimal":"34","bank":"","page":"","description":"Low byte of Z gyro output (GYRO_ZOUT_L)"}] | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"High byte of Z gyro output"},{"hex":"0x22","decimal":"34","bank":"","page":"","description":"Low byte of Z gyro output"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit Z gyro output data (two's complement). \| Low byte of 16-bit Z gyro output data (two's complement). | 16-bit Z gyro output data in 2's complement format. Sensor data is affected by full-scale setting register 22 and offset registers 12 to 17 before being placed into sensor registers. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0000h |
| `default_value_description` | 0.0334 | 1.0 | "" | High byte then low byte; default applies if sensor is disabled. |

\(Q(L_{16})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.933400/1.0001=\mathbf{0.933307}\).

## Extracted logical register 17: `AUX_XOUT`

v11_0 location: `registers[16]`; truth association: `registers[23] (AUX_XOUT_H)`, `registers[24] (AUX_XOUT_L)`.
Associated physical locations: 0x23 (35), 0x24 (36).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v11_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_XOUT_H` at 0x23 (35)

Locations: `truth registers[23].field_parts` ↔ `v11_0 registers[16].field_parts[0]`.

**Truth bit field 1: `AUX_XOUT_H` bits 7:0**

Locations: `truth registers[23].field_parts.bit_field` ↔ `v11_0 registers[16].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_XOUT_H | AUX_XOUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit X auxiliary (accel) output. | High byte of 16-bit X aux (accel) output data as available from aux. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_XOUT_H | AUX_XOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte of X auxiliary (accel) output (AUX_XOUT_H)"} | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte physical register"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit X auxiliary (accel) output. | High byte AUX_XOUT_H of 16-bit X auxiliary output. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

#### Field part 2: `AUX_XOUT_L` at 0x24 (36)

Locations: `truth registers[24].field_parts` ↔ `v11_0 registers[16].field_parts[1]`.

**Truth bit field 1: `AUX_XOUT_L` bits 7:0**

Locations: `truth registers[24].field_parts.bit_field` ↔ `v11_0 registers[16].field_parts[1].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_XOUT_L | AUX_XOUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit X auxiliary (accel) output. | Low byte of 16-bit X aux (accel) output data as available from aux. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_XOUT_L | AUX_XOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low byte of X auxiliary (accel) output (AUX_XOUT_L)"} | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low byte physical register"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit X auxiliary (accel) output. | Low byte AUX_XOUT_L of 16-bit X auxiliary output. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000) = **1.000000**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_XOUT_H + AUX_XOUT_L | AUX_XOUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte of X auxiliary (accel) output (AUX_XOUT_H)"},{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low byte of X auxiliary (accel) output (AUX_XOUT_L)"}] | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte of X auxiliary output"},{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low byte of X auxiliary output"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit auxiliary X-axis output (as available from auxiliary device). \| Low byte of 16-bit auxiliary X-axis output (as available from auxiliary device). | 16-bit X auxiliary accelerometer output data as available from the auxiliary device. Register map note states _H and _L names contain high and low bytes of an internal 16-bit value. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0000h |
| `default_value_description` | 0.0334 | 1.0 | "" | High byte then low byte; default applies if sensor is disabled. |

\(Q(L_{17})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.933400/1.0001=\mathbf{0.933307}\).

## Extracted logical register 18: `AUX_YOUT`

v11_0 location: `registers[17]`; truth association: `registers[25] (AUX_YOUT_H)`, `registers[26] (AUX_YOUT_L)`.
Associated physical locations: 0x25 (37), 0x26 (38).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v11_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_YOUT_H` at 0x25 (37)

Locations: `truth registers[25].field_parts` ↔ `v11_0 registers[17].field_parts[0]`.

**Truth bit field 1: `AUX_YOUT_H` bits 7:0**

Locations: `truth registers[25].field_parts.bit_field` ↔ `v11_0 registers[17].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_YOUT_H | AUX_YOUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit Y auxiliary (accel) output. | High byte of 16-bit Y aux (accel) output data as available from aux. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_YOUT_H | AUX_YOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"High byte of Y auxiliary (accel) output (AUX_YOUT_H)"} | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"High byte physical register"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Y auxiliary (accel) output. | High byte AUX_YOUT_H of 16-bit Y auxiliary output. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

#### Field part 2: `AUX_YOUT_L` at 0x26 (38)

Locations: `truth registers[26].field_parts` ↔ `v11_0 registers[17].field_parts[1]`.

**Truth bit field 1: `AUX_YOUT_L` bits 7:0**

Locations: `truth registers[26].field_parts.bit_field` ↔ `v11_0 registers[17].field_parts[1].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_YOUT_L | AUX_YOUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit Y auxiliary (accel) output. | Low byte of 16-bit Y aux (accel) output data as available from aux. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_YOUT_L | AUX_YOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Low byte of Y auxiliary (accel) output (AUX_YOUT_L)"} | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Low byte physical register"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Y auxiliary (accel) output. | Low byte AUX_YOUT_L of 16-bit Y auxiliary output. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000) = **1.000000**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_YOUT_H + AUX_YOUT_L | AUX_YOUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":"High byte of Y auxiliary (accel) output (AUX_YOUT_H)"},{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Low byte of Y auxiliary (accel) output (AUX_YOUT_L)"}] | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":"High byte of Y auxiliary output"},{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Low byte of Y auxiliary output"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit auxiliary Y-axis output (as available from auxiliary device). \| Low byte of 16-bit auxiliary Y-axis output (as available from auxiliary device). | 16-bit Y auxiliary accelerometer output data as available from the auxiliary device. Register map note states _H and _L names contain high and low bytes of an internal 16-bit value. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0000h |
| `default_value_description` | 0.0334 | 1.0 | "" | High byte then low byte; default applies if sensor is disabled. |

\(Q(L_{18})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.933400/1.0001=\mathbf{0.933307}\).

## Extracted logical register 19: `AUX_ZOUT`

v11_0 location: `registers[18]`; truth association: `registers[27] (AUX_ZOUT_H)`, `registers[28] (AUX_ZOUT_L)`.
Associated physical locations: 0x27 (39), 0x28 (40).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v11_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_ZOUT_H` at 0x27 (39)

Locations: `truth registers[27].field_parts` ↔ `v11_0 registers[18].field_parts[0]`.

**Truth bit field 1: `AUX_ZOUT_H` bits 7:0**

Locations: `truth registers[27].field_parts.bit_field` ↔ `v11_0 registers[18].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_ZOUT_H | AUX_ZOUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit Z auxiliary (accel) output. | High byte of 16-bit Z aux (accel) output data as available from aux. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_ZOUT_H | AUX_ZOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"High byte of Z auxiliary (accel) output (AUX_ZOUT_H)"} | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"High byte physical register"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Z auxiliary (accel) output. | High byte AUX_ZOUT_H of 16-bit Z auxiliary output. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

#### Field part 2: `AUX_ZOUT_L` at 0x28 (40)

Locations: `truth registers[28].field_parts` ↔ `v11_0 registers[18].field_parts[1]`.

**Truth bit field 1: `AUX_ZOUT_L` bits 7:0**

Locations: `truth registers[28].field_parts.bit_field` ↔ `v11_0 registers[18].field_parts[1].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_ZOUT_L | AUX_ZOUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit Z auxiliary (accel) output. | Low byte of 16-bit Z aux (accel) output data as available from aux. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_ZOUT_L | AUX_ZOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of Z auxiliary (accel) output (AUX_ZOUT_L)"} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte physical register"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Z auxiliary (accel) output. | Low byte AUX_ZOUT_L of 16-bit Z auxiliary output. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000) = **1.000000**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_ZOUT_H + AUX_ZOUT_L | AUX_ZOUT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"High byte of Z auxiliary (accel) output (AUX_ZOUT_H)"},{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of Z auxiliary (accel) output (AUX_ZOUT_L)"}] | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"High byte of Z auxiliary output"},{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of Z auxiliary output"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit auxiliary Z-axis output (as available from auxiliary device). \| Low byte of 16-bit auxiliary Z-axis output (as available from auxiliary device). | 16-bit Z auxiliary accelerometer output data as available from the auxiliary device. Register map note states _H and _L names contain high and low bytes of an internal 16-bit value. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0000h |
| `default_value_description` | 0.0334 | 1.0 | "" | High byte then low byte; default applies if sensor is disabled. |

\(Q(L_{19})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.933400/1.0001=\mathbf{0.933307}\).

## Extracted logical register 20: `FIFO_COUNT`

v11_0 location: `registers[19]`; truth association: `registers[29] (FIFO_COUNTH)`, `registers[30] (FIFO_COUNTL)`.
Associated physical locations: 0x3A (58), 0x3B (59).
This is an accepted equivalent multi-physical logical-register merge; Q(L) is calculated once for the complete v11_0 item.

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_COUNTH` at 0x3A (58)

Locations: `truth registers[29].field_parts` ↔ `v11_0 registers[19].field_parts[0]`.

**Truth bit field 1: `Reserved` bits 7:2**

Locations: `truth registers[29].field_parts.bit_field[0]` ↔ `v11_0 registers[19].field_parts[0].bit_field[0]`. Judgment: reserved-bit name omission/placeholder is permitted.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | - |
| `field_description` | 0.0586 | 1.0 | No function defined for these bits (reserved). | Unused high bits of FIFO_COUNTH. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `FIFO_COUNT_H` bits 1:0**

Locations: `truth registers[29].field_parts.bit_field[1]` ↔ `v11_0 registers[19].field_parts[0].bit_field[1]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_COUNT_H | FIFO_COUNT_H |
| `field_description` | 0.0586 | 1.0 | High bits of the number of bytes currently in FIFO. | High bits of number of bytes currently in FIFO. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | FIFO_COUNTH | FIFO_COUNTH |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":"FIFO byte count high part (FIFO_COUNT_H)"} | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":"High count physical register"} |
| `description` | 0.0693 | 1.0 | High portion of FIFO byte count. | High part containing FIFO_COUNT_H in bits 1:0; bits 7:2 are unused. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

#### Field part 2: `FIFO_COUNTL` at 0x3B (59)

Locations: `truth registers[30].field_parts` ↔ `v11_0 registers[19].field_parts[1]`.

**Truth bit field 1: `FIFO_COUNT_L` bits 7:0**

Locations: `truth registers[30].field_parts.bit_field` ↔ `v11_0 registers[19].field_parts[1].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_COUNT_L | FIFO_COUNT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of the number of bytes currently in FIFO. | Low byte of number of bytes currently in FIFO. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | FIFO_COUNTL | FIFO_COUNTL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":"FIFO byte count low part (FIFO_COUNT_L)"} | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":"Low count physical register"} |
| `description` | 0.0693 | 1.0 | Low portion of FIFO byte count. | Low byte FIFO_COUNT_L of number of bytes currently in FIFO. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000, 1.000000) = **1.000000**. Judgment: equivalent multi-physical logical-register grouping accepted; default value does not match the truth.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | FIFO_COUNTH + FIFO_COUNTL | FIFO_COUNT |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x3A","decimal":"58","bank":"","page":"","description":"FIFO byte count high part (FIFO_COUNT_H)"},{"hex":"0x3B","decimal":"59","bank":"","page":"","description":"FIFO byte count low part (FIFO_COUNT_L)"}] | [{"hex":"0x3A","decimal":"58","bank":"","page":"","description":"High bits of FIFO count"},{"hex":"0x3B","decimal":"59","bank":"","page":"","description":"Low byte of FIFO count"}] |
| `register_description` | 0.0564 | 1.0 | Indicates how many bytes of valid data are contained in the FIFO (high part). \| Indicates how many bytes of valid data are contained in the FIFO (low part). | Indicates how many bytes of valid data are contained in the FIFO, up to 512 bytes. If FIFO fills completely, length reads 512 and new data overwrites old data; overflow can change sensor-data alignment, and InvenSense recommends resetting FIFO with register 61. Count uses FIFO_COUNT_H bits 1:0 plus FIFO_COUNT_L byte. |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 0.0 | 00h | 0000h |
| `default_value_description` | 0.0334 | 1.0 | "" | High byte then low byte as shown in the FIFO count table. |

\(Q(L_{20})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.933400/1.0001=\mathbf{0.933307}\).

## Extracted logical register 21: `FIFO_R`

v11_0 location: `registers[20]`; truth association: `registers[31] (FIFO_R)`.
Associated physical locations: 0x3C (60).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_R` at 0x3C (60)

Locations: `truth registers[31].field_parts` ↔ `v11_0 registers[20].field_parts[0]`.

**Truth bit field 1: `FIFO_DATA` bits 7:0**

Locations: `truth registers[31].field_parts.bit_field` ↔ `v11_0 registers[20].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_DATA | FIFO_DATA |
| `field_description` | 0.0586 | 1.0 | FIFO data byte. | Contains the FIFO data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: register_name is objectively different.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 0.0 | FIFO_DATA | FIFO_R |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"FIFO data output (FIFO_DATA)"} | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Single-byte FIFO read register"} |
| `description` | 0.0693 | 1.0 | FIFO output data byte; reading this register fetches the next byte from FIFO. | Contains FIFO_DATA, the oldest FIFO byte on each read. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×0.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{0.972000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.972000) = **0.972000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | FIFO_R | FIFO_R |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"FIFO data output (FIFO_DATA)"} | [{"hex":"0x3C","decimal":"60","bank":"","page":"","description":"FIFO data output register"}] |
| `register_description` | 0.0564 | 1.0 | Output register of the FIFO. Each read returns the oldest contents of the FIFO buffer; a burst read is required to read multiple bytes. | Output register of the FIFO; each read gets the oldest contents of the FIFO buffer. Data written into FIFO is determined by FIFO enable register 18. Burst read is required for multiple bytes because any read causes auto-increment and prefetch. At least one word should remain in FIFO during reads; overflow mode acts as a circular buffer of the most recent 512 bytes and the first byte read after halting input is not valid. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.972000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{21})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.972000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.991736/1.0001=\mathbf{0.991637}\).

## Extracted logical register 22: `USER_CTRL`

v11_0 location: `registers[21]`; truth association: `registers[32] (USER_CTRL)`.
Associated physical locations: 0x3D (61).

### Bottom layer: bit fields, then field parts

#### Field part 1: `USER_CTRL` at 0x3D (61)

Locations: `truth registers[32].field_parts` ↔ `v11_0 registers[21].field_parts[0]`.

**Truth bit field 1: `Reserved` bits 7:7**

Locations: `truth registers[32].field_parts.bit_field[0]` ↔ `v11_0 registers[21].field_parts[0].bit_field[0]`. Judgment: reserved-bit name omission/placeholder is permitted.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | - |
| `field_description` | 0.0586 | 1.0 | No function defined for this bit (reserved). | Undefined bit; no function shown. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `FIFO_EN` bits 6:6**

Locations: `truth registers[32].field_parts.bit_field[1]` ↔ `v11_0 registers[21].field_parts[0].bit_field[1]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_EN | FIFO_EN |
| `field_description` | 0.0586 | 1.0 | Enable FIFO operation for sensor data. | Enable FIFO operation for sensor data. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `AUX_IF_EN` bits 5:5**

Locations: `truth registers[32].field_parts.bit_field[2]` ↔ `v11_0 registers[21].field_parts[0].bit_field[2]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_IF_EN | AUX_IF_EN |
| `field_description` | 0.0586 | 1.0 | Enable 3rd-party accelerometer interface via I²C. Clear this bit to enable bypass mode (host direct access to accel). | Enable 3rd-party accelerometer interface via I2C; clear to enable Bypass Mode for host direct access to the accelerometer. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `Reserved` bits 4:4**

Locations: `truth registers[32].field_parts.bit_field[3]` ↔ `v11_0 registers[21].field_parts[0].bit_field[3]`. Judgment: reserved-bit name omission/placeholder is permitted.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | - |
| `field_description` | 0.0586 | 1.0 | No function defined for this bit (reserved). | Undefined bit; no function shown. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 5: `AUX_IF_RST` bits 3:3**

Locations: `truth registers[32].field_parts.bit_field[4]` ↔ `v11_0 registers[21].field_parts[0].bit_field[4]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_IF_RST | AUX_IF_RST |
| `field_description` | 0.0586 | 1.0 | Reset third-party accelerometer interface function; set this only after changing AUX_IF_EN to 0. | Reset third-party accelerometer interface function; set only after changing AUX_IF_EN to 0. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 6: `Reserved` bits 2:2**

Locations: `truth registers[32].field_parts.bit_field[5]` ↔ `v11_0 registers[21].field_parts[0].bit_field[5]`. Judgment: reserved-bit name omission/placeholder is permitted.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | - |
| `field_description` | 0.0586 | 1.0 | No function defined for this bit (reserved). | Undefined bit; no function shown. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 7: `FIFO_RST` bits 1:1**

Locations: `truth registers[32].field_parts.bit_field[6]` ↔ `v11_0 registers[21].field_parts[0].bit_field[6]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_RST | FIFO_RST |
| `field_description` | 0.0586 | 1.0 | Reset FIFO function; set this to clear FIFO or when changing FIFO_EN. | Reset FIFO function; set to clear FIFO or when changing FIFO_EN. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 8: `GYRO_RST` bits 0:0**

Locations: `truth registers[32].field_parts.bit_field[7]` ↔ `v11_0 registers[21].field_parts[0].bit_field[7]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_RST | GYRO_RST |
| `field_description` | 0.0586 | 1.0 | Reset gyro analog and digital functions. | Reset gyro analog and digital functions. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | USER_CTRL | USER_CTRL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"User control (enable/reset auxiliary functions and FIFO)"} | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"Single-byte user control register"} |
| `description` | 0.0693 | 1.0 | Control and reset bits for FIFO and auxiliary interface functions. | FIFO and auxiliary interface enable/reset and gyro reset controls with reserved bits 7, 4, and 2. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | USER_CTRL | USER_CTRL |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"User control (enable/reset auxiliary functions and FIFO)"} | [{"hex":"0x3D","decimal":"61","bank":"","page":"","description":"User control register"}] |
| `register_description` | 0.0564 | 1.0 | Used to enable/disable and reset various modes and functions (FIFO, AUX I2C master interface, gyro reset). Reset bits are auto-cleared after reset. | Enables and resets FIFO, auxiliary I2C interface, and gyro functions. Reset bits are automatically cleared after the function is reset. When AUX_IF_EN=1, I2C Master Mode is enabled and ITG-3050 acts as master to the external slave; when cleared, auxiliary I2C lines are logically driven by the primary I2C bus, enabling bypass/direct host access. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{22})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 23: `PWR_MGM`

v11_0 location: `registers[22]`; truth association: `registers[33] (PWR_MGM)`.
Associated physical locations: 0x3E (62).

### Bottom layer: bit fields, then field parts

#### Field part 1: `PWR_MGM` at 0x3E (62)

Locations: `truth registers[33].field_parts` ↔ `v11_0 registers[22].field_parts[0]`.

**Truth bit field 1: `H_RESET` bits 7:7**

Locations: `truth registers[33].field_parts.bit_field[0]` ↔ `v11_0 registers[22].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | H_RESET | H_RESET |
| `field_description` | 0.0586 | 1.0 | Reset device and internal registers to the power-up-default settings. | Reset device and internal registers to the power-up-default settings. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `SLEEP` bits 6:6**

Locations: `truth registers[33].field_parts.bit_field[1]` ↔ `v11_0 registers[22].field_parts[0].bit_field[1]`. Judgment: v11_0 adds unsupported objective value codes where truth has none.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SLEEP | SLEEP |
| `field_description` | 0.0586 | 1.0 | Enable low power sleep mode. | Enable low power sleep mode; setting puts device into sleep, clearing returns to normal mode. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [] | [{"value":"1","value_description":"Low power sleep mode"},{"value":"0","value_description":"Normal mode"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 3: `STBY_XG` bits 5:5**

Locations: `truth registers[33].field_parts.bit_field[2]` ↔ `v11_0 registers[22].field_parts[0].bit_field[2]`. Judgment: v11_0 adds unsupported objective value codes where truth has none.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_XG | STBY_XG |
| `field_description` | 0.0586 | 1.0 | Put gyro X in standby mode (1=standby, 0=normal). | Put gyro X in standby mode. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [] | [{"value":"1","value_description":"Standby"},{"value":"0","value_description":"Normal"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 4: `STBY_YG` bits 4:4**

Locations: `truth registers[33].field_parts.bit_field[3]` ↔ `v11_0 registers[22].field_parts[0].bit_field[3]`. Judgment: v11_0 adds unsupported objective value codes where truth has none.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_YG | STBY_YG |
| `field_description` | 0.0586 | 1.0 | Put gyro Y in standby mode (1=standby, 0=normal). | Put gyro Y in standby mode. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [] | [{"value":"1","value_description":"Standby"},{"value":"0","value_description":"Normal"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 5: `STBY_ZG` bits 3:3**

Locations: `truth registers[33].field_parts.bit_field[4]` ↔ `v11_0 registers[22].field_parts[0].bit_field[4]`. Judgment: v11_0 adds unsupported objective value codes where truth has none.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_ZG | STBY_ZG |
| `field_description` | 0.0586 | 1.0 | Put gyro Z in standby mode (1=standby, 0=normal). | Put gyro Z in standby mode. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [] | [{"value":"1","value_description":"Standby"},{"value":"0","value_description":"Normal"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 6: `CLK_SEL` bits 2:0**

Locations: `truth registers[33].field_parts.bit_field[5]` ↔ `v11_0 registers[22].field_parts[0].bit_field[5]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | CLK_SEL | CLK_SEL |
| `field_description` | 0.0586 | 1.0 | Select device clock source. | Select device clock source. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Internal oscillator"},{"value":"1","value_description":"PLL with X Gyro reference"},{"value":"2","value_description":"PLL with Y Gyro reference"},{"value":"3","value_description":"PLL with Z Gyro reference"},{"value":"4","value_description":"PLL with external 32.768kHz reference"},{"value":"5","value_description":"PLL with external 19.2MHz reference"},{"value":"6","value_description":"Reserved"},{"value":"7","value_description":"Stop clock and synchronous reset clock state"}] | [{"value":"0","value_description":"Internal oscillator"},{"value":"1","value_description":"PLL with X Gyro reference"},{"value":"2","value_description":"PLL with Y Gyro reference"},{"value":"3","value_description":"PLL with Z Gyro reference"},{"value":"4","value_description":"PLL with external 32.768kHz reference"},{"value":"5","value_description":"PLL with external 19.2MHz reference"},{"value":"6","value_description":"Reserved"},{"value":"7","value_description":"Stop clock and synchronous reset clock state"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000, 0.790279, 0.790279, 0.790279, 0.790279, 1.000000) = **0.860186**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | v11_0 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | PWR_MGM | PWR_MGM |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Power management and clock select"} | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Single-byte power management register"} |
| `description` | 0.0693 | 1.0 | Power control bits, standby selections, and clock source selection. | H_RESET, SLEEP, gyro standby bits, and CLK_SEL clock source selection. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.860186 | truth bit-field targets | matched exact v11_0 ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.860186=\mathbf{0.956252}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.956252) = **0.956252**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | v11_0 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | PWR_MGM | PWR_MGM |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Power management and clock select"} | [{"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Power management register"}] |
| `register_description` | 0.0564 | 1.0 | Manages power control, clock source selection, standby modes, and device reset. | Manages power control, clock source selection, and master reset. SLEEP puts the device into low-power sleep where only serial interface and internal registers remain active; clearing returns to normal mode. Individual gyro standby bits can power down unused gyros. On power-up the device defaults to internal oscillator, but a gyro or external clock reference is recommended for stability. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.956252 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{23})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.956252 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.987033/1.0001=\mathbf{0.986934}\).

## 2. Ground-truth physical-register scores

For every truth physical register, \(q_R=\frac{1}{|L_R|}\sum_{L\in L_R}Q(L)\). A merged v11_0 logical register contributes its one Q(L) to each physical address it covers.

| Truth physical address | Associated extracted logical registers and Q(L) | q_R |
|---|---|---:|
| 0x00 (0) | v11_0 registers[0] `WHO_AM_I`=0.985118 | 0.985118 |
| 0x0C (12) | v11_0 registers[1] `X_OFFS`=1.000000 | 1.000000 |
| 0x0D (13) | v11_0 registers[1] `X_OFFS`=1.000000 | 1.000000 |
| 0x0E (14) | v11_0 registers[2] `Y_OFFS`=1.000000 | 1.000000 |
| 0x0F (15) | v11_0 registers[2] `Y_OFFS`=1.000000 | 1.000000 |
| 0x10 (16) | v11_0 registers[3] `Z_OFFS`=1.000000 | 1.000000 |
| 0x11 (17) | v11_0 registers[3] `Z_OFFS`=1.000000 | 1.000000 |
| 0x12 (18) | v11_0 registers[4] `FIFO_EN`=1.000000 | 1.000000 |
| 0x13 (19) | v11_0 registers[5] `AUX_VDDIO`=0.988794 | 0.988794 |
| 0x14 (20) | v11_0 registers[6] `AUX_SLV_ADDR`=0.990200 | 0.990200 |
| 0x15 (21) | v11_0 registers[7] `SMPLRT_DIV`=1.000000 | 1.000000 |
| 0x16 (22) | v11_0 registers[8] `DLPF_FS_SYNC`=1.000000 | 1.000000 |
| 0x17 (23) | v11_0 registers[9] `INT_CFG`=0.990200 | 0.990200 |
| 0x18 (24) | v11_0 registers[10] `AUX_ADDR`=1.000000 | 1.000000 |
| 0x1A (26) | v11_0 registers[11] `INT_STATUS`=0.998638 | 0.998638 |
| 0x1B (27) | v11_0 registers[12] `TEMP_OUT`=0.933307 | 0.933307 |
| 0x1C (28) | v11_0 registers[12] `TEMP_OUT`=0.933307 | 0.933307 |
| 0x1D (29) | v11_0 registers[13] `GYRO_XOUT`=0.933307 | 0.933307 |
| 0x1E (30) | v11_0 registers[13] `GYRO_XOUT`=0.933307 | 0.933307 |
| 0x1F (31) | v11_0 registers[14] `GYRO_YOUT`=0.933307 | 0.933307 |
| 0x20 (32) | v11_0 registers[14] `GYRO_YOUT`=0.933307 | 0.933307 |
| 0x21 (33) | v11_0 registers[15] `GYRO_ZOUT`=0.933307 | 0.933307 |
| 0x22 (34) | v11_0 registers[15] `GYRO_ZOUT`=0.933307 | 0.933307 |
| 0x23 (35) | v11_0 registers[16] `AUX_XOUT`=0.933307 | 0.933307 |
| 0x24 (36) | v11_0 registers[16] `AUX_XOUT`=0.933307 | 0.933307 |
| 0x25 (37) | v11_0 registers[17] `AUX_YOUT`=0.933307 | 0.933307 |
| 0x26 (38) | v11_0 registers[17] `AUX_YOUT`=0.933307 | 0.933307 |
| 0x27 (39) | v11_0 registers[18] `AUX_ZOUT`=0.933307 | 0.933307 |
| 0x28 (40) | v11_0 registers[18] `AUX_ZOUT`=0.933307 | 0.933307 |
| 0x3A (58) | v11_0 registers[19] `FIFO_COUNT`=0.933307 | 0.933307 |
| 0x3B (59) | v11_0 registers[19] `FIFO_COUNT`=0.933307 | 0.933307 |
| 0x3C (60) | v11_0 registers[20] `FIFO_R`=0.991637 | 0.991637 |
| 0x3D (61) | v11_0 registers[21] `USER_CTRL`=1.000000 | 1.000000 |
| 0x3E (62) | v11_0 registers[22] `PWR_MGM`=0.986934 | 0.986934 |

\(\sum_{R=1}^{34}q_R=\mathbf{32.864427617}\).

\(m=34,\ x=0,\ \frac{m}{m+x}=\frac{34}{34+0}=1.000000\).

Missing truth physical addresses: none.
Extra extracted physical addresses: none.

\[S_{final}=\left(\frac{10}{34}\times 32.864427617\right)\times\frac{34}{34+0}=\boxed{\mathbf{9.666008123/10}}\]

## 3. Detailed deduction inventory

The following entries are the exact scored deviations. The preceding sections contain the complete bottom-up table for every logical register, field part, and truth bit-field target.

### 3.1 Objective-fact errors and omissions

| Exact location | Field | Truth content | v11_0 content | C | Judgment |
|---|---|---|---|---:|---|
| `v11_0 registers[0].field_parts[0].bit_field[1]` | `values` | {"value":"110 100","value_description":"Power-On-Reset value of Bit6:Bit1"} | [] | 0.0 | truth value enumeration is missing from v11_0 |
| `v11_0 registers[0].field_parts[0].bit_field[1]` | `type_write_read` | R | RW | 0.0 | truth type_write_read='R', v11_0 has 'RW' |
| `v11_0 registers[0].field_parts[0].bit_field[2]` | `values` | [{"value":0,"value_description":""},{"value":1,"value_description":""}] | [] | 0.0 | truth value enumeration is missing from v11_0 |
| `v11_0 registers[5].field_parts[0].bit_field[0]` | `is_reserved` | True | False | 0.0 | is_reserved is objectively different; reserved-bit name omission/placeholder is permitted |
| `v11_0 registers[5].field_parts[0].bit_field[1]` | `values` | [] | [{"value":"1","value_description":"VDD"},{"value":"0","value_description":"VLOGIC"}] | 0.0 | v11_0 adds unsupported objective value codes where truth has none |
| `v11_0 registers[5].field_parts[0].bit_field[2]` | `is_reserved` | True | False | 0.0 | is_reserved is objectively different; reserved-bit name omission/placeholder is permitted |
| `v11_0 registers[6].field_parts[0].bit_field[0]` | `values` | [] | [{"value":"1","value_description":"Reference clock output is provided at CLKOUT pin"},{"value":"0","value_description":"Function is disabled"}] | 0.0 | v11_0 adds unsupported objective value codes where truth has none |
| `v11_0 registers[9].field_parts[0].bit_field[0]` | `values` | [] | [{"value":"1","value_description":"Active low"},{"value":"0","value_description":"Active high"}] | 0.0 | v11_0 adds unsupported objective value codes where truth has none |
| `v11_0 registers[9].field_parts[0].bit_field[1]` | `values` | [] | [{"value":"1","value_description":"Open drain"},{"value":"0","value_description":"Push-pull"}] | 0.0 | v11_0 adds unsupported objective value codes where truth has none |
| `v11_0 registers[9].field_parts[0].bit_field[2]` | `values` | [] | [{"value":"1","value_description":"Latch until interrupt is cleared"},{"value":"0","value_description":"50us pulse"}] | 0.0 | v11_0 adds unsupported objective value codes where truth has none |
| `v11_0 registers[9].field_parts[0].bit_field[3]` | `values` | [] | [{"value":"1","value_description":"Clear by reading any register"},{"value":"0","value_description":"Clear by reading interrupt status register (26) only"}] | 0.0 | v11_0 adds unsupported objective value codes where truth has none |
| `v11_0 registers[11].field_parts[0].bit_field[0]` | `type_write_read` | R | "" | 0.0 | truth type_write_read='R', v11_0 has '' |
| `v11_0 registers[12]` | `default_value` | 00h | 0000h | 0.0 | default value does not match the truth |
| `v11_0 registers[13]` | `default_value` | 00h | 0000h | 0.0 | default value does not match the truth |
| `v11_0 registers[14]` | `default_value` | 00h | 0000h | 0.0 | default value does not match the truth |
| `v11_0 registers[15]` | `default_value` | 00h | 0000h | 0.0 | default value does not match the truth |
| `v11_0 registers[16]` | `default_value` | 00h | 0000h | 0.0 | default value does not match the truth |
| `v11_0 registers[17]` | `default_value` | 00h | 0000h | 0.0 | default value does not match the truth |
| `v11_0 registers[18]` | `default_value` | 00h | 0000h | 0.0 | default value does not match the truth |
| `v11_0 registers[19]` | `default_value` | 00h | 0000h | 0.0 | default value does not match the truth |
| `v11_0 registers[20].field_parts[0]` | `register_name` | FIFO_DATA | FIFO_R | 0.0 | register_name is objectively different |
| `v11_0 registers[22].field_parts[0].bit_field[1]` | `values` | [] | [{"value":"1","value_description":"Low power sleep mode"},{"value":"0","value_description":"Normal mode"}] | 0.0 | v11_0 adds unsupported objective value codes where truth has none |
| `v11_0 registers[22].field_parts[0].bit_field[2]` | `values` | [] | [{"value":"1","value_description":"Standby"},{"value":"0","value_description":"Normal"}] | 0.0 | v11_0 adds unsupported objective value codes where truth has none |
| `v11_0 registers[22].field_parts[0].bit_field[3]` | `values` | [] | [{"value":"1","value_description":"Standby"},{"value":"0","value_description":"Normal"}] | 0.0 | v11_0 adds unsupported objective value codes where truth has none |
| `v11_0 registers[22].field_parts[0].bit_field[4]` | `values` | [] | [{"value":"1","value_description":"Standby"},{"value":"0","value_description":"Normal"}] | 0.0 | v11_0 adds unsupported objective value codes where truth has none |

### 3.2 Unmatched v11_0 bit ranges

None.

### 3.3 Description differences accepted under the requested leniency

Nonempty descriptions whose meaning is preserved are not deducted; missing descriptions remain in section 3.1.

| Truth location | v11_0 location | Field | Truth content | v11_0 content | Result |
|---|---|---|---|---|---|
| `truth registers[0].field_parts.bit_field[0]` | `v11_0 registers[0].field_parts[0].bit_field[0]` | `field_description` | Setting this bit disables I²C access mode. | Setting this bit disables I2C access mode. | C=1.0, semantically equivalent |
| `truth registers[0].field_parts.bit_field[1]` | `v11_0 registers[0].field_parts[0].bit_field[1]` | `field_description` | Contains the 6-bit I²C address of the device. The Power-On-Reset value of Bit6:Bit1 is 110 100. | Contains the 6-bit I2C address of the device. Power-On-Reset value of Bit6:Bit1 is 110100. | C=1.0, semantically equivalent |
| `truth registers[0].field_parts.bit_field[2]` | `v11_0 registers[0].field_parts[0].bit_field[2]` | `field_description` | Bit0 is reserved (may be 0 or 1). | Bit0 is reserved and may be 0 or 1. | C=1.0, semantically equivalent |
| `truth registers[0].field_parts` | `v11_0 registers[0].field_parts[0]` | `description` | Device ID and I²C interface control | Contains I2C interface disable bit and 6-bit device I2C address ID. | C=1.0, semantically equivalent |
| `truth registers[0].register_description` | `v11_0 registers[0].register_description` | `register_description` | This register is used to verify the identity of the device, and to enable/disable the I²C interface. | Verifies the identity of the device and enables/disables the I2C interface. ID contains the 6-bit I2C address of the device; I2C_IF_DIS disables I2C access mode. | C=1.0, semantically equivalent |
| `truth registers[1].field_parts.bit_field` | `v11_0 registers[1].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit X gyro offset (two's complement). | High byte of 16-bit X gyro offset, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[1].field_parts` | `v11_0 registers[1].field_parts[0]` | `description` | High byte of 16-bit X gyro offset (two's complement). | High byte X_OFFS_H of the 16-bit X gyro offset. | C=1.0, semantically equivalent |
| `truth registers[2].field_parts.bit_field` | `v11_0 registers[1].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit X gyro offset (two's complement). | Low byte of 16-bit X gyro offset, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[2].field_parts` | `v11_0 registers[1].field_parts[1]` | `description` | Low byte of 16-bit X gyro offset (two's complement). | Low byte X_OFFS_L of the 16-bit X gyro offset. | C=1.0, semantically equivalent |
| `truth registers[1].register_description` | `v11_0 registers[1].register_description` | `register_description` | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). \| These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | 16-bit X gyro offset in 2's complement format. Offset values are subtracted from gyro sensor values before the sensor registers; used to remove DC bias from sensor outputs. Register map physical names are X_OFFS_USRH and X_OFFS_USRL; detailed parameter name is X_OFFS_H/L. | C=1.0, semantically equivalent |
| `truth registers[3].field_parts.bit_field` | `v11_0 registers[2].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Y gyro offset (two's complement). | High byte of 16-bit Y gyro offset, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[3].field_parts` | `v11_0 registers[2].field_parts[0]` | `description` | High byte of 16-bit Y gyro offset (two's complement). | High byte Y_OFFS_H of the 16-bit Y gyro offset. | C=1.0, semantically equivalent |
| `truth registers[4].field_parts.bit_field` | `v11_0 registers[2].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit Y gyro offset (two's complement). | Low byte of 16-bit Y gyro offset, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[4].field_parts` | `v11_0 registers[2].field_parts[1]` | `description` | Low byte of 16-bit Y gyro offset (two's complement). | Low byte Y_OFFS_L of the 16-bit Y gyro offset. | C=1.0, semantically equivalent |
| `truth registers[3].register_description` | `v11_0 registers[2].register_description` | `register_description` | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). \| These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | 16-bit Y gyro offset in 2's complement format. Offset values are subtracted from gyro sensor values before the sensor registers; used to remove DC bias from sensor outputs. Register map physical names are Y_OFFS_USRH and Y_OFFS_USRL; detailed parameter name is Y_OFFS_H/L. | C=1.0, semantically equivalent |
| `truth registers[5].field_parts.bit_field` | `v11_0 registers[3].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Z gyro offset (two's complement). | High byte of 16-bit Z gyro offset, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[5].field_parts` | `v11_0 registers[3].field_parts[0]` | `description` | High byte of 16-bit Z gyro offset (two's complement). | High byte Z_OFFS_H of the 16-bit Z gyro offset. | C=1.0, semantically equivalent |
| `truth registers[6].field_parts.bit_field` | `v11_0 registers[3].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit Z gyro offset (two's complement). | Low byte of 16-bit Z gyro offset, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[6].field_parts` | `v11_0 registers[3].field_parts[1]` | `description` | Low byte of 16-bit Z gyro offset (two's complement). | Low byte Z_OFFS_L of the 16-bit Z gyro offset. | C=1.0, semantically equivalent |
| `truth registers[5].register_description` | `v11_0 registers[3].register_description` | `register_description` | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). \| These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | 16-bit Z gyro offset in 2's complement format. Offset values are subtracted from gyro sensor values before the sensor registers; used to remove DC bias from sensor outputs. Register map physical names are Z_OFFS_USRH and Z_OFFS_USRL; detailed parameter name is Z_OFFS_H/L. | C=1.0, semantically equivalent |
| `truth registers[7].field_parts` | `v11_0 registers[4].field_parts[0]` | `description` | Enable selection for data inserted into FIFO; each bit inserts the listed data into the FIFO when set. | Selects temperature, gyro, auxiliary accel, and footer words for FIFO insertion. | C=1.0, semantically equivalent |
| `truth registers[7].register_description` | `v11_0 registers[4].register_description` | `register_description` | Determines what data goes into the ITG-3050 FIFO (512 byte FIFO); sensor data is automatically placed into the FIFO after each ADC sampling period. | Determines what data goes into the 512-byte ITG-3050 FIFO. Sensor data is placed into FIFO after each ADC sampling period; ADC sample rate is controlled by register 21. FIFO insertion order is MSB to LSB and two bytes are used per reading. FIFO_FOOTER is described with register 60. | C=1.0, semantically equivalent |
| `truth registers[8].field_parts.bit_field[0]` | `v11_0 registers[5].field_parts[0].bit_field[0]` | `field_description` | Load zeros into bits 7..3 (must be 0). | Load zeros into Bits 3-7. | C=1.0, semantically equivalent |
| `truth registers[8].field_parts.bit_field[1]` | `v11_0 registers[5].field_parts[0].bit_field[1]` | `field_description` | I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1=VDD, 0=VLOGIC. | I/O logic levels for secondary I2C bus clock and data lines AUX_CL and AUX_DA. | C=1.0, semantically equivalent |
| `truth registers[8].field_parts.bit_field[2]` | `v11_0 registers[5].field_parts[0].bit_field[2]` | `field_description` | Load zeros into bits 1..0 (must be 0). | Load zeros into Bits 0 and 1. | C=1.0, semantically equivalent |
| `truth registers[8].field_parts` | `v11_0 registers[5].field_parts[0]` | `description` | I/O logic level selection for the secondary I²C bus lines; other bits must be written as zeros. | Contains AUX_VDDIO at bit 2; other shown bits are fixed zero. | C=1.0, semantically equivalent |
| `truth registers[8].register_description` | `v11_0 registers[5].register_description` | `register_description` | Determines the I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1 = VDD, 0 = VLOGIC. | Determines the I/O logic levels for the secondary I2C bus clock and data lines AUX_CL and AUX_DA. | C=1.0, semantically equivalent |
| `truth registers[9].field_parts.bit_field[0]` | `v11_0 registers[6].field_parts[0].bit_field[0]` | `field_description` | 1 = reference clock output is provided at CLKOUT pin; 0 = function disabled. | Controls reference clock output at CLKOUT pin. | C=1.0, semantically equivalent |
| `truth registers[9].field_parts.bit_field[1]` | `v11_0 registers[6].field_parts[0].bit_field[1]` | `field_description` | Contains the I²C address of the external accelerometer device (bits 6:0). | Contains the I2C address of the external accelerometer device; can be changed by writing this register. | C=1.0, semantically equivalent |
| `truth registers[9].field_parts` | `v11_0 registers[6].field_parts[0]` | `description` | CLKOUT enable and auxiliary device address (AUX_ID). | CLKOUT_EN at bit 7 and AUX_ID 7-bit address at bits 6:0. | C=1.0, semantically equivalent |
| `truth registers[9].register_description` | `v11_0 registers[6].register_description` | `register_description` | Contains the 7-bit slave address of the external accelerometer device and the CLKOUT enable bit. Used by the ITG-3050 when acting as I²C master for the auxiliary sensor. | Contains the 7-bit slave address of the external accelerometer and CLKOUT enable. The address is used to access the accel device so its sensor reading can be automatically read each sample period. For the interface to be active, AUX_IF_EN in User Control register 61 must be set; after changing this register, the accel interface must be reset via register 61. | C=1.0, semantically equivalent |
| `truth registers[10].field_parts.bit_field` | `v11_0 registers[7].field_parts[0].bit_field[0]` | `field_description` | Sample rate divider. F_sample = F_internal / (divider + 1). | Sample rate divider: 0 to 255. | C=1.0, semantically equivalent |
| `truth registers[10].field_parts` | `v11_0 registers[7].field_parts[0]` | `description` | Sample rate divider (0-255). | 8-bit sample rate divider. | C=1.0, semantically equivalent |
| `truth registers[10].register_description` | `v11_0 registers[7].register_description` | `register_description` | Determines the sample rate of the ITG-3050 gyros. F_sample = F_internal / (divider + 1), where F_internal is either 1kHz or 8kHz (set by DLPF_CFG). | Determines gyro sample rate. Internal sampling is 1 kHz or 8 kHz depending on DLPF_CFG in register 22; output sample rate is Fsample = Finternal / (divider + 1). Example: Finternal=1 kHz and divider=7 gives 125 Hz or 8 ms per sample. | C=1.0, semantically equivalent |
| `truth registers[11].field_parts.bit_field[2]` | `v11_0 registers[8].field_parts[0].bit_field[2]` | `field_description` | Digital low pass filter configuration; also determines internal analog sampling rate. | Digital low pass filter configuration; also determines analog sample rate. Additional gain and phase response plots are shown in the DLPF characteristics figure and should be retrieved if filter response details are needed. | C=1.0, semantically equivalent |
| `truth registers[11].field_parts` | `v11_0 registers[8].field_parts[0]` | `description` | EXT_SYNC_SET (bits7:5), FS_SEL (bits4:3), DLPF_CFG (bits2:0). | EXT_SYNC_SET bits 7:5, FS_SEL bits 4:3, DLPF_CFG bits 2:0. | C=1.0, semantically equivalent |
| `truth registers[11].register_description` | `v11_0 registers[8].register_description` | `register_description` | Configures external sync routing (EXT_SYNC_SET), full-scale range (FS_SEL), and digital low-pass filter (DLPF_CFG). | Configures external frame sync routing, gyro full-scale range, and digital low-pass filter. EXT_SYNC_SET routes FSYNC input state into the LSB of a selected sensor low-byte register. FS_SEL selects gyro full-scale range. DLPF_CFG sets low-pass bandwidth and internal analog sample rate used by SMPLRT_DIV. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[0]` | `v11_0 registers[9].field_parts[0].bit_field[0]` | `field_description` | Logic level for INT output pin - 1=active low, 0=active high. | Logic level for INT output pin. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[1]` | `v11_0 registers[9].field_parts[0].bit_field[1]` | `field_description` | Drive type for INT output pin - 1=open drain, 0=push-pull. | Drive type for INT output pin. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[2]` | `v11_0 registers[9].field_parts[0].bit_field[2]` | `field_description` | "Latch mode - 1=latch until interrupt is cleared, 0=50\u0000us pulse." | Latch mode for interrupt output. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[3]` | `v11_0 registers[9].field_parts[0].bit_field[3]` | `field_description` | Interrupt status register clear method - 1=clear by reading any register, 0=clear by reading interrupt status register (26) only. | Interrupt status register clear method. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[4]` | `v11_0 registers[9].field_parts[0].bit_field[4]` | `field_description` | No function defined for this bit (reserved). | Undefined bit; set to zero for future compatibility. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[6]` | `v11_0 registers[9].field_parts[0].bit_field[6]` | `field_description` | No function defined for this bit (reserved). | Undefined bit; set to zero for future compatibility. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[7]` | `v11_0 registers[9].field_parts[0].bit_field[7]` | `field_description` | Enable interrupt when data is available (raw data ready). | Enable interrupt when data is available. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts` | `v11_0 registers[9].field_parts[0]` | `description` | Interrupt pin configuration, latch mode, and interrupt enables. | Interrupt pin configuration, clear method, and enable bits with reserved bits 3 and 1. | C=1.0, semantically equivalent |
| `truth registers[12].register_description` | `v11_0 registers[9].register_description` | `register_description` | Configures the interrupt operation: INT pin polarity and drive type, latch/clear behavior, and which sources generate interrupts. | Configures interrupt operation: INT output pin level and drive type, interrupt latch/clear method, and interrupt trigger enables. If LATCH_INT_EN=1, INT is held active until interrupt status is cleared. RAW_RDY_EN is recommended when the application must read every sample. | C=1.0, semantically equivalent |
| `truth registers[13].field_parts.bit_field` | `v11_0 registers[10].field_parts[0].bit_field[0]` | `field_description` | Burst-mode read starting address for external accelerometer attached to secondary I2C bus. | Burst-mode read starting address for external accelerometer attached to secondary I2C bus; starting address the ITG-3050 could use to read from. | C=1.0, semantically equivalent |
| `truth registers[13].field_parts` | `v11_0 registers[10].field_parts[0]` | `description` | Burst-mode read starting address for external accelerometer (BURST_ADDR). | Burst-mode read starting address for external accelerometer on secondary I2C bus. | C=1.0, semantically equivalent |
| `truth registers[13].register_description` | `v11_0 registers[10].register_description` | `register_description` | Configures the burst-mode-read starting address for an accelerometer attached to the secondary I2C bus of the ITG-3050. | Configures the burst-mode-read starting address for an accelerometer attached to the secondary I2C bus of the ITG-3050. Detailed section identifies this register as read only. | C=1.0, semantically equivalent |
| `truth registers[14].field_parts.bit_field[0]` | `v11_0 registers[11].field_parts[0].bit_field[0]` | `field_description` | No function defined for these bits (reserved). | Undefined bits; no function shown. | C=1.0, semantically equivalent |
| `truth registers[14].field_parts.bit_field[2]` | `v11_0 registers[11].field_parts[0].bit_field[2]` | `field_description` | No function defined for this bit (reserved). | Undefined bit; no function shown. | C=1.0, semantically equivalent |
| `truth registers[14].field_parts` | `v11_0 registers[11].field_parts[0]` | `description` | Interrupt status bits. | Status bits ITG_RDY and RAW_DATA_RDY with other bits reserved. | C=1.0, semantically equivalent |
| `truth registers[14].register_description` | `v11_0 registers[11].register_description` | `register_description` | Indicates the status of interrupt sources. Bits are set when corresponding interrupt sources are triggered. Interrupt status bits are cleared as determined by INT_ANYRD_2CLEAR. | Determines ITG-3050 interrupt status. When an interrupt source triggers, the corresponding bit is set; INT pin polarity and latch type do not affect status bits. RAW_DATA_RDY indicates new sensor data in sensor registers 27 to 34 or FIFO register 60. Status bits clear as determined by INT_ANYRD_2CLEAR in register 23. | C=1.0, semantically equivalent |
| `truth registers[15].field_parts.bit_field` | `v11_0 registers[12].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit temperature data (two's complement). | High byte of 16-bit temperature data, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[15].field_parts` | `v11_0 registers[12].field_parts[0]` | `description` | High byte of 16-bit temperature data (two's complement). | High byte TEMP_OUT_H of 16-bit temperature data. | C=1.0, semantically equivalent |
| `truth registers[16].field_parts.bit_field` | `v11_0 registers[12].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit temperature data (two's complement). | Low byte of 16-bit temperature data, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[16].field_parts` | `v11_0 registers[12].field_parts[1]` | `description` | Low byte of 16-bit temperature data (two's complement). | Low byte TEMP_OUT_L of 16-bit temperature data. | C=1.0, semantically equivalent |
| `truth registers[15].register_description` | `v11_0 registers[12].register_description` | `register_description` | High byte of 16-bit temperature data (two's complement). \| Low byte of 16-bit temperature data (two's complement). | 16-bit temperature output data in 2's complement format. Sensor data is manipulated by full-scale setting register 22 and offset registers 12 to 17 before being placed into sensor registers; use interrupt function to determine when new data is available. | C=1.0, semantically equivalent |
| `truth registers[17].field_parts.bit_field` | `v11_0 registers[13].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit X gyro output (two's complement). | High byte of 16-bit X gyro output data, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[17].field_parts` | `v11_0 registers[13].field_parts[0]` | `description` | High byte of 16-bit X gyro output (two's complement). | High byte GYRO_XOUT_H of 16-bit X gyro output. | C=1.0, semantically equivalent |
| `truth registers[18].field_parts.bit_field` | `v11_0 registers[13].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit X gyro output (two's complement). | Low byte of 16-bit X gyro output data, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[18].field_parts` | `v11_0 registers[13].field_parts[1]` | `description` | Low byte of 16-bit X gyro output (two's complement). | Low byte GYRO_XOUT_L of 16-bit X gyro output. | C=1.0, semantically equivalent |
| `truth registers[17].register_description` | `v11_0 registers[13].register_description` | `register_description` | High byte of 16-bit X gyro output data (two's complement). \| Low byte of 16-bit X gyro output data (two's complement). | 16-bit X gyro output data in 2's complement format. Sensor data is affected by full-scale setting register 22 and offset registers 12 to 17 before being placed into sensor registers. | C=1.0, semantically equivalent |
| `truth registers[19].field_parts.bit_field` | `v11_0 registers[14].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Y gyro output (two's complement). | High byte of 16-bit Y gyro output data, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[19].field_parts` | `v11_0 registers[14].field_parts[0]` | `description` | High byte of 16-bit Y gyro output (two's complement). | High byte GYRO_YOUT_H of 16-bit Y gyro output. | C=1.0, semantically equivalent |
| `truth registers[20].field_parts.bit_field` | `v11_0 registers[14].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit Y gyro output (two's complement). | Low byte of 16-bit Y gyro output data, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[20].field_parts` | `v11_0 registers[14].field_parts[1]` | `description` | Low byte of 16-bit Y gyro output (two's complement). | Low byte GYRO_YOUT_L of 16-bit Y gyro output. | C=1.0, semantically equivalent |
| `truth registers[19].register_description` | `v11_0 registers[14].register_description` | `register_description` | High byte of 16-bit Y gyro output data (two's complement). \| Low byte of 16-bit Y gyro output data (two's complement). | 16-bit Y gyro output data in 2's complement format. Sensor data is affected by full-scale setting register 22 and offset registers 12 to 17 before being placed into sensor registers. | C=1.0, semantically equivalent |
| `truth registers[21].field_parts.bit_field` | `v11_0 registers[15].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Z gyro output (two's complement). | High byte of 16-bit Z gyro output data, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[21].field_parts` | `v11_0 registers[15].field_parts[0]` | `description` | High byte of 16-bit Z gyro output (two's complement). | High byte GYRO_ZOUT_H of 16-bit Z gyro output. | C=1.0, semantically equivalent |
| `truth registers[22].field_parts.bit_field` | `v11_0 registers[15].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit Z gyro output (two's complement). | Low byte of 16-bit Z gyro output data, 2's complement. | C=1.0, semantically equivalent |
| `truth registers[22].field_parts` | `v11_0 registers[15].field_parts[1]` | `description` | Low byte of 16-bit Z gyro output (two's complement). | Low byte GYRO_ZOUT_L of 16-bit Z gyro output. | C=1.0, semantically equivalent |
| `truth registers[21].register_description` | `v11_0 registers[15].register_description` | `register_description` | High byte of 16-bit Z gyro output data (two's complement). \| Low byte of 16-bit Z gyro output data (two's complement). | 16-bit Z gyro output data in 2's complement format. Sensor data is affected by full-scale setting register 22 and offset registers 12 to 17 before being placed into sensor registers. | C=1.0, semantically equivalent |
| `truth registers[23].field_parts.bit_field` | `v11_0 registers[16].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit X auxiliary (accel) output. | High byte of 16-bit X aux (accel) output data as available from aux. | C=1.0, semantically equivalent |
| `truth registers[23].field_parts` | `v11_0 registers[16].field_parts[0]` | `description` | High byte of 16-bit X auxiliary (accel) output. | High byte AUX_XOUT_H of 16-bit X auxiliary output. | C=1.0, semantically equivalent |
| `truth registers[24].field_parts.bit_field` | `v11_0 registers[16].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit X auxiliary (accel) output. | Low byte of 16-bit X aux (accel) output data as available from aux. | C=1.0, semantically equivalent |
| `truth registers[24].field_parts` | `v11_0 registers[16].field_parts[1]` | `description` | Low byte of 16-bit X auxiliary (accel) output. | Low byte AUX_XOUT_L of 16-bit X auxiliary output. | C=1.0, semantically equivalent |
| `truth registers[23].register_description` | `v11_0 registers[16].register_description` | `register_description` | High byte of 16-bit auxiliary X-axis output (as available from auxiliary device). \| Low byte of 16-bit auxiliary X-axis output (as available from auxiliary device). | 16-bit X auxiliary accelerometer output data as available from the auxiliary device. Register map note states _H and _L names contain high and low bytes of an internal 16-bit value. | C=1.0, semantically equivalent |
| `truth registers[25].field_parts.bit_field` | `v11_0 registers[17].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Y auxiliary (accel) output. | High byte of 16-bit Y aux (accel) output data as available from aux. | C=1.0, semantically equivalent |
| `truth registers[25].field_parts` | `v11_0 registers[17].field_parts[0]` | `description` | High byte of 16-bit Y auxiliary (accel) output. | High byte AUX_YOUT_H of 16-bit Y auxiliary output. | C=1.0, semantically equivalent |
| `truth registers[26].field_parts.bit_field` | `v11_0 registers[17].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit Y auxiliary (accel) output. | Low byte of 16-bit Y aux (accel) output data as available from aux. | C=1.0, semantically equivalent |
| `truth registers[26].field_parts` | `v11_0 registers[17].field_parts[1]` | `description` | Low byte of 16-bit Y auxiliary (accel) output. | Low byte AUX_YOUT_L of 16-bit Y auxiliary output. | C=1.0, semantically equivalent |
| `truth registers[25].register_description` | `v11_0 registers[17].register_description` | `register_description` | High byte of 16-bit auxiliary Y-axis output (as available from auxiliary device). \| Low byte of 16-bit auxiliary Y-axis output (as available from auxiliary device). | 16-bit Y auxiliary accelerometer output data as available from the auxiliary device. Register map note states _H and _L names contain high and low bytes of an internal 16-bit value. | C=1.0, semantically equivalent |
| `truth registers[27].field_parts.bit_field` | `v11_0 registers[18].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Z auxiliary (accel) output. | High byte of 16-bit Z aux (accel) output data as available from aux. | C=1.0, semantically equivalent |
| `truth registers[27].field_parts` | `v11_0 registers[18].field_parts[0]` | `description` | High byte of 16-bit Z auxiliary (accel) output. | High byte AUX_ZOUT_H of 16-bit Z auxiliary output. | C=1.0, semantically equivalent |
| `truth registers[28].field_parts.bit_field` | `v11_0 registers[18].field_parts[1].bit_field[0]` | `field_description` | Low byte of 16-bit Z auxiliary (accel) output. | Low byte of 16-bit Z aux (accel) output data as available from aux. | C=1.0, semantically equivalent |
| `truth registers[28].field_parts` | `v11_0 registers[18].field_parts[1]` | `description` | Low byte of 16-bit Z auxiliary (accel) output. | Low byte AUX_ZOUT_L of 16-bit Z auxiliary output. | C=1.0, semantically equivalent |
| `truth registers[27].register_description` | `v11_0 registers[18].register_description` | `register_description` | High byte of 16-bit auxiliary Z-axis output (as available from auxiliary device). \| Low byte of 16-bit auxiliary Z-axis output (as available from auxiliary device). | 16-bit Z auxiliary accelerometer output data as available from the auxiliary device. Register map note states _H and _L names contain high and low bytes of an internal 16-bit value. | C=1.0, semantically equivalent |
| `truth registers[29].field_parts.bit_field[0]` | `v11_0 registers[19].field_parts[0].bit_field[0]` | `field_description` | No function defined for these bits (reserved). | Unused high bits of FIFO_COUNTH. | C=1.0, semantically equivalent |
| `truth registers[29].field_parts.bit_field[1]` | `v11_0 registers[19].field_parts[0].bit_field[1]` | `field_description` | High bits of the number of bytes currently in FIFO. | High bits of number of bytes currently in FIFO. | C=1.0, semantically equivalent |
| `truth registers[29].field_parts` | `v11_0 registers[19].field_parts[0]` | `description` | High portion of FIFO byte count. | High part containing FIFO_COUNT_H in bits 1:0; bits 7:2 are unused. | C=1.0, semantically equivalent |
| `truth registers[30].field_parts.bit_field` | `v11_0 registers[19].field_parts[1].bit_field[0]` | `field_description` | Low byte of the number of bytes currently in FIFO. | Low byte of number of bytes currently in FIFO. | C=1.0, semantically equivalent |
| `truth registers[30].field_parts` | `v11_0 registers[19].field_parts[1]` | `description` | Low portion of FIFO byte count. | Low byte FIFO_COUNT_L of number of bytes currently in FIFO. | C=1.0, semantically equivalent |
| `truth registers[29].register_description` | `v11_0 registers[19].register_description` | `register_description` | Indicates how many bytes of valid data are contained in the FIFO (high part). \| Indicates how many bytes of valid data are contained in the FIFO (low part). | Indicates how many bytes of valid data are contained in the FIFO, up to 512 bytes. If FIFO fills completely, length reads 512 and new data overwrites old data; overflow can change sensor-data alignment, and InvenSense recommends resetting FIFO with register 61. Count uses FIFO_COUNT_H bits 1:0 plus FIFO_COUNT_L byte. | C=1.0, semantically equivalent |
| `truth registers[31].field_parts.bit_field` | `v11_0 registers[20].field_parts[0].bit_field[0]` | `field_description` | FIFO data byte. | Contains the FIFO data. | C=1.0, semantically equivalent |
| `truth registers[31].field_parts` | `v11_0 registers[20].field_parts[0]` | `description` | FIFO output data byte; reading this register fetches the next byte from FIFO. | Contains FIFO_DATA, the oldest FIFO byte on each read. | C=1.0, semantically equivalent |
| `truth registers[31].register_description` | `v11_0 registers[20].register_description` | `register_description` | Output register of the FIFO. Each read returns the oldest contents of the FIFO buffer; a burst read is required to read multiple bytes. | Output register of the FIFO; each read gets the oldest contents of the FIFO buffer. Data written into FIFO is determined by FIFO enable register 18. Burst read is required for multiple bytes because any read causes auto-increment and prefetch. At least one word should remain in FIFO during reads; overflow mode acts as a circular buffer of the most recent 512 bytes and the first byte read after halting input is not valid. | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[0]` | `v11_0 registers[21].field_parts[0].bit_field[0]` | `field_description` | No function defined for this bit (reserved). | Undefined bit; no function shown. | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[2]` | `v11_0 registers[21].field_parts[0].bit_field[2]` | `field_description` | Enable 3rd-party accelerometer interface via I²C. Clear this bit to enable bypass mode (host direct access to accel). | Enable 3rd-party accelerometer interface via I2C; clear to enable Bypass Mode for host direct access to the accelerometer. | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[3]` | `v11_0 registers[21].field_parts[0].bit_field[3]` | `field_description` | No function defined for this bit (reserved). | Undefined bit; no function shown. | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[4]` | `v11_0 registers[21].field_parts[0].bit_field[4]` | `field_description` | Reset third-party accelerometer interface function; set this only after changing AUX_IF_EN to 0. | Reset third-party accelerometer interface function; set only after changing AUX_IF_EN to 0. | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[5]` | `v11_0 registers[21].field_parts[0].bit_field[5]` | `field_description` | No function defined for this bit (reserved). | Undefined bit; no function shown. | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[6]` | `v11_0 registers[21].field_parts[0].bit_field[6]` | `field_description` | Reset FIFO function; set this to clear FIFO or when changing FIFO_EN. | Reset FIFO function; set to clear FIFO or when changing FIFO_EN. | C=1.0, semantically equivalent |
| `truth registers[32].field_parts` | `v11_0 registers[21].field_parts[0]` | `description` | Control and reset bits for FIFO and auxiliary interface functions. | FIFO and auxiliary interface enable/reset and gyro reset controls with reserved bits 7, 4, and 2. | C=1.0, semantically equivalent |
| `truth registers[32].register_description` | `v11_0 registers[21].register_description` | `register_description` | Used to enable/disable and reset various modes and functions (FIFO, AUX I2C master interface, gyro reset). Reset bits are auto-cleared after reset. | Enables and resets FIFO, auxiliary I2C interface, and gyro functions. Reset bits are automatically cleared after the function is reset. When AUX_IF_EN=1, I2C Master Mode is enabled and ITG-3050 acts as master to the external slave; when cleared, auxiliary I2C lines are logically driven by the primary I2C bus, enabling bypass/direct host access. | C=1.0, semantically equivalent |
| `truth registers[33].field_parts.bit_field[1]` | `v11_0 registers[22].field_parts[0].bit_field[1]` | `field_description` | Enable low power sleep mode. | Enable low power sleep mode; setting puts device into sleep, clearing returns to normal mode. | C=1.0, semantically equivalent |
| `truth registers[33].field_parts.bit_field[2]` | `v11_0 registers[22].field_parts[0].bit_field[2]` | `field_description` | Put gyro X in standby mode (1=standby, 0=normal). | Put gyro X in standby mode. | C=1.0, semantically equivalent |
| `truth registers[33].field_parts.bit_field[3]` | `v11_0 registers[22].field_parts[0].bit_field[3]` | `field_description` | Put gyro Y in standby mode (1=standby, 0=normal). | Put gyro Y in standby mode. | C=1.0, semantically equivalent |
| `truth registers[33].field_parts.bit_field[4]` | `v11_0 registers[22].field_parts[0].bit_field[4]` | `field_description` | Put gyro Z in standby mode (1=standby, 0=normal). | Put gyro Z in standby mode. | C=1.0, semantically equivalent |
| `truth registers[33].field_parts` | `v11_0 registers[22].field_parts[0]` | `description` | Power control bits, standby selections, and clock source selection. | H_RESET, SLEEP, gyro standby bits, and CLK_SEL clock source selection. | C=1.0, semantically equivalent |
| `truth registers[33].register_description` | `v11_0 registers[22].register_description` | `register_description` | Manages power control, clock source selection, standby modes, and device reset. | Manages power control, clock source selection, and master reset. SLEEP puts the device into low-power sleep where only serial interface and internal registers remain active; clearing returns to normal mode. Individual gyro standby bits can power down unused gyros. On power-up the device defaults to internal oscillator, but a gyro or external clock reference is recommended for stability. | C=1.0, semantically equivalent |

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
- No unmatched extracted bit ranges were found; every extracted bit field matched an exact truth bit_start/bit_end range.
- Added v11_0 value enumerations on fields whose truth values are empty are objective unsupported facts and are scored as C=0 in section 3.1.
- Bit-field type_write_read is C=1 when both sides are empty; one-sided or concrete mismatches remain strict. The concrete truth type on INT_STATUS reserved bits is also absent from any exact v11_0 target.

