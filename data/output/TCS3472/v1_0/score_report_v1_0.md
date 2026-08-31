# TCS3472 v1.0 detailed score - datasheet-based AGENTS.md rules

## 1. Scoring basis

- The comparison source is the local [TCS3472 datasheet v1-04, ams Datasheet, 2020-Apr-10](../TCS3472.pdf), not a truth JSON. Register-set facts come from printed p. 20, Figure 24; the bit-field and value facts come from printed pp. 21-28, Figures 25-35.
- The extracted map is TCS3472/v1_0/register_map.json. It contains 15 logical-register entries, 21 physical register entries (20 numeric addresses plus the datasheet's explicitly addressless COMMAND entry), and 35 bit fields.
- The addressless COMMAND row is counted as the unique datasheet register key COMMAND/-- because Figure 24 explicitly lists it with address -- and v1 preserves empty hex/decimal. It is not assigned a fabricated numeric address.
- Equivalent logical grouping is accepted: the two threshold pairs and the four 16-bit channel-data pairs are evaluated as one logical register with multiple field parts, while every physical field part still receives its own bottom-up calculation.
- The datasheet itself uses both CDATAL/RDATAL/GDATAL/BDATAL (Figure 24) and CDATA/RDATA/GDATA/BDATA for the corresponding low-byte rows (Figure 35). v1's logical group names and low-byte field-part names are treated as this equivalent source naming, with no penalty.
- Rounded weights are normalized by 0.9999 at bit-field level and 1.0001 at logical-register level; field-part weights sum to 1.0000.
- For the composite physical_address field, an exactly correct numeric address with an omitted address description receives C=0.5: the objective address is correct but the content is incomplete. A missing standalone field-part description receives C=0.0. Semantically equivalent descriptions receive C=1.0.
- For values, explicit datasheet value tables and the explicit fixed CMD=1 statement are evaluated strictly. The CMD fixed value is absent from v1.values and receives C=0.0 even though the same fact appears in field_description.
- The datasheet does not assign type_write_read separately to individual bit fields. In accordance with the scoring convention used for an unspecified deepest field, every v1 bit-field type_write_read is empty and receives no credit; register-level and field-part R/W values are scored from Figure 24.

AHP weights used:

| Object | Scored fields and weights |
|---|---|
| logical_register | name 0.0225; physical_address 0.4044; register_description 0.0564; width_bits 0.0590; type_write_read 0.0590; field_parts 0.2987; default_value 0.0667; default_value_description 0.0334 |
| field_part | register_name 0.0280; physical_address 0.4688; description 0.0693; width_bits 0.0605; type_write_read 0.0605; bit_field 0.3129 |
| bit_field | name_or_parameter 0.0212; field_description 0.0586; bit_start 0.2594; bit_end 0.2594; bit_width 0.0583; values 0.2097; is_reserved 0.0750; type_write_read 0.0583 |

## Extracted logical register 1: `COMMAND`

v1 location: `registers[0]` (JSON index=1); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 21, Fig. 25](../TCS3472.pdf).
Associated physical locations: --.

### Bottom layer: bit fields, then field parts

#### Field part 1: `COMMAND` at -- (no numeric address)

Location: `registers[0].field_parts[0]` ↔ datasheet [Figure 25](../TCS3472.pdf).

**Bit field 1: `CMD`, bits 7:7**

Judgment: the bit position, width, name, reserved flag, and description are correct. The datasheet explicitly requires CMD=1, but v1 leaves values empty; bit-level type_write_read is also empty and not credited.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "CMD" | "CMD" |
| `field_description` | 0.0586 | 1.0 | "Select Command Register. Must write as 1 when addressing the COMMAND register." | "Select Command Register. Must be written as 1 when addressing the COMMAND register." |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"1","value_description":"Must write as 1 when addressing the COMMAND register."}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x0.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.731900 / 0.9999 = **0.731973**.

**Bit field 2: `TYPE`, bits 6:5**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "TYPE" | "TYPE" |
| `field_description` | 0.0586 | 1.0 | "Selects type of transaction to follow in subsequent data transfers." | "Selects the transaction type for subsequent data transfers." |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"Repeated byte protocol transaction"},{"value":"01","value_description":"Auto-increment protocol transaction"},{"value":"10","value_description":"Reserved - Do not use"},{"value":"11","value_description":"Special function - See description below"}] | [{"value":"00","value_description":"Repeated byte protocol transaction"},{"value":"01","value_description":"Auto-increment protocol transaction"},{"value":"10","value_description":"Reserved — Do not use"},{"value":"11","value_description":"Special function — See description below"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Bit field 3: `ADDR/SF`, bits 4:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "ADDR/SF" | "ADDR/SF" |
| `field_description` | 0.0586 | 1.0 | "Address field/special function field. Depending on the transaction type, this field either specifies a special function command or selects the specific control-status-data register for subsequent read and write transactions. The field values listed below only apply to special function commands." | "Address or special-function field. Selects a control-status-data register or specifies a special-function command, depending on TYPE." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | [{"value":"00110","value_description":"Clear channel interrupt clear"},{"value":"Other","value_description":"Reserved - Do not write"}] | [{"value":"00110","value_description":"Clear channel interrupt clear; clears any pending interrupt and is self-clearing."},{"value":"Other","value_description":"Reserved — Do not write"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.731973, 0.941694, 0.941694) = **0.871787**.
Direct judgment: all five direct field-part fields are semantically correct; where v1 uses a shorter address description, it has no functional deviation.

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "COMMAND" | "COMMAND" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"","decimal":"","bank":"","page":"","description":"Specifies register address"} | {"hex":"","decimal":"","bank":"","page":"","description":"Command byte; no physical register address is specified."} |
| `description` | 0.0693 | 1.0 | "Specifies register address" | "Command byte specifying the target register address or a special function." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "W" | "W" |
| `bit_field` | 0.3129 | 0.871787 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x1.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.871787 = **0.959882**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.959882) = **0.959882**.
Judgment: the logical register, addresses, register description, width, R/W, defaults, and grouped field-part representation are semantically correct.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "COMMAND" | "COMMAND" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"","decimal":"","bank":"","page":"","description":"Specifies register address"}] | [{"hex":"","decimal":"","bank":"","page":"","description":"Command byte; no physical register address is specified."}] |
| `register_description` | 0.0564 | 1.0 | "The command register specifies the address of the target register for future write and read operations." | "Written first to select the target control-status-data register for subsequent reads or writes. TYPE selects repeated-byte, auto-increment, or special-function operation; ADDR/SF supplies the register address or special-function code. See the I²C protocol section for access mechanics." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "W" | "W" |
| `field_parts` | 0.2987 | 0.959882 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "No separate reset-value description is printed in Figure 24." | "" |

Q_L = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.959882 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.988117 / 1.0001 = **0.988018**.

## Extracted logical register 2: `ENABLE`

v1 location: `registers[1]` (JSON index=2); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 22, Fig. 26](../TCS3472.pdf).
Associated physical locations: 0x00 (0).

### Bottom layer: bit fields, then field parts

#### Field part 1: `ENABLE` at 0x00 (0)

Location: `registers[1].field_parts[0]` ↔ datasheet [Figure 26](../TCS3472.pdf).

**Bit field 1: `Reserved`, bits 7:5**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Reserved" | "Reserved" |
| `field_description` | 0.0586 | 1.0 | "Reserved. Write as 0." | "Reserved. Write as 0." |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Bit field 2: `AIEN`, bits 4:4**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "AIEN" | "AIEN" |
| `field_description` | 0.0586 | 1.0 | "RGBC interrupt enable. When asserted, permits RGBC interrupts to be generated." | "RGBC interrupt enable. When asserted, permits RGBC interrupts to be generated." |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Bit field 3: `WEN`, bits 3:3**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "WEN" | "WEN" |
| `field_description` | 0.0586 | 1.0 | "Wait enable. This bit activates the wait feature. Writing a 1 activates the wait timer. Writing a 0 disables the wait timer." | "Wait enable. Writing 1 activates the wait timer; writing 0 disables it." |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Writing a 1 activates the wait timer."},{"value":"0","value_description":"Writing a 0 disables the wait timer."}] | [{"value":"1","value_description":"Activates the wait timer."},{"value":"0","value_description":"Disables the wait timer."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Bit field 4: `Reserved`, bits 2:2**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Reserved" | "Reserved" |
| `field_description` | 0.0586 | 1.0 | "Reserved. Write as 0." | "Reserved. Write as 0." |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Bit field 5: `AEN`, bits 1:1**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "AEN" | "AEN" |
| `field_description` | 0.0586 | 1.0 | "RGBC enable. This bit activates the two-channel ADC. Writing a 1 activates the RGBC. Writing a 0 disables the RGBC." | "RGBC enable. Writing 1 activates the RGBC ADC; writing 0 disables it." |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Writing a 1 activates the RGBC."},{"value":"0","value_description":"Writing a 0 disables the RGBC."}] | [{"value":"1","value_description":"Activates the RGBC ADC."},{"value":"0","value_description":"Disables the RGBC ADC."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Bit field 6: `PON`, bits 0:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "PON" | "PON" |
| `field_description` | 0.0586 | 1.0 | "Power ON. This bit activates the internal oscillator to permit the timers and ADC channels to operate. Writing a 1 activates the oscillator. Writing a 0 disables the oscillator." | "Power ON. Controls the internal oscillator used by the timers and ADC channels." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Writing a 1 activates the oscillator."},{"value":"0","value_description":"Writing a 0 disables the oscillator."}] | [{"value":"1","value_description":"Activates the internal oscillator."},{"value":"0","value_description":"Disables the internal oscillator."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**.
Direct judgment: register_name, numeric address, width, and field-part R/W are correct; physical_address is partial because its description is empty (C=0.5), and the standalone field-part description is missing (C=0.0).

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "ENABLE" | "ENABLE" |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Enables states and interrupts"} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | "Enables states and interrupts" | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x0.500000 + 0.0693x0.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.678056**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.
Judgment: every objective logical-register fact is correct, but the single physical_address object's description is omitted (C=0.5); the corresponding field-part description is also missing.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "ENABLE" | "ENABLE" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Enables states and interrupts"}] | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | "The ENABLE register is used primarily to power the TCS3472 device ON and OFF, and enable functions and interrupts as shown below." | "Powers the device on or off and enables RGBC conversion, waiting, and RGBC interrupts. At least 2.4 ms must pass after PON is asserted before an RGBC conversion can be initiated. Interrupt status remains available in STATUS, while AIEN controls interrupt output generation; see the Power Management section for additional information." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.678056 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "No separate reset-value description is printed in Figure 24." | "" |

Q_L = (0.0225x1.000000 + 0.4044x0.500000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.678056 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.701735 / 1.0001 = **0.701665**.

## Extracted logical register 3: `ATIME`

v1 location: `registers[2]` (JSON index=3); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 23, Fig. 27](../TCS3472.pdf).
Associated physical locations: 0x01 (1).

### Bottom layer: bit fields, then field parts

#### Field part 1: `ATIME` at 0x01 (1)

Location: `registers[2].field_parts[0]` ↔ datasheet [Figure 27](../TCS3472.pdf).

**Bit field 1: `ATIME`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "ATIME" | "ATIME" |
| `field_description` | 0.0586 | 1.0 | "Controls the RGBC integration time in 2.4-ms increments." | "Programs the RGBC integration time in 2.4-ms increments." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [{"value":"0xFF","value_description":"1 integration cycle, 2.4 ms, maximum count 1024"},{"value":"0xF6","value_description":"10 integration cycles, 24 ms, maximum count 10240"},{"value":"0xD5","value_description":"42 integration cycles, 101 ms, maximum count 43008"},{"value":"0xC0","value_description":"64 integration cycles, 154 ms, maximum count 65535"},{"value":"0x00","value_description":"256 integration cycles, 614 ms, maximum count 65535"}] | [{"value":"0xFF","value_description":"1 integration cycle, 2.4 ms, maximum count 1024"},{"value":"0xF6","value_description":"10 integration cycles, 24 ms, maximum count 10240"},{"value":"0xD5","value_description":"42 integration cycles, 101 ms, maximum count 43008"},{"value":"0xC0","value_description":"64 integration cycles, 154 ms, maximum count 65535"},{"value":"0x00","value_description":"256 integration cycles, 614 ms, maximum count 65535"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: register_name, numeric address, width, and field-part R/W are correct; physical_address is partial because its description is empty (C=0.5), and the standalone field-part description is missing (C=0.0).

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "ATIME" | "ATIME" |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"RGBC time"} | {"hex":"0x01","decimal":"1","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | "RGBC time" | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x0.500000 + 0.0693x0.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.678056**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.
Judgment: every objective logical-register fact is correct, but the single physical_address object's description is omitted (C=0.5); the corresponding field-part description is also missing.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "ATIME" | "ATIME" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":"RGBC time"}] | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | "The RGBC timing register controls the internal integration time of the RGBC clear and IR channel ADCs in 2.4-ms increments. Max RGBC Count = (256 - ATIME) x 1024 up to a maximum of 65535." | "Controls the RGBC clear and IR channel ADC integration time in 2.4-ms increments. Integration Time = 2.4 ms × (256 − ATIME), and ATIME = 256 − Integration Time / 2.4 ms. Maximum RGBC count is (256 − ATIME) × 1024, limited to 65535." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.678056 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0xFF" | "0xFF" |
| `default_value_description` | 0.0334 | 1.0 | "No separate reset-value description is printed in Figure 24." | "" |

Q_L = (0.0225x1.000000 + 0.4044x0.500000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.678056 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.701735 / 1.0001 = **0.701665**.

## Extracted logical register 4: `WTIME`

v1 location: `registers[3]` (JSON index=4); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 23, Fig. 28](../TCS3472.pdf).
Associated physical locations: 0x03 (3).

### Bottom layer: bit fields, then field parts

#### Field part 1: `WTIME` at 0x03 (3)

Location: `registers[3].field_parts[0]` ↔ datasheet [Figure 28](../TCS3472.pdf).

**Bit field 1: `WTIME`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "WTIME" | "WTIME" |
| `field_description` | 0.0586 | 1.0 | "Wait time is set in 2.4-ms increments unless WLONG is asserted, in which case wait times are 12x longer. WTIME is programmed as a 2's complement number." | "Programs wait time as a 2's complement number." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [{"value":"0xFF","value_description":"Wait value 1: 2.4 ms with WLONG=0 or 0.029 sec with WLONG=1"},{"value":"0xAB","value_description":"Wait value 85: 204 ms with WLONG=0 or 2.45 sec with WLONG=1"},{"value":"0x00","value_description":"Wait value 256: 614 ms with WLONG=0 or 7.4 sec with WLONG=1"}] | [{"value":"0xFF","value_description":"Wait value 1: 2.4 ms with WLONG=0 or 0.029 sec with WLONG=1"},{"value":"0xAB","value_description":"Wait value 85: 204 ms with WLONG=0 or 2.45 sec with WLONG=1"},{"value":"0x00","value_description":"Wait value 256: 614 ms with WLONG=0 or 7.4 sec with WLONG=1"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: register_name, numeric address, width, and field-part R/W are correct; physical_address is partial because its description is empty (C=0.5), and the standalone field-part description is missing (C=0.0).

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "WTIME" | "WTIME" |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"Wait time"} | {"hex":"0x03","decimal":"3","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | "Wait time" | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x0.500000 + 0.0693x0.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.678056**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.
Judgment: every objective logical-register fact is correct, but the single physical_address object's description is omitted (C=0.5); the corresponding field-part description is also missing.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "WTIME" | "WTIME" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"Wait time"}] | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | "Wait time is set in 2.4-ms increments unless the WLONG bit is asserted, in which case the wait times are 12x longer. WTIME is programmed as a 2's complement number." | "Programs wait time in 2.4-ms increments as a 2's complement value. When CONFIG.WLONG is asserted, the programmed wait cycles are increased by a factor of 12." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.678056 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0xFF" | "0xFF" |
| `default_value_description` | 0.0334 | 1.0 | "No separate reset-value description is printed in Figure 24." | "" |

Q_L = (0.0225x1.000000 + 0.4044x0.500000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.678056 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.701735 / 1.0001 = **0.701665**.

## Extracted logical register 5: `Clear interrupt low threshold (AILTx)`

v1 location: `registers[4]` (JSON index=5); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 24, Fig. 29](../TCS3472.pdf).
Associated physical locations: 0x04 (4), 0x05 (5).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AILTL` at 0x04 (4)

Location: `registers[4].field_parts[0]` ↔ datasheet [Figure 29](../TCS3472.pdf).

**Bit field 1: `AILTL`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "AILTL" | "AILTL" |
| `field_description` | 0.0586 | 1.0 | "RGBC clear channel low threshold lower byte." | "Lower byte of the RGBC clear-channel low threshold." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: all five direct field-part fields are semantically correct; where v1 uses a shorter address description, it has no functional deviation.

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "AILTL" | "AILTL" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Clear interrupt low threshold low byte"} | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Low-threshold lower byte."} |
| `description` | 0.0693 | 1.0 | "RGBC clear-channel low-threshold lower byte." | "RGBC clear-channel low-threshold lower byte." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x1.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.981756**.

#### Field part 2: `AILTH` at 0x05 (5)

Location: `registers[4].field_parts[1]` ↔ datasheet [Figure 29](../TCS3472.pdf).

**Bit field 1: `AILTH`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "AILTH" | "AILTH" |
| `field_description` | 0.0586 | 1.0 | "RGBC clear channel low threshold upper byte." | "Upper byte of the RGBC clear-channel low threshold." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: all five direct field-part fields are semantically correct; where v1 uses a shorter address description, it has no functional deviation.

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "AILTH" | "AILTH" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Clear interrupt low threshold high byte"} | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Low-threshold upper byte."} |
| `description` | 0.0693 | 1.0 | "RGBC clear-channel low-threshold upper byte." | "RGBC clear-channel low-threshold upper byte." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x1.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.981756**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.981756, 0.981756) = **0.981756**.
Judgment: the logical register, addresses, register description, width, R/W, defaults, and grouped field-part representation are semantically correct.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "Clear interrupt low threshold (AILTx)" | "Clear interrupt low threshold (AILTx)" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":"Clear interrupt low threshold low byte"},{"hex":"0x05","decimal":"5","bank":"","page":"","description":"Clear interrupt low threshold high byte"}] | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":"Low-threshold lower byte."},{"hex":"0x05","decimal":"5","bank":"","page":"","description":"Low-threshold upper byte."}] |
| `register_description` | 0.0564 | 1.0 | "The RGBC clear-channel low threshold is used as the lower trigger point for interrupt comparison. An interrupt is asserted when the clear-channel result crosses below the lower threshold; low threshold evaluation occurs before high threshold evaluation." | "A 16-bit lower clear-channel threshold used for interrupt comparison. An interrupt can be generated when CDATA is below this threshold. Thresholds are evaluated low first and then high; if the low threshold is above the high threshold, the high threshold is ignored." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.981756 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "No separate prose reset-description field; byte order/reset semantics are shown by the register entries in Figure 24." | "AILTH is the upper byte and AILTL is the lower byte." |

Q_L = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.981756 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.994651 / 1.0001 = **0.994551**.

## Extracted logical register 6: `Clear interrupt high threshold (AIHTx)`

v1 location: `registers[5]` (JSON index=6); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 24, Fig. 29](../TCS3472.pdf).
Associated physical locations: 0x06 (6), 0x07 (7).

### Bottom layer: bit fields, then field parts

#### Field part 1: `AIHTL` at 0x06 (6)

Location: `registers[5].field_parts[0]` ↔ datasheet [Figure 29](../TCS3472.pdf).

**Bit field 1: `AIHTL`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "AIHTL" | "AIHTL" |
| `field_description` | 0.0586 | 1.0 | "RGBC clear channel high threshold lower byte." | "Lower byte of the RGBC clear-channel high threshold." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: all five direct field-part fields are semantically correct; where v1 uses a shorter address description, it has no functional deviation.

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "AIHTL" | "AIHTL" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x06","decimal":"6","bank":"","page":"","description":"Clear interrupt high threshold low byte"} | {"hex":"0x06","decimal":"6","bank":"","page":"","description":"High-threshold lower byte."} |
| `description` | 0.0693 | 1.0 | "RGBC clear-channel high-threshold lower byte." | "RGBC clear-channel high-threshold lower byte." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x1.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.981756**.

#### Field part 2: `AIHTH` at 0x07 (7)

Location: `registers[5].field_parts[1]` ↔ datasheet [Figure 29](../TCS3472.pdf).

**Bit field 1: `AIHTH`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "AIHTH" | "AIHTH" |
| `field_description` | 0.0586 | 1.0 | "RGBC clear channel high threshold upper byte." | "Upper byte of the RGBC clear-channel high threshold." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: all five direct field-part fields are semantically correct; where v1 uses a shorter address description, it has no functional deviation.

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "AIHTH" | "AIHTH" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":"Clear interrupt high threshold high byte"} | {"hex":"0x07","decimal":"7","bank":"","page":"","description":"High-threshold upper byte."} |
| `description` | 0.0693 | 1.0 | "RGBC clear-channel high-threshold upper byte." | "RGBC clear-channel high-threshold upper byte." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x1.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.981756**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.981756, 0.981756) = **0.981756**.
Judgment: the logical register, addresses, register description, width, R/W, defaults, and grouped field-part representation are semantically correct.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "Clear interrupt high threshold (AIHTx)" | "Clear interrupt high threshold (AIHTx)" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":"Clear interrupt high threshold low byte"},{"hex":"0x07","decimal":"7","bank":"","page":"","description":"Clear interrupt high threshold high byte"}] | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":"High-threshold lower byte."},{"hex":"0x07","decimal":"7","bank":"","page":"","description":"High-threshold upper byte."}] |
| `register_description` | 0.0564 | 1.0 | "The RGBC clear-channel high threshold is used as the higher trigger point for interrupt comparison. An interrupt is asserted when the clear-channel result crosses above the higher threshold; low threshold evaluation occurs before high threshold evaluation." | "A 16-bit upper clear-channel threshold used for interrupt comparison. An interrupt can be generated when CDATA is above this threshold. Thresholds are evaluated low first and then high; if the low threshold is above the high threshold, this high threshold is ignored." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.981756 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "No separate prose reset-description field; byte order/reset semantics are shown by the register entries in Figure 24." | "AIHTH is the upper byte and AIHTL is the lower byte." |

Q_L = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.981756 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.994651 / 1.0001 = **0.994551**.

## Extracted logical register 7: `PERS`

v1 location: `registers[6]` (JSON index=7); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 24, Fig. 30; printed p. 25 continuation](../TCS3472.pdf).
Associated physical locations: 0x0C (12).

### Bottom layer: bit fields, then field parts

#### Field part 1: `PERS` at 0x0C (12)

Location: `registers[6].field_parts[0]` ↔ datasheet [Figure 30; printed p. 25 continuation](../TCS3472.pdf).

**Bit field 1: `PPERS`, bits 7:4**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "PPERS" | "PPERS" |
| `field_description` | 0.0586 | 1.0 | "Reserved" | "Reserved." |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Bit field 2: `APERS`, bits 3:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "APERS" | "APERS" |
| `field_description` | 0.0586 | 1.0 | "Interrupt persistence. Controls rate of interrupt to the host processor." | "Interrupt persistence; controls the rate of interrupts to the host processor." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | [{"value":"0000","value_description":"Every RGBC cycle generates an interrupt"},{"value":"0001","value_description":"1 clear channel value outside of threshold range"},{"value":"0010","value_description":"2 clear channel consecutive values out of range"},{"value":"0011","value_description":"3 clear channel consecutive values out of range"},{"value":"0100","value_description":"5 clear channel consecutive values out of range"},{"value":"0101","value_description":"10 clear channel consecutive values out of range"},{"value":"0110","value_description":"15 clear channel consecutive values out of range"},{"value":"0111","value_description":"20 clear channel consecutive values out of range"},{"value":"1000","value_description":"25 clear channel consecutive values out of range"},{"value":"1001","value_description":"30 clear channel consecutive values out of range"},{"value":"1010","value_description":"35 clear channel consecutive values out of range"},{"value":"1011","value_description":"40 clear channel consecutive values out of range"},{"value":"1100","value_description":"45 clear channel consecutive values out of range"},{"value":"1101","value_description":"50 clear channel consecutive values out of range"},{"value":"1110","value_description":"55 clear channel consecutive values out of range"},{"value":"1111","value_description":"60 clear channel consecutive values out of range"}] | [{"value":"0000","value_description":"Every RGBC cycle generates an interrupt"},{"value":"0001","value_description":"1 clear-channel value outside the threshold range"},{"value":"0010","value_description":"2 consecutive clear-channel values outside the threshold range"},{"value":"0011","value_description":"3 consecutive clear-channel values outside the threshold range"},{"value":"0100","value_description":"5 consecutive clear-channel values outside the threshold range"},{"value":"0101","value_description":"10 consecutive clear-channel values outside the threshold range"},{"value":"0110","value_description":"15 consecutive clear-channel values outside the threshold range"},{"value":"0111","value_description":"20 consecutive clear-channel values outside the threshold range"},{"value":"1000","value_description":"25 consecutive clear-channel values outside the threshold range"},{"value":"1001","value_description":"30 consecutive clear-channel values outside the threshold range"},{"value":"1010","value_description":"35 consecutive clear-channel values outside the threshold range"},{"value":"1011","value_description":"40 consecutive clear-channel values outside the threshold range"},{"value":"1100","value_description":"45 consecutive clear-channel values outside the threshold range"},{"value":"1101","value_description":"50 consecutive clear-channel values outside the threshold range"},{"value":"1110","value_description":"55 consecutive clear-channel values outside the threshold range"},{"value":"1111","value_description":"60 consecutive clear-channel values outside the threshold range"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694) = **0.941694**.
Direct judgment: register_name, numeric address, width, and field-part R/W are correct; physical_address is partial because its description is empty (C=0.5), and the standalone field-part description is missing (C=0.0).

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "PERS" | "PERS" |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Interrupt persistence filter"} | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | "Interrupt persistence filter" | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x0.500000 + 0.0693x0.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.678056**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.
Judgment: every objective logical-register fact is correct, but the single physical_address object's description is omitted (C=0.5); the corresponding field-part description is also missing.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "PERS" | "PERS" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Interrupt persistence filter"}] | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | "The persistence register controls interrupt filtering, allowing interrupts after every integration cycle or after a selected number of consecutive clear-channel results outside the programmed threshold range." | "Controls interrupt filtering, allowing interrupts after every integration cycle or after a selected number of consecutive clear-channel results outside the programmed threshold range." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.678056 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "No separate reset-value description is printed in Figure 24." | "" |

Q_L = (0.0225x1.000000 + 0.4044x0.500000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.678056 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.701735 / 1.0001 = **0.701665**.

## Extracted logical register 8: `CONFIG`

v1 location: `registers[7]` (JSON index=8); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 25, Fig. 31](../TCS3472.pdf).
Associated physical locations: 0x0D (13).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CONFIG` at 0x0D (13)

Location: `registers[7].field_parts[0]` ↔ datasheet [Figure 31](../TCS3472.pdf).

**Bit field 1: `Reserved`, bits 7:2**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Reserved" | "Reserved" |
| `field_description` | 0.0586 | 1.0 | "Reserved. Write as 0." | "Reserved. Write as 0." |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Bit field 2: `WLONG`, bits 1:1**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "WLONG" | "WLONG" |
| `field_description` | 0.0586 | 1.0 | "Wait Long. When asserted, the wait cycles are increased by a factor 12x from that programmed in the WTIME register." | "Wait Long. When asserted, wait cycles are increased by 12× from the value programmed in WTIME." |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Bit field 3: `Reserved`, bits 0:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Reserved" | "Reserved" |
| `field_description` | 0.0586 | 1.0 | "Reserved. Write as 0." | "Reserved. Write as 0." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694) = **0.941694**.
Direct judgment: register_name, numeric address, width, and field-part R/W are correct; physical_address is partial because its description is empty (C=0.5), and the standalone field-part description is missing (C=0.0).

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "CONFIG" | "CONFIG" |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Configuration"} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | "Configuration" | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x0.500000 + 0.0693x0.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.678056**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.
Judgment: every objective logical-register fact is correct, but the single physical_address object's description is omitted (C=0.5); the corresponding field-part description is also missing.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "CONFIG" | "CONFIG" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Configuration"}] | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | "The configuration register sets the wait long time." | "Configures long wait timing. Asserting WLONG increases wait cycles by a factor of 12 relative to the value programmed in WTIME." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.678056 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "No separate reset-value description is printed in Figure 24." | "" |

Q_L = (0.0225x1.000000 + 0.4044x0.500000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.678056 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.701735 / 1.0001 = **0.701665**.

## Extracted logical register 9: `CONTROL`

v1 location: `registers[8]` (JSON index=9); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 26, Fig. 32](../TCS3472.pdf).
Associated physical locations: 0x0F (15).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CONTROL` at 0x0F (15)

Location: `registers[8].field_parts[0]` ↔ datasheet [Figure 32](../TCS3472.pdf).

**Bit field 1: `Reserved`, bits 7:2**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Reserved" | "Reserved" |
| `field_description` | 0.0586 | 1.0 | "Reserved. Write as 0." | "Reserved. Write as 0." |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Bit field 2: `AGAIN`, bits 1:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "AGAIN" | "AGAIN" |
| `field_description` | 0.0586 | 1.0 | "RGBC Gain Control." | "RGBC Gain Control." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"1x gain"},{"value":"01","value_description":"4x gain"},{"value":"10","value_description":"16x gain"},{"value":"11","value_description":"60x gain"}] | [{"value":"00","value_description":"1x gain"},{"value":"01","value_description":"4x gain"},{"value":"10","value_description":"16x gain"},{"value":"11","value_description":"60x gain"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694) = **0.941694**.
Direct judgment: register_name, numeric address, width, and field-part R/W are correct; physical_address is partial because its description is empty (C=0.5), and the standalone field-part description is missing (C=0.0).

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "CONTROL" | "CONTROL" |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Control"} | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | "Control" | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x0.500000 + 0.0693x0.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.678056**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.
Judgment: every objective logical-register fact is correct, but the single physical_address object's description is omitted (C=0.5); the corresponding field-part description is also missing.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "CONTROL" | "CONTROL" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"Control"}] | [{"hex":"0x0F","decimal":"15","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | "The Control register provides eight bits of miscellaneous control to the analog block. These bits typically control functions such as gain settings and/or diode selection." | "Provides miscellaneous control of the analog block; the defined AGAIN field selects RGBC gain." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.678056 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "No separate reset-value description is printed in Figure 24." | "" |

Q_L = (0.0225x1.000000 + 0.4044x0.500000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.678056 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.701735 / 1.0001 = **0.701665**.

## Extracted logical register 10: `ID`

v1 location: `registers[9]` (JSON index=10); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 27, Fig. 33](../TCS3472.pdf).
Associated physical locations: 0x12 (18).

### Bottom layer: bit fields, then field parts

#### Field part 1: `ID` at 0x12 (18)

Location: `registers[9].field_parts[0]` ↔ datasheet [Figure 33](../TCS3472.pdf).

**Bit field 1: `ID`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "ID" | "ID" |
| `field_description` | 0.0586 | 1.0 | "Part number identification" | "Part number identification." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [{"value":"0x44","value_description":"TCS34725"},{"value":"0x4D","value_description":"TCS34727"}] | [{"value":"0x44","value_description":"TCS34725"},{"value":"0x4D","value_description":"TCS34727"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: register_name, numeric address, width, and field-part R/W are correct; physical_address is partial because its description is empty (C=0.5), and the standalone field-part description is missing (C=0.0).

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "ID" | "ID" |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"Device ID"} | {"hex":"0x12","decimal":"18","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | "Device ID" | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x0.500000 + 0.0693x0.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.678056**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.
Judgment: every objective logical-register fact is correct, but the single physical_address object's description is omitted (C=0.5); the corresponding field-part description is also missing.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "ID" | "ID" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x12","decimal":"18","bank":"","page":"","description":"Device ID"}] | [{"hex":"0x12","decimal":"18","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | "The ID Register provides the value for the part number. The ID register is a read-only register." | "Read-only part-number identification register." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.678056 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "ID" | "ID" |
| `default_value_description` | 0.0334 | 1.0 | "No separate reset-value description is printed in Figure 24." | "" |

Q_L = (0.0225x1.000000 + 0.4044x0.500000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.678056 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.701735 / 1.0001 = **0.701665**.

## Extracted logical register 11: `STATUS`

v1 location: `registers[10]` (JSON index=11); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 27, Fig. 34](../TCS3472.pdf).
Associated physical locations: 0x13 (19).

### Bottom layer: bit fields, then field parts

#### Field part 1: `STATUS` at 0x13 (19)

Location: `registers[10].field_parts[0]` ↔ datasheet [Figure 34](../TCS3472.pdf).

**Bit field 1: `Reserved`, bits 7:5**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Reserved" | "Reserved" |
| `field_description` | 0.0586 | 1.0 | "Reserved." | "Reserved." |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Bit field 2: `AINT`, bits 4:4**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "AINT" | "AINT" |
| `field_description` | 0.0586 | 1.0 | "RGBC clear channel Interrupt." | "RGBC clear-channel interrupt status." |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Bit field 3: `Reserved`, bits 3:1**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Reserved" | "Reserved" |
| `field_description` | 0.0586 | 1.0 | "Reserved." | "Reserved." |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Bit field 4: `AVALID`, bits 0:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "AVALID" | "AVALID" |
| `field_description` | 0.0586 | 1.0 | "RGBC Valid. Indicates that the RGBC channels have completed an integration cycle." | "Indicates that the RGBC channels have completed an integration cycle." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694, 0.941694, 0.941694, 0.941694) = **0.941694**.
Direct judgment: register_name, numeric address, width, and field-part R/W are correct; physical_address is partial because its description is empty (C=0.5), and the standalone field-part description is missing (C=0.0).

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "STATUS" | "STATUS" |
| `physical_address` | 0.4688 | 0.5 | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Device status"} | {"hex":"0x13","decimal":"19","bank":"","page":"","description":""} |
| `description` | 0.0693 | 0.0 | "Device status" | "" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x0.500000 + 0.0693x0.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.678056**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.678056) = **0.678056**.
Judgment: every objective logical-register fact is correct, but the single physical_address object's description is omitted (C=0.5); the corresponding field-part description is also missing.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "STATUS" | "STATUS" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x13","decimal":"19","bank":"","page":"","description":"Device status"}] | [{"hex":"0x13","decimal":"19","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | "The Status Register provides the internal status of the device. This register is read only." | "Read-only internal status register reporting the RGBC clear-channel interrupt state and completion of an RGBC integration cycle." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.678056 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "No separate reset-value description is printed in Figure 24." | "" |

Q_L = (0.0225x1.000000 + 0.4044x0.500000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.678056 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.701735 / 1.0001 = **0.701665**.

## Extracted logical register 12: `CDATA`

v1 location: `registers[11]` (JSON index=12); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 28, Fig. 35](../TCS3472.pdf).
Associated physical locations: 0x14 (20), 0x15 (21).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CDATAL` at 0x14 (20)

Location: `registers[11].field_parts[0]` ↔ datasheet [Figure 35](../TCS3472.pdf).

**Bit field 1: `CDATAL`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "CDATAL" | "CDATAL" |
| `field_description` | 0.0586 | 1.0 | "Clear data low byte." | "Clear data low byte." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: all five direct field-part fields are semantically correct; where v1 uses a shorter address description, it has no functional deviation.

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "CDATAL" | "CDATAL" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Clear data low byte"} | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Clear data low byte."} |
| `description` | 0.0693 | 1.0 | "Clear data low byte." | "Clear data low byte." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x1.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.981756**.

#### Field part 2: `CDATAH` at 0x15 (21)

Location: `registers[11].field_parts[1]` ↔ datasheet [Figure 35](../TCS3472.pdf).

**Bit field 1: `CDATAH`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "CDATAH" | "CDATAH" |
| `field_description` | 0.0586 | 1.0 | "Clear data high byte." | "Clear data high byte." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: all five direct field-part fields are semantically correct; where v1 uses a shorter address description, it has no functional deviation.

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "CDATAH" | "CDATAH" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Clear data high byte"} | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"Clear data high byte."} |
| `description` | 0.0693 | 1.0 | "Clear data high byte." | "Clear data high byte." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x1.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.981756**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.981756, 0.981756) = **0.981756**.
Judgment: the logical register, addresses, register description, width, R/W, defaults, and grouped field-part representation are semantically correct.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "CDATA" | "CDATA" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x14","decimal":"20","bank":"","page":"","description":"Clear data low byte"},{"hex":"0x15","decimal":"21","bank":"","page":"","description":"Clear data high byte"}] | [{"hex":"0x14","decimal":"20","bank":"","page":"","description":"Clear data low byte."},{"hex":"0x15","decimal":"21","bank":"","page":"","description":"Clear data high byte."}] |
| `register_description` | 0.0564 | 1.0 | "Stores the 16-bit clear data conversion result. A two-byte read-word I2C transaction should be used; reading the low byte captures the upper byte in a shadow register for the subsequent high-byte read." | "Stores the 16-bit clear-channel conversion result. Use a two-byte I²C read transaction with the read-word protocol bit set in COMMAND; reading the low byte captures the upper byte in a shadow register for the subsequent high-byte read." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.981756 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "No separate prose reset-description field; byte order/reset semantics are shown by the register entries in Figure 24." | "CDATAH is the high byte and CDATAL is the low byte." |

Q_L = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.981756 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.994651 / 1.0001 = **0.994551**.

## Extracted logical register 13: `RDATA`

v1 location: `registers[12]` (JSON index=13); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 28, Fig. 35](../TCS3472.pdf).
Associated physical locations: 0x16 (22), 0x17 (23).

### Bottom layer: bit fields, then field parts

#### Field part 1: `RDATAL` at 0x16 (22)

Location: `registers[12].field_parts[0]` ↔ datasheet [Figure 35](../TCS3472.pdf).

**Bit field 1: `RDATAL`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "RDATAL" | "RDATAL" |
| `field_description` | 0.0586 | 1.0 | "Red data low byte." | "Red data low byte." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: all five direct field-part fields are semantically correct; where v1 uses a shorter address description, it has no functional deviation.

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "RDATAL" | "RDATAL" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"Red data low byte"} | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"Red data low byte."} |
| `description` | 0.0693 | 1.0 | "Red data low byte." | "Red data low byte." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x1.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.981756**.

#### Field part 2: `RDATAH` at 0x17 (23)

Location: `registers[12].field_parts[1]` ↔ datasheet [Figure 35](../TCS3472.pdf).

**Bit field 1: `RDATAH`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "RDATAH" | "RDATAH" |
| `field_description` | 0.0586 | 1.0 | "Red data high byte." | "Red data high byte." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: all five direct field-part fields are semantically correct; where v1 uses a shorter address description, it has no functional deviation.

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "RDATAH" | "RDATAH" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Red data high byte"} | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Red data high byte."} |
| `description` | 0.0693 | 1.0 | "Red data high byte." | "Red data high byte." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x1.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.981756**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.981756, 0.981756) = **0.981756**.
Judgment: the logical register, addresses, register description, width, R/W, defaults, and grouped field-part representation are semantically correct.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "RDATA" | "RDATA" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x16","decimal":"22","bank":"","page":"","description":"Red data low byte"},{"hex":"0x17","decimal":"23","bank":"","page":"","description":"Red data high byte"}] | [{"hex":"0x16","decimal":"22","bank":"","page":"","description":"Red data low byte."},{"hex":"0x17","decimal":"23","bank":"","page":"","description":"Red data high byte."}] |
| `register_description` | 0.0564 | 1.0 | "Stores the 16-bit red data conversion result. A two-byte read-word I2C transaction should be used; reading the low byte captures the upper byte in a shadow register for the subsequent high-byte read." | "Stores the 16-bit red-channel conversion result. Use a two-byte I²C read transaction with the read-word protocol bit set in COMMAND; reading the low byte captures the upper byte in a shadow register for the subsequent high-byte read." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.981756 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "No separate prose reset-description field; byte order/reset semantics are shown by the register entries in Figure 24." | "RDATAH is the high byte and RDATAL is the low byte." |

Q_L = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.981756 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.994651 / 1.0001 = **0.994551**.

## Extracted logical register 14: `GDATA`

v1 location: `registers[13]` (JSON index=14); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 28, Fig. 35](../TCS3472.pdf).
Associated physical locations: 0x18 (24), 0x19 (25).

### Bottom layer: bit fields, then field parts

#### Field part 1: `GDATAL` at 0x18 (24)

Location: `registers[13].field_parts[0]` ↔ datasheet [Figure 35](../TCS3472.pdf).

**Bit field 1: `GDATAL`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "GDATAL" | "GDATAL" |
| `field_description` | 0.0586 | 1.0 | "Green data low byte." | "Green data low byte." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: all five direct field-part fields are semantically correct; where v1 uses a shorter address description, it has no functional deviation.

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "GDATAL" | "GDATAL" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Green data low byte"} | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Green data low byte."} |
| `description` | 0.0693 | 1.0 | "Green data low byte." | "Green data low byte." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x1.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.981756**.

#### Field part 2: `GDATAH` at 0x19 (25)

Location: `registers[13].field_parts[1]` ↔ datasheet [Figure 35](../TCS3472.pdf).

**Bit field 1: `GDATAH`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "GDATAH" | "GDATAH" |
| `field_description` | 0.0586 | 1.0 | "Green data high byte." | "Green data high byte." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: all five direct field-part fields are semantically correct; where v1 uses a shorter address description, it has no functional deviation.

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "GDATAH" | "GDATAH" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x19","decimal":"25","bank":"","page":"","description":"Green data high byte"} | {"hex":"0x19","decimal":"25","bank":"","page":"","description":"Green data high byte."} |
| `description` | 0.0693 | 1.0 | "Green data high byte." | "Green data high byte." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x1.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.981756**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.981756, 0.981756) = **0.981756**.
Judgment: the logical register, addresses, register description, width, R/W, defaults, and grouped field-part representation are semantically correct.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "GDATA" | "GDATA" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x18","decimal":"24","bank":"","page":"","description":"Green data low byte"},{"hex":"0x19","decimal":"25","bank":"","page":"","description":"Green data high byte"}] | [{"hex":"0x18","decimal":"24","bank":"","page":"","description":"Green data low byte."},{"hex":"0x19","decimal":"25","bank":"","page":"","description":"Green data high byte."}] |
| `register_description` | 0.0564 | 1.0 | "Stores the 16-bit green data conversion result. A two-byte read-word I2C transaction should be used; reading the low byte captures the upper byte in a shadow register for the subsequent high-byte read." | "Stores the 16-bit green-channel conversion result. Use a two-byte I²C read transaction with the read-word protocol bit set in COMMAND; reading the low byte captures the upper byte in a shadow register for the subsequent high-byte read." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.981756 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "No separate prose reset-description field; byte order/reset semantics are shown by the register entries in Figure 24." | "GDATAH is the high byte and GDATAL is the low byte." |

Q_L = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.981756 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.994651 / 1.0001 = **0.994551**.

## Extracted logical register 15: `BDATA`

v1 location: `registers[14]` (JSON index=15); datasheet source: [TCS3472 datasheet v1-04, printed p. 20, Fig. 24; printed p. 28, Fig. 35](../TCS3472.pdf).
Associated physical locations: 0x1A (26), 0x1B (27).

### Bottom layer: bit fields, then field parts

#### Field part 1: `BDATAL` at 0x1A (26)

Location: `registers[14].field_parts[0]` ↔ datasheet [Figure 35](../TCS3472.pdf).

**Bit field 1: `BDATAL`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "BDATAL" | "BDATAL" |
| `field_description` | 0.0586 | 1.0 | "Blue data low byte." | "Blue data low byte." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: all five direct field-part fields are semantically correct; where v1 uses a shorter address description, it has no functional deviation.

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "BDATAL" | "BDATAL" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Blue data low byte"} | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Blue data low byte."} |
| `description` | 0.0693 | 1.0 | "Blue data low byte." | "Blue data low byte." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x1.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.981756**.

#### Field part 2: `BDATAH` at 0x1B (27)

Location: `registers[14].field_parts[1]` ↔ datasheet [Figure 35](../TCS3472.pdf).

**Bit field 1: `BDATAH`, bits 7:0**

Judgment: the objective bit range, width, reserved flag, and explicit value set are correct. The wording is semantically correct; bit-level type_write_read is empty in v1 and receives no credit because the datasheet does not provide a per-bit R/W value.

| Scored field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "BDATAH" | "BDATAH" |
| `field_description` | 0.0586 | 1.0 | "Blue data high byte." | "Blue data high byte." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "" | "" |

Q_BF = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0) / 0.9999 = 0.941600 / 0.9999 = **0.941694**.

**Field-part aggregation**

bit_field correctness = mean(0.941694) = **0.941694**.
Direct judgment: all five direct field-part fields are semantically correct; where v1 uses a shorter address description, it has no functional deviation.

| Field-part field | Weight | Correctness | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "BDATAH" | "BDATAH" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Blue data high byte"} | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Blue data high byte."} |
| `description` | 0.0693 | 1.0 | "Blue data high byte." | "Blue data high byte." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.941694 | "datasheet bit-field set" | "v1 bit-field set" |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x1.000000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.941694 = **0.981756**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.981756, 0.981756) = **0.981756**.
Judgment: the logical register, addresses, register description, width, R/W, defaults, and grouped field-part representation are semantically correct.

| Logical-register field | Weight | Correctness | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "BDATA" | "BDATA" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Blue data low byte"},{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Blue data high byte"}] | [{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Blue data low byte."},{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Blue data high byte."}] |
| `register_description` | 0.0564 | 1.0 | "Stores the 16-bit blue data conversion result. A two-byte read-word I2C transaction should be used; reading the low byte captures the upper byte in a shadow register for the subsequent high-byte read." | "Stores the 16-bit blue-channel conversion result. Use a two-byte I²C read transaction with the read-word protocol bit set in COMMAND; reading the low byte captures the upper byte in a shadow register for the subsequent high-byte read." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.981756 | "corresponding datasheet field-part collection" | "v1 field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "No separate prose reset-description field; byte order/reset semantics are shown by the register entries in Figure 24." | "BDATAH is the high byte and BDATAL is the low byte." |

Q_L = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.981756 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = 0.994651 / 1.0001 = **0.994551**.

## 2. Ground-truth physical-register scores

For every datasheet register entry R, q_R is the mean of Q(L) for all associated extracted logical registers. Every physical location is matched exactly once; the addressless COMMAND entry is represented by the source key COMMAND/--. Therefore there are no missing or extra physical register entries.

| Datasheet physical register key | Associated extracted logical register(s) and Q(L) | q_R |
|---|---|---:|
| -- (COMMAND) | v1 `registers[0]` `COMMAND` = 0.988018 | 0.988018 |
| 0x00 (0) | v1 `registers[1]` `ENABLE` = 0.701665 | 0.701665 |
| 0x01 (1) | v1 `registers[2]` `ATIME` = 0.701665 | 0.701665 |
| 0x03 (3) | v1 `registers[3]` `WTIME` = 0.701665 | 0.701665 |
| 0x04 (4) | v1 `registers[4]` `Clear interrupt low threshold (AILTx)` = 0.994551 | 0.994551 |
| 0x05 (5) | v1 `registers[4]` `Clear interrupt low threshold (AILTx)` = 0.994551 | 0.994551 |
| 0x06 (6) | v1 `registers[5]` `Clear interrupt high threshold (AIHTx)` = 0.994551 | 0.994551 |
| 0x07 (7) | v1 `registers[5]` `Clear interrupt high threshold (AIHTx)` = 0.994551 | 0.994551 |
| 0x0C (12) | v1 `registers[6]` `PERS` = 0.701665 | 0.701665 |
| 0x0D (13) | v1 `registers[7]` `CONFIG` = 0.701665 | 0.701665 |
| 0x0F (15) | v1 `registers[8]` `CONTROL` = 0.701665 | 0.701665 |
| 0x12 (18) | v1 `registers[9]` `ID` = 0.701665 | 0.701665 |
| 0x13 (19) | v1 `registers[10]` `STATUS` = 0.701665 | 0.701665 |
| 0x14 (20) | v1 `registers[11]` `CDATA` = 0.994551 | 0.994551 |
| 0x15 (21) | v1 `registers[11]` `CDATA` = 0.994551 | 0.994551 |
| 0x16 (22) | v1 `registers[12]` `RDATA` = 0.994551 | 0.994551 |
| 0x17 (23) | v1 `registers[12]` `RDATA` = 0.994551 | 0.994551 |
| 0x18 (24) | v1 `registers[13]` `GDATA` = 0.994551 | 0.994551 |
| 0x19 (25) | v1 `registers[13]` `GDATA` = 0.994551 | 0.994551 |
| 0x1A (26) | v1 `registers[14]` `BDATA` = 0.994551 | 0.994551 |
| 0x1B (27) | v1 `registers[14]` `BDATA` = 0.994551 | 0.994551 |

sum(q_R) = **18.535952675**.

m = 21 matched extracted physical registers; x = 0 extra extracted physical registers; m/(m+x) = 21/21 = 1.000000.

S_final = (10/21 x 18.535952675) x 21/21 = **8.826644131/10**.

## 3. Detailed deduction inventory

1. v1 registers[1], registers[2], registers[3], registers[6], registers[7], registers[8], registers[9], and registers[10] have the correct numeric physical addresses but empty physical_address.description and empty field_parts[0].description. The corresponding Figure 24 Register Function entries are, respectively, Enables states and interrupts; RGBC time; Wait time; Interrupt persistence filter; Configuration; Control; Device ID; and Device status. The physical_address field is scored partial (C=0.5), while each missing standalone field-part description is C=0.0.
2. v1 registers[0].field_parts[0].bit_field[0] (COMMAND.CMD, path registers[0].field_parts[0].bit_field[0]) omits values=[1] even though Figure 25 states that CMD must be written as 1 when addressing COMMAND. The fact is present in field_description, but the scored values field itself is empty and receives C=0.0.
3. All 35 v1 bit-field objects leave type_write_read empty. Figure 24 specifies R/W at register level and Figures 25-35 do not provide an independent per-bit R/W column. Under the stated deepest-field convention this field receives no credit for every bit field; all register-level and field-part R/W values are correct.
4. No objective range, bit width, reserved flag, register width, numeric address, register-level R/W value, reset value, or explicit enumerated value set is otherwise wrong. The threshold and channel-data multi-address groupings are accepted under the equivalent merge/split rule.
5. The datasheet's addressless COMMAND entry is not treated as a fabricated numeric location. It is counted once as COMMAND/--, matched to v1 registers[0], and does not create an extra-address penalty.

## 4. Invented-field check

- No extra physical address is present in v1; all 20 numeric datasheet addresses and the addressless COMMAND entry are covered.
- No unmatched bit-field range or incorrect reserved/non-reserved classification is present.
- No value code outside the datasheet set is introduced. The only value issue is the omission of the explicit CMD=1 value from v1.values.
- Descriptive paraphrases such as RGBC ADC, clear-channel threshold wording, and the channel-data shadow-register explanation do not introduce functional deviations and receive full descriptive credit where present.
