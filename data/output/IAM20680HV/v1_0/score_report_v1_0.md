# IAM-20680HV v1.0 detailed score - datasheet-based

## 1. Scoring basis

- Datasheet source: TDK InvenSense, *IAM-20680HV High Performance Automotive 6-Axis MotionTracking Device*, Document Number `DS-000612`, Revision `1.0`, Rev. Date `02/26/2025`.
- Local source PDF: `D:\python\master_arbeit\data\output\IAM20680HV\IAM20680HV.pdf`.
- Datasheet truth is taken from the printed register map on PDF pp.28-29 and the detailed register descriptions on PDF pp.30-43. The register-map addresses are keyed by numeric address plus bank/page; this device uses empty bank/page.
- Printed-source consistency: the register map on p.29 prints `GYRO_2OUT_H/L` at `0x47/0x48` and `SIGNAL_PAT_H_RESET` at `0x68`; the detailed sections on pp.40-41 identify these as `GYRO_ZOUT_H/L` and `SIGNAL_PATH_RESET`. The detailed section names are used for semantic truth, and v1 matches them.
- The PDF detailed table for `FSYNC_INT` shows bit 7; the register map marks bits [6:0] as `-`, so the lower seven bits are represented as one reserved bit field in the datasheet truth.
- `registers[i]` and nested indices in this report are zero-based locations in `IAM20680HV\v1_0\register_map.json`. Printed PDF page numbers are used for source references.
- There are 38 extracted logical registers and 51 extracted physical field parts. The 13 two-byte logical representations are accepted as equivalent grouping; a logical-register score is calculated once and then associated with each of its physical locations.
- Objective fields are judged strictly: names, numeric addresses, bit ranges, bit widths, read/write behavior, value-code sets, reserved status, default values, and the 15-bit width of the accelerometer offset value. Descriptive text is judged semantically. For a `physical_address` whose numeric address is correct but whose descriptive subfield is empty, `C=0.5`; an empty standalone `description` against a datasheet function is `C=0.0`.
- Because the datasheet gives a register-level access type, that type is the truth value for every contained bit field's `type_write_read`. A blank v1 bit-field type therefore receives no credit. Value descriptions are accepted when the code set and functional meaning are equivalent, even where wording differs.
- Rounded weights are used exactly as specified in AGENTS.md: bit-field denominator `0.9999`, logical-register denominator `1.0001`, field-part weights sum to `1.0000`.

## 2. Version score

| version | logical registers | physical entries | n | m | x | sum q_R | S_final / 10 |
|---|---:|---:|---:|---:|---:|---:|---:|
| v1.0 | 38 | 51 | 51 | 51 | 0 | 42.978833238 | 8.427222203 |

\(S_{final}=\left(\frac{10}{51}\times 42.978833238\right)\times\frac{51}{51+0}=\boxed{\mathbf{8.427222203/10}}\).

## 3. AHP weights and bottom-up procedure

- Bit field: `name_or_parameter` 0.0212, `field_description` 0.0586, `bit_start` 0.2594, `bit_end` 0.2594, `bit_width` 0.0583, `values` 0.2097, `is_reserved` 0.0750, `type_write_read` 0.0583.
- Field part: `register_name` 0.0280, `physical_address` 0.4688, `description` 0.0693, `width_bits` 0.0605, `type_write_read` 0.0605, `bit_field` 0.3129.
- Logical register: `name` 0.0225, `physical_address` 0.4044, `register_description` 0.0564, `width_bits` 0.0590, `type_write_read` 0.0590, `field_parts` 0.2987, `default_value` 0.0667, `default_value_description` 0.0334.
- For every logical register: calculate every bit field first, calculate each field part from its direct fields and the mean of its bit-field scores, then calculate one logical-register `Q(L)` from its direct fields and the mean of its field-part scores. The physical-register score `q_R` is then the mean of all associated logical-register scores.

## 4. Detailed bottom-up calculations

### Extracted logical register 1: `SELF_TEST_X_GYRO`

v1 location: `registers[0]`; datasheet association: PDF p.30, §9.1, Table 26.

Associated physical locations: [{"hex":"0x00","decimal":"0","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `SELF_TEST_X_GYRO` at 0x00 (0)

Location: `v1 registers[0].field_parts[0]`; datasheet source: PDF p.30, §9.1, Table 26.

**Datasheet bit field 1: `XG_ST_DATA[7:0]`, bits [7:0]**

Location: `v1 registers[0].field_parts[0].bit_field[0]`; datasheet source: PDF p.30, §9.1, Table 26. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XG_ST_DATA[7:0] | XG_ST_DATA[7:0] |
| `field_description` | 0.0586 | 1.0 | The value in this register indicates the manufacturing self-test output used to check subsequent end-user self-test outputs. | Manufacturing self-test output used to check subsequent end-user self-test outputs. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | SELF_TEST_X_GYRO | SELF_TEST_X_GYRO |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"SELF_TEST_X_GYRO register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Manufacturing self-test output; used to check subsequent end-user self-test outputs. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | SELF_TEST_X_GYRO | SELF_TEST_X_GYRO |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"SELF_TEST_X_GYRO register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}] | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Manufacturing self-test output; used to check subsequent end-user self-test outputs. | Stores the X-axis gyroscope manufacturing self-test output for comparison with subsequent end-user self-test outputs. Convert the self-test code using ST_OTP = (2620 / 2^FS) × 1.01^(ST_code-1) lsb; ST_code is derived from the documented ST_FAC logarithmic equation. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | Pre-programmed value | Pre-programmed value |
| `default_value_description` | 0.0334 | 1.000000 | Contains a pre-programmed self-test value. | Contains a pre-programmed self-test value. |

\(Q(L_{1})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 2: `SELF_TEST_Y_GYRO`

v1 location: `registers[1]`; datasheet association: PDF p.30, §9.1, Table 26.

Associated physical locations: [{"hex":"0x01","decimal":"1","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `SELF_TEST_Y_GYRO` at 0x01 (1)

Location: `v1 registers[1].field_parts[0]`; datasheet source: PDF p.30, §9.1, Table 26.

**Datasheet bit field 1: `YG_ST_DATA[7:0]`, bits [7:0]**

Location: `v1 registers[1].field_parts[0].bit_field[0]`; datasheet source: PDF p.30, §9.1, Table 26. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YG_ST_DATA[7:0] | YG_ST_DATA[7:0] |
| `field_description` | 0.0586 | 1.0 | The value in this register indicates the manufacturing self-test output used to check subsequent end-user self-test outputs. | Manufacturing self-test output used to check subsequent end-user self-test outputs. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | SELF_TEST_Y_GYRO | SELF_TEST_Y_GYRO |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"SELF_TEST_Y_GYRO register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."} | {"hex":"0x01","decimal":"1","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Manufacturing self-test output; used to check subsequent end-user self-test outputs. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | SELF_TEST_Y_GYRO | SELF_TEST_Y_GYRO |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":"SELF_TEST_Y_GYRO register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}] | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Manufacturing self-test output; used to check subsequent end-user self-test outputs. | Stores the Y-axis gyroscope manufacturing self-test output for comparison with subsequent end-user self-test outputs. Convert the self-test code using ST_OTP = (2620 / 2^FS) × 1.01^(ST_code-1) lsb; ST_code is derived from the documented ST_FAC logarithmic equation. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | Pre-programmed value | Pre-programmed value |
| `default_value_description` | 0.0334 | 1.000000 | Contains a pre-programmed self-test value. | Contains a pre-programmed self-test value. |

\(Q(L_{2})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 3: `SELF_TEST_Z_GYRO`

v1 location: `registers[2]`; datasheet association: PDF p.30, §9.1, Table 26.

Associated physical locations: [{"hex":"0x02","decimal":"2","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `SELF_TEST_Z_GYRO` at 0x02 (2)

Location: `v1 registers[2].field_parts[0]`; datasheet source: PDF p.30, §9.1, Table 26.

**Datasheet bit field 1: `ZG_ST_DATA[7:0]`, bits [7:0]**

Location: `v1 registers[2].field_parts[0].bit_field[0]`; datasheet source: PDF p.30, §9.1, Table 26. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZG_ST_DATA[7:0] | ZG_ST_DATA[7:0] |
| `field_description` | 0.0586 | 1.0 | The value in this register indicates the manufacturing self-test output used to check subsequent end-user self-test outputs. | Manufacturing self-test output used to check subsequent end-user self-test outputs. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | SELF_TEST_Z_GYRO | SELF_TEST_Z_GYRO |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"SELF_TEST_Z_GYRO register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."} | {"hex":"0x02","decimal":"2","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Manufacturing self-test output; used to check subsequent end-user self-test outputs. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | SELF_TEST_Z_GYRO | SELF_TEST_Z_GYRO |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":"SELF_TEST_Z_GYRO register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}] | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Manufacturing self-test output; used to check subsequent end-user self-test outputs. | Stores the Z-axis gyroscope manufacturing self-test output for comparison with subsequent end-user self-test outputs. Convert the self-test code using ST_OTP = (2620 / 2^FS) × 1.01^(ST_code-1) lsb; ST_code is derived from the documented ST_FAC logarithmic equation. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | Pre-programmed value | Pre-programmed value |
| `default_value_description` | 0.0334 | 1.000000 | Contains a pre-programmed self-test value. | Contains a pre-programmed self-test value. |

\(Q(L_{3})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 4: `SELF_TEST_X_ACCEL`

v1 location: `registers[3]`; datasheet association: PDF p.30, §9.2, Table 27.

Associated physical locations: [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `SELF_TEST_X_ACCEL` at 0x0D (13)

Location: `v1 registers[3].field_parts[0]`; datasheet source: PDF p.30, §9.2, Table 27.

**Datasheet bit field 1: `XA_ST_DATA[7:0]`, bits [7:0]**

Location: `v1 registers[3].field_parts[0].bit_field[0]`; datasheet source: PDF p.30, §9.2, Table 27. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XA_ST_DATA[7:0] | XA_ST_DATA[7:0] |
| `field_description` | 0.0586 | 1.0 | The value in this register indicates the manufacturing self-test output used to check subsequent end-user self-test outputs. | Manufacturing self-test output used to check subsequent end-user self-test outputs. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | SELF_TEST_X_ACCEL | SELF_TEST_X_ACCEL |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"SELF_TEST_X_ACCEL register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Manufacturing self-test output; used to check subsequent end-user self-test outputs. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | SELF_TEST_X_ACCEL | SELF_TEST_X_ACCEL |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"SELF_TEST_X_ACCEL register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}] | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Manufacturing self-test output; used to check subsequent end-user self-test outputs. | Stores the X-axis accelerometer manufacturing self-test output for comparison with subsequent end-user self-test outputs. Convert the self-test code using ST_OTP = (2620 / 2^FS) × 1.01^(ST_code-1) lsb; ST_code is derived from the documented ST_FAC logarithmic equation. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | Pre-programmed value | Pre-programmed value |
| `default_value_description` | 0.0334 | 1.000000 | Contains a pre-programmed self-test value. | Contains a pre-programmed self-test value. |

\(Q(L_{4})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 5: `SELF_TEST_Y_ACCEL`

v1 location: `registers[4]`; datasheet association: PDF p.30, §9.2, Table 27.

Associated physical locations: [{"hex":"0x0E","decimal":"14","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `SELF_TEST_Y_ACCEL` at 0x0E (14)

Location: `v1 registers[4].field_parts[0]`; datasheet source: PDF p.30, §9.2, Table 27.

**Datasheet bit field 1: `YA_ST_DATA[7:0]`, bits [7:0]**

Location: `v1 registers[4].field_parts[0].bit_field[0]`; datasheet source: PDF p.30, §9.2, Table 27. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YA_ST_DATA[7:0] | YA_ST_DATA[7:0] |
| `field_description` | 0.0586 | 1.0 | The value in this register indicates the manufacturing self-test output used to check subsequent end-user self-test outputs. | Manufacturing self-test output used to check subsequent end-user self-test outputs. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | SELF_TEST_Y_ACCEL | SELF_TEST_Y_ACCEL |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x0E","decimal":"14","bank":"","page":"","description":"SELF_TEST_Y_ACCEL register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."} | {"hex":"0x0E","decimal":"14","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Manufacturing self-test output; used to check subsequent end-user self-test outputs. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | SELF_TEST_Y_ACCEL | SELF_TEST_Y_ACCEL |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x0E","decimal":"14","bank":"","page":"","description":"SELF_TEST_Y_ACCEL register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}] | [{"hex":"0x0E","decimal":"14","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Manufacturing self-test output; used to check subsequent end-user self-test outputs. | Stores the Y-axis accelerometer manufacturing self-test output for comparison with subsequent end-user self-test outputs. Convert the self-test code using ST_OTP = (2620 / 2^FS) × 1.01^(ST_code-1) lsb; ST_code is derived from the documented ST_FAC logarithmic equation. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | Pre-programmed value | Pre-programmed value |
| `default_value_description` | 0.0334 | 1.000000 | Contains a pre-programmed self-test value. | Contains a pre-programmed self-test value. |

\(Q(L_{5})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 6: `SELF_TEST_Z_ACCEL`

v1 location: `registers[5]`; datasheet association: PDF p.30, §9.2, Table 27.

Associated physical locations: [{"hex":"0x0F","decimal":"15","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `SELF_TEST_Z_ACCEL` at 0x0F (15)

Location: `v1 registers[5].field_parts[0]`; datasheet source: PDF p.30, §9.2, Table 27.

**Datasheet bit field 1: `ZA_ST_DATA[7:0]`, bits [7:0]**

Location: `v1 registers[5].field_parts[0].bit_field[0]`; datasheet source: PDF p.30, §9.2, Table 27. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZA_ST_DATA[7:0] | ZA_ST_DATA[7:0] |
| `field_description` | 0.0586 | 1.0 | The value in this register indicates the manufacturing self-test output used to check subsequent end-user self-test outputs. | Manufacturing self-test output used to check subsequent end-user self-test outputs. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | SELF_TEST_Z_ACCEL | SELF_TEST_Z_ACCEL |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":"SELF_TEST_Z_ACCEL register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."} | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Manufacturing self-test output; used to check subsequent end-user self-test outputs. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | SELF_TEST_Z_ACCEL | SELF_TEST_Z_ACCEL |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"SELF_TEST_Z_ACCEL register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}] | [{"hex":"0x0F","decimal":"15","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Manufacturing self-test output; used to check subsequent end-user self-test outputs. | Stores the Z-axis accelerometer manufacturing self-test output for comparison with subsequent end-user self-test outputs. Convert the self-test code using ST_OTP = (2620 / 2^FS) × 1.01^(ST_code-1) lsb; ST_code is derived from the documented ST_FAC logarithmic equation. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | Pre-programmed value | Pre-programmed value |
| `default_value_description` | 0.0334 | 1.000000 | Contains a pre-programmed self-test value. | Contains a pre-programmed self-test value. |

\(Q(L_{6})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 7: `X_OFFS_USR`

v1 location: `registers[6]`; datasheet association: PDF p.31, §§9.3-9.4, Tables 28-29.

Associated physical locations: [{"hex":"0x13","decimal":"19","bank":"","page":"","description":"High byte of the 16-bit X gyroscope offset."},{"hex":"0x14","decimal":"20","bank":"","page":"","description":"Low byte of the 16-bit X gyroscope offset."}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `XG_OFFS_USRH` at 0x13 (19)

Location: `v1 registers[6].field_parts[0]`; datasheet source: PDF p.31, Table 28.

**Datasheet bit field 1: `X_OFFS_USR[15:8]`, bits [7:0]**

Location: `v1 registers[6].field_parts[0].bit_field[0]`; datasheet source: PDF p.31, Table 28. Judgment: C<1 fields: field_description=0.500000, type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | X_OFFS_USR[15:8] | X_OFFS_USR[15:8] |
| `field_description` | 0.0586 | 0.5 | Bits 15 to 8 of the 16-bit offset of X gyroscope (2's complement). This register removes DC bias and adds the offset before the sensor register. | Bits 15 to 8 of the signed 16-bit X gyroscope offset. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Field-part aggregation**

bit_field correctness = mean(0.912391) = **0.912391**.

Direct judgment: 直接字段不完全正确：bit_field=0.912391；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | XG_OFFS_USRH | XG_OFFS_USRH |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"High byte of the 16-bit X gyroscope offset."} | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"High byte of the 16-bit X gyroscope offset."} |
| `description` | 0.0693 | 1.000000 | High byte. | High byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.912391 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.912391)/1.0000=0.972587/1.0000=\mathbf{0.972587}\).

##### Field part 2: `XG_OFFS_USRL` at 0x14 (20)

Location: `v1 registers[6].field_parts[1]`; datasheet source: PDF p.31, Table 29.

**Datasheet bit field 1: `X_OFFS_USR[7:0]`, bits [7:0]**

Location: `v1 registers[6].field_parts[1].bit_field[0]`; datasheet source: PDF p.31, Table 29. Judgment: C<1 fields: field_description=0.500000, type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | X_OFFS_USR[7:0] | X_OFFS_USR[7:0] |
| `field_description` | 0.0586 | 0.5 | Bits 7 to 0 of the 16-bit offset of X gyroscope (2's complement). This register removes DC bias and adds the offset before the sensor register. | Bits 7 to 0 of the signed 16-bit X gyroscope offset. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Field-part aggregation**

bit_field correctness = mean(0.912391) = **0.912391**.

Direct judgment: 直接字段不完全正确：bit_field=0.912391；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | XG_OFFS_USRL | XG_OFFS_USRL |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Low byte of the 16-bit X gyroscope offset."} | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Low byte of the 16-bit X gyroscope offset."} |
| `description` | 0.0693 | 1.000000 | Low byte. | Low byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.912391 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.912391)/1.0000=0.972587/1.0000=\mathbf{0.972587}\).

#### Logical-register aggregation

field_parts correctness = mean(0.972587, 0.972587) = **0.972587**.

Direct judgment: 直接字段不完全正确：field_parts=0.972587；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | X_OFFS_USR | X_OFFS_USR |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x13","decimal":"19","bank":"","page":"","description":"High byte of the 16-bit X gyroscope offset."},{"hex":"0x14","decimal":"20","bank":"","page":"","description":"Low byte of the 16-bit X gyroscope offset."}] | [{"hex":"0x13","decimal":"19","bank":"","page":"","description":"High byte of the 16-bit X gyroscope offset."},{"hex":"0x14","decimal":"20","bank":"","page":"","description":"Low byte of the 16-bit X gyroscope offset."}] |
| `register_description` | 0.0564 | 1.000000 | Signed 16-bit two's-complement X-axis gyroscope offset used to remove DC bias; the offset is added to the gyroscope sensor value before it enters the sensor register. | Signed 16-bit two's-complement X-axis gyroscope offset used to remove DC bias. The offset is added to the gyroscope sensor value before it enters the sensor register. |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.972587 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x0000 | 0x0000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | High byte at 0x13 followed by low byte at 0x14; inferred from the stated 0x00 reset value of both physical registers. |

\(Q(L_{7})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.972587 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.991912/1.0001=\mathbf{0.991813}\).

### Extracted logical register 8: `Y_OFFS_USR`

v1 location: `registers[7]`; datasheet association: PDF p.31, §§9.5-9.6, Tables 30-31.

Associated physical locations: [{"hex":"0x15","decimal":"21","bank":"","page":"","description":"High byte of the 16-bit Y gyroscope offset."},{"hex":"0x16","decimal":"22","bank":"","page":"","description":"Low byte of the 16-bit Y gyroscope offset."}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `YG_OFFS_USRH` at 0x15 (21)

Location: `v1 registers[7].field_parts[0]`; datasheet source: PDF p.31, Table 30.

**Datasheet bit field 1: `Y_OFFS_USR[15:8]`, bits [7:0]**

Location: `v1 registers[7].field_parts[0].bit_field[0]`; datasheet source: PDF p.31, Table 30. Judgment: C<1 fields: field_description=0.500000, type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Y_OFFS_USR[15:8] | Y_OFFS_USR[15:8] |
| `field_description` | 0.0586 | 0.5 | Bits 15 to 8 of the 16-bit offset of Y gyroscope (2's complement). This register removes DC bias and adds the offset before the sensor register. | Bits 15 to 8 of the signed 16-bit Y gyroscope offset. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Field-part aggregation**

bit_field correctness = mean(0.912391) = **0.912391**.

Direct judgment: 直接字段不完全正确：bit_field=0.912391；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | YG_OFFS_USRH | YG_OFFS_USRH |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"High byte of the 16-bit Y gyroscope offset."} | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"High byte of the 16-bit Y gyroscope offset."} |
| `description` | 0.0693 | 1.000000 | High byte. | High byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.912391 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.912391)/1.0000=0.972587/1.0000=\mathbf{0.972587}\).

##### Field part 2: `YG_OFFS_USRL` at 0x16 (22)

Location: `v1 registers[7].field_parts[1]`; datasheet source: PDF p.31, Table 31.

**Datasheet bit field 1: `Y_OFFS_USR[7:0]`, bits [7:0]**

Location: `v1 registers[7].field_parts[1].bit_field[0]`; datasheet source: PDF p.31, Table 31. Judgment: C<1 fields: field_description=0.500000, type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Y_OFFS_USR[7:0] | Y_OFFS_USR[7:0] |
| `field_description` | 0.0586 | 0.5 | Bits 7 to 0 of the 16-bit offset of Y gyroscope (2's complement). This register removes DC bias and adds the offset before the sensor register. | Bits 7 to 0 of the signed 16-bit Y gyroscope offset. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Field-part aggregation**

bit_field correctness = mean(0.912391) = **0.912391**.

Direct judgment: 直接字段不完全正确：bit_field=0.912391；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | YG_OFFS_USRL | YG_OFFS_USRL |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"Low byte of the 16-bit Y gyroscope offset."} | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"Low byte of the 16-bit Y gyroscope offset."} |
| `description` | 0.0693 | 1.000000 | Low byte. | Low byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.912391 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.912391)/1.0000=0.972587/1.0000=\mathbf{0.972587}\).

#### Logical-register aggregation

field_parts correctness = mean(0.972587, 0.972587) = **0.972587**.

Direct judgment: 直接字段不完全正确：field_parts=0.972587；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | Y_OFFS_USR | Y_OFFS_USR |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x15","decimal":"21","bank":"","page":"","description":"High byte of the 16-bit Y gyroscope offset."},{"hex":"0x16","decimal":"22","bank":"","page":"","description":"Low byte of the 16-bit Y gyroscope offset."}] | [{"hex":"0x15","decimal":"21","bank":"","page":"","description":"High byte of the 16-bit Y gyroscope offset."},{"hex":"0x16","decimal":"22","bank":"","page":"","description":"Low byte of the 16-bit Y gyroscope offset."}] |
| `register_description` | 0.0564 | 1.000000 | Signed 16-bit two's-complement Y-axis gyroscope offset used to remove DC bias; the offset is added to the gyroscope sensor value before it enters the sensor register. | Signed 16-bit two's-complement Y-axis gyroscope offset used to remove DC bias. The offset is added to the gyroscope sensor value before it enters the sensor register. |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.972587 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x0000 | 0x0000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | High byte at 0x15 followed by low byte at 0x16; inferred from the stated 0x00 reset value of both physical registers. |

\(Q(L_{8})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.972587 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.991912/1.0001=\mathbf{0.991813}\).

### Extracted logical register 9: `Z_OFFS_USR`

v1 location: `registers[8]`; datasheet association: PDF pp.31-32, §§9.7-9.8, Tables 32-33.

Associated physical locations: [{"hex":"0x17","decimal":"23","bank":"","page":"","description":"High byte of the 16-bit Z gyroscope offset."},{"hex":"0x18","decimal":"24","bank":"","page":"","description":"Low byte of the 16-bit Z gyroscope offset."}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `ZG_OFFS_USRH` at 0x17 (23)

Location: `v1 registers[8].field_parts[0]`; datasheet source: PDF p.31, Table 32.

**Datasheet bit field 1: `Z_OFFS_USR[15:8]`, bits [7:0]**

Location: `v1 registers[8].field_parts[0].bit_field[0]`; datasheet source: PDF p.31, Table 32. Judgment: C<1 fields: field_description=0.500000, type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Z_OFFS_USR[15:8] | Z_OFFS_USR[15:8] |
| `field_description` | 0.0586 | 0.5 | Bits 15 to 8 of the 16-bit offset of Z gyroscope (2's complement). This register removes DC bias and adds the offset before the sensor register. | Bits 15 to 8 of the signed 16-bit Z gyroscope offset. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Field-part aggregation**

bit_field correctness = mean(0.912391) = **0.912391**.

Direct judgment: 直接字段不完全正确：bit_field=0.912391；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ZG_OFFS_USRH | ZG_OFFS_USRH |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"High byte of the 16-bit Z gyroscope offset."} | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"High byte of the 16-bit Z gyroscope offset."} |
| `description` | 0.0693 | 1.000000 | High byte. | High byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.912391 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.912391)/1.0000=0.972587/1.0000=\mathbf{0.972587}\).

##### Field part 2: `ZG_OFFS_USRL` at 0x18 (24)

Location: `v1 registers[8].field_parts[1]`; datasheet source: PDF p.32, Table 33.

**Datasheet bit field 1: `Z_OFFS_USR[7:0]`, bits [7:0]**

Location: `v1 registers[8].field_parts[1].bit_field[0]`; datasheet source: PDF p.32, Table 33. Judgment: C<1 fields: field_description=0.500000, type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Z_OFFS_USR[7:0] | Z_OFFS_USR[7:0] |
| `field_description` | 0.0586 | 0.5 | Bits 7 to 0 of the 16-bit offset of Z gyroscope (2's complement). This register removes DC bias and adds the offset before the sensor register. | Bits 7 to 0 of the signed 16-bit Z gyroscope offset. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Field-part aggregation**

bit_field correctness = mean(0.912391) = **0.912391**.

Direct judgment: 直接字段不完全正确：bit_field=0.912391；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ZG_OFFS_USRL | ZG_OFFS_USRL |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Low byte of the 16-bit Z gyroscope offset."} | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Low byte of the 16-bit Z gyroscope offset."} |
| `description` | 0.0693 | 1.000000 | Low byte. | Low byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.912391 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.912391)/1.0000=0.972587/1.0000=\mathbf{0.972587}\).

#### Logical-register aggregation

field_parts correctness = mean(0.972587, 0.972587) = **0.972587**.

Direct judgment: 直接字段不完全正确：field_parts=0.972587；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | Z_OFFS_USR | Z_OFFS_USR |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x17","decimal":"23","bank":"","page":"","description":"High byte of the 16-bit Z gyroscope offset."},{"hex":"0x18","decimal":"24","bank":"","page":"","description":"Low byte of the 16-bit Z gyroscope offset."}] | [{"hex":"0x17","decimal":"23","bank":"","page":"","description":"High byte of the 16-bit Z gyroscope offset."},{"hex":"0x18","decimal":"24","bank":"","page":"","description":"Low byte of the 16-bit Z gyroscope offset."}] |
| `register_description` | 0.0564 | 1.000000 | Signed 16-bit two's-complement Z-axis gyroscope offset used to remove DC bias; the offset is added to the gyroscope sensor value before it enters the sensor register. | Signed 16-bit two's-complement Z-axis gyroscope offset used to remove DC bias. The offset is added to the gyroscope sensor value before it enters the sensor register. |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.972587 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x0000 | 0x0000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | High byte at 0x17 followed by low byte at 0x18; inferred from the stated 0x00 reset value of both physical registers. |

\(Q(L_{9})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.972587 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.991912/1.0001=\mathbf{0.991813}\).

### Extracted logical register 10: `SMPLRT_DIV`

v1 location: `registers[9]`; datasheet association: PDF p.32, §9.9, Table 34.

Associated physical locations: [{"hex":"0x19","decimal":"25","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `SMPLRT_DIV` at 0x19 (25)

Location: `v1 registers[9].field_parts[0]`; datasheet source: PDF p.32, §9.9, Table 34.

**Datasheet bit field 1: `SMPLRT_DIV[7:0]`, bits [7:0]**

Location: `v1 registers[9].field_parts[0].bit_field[0]`; datasheet source: PDF p.32, §9.9, Table 34. Judgment: C<1 fields: field_description=0.500000, type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SMPLRT_DIV[7:0] | SMPLRT_DIV[7:0] |
| `field_description` | 0.0586 | 0.5 | Divides the internal sample rate to generate the sensor data output rate; see the register CONFIG conditions and formula. | Eight-bit internal sample-rate divider. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Field-part aggregation**

bit_field correctness = mean(0.912391) = **0.912391**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.912391；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | SMPLRT_DIV | SMPLRT_DIV |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x19","decimal":"25","bank":"","page":"","description":"SMPLRT_DIV register; Divides the internal sample rate to generate sensor data output rate: SAMPLE_RATE = 1 kHz/(1+SMPLRT_DIV). Effective when FCHOICE_B[1:0]=00 and 0 < DLPF_CFG < 7."} | {"hex":"0x19","decimal":"25","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Divides the internal sample rate to generate sensor data output rate: SAMPLE_RATE = 1 kHz/(1+SMPLRT_DIV). Effective when FCHOICE_B[1:0]=00 and 0 < DLPF_CFG < 7. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.912391 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.912391)/1.0000=0.668887/1.0000=\mathbf{0.668887}\).

#### Logical-register aggregation

field_parts correctness = mean(0.668887) = **0.668887**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.668887；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | SMPLRT_DIV | SMPLRT_DIV |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x19","decimal":"25","bank":"","page":"","description":"SMPLRT_DIV register; Divides the internal sample rate to generate sensor data output rate: SAMPLE_RATE = 1 kHz/(1+SMPLRT_DIV). Effective when FCHOICE_B[1:0]=00 and 0 < DLPF_CFG < 7."}] | [{"hex":"0x19","decimal":"25","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Divides the internal sample rate to generate sensor data output rate: SAMPLE_RATE = 1 kHz/(1+SMPLRT_DIV). Effective when FCHOICE_B[1:0]=00 and 0 < DLPF_CFG < 7. | Divides the internal sample rate to control the sensor-data output rate: SAMPLE_RATE = INTERNAL_SAMPLE_RATE / (1 + SMPLRT_DIV), where INTERNAL_SAMPLE_RATE = 1 kHz. Effective only when FCHOICE_B = 2'b00 and 0 < DLPF_CFG < 7; CONFIG supplies the related filter configuration. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.668887 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{10})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.668887 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.698997/1.0001=\mathbf{0.698927}\).

### Extracted logical register 11: `CONFIG`

v1 location: `registers[10]`; datasheet association: PDF p.32, §9.10, Table 35.

Associated physical locations: [{"hex":"0x1A","decimal":"26","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `CONFIG` at 0x1A (26)

Location: `v1 registers[10].field_parts[0]`; datasheet source: PDF p.32, §9.10, Table 35.

**Datasheet bit field 1: `-`, bits [7]**

Location: `v1 registers[10].field_parts[0].bit_field[0]`; datasheet source: PDF p.32, §9.10, Table 35. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Always set to 0. | Always set to 0. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `-`, bits [6]**

Location: `v1 registers[10].field_parts[0].bit_field[1]`; datasheet source: PDF p.32, §9.10, Table 35. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 3: `EXT_SYNC_SET[2:0]`, bits [5:3]**

Location: `v1 registers[10].field_parts[0].bit_field[2]`; datasheet source: PDF p.32, §9.10, Table 35. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | EXT_SYNC_SET[2:0] | EXT_SYNC_SET[2:0] |
| `field_description` | 0.0586 | 1.0 | Enables FSYNC pin data sampling and selects the output-register bit that receives the latched FSYNC value. | Enables FSYNC pin data sampling and selects the output-register bit that receives the latched FSYNC value. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"TEMP_OUT_L[0]."},{"value":"2","value_description":"GYRO_XOUT_L[0]."},{"value":"3","value_description":"GYRO_YOUT_L[0]."},{"value":"4","value_description":"GYRO_ZOUT_L[0]."},{"value":"5","value_description":"ACCEL_XOUT_L[0]."},{"value":"6","value_description":"ACCEL_YOUT_L[0]."},{"value":"7","value_description":"ACCEL_ZOUT_L[0]."}] | [{"value":"0","value_description":"Function disabled."},{"value":"1","value_description":"TEMP_OUT_L[0]."},{"value":"2","value_description":"GYRO_XOUT_L[0]."},{"value":"3","value_description":"GYRO_YOUT_L[0]."},{"value":"4","value_description":"GYRO_ZOUT_L[0]."},{"value":"5","value_description":"ACCEL_XOUT_L[0]."},{"value":"6","value_description":"ACCEL_YOUT_L[0]."},{"value":"7","value_description":"ACCEL_ZOUT_L[0]."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 4: `DLPF_CFG[2:0]`, bits [2:0]**

Location: `v1 registers[10].field_parts[0].bit_field[3]`; datasheet source: PDF p.32, §9.10, Table 35. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DLPF_CFG[2:0] | DLPF_CFG[2:0] |
| `field_description` | 0.0586 | 1.0 | Gyroscope and temperature DLPF setting; used when FCHOICE_B[1:0]=00. | Gyroscope and temperature DLPF setting; see Table 17. Used when FCHOICE_B[1:0] is 2'b00. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | CONFIG | CONFIG |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"CONFIG register; Configures FSYNC sampling and the gyroscope/temperature digital low-pass filter; DLPF_CFG is used when FCHOICE_B[1:0]=00."} | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Configures FSYNC sampling and the gyroscope/temperature digital low-pass filter; DLPF_CFG is used when FCHOICE_B[1:0]=00. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | CONFIG | CONFIG |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"CONFIG register; Configures FSYNC sampling and the gyroscope/temperature digital low-pass filter; DLPF_CFG is used when FCHOICE_B[1:0]=00."}] | [{"hex":"0x1A","decimal":"26","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Configures FSYNC sampling and the gyroscope/temperature digital low-pass filter; DLPF_CFG is used when FCHOICE_B[1:0]=00. | Configures FSYNC sampling and the gyroscope/temperature digital low-pass filter. DLPF_CFG is used when GYRO_CONFIG.FCHOICE_B[1:0] = 2'b00; retrieve Table 17 for the corresponding data rates and bandwidths. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{11})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 12: `GYRO_CONFIG`

v1 location: `registers[11]`; datasheet association: PDF p.33, §9.11, Table 37.

Associated physical locations: [{"hex":"0x1B","decimal":"27","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `GYRO_CONFIG` at 0x1B (27)

Location: `v1 registers[11].field_parts[0]`; datasheet source: PDF p.33, §9.11, Table 37.

**Datasheet bit field 1: `XG_ST`, bits [7]**

Location: `v1 registers[11].field_parts[0].bit_field[0]`; datasheet source: PDF p.33, §9.11, Table 37. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XG_ST | XG_ST |
| `field_description` | 0.0586 | 1.0 | X Gyro self-test. | X gyroscope self-test. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `YG_ST`, bits [6]**

Location: `v1 registers[11].field_parts[0].bit_field[1]`; datasheet source: PDF p.33, §9.11, Table 37. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YG_ST | YG_ST |
| `field_description` | 0.0586 | 1.0 | Y Gyro self-test. | Y gyroscope self-test. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 3: `ZG_ST`, bits [5]**

Location: `v1 registers[11].field_parts[0].bit_field[2]`; datasheet source: PDF p.33, §9.11, Table 37. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZG_ST | ZG_ST |
| `field_description` | 0.0586 | 1.0 | Z Gyro self-test. | Z gyroscope self-test. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 4: `FS_SEL[1:0]`, bits [4:3]**

Location: `v1 registers[11].field_parts[0].bit_field[3]`; datasheet source: PDF p.33, §9.11, Table 37. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FS_SEL[1:0] | FS_SEL[1:0] |
| `field_description` | 0.0586 | 1.0 | Gyro Full Scale Select. | Gyroscope full-scale selection. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"±125 dps."},{"value":"01","value_description":"±250 dps."},{"value":"10","value_description":"±500 dps."},{"value":"11","value_description":"±1000 dps."}] | [{"value":"00","value_description":"±125 dps."},{"value":"01","value_description":"±250 dps."},{"value":"10","value_description":"±500 dps."},{"value":"11","value_description":"±1000 dps."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 5: `-`, bits [2]**

Location: `v1 registers[11].field_parts[0].bit_field[4]`; datasheet source: PDF p.33, §9.11, Table 37. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 6: `FCHOICE_B[1:0]`, bits [1:0]**

Location: `v1 registers[11].field_parts[0].bit_field[5]`; datasheet source: PDF p.33, §9.11, Table 37. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FCHOICE_B[1:0] | FCHOICE_B[1:0] |
| `field_description` | 0.0586 | 1.0 | Used to bypass DLPF as shown in Table 17. | Controls DLPF bypass as shown in Table 17. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | GYRO_CONFIG | GYRO_CONFIG |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"GYRO_CONFIG register; Enables per-axis gyroscope self-test, selects the gyroscope full-scale range, and controls DLPF bypass through FCHOICE_B."} | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Enables per-axis gyroscope self-test, selects the gyroscope full-scale range, and controls DLPF bypass through FCHOICE_B. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | GYRO_CONFIG | GYRO_CONFIG |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"GYRO_CONFIG register; Enables per-axis gyroscope self-test, selects the gyroscope full-scale range, and controls DLPF bypass through FCHOICE_B."}] | [{"hex":"0x1B","decimal":"27","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Enables per-axis gyroscope self-test, selects the gyroscope full-scale range, and controls DLPF bypass through FCHOICE_B. | Enables per-axis gyroscope self-test, selects the gyroscope full-scale range, and controls DLPF bypass through FCHOICE_B. Retrieve Table 17 for FCHOICE_B-dependent bandwidth and rate settings. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{12})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 13: `ACCEL_CONFIG`

v1 location: `registers[12]`; datasheet association: PDF p.33, §9.12, Table 38.

Associated physical locations: [{"hex":"0x1C","decimal":"28","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `ACCEL_CONFIG` at 0x1C (28)

Location: `v1 registers[12].field_parts[0]`; datasheet source: PDF p.33, §9.12, Table 38.

**Datasheet bit field 1: `XA_ST`, bits [7]**

Location: `v1 registers[12].field_parts[0].bit_field[0]`; datasheet source: PDF p.33, §9.12, Table 38. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XA_ST | XA_ST |
| `field_description` | 0.0586 | 1.0 | X Accel self-test. | X accelerometer self-test. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `YA_ST`, bits [6]**

Location: `v1 registers[12].field_parts[0].bit_field[1]`; datasheet source: PDF p.33, §9.12, Table 38. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YA_ST | YA_ST |
| `field_description` | 0.0586 | 1.0 | Y Accel self-test. | Y accelerometer self-test. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 3: `ZA_ST`, bits [5]**

Location: `v1 registers[12].field_parts[0].bit_field[2]`; datasheet source: PDF p.33, §9.12, Table 38. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZA_ST | ZA_ST |
| `field_description` | 0.0586 | 1.0 | Z Accel self-test. | Z accelerometer self-test. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 4: `ACCEL_FS_SEL[1:0]`, bits [4:3]**

Location: `v1 registers[12].field_parts[0].bit_field[3]`; datasheet source: PDF p.33, §9.12, Table 38. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_FS_SEL[1:0] | ACCEL_FS_SEL[1:0] |
| `field_description` | 0.0586 | 1.0 | Accel Full Scale Select. | Accelerometer full-scale selection. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"±2g."},{"value":"01","value_description":"±4g."},{"value":"10","value_description":"±8g."},{"value":"11","value_description":"±16g."}] | [{"value":"00","value_description":"±2g."},{"value":"01","value_description":"±4g."},{"value":"10","value_description":"±8g."},{"value":"11","value_description":"±16g."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 5: `-`, bits [2:0]**

Location: `v1 registers[12].field_parts[0].bit_field[4]`; datasheet source: PDF p.33, §9.12, Table 38. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_CONFIG | ACCEL_CONFIG |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":"ACCEL_CONFIG register; Enables per-axis accelerometer self-test and selects the accelerometer full-scale range."} | {"hex":"0x1C","decimal":"28","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Enables per-axis accelerometer self-test and selects the accelerometer full-scale range. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_CONFIG | ACCEL_CONFIG |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"ACCEL_CONFIG register; Enables per-axis accelerometer self-test and selects the accelerometer full-scale range."}] | [{"hex":"0x1C","decimal":"28","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Enables per-axis accelerometer self-test and selects the accelerometer full-scale range. | Enables per-axis accelerometer self-test and selects the accelerometer full-scale range. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{13})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 14: `ACCEL_CONFIG2`

v1 location: `registers[13]`; datasheet association: PDF p.34, §9.13, Table 39; Table 18.

Associated physical locations: [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `ACCEL_CONFIG2` at 0x1D (29)

Location: `v1 registers[13].field_parts[0]`; datasheet source: PDF p.34, §9.13, Table 39; Table 18.

**Datasheet bit field 1: `-`, bits [7:6]**

Location: `v1 registers[13].field_parts[0].bit_field[0]`; datasheet source: PDF p.34, §9.13, Table 39; Table 18. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | "" | "" |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `DEC2_CFG[1:0]`, bits [5:4]**

Location: `v1 registers[13].field_parts[0].bit_field[1]`; datasheet source: PDF p.34, §9.13, Table 39; Table 18. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DEC2_CFG[1:0] | DEC2_CFG[1:0] |
| `field_description` | 0.0586 | 1.0 | Averaging filter settings for WoM Accelerometer Mode. | Averaging filter setting for Wake-on-Motion accelerometer mode. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Average 4 samples."},{"value":"1","value_description":"Average 8 samples."},{"value":"2","value_description":"Average 16 samples."},{"value":"3","value_description":"Average 32 samples."}] | [{"value":"0","value_description":"Average 4 samples."},{"value":"1","value_description":"Average 8 samples."},{"value":"2","value_description":"Average 16 samples."},{"value":"3","value_description":"Average 32 samples."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 3: `ACCEL_FCHOICE_B`, bits [3]**

Location: `v1 registers[13].field_parts[0].bit_field[2]`; datasheet source: PDF p.34, §9.13, Table 39; Table 18. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_FCHOICE_B | ACCEL_FCHOICE_B |
| `field_description` | 0.0586 | 1.0 | Used to bypass DLPF as shown in Table 18. | Bypasses the DLPF as shown in Table 18. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 4: `A_DLPF_CFG`, bits [2:0]**

Location: `v1 registers[13].field_parts[0].bit_field[3]`; datasheet source: PDF p.34, §9.13, Table 39; Table 18. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | A_DLPF_CFG | A_DLPF_CFG |
| `field_description` | 0.0586 | 1.0 | Accelerometer low-pass filter setting as shown in Table 18. | Accelerometer low-pass filter setting shown in Table 18. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_CONFIG2 | ACCEL_CONFIG2 |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":"ACCEL_CONFIG2 register; Configures accelerometer WoM averaging, DLPF bypass, and accelerometer low-pass filter settings."} | {"hex":"0x1D","decimal":"29","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Configures accelerometer WoM averaging, DLPF bypass, and accelerometer low-pass filter settings. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_CONFIG2 | ACCEL_CONFIG2 |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"ACCEL_CONFIG2 register; Configures accelerometer WoM averaging, DLPF bypass, and accelerometer low-pass filter settings."}] | [{"hex":"0x1D","decimal":"29","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Configures accelerometer WoM averaging, DLPF bypass, and accelerometer low-pass filter settings. | Configures accelerometer averaging in Wake-on-Motion mode, DLPF bypass, and the accelerometer low-pass filter. The DLPF output rate can be reduced by 1/(1+SMPLRT_DIV). Retrieve Table 18 for low-noise bandwidth/rate settings and Table 19 for Wake-on-Motion examples. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{14})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 15: `LP_MODE_CFG`

v1 location: `registers[14]`; datasheet association: PDF p.35, §9.14, Table 42.

Associated physical locations: [{"hex":"0x1E","decimal":"30","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `LP_MODE_CFG` at 0x1E (30)

Location: `v1 registers[14].field_parts[0]`; datasheet source: PDF p.35, §9.14, Table 42.

**Datasheet bit field 1: `GYRO_CYCLE`, bits [7]**

Location: `v1 registers[14].field_parts[0].bit_field[0]`; datasheet source: PDF p.35, §9.14, Table 42. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_CYCLE | GYRO_CYCLE |
| `field_description` | 0.0586 | 1.0 | When set to 1, the gyroscope or 6-axis system is duty-cycled; default is 0. | When set to 1, the gyroscope or 6-axis system is duty-cycled; default is 0. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Gyroscope or 6-axis operation is duty-cycled."},{"value":"0","value_description":"Default setting."}] | [{"value":"1","value_description":"Gyroscope or 6-axis operation is duty-cycled."},{"value":"0","value_description":"Default setting."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `G_AVGCFG[2:0]`, bits [6:4]**

Location: `v1 registers[14].field_parts[0].bit_field[1]`; datasheet source: PDF p.35, §9.14, Table 42. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | G_AVGCFG[2:0] | G_AVGCFG[2:0] |
| `field_description` | 0.0586 | 1.0 | Gyroscope averaging filter settings when GYRO_CYCLE is set to 1; default is 000. | Gyroscope averaging filter setting when GYRO_CYCLE is 1; default is 000. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 3: `ACCEL_WOM_ODR_CTRL[3:0]`, bits [3:0]**

Location: `v1 registers[14].field_parts[0].bit_field[2]`; datasheet source: PDF p.35, §9.14, Table 42. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_WOM_ODR_CTRL[3:0] | ACCEL_WOM_ODR_CTRL[3:0] |
| `field_description` | 0.0586 | 1.0 | Accelerometer WoM Mode ODR configuration. | Accelerometer Wake-on-Motion output data rate configuration. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [{"value":"0 to 3","value_description":"Reserved."},{"value":"4","value_description":"3.9 Hz."},{"value":"5","value_description":"7.8 Hz."},{"value":"6","value_description":"15.6 Hz."},{"value":"7","value_description":"31.3 Hz."},{"value":"8","value_description":"62.5 Hz."},{"value":"9","value_description":"125 Hz."},{"value":"10","value_description":"250 Hz."},{"value":"11","value_description":"500 Hz."},{"value":"12 to 15","value_description":"Reserved."}] | [{"value":"0 to 3","value_description":"Reserved."},{"value":"4","value_description":"3.9 Hz."},{"value":"5","value_description":"7.8 Hz."},{"value":"6","value_description":"15.6 Hz."},{"value":"7","value_description":"31.3 Hz."},{"value":"8","value_description":"62.5 Hz."},{"value":"9","value_description":"125 Hz."},{"value":"10","value_description":"250 Hz."},{"value":"11","value_description":"500 Hz."},{"value":"12 to 15","value_description":"Reserved."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | LP_MODE_CFG | LP_MODE_CFG |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":"LP_MODE_CFG register; Configures duty-cycled gyroscope or 6-axis operation, gyroscope averaging, and accelerometer WoM output data rate."} | {"hex":"0x1E","decimal":"30","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Configures duty-cycled gyroscope or 6-axis operation, gyroscope averaging, and accelerometer WoM output data rate. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | LP_MODE_CFG | LP_MODE_CFG |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"LP_MODE_CFG register; Configures duty-cycled gyroscope or 6-axis operation, gyroscope averaging, and accelerometer WoM output data rate."}] | [{"hex":"0x1E","decimal":"30","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Configures duty-cycled gyroscope or 6-axis operation, gyroscope averaging, and accelerometer WoM output data rate. | Configures duty-cycled gyroscope or 6-axis operation, gyroscope averaging, and accelerometer Wake-on-Motion output data rate. ACCEL_WOM_ODR_CTRL is effective only while the gyroscope is off and PWR_MGMT_1.ACCEL_CYCLE is 1; retrieve Tables 19 and 20 for example configurations. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{15})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 16: `ACCEL_WOM_X_THR`

v1 location: `registers[15]`; datasheet association: PDF p.36, §9.15, Table 44.

Associated physical locations: [{"hex":"0x20","decimal":"32","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `ACCEL_WOM_X_THR` at 0x20 (32)

Location: `v1 registers[15].field_parts[0]`; datasheet source: PDF p.36, §9.15, Table 44.

**Datasheet bit field 1: `WOM_X_THRESHOLD[7:0]`, bits [7:0]**

Location: `v1 registers[15].field_parts[0].bit_field[0]`; datasheet source: PDF p.36, §9.15, Table 44. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WOM_X_THRESHOLD[7:0] | WOM_X_THRESHOLD[7:0] |
| `field_description` | 0.0586 | 1.0 | X-axis Wake-on-Motion threshold; resolution is 4 mg/LSB regardless of selected full scale. | X-axis Wake-on-Motion threshold; resolution is 4 mg/LSB. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_WOM_X_THR | ACCEL_WOM_X_THR |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"ACCEL_WOM_X_THR register; Holds the X-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale."} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Holds the X-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_WOM_X_THR | ACCEL_WOM_X_THR |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":"ACCEL_WOM_X_THR register; Holds the X-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale."}] | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Holds the X-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale. | Holds the X-axis accelerometer Wake-on-Motion interrupt threshold with 4 mg/LSB resolution regardless of selected full scale. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{16})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 17: `ACCEL_WOM_Y_THR`

v1 location: `registers[16]`; datasheet association: PDF p.36, §9.15, Table 45.

Associated physical locations: [{"hex":"0x21","decimal":"33","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `ACCEL_WOM_Y_THR` at 0x21 (33)

Location: `v1 registers[16].field_parts[0]`; datasheet source: PDF p.36, §9.15, Table 45.

**Datasheet bit field 1: `WOM_Y_THRESHOLD[7:0]`, bits [7:0]**

Location: `v1 registers[16].field_parts[0].bit_field[0]`; datasheet source: PDF p.36, §9.15, Table 45. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WOM_Y_THRESHOLD[7:0] | WOM_Y_THRESHOLD[7:0] |
| `field_description` | 0.0586 | 1.0 | Y-axis Wake-on-Motion threshold; resolution is 4 mg/LSB regardless of selected full scale. | Y-axis Wake-on-Motion threshold; resolution is 4 mg/LSB. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_WOM_Y_THR | ACCEL_WOM_Y_THR |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"ACCEL_WOM_Y_THR register; Holds the Y-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale."} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Holds the Y-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_WOM_Y_THR | ACCEL_WOM_Y_THR |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"ACCEL_WOM_Y_THR register; Holds the Y-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale."}] | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Holds the Y-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale. | Holds the Y-axis accelerometer Wake-on-Motion interrupt threshold with 4 mg/LSB resolution regardless of selected full scale. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{17})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 18: `ACCEL_WOM_Z_THR`

v1 location: `registers[17]`; datasheet association: PDF p.36, §9.15, Table 46.

Associated physical locations: [{"hex":"0x22","decimal":"34","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `ACCEL_WOM_Z_THR` at 0x22 (34)

Location: `v1 registers[17].field_parts[0]`; datasheet source: PDF p.36, §9.15, Table 46.

**Datasheet bit field 1: `WOM_Z_THRESHOLD[7:0]`, bits [7:0]**

Location: `v1 registers[17].field_parts[0].bit_field[0]`; datasheet source: PDF p.36, §9.15, Table 46. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WOM_Z_THRESHOLD[7:0] | WOM_Z_THRESHOLD[7:0] |
| `field_description` | 0.0586 | 1.0 | Z-axis Wake-on-Motion threshold; resolution is 4 mg/LSB regardless of selected full scale. | Z-axis Wake-on-Motion threshold; resolution is 4 mg/LSB. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_WOM_Z_THR | ACCEL_WOM_Z_THR |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x22","decimal":"34","bank":"","page":"","description":"ACCEL_WOM_Z_THR register; Holds the Z-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale."} | {"hex":"0x22","decimal":"34","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Holds the Z-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_WOM_Z_THR | ACCEL_WOM_Z_THR |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x22","decimal":"34","bank":"","page":"","description":"ACCEL_WOM_Z_THR register; Holds the Z-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale."}] | [{"hex":"0x22","decimal":"34","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Holds the Z-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale. | Holds the Z-axis accelerometer Wake-on-Motion interrupt threshold with 4 mg/LSB resolution regardless of selected full scale. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{18})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 19: `FSYNC_INT`

v1 location: `registers[18]`; datasheet association: PDF p.37, §9.16, Table 47.

Associated physical locations: [{"hex":"0x36","decimal":"54","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `FSYNC_INT` at 0x36 (54)

Location: `v1 registers[18].field_parts[0]`; datasheet source: PDF p.37, §9.16, Table 47.

**Datasheet bit field 1: `FSYNC_INT`, bits [7]**

Location: `v1 registers[18].field_parts[0].bit_field[0]`; datasheet source: PDF p.37, §9.16, Table 47. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FSYNC_INT | FSYNC_INT |
| `field_description` | 0.0586 | 1.0 | Sets to 1 when an FSYNC interrupt is generated and clears to 0 after the register is read. | Sets to 1 when an FSYNC interrupt is generated and clears to 0 after the register is read. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R/C | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `-`, bits [6:0]**

Location: `v1 registers[18].field_parts[0].bit_field[1]`; datasheet source: PDF p.37, §9.16, Table 47. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | "" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R/C | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, type_write_read=0.500000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | FSYNC_INT | FSYNC_INT |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x36","decimal":"54","bank":"","page":"","description":"FSYNC_INT register; FSYNC interrupt status; the bit sets when an FSYNC interrupt is generated and clears after the register is read."} | {"hex":"0x36","decimal":"54","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | FSYNC interrupt status; the bit sets when an FSYNC interrupt is generated and clears after the register is read. | Read-to-clear status register. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.500000 | R/C | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×0.500000 + 0.3129×0.941694)/1.0000=0.717106/1.0000=\mathbf{0.717106}\).

#### Logical-register aggregation

field_parts correctness = mean(0.717106) = **0.717106**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, type_write_read=0.500000, field_parts=0.717106；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | FSYNC_INT | FSYNC_INT |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":"FSYNC_INT register; FSYNC interrupt status; the bit sets when an FSYNC interrupt is generated and clears after the register is read."}] | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | FSYNC interrupt status; the bit sets when an FSYNC interrupt is generated and clears after the register is read. | Reports FSYNC interrupt status. The status bit sets when an FSYNC interrupt is generated and clears after the register is read. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 0.500000 | R/C | R |
| `field_parts` | 0.2987 | 0.717106 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{19})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×0.500000 + 0.2987×0.717106 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.683900/1.0001=\mathbf{0.683831}\).

### Extracted logical register 20: `INT_PIN_CFG`

v1 location: `registers[19]`; datasheet association: PDF p.37, §9.17, Table 48.

Associated physical locations: [{"hex":"0x37","decimal":"55","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `INT_PIN_CFG` at 0x37 (55)

Location: `v1 registers[19].field_parts[0]`; datasheet source: PDF p.37, §9.17, Table 48.

**Datasheet bit field 1: `INT_LEVEL`, bits [7]**

Location: `v1 registers[19].field_parts[0].bit_field[0]`; datasheet source: PDF p.37, §9.17, Table 48. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | INT_LEVEL | INT_LEVEL |
| `field_description` | 0.0586 | 1.0 | Logic level for INT/INT2. | INT/INT2 active logic level. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Active low."},{"value":"0","value_description":"Active high."}] | [{"value":"1","value_description":"Active low."},{"value":"0","value_description":"Active high."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `INT_OPEN`, bits [6]**

Location: `v1 registers[19].field_parts[0].bit_field[1]`; datasheet source: PDF p.37, §9.17, Table 48. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | INT_OPEN | INT_OPEN |
| `field_description` | 0.0586 | 1.0 | INT/INT2 output type. | INT/INT2 output type. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Open drain."},{"value":"0","value_description":"Push-pull."}] | [{"value":"1","value_description":"Open drain."},{"value":"0","value_description":"Push-pull."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 3: `LATCH_INT_EN`, bits [5]**

Location: `v1 registers[19].field_parts[0].bit_field[2]`; datasheet source: PDF p.37, §9.17, Table 48. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LATCH_INT_EN | LATCH_INT_EN |
| `field_description` | 0.0586 | 1.0 | Selects latched or pulsed interrupt signaling. | Selects latched or pulsed interrupt signaling. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Hold INT/INT2 until status is cleared."},{"value":"0","value_description":"INT/INT2 pulse width is 50 μs."}] | [{"value":"1","value_description":"Hold INT/INT2 level until interrupt status is cleared."},{"value":"0","value_description":"INT/INT2 interrupt pulse width is 50 μs."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 4: `INT_RD_CLEAR`, bits [4]**

Location: `v1 registers[19].field_parts[0].bit_field[3]`; datasheet source: PDF p.37, §9.17, Table 48. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | INT_RD_CLEAR | INT_RD_CLEAR |
| `field_description` | 0.0586 | 1.0 | Selects interrupt-status clearing method. | Selects the interrupt-status clearing method. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Clear on any read operation."},{"value":"0","value_description":"Clear only by reading INT_STATUS."}] | [{"value":"1","value_description":"Clear interrupt status on any read operation."},{"value":"0","value_description":"Clear interrupt status only by reading INT_STATUS."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 5: `FSYNC_INT_LEVEL`, bits [3]**

Location: `v1 registers[19].field_parts[0].bit_field[4]`; datasheet source: PDF p.37, §9.17, Table 48. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FSYNC_INT_LEVEL | FSYNC_INT_LEVEL |
| `field_description` | 0.0586 | 1.0 | FSYNC interrupt logic level. | FSYNC interrupt active logic level. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Active low."},{"value":"0","value_description":"Active high."}] | [{"value":"1","value_description":"Active low."},{"value":"0","value_description":"Active high."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 6: `FSYNC_INT_MODE_EN`, bits [2]**

Location: `v1 registers[19].field_parts[0].bit_field[5]`; datasheet source: PDF p.37, §9.17, Table 48. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FSYNC_INT_MODE_EN | FSYNC_INT_MODE_EN |
| `field_description` | 0.0586 | 1.0 | Enables FSYNC to trigger an interrupt at the selected level. | Enables FSYNC to trigger an interrupt at the level selected by FSYNC_INT_LEVEL. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"FSYNC interrupt enabled."},{"value":"0","value_description":"FSYNC disabled from causing an interrupt."}] | [{"value":"1","value_description":"FSYNC interrupt enabled."},{"value":"0","value_description":"FSYNC disabled from causing an interrupt."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 7: `-`, bits [1]**

Location: `v1 registers[19].field_parts[0].bit_field[6]`; datasheet source: PDF p.37, §9.17, Table 48. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 8: `-INT2_EN`, bits [0]**

Location: `v1 registers[19].field_parts[0].bit_field[7]`; datasheet source: PDF p.37, §9.17, Table 48. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | -INT2_EN | -INT2_EN |
| `field_description` | 0.0586 | 1.0 | Routes interrupts between INT and INT2; data ready always remains on INT. | Routes interrupts between INT and INT2; data ready always remains on INT. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"All interrupts appear on INT; INT2 is unused."},{"value":"1","value_description":"All interrupts except data ready appear on INT2; data ready appears on INT."}] | [{"value":"0","value_description":"All interrupts appear on INT; INT2 is unused."},{"value":"1","value_description":"All interrupts except data ready appear on INT2; data ready appears on INT."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT_PIN_CFG | INT_PIN_CFG |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x37","decimal":"55","bank":"","page":"","description":"INT_PIN_CFG register; Configures INT/INT2 polarity, output drive, interrupt latching/clearing, FSYNC interrupt behavior, and INT2 routing."} | {"hex":"0x37","decimal":"55","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Configures INT/INT2 polarity, output drive, interrupt latching/clearing, FSYNC interrupt behavior, and INT2 routing. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT_PIN_CFG | INT_PIN_CFG |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":"INT_PIN_CFG register; Configures INT/INT2 polarity, output drive, interrupt latching/clearing, FSYNC interrupt behavior, and INT2 routing."}] | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Configures INT/INT2 polarity, output drive, interrupt latching/clearing, FSYNC interrupt behavior, and INT2 routing. | Configures INT/INT2 polarity, output drive, latching and clearing behavior, FSYNC interrupt behavior, and routing of non-data-ready interrupts between INT and INT2. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{20})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 21: `INT_ENABLE`

v1 location: `registers[20]`; datasheet association: PDF p.37, §9.18, Table 49.

Associated physical locations: [{"hex":"0x38","decimal":"56","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `INT_ENABLE` at 0x38 (56)

Location: `v1 registers[20].field_parts[0]`; datasheet source: PDF p.37, §9.18, Table 49.

**Datasheet bit field 1: `WOM_X_INT_EN`, bits [7]**

Location: `v1 registers[20].field_parts[0].bit_field[0]`; datasheet source: PDF p.37, §9.18, Table 49. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WOM_X_INT_EN | WOM_X_INT_EN |
| `field_description` | 0.0586 | 1.0 | X-axis accelerometer Wake-on-Motion interrupt enable. | X-axis accelerometer Wake-on-Motion interrupt enable. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Enable."},{"value":"0","value_description":"Disable."}] | [{"value":"1","value_description":"Enable."},{"value":"0","value_description":"Disable."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `WOM_Y_INT_EN`, bits [6]**

Location: `v1 registers[20].field_parts[0].bit_field[1]`; datasheet source: PDF p.37, §9.18, Table 49. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WOM_Y_INT_EN | WOM_Y_INT_EN |
| `field_description` | 0.0586 | 1.0 | Y-axis accelerometer Wake-on-Motion interrupt enable. | Y-axis accelerometer Wake-on-Motion interrupt enable. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Enable."},{"value":"0","value_description":"Disable."}] | [{"value":"1","value_description":"Enable."},{"value":"0","value_description":"Disable."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 3: `WOM_Z_INT_EN`, bits [5]**

Location: `v1 registers[20].field_parts[0].bit_field[2]`; datasheet source: PDF p.37, §9.18, Table 49. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WOM_Z_INT_EN | WOM_Z_INT_EN |
| `field_description` | 0.0586 | 1.0 | Z-axis accelerometer Wake-on-Motion interrupt enable. | Z-axis accelerometer Wake-on-Motion interrupt enable. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Enable."},{"value":"0","value_description":"Disable."}] | [{"value":"1","value_description":"Enable."},{"value":"0","value_description":"Disable."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 4: `-`, bits [4:3]**

Location: `v1 registers[20].field_parts[0].bit_field[3]`; datasheet source: PDF p.37, §9.18, Table 49. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 5: `GDRIVE_INT_EN`, bits [2]**

Location: `v1 registers[20].field_parts[0].bit_field[4]`; datasheet source: PDF p.37, §9.18, Table 49. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GDRIVE_INT_EN | GDRIVE_INT_EN |
| `field_description` | 0.0586 | 1.0 | Gyroscope Drive System Ready interrupt enable. | Gyroscope Drive System Ready interrupt enable. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 6: `-`, bits [1]**

Location: `v1 registers[20].field_parts[0].bit_field[5]`; datasheet source: PDF p.37, §9.18, Table 49. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 7: `DATA_RDY_INT_EN`, bits [0]**

Location: `v1 registers[20].field_parts[0].bit_field[6]`; datasheet source: PDF p.37, §9.18, Table 49. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DATA_RDY_INT_EN | DATA_RDY_INT_EN |
| `field_description` | 0.0586 | 1.0 | Data ready interrupt enable. | Data-ready interrupt enable. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT_ENABLE | INT_ENABLE |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x38","decimal":"56","bank":"","page":"","description":"INT_ENABLE register; Individually enables X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupts."} | {"hex":"0x38","decimal":"56","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Individually enables X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupts. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT_ENABLE | INT_ENABLE |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x38","decimal":"56","bank":"","page":"","description":"INT_ENABLE register; Individually enables X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupts."}] | [{"hex":"0x38","decimal":"56","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Individually enables X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupts. | Individually enables X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupts. Data ready is generated on INT; other enabled interrupts are routed according to INT_PIN_CFG.INT2_EN. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{21})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 22: `INT_STATUS`

v1 location: `registers[21]`; datasheet association: PDF p.38, §9.19, Table 50.

Associated physical locations: [{"hex":"0x3A","decimal":"58","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `INT_STATUS` at 0x3A (58)

Location: `v1 registers[21].field_parts[0]`; datasheet source: PDF p.38, §9.19, Table 50.

**Datasheet bit field 1: `WOM_X_INT`, bits [7]**

Location: `v1 registers[21].field_parts[0].bit_field[0]`; datasheet source: PDF p.38, §9.19, Table 50. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WOM_X_INT | WOM_X_INT |
| `field_description` | 0.0586 | 1.0 | Accelerometer X WoM interrupt status; cleared on read. | X-axis accelerometer Wake-on-Motion status; cleared on read. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"WoM detected."}] | [{"value":"1","value_description":"Wake-on-Motion detected."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R/C | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `WOM_Y_INT`, bits [6]**

Location: `v1 registers[21].field_parts[0].bit_field[1]`; datasheet source: PDF p.38, §9.19, Table 50. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WOM_Y_INT | WOM_Y_INT |
| `field_description` | 0.0586 | 1.0 | Accelerometer Y WoM interrupt status; cleared on read. | Y-axis accelerometer Wake-on-Motion status; cleared on read. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"WoM detected."}] | [{"value":"1","value_description":"Wake-on-Motion detected."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R/C | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 3: `WOM_Z_INT`, bits [5]**

Location: `v1 registers[21].field_parts[0].bit_field[2]`; datasheet source: PDF p.38, §9.19, Table 50. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WOM_Z_INT | WOM_Z_INT |
| `field_description` | 0.0586 | 1.0 | Accelerometer Z WoM interrupt status; cleared on read. | Z-axis accelerometer Wake-on-Motion status; cleared on read. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"WoM detected."}] | [{"value":"1","value_description":"Wake-on-Motion detected."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R/C | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 4: `-`, bits [4:3]**

Location: `v1 registers[21].field_parts[0].bit_field[3]`; datasheet source: PDF p.38, §9.19, Table 50. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R/C | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 5: `GDRIVE_INT`, bits [2]**

Location: `v1 registers[21].field_parts[0].bit_field[4]`; datasheet source: PDF p.38, §9.19, Table 50. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GDRIVE_INT | GDRIVE_INT |
| `field_description` | 0.0586 | 1.0 | Gyroscope Drive System Ready interrupt status. | Gyroscope Drive System Ready interrupt status. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R/C | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 6: `-`, bits [1]**

Location: `v1 registers[21].field_parts[0].bit_field[5]`; datasheet source: PDF p.38, §9.19, Table 50. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R/C | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 7: `DATA_RDY_INT`, bits [0]**

Location: `v1 registers[21].field_parts[0].bit_field[6]`; datasheet source: PDF p.38, §9.19, Table 50. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DATA_RDY_INT | DATA_RDY_INT |
| `field_description` | 0.0586 | 1.0 | Sets to 1 when a data-ready interrupt is generated and clears after the register is read. | Sets to 1 when a data-ready interrupt is generated and clears to 0 after the register is read. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R/C | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, type_write_read=0.500000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT_STATUS | INT_STATUS |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":"INT_STATUS register; Reports X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupt status; WOM and data-ready status clear on read."} | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.000000 | Reports X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupt status; WOM and data-ready status clear on read. | Read-to-clear interrupt status register. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.500000 | R/C | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×0.500000 + 0.3129×0.941694)/1.0000=0.717106/1.0000=\mathbf{0.717106}\).

#### Logical-register aggregation

field_parts correctness = mean(0.717106) = **0.717106**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, type_write_read=0.500000, field_parts=0.717106；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT_STATUS | INT_STATUS |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x3A","decimal":"58","bank":"","page":"","description":"INT_STATUS register; Reports X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupt status; WOM and data-ready status clear on read."}] | [{"hex":"0x3A","decimal":"58","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Reports X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupt status; WOM and data-ready status clear on read. | Reports X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupt status. Wake-on-Motion and data-ready status fields are cleared on read. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 0.500000 | R/C | R |
| `field_parts` | 0.2987 | 0.717106 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{22})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×0.500000 + 0.2987×0.717106 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.683900/1.0001=\mathbf{0.683831}\).

### Extracted logical register 23: `ACCEL_XOUT`

v1 location: `registers[22]`; datasheet association: PDF p.39, §9.20, Tables 51-52.

Associated physical locations: [{"hex":"0x3B","decimal":"59","bank":"","page":"","description":"High byte of the 16-bit X-axis accelerometer measurement."},{"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Low byte of the 16-bit X-axis accelerometer measurement."}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `ACCEL_XOUT_H` at 0x3B (59)

Location: `v1 registers[22].field_parts[0]`; datasheet source: PDF p.39, Table 51.

**Datasheet bit field 1: `ACCEL_XOUT_H[15:8]`, bits [7:0]**

Location: `v1 registers[22].field_parts[0].bit_field[0]`; datasheet source: PDF p.39, Table 51. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_XOUT_H[15:8] | ACCEL_XOUT_H[15:8] |
| `field_description` | 0.0586 | 1.0 | High byte of accelerometer X-axis data. | High byte of X-axis accelerometer data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_XOUT_H | ACCEL_XOUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":"High byte of accelerometer X-axis data."} | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":"High byte of the 16-bit X-axis accelerometer measurement."} |
| `description` | 0.0693 | 1.000000 | High byte. | High byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

##### Field part 2: `ACCEL_XOUT_L` at 0x3C (60)

Location: `v1 registers[22].field_parts[1]`; datasheet source: PDF p.39, Table 52.

**Datasheet bit field 1: `ACCEL_XOUT_L[7:0]`, bits [7:0]**

Location: `v1 registers[22].field_parts[1].bit_field[0]`; datasheet source: PDF p.39, Table 52. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_XOUT_L[7:0] | ACCEL_XOUT_L[7:0] |
| `field_description` | 0.0586 | 1.0 | Low byte of accelerometer X-axis data. | Low byte of X-axis accelerometer data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_XOUT_L | ACCEL_XOUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Low byte of accelerometer X-axis data."} | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Low byte of the 16-bit X-axis accelerometer measurement."} |
| `description` | 0.0693 | 1.000000 | Low byte. | Low byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

#### Logical-register aggregation

field_parts correctness = mean(0.981756, 0.981756) = **0.981756**.

Direct judgment: 直接字段不完全正确：field_parts=0.981756；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_XOUT | ACCEL_XOUT |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x3B","decimal":"59","bank":"","page":"","description":"High byte of accelerometer X-axis data."},{"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Low byte of accelerometer X-axis data."}] | [{"hex":"0x3B","decimal":"59","bank":"","page":"","description":"High byte of the 16-bit X-axis accelerometer measurement."},{"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Low byte of the 16-bit X-axis accelerometer measurement."}] |
| `register_description` | 0.0564 | 1.000000 | Contains the latest 16-bit X-axis accelerometer measurement. | Contains the latest 16-bit X-axis accelerometer measurement and may be read at any time through the serial interface. |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.981756 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x0000 | 0x0000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | High byte at 0x3B followed by low byte at 0x3C; inferred from the stated 0x00 reset value of both physical registers. |

\(Q(L_{23})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.994651/1.0001=\mathbf{0.994551}\).

### Extracted logical register 24: `ACCEL_YOUT`

v1 location: `registers[23]`; datasheet association: PDF p.39, §9.20, Tables 53-54.

Associated physical locations: [{"hex":"0x3D","decimal":"61","bank":"","page":"","description":"High byte of the 16-bit Y-axis accelerometer measurement."},{"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Low byte of the 16-bit Y-axis accelerometer measurement."}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `ACCEL_YOUT_H` at 0x3D (61)

Location: `v1 registers[23].field_parts[0]`; datasheet source: PDF p.39, Table 53.

**Datasheet bit field 1: `ACCEL_YOUT_H[15:8]`, bits [7:0]**

Location: `v1 registers[23].field_parts[0].bit_field[0]`; datasheet source: PDF p.39, Table 53. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_YOUT_H[15:8] | ACCEL_YOUT_H[15:8] |
| `field_description` | 0.0586 | 1.0 | High byte of accelerometer Y-axis data. | High byte of Y-axis accelerometer data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_YOUT_H | ACCEL_YOUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"High byte of accelerometer Y-axis data."} | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"High byte of the 16-bit Y-axis accelerometer measurement."} |
| `description` | 0.0693 | 1.000000 | High byte. | High byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

##### Field part 2: `ACCEL_YOUT_L` at 0x3E (62)

Location: `v1 registers[23].field_parts[1]`; datasheet source: PDF p.39, Table 54.

**Datasheet bit field 1: `ACCEL_YOUT_L[7:0]`, bits [7:0]**

Location: `v1 registers[23].field_parts[1].bit_field[0]`; datasheet source: PDF p.39, Table 54. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_YOUT_L[7:0] | ACCEL_YOUT_L[7:0] |
| `field_description` | 0.0586 | 1.0 | Low byte of accelerometer Y-axis data. | Low byte of Y-axis accelerometer data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_YOUT_L | ACCEL_YOUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Low byte of accelerometer Y-axis data."} | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Low byte of the 16-bit Y-axis accelerometer measurement."} |
| `description` | 0.0693 | 1.000000 | Low byte. | Low byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

#### Logical-register aggregation

field_parts correctness = mean(0.981756, 0.981756) = **0.981756**.

Direct judgment: 直接字段不完全正确：field_parts=0.981756；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_YOUT | ACCEL_YOUT |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x3D","decimal":"61","bank":"","page":"","description":"High byte of accelerometer Y-axis data."},{"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Low byte of accelerometer Y-axis data."}] | [{"hex":"0x3D","decimal":"61","bank":"","page":"","description":"High byte of the 16-bit Y-axis accelerometer measurement."},{"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Low byte of the 16-bit Y-axis accelerometer measurement."}] |
| `register_description` | 0.0564 | 1.000000 | Contains the latest 16-bit Y-axis accelerometer measurement. | Contains the latest 16-bit Y-axis accelerometer measurement and may be read at any time through the serial interface. |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.981756 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x0000 | 0x0000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | High byte at 0x3D followed by low byte at 0x3E; inferred from the stated 0x00 reset value of both physical registers. |

\(Q(L_{24})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.994651/1.0001=\mathbf{0.994551}\).

### Extracted logical register 25: `ACCEL_ZOUT`

v1 location: `registers[24]`; datasheet association: PDF p.39, §9.20, Tables 55-56.

Associated physical locations: [{"hex":"0x3F","decimal":"63","bank":"","page":"","description":"High byte of the 16-bit Z-axis accelerometer measurement."},{"hex":"0x40","decimal":"64","bank":"","page":"","description":"Low byte of the 16-bit Z-axis accelerometer measurement."}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `ACCEL_ZOUT_H` at 0x3F (63)

Location: `v1 registers[24].field_parts[0]`; datasheet source: PDF p.39, Table 55.

**Datasheet bit field 1: `ACCEL_ZOUT_H[15:8]`, bits [7:0]**

Location: `v1 registers[24].field_parts[0].bit_field[0]`; datasheet source: PDF p.39, Table 55. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_ZOUT_H[15:8] | ACCEL_ZOUT_H[15:8] |
| `field_description` | 0.0586 | 1.0 | High byte of accelerometer Z-axis data. | High byte of Z-axis accelerometer data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_ZOUT_H | ACCEL_ZOUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3F","decimal":"63","bank":"","page":"","description":"High byte of accelerometer Z-axis data."} | {"hex":"0x3F","decimal":"63","bank":"","page":"","description":"High byte of the 16-bit Z-axis accelerometer measurement."} |
| `description` | 0.0693 | 1.000000 | High byte. | High byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

##### Field part 2: `ACCEL_ZOUT_L` at 0x40 (64)

Location: `v1 registers[24].field_parts[1]`; datasheet source: PDF p.39, Table 56.

**Datasheet bit field 1: `ACCEL_ZOUT_L[7:0]`, bits [7:0]**

Location: `v1 registers[24].field_parts[1].bit_field[0]`; datasheet source: PDF p.39, Table 56. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_ZOUT_L[7:0] | ACCEL_ZOUT_L[7:0] |
| `field_description` | 0.0586 | 1.0 | Low byte of accelerometer Z-axis data. | Low byte of Z-axis accelerometer data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_ZOUT_L | ACCEL_ZOUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x40","decimal":"64","bank":"","page":"","description":"Low byte of accelerometer Z-axis data."} | {"hex":"0x40","decimal":"64","bank":"","page":"","description":"Low byte of the 16-bit Z-axis accelerometer measurement."} |
| `description` | 0.0693 | 1.000000 | Low byte. | Low byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

#### Logical-register aggregation

field_parts correctness = mean(0.981756, 0.981756) = **0.981756**.

Direct judgment: 直接字段不完全正确：field_parts=0.981756；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_ZOUT | ACCEL_ZOUT |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x3F","decimal":"63","bank":"","page":"","description":"High byte of accelerometer Z-axis data."},{"hex":"0x40","decimal":"64","bank":"","page":"","description":"Low byte of accelerometer Z-axis data."}] | [{"hex":"0x3F","decimal":"63","bank":"","page":"","description":"High byte of the 16-bit Z-axis accelerometer measurement."},{"hex":"0x40","decimal":"64","bank":"","page":"","description":"Low byte of the 16-bit Z-axis accelerometer measurement."}] |
| `register_description` | 0.0564 | 1.000000 | Contains the latest 16-bit Z-axis accelerometer measurement. | Contains the latest 16-bit Z-axis accelerometer measurement and may be read at any time through the serial interface. |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.981756 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x0000 | 0x0000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | High byte at 0x3F followed by low byte at 0x40; inferred from the stated 0x00 reset value of both physical registers. |

\(Q(L_{25})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.994651/1.0001=\mathbf{0.994551}\).

### Extracted logical register 26: `TEMP_OUT`

v1 location: `registers[25]`; datasheet association: PDF p.39, §9.21, Tables 57-58.

Associated physical locations: [{"hex":"0x41","decimal":"65","bank":"","page":"","description":"High byte of the 16-bit temperature sensor output."},{"hex":"0x42","decimal":"66","bank":"","page":"","description":"Low byte of the 16-bit temperature sensor output."}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `TEMP_OUT_H` at 0x41 (65)

Location: `v1 registers[25].field_parts[0]`; datasheet source: PDF p.39, Table 57.

**Datasheet bit field 1: `TEMP_OUT[15:8]`, bits [7:0]**

Location: `v1 registers[25].field_parts[0].bit_field[0]`; datasheet source: PDF p.39, Table 57. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_OUT[15:8] | TEMP_OUT[15:8] |
| `field_description` | 0.0586 | 1.0 | High byte of the temperature sensor output. | High byte of the temperature sensor output. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TEMP_OUT_H | TEMP_OUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x41","decimal":"65","bank":"","page":"","description":"High byte of the temperature sensor output."} | {"hex":"0x41","decimal":"65","bank":"","page":"","description":"High byte of the 16-bit temperature sensor output."} |
| `description` | 0.0693 | 1.000000 | High byte. | High byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

##### Field part 2: `TEMP_OUT_L` at 0x42 (66)

Location: `v1 registers[25].field_parts[1]`; datasheet source: PDF p.39, Table 58.

**Datasheet bit field 1: `TEMP_OUT[7:0]`, bits [7:0]**

Location: `v1 registers[25].field_parts[1].bit_field[0]`; datasheet source: PDF p.39, Table 58. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_OUT[7:0] | TEMP_OUT[7:0] |
| `field_description` | 0.0586 | 1.0 | Low byte of the temperature sensor output. | Low byte of the temperature sensor output. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TEMP_OUT_L | TEMP_OUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x42","decimal":"66","bank":"","page":"","description":"Low byte of the temperature sensor output."} | {"hex":"0x42","decimal":"66","bank":"","page":"","description":"Low byte of the 16-bit temperature sensor output."} |
| `description` | 0.0693 | 1.000000 | Low byte. | Low byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

#### Logical-register aggregation

field_parts correctness = mean(0.981756, 0.981756) = **0.981756**.

Direct judgment: 直接字段不完全正确：field_parts=0.981756；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TEMP_OUT | TEMP_OUT |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x41","decimal":"65","bank":"","page":"","description":"High byte of the temperature sensor output."},{"hex":"0x42","decimal":"66","bank":"","page":"","description":"Low byte of the temperature sensor output."}] | [{"hex":"0x41","decimal":"65","bank":"","page":"","description":"High byte of the 16-bit temperature sensor output."},{"hex":"0x42","decimal":"66","bank":"","page":"","description":"Low byte of the 16-bit temperature sensor output."}] |
| `register_description` | 0.0564 | 1.000000 | Contains the latest 16-bit temperature sensor output; TEMP [°C] = ((TEMP_OUT - RoomTemp_Offset)/Temp_Sensitivity) + 25°C. | Contains the latest 16-bit temperature measurement. Convert it using TEMP [°C] = ((TEMP_OUT - RoomTemp_Offset) / Temp_Sensitivity) + 25°C. |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.981756 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x0000 | 0x0000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | High byte at 0x41 followed by low byte at 0x42; inferred from the stated 0x00 reset value of both physical registers. |

\(Q(L_{26})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.994651/1.0001=\mathbf{0.994551}\).

### Extracted logical register 27: `GYRO_XOUT`

v1 location: `registers[26]`; datasheet association: PDF p.40, §9.22, Tables 59-60.

Associated physical locations: [{"hex":"0x43","decimal":"67","bank":"","page":"","description":"High byte of the 16-bit X-axis gyroscope output."},{"hex":"0x44","decimal":"68","bank":"","page":"","description":"Low byte of the 16-bit X-axis gyroscope output."}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `GYRO_XOUT_H` at 0x43 (67)

Location: `v1 registers[26].field_parts[0]`; datasheet source: PDF p.40, Table 59.

**Datasheet bit field 1: `GYRO_XOUT[15:8]`, bits [7:0]**

Location: `v1 registers[26].field_parts[0].bit_field[0]`; datasheet source: PDF p.40, Table 59. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_XOUT[15:8] | GYRO_XOUT[15:8] |
| `field_description` | 0.0586 | 1.0 | High byte of the X-axis gyroscope output. | High byte of the X-axis gyroscope output. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | GYRO_XOUT_H | GYRO_XOUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x43","decimal":"67","bank":"","page":"","description":"High byte of the X-axis gyroscope output."} | {"hex":"0x43","decimal":"67","bank":"","page":"","description":"High byte of the 16-bit X-axis gyroscope output."} |
| `description` | 0.0693 | 1.000000 | High byte. | High byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

##### Field part 2: `GYRO_XOUT_L` at 0x44 (68)

Location: `v1 registers[26].field_parts[1]`; datasheet source: PDF p.40, Table 60.

**Datasheet bit field 1: `GYRO_XOUT[7:0]`, bits [7:0]**

Location: `v1 registers[26].field_parts[1].bit_field[0]`; datasheet source: PDF p.40, Table 60. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_XOUT[7:0] | GYRO_XOUT[7:0] |
| `field_description` | 0.0586 | 1.0 | Low byte of the X-axis gyroscope output. | Low byte of the X-axis gyroscope output. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | GYRO_XOUT_L | GYRO_XOUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x44","decimal":"68","bank":"","page":"","description":"Low byte of the X-axis gyroscope output."} | {"hex":"0x44","decimal":"68","bank":"","page":"","description":"Low byte of the 16-bit X-axis gyroscope output."} |
| `description` | 0.0693 | 1.000000 | Low byte. | Low byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

#### Logical-register aggregation

field_parts correctness = mean(0.981756, 0.981756) = **0.981756**.

Direct judgment: 直接字段不完全正确：field_parts=0.981756；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | GYRO_XOUT | GYRO_XOUT |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x43","decimal":"67","bank":"","page":"","description":"High byte of the X-axis gyroscope output."},{"hex":"0x44","decimal":"68","bank":"","page":"","description":"Low byte of the X-axis gyroscope output."}] | [{"hex":"0x43","decimal":"67","bank":"","page":"","description":"High byte of the 16-bit X-axis gyroscope output."},{"hex":"0x44","decimal":"68","bank":"","page":"","description":"Low byte of the 16-bit X-axis gyroscope output."}] |
| `register_description` | 0.0564 | 1.000000 | Contains the latest 16-bit X-axis gyroscope output; GYRO_XOUT = Gyro_Sensitivity × X_angular_rate, with nominal sensitivity 131 LSB/(dps) at FS_SEL=0. | Contains the latest 16-bit X-axis gyroscope measurement. GYRO_XOUT = Gyro_Sensitivity × X_angular_rate; for nominal FS_SEL = 0, Gyro_Sensitivity = 131 LSB/(dps). |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.981756 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x0000 | 0x0000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | High byte at 0x43 followed by low byte at 0x44; inferred from the stated 0x00 reset value of both physical registers. |

\(Q(L_{27})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.994651/1.0001=\mathbf{0.994551}\).

### Extracted logical register 28: `GYRO_YOUT`

v1 location: `registers[27]`; datasheet association: PDF p.40, §9.22, Tables 61-62.

Associated physical locations: [{"hex":"0x45","decimal":"69","bank":"","page":"","description":"High byte of the 16-bit Y-axis gyroscope output."},{"hex":"0x46","decimal":"70","bank":"","page":"","description":"Low byte of the 16-bit Y-axis gyroscope output."}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `GYRO_YOUT_H` at 0x45 (69)

Location: `v1 registers[27].field_parts[0]`; datasheet source: PDF p.40, Table 61.

**Datasheet bit field 1: `GYRO_YOUT[15:8]`, bits [7:0]**

Location: `v1 registers[27].field_parts[0].bit_field[0]`; datasheet source: PDF p.40, Table 61. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_YOUT[15:8] | GYRO_YOUT[15:8] |
| `field_description` | 0.0586 | 1.0 | High byte of the Y-axis gyroscope output. | High byte of the Y-axis gyroscope output. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | GYRO_YOUT_H | GYRO_YOUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x45","decimal":"69","bank":"","page":"","description":"High byte of the Y-axis gyroscope output."} | {"hex":"0x45","decimal":"69","bank":"","page":"","description":"High byte of the 16-bit Y-axis gyroscope output."} |
| `description` | 0.0693 | 1.000000 | High byte. | High byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

##### Field part 2: `GYRO_YOUT_L` at 0x46 (70)

Location: `v1 registers[27].field_parts[1]`; datasheet source: PDF p.40, Table 62.

**Datasheet bit field 1: `GYRO_YOUT[7:0]`, bits [7:0]**

Location: `v1 registers[27].field_parts[1].bit_field[0]`; datasheet source: PDF p.40, Table 62. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_YOUT[7:0] | GYRO_YOUT[7:0] |
| `field_description` | 0.0586 | 1.0 | Low byte of the Y-axis gyroscope output. | Low byte of the Y-axis gyroscope output. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | GYRO_YOUT_L | GYRO_YOUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x46","decimal":"70","bank":"","page":"","description":"Low byte of the Y-axis gyroscope output."} | {"hex":"0x46","decimal":"70","bank":"","page":"","description":"Low byte of the 16-bit Y-axis gyroscope output."} |
| `description` | 0.0693 | 1.000000 | Low byte. | Low byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

#### Logical-register aggregation

field_parts correctness = mean(0.981756, 0.981756) = **0.981756**.

Direct judgment: 直接字段不完全正确：field_parts=0.981756；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | GYRO_YOUT | GYRO_YOUT |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x45","decimal":"69","bank":"","page":"","description":"High byte of the Y-axis gyroscope output."},{"hex":"0x46","decimal":"70","bank":"","page":"","description":"Low byte of the Y-axis gyroscope output."}] | [{"hex":"0x45","decimal":"69","bank":"","page":"","description":"High byte of the 16-bit Y-axis gyroscope output."},{"hex":"0x46","decimal":"70","bank":"","page":"","description":"Low byte of the 16-bit Y-axis gyroscope output."}] |
| `register_description` | 0.0564 | 1.000000 | Contains the latest 16-bit Y-axis gyroscope output; GYRO_YOUT = Gyro_Sensitivity × Y_angular_rate, with nominal sensitivity 131 LSB/(dps) at FS_SEL=0. | Contains the latest 16-bit Y-axis gyroscope measurement. GYRO_YOUT = Gyro_Sensitivity × Y_angular_rate; for nominal FS_SEL = 0, Gyro_Sensitivity = 131 LSB/(dps). |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.981756 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x0000 | 0x0000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | High byte at 0x45 followed by low byte at 0x46; inferred from the stated 0x00 reset value of both physical registers. |

\(Q(L_{28})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.994651/1.0001=\mathbf{0.994551}\).

### Extracted logical register 29: `GYRO_ZOUT`

v1 location: `registers[28]`; datasheet association: PDF p.40, §9.22, Tables 63-64.

Associated physical locations: [{"hex":"0x47","decimal":"71","bank":"","page":"","description":"High byte of the 16-bit Z-axis gyroscope output."},{"hex":"0x48","decimal":"72","bank":"","page":"","description":"Low byte of the 16-bit Z-axis gyroscope output."}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `GYRO_ZOUT_H` at 0x47 (71)

Location: `v1 registers[28].field_parts[0]`; datasheet source: PDF p.40, Table 63.

**Datasheet bit field 1: `GYRO_ZOUT[15:8]`, bits [7:0]**

Location: `v1 registers[28].field_parts[0].bit_field[0]`; datasheet source: PDF p.40, Table 63. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_ZOUT[15:8] | GYRO_ZOUT[15:8] |
| `field_description` | 0.0586 | 1.0 | High byte of the Z-axis gyroscope output. | High byte of the Z-axis gyroscope output. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | GYRO_ZOUT_H | GYRO_ZOUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x47","decimal":"71","bank":"","page":"","description":"High byte of the Z-axis gyroscope output."} | {"hex":"0x47","decimal":"71","bank":"","page":"","description":"High byte of the 16-bit Z-axis gyroscope output."} |
| `description` | 0.0693 | 1.000000 | High byte. | High byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

##### Field part 2: `GYRO_ZOUT_L` at 0x48 (72)

Location: `v1 registers[28].field_parts[1]`; datasheet source: PDF p.40, Table 64.

**Datasheet bit field 1: `GYRO_ZOUT[7:0]`, bits [7:0]**

Location: `v1 registers[28].field_parts[1].bit_field[0]`; datasheet source: PDF p.40, Table 64. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_ZOUT[7:0] | GYRO_ZOUT[7:0] |
| `field_description` | 0.0586 | 1.0 | Low byte of the Z-axis gyroscope output. | Low byte of the Z-axis gyroscope output. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | GYRO_ZOUT_L | GYRO_ZOUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x48","decimal":"72","bank":"","page":"","description":"Low byte of the Z-axis gyroscope output."} | {"hex":"0x48","decimal":"72","bank":"","page":"","description":"Low byte of the 16-bit Z-axis gyroscope output."} |
| `description` | 0.0693 | 1.000000 | Low byte. | Low byte. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.981756/1.0000=\mathbf{0.981756}\).

#### Logical-register aggregation

field_parts correctness = mean(0.981756, 0.981756) = **0.981756**.

Direct judgment: 直接字段不完全正确：field_parts=0.981756；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | GYRO_ZOUT | GYRO_ZOUT |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x47","decimal":"71","bank":"","page":"","description":"High byte of the Z-axis gyroscope output."},{"hex":"0x48","decimal":"72","bank":"","page":"","description":"Low byte of the Z-axis gyroscope output."}] | [{"hex":"0x47","decimal":"71","bank":"","page":"","description":"High byte of the 16-bit Z-axis gyroscope output."},{"hex":"0x48","decimal":"72","bank":"","page":"","description":"Low byte of the 16-bit Z-axis gyroscope output."}] |
| `register_description` | 0.0564 | 1.000000 | Contains the latest 16-bit Z-axis gyroscope output; GYRO_ZOUT = Gyro_Sensitivity × Z_angular_rate, with nominal sensitivity 131 LSB/(dps) at FS_SEL=0. | Contains the latest 16-bit Z-axis gyroscope measurement. GYRO_ZOUT = Gyro_Sensitivity × Z_angular_rate; for nominal FS_SEL = 0, Gyro_Sensitivity = 131 LSB/(dps). |
| `width_bits` | 0.0590 | 1.000000 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.981756 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x0000 | 0x0000 |
| `default_value_description` | 0.0334 | 1.000000 | "" | High byte at 0x47 followed by low byte at 0x48; inferred from the stated 0x00 reset value of both physical registers. |

\(Q(L_{29})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.981756 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.994651/1.0001=\mathbf{0.994551}\).

### Extracted logical register 30: `SIGNAL_PATH_RESET`

v1 location: `registers[29]`; datasheet association: PDF p.41, §9.23, Table 65.

Associated physical locations: [{"hex":"0x68","decimal":"104","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `SIGNAL_PATH_RESET` at 0x68 (104)

Location: `v1 registers[29].field_parts[0]`; datasheet source: PDF p.41, §9.23, Table 65.

**Datasheet bit field 1: `-`, bits [7:2]**

Location: `v1 registers[29].field_parts[0].bit_field[0]`; datasheet source: PDF p.41, §9.23, Table 65. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `ACCEL_RST`, bits [1]**

Location: `v1 registers[29].field_parts[0].bit_field[1]`; datasheet source: PDF p.41, §9.23, Table 65. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_RST | ACCEL_RST |
| `field_description` | 0.0586 | 1.0 | Reset accel digital signal path; sensor registers are not cleared. | Resets the accelerometer digital signal path without clearing sensor registers. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 3: `TEMP_RST`, bits [0]**

Location: `v1 registers[29].field_parts[0].bit_field[2]`; datasheet source: PDF p.41, §9.23, Table 65. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_RST | TEMP_RST |
| `field_description` | 0.0586 | 1.0 | Reset temp digital signal path; sensor registers are not cleared. | Resets the temperature digital signal path without clearing sensor registers. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | SIGNAL_PATH_RESET | SIGNAL_PATH_RESET |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x68","decimal":"104","bank":"","page":"","description":"SIGNAL_PATH_RESET register; Resets the accelerometer or temperature digital signal path; sensor registers are not cleared."} | {"hex":"0x68","decimal":"104","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Resets the accelerometer or temperature digital signal path; sensor registers are not cleared. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | SIGNAL_PATH_RESET | SIGNAL_PATH_RESET |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x68","decimal":"104","bank":"","page":"","description":"SIGNAL_PATH_RESET register; Resets the accelerometer or temperature digital signal path; sensor registers are not cleared."}] | [{"hex":"0x68","decimal":"104","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Resets the accelerometer or temperature digital signal path; sensor registers are not cleared. | Resets the accelerometer or temperature digital signal path. These operations do not clear sensor registers; use USER_CTRL.SIG_COND_RST to clear sensor registers. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{30})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 31: `ACCEL_INTEL_CTRL`

v1 location: `registers[30]`; datasheet association: PDF p.41, §9.24, Table 66.

Associated physical locations: [{"hex":"0x69","decimal":"105","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `ACCEL_INTEL_CTRL` at 0x69 (105)

Location: `v1 registers[30].field_parts[0]`; datasheet source: PDF p.41, §9.24, Table 66.

**Datasheet bit field 1: `ACCEL_INTEL_EN`, bits [7]**

Location: `v1 registers[30].field_parts[0].bit_field[0]`; datasheet source: PDF p.41, §9.24, Table 66. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_INTEL_EN | ACCEL_INTEL_EN |
| `field_description` | 0.0586 | 1.0 | Enables the Wake-on-Motion detection logic. | Enables Wake-on-Motion detection logic. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `ACCEL_INTEL_MODE`, bits [6]**

Location: `v1 registers[30].field_parts[0].bit_field[1]`; datasheet source: PDF p.41, §9.24, Table 66. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_INTEL_MODE | ACCEL_INTEL_MODE |
| `field_description` | 0.0586 | 1.0 | Selects the Wake-on-Motion sample-comparison mode. | Selects the Wake-on-Motion sample-comparison mode. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Compare current sample to the first sample taken when entering WoM mode."},{"value":"1","value_description":"Compare current sample with the previous sample."}] | [{"value":"0","value_description":"Compare the current sample to the first sample taken when entering Wake-on-Motion mode."},{"value":"1","value_description":"Compare the current sample with the previous sample."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 3: `-`, bits [5:1]**

Location: `v1 registers[30].field_parts[0].bit_field[2]`; datasheet source: PDF p.41, §9.24, Table 66. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 4: `-`, bits [0]**

Location: `v1 registers[30].field_parts[0].bit_field[3]`; datasheet source: PDF p.41, §9.24, Table 66. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved; must be set to 0 when WoM is activated. | Reserved; must be set to 0 when Wake-on-Motion is activated. Refer to section 5.1. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_INTEL_CTRL | ACCEL_INTEL_CTRL |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x69","decimal":"105","bank":"","page":"","description":"ACCEL_INTEL_CTRL register; Enables Wake-on-Motion detection and selects current-sample comparison with the first or previous sample; bit 0 must be 0 when WoM is activated."} | {"hex":"0x69","decimal":"105","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Enables Wake-on-Motion detection and selects current-sample comparison with the first or previous sample; bit 0 must be 0 when WoM is activated. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_INTEL_CTRL | ACCEL_INTEL_CTRL |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x69","decimal":"105","bank":"","page":"","description":"ACCEL_INTEL_CTRL register; Enables Wake-on-Motion detection and selects current-sample comparison with the first or previous sample; bit 0 must be 0 when WoM is activated."}] | [{"hex":"0x69","decimal":"105","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Enables Wake-on-Motion detection and selects current-sample comparison with the first or previous sample; bit 0 must be 0 when WoM is activated. | Enables Wake-on-Motion detection and selects whether the current accelerometer sample is compared with the first sample on entry or the previous sample. Bit 0 must remain 0 when Wake-on-Motion is active; see section 5.1 for the full configuration workflow. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{31})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 32: `USER_CTRL`

v1 location: `registers[31]`; datasheet association: PDF p.41, §9.25, Table 67.

Associated physical locations: [{"hex":"0x6A","decimal":"106","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `USER_CTRL` at 0x6A (106)

Location: `v1 registers[31].field_parts[0]`; datasheet source: PDF p.41, §9.25, Table 67.

**Datasheet bit field 1: `-`, bits [7:5]**

Location: `v1 registers[31].field_parts[0].bit_field[0]`; datasheet source: PDF p.41, §9.25, Table 67. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `I2C_IF_DIS`, bits [4]**

Location: `v1 registers[31].field_parts[0].bit_field[1]`; datasheet source: PDF p.41, §9.25, Table 67. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_IF_DIS | I2C_IF_DIS |
| `field_description` | 0.0586 | 1.0 | Disable I²C Slave module and put serial interface in SPI-only mode. | Disables the I²C slave module and places the serial interface in SPI-only mode. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Disable I²C slave module; SPI-only mode."}] | [{"value":"1","value_description":"Disable I²C slave module; SPI-only mode."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 3: `-`, bits [3:1]**

Location: `v1 registers[31].field_parts[0].bit_field[2]`; datasheet source: PDF p.41, §9.25, Table 67. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 4: `SIG_COND_RST`, bits [0]**

Location: `v1 registers[31].field_parts[0].bit_field[3]`; datasheet source: PDF p.41, §9.25, Table 67. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SIG_COND_RST | SIG_COND_RST |
| `field_description` | 0.0586 | 1.0 | Reset all gyro, accel, and temperature digital signal paths and clear all sensor registers. | Resets all gyro, accelerometer, and temperature digital signal paths and clears all sensor registers. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Reset all sensor digital signal paths and clear sensor registers."}] | [{"value":"1","value_description":"Reset all sensor digital signal paths and clear sensor registers."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | USER_CTRL | USER_CTRL |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x6A","decimal":"106","bank":"","page":"","description":"USER_CTRL register; Controls serial-interface mode and digital signal-path reset; I2C_IF_DIS selects SPI-only operation and SIG_COND_RST clears sensor registers."} | {"hex":"0x6A","decimal":"106","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Controls serial-interface mode and digital signal-path reset; I2C_IF_DIS selects SPI-only operation and SIG_COND_RST clears sensor registers. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | USER_CTRL | USER_CTRL |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x6A","decimal":"106","bank":"","page":"","description":"USER_CTRL register; Controls serial-interface mode and digital signal-path reset; I2C_IF_DIS selects SPI-only operation and SIG_COND_RST clears sensor registers."}] | [{"hex":"0x6A","decimal":"106","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Controls serial-interface mode and digital signal-path reset; I2C_IF_DIS selects SPI-only operation and SIG_COND_RST clears sensor registers. | Controls serial-interface mode and digital signal-path reset. I2C_IF_DIS disables the I²C slave and leaves SPI-only operation; SIG_COND_RST resets gyro, accelerometer, and temperature digital signal paths and clears sensor registers. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{32})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 33: `PWR_MGMT_1`

v1 location: `registers[32]`; datasheet association: PDF pp.41-42, §9.26, Tables 68-69.

Associated physical locations: [{"hex":"0x6B","decimal":"107","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `PWR_MGMT_1` at 0x6B (107)

Location: `v1 registers[32].field_parts[0]`; datasheet source: PDF pp.41-42, §9.26, Tables 68-69.

**Datasheet bit field 1: `DEVICE_RESET`, bits [7]**

Location: `v1 registers[32].field_parts[0].bit_field[0]`; datasheet source: PDF pp.41-42, §9.26, Tables 68-69. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DEVICE_RESET | DEVICE_RESET |
| `field_description` | 0.0586 | 1.0 | Resets internal registers and restores defaults; automatically clears when reset completes. | Resets internal registers and restores default settings; automatically clears when reset completes. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Reset internal registers and restore default settings."}] | [{"value":"1","value_description":"Reset internal registers and restore defaults."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `SLEEP`, bits [6]**

Location: `v1 registers[32].field_parts[0].bit_field[1]`; datasheet source: PDF pp.41-42, §9.26, Tables 68-69. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SLEEP | SLEEP |
| `field_description` | 0.0586 | 1.0 | When set to 1, the chip is in sleep mode; default is 0. | Places the device in sleep mode; default is 0. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Sleep mode."},{"value":"0","value_description":"Default setting."}] | [{"value":"1","value_description":"Sleep mode."},{"value":"0","value_description":"Default setting."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 3: `ACCEL_CYCLE`, bits [5]**

Location: `v1 registers[32].field_parts[0].bit_field[2]`; datasheet source: PDF pp.41-42, §9.26, Tables 68-69. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_CYCLE | ACCEL_CYCLE |
| `field_description` | 0.0586 | 1.0 | When set to 1, and SLEEP and STANDBY are not 1, the chip cycles between sleep and taking a single accelerometer sample. | When set while SLEEP and STANDBY are not set, cycles between sleep and taking one accelerometer sample. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 4: `GYRO_STANDBY`, bits [4]**

Location: `v1 registers[32].field_parts[0].bit_field[3]`; datasheet source: PDF pp.41-42, §9.26, Tables 68-69. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_STANDBY | GYRO_STANDBY |
| `field_description` | 0.0586 | 1.0 | When set, gyro drive and PLL are enabled but sense paths are disabled. | Enables gyro drive and PLL while disabling sense paths for quick gyro enabling. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 5: `TEMP_DIS`, bits [3]**

Location: `v1 registers[32].field_parts[0].bit_field[4]`; datasheet source: PDF pp.41-42, §9.26, Tables 68-69. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_DIS | TEMP_DIS |
| `field_description` | 0.0586 | 1.0 | When set to 1, this bit disables the temperature sensor. | Disables the temperature sensor. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Temperature sensor disabled."}] | [{"value":"1","value_description":"Temperature sensor disabled."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 6: `CLKSEL[2:0]`, bits [2:0]**

Location: `v1 registers[32].field_parts[0].bit_field[5]`; datasheet source: PDF pp.41-42, §9.26, Tables 68-69. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | CLKSEL[2:0] | CLKSEL[2:0] |
| `field_description` | 0.0586 | 1.0 | Clock-source selection; default is 001. | Clock-source selection; default is 001. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Internal 20 MHz oscillator."},{"value":"1","value_description":"Auto selects the best available clock source - PLL if ready, else use the Internal oscillator."},{"value":"2","value_description":"Auto selects the best available clock source - PLL if ready, else use the Internal oscillator."},{"value":"3","value_description":"Auto selects the best available clock source - PLL if ready, else use the Internal oscillator."},{"value":"4","value_description":"Auto selects the best available clock source - PLL if ready, else use the Internal oscillator."},{"value":"5","value_description":"Auto selects the best available clock source - PLL if ready, else use the Internal oscillator."},{"value":"6","value_description":"Internal 20 MHz oscillator."},{"value":"7","value_description":"Stops the clock and keeps timing generator in reset."}] | [{"value":"0","value_description":"Internal 20 MHz oscillator."},{"value":"1","value_description":"Auto-select best available source: PLL if ready, otherwise internal oscillator."},{"value":"2","value_description":"Auto-select best available source: PLL if ready, otherwise internal oscillator."},{"value":"3","value_description":"Auto-select best available source: PLL if ready, otherwise internal oscillator."},{"value":"4","value_description":"Auto-select best available source: PLL if ready, otherwise internal oscillator."},{"value":"5","value_description":"Auto-select best available source: PLL if ready, otherwise internal oscillator."},{"value":"6","value_description":"Internal 20 MHz oscillator."},{"value":"7","value_description":"Stop the clock and keep the timing generator in reset."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | PWR_MGMT_1 | PWR_MGMT_1 |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x6B","decimal":"107","bank":"","page":"","description":"PWR_MGMT_1 register; Controls device reset, sleep, accelerometer cycle, gyroscope standby, temperature disable, and clock source; default PWR_MGMT_1 is 0x01 and CLKSEL[2:0] defaults to 001."} | {"hex":"0x6B","decimal":"107","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Controls device reset, sleep, accelerometer cycle, gyroscope standby, temperature disable, and clock source; default PWR_MGMT_1 is 0x01 and CLKSEL[2:0] defaults to 001. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | PWR_MGMT_1 | PWR_MGMT_1 |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x6B","decimal":"107","bank":"","page":"","description":"PWR_MGMT_1 register; Controls device reset, sleep, accelerometer cycle, gyroscope standby, temperature disable, and clock source; default PWR_MGMT_1 is 0x01 and CLKSEL[2:0] defaults to 001."}] | [{"hex":"0x6B","decimal":"107","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Controls device reset, sleep, accelerometer cycle, gyroscope standby, temperature disable, and clock source; default PWR_MGMT_1 is 0x01 and CLKSEL[2:0] defaults to 001. | Controls device reset, sleep, accelerometer cycling, gyroscope standby, temperature disable, and clock source. After power-up, initialize and select the best clock by writing 0x81 before other register initialization; correct WHO_AM_I access is ensured after reset completion. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x01 | 0x01 |
| `default_value_description` | 0.0334 | 1.000000 | CLKSEL[2:0] defaults to 001. | CLKSEL[2:0] defaults to 001. |

\(Q(L_{33})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 34: `PWR_MGMT_2`

v1 location: `registers[33]`; datasheet association: PDF p.42, §9.27, Table 70.

Associated physical locations: [{"hex":"0x6C","decimal":"108","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `PWR_MGMT_2` at 0x6C (108)

Location: `v1 registers[33].field_parts[0]`; datasheet source: PDF p.42, §9.27, Table 70.

**Datasheet bit field 1: `-`, bits [7:6]**

Location: `v1 registers[33].field_parts[0].bit_field[0]`; datasheet source: PDF p.42, §9.27, Table 70. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 2: `STBY_XA`, bits [5]**

Location: `v1 registers[33].field_parts[0].bit_field[1]`; datasheet source: PDF p.42, §9.27, Table 70. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_XA | STBY_XA |
| `field_description` | 0.0586 | 1.0 | X accelerometer standby control. | X accelerometer standby control. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"X accelerometer disabled."},{"value":"0","value_description":"X accelerometer is on."}] | [{"value":"1","value_description":"X accelerometer disabled."},{"value":"0","value_description":"X accelerometer on."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 3: `STBY_YA`, bits [4]**

Location: `v1 registers[33].field_parts[0].bit_field[2]`; datasheet source: PDF p.42, §9.27, Table 70. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_YA | STBY_YA |
| `field_description` | 0.0586 | 1.0 | Y accelerometer standby control. | Y accelerometer standby control. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Y accelerometer disabled."},{"value":"0","value_description":"Y accelerometer is on."}] | [{"value":"1","value_description":"Y accelerometer disabled."},{"value":"0","value_description":"Y accelerometer on."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 4: `STBY_ZA`, bits [3]**

Location: `v1 registers[33].field_parts[0].bit_field[3]`; datasheet source: PDF p.42, §9.27, Table 70. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_ZA | STBY_ZA |
| `field_description` | 0.0586 | 1.0 | Z accelerometer standby control. | Z accelerometer standby control. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Z accelerometer disabled."},{"value":"0","value_description":"Z accelerometer is on."}] | [{"value":"1","value_description":"Z accelerometer disabled."},{"value":"0","value_description":"Z accelerometer on."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 5: `STBY_XG`, bits [2]**

Location: `v1 registers[33].field_parts[0].bit_field[4]`; datasheet source: PDF p.42, §9.27, Table 70. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_XG | STBY_XG |
| `field_description` | 0.0586 | 1.0 | X gyro standby control. | X gyroscope standby control. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"X gyro is disabled."},{"value":"0","value_description":"X gyro is on."}] | [{"value":"1","value_description":"X gyroscope disabled."},{"value":"0","value_description":"X gyroscope on."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 6: `STBY_YG`, bits [1]**

Location: `v1 registers[33].field_parts[0].bit_field[5]`; datasheet source: PDF p.42, §9.27, Table 70. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_YG | STBY_YG |
| `field_description` | 0.0586 | 1.0 | Y gyro standby control. | Y gyroscope standby control. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Y gyro is disabled."},{"value":"0","value_description":"Y gyro is on."}] | [{"value":"1","value_description":"Y gyroscope disabled."},{"value":"0","value_description":"Y gyroscope on."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Datasheet bit field 7: `STBY_ZG`, bits [0]**

Location: `v1 registers[33].field_parts[0].bit_field[6]`; datasheet source: PDF p.42, §9.27, Table 70. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | STBY_ZG | STBY_ZG |
| `field_description` | 0.0586 | 1.0 | Z gyro standby control. | Z gyroscope standby control. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Z gyro is disabled."},{"value":"0","value_description":"Z gyro is on."}] | [{"value":"1","value_description":"Z gyroscope disabled."},{"value":"0","value_description":"Z gyroscope on."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | PWR_MGMT_2 | PWR_MGMT_2 |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x6C","decimal":"108","bank":"","page":"","description":"PWR_MGMT_2 register; Individually controls standby/enable state for each accelerometer and gyroscope axis."} | {"hex":"0x6C","decimal":"108","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Individually controls standby/enable state for each accelerometer and gyroscope axis. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | PWR_MGMT_2 | PWR_MGMT_2 |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x6C","decimal":"108","bank":"","page":"","description":"PWR_MGMT_2 register; Individually controls standby/enable state for each accelerometer and gyroscope axis."}] | [{"hex":"0x6C","decimal":"108","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Individually controls standby/enable state for each accelerometer and gyroscope axis. | Individually enables or disables each accelerometer and gyroscope axis. Wake-on-Motion cycle-mode setup disables all gyro axes while leaving all accelerometer axes enabled. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

\(Q(L_{34})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 35: `WHO_AM_I`

v1 location: `registers[34]`; datasheet association: PDF p.42, §9.28, Table 71.

Associated physical locations: [{"hex":"0x75","decimal":"117","bank":"","page":"","description":""}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `WHO_AM_I` at 0x75 (117)

Location: `v1 registers[34].field_parts[0]`; datasheet source: PDF p.42, §9.28, Table 71.

**Datasheet bit field 1: `WHOAMI`, bits [7:0]**

Location: `v1 registers[34].field_parts[0].bit_field[0]`; datasheet source: PDF p.42, §9.28, Table 71. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WHOAMI | WHOAMI |
| `field_description` | 0.0586 | 1.0 | Register to indicate to user which device is being accessed. | Identifies which device is being accessed. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | R | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, description=0.000000, bit_field=0.941694；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4688 | 0.500000 | {"hex":"0x75","decimal":"117","bank":"","page":"","description":"WHO_AM_I register; Provides the 8-bit device identity for access verification; default value is 0xFE and is distinct from the device I²C address."} | {"hex":"0x75","decimal":"117","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.000000 | Provides the 8-bit device identity for access verification; default value is 0xFE and is distinct from the device I²C address. | "" |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 0.941694 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×0.500000 + 0.0693×0.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.941694)/1.0000=0.678056/1.0000=\mathbf{0.678056}\).

#### Logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.

Direct judgment: 直接字段不完全正确：physical_address=0.500000, field_parts=0.678056；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4044 | 0.500000 | [{"hex":"0x75","decimal":"117","bank":"","page":"","description":"WHO_AM_I register; Provides the 8-bit device identity for access verification; default value is 0xFE and is distinct from the device I²C address."}] | [{"hex":"0x75","decimal":"117","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.000000 | Provides the 8-bit device identity for access verification; default value is 0xFE and is distinct from the device I²C address. | Provides the 8-bit device identity for digital-interface access verification. Its value is distinct from the device I²C slave address. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 0.678056 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | 0xFE | 0xFE |
| `default_value_description` | 0.0334 | 1.000000 | Eight-bit device ID; different from the I²C address. | Eight-bit device ID; different from the I²C address. |

\(Q(L_{35})=(0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.678056 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.701735/1.0001=\mathbf{0.701665}\).

### Extracted logical register 36: `XA_OFFS`

v1 location: `registers[35]`; datasheet association: PDF p.43, §9.29, Tables 72-77.

Associated physical locations: [{"hex":"0x77","decimal":"119","bank":"","page":"","description":"Upper eight bits of the 15-bit X accelerometer offset cancellation value."},{"hex":"0x78","decimal":"120","bank":"","page":"","description":"Lower seven bits and factory-calibrated reserved bit of the X accelerometer offset register."}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `XA_OFFSET_H` at 0x77 (119)

Location: `v1 registers[35].field_parts[0]`; datasheet source: PDF p.43, Table 72.

**Datasheet bit field 1: `XA_OFFS[14:7]`, bits [7:0]**

Location: `v1 registers[35].field_parts[0].bit_field[0]`; datasheet source: PDF p.43, Table 72. Judgment: C<1 fields: field_description=0.500000, type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XA_OFFS[14:7] | XA_OFFS[14:7] |
| `field_description` | 0.0586 | 0.5 | Bits 14 to 7 of the 15-bit X accelerometer offset cancellation (2's complement); ±16g and 0.98-mg steps. | Bits 14 to 7 of the signed 15-bit X accelerometer offset cancellation value. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Field-part aggregation**

bit_field correctness = mean(0.912391) = **0.912391**.

Direct judgment: 直接字段不完全正确：bit_field=0.912391；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | XA_OFFSET_H | XA_OFFSET_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x77","decimal":"119","bank":"","page":"","description":"Upper byte of XA_OFFS[14:7]."} | {"hex":"0x77","decimal":"119","bank":"","page":"","description":"Upper eight bits of the 15-bit X accelerometer offset cancellation value."} |
| `description` | 0.0693 | 1.000000 | High part containing XA_OFFS[14:7]. | High part containing offset bits 14:7. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.912391 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.912391)/1.0000=0.972587/1.0000=\mathbf{0.972587}\).

##### Field part 2: `XA_OFFSET_L` at 0x78 (120)

Location: `v1 registers[35].field_parts[1]`; datasheet source: PDF p.43, Table 73.

**Datasheet bit field 1: `XA_OFFS[6:0]`, bits [7:1]**

Location: `v1 registers[35].field_parts[1].bit_field[0]`; datasheet source: PDF p.43, Table 73. Judgment: C<1 fields: field_description=0.500000, type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | XA_OFFS[6:0] | XA_OFFS[6:0] |
| `field_description` | 0.0586 | 0.5 | Bits 6 to 0 of the 15-bit X accelerometer offset cancellation (2's complement); ±16g and 0.98-mg steps. | Bits 6 to 0 of the signed 15-bit X accelerometer offset cancellation value. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Datasheet bit field 2: `-`, bits [0]**

Location: `v1 registers[35].field_parts[1].bit_field[1]`; datasheet source: PDF p.43, Table 73. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved; set during factory calibration and kept unchanged. | Reserved; set during factory calibration and must be kept unchanged. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.912391, 0.941694) = **0.927043**.

Direct judgment: 直接字段不完全正确：bit_field=0.927043；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | XA_OFFSET_L | XA_OFFSET_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x78","decimal":"120","bank":"","page":"","description":"Lower seven offset bits and factory-calibrated reserved bit of XA_OFFS."} | {"hex":"0x78","decimal":"120","bank":"","page":"","description":"Lower seven bits and factory-calibrated reserved bit of the X accelerometer offset register."} |
| `description` | 0.0693 | 1.000000 | Low part containing XA_OFFS[6:0] and the factory-calibrated reserved bit. | Low part containing offset bits 6:0 and a factory-calibrated reserved bit. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.927043 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.927043)/1.0000=0.977172/1.0000=\mathbf{0.977172}\).

#### Logical-register aggregation

field_parts correctness = mean(0.972587, 0.977172) = **0.974879**.

Direct judgment: 直接字段不完全正确：width_bits=0.000000, field_parts=0.974879；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | XA_OFFS | XA_OFFS |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x77","decimal":"119","bank":"","page":"","description":"Upper byte of XA_OFFS[14:7]."},{"hex":"0x78","decimal":"120","bank":"","page":"","description":"Lower seven offset bits and factory-calibrated reserved bit of XA_OFFS."}] | [{"hex":"0x77","decimal":"119","bank":"","page":"","description":"Upper eight bits of the 15-bit X accelerometer offset cancellation value."},{"hex":"0x78","decimal":"120","bank":"","page":"","description":"Lower seven bits and factory-calibrated reserved bit of the X accelerometer offset register."}] |
| `register_description` | 0.0564 | 1.000000 | Signed 15-bit two's-complement X-axis accelerometer offset cancellation with 0.98 mg steps and ±16g range in all full-scale modes; the low register bit 0 is factory-calibrated and must remain unchanged. | Signed 15-bit two's-complement X-axis accelerometer offset cancellation with 0.98 mg steps and ±16g offset cancellation in all full-scale modes. The low register's reserved bit must retain its factory-calibrated value. |
| `width_bits` | 0.0590 | 0.000000 | 15 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.974879 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | Pre-programmed offset cancellation value | Pre-programmed offset cancellation value |
| `default_value_description` | 0.0334 | 1.000000 | Physical registers 119 and 120 contain factory-programmed offset cancellation data. | Physical registers 119 and 120 contain factory-programmed offset cancellation data. |

\(Q(L_{36})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×0.000000 + 0.0590×1.000000 + 0.2987×0.974879 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.933596/1.0001=\mathbf{0.933503}\).

### Extracted logical register 37: `YA_OFFS`

v1 location: `registers[36]`; datasheet association: IAM-20680HV datasheet.

Associated physical locations: [{"hex":"0x7A","decimal":"122","bank":"","page":"","description":"Upper eight bits of the 15-bit Y accelerometer offset cancellation value."},{"hex":"0x7B","decimal":"123","bank":"","page":"","description":"Lower seven bits and factory-calibrated reserved bit of the Y accelerometer offset register."}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `YA_OFFSET_H` at 0x7A (122)

Location: `v1 registers[36].field_parts[0]`; datasheet source: PDF p.43, Table 74.

**Datasheet bit field 1: `YA_OFFS[14:7]`, bits [7:0]**

Location: `v1 registers[36].field_parts[0].bit_field[0]`; datasheet source: PDF p.43, Table 74. Judgment: C<1 fields: field_description=0.500000, type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YA_OFFS[14:7] | YA_OFFS[14:7] |
| `field_description` | 0.0586 | 0.5 | Bits 14 to 7 of the 15-bit Y accelerometer offset cancellation (2's complement); ±16g and 0.98-mg steps. | Bits 14 to 7 of the signed 15-bit Y accelerometer offset cancellation value. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Field-part aggregation**

bit_field correctness = mean(0.912391) = **0.912391**.

Direct judgment: 直接字段不完全正确：bit_field=0.912391；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | YA_OFFSET_H | YA_OFFSET_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x7A","decimal":"122","bank":"","page":"","description":"Upper byte of YA_OFFS[14:7]."} | {"hex":"0x7A","decimal":"122","bank":"","page":"","description":"Upper eight bits of the 15-bit Y accelerometer offset cancellation value."} |
| `description` | 0.0693 | 1.000000 | High part containing YA_OFFS[14:7]. | High part containing offset bits 14:7. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.912391 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.912391)/1.0000=0.972587/1.0000=\mathbf{0.972587}\).

##### Field part 2: `YA_OFFSET_L` at 0x7B (123)

Location: `v1 registers[36].field_parts[1]`; datasheet source: PDF p.43, Table 75.

**Datasheet bit field 1: `YA_OFFS[6:0]`, bits [7:1]**

Location: `v1 registers[36].field_parts[1].bit_field[0]`; datasheet source: PDF p.43, Table 75. Judgment: C<1 fields: field_description=0.500000, type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | YA_OFFS[6:0] | YA_OFFS[6:0] |
| `field_description` | 0.0586 | 0.5 | Bits 6 to 0 of the 15-bit Y accelerometer offset cancellation (2's complement); ±16g and 0.98-mg steps. | Bits 6 to 0 of the signed 15-bit Y accelerometer offset cancellation value. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Datasheet bit field 2: `-`, bits [0]**

Location: `v1 registers[36].field_parts[1].bit_field[1]`; datasheet source: PDF p.43, Table 75. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved; set during factory calibration and kept unchanged. | Reserved; set during factory calibration and must be kept unchanged. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.912391, 0.941694) = **0.927043**.

Direct judgment: 直接字段不完全正确：bit_field=0.927043；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | YA_OFFSET_L | YA_OFFSET_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x7B","decimal":"123","bank":"","page":"","description":"Lower seven offset bits and factory-calibrated reserved bit of YA_OFFS."} | {"hex":"0x7B","decimal":"123","bank":"","page":"","description":"Lower seven bits and factory-calibrated reserved bit of the Y accelerometer offset register."} |
| `description` | 0.0693 | 1.000000 | Low part containing YA_OFFS[6:0] and the factory-calibrated reserved bit. | Low part containing offset bits 6:0 and a factory-calibrated reserved bit. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.927043 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.927043)/1.0000=0.977172/1.0000=\mathbf{0.977172}\).

#### Logical-register aggregation

field_parts correctness = mean(0.972587, 0.977172) = **0.974879**.

Direct judgment: 直接字段不完全正确：width_bits=0.000000, field_parts=0.974879；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | YA_OFFS | YA_OFFS |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x7A","decimal":"122","bank":"","page":"","description":"Upper byte of YA_OFFS[14:7]."},{"hex":"0x7B","decimal":"123","bank":"","page":"","description":"Lower seven offset bits and factory-calibrated reserved bit of YA_OFFS."}] | [{"hex":"0x7A","decimal":"122","bank":"","page":"","description":"Upper eight bits of the 15-bit Y accelerometer offset cancellation value."},{"hex":"0x7B","decimal":"123","bank":"","page":"","description":"Lower seven bits and factory-calibrated reserved bit of the Y accelerometer offset register."}] |
| `register_description` | 0.0564 | 1.000000 | Signed 15-bit two's-complement Y-axis accelerometer offset cancellation with 0.98 mg steps and ±16g range in all full-scale modes; the low register bit 0 is factory-calibrated and must remain unchanged. | Signed 15-bit two's-complement Y-axis accelerometer offset cancellation with 0.98 mg steps and ±16g offset cancellation in all full-scale modes. The low register's reserved bit must retain its factory-calibrated value. |
| `width_bits` | 0.0590 | 0.000000 | 15 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.974879 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | Pre-programmed offset cancellation value | Pre-programmed offset cancellation value |
| `default_value_description` | 0.0334 | 1.000000 | Physical registers 122 and 123 contain factory-programmed offset cancellation data. | Physical registers 122 and 123 contain factory-programmed offset cancellation data. |

\(Q(L_{37})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×0.000000 + 0.0590×1.000000 + 0.2987×0.974879 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.933596/1.0001=\mathbf{0.933503}\).

### Extracted logical register 38: `ZA_OFFS`

v1 location: `registers[37]`; datasheet association: IAM-20680HV datasheet.

Associated physical locations: [{"hex":"0x7D","decimal":"125","bank":"","page":"","description":"Upper eight bits of the 15-bit Z accelerometer offset cancellation value."},{"hex":"0x7E","decimal":"126","bank":"","page":"","description":"Lower seven bits and factory-calibrated reserved bit of the Z accelerometer offset register."}].

#### Bottom layer: bit fields, then field parts

##### Field part 1: `ZA_OFFSET_H` at 0x7D (125)

Location: `v1 registers[37].field_parts[0]`; datasheet source: PDF p.43, Table 76.

**Datasheet bit field 1: `ZA_OFFS[14:7]`, bits [7:0]**

Location: `v1 registers[37].field_parts[0].bit_field[0]`; datasheet source: PDF p.43, Table 76. Judgment: C<1 fields: field_description=0.500000, type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZA_OFFS[14:7] | ZA_OFFS[14:7] |
| `field_description` | 0.0586 | 0.5 | Bits 14 to 7 of the 15-bit Z accelerometer offset cancellation (2's complement); ±16g and 0.98-mg steps. | Bits 14 to 7 of the signed 15-bit Z accelerometer offset cancellation value. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Field-part aggregation**

bit_field correctness = mean(0.912391) = **0.912391**.

Direct judgment: 直接字段不完全正确：bit_field=0.912391；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ZA_OFFSET_H | ZA_OFFSET_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x7D","decimal":"125","bank":"","page":"","description":"Upper byte of ZA_OFFS[14:7]."} | {"hex":"0x7D","decimal":"125","bank":"","page":"","description":"Upper eight bits of the 15-bit Z accelerometer offset cancellation value."} |
| `description` | 0.0693 | 1.000000 | High part containing ZA_OFFS[14:7]. | High part containing offset bits 14:7. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.912391 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.912391)/1.0000=0.972587/1.0000=\mathbf{0.972587}\).

##### Field part 2: `ZA_OFFSET_L` at 0x7E (126)

Location: `v1 registers[37].field_parts[1]`; datasheet source: PDF p.43, Table 77.

**Datasheet bit field 1: `ZA_OFFS[6:0]`, bits [7:1]**

Location: `v1 registers[37].field_parts[1].bit_field[0]`; datasheet source: PDF p.43, Table 77. Judgment: C<1 fields: field_description=0.500000, type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ZA_OFFS[6:0] | ZA_OFFS[6:0] |
| `field_description` | 0.0586 | 0.5 | Bits 6 to 0 of the 15-bit Z accelerometer offset cancellation (2's complement); ±16g and 0.98-mg steps. | Bits 6 to 0 of the signed 15-bit Z accelerometer offset cancellation value. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 7 | 7 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×0.500000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.912300/0.9999=\mathbf{0.912391}\).

**Datasheet bit field 2: `-`, bits [0]**

Location: `v1 registers[37].field_parts[1].bit_field[1]`; datasheet source: PDF p.43, Table 77. Judgment: C<1 fields: type_write_read=0.000000。

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | - | - |
| `field_description` | 0.0586 | 1.0 | Reserved; set during factory calibration and kept unchanged. | Reserved; set during factory calibration and must be kept unchanged. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | RW | "" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×0.000000)/0.9999=0.941600/0.9999=\mathbf{0.941694}\).

**Field-part aggregation**

bit_field correctness = mean(0.912391, 0.941694) = **0.927043**.

Direct judgment: 直接字段不完全正确：bit_field=0.927043；bit_field 由下方位字段分数自底向上聚合。

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ZA_OFFSET_L | ZA_OFFSET_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x7E","decimal":"126","bank":"","page":"","description":"Lower seven offset bits and factory-calibrated reserved bit of ZA_OFFS."} | {"hex":"0x7E","decimal":"126","bank":"","page":"","description":"Lower seven bits and factory-calibrated reserved bit of the Z accelerometer offset register."} |
| `description` | 0.0693 | 1.000000 | Low part containing ZA_OFFS[6:0] and the factory-calibrated reserved bit. | Low part containing offset bits 6:0 and a factory-calibrated reserved bit. |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | RW | RW |
| `bit_field` | 0.3129 | 0.927043 | datasheet bit-field set | matched v1 bit-field set |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.927043)/1.0000=0.977172/1.0000=\mathbf{0.977172}\).

#### Logical-register aggregation

field_parts correctness = mean(0.972587, 0.977172) = **0.974879**.

Direct judgment: 直接字段不完全正确：width_bits=0.000000, field_parts=0.974879；field_parts 使用下方各物理 field part 的平均分。

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ZA_OFFS | ZA_OFFS |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x7D","decimal":"125","bank":"","page":"","description":"Upper byte of ZA_OFFS[14:7]."},{"hex":"0x7E","decimal":"126","bank":"","page":"","description":"Lower seven offset bits and factory-calibrated reserved bit of ZA_OFFS."}] | [{"hex":"0x7D","decimal":"125","bank":"","page":"","description":"Upper eight bits of the 15-bit Z accelerometer offset cancellation value."},{"hex":"0x7E","decimal":"126","bank":"","page":"","description":"Lower seven bits and factory-calibrated reserved bit of the Z accelerometer offset register."}] |
| `register_description` | 0.0564 | 1.000000 | Signed 15-bit two's-complement Z-axis accelerometer offset cancellation with 0.98 mg steps and ±16g range in all full-scale modes; the low register bit 0 is factory-calibrated and must remain unchanged. | Signed 15-bit two's-complement Z-axis accelerometer offset cancellation with 0.98 mg steps and ±16g offset cancellation in all full-scale modes. The low register's reserved bit must retain its factory-calibrated value. |
| `width_bits` | 0.0590 | 0.000000 | 15 | 16 |
| `type_write_read` | 0.0590 | 1.000000 | RW | RW |
| `field_parts` | 0.2987 | 0.974879 | corresponding datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.000000 | Pre-programmed offset cancellation value | Pre-programmed offset cancellation value |
| `default_value_description` | 0.0334 | 1.000000 | Physical registers 125 and 126 contain factory-programmed offset cancellation data. | Physical registers 125 and 126 contain factory-programmed offset cancellation data. |

\(Q(L_{38})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×0.000000 + 0.0590×1.000000 + 0.2987×0.974879 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.933596/1.0001=\mathbf{0.933503}\).

## 5. Ground-truth physical-register scores

For every datasheet physical register, \(q_R=\frac{1}{|L_R|}\sum_{L\in L_R}Q(L)\). Each physical location below is matched by numeric address; there are no bank/page variants. The repeated score for a two-byte logical register is intentional: one `Q(L)` is associated with each of its physical field parts, as required by the bottom-up rule.

| Datasheet physical address | Associated extracted logical registers and Q(L) | q_R |
|---|---|---:|
| 0x00 (0) | v1 registers[0] `SELF_TEST_X_GYRO`=0.701665 | 0.701665 |
| 0x01 (1) | v1 registers[1] `SELF_TEST_Y_GYRO`=0.701665 | 0.701665 |
| 0x02 (2) | v1 registers[2] `SELF_TEST_Z_GYRO`=0.701665 | 0.701665 |
| 0x0D (13) | v1 registers[3] `SELF_TEST_X_ACCEL`=0.701665 | 0.701665 |
| 0x0E (14) | v1 registers[4] `SELF_TEST_Y_ACCEL`=0.701665 | 0.701665 |
| 0x0F (15) | v1 registers[5] `SELF_TEST_Z_ACCEL`=0.701665 | 0.701665 |
| 0x13 (19) | v1 registers[6] `X_OFFS_USR`=0.991813 | 0.991813 |
| 0x14 (20) | v1 registers[6] `X_OFFS_USR`=0.991813 | 0.991813 |
| 0x15 (21) | v1 registers[7] `Y_OFFS_USR`=0.991813 | 0.991813 |
| 0x16 (22) | v1 registers[7] `Y_OFFS_USR`=0.991813 | 0.991813 |
| 0x17 (23) | v1 registers[8] `Z_OFFS_USR`=0.991813 | 0.991813 |
| 0x18 (24) | v1 registers[8] `Z_OFFS_USR`=0.991813 | 0.991813 |
| 0x19 (25) | v1 registers[9] `SMPLRT_DIV`=0.698927 | 0.698927 |
| 0x1A (26) | v1 registers[10] `CONFIG`=0.701665 | 0.701665 |
| 0x1B (27) | v1 registers[11] `GYRO_CONFIG`=0.701665 | 0.701665 |
| 0x1C (28) | v1 registers[12] `ACCEL_CONFIG`=0.701665 | 0.701665 |
| 0x1D (29) | v1 registers[13] `ACCEL_CONFIG2`=0.701665 | 0.701665 |
| 0x1E (30) | v1 registers[14] `LP_MODE_CFG`=0.701665 | 0.701665 |
| 0x20 (32) | v1 registers[15] `ACCEL_WOM_X_THR`=0.701665 | 0.701665 |
| 0x21 (33) | v1 registers[16] `ACCEL_WOM_Y_THR`=0.701665 | 0.701665 |
| 0x22 (34) | v1 registers[17] `ACCEL_WOM_Z_THR`=0.701665 | 0.701665 |
| 0x36 (54) | v1 registers[18] `FSYNC_INT`=0.683831 | 0.683831 |
| 0x37 (55) | v1 registers[19] `INT_PIN_CFG`=0.701665 | 0.701665 |
| 0x38 (56) | v1 registers[20] `INT_ENABLE`=0.701665 | 0.701665 |
| 0x3A (58) | v1 registers[21] `INT_STATUS`=0.683831 | 0.683831 |
| 0x3B (59) | v1 registers[22] `ACCEL_XOUT`=0.994551 | 0.994551 |
| 0x3C (60) | v1 registers[22] `ACCEL_XOUT`=0.994551 | 0.994551 |
| 0x3D (61) | v1 registers[23] `ACCEL_YOUT`=0.994551 | 0.994551 |
| 0x3E (62) | v1 registers[23] `ACCEL_YOUT`=0.994551 | 0.994551 |
| 0x3F (63) | v1 registers[24] `ACCEL_ZOUT`=0.994551 | 0.994551 |
| 0x40 (64) | v1 registers[24] `ACCEL_ZOUT`=0.994551 | 0.994551 |
| 0x41 (65) | v1 registers[25] `TEMP_OUT`=0.994551 | 0.994551 |
| 0x42 (66) | v1 registers[25] `TEMP_OUT`=0.994551 | 0.994551 |
| 0x43 (67) | v1 registers[26] `GYRO_XOUT`=0.994551 | 0.994551 |
| 0x44 (68) | v1 registers[26] `GYRO_XOUT`=0.994551 | 0.994551 |
| 0x45 (69) | v1 registers[27] `GYRO_YOUT`=0.994551 | 0.994551 |
| 0x46 (70) | v1 registers[27] `GYRO_YOUT`=0.994551 | 0.994551 |
| 0x47 (71) | v1 registers[28] `GYRO_ZOUT`=0.994551 | 0.994551 |
| 0x48 (72) | v1 registers[28] `GYRO_ZOUT`=0.994551 | 0.994551 |
| 0x68 (104) | v1 registers[29] `SIGNAL_PATH_RESET`=0.701665 | 0.701665 |
| 0x69 (105) | v1 registers[30] `ACCEL_INTEL_CTRL`=0.701665 | 0.701665 |
| 0x6A (106) | v1 registers[31] `USER_CTRL`=0.701665 | 0.701665 |
| 0x6B (107) | v1 registers[32] `PWR_MGMT_1`=0.701665 | 0.701665 |
| 0x6C (108) | v1 registers[33] `PWR_MGMT_2`=0.701665 | 0.701665 |
| 0x75 (117) | v1 registers[34] `WHO_AM_I`=0.701665 | 0.701665 |
| 0x77 (119) | v1 registers[35] `XA_OFFS`=0.933503 | 0.933503 |
| 0x78 (120) | v1 registers[35] `XA_OFFS`=0.933503 | 0.933503 |
| 0x7A (122) | v1 registers[36] `YA_OFFS`=0.933503 | 0.933503 |
| 0x7B (123) | v1 registers[36] `YA_OFFS`=0.933503 | 0.933503 |
| 0x7D (125) | v1 registers[37] `ZA_OFFS`=0.933503 | 0.933503 |
| 0x7E (126) | v1 registers[37] `ZA_OFFS`=0.933503 | 0.933503 |

\(\sum_R q_R=\mathbf{42.978833238}\).

`n=51` unique datasheet physical registers; `m=51` matched extracted physical registers; `x=0` extra extracted physical registers.

\(\frac{m}{m+x}=\frac{51}{51+0}=1.000000\).

\(S_{final}=\left(\frac{10}{51}\times 42.978833238\right)\times 1.000000=\boxed{\mathbf{8.427222203/10}}\).

## 6. Detailed deduction inventory

The following inventory lists every scored field with `C<1`; the per-register sections above show the complete truth/v1 contents and the arithmetic for all fields, including the fields that receive full credit.
1. `registers[0].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x00","decimal":"0","bank":"","page":"","description":"SELF_TEST_X_GYRO register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}]; v1=[{"hex":"0x00","decimal":"0","bank":"","page":"","description":""}].
2. `registers[0].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
3. `registers[0].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x00","decimal":"0","bank":"","page":"","description":"SELF_TEST_X_GYRO register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}; v1={"hex":"0x00","decimal":"0","bank":"","page":"","description":""}.
4. `registers[0].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Manufacturing self-test output; used to check subsequent end-user self-test outputs.; v1="".
5. `registers[0].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
6. `registers[0].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
7. `registers[1].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x01","decimal":"1","bank":"","page":"","description":"SELF_TEST_Y_GYRO register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}]; v1=[{"hex":"0x01","decimal":"1","bank":"","page":"","description":""}].
8. `registers[1].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
9. `registers[1].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x01","decimal":"1","bank":"","page":"","description":"SELF_TEST_Y_GYRO register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}; v1={"hex":"0x01","decimal":"1","bank":"","page":"","description":""}.
10. `registers[1].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Manufacturing self-test output; used to check subsequent end-user self-test outputs.; v1="".
11. `registers[1].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
12. `registers[1].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
13. `registers[2].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x02","decimal":"2","bank":"","page":"","description":"SELF_TEST_Z_GYRO register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}]; v1=[{"hex":"0x02","decimal":"2","bank":"","page":"","description":""}].
14. `registers[2].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
15. `registers[2].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x02","decimal":"2","bank":"","page":"","description":"SELF_TEST_Z_GYRO register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}; v1={"hex":"0x02","decimal":"2","bank":"","page":"","description":""}.
16. `registers[2].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Manufacturing self-test output; used to check subsequent end-user self-test outputs.; v1="".
17. `registers[2].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
18. `registers[2].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
19. `registers[3].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"SELF_TEST_X_ACCEL register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}]; v1=[{"hex":"0x0D","decimal":"13","bank":"","page":"","description":""}].
20. `registers[3].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
21. `registers[3].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x0D","decimal":"13","bank":"","page":"","description":"SELF_TEST_X_ACCEL register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}; v1={"hex":"0x0D","decimal":"13","bank":"","page":"","description":""}.
22. `registers[3].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Manufacturing self-test output; used to check subsequent end-user self-test outputs.; v1="".
23. `registers[3].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
24. `registers[3].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
25. `registers[4].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x0E","decimal":"14","bank":"","page":"","description":"SELF_TEST_Y_ACCEL register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}]; v1=[{"hex":"0x0E","decimal":"14","bank":"","page":"","description":""}].
26. `registers[4].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
27. `registers[4].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x0E","decimal":"14","bank":"","page":"","description":"SELF_TEST_Y_ACCEL register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}; v1={"hex":"0x0E","decimal":"14","bank":"","page":"","description":""}.
28. `registers[4].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Manufacturing self-test output; used to check subsequent end-user self-test outputs.; v1="".
29. `registers[4].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
30. `registers[4].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
31. `registers[5].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"SELF_TEST_Z_ACCEL register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}]; v1=[{"hex":"0x0F","decimal":"15","bank":"","page":"","description":""}].
32. `registers[5].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
33. `registers[5].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x0F","decimal":"15","bank":"","page":"","description":"SELF_TEST_Z_ACCEL register; Manufacturing self-test output; used to check subsequent end-user self-test outputs."}; v1={"hex":"0x0F","decimal":"15","bank":"","page":"","description":""}.
34. `registers[5].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Manufacturing self-test output; used to check subsequent end-user self-test outputs.; v1="".
35. `registers[5].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
36. `registers[5].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
37. `registers[6].field_parts`: C=0.972587; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
38. `registers[6].field_parts[0].bit_field`: C=0.912391; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
39. `registers[6].field_parts[0].bit_field[0].field_description`: C=0.500000; description is incomplete but the main function is present. Datasheet=Bits 15 to 8 of the 16-bit offset of X gyroscope (2's complement). This register removes DC bias and adds the offset before the sensor register.; v1=Bits 15 to 8 of the signed 16-bit X gyroscope offset..
40. `registers[6].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
41. `registers[6].field_parts[1].bit_field`: C=0.912391; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
42. `registers[6].field_parts[1].bit_field[0].field_description`: C=0.500000; description is incomplete but the main function is present. Datasheet=Bits 7 to 0 of the 16-bit offset of X gyroscope (2's complement). This register removes DC bias and adds the offset before the sensor register.; v1=Bits 7 to 0 of the signed 16-bit X gyroscope offset..
43. `registers[6].field_parts[1].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
44. `registers[7].field_parts`: C=0.972587; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
45. `registers[7].field_parts[0].bit_field`: C=0.912391; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
46. `registers[7].field_parts[0].bit_field[0].field_description`: C=0.500000; description is incomplete but the main function is present. Datasheet=Bits 15 to 8 of the 16-bit offset of Y gyroscope (2's complement). This register removes DC bias and adds the offset before the sensor register.; v1=Bits 15 to 8 of the signed 16-bit Y gyroscope offset..
47. `registers[7].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
48. `registers[7].field_parts[1].bit_field`: C=0.912391; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
49. `registers[7].field_parts[1].bit_field[0].field_description`: C=0.500000; description is incomplete but the main function is present. Datasheet=Bits 7 to 0 of the 16-bit offset of Y gyroscope (2's complement). This register removes DC bias and adds the offset before the sensor register.; v1=Bits 7 to 0 of the signed 16-bit Y gyroscope offset..
50. `registers[7].field_parts[1].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
51. `registers[8].field_parts`: C=0.972587; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
52. `registers[8].field_parts[0].bit_field`: C=0.912391; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
53. `registers[8].field_parts[0].bit_field[0].field_description`: C=0.500000; description is incomplete but the main function is present. Datasheet=Bits 15 to 8 of the 16-bit offset of Z gyroscope (2's complement). This register removes DC bias and adds the offset before the sensor register.; v1=Bits 15 to 8 of the signed 16-bit Z gyroscope offset..
54. `registers[8].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
55. `registers[8].field_parts[1].bit_field`: C=0.912391; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
56. `registers[8].field_parts[1].bit_field[0].field_description`: C=0.500000; description is incomplete but the main function is present. Datasheet=Bits 7 to 0 of the 16-bit offset of Z gyroscope (2's complement). This register removes DC bias and adds the offset before the sensor register.; v1=Bits 7 to 0 of the signed 16-bit Z gyroscope offset..
57. `registers[8].field_parts[1].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
58. `registers[9].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x19","decimal":"25","bank":"","page":"","description":"SMPLRT_DIV register; Divides the internal sample rate to generate sensor data output rate: SAMPLE_RATE = 1 kHz/(1+SMPLRT_DIV). Effective when FCHOICE_B[1:0]=00 and 0 < DLPF_CFG < 7."}]; v1=[{"hex":"0x19","decimal":"25","bank":"","page":"","description":""}].
59. `registers[9].field_parts`: C=0.668887; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
60. `registers[9].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x19","decimal":"25","bank":"","page":"","description":"SMPLRT_DIV register; Divides the internal sample rate to generate sensor data output rate: SAMPLE_RATE = 1 kHz/(1+SMPLRT_DIV). Effective when FCHOICE_B[1:0]=00 and 0 < DLPF_CFG < 7."}; v1={"hex":"0x19","decimal":"25","bank":"","page":"","description":""}.
61. `registers[9].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Divides the internal sample rate to generate sensor data output rate: SAMPLE_RATE = 1 kHz/(1+SMPLRT_DIV). Effective when FCHOICE_B[1:0]=00 and 0 < DLPF_CFG < 7.; v1="".
62. `registers[9].field_parts[0].bit_field`: C=0.912391; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
63. `registers[9].field_parts[0].bit_field[0].field_description`: C=0.500000; description is incomplete but the main function is present. Datasheet=Divides the internal sample rate to generate the sensor data output rate; see the register CONFIG conditions and formula.; v1=Eight-bit internal sample-rate divider..
64. `registers[9].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
65. `registers[10].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"CONFIG register; Configures FSYNC sampling and the gyroscope/temperature digital low-pass filter; DLPF_CFG is used when FCHOICE_B[1:0]=00."}]; v1=[{"hex":"0x1A","decimal":"26","bank":"","page":"","description":""}].
66. `registers[10].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
67. `registers[10].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x1A","decimal":"26","bank":"","page":"","description":"CONFIG register; Configures FSYNC sampling and the gyroscope/temperature digital low-pass filter; DLPF_CFG is used when FCHOICE_B[1:0]=00."}; v1={"hex":"0x1A","decimal":"26","bank":"","page":"","description":""}.
68. `registers[10].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Configures FSYNC sampling and the gyroscope/temperature digital low-pass filter; DLPF_CFG is used when FCHOICE_B[1:0]=00.; v1="".
69. `registers[10].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
70. `registers[10].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
71. `registers[10].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
72. `registers[10].field_parts[0].bit_field[2].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
73. `registers[10].field_parts[0].bit_field[3].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
74. `registers[11].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"GYRO_CONFIG register; Enables per-axis gyroscope self-test, selects the gyroscope full-scale range, and controls DLPF bypass through FCHOICE_B."}]; v1=[{"hex":"0x1B","decimal":"27","bank":"","page":"","description":""}].
75. `registers[11].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
76. `registers[11].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x1B","decimal":"27","bank":"","page":"","description":"GYRO_CONFIG register; Enables per-axis gyroscope self-test, selects the gyroscope full-scale range, and controls DLPF bypass through FCHOICE_B."}; v1={"hex":"0x1B","decimal":"27","bank":"","page":"","description":""}.
77. `registers[11].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Enables per-axis gyroscope self-test, selects the gyroscope full-scale range, and controls DLPF bypass through FCHOICE_B.; v1="".
78. `registers[11].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
79. `registers[11].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
80. `registers[11].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
81. `registers[11].field_parts[0].bit_field[2].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
82. `registers[11].field_parts[0].bit_field[3].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
83. `registers[11].field_parts[0].bit_field[4].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
84. `registers[11].field_parts[0].bit_field[5].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
85. `registers[12].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x1C","decimal":"28","bank":"","page":"","description":"ACCEL_CONFIG register; Enables per-axis accelerometer self-test and selects the accelerometer full-scale range."}]; v1=[{"hex":"0x1C","decimal":"28","bank":"","page":"","description":""}].
86. `registers[12].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
87. `registers[12].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x1C","decimal":"28","bank":"","page":"","description":"ACCEL_CONFIG register; Enables per-axis accelerometer self-test and selects the accelerometer full-scale range."}; v1={"hex":"0x1C","decimal":"28","bank":"","page":"","description":""}.
88. `registers[12].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Enables per-axis accelerometer self-test and selects the accelerometer full-scale range.; v1="".
89. `registers[12].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
90. `registers[12].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
91. `registers[12].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
92. `registers[12].field_parts[0].bit_field[2].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
93. `registers[12].field_parts[0].bit_field[3].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
94. `registers[12].field_parts[0].bit_field[4].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
95. `registers[13].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x1D","decimal":"29","bank":"","page":"","description":"ACCEL_CONFIG2 register; Configures accelerometer WoM averaging, DLPF bypass, and accelerometer low-pass filter settings."}]; v1=[{"hex":"0x1D","decimal":"29","bank":"","page":"","description":""}].
96. `registers[13].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
97. `registers[13].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x1D","decimal":"29","bank":"","page":"","description":"ACCEL_CONFIG2 register; Configures accelerometer WoM averaging, DLPF bypass, and accelerometer low-pass filter settings."}; v1={"hex":"0x1D","decimal":"29","bank":"","page":"","description":""}.
98. `registers[13].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Configures accelerometer WoM averaging, DLPF bypass, and accelerometer low-pass filter settings.; v1="".
99. `registers[13].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
100. `registers[13].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
101. `registers[13].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
102. `registers[13].field_parts[0].bit_field[2].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
103. `registers[13].field_parts[0].bit_field[3].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
104. `registers[14].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x1E","decimal":"30","bank":"","page":"","description":"LP_MODE_CFG register; Configures duty-cycled gyroscope or 6-axis operation, gyroscope averaging, and accelerometer WoM output data rate."}]; v1=[{"hex":"0x1E","decimal":"30","bank":"","page":"","description":""}].
105. `registers[14].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
106. `registers[14].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x1E","decimal":"30","bank":"","page":"","description":"LP_MODE_CFG register; Configures duty-cycled gyroscope or 6-axis operation, gyroscope averaging, and accelerometer WoM output data rate."}; v1={"hex":"0x1E","decimal":"30","bank":"","page":"","description":""}.
107. `registers[14].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Configures duty-cycled gyroscope or 6-axis operation, gyroscope averaging, and accelerometer WoM output data rate.; v1="".
108. `registers[14].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
109. `registers[14].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
110. `registers[14].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
111. `registers[14].field_parts[0].bit_field[2].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
112. `registers[15].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x20","decimal":"32","bank":"","page":"","description":"ACCEL_WOM_X_THR register; Holds the X-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale."}]; v1=[{"hex":"0x20","decimal":"32","bank":"","page":"","description":""}].
113. `registers[15].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
114. `registers[15].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x20","decimal":"32","bank":"","page":"","description":"ACCEL_WOM_X_THR register; Holds the X-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale."}; v1={"hex":"0x20","decimal":"32","bank":"","page":"","description":""}.
115. `registers[15].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Holds the X-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale.; v1="".
116. `registers[15].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
117. `registers[15].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
118. `registers[16].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x21","decimal":"33","bank":"","page":"","description":"ACCEL_WOM_Y_THR register; Holds the Y-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale."}]; v1=[{"hex":"0x21","decimal":"33","bank":"","page":"","description":""}].
119. `registers[16].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
120. `registers[16].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x21","decimal":"33","bank":"","page":"","description":"ACCEL_WOM_Y_THR register; Holds the Y-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale."}; v1={"hex":"0x21","decimal":"33","bank":"","page":"","description":""}.
121. `registers[16].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Holds the Y-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale.; v1="".
122. `registers[16].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
123. `registers[16].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
124. `registers[17].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x22","decimal":"34","bank":"","page":"","description":"ACCEL_WOM_Z_THR register; Holds the Z-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale."}]; v1=[{"hex":"0x22","decimal":"34","bank":"","page":"","description":""}].
125. `registers[17].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
126. `registers[17].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x22","decimal":"34","bank":"","page":"","description":"ACCEL_WOM_Z_THR register; Holds the Z-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale."}; v1={"hex":"0x22","decimal":"34","bank":"","page":"","description":""}.
127. `registers[17].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Holds the Z-axis accelerometer Wake-on-Motion interrupt threshold; resolution is 4 mg/LSB regardless of selected full scale.; v1="".
128. `registers[17].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
129. `registers[17].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
130. `registers[18].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x36","decimal":"54","bank":"","page":"","description":"FSYNC_INT register; FSYNC interrupt status; the bit sets when an FSYNC interrupt is generated and clears after the register is read."}]; v1=[{"hex":"0x36","decimal":"54","bank":"","page":"","description":""}].
131. `registers[18].type_write_read`: C=0.500000; read access is present but read-to-clear behavior is omitted. Datasheet=R/C; v1=R.
132. `registers[18].field_parts`: C=0.717106; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
133. `registers[18].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x36","decimal":"54","bank":"","page":"","description":"FSYNC_INT register; FSYNC interrupt status; the bit sets when an FSYNC interrupt is generated and clears after the register is read."}; v1={"hex":"0x36","decimal":"54","bank":"","page":"","description":""}.
134. `registers[18].field_parts[0].type_write_read`: C=0.500000; v1 records R but datasheet specifies READ to CLEAR. Datasheet=R/C; v1=R.
135. `registers[18].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
136. `registers[18].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R/C; v1="".
137. `registers[18].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R/C; v1="".
138. `registers[19].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x37","decimal":"55","bank":"","page":"","description":"INT_PIN_CFG register; Configures INT/INT2 polarity, output drive, interrupt latching/clearing, FSYNC interrupt behavior, and INT2 routing."}]; v1=[{"hex":"0x37","decimal":"55","bank":"","page":"","description":""}].
139. `registers[19].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
140. `registers[19].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x37","decimal":"55","bank":"","page":"","description":"INT_PIN_CFG register; Configures INT/INT2 polarity, output drive, interrupt latching/clearing, FSYNC interrupt behavior, and INT2 routing."}; v1={"hex":"0x37","decimal":"55","bank":"","page":"","description":""}.
141. `registers[19].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Configures INT/INT2 polarity, output drive, interrupt latching/clearing, FSYNC interrupt behavior, and INT2 routing.; v1="".
142. `registers[19].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
143. `registers[19].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
144. `registers[19].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
145. `registers[19].field_parts[0].bit_field[2].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
146. `registers[19].field_parts[0].bit_field[3].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
147. `registers[19].field_parts[0].bit_field[4].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
148. `registers[19].field_parts[0].bit_field[5].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
149. `registers[19].field_parts[0].bit_field[6].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
150. `registers[19].field_parts[0].bit_field[7].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
151. `registers[20].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x38","decimal":"56","bank":"","page":"","description":"INT_ENABLE register; Individually enables X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupts."}]; v1=[{"hex":"0x38","decimal":"56","bank":"","page":"","description":""}].
152. `registers[20].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
153. `registers[20].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x38","decimal":"56","bank":"","page":"","description":"INT_ENABLE register; Individually enables X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupts."}; v1={"hex":"0x38","decimal":"56","bank":"","page":"","description":""}.
154. `registers[20].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Individually enables X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupts.; v1="".
155. `registers[20].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
156. `registers[20].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
157. `registers[20].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
158. `registers[20].field_parts[0].bit_field[2].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
159. `registers[20].field_parts[0].bit_field[3].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
160. `registers[20].field_parts[0].bit_field[4].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
161. `registers[20].field_parts[0].bit_field[5].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
162. `registers[20].field_parts[0].bit_field[6].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
163. `registers[21].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x3A","decimal":"58","bank":"","page":"","description":"INT_STATUS register; Reports X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupt status; WOM and data-ready status clear on read."}]; v1=[{"hex":"0x3A","decimal":"58","bank":"","page":"","description":""}].
164. `registers[21].type_write_read`: C=0.500000; read access is present but read-to-clear behavior is omitted. Datasheet=R/C; v1=R.
165. `registers[21].field_parts`: C=0.717106; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
166. `registers[21].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x3A","decimal":"58","bank":"","page":"","description":"INT_STATUS register; Reports X/Y/Z Wake-on-Motion, gyroscope-drive-ready, and data-ready interrupt status; WOM and data-ready status clear on read."}; v1={"hex":"0x3A","decimal":"58","bank":"","page":"","description":""}.
167. `registers[21].field_parts[0].type_write_read`: C=0.500000; v1 records R but datasheet specifies READ to CLEAR. Datasheet=R/C; v1=R.
168. `registers[21].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
169. `registers[21].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R/C; v1="".
170. `registers[21].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R/C; v1="".
171. `registers[21].field_parts[0].bit_field[2].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R/C; v1="".
172. `registers[21].field_parts[0].bit_field[3].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R/C; v1="".
173. `registers[21].field_parts[0].bit_field[4].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R/C; v1="".
174. `registers[21].field_parts[0].bit_field[5].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R/C; v1="".
175. `registers[21].field_parts[0].bit_field[6].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R/C; v1="".
176. `registers[22].field_parts`: C=0.981756; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
177. `registers[22].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
178. `registers[22].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
179. `registers[22].field_parts[1].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
180. `registers[22].field_parts[1].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
181. `registers[23].field_parts`: C=0.981756; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
182. `registers[23].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
183. `registers[23].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
184. `registers[23].field_parts[1].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
185. `registers[23].field_parts[1].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
186. `registers[24].field_parts`: C=0.981756; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
187. `registers[24].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
188. `registers[24].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
189. `registers[24].field_parts[1].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
190. `registers[24].field_parts[1].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
191. `registers[25].field_parts`: C=0.981756; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
192. `registers[25].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
193. `registers[25].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
194. `registers[25].field_parts[1].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
195. `registers[25].field_parts[1].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
196. `registers[26].field_parts`: C=0.981756; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
197. `registers[26].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
198. `registers[26].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
199. `registers[26].field_parts[1].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
200. `registers[26].field_parts[1].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
201. `registers[27].field_parts`: C=0.981756; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
202. `registers[27].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
203. `registers[27].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
204. `registers[27].field_parts[1].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
205. `registers[27].field_parts[1].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
206. `registers[28].field_parts`: C=0.981756; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
207. `registers[28].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
208. `registers[28].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
209. `registers[28].field_parts[1].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
210. `registers[28].field_parts[1].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
211. `registers[29].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x68","decimal":"104","bank":"","page":"","description":"SIGNAL_PATH_RESET register; Resets the accelerometer or temperature digital signal path; sensor registers are not cleared."}]; v1=[{"hex":"0x68","decimal":"104","bank":"","page":"","description":""}].
212. `registers[29].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
213. `registers[29].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x68","decimal":"104","bank":"","page":"","description":"SIGNAL_PATH_RESET register; Resets the accelerometer or temperature digital signal path; sensor registers are not cleared."}; v1={"hex":"0x68","decimal":"104","bank":"","page":"","description":""}.
214. `registers[29].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Resets the accelerometer or temperature digital signal path; sensor registers are not cleared.; v1="".
215. `registers[29].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
216. `registers[29].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
217. `registers[29].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
218. `registers[29].field_parts[0].bit_field[2].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
219. `registers[30].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x69","decimal":"105","bank":"","page":"","description":"ACCEL_INTEL_CTRL register; Enables Wake-on-Motion detection and selects current-sample comparison with the first or previous sample; bit 0 must be 0 when WoM is activated."}]; v1=[{"hex":"0x69","decimal":"105","bank":"","page":"","description":""}].
220. `registers[30].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
221. `registers[30].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x69","decimal":"105","bank":"","page":"","description":"ACCEL_INTEL_CTRL register; Enables Wake-on-Motion detection and selects current-sample comparison with the first or previous sample; bit 0 must be 0 when WoM is activated."}; v1={"hex":"0x69","decimal":"105","bank":"","page":"","description":""}.
222. `registers[30].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Enables Wake-on-Motion detection and selects current-sample comparison with the first or previous sample; bit 0 must be 0 when WoM is activated.; v1="".
223. `registers[30].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
224. `registers[30].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
225. `registers[30].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
226. `registers[30].field_parts[0].bit_field[2].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
227. `registers[30].field_parts[0].bit_field[3].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
228. `registers[31].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x6A","decimal":"106","bank":"","page":"","description":"USER_CTRL register; Controls serial-interface mode and digital signal-path reset; I2C_IF_DIS selects SPI-only operation and SIG_COND_RST clears sensor registers."}]; v1=[{"hex":"0x6A","decimal":"106","bank":"","page":"","description":""}].
229. `registers[31].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
230. `registers[31].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x6A","decimal":"106","bank":"","page":"","description":"USER_CTRL register; Controls serial-interface mode and digital signal-path reset; I2C_IF_DIS selects SPI-only operation and SIG_COND_RST clears sensor registers."}; v1={"hex":"0x6A","decimal":"106","bank":"","page":"","description":""}.
231. `registers[31].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Controls serial-interface mode and digital signal-path reset; I2C_IF_DIS selects SPI-only operation and SIG_COND_RST clears sensor registers.; v1="".
232. `registers[31].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
233. `registers[31].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
234. `registers[31].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
235. `registers[31].field_parts[0].bit_field[2].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
236. `registers[31].field_parts[0].bit_field[3].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
237. `registers[32].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x6B","decimal":"107","bank":"","page":"","description":"PWR_MGMT_1 register; Controls device reset, sleep, accelerometer cycle, gyroscope standby, temperature disable, and clock source; default PWR_MGMT_1 is 0x01 and CLKSEL[2:0] defaults to 001."}]; v1=[{"hex":"0x6B","decimal":"107","bank":"","page":"","description":""}].
238. `registers[32].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
239. `registers[32].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x6B","decimal":"107","bank":"","page":"","description":"PWR_MGMT_1 register; Controls device reset, sleep, accelerometer cycle, gyroscope standby, temperature disable, and clock source; default PWR_MGMT_1 is 0x01 and CLKSEL[2:0] defaults to 001."}; v1={"hex":"0x6B","decimal":"107","bank":"","page":"","description":""}.
240. `registers[32].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Controls device reset, sleep, accelerometer cycle, gyroscope standby, temperature disable, and clock source; default PWR_MGMT_1 is 0x01 and CLKSEL[2:0] defaults to 001.; v1="".
241. `registers[32].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
242. `registers[32].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
243. `registers[32].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
244. `registers[32].field_parts[0].bit_field[2].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
245. `registers[32].field_parts[0].bit_field[3].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
246. `registers[32].field_parts[0].bit_field[4].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
247. `registers[32].field_parts[0].bit_field[5].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
248. `registers[33].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x6C","decimal":"108","bank":"","page":"","description":"PWR_MGMT_2 register; Individually controls standby/enable state for each accelerometer and gyroscope axis."}]; v1=[{"hex":"0x6C","decimal":"108","bank":"","page":"","description":""}].
249. `registers[33].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
250. `registers[33].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x6C","decimal":"108","bank":"","page":"","description":"PWR_MGMT_2 register; Individually controls standby/enable state for each accelerometer and gyroscope axis."}; v1={"hex":"0x6C","decimal":"108","bank":"","page":"","description":""}.
251. `registers[33].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Individually controls standby/enable state for each accelerometer and gyroscope axis.; v1="".
252. `registers[33].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
253. `registers[33].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
254. `registers[33].field_parts[0].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
255. `registers[33].field_parts[0].bit_field[2].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
256. `registers[33].field_parts[0].bit_field[3].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
257. `registers[33].field_parts[0].bit_field[4].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
258. `registers[33].field_parts[0].bit_field[5].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
259. `registers[33].field_parts[0].bit_field[6].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
260. `registers[34].physical_address`: C=0.500000; numeric physical address is correct but the address description is empty, so the composite address field is partial. Datasheet=[{"hex":"0x75","decimal":"117","bank":"","page":"","description":"WHO_AM_I register; Provides the 8-bit device identity for access verification; default value is 0xFE and is distinct from the device I²C address."}]; v1=[{"hex":"0x75","decimal":"117","bank":"","page":"","description":""}].
261. `registers[34].field_parts`: C=0.678056; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
262. `registers[34].field_parts[0].physical_address`: C=0.500000; numeric address matches but v1 omits the address description. Datasheet={"hex":"0x75","decimal":"117","bank":"","page":"","description":"WHO_AM_I register; Provides the 8-bit device identity for access verification; default value is 0xFE and is distinct from the device I²C address."}; v1={"hex":"0x75","decimal":"117","bank":"","page":"","description":""}.
263. `registers[34].field_parts[0].description`: C=0.000000; standalone field-part description is missing. Datasheet=Provides the 8-bit device identity for access verification; default value is 0xFE and is distinct from the device I²C address.; v1="".
264. `registers[34].field_parts[0].bit_field`: C=0.941694; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
265. `registers[34].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=R; v1="".
266. `registers[35].width_bits`: C=0.000000; objective width mismatch. Datasheet=15; v1=16.
267. `registers[35].field_parts`: C=0.974879; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
268. `registers[35].field_parts[0].bit_field`: C=0.912391; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
269. `registers[35].field_parts[0].bit_field[0].field_description`: C=0.500000; description is incomplete but the main function is present. Datasheet=Bits 14 to 7 of the 15-bit X accelerometer offset cancellation (2's complement); ±16g and 0.98-mg steps.; v1=Bits 14 to 7 of the signed 15-bit X accelerometer offset cancellation value..
270. `registers[35].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
271. `registers[35].field_parts[1].bit_field`: C=0.927043; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
272. `registers[35].field_parts[1].bit_field[0].field_description`: C=0.500000; description is incomplete but the main function is present. Datasheet=Bits 6 to 0 of the 15-bit X accelerometer offset cancellation (2's complement); ±16g and 0.98-mg steps.; v1=Bits 6 to 0 of the signed 15-bit X accelerometer offset cancellation value..
273. `registers[35].field_parts[1].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
274. `registers[35].field_parts[1].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
275. `registers[36].width_bits`: C=0.000000; objective width mismatch. Datasheet=15; v1=16.
276. `registers[36].field_parts`: C=0.974879; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
277. `registers[36].field_parts[0].bit_field`: C=0.912391; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
278. `registers[36].field_parts[0].bit_field[0].field_description`: C=0.500000; description is incomplete but the main function is present. Datasheet=Bits 14 to 7 of the 15-bit Y accelerometer offset cancellation (2's complement); ±16g and 0.98-mg steps.; v1=Bits 14 to 7 of the signed 15-bit Y accelerometer offset cancellation value..
279. `registers[36].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
280. `registers[36].field_parts[1].bit_field`: C=0.927043; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
281. `registers[36].field_parts[1].bit_field[0].field_description`: C=0.500000; description is incomplete but the main function is present. Datasheet=Bits 6 to 0 of the 15-bit Y accelerometer offset cancellation (2's complement); ±16g and 0.98-mg steps.; v1=Bits 6 to 0 of the signed 15-bit Y accelerometer offset cancellation value..
282. `registers[36].field_parts[1].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
283. `registers[36].field_parts[1].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
284. `registers[37].width_bits`: C=0.000000; objective width mismatch. Datasheet=15; v1=16.
285. `registers[37].field_parts`: C=0.974879; recursive mean is below 1 because one or more nested fields are incomplete. Datasheet=datasheet field-part collection; v1=extracted field-part collection.
286. `registers[37].field_parts[0].bit_field`: C=0.912391; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
287. `registers[37].field_parts[0].bit_field[0].field_description`: C=0.500000; description is incomplete but the main function is present. Datasheet=Bits 14 to 7 of the 15-bit Z accelerometer offset cancellation (2's complement); ±16g and 0.98-mg steps.; v1=Bits 14 to 7 of the signed 15-bit Z accelerometer offset cancellation value..
288. `registers[37].field_parts[0].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
289. `registers[37].field_parts[1].bit_field`: C=0.927043; mean of nested bit-field scores. Datasheet=datasheet bit-field set; v1=matched v1 bit-field set.
290. `registers[37].field_parts[1].bit_field[0].field_description`: C=0.500000; description is incomplete but the main function is present. Datasheet=Bits 6 to 0 of the 15-bit Z accelerometer offset cancellation (2's complement); ±16g and 0.98-mg steps.; v1=Bits 6 to 0 of the signed 15-bit Z accelerometer offset cancellation value..
291. `registers[37].field_parts[1].bit_field[0].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".
292. `registers[37].field_parts[1].bit_field[1].type_write_read`: C=0.000000; datasheet register access type is inherited by the bit field; v1 leaves it empty. Datasheet=RW; v1="".

### Error/omission summary

- All 110 v1 bit fields leave `type_write_read` empty. The datasheet provides the applicable register type for every one of these fields; this is the largest repeated omission.
- The 25 single-byte logical registers omit the `physical_address.description` at both logical and field-part address locations. Numeric hex/decimal addresses are correct, so each composite address field receives 0.5 rather than 0.
- 23 field-part `description` fields are empty: v1 `registers[0..5]`, `registers[9..17]`, `registers[19..20]`, and `registers[29..34]`, each at `field_parts[0].description`. Their datasheet register functions are present in the source tables.
- `registers[9].field_parts[0].bit_field[0].field_description` only says that the field is an eight-bit divider; it omits the datasheet formula and effectiveness conditions, so it is partial.
- `registers[6..8].field_parts[0..1].bit_field[0].field_description` records the bit slice and signed offset but omits the datasheet's DC-bias/add-before-sensor-register behavior; the logical descriptions retain that behavior, so each is partial.
- `registers[18].type_write_read` and `registers[18].field_parts[0].type_write_read` record `R` while the datasheet says `READ to CLEAR`; the same issue occurs at `registers[21]`. The read aspect is correct, but clear-on-read is omitted, so these direct type fields are partial.
- `registers[35].width_bits`, `registers[36].width_bits`, and `registers[37].width_bits` are `16`, but the datasheet defines `XA_OFFS`, `YA_OFFS`, and `ZA_OFFS` as 15-bit offset-cancellation values; the low-byte bit 0 is a separate factory-calibrated reserved bit. These three objective width fields receive 0.
- `registers[35..37].field_parts[0..1].bit_field[0].field_description` gives the correct 15-bit slice but omits the datasheet's ±16g and 0.98-mg-step qualification; each is partial. The reserved bit fields are accepted, including the empty-name/description allowance.
- No datasheet physical register is missing, no extracted physical address is extra, no bit range is missing or extra at a matched address, and all enumerated value-code sets match the datasheet. Wording differences in correct value descriptions are not penalized.

## 7. Invented-field and source-consistency check

- Physical-address check: 51 unique v1 physical keys, all matched to the 51 datasheet register-map locations; no duplicate or unmatched address.
- Bit-range check: every v1 bit field is aligned with the corresponding datasheet range. The reserved [6:0] lower portion of `FSYNC_INT` is supported by the p.29 register map.
- Value check: no extra functional code or missing code was found in the enumerated fields (`EXT_SYNC_SET`, `FS_SEL`, `ACCEL_FS_SEL`, `DEC2_CFG`, `ACCEL_WOM_ODR_CTRL`, interrupt controls/status, `ACCEL_INTEL_MODE`, `PWR_MGMT_1`, `PWR_MGMT_2`).
- Source spelling check: `GYRO_ZOUT_H/L` and `SIGNAL_PATH_RESET` follow the detailed datasheet sections, not the two abbreviated/typographical strings in the register-map overview.

## 8. Final result

IAM-20680HV v1.0 datasheet-based score: **8.427222203/10**.

The score includes all 38 logical-register calculations, all 51 physical field parts, all 110 bit fields, the 51 physical-register q_R aggregation, and the extra-register penalty factor.

