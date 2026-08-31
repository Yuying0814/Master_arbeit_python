# ITG3050 without detailed score — revised AGENTS.md rules

## 1. Scoring basis

- `n=34`, based on unique truth physical keys `(numeric address, bank, page)`; `physical_address.hex` and `physical_address.decimal` are normalized as the same address.
- Every one of the 34 extracted without logical registers is calculated independently from its truth physical targets: bit fields → field part → logical register `Q(L)`.
- A without logical register covering multiple truth physical addresses is evaluated once. Its single Q(L) is then associated with every covered truth physical register; the merge itself is not penalized.
- Bit-field targets are matched by exact bit_start/bit_end range. A split of one truth bit range into several without ranges is reported as an unmatched grouping and does not receive credit merely from coverage; only logical-register merge/split equivalence is exempted by AGENTS.md.
- Description-like scored fields (register_description, description, field_description, and default_value_description) are judged semantically: nonempty wording with preserved meaning is accepted, while missing descriptions normally receive C=0. For reserved bit fields, omitting name_or_parameter and field_description is explicitly accepted. Nested physical_address.description is scored leniently: equivalent/general wording receives C=1, while a missing description with matching numeric address receives C=0.5.
- Objective facts (names except the reserved-bit omission, numeric address/bank/page, widths, exact bit ranges, value codes, is_reserved, access types, and default values) are strict. Numeric-string value codes and singleton object/list representations are normalized when they encode the same fact. When value codes match, non-functional/general wording differences in value_description receive credit.
- For bit-field type_write_read, both empty truth/extracted values are treated as C=1; a one-sided empty/nonempty value or a concrete mismatch is strict.
- Only the AGENTS.md weighted fields are scored; category, index, is_multi_address, source, and all other unlisted fields are excluded.
- Rounded weights are normalized by 0.9999 at bit-field level and 1.0001 at logical-register level; field-part weights sum to 1.0000.

## Extracted logical register 1: `WHO_AM_I`

without location: `registers[0]`; truth association: `registers[0] (WHO_AM_I)`.
Associated physical locations: 0x00 (0).

### Bottom layer: bit fields, then field parts

#### Field part 1: `WHO_AM_I` at 0x00 (0)

Locations: `truth registers[0].field_parts` ↔ `without registers[0].field_parts[0]`.

**Truth bit field 1: `I2C_IF_DIS` bits 7:7**

Locations: `truth registers[0].field_parts.bit_field[0]` ↔ `without registers[0].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_IF_DIS | I2C_IF_DIS |
| `field_description` | 0.0586 | 1.0 | Setting this bit disables I²C access mode. | Setting this bit disables I²C access mode |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `ID` bits 6:1**

Locations: `truth registers[0].field_parts.bit_field[1]` ↔ `without registers[0].field_parts[0].bit_field[1]`. Judgment: truth value enumeration is missing from without; truth type_write_read='R', without has 'RW'.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ID | ID |
| `field_description` | 0.0586 | 1.0 | Contains the 6-bit I²C address of the device. The Power-On-Reset value of Bit6:Bit1 is 110 100. | 6-bit I²C address of the device (Power-On-Reset value of bits6:1 = 110100) |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 0.0 | {"value":"110 100","value_description":"Power-On-Reset value of Bit6:Bit1"} | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 0.0 | R | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×0.0)/0.9999=0.731900/0.9999=\mathbf{0.731973}\).

**Truth bit field 3: `Reserved` bits 0:0**

Locations: `truth registers[0].field_parts.bit_field[2]` ↔ `without registers[0].field_parts[0].bit_field[2]`. Judgment: truth value enumeration is missing from without.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Bit0 is reserved (may be 0 or 1). | Reserved (may be 0 or 1) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":0,"value_description":""},{"value":1,"value_description":""}] | [] |
| `is_reserved` | 0.0750 | 1.0 | True | True |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000, 0.731973, 0.790279) = **0.840751**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Contains device ID and I²C interface disable bit"} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"WHO_AM_I register"} |
| `description` | 0.0693 | 1.0 | Device ID and I²C interface control | Device ID and I²C interface control |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.840751 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.840751=\mathbf{0.950171}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.950171) = **0.950171**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Contains device ID and I²C interface disable bit"} | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"WHO_AM_I register"}] |
| `register_description` | 0.0564 | 1.0 | This register is used to verify the identity of the device, and to enable/disable the I²C interface. | Used to verify device identity and to enable/disable the I²C interface. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.950171 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | ["68h","69h"] | 68h or 69h |
| `default_value_description` | 0.0334 | 1.0 | [] | "" |

\(Q(L_{1})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.950171 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.985216/1.0001=\mathbf{0.985118}\).

## Extracted logical register 2: `X_OFFS_USRH`

without location: `registers[1]`; truth association: `registers[1] (X_OFFS_USRH)`.
Associated physical locations: 0x0C (12).

### Bottom layer: bit fields, then field parts

#### Field part 1: `X_OFFS_USRH` at 0x0C (12)

Locations: `truth registers[1].field_parts` ↔ `without registers[1].field_parts[0]`.

**Truth bit field 1: `X_OFFS_H` bits 7:0**

Locations: `truth registers[1].field_parts.bit_field` ↔ `without registers[1].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | X_OFFS_H | X_OFFS_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit X gyro offset (two's complement). | High byte of 16-bit X gyro offset (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | X_OFFS_USRH | X_OFFS_USRH |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"High byte of X gyro offset (X_OFFS_H)"} | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"X gyro offset high byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit X gyro offset (two's complement). | X_OFFS_H (high byte of X gyro offset) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | X_OFFS_USRH | X_OFFS_USRH |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"High byte of X gyro offset (X_OFFS_H)"} | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"X gyro offset high byte"}] |
| `register_description` | 0.0564 | 1.0 | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | High byte of 16-bit X-axis gyro offset (two's complement). Used to remove DC bias from gyro outputs. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | "" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{2})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 3: `X_OFFS_USRL`

without location: `registers[2]`; truth association: `registers[2] (X_OFFS_USRL)`.
Associated physical locations: 0x0D (13).

### Bottom layer: bit fields, then field parts

#### Field part 1: `X_OFFS_USRL` at 0x0D (13)

Locations: `truth registers[2].field_parts` ↔ `without registers[2].field_parts[0]`.

**Truth bit field 1: `X_OFFS_L` bits 7:0**

Locations: `truth registers[2].field_parts.bit_field` ↔ `without registers[2].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | X_OFFS_L | X_OFFS_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit X gyro offset (two's complement). | Low byte of 16-bit X gyro offset (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | X_OFFS_USRL | X_OFFS_USRL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Low byte of X gyro offset (X_OFFS_L)"} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"X gyro offset low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit X gyro offset (two's complement). | X_OFFS_L (low byte of X gyro offset) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | X_OFFS_USRL | X_OFFS_USRL |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Low byte of X gyro offset (X_OFFS_L)"} | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"X gyro offset low byte"}] |
| `register_description` | 0.0564 | 1.0 | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | Low byte of 16-bit X-axis gyro offset (two's complement). Used to remove DC bias from gyro outputs. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | "" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{3})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 4: `Y_OFFS_USRH`

without location: `registers[3]`; truth association: `registers[3] (Y_OFFS_USRH)`.
Associated physical locations: 0x0E (14).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Y_OFFS_USRH` at 0x0E (14)

Locations: `truth registers[3].field_parts` ↔ `without registers[3].field_parts[0]`.

**Truth bit field 1: `Y_OFFS_H` bits 7:0**

Locations: `truth registers[3].field_parts.bit_field` ↔ `without registers[3].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Y_OFFS_H | Y_OFFS_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit Y gyro offset (two's complement). | High byte of 16-bit Y gyro offset (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Y_OFFS_USRH | Y_OFFS_USRH |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0E","decimal":"14","bank":"","page":"","description":"High byte of Y gyro offset (Y_OFFS_H)"} | {"hex":"0x0E","decimal":"14","bank":"","page":"","description":"Y gyro offset high byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Y gyro offset (two's complement). | Y_OFFS_H (high byte of Y gyro offset) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Y_OFFS_USRH | Y_OFFS_USRH |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x0E","decimal":"14","bank":"","page":"","description":"High byte of Y gyro offset (Y_OFFS_H)"} | [{"hex":"0x0E","decimal":"14","bank":"","page":"","description":"Y gyro offset high byte"}] |
| `register_description` | 0.0564 | 1.0 | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | High byte of 16-bit Y-axis gyro offset (two's complement). Used to remove DC bias from gyro outputs. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | "" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{4})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 5: `Y_OFFS_USRL`

without location: `registers[4]`; truth association: `registers[4] (Y_OFFS_USRL)`.
Associated physical locations: 0x0F (15).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Y_OFFS_USRL` at 0x0F (15)

Locations: `truth registers[4].field_parts` ↔ `without registers[4].field_parts[0]`.

**Truth bit field 1: `Y_OFFS_L` bits 7:0**

Locations: `truth registers[4].field_parts.bit_field` ↔ `without registers[4].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Y_OFFS_L | Y_OFFS_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit Y gyro offset (two's complement). | Low byte of 16-bit Y gyro offset (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Y_OFFS_USRL | Y_OFFS_USRL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Low byte of Y gyro offset (Y_OFFS_L)"} | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Y gyro offset low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Y gyro offset (two's complement). | Y_OFFS_L (low byte of Y gyro offset) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Y_OFFS_USRL | Y_OFFS_USRL |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Low byte of Y gyro offset (Y_OFFS_L)"} | [{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Y gyro offset low byte"}] |
| `register_description` | 0.0564 | 1.0 | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | Low byte of 16-bit Y-axis gyro offset (two's complement). Used to remove DC bias from gyro outputs. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | "" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{5})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 6: `Z_OFFS_USRH`

without location: `registers[5]`; truth association: `registers[5] (Z_OFFS_USRH)`.
Associated physical locations: 0x10 (16).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Z_OFFS_USRH` at 0x10 (16)

Locations: `truth registers[5].field_parts` ↔ `without registers[5].field_parts[0]`.

**Truth bit field 1: `Z_OFFS_H` bits 7:0**

Locations: `truth registers[5].field_parts.bit_field` ↔ `without registers[5].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Z_OFFS_H | Z_OFFS_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit Z gyro offset (two's complement). | High byte of 16-bit Z gyro offset (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Z_OFFS_USRH | Z_OFFS_USRH |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"High byte of Z gyro offset (Z_OFFS_H)"} | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"Z gyro offset high byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Z gyro offset (two's complement). | Z_OFFS_H (high byte of Z gyro offset) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Z_OFFS_USRH | Z_OFFS_USRH |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"High byte of Z gyro offset (Z_OFFS_H)"} | [{"hex":"0x10","decimal":"16","bank":"","page":"","description":"Z gyro offset high byte"}] |
| `register_description` | 0.0564 | 1.0 | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | High byte of 16-bit Z-axis gyro offset (two's complement). Used to remove DC bias from gyro outputs. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | "" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{6})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 7: `Z_OFFS_USRL`

without location: `registers[6]`; truth association: `registers[6] (Z_OFFS_USRL)`.
Associated physical locations: 0x11 (17).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Z_OFFS_USRL` at 0x11 (17)

Locations: `truth registers[6].field_parts` ↔ `without registers[6].field_parts[0]`.

**Truth bit field 1: `Z_OFFS_L` bits 7:0**

Locations: `truth registers[6].field_parts.bit_field` ↔ `without registers[6].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Z_OFFS_L | Z_OFFS_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit Z gyro offset (two's complement). | Low byte of 16-bit Z gyro offset (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Z_OFFS_USRL | Z_OFFS_USRL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Low byte of Z gyro offset (Z_OFFS_L)"} | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Z gyro offset low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Z gyro offset (two's complement). | Z_OFFS_L (low byte of Z gyro offset) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Z_OFFS_USRL | Z_OFFS_USRL |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Low byte of Z gyro offset (Z_OFFS_L)"} | [{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Z gyro offset low byte"}] |
| `register_description` | 0.0564 | 1.0 | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | Low byte of 16-bit Z-axis gyro offset (two's complement). Used to remove DC bias from gyro outputs. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | "" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{7})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 8: `FIFO_EN`

without location: `registers[7]`; truth association: `registers[7] (FIFO_EN)`.
Associated physical locations: 0x12 (18).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_EN` at 0x12 (18)

Locations: `truth registers[7].field_parts` ↔ `without registers[7].field_parts[0]`.

**Truth bit field 1: `TEMP_OUT` bits 7:7**

Locations: `truth registers[7].field_parts.bit_field[0]` ↔ `without registers[7].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_OUT | TEMP_OUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Temperature reading into FIFO. | Insert Temperature reading into FIFO |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `GYRO_XOUT` bits 6:6**

Locations: `truth registers[7].field_parts.bit_field[1]` ↔ `without registers[7].field_parts[0].bit_field[1]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_XOUT | GYRO_XOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the X Gyro reading into FIFO. | Insert X Gyro reading into FIFO |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `GYRO_YOUT` bits 5:5**

Locations: `truth registers[7].field_parts.bit_field[2]` ↔ `without registers[7].field_parts[0].bit_field[2]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_YOUT | GYRO_YOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Y Gyro reading into FIFO. | Insert Y Gyro reading into FIFO |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `GYRO_ZOUT` bits 4:4**

Locations: `truth registers[7].field_parts.bit_field[3]` ↔ `without registers[7].field_parts[0].bit_field[3]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_ZOUT | GYRO_ZOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Z Gyro reading into FIFO. | Insert Z Gyro reading into FIFO |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 5: `AUX_XOUT` bits 3:3**

Locations: `truth registers[7].field_parts.bit_field[4]` ↔ `without registers[7].field_parts[0].bit_field[4]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_XOUT | AUX_XOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the X Accelerometer reading into FIFO. | Insert X accelerometer reading into FIFO |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 6: `AUX_YOUT` bits 2:2**

Locations: `truth registers[7].field_parts.bit_field[5]` ↔ `without registers[7].field_parts[0].bit_field[5]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_YOUT | AUX_YOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Y Accelerometer reading into FIFO. | Insert Y accelerometer reading into FIFO |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 7: `AUX_ZOUT` bits 1:1**

Locations: `truth registers[7].field_parts.bit_field[6]` ↔ `without registers[7].field_parts[0].bit_field[6]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_ZOUT | AUX_ZOUT |
| `field_description` | 0.0586 | 1.0 | Setting this inserts the Z Accelerometer reading into FIFO. | Insert Z accelerometer reading into FIFO |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 8: `FIFO_FOOTER` bits 0:0**

Locations: `truth registers[7].field_parts.bit_field[7]` ↔ `without registers[7].field_parts[0].bit_field[7]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_FOOTER | FIFO_FOOTER |
| `field_description` | 0.0586 | 1.0 | Last word (2 bytes) for FIFO read; described in more detail in register 60. | Include FIFO footer (last word) in FIFO |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | FIFO_EN | FIFO_EN |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"FIFO enable bits (select which sensor data are written into FIFO)"} | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"FIFO enable register"} |
| `description` | 0.0693 | 1.0 | Enable selection for data inserted into FIFO; each bit inserts the listed data into the FIFO when set. | Enable selection bits for FIFO data sources |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | FIFO_EN | FIFO_EN |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"FIFO enable bits (select which sensor data are written into FIFO)"} | [{"hex":"0x12","decimal":"18","bank":"","page":"","description":"FIFO enable register"}] |
| `register_description` | 0.0564 | 1.0 | Determines what data goes into the ITG-3050 FIFO (512 byte FIFO); sensor data is automatically placed into the FIFO after each ADC sampling period. | Determines which sensor data words are written into the 512-byte FIFO (TEMP, gyro axes, aux accel axes, FIFO footer). |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{8})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 9: `AUX_VDDIO`

without location: `registers[8]`; truth association: `registers[8] (AUX_VDDIO)`.
Associated physical locations: 0x13 (19).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_VDDIO` at 0x13 (19)

Locations: `truth registers[8].field_parts` ↔ `without registers[8].field_parts[0]`.

**Truth bit field 1: `Reserved` bits 7:3**

Locations: `truth registers[8].field_parts.bit_field[0]` ↔ `without: missing`. Judgment: truth bit-field target has no exact without bit range.

| Scored field | Weight | C | Truth content | without content |
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

Locations: `truth registers[8].field_parts.bit_field[1]` ↔ `without registers[8].field_parts[0].bit_field[0]`. Judgment: without adds unsupported objective value codes where truth has none.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_VDDIO | AUX_VDDIO |
| `field_description` | 0.0586 | 1.0 | I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1=VDD, 0=VLOGIC. | I/O logic for AUX bus: 1=VDD, 0=VLOGIC |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [] | [{"value":"1","value_description":"VDD"},{"value":"0","value_description":"VLOGIC"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 3: `Reserved` bits 1:0**

Locations: `truth registers[8].field_parts.bit_field[2]` ↔ `without: missing`. Judgment: truth bit-field target has no exact without bit range.

| Scored field | Weight | C | Truth content | without content |
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

**Field-part aggregation**

bit_field correctness = mean(0.000000, 0.790279, 0.000000) = **0.263426**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_VDDIO | AUX_VDDIO |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Auxiliary I/O voltage selection bit"} | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Auxiliary I/O voltage selection"} |
| `description` | 0.0693 | 1.0 | I/O logic level selection for the secondary I²C bus lines; other bits must be written as zeros. | I/O logic level selection for secondary I²C bus |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.263426 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.263426=\mathbf{0.769526}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.769526) = **0.769526**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_VDDIO | AUX_VDDIO |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Auxiliary I/O voltage selection bit"} | [{"hex":"0x13","decimal":"19","bank":"","page":"","description":"Auxiliary I/O voltage selection"}] |
| `register_description` | 0.0564 | 1.0 | Determines the I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1 = VDD, 0 = VLOGIC. | Determines I/O logic level for secondary I²C bus (AUX_CL, AUX_DA): 1 = VDD, 0 = VLOGIC. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.769526 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{9})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.769526 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.931257/1.0001=\mathbf{0.931164}\).

## Extracted logical register 10: `AUX_SLV_ADDR`

without location: `registers[9]`; truth association: `registers[9] (AUX_SLV_ADDR)`.
Associated physical locations: 0x14 (20).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_SLV_ADDR` at 0x14 (20)

Locations: `truth registers[9].field_parts` ↔ `without registers[9].field_parts[0]`.

**Truth bit field 1: `CLKOUT_EN` bits 7:7**

Locations: `truth registers[9].field_parts.bit_field[0]` ↔ `without registers[9].field_parts[0].bit_field[0]`. Judgment: without adds unsupported objective value codes where truth has none.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | CLKOUT_EN | CLKOUT_EN |
| `field_description` | 0.0586 | 1.0 | 1 = reference clock output is provided at CLKOUT pin; 0 = function disabled. | Reference clock output enable at CLKOUT pin (1=enabled, 0=disabled) |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [] | [{"value":"1","value_description":"reference clock output enabled at CLKOUT pin"},{"value":"0","value_description":"function disabled"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Truth bit field 2: `AUX_ID` bits 6:0**

Locations: `truth registers[9].field_parts.bit_field[1]` ↔ `without registers[9].field_parts[0].bit_field[1]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_ID | AUX_ID |
| `field_description` | 0.0586 | 1.0 | Contains the I²C address of the external accelerometer device (bits 6:0). | 7-bit I²C address of the external accelerometer |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(0.790279, 1.000000) = **0.895140**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_SLV_ADDR | AUX_SLV_ADDR |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Auxiliary device 7-bit slave address and CLKOUT enable"} | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Auxiliary slave address and clock output enable"} |
| `description` | 0.0693 | 1.0 | CLKOUT enable and auxiliary device address (AUX_ID). | CLKOUT enable and auxiliary device I²C address |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.895140 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.895140=\mathbf{0.967189}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.967189) = **0.967189**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_SLV_ADDR | AUX_SLV_ADDR |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Auxiliary device 7-bit slave address and CLKOUT enable"} | [{"hex":"0x14","decimal":"20","bank":"","page":"","description":"Auxiliary slave (accelerometer) address and CLKOUT enable"}] |
| `register_description` | 0.0564 | 1.0 | Contains the 7-bit slave address of the external accelerometer device and the CLKOUT enable bit. Used by the ITG-3050 when acting as I²C master for the auxiliary sensor. | Contains 7-bit I²C address of external accelerometer (AUX_ID) and CLKOUT enable bit for reference clock output. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.967189 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{10})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.967189 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.990299/1.0001=\mathbf{0.990200}\).

## Extracted logical register 11: `SMPLRT_DIV`

without location: `registers[10]`; truth association: `registers[10] (SMPLRT_DIV)`.
Associated physical locations: 0x15 (21).

### Bottom layer: bit fields, then field parts

#### Field part 1: `SMPLRT_DIV` at 0x15 (21)

Locations: `truth registers[10].field_parts` ↔ `without registers[10].field_parts[0]`.

**Truth bit field 1: `SMPLRT_DIV` bits 7:0**

Locations: `truth registers[10].field_parts.bit_field` ↔ `without registers[10].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SMPLRT_DIV | SMPLRT_DIV |
| `field_description` | 0.0586 | 1.0 | Sample rate divider. F_sample = F_internal / (divider + 1). | Sample rate divider (0–255) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | SMPLRT_DIV | SMPLRT_DIV |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Sample rate divider"} | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Sample rate divider"} |
| `description` | 0.0693 | 1.0 | Sample rate divider (0-255). | Divider for delivered sample rate |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | SMPLRT_DIV | SMPLRT_DIV |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Sample rate divider"} | [{"hex":"0x15","decimal":"21","bank":"","page":"","description":"Sample rate divider"}] |
| `register_description` | 0.0564 | 1.0 | Determines the sample rate of the ITG-3050 gyros. F_sample = F_internal / (divider + 1), where F_internal is either 1kHz or 8kHz (set by DLPF_CFG). | Sample rate divider; sample rate = F_internal / (divider + 1). F_internal is 1kHz or 8kHz depending on DLPF_CFG. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{11})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 12: `DLPF_FS_SYNC`

without location: `registers[11]`; truth association: `registers[11] (DLPF_FS_SYNC)`.
Associated physical locations: 0x16 (22).

### Bottom layer: bit fields, then field parts

#### Field part 1: `DLPF_FS_SYNC` at 0x16 (22)

Locations: `truth registers[11].field_parts` ↔ `without registers[11].field_parts[0]`.

**Truth bit field 1: `EXT_SYNC_SET` bits 7:5**

Locations: `truth registers[11].field_parts.bit_field[0]` ↔ `without registers[11].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | EXT_SYNC_SET | EXT_SYNC_SET |
| `field_description` | 0.0586 | 1.0 | Routing for the external frame synchronization input bit. | Routing for external frame synchronization input (FSYNC) inserted into LSB of selected register |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No sync (default)"},{"value":"1","value_description":"TEMP_OUT_L[0]"},{"value":"2","value_description":"GYRO_XOUT_L[0]"},{"value":"3","value_description":"GYRO_YOUT_L[0]"},{"value":"4","value_description":"GYRO_ZOUT_L[0]"},{"value":"5","value_description":"AUX_XOUT_L[0]"},{"value":"6","value_description":"AUX_YOUT_L[0]"},{"value":"7","value_description":"AUX_ZOUT_L[0]"}] | [{"value":"0","value_description":"No sync (default)"},{"value":"1","value_description":"TEMP_OUT_L[0]"},{"value":"2","value_description":"GYRO_XOUT_L[0]"},{"value":"3","value_description":"GYRO_YOUT_L[0]"},{"value":"4","value_description":"GYRO_ZOUT_L[0]"},{"value":"5","value_description":"AUX_XOUT_L[0]"},{"value":"6","value_description":"AUX_YOUT_L[0]"},{"value":"7","value_description":"AUX_ZOUT_L[0]"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `FS_SEL` bits 4:3**

Locations: `truth registers[11].field_parts.bit_field[1]` ↔ `without registers[11].field_parts[0].bit_field[1]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FS_SEL | FS_SEL |
| `field_description` | 0.0586 | 1.0 | Full scale selection for gyro sensor data. | Full-scale selection for gyro sensor data |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"±250°/sec"},{"value":"1","value_description":"±500°/sec"},{"value":"2","value_description":"±1000°/sec"},{"value":"3","value_description":"±2000°/sec"}] | [{"value":"0","value_description":"±250°/sec"},{"value":"1","value_description":"±500°/sec"},{"value":"2","value_description":"±1000°/sec"},{"value":"3","value_description":"±2000°/sec"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `DLPF_CFG` bits 2:0**

Locations: `truth registers[11].field_parts.bit_field[2]` ↔ `without registers[11].field_parts[0].bit_field[2]`. Judgment: objective value-code set matches; value-description wording has no functional deviation and is accepted.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DLPF_CFG | DLPF_CFG |
| `field_description` | 0.0586 | 1.0 | Digital low pass filter configuration; also determines internal analog sampling rate. | Digital low pass filter configuration (also selects analog sample rate) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Low pass filter bandwidth 256Hz; Analog sample rate 8kHz"},{"value":"1","value_description":"Low pass filter bandwidth 188Hz; Analog sample rate 1kHz"},{"value":"2","value_description":"Low pass filter bandwidth 98Hz; Analog sample rate 1kHz"},{"value":"3","value_description":"Low pass filter bandwidth 42Hz; Analog sample rate 1kHz"},{"value":"4","value_description":"Low pass filter bandwidth 20Hz; Analog sample rate 1kHz"},{"value":"5","value_description":"Low pass filter bandwidth 10Hz; Analog sample rate 1kHz"},{"value":"6","value_description":"Low pass filter bandwidth 5Hz; Analog sample rate 1kHz"}] | [{"value":"0","value_description":"256Hz LP, analog sample 8kHz"},{"value":"1","value_description":"188Hz LP, analog sample 1kHz"},{"value":"2","value_description":"98Hz LP, analog sample 1kHz"},{"value":"3","value_description":"42Hz LP, analog sample 1kHz"},{"value":"4","value_description":"20Hz LP, analog sample 1kHz"},{"value":"5","value_description":"10Hz LP, analog sample 1kHz"},{"value":"6","value_description":"5Hz LP, analog sample 1kHz"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | DLPF_FS_SYNC | DLPF_FS_SYNC |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"DLPF_CFG, FS_SEL, and EXT_SYNC_SET configuration"} | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"DLPF, full-scale, external sync register"} |
| `description` | 0.0693 | 1.0 | EXT_SYNC_SET (bits7:5), FS_SEL (bits4:3), DLPF_CFG (bits2:0). | EXT_SYNC_SET, FS_SEL, and DLPF_CFG fields |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | DLPF_FS_SYNC | DLPF_FS_SYNC |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"DLPF_CFG, FS_SEL, and EXT_SYNC_SET configuration"} | [{"hex":"0x16","decimal":"22","bank":"","page":"","description":"Digital low pass filter, full-scale, and external sync settings"}] |
| `register_description` | 0.0564 | 1.0 | Configures external sync routing (EXT_SYNC_SET), full-scale range (FS_SEL), and digital low-pass filter (DLPF_CFG). | Configures external sync routing (EXT_SYNC_SET), gyro full-scale range (FS_SEL), and digital low-pass filter (DLPF_CFG) and determines internal analog sampling rate. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{12})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 13: `INT_CFG`

without location: `registers[12]`; truth association: `registers[12] (INT_CFG)`.
Associated physical locations: 0x17 (23).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_CFG` at 0x17 (23)

Locations: `truth registers[12].field_parts` ↔ `without registers[12].field_parts[0]`.

**Truth bit field 1: `ACTL` bits 7:7**

Locations: `truth registers[12].field_parts.bit_field[0]` ↔ `without registers[12].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACTL | ACTL |
| `field_description` | 0.0586 | 1.0 | Logic level for INT output pin - 1=active low, 0=active high. | Logic level for INT output pin – 1=active low, 0=active high |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `OPEN` bits 6:6**

Locations: `truth registers[12].field_parts.bit_field[1]` ↔ `without registers[12].field_parts[0].bit_field[1]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | OPEN | OPEN |
| `field_description` | 0.0586 | 1.0 | Drive type for INT output pin - 1=open drain, 0=push-pull. | Drive type for INT output pin – 1=open drain, 0=push-pull |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `LATCH_INT_EN` bits 5:5**

Locations: `truth registers[12].field_parts.bit_field[2]` ↔ `without registers[12].field_parts[0].bit_field[2]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LATCH_INT_EN | LATCH_INT_EN |
| `field_description` | 0.0586 | 1.0 | "Latch mode - 1=latch until interrupt is cleared, 0=50\u0000us pulse." | Latch mode – 1=latch until interrupt is cleared, 0=50µs pulse |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `INT_ANYRD_2CLEAR` bits 4:4**

Locations: `truth registers[12].field_parts.bit_field[3]` ↔ `without registers[12].field_parts[0].bit_field[3]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | INT_ANYRD_2CLEAR | INT_ANYRD_2CLEAR |
| `field_description` | 0.0586 | 1.0 | Interrupt status register clear method - 1=clear by reading any register, 0=clear by reading interrupt status register (26) only. | Interrupt clear method – 1=clear by reading any register, 0=clear by reading INT_STATUS only |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 5: `Reserved` bits 3:3**

Locations: `truth registers[12].field_parts.bit_field[4]` ↔ `without: missing`. Judgment: truth bit-field target has no exact without bit range.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Reserved | MISSING |
| `field_description` | 0.0586 | 0.0 | No function defined for this bit (reserved). | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 6: `ITG_RDY_EN` bits 2:2**

Locations: `truth registers[12].field_parts.bit_field[5]` ↔ `without registers[12].field_parts[0].bit_field[4]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ITG_RDY_EN | ITG_RDY_EN |
| `field_description` | 0.0586 | 1.0 | Enable interrupt when device is ready (PLL ready after changing clock source). | Enable interrupt when device PLL/clock source is ready |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 7: `Reserved` bits 1:1**

Locations: `truth registers[12].field_parts.bit_field[6]` ↔ `without: missing`. Judgment: truth bit-field target has no exact without bit range.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Reserved | MISSING |
| `field_description` | 0.0586 | 0.0 | No function defined for this bit (reserved). | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 8: `RAW_RDY_EN` bits 0:0**

Locations: `truth registers[12].field_parts.bit_field[7]` ↔ `without registers[12].field_parts[0].bit_field[5]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | RAW_RDY_EN | RAW_RDY_EN |
| `field_description` | 0.0586 | 1.0 | Enable interrupt when data is available (raw data ready). | Enable interrupt when new raw data is available |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 0.000000, 1.000000, 0.000000, 1.000000) = **0.750000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | INT_CFG | INT_CFG |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Interrupt configuration"} | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Interrupt configuration register"} |
| `description` | 0.0693 | 1.0 | Interrupt pin configuration, latch mode, and interrupt enables. | Interrupt output and trigger configuration |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.750000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.750000=\mathbf{0.921775}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.921775) = **0.921775**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | INT_CFG | INT_CFG |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Interrupt configuration"} | [{"hex":"0x17","decimal":"23","bank":"","page":"","description":"Interrupt configuration"}] |
| `register_description` | 0.0564 | 1.0 | Configures the interrupt operation: INT pin polarity and drive type, latch/clear behavior, and which sources generate interrupts. | Configures INT pin polarity, drive type, latch method, clear method, and enables for device-ready and raw-data-ready interrupts. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.921775 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{13})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.921775 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.976734/1.0001=\mathbf{0.976637}\).

## Extracted logical register 14: `AUX_ADDR`

without location: `registers[13]`; truth association: `registers[13] (AUX_ADDR)`.
Associated physical locations: 0x18 (24).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_ADDR` at 0x18 (24)

Locations: `truth registers[13].field_parts` ↔ `without registers[13].field_parts[0]`.

**Truth bit field 1: `BURST_ADDR` bits 7:0**

Locations: `truth registers[13].field_parts.bit_field` ↔ `without registers[13].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | BURST_ADDR | BURST_ADDR |
| `field_description` | 0.0586 | 1.0 | Burst-mode read starting address for external accelerometer attached to secondary I2C bus. | Starting address in the external accelerometer for burst reads |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_ADDR | AUX_ADDR |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Auxiliary accelerometer burst read starting address (BURST_ADDR)"} | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Burst read start address for external accelerometer"} |
| `description` | 0.0693 | 1.0 | Burst-mode read starting address for external accelerometer (BURST_ADDR). | Burst-mode read starting address (AUX) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_ADDR | AUX_ADDR |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Auxiliary accelerometer burst read starting address (BURST_ADDR)"} | [{"hex":"0x18","decimal":"24","bank":"","page":"","description":"Auxiliary (accelerometer) burst read starting address"}] |
| `register_description` | 0.0564 | 1.0 | Configures the burst-mode-read starting address for an accelerometer attached to the secondary I2C bus of the ITG-3050. | Burst-mode read starting address for external accelerometer attached to the secondary I²C bus. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{14})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 15: `INT_STATUS`

without location: `registers[14]`; truth association: `registers[14] (INT_STATUS)`.
Associated physical locations: 0x1A (26).

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_STATUS` at 0x1A (26)

Locations: `truth registers[14].field_parts` ↔ `without registers[14].field_parts[0]`.

**Truth bit field 1: `Reserved` bits 7:3**

Locations: `truth registers[14].field_parts.bit_field[0]` ↔ `without: missing`. Judgment: truth bit-field target has no exact without bit range.

| Scored field | Weight | C | Truth content | without content |
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

Locations: `truth registers[14].field_parts.bit_field[1]` ↔ `without: missing`. Judgment: truth bit-field target has no exact without bit range.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ITG_RDY | MISSING |
| `field_description` | 0.0586 | 0.0 | PLL ready. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | False | MISSING |
| `type_write_read` | 0.0583 | 0.0 | R | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 3: `Reserved` bits 1:1**

Locations: `truth registers[14].field_parts.bit_field[2]` ↔ `without: missing`. Judgment: truth bit-field target has no exact without bit range.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Reserved | MISSING |
| `field_description` | 0.0586 | 0.0 | No function defined for this bit (reserved). | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 4: `RAW_DATA_RDY` bits 0:0**

Locations: `truth registers[14].field_parts.bit_field[3]` ↔ `without registers[14].field_parts[0].bit_field[1]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | RAW_DATA_RDY | RAW_DATA_RDY |
| `field_description` | 0.0586 | 1.0 | Raw data or FIFO data is ready. | Raw sensor or FIFO data ready |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

Additional without bit field not matched to an exact truth range: `without registers[14].field_parts[0].bit_field[0]` (ITG_RDY, bits 5:5). It is reported but not credited.
**Field-part aggregation**

bit_field correctness = mean(0.000000, 0.000000, 0.000000, 1.000000) = **0.250000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | INT_STATUS | INT_STATUS |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Interrupt status"} | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Interrupt status register"} |
| `description` | 0.0693 | 1.0 | Interrupt status bits. | Interrupt status bits |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.250000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.250000=\mathbf{0.765325}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.765325) = **0.765325**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | INT_STATUS | INT_STATUS |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Interrupt status"} | [{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Interrupt status"}] |
| `register_description` | 0.0564 | 1.0 | Indicates the status of interrupt sources. Bits are set when corresponding interrupt sources are triggered. Interrupt status bits are cleared as determined by INT_ANYRD_2CLEAR. | Indicates status of interrupt sources (device ready and raw data ready). Bits cleared according to INT_ANYRD_2CLEAR setting. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.765325 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{15})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.765325 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.930003/1.0001=\mathbf{0.929910}\).

## Extracted logical register 16: `TEMP_OUT_H`

without location: `registers[15]`; truth association: `registers[15] (TEMP_OUT_H)`.
Associated physical locations: 0x1B (27).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TEMP_OUT_H` at 0x1B (27)

Locations: `truth registers[15].field_parts` ↔ `without registers[15].field_parts[0]`.

**Truth bit field 1: `TEMP_OUT_H` bits 7:0**

Locations: `truth registers[15].field_parts.bit_field` ↔ `without registers[15].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_OUT_H | TEMP_OUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit temperature data (two's complement). | TEMP_OUT[15:8] high byte of temperature measurement (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TEMP_OUT_H | TEMP_OUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"High byte of temperature output (TEMP_OUT_H)"} | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Temperature output high byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit temperature data (two's complement). | High byte of TEMP_OUT (MSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | TEMP_OUT_H | TEMP_OUT_H |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"High byte of temperature output (TEMP_OUT_H)"} | [{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Temperature output high byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit temperature data (two's complement). | High byte of 16-bit temperature sensor reading (two's complement). |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{16})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 17: `TEMP_OUT_L`

without location: `registers[16]`; truth association: `registers[16] (TEMP_OUT_L)`.
Associated physical locations: 0x1C (28).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TEMP_OUT_L` at 0x1C (28)

Locations: `truth registers[16].field_parts` ↔ `without registers[16].field_parts[0]`.

**Truth bit field 1: `TEMP_OUT_L` bits 7:0**

Locations: `truth registers[16].field_parts.bit_field` ↔ `without registers[16].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_OUT_L | TEMP_OUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit temperature data (two's complement). | TEMP_OUT[7:0] low byte of temperature measurement (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TEMP_OUT_L | TEMP_OUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Low byte of temperature output (TEMP_OUT_L)"} | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Temperature output low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit temperature data (two's complement). | Low byte of TEMP_OUT (LSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | TEMP_OUT_L | TEMP_OUT_L |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Low byte of temperature output (TEMP_OUT_L)"} | [{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"Temperature output low byte"}] |
| `register_description` | 0.0564 | 1.0 | Low byte of 16-bit temperature data (two's complement). | Low byte of 16-bit temperature sensor reading (two's complement). |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{17})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 18: `GYRO_XOUT_H`

without location: `registers[17]`; truth association: `registers[17] (GYRO_XOUT_H)`.
Associated physical locations: 0x1D (29).

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_XOUT_H` at 0x1D (29)

Locations: `truth registers[17].field_parts` ↔ `without registers[17].field_parts[0]`.

**Truth bit field 1: `GYRO_XOUT_H` bits 7:0**

Locations: `truth registers[17].field_parts.bit_field` ↔ `without registers[17].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_XOUT_H | GYRO_XOUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit X gyro output (two's complement). | GYRO_XOUT[15:8] high byte of X gyro measurement (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_XOUT_H | GYRO_XOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"High byte of X gyro output (GYRO_XOUT_H)"} | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"X gyro output high byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit X gyro output (two's complement). | High byte of GYRO_XOUT (MSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | GYRO_XOUT_H | GYRO_XOUT_H |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"High byte of X gyro output (GYRO_XOUT_H)"} | [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"X gyro output high byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit X gyro output data (two's complement). | High byte of 16-bit X-axis gyro output (two's complement). |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{18})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 19: `GYRO_XOUT_L`

without location: `registers[18]`; truth association: `registers[18] (GYRO_XOUT_L)`.
Associated physical locations: 0x1E (30).

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_XOUT_L` at 0x1E (30)

Locations: `truth registers[18].field_parts` ↔ `without registers[18].field_parts[0]`.

**Truth bit field 1: `GYRO_XOUT_L` bits 7:0**

Locations: `truth registers[18].field_parts.bit_field` ↔ `without registers[18].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_XOUT_L | GYRO_XOUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit X gyro output (two's complement). | GYRO_XOUT[7:0] low byte of X gyro measurement (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_XOUT_L | GYRO_XOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Low byte of X gyro output (GYRO_XOUT_L)"} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"X gyro output low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit X gyro output (two's complement). | Low byte of GYRO_XOUT (LSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | GYRO_XOUT_L | GYRO_XOUT_L |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"Low byte of X gyro output (GYRO_XOUT_L)"} | [{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"X gyro output low byte"}] |
| `register_description` | 0.0564 | 1.0 | Low byte of 16-bit X gyro output data (two's complement). | Low byte of 16-bit X-axis gyro output (two's complement). |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{19})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 20: `GYRO_YOUT_H`

without location: `registers[19]`; truth association: `registers[19] (GYRO_YOUT_H)`.
Associated physical locations: 0x1F (31).

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_YOUT_H` at 0x1F (31)

Locations: `truth registers[19].field_parts` ↔ `without registers[19].field_parts[0]`.

**Truth bit field 1: `GYRO_YOUT_H` bits 7:0**

Locations: `truth registers[19].field_parts.bit_field` ↔ `without registers[19].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_YOUT_H | GYRO_YOUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit Y gyro output (two's complement). | GYRO_YOUT[15:8] high byte of Y gyro measurement (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_YOUT_H | GYRO_YOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"High byte of Y gyro output (GYRO_YOUT_H)"} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Y gyro output high byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Y gyro output (two's complement). | High byte of GYRO_YOUT (MSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | GYRO_YOUT_H | GYRO_YOUT_H |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"High byte of Y gyro output (GYRO_YOUT_H)"} | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Y gyro output high byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit Y gyro output data (two's complement). | High byte of 16-bit Y-axis gyro output (two's complement). |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{20})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 21: `GYRO_YOUT_L`

without location: `registers[20]`; truth association: `registers[20] (GYRO_YOUT_L)`.
Associated physical locations: 0x20 (32).

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_YOUT_L` at 0x20 (32)

Locations: `truth registers[20].field_parts` ↔ `without registers[20].field_parts[0]`.

**Truth bit field 1: `GYRO_YOUT_L` bits 7:0**

Locations: `truth registers[20].field_parts.bit_field` ↔ `without registers[20].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_YOUT_L | GYRO_YOUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit Y gyro output (two's complement). | GYRO_YOUT[7:0] low byte of Y gyro measurement (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_YOUT_L | GYRO_YOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Low byte of Y gyro output (GYRO_YOUT_L)"} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Y gyro output low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Y gyro output (two's complement). | Low byte of GYRO_YOUT (LSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | GYRO_YOUT_L | GYRO_YOUT_L |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Low byte of Y gyro output (GYRO_YOUT_L)"} | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Y gyro output low byte"}] |
| `register_description` | 0.0564 | 1.0 | Low byte of 16-bit Y gyro output data (two's complement). | Low byte of 16-bit Y-axis gyro output (two's complement). |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{21})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 22: `GYRO_ZOUT_H`

without location: `registers[21]`; truth association: `registers[21] (GYRO_ZOUT_H)`.
Associated physical locations: 0x21 (33).

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_ZOUT_H` at 0x21 (33)

Locations: `truth registers[21].field_parts` ↔ `without registers[21].field_parts[0]`.

**Truth bit field 1: `GYRO_ZOUT_H` bits 7:0**

Locations: `truth registers[21].field_parts.bit_field` ↔ `without registers[21].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_ZOUT_H | GYRO_ZOUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit Z gyro output (two's complement). | GYRO_ZOUT[15:8] high byte of Z gyro measurement (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_ZOUT_H | GYRO_ZOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"High byte of Z gyro output (GYRO_ZOUT_H)"} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"Z gyro output high byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Z gyro output (two's complement). | High byte of GYRO_ZOUT (MSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | GYRO_ZOUT_H | GYRO_ZOUT_H |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"High byte of Z gyro output (GYRO_ZOUT_H)"} | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"Z gyro output high byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit Z gyro output data (two's complement). | High byte of 16-bit Z-axis gyro output (two's complement). |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{22})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 23: `GYRO_ZOUT_L`

without location: `registers[22]`; truth association: `registers[22] (GYRO_ZOUT_L)`.
Associated physical locations: 0x22 (34).

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_ZOUT_L` at 0x22 (34)

Locations: `truth registers[22].field_parts` ↔ `without registers[22].field_parts[0]`.

**Truth bit field 1: `GYRO_ZOUT_L` bits 7:0**

Locations: `truth registers[22].field_parts.bit_field` ↔ `without registers[22].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_ZOUT_L | GYRO_ZOUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit Z gyro output (two's complement). | GYRO_ZOUT[7:0] low byte of Z gyro measurement (2's complement) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | GYRO_ZOUT_L | GYRO_ZOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Low byte of Z gyro output (GYRO_ZOUT_L)"} | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Z gyro output low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Z gyro output (two's complement). | Low byte of GYRO_ZOUT (LSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | GYRO_ZOUT_L | GYRO_ZOUT_L |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"Low byte of Z gyro output (GYRO_ZOUT_L)"} | [{"hex":"0x22","decimal":"34","bank":"","page":"","description":"Z gyro output low byte"}] |
| `register_description` | 0.0564 | 1.0 | Low byte of 16-bit Z gyro output data (two's complement). | Low byte of 16-bit Z-axis gyro output (two's complement). |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{23})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 24: `AUX_XOUT_H`

without location: `registers[23]`; truth association: `registers[23] (AUX_XOUT_H)`.
Associated physical locations: 0x23 (35).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_XOUT_H` at 0x23 (35)

Locations: `truth registers[23].field_parts` ↔ `without registers[23].field_parts[0]`.

**Truth bit field 1: `AUX_XOUT_H` bits 7:0**

Locations: `truth registers[23].field_parts.bit_field` ↔ `without registers[23].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_XOUT_H | AUX_XOUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit X auxiliary (accel) output. | AUX_XOUT[15:8] high byte of auxiliary X-axis measurement |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_XOUT_H | AUX_XOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte of X auxiliary (accel) output (AUX_XOUT_H)"} | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"Auxiliary X output high byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit X auxiliary (accel) output. | High byte of AUX_XOUT (MSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_XOUT_H | AUX_XOUT_H |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte of X auxiliary (accel) output (AUX_XOUT_H)"} | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"Auxiliary X output high byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit auxiliary X-axis output (as available from auxiliary device). | High byte of 16-bit AUX (accelerometer) X-axis output as read via the auxiliary interface. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{24})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 25: `AUX_XOUT_L`

without location: `registers[24]`; truth association: `registers[24] (AUX_XOUT_L)`.
Associated physical locations: 0x24 (36).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_XOUT_L` at 0x24 (36)

Locations: `truth registers[24].field_parts` ↔ `without registers[24].field_parts[0]`.

**Truth bit field 1: `AUX_XOUT_L` bits 7:0**

Locations: `truth registers[24].field_parts.bit_field` ↔ `without registers[24].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_XOUT_L | AUX_XOUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit X auxiliary (accel) output. | AUX_XOUT[7:0] low byte of auxiliary X-axis measurement |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_XOUT_L | AUX_XOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low byte of X auxiliary (accel) output (AUX_XOUT_L)"} | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Auxiliary X output low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit X auxiliary (accel) output. | Low byte of AUX_XOUT (LSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_XOUT_L | AUX_XOUT_L |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low byte of X auxiliary (accel) output (AUX_XOUT_L)"} | [{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Auxiliary X output low byte"}] |
| `register_description` | 0.0564 | 1.0 | Low byte of 16-bit auxiliary X-axis output (as available from auxiliary device). | Low byte of 16-bit AUX (accelerometer) X-axis output as read via the auxiliary interface. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{25})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 26: `AUX_YOUT_H`

without location: `registers[25]`; truth association: `registers[25] (AUX_YOUT_H)`.
Associated physical locations: 0x25 (37).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_YOUT_H` at 0x25 (37)

Locations: `truth registers[25].field_parts` ↔ `without registers[25].field_parts[0]`.

**Truth bit field 1: `AUX_YOUT_H` bits 7:0**

Locations: `truth registers[25].field_parts.bit_field` ↔ `without registers[25].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_YOUT_H | AUX_YOUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit Y auxiliary (accel) output. | AUX_YOUT[15:8] high byte of auxiliary Y-axis measurement |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_YOUT_H | AUX_YOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"High byte of Y auxiliary (accel) output (AUX_YOUT_H)"} | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"Auxiliary Y output high byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Y auxiliary (accel) output. | High byte of AUX_YOUT (MSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_YOUT_H | AUX_YOUT_H |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x25","decimal":"37","bank":"","page":"","description":"High byte of Y auxiliary (accel) output (AUX_YOUT_H)"} | [{"hex":"0x25","decimal":"37","bank":"","page":"","description":"Auxiliary Y output high byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit auxiliary Y-axis output (as available from auxiliary device). | High byte of 16-bit AUX (accelerometer) Y-axis output as read via the auxiliary interface. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{26})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 27: `AUX_YOUT_L`

without location: `registers[26]`; truth association: `registers[26] (AUX_YOUT_L)`.
Associated physical locations: 0x26 (38).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_YOUT_L` at 0x26 (38)

Locations: `truth registers[26].field_parts` ↔ `without registers[26].field_parts[0]`.

**Truth bit field 1: `AUX_YOUT_L` bits 7:0**

Locations: `truth registers[26].field_parts.bit_field` ↔ `without registers[26].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_YOUT_L | AUX_YOUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit Y auxiliary (accel) output. | AUX_YOUT[7:0] low byte of auxiliary Y-axis measurement |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_YOUT_L | AUX_YOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Low byte of Y auxiliary (accel) output (AUX_YOUT_L)"} | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Auxiliary Y output low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Y auxiliary (accel) output. | Low byte of AUX_YOUT (LSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_YOUT_L | AUX_YOUT_L |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x26","decimal":"38","bank":"","page":"","description":"Low byte of Y auxiliary (accel) output (AUX_YOUT_L)"} | [{"hex":"0x26","decimal":"38","bank":"","page":"","description":"Auxiliary Y output low byte"}] |
| `register_description` | 0.0564 | 1.0 | Low byte of 16-bit auxiliary Y-axis output (as available from auxiliary device). | Low byte of 16-bit AUX (accelerometer) Y-axis output as read via the auxiliary interface. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{27})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 28: `AUX_ZOUT_H`

without location: `registers[27]`; truth association: `registers[27] (AUX_ZOUT_H)`.
Associated physical locations: 0x27 (39).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_ZOUT_H` at 0x27 (39)

Locations: `truth registers[27].field_parts` ↔ `without registers[27].field_parts[0]`.

**Truth bit field 1: `AUX_ZOUT_H` bits 7:0**

Locations: `truth registers[27].field_parts.bit_field` ↔ `without registers[27].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_ZOUT_H | AUX_ZOUT_H |
| `field_description` | 0.0586 | 1.0 | High byte of 16-bit Z auxiliary (accel) output. | AUX_ZOUT[15:8] high byte of auxiliary Z-axis measurement |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_ZOUT_H | AUX_ZOUT_H |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"High byte of Z auxiliary (accel) output (AUX_ZOUT_H)"} | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"Auxiliary Z output high byte"} |
| `description` | 0.0693 | 1.0 | High byte of 16-bit Z auxiliary (accel) output. | High byte of AUX_ZOUT (MSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_ZOUT_H | AUX_ZOUT_H |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"High byte of Z auxiliary (accel) output (AUX_ZOUT_H)"} | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Auxiliary Z output high byte"}] |
| `register_description` | 0.0564 | 1.0 | High byte of 16-bit auxiliary Z-axis output (as available from auxiliary device). | High byte of 16-bit AUX (accelerometer) Z-axis output as read via the auxiliary interface. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{28})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 29: `AUX_ZOUT_L`

without location: `registers[28]`; truth association: `registers[28] (AUX_ZOUT_L)`.
Associated physical locations: 0x28 (40).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AUX_ZOUT_L` at 0x28 (40)

Locations: `truth registers[28].field_parts` ↔ `without registers[28].field_parts[0]`.

**Truth bit field 1: `AUX_ZOUT_L` bits 7:0**

Locations: `truth registers[28].field_parts.bit_field` ↔ `without registers[28].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_ZOUT_L | AUX_ZOUT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of 16-bit Z auxiliary (accel) output. | AUX_ZOUT[7:0] low byte of auxiliary Z-axis measurement |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | AUX_ZOUT_L | AUX_ZOUT_L |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of Z auxiliary (accel) output (AUX_ZOUT_L)"} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Auxiliary Z output low byte"} |
| `description` | 0.0693 | 1.0 | Low byte of 16-bit Z auxiliary (accel) output. | Low byte of AUX_ZOUT (LSB) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | AUX_ZOUT_L | AUX_ZOUT_L |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Low byte of Z auxiliary (accel) output (AUX_ZOUT_L)"} | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Auxiliary Z output low byte"}] |
| `register_description` | 0.0564 | 1.0 | Low byte of 16-bit auxiliary Z-axis output (as available from auxiliary device). | Low byte of 16-bit AUX (accelerometer) Z-axis output as read via the auxiliary interface. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{29})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 30: `FIFO_COUNTH`

without location: `registers[29]`; truth association: `registers[29] (FIFO_COUNTH)`.
Associated physical locations: 0x3A (58).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_COUNTH` at 0x3A (58)

Locations: `truth registers[29].field_parts` ↔ `without registers[29].field_parts[0]`.

**Truth bit field 1: `Reserved` bits 7:2**

Locations: `truth registers[29].field_parts.bit_field[0]` ↔ `without: missing`. Judgment: truth bit-field target has no exact without bit range.

| Scored field | Weight | C | Truth content | without content |
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

Locations: `truth registers[29].field_parts.bit_field[1]` ↔ `without registers[29].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_COUNT_H | FIFO_COUNT_H |
| `field_description` | 0.0586 | 1.0 | High bits of the number of bytes currently in FIFO. | High portion of FIFO byte count |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(0.000000, 1.000000) = **0.500000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | FIFO_COUNTH | FIFO_COUNTH |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":"FIFO byte count high part (FIFO_COUNT_H)"} | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":"FIFO count high byte"} |
| `description` | 0.0693 | 1.0 | High portion of FIFO byte count. | High bits of FIFO byte count |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.500000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.500000=\mathbf{0.843550}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.843550) = **0.843550**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | FIFO_COUNTH | FIFO_COUNTH |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":"FIFO byte count high part (FIFO_COUNT_H)"} | [{"hex":"0x3A","decimal":"58","bank":"","page":"","description":"FIFO byte count high"}] |
| `register_description` | 0.0564 | 1.0 | Indicates how many bytes of valid data are contained in the FIFO (high part). | High part of the number of valid bytes currently in the FIFO. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.843550 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{30})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.843550 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.953368/1.0001=\mathbf{0.953273}\).

## Extracted logical register 31: `FIFO_COUNTL`

without location: `registers[30]`; truth association: `registers[30] (FIFO_COUNTL)`.
Associated physical locations: 0x3B (59).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_COUNTL` at 0x3B (59)

Locations: `truth registers[30].field_parts` ↔ `without registers[30].field_parts[0]`.

**Truth bit field 1: `FIFO_COUNT_L` bits 7:0**

Locations: `truth registers[30].field_parts.bit_field` ↔ `without registers[30].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_COUNT_L | FIFO_COUNT_L |
| `field_description` | 0.0586 | 1.0 | Low byte of the number of bytes currently in FIFO. | Low portion of FIFO byte count |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | FIFO_COUNTL | FIFO_COUNTL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":"FIFO byte count low part (FIFO_COUNT_L)"} | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":"FIFO count low byte"} |
| `description` | 0.0693 | 1.0 | Low portion of FIFO byte count. | Low 8 bits of FIFO byte count |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | FIFO_COUNTL | FIFO_COUNTL |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":"FIFO byte count low part (FIFO_COUNT_L)"} | [{"hex":"0x3B","decimal":"59","bank":"","page":"","description":"FIFO byte count low"}] |
| `register_description` | 0.0564 | 1.0 | Indicates how many bytes of valid data are contained in the FIFO (low part). | Low part of the number of valid bytes currently in the FIFO. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{31})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 32: `FIFO_R`

without location: `registers[31]`; truth association: `registers[31] (FIFO_R)`.
Associated physical locations: 0x3C (60).

### Bottom layer: bit fields, then field parts

#### Field part 1: `FIFO_R` at 0x3C (60)

Locations: `truth registers[31].field_parts` ↔ `without registers[31].field_parts[0]`.

**Truth bit field 1: `FIFO_DATA` bits 7:0**

Locations: `truth registers[31].field_parts.bit_field` ↔ `without registers[31].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_DATA | FIFO_DATA |
| `field_description` | 0.0586 | 1.0 | FIFO data byte. | FIFO output data byte |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**. Direct judgment: register_name is objectively different.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 0.0 | FIFO_DATA | FIFO_R |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"FIFO data output (FIFO_DATA)"} | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"FIFO read register"} |
| `description` | 0.0693 | 1.0 | FIFO output data byte; reading this register fetches the next byte from FIFO. | FIFO data output (one byte per read) |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×0.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{0.972000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.972000) = **0.972000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | FIFO_R | FIFO_R |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"FIFO data output (FIFO_DATA)"} | [{"hex":"0x3C","decimal":"60","bank":"","page":"","description":"FIFO read (data output)"}] |
| `register_description` | 0.0564 | 1.0 | Output register of the FIFO. Each read returns the oldest contents of the FIFO buffer; a burst read is required to read multiple bytes. | FIFO data output register. Reading returns oldest FIFO contents; burst read auto-increments and prefetches. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.972000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{32})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.972000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.991736/1.0001=\mathbf{0.991637}\).

## Extracted logical register 33: `USER_CTRL`

without location: `registers[32]`; truth association: `registers[32] (USER_CTRL)`.
Associated physical locations: 0x3D (61).

### Bottom layer: bit fields, then field parts

#### Field part 1: `USER_CTRL` at 0x3D (61)

Locations: `truth registers[32].field_parts` ↔ `without registers[32].field_parts[0]`.

**Truth bit field 1: `Reserved` bits 7:7**

Locations: `truth registers[32].field_parts.bit_field[0]` ↔ `without: missing`. Judgment: truth bit-field target has no exact without bit range.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Reserved | MISSING |
| `field_description` | 0.0586 | 0.0 | No function defined for this bit (reserved). | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 2: `FIFO_EN` bits 6:6**

Locations: `truth registers[32].field_parts.bit_field[1]` ↔ `without registers[32].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_EN | FIFO_EN |
| `field_description` | 0.0586 | 1.0 | Enable FIFO operation for sensor data. | Enable FIFO operation for sensor data |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `AUX_IF_EN` bits 5:5**

Locations: `truth registers[32].field_parts.bit_field[2]` ↔ `without registers[32].field_parts[0].bit_field[1]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_IF_EN | AUX_IF_EN |
| `field_description` | 0.0586 | 1.0 | Enable 3rd-party accelerometer interface via I²C. Clear this bit to enable bypass mode (host direct access to accel). | Enable auxiliary I²C master interface (1 = master); clearing enables bypass mode for host access |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `Reserved` bits 4:4**

Locations: `truth registers[32].field_parts.bit_field[3]` ↔ `without: missing`. Judgment: truth bit-field target has no exact without bit range.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Reserved | MISSING |
| `field_description` | 0.0586 | 0.0 | No function defined for this bit (reserved). | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 5: `AUX_IF_RST` bits 3:3**

Locations: `truth registers[32].field_parts.bit_field[4]` ↔ `without registers[32].field_parts[0].bit_field[2]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | AUX_IF_RST | AUX_IF_RST |
| `field_description` | 0.0586 | 1.0 | Reset third-party accelerometer interface function; set this only after changing AUX_IF_EN to 0. | Reset third-party accelerometer interface (use after changing AUX_IF_EN to 0) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 6: `Reserved` bits 2:2**

Locations: `truth registers[32].field_parts.bit_field[5]` ↔ `without: missing`. Judgment: truth bit-field target has no exact without bit range.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | Reserved | MISSING |
| `field_description` | 0.0586 | 0.0 | No function defined for this bit (reserved). | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "" | MISSING |

\(Q_{BF}=(0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 7: `FIFO_RST` bits 1:1**

Locations: `truth registers[32].field_parts.bit_field[6]` ↔ `without registers[32].field_parts[0].bit_field[3]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_RST | FIFO_RST |
| `field_description` | 0.0586 | 1.0 | Reset FIFO function; set this to clear FIFO or when changing FIFO_EN. | Reset FIFO function; clears FIFO and should be used when changing FIFO_EN |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 8: `GYRO_RST` bits 0:0**

Locations: `truth registers[32].field_parts.bit_field[7]` ↔ `without registers[32].field_parts[0].bit_field[4]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_RST | GYRO_RST |
| `field_description` | 0.0586 | 1.0 | Reset gyro analog and digital functions. | Reset gyro analog and digital functions |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(0.000000, 1.000000, 1.000000, 0.000000, 1.000000, 0.000000, 1.000000, 1.000000) = **0.625000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | USER_CTRL | USER_CTRL |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"User control (enable/reset auxiliary functions and FIFO)"} | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"User control register"} |
| `description` | 0.0693 | 1.0 | Control and reset bits for FIFO and auxiliary interface functions. | Enable/reset controls for FIFO, AUX interface, and gyro |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.625000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.625000=\mathbf{0.882663}\).

### Extracted logical-register aggregation

field_parts correctness = mean(0.882663) = **0.882663**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | USER_CTRL | USER_CTRL |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"User control (enable/reset auxiliary functions and FIFO)"} | [{"hex":"0x3D","decimal":"61","bank":"","page":"","description":"User control"}] |
| `register_description` | 0.0564 | 1.0 | Used to enable/disable and reset various modes and functions (FIFO, AUX I2C master interface, gyro reset). Reset bits are auto-cleared after reset. | Enables and resets FIFO, auxiliary interface (I²C master), and gyro reset functions. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.882663 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{33})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.882663 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.965051/1.0001=\mathbf{0.964955}\).

## Extracted logical register 34: `PWR_MGM`

without location: `registers[33]`; truth association: `registers[33] (PWR_MGM)`.
Associated physical locations: 0x3E (62).

### Bottom layer: bit fields, then field parts

#### Field part 1: `PWR_MGM` at 0x3E (62)

Locations: `truth registers[33].field_parts` ↔ `without registers[33].field_parts[0]`.

**Truth bit field 1: `H_RESET` bits 7:7**

Locations: `truth registers[33].field_parts.bit_field[0]` ↔ `without registers[33].field_parts[0].bit_field[0]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | H_RESET | H_RESET |
| `field_description` | 0.0586 | 1.0 | Reset device and internal registers to the power-up-default settings. | Reset device and internal registers to power-up defaults |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `SLEEP` bits 6:6**

Locations: `truth registers[33].field_parts.bit_field[1]` ↔ `without registers[33].field_parts[0].bit_field[1]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SLEEP | SLEEP |
| `field_description` | 0.0586 | 1.0 | Enable low power sleep mode. | Enable low-power sleep mode (1 = sleep) |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `STBY_XG` bits 5:5**

Locations: `truth registers[33].field_parts.bit_field[2]` ↔ `without registers[33].field_parts[0].bit_field[2]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_XG | STBY_XG |
| `field_description` | 0.0586 | 1.0 | Put gyro X in standby mode (1=standby, 0=normal). | Put X gyro in standby (1=standby, 0=normal) |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `STBY_YG` bits 4:4**

Locations: `truth registers[33].field_parts.bit_field[3]` ↔ `without registers[33].field_parts[0].bit_field[3]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_YG | STBY_YG |
| `field_description` | 0.0586 | 1.0 | Put gyro Y in standby mode (1=standby, 0=normal). | Put Y gyro in standby (1=standby, 0=normal) |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 5: `STBY_ZG` bits 3:3**

Locations: `truth registers[33].field_parts.bit_field[4]` ↔ `without registers[33].field_parts[0].bit_field[4]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_ZG | STBY_ZG |
| `field_description` | 0.0586 | 1.0 | Put gyro Z in standby mode (1=standby, 0=normal). | Put Z gyro in standby (1=standby, 0=normal) |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 6: `CLK_SEL` bits 2:0**

Locations: `truth registers[33].field_parts.bit_field[5]` ↔ `without registers[33].field_parts[0].bit_field[5]`. Judgment: objective facts match; description compared semantically.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | CLK_SEL | CLK_SEL |
| `field_description` | 0.0586 | 1.0 | Select device clock source. | Clock source selection (see CLK_SEL table) |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Internal oscillator"},{"value":"1","value_description":"PLL with X Gyro reference"},{"value":"2","value_description":"PLL with Y Gyro reference"},{"value":"3","value_description":"PLL with Z Gyro reference"},{"value":"4","value_description":"PLL with external 32.768kHz reference"},{"value":"5","value_description":"PLL with external 19.2MHz reference"},{"value":"6","value_description":"Reserved"},{"value":"7","value_description":"Stop clock and synchronous reset clock state"}] | [{"value":"0","value_description":"Internal oscillator"},{"value":"1","value_description":"PLL with X Gyro reference"},{"value":"2","value_description":"PLL with Y Gyro reference"},{"value":"3","value_description":"PLL with Z Gyro reference"},{"value":"4","value_description":"PLL with external 32.768kHz reference"},{"value":"5","value_description":"PLL with external 19.2MHz reference"},{"value":"6","value_description":"Reserved"},{"value":"7","value_description":"Stop clock and synchronous reset clock state"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**. Direct judgment: direct facts match; description compared semantically.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | PWR_MGM | PWR_MGM |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Power management and clock select"} | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Power management register"} |
| `description` | 0.0693 | 1.0 | Power control bits, standby selections, and clock source selection. | Power, standby, reset and clock source settings |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | truth bit-field targets | matched exact without ranges |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared semantically.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | PWR_MGM | PWR_MGM |
| `physical_address` | 0.4044 | 1.0 | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Power management and clock select"} | [{"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Power management"}] |
| `register_description` | 0.0564 | 1.0 | Manages power control, clock source selection, standby modes, and device reset. | Power control, clock source selection, standby for individual gyros, and device reset. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | corresponding truth target collection | extracted collection |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{34})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## 2. Ground-truth physical-register scores

For every truth physical register, \(q_R=\frac{1}{|L_R|}\sum_{L\in L_R}Q(L)\). A merged without logical register contributes its one Q(L) to each physical address it covers.

| Truth physical address | Associated extracted logical registers and Q(L) | q_R |
|---|---|---:|
| 0x00 (0) | without registers[0] `WHO_AM_I`=0.985118 | 0.985118 |
| 0x0C (12) | without registers[1] `X_OFFS_USRH`=1.000000 | 1.000000 |
| 0x0D (13) | without registers[2] `X_OFFS_USRL`=1.000000 | 1.000000 |
| 0x0E (14) | without registers[3] `Y_OFFS_USRH`=1.000000 | 1.000000 |
| 0x0F (15) | without registers[4] `Y_OFFS_USRL`=1.000000 | 1.000000 |
| 0x10 (16) | without registers[5] `Z_OFFS_USRH`=1.000000 | 1.000000 |
| 0x11 (17) | without registers[6] `Z_OFFS_USRL`=1.000000 | 1.000000 |
| 0x12 (18) | without registers[7] `FIFO_EN`=1.000000 | 1.000000 |
| 0x13 (19) | without registers[8] `AUX_VDDIO`=0.931164 | 0.931164 |
| 0x14 (20) | without registers[9] `AUX_SLV_ADDR`=0.990200 | 0.990200 |
| 0x15 (21) | without registers[10] `SMPLRT_DIV`=1.000000 | 1.000000 |
| 0x16 (22) | without registers[11] `DLPF_FS_SYNC`=1.000000 | 1.000000 |
| 0x17 (23) | without registers[12] `INT_CFG`=0.976637 | 0.976637 |
| 0x18 (24) | without registers[13] `AUX_ADDR`=1.000000 | 1.000000 |
| 0x1A (26) | without registers[14] `INT_STATUS`=0.929910 | 0.929910 |
| 0x1B (27) | without registers[15] `TEMP_OUT_H`=1.000000 | 1.000000 |
| 0x1C (28) | without registers[16] `TEMP_OUT_L`=1.000000 | 1.000000 |
| 0x1D (29) | without registers[17] `GYRO_XOUT_H`=1.000000 | 1.000000 |
| 0x1E (30) | without registers[18] `GYRO_XOUT_L`=1.000000 | 1.000000 |
| 0x1F (31) | without registers[19] `GYRO_YOUT_H`=1.000000 | 1.000000 |
| 0x20 (32) | without registers[20] `GYRO_YOUT_L`=1.000000 | 1.000000 |
| 0x21 (33) | without registers[21] `GYRO_ZOUT_H`=1.000000 | 1.000000 |
| 0x22 (34) | without registers[22] `GYRO_ZOUT_L`=1.000000 | 1.000000 |
| 0x23 (35) | without registers[23] `AUX_XOUT_H`=1.000000 | 1.000000 |
| 0x24 (36) | without registers[24] `AUX_XOUT_L`=1.000000 | 1.000000 |
| 0x25 (37) | without registers[25] `AUX_YOUT_H`=1.000000 | 1.000000 |
| 0x26 (38) | without registers[26] `AUX_YOUT_L`=1.000000 | 1.000000 |
| 0x27 (39) | without registers[27] `AUX_ZOUT_H`=1.000000 | 1.000000 |
| 0x28 (40) | without registers[28] `AUX_ZOUT_L`=1.000000 | 1.000000 |
| 0x3A (58) | without registers[29] `FIFO_COUNTH`=0.953273 | 0.953273 |
| 0x3B (59) | without registers[30] `FIFO_COUNTL`=1.000000 | 1.000000 |
| 0x3C (60) | without registers[31] `FIFO_R`=0.991637 | 0.991637 |
| 0x3D (61) | without registers[32] `USER_CTRL`=0.964955 | 0.964955 |
| 0x3E (62) | without registers[33] `PWR_MGM`=1.000000 | 1.000000 |

\(\sum_{R=1}^{34}q_R=\mathbf{33.722893451}\).

\(m=34,\ x=0,\ \frac{m}{m+x}=\frac{34}{34+0}=1.000000\).

Missing truth physical addresses: none.
Extra extracted physical addresses: none.

\[S_{final}=\left(\frac{10}{34}\times 33.722893451\right)\times\frac{34}{34+0}=\boxed{\mathbf{9.918498074/10}}\]

## 3. Detailed deduction inventory

The following entries are the exact scored deviations. The preceding sections contain the complete bottom-up table for every logical register, field part, and truth bit-field target.

### 3.1 Objective-fact errors and omissions

| Exact location | Field | Truth content | without content | C | Judgment |
|---|---|---|---|---:|---|
| `without registers[0].field_parts[0].bit_field[1]` | `values` | {"value":"110 100","value_description":"Power-On-Reset value of Bit6:Bit1"} | [] | 0.0 | truth value enumeration is missing from without |
| `without registers[0].field_parts[0].bit_field[1]` | `type_write_read` | R | RW | 0.0 | truth type_write_read='R', without has 'RW' |
| `without registers[0].field_parts[0].bit_field[2]` | `values` | [{"value":0,"value_description":""},{"value":1,"value_description":""}] | [] | 0.0 | truth value enumeration is missing from without |
| `truth registers[8].field_parts.bit_field[0]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[0]` | `field_description` | Load zeros into bits 7..3 (must be 0). | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[0]` | `bit_start` | 3 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[0]` | `bit_end` | 7 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[0]` | `bit_width` | 5 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[0]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[0]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[0]` | `type_write_read` | "" | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `without registers[8].field_parts[0].bit_field[0]` | `values` | [] | [{"value":"1","value_description":"VDD"},{"value":"0","value_description":"VLOGIC"}] | 0.0 | without adds unsupported objective value codes where truth has none |
| `truth registers[8].field_parts.bit_field[2]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[2]` | `field_description` | Load zeros into bits 1..0 (must be 0). | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[2]` | `bit_start` | 0 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[2]` | `bit_end` | 1 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[2]` | `bit_width` | 2 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[2]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[2]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[8].field_parts.bit_field[2]` | `type_write_read` | "" | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `without registers[9].field_parts[0].bit_field[0]` | `values` | [] | [{"value":"1","value_description":"reference clock output enabled at CLKOUT pin"},{"value":"0","value_description":"function disabled"}] | 0.0 | without adds unsupported objective value codes where truth has none |
| `truth registers[12].field_parts.bit_field[4]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[4]` | `field_description` | No function defined for this bit (reserved). | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[4]` | `bit_start` | 3 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[4]` | `bit_end` | 3 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[4]` | `bit_width` | 1 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[4]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[4]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[4]` | `type_write_read` | "" | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[6]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[6]` | `field_description` | No function defined for this bit (reserved). | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[6]` | `bit_start` | 1 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[6]` | `bit_end` | 1 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[6]` | `bit_width` | 1 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[6]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[6]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[12].field_parts.bit_field[6]` | `type_write_read` | "" | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[0]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[0]` | `field_description` | No function defined for these bits (reserved). | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[0]` | `bit_start` | 3 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[0]` | `bit_end` | 7 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[0]` | `bit_width` | 5 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[0]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[0]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[0]` | `type_write_read` | R | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[1]` | `name_or_parameter` | ITG_RDY | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[1]` | `field_description` | PLL ready. | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[1]` | `bit_start` | 2 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[1]` | `bit_end` | 2 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[1]` | `bit_width` | 1 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[1]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[1]` | `is_reserved` | False | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[1]` | `type_write_read` | R | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[2]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[2]` | `field_description` | No function defined for this bit (reserved). | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[2]` | `bit_start` | 1 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[2]` | `bit_end` | 1 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[2]` | `bit_width` | 1 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[2]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[2]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[14].field_parts.bit_field[2]` | `type_write_read` | "" | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[29].field_parts.bit_field[0]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[29].field_parts.bit_field[0]` | `field_description` | No function defined for these bits (reserved). | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[29].field_parts.bit_field[0]` | `bit_start` | 2 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[29].field_parts.bit_field[0]` | `bit_end` | 7 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[29].field_parts.bit_field[0]` | `bit_width` | 6 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[29].field_parts.bit_field[0]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[29].field_parts.bit_field[0]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[29].field_parts.bit_field[0]` | `type_write_read` | "" | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `without registers[31].field_parts[0]` | `register_name` | FIFO_DATA | FIFO_R | 0.0 | register_name is objectively different |
| `truth registers[32].field_parts.bit_field[0]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[0]` | `field_description` | No function defined for this bit (reserved). | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[0]` | `bit_start` | 7 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[0]` | `bit_end` | 7 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[0]` | `bit_width` | 1 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[0]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[0]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[0]` | `type_write_read` | "" | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[3]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[3]` | `field_description` | No function defined for this bit (reserved). | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[3]` | `bit_start` | 4 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[3]` | `bit_end` | 4 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[3]` | `bit_width` | 1 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[3]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[3]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[3]` | `type_write_read` | "" | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[5]` | `name_or_parameter` | Reserved | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[5]` | `field_description` | No function defined for this bit (reserved). | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[5]` | `bit_start` | 2 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[5]` | `bit_end` | 2 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[5]` | `bit_width` | 1 | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[5]` | `values` | [] | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[5]` | `is_reserved` | True | ∅ | 0.0 | truth bit-field target has no exact without bit range |
| `truth registers[32].field_parts.bit_field[5]` | `type_write_read` | "" | ∅ | 0.0 | truth bit-field target has no exact without bit range |

### 3.2 Unmatched without bit ranges

These without bit fields do not have an exact truth bit_start/bit_end target. They are reported for auditability and are not independently credited or added to the physical-register extra-address penalty. For reserved entries, placeholder/omitted names and descriptions are allowed; the remaining deduction is only the unmatched exact-range grouping.

| without location | Truth part target | without name | without range |
|---|---|---|---|
| `without registers[14].field_parts[0].bit_field[0]` | `truth registers[14].field_parts` | ITG_RDY | 5:5 |

### 3.3 Description differences accepted under the requested leniency

Nonempty descriptions whose meaning is preserved are not deducted; missing descriptions remain in section 3.1.

| Truth location | without location | Field | Truth content | without content | Result |
|---|---|---|---|---|---|
| `truth registers[0].field_parts.bit_field[0]` | `without registers[0].field_parts[0].bit_field[0]` | `field_description` | Setting this bit disables I²C access mode. | Setting this bit disables I²C access mode | C=1.0, semantically equivalent |
| `truth registers[0].field_parts.bit_field[1]` | `without registers[0].field_parts[0].bit_field[1]` | `field_description` | Contains the 6-bit I²C address of the device. The Power-On-Reset value of Bit6:Bit1 is 110 100. | 6-bit I²C address of the device (Power-On-Reset value of bits6:1 = 110100) | C=1.0, semantically equivalent |
| `truth registers[0].field_parts.bit_field[2]` | `without registers[0].field_parts[0].bit_field[2]` | `field_description` | Bit0 is reserved (may be 0 or 1). | Reserved (may be 0 or 1) | C=1.0, semantically equivalent |
| `truth registers[0].register_description` | `without registers[0].register_description` | `register_description` | This register is used to verify the identity of the device, and to enable/disable the I²C interface. | Used to verify device identity and to enable/disable the I²C interface. | C=1.0, semantically equivalent |
| `truth registers[1].field_parts.bit_field` | `without registers[1].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit X gyro offset (two's complement). | High byte of 16-bit X gyro offset (2's complement) | C=1.0, semantically equivalent |
| `truth registers[1].field_parts` | `without registers[1].field_parts[0]` | `description` | High byte of 16-bit X gyro offset (two's complement). | X_OFFS_H (high byte of X gyro offset) | C=1.0, semantically equivalent |
| `truth registers[1].register_description` | `without registers[1].register_description` | `register_description` | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | High byte of 16-bit X-axis gyro offset (two's complement). Used to remove DC bias from gyro outputs. | C=1.0, semantically equivalent |
| `truth registers[2].field_parts.bit_field` | `without registers[2].field_parts[0].bit_field[0]` | `field_description` | Low byte of 16-bit X gyro offset (two's complement). | Low byte of 16-bit X gyro offset (2's complement) | C=1.0, semantically equivalent |
| `truth registers[2].field_parts` | `without registers[2].field_parts[0]` | `description` | Low byte of 16-bit X gyro offset (two's complement). | X_OFFS_L (low byte of X gyro offset) | C=1.0, semantically equivalent |
| `truth registers[2].register_description` | `without registers[2].register_description` | `register_description` | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | Low byte of 16-bit X-axis gyro offset (two's complement). Used to remove DC bias from gyro outputs. | C=1.0, semantically equivalent |
| `truth registers[3].field_parts.bit_field` | `without registers[3].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Y gyro offset (two's complement). | High byte of 16-bit Y gyro offset (2's complement) | C=1.0, semantically equivalent |
| `truth registers[3].field_parts` | `without registers[3].field_parts[0]` | `description` | High byte of 16-bit Y gyro offset (two's complement). | Y_OFFS_H (high byte of Y gyro offset) | C=1.0, semantically equivalent |
| `truth registers[3].register_description` | `without registers[3].register_description` | `register_description` | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | High byte of 16-bit Y-axis gyro offset (two's complement). Used to remove DC bias from gyro outputs. | C=1.0, semantically equivalent |
| `truth registers[4].field_parts.bit_field` | `without registers[4].field_parts[0].bit_field[0]` | `field_description` | Low byte of 16-bit Y gyro offset (two's complement). | Low byte of 16-bit Y gyro offset (2's complement) | C=1.0, semantically equivalent |
| `truth registers[4].field_parts` | `without registers[4].field_parts[0]` | `description` | Low byte of 16-bit Y gyro offset (two's complement). | Y_OFFS_L (low byte of Y gyro offset) | C=1.0, semantically equivalent |
| `truth registers[4].register_description` | `without registers[4].register_description` | `register_description` | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | Low byte of 16-bit Y-axis gyro offset (two's complement). Used to remove DC bias from gyro outputs. | C=1.0, semantically equivalent |
| `truth registers[5].field_parts.bit_field` | `without registers[5].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Z gyro offset (two's complement). | High byte of 16-bit Z gyro offset (2's complement) | C=1.0, semantically equivalent |
| `truth registers[5].field_parts` | `without registers[5].field_parts[0]` | `description` | High byte of 16-bit Z gyro offset (two's complement). | Z_OFFS_H (high byte of Z gyro offset) | C=1.0, semantically equivalent |
| `truth registers[5].register_description` | `without registers[5].register_description` | `register_description` | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | High byte of 16-bit Z-axis gyro offset (two's complement). Used to remove DC bias from gyro outputs. | C=1.0, semantically equivalent |
| `truth registers[6].field_parts.bit_field` | `without registers[6].field_parts[0].bit_field[0]` | `field_description` | Low byte of 16-bit Z gyro offset (two's complement). | Low byte of 16-bit Z gyro offset (2's complement) | C=1.0, semantically equivalent |
| `truth registers[6].field_parts` | `without registers[6].field_parts[0]` | `description` | Low byte of 16-bit Z gyro offset (two's complement). | Z_OFFS_L (low byte of Z gyro offset) | C=1.0, semantically equivalent |
| `truth registers[6].register_description` | `without registers[6].register_description` | `register_description` | These registers are used to remove DC bias from the sensor outputs. The values in these registers are subtracted from the gyro sensor values before going into the sensor registers (see registers addr.(decimal) 27 to 34). | Low byte of 16-bit Z-axis gyro offset (two's complement). Used to remove DC bias from gyro outputs. | C=1.0, semantically equivalent |
| `truth registers[7].field_parts.bit_field[0]` | `without registers[7].field_parts[0].bit_field[0]` | `field_description` | Setting this inserts the Temperature reading into FIFO. | Insert Temperature reading into FIFO | C=1.0, semantically equivalent |
| `truth registers[7].field_parts.bit_field[1]` | `without registers[7].field_parts[0].bit_field[1]` | `field_description` | Setting this inserts the X Gyro reading into FIFO. | Insert X Gyro reading into FIFO | C=1.0, semantically equivalent |
| `truth registers[7].field_parts.bit_field[2]` | `without registers[7].field_parts[0].bit_field[2]` | `field_description` | Setting this inserts the Y Gyro reading into FIFO. | Insert Y Gyro reading into FIFO | C=1.0, semantically equivalent |
| `truth registers[7].field_parts.bit_field[3]` | `without registers[7].field_parts[0].bit_field[3]` | `field_description` | Setting this inserts the Z Gyro reading into FIFO. | Insert Z Gyro reading into FIFO | C=1.0, semantically equivalent |
| `truth registers[7].field_parts.bit_field[4]` | `without registers[7].field_parts[0].bit_field[4]` | `field_description` | Setting this inserts the X Accelerometer reading into FIFO. | Insert X accelerometer reading into FIFO | C=1.0, semantically equivalent |
| `truth registers[7].field_parts.bit_field[5]` | `without registers[7].field_parts[0].bit_field[5]` | `field_description` | Setting this inserts the Y Accelerometer reading into FIFO. | Insert Y accelerometer reading into FIFO | C=1.0, semantically equivalent |
| `truth registers[7].field_parts.bit_field[6]` | `without registers[7].field_parts[0].bit_field[6]` | `field_description` | Setting this inserts the Z Accelerometer reading into FIFO. | Insert Z accelerometer reading into FIFO | C=1.0, semantically equivalent |
| `truth registers[7].field_parts.bit_field[7]` | `without registers[7].field_parts[0].bit_field[7]` | `field_description` | Last word (2 bytes) for FIFO read; described in more detail in register 60. | Include FIFO footer (last word) in FIFO | C=1.0, semantically equivalent |
| `truth registers[7].field_parts` | `without registers[7].field_parts[0]` | `description` | Enable selection for data inserted into FIFO; each bit inserts the listed data into the FIFO when set. | Enable selection bits for FIFO data sources | C=1.0, semantically equivalent |
| `truth registers[7].register_description` | `without registers[7].register_description` | `register_description` | Determines what data goes into the ITG-3050 FIFO (512 byte FIFO); sensor data is automatically placed into the FIFO after each ADC sampling period. | Determines which sensor data words are written into the 512-byte FIFO (TEMP, gyro axes, aux accel axes, FIFO footer). | C=1.0, semantically equivalent |
| `truth registers[8].field_parts.bit_field[1]` | `without registers[8].field_parts[0].bit_field[0]` | `field_description` | I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1=VDD, 0=VLOGIC. | I/O logic for AUX bus: 1=VDD, 0=VLOGIC | C=1.0, semantically equivalent |
| `truth registers[8].field_parts` | `without registers[8].field_parts[0]` | `description` | I/O logic level selection for the secondary I²C bus lines; other bits must be written as zeros. | I/O logic level selection for secondary I²C bus | C=1.0, semantically equivalent |
| `truth registers[8].register_description` | `without registers[8].register_description` | `register_description` | Determines the I/O logic levels for the secondary I²C bus clock and data lines (AUX_CL, AUX_DA). 1 = VDD, 0 = VLOGIC. | Determines I/O logic level for secondary I²C bus (AUX_CL, AUX_DA): 1 = VDD, 0 = VLOGIC. | C=1.0, semantically equivalent |
| `truth registers[9].field_parts.bit_field[0]` | `without registers[9].field_parts[0].bit_field[0]` | `field_description` | 1 = reference clock output is provided at CLKOUT pin; 0 = function disabled. | Reference clock output enable at CLKOUT pin (1=enabled, 0=disabled) | C=1.0, semantically equivalent |
| `truth registers[9].field_parts.bit_field[1]` | `without registers[9].field_parts[0].bit_field[1]` | `field_description` | Contains the I²C address of the external accelerometer device (bits 6:0). | 7-bit I²C address of the external accelerometer | C=1.0, semantically equivalent |
| `truth registers[9].field_parts` | `without registers[9].field_parts[0]` | `description` | CLKOUT enable and auxiliary device address (AUX_ID). | CLKOUT enable and auxiliary device I²C address | C=1.0, semantically equivalent |
| `truth registers[9].register_description` | `without registers[9].register_description` | `register_description` | Contains the 7-bit slave address of the external accelerometer device and the CLKOUT enable bit. Used by the ITG-3050 when acting as I²C master for the auxiliary sensor. | Contains 7-bit I²C address of external accelerometer (AUX_ID) and CLKOUT enable bit for reference clock output. | C=1.0, semantically equivalent |
| `truth registers[10].field_parts.bit_field` | `without registers[10].field_parts[0].bit_field[0]` | `field_description` | Sample rate divider. F_sample = F_internal / (divider + 1). | Sample rate divider (0–255) | C=1.0, semantically equivalent |
| `truth registers[10].field_parts` | `without registers[10].field_parts[0]` | `description` | Sample rate divider (0-255). | Divider for delivered sample rate | C=1.0, semantically equivalent |
| `truth registers[10].register_description` | `without registers[10].register_description` | `register_description` | Determines the sample rate of the ITG-3050 gyros. F_sample = F_internal / (divider + 1), where F_internal is either 1kHz or 8kHz (set by DLPF_CFG). | Sample rate divider; sample rate = F_internal / (divider + 1). F_internal is 1kHz or 8kHz depending on DLPF_CFG. | C=1.0, semantically equivalent |
| `truth registers[11].field_parts.bit_field[0]` | `without registers[11].field_parts[0].bit_field[0]` | `field_description` | Routing for the external frame synchronization input bit. | Routing for external frame synchronization input (FSYNC) inserted into LSB of selected register | C=1.0, semantically equivalent |
| `truth registers[11].field_parts.bit_field[1]` | `without registers[11].field_parts[0].bit_field[1]` | `field_description` | Full scale selection for gyro sensor data. | Full-scale selection for gyro sensor data | C=1.0, semantically equivalent |
| `truth registers[11].field_parts.bit_field[2]` | `without registers[11].field_parts[0].bit_field[2]` | `field_description` | Digital low pass filter configuration; also determines internal analog sampling rate. | Digital low pass filter configuration (also selects analog sample rate) | C=1.0, semantically equivalent |
| `truth registers[11].field_parts` | `without registers[11].field_parts[0]` | `description` | EXT_SYNC_SET (bits7:5), FS_SEL (bits4:3), DLPF_CFG (bits2:0). | EXT_SYNC_SET, FS_SEL, and DLPF_CFG fields | C=1.0, semantically equivalent |
| `truth registers[11].register_description` | `without registers[11].register_description` | `register_description` | Configures external sync routing (EXT_SYNC_SET), full-scale range (FS_SEL), and digital low-pass filter (DLPF_CFG). | Configures external sync routing (EXT_SYNC_SET), gyro full-scale range (FS_SEL), and digital low-pass filter (DLPF_CFG) and determines internal analog sampling rate. | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[0]` | `without registers[12].field_parts[0].bit_field[0]` | `field_description` | Logic level for INT output pin - 1=active low, 0=active high. | Logic level for INT output pin – 1=active low, 0=active high | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[1]` | `without registers[12].field_parts[0].bit_field[1]` | `field_description` | Drive type for INT output pin - 1=open drain, 0=push-pull. | Drive type for INT output pin – 1=open drain, 0=push-pull | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[2]` | `without registers[12].field_parts[0].bit_field[2]` | `field_description` | "Latch mode - 1=latch until interrupt is cleared, 0=50\u0000us pulse." | Latch mode – 1=latch until interrupt is cleared, 0=50µs pulse | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[3]` | `without registers[12].field_parts[0].bit_field[3]` | `field_description` | Interrupt status register clear method - 1=clear by reading any register, 0=clear by reading interrupt status register (26) only. | Interrupt clear method – 1=clear by reading any register, 0=clear by reading INT_STATUS only | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[5]` | `without registers[12].field_parts[0].bit_field[4]` | `field_description` | Enable interrupt when device is ready (PLL ready after changing clock source). | Enable interrupt when device PLL/clock source is ready | C=1.0, semantically equivalent |
| `truth registers[12].field_parts.bit_field[7]` | `without registers[12].field_parts[0].bit_field[5]` | `field_description` | Enable interrupt when data is available (raw data ready). | Enable interrupt when new raw data is available | C=1.0, semantically equivalent |
| `truth registers[12].field_parts` | `without registers[12].field_parts[0]` | `description` | Interrupt pin configuration, latch mode, and interrupt enables. | Interrupt output and trigger configuration | C=1.0, semantically equivalent |
| `truth registers[12].register_description` | `without registers[12].register_description` | `register_description` | Configures the interrupt operation: INT pin polarity and drive type, latch/clear behavior, and which sources generate interrupts. | Configures INT pin polarity, drive type, latch method, clear method, and enables for device-ready and raw-data-ready interrupts. | C=1.0, semantically equivalent |
| `truth registers[13].field_parts.bit_field` | `without registers[13].field_parts[0].bit_field[0]` | `field_description` | Burst-mode read starting address for external accelerometer attached to secondary I2C bus. | Starting address in the external accelerometer for burst reads | C=1.0, semantically equivalent |
| `truth registers[13].field_parts` | `without registers[13].field_parts[0]` | `description` | Burst-mode read starting address for external accelerometer (BURST_ADDR). | Burst-mode read starting address (AUX) | C=1.0, semantically equivalent |
| `truth registers[13].register_description` | `without registers[13].register_description` | `register_description` | Configures the burst-mode-read starting address for an accelerometer attached to the secondary I2C bus of the ITG-3050. | Burst-mode read starting address for external accelerometer attached to the secondary I²C bus. | C=1.0, semantically equivalent |
| `truth registers[14].field_parts.bit_field[3]` | `without registers[14].field_parts[0].bit_field[1]` | `field_description` | Raw data or FIFO data is ready. | Raw sensor or FIFO data ready | C=1.0, semantically equivalent |
| `truth registers[14].field_parts` | `without registers[14].field_parts[0]` | `description` | Interrupt status bits. | Interrupt status bits | C=1.0, semantically equivalent |
| `truth registers[14].register_description` | `without registers[14].register_description` | `register_description` | Indicates the status of interrupt sources. Bits are set when corresponding interrupt sources are triggered. Interrupt status bits are cleared as determined by INT_ANYRD_2CLEAR. | Indicates status of interrupt sources (device ready and raw data ready). Bits cleared according to INT_ANYRD_2CLEAR setting. | C=1.0, semantically equivalent |
| `truth registers[15].field_parts.bit_field` | `without registers[15].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit temperature data (two's complement). | TEMP_OUT[15:8] high byte of temperature measurement (2's complement) | C=1.0, semantically equivalent |
| `truth registers[15].field_parts` | `without registers[15].field_parts[0]` | `description` | High byte of 16-bit temperature data (two's complement). | High byte of TEMP_OUT (MSB) | C=1.0, semantically equivalent |
| `truth registers[15].register_description` | `without registers[15].register_description` | `register_description` | High byte of 16-bit temperature data (two's complement). | High byte of 16-bit temperature sensor reading (two's complement). | C=1.0, semantically equivalent |
| `truth registers[16].field_parts.bit_field` | `without registers[16].field_parts[0].bit_field[0]` | `field_description` | Low byte of 16-bit temperature data (two's complement). | TEMP_OUT[7:0] low byte of temperature measurement (2's complement) | C=1.0, semantically equivalent |
| `truth registers[16].field_parts` | `without registers[16].field_parts[0]` | `description` | Low byte of 16-bit temperature data (two's complement). | Low byte of TEMP_OUT (LSB) | C=1.0, semantically equivalent |
| `truth registers[16].register_description` | `without registers[16].register_description` | `register_description` | Low byte of 16-bit temperature data (two's complement). | Low byte of 16-bit temperature sensor reading (two's complement). | C=1.0, semantically equivalent |
| `truth registers[17].field_parts.bit_field` | `without registers[17].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit X gyro output (two's complement). | GYRO_XOUT[15:8] high byte of X gyro measurement (2's complement) | C=1.0, semantically equivalent |
| `truth registers[17].field_parts` | `without registers[17].field_parts[0]` | `description` | High byte of 16-bit X gyro output (two's complement). | High byte of GYRO_XOUT (MSB) | C=1.0, semantically equivalent |
| `truth registers[17].register_description` | `without registers[17].register_description` | `register_description` | High byte of 16-bit X gyro output data (two's complement). | High byte of 16-bit X-axis gyro output (two's complement). | C=1.0, semantically equivalent |
| `truth registers[18].field_parts.bit_field` | `without registers[18].field_parts[0].bit_field[0]` | `field_description` | Low byte of 16-bit X gyro output (two's complement). | GYRO_XOUT[7:0] low byte of X gyro measurement (2's complement) | C=1.0, semantically equivalent |
| `truth registers[18].field_parts` | `without registers[18].field_parts[0]` | `description` | Low byte of 16-bit X gyro output (two's complement). | Low byte of GYRO_XOUT (LSB) | C=1.0, semantically equivalent |
| `truth registers[18].register_description` | `without registers[18].register_description` | `register_description` | Low byte of 16-bit X gyro output data (two's complement). | Low byte of 16-bit X-axis gyro output (two's complement). | C=1.0, semantically equivalent |
| `truth registers[19].field_parts.bit_field` | `without registers[19].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Y gyro output (two's complement). | GYRO_YOUT[15:8] high byte of Y gyro measurement (2's complement) | C=1.0, semantically equivalent |
| `truth registers[19].field_parts` | `without registers[19].field_parts[0]` | `description` | High byte of 16-bit Y gyro output (two's complement). | High byte of GYRO_YOUT (MSB) | C=1.0, semantically equivalent |
| `truth registers[19].register_description` | `without registers[19].register_description` | `register_description` | High byte of 16-bit Y gyro output data (two's complement). | High byte of 16-bit Y-axis gyro output (two's complement). | C=1.0, semantically equivalent |
| `truth registers[20].field_parts.bit_field` | `without registers[20].field_parts[0].bit_field[0]` | `field_description` | Low byte of 16-bit Y gyro output (two's complement). | GYRO_YOUT[7:0] low byte of Y gyro measurement (2's complement) | C=1.0, semantically equivalent |
| `truth registers[20].field_parts` | `without registers[20].field_parts[0]` | `description` | Low byte of 16-bit Y gyro output (two's complement). | Low byte of GYRO_YOUT (LSB) | C=1.0, semantically equivalent |
| `truth registers[20].register_description` | `without registers[20].register_description` | `register_description` | Low byte of 16-bit Y gyro output data (two's complement). | Low byte of 16-bit Y-axis gyro output (two's complement). | C=1.0, semantically equivalent |
| `truth registers[21].field_parts.bit_field` | `without registers[21].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Z gyro output (two's complement). | GYRO_ZOUT[15:8] high byte of Z gyro measurement (2's complement) | C=1.0, semantically equivalent |
| `truth registers[21].field_parts` | `without registers[21].field_parts[0]` | `description` | High byte of 16-bit Z gyro output (two's complement). | High byte of GYRO_ZOUT (MSB) | C=1.0, semantically equivalent |
| `truth registers[21].register_description` | `without registers[21].register_description` | `register_description` | High byte of 16-bit Z gyro output data (two's complement). | High byte of 16-bit Z-axis gyro output (two's complement). | C=1.0, semantically equivalent |
| `truth registers[22].field_parts.bit_field` | `without registers[22].field_parts[0].bit_field[0]` | `field_description` | Low byte of 16-bit Z gyro output (two's complement). | GYRO_ZOUT[7:0] low byte of Z gyro measurement (2's complement) | C=1.0, semantically equivalent |
| `truth registers[22].field_parts` | `without registers[22].field_parts[0]` | `description` | Low byte of 16-bit Z gyro output (two's complement). | Low byte of GYRO_ZOUT (LSB) | C=1.0, semantically equivalent |
| `truth registers[22].register_description` | `without registers[22].register_description` | `register_description` | Low byte of 16-bit Z gyro output data (two's complement). | Low byte of 16-bit Z-axis gyro output (two's complement). | C=1.0, semantically equivalent |
| `truth registers[23].field_parts.bit_field` | `without registers[23].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit X auxiliary (accel) output. | AUX_XOUT[15:8] high byte of auxiliary X-axis measurement | C=1.0, semantically equivalent |
| `truth registers[23].field_parts` | `without registers[23].field_parts[0]` | `description` | High byte of 16-bit X auxiliary (accel) output. | High byte of AUX_XOUT (MSB) | C=1.0, semantically equivalent |
| `truth registers[23].register_description` | `without registers[23].register_description` | `register_description` | High byte of 16-bit auxiliary X-axis output (as available from auxiliary device). | High byte of 16-bit AUX (accelerometer) X-axis output as read via the auxiliary interface. | C=1.0, semantically equivalent |
| `truth registers[24].field_parts.bit_field` | `without registers[24].field_parts[0].bit_field[0]` | `field_description` | Low byte of 16-bit X auxiliary (accel) output. | AUX_XOUT[7:0] low byte of auxiliary X-axis measurement | C=1.0, semantically equivalent |
| `truth registers[24].field_parts` | `without registers[24].field_parts[0]` | `description` | Low byte of 16-bit X auxiliary (accel) output. | Low byte of AUX_XOUT (LSB) | C=1.0, semantically equivalent |
| `truth registers[24].register_description` | `without registers[24].register_description` | `register_description` | Low byte of 16-bit auxiliary X-axis output (as available from auxiliary device). | Low byte of 16-bit AUX (accelerometer) X-axis output as read via the auxiliary interface. | C=1.0, semantically equivalent |
| `truth registers[25].field_parts.bit_field` | `without registers[25].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Y auxiliary (accel) output. | AUX_YOUT[15:8] high byte of auxiliary Y-axis measurement | C=1.0, semantically equivalent |
| `truth registers[25].field_parts` | `without registers[25].field_parts[0]` | `description` | High byte of 16-bit Y auxiliary (accel) output. | High byte of AUX_YOUT (MSB) | C=1.0, semantically equivalent |
| `truth registers[25].register_description` | `without registers[25].register_description` | `register_description` | High byte of 16-bit auxiliary Y-axis output (as available from auxiliary device). | High byte of 16-bit AUX (accelerometer) Y-axis output as read via the auxiliary interface. | C=1.0, semantically equivalent |
| `truth registers[26].field_parts.bit_field` | `without registers[26].field_parts[0].bit_field[0]` | `field_description` | Low byte of 16-bit Y auxiliary (accel) output. | AUX_YOUT[7:0] low byte of auxiliary Y-axis measurement | C=1.0, semantically equivalent |
| `truth registers[26].field_parts` | `without registers[26].field_parts[0]` | `description` | Low byte of 16-bit Y auxiliary (accel) output. | Low byte of AUX_YOUT (LSB) | C=1.0, semantically equivalent |
| `truth registers[26].register_description` | `without registers[26].register_description` | `register_description` | Low byte of 16-bit auxiliary Y-axis output (as available from auxiliary device). | Low byte of 16-bit AUX (accelerometer) Y-axis output as read via the auxiliary interface. | C=1.0, semantically equivalent |
| `truth registers[27].field_parts.bit_field` | `without registers[27].field_parts[0].bit_field[0]` | `field_description` | High byte of 16-bit Z auxiliary (accel) output. | AUX_ZOUT[15:8] high byte of auxiliary Z-axis measurement | C=1.0, semantically equivalent |
| `truth registers[27].field_parts` | `without registers[27].field_parts[0]` | `description` | High byte of 16-bit Z auxiliary (accel) output. | High byte of AUX_ZOUT (MSB) | C=1.0, semantically equivalent |
| `truth registers[27].register_description` | `without registers[27].register_description` | `register_description` | High byte of 16-bit auxiliary Z-axis output (as available from auxiliary device). | High byte of 16-bit AUX (accelerometer) Z-axis output as read via the auxiliary interface. | C=1.0, semantically equivalent |
| `truth registers[28].field_parts.bit_field` | `without registers[28].field_parts[0].bit_field[0]` | `field_description` | Low byte of 16-bit Z auxiliary (accel) output. | AUX_ZOUT[7:0] low byte of auxiliary Z-axis measurement | C=1.0, semantically equivalent |
| `truth registers[28].field_parts` | `without registers[28].field_parts[0]` | `description` | Low byte of 16-bit Z auxiliary (accel) output. | Low byte of AUX_ZOUT (LSB) | C=1.0, semantically equivalent |
| `truth registers[28].register_description` | `without registers[28].register_description` | `register_description` | Low byte of 16-bit auxiliary Z-axis output (as available from auxiliary device). | Low byte of 16-bit AUX (accelerometer) Z-axis output as read via the auxiliary interface. | C=1.0, semantically equivalent |
| `truth registers[29].field_parts.bit_field[1]` | `without registers[29].field_parts[0].bit_field[0]` | `field_description` | High bits of the number of bytes currently in FIFO. | High portion of FIFO byte count | C=1.0, semantically equivalent |
| `truth registers[29].field_parts` | `without registers[29].field_parts[0]` | `description` | High portion of FIFO byte count. | High bits of FIFO byte count | C=1.0, semantically equivalent |
| `truth registers[29].register_description` | `without registers[29].register_description` | `register_description` | Indicates how many bytes of valid data are contained in the FIFO (high part). | High part of the number of valid bytes currently in the FIFO. | C=1.0, semantically equivalent |
| `truth registers[30].field_parts.bit_field` | `without registers[30].field_parts[0].bit_field[0]` | `field_description` | Low byte of the number of bytes currently in FIFO. | Low portion of FIFO byte count | C=1.0, semantically equivalent |
| `truth registers[30].field_parts` | `without registers[30].field_parts[0]` | `description` | Low portion of FIFO byte count. | Low 8 bits of FIFO byte count | C=1.0, semantically equivalent |
| `truth registers[30].register_description` | `without registers[30].register_description` | `register_description` | Indicates how many bytes of valid data are contained in the FIFO (low part). | Low part of the number of valid bytes currently in the FIFO. | C=1.0, semantically equivalent |
| `truth registers[31].field_parts.bit_field` | `without registers[31].field_parts[0].bit_field[0]` | `field_description` | FIFO data byte. | FIFO output data byte | C=1.0, semantically equivalent |
| `truth registers[31].field_parts` | `without registers[31].field_parts[0]` | `description` | FIFO output data byte; reading this register fetches the next byte from FIFO. | FIFO data output (one byte per read) | C=1.0, semantically equivalent |
| `truth registers[31].register_description` | `without registers[31].register_description` | `register_description` | Output register of the FIFO. Each read returns the oldest contents of the FIFO buffer; a burst read is required to read multiple bytes. | FIFO data output register. Reading returns oldest FIFO contents; burst read auto-increments and prefetches. | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[1]` | `without registers[32].field_parts[0].bit_field[0]` | `field_description` | Enable FIFO operation for sensor data. | Enable FIFO operation for sensor data | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[2]` | `without registers[32].field_parts[0].bit_field[1]` | `field_description` | Enable 3rd-party accelerometer interface via I²C. Clear this bit to enable bypass mode (host direct access to accel). | Enable auxiliary I²C master interface (1 = master); clearing enables bypass mode for host access | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[4]` | `without registers[32].field_parts[0].bit_field[2]` | `field_description` | Reset third-party accelerometer interface function; set this only after changing AUX_IF_EN to 0. | Reset third-party accelerometer interface (use after changing AUX_IF_EN to 0) | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[6]` | `without registers[32].field_parts[0].bit_field[3]` | `field_description` | Reset FIFO function; set this to clear FIFO or when changing FIFO_EN. | Reset FIFO function; clears FIFO and should be used when changing FIFO_EN | C=1.0, semantically equivalent |
| `truth registers[32].field_parts.bit_field[7]` | `without registers[32].field_parts[0].bit_field[4]` | `field_description` | Reset gyro analog and digital functions. | Reset gyro analog and digital functions | C=1.0, semantically equivalent |
| `truth registers[32].field_parts` | `without registers[32].field_parts[0]` | `description` | Control and reset bits for FIFO and auxiliary interface functions. | Enable/reset controls for FIFO, AUX interface, and gyro | C=1.0, semantically equivalent |
| `truth registers[32].register_description` | `without registers[32].register_description` | `register_description` | Used to enable/disable and reset various modes and functions (FIFO, AUX I2C master interface, gyro reset). Reset bits are auto-cleared after reset. | Enables and resets FIFO, auxiliary interface (I²C master), and gyro reset functions. | C=1.0, semantically equivalent |
| `truth registers[33].field_parts.bit_field[0]` | `without registers[33].field_parts[0].bit_field[0]` | `field_description` | Reset device and internal registers to the power-up-default settings. | Reset device and internal registers to power-up defaults | C=1.0, semantically equivalent |
| `truth registers[33].field_parts.bit_field[1]` | `without registers[33].field_parts[0].bit_field[1]` | `field_description` | Enable low power sleep mode. | Enable low-power sleep mode (1 = sleep) | C=1.0, semantically equivalent |
| `truth registers[33].field_parts.bit_field[2]` | `without registers[33].field_parts[0].bit_field[2]` | `field_description` | Put gyro X in standby mode (1=standby, 0=normal). | Put X gyro in standby (1=standby, 0=normal) | C=1.0, semantically equivalent |
| `truth registers[33].field_parts.bit_field[3]` | `without registers[33].field_parts[0].bit_field[3]` | `field_description` | Put gyro Y in standby mode (1=standby, 0=normal). | Put Y gyro in standby (1=standby, 0=normal) | C=1.0, semantically equivalent |
| `truth registers[33].field_parts.bit_field[4]` | `without registers[33].field_parts[0].bit_field[4]` | `field_description` | Put gyro Z in standby mode (1=standby, 0=normal). | Put Z gyro in standby (1=standby, 0=normal) | C=1.0, semantically equivalent |
| `truth registers[33].field_parts.bit_field[5]` | `without registers[33].field_parts[0].bit_field[5]` | `field_description` | Select device clock source. | Clock source selection (see CLK_SEL table) | C=1.0, semantically equivalent |
| `truth registers[33].field_parts` | `without registers[33].field_parts[0]` | `description` | Power control bits, standby selections, and clock source selection. | Power, standby, reset and clock source settings | C=1.0, semantically equivalent |
| `truth registers[33].register_description` | `without registers[33].register_description` | `register_description` | Manages power control, clock source selection, standby modes, and device reset. | Power control, clock source selection, standby for individual gyros, and device reset. | C=1.0, semantically equivalent |

### 3.4 Representation normalizations that receive no penalty

- Numeric physical addresses are matched by numeric address, bank, and page; hex spelling, decimal spelling, object-versus-list shape, and semantically equivalent/general nested address-description wording are accepted. When the truth has an address description but the extracted description is empty, the matching numeric address receives C=0.5 for that field.
- Singleton numeric strings such as value code 0 and numeric value 0 are treated as the same objective code.
- Multi-physical logical-register merges such as X_OFFS_H/L, TEMP_OUT_H/L, and FIFO_COUNT_H/L are accepted as grouping equivalents; their one Q(L) is not recalculated separately for each part.

### 3.5 Coverage and extra-physical-register check

- Truth physical-register coverage: 34/34 matched; missing truth locations: 0.
- Extra extracted physical locations: 0; physical-address penalty factor = 1.000000.
- Extracted logical registers: 34; merged multi-physical logical registers: 0.

## 4. Invented-field check

- No extracted physical address lies outside the truth physical-address set.
- Unmatched extracted bit ranges are listed in section 3.2; they are not credited without an exact truth bit_start/bit_end target.
- Added without value enumerations on fields whose truth values are empty are objective unsupported facts and are scored as C=0 in section 3.1.
- Bit-field type_write_read is C=1 when both sides are empty; one-sided or concrete mismatches remain strict. The concrete truth type on INT_STATUS reserved bits is also absent from any exact without target.

