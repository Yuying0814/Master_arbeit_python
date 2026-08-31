# ICM-20948 without detailed score - datasheet-based

## 1. Scoring basis

- Datasheet truth is the supplied PDF, not a JSON truth file: `D:\python\master_arbeit\data\output\ICM20948\ds-000189-icm-20948-v1.5.pdf`.
- Official source: [TDK InvenSense DS-000189 ICM-20948 v1.5](https://invensense.tdk.com/wp-content/uploads/2021/10/DS-000189-ICM-20948-v1.5.pdf); Revision 1.5, release date 2021-09-02.
- The requested device name says ICM20947, but the supplied PDF and extraction are for ICM-20948; this report evaluates the supplied ICM-20948 datasheet.
- Datasheet sources used for physical truth and field details: User Bank 0 register map PDF p.32 and detailed descriptions p.36-54; User Bank 1 p.33 and p.55-58; User Bank 2 p.34 and p.59-67; User Bank 3 p.34 and p.68-76; AK09916 magnetometer p.77-80.
- Physical-register definition: one real register location present in the datasheet. Numeric address plus bank/page identifies a location. The four repeated REG_BANK_SEL rows are normalized to one global physical register `ALL/0x7F`; a wrong bank/address is not repaired by a matching name.
- Datasheet contains n=134 unique real physical registers: User Bank 0 = 64, User Bank 1 = 13, User Bank 2 = 19, User Bank 3 = 24, global REG_BANK_SEL = 1, and AK09916 magnetometer = 13.
- The evaluated input is `D:\python\master_arbeit\data\output\ICM20948\without\ds-000189-icm-20948-v1.5.json`; it contains 35 logical-register entries and 35 physical entries.
- Objective facts are strict: register identity, numeric address/bank/page, widths, exact bit ranges, reset values, access types, reserved state, and value codes. Description-like fields receive semantic credit when functional meaning is present. If both sides are empty, C=1.0.
- Equivalent notation `R/W`/`RW` and `R/C`/`RC`, numeric value-code lists versus singleton value objects, the global REG_BANK_SEL view, and the known ICM-20948 `INT1_LATCH__EN`/`INT1_LATCH_INT_EN` OCR spelling are normalized only when they encode the same objective fact.
- Every matched logical register is calculated bottom-up independently: all bit fields, then the containing field part, then one Q(L). Missing truth physical registers have q_R=0; extra extracted physical entries are penalized by m/(m+x).
- Rounded AHP weights and level denominators follow AGENTS.md: bit-field denominator 0.9999, field-part denominator 1.0000, logical-register denominator 1.0001.

## 2. Score summary

| Quantity | Value |
|---|---:|
| n (real datasheet physical registers) | 134 |
| extracted logical-register entries | 35 |
| extracted physical-register entries | 35 |
| m (matched datasheet physical registers) | 26 |
| x (extra extracted physical entries) | 9 |
| sum q_R | 25.808253296429 |
| mean q_R over n truth locations | 0.192598905197 |
| extra penalty m/(m+x) | 0.742857142857 |
| S_final | **1.430734724322 / 10** |

S_final = (10/134 × 25.808253296429) × (26/(26+9)) = **1.430734724322 / 10**.

## 3. Detailed bottom-up calculations

Only the 26 extracted entries whose numeric address and bank/page correspond to a real datasheet location receive Q(L). The 9 entries listed later as extras do not receive a truth-register q_R.

## Extracted logical register 1: `WHO_AM_I`

Extraction location: `registers[0]`; truth association: `bank0/0x00`.
Associated physical location: `bank0/0x00`; datasheet source: PDF p.36.

### Bottom layer: bit fields, then field parts

#### Field part 1: `WHO_AM_I`

**Datasheet bit field 1: `WHO_AM_I[7:0]`, bits 7:0**

Location: `registers[0].field_parts[0].bit_field[0]`; datasheet source: PDF p.36.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WHO_AM_I[7:0] | WHO_AM_I[7:0] |
| `field_description` | 0.0586 | 1.0 | Register to indicate to user which device is being accessed.<br>The value for ICM-20948 is 0xEA. | Register to indicate which device is being accessed. The value for ICM-20948 is 0xEA. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x00","decimal":0,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x00","decimal":"0","bank":"0","page":"","description":"User Bank 0 register address"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for WHO_AM_I (PDF p.36). | Device ID register (MSB..LSB) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | WHO_AM_I | WHO_AM_I |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x00","decimal":0,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x00","decimal":"0","bank":"0","page":"","description":"User Bank 0 register address"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register WHO_AM_I; see PDF p.36. | Read-only device ID register. ICM-20948 WHO_AM_I value = 0xEA. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.36) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0xEA | 0xEA |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 2: `USER_CTRL`

Extraction location: `registers[1]`; truth association: `bank0/0x03`.
Associated physical location: `bank0/0x03`; datasheet source: PDF p.36.

### Bottom layer: bit fields, then field parts

#### Field part 1: `USER_CTRL`

**Datasheet bit field 1: `DMP_EN`, bits 7:7**

Location: `registers[1].field_parts[0].bit_field[0]`; datasheet source: PDF p.36.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DMP_EN | DMP_EN |
| `field_description` | 0.0586 | 1.0 | 1 – Enables DMP features.<br>0 – DMP features are disabled after the current processing round has completed. | 1 – Enables DMP features. 0 – DMP features disabled after current processing round has completed. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 2: `FIFO_EN`, bits 6:6**

Location: `registers[1].field_parts[0].bit_field[1]`; datasheet source: PDF p.36.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FIFO_EN | FIFO_EN |
| `field_description` | 0.0586 | 1.0 | 1 – Enable FIFO operation mode.<br>0 – Disable FIFO access from serial interface.<br>To disable FIFO writes by DMA, use FIFO_EN register. To disable possible FIFO writes from DMP, disable the DMP. | 1 – Enable FIFO operation. 0 – Disable FIFO access from serial interface. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 3: `I2C_MST_EN`, bits 5:5**

Location: `registers[1].field_parts[0].bit_field[2]`; datasheet source: PDF p.36.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_MST_EN | I2C_MST_EN |
| `field_description` | 0.0586 | 1.0 | 1 – Enable the I²C Master I/F module; pins ES_DA and ES_SCL are isolated from pins SDA/SDI and SCL/ SCLK.<br>0 – Disable I²C Master I/F module; pins ES_DA and ES_SCL are logically driven by pins SDA/SDI and SCL/ SCLK. | 1 – Enable I²C Master module; auxiliary pins isolated from primary SDA/SCL. 0 – Disable I²C Master module; auxiliary pins driven by primary SDA/SCL. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 4: `I2C_IF_DIS`, bits 4:4**

Location: `registers[1].field_parts[0].bit_field[3]`; datasheet source: PDF p.36.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_IF_DIS | I2C_IF_DIS |
| `field_description` | 0.0586 | 1.0 | 1 – Reset I²C Slave module and put the serial interface in SPI mode only. | 1 – Reset I²C Slave module and put serial interface in SPI-only mode. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 5: `DMP_RST`, bits 3:3**

Location: `registers[1].field_parts[0].bit_field[4]`; datasheet source: PDF p.36.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DMP_RST | DMP_RST |
| `field_description` | 0.0586 | 1.0 | 1 – Reset DMP module. Reset is asynchronous. This bit auto clears after one clock cycle of the internal 20 MHz clock. | 1 – Reset DMP module (asynchronous). Auto-clears after one internal clock cycle. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 6: `SRAM_RST`, bits 2:2**

Location: `registers[1].field_parts[0].bit_field[5]`; datasheet source: PDF p.36.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SRAM_RST | SRAM_RST |
| `field_description` | 0.0586 | 1.0 | 1 – Reset SRAM module. Reset is asynchronous. This bit auto clears after one clock cycle of the internal 20 MHz clock. | 1 – Reset SRAM module (asynchronous). Auto-clears after one internal clock cycle. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 7: `I2C_MST_RST`, bits 1:1**

Location: `registers[1].field_parts[0].bit_field[6]`; datasheet source: PDF p.36.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_MST_RST | I2C_MST_RST |
| `field_description` | 0.0586 | 1.0 | 1 – Reset I²C Master module. Reset is asynchronous. This bit auto clears after one clock cycle of the internal 20 MHz clock.<br>NOTE: This bit should only be set when the I²C master has hung. If this bit is set during an active I²C master transaction, the I²C slave will hang, which will require the host to reset the slave. | 1 – Reset I²C Master module (asynchronous). Auto-clears after one internal clock cycle. Use only if I²C master hung. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 8: `reserved/fixed`, bits 0:0**

Location: `registers[1].field_parts[0].bit_field[7]`; datasheet source: PDF p.36.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ∅ | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | True |
| `type_write_read` | 0.0583 | 1.0 | ∅ | ∅ |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(0.790279, 0.790279, 0.790279, 0.790279, 0.790279, 0.790279, 0.790279, 1.000000) = **0.816494**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | USER_CTRL | USER_CTRL |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x03","decimal":3,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x03","decimal":"3","bank":"0","page":"","description":"User Bank 0 register address"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for USER_CTRL (PDF p.36). | Control bits for DMP/FIFO/I2C master and resets |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R/W | R/W |
| `bit_field` | 0.3129 | 0.816494 | datasheet bit-field set (8 exact ranges) | matched exact ranges (8); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.816494)/1.0000 = 0.942581/1.0000 = **0.942581**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.942581) = **0.942581**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | USER_CTRL | USER_CTRL |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x03","decimal":3,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x03","decimal":"3","bank":"0","page":"","description":"User Bank 0 register address"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register USER_CTRL; see PDF p.36. | Controls DMP, FIFO, and I²C master/SRAM resets and I²C interface mode. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R/W | R/W |
| `field_parts` | 0.2987 | 0.942581 | corresponding datasheet field-part collection (PDF p.36) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.942581 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 0.982949/1.0001 = **0.982851**.

## Extracted logical register 3: `LP_CONFIG`

Extraction location: `registers[2]`; truth association: `bank0/0x05`.
Associated physical location: `bank0/0x05`; datasheet source: PDF p.37.

### Bottom layer: bit fields, then field parts

#### Field part 1: `LP_CONFIG`

**Datasheet bit field 1: `reserved/fixed`, bits 7:7**

Location: `registers[2].field_parts[0].bit_field` has no entry for the exact datasheet range; datasheet source: PDF p.37.
Judgment: C<1 fields: name_or_parameter (entire datasheet bit field missing); field_description (entire datasheet bit field missing); bit_start (entire datasheet bit field missing); bit_end (entire datasheet bit field missing); bit_width (entire datasheet bit field missing); values (entire datasheet bit field missing); is_reserved (entire datasheet bit field missing); type_write_read (entire datasheet bit field missing).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ∅ | MISSING |
| `field_description` | 0.0586 | 0.0 | Reserved. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | ∅ | MISSING |

Q_BF = (0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999 = 0.000000/0.9999 = **0.000000**.

**Datasheet bit field 2: `I2C_MST_CYCLE`, bits 6:6**

Location: `registers[2].field_parts[0].bit_field[0]`; datasheet source: PDF p.37.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_MST_CYCLE | I2C_MST_CYCLE |
| `field_description` | 0.0586 | 1.0 | 1 - Operate I²C master in duty cycled mode. ODR is determined by I2C_MST_ODR_CONFIG register.<br>0 - Disable I²C master duty cycled mode. | 1 – Operate I²C master in duty-cycled mode. ODR determined by I2C_MST_ODR_CONFIG. 0 – Disable I²C master duty cycled mode. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 3: `ACCEL_CYCLE`, bits 5:5**

Location: `registers[2].field_parts[0].bit_field[1]`; datasheet source: PDF p.37.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_CYCLE | ACCEL_CYCLE |
| `field_description` | 0.0586 | 1.0 | 1 - Operate ACCEL in duty cycled mode. ODR is determined by ACCEL_SMPLRT_DIV register.<br>0 - Disable ACCEL duty cycled mode. | 1 – Operate accelerometer in duty-cycled mode. ODR determined by ACCEL_SMPLRT_DIV. 0 – Disable accel duty-cycled mode. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 4: `GYRO_CYCLE`, bits 4:4**

Location: `registers[2].field_parts[0].bit_field[2]`; datasheet source: PDF p.37.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_CYCLE | GYRO_CYCLE |
| `field_description` | 0.0586 | 1.0 | 1 - Operate GYRO in duty cycled mode. ODR is determined by GYRO_SMPLRT_DIV register.<br>0 - Disable GYRO duty cycled mode. | 1 – Operate gyro in duty-cycled mode. ODR determined by GYRO_SMPLRT_DIV. 0 – Disable gyro duty-cycled mode. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 5: `reserved/fixed`, bits 3:0**

Location: `registers[2].field_parts[0].bit_field[3]`; datasheet source: PDF p.37.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ∅ | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | True |
| `type_write_read` | 0.0583 | 1.0 | ∅ | ∅ |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(0.000000, 0.790279, 0.790279, 0.790279, 1.000000) = **0.674167**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | LP_CONFIG | LP_CONFIG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x05","decimal":5,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x05","decimal":"5","bank":"0","page":"","description":"User Bank 0 register address"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for LP_CONFIG (PDF p.37). | Low-power configuration bits |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R/W | R/W |
| `bit_field` | 0.3129 | 0.674167 | datasheet bit-field set (5 exact ranges) | matched exact ranges (5); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.674167)/1.0000 = 0.898047/1.0000 = **0.898047**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.898047) = **0.898047**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | LP_CONFIG | LP_CONFIG |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x05","decimal":5,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x05","decimal":"5","bank":"0","page":"","description":"User Bank 0 register address"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register LP_CONFIG; see PDF p.37. | Low-power related configuration: duty-cycle control for I²C master, accelerometer, and gyroscope. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R/W | R/W |
| `field_parts` | 0.2987 | 0.898047 | corresponding datasheet field-part collection (PDF p.37) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x40 | 0x40 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.898047 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 0.969647/1.0001 = **0.969550**.

## Extracted logical register 4: `PWR_MGMT_1`

Extraction location: `registers[3]`; truth association: `bank0/0x06`.
Associated physical location: `bank0/0x06`; datasheet source: PDF p.37.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PWR_MGMT_1`

**Datasheet bit field 1: `DEVICE_RESET`, bits 7:7**

Location: `registers[3].field_parts[0].bit_field[0]`; datasheet source: PDF p.37.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DEVICE_RESET | DEVICE_RESET |
| `field_description` | 0.0586 | 1.0 | 1 - Reset the internal registers and restores the default settings. Write a 1 to set the reset, the bit will auto clear. | 1 – Reset internal registers and restore defaults. Write 1 to set reset; auto-clears. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 2: `SLEEP`, bits 6:6**

Location: `registers[3].field_parts[0].bit_field[1]`; datasheet source: PDF p.37.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | SLEEP | SLEEP |
| `field_description` | 0.0586 | 1.0 | When set, the chip is set to sleep mode (in sleep mode all analog is powered off). Clearing the bit wakes the chip from sleep mode. | When set, chip enters sleep mode (all analog powered off). Clearing wakes chip. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 3: `LP_EN`, bits 5:5**

Location: `registers[3].field_parts[0].bit_field[2]`; datasheet source: PDF p.37.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | LP_EN | LP_EN |
| `field_description` | 0.0586 | 1.0 | The LP_EN only affects the digital circuitry, it helps to reduce the digital current when sensors are in LP mode. Please note that the sensors themselves are set in LP mode by the LP_CONFIG register settings. Sensors in LP mode, and use of LP_EN bit together help to reduce overall current. The bit settings are:<br>1: Turn on low power feature.<br>0: Turn off low power feature.<br>LP_EN has no effect when the sensors are in low-noise mode. | Digital low-power enable to reduce digital current when sensors in LP mode. 1: enable; 0: disable. No effect in low-noise mode. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 4: `reserved/fixed`, bits 4:4**

Location: `registers[3].field_parts[0].bit_field[3]`; datasheet source: PDF p.37.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ∅ | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | True |
| `type_write_read` | 0.0583 | 1.0 | ∅ | ∅ |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 5: `TEMP_DIS`, bits 3:3**

Location: `registers[3].field_parts[0].bit_field[4]`; datasheet source: PDF p.37.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_DIS | TEMP_DIS |
| `field_description` | 0.0586 | 1.0 | When set to 1, this bit disables the temperature sensor. | When 1, disables the temperature sensor. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 6: `CLKSEL[2:0]`, bits 2:0**

Location: `registers[3].field_parts[0].bit_field[5]`; datasheet source: PDF p.37.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | CLKSEL[2:0] | CLKSEL[2:0] |
| `field_description` | 0.0586 | 1.0 | Code: Clock Source<br>0: Internal 20 MHz oscillator<br>1-5: Auto selects the best available clock source - PLL if ready, else use the Internal oscillator<br>6: Internal 20 MHz oscillator<br>7: Stops the clock and keeps timing generator in reset<br>NOTE: CLKSEL[2:0] should be set to 1~5 to achieve full gyroscope performance. | Clock source selection. 0: internal 20 MHz oscillator; 1-5: auto select best clock (PLL if ready else internal); 6: internal 20 MHz; 7: stop clock and hold timing generator in reset. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 0.0 | ["0","5","6","7"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Field-part aggregation**

bit_field correctness = mean(0.790279, 1.000000, 0.790279, 1.000000, 1.000000, 0.790279) = **0.895140**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | PWR_MGMT_1 | PWR_MGMT_1 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x06","decimal":6,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x06","decimal":"6","bank":"0","page":"","description":"User Bank 0 register address"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for PWR_MGMT_1 (PDF p.37). | Power-management and clock selection bits |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R/W | R/W |
| `bit_field` | 0.3129 | 0.895140 | datasheet bit-field set (6 exact ranges) | matched exact ranges (6); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.895140)/1.0000 = 0.967189/1.0000 = **0.967189**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.967189) = **0.967189**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | PWR_MGMT_1 | PWR_MGMT_1 |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x06","decimal":6,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x06","decimal":"6","bank":"0","page":"","description":"User Bank 0 register address"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register PWR_MGMT_1; see PDF p.37. | Power management control: device reset, sleep, low-power enable, temperature sensor disable, and clock source selection. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R/W | R/W |
| `field_parts` | 0.2987 | 0.967189 | corresponding datasheet field-part collection (PDF p.37) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x41 | 0x41 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.967189 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 0.990299/1.0001 = **0.990200**.

## Extracted logical register 5: `PWR_MGMT_2`

Extraction location: `registers[4]`; truth association: `bank0/0x07`.
Associated physical location: `bank0/0x07`; datasheet source: PDF p.38.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PWR_MGMT_2`

**Datasheet bit field 1: `reserved/fixed`, bits 7:6**

Location: `registers[4].field_parts[0].bit_field[2]`; datasheet source: PDF p.38.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ∅ | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | True |
| `type_write_read` | 0.0583 | 1.0 | ∅ | ∅ |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 2: `DISABLE_ACCEL`, bits 5:3**

Location: `registers[4].field_parts[0].bit_field[0]`; datasheet source: PDF p.38.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DISABLE_ACCEL | DISABLE_ACCEL |
| `field_description` | 0.0586 | 1.0 | Only the following values are applicable:<br>111 – Accelerometer (all axes) disabled.<br>000 – Accelerometer (all axes) on. | Field controls accelerometer disable. Valid values: 111 – accelerometer (all axes) disabled; 000 – accelerometer on. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 0.0 | ["0","7"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 3: `DISABLE_GYRO`, bits 2:0**

Location: `registers[4].field_parts[0].bit_field[1]`; datasheet source: PDF p.38.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DISABLE_GYRO | DISABLE_GYRO |
| `field_description` | 0.0586 | 1.0 | Only the following values are applicable:<br>111 – Gyroscope (all axes) disabled.<br>000 – Gyroscope (all axes) on. | Field controls gyroscope disable. Valid values: 111 – gyroscope (all axes) disabled; 000 – gyroscope on. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 0.0 | ["0","7"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Field-part aggregation**

bit_field correctness = mean(1.000000, 0.790279, 0.790279) = **0.860186**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | PWR_MGMT_2 | PWR_MGMT_2 |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x07","decimal":7,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x07","decimal":"7","bank":"0","page":"","description":"User Bank 0 register address"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for PWR_MGMT_2 (PDF p.38). | Disable/enable accelerometer and gyroscope axes |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R/W | R/W |
| `bit_field` | 0.3129 | 0.860186 | datasheet bit-field set (3 exact ranges) | matched exact ranges (3); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.860186)/1.0000 = 0.956252/1.0000 = **0.956252**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.956252) = **0.956252**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | PWR_MGMT_2 | PWR_MGMT_2 |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x07","decimal":7,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x07","decimal":"7","bank":"0","page":"","description":"User Bank 0 register address"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register PWR_MGMT_2; see PDF p.38. | Enable/disable individual sensor axes (gyro and accel) for power management. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R/W | R/W |
| `field_parts` | 0.2987 | 0.956252 | corresponding datasheet field-part collection (PDF p.38) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.956252 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 0.987033/1.0001 = **0.986934**.

## Extracted logical register 6: `INT_PIN_CFG`

Extraction location: `registers[5]`; truth association: `bank0/0x0F`.
Associated physical location: `bank0/0x0F`; datasheet source: PDF p.38.

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_PIN_CFG`

**Datasheet bit field 1: `INT1_ACTL`, bits 7:7**

Location: `registers[5].field_parts[0].bit_field[0]`; datasheet source: PDF p.38.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | INT1_ACTL | INT1_ACTL |
| `field_description` | 0.0586 | 1.0 | 1 – The logic level for INT1 pin is active low.<br>0 – The logic level for INT1 pin is active high. | 1 – INT1 active low; 0 – active high. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 2: `INT1_OPEN`, bits 6:6**

Location: `registers[5].field_parts[0].bit_field[1]`; datasheet source: PDF p.38.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | INT1_OPEN | INT1_OPEN |
| `field_description` | 0.0586 | 1.0 | 1 – INT1 pin is configured as open drain.<br>0 – INT1 pin is configured as push-pull. | 1 – INT1 configured as open-drain; 0 – push-pull. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 3: `INT1_LATCH__EN`, bits 5:5**

Location: `registers[5].field_parts[0].bit_field[2]`; datasheet source: PDF p.38.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | INT1_LATCH__EN | INT1_LATCH_INT_EN |
| `field_description` | 0.0586 | 1.0 | 1 – INT1 pin level held until interrupt status is cleared.<br>0 – INT1 pin indicates interrupt pulse is width 50 μs. | 1 – INT1 level held until interrupt status cleared; 0 – INT1 is a 50 μs pulse. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 4: `INT_ANYRD_2CLEAR`, bits 4:4**

Location: `registers[5].field_parts[0].bit_field[3]`; datasheet source: PDF p.38.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | INT_ANYRD_2CLEAR | INT_ANYRD_2CLEAR |
| `field_description` | 0.0586 | 1.0 | 1 – Interrupt status in INT_STATUS is cleared (set to 0) if any read operation is performed.<br>0 – Interrupt status in INT_STATUS is cleared (set to 0) only by reading INT_STATUS register.<br>This bit only affects the interrupt status bits that are contained in the register INT_STATUS, and the corresponding hardware interrupt.<br>This bit does not affect the interrupt status bits that are contained in registers INT_STATUS_1, INT_STATUS_2, INT_STATUS_3, and the corresponding hardware interrupt. | 1 – INT_STATUS bits cleared by any read operation; 0 – cleared only by reading INT_STATUS register. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 5: `ACTL_FSYNC`, bits 3:3**

Location: `registers[5].field_parts[0].bit_field[4]`; datasheet source: PDF p.38.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACTL_FSYNC | ACTL_FSYNC |
| `field_description` | 0.0586 | 1.0 | 1 – The logic level for the FSYNC pin as an interrupt to the ICM-20948 is active low.<br>0 – The logic level for the FSYNC pin as an interrupt to the ICM-20948 is active high. | 1 – FSYNC active low for interrupt; 0 – FSYNC active high. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 6: `FSYNC_INT_MODE_EN`, bits 2:2**

Location: `registers[5].field_parts[0].bit_field[5]`; datasheet source: PDF p.38.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | FSYNC_INT_MODE_EN | FSYNC_INT_MODE_EN |
| `field_description` | 0.0586 | 1.0 | 1 – This enables the FSYNC pin to be used as an interrupt. A transition to the active level described by the ACTL_FSYNC bit will cause an interrupt. The status of the interrupt is read in the I²C Master Status register PASS_THROUGH bit.<br>0 – This disables the FSYNC pin from causing an interrupt. | 1 – Enables FSYNC to be used as interrupt (status read in I2C_MST_STATUS PASS_THROUGH bit). 0 – FSYNC disabled as interrupt. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 7: `BYPASS_EN`, bits 1:1**

Location: `registers[5].field_parts[0].bit_field[6]`; datasheet source: PDF p.38.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | BYPASS_EN | BYPASS_EN |
| `field_description` | 0.0586 | 1.0 | When asserted, the I2C_MASTER interface pins (ES_CL and ES_DA) will go into 'bypass mode' when the I²C master interface is disabled. | When asserted and I²C_MASTER disabled, ES_CL and ES_DA go into bypass mode (connect primary to auxiliary bus). |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 8: `reserved/fixed`, bits 0:0**

Location: `registers[5].field_parts[0].bit_field[7]`; datasheet source: PDF p.38.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ∅ | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | True |
| `type_write_read` | 0.0583 | 1.0 | ∅ | ∅ |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(0.790279, 0.790279, 0.790279, 0.790279, 0.790279, 0.790279, 1.000000, 1.000000) = **0.842709**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT_PIN_CFG | INT_PIN_CFG |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x0F","decimal":15,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x0F","decimal":"15","bank":"0","page":"","description":"User Bank 0 register address"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for INT_PIN_CFG (PDF p.38). | Interrupt pin configuration and bypass enable |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R/W | R/W |
| `bit_field` | 0.3129 | 0.842709 | datasheet bit-field set (8 exact ranges) | matched exact ranges (8); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.842709)/1.0000 = 0.950784/1.0000 = **0.950784**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.950784) = **0.950784**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT_PIN_CFG | INT_PIN_CFG |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x0F","decimal":15,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x0F","decimal":"15","bank":"0","page":"","description":"User Bank 0 register address"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register INT_PIN_CFG; see PDF p.38. | Configures INT pin behavior and bypass/FSYNC interrupt modes. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R/W | R/W |
| `field_parts` | 0.2987 | 0.950784 | corresponding datasheet field-part collection (PDF p.38) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.950784 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 0.985399/1.0001 = **0.985301**.

## Extracted logical register 7: `INT_ENABLE`

Extraction location: `registers[6]`; truth association: `bank0/0x10`.
Associated physical location: `bank0/0x10`; datasheet source: PDF p.39.

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_ENABLE`

**Datasheet bit field 1: `REG_WOF_EN`, bits 7:7**

Location: `registers[6].field_parts[0].bit_field[0]`; datasheet source: PDF p.39.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | REG_WOF_EN | REG_WOF_EN |
| `field_description` | 0.0586 | 1.0 | 1 – Enable wake on FSYNC interrupt.<br>0 – Function is disabled. | 1 – Enable wake on FSYNC interrupt propagation. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 2: `reserved/fixed`, bits 6:4**

Location: `registers[6].field_parts[0].bit_field` has no entry for the exact datasheet range; datasheet source: PDF p.39.
Judgment: C<1 fields: name_or_parameter (entire datasheet bit field missing); field_description (entire datasheet bit field missing); bit_start (entire datasheet bit field missing); bit_end (entire datasheet bit field missing); bit_width (entire datasheet bit field missing); values (entire datasheet bit field missing); is_reserved (entire datasheet bit field missing); type_write_read (entire datasheet bit field missing).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | ∅ | MISSING |
| `field_description` | 0.0586 | 0.0 | Reserved. | MISSING |
| `bit_start` | 0.2594 | 0.0 | 4 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 3 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | true | MISSING |
| `type_write_read` | 0.0583 | 0.0 | ∅ | MISSING |

Q_BF = (0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999 = 0.000000/0.9999 = **0.000000**.

**Datasheet bit field 3: `WOM_INT_EN`, bits 3:3**

Location: `registers[6].field_parts[0].bit_field[2]`; datasheet source: PDF p.39.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WOM_INT_EN | WOM_INT_EN |
| `field_description` | 0.0586 | 1.0 | 1 – Enable interrupt for wake on motion to propagate to interrupt pin 1.<br>0 – Function is disabled. | 1 – Enable Wake on Motion interrupt propagation to INT1. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 4: `PLL_RDY_EN`, bits 2:2**

Location: `registers[6].field_parts[0].bit_field[3]`; datasheet source: PDF p.39.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | PLL_RDY_EN | PLL_RDY_EN |
| `field_description` | 0.0586 | 1.0 | 1 – Enable PLL RDY interrupt (PLL RDY means PLL is running and in use as the clock source for the system) to propagate to interrupt pin 1.<br>0 – Function is disabled. | 1 – Enable PLL ready interrupt propagation to INT1. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 5: `DMP_INT1_EN`, bits 1:1**

Location: `registers[6].field_parts[0].bit_field[4]`; datasheet source: PDF p.39.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DMP_INT1_EN | DMP_INT1_EN |
| `field_description` | 0.0586 | 1.0 | 1 – Enable DMP interrupt to propagate to interrupt pin 1.<br>0 – Function is disabled. | 1 – Enable DMP interrupt propagation to INT1. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 6: `I2C_MST_INT_EN`, bits 0:0**

Location: `registers[6].field_parts[0].bit_field[5]`; datasheet source: PDF p.39.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_MST_INT_EN | I2C_MST_INT_EN |
| `field_description` | 0.0586 | 1.0 | 1 – Enable I²C master interrupt to propagate to interrupt pin 1.<br>0 – Function is disabled. | 1 – Enable I²C master interrupt propagation to INT1. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["0","1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Field-part aggregation**

bit_field correctness = mean(0.790279, 0.000000, 0.790279, 0.790279, 0.790279, 0.790279) = **0.658566**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT_ENABLE | INT_ENABLE |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x10","decimal":16,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x10","decimal":"16","bank":"0","page":"","description":"User Bank 0 register address"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for INT_ENABLE (PDF p.39). | Interrupt enable bits for INT1 |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R/W | R/W |
| `bit_field` | 0.3129 | 0.658566 | datasheet bit-field set (6 exact ranges) | matched exact ranges (6); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.658566)/1.0000 = 0.893165/1.0000 = **0.893165**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.893165) = **0.893165**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT_ENABLE | INT_ENABLE |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x10","decimal":16,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x10","decimal":"16","bank":"0","page":"","description":"User Bank 0 register address"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register INT_ENABLE; see PDF p.39. | Enables propagation of selected interrupt sources to INT1 pin. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R/W | R/W |
| `field_parts` | 0.2987 | 0.893165 | corresponding datasheet field-part collection (PDF p.39) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.893165 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 0.968188/1.0001 = **0.968092**.

#### Unmatched extracted bit-field entries

These extracted bit fields do not match a datasheet target by the exact `bit_start`/`bit_end` tuple. They are reported for auditability and receive no independent credit.

| Extraction path | Extracted content | Exact datasheet target | Source |
|---|---|---|---|
| `registers[6].field_parts[0].bit_field[1]` | name=-, bit_start=6, bit_end=4, bit_width=3 | bit_start=4, bit_end=6, reserved/fixed | PDF p.39 |

## Extracted logical register 8: `I2C_MST_STATUS`

Extraction location: `registers[7]`; truth association: `bank0/0x17`.
Associated physical location: `bank0/0x17`; datasheet source: PDF p.40.

### Bottom layer: bit fields, then field parts

#### Field part 1: `I2C_MST_STATUS`

**Datasheet bit field 1: `PASS_THROUGH`, bits 7:7**

Location: `registers[7].field_parts[0].bit_field[0]`; datasheet source: PDF p.40.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | PASS_THROUGH | PASS_THROUGH |
| `field_description` | 0.0586 | 1.0 | Status of FSYNC interrupt – used as a way to pass an external interrupt through this chip to the host. If enabled in the INT_PIN_CFG register by asserting bit FSYNC_INT_MODE_EN, this will cause an interrupt. A read of this register clears all status bits in this register. | Status of FSYNC interrupt / pass-through. Reading clears all bits in this register. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/C | R/C |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 2: `I2C_SLV4_DONE`, bits 6:6**

Location: `registers[7].field_parts[0].bit_field[1]`; datasheet source: PDF p.40.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_SLV4_DONE | I2C_SLV4_DONE |
| `field_description` | 0.0586 | 1.0 | Asserted when I²C slave 4's transfer is complete, will cause an interrupt if bit I2C_MST_INT_EN in the INT_ENABLE register is asserted, and if the SLV4_DONE_INT_EN bit is asserted in the I2C_SLV4_CTRL register. | Asserted when I²C slave 4 transfer complete; can generate I2C_MST_INT if enabled. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/C | R/C |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 3: `I2C_LOST_ARB`, bits 5:5**

Location: `registers[7].field_parts[0].bit_field[2]`; datasheet source: PDF p.40.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_LOST_ARB | I2C_LOST_ARB |
| `field_description` | 0.0586 | 1.0 | Asserted when I²C slave loses arbitration of the I²C bus, will cause an interrupt if bit I2C_MST_INT_EN in the INT_ENABLE register is asserted. | Asserted when I²C slave loses arbitration of I²C bus. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/C | R/C |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 4: `I2C_SLV4_NACK`, bits 4:4**

Location: `registers[7].field_parts[0].bit_field[3]`; datasheet source: PDF p.40.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_SLV4_NACK | I2C_SLV4_NACK |
| `field_description` | 0.0586 | 1.0 | Asserted when slave 4 receives a NACK, will cause an interrupt if bit I2C_MST_INT_EN in the INT_ENABLE register is asserted. | Asserted when slave 4 receives NACK. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/C | R/C |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 5: `I2C_SLV3_NACK`, bits 3:3**

Location: `registers[7].field_parts[0].bit_field[4]`; datasheet source: PDF p.40.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_SLV3_NACK | I2C_SLV3_NACK |
| `field_description` | 0.0586 | 1.0 | Asserted when slave 3 receives a NACK, will cause an interrupt if bit I2C_MST_INT_EN in the INT_ENABLE register is asserted. | Asserted when slave 3 receives NACK. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/C | R/C |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 6: `I2C_SLV2_NACK`, bits 2:2**

Location: `registers[7].field_parts[0].bit_field[5]`; datasheet source: PDF p.40.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_SLV2_NACK | I2C_SLV2_NACK |
| `field_description` | 0.0586 | 1.0 | Asserted when slave 2 receives a NACK, will cause an interrupt if bit I2C_MST_INT_EN in the INT_ENABLE register is asserted. | Asserted when slave 2 receives NACK. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/C | R/C |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 7: `I2C_SLV1_NACK`, bits 1:1**

Location: `registers[7].field_parts[0].bit_field[6]`; datasheet source: PDF p.40.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_SLV1_NACK | I2C_SLV1_NACK |
| `field_description` | 0.0586 | 1.0 | Asserted when slave 1 receives a NACK, will cause an interrupt if bit I2C_MST_INT_EN in the INT_ENABLE register is asserted. | Asserted when slave 1 receives NACK. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/C | R/C |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 8: `I2C_SLV0_NACK`, bits 0:0**

Location: `registers[7].field_parts[0].bit_field[7]`; datasheet source: PDF p.40.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_SLV0_NACK | I2C_SLV0_NACK |
| `field_description` | 0.0586 | 1.0 | Asserted when slave 0 receives a NACK, will cause an interrupt if bit I2C_MST_INT_EN in the INT_ENABLE register is asserted. | Asserted when slave 0 receives NACK. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/C | R/C |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | I2C_MST_STATUS | I2C_MST_STATUS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x17","decimal":23,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x17","decimal":"23","bank":"0","page":"","description":"User Bank 0 register address"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for I2C_MST_STATUS (PDF p.40). | I²C master interface status flags (read clears) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R/C | R/C |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (8 exact ranges) | matched exact ranges (8); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: C<1 fields: type_write_read (objective access-type mismatch).

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | I2C_MST_STATUS | I2C_MST_STATUS |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x17","decimal":23,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x17","decimal":"23","bank":"0","page":"","description":"User Bank 0 register address"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register I2C_MST_STATUS; see PDF p.40. | I²C master and pass-through status flags; read-to-clear. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 0.000000 | R/C | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.40) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×0.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 0.941100/1.0001 = **0.941006**.

## Extracted logical register 9: `INT_STATUS`

Extraction location: `registers[8]`; truth association: `bank0/0x19`.
Associated physical location: `bank0/0x19`; datasheet source: PDF p.40.

### Bottom layer: bit fields, then field parts

#### Field part 1: `INT_STATUS`

**Datasheet bit field 1: `reserved/fixed`, bits 7:4**

Location: `registers[8].field_parts[0].bit_field[4]`; datasheet source: PDF p.40.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ∅ | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | True |
| `type_write_read` | 0.0583 | 1.0 | ∅ | ∅ |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 2: `WOM_INT`, bits 3:3**

Location: `registers[8].field_parts[0].bit_field[0]`; datasheet source: PDF p.40.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | WOM_INT | WOM_INT |
| `field_description` | 0.0586 | 1.0 | 1 – Wake on motion interrupt occurred. | 1 – Wake on Motion interrupt occurred. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/C | R/C |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 3: `PLL_RDY_INT`, bits 2:2**

Location: `registers[8].field_parts[0].bit_field[1]`; datasheet source: PDF p.40.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | PLL_RDY_INT | PLL_RDY_INT |
| `field_description` | 0.0586 | 1.0 | 1 – Indicates that the PLL has been enabled and is ready (delay of 4 ms ensures lock). | 1 – PLL has been enabled and is ready (after ~4 ms lock delay). |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/C | R/C |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 4: `DMP_INT1`, bits 1:1**

Location: `registers[8].field_parts[0].bit_field[2]`; datasheet source: PDF p.40.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DMP_INT1 | DMP_INT1 |
| `field_description` | 0.0586 | 1.0 | 1 – Indicates the DMP has generated INT1 interrupt. | 1 – DMP generated INT1 interrupt. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/C | R/C |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Datasheet bit field 5: `I2C_MST_INT`, bits 0:0**

Location: `registers[8].field_parts[0].bit_field[3]`; datasheet source: PDF p.40.
Judgment: C<1 fields: values (datasheet value codes missing or incorrect).

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | I2C_MST_INT | I2C_MST_INT |
| `field_description` | 0.0586 | 1.0 | 1 – Indicates I²C master has generated an interrupt. | 1 – I²C master generated an interrupt. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | ["1"] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/C | R/C |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.790200/0.9999 = **0.790279**.

**Field-part aggregation**

bit_field correctness = mean(1.000000, 0.790279, 0.790279, 0.790279, 0.790279) = **0.832223**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | INT_STATUS | INT_STATUS |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x19","decimal":25,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x19","decimal":"25","bank":"0","page":"","description":"User Bank 0 register address"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for INT_STATUS (PDF p.40). | Interrupt status bits read/clear |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R/C | R/C |
| `bit_field` | 0.3129 | 0.832223 | datasheet bit-field set (5 exact ranges) | matched exact ranges (5); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.832223)/1.0000 = 0.947503/1.0000 = **0.947503**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.947503) = **0.947503**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | INT_STATUS | INT_STATUS |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x19","decimal":25,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x19","decimal":"25","bank":"0","page":"","description":"User Bank 0 register address"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register INT_STATUS; see PDF p.40. | Interrupt status flags (read/clear) indicating sources like WOM, PLL ready, DMP and I2C master interrupts. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R/C | R/C |
| `field_parts` | 0.2987 | 0.947503 | corresponding datasheet field-part collection (PDF p.40) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.947503 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 0.984419/1.0001 = **0.984321**.

## Extracted logical register 10: `DELAY_TIMEH`

Extraction location: `registers[9]`; truth association: `bank0/0x28`.
Associated physical location: `bank0/0x28`; datasheet source: PDF p.41.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DELAY_TIMEH`

**Datasheet bit field 1: `DELAY_TIMEH[7:0]`, bits 7:0**

Location: `registers[9].field_parts[0].bit_field[0]`; datasheet source: PDF p.41.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DELAY_TIMEH[7:0] | DELAY_TIMEH[7:0] |
| `field_description` | 0.0586 | 1.0 | High-byte of delay time between FSYNC event and the 1st gyro ODR event (after the FSYNC event).<br>Reading DELAY_TIMEH will lock DELAY_TIMEH and DELAY_TIMEL from the next update. Reading DELAY_TIMEL will unlock DELAY_TIMEH and DELAY_TIMEL to take the next update due to an FSYNC event. | High-byte of delay time between FSYNC event and the 1st gyro ODR event. Reading DELAY_TIMEH locks DELAY_TIMEH and DELAY_TIMEL from next update. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | DELAY_TIMEH | DELAY_TIMEH |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x28","decimal":40,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x28","decimal":"40","bank":"0","page":"","description":"User Bank 0 register address"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for DELAY_TIMEH (PDF p.41). | High byte of FSYNC-to-ODR delay (locks when read) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | DELAY_TIMEH | DELAY_TIMEH |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x28","decimal":40,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x28","decimal":"40","bank":"0","page":"","description":"User Bank 0 register address"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register DELAY_TIMEH; see PDF p.41. | High byte of delay time between FSYNC event and the first gyro ODR event; reading locks the pair until DELAY_TIMEL is read. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.41) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 11: `DELAY_TIMEL`

Extraction location: `registers[10]`; truth association: `bank0/0x29`.
Associated physical location: `bank0/0x29`; datasheet source: PDF p.42.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DELAY_TIMEL`

**Datasheet bit field 1: `DELAY_TIMEL[7:0]`, bits 7:0**

Location: `registers[10].field_parts[0].bit_field[0]`; datasheet source: PDF p.42.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | DELAY_TIMEL[7:0] | DELAY_TIMEL[7:0] |
| `field_description` | 0.0586 | 1.0 | Low-byte of delay time between FSYNC event and the 1st gyro ODR event (after the FSYNC event).<br>Reading DELAY_TIMEH will lock DELAY_TIMEH and DELAY_TIMEL from the next update. Reading DELAY_TIMEL will unlock DELAY_TIMEH and DELAY_TIMEL to take the next update due to an FSYNC event.<br>Delay time in μs = (DELAY_TIMEH * 256 + DELAY_TIMEL) * 0.9645 | Low-byte of delay time between FSYNC event and the 1st gyro ODR event. Delay (μs) = (DELAY_TIMEH*256 + DELAY_TIMEL) * 0.9645 |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | DELAY_TIMEL | DELAY_TIMEL |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x29","decimal":41,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x29","decimal":"41","bank":"0","page":"","description":"User Bank 0 register address"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for DELAY_TIMEL (PDF p.42). | Low byte of FSYNC-to-ODR delay (reading unlocks the lock) |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | DELAY_TIMEL | DELAY_TIMEL |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x29","decimal":41,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x29","decimal":"41","bank":"0","page":"","description":"User Bank 0 register address"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register DELAY_TIMEL; see PDF p.42. | Low byte of delay time between FSYNC event and first gyro ODR event; unlocks locked DELAY_TIMEH/DELAY_TIMEL and provides conversion formula. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.42) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 12: `ACCEL_XOUT_H`

Extraction location: `registers[11]`; truth association: `bank0/0x2D`.
Associated physical location: `bank0/0x2D`; datasheet source: PDF p.42.

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACCEL_XOUT_H`

**Datasheet bit field 1: `ACCEL_XOUT_H[7:0]`, bits 7:0**

Location: `registers[11].field_parts[0].bit_field[0]`; datasheet source: PDF p.42.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_XOUT_H[7:0] | ACCEL_XOUT_H[7:0] |
| `field_description` | 0.0586 | 1.0 | High Byte of Accelerometer X-axis data. | High Byte of Accelerometer X-axis data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_XOUT_H | ACCEL_XOUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2D","decimal":45,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x2D","decimal":"45","bank":"0","page":"","description":"Accelerometer X high byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for ACCEL_XOUT_H (PDF p.42). | High byte of accelerometer X-axis data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_XOUT_H | ACCEL_XOUT_H |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x2D","decimal":45,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x2D","decimal":"45","bank":"0","page":"","description":"User Bank 0 register address — accelerometer X high byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register ACCEL_XOUT_H; see PDF p.42. | High byte of accelerometer X-axis sample (16-bit, two's complement). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.42) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 13: `ACCEL_XOUT_L`

Extraction location: `registers[12]`; truth association: `bank0/0x2E`.
Associated physical location: `bank0/0x2E`; datasheet source: PDF p.42.

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACCEL_XOUT_L`

**Datasheet bit field 1: `ACCEL_XOUT_L[7:0]`, bits 7:0**

Location: `registers[12].field_parts[0].bit_field[0]`; datasheet source: PDF p.42.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_XOUT_L[7:0] | ACCEL_XOUT_L[7:0] |
| `field_description` | 0.0586 | 1.0 | Low Byte of Accelerometer X-axis data.<br>To convert the output of the accelerometer to acceleration measurement use the formula below:<br>X_acceleration = ACCEL_XOUT/Accel_Sensitivity | Low Byte of Accelerometer X-axis data. To convert to acceleration: X_acceleration = ACCEL_XOUT/Accel_Sensitivity. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_XOUT_L | ACCEL_XOUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2E","decimal":46,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x2E","decimal":"46","bank":"0","page":"","description":"Accelerometer X low byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for ACCEL_XOUT_L (PDF p.42). | Low byte of accelerometer X-axis data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_XOUT_L | ACCEL_XOUT_L |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x2E","decimal":46,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x2E","decimal":"46","bank":"0","page":"","description":"User Bank 0 register address — accelerometer X low byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register ACCEL_XOUT_L; see PDF p.42. | Low byte of accelerometer X-axis sample. Conversion: X_acceleration = ACCEL_XOUT/Accel_Sensitivity. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.42) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 14: `ACCEL_YOUT_H`

Extraction location: `registers[13]`; truth association: `bank0/0x2F`.
Associated physical location: `bank0/0x2F`; datasheet source: PDF p.42.

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACCEL_YOUT_H`

**Datasheet bit field 1: `ACCEL_YOUT_H[7:0]`, bits 7:0**

Location: `registers[13].field_parts[0].bit_field[0]`; datasheet source: PDF p.42.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_YOUT_H[7:0] | ACCEL_YOUT_H[7:0] |
| `field_description` | 0.0586 | 1.0 | High Byte of Accelerometer Y-axis data. | High Byte of Accelerometer Y-axis data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_YOUT_H | ACCEL_YOUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x2F","decimal":47,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x2F","decimal":"47","bank":"0","page":"","description":"Accelerometer Y high byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for ACCEL_YOUT_H (PDF p.42). | High byte of accelerometer Y-axis data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_YOUT_H | ACCEL_YOUT_H |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x2F","decimal":47,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x2F","decimal":"47","bank":"0","page":"","description":"User Bank 0 register address — accelerometer Y high byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register ACCEL_YOUT_H; see PDF p.42. | High byte of accelerometer Y-axis sample (16-bit). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.42) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 15: `ACCEL_YOUT_L`

Extraction location: `registers[14]`; truth association: `bank0/0x30`.
Associated physical location: `bank0/0x30`; datasheet source: PDF p.43.

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACCEL_YOUT_L`

**Datasheet bit field 1: `ACCEL_YOUT_L[7:0]`, bits 7:0**

Location: `registers[14].field_parts[0].bit_field[0]`; datasheet source: PDF p.43.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_YOUT_L[7:0] | ACCEL_YOUT_L[7:0] |
| `field_description` | 0.0586 | 1.0 | Low Byte of Accelerometer Y-axis data.<br>To convert the output of the accelerometer to acceleration measurement use the formula below:<br>Y_acceleration = ACCEL_YOUT/Accel_Sensitivity | Low Byte of Accelerometer Y-axis data. To convert: Y_acceleration = ACCEL_YOUT/Accel_Sensitivity. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_YOUT_L | ACCEL_YOUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x30","decimal":48,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x30","decimal":"48","bank":"0","page":"","description":"Accelerometer Y low byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for ACCEL_YOUT_L (PDF p.43). | Low byte of accelerometer Y-axis data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_YOUT_L | ACCEL_YOUT_L |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x30","decimal":48,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x30","decimal":"48","bank":"0","page":"","description":"User Bank 0 register address — accelerometer Y low byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register ACCEL_YOUT_L; see PDF p.43. | Low byte of accelerometer Y-axis sample. Conversion: Y_acceleration = ACCEL_YOUT/Accel_Sensitivity. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.43) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 16: `ACCEL_ZOUT_H`

Extraction location: `registers[15]`; truth association: `bank0/0x31`.
Associated physical location: `bank0/0x31`; datasheet source: PDF p.43.

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACCEL_ZOUT_H`

**Datasheet bit field 1: `ACCEL_ZOUT_H[7:0]`, bits 7:0**

Location: `registers[15].field_parts[0].bit_field[0]`; datasheet source: PDF p.43.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_ZOUT_H[7:0] | ACCEL_ZOUT_H[7:0] |
| `field_description` | 0.0586 | 1.0 | High Byte of Accelerometer Z-axis data. | High Byte of Accelerometer Z-axis data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_ZOUT_H | ACCEL_ZOUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x31","decimal":49,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x31","decimal":"49","bank":"0","page":"","description":"Accelerometer Z high byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for ACCEL_ZOUT_H (PDF p.43). | High byte of accelerometer Z-axis data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_ZOUT_H | ACCEL_ZOUT_H |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x31","decimal":49,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x31","decimal":"49","bank":"0","page":"","description":"User Bank 0 register address — accelerometer Z high byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register ACCEL_ZOUT_H; see PDF p.43. | High byte of accelerometer Z-axis sample (16-bit). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.43) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 17: `ACCEL_ZOUT_L`

Extraction location: `registers[16]`; truth association: `bank0/0x32`.
Associated physical location: `bank0/0x32`; datasheet source: PDF p.43.

### Bottom layer: bit fields, then field parts

#### Field part 1: `ACCEL_ZOUT_L`

**Datasheet bit field 1: `ACCEL_ZOUT_L[7:0]`, bits 7:0**

Location: `registers[16].field_parts[0].bit_field[0]`; datasheet source: PDF p.43.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ACCEL_ZOUT_L[7:0] | ACCEL_ZOUT_L[7:0] |
| `field_description` | 0.0586 | 1.0 | Low Byte of Accelerometer Z-axis data.<br>To convert the output of the accelerometer to acceleration measurement use the formula below:<br>Z_acceleration = ACCEL_ZOUT/Accel_Sensitivity | Low Byte of Accelerometer Z-axis data. To convert: Z_acceleration = ACCEL_ZOUT/Accel_Sensitivity. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | ACCEL_ZOUT_L | ACCEL_ZOUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x32","decimal":50,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x32","decimal":"50","bank":"0","page":"","description":"Accelerometer Z low byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for ACCEL_ZOUT_L (PDF p.43). | Low byte of accelerometer Z-axis data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | ACCEL_ZOUT_L | ACCEL_ZOUT_L |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x32","decimal":50,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x32","decimal":"50","bank":"0","page":"","description":"User Bank 0 register address — accelerometer Z low byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register ACCEL_ZOUT_L; see PDF p.43. | Low byte of accelerometer Z-axis sample. Conversion: Z_acceleration = ACCEL_ZOUT/Accel_Sensitivity. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.43) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 18: `GYRO_XOUT_H`

Extraction location: `registers[17]`; truth association: `bank0/0x33`.
Associated physical location: `bank0/0x33`; datasheet source: PDF p.43.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_XOUT_H`

**Datasheet bit field 1: `GYRO_XOUT_H[7:0]`, bits 7:0**

Location: `registers[17].field_parts[0].bit_field[0]`; datasheet source: PDF p.43.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_XOUT_H[7:0] | GYRO_XOUT_H[7:0] |
| `field_description` | 0.0586 | 1.0 | High Byte of Gyroscope X-axis data. | High Byte of Gyroscope X-axis data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | GYRO_XOUT_H | GYRO_XOUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x33","decimal":51,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x33","decimal":"51","bank":"0","page":"","description":"Gyroscope X high byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for GYRO_XOUT_H (PDF p.43). | High byte of gyroscope X-axis data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | GYRO_XOUT_H | GYRO_XOUT_H |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x33","decimal":51,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x33","decimal":"51","bank":"0","page":"","description":"User Bank 0 register address — gyroscope X high byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register GYRO_XOUT_H; see PDF p.43. | High byte of gyroscope X-axis data (16-bit two's complement). |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.43) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 19: `GYRO_XOUT_L`

Extraction location: `registers[18]`; truth association: `bank0/0x34`.
Associated physical location: `bank0/0x34`; datasheet source: PDF p.44.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_XOUT_L`

**Datasheet bit field 1: `GYRO_XOUT_L[7:0]`, bits 7:0**

Location: `registers[18].field_parts[0].bit_field[0]`; datasheet source: PDF p.44.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_XOUT_L[7:0] | GYRO_XOUT_L[7:0] |
| `field_description` | 0.0586 | 1.0 | Low Byte of Gyroscope X-axis data.<br>To convert the output of the gyroscope to angular rate measurement use the formula below:<br>X_angular_rate = GYRO_XOUT/Gyro_Sensitivity | Low Byte of Gyroscope X-axis data. To convert: X_angular_rate = GYRO_XOUT/Gyro_Sensitivity. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | GYRO_XOUT_L | GYRO_XOUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x34","decimal":52,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x34","decimal":"52","bank":"0","page":"","description":"Gyroscope X low byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for GYRO_XOUT_L (PDF p.44). | Low byte of gyroscope X-axis data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | GYRO_XOUT_L | GYRO_XOUT_L |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x34","decimal":52,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x34","decimal":"52","bank":"0","page":"","description":"User Bank 0 register address — gyroscope X low byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register GYRO_XOUT_L; see PDF p.44. | Low byte of gyroscope X-axis; conversion: X_angular_rate = GYRO_XOUT/Gyro_Sensitivity. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.44) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 20: `GYRO_YOUT_H`

Extraction location: `registers[19]`; truth association: `bank0/0x35`.
Associated physical location: `bank0/0x35`; datasheet source: PDF p.44.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_YOUT_H`

**Datasheet bit field 1: `GYRO_YOUT_H[7:0]`, bits 7:0**

Location: `registers[19].field_parts[0].bit_field[0]`; datasheet source: PDF p.44.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_YOUT_H[7:0] | GYRO_YOUT_H[7:0] |
| `field_description` | 0.0586 | 1.0 | High Byte of Gyroscope Y-axis data. | High Byte of Gyroscope Y-axis data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | GYRO_YOUT_H | GYRO_YOUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x35","decimal":53,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x35","decimal":"53","bank":"0","page":"","description":"Gyroscope Y high byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for GYRO_YOUT_H (PDF p.44). | High byte of gyroscope Y-axis data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | GYRO_YOUT_H | GYRO_YOUT_H |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x35","decimal":53,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x35","decimal":"53","bank":"0","page":"","description":"User Bank 0 register address — gyroscope Y high byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register GYRO_YOUT_H; see PDF p.44. | High byte of gyroscope Y-axis data. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.44) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 21: `GYRO_YOUT_L`

Extraction location: `registers[20]`; truth association: `bank0/0x36`.
Associated physical location: `bank0/0x36`; datasheet source: PDF p.44.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_YOUT_L`

**Datasheet bit field 1: `GYRO_YOUT_L[7:0]`, bits 7:0**

Location: `registers[20].field_parts[0].bit_field[0]`; datasheet source: PDF p.44.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_YOUT_L[7:0] | GYRO_YOUT_L[7:0] |
| `field_description` | 0.0586 | 1.0 | Low Byte of Gyroscope Y-axis data.<br>To convert the output of the gyroscope to angular rate measurement use the formula below:<br>Y_angular_rate = GYRO_YOUT/Gyro_Sensitivity | Low Byte of Gyroscope Y-axis data. To convert: Y_angular_rate = GYRO_YOUT/Gyro_Sensitivity. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | GYRO_YOUT_L | GYRO_YOUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x36","decimal":54,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x36","decimal":"54","bank":"0","page":"","description":"Gyroscope Y low byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for GYRO_YOUT_L (PDF p.44). | Low byte of gyroscope Y-axis data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | GYRO_YOUT_L | GYRO_YOUT_L |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x36","decimal":54,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x36","decimal":"54","bank":"0","page":"","description":"User Bank 0 register address — gyroscope Y low byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register GYRO_YOUT_L; see PDF p.44. | Low byte of gyroscope Y-axis; conversion: Y_angular_rate = GYRO_YOUT/Gyro_Sensitivity. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.44) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 22: `GYRO_ZOUT_H`

Extraction location: `registers[21]`; truth association: `bank0/0x37`.
Associated physical location: `bank0/0x37`; datasheet source: PDF p.44.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_ZOUT_H`

**Datasheet bit field 1: `GYRO_ZOUT_H[7:0]`, bits 7:0**

Location: `registers[21].field_parts[0].bit_field[0]`; datasheet source: PDF p.44.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_ZOUT_H[7:0] | GYRO_ZOUT_H[7:0] |
| `field_description` | 0.0586 | 1.0 | High Byte of Gyroscope Z-axis data. | High Byte of Gyroscope Z-axis data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | GYRO_ZOUT_H | GYRO_ZOUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x37","decimal":55,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x37","decimal":"55","bank":"0","page":"","description":"Gyroscope Z high byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for GYRO_ZOUT_H (PDF p.44). | High byte of gyroscope Z-axis data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | GYRO_ZOUT_H | GYRO_ZOUT_H |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x37","decimal":55,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x37","decimal":"55","bank":"0","page":"","description":"User Bank 0 register address — gyroscope Z high byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register GYRO_ZOUT_H; see PDF p.44. | High byte of gyroscope Z-axis data. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.44) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 23: `GYRO_ZOUT_L`

Extraction location: `registers[22]`; truth association: `bank0/0x38`.
Associated physical location: `bank0/0x38`; datasheet source: PDF p.45.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GYRO_ZOUT_L`

**Datasheet bit field 1: `GYRO_ZOUT_L[7:0]`, bits 7:0**

Location: `registers[22].field_parts[0].bit_field[0]`; datasheet source: PDF p.45.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | GYRO_ZOUT_L[7:0] | GYRO_ZOUT_L[7:0] |
| `field_description` | 0.0586 | 1.0 | Low Byte of Gyroscope Z-axis data.<br>To convert the output of the gyroscope to angular rate measurement use the formula below:<br>Z_angular_rate = GYRO_ZOUT/Gyro_Sensitivity | Low Byte of Gyroscope Z-axis data. To convert: Z_angular_rate = GYRO_ZOUT/Gyro_Sensitivity. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | GYRO_ZOUT_L | GYRO_ZOUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x38","decimal":56,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x38","decimal":"56","bank":"0","page":"","description":"Gyroscope Z low byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for GYRO_ZOUT_L (PDF p.45). | Low byte of gyroscope Z-axis data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | GYRO_ZOUT_L | GYRO_ZOUT_L |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x38","decimal":56,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x38","decimal":"56","bank":"0","page":"","description":"User Bank 0 register address — gyroscope Z low byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register GYRO_ZOUT_L; see PDF p.45. | Low byte of gyroscope Z-axis; conversion: Z_angular_rate = GYRO_ZOUT/Gyro_Sensitivity. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.45) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 24: `TEMP_OUT_H`

Extraction location: `registers[23]`; truth association: `bank0/0x39`.
Associated physical location: `bank0/0x39`; datasheet source: PDF p.45.

### Bottom layer: bit fields, then field parts

#### Field part 1: `TEMP_OUT_H`

**Datasheet bit field 1: `TEMP_OUT_H[7:0]`, bits 7:0**

Location: `registers[23].field_parts[0].bit_field[0]`; datasheet source: PDF p.45.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_OUT_H[7:0] | TEMP_OUT_H[7:0] |
| `field_description` | 0.0586 | 1.0 | High Byte of Temp sensor data. | High Byte of temperature sensor data. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TEMP_OUT_H | TEMP_OUT_H |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x39","decimal":57,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x39","decimal":"57","bank":"0","page":"","description":"Temperature high byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for TEMP_OUT_H (PDF p.45). | High byte of temperature sensor data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TEMP_OUT_H | TEMP_OUT_H |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x39","decimal":57,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x39","decimal":"57","bank":"0","page":"","description":"User Bank 0 register address — temperature high byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register TEMP_OUT_H; see PDF p.45. | High byte of on-chip temperature sensor reading. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.45) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 25: `TEMP_OUT_L`

Extraction location: `registers[24]`; truth association: `bank0/0x3A`.
Associated physical location: `bank0/0x3A`; datasheet source: PDF p.45.

### Bottom layer: bit fields, then field parts

#### Field part 1: `TEMP_OUT_L`

**Datasheet bit field 1: `TEMP_OUT_L[7:0]`, bits 7:0**

Location: `registers[24].field_parts[0].bit_field[0]`; datasheet source: PDF p.45.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TEMP_OUT_L[7:0] | TEMP_OUT_L[7:0] |
| `field_description` | 0.0586 | 1.0 | Low Byte of Temp sensor data.<br>To convert the output of the temperature sensor to degrees C use the following formula:<br>TEMP_degC = ((TEMP_OUT - RoomTemp_Offset)/Temp_Sensitivity) + 21degC | Low Byte of Temp sensor data. Convert to degrees C using documented formula. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | TEMP_OUT_L | TEMP_OUT_L |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x3A","decimal":58,"bank":"0","page":"","description":"Datasheet physical register location"} | {"hex":"0x3A","decimal":"58","bank":"0","page":"","description":"Temperature low byte"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for TEMP_OUT_L (PDF p.45). | Low byte of temperature sensor data |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R | R |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (1 exact ranges) | matched exact ranges (1); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | TEMP_OUT_L | TEMP_OUT_L |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x3A","decimal":58,"bank":"0","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x3A","decimal":"58","bank":"0","page":"","description":"User Bank 0 register address — temperature low byte"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register TEMP_OUT_L; see PDF p.45. | Low byte of on-chip temperature sensor reading. Conversion formula: TEMP_degC = ((TEMP_OUT - RoomTemp_Offset)/Temp_Sensitivity) + 21°C. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R | R |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.45) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## Extracted logical register 26: `FIFO_EN_1` (unmatched physical location)

Extraction location: `registers[25]`.
Extracted physical location: `bank1/0x42`.
The datasheet register with the same name is `bank0/0x66` (PDF p.52), but name matching cannot override the wrong physical bank/address. This entry is an extra (`x`) and is not scored against that differently located datasheet register.

### Extracted content retained for extra-entry audit

| Field | Extracted content |
|---|---|
| `name` | FIFO_EN_1 |
| `physical_address` | [{"hex":"0x42","decimal":"66","bank":"1","page":"","description":"User Bank 1 register address (FIFO enable group 1)"}] |
| `register_description` | Enable writing of selected external sensor slave data groups into FIFO. |
| `width_bits` | 8 |
| `type_write_read` | RW |
| `default_value` | 0x00 |
| `default_value_description` | ∅ |

| Field-part field | Extracted content |
|---|---|
| `register_name` | FIFO_EN_1 |
| `physical_address` | {"hex":"0x42","decimal":"66","bank":"1","page":"","description":"FIFO enable register (group 1)"} |
| `description` | Enable selected external slave data to be written to FIFO |
| `width_bits` | 8 |
| `type_write_read` | RW |

| Bit-field path | Name | Range | Width | Values | Reserved | Access | Description |
|---|---|---:|---:|---|---:|---|---|
| `registers[25].field_parts[0].bit_field[0]` | SLV_3_FIFO_EN | 3:3 | 1 | [] | False | RW | 1 – Write EXT_SENS_DATA associated with Slave 3 to FIFO at sample rate. |
| `registers[25].field_parts[0].bit_field[1]` | SLV_2_FIFO_EN | 2:2 | 1 | [] | False | RW | 1 – Write EXT_SENS_DATA associated with Slave 2 to FIFO at sample rate. |
| `registers[25].field_parts[0].bit_field[2]` | SLV_1_FIFO_EN | 1:1 | 1 | [] | False | RW | 1 – Write EXT_SENS_DATA associated with Slave 1 to FIFO at sample rate. |
| `registers[25].field_parts[0].bit_field[3]` | SLV_0_FIFO_EN | 0:0 | 1 | [] | False | RW | 1 – Write EXT_SENS_DATA associated with Slave 0 to FIFO at sample rate. |
| `registers[25].field_parts[0].bit_field[4]` | - | 4:7 | 4 | [] | True | ∅ | Reserved. |

## Extracted logical register 27: `FIFO_EN_2` (unmatched physical location)

Extraction location: `registers[26]`.
Extracted physical location: `bank1/0x43`.
The datasheet register with the same name is `bank0/0x67` (PDF p.52), but name matching cannot override the wrong physical bank/address. This entry is an extra (`x`) and is not scored against that differently located datasheet register.

### Extracted content retained for extra-entry audit

| Field | Extracted content |
|---|---|
| `name` | FIFO_EN_2 |
| `physical_address` | [{"hex":"0x43","decimal":"67","bank":"1","page":"","description":"User Bank 1 register address (FIFO enable group 2)"}] |
| `register_description` | Enable writing of accelerometer, gyro, and temperature data to FIFO. |
| `width_bits` | 8 |
| `type_write_read` | RW |
| `default_value` | 0x00 |
| `default_value_description` | ∅ |

| Field-part field | Extracted content |
|---|---|
| `register_name` | FIFO_EN_2 |
| `physical_address` | {"hex":"0x43","decimal":"67","bank":"1","page":"","description":"FIFO enable register (group 2)"} |
| `description` | Enable writing sensor data (accel/gyro/temp) into FIFO |
| `width_bits` | 8 |
| `type_write_read` | RW |

| Bit-field path | Name | Range | Width | Values | Reserved | Access | Description |
|---|---|---:|---:|---|---:|---|---|
| `registers[26].field_parts[0].bit_field[0]` | ACCEL_FIFO_EN | 4:4 | 1 | [] | False | RW | 1 – Write accelerometer X/Y/Z high/low bytes to FIFO at sample rate. |
| `registers[26].field_parts[0].bit_field[1]` | GYRO_Z_FIFO_EN | 3:3 | 1 | [] | False | RW | 1 – Write GYRO_ZOUT_H/L to FIFO at sample rate. |
| `registers[26].field_parts[0].bit_field[2]` | GYRO_Y_FIFO_EN | 2:2 | 1 | [] | False | RW | 1 – Write GYRO_YOUT_H/L to FIFO at sample rate. |
| `registers[26].field_parts[0].bit_field[3]` | GYRO_X_FIFO_EN | 1:1 | 1 | [] | False | RW | 1 – Write GYRO_XOUT_H/L to FIFO at sample rate. |
| `registers[26].field_parts[0].bit_field[4]` | TEMP_FIFO_EN | 0:0 | 1 | [] | False | RW | 1 – Write TEMP_OUT_H/L to FIFO at sample rate. |
| `registers[26].field_parts[0].bit_field[5]` | - | 5:7 | 3 | [] | True | ∅ | Reserved. |

## Extracted logical register 28: `FIFO_RST` (unmatched physical location)

Extraction location: `registers[27]`.
Extracted physical location: `bank1/0x44`.
The datasheet register with the same name is `bank0/0x68` (PDF p.53), but name matching cannot override the wrong physical bank/address. This entry is an extra (`x`) and is not scored against that differently located datasheet register.

### Extracted content retained for extra-entry audit

| Field | Extracted content |
|---|---|
| `name` | FIFO_RST |
| `physical_address` | [{"hex":"0x44","decimal":"68","bank":"1","page":"","description":"User Bank 1 register address (FIFO reset)"}] |
| `register_description` | Software FIFO reset. Assert to set FIFO size to 0; assert+deassert to reset FIFO. |
| `width_bits` | 8 |
| `type_write_read` | RW |
| `default_value` | 0x00 |
| `default_value_description` | ∅ |

| Field-part field | Extracted content |
|---|---|
| `register_name` | FIFO_RST |
| `physical_address` | {"hex":"0x44","decimal":"68","bank":"1","page":"","description":"FIFO reset control"} |
| `description` | Software FIFO reset control |
| `width_bits` | 8 |
| `type_write_read` | RW |

| Bit-field path | Name | Range | Width | Values | Reserved | Access | Description |
|---|---|---:|---:|---|---:|---|---|
| `registers[27].field_parts[0].bit_field[0]` | FIFO_RESET[4:0] | 0:4 | 5 | [] | False | RW | Software FIFO reset. Assert and hold to set FIFO size to 0. Assert and de-assert to reset FIFO. |
| `registers[27].field_parts[0].bit_field[1]` | - | 5:7 | 3 | [] | True | ∅ | Reserved. |

## Extracted logical register 29: `FIFO_MODE` (unmatched physical location)

Extraction location: `registers[28]`.
Extracted physical location: `bank1/0x45`.
The datasheet register with the same name is `bank0/0x69` (PDF p.53), but name matching cannot override the wrong physical bank/address. This entry is an extra (`x`) and is not scored against that differently located datasheet register.

### Extracted content retained for extra-entry audit

| Field | Extracted content |
|---|---|
| `name` | FIFO_MODE |
| `physical_address` | [{"hex":"0x45","decimal":"69","bank":"1","page":"","description":"User Bank 1 register address (FIFO mode)"}] |
| `register_description` | FIFO mode selection: Stream (overwrite oldest) or Snapshot (stop writing when full). |
| `width_bits` | 8 |
| `type_write_read` | RW |
| `default_value` | 0x00 |
| `default_value_description` | ∅ |

| Field-part field | Extracted content |
|---|---|
| `register_name` | FIFO_MODE |
| `physical_address` | {"hex":"0x45","decimal":"69","bank":"1","page":"","description":"FIFO mode select"} |
| `description` | FIFO operating mode (stream or snapshot) |
| `width_bits` | 8 |
| `type_write_read` | RW |

| Bit-field path | Name | Range | Width | Values | Reserved | Access | Description |
|---|---|---:|---:|---|---:|---|---|
| `registers[28].field_parts[0].bit_field[0]` | FIFO_MODE[4:0] | 0:4 | 5 | [{"value":"0","value_description":"Stream (wrap; overwrite oldest data when FIFO full)"},{"value":"1","value_description":"Snapshot (stop writing when FIFO full)"}] | False | RW | 0 – Stream (wrap). 1 – Snapshot (stop writing when full). |
| `registers[28].field_parts[0].bit_field[1]` | - | 5:7 | 3 | [] | True | ∅ | Reserved. |

## Extracted logical register 30: `FIFO_COUNTH` (unmatched physical location)

Extraction location: `registers[29]`.
Extracted physical location: `bank1/0x46`.
The datasheet register with the same name is `bank0/0x70` (PDF p.53), but name matching cannot override the wrong physical bank/address. This entry is an extra (`x`) and is not scored against that differently located datasheet register.

### Extracted content retained for extra-entry audit

| Field | Extracted content |
|---|---|
| `name` | FIFO_COUNTH |
| `physical_address` | [{"hex":"0x46","decimal":"70","bank":"1","page":"","description":"User Bank 1 register address (FIFO count high byte)"}] |
| `register_description` | High bits of FIFO byte count (FIFO_CNT[12:8]). Reading latches count for both FIFO_COUNTH and FIFO_COUNTL. |
| `width_bits` | 8 |
| `type_write_read` | R |
| `default_value` | 0x00 |
| `default_value_description` | ∅ |

| Field-part field | Extracted content |
|---|---|
| `register_name` | FIFO_COUNTH |
| `physical_address` | {"hex":"0x46","decimal":"70","bank":"1","page":"","description":"FIFO count high byte"} |
| `description` | High bits of FIFO count; read latches count |
| `width_bits` | 8 |
| `type_write_read` | R |

| Bit-field path | Name | Range | Width | Values | Reserved | Access | Description |
|---|---|---:|---:|---|---:|---|---|
| `registers[29].field_parts[0].bit_field[0]` | FIFO_CNT[12:8] | 0:4 | 5 | [] | False | R | High bits of number of written bytes in FIFO. Reading this latches FIFO count for readout. |
| `registers[29].field_parts[0].bit_field[1]` | - | 5:7 | 3 | [] | True | ∅ | Reserved. |

## Extracted logical register 31: `FIFO_COUNTL` (unmatched physical location)

Extraction location: `registers[30]`.
Extracted physical location: `bank1/0x47`.
The datasheet register with the same name is `bank0/0x71` (PDF p.53), but name matching cannot override the wrong physical bank/address. This entry is an extra (`x`) and is not scored against that differently located datasheet register.

### Extracted content retained for extra-entry audit

| Field | Extracted content |
|---|---|
| `name` | FIFO_COUNTL |
| `physical_address` | [{"hex":"0x47","decimal":"71","bank":"1","page":"","description":"User Bank 1 register address (FIFO count low byte)"}] |
| `register_description` | Low bits of FIFO byte count (FIFO_CNT[7:0]). |
| `width_bits` | 8 |
| `type_write_read` | R |
| `default_value` | 0x00 |
| `default_value_description` | ∅ |

| Field-part field | Extracted content |
|---|---|
| `register_name` | FIFO_COUNTL |
| `physical_address` | {"hex":"0x47","decimal":"71","bank":"1","page":"","description":"FIFO count low byte"} |
| `description` | Low bits of FIFO byte count |
| `width_bits` | 8 |
| `type_write_read` | R |

| Bit-field path | Name | Range | Width | Values | Reserved | Access | Description |
|---|---|---:|---:|---|---:|---|---|
| `registers[30].field_parts[0].bit_field[0]` | FIFO_CNT[7:0] | 0:7 | 8 | [] | False | R | Low bits of number of written bytes in FIFO. |

## Extracted logical register 32: `FIFO_R_W` (unmatched physical location)

Extraction location: `registers[31]`.
Extracted physical location: `bank1/0x48`.
The datasheet register with the same name is `bank0/0x72` (PDF p.54), but name matching cannot override the wrong physical bank/address. This entry is an extra (`x`) and is not scored against that differently located datasheet register.

### Extracted content retained for extra-entry audit

| Field | Extracted content |
|---|---|
| `name` | FIFO_R_W |
| `physical_address` | [{"hex":"0x48","decimal":"72","bank":"1","page":"","description":"User Bank 1 register address (FIFO read/write)"}] |
| `register_description` | Register used to read from/write to FIFO data stream (byte-wise). |
| `width_bits` | 8 |
| `type_write_read` | RW |
| `default_value` | 0x00 |
| `default_value_description` | ∅ |

| Field-part field | Extracted content |
|---|---|
| `register_name` | FIFO_R_W |
| `physical_address` | {"hex":"0x48","decimal":"72","bank":"1","page":"","description":"FIFO read/write data port"} |
| `description` | FIFO data read/write port |
| `width_bits` | 8 |
| `type_write_read` | RW |

| Bit-field path | Name | Range | Width | Values | Reserved | Access | Description |
|---|---|---:|---:|---|---:|---|---|
| `registers[31].field_parts[0].bit_field[0]` | FIFO_R_W[7:0] | 0:7 | 8 | [] | False | RW | Reading/writing this register reads/writes a byte from/to the FIFO. |

## Extracted logical register 33: `DATA_RDY_STATUS` (unmatched physical location)

Extraction location: `registers[32]`.
Extracted physical location: `bank1/0x74`.
The datasheet register with the same name is `bank0/0x74` (PDF p.54), but name matching cannot override the wrong physical bank/address. This entry is an extra (`x`) and is not scored against that differently located datasheet register.

### Extracted content retained for extra-entry audit

| Field | Extracted content |
|---|---|
| `name` | DATA_RDY_STATUS |
| `physical_address` | [{"hex":"0x74","decimal":"116","bank":"1","page":"","description":"User Bank 1 register address (data ready status)"}] |
| `register_description` | Status indicating Wake-on-FSYNC and raw data ready conditions; read/clear. |
| `width_bits` | 8 |
| `type_write_read` | R/C |
| `default_value` | 0x00 |
| `default_value_description` | ∅ |

| Field-part field | Extracted content |
|---|---|
| `register_name` | DATA_RDY_STATUS |
| `physical_address` | {"hex":"0x74","decimal":"116","bank":"1","page":"","description":"Data ready and WOF status"} |
| `description` | Wake on FSYNC and raw data ready status flags (cleared on read) |
| `width_bits` | 8 |
| `type_write_read` | R/C |

| Bit-field path | Name | Range | Width | Values | Reserved | Access | Description |
|---|---|---:|---:|---|---:|---|---|
| `registers[32].field_parts[0].bit_field[0]` | WOF_STATUS | 7:7 | 1 | [] | False | R/C | Wake on FSYNC interrupt status. Cleared on read. |
| `registers[32].field_parts[0].bit_field[1]` | RAW_DATA_RDY[3:0] | 0:3 | 4 | [] | False | R/C | Raw data ready flags indicating sensors have copied data to FIFO or SRAM; cleared on read. Only bit0 is relevant in single FIFO configuration. |
| `registers[32].field_parts[0].bit_field[2]` | - | 4:6 | 3 | [] | True | ∅ | Reserved. |

## Extracted logical register 34: `FIFO_CFG` (unmatched physical location)

Extraction location: `registers[33]`.
Extracted physical location: `bank1/0x76`.
The datasheet register with the same name is `bank0/0x76` (PDF p.54), but name matching cannot override the wrong physical bank/address. This entry is an extra (`x`) and is not scored against that differently located datasheet register.

### Extracted content retained for extra-entry audit

| Field | Extracted content |
|---|---|
| `name` | FIFO_CFG |
| `physical_address` | [{"hex":"0x76","decimal":"118","bank":"1","page":"","description":"User Bank 1 register address (FIFO configuration)"}] |
| `register_description` | FIFO configuration bit; indicates whether interrupt status per sensor is required. |
| `width_bits` | 8 |
| `type_write_read` | RW |
| `default_value` | 0x00 |
| `default_value_description` | ∅ |

| Field-part field | Extracted content |
|---|---|
| `register_name` | FIFO_CFG |
| `physical_address` | {"hex":"0x76","decimal":"118","bank":"1","page":"","description":"FIFO configuration control"} |
| `description` | FIFO configuration (interrupt behavior) |
| `width_bits` | 8 |
| `type_write_read` | RW |

| Bit-field path | Name | Range | Width | Values | Reserved | Access | Description |
|---|---|---:|---:|---|---:|---|---|
| `registers[33].field_parts[0].bit_field[0]` | FIFO_CFG | 0:0 | 1 | [{"value":"1","value_description":"Enable sensor interrupt status reporting for FIFO"}] | False | RW | Set to 1 if interrupt status for each sensor is required. |
| `registers[33].field_parts[0].bit_field[1]` | - | 1:7 | 7 | [] | True | ∅ | Reserved. |

## Extracted logical register 35: `REG_BANK_SEL`

Extraction location: `registers[34]`; truth association: `ALL/0x7F`.
Associated physical location: `ALL/0x7F`; datasheet source: PDF p.54.

### Bottom layer: bit fields, then field parts

#### Field part 1: `REG_BANK_SEL`

**Datasheet bit field 1: `reserved/fixed`, bits 7:6**

Location: `registers[34].field_parts[0].bit_field[2]`; datasheet source: PDF p.54.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ∅ | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | True |
| `type_write_read` | 0.0583 | 1.0 | ∅ | ∅ |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 2: `USER_BANK[1:0]`, bits 5:4**

Location: `registers[34].field_parts[0].bit_field[0]`; datasheet source: PDF p.54.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | USER_BANK[1:0] | USER_BANK[1:0] |
| `field_description` | 0.0586 | 1.0 | Use the following values in this bit-field to select a USER BANK.<br>0: Select USER BANK 0.<br>1: Select USER BANK 1.<br>2: Select USER BANK 2.<br>3: Select USER BANK 3. | Select USER BANK: 0=Bank0; 1=Bank1; 2=Bank2; 3=Bank3. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | ["0","1","2","3"] | [{"value":"0","value_description":"Select USER BANK 0"},{"value":"1","value_description":"Select USER BANK 1"},{"value":"2","value_description":"Select USER BANK 2"},{"value":"3","value_description":"Select USER BANK 3"}] |
| `is_reserved` | 0.0750 | 1.0 | false | False |
| `type_write_read` | 0.0583 | 1.0 | R/W | RW |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Datasheet bit field 3: `reserved/fixed`, bits 3:0**

Location: `registers[34].field_parts[0].bit_field[1]`; datasheet source: PDF p.54.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Scored field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ∅ | - |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | True |
| `type_write_read` | 0.0583 | 1.0 | ∅ | ∅ |

Q_BF = (0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999 = 0.999900/0.9999 = **1.000000**.

**Field-part aggregation**

bit_field correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | REG_BANK_SEL | REG_BANK_SEL |
| `physical_address` | 0.4688 | 1.000000 | {"hex":"0x7F","decimal":127,"bank":"ALL","page":"","description":"Datasheet physical register location"} | {"hex":"0x7F","decimal":"127","bank":"0","page":"","description":"Register bank select"} |
| `description` | 0.0693 | 1.000000 | Datasheet field definitions for REG_BANK_SEL (PDF p.54). | User bank selection for register addressing |
| `width_bits` | 0.0605 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.000000 | R/W | R/W |
| `bit_field` | 0.3129 | 1.000000 | datasheet bit-field set (3 exact ranges) | matched exact ranges (3); missing ranges receive zero |

Q_FP = (0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000 = 1.000000/1.0000 = **1.000000**.

### Extracted logical-register aggregation

field_parts correctness = mean(1.000000) = **1.000000**.
Judgment: all direct facts match; descriptions use the permitted semantic leniency.

| Logical-register field | Weight | C | Datasheet comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | REG_BANK_SEL | REG_BANK_SEL |
| `physical_address` | 0.4044 | 1.000000 | [{"hex":"0x7F","decimal":127,"bank":"ALL","page":"","description":"Datasheet physical register location"}] | [{"hex":"0x7F","decimal":"127","bank":"0","page":"","description":"Register used to select USER BANK (0..3)"}] |
| `register_description` | 0.0564 | 1.000000 | Datasheet register REG_BANK_SEL; see PDF p.54. | Selects the current USER BANK (0-3) for register access. |
| `width_bits` | 0.0590 | 1.000000 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.000000 | R/W | R/W |
| `field_parts` | 0.2987 | 1.000000 | corresponding datasheet field-part collection (PDF p.54) | one extracted field part |
| `default_value` | 0.0667 | 1.000000 | 0x00 | 0x00 |
| `default_value_description` | 0.0334 | 1.000000 | ∅ (PDF has no separate field) | ∅ |

Q(L) = (0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001 = 1.000100/1.0001 = **1.000000**.

## 4. Datasheet physical-register aggregation

q_R is the mean of Q(L) over extracted logical registers associated with the same datasheet physical register. Missing truth locations have q_R=0.

| Datasheet key | Datasheet register | Source | Associated without entry | q_R |
|---|---|---|---|---:|
| bank0/0x00 | WHO_AM_I | PDF p.36 | registers[0] `WHO_AM_I` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x03 | USER_CTRL | PDF p.36 | registers[1] `USER_CTRL` Q(L)=0.982850665 | 0.982850665 |
| bank0/0x05 | LP_CONFIG | PDF p.37 | registers[2] `LP_CONFIG` Q(L)=0.969549679 | 0.969549679 |
| bank0/0x06 | PWR_MGMT_1 | PDF p.37 | registers[3] `PWR_MGMT_1` Q(L)=0.990200380 | 0.990200380 |
| bank0/0x07 | PWR_MGMT_2 | PDF p.38 | registers[4] `PWR_MGMT_2` Q(L)=0.986933840 | 0.986933840 |
| bank0/0x0F | INT_PIN_CFG | PDF p.38 | registers[5] `INT_PIN_CFG` Q(L)=0.985300570 | 0.985300570 |
| bank0/0x10 | INT_ENABLE | PDF p.39 | registers[6] `INT_ENABLE` Q(L)=0.968091653 | 0.968091653 |
| bank0/0x11 | INT_ENABLE_1 | PDF p.39 | none | 0.000000000 |
| bank0/0x12 | INT_ENABLE_2 | PDF p.39 | none | 0.000000000 |
| bank0/0x13 | INT_ENABLE_3 | PDF p.40 | none | 0.000000000 |
| bank0/0x17 | I2C_MST_STATUS | PDF p.40 | registers[7] `I2C_MST_STATUS` Q(L)=0.941005899 | 0.941005899 |
| bank0/0x19 | INT_STATUS | PDF p.40 | registers[8] `INT_STATUS` Q(L)=0.984320608 | 0.984320608 |
| bank0/0x1A | INT_STATUS_1 | PDF p.41 | none | 0.000000000 |
| bank0/0x1B | INT_STATUS_2 | PDF p.41 | none | 0.000000000 |
| bank0/0x1C | INT_STATUS_3 | PDF p.41 | none | 0.000000000 |
| bank0/0x28 | DELAY_TIMEH | PDF p.41 | registers[9] `DELAY_TIMEH` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x29 | DELAY_TIMEL | PDF p.42 | registers[10] `DELAY_TIMEL` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x2D | ACCEL_XOUT_H | PDF p.42 | registers[11] `ACCEL_XOUT_H` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x2E | ACCEL_XOUT_L | PDF p.42 | registers[12] `ACCEL_XOUT_L` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x2F | ACCEL_YOUT_H | PDF p.42 | registers[13] `ACCEL_YOUT_H` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x30 | ACCEL_YOUT_L | PDF p.43 | registers[14] `ACCEL_YOUT_L` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x31 | ACCEL_ZOUT_H | PDF p.43 | registers[15] `ACCEL_ZOUT_H` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x32 | ACCEL_ZOUT_L | PDF p.43 | registers[16] `ACCEL_ZOUT_L` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x33 | GYRO_XOUT_H | PDF p.43 | registers[17] `GYRO_XOUT_H` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x34 | GYRO_XOUT_L | PDF p.44 | registers[18] `GYRO_XOUT_L` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x35 | GYRO_YOUT_H | PDF p.44 | registers[19] `GYRO_YOUT_H` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x36 | GYRO_YOUT_L | PDF p.44 | registers[20] `GYRO_YOUT_L` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x37 | GYRO_ZOUT_H | PDF p.44 | registers[21] `GYRO_ZOUT_H` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x38 | GYRO_ZOUT_L | PDF p.45 | registers[22] `GYRO_ZOUT_L` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x39 | TEMP_OUT_H | PDF p.45 | registers[23] `TEMP_OUT_H` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x3A | TEMP_OUT_L | PDF p.45 | registers[24] `TEMP_OUT_L` Q(L)=1.000000000 | 1.000000000 |
| bank0/0x3B | EXT_SLV_SENS_DATA_00 | PDF p.45 | none | 0.000000000 |
| bank0/0x3C | EXT_SLV_SENS_DATA_01 | PDF p.46 | none | 0.000000000 |
| bank0/0x3D | EXT_SLV_SENS_DATA_02 | PDF p.46 | none | 0.000000000 |
| bank0/0x3E | EXT_SLV_SENS_DATA_03 | PDF p.46 | none | 0.000000000 |
| bank0/0x3F | EXT_SLV_SENS_DATA_04 | PDF p.46 | none | 0.000000000 |
| bank0/0x40 | EXT_SLV_SENS_DATA_05 | PDF p.47 | none | 0.000000000 |
| bank0/0x41 | EXT_SLV_SENS_DATA_06 | PDF p.47 | none | 0.000000000 |
| bank0/0x42 | EXT_SLV_SENS_DATA_07 | PDF p.47 | none | 0.000000000 |
| bank0/0x43 | EXT_SLV_SENS_DATA_08 | PDF p.47 | none | 0.000000000 |
| bank0/0x44 | EXT_SLV_SENS_DATA_09 | PDF p.48 | none | 0.000000000 |
| bank0/0x45 | EXT_SLV_SENS_DATA_10 | PDF p.48 | none | 0.000000000 |
| bank0/0x46 | EXT_SLV_SENS_DATA_11 | PDF p.48 | none | 0.000000000 |
| bank0/0x47 | EXT_SLV_SENS_DATA_12 | PDF p.48 | none | 0.000000000 |
| bank0/0x48 | EXT_SLV_SENS_DATA_13 | PDF p.49 | none | 0.000000000 |
| bank0/0x49 | EXT_SLV_SENS_DATA_14 | PDF p.49 | none | 0.000000000 |
| bank0/0x4A | EXT_SLV_SENS_DATA_15 | PDF p.49 | none | 0.000000000 |
| bank0/0x4B | EXT_SLV_SENS_DATA_16 | PDF p.49 | none | 0.000000000 |
| bank0/0x4C | EXT_SLV_SENS_DATA_17 | PDF p.50 | none | 0.000000000 |
| bank0/0x4D | EXT_SLV_SENS_DATA_18 | PDF p.50 | none | 0.000000000 |
| bank0/0x4E | EXT_SLV_SENS_DATA_19 | PDF p.50 | none | 0.000000000 |
| bank0/0x4F | EXT_SLV_SENS_DATA_20 | PDF p.50 | none | 0.000000000 |
| bank0/0x50 | EXT_SLV_SENS_DATA_21 | PDF p.51 | none | 0.000000000 |
| bank0/0x51 | EXT_SLV_SENS_DATA_22 | PDF p.51 | none | 0.000000000 |
| bank0/0x52 | EXT_SLV_SENS_DATA_23 | PDF p.51 | none | 0.000000000 |
| bank0/0x66 | FIFO_EN_1 | PDF p.52 | none | 0.000000000 |
| bank0/0x67 | FIFO_EN_2 | PDF p.52 | none | 0.000000000 |
| bank0/0x68 | FIFO_RST | PDF p.53 | none | 0.000000000 |
| bank0/0x69 | FIFO_MODE | PDF p.53 | none | 0.000000000 |
| bank0/0x70 | FIFO_COUNTH | PDF p.53 | none | 0.000000000 |
| bank0/0x71 | FIFO_COUNTL | PDF p.53 | none | 0.000000000 |
| bank0/0x72 | FIFO_R_W | PDF p.54 | none | 0.000000000 |
| bank0/0x74 | DATA_RDY_STATUS | PDF p.54 | none | 0.000000000 |
| bank0/0x76 | FIFO_CFG | PDF p.54 | none | 0.000000000 |
| bank1/0x02 | SELF_TEST_X_GYRO | PDF p.55 | none | 0.000000000 |
| bank1/0x03 | SELF_TEST_Y_GYRO | PDF p.55 | none | 0.000000000 |
| bank1/0x04 | SELF_TEST_Z_GYRO | PDF p.55 | none | 0.000000000 |
| bank1/0x0E | SELF_TEST_X_ACCEL | PDF p.55 | none | 0.000000000 |
| bank1/0x0F | SELF_TEST_Y_ACCEL | PDF p.56 | none | 0.000000000 |
| bank1/0x10 | SELF_TEST_Z_ACCEL | PDF p.56 | none | 0.000000000 |
| bank1/0x14 | XA_OFFS_H | PDF p.56 | none | 0.000000000 |
| bank1/0x15 | XA_OFFS_L | PDF p.56 | none | 0.000000000 |
| bank1/0x17 | YA_OFFS_H | PDF p.57 | none | 0.000000000 |
| bank1/0x18 | YA_OFFS_L | PDF p.57 | none | 0.000000000 |
| bank1/0x1A | ZA_OFFS_H | PDF p.57 | none | 0.000000000 |
| bank1/0x1B | ZA_OFFS_L | PDF p.57 | none | 0.000000000 |
| bank1/0x28 | TIMEBASE_CORRECTION_PLL | PDF p.58 | none | 0.000000000 |
| bank2/0x00 | GYRO_SMPLRT_DIV | PDF p.59 | none | 0.000000000 |
| bank2/0x01 | GYRO_CONFIG_1 | PDF p.59 | none | 0.000000000 |
| bank2/0x03 | XG_OFFS_USRH | PDF p.61 | none | 0.000000000 |
| bank2/0x04 | XG_OFFS_USRL | PDF p.62 | none | 0.000000000 |
| bank2/0x05 | YG_OFFS_USRH | PDF p.62 | none | 0.000000000 |
| bank2/0x06 | YG_OFFS_USRL | PDF p.62 | none | 0.000000000 |
| bank2/0x07 | ZG_OFFS_USRH | PDF p.62 | none | 0.000000000 |
| bank2/0x08 | ZG_OFFS_USRL | PDF p.62 | none | 0.000000000 |
| bank2/0x09 | ODR_ALIGN_EN | PDF p.63 | none | 0.000000000 |
| bank2/0x10 | ACCEL_SMPLRT_DIV_1 | PDF p.63 | none | 0.000000000 |
| bank2/0x11 | ACCEL_SMPLRT_DIV_2 | PDF p.63 | none | 0.000000000 |
| bank2/0x12 | ACCEL_INTEL_CTRL | PDF p.63 | none | 0.000000000 |
| bank2/0x13 | ACCEL_WOM_THR | PDF p.64 | none | 0.000000000 |
| bank2/0x14 | ACCEL_CONFIG | PDF p.64 | none | 0.000000000 |
| bank2/0x52 | FSYNC_CONFIG | PDF p.66 | none | 0.000000000 |
| bank2/0x02 | GYRO_CONFIG_2 | PDF p.60 | none | 0.000000000 |
| bank2/0x15 | ACCEL_CONFIG_2 | PDF p.65 | none | 0.000000000 |
| bank2/0x53 | TEMP_CONFIG | PDF p.67 | none | 0.000000000 |
| bank2/0x54 | MOD_CTRL_USR | PDF p.67 | none | 0.000000000 |
| bank3/0x00 | I2C_MST_ODR_CONFIG | PDF p.68 | none | 0.000000000 |
| bank3/0x01 | I2C_MST_CTRL | PDF p.68 | none | 0.000000000 |
| bank3/0x02 | I2C_MST_DELAY_CTRL | PDF p.69 | none | 0.000000000 |
| bank3/0x03 | I2C_SLV0_ADDR | PDF p.69 | none | 0.000000000 |
| bank3/0x04 | I2C_SLV0_REG | PDF p.69 | none | 0.000000000 |
| bank3/0x05 | I2C_SLV0_CTRL | PDF p.70 | none | 0.000000000 |
| bank3/0x06 | I2C_SLV0_DO | PDF p.70 | none | 0.000000000 |
| bank3/0x07 | I2C_SLV1_ADDR | PDF p.70 | none | 0.000000000 |
| bank3/0x08 | I2C_SLV1_REG | PDF p.71 | none | 0.000000000 |
| bank3/0x09 | I2C_SLV1_CTRL | PDF p.71 | none | 0.000000000 |
| bank3/0x0A | I2C_SLV1_DO | PDF p.72 | none | 0.000000000 |
| bank3/0x0B | I2C_SLV2_ADDR | PDF p.72 | none | 0.000000000 |
| bank3/0x0C | I2C_SLV2_REG | PDF p.72 | none | 0.000000000 |
| bank3/0x0D | I2C_SLV2_CTRL | PDF p.73 | none | 0.000000000 |
| bank3/0x0E | I2C_SLV2_DO | PDF p.73 | none | 0.000000000 |
| bank3/0x0F | I2C_SLV3_ADDR | PDF p.73 | none | 0.000000000 |
| bank3/0x10 | I2C_SLV3_REG | PDF p.74 | none | 0.000000000 |
| bank3/0x11 | I2C_SLV3_CTRL | PDF p.74 | none | 0.000000000 |
| bank3/0x12 | I2C_SLV3_DO | PDF p.74 | none | 0.000000000 |
| bank3/0x13 | I2C_SLV4_ADDR | PDF p.75 | none | 0.000000000 |
| bank3/0x14 | I2C_SLV4_REG | PDF p.75 | none | 0.000000000 |
| bank3/0x15 | I2C_SLV4_CTRL | PDF p.75 | none | 0.000000000 |
| bank3/0x16 | I2C_SLV4_DO | PDF p.75 | none | 0.000000000 |
| bank3/0x17 | I2C_SLV4_DI | PDF p.76 | none | 0.000000000 |
| ALL/0x7F | REG_BANK_SEL | PDF p.54 | registers[34] `REG_BANK_SEL` Q(L)=1.000000000 | 1.000000000 |
| MAG/0x01 | WIA2 | PDF p.78 | none | 0.000000000 |
| MAG/0x10 | ST1 | PDF p.78 | none | 0.000000000 |
| MAG/0x11 | HXL | PDF p.78 | none | 0.000000000 |
| MAG/0x12 | HXH | PDF p.78 | none | 0.000000000 |
| MAG/0x13 | HYL | PDF p.78 | none | 0.000000000 |
| MAG/0x14 | HYH | PDF p.78 | none | 0.000000000 |
| MAG/0x15 | HZL | PDF p.78 | none | 0.000000000 |
| MAG/0x16 | HZH | PDF p.78 | none | 0.000000000 |
| MAG/0x18 | ST2 | PDF p.79 | none | 0.000000000 |
| MAG/0x31 | CNTL2 | PDF p.79 | none | 0.000000000 |
| MAG/0x32 | CNTL3 | PDF p.80 | none | 0.000000000 |
| MAG/0x33 | TS1 | PDF p.80 | none | 0.000000000 |
| MAG/0x34 | TS2 | PDF p.80 | none | 0.000000000 |

## 5. Detailed deduction inventory

### 5.1 Missing datasheet physical registers (q_R=0)

108 of the 134 real datasheet physical registers are missing from the extracted physical locations.

| Missing datasheet key | Register | Source |
|---|---|---|
| bank0/0x11 | INT_ENABLE_1 | PDF p.39 |
| bank0/0x12 | INT_ENABLE_2 | PDF p.39 |
| bank0/0x13 | INT_ENABLE_3 | PDF p.40 |
| bank0/0x1A | INT_STATUS_1 | PDF p.41 |
| bank0/0x1B | INT_STATUS_2 | PDF p.41 |
| bank0/0x1C | INT_STATUS_3 | PDF p.41 |
| bank0/0x3B | EXT_SLV_SENS_DATA_00 | PDF p.45 |
| bank0/0x3C | EXT_SLV_SENS_DATA_01 | PDF p.46 |
| bank0/0x3D | EXT_SLV_SENS_DATA_02 | PDF p.46 |
| bank0/0x3E | EXT_SLV_SENS_DATA_03 | PDF p.46 |
| bank0/0x3F | EXT_SLV_SENS_DATA_04 | PDF p.46 |
| bank0/0x40 | EXT_SLV_SENS_DATA_05 | PDF p.47 |
| bank0/0x41 | EXT_SLV_SENS_DATA_06 | PDF p.47 |
| bank0/0x42 | EXT_SLV_SENS_DATA_07 | PDF p.47 |
| bank0/0x43 | EXT_SLV_SENS_DATA_08 | PDF p.47 |
| bank0/0x44 | EXT_SLV_SENS_DATA_09 | PDF p.48 |
| bank0/0x45 | EXT_SLV_SENS_DATA_10 | PDF p.48 |
| bank0/0x46 | EXT_SLV_SENS_DATA_11 | PDF p.48 |
| bank0/0x47 | EXT_SLV_SENS_DATA_12 | PDF p.48 |
| bank0/0x48 | EXT_SLV_SENS_DATA_13 | PDF p.49 |
| bank0/0x49 | EXT_SLV_SENS_DATA_14 | PDF p.49 |
| bank0/0x4A | EXT_SLV_SENS_DATA_15 | PDF p.49 |
| bank0/0x4B | EXT_SLV_SENS_DATA_16 | PDF p.49 |
| bank0/0x4C | EXT_SLV_SENS_DATA_17 | PDF p.50 |
| bank0/0x4D | EXT_SLV_SENS_DATA_18 | PDF p.50 |
| bank0/0x4E | EXT_SLV_SENS_DATA_19 | PDF p.50 |
| bank0/0x4F | EXT_SLV_SENS_DATA_20 | PDF p.50 |
| bank0/0x50 | EXT_SLV_SENS_DATA_21 | PDF p.51 |
| bank0/0x51 | EXT_SLV_SENS_DATA_22 | PDF p.51 |
| bank0/0x52 | EXT_SLV_SENS_DATA_23 | PDF p.51 |
| bank0/0x66 | FIFO_EN_1 | PDF p.52 |
| bank0/0x67 | FIFO_EN_2 | PDF p.52 |
| bank0/0x68 | FIFO_RST | PDF p.53 |
| bank0/0x69 | FIFO_MODE | PDF p.53 |
| bank0/0x70 | FIFO_COUNTH | PDF p.53 |
| bank0/0x71 | FIFO_COUNTL | PDF p.53 |
| bank0/0x72 | FIFO_R_W | PDF p.54 |
| bank0/0x74 | DATA_RDY_STATUS | PDF p.54 |
| bank0/0x76 | FIFO_CFG | PDF p.54 |
| bank1/0x02 | SELF_TEST_X_GYRO | PDF p.55 |
| bank1/0x03 | SELF_TEST_Y_GYRO | PDF p.55 |
| bank1/0x04 | SELF_TEST_Z_GYRO | PDF p.55 |
| bank1/0x0E | SELF_TEST_X_ACCEL | PDF p.55 |
| bank1/0x0F | SELF_TEST_Y_ACCEL | PDF p.56 |
| bank1/0x10 | SELF_TEST_Z_ACCEL | PDF p.56 |
| bank1/0x14 | XA_OFFS_H | PDF p.56 |
| bank1/0x15 | XA_OFFS_L | PDF p.56 |
| bank1/0x17 | YA_OFFS_H | PDF p.57 |
| bank1/0x18 | YA_OFFS_L | PDF p.57 |
| bank1/0x1A | ZA_OFFS_H | PDF p.57 |
| bank1/0x1B | ZA_OFFS_L | PDF p.57 |
| bank1/0x28 | TIMEBASE_CORRECTION_PLL | PDF p.58 |
| bank2/0x00 | GYRO_SMPLRT_DIV | PDF p.59 |
| bank2/0x01 | GYRO_CONFIG_1 | PDF p.59 |
| bank2/0x03 | XG_OFFS_USRH | PDF p.61 |
| bank2/0x04 | XG_OFFS_USRL | PDF p.62 |
| bank2/0x05 | YG_OFFS_USRH | PDF p.62 |
| bank2/0x06 | YG_OFFS_USRL | PDF p.62 |
| bank2/0x07 | ZG_OFFS_USRH | PDF p.62 |
| bank2/0x08 | ZG_OFFS_USRL | PDF p.62 |
| bank2/0x09 | ODR_ALIGN_EN | PDF p.63 |
| bank2/0x10 | ACCEL_SMPLRT_DIV_1 | PDF p.63 |
| bank2/0x11 | ACCEL_SMPLRT_DIV_2 | PDF p.63 |
| bank2/0x12 | ACCEL_INTEL_CTRL | PDF p.63 |
| bank2/0x13 | ACCEL_WOM_THR | PDF p.64 |
| bank2/0x14 | ACCEL_CONFIG | PDF p.64 |
| bank2/0x52 | FSYNC_CONFIG | PDF p.66 |
| bank2/0x02 | GYRO_CONFIG_2 | PDF p.60 |
| bank2/0x15 | ACCEL_CONFIG_2 | PDF p.65 |
| bank2/0x53 | TEMP_CONFIG | PDF p.67 |
| bank2/0x54 | MOD_CTRL_USR | PDF p.67 |
| bank3/0x00 | I2C_MST_ODR_CONFIG | PDF p.68 |
| bank3/0x01 | I2C_MST_CTRL | PDF p.68 |
| bank3/0x02 | I2C_MST_DELAY_CTRL | PDF p.69 |
| bank3/0x03 | I2C_SLV0_ADDR | PDF p.69 |
| bank3/0x04 | I2C_SLV0_REG | PDF p.69 |
| bank3/0x05 | I2C_SLV0_CTRL | PDF p.70 |
| bank3/0x06 | I2C_SLV0_DO | PDF p.70 |
| bank3/0x07 | I2C_SLV1_ADDR | PDF p.70 |
| bank3/0x08 | I2C_SLV1_REG | PDF p.71 |
| bank3/0x09 | I2C_SLV1_CTRL | PDF p.71 |
| bank3/0x0A | I2C_SLV1_DO | PDF p.72 |
| bank3/0x0B | I2C_SLV2_ADDR | PDF p.72 |
| bank3/0x0C | I2C_SLV2_REG | PDF p.72 |
| bank3/0x0D | I2C_SLV2_CTRL | PDF p.73 |
| bank3/0x0E | I2C_SLV2_DO | PDF p.73 |
| bank3/0x0F | I2C_SLV3_ADDR | PDF p.73 |
| bank3/0x10 | I2C_SLV3_REG | PDF p.74 |
| bank3/0x11 | I2C_SLV3_CTRL | PDF p.74 |
| bank3/0x12 | I2C_SLV3_DO | PDF p.74 |
| bank3/0x13 | I2C_SLV4_ADDR | PDF p.75 |
| bank3/0x14 | I2C_SLV4_REG | PDF p.75 |
| bank3/0x15 | I2C_SLV4_CTRL | PDF p.75 |
| bank3/0x16 | I2C_SLV4_DO | PDF p.75 |
| bank3/0x17 | I2C_SLV4_DI | PDF p.76 |
| MAG/0x01 | WIA2 | PDF p.78 |
| MAG/0x10 | ST1 | PDF p.78 |
| MAG/0x11 | HXL | PDF p.78 |
| MAG/0x12 | HXH | PDF p.78 |
| MAG/0x13 | HYL | PDF p.78 |
| MAG/0x14 | HYH | PDF p.78 |
| MAG/0x15 | HZL | PDF p.78 |
| MAG/0x16 | HZH | PDF p.78 |
| MAG/0x18 | ST2 | PDF p.79 |
| MAG/0x31 | CNTL2 | PDF p.79 |
| MAG/0x32 | CNTL3 | PDF p.80 |
| MAG/0x33 | TS1 | PDF p.80 |
| MAG/0x34 | TS2 | PDF p.80 |

### 5.2 Extra extracted physical-register entries (x penalty)

9 extracted physical entries are not real datasheet locations and therefore contribute to x.

| Extra without path | Extracted register | Extracted physical key | Datasheet same-name location | Reason |
|---|---|---|---|---|
| `registers[25]` | FIFO_EN_1 | bank1/0x42 | bank0/0x66 (PDF p.52) | wrong bank/address; bank1/0x42 is not the datasheet location |
| `registers[26]` | FIFO_EN_2 | bank1/0x43 | bank0/0x67 (PDF p.52) | wrong bank/address; bank1/0x43 is not the datasheet location |
| `registers[27]` | FIFO_RST | bank1/0x44 | bank0/0x68 (PDF p.53) | wrong bank/address; bank1/0x44 is not the datasheet location |
| `registers[28]` | FIFO_MODE | bank1/0x45 | bank0/0x69 (PDF p.53) | wrong bank/address; bank1/0x45 is not the datasheet location |
| `registers[29]` | FIFO_COUNTH | bank1/0x46 | bank0/0x70 (PDF p.53) | wrong bank/address; bank1/0x46 is not the datasheet location |
| `registers[30]` | FIFO_COUNTL | bank1/0x47 | bank0/0x71 (PDF p.53) | wrong bank/address; bank1/0x47 is not the datasheet location |
| `registers[31]` | FIFO_R_W | bank1/0x48 | bank0/0x72 (PDF p.54) | wrong bank/address; bank1/0x48 is not the datasheet location |
| `registers[32]` | DATA_RDY_STATUS | bank1/0x74 | bank0/0x74 (PDF p.54) | wrong bank/address; bank1/0x74 is not the datasheet location |
| `registers[33]` | FIFO_CFG | bank1/0x76 | bank0/0x76 (PDF p.54) | wrong bank/address; bank1/0x76 is not the datasheet location |

### 5.3 Exact content-level objective deductions

- `LP_CONFIG` at `registers[2]`: datasheet bit 7 is a reserved bit (`bits 7:7`, PDF p.37), but the extraction has no exact bit-field entry for that range. Its eight bottom-layer fields are therefore C=0 and the missing bit lowers `Q_BF`, `Q_FP`, and Q(L).
- `USER_CTRL` at `registers[1]`: the datasheet value-code enumerations are omitted for `DMP_EN [0,1]`, `FIFO_EN [0,1]`, `I2C_MST_EN [0,1]`, `I2C_IF_DIS [1]`, `DMP_RST [1]`, `SRAM_RST [1]`, and `I2C_MST_RST [1]` (PDF p.36); each corresponding extraction `values` is empty and receives C=0. The functional descriptions and ranges remain credited.
- `PWR_MGMT_1` at `registers[3]`: value codes for `DEVICE_RESET [1]`, `LP_EN [0,1]`, and `CLKSEL [0,5,6,7]` are omitted from `values` (PDF p.37), so those value fields receive C=0. `SLEEP` and `TEMP_DIS` have no separate enumerated target list and the empty/empty values fields receive C=1.
- `PWR_MGMT_2` at `registers[4]`: the datasheet restricts `DISABLE_ACCEL` and `DISABLE_GYRO` to codes `000` and `111`, normalized as [0,7] (PDF p.38); both extraction `values` fields are empty and receive C=0.
- `INT_PIN_CFG` at `registers[5]`: value codes [0,1] are omitted for `INT1_ACTL`, `INT1_OPEN`, `INT1_LATCH__EN`, `INT_ANYRD_2CLEAR`, `ACTL_FSYNC`, and `FSYNC_INT_MODE_EN` (PDF p.38); the corresponding empty extraction `values` fields receive C=0. `BYPASS_EN` has no separate target enumeration list and receives C=1 for empty/empty values.
- `INT_ENABLE` at `registers[6]`: value codes [0,1] are omitted for `REG_WOF_EN`, `WOM_INT_EN`, `PLL_RDY_EN`, `DMP_INT1_EN`, and `I2C_MST_INT_EN` (PDF p.39); each receives C=0 for `values`. The extracted reserved entry has `bit_start=6, bit_end=4`, while the datasheet target is `bit_start=4, bit_end=6`; because exact bit_start/bit_end matching is required, the target reserved range is unpaired and the reversed extraction is listed as an unmatched bit-field entry.
- `INT_STATUS` at `registers[8]`: the datasheet explicitly marks code 1 for `WOM_INT`, `PLL_RDY_INT`, `DMP_INT1`, and `I2C_MST_INT` (PDF p.40); all four extraction `values` fields are empty and receive C=0.
- `I2C_MST_STATUS` at `registers[7]`: the field-part and all bit-field access types are equivalent to datasheet `R/C`; however, the logical-register `type_write_read` is extracted as `R` instead of datasheet `R/C`, so that logical direct field receives C=0. This objective error is reflected in Q(L).
- `REG_BANK_SEL` at `registers[34]`: its extracted value objects contain codes 0,1,2,3, which match the datasheet code set; the object/list representation is normalized and receives full credit. The bank-0 view is normalized to the datasheet's global `ALL/0x7F` register.

### 5.4 Accepted description and representation comparisons

- Nonempty descriptions in the 26 matched entries preserve the relevant register/bit function and are therefore credited under the requested description leniency; the exact datasheet field text and source page are shown in each bit-field table.
- Hex versus decimal address representations, list/object shape for a single physical address, `R/W` versus `RW`, `R/C` versus `RC`, and value-code-only versus value-code-plus-description representations are not penalized when the encoded fact is identical.
- No logical-register merge/split penalty is applied: every matched without logical register has one field part for one physical datasheet register. The nine FIFO entries are not grouping differences; they are wrong-bank physical entries and are extras.

### 5.5 Coverage and extra-physical-register check

- Truth physical-register coverage: 26/134 matched; missing truth locations: 108.
- Extra extracted physical locations: 9; physical-address penalty factor = 0.742857142857.
- Extracted logical registers with matched physical locations: registers[0], registers[1], registers[2], registers[3], registers[4], registers[5], registers[6], registers[7], registers[8], registers[9], registers[10], registers[11], registers[12], registers[13], registers[14], registers[15], registers[16], registers[17], registers[18], registers[19], registers[20], registers[21], registers[22], registers[23], registers[24], registers[34].
- Extracted logical registers with extra physical locations: registers[25], registers[26], registers[27], registers[28], registers[29], registers[30], registers[31], registers[32], registers[33].

## 6. Invented-field and unsupported-content check

- The nine extra physical entries are listed with every extracted bit field above; they are not credited because their physical locations are not real datasheet registers.
- Within matched physical locations, `LP_CONFIG` bit 7 is absent and `INT_ENABLE` contains one unmatched reversed bit_start/bit_end entry; both are listed in the per-register audit and section 5.3.
- Empty extracted value lists on datasheet fields with explicit value codes are strict objective omissions and are listed in section 5.3; empty/empty values fields are allowed and credited.

## 7. Version-level calculation

- sum(q_R) = 25.808253296429; m = 26; x = 9.
- S_final = (10/134 × 25.808253296429) × (26/(26+9)) = 1.430734724322 / 10.

