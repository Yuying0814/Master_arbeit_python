# TMP4719 v1.0 detailed score — datasheet-based audit

## 1. Scoring basis and datasheet source

- Candidate result: `TMP4719/v1_0/register_map.json`; all JSON locations below are zero-based array paths.
- Datasheet reference D1: Texas Instruments, **TMP4719 High-Accuracy 3-Channel (2-Remote and 1-Local) 1.2V Logic Compatible Temperature Sensor With η-Factor**, document **SBOSAJ7A**, October 2025, revised December 2025. Local source: `D:\python\master_arbeit\data\output\TMP4719\TMP4719.pdf`.
- All page numbers are printed datasheet page numbers. Register addresses, access types, reset values, bit positions, and field meanings are taken from D1 §8, Tables 8-1 through 8-39; the 12-bit remote data-format fact is also checked against D1 §7.5.1, Table 7-1.
- This report compares v1 directly with D1; no truth JSON is used.

### Physical-register accounting

- `n=42` : D1 Table 8-1 exposes 36 primary register-address entries plus six shared-address entries (09h, 0Ah, 0Bh, 0Ch, 0Dh, 0Eh). Following the scoring key of numeric address plus bank/page, each listed address entry is counted once. A shared address is a valid alternate access entry for the same storage and is not an extra extracted register.
- `m=42` : every one of the 42 D1 address entries is represented in v1.
- `x=0` : v1 contains no physical address outside D1 Table 8-1.
- The six merged v1 logical registers containing 12-bit quantities are accepted as equivalent logical groupings. Their valid logical width is nevertheless 12 bits, not the 16 physical container bits.

### Correctness and normalization

- `C=1.0` means complete agreement; `C=0.5` means partial/incomplete agreement; `C=0` means wrong or missing.
- Description wording is judged by functional meaning. Correct paraphrases and correct additional context receive full credit.
- A reserved bit may have an empty name/description, but D1 still specifies its access type as `R`; an empty v1 `type_write_read` is missing.
- For the two `RC` registers, v1's `R` preserves read access but omits read-to-clear behavior, so the access-type field is partial (`C=0.5`), not fully correct.
- Rounded AHP weights are normalized as in the example report: bit-field denominator `0.9999`, logical-register denominator `1.0001`; field-part weights sum to 1.0000.

| Object | Scored fields and weights |
|---|---|
| `logical_register` | `name` 0.0225; `physical_address` 0.4044; `register_description` 0.0564; `width_bits` 0.0590; `type_write_read` 0.0590; `field_parts` 0.2987; `default_value` 0.0667; `default_value_description` 0.0334 |
| `field_part` | `register_name` 0.0280; `physical_address` 0.4688; `description` 0.0693; `width_bits` 0.0605; `type_write_read` 0.0605; `bit_field` 0.3129 |
| `bit_field` | `name_or_parameter` 0.0212; `field_description` 0.0586; `bit_start` 0.2594; `bit_end` 0.2594; `bit_width` 0.0583; `values` 0.2097; `is_reserved` 0.0750; `type_write_read` 0.0583 |

## 2. Logical-register calculations

Every v1 logical register is calculated independently from the bottom up: all bit fields, then each field part, then the logical-register sum.

### Logical-register score summary

| v1 path | logical name | D1 address entries | D1 width | v1 width | v1 type | Q(L) |
|---|---|---:|---:|---:|---|---:|
| `registers[0]` | `Temp_Local` | 1 | 8 | 8 | R | **1.000000** |
| `registers[1]` | `Temp_Remote_Ch1` | 2 | 12 | 16 | R | **0.939644** |
| `registers[2]` | `Status` | 1 | 8 | 8 | R | **0.998443** |
| `registers[3]` | `Configuration` | 2 | 8 | 8 | RW | **0.998638** |
| `registers[4]` | `Conv_Period` | 2 | 8 | 8 | RW | **0.997276** |
| `registers[5]` | `THigh_Limit_Local` | 2 | 8 | 8 | RW | **1.000000** |
| `registers[6]` | `TLow_Limit_Local` | 2 | 8 | 8 | RW | **1.000000** |
| `registers[7]` | `THigh_Limit_Remote_Ch1` | 3 | 12 | 16 | RW | **0.940098** |
| `registers[8]` | `TLow_Limit_Remote_Ch1` | 3 | 12 | 16 | RW | **0.940098** |
| `registers[9]` | `One_Shot` | 1 | 8 | 8 | W | **1.000000** |
| `registers[10]` | `Scratchpad1` | 1 | 8 | 8 | RW | **1.000000** |
| `registers[11]` | `Scratchpad2` | 1 | 8 | 8 | RW | **1.000000** |
| `registers[12]` | `THigh_Limit_Remote_Ch2` | 2 | 12 | 16 | RW | **0.939644** |
| `registers[13]` | `TLow_Limit_Remote_Ch2` | 2 | 12 | 16 | RW | **0.939644** |
| `registers[14]` | `THigh_Crit_Remote_Ch1` | 1 | 8 | 8 | RW | **1.000000** |
| `registers[15]` | `THigh_Crit_Remote_Ch2` | 1 | 8 | 8 | RW | **1.000000** |
| `registers[16]` | `Diode_Fault` | 1 | 8 | 8 | R | **0.997820** |
| `registers[17]` | `Alert_Mask` | 1 | 8 | 8 | RW | **0.998638** |
| `registers[18]` | `THigh_Crit_Local` | 1 | 8 | 8 | RW | **1.000000** |
| `registers[19]` | `Hysteresis` | 1 | 8 | 8 | RW | **0.997276** |
| `registers[20]` | `Temp_Remote_Ch2` | 2 | 12 | 16 | R | **0.939644** |
| `registers[21]` | `η-Factor_Ch1` | 1 | 8 | 8 | RW | **1.000000** |
| `registers[22]` | `η-Factor_Ch2` | 1 | 8 | 8 | RW | **1.000000** |
| `registers[23]` | `High_Limit_Status` | 1 | 8 | 8 | R | **0.958063** |
| `registers[24]` | `Low_Limit_Status` | 1 | 8 | 8 | R | **0.958063** |
| `registers[25]` | `TCRIT_Limit_Status` | 1 | 8 | 8 | R | **0.998638** |
| `registers[26]` | `Filter_Control` | 1 | 8 | 8 | RW | **0.997276** |
| `registers[27]` | `Chip_ID` | 1 | 8 | 8 | R | **1.000000** |
| `registers[28]` | `Vendor_ID` | 1 | 8 | 8 | R | **1.000000** |
| `registers[29]` | `Device_Rev_ID` | 1 | 8 | 8 | R | **1.000000** |

## Extracted logical register 1: `Temp_Local`

v1 location: `registers[0]`; datasheet association: D1 §8.1, p.27, Table 8-3; §7.5.1, p.19, Table 7-2.

Associated physical address entries: 0x00 (0).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Temp_Local` at `0x00` (0)

Location: `registers[0].field_parts[0]`; source: D1 §8.1, p.27, Table 8-3; §7.5.1, p.19, Table 7-2.

**Truth bit field 1: `Temp_Local[7:0]` bits 0:7**

Location: `registers[0].field_parts[0].bit_field[0]`; D1 source: D1 §8.1, p.27, Table 8-3; §7.5.1, p.19, Table 7-2.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Temp_Local[7:0] | Temp_Local[7:0] |
| `field_description` | 0.0586 | 1.0 | 8-bit local temperature conversion result in two's-complement format with an LSB of 1°C. | 8-bit local temperature conversion result in two's-complement format with an LSB of 1°C. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | same nine examples as D1 Table 7-2: [{"value":"80","value_description":"-128°C"},{"value":"E6","value_description":"-25°C"},{"value":"FD","value_description":"-2°C"},{"value":"FE","value_description":"-1°C"},{"value":"00","value_description":"0°C"},{"value":"01","value_description":"1°C"},{"value":"02","value_description":"2°C"},{"value":"19","value_description":"25°C"},{"value":"7F","value_description":"127°C"}] | [{"value":"80","value_description":"-128°C"},{"value":"E6","value_description":"-25°C"},{"value":"FD","value_description":"-2°C"},{"value":"FE","value_description":"-1°C"},{"value":"00","value_description":"0°C"},{"value":"01","value_description":"1°C"},{"value":"02","value_description":"2°C"},{"value":"19","value_description":"25°C"},{"value":"7F","value_description":"127°C"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Temp_Local | Temp_Local |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Local temperature conversion result register."} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Local temperature conversion result register."} |
| `description` | 0.0693 | 1.0 | Latest local conversion result; 8-bit two's-complement with 1°C LSB; POR pointer defaults to 0h. | 8-bit local temperature result. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Temp_Local[7:0]","field_description":"8-bit local temperature conversion result in two's-complement format with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"80","value_description":"-128°C"},{"value":"E6","value_description":"-25°C"},{"value":"FD","value_description":"-2°C"},{"value":"FE","value_description":"-1°C"},{"value":"00","value_description":"0°C"},{"value":"01","value_description":"1°C"},{"value":"02","value_description":"2°C"},{"value":"19","value_description":"25°C"},{"value":"7F","value_description":"127°C"}],"is_reserved":false,"type_write_read":"R"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Temp_Local | Temp_Local |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Local temperature conversion result register."}] | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Local temperature conversion result register."}] |
| `register_description` | 0.0564 | 1.0 | Latest local conversion result; 8-bit two's-complement with 1°C LSB; POR pointer defaults to 0h. | Stores the latest local temperature conversion result as an 8-bit two's-complement value with an LSB of 1°C. After POR, the register pointer defaults to 0h, allowing this register to be read without first setting the pointer. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Temp_Local","physical_address":{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Local temperature conversion result register."},"description":"8-bit local temperature result.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Temp_Local[7:0]","field_description":"8-bit local temperature conversion result in two's-complement format with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"80","value_description":"-128°C"},{"value":"E6","value_description":"-25°C"},{"value":"FD","value_description":"-2°C"},{"value":"FE","value_description":"-1°C"},{"value":"00","value_description":"0°C"},{"value":"01","value_description":"1°C"},{"value":"02","value_description":"2°C"},{"value":"19","value_description":"25°C"},{"value":"7F","value_description":"127°C"}],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | Reset value. | Reset value. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## Extracted logical register 2: `Temp_Remote_Ch1`

v1 location: `registers[1]`; datasheet association: D1 §8.2 p.27 Table 8-4; §8.11 p.33 Table 8-13; §7.5.1 p.19 Table 7-1.

Associated physical address entries: 0x01 (1), 0x10 (16).

Audit findings for this logical register: v1 `width_bits=16` is wrong; D1 defines a 12-bit logical quantity. 1 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Temp_Remote_Ch1_High` at `0x01` (1)

Location: `registers[1].field_parts[0]`; source: D1 §8.2 p.27 Table 8-4; §8.11 p.33 Table 8-13; §7.5.1 p.19 Table 7-1.

**Truth bit field 1: `Temp_Remote_Ch1[11:4]` bits 0:7**

Location: `registers[1].field_parts[0].bit_field[0]`; D1 source: D1 §8.2 p.27 Table 8-4; §8.11 p.33 Table 8-13; §7.5.1 p.19 Table 7-1.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Temp_Remote_Ch1[11:4] | Temp_Remote_Ch1[11:4] |
| `field_description` | 0.0586 | 1.0 | Bits 11:4 of the 12-bit remote channel 1 temperature result. | Bits 11:4 of the 12-bit remote channel 1 temperature result. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Temp_Remote_Ch1_High | Temp_Remote_Ch1_High |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"High byte containing remote channel 1 result bits 11:4."} | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"High byte containing remote channel 1 result bits 11:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-1 temperature result split between 01h and 10h; 0.0625°C LSB; low-byte bits 3:0 reserved. | High byte of the remote channel 1 temperature result. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Temp_Remote_Ch1[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 1 temperature result.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

#### Field part 2: `Temp_Remote_Ch1_Low` at `0x10` (16)

Location: `registers[1].field_parts[1]`; source: D1 §8.2 p.27 Table 8-4; §8.11 p.33 Table 8-13; §7.5.1 p.19 Table 7-1.

**Truth bit field 1: `Temp_Remote_Ch1_Low[3:0]` bits 4:7**

Location: `registers[1].field_parts[1].bit_field[0]`; D1 source: D1 §8.2 p.27 Table 8-4; §8.11 p.33 Table 8-13; §7.5.1 p.19 Table 7-1.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Temp_Remote_Ch1_Low[3:0] | Temp_Remote_Ch1_Low[3:0] |
| `field_description` | 0.0586 | 1.0 | Bits 3:0 of the 12-bit result, stored in physical register bits 7:4. | Bits 3:0 of the 12-bit result, stored in physical register bits 7:4. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 2: `Reserved` bits 0:3**

Location: `registers[1].field_parts[1].bit_field[1]`; D1 source: D1 §8.2 p.27 Table 8-4; §8.11 p.33 Table 8-13; §7.5.1 p.19 Table 7-1. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 0.941694) = **0.970847**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Temp_Remote_Ch1_Low | Temp_Remote_Ch1_Low |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"Low-byte register containing remote channel 1 result bits 3:0 in register bits 7:4."} | {"hex":"0x10","decimal":"16","bank":"","page":"","description":"Low-byte register containing remote channel 1 result bits 3:0 in register bits 7:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-1 temperature result split between 01h and 10h; 0.0625°C LSB; low-byte bits 3:0 reserved. | Low-byte register for the remote channel 1 temperature result. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.970847 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Temp_Remote_Ch1_Low[3:0]","field_description":"Bits 3:0 of the 12-bit result, stored in physical register bits 7:4.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.970847) = 0.990878.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 0.990878) = **0.995439**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | equivalent merged name accepted; D1 splits the high/low access entries | Temp_Remote_Ch1 |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":"High byte containing remote channel 1 result bits 11:4."},{"hex":"0x10","decimal":"16","bank":"","page":"","description":"Low-byte register containing remote channel 1 result bits 3:0 in register bits 7:4."}] | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":"High byte containing remote channel 1 result bits 11:4."},{"hex":"0x10","decimal":"16","bank":"","page":"","description":"Low-byte register containing remote channel 1 result bits 3:0 in register bits 7:4."}] |
| `register_description` | 0.0564 | 1.0 | One logical 12-bit remote-channel-1 temperature result split between 01h and 10h; 0.0625°C LSB; low-byte bits 3:0 reserved. | Stores the latest 12-bit remote channel 1 temperature conversion result across the high- and low-byte registers. The result is a 12-bit two's-complement value with an LSB of 0.0625°C; use both parts to obtain the full result. The low register's bits 3:0 are reserved. |
| `width_bits` | 0.0590 | 0.0 | 12 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.995439 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Temp_Remote_Ch1_High","physical_address":{"hex":"0x01","decimal":"1","bank":"","page":"","description":"High byte containing remote channel 1 result bits 11:4."},"description":"High byte of the remote channel 1 temperature result.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Temp_Remote_Ch1[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 1 temperature result.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"Temp_Remote_Ch1_Low","physical_address":{"hex":"0x10","decimal":"16","bank":"","page":"","description":"Low-byte register containing remote channel 1 result bits 3:0 in register bits 7:4."},"description":"Low-byte register for the remote channel 1 temperature result.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Temp_Remote_Ch1_Low[3:0]","field_description":"Bits 3:0 of the 12-bit result, stored in physical register bits 7:4.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}]}] |
| `default_value` | 0.0667 | 1.0 | 000h | 000h |
| `default_value_description` | 0.0334 | 1.0 | Combined 12-bit data reset inferred from high-byte reset 00h and low data-nibble reset 0h. | Combined 12-bit data reset inferred from high-byte reset 00h and low data-nibble reset 0h. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 0.0 + 0.0590 x 1.0 + 0.2987 x 0.995439 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.939644.

## Extracted logical register 3: `Status`

v1 location: `registers[2]`; datasheet association: D1 §8.3, p.28, Table 8-5; §7.5.5, p.23.

Associated physical address entries: 0x02 (2).

Audit findings for this logical register: 2 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Status` at `0x02` (2)

Location: `registers[2].field_parts[0]`; source: D1 §8.3, p.28, Table 8-5; §7.5.5, p.23.

**Truth bit field 1: `ADC_Busy` bits 7:7**

Location: `registers[2].field_parts[0].bit_field[0]`; D1 source: D1 §8.3, p.28, Table 8-5; §7.5.5, p.23.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | ADC_Busy | ADC_Busy |
| `field_description` | 0.0586 | 1.0 | Indicates whether the ADC is in the middle of a conversion. | Indicates whether the ADC is in the middle of a conversion. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"The ADC is idle."},{"value":"1h","value_description":"The ADC is converting."}] | [{"value":"0h","value_description":"The ADC is idle."},{"value":"1h","value_description":"The ADC is converting."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 2: `Reserved` bits 5:6**

Location: `registers[2].field_parts[0].bit_field[1]`; D1 source: D1 §8.3, p.28, Table 8-5; §7.5.5, p.23. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Truth bit field 3: `THigh` bits 4:4**

Location: `registers[2].field_parts[0].bit_field[2]`; D1 source: D1 §8.3, p.28, Table 8-5; §7.5.5, p.23.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THigh | THigh |
| `field_description` | 0.0586 | 1.0 | Indicates whether any local or remote temperature result exceeds its high-limit setting; when set, asserts ALERT. | Indicates whether any local or remote temperature result exceeds its high-limit setting; when set, asserts ALERT. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"All temperature results are below the high limit."},{"value":"1h","value_description":"At least one temperature result exceeds the high limit."}] | [{"value":"0h","value_description":"All temperature results are below the high limit."},{"value":"1h","value_description":"At least one temperature result exceeds the high limit."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 4: `TLow` bits 3:3**

Location: `registers[2].field_parts[0].bit_field[3]`; D1 source: D1 §8.3, p.28, Table 8-5; §7.5.5, p.23.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TLow | TLow |
| `field_description` | 0.0586 | 1.0 | Indicates whether any local or remote temperature result is below its low-limit setting; when set, asserts ALERT. | Indicates whether any local or remote temperature result is below its low-limit setting; when set, asserts ALERT. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"All temperature results are above the low limit."},{"value":"1h","value_description":"At least one temperature result is below the low limit."}] | [{"value":"0h","value_description":"All temperature results are above the low limit."},{"value":"1h","value_description":"At least one temperature result is below the low limit."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 5: `Remote_Fault` bits 2:2**

Location: `registers[2].field_parts[0].bit_field[4]`; D1 source: D1 §8.3, p.28, Table 8-5; §7.5.5, p.23.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Remote_Fault | Remote_Fault |
| `field_description` | 0.0586 | 1.0 | Indicates whether either remote channel is disconnected or shorted. | Indicates whether either remote channel is disconnected or shorted. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"Both remote channels are connected."},{"value":"1h","value_description":"Either remote channel is disconnected or shorted."}] | [{"value":"0h","value_description":"Both remote channels are connected."},{"value":"1h","value_description":"Either remote channel is disconnected or shorted."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 6: `TCrit` bits 1:1**

Location: `registers[2].field_parts[0].bit_field[5]`; D1 source: D1 §8.3, p.28, Table 8-5; §7.5.5, p.23.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TCrit | TCrit |
| `field_description` | 0.0586 | 1.0 | Indicates whether any local or remote temperature exceeds its corresponding T_CRIT limit; when set, asserts T_CRIT. | Indicates whether any local or remote temperature exceeds its corresponding T_CRIT limit; when set, asserts T_CRIT. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"All temperature results are below the configured T_CRIT limits."},{"value":"1h","value_description":"At least one temperature result exceeds its configured T_CRIT limit."}] | [{"value":"0h","value_description":"All temperature results are below the configured T_CRIT limits."},{"value":"1h","value_description":"At least one temperature result exceeds its configured T_CRIT limit."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 7: `Reserved` bits 0:0**

Location: `registers[2].field_parts[0].bit_field[6]`; D1 source: D1 §8.3, p.28, Table 8-5; §7.5.5, p.23. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 0.941694, 1.000000, 1.000000, 1.000000, 1.000000, 0.941694) = **0.983341**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Status | Status |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"Device status register."} | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"Device status register."} |
| `description` | 0.0693 | 1.0 | Current status flags; in SMBus Alert interrupt mode a Status read clears limit flags and can set Alert_Mask. | Current device status flags. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.983341 | mean of all bit-field Q values listed below | [{"name_or_parameter":"ADC_Busy","field_description":"Indicates whether the ADC is in the middle of a conversion.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0h","value_description":"The ADC is idle."},{"value":"1h","value_description":"The ADC is converting."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":5,"bit_end":6,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THigh","field_description":"Indicates whether any local or remote temperature result exceeds its high-limit setting; when set, asserts ALERT.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0h","value_description":"All temperature results are below the high limit."},{"value":"1h","value_description":"At least one temperature result exceeds the high limit."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"TLow","field_description":"Indicates whether any local or remote temperature result is below its low-limit setting; when set, asserts ALERT.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0h","value_description":"All temperature results are above the low limit."},{"value":"1h","value_description":"At least one temperature result is below the low limit."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Remote_Fault","field_description":"Indicates whether either remote channel is disconnected or shorted.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0h","value_description":"Both remote channels are connected."},{"value":"1h","value_description":"Either remote channel is disconnected or shorted."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"TCrit","field_description":"Indicates whether any local or remote temperature exceeds its corresponding T_CRIT limit; when set, asserts T_CRIT.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0h","value_description":"All temperature results are below the configured T_CRIT limits."},{"value":"1h","value_description":"At least one temperature result exceeds its configured T_CRIT limit."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.983341) = 0.994787.

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.994787) = **0.994787**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Status | Status |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":"Device status register."}] | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":"Device status register."}] |
| `register_description` | 0.0564 | 1.0 | Current status flags; in SMBus Alert interrupt mode a Status read clears limit flags and can set Alert_Mask. | Shows current conversion, temperature-limit, remote-diode-fault, and T_CRIT status. In SMBus Alert interrupt mode, reading the Status register clears its limit flags; qualifying conditions can set them again after a conversion. Reading Status with an applicable flag set also sets the Configuration register Alert_Mask bit. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.994787 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Status","physical_address":{"hex":"0x02","decimal":"2","bank":"","page":"","description":"Device status register."},"description":"Current device status flags.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"ADC_Busy","field_description":"Indicates whether the ADC is in the middle of a conversion.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0h","value_description":"The ADC is idle."},{"value":"1h","value_description":"The ADC is converting."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":5,"bit_end":6,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"THigh","field_description":"Indicates whether any local or remote temperature result exceeds its high-limit setting; when set, asserts ALERT.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0h","value_description":"All temperature results are below the high limit."},{"value":"1h","value_description":"At least one temperature result exceeds the high limit."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"TLow","field_description":"Indicates whether any local or remote temperature result is below its low-limit setting; when set, asserts ALERT.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0h","value_description":"All temperature results are above the low limit."},{"value":"1h","value_description":"At least one temperature result is below the low limit."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Remote_Fault","field_description":"Indicates whether either remote channel is disconnected or shorted.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0h","value_description":"Both remote channels are connected."},{"value":"1h","value_description":"Either remote channel is disconnected or shorted."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"TCrit","field_description":"Indicates whether any local or remote temperature exceeds its corresponding T_CRIT limit; when set, asserts T_CRIT.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0h","value_description":"All temperature results are below the configured T_CRIT limits."},{"value":"1h","value_description":"At least one temperature result exceeds its configured T_CRIT limit."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}]}] |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | Reset value. | Reset value. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 0.994787 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.998443.

## Extracted logical register 4: `Configuration`

v1 location: `registers[3]`; datasheet association: D1 §8.4, p.29, Table 8-6.

Associated physical address entries: 0x03 (3), 0x09 (9).

Audit findings for this logical register: 2 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Configuration` at `0x03` (3)

Location: `registers[3].field_parts[0]`; source: D1 §8.4, p.29, Table 8-6.

**Truth bit field 1: `Alert_Mask` bits 7:7**

Location: `registers[3].field_parts[0].bit_field[0]`; D1 source: D1 §8.4, p.29, Table 8-6.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Alert_Mask | Alert_Mask |
| `field_description` | 0.0586 | 1.0 | Masks the ALERT pin from asserting. | Masks the ALERT pin from asserting. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"ALERT pin assertion is enabled."},{"value":"1h","value_description":"ALERT is masked and does not assert low unless comparator mode is selected; Status continues updating."}] | [{"value":"0h","value_description":"ALERT pin assertion is enabled."},{"value":"1h","value_description":"ALERT is masked and does not assert low unless comparator mode is selected; Status continues updating."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 2: `Mode` bits 6:6**

Location: `registers[3].field_parts[0].bit_field[1]`; D1 source: D1 §8.4, p.29, Table 8-6.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Mode | Mode |
| `field_description` | 0.0586 | 1.0 | Controls device operating mode. | Controls device operating mode. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"Continuous mode enabled."},{"value":"1h","value_description":"Shutdown mode enabled; a one-shot conversion can be started in this mode."}] | [{"value":"0h","value_description":"Continuous mode enabled."},{"value":"1h","value_description":"Shutdown mode enabled; a one-shot conversion can be started in this mode."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 3: `Alert_Mode` bits 5:5**

Location: `registers[3].field_parts[0].bit_field[2]`; D1 source: D1 §8.4, p.29, Table 8-6.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Alert_Mode | Alert_Mode |
| `field_description` | 0.0586 | 1.0 | Configures the ALERT pin output mode. | Configures the ALERT pin output mode. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"Interrupt mode enabled for ALERT."},{"value":"1h","value_description":"Comparator mode enabled for ALERT."}] | [{"value":"0h","value_description":"Interrupt mode enabled for ALERT."},{"value":"1h","value_description":"Comparator mode enabled for ALERT."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 4: `Reserved` bits 0:4**

Location: `registers[3].field_parts[0].bit_field[3]`; D1 source: D1 §8.4, p.29, Table 8-6. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 1.000000, 0.941694) = **0.985424**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Configuration | Configuration |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"Primary address of the Configuration register."} | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"Primary address of the Configuration register."} |
| `description` | 0.0693 | 1.0 | Controls ALERT masking, continuous/shutdown operation, and interrupt/comparator mode. | Primary address view. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.985424 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Alert_Mask","field_description":"Masks the ALERT pin from asserting.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0h","value_description":"ALERT pin assertion is enabled."},{"value":"1h","value_description":"ALERT is masked and does not assert low unless comparator mode is selected; Status continues updating."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Mode","field_description":"Controls device operating mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0h","value_description":"Continuous mode enabled."},{"value":"1h","value_description":"Shutdown mode enabled; a one-shot conversion can be started in this mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Alert_Mode","field_description":"Configures the ALERT pin output mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0h","value_description":"Interrupt mode enabled for ALERT."},{"value":"1h","value_description":"Comparator mode enabled for ALERT."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.985424) = 0.995439.

#### Field part 2: `Configuration` at `0x09` (9)

Location: `registers[3].field_parts[1]`; source: D1 §8.4, p.29, Table 8-6.

**Truth bit field 1: `Alert_Mask` bits 7:7**

Location: `registers[3].field_parts[1].bit_field[0]`; D1 source: D1 §8.4, p.29, Table 8-6.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Alert_Mask | Alert_Mask |
| `field_description` | 0.0586 | 1.0 | Masks the ALERT pin from asserting. | Masks the ALERT pin from asserting. |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"ALERT pin assertion is enabled."},{"value":"1h","value_description":"ALERT is masked and does not assert low unless comparator mode is selected; Status continues updating."}] | [{"value":"0h","value_description":"ALERT pin assertion is enabled."},{"value":"1h","value_description":"ALERT is masked and does not assert low unless comparator mode is selected; Status continues updating."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 2: `Mode` bits 6:6**

Location: `registers[3].field_parts[1].bit_field[1]`; D1 source: D1 §8.4, p.29, Table 8-6.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Mode | Mode |
| `field_description` | 0.0586 | 1.0 | Controls device operating mode. | Controls device operating mode. |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"Continuous mode enabled."},{"value":"1h","value_description":"Shutdown mode enabled; a one-shot conversion can be started in this mode."}] | [{"value":"0h","value_description":"Continuous mode enabled."},{"value":"1h","value_description":"Shutdown mode enabled; a one-shot conversion can be started in this mode."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 3: `Alert_Mode` bits 5:5**

Location: `registers[3].field_parts[1].bit_field[2]`; D1 source: D1 §8.4, p.29, Table 8-6.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Alert_Mode | Alert_Mode |
| `field_description` | 0.0586 | 1.0 | Configures the ALERT pin output mode. | Configures the ALERT pin output mode. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"Interrupt mode enabled for ALERT."},{"value":"1h","value_description":"Comparator mode enabled for ALERT."}] | [{"value":"0h","value_description":"Interrupt mode enabled for ALERT."},{"value":"1h","value_description":"Comparator mode enabled for ALERT."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 4: `Reserved` bits 0:4**

Location: `registers[3].field_parts[1].bit_field[3]`; D1 source: D1 §8.4, p.29, Table 8-6. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 1.000000, 0.941694) = **0.985424**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Configuration | Configuration |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"Shared alias address of the Configuration register."} | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"Shared alias address of the Configuration register."} |
| `description` | 0.0693 | 1.0 | Controls ALERT masking, continuous/shutdown operation, and interrupt/comparator mode. | Shared alias address view. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.985424 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Alert_Mask","field_description":"Masks the ALERT pin from asserting.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0h","value_description":"ALERT pin assertion is enabled."},{"value":"1h","value_description":"ALERT is masked and does not assert low unless comparator mode is selected; Status continues updating."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Mode","field_description":"Controls device operating mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0h","value_description":"Continuous mode enabled."},{"value":"1h","value_description":"Shutdown mode enabled; a one-shot conversion can be started in this mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Alert_Mode","field_description":"Configures the ALERT pin output mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0h","value_description":"Interrupt mode enabled for ALERT."},{"value":"1h","value_description":"Comparator mode enabled for ALERT."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.985424) = 0.995439.

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.995439, 0.995439) = **0.995439**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Configuration | Configuration |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"Primary address of the Configuration register."},{"hex":"0x09","decimal":"9","bank":"","page":"","description":"Shared alias address of the Configuration register."}] | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"Primary address of the Configuration register."},{"hex":"0x09","decimal":"9","bank":"","page":"","description":"Shared alias address of the Configuration register."}] |
| `register_description` | 0.0564 | 1.0 | Controls ALERT masking, continuous/shutdown operation, and interrupt/comparator mode. | Configures ALERT pin behavior, continuous or shutdown operation, and interrupt or comparator alert mode. Configuration changes are serviced after the current conversion completes, except entering Shutdown mode. In SMBus Alert interrupt mode, applicable status reads or an Alert Response Address command can set Alert_Mask; software clears it by writing 0. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.995439 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Configuration","physical_address":{"hex":"0x03","decimal":"3","bank":"","page":"","description":"Primary address of the Configuration register."},"description":"Primary address view.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Alert_Mask","field_description":"Masks the ALERT pin from asserting.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0h","value_description":"ALERT pin assertion is enabled."},{"value":"1h","value_description":"ALERT is masked and does not assert low unless comparator mode is selected; Status continues updating."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Mode","field_description":"Controls device operating mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0h","value_description":"Continuous mode enabled."},{"value":"1h","value_description":"Shutdown mode enabled; a one-shot conversion can be started in this mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Alert_Mode","field_description":"Configures the ALERT pin output mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0h","value_description":"Interrupt mode enabled for ALERT."},{"value":"1h","value_description":"Comparator mode enabled for ALERT."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""}]},{"register_name":"Configuration","physical_address":{"hex":"0x09","decimal":"9","bank":"","page":"","description":"Shared alias address of the Configuration register."},"description":"Shared alias address view.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Alert_Mask","field_description":"Masks the ALERT pin from asserting.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0h","value_description":"ALERT pin assertion is enabled."},{"value":"1h","value_description":"ALERT is masked and does not assert low unless comparator mode is selected; Status continues updating."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Mode","field_description":"Controls device operating mode.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0h","value_description":"Continuous mode enabled."},{"value":"1h","value_description":"Shutdown mode enabled; a one-shot conversion can be started in this mode."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Alert_Mode","field_description":"Configures the ALERT pin output mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0h","value_description":"Interrupt mode enabled for ALERT."},{"value":"1h","value_description":"Comparator mode enabled for ALERT."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""}]}] |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | Reset value; both addresses access the same register. | Reset value; both addresses access the same register. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 0.995439 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.998638.

## Extracted logical register 5: `Conv_Period`

v1 location: `registers[4]`; datasheet association: D1 §8.5, p.30, Table 8-7.

Associated physical address entries: 0x04 (4), 0x0A (10).

Audit findings for this logical register: 2 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Conv_Period` at `0x04` (4)

Location: `registers[4].field_parts[0]`; source: D1 §8.5, p.30, Table 8-7.

**Truth bit field 1: `Reserved` bits 4:7**

Location: `registers[4].field_parts[0].bit_field[0]`; D1 source: D1 §8.5, p.30, Table 8-7. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Truth bit field 2: `Conv_Period[3:0]` bits 0:3**

Location: `registers[4].field_parts[0].bit_field[1]`; D1 source: D1 §8.5, p.30, Table 8-7.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Conv_Period[3:0] | Conv_Period[3:0] |
| `field_description` | 0.0586 | 1.0 | Conversion-period setting; unsupported values select Shutdown mode. | Conversion-period setting; unsupported values select Shutdown mode. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"16s / 0.0625Hz"},{"value":"1h","value_description":"8s / 0.125Hz"},{"value":"2h","value_description":"4s / 0.25Hz"},{"value":"3h","value_description":"2s / 0.5Hz"},{"value":"4h","value_description":"1s / 1Hz"},{"value":"5h","value_description":"0.5s / 2Hz"},{"value":"6h","value_description":"0.25s / 4Hz"},{"value":"7h","value_description":"0.125s / 8Hz"},{"value":"8h","value_description":"0.0625s / 16Hz"},{"value":"9h-Fh","value_description":"1s / 1Hz"}] | [{"value":"0h","value_description":"16s / 0.0625Hz"},{"value":"1h","value_description":"8s / 0.125Hz"},{"value":"2h","value_description":"4s / 0.25Hz"},{"value":"3h","value_description":"2s / 0.5Hz"},{"value":"4h","value_description":"1s / 1Hz"},{"value":"5h","value_description":"0.5s / 2Hz"},{"value":"6h","value_description":"0.25s / 4Hz"},{"value":"7h","value_description":"0.125s / 8Hz"},{"value":"8h","value_description":"0.0625s / 16Hz"},{"value":"9h-Fh","value_description":"1s / 1Hz"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(0.941694, 1.000000) = **0.970847**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Conv_Period | Conv_Period |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Primary address of the conversion-period register."} | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Primary address of the conversion-period register."} |
| `description` | 0.0693 | 1.0 | Conversion-period setting; unsupported settings put the device in Shutdown. | Primary address view. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Conv_Period[3:0]","field_description":"Conversion-period setting; unsupported values select Shutdown mode.","bit_start":0,"bit_end":3,"bit_width":4,"values":[{"value":"0h","value_description":"16s / 0.0625Hz"},{"value":"1h","value_description":"8s / 0.125Hz"},{"value":"2h","value_description":"4s / 0.25Hz"},{"value":"3h","value_description":"2s / 0.5Hz"},{"value":"4h","value_description":"1s / 1Hz"},{"value":"5h","value_description":"0.5s / 2Hz"},{"value":"6h","value_description":"0.25s / 4Hz"},{"value":"7h","value_description":"0.125s / 8Hz"},{"value":"8h","value_description":"0.0625s / 16Hz"},{"value":"9h-Fh","value_description":"1s / 1Hz"}],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.970847) = 0.990878.

#### Field part 2: `Conv_Period` at `0x0A` (10)

Location: `registers[4].field_parts[1]`; source: D1 §8.5, p.30, Table 8-7.

**Truth bit field 1: `Reserved` bits 4:7**

Location: `registers[4].field_parts[1].bit_field[0]`; D1 source: D1 §8.5, p.30, Table 8-7. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Truth bit field 2: `Conv_Period[3:0]` bits 0:3**

Location: `registers[4].field_parts[1].bit_field[1]`; D1 source: D1 §8.5, p.30, Table 8-7.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Conv_Period[3:0] | Conv_Period[3:0] |
| `field_description` | 0.0586 | 1.0 | Conversion-period setting; unsupported values select Shutdown mode. | Conversion-period setting; unsupported values select Shutdown mode. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"16s / 0.0625Hz"},{"value":"1h","value_description":"8s / 0.125Hz"},{"value":"2h","value_description":"4s / 0.25Hz"},{"value":"3h","value_description":"2s / 0.5Hz"},{"value":"4h","value_description":"1s / 1Hz"},{"value":"5h","value_description":"0.5s / 2Hz"},{"value":"6h","value_description":"0.25s / 4Hz"},{"value":"7h","value_description":"0.125s / 8Hz"},{"value":"8h","value_description":"0.0625s / 16Hz"},{"value":"9h-Fh","value_description":"1s / 1Hz"}] | [{"value":"0h","value_description":"16s / 0.0625Hz"},{"value":"1h","value_description":"8s / 0.125Hz"},{"value":"2h","value_description":"4s / 0.25Hz"},{"value":"3h","value_description":"2s / 0.5Hz"},{"value":"4h","value_description":"1s / 1Hz"},{"value":"5h","value_description":"0.5s / 2Hz"},{"value":"6h","value_description":"0.25s / 4Hz"},{"value":"7h","value_description":"0.125s / 8Hz"},{"value":"8h","value_description":"0.0625s / 16Hz"},{"value":"9h-Fh","value_description":"1s / 1Hz"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(0.941694, 1.000000) = **0.970847**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Conv_Period | Conv_Period |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Shared alias address of the conversion-period register."} | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Shared alias address of the conversion-period register."} |
| `description` | 0.0693 | 1.0 | Conversion-period setting; unsupported settings put the device in Shutdown. | Shared alias address view. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Conv_Period[3:0]","field_description":"Conversion-period setting; unsupported values select Shutdown mode.","bit_start":0,"bit_end":3,"bit_width":4,"values":[{"value":"0h","value_description":"16s / 0.0625Hz"},{"value":"1h","value_description":"8s / 0.125Hz"},{"value":"2h","value_description":"4s / 0.25Hz"},{"value":"3h","value_description":"2s / 0.5Hz"},{"value":"4h","value_description":"1s / 1Hz"},{"value":"5h","value_description":"0.5s / 2Hz"},{"value":"6h","value_description":"0.25s / 4Hz"},{"value":"7h","value_description":"0.125s / 8Hz"},{"value":"8h","value_description":"0.0625s / 16Hz"},{"value":"9h-Fh","value_description":"1s / 1Hz"}],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.970847) = 0.990878.

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.990878, 0.990878) = **0.990878**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Conv_Period | Conv_Period |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":"Primary address of the conversion-period register."},{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Shared alias address of the conversion-period register."}] | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":"Primary address of the conversion-period register."},{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Shared alias address of the conversion-period register."}] |
| `register_description` | 0.0564 | 1.0 | Conversion-period setting; unsupported settings put the device in Shutdown. | Configures the conversion period. A new setting takes effect at the next possible interval without restarting an ongoing conversion period. Unsupported settings place the device in Shutdown mode. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.990878 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Conv_Period","physical_address":{"hex":"0x04","decimal":"4","bank":"","page":"","description":"Primary address of the conversion-period register."},"description":"Primary address view.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Conv_Period[3:0]","field_description":"Conversion-period setting; unsupported values select Shutdown mode.","bit_start":0,"bit_end":3,"bit_width":4,"values":[{"value":"0h","value_description":"16s / 0.0625Hz"},{"value":"1h","value_description":"8s / 0.125Hz"},{"value":"2h","value_description":"4s / 0.25Hz"},{"value":"3h","value_description":"2s / 0.5Hz"},{"value":"4h","value_description":"1s / 1Hz"},{"value":"5h","value_description":"0.5s / 2Hz"},{"value":"6h","value_description":"0.25s / 4Hz"},{"value":"7h","value_description":"0.125s / 8Hz"},{"value":"8h","value_description":"0.0625s / 16Hz"},{"value":"9h-Fh","value_description":"1s / 1Hz"}],"is_reserved":false,"type_write_read":"RW"}]},{"register_name":"Conv_Period","physical_address":{"hex":"0x0A","decimal":"10","bank":"","page":"","description":"Shared alias address of the conversion-period register."},"description":"Shared alias address view.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Conv_Period[3:0]","field_description":"Conversion-period setting; unsupported values select Shutdown mode.","bit_start":0,"bit_end":3,"bit_width":4,"values":[{"value":"0h","value_description":"16s / 0.0625Hz"},{"value":"1h","value_description":"8s / 0.125Hz"},{"value":"2h","value_description":"4s / 0.25Hz"},{"value":"3h","value_description":"2s / 0.5Hz"},{"value":"4h","value_description":"1s / 1Hz"},{"value":"5h","value_description":"0.5s / 2Hz"},{"value":"6h","value_description":"0.25s / 4Hz"},{"value":"7h","value_description":"0.125s / 8Hz"},{"value":"8h","value_description":"0.0625s / 16Hz"},{"value":"9h-Fh","value_description":"1s / 1Hz"}],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.0 | 06h | 06h |
| `default_value_description` | 0.0334 | 1.0 | Reset value; corresponds to 0.25s / 4Hz. | Reset value; corresponds to 0.25s / 4Hz. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 0.990878 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.997276.

## Extracted logical register 6: `THigh_Limit_Local`

v1 location: `registers[5]`; datasheet association: D1 §8.6, p.31, Table 8-8.

Associated physical address entries: 0x05 (5), 0x0B (11).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `THigh_Limit_Local` at `0x05` (5)

Location: `registers[5].field_parts[0]`; source: D1 §8.6, p.31, Table 8-8.

**Truth bit field 1: `THigh_Limit_Local[7:0]` bits 0:7**

Location: `registers[5].field_parts[0].bit_field[0]`; D1 source: D1 §8.6, p.31, Table 8-8.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THigh_Limit_Local[7:0] | THigh_Limit_Local[7:0] |
| `field_description` | 0.0586 | 1.0 | 8-bit local-temperature alert high-limit setting; two's complement with an LSB of 1°C. | 8-bit local-temperature alert high-limit setting; two's complement with an LSB of 1°C. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | THigh_Limit_Local | THigh_Limit_Local |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Primary address of the local high-limit register."} | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Primary address of the local high-limit register."} |
| `description` | 0.0693 | 1.0 | 8-bit local ALERT high limit, two's complement, 1°C LSB; reset 55h = 85°C. | Primary address view. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"THigh_Limit_Local[7:0]","field_description":"8-bit local-temperature alert high-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

#### Field part 2: `THigh_Limit_Local` at `0x0B` (11)

Location: `registers[5].field_parts[1]`; source: D1 §8.6, p.31, Table 8-8.

**Truth bit field 1: `THigh_Limit_Local[7:0]` bits 0:7**

Location: `registers[5].field_parts[1].bit_field[0]`; D1 source: D1 §8.6, p.31, Table 8-8.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THigh_Limit_Local[7:0] | THigh_Limit_Local[7:0] |
| `field_description` | 0.0586 | 1.0 | 8-bit local-temperature alert high-limit setting; two's complement with an LSB of 1°C. | 8-bit local-temperature alert high-limit setting; two's complement with an LSB of 1°C. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | THigh_Limit_Local | THigh_Limit_Local |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"Shared alias address of the local high-limit register."} | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"Shared alias address of the local high-limit register."} |
| `description` | 0.0693 | 1.0 | 8-bit local ALERT high limit, two's complement, 1°C LSB; reset 55h = 85°C. | Shared alias address view. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"THigh_Limit_Local[7:0]","field_description":"8-bit local-temperature alert high-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | THigh_Limit_Local | THigh_Limit_Local |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x05","decimal":"5","bank":"","page":"","description":"Primary address of the local high-limit register."},{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"Shared alias address of the local high-limit register."}] | [{"hex":"0x05","decimal":"5","bank":"","page":"","description":"Primary address of the local high-limit register."},{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"Shared alias address of the local high-limit register."}] |
| `register_description` | 0.0564 | 1.0 | 8-bit local ALERT high limit, two's complement, 1°C LSB; reset 55h = 85°C. | Configures the local-temperature ALERT high limit as an 8-bit two's-complement value with an LSB of 1°C. The reset setting 55h corresponds to 85°C. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"THigh_Limit_Local","physical_address":{"hex":"0x05","decimal":"5","bank":"","page":"","description":"Primary address of the local high-limit register."},"description":"Primary address view.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THigh_Limit_Local[7:0]","field_description":"8-bit local-temperature alert high-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]},{"register_name":"THigh_Limit_Local","physical_address":{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"Shared alias address of the local high-limit register."},"description":"Shared alias address view.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THigh_Limit_Local[7:0]","field_description":"8-bit local-temperature alert high-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.0 | 55h | 55h |
| `default_value_description` | 0.0334 | 1.0 | Reset value; corresponds to 85°C. | Reset value; corresponds to 85°C. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## Extracted logical register 7: `TLow_Limit_Local`

v1 location: `registers[6]`; datasheet association: D1 §8.7, p.31, Table 8-9.

Associated physical address entries: 0x06 (6), 0x0C (12).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `TLow_Limit_Local` at `0x06` (6)

Location: `registers[6].field_parts[0]`; source: D1 §8.7, p.31, Table 8-9.

**Truth bit field 1: `TLow_Limit_Local[7:0]` bits 0:7**

Location: `registers[6].field_parts[0].bit_field[0]`; D1 source: D1 §8.7, p.31, Table 8-9.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TLow_Limit_Local[7:0] | TLow_Limit_Local[7:0] |
| `field_description` | 0.0586 | 1.0 | 8-bit local-temperature alert low-limit setting; two's complement with an LSB of 1°C. | 8-bit local-temperature alert low-limit setting; two's complement with an LSB of 1°C. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TLow_Limit_Local | TLow_Limit_Local |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x06","decimal":"6","bank":"","page":"","description":"Primary address of the local low-limit register."} | {"hex":"0x06","decimal":"6","bank":"","page":"","description":"Primary address of the local low-limit register."} |
| `description` | 0.0693 | 1.0 | 8-bit local ALERT low limit, two's complement, 1°C LSB; reset 00h = 0°C. | Primary address view. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"TLow_Limit_Local[7:0]","field_description":"8-bit local-temperature alert low-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

#### Field part 2: `TLow_Limit_Local` at `0x0C` (12)

Location: `registers[6].field_parts[1]`; source: D1 §8.7, p.31, Table 8-9.

**Truth bit field 1: `TLow_Limit_Local[7:0]` bits 0:7**

Location: `registers[6].field_parts[1].bit_field[0]`; D1 source: D1 §8.7, p.31, Table 8-9.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TLow_Limit_Local[7:0] | TLow_Limit_Local[7:0] |
| `field_description` | 0.0586 | 1.0 | 8-bit local-temperature alert low-limit setting; two's complement with an LSB of 1°C. | 8-bit local-temperature alert low-limit setting; two's complement with an LSB of 1°C. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TLow_Limit_Local | TLow_Limit_Local |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Shared alias address of the local low-limit register."} | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Shared alias address of the local low-limit register."} |
| `description` | 0.0693 | 1.0 | 8-bit local ALERT low limit, two's complement, 1°C LSB; reset 00h = 0°C. | Shared alias address view. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"TLow_Limit_Local[7:0]","field_description":"8-bit local-temperature alert low-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | TLow_Limit_Local | TLow_Limit_Local |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":"Primary address of the local low-limit register."},{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Shared alias address of the local low-limit register."}] | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":"Primary address of the local low-limit register."},{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Shared alias address of the local low-limit register."}] |
| `register_description` | 0.0564 | 1.0 | 8-bit local ALERT low limit, two's complement, 1°C LSB; reset 00h = 0°C. | Configures the local-temperature ALERT low limit as an 8-bit two's-complement value with an LSB of 1°C. The reset setting 00h corresponds to 0°C. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"TLow_Limit_Local","physical_address":{"hex":"0x06","decimal":"6","bank":"","page":"","description":"Primary address of the local low-limit register."},"description":"Primary address view.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"TLow_Limit_Local[7:0]","field_description":"8-bit local-temperature alert low-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]},{"register_name":"TLow_Limit_Local","physical_address":{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Shared alias address of the local low-limit register."},"description":"Shared alias address view.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"TLow_Limit_Local[7:0]","field_description":"8-bit local-temperature alert low-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | Reset value; corresponds to 0°C. | Reset value; corresponds to 0°C. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## Extracted logical register 8: `THigh_Limit_Remote_Ch1`

v1 location: `registers[7]`; datasheet association: D1 §8.8 p.32 Table 8-10; §8.14 p.35 Table 8-16.

Associated physical address entries: 0x07 (7), 0x0D (13), 0x13 (19).

Audit findings for this logical register: v1 `width_bits=16` is wrong; D1 defines a 12-bit logical quantity. 1 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `THigh_Limit_Remote_Ch1_High` at `0x07` (7)

Location: `registers[7].field_parts[0]`; source: D1 §8.8 p.32 Table 8-10; §8.14 p.35 Table 8-16.

**Truth bit field 1: `THigh_Limit_Remote_Ch1_High[11:4]` bits 0:7**

Location: `registers[7].field_parts[0].bit_field[0]`; D1 source: D1 §8.8 p.32 Table 8-10; §8.14 p.35 Table 8-16.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THigh_Limit_Remote_Ch1_High[11:4] | THigh_Limit_Remote_Ch1_High[11:4] |
| `field_description` | 0.0586 | 1.0 | Bits 11:4 of the 12-bit remote channel 1 alert high limit. | Bits 11:4 of the 12-bit remote channel 1 alert high limit. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | THigh_Limit_Remote_Ch1_High | THigh_Limit_Remote_Ch1_High |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":"Primary high-byte address containing limit bits 11:4."} | {"hex":"0x07","decimal":"7","bank":"","page":"","description":"Primary high-byte address containing limit bits 11:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-1 high limit: bits 11:4 at 07h/0Dh, bits 3:0 in bits 7:4 at 13h; low bits 3:0 reserved. | Primary high-byte address. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"THigh_Limit_Remote_Ch1_High[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 1 alert high limit.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

#### Field part 2: `THigh_Limit_Remote_Ch1_High` at `0x0D` (13)

Location: `registers[7].field_parts[1]`; source: D1 §8.8 p.32 Table 8-10; §8.14 p.35 Table 8-16.

**Truth bit field 1: `THigh_Limit_Remote_Ch1_High[11:4]` bits 0:7**

Location: `registers[7].field_parts[1].bit_field[0]`; D1 source: D1 §8.8 p.32 Table 8-10; §8.14 p.35 Table 8-16.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THigh_Limit_Remote_Ch1_High[11:4] | THigh_Limit_Remote_Ch1_High[11:4] |
| `field_description` | 0.0586 | 1.0 | Bits 11:4 of the 12-bit remote channel 1 alert high limit. | Bits 11:4 of the 12-bit remote channel 1 alert high limit. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | THigh_Limit_Remote_Ch1_High | THigh_Limit_Remote_Ch1_High |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Shared alias of the high-byte address containing limit bits 11:4."} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Shared alias of the high-byte address containing limit bits 11:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-1 high limit: bits 11:4 at 07h/0Dh, bits 3:0 in bits 7:4 at 13h; low bits 3:0 reserved. | Shared alias high-byte address. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"THigh_Limit_Remote_Ch1_High[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 1 alert high limit.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

#### Field part 3: `THigh_Limit_Remote_Ch1_Low` at `0x13` (19)

Location: `registers[7].field_parts[2]`; source: D1 §8.8 p.32 Table 8-10; §8.14 p.35 Table 8-16.

**Truth bit field 1: `THigh_Limit_Remote_Ch1_Low[3:0]` bits 4:7**

Location: `registers[7].field_parts[2].bit_field[0]`; D1 source: D1 §8.8 p.32 Table 8-10; §8.14 p.35 Table 8-16.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THigh_Limit_Remote_Ch1_Low[3:0] | THigh_Limit_Remote_Ch1_Low[3:0] |
| `field_description` | 0.0586 | 1.0 | Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4. | Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 2: `Reserved` bits 0:3**

Location: `registers[7].field_parts[2].bit_field[1]`; D1 source: D1 §8.8 p.32 Table 8-10; §8.14 p.35 Table 8-16. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 0.941694) = **0.970847**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | THigh_Limit_Remote_Ch1_Low | THigh_Limit_Remote_Ch1_Low |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Low-byte address containing limit bits 3:0 in register bits 7:4."} | {"hex":"0x13","decimal":"19","bank":"","page":"","description":"Low-byte address containing limit bits 3:0 in register bits 7:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-1 high limit: bits 11:4 at 07h/0Dh, bits 3:0 in bits 7:4 at 13h; low bits 3:0 reserved. | Low-byte register for the limit. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | mean of all bit-field Q values listed below | [{"name_or_parameter":"THigh_Limit_Remote_Ch1_Low[3:0]","field_description":"Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.970847) = 0.990878.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 1.000000, 0.990878) = **0.996959**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | equivalent merged name accepted; D1 splits the high/low access entries | THigh_Limit_Remote_Ch1 |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":"Primary high-byte address containing limit bits 11:4."},{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Shared alias of the high-byte address containing limit bits 11:4."},{"hex":"0x13","decimal":"19","bank":"","page":"","description":"Low-byte address containing limit bits 3:0 in register bits 7:4."}] | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":"Primary high-byte address containing limit bits 11:4."},{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Shared alias of the high-byte address containing limit bits 11:4."},{"hex":"0x13","decimal":"19","bank":"","page":"","description":"Low-byte address containing limit bits 3:0 in register bits 7:4."}] |
| `register_description` | 0.0564 | 1.0 | One logical 12-bit remote-channel-1 high limit: bits 11:4 at 07h/0Dh, bits 3:0 in bits 7:4 at 13h; low bits 3:0 reserved. | Configures the full 12-bit remote channel 1 ALERT high limit using the high- and low-byte registers. The high register contains bits 11:4 and the low register contains bits 3:0 in physical bits 7:4. The reset setting corresponds to 85°C. |
| `width_bits` | 0.0590 | 0.0 | 12 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.996959 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"THigh_Limit_Remote_Ch1_High","physical_address":{"hex":"0x07","decimal":"7","bank":"","page":"","description":"Primary high-byte address containing limit bits 11:4."},"description":"Primary high-byte address.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THigh_Limit_Remote_Ch1_High[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 1 alert high limit.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]},{"register_name":"THigh_Limit_Remote_Ch1_High","physical_address":{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Shared alias of the high-byte address containing limit bits 11:4."},"description":"Shared alias high-byte address.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THigh_Limit_Remote_Ch1_High[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 1 alert high limit.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]},{"register_name":"THigh_Limit_Remote_Ch1_Low","physical_address":{"hex":"0x13","decimal":"19","bank":"","page":"","description":"Low-byte address containing limit bits 3:0 in register bits 7:4."},"description":"Low-byte register for the limit.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THigh_Limit_Remote_Ch1_Low[3:0]","field_description":"Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}]}] |
| `default_value` | 0.0667 | 1.0 | 550h | 550h |
| `default_value_description` | 0.0334 | 1.0 | Combined 12-bit limit inferred from high-byte reset 55h and low data-nibble reset 0h; corresponds to 85°C. | Combined 12-bit limit inferred from high-byte reset 55h and low data-nibble reset 0h; corresponds to 85°C. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 0.0 + 0.0590 x 1.0 + 0.2987 x 0.996959 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.940098.

## Extracted logical register 9: `TLow_Limit_Remote_Ch1`

v1 location: `registers[8]`; datasheet association: D1 §8.9 p.32 Table 8-11; §8.15 p.35 Table 8-17.

Associated physical address entries: 0x08 (8), 0x0E (14), 0x14 (20).

Audit findings for this logical register: v1 `width_bits=16` is wrong; D1 defines a 12-bit logical quantity. 1 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `TLow_Limit_Remote_Ch1_High` at `0x08` (8)

Location: `registers[8].field_parts[0]`; source: D1 §8.9 p.32 Table 8-11; §8.15 p.35 Table 8-17.

**Truth bit field 1: `TLow_Limit_Remote_Ch1_High[11:4]` bits 0:7**

Location: `registers[8].field_parts[0].bit_field[0]`; D1 source: D1 §8.9 p.32 Table 8-11; §8.15 p.35 Table 8-17.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TLow_Limit_Remote_Ch1_High[11:4] | TLow_Limit_Remote_Ch1_High[11:4] |
| `field_description` | 0.0586 | 1.0 | Bits 11:4 of the 12-bit remote channel 1 alert low limit. | Bits 11:4 of the 12-bit remote channel 1 alert low limit. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TLow_Limit_Remote_Ch1_High | TLow_Limit_Remote_Ch1_High |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"Primary high-byte address containing limit bits 11:4."} | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"Primary high-byte address containing limit bits 11:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-1 low limit: bits 11:4 at 08h/0Eh, bits 3:0 in bits 7:4 at 14h; low bits 3:0 reserved. | Primary high-byte address. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"TLow_Limit_Remote_Ch1_High[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 1 alert low limit.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

#### Field part 2: `TLow_Limit_Remote_Ch1_High` at `0x0E` (14)

Location: `registers[8].field_parts[1]`; source: D1 §8.9 p.32 Table 8-11; §8.15 p.35 Table 8-17.

**Truth bit field 1: `TLow_Limit_Remote_Ch1_High[11:4]` bits 0:7**

Location: `registers[8].field_parts[1].bit_field[0]`; D1 source: D1 §8.9 p.32 Table 8-11; §8.15 p.35 Table 8-17.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TLow_Limit_Remote_Ch1_High[11:4] | TLow_Limit_Remote_Ch1_High[11:4] |
| `field_description` | 0.0586 | 1.0 | Bits 11:4 of the 12-bit remote channel 1 alert low limit. | Bits 11:4 of the 12-bit remote channel 1 alert low limit. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TLow_Limit_Remote_Ch1_High | TLow_Limit_Remote_Ch1_High |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0E","decimal":"14","bank":"","page":"","description":"Shared alias of the high-byte address containing limit bits 11:4."} | {"hex":"0x0E","decimal":"14","bank":"","page":"","description":"Shared alias of the high-byte address containing limit bits 11:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-1 low limit: bits 11:4 at 08h/0Eh, bits 3:0 in bits 7:4 at 14h; low bits 3:0 reserved. | Shared alias high-byte address. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"TLow_Limit_Remote_Ch1_High[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 1 alert low limit.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

#### Field part 3: `TLow_Limit_Remote_Ch1_Low` at `0x14` (20)

Location: `registers[8].field_parts[2]`; source: D1 §8.9 p.32 Table 8-11; §8.15 p.35 Table 8-17.

**Truth bit field 1: `TLow_Limit_Remote_Ch1_Low [3:0]` bits 4:7**

Location: `registers[8].field_parts[2].bit_field[0]`; D1 source: D1 §8.9 p.32 Table 8-11; §8.15 p.35 Table 8-17.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TLow_Limit_Remote_Ch1_Low [3:0] | TLow_Limit_Remote_Ch1_Low [3:0] |
| `field_description` | 0.0586 | 1.0 | Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4. | Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 2: `Reserved` bits 0:3**

Location: `registers[8].field_parts[2].bit_field[1]`; D1 source: D1 §8.9 p.32 Table 8-11; §8.15 p.35 Table 8-17. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 0.941694) = **0.970847**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TLow_Limit_Remote_Ch1_Low | TLow_Limit_Remote_Ch1_Low |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Low-byte address containing limit bits 3:0 in register bits 7:4."} | {"hex":"0x14","decimal":"20","bank":"","page":"","description":"Low-byte address containing limit bits 3:0 in register bits 7:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-1 low limit: bits 11:4 at 08h/0Eh, bits 3:0 in bits 7:4 at 14h; low bits 3:0 reserved. | Low-byte register for the limit. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | mean of all bit-field Q values listed below | [{"name_or_parameter":"TLow_Limit_Remote_Ch1_Low [3:0]","field_description":"Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.970847) = 0.990878.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 1.000000, 0.990878) = **0.996959**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | equivalent merged name accepted; D1 splits the high/low access entries | TLow_Limit_Remote_Ch1 |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":"Primary high-byte address containing limit bits 11:4."},{"hex":"0x0E","decimal":"14","bank":"","page":"","description":"Shared alias of the high-byte address containing limit bits 11:4."},{"hex":"0x14","decimal":"20","bank":"","page":"","description":"Low-byte address containing limit bits 3:0 in register bits 7:4."}] | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":"Primary high-byte address containing limit bits 11:4."},{"hex":"0x0E","decimal":"14","bank":"","page":"","description":"Shared alias of the high-byte address containing limit bits 11:4."},{"hex":"0x14","decimal":"20","bank":"","page":"","description":"Low-byte address containing limit bits 3:0 in register bits 7:4."}] |
| `register_description` | 0.0564 | 1.0 | One logical 12-bit remote-channel-1 low limit: bits 11:4 at 08h/0Eh, bits 3:0 in bits 7:4 at 14h; low bits 3:0 reserved. | Configures the full 12-bit remote channel 1 ALERT low limit using the high- and low-byte registers. The high register contains bits 11:4 and the low register contains bits 3:0 in physical bits 7:4. The reset setting corresponds to 0°C. |
| `width_bits` | 0.0590 | 0.0 | 12 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.996959 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"TLow_Limit_Remote_Ch1_High","physical_address":{"hex":"0x08","decimal":"8","bank":"","page":"","description":"Primary high-byte address containing limit bits 11:4."},"description":"Primary high-byte address.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"TLow_Limit_Remote_Ch1_High[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 1 alert low limit.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]},{"register_name":"TLow_Limit_Remote_Ch1_High","physical_address":{"hex":"0x0E","decimal":"14","bank":"","page":"","description":"Shared alias of the high-byte address containing limit bits 11:4."},"description":"Shared alias high-byte address.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"TLow_Limit_Remote_Ch1_High[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 1 alert low limit.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]},{"register_name":"TLow_Limit_Remote_Ch1_Low","physical_address":{"hex":"0x14","decimal":"20","bank":"","page":"","description":"Low-byte address containing limit bits 3:0 in register bits 7:4."},"description":"Low-byte register for the limit.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"TLow_Limit_Remote_Ch1_Low [3:0]","field_description":"Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}]}] |
| `default_value` | 0.0667 | 1.0 | 000h | 000h |
| `default_value_description` | 0.0334 | 1.0 | Combined 12-bit limit inferred from high-byte reset 00h and low data-nibble reset 0h; corresponds to 0°C. | Combined 12-bit limit inferred from high-byte reset 00h and low data-nibble reset 0h; corresponds to 0°C. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 0.0 + 0.0590 x 1.0 + 0.2987 x 0.996959 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.940098.

## Extracted logical register 10: `One_Shot`

v1 location: `registers[9]`; datasheet association: D1 §8.10, p.33, Table 8-12.

Associated physical address entries: 0x0F (15).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `One_Shot` at `0x0F` (15)

Location: `registers[9].field_parts[0]`; source: D1 §8.10, p.33, Table 8-12.

**Truth bit field 1: `One_Shot[7:0]` bits 0:7**

Location: `registers[9].field_parts[0].bit_field[0]`; D1 source: D1 §8.10, p.33, Table 8-12.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | One_Shot[7:0] | One_Shot[7:0] |
| `field_description` | 0.0586 | 1.0 | Writing any value triggers a one-shot conversion in Shutdown mode; no effect in continuous mode. | Writing any value triggers a one-shot conversion in Shutdown mode; no effect in continuous mode. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | W | W |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | One_Shot | One_Shot |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":"One-shot conversion command register."} | {"hex":"0x0F","decimal":"15","bank":"","page":"","description":"One-shot conversion command register."} |
| `description` | 0.0693 | 1.0 | Write-only one-shot command; any value triggers conversion in Shutdown and has no effect in continuous mode. | One-shot conversion trigger byte. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | W | W |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"One_Shot[7:0]","field_description":"Writing any value triggers a one-shot conversion in Shutdown mode; no effect in continuous mode.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"W"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | One_Shot | One_Shot |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"One-shot conversion command register."}] | [{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"One-shot conversion command register."}] |
| `register_description` | 0.0564 | 1.0 | Write-only one-shot command; any value triggers conversion in Shutdown and has no effect in continuous mode. | Writing any value triggers a one-shot conversion while the Configuration register Mode bit selects Shutdown mode. Writes have no effect in continuous mode. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | W | W |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"One_Shot","physical_address":{"hex":"0x0F","decimal":"15","bank":"","page":"","description":"One-shot conversion command register."},"description":"One-shot conversion trigger byte.","width_bits":8,"type_write_read":"W","bit_field":[{"name_or_parameter":"One_Shot[7:0]","field_description":"Writing any value triggers a one-shot conversion in Shutdown mode; no effect in continuous mode.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"W"}]}] |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | Reset value. | Reset value. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## Extracted logical register 11: `Scratchpad1`

v1 location: `registers[10]`; datasheet association: D1 §8.12, p.34, Table 8-14.

Associated physical address entries: 0x11 (17).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Scratchpad1` at `0x11` (17)

Location: `registers[10].field_parts[0]`; source: D1 §8.12, p.34, Table 8-14.

**Truth bit field 1: `Scratchpad1[7:0]` bits 0:7**

Location: `registers[10].field_parts[0].bit_field[0]`; D1 source: D1 §8.12, p.34, Table 8-14.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Scratchpad1[7:0] | Scratchpad1[7:0] |
| `field_description` | 0.0586 | 1.0 | User-programmable volatile data; reads return the previously programmed content. | User-programmable volatile data; reads return the previously programmed content. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Scratchpad1 | Scratchpad1 |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Scratchpad 1 data register."} | {"hex":"0x11","decimal":"17","bank":"","page":"","description":"Scratchpad 1 data register."} |
| `description` | 0.0693 | 1.0 | Volatile editable/readable 8-bit user-programmable data. | 8-bit volatile scratchpad storage. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Scratchpad1[7:0]","field_description":"User-programmable volatile data; reads return the previously programmed content.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Scratchpad1 | Scratchpad1 |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Scratchpad 1 data register."}] | [{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Scratchpad 1 data register."}] |
| `register_description` | 0.0564 | 1.0 | Volatile editable/readable 8-bit user-programmable data. | Volatile, readable and writable storage for user-programmable data such as serial-number or system-calibration data. Power must remain supplied to retain the programmed content. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Scratchpad1","physical_address":{"hex":"0x11","decimal":"17","bank":"","page":"","description":"Scratchpad 1 data register."},"description":"8-bit volatile scratchpad storage.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Scratchpad1[7:0]","field_description":"User-programmable volatile data; reads return the previously programmed content.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | Reset value. | Reset value. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## Extracted logical register 12: `Scratchpad2`

v1 location: `registers[11]`; datasheet association: D1 §8.13, p.34, Table 8-15.

Associated physical address entries: 0x12 (18).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Scratchpad2` at `0x12` (18)

Location: `registers[11].field_parts[0]`; source: D1 §8.13, p.34, Table 8-15.

**Truth bit field 1: `Scratchpad2[7:0]` bits 0:7**

Location: `registers[11].field_parts[0].bit_field[0]`; D1 source: D1 §8.13, p.34, Table 8-15.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Scratchpad2[7:0] | Scratchpad2[7:0] |
| `field_description` | 0.0586 | 1.0 | User-programmable volatile data; reads return the previously programmed content. | User-programmable volatile data; reads return the previously programmed content. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Scratchpad2 | Scratchpad2 |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"Scratchpad 2 data register."} | {"hex":"0x12","decimal":"18","bank":"","page":"","description":"Scratchpad 2 data register."} |
| `description` | 0.0693 | 1.0 | Volatile editable/readable 8-bit user-programmable data. | 8-bit volatile scratchpad storage. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Scratchpad2[7:0]","field_description":"User-programmable volatile data; reads return the previously programmed content.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Scratchpad2 | Scratchpad2 |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x12","decimal":"18","bank":"","page":"","description":"Scratchpad 2 data register."}] | [{"hex":"0x12","decimal":"18","bank":"","page":"","description":"Scratchpad 2 data register."}] |
| `register_description` | 0.0564 | 1.0 | Volatile editable/readable 8-bit user-programmable data. | Volatile, readable and writable storage for user-programmable data such as serial-number or system-calibration data. Power must remain supplied to retain the programmed content. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Scratchpad2","physical_address":{"hex":"0x12","decimal":"18","bank":"","page":"","description":"Scratchpad 2 data register."},"description":"8-bit volatile scratchpad storage.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Scratchpad2[7:0]","field_description":"User-programmable volatile data; reads return the previously programmed content.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | Reset value. | Reset value. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## Extracted logical register 13: `THigh_Limit_Remote_Ch2`

v1 location: `registers[12]`; datasheet association: D1 §8.16 p.36 Table 8-18; §8.18 p.37 Table 8-20.

Associated physical address entries: 0x15 (21), 0x17 (23).

Audit findings for this logical register: v1 `width_bits=16` is wrong; D1 defines a 12-bit logical quantity. 1 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `THigh_Limit_Remote_Ch2_High` at `0x15` (21)

Location: `registers[12].field_parts[0]`; source: D1 §8.16 p.36 Table 8-18; §8.18 p.37 Table 8-20.

**Truth bit field 1: `THigh_Limit_Remote_Ch2_High[11:4]` bits 0:7**

Location: `registers[12].field_parts[0].bit_field[0]`; D1 source: D1 §8.16 p.36 Table 8-18; §8.18 p.37 Table 8-20.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THigh_Limit_Remote_Ch2_High[11:4] | THigh_Limit_Remote_Ch2_High[11:4] |
| `field_description` | 0.0586 | 1.0 | Bits 11:4 of the 12-bit remote channel 2 alert high limit. | Bits 11:4 of the 12-bit remote channel 2 alert high limit. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | THigh_Limit_Remote_Ch2_High | THigh_Limit_Remote_Ch2_High |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"High-byte address containing remote channel 2 high-limit bits 11:4."} | {"hex":"0x15","decimal":"21","bank":"","page":"","description":"High-byte address containing remote channel 2 high-limit bits 11:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-2 high limit: bits 11:4 at 15h, bits 3:0 in bits 7:4 at 17h; low bits 3:0 reserved. | High byte of the limit. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"THigh_Limit_Remote_Ch2_High[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 2 alert high limit.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

#### Field part 2: `THigh_Limit_Remote_Ch2_Low` at `0x17` (23)

Location: `registers[12].field_parts[1]`; source: D1 §8.16 p.36 Table 8-18; §8.18 p.37 Table 8-20.

**Truth bit field 1: `THigh_Limit_Remote_Ch2_Low[3:0]` bits 4:7**

Location: `registers[12].field_parts[1].bit_field[0]`; D1 source: D1 §8.16 p.36 Table 8-18; §8.18 p.37 Table 8-20.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THigh_Limit_Remote_Ch2_Low[3:0] | THigh_Limit_Remote_Ch2_Low[3:0] |
| `field_description` | 0.0586 | 1.0 | Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4. | Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 2: `Reserved` bits 0:3**

Location: `registers[12].field_parts[1].bit_field[1]`; D1 source: D1 §8.16 p.36 Table 8-18; §8.18 p.37 Table 8-20. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 0.941694) = **0.970847**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | THigh_Limit_Remote_Ch2_Low | THigh_Limit_Remote_Ch2_Low |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Low-byte address containing remote channel 2 high-limit bits 3:0 in register bits 7:4."} | {"hex":"0x17","decimal":"23","bank":"","page":"","description":"Low-byte address containing remote channel 2 high-limit bits 3:0 in register bits 7:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-2 high limit: bits 11:4 at 15h, bits 3:0 in bits 7:4 at 17h; low bits 3:0 reserved. | Low-byte register for the limit. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | mean of all bit-field Q values listed below | [{"name_or_parameter":"THigh_Limit_Remote_Ch2_Low[3:0]","field_description":"Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.970847) = 0.990878.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 0.990878) = **0.995439**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | equivalent merged name accepted; D1 splits the high/low access entries | THigh_Limit_Remote_Ch2 |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x15","decimal":"21","bank":"","page":"","description":"High-byte address containing remote channel 2 high-limit bits 11:4."},{"hex":"0x17","decimal":"23","bank":"","page":"","description":"Low-byte address containing remote channel 2 high-limit bits 3:0 in register bits 7:4."}] | [{"hex":"0x15","decimal":"21","bank":"","page":"","description":"High-byte address containing remote channel 2 high-limit bits 11:4."},{"hex":"0x17","decimal":"23","bank":"","page":"","description":"Low-byte address containing remote channel 2 high-limit bits 3:0 in register bits 7:4."}] |
| `register_description` | 0.0564 | 1.0 | One logical 12-bit remote-channel-2 high limit: bits 11:4 at 15h, bits 3:0 in bits 7:4 at 17h; low bits 3:0 reserved. | Configures the full 12-bit remote channel 2 ALERT high limit using the high- and low-byte registers. The reset setting corresponds to 85°C. |
| `width_bits` | 0.0590 | 0.0 | 12 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.995439 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"THigh_Limit_Remote_Ch2_High","physical_address":{"hex":"0x15","decimal":"21","bank":"","page":"","description":"High-byte address containing remote channel 2 high-limit bits 11:4."},"description":"High byte of the limit.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THigh_Limit_Remote_Ch2_High[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 2 alert high limit.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]},{"register_name":"THigh_Limit_Remote_Ch2_Low","physical_address":{"hex":"0x17","decimal":"23","bank":"","page":"","description":"Low-byte address containing remote channel 2 high-limit bits 3:0 in register bits 7:4."},"description":"Low-byte register for the limit.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THigh_Limit_Remote_Ch2_Low[3:0]","field_description":"Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}]}] |
| `default_value` | 0.0667 | 1.0 | 550h | 550h |
| `default_value_description` | 0.0334 | 1.0 | Combined 12-bit limit inferred from high-byte reset 55h and low data-nibble reset 0h; corresponds to 85°C. | Combined 12-bit limit inferred from high-byte reset 55h and low data-nibble reset 0h; corresponds to 85°C. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 0.0 + 0.0590 x 1.0 + 0.2987 x 0.995439 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.939644.

## Extracted logical register 14: `TLow_Limit_Remote_Ch2`

v1 location: `registers[13]`; datasheet association: D1 §8.17 p.36 Table 8-19; §8.19 p.37 Table 8-21.

Associated physical address entries: 0x16 (22), 0x18 (24).

Audit findings for this logical register: v1 `width_bits=16` is wrong; D1 defines a 12-bit logical quantity. 1 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `TLow_Limit_Remote_Ch2_High` at `0x16` (22)

Location: `registers[13].field_parts[0]`; source: D1 §8.17 p.36 Table 8-19; §8.19 p.37 Table 8-21.

**Truth bit field 1: `TLow_Limit_Remote_Ch2_High[11:4]` bits 0:7**

Location: `registers[13].field_parts[0].bit_field[0]`; D1 source: D1 §8.17 p.36 Table 8-19; §8.19 p.37 Table 8-21.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TLow_Limit_Remote_Ch2_High[11:4] | TLow_Limit_Remote_Ch2_High[11:4] |
| `field_description` | 0.0586 | 1.0 | Bits 11:4 of the 12-bit remote channel 2 alert low limit. | Bits 11:4 of the 12-bit remote channel 2 alert low limit. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TLow_Limit_Remote_Ch2_High | TLow_Limit_Remote_Ch2_High |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"High-byte address containing remote channel 2 low-limit bits 11:4."} | {"hex":"0x16","decimal":"22","bank":"","page":"","description":"High-byte address containing remote channel 2 low-limit bits 11:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-2 low limit: bits 11:4 at 16h, bits 3:0 in bits 7:4 at 18h; low bits 3:0 reserved. | High byte of the limit. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"TLow_Limit_Remote_Ch2_High[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 2 alert low limit.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

#### Field part 2: `TLow_Limit_Remote_Ch2_Low` at `0x18` (24)

Location: `registers[13].field_parts[1]`; source: D1 §8.17 p.36 Table 8-19; §8.19 p.37 Table 8-21.

**Truth bit field 1: `TLow_Limit_Remote_Ch2_Low [3:0]` bits 4:7**

Location: `registers[13].field_parts[1].bit_field[0]`; D1 source: D1 §8.17 p.36 Table 8-19; §8.19 p.37 Table 8-21.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | TLow_Limit_Remote_Ch2_Low [3:0] | TLow_Limit_Remote_Ch2_Low [3:0] |
| `field_description` | 0.0586 | 1.0 | Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4. | Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 2: `Reserved` bits 0:3**

Location: `registers[13].field_parts[1].bit_field[1]`; D1 source: D1 §8.17 p.36 Table 8-19; §8.19 p.37 Table 8-21. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 0.941694) = **0.970847**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TLow_Limit_Remote_Ch2_Low | TLow_Limit_Remote_Ch2_Low |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Low-byte address containing remote channel 2 low-limit bits 3:0 in register bits 7:4."} | {"hex":"0x18","decimal":"24","bank":"","page":"","description":"Low-byte address containing remote channel 2 low-limit bits 3:0 in register bits 7:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-2 low limit: bits 11:4 at 16h, bits 3:0 in bits 7:4 at 18h; low bits 3:0 reserved. | Low-byte register for the limit. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | mean of all bit-field Q values listed below | [{"name_or_parameter":"TLow_Limit_Remote_Ch2_Low [3:0]","field_description":"Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.970847) = 0.990878.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 0.990878) = **0.995439**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | equivalent merged name accepted; D1 splits the high/low access entries | TLow_Limit_Remote_Ch2 |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x16","decimal":"22","bank":"","page":"","description":"High-byte address containing remote channel 2 low-limit bits 11:4."},{"hex":"0x18","decimal":"24","bank":"","page":"","description":"Low-byte address containing remote channel 2 low-limit bits 3:0 in register bits 7:4."}] | [{"hex":"0x16","decimal":"22","bank":"","page":"","description":"High-byte address containing remote channel 2 low-limit bits 11:4."},{"hex":"0x18","decimal":"24","bank":"","page":"","description":"Low-byte address containing remote channel 2 low-limit bits 3:0 in register bits 7:4."}] |
| `register_description` | 0.0564 | 1.0 | One logical 12-bit remote-channel-2 low limit: bits 11:4 at 16h, bits 3:0 in bits 7:4 at 18h; low bits 3:0 reserved. | Configures the full 12-bit remote channel 2 ALERT low limit using the high- and low-byte registers. The reset setting corresponds to 0°C. |
| `width_bits` | 0.0590 | 0.0 | 12 | 16 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.995439 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"TLow_Limit_Remote_Ch2_High","physical_address":{"hex":"0x16","decimal":"22","bank":"","page":"","description":"High-byte address containing remote channel 2 low-limit bits 11:4."},"description":"High byte of the limit.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"TLow_Limit_Remote_Ch2_High[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 2 alert low limit.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]},{"register_name":"TLow_Limit_Remote_Ch2_Low","physical_address":{"hex":"0x18","decimal":"24","bank":"","page":"","description":"Low-byte address containing remote channel 2 low-limit bits 3:0 in register bits 7:4."},"description":"Low-byte register for the limit.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"TLow_Limit_Remote_Ch2_Low [3:0]","field_description":"Bits 3:0 of the 12-bit limit, stored in physical register bits 7:4.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}]}] |
| `default_value` | 0.0667 | 1.0 | 000h | 000h |
| `default_value_description` | 0.0334 | 1.0 | Combined 12-bit limit inferred from high-byte reset 00h and low data-nibble reset 0h; corresponds to 0°C. | Combined 12-bit limit inferred from high-byte reset 00h and low data-nibble reset 0h; corresponds to 0°C. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 0.0 + 0.0590 x 1.0 + 0.2987 x 0.995439 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.939644.

## Extracted logical register 15: `THigh_Crit_Remote_Ch1`

v1 location: `registers[14]`; datasheet association: D1 §8.20, p.38, Table 8-22.

Associated physical address entries: 0x19 (25).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `THigh_Crit_Remote_Ch1` at `0x19` (25)

Location: `registers[14].field_parts[0]`; source: D1 §8.20, p.38, Table 8-22.

**Truth bit field 1: `THigh_Crit_Remote_Ch1[7:0]` bits 0:7**

Location: `registers[14].field_parts[0].bit_field[0]`; D1 source: D1 §8.20, p.38, Table 8-22.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THigh_Crit_Remote_Ch1[7:0] | THigh_Crit_Remote_Ch1[7:0] |
| `field_description` | 0.0586 | 1.0 | 8-bit remote channel 1 temperature critical-limit setting; two's complement with an LSB of 1°C. | 8-bit remote channel 1 temperature critical-limit setting; two's complement with an LSB of 1°C. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | THigh_Crit_Remote_Ch1 | THigh_Crit_Remote_Ch1 |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x19","decimal":"25","bank":"","page":"","description":"Remote channel 1 critical-temperature limit register."} | {"hex":"0x19","decimal":"25","bank":"","page":"","description":"Remote channel 1 critical-temperature limit register."} |
| `description` | 0.0693 | 1.0 | 8-bit remote-channel-1 T_CRIT limit, two's complement, 1°C LSB; reset 55h = 85°C. | Remote channel 1 T_CRIT limit. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"THigh_Crit_Remote_Ch1[7:0]","field_description":"8-bit remote channel 1 temperature critical-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | THigh_Crit_Remote_Ch1 | THigh_Crit_Remote_Ch1 |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x19","decimal":"25","bank":"","page":"","description":"Remote channel 1 critical-temperature limit register."}] | [{"hex":"0x19","decimal":"25","bank":"","page":"","description":"Remote channel 1 critical-temperature limit register."}] |
| `register_description` | 0.0564 | 1.0 | 8-bit remote-channel-1 T_CRIT limit, two's complement, 1°C LSB; reset 55h = 85°C. | Configures the remote channel 1 critical-temperature limit as an 8-bit two's-complement value with an LSB of 1°C. Reset value 55h corresponds to 85°C. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"THigh_Crit_Remote_Ch1","physical_address":{"hex":"0x19","decimal":"25","bank":"","page":"","description":"Remote channel 1 critical-temperature limit register."},"description":"Remote channel 1 T_CRIT limit.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THigh_Crit_Remote_Ch1[7:0]","field_description":"8-bit remote channel 1 temperature critical-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.0 | 55h | 55h |
| `default_value_description` | 0.0334 | 1.0 | Reset value; corresponds to 85°C. | Reset value; corresponds to 85°C. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## Extracted logical register 16: `THigh_Crit_Remote_Ch2`

v1 location: `registers[15]`; datasheet association: D1 §8.21, p.38, Table 8-23.

Associated physical address entries: 0x1A (26).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `THigh_Crit_Remote_Ch2` at `0x1A` (26)

Location: `registers[15].field_parts[0]`; source: D1 §8.21, p.38, Table 8-23.

**Truth bit field 1: `THigh_Crit_Remote_Ch2[7:0]` bits 0:7**

Location: `registers[15].field_parts[0].bit_field[0]`; D1 source: D1 §8.21, p.38, Table 8-23.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THigh_Crit_Remote_Ch2[7:0] | THigh_Crit_Remote_Ch2[7:0] |
| `field_description` | 0.0586 | 1.0 | 8-bit remote channel 2 temperature critical-limit setting; two's complement with an LSB of 1°C. | 8-bit remote channel 2 temperature critical-limit setting; two's complement with an LSB of 1°C. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | THigh_Crit_Remote_Ch2 | THigh_Crit_Remote_Ch2 |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Remote channel 2 critical-temperature limit register."} | {"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Remote channel 2 critical-temperature limit register."} |
| `description` | 0.0693 | 1.0 | 8-bit remote-channel-2 T_CRIT limit, two's complement, 1°C LSB; reset 55h = 85°C. | Remote channel 2 T_CRIT limit. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"THigh_Crit_Remote_Ch2[7:0]","field_description":"8-bit remote channel 2 temperature critical-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | THigh_Crit_Remote_Ch2 | THigh_Crit_Remote_Ch2 |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Remote channel 2 critical-temperature limit register."}] | [{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Remote channel 2 critical-temperature limit register."}] |
| `register_description` | 0.0564 | 1.0 | 8-bit remote-channel-2 T_CRIT limit, two's complement, 1°C LSB; reset 55h = 85°C. | Configures the remote channel 2 critical-temperature limit as an 8-bit two's-complement value with an LSB of 1°C. Reset value 55h corresponds to 85°C. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"THigh_Crit_Remote_Ch2","physical_address":{"hex":"0x1A","decimal":"26","bank":"","page":"","description":"Remote channel 2 critical-temperature limit register."},"description":"Remote channel 2 T_CRIT limit.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THigh_Crit_Remote_Ch2[7:0]","field_description":"8-bit remote channel 2 temperature critical-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.0 | 55h | 55h |
| `default_value_description` | 0.0334 | 1.0 | Reset value; corresponds to 85°C. | Reset value; corresponds to 85°C. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## Extracted logical register 17: `Diode_Fault`

v1 location: `registers[16]`; datasheet association: D1 §8.22, p.39, Table 8-24 and preceding prose.

Associated physical address entries: 0x1B (27).

Audit findings for this logical register: 2 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Diode_Fault` at `0x1B` (27)

Location: `registers[16].field_parts[0]`; source: D1 §8.22, p.39, Table 8-24 and preceding prose.

**Truth bit field 1: `Reserved` bits 4:7**

Location: `registers[16].field_parts[0].bit_field[0]`; D1 source: D1 §8.22, p.39, Table 8-24 and preceding prose. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Truth bit field 2: `Short` bits 3:3**

Location: `registers[16].field_parts[0].bit_field[1]`; D1 source: D1 §8.22, p.39, Table 8-24 and preceding prose.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Short | Short |
| `field_description` | 0.0586 | 1.0 | Indicates that remote channel 1 and/or remote channel 2 is shorted. | Indicates that remote channel 1 and/or remote channel 2 is shorted. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"1b","value_description":"Remote channel 1 and/or remote channel 2 is shorted."}] | [{"value":"1b","value_description":"Remote channel 1 and/or remote channel 2 is shorted."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 3: `Ch2_Open` bits 2:2**

Location: `registers[16].field_parts[0].bit_field[2]`; D1 source: D1 §8.22, p.39, Table 8-24 and preceding prose.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Ch2_Open | Ch2_Open |
| `field_description` | 0.0586 | 1.0 | Indicates an open condition on remote channel 2. | Indicates an open condition on remote channel 2. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"1b","value_description":"Remote channel 2 has an open condition."}] | [{"value":"1b","value_description":"Remote channel 2 has an open condition."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 4: `Ch1_Open` bits 1:1**

Location: `registers[16].field_parts[0].bit_field[3]`; D1 source: D1 §8.22, p.39, Table 8-24 and preceding prose.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Ch1_Open | Ch1_Open |
| `field_description` | 0.0586 | 1.0 | Indicates an open condition on remote channel 1. | Indicates an open condition on remote channel 1. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"1b","value_description":"Remote channel 1 has an open condition."}] | [{"value":"1b","value_description":"Remote channel 1 has an open condition."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 5: `Reserved` bits 0:0**

Location: `registers[16].field_parts[0].bit_field[4]`; D1 source: D1 §8.22, p.39, Table 8-24 and preceding prose. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Field-part aggregation**

`bit_field` correctness = mean(0.941694, 1.000000, 1.000000, 1.000000, 0.941694) = **0.976678**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Diode_Fault | Diode_Fault |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Remote-diode open/short fault indicator register."} | {"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Remote-diode open/short fault indicator register."} |
| `description` | 0.0693 | 1.0 | Remote-diode open/short indicators; affected result 0000h, short may assert ALERT, open does not. | Remote-channel diode fault flags. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.976678 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Short","field_description":"Indicates that remote channel 1 and/or remote channel 2 is shorted.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"1b","value_description":"Remote channel 1 and/or remote channel 2 is shorted."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Ch2_Open","field_description":"Indicates an open condition on remote channel 2.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"1b","value_description":"Remote channel 2 has an open condition."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Ch1_Open","field_description":"Indicates an open condition on remote channel 1.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"1b","value_description":"Remote channel 1 has an open condition."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.976678) = 0.992702.

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.992702) = **0.992702**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Diode_Fault | Diode_Fault |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Remote-diode open/short fault indicator register."}] | [{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Remote-diode open/short fault indicator register."}] |
| `register_description` | 0.0564 | 1.0 | Remote-diode open/short indicators; affected result 0000h, short may assert ALERT, open does not. | Indicates open or short fault conditions on the remote channels. A fault causes the affected remote conversion result to become 0000h. Short status can assert ALERT subject to channel masking and mode; open status does not assert ALERT. Fault bits clear when the corresponding physical fault clears following conversion. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.992702 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Diode_Fault","physical_address":{"hex":"0x1B","decimal":"27","bank":"","page":"","description":"Remote-diode open/short fault indicator register."},"description":"Remote-channel diode fault flags.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Short","field_description":"Indicates that remote channel 1 and/or remote channel 2 is shorted.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"1b","value_description":"Remote channel 1 and/or remote channel 2 is shorted."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Ch2_Open","field_description":"Indicates an open condition on remote channel 2.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"1b","value_description":"Remote channel 2 has an open condition."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Ch1_Open","field_description":"Indicates an open condition on remote channel 1.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"1b","value_description":"Remote channel 1 has an open condition."}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":""}]}] |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | Reset value. | Reset value. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 0.992702 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.997820.

## Extracted logical register 18: `Alert_Mask`

v1 location: `registers[17]`; datasheet association: D1 §8.23, p.40, Table 8-25.

Associated physical address entries: 0x1F (31).

Audit findings for this logical register: 1 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Alert_Mask` at `0x1F` (31)

Location: `registers[17].field_parts[0]`; source: D1 §8.23, p.40, Table 8-25.

**Truth bit field 1: `Reserved` bits 3:7**

Location: `registers[17].field_parts[0].bit_field[0]`; D1 source: D1 §8.23, p.40, Table 8-25. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Truth bit field 2: `Mask_Ch2` bits 2:2**

Location: `registers[17].field_parts[0].bit_field[1]`; D1 source: D1 §8.23, p.40, Table 8-25.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Mask_Ch2 | Mask_Ch2 |
| `field_description` | 0.0586 | 1.0 | When set to 1, prevents ALERT assertion for remote channel 2 out-of-limit or diode-fault conditions. | When set to 1, prevents ALERT assertion for remote channel 2 out-of-limit or diode-fault conditions. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"1","value_description":"Mask remote channel 2 ALERT assertion."}] | [{"value":"1","value_description":"Mask remote channel 2 ALERT assertion."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 3: `Mask_Ch1` bits 1:1**

Location: `registers[17].field_parts[0].bit_field[2]`; D1 source: D1 §8.23, p.40, Table 8-25.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Mask_Ch1 | Mask_Ch1 |
| `field_description` | 0.0586 | 1.0 | When set to 1, prevents ALERT assertion for remote channel 1 out-of-limit or diode-fault conditions. | When set to 1, prevents ALERT assertion for remote channel 1 out-of-limit or diode-fault conditions. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"1","value_description":"Mask remote channel 1 ALERT assertion."}] | [{"value":"1","value_description":"Mask remote channel 1 ALERT assertion."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 4: `Mask_L` bits 0:0**

Location: `registers[17].field_parts[0].bit_field[3]`; D1 source: D1 §8.23, p.40, Table 8-25.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Mask_L | Mask_L |
| `field_description` | 0.0586 | 1.0 | When set to 1, prevents ALERT assertion when the local channel is out of limit. | When set to 1, prevents ALERT assertion when the local channel is out of limit. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"1","value_description":"Mask local-channel ALERT assertion."}] | [{"value":"1","value_description":"Mask local-channel ALERT assertion."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(0.941694, 1.000000, 1.000000, 1.000000) = **0.985424**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Alert_Mask | Alert_Mask |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Per-channel ALERT mask register."} | {"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Per-channel ALERT mask register."} |
| `description` | 0.0693 | 1.0 | Per-channel ALERT masking controls. | Per-channel ALERT masking controls. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.985424 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":3,"bit_end":7,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Mask_Ch2","field_description":"When set to 1, prevents ALERT assertion for remote channel 2 out-of-limit or diode-fault conditions.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"1","value_description":"Mask remote channel 2 ALERT assertion."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Mask_Ch1","field_description":"When set to 1, prevents ALERT assertion for remote channel 1 out-of-limit or diode-fault conditions.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"1","value_description":"Mask remote channel 1 ALERT assertion."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Mask_L","field_description":"When set to 1, prevents ALERT assertion when the local channel is out of limit.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"1","value_description":"Mask local-channel ALERT assertion."}],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.985424) = 0.995439.

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.995439) = **0.995439**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Alert_Mask | Alert_Mask |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Per-channel ALERT mask register."}] | [{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Per-channel ALERT mask register."}] |
| `register_description` | 0.0564 | 1.0 | Per-channel ALERT masking controls. | Controls local and remote channel alert masking. In Interrupt mode, masking a channel prevents its out-of-limit or specified diode-fault condition from asserting ALERT low. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.995439 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Alert_Mask","physical_address":{"hex":"0x1F","decimal":"31","bank":"","page":"","description":"Per-channel ALERT mask register."},"description":"Per-channel ALERT masking controls.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":3,"bit_end":7,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Mask_Ch2","field_description":"When set to 1, prevents ALERT assertion for remote channel 2 out-of-limit or diode-fault conditions.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"1","value_description":"Mask remote channel 2 ALERT assertion."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Mask_Ch1","field_description":"When set to 1, prevents ALERT assertion for remote channel 1 out-of-limit or diode-fault conditions.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"1","value_description":"Mask remote channel 1 ALERT assertion."}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Mask_L","field_description":"When set to 1, prevents ALERT assertion when the local channel is out of limit.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"1","value_description":"Mask local-channel ALERT assertion."}],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | Reset value. | Reset value. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 0.995439 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.998638.

## Extracted logical register 19: `THigh_Crit_Local`

v1 location: `registers[18]`; datasheet association: D1 §8.24, p.41, Table 8-26.

Associated physical address entries: 0x20 (32).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `THigh_Crit_Local` at `0x20` (32)

Location: `registers[18].field_parts[0]`; source: D1 §8.24, p.41, Table 8-26.

**Truth bit field 1: `THigh_Crit_Local[7:0]` bits 0:7**

Location: `registers[18].field_parts[0].bit_field[0]`; D1 source: D1 §8.24, p.41, Table 8-26.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | THigh_Crit_Local[7:0] | THigh_Crit_Local[7:0] |
| `field_description` | 0.0586 | 1.0 | 8-bit local-channel temperature critical-limit setting; two's complement with an LSB of 1°C. | 8-bit local-channel temperature critical-limit setting; two's complement with an LSB of 1°C. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | THigh_Crit_Local | THigh_Crit_Local |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Local-channel critical-temperature limit register."} | {"hex":"0x20","decimal":"32","bank":"","page":"","description":"Local-channel critical-temperature limit register."} |
| `description` | 0.0693 | 1.0 | 8-bit local T_CRIT limit, two's complement, 1°C LSB; reset 55h = 85°C. | Local-channel T_CRIT limit. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"THigh_Crit_Local[7:0]","field_description":"8-bit local-channel temperature critical-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | THigh_Crit_Local | THigh_Crit_Local |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Local-channel critical-temperature limit register."}] | [{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Local-channel critical-temperature limit register."}] |
| `register_description` | 0.0564 | 1.0 | 8-bit local T_CRIT limit, two's complement, 1°C LSB; reset 55h = 85°C. | Configures the local-channel critical-temperature limit as an 8-bit two's-complement value with an LSB of 1°C. Reset value 55h corresponds to 85°C. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"THigh_Crit_Local","physical_address":{"hex":"0x20","decimal":"32","bank":"","page":"","description":"Local-channel critical-temperature limit register."},"description":"Local-channel T_CRIT limit.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"THigh_Crit_Local[7:0]","field_description":"8-bit local-channel temperature critical-limit setting; two's complement with an LSB of 1°C.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.0 | 55h | 55h |
| `default_value_description` | 0.0334 | 1.0 | Reset value; corresponds to 85°C. | Reset value; corresponds to 85°C. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## Extracted logical register 20: `Hysteresis`

v1 location: `registers[19]`; datasheet association: D1 §8.25, p.41, Table 8-27.

Associated physical address entries: 0x21 (33).

Audit findings for this logical register: 1 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Hysteresis` at `0x21` (33)

Location: `registers[19].field_parts[0]`; source: D1 §8.25, p.41, Table 8-27.

**Truth bit field 1: `Reserved` bits 5:7**

Location: `registers[19].field_parts[0].bit_field[0]`; D1 source: D1 §8.25, p.41, Table 8-27. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Truth bit field 2: `Hysteresis[4:0]` bits 0:4**

Location: `registers[19].field_parts[0].bit_field[1]`; D1 source: D1 §8.25, p.41, Table 8-27.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Hysteresis[4:0] | Hysteresis[4:0] |
| `field_description` | 0.0586 | 1.0 | 5-bit temperature hysteresis integer with an LSB of 1°C. | 5-bit temperature hysteresis integer with an LSB of 1°C. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(0.941694, 1.000000) = **0.970847**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Hysteresis | Hysteresis |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"ALERT and T_CRIT hysteresis register."} | {"hex":"0x21","decimal":"33","bank":"","page":"","description":"ALERT and T_CRIT hysteresis register."} |
| `description` | 0.0693 | 1.0 | 5-bit ALERT/T_CRIT hysteresis, 1°C LSB; reset 0Ah = 10°C. | Temperature hysteresis setting. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":5,"bit_end":7,"bit_width":3,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Hysteresis[4:0]","field_description":"5-bit temperature hysteresis integer with an LSB of 1°C.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.970847) = 0.990878.

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.990878) = **0.990878**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Hysteresis | Hysteresis |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"ALERT and T_CRIT hysteresis register."}] | [{"hex":"0x21","decimal":"33","bank":"","page":"","description":"ALERT and T_CRIT hysteresis register."}] |
| `register_description` | 0.0564 | 1.0 | 5-bit ALERT/T_CRIT hysteresis, 1°C LSB; reset 0Ah = 10°C. | Configures ALERT and T_CRIT hysteresis for local and remote channels. The setting is a 5-bit integer with an LSB of 1°C; the default is 10°C. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.990878 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Hysteresis","physical_address":{"hex":"0x21","decimal":"33","bank":"","page":"","description":"ALERT and T_CRIT hysteresis register."},"description":"Temperature hysteresis setting.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":5,"bit_end":7,"bit_width":3,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Hysteresis[4:0]","field_description":"5-bit temperature hysteresis integer with an LSB of 1°C.","bit_start":0,"bit_end":4,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.0 | 0Ah | 0Ah |
| `default_value_description` | 0.0334 | 1.0 | Reset value; corresponds to 10°C. | Reset value; corresponds to 10°C. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 0.990878 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.997276.

## Extracted logical register 21: `Temp_Remote_Ch2`

v1 location: `registers[20]`; datasheet association: D1 §8.26-8.27, p.42, Tables 8-28 and 8-29; §7.5.1 p.19 Table 7-1.

Associated physical address entries: 0x23 (35), 0x24 (36).

Audit findings for this logical register: v1 `width_bits=16` is wrong; D1 defines a 12-bit logical quantity. 1 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Temp_Remote_Ch2_High` at `0x23` (35)

Location: `registers[20].field_parts[0]`; source: D1 §8.26-8.27, p.42, Tables 8-28 and 8-29; §7.5.1 p.19 Table 7-1.

**Truth bit field 1: `Temp_Remote_Ch2[11:4]` bits 0:7**

Location: `registers[20].field_parts[0].bit_field[0]`; D1 source: D1 §8.26-8.27, p.42, Tables 8-28 and 8-29; §7.5.1 p.19 Table 7-1.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Temp_Remote_Ch2[11:4] | Temp_Remote_Ch2[11:4] |
| `field_description` | 0.0586 | 1.0 | Bits 11:4 of the 12-bit remote channel 2 temperature result. | Bits 11:4 of the 12-bit remote channel 2 temperature result. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Temp_Remote_Ch2_High | Temp_Remote_Ch2_High |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte containing remote channel 2 result bits 11:4."} | {"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte containing remote channel 2 result bits 11:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-2 temperature result split between 23h and 24h; 0.0625°C LSB; low bits 3:0 reserved. | High byte of the remote channel 2 temperature result. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Temp_Remote_Ch2[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 2 temperature result.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

#### Field part 2: `Temp_Remote_Ch2_Low` at `0x24` (36)

Location: `registers[20].field_parts[1]`; source: D1 §8.26-8.27, p.42, Tables 8-28 and 8-29; §7.5.1 p.19 Table 7-1.

**Truth bit field 1: `Temp_Remote_Ch2_Low[3:0]` bits 4:7**

Location: `registers[20].field_parts[1].bit_field[0]`; D1 source: D1 §8.26-8.27, p.42, Tables 8-28 and 8-29; §7.5.1 p.19 Table 7-1.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Temp_Remote_Ch2_Low[3:0] | Temp_Remote_Ch2_Low[3:0] |
| `field_description` | 0.0586 | 1.0 | Bits 3:0 of the 12-bit remote channel 2 result, stored in physical register bits 7:4. | Bits 3:0 of the 12-bit remote channel 2 result, stored in physical register bits 7:4. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 2: `Reserved` bits 0:3**

Location: `registers[20].field_parts[1].bit_field[1]`; D1 source: D1 §8.26-8.27, p.42, Tables 8-28 and 8-29; §7.5.1 p.19 Table 7-1. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 0.941694) = **0.970847**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Temp_Remote_Ch2_Low | Temp_Remote_Ch2_Low |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low-byte register containing remote channel 2 result bits 3:0 in register bits 7:4."} | {"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low-byte register containing remote channel 2 result bits 3:0 in register bits 7:4."} |
| `description` | 0.0693 | 1.0 | One logical 12-bit remote-channel-2 temperature result split between 23h and 24h; 0.0625°C LSB; low bits 3:0 reserved. | Low-byte register for the remote channel 2 temperature result. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.970847 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Temp_Remote_Ch2_Low[3:0]","field_description":"Bits 3:0 of the 12-bit remote channel 2 result, stored in physical register bits 7:4.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.970847) = 0.990878.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000, 0.990878) = **0.995439**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | equivalent merged name accepted; D1 splits the high/low access entries | Temp_Remote_Ch2 |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte containing remote channel 2 result bits 11:4."},{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low-byte register containing remote channel 2 result bits 3:0 in register bits 7:4."}] | [{"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte containing remote channel 2 result bits 11:4."},{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low-byte register containing remote channel 2 result bits 3:0 in register bits 7:4."}] |
| `register_description` | 0.0564 | 1.0 | One logical 12-bit remote-channel-2 temperature result split between 23h and 24h; 0.0625°C LSB; low bits 3:0 reserved. | Stores the latest 12-bit remote channel 2 temperature conversion result across the high- and low-byte registers. The result is a 12-bit two's-complement value with an LSB of 0.0625°C; use both parts to obtain the full result. The low register's bits 3:0 are reserved. |
| `width_bits` | 0.0590 | 0.0 | 12 | 16 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.995439 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Temp_Remote_Ch2_High","physical_address":{"hex":"0x23","decimal":"35","bank":"","page":"","description":"High byte containing remote channel 2 result bits 11:4."},"description":"High byte of the remote channel 2 temperature result.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Temp_Remote_Ch2[11:4]","field_description":"Bits 11:4 of the 12-bit remote channel 2 temperature result.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]},{"register_name":"Temp_Remote_Ch2_Low","physical_address":{"hex":"0x24","decimal":"36","bank":"","page":"","description":"Low-byte register containing remote channel 2 result bits 3:0 in register bits 7:4."},"description":"Low-byte register for the remote channel 2 temperature result.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Temp_Remote_Ch2_Low[3:0]","field_description":"Bits 3:0 of the 12-bit remote channel 2 result, stored in physical register bits 7:4.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""}]}] |
| `default_value` | 0.0667 | 1.0 | 000h | 000h |
| `default_value_description` | 0.0334 | 1.0 | Combined 12-bit data reset inferred from high-byte reset 00h and low data-nibble reset 0h. | Combined 12-bit data reset inferred from high-byte reset 00h and low data-nibble reset 0h. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 0.0 + 0.0590 x 1.0 + 0.2987 x 0.995439 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.939644.

## Extracted logical register 22: `η-Factor_Ch1`

v1 location: `registers[21]`; datasheet association: D1 §8.28, p.43, Tables 8-30 and 8-31.

Associated physical address entries: 0x27 (39).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `η-Factor_Ch1` at `0x27` (39)

Location: `registers[21].field_parts[0]`; source: D1 §8.28, p.43, Tables 8-30 and 8-31.

**Truth bit field 1: `η-Factor_Ch1[7:0]` bits 0:7**

Location: `registers[21].field_parts[0].bit_field[0]`; D1 source: D1 §8.28, p.43, Tables 8-30 and 8-31.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | η-Factor_Ch1[7:0] | η-Factor_Ch1[7:0] |
| `field_description` | 0.0586 | 1.0 | Diode ideality-factor setting for remote channel 1; values are defined by Table 8-30. | Diode ideality-factor setting for remote channel 1; values are defined by Table 8-30. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | same 48-entry lookup list as D1 Table 8-30: [{"value":"8","value_description":"η-Factor 0.9911"},{"value":"9","value_description":"η-Factor 0.9923"},{"value":"A","value_description":"η-Factor 0.9936"},{"value":"B","value_description":"η-Factor 0.9949"},{"value":"C","value_description":"η-Factor 0.9962"},{"value":"D","value_description":"η-Factor 0.9975"},{"value":"E","value_description":"η-Factor 0.9987"},{"value":"F","value_description":"η-Factor 1.0001"},{"value":"10","value_description":"η-Factor 1.0013"},{"value":"11","value_description":"η-Factor 1.0026"},{"value":"12","value_description":"η-Factor 1.004"},{"value":"13","value_description":"η-Factor 1.0053"},{"value":"14","value_description":"η-Factor 1.0066"},{"value":"15","value_description":"η-Factor 1.0079"},{"value":"16","value_description":"η-Factor 1.0092"},{"value":"17","value_description":"η-Factor 1.0105"},{"value":"18","value_description":"η-Factor 1.0118"},{"value":"19","value_description":"η-Factor 1.0131"},{"value":"1A","value_description":"η-Factor 1.0144"},{"value":"1B","value_description":"η-Factor 1.0159"},{"value":"1C","value_description":"η-Factor 1.0171"},{"value":"1D","value_description":"η-Factor 1.0185"},{"value":"1E","value_description":"η-Factor 1.0198"},{"value":"1F","value_description":"η-Factor 1.0211"},{"value":"20","value_description":"η-Factor 1.0225"},{"value":"21","value_description":"η-Factor 1.0238"},{"value":"22","value_description":"η-Factor 1.0251"},{"value":"23","value_description":"η-Factor 1.0263"},{"value":"24","value_description":"η-Factor 1.0277"},{"value":"25","value_description":"η-Factor 1.0290"},{"value":"26","value_description":"η-Factor 1.0302"},{"value":"27","value_description":"η-Factor 1.0316"},{"value":"28","value_description":"η-Factor 1.0328"},{"value":"29","value_description":"η-Factor 1.0341"},{"value":"2A","value_description":"η-Factor 1.0354"},{"value":"2B","value_description":"η-Factor 1.0367"},{"value":"2C","value_description":"η-Factor 1.0379"},{"value":"2D","value_description":"η-Factor 1.0393"},{"value":"2E","value_description":"η-Factor 1.0405"},{"value":"2F","value_description":"η-Factor 1.0419"},{"value":"30","value_description":"η-Factor 1.0431"},{"value":"31","value_description":"η-Factor 1.0445"},{"value":"32","value_description":"η-Factor 1.0456"},{"value":"33","value_description":"η-Factor 1.0470"},{"value":"34","value_description":"η-Factor 1.0482"},{"value":"35","value_description":"η-Factor 1.0496"},{"value":"36","value_description":"η-Factor 1.0508"},{"value":"37","value_description":"η-Factor 1.0522"}] | [{"value":"8","value_description":"η-Factor 0.9911"},{"value":"9","value_description":"η-Factor 0.9923"},{"value":"A","value_description":"η-Factor 0.9936"},{"value":"B","value_description":"η-Factor 0.9949"},{"value":"C","value_description":"η-Factor 0.9962"},{"value":"D","value_description":"η-Factor 0.9975"},{"value":"E","value_description":"η-Factor 0.9987"},{"value":"F","value_description":"η-Factor 1.0001"},{"value":"10","value_description":"η-Factor 1.0013"},{"value":"11","value_description":"η-Factor 1.0026"},{"value":"12","value_description":"η-Factor 1.004"},{"value":"13","value_description":"η-Factor 1.0053"},{"value":"14","value_description":"η-Factor 1.0066"},{"value":"15","value_description":"η-Factor 1.0079"},{"value":"16","value_description":"η-Factor 1.0092"},{"value":"17","value_description":"η-Factor 1.0105"},{"value":"18","value_description":"η-Factor 1.0118"},{"value":"19","value_description":"η-Factor 1.0131"},{"value":"1A","value_description":"η-Factor 1.0144"},{"value":"1B","value_description":"η-Factor 1.0159"},{"value":"1C","value_description":"η-Factor 1.0171"},{"value":"1D","value_description":"η-Factor 1.0185"},{"value":"1E","value_description":"η-Factor 1.0198"},{"value":"1F","value_description":"η-Factor 1.0211"},{"value":"20","value_description":"η-Factor 1.0225"},{"value":"21","value_description":"η-Factor 1.0238"},{"value":"22","value_description":"η-Factor 1.0251"},{"value":"23","value_description":"η-Factor 1.0263"},{"value":"24","value_description":"η-Factor 1.0277"},{"value":"25","value_description":"η-Factor 1.0290"},{"value":"26","value_description":"η-Factor 1.0302"},{"value":"27","value_description":"η-Factor 1.0316"},{"value":"28","value_description":"η-Factor 1.0328"},{"value":"29","value_description":"η-Factor 1.0341"},{"value":"2A","value_description":"η-Factor 1.0354"},{"value":"2B","value_description":"η-Factor 1.0367"},{"value":"2C","value_description":"η-Factor 1.0379"},{"value":"2D","value_description":"η-Factor 1.0393"},{"value":"2E","value_description":"η-Factor 1.0405"},{"value":"2F","value_description":"η-Factor 1.0419"},{"value":"30","value_description":"η-Factor 1.0431"},{"value":"31","value_description":"η-Factor 1.0445"},{"value":"32","value_description":"η-Factor 1.0456"},{"value":"33","value_description":"η-Factor 1.0470"},{"value":"34","value_description":"η-Factor 1.0482"},{"value":"35","value_description":"η-Factor 1.0496"},{"value":"36","value_description":"η-Factor 1.0508"},{"value":"37","value_description":"η-Factor 1.0522"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | η-Factor_Ch1 | η-Factor_Ch1 |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"Remote channel 1 diode ideality-factor correction register."} | {"hex":"0x27","decimal":"39","bank":"","page":"","description":"Remote channel 1 diode ideality-factor correction register."} |
| `description` | 0.0693 | 1.0 | Remote-channel-1 ideality-factor lookup; reset 12h = η 1.004. | Remote channel 1 ideality-factor setting. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"η-Factor_Ch1[7:0]","field_description":"Diode ideality-factor setting for remote channel 1; values are defined by Table 8-30.","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"8","value_description":"η-Factor 0.9911"},{"value":"9","value_description":"η-Factor 0.9923"},{"value":"A","value_description":"η-Factor 0.9936"},{"value":"B","value_description":"η-Factor 0.9949"},{"value":"C","value_description":"η-Factor 0.9962"},{"value":"D","value_description":"η-Factor 0.9975"},{"value":"E","value_description":"η-Factor 0.9987"},{"value":"F","value_description":"η-Factor 1.0001"},{"value":"10","value_description":"η-Factor 1.0013"},{"value":"11","value_description":"η-Factor 1.0026"},{"value":"12","value_description":"η-Factor 1.004"},{"value":"13","value_description":"η-Factor 1.0053"},{"value":"14","value_description":"η-Factor 1.0066"},{"value":"15","value_description":"η-Factor 1.0079"},{"value":"16","value_description":"η-Factor 1.0092"},{"value":"17","value_description":"η-Factor 1.0105"},{"value":"18","value_description":"η-Factor 1.0118"},{"value":"19","value_description":"η-Factor 1.0131"},{"value":"1A","value_description":"η-Factor 1.0144"},{"value":"1B","value_description":"η-Factor 1.0159"},{"value":"1C","value_description":"η-Factor 1.0171"},{"value":"1D","value_description":"η-Factor 1.0185"},{"value":"1E","value_description":"η-Factor 1.0198"},{"value":"1F","value_description":"η-Factor 1.0211"},{"value":"20","value_description":"η-Factor 1.0225"},{"value":"21","value_description":"η-Factor 1.0238"},{"value":"22","value_description":"η-Factor 1.0251"},{"value":"23","value_description":"η-Factor 1.0263"},{"value":"24","value_description":"η-Factor 1.0277"},{"value":"25","value_description":"η-Factor 1.0290"},{"value":"26","value_description":"η-Factor 1.0302"},{"value":"27","value_description":"η-Factor 1.0316"},{"value":"28","value_description":"η-Factor 1.0328"},{"value":"29","value_description":"η-Factor 1.0341"},{"value":"2A","value_description":"η-Factor 1.0354"},{"value":"2B","value_description":"η-Factor 1.0367"},{"value":"2C","value_description":"η-Factor 1.0379"},{"value":"2D","value_description":"η-Factor 1.0393"},{"value":"2E","value_description":"η-Factor 1.0405"},{"value":"2F","value_description":"η-Factor 1.0419"},{"value":"30","value_description":"η-Factor 1.0431"},{"value":"31","value_description":"η-Factor 1.0445"},{"value":"32","value_description":"η-Factor 1.0456"},{"value":"33","value_description":"η-Factor 1.0470"},{"value":"34","value_description":"η-Factor 1.0482"},{"value":"35","value_description":"η-Factor 1.0496"},{"value":"36","value_description":"η-Factor 1.0508"},{"value":"37","value_description":"η-Factor 1.0522"}],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | η-Factor_Ch1 | η-Factor_Ch1 |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Remote channel 1 diode ideality-factor correction register."}] | [{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Remote channel 1 diode ideality-factor correction register."}] |
| `register_description` | 0.0564 | 1.0 | Remote-channel-1 ideality-factor lookup; reset 12h = η 1.004. | Configures the remote channel 1 diode ideality factor according to Table 8-30. The device is calibrated for 1.004, corresponding to the reset setting 12h. Select the lookup setting nearest the target diode ideality factor; the design example uses 15h for approximately 1.008. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"η-Factor_Ch1","physical_address":{"hex":"0x27","decimal":"39","bank":"","page":"","description":"Remote channel 1 diode ideality-factor correction register."},"description":"Remote channel 1 ideality-factor setting.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"η-Factor_Ch1[7:0]","field_description":"Diode ideality-factor setting for remote channel 1; values are defined by Table 8-30.","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"8","value_description":"η-Factor 0.9911"},{"value":"9","value_description":"η-Factor 0.9923"},{"value":"A","value_description":"η-Factor 0.9936"},{"value":"B","value_description":"η-Factor 0.9949"},{"value":"C","value_description":"η-Factor 0.9962"},{"value":"D","value_description":"η-Factor 0.9975"},{"value":"E","value_description":"η-Factor 0.9987"},{"value":"F","value_description":"η-Factor 1.0001"},{"value":"10","value_description":"η-Factor 1.0013"},{"value":"11","value_description":"η-Factor 1.0026"},{"value":"12","value_description":"η-Factor 1.004"},{"value":"13","value_description":"η-Factor 1.0053"},{"value":"14","value_description":"η-Factor 1.0066"},{"value":"15","value_description":"η-Factor 1.0079"},{"value":"16","value_description":"η-Factor 1.0092"},{"value":"17","value_description":"η-Factor 1.0105"},{"value":"18","value_description":"η-Factor 1.0118"},{"value":"19","value_description":"η-Factor 1.0131"},{"value":"1A","value_description":"η-Factor 1.0144"},{"value":"1B","value_description":"η-Factor 1.0159"},{"value":"1C","value_description":"η-Factor 1.0171"},{"value":"1D","value_description":"η-Factor 1.0185"},{"value":"1E","value_description":"η-Factor 1.0198"},{"value":"1F","value_description":"η-Factor 1.0211"},{"value":"20","value_description":"η-Factor 1.0225"},{"value":"21","value_description":"η-Factor 1.0238"},{"value":"22","value_description":"η-Factor 1.0251"},{"value":"23","value_description":"η-Factor 1.0263"},{"value":"24","value_description":"η-Factor 1.0277"},{"value":"25","value_description":"η-Factor 1.0290"},{"value":"26","value_description":"η-Factor 1.0302"},{"value":"27","value_description":"η-Factor 1.0316"},{"value":"28","value_description":"η-Factor 1.0328"},{"value":"29","value_description":"η-Factor 1.0341"},{"value":"2A","value_description":"η-Factor 1.0354"},{"value":"2B","value_description":"η-Factor 1.0367"},{"value":"2C","value_description":"η-Factor 1.0379"},{"value":"2D","value_description":"η-Factor 1.0393"},{"value":"2E","value_description":"η-Factor 1.0405"},{"value":"2F","value_description":"η-Factor 1.0419"},{"value":"30","value_description":"η-Factor 1.0431"},{"value":"31","value_description":"η-Factor 1.0445"},{"value":"32","value_description":"η-Factor 1.0456"},{"value":"33","value_description":"η-Factor 1.0470"},{"value":"34","value_description":"η-Factor 1.0482"},{"value":"35","value_description":"η-Factor 1.0496"},{"value":"36","value_description":"η-Factor 1.0508"},{"value":"37","value_description":"η-Factor 1.0522"}],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.0 | 12h | 12h |
| `default_value_description` | 0.0334 | 1.0 | Reset value; corresponds to ideality factor 1.004. | Reset value; corresponds to ideality factor 1.004. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## Extracted logical register 23: `η-Factor_Ch2`

v1 location: `registers[22]`; datasheet association: D1 §8.29, p.44, Table 8-32; lookup Table 8-30 p.43.

Associated physical address entries: 0x28 (40).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `η-Factor_Ch2` at `0x28` (40)

Location: `registers[22].field_parts[0]`; source: D1 §8.29, p.44, Table 8-32; lookup Table 8-30 p.43.

**Truth bit field 1: `η-Factor_Ch2[7:0]` bits 0:7**

Location: `registers[22].field_parts[0].bit_field[0]`; D1 source: D1 §8.29, p.44, Table 8-32; lookup Table 8-30 p.43.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | η-Factor_Ch2[7:0] | η-Factor_Ch2[7:0] |
| `field_description` | 0.0586 | 1.0 | Diode ideality-factor setting for remote channel 2; values are defined by Table 8-30. | Diode ideality-factor setting for remote channel 2; values are defined by Table 8-30. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | same 48-entry lookup list as D1 Table 8-30: [{"value":"8","value_description":"η-Factor 0.9911"},{"value":"9","value_description":"η-Factor 0.9923"},{"value":"A","value_description":"η-Factor 0.9936"},{"value":"B","value_description":"η-Factor 0.9949"},{"value":"C","value_description":"η-Factor 0.9962"},{"value":"D","value_description":"η-Factor 0.9975"},{"value":"E","value_description":"η-Factor 0.9987"},{"value":"F","value_description":"η-Factor 1.0001"},{"value":"10","value_description":"η-Factor 1.0013"},{"value":"11","value_description":"η-Factor 1.0026"},{"value":"12","value_description":"η-Factor 1.004"},{"value":"13","value_description":"η-Factor 1.0053"},{"value":"14","value_description":"η-Factor 1.0066"},{"value":"15","value_description":"η-Factor 1.0079"},{"value":"16","value_description":"η-Factor 1.0092"},{"value":"17","value_description":"η-Factor 1.0105"},{"value":"18","value_description":"η-Factor 1.0118"},{"value":"19","value_description":"η-Factor 1.0131"},{"value":"1A","value_description":"η-Factor 1.0144"},{"value":"1B","value_description":"η-Factor 1.0159"},{"value":"1C","value_description":"η-Factor 1.0171"},{"value":"1D","value_description":"η-Factor 1.0185"},{"value":"1E","value_description":"η-Factor 1.0198"},{"value":"1F","value_description":"η-Factor 1.0211"},{"value":"20","value_description":"η-Factor 1.0225"},{"value":"21","value_description":"η-Factor 1.0238"},{"value":"22","value_description":"η-Factor 1.0251"},{"value":"23","value_description":"η-Factor 1.0263"},{"value":"24","value_description":"η-Factor 1.0277"},{"value":"25","value_description":"η-Factor 1.0290"},{"value":"26","value_description":"η-Factor 1.0302"},{"value":"27","value_description":"η-Factor 1.0316"},{"value":"28","value_description":"η-Factor 1.0328"},{"value":"29","value_description":"η-Factor 1.0341"},{"value":"2A","value_description":"η-Factor 1.0354"},{"value":"2B","value_description":"η-Factor 1.0367"},{"value":"2C","value_description":"η-Factor 1.0379"},{"value":"2D","value_description":"η-Factor 1.0393"},{"value":"2E","value_description":"η-Factor 1.0405"},{"value":"2F","value_description":"η-Factor 1.0419"},{"value":"30","value_description":"η-Factor 1.0431"},{"value":"31","value_description":"η-Factor 1.0445"},{"value":"32","value_description":"η-Factor 1.0456"},{"value":"33","value_description":"η-Factor 1.0470"},{"value":"34","value_description":"η-Factor 1.0482"},{"value":"35","value_description":"η-Factor 1.0496"},{"value":"36","value_description":"η-Factor 1.0508"},{"value":"37","value_description":"η-Factor 1.0522"}] | [{"value":"8","value_description":"η-Factor 0.9911"},{"value":"9","value_description":"η-Factor 0.9923"},{"value":"A","value_description":"η-Factor 0.9936"},{"value":"B","value_description":"η-Factor 0.9949"},{"value":"C","value_description":"η-Factor 0.9962"},{"value":"D","value_description":"η-Factor 0.9975"},{"value":"E","value_description":"η-Factor 0.9987"},{"value":"F","value_description":"η-Factor 1.0001"},{"value":"10","value_description":"η-Factor 1.0013"},{"value":"11","value_description":"η-Factor 1.0026"},{"value":"12","value_description":"η-Factor 1.004"},{"value":"13","value_description":"η-Factor 1.0053"},{"value":"14","value_description":"η-Factor 1.0066"},{"value":"15","value_description":"η-Factor 1.0079"},{"value":"16","value_description":"η-Factor 1.0092"},{"value":"17","value_description":"η-Factor 1.0105"},{"value":"18","value_description":"η-Factor 1.0118"},{"value":"19","value_description":"η-Factor 1.0131"},{"value":"1A","value_description":"η-Factor 1.0144"},{"value":"1B","value_description":"η-Factor 1.0159"},{"value":"1C","value_description":"η-Factor 1.0171"},{"value":"1D","value_description":"η-Factor 1.0185"},{"value":"1E","value_description":"η-Factor 1.0198"},{"value":"1F","value_description":"η-Factor 1.0211"},{"value":"20","value_description":"η-Factor 1.0225"},{"value":"21","value_description":"η-Factor 1.0238"},{"value":"22","value_description":"η-Factor 1.0251"},{"value":"23","value_description":"η-Factor 1.0263"},{"value":"24","value_description":"η-Factor 1.0277"},{"value":"25","value_description":"η-Factor 1.0290"},{"value":"26","value_description":"η-Factor 1.0302"},{"value":"27","value_description":"η-Factor 1.0316"},{"value":"28","value_description":"η-Factor 1.0328"},{"value":"29","value_description":"η-Factor 1.0341"},{"value":"2A","value_description":"η-Factor 1.0354"},{"value":"2B","value_description":"η-Factor 1.0367"},{"value":"2C","value_description":"η-Factor 1.0379"},{"value":"2D","value_description":"η-Factor 1.0393"},{"value":"2E","value_description":"η-Factor 1.0405"},{"value":"2F","value_description":"η-Factor 1.0419"},{"value":"30","value_description":"η-Factor 1.0431"},{"value":"31","value_description":"η-Factor 1.0445"},{"value":"32","value_description":"η-Factor 1.0456"},{"value":"33","value_description":"η-Factor 1.0470"},{"value":"34","value_description":"η-Factor 1.0482"},{"value":"35","value_description":"η-Factor 1.0496"},{"value":"36","value_description":"η-Factor 1.0508"},{"value":"37","value_description":"η-Factor 1.0522"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | η-Factor_Ch2 | η-Factor_Ch2 |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Remote channel 2 diode ideality-factor correction register."} | {"hex":"0x28","decimal":"40","bank":"","page":"","description":"Remote channel 2 diode ideality-factor correction register."} |
| `description` | 0.0693 | 1.0 | Remote-channel-2 ideality-factor lookup; reset 12h = η 1.004. | Remote channel 2 ideality-factor setting. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"η-Factor_Ch2[7:0]","field_description":"Diode ideality-factor setting for remote channel 2; values are defined by Table 8-30.","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"8","value_description":"η-Factor 0.9911"},{"value":"9","value_description":"η-Factor 0.9923"},{"value":"A","value_description":"η-Factor 0.9936"},{"value":"B","value_description":"η-Factor 0.9949"},{"value":"C","value_description":"η-Factor 0.9962"},{"value":"D","value_description":"η-Factor 0.9975"},{"value":"E","value_description":"η-Factor 0.9987"},{"value":"F","value_description":"η-Factor 1.0001"},{"value":"10","value_description":"η-Factor 1.0013"},{"value":"11","value_description":"η-Factor 1.0026"},{"value":"12","value_description":"η-Factor 1.004"},{"value":"13","value_description":"η-Factor 1.0053"},{"value":"14","value_description":"η-Factor 1.0066"},{"value":"15","value_description":"η-Factor 1.0079"},{"value":"16","value_description":"η-Factor 1.0092"},{"value":"17","value_description":"η-Factor 1.0105"},{"value":"18","value_description":"η-Factor 1.0118"},{"value":"19","value_description":"η-Factor 1.0131"},{"value":"1A","value_description":"η-Factor 1.0144"},{"value":"1B","value_description":"η-Factor 1.0159"},{"value":"1C","value_description":"η-Factor 1.0171"},{"value":"1D","value_description":"η-Factor 1.0185"},{"value":"1E","value_description":"η-Factor 1.0198"},{"value":"1F","value_description":"η-Factor 1.0211"},{"value":"20","value_description":"η-Factor 1.0225"},{"value":"21","value_description":"η-Factor 1.0238"},{"value":"22","value_description":"η-Factor 1.0251"},{"value":"23","value_description":"η-Factor 1.0263"},{"value":"24","value_description":"η-Factor 1.0277"},{"value":"25","value_description":"η-Factor 1.0290"},{"value":"26","value_description":"η-Factor 1.0302"},{"value":"27","value_description":"η-Factor 1.0316"},{"value":"28","value_description":"η-Factor 1.0328"},{"value":"29","value_description":"η-Factor 1.0341"},{"value":"2A","value_description":"η-Factor 1.0354"},{"value":"2B","value_description":"η-Factor 1.0367"},{"value":"2C","value_description":"η-Factor 1.0379"},{"value":"2D","value_description":"η-Factor 1.0393"},{"value":"2E","value_description":"η-Factor 1.0405"},{"value":"2F","value_description":"η-Factor 1.0419"},{"value":"30","value_description":"η-Factor 1.0431"},{"value":"31","value_description":"η-Factor 1.0445"},{"value":"32","value_description":"η-Factor 1.0456"},{"value":"33","value_description":"η-Factor 1.0470"},{"value":"34","value_description":"η-Factor 1.0482"},{"value":"35","value_description":"η-Factor 1.0496"},{"value":"36","value_description":"η-Factor 1.0508"},{"value":"37","value_description":"η-Factor 1.0522"}],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | η-Factor_Ch2 | η-Factor_Ch2 |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Remote channel 2 diode ideality-factor correction register."}] | [{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Remote channel 2 diode ideality-factor correction register."}] |
| `register_description` | 0.0564 | 1.0 | Remote-channel-2 ideality-factor lookup; reset 12h = η 1.004. | Configures the remote channel 2 diode ideality factor according to the η-Factor Lookup Table, Table 8-30. The reset setting 12h corresponds to an ideality factor of 1.004. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"η-Factor_Ch2","physical_address":{"hex":"0x28","decimal":"40","bank":"","page":"","description":"Remote channel 2 diode ideality-factor correction register."},"description":"Remote channel 2 ideality-factor setting.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"η-Factor_Ch2[7:0]","field_description":"Diode ideality-factor setting for remote channel 2; values are defined by Table 8-30.","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"8","value_description":"η-Factor 0.9911"},{"value":"9","value_description":"η-Factor 0.9923"},{"value":"A","value_description":"η-Factor 0.9936"},{"value":"B","value_description":"η-Factor 0.9949"},{"value":"C","value_description":"η-Factor 0.9962"},{"value":"D","value_description":"η-Factor 0.9975"},{"value":"E","value_description":"η-Factor 0.9987"},{"value":"F","value_description":"η-Factor 1.0001"},{"value":"10","value_description":"η-Factor 1.0013"},{"value":"11","value_description":"η-Factor 1.0026"},{"value":"12","value_description":"η-Factor 1.004"},{"value":"13","value_description":"η-Factor 1.0053"},{"value":"14","value_description":"η-Factor 1.0066"},{"value":"15","value_description":"η-Factor 1.0079"},{"value":"16","value_description":"η-Factor 1.0092"},{"value":"17","value_description":"η-Factor 1.0105"},{"value":"18","value_description":"η-Factor 1.0118"},{"value":"19","value_description":"η-Factor 1.0131"},{"value":"1A","value_description":"η-Factor 1.0144"},{"value":"1B","value_description":"η-Factor 1.0159"},{"value":"1C","value_description":"η-Factor 1.0171"},{"value":"1D","value_description":"η-Factor 1.0185"},{"value":"1E","value_description":"η-Factor 1.0198"},{"value":"1F","value_description":"η-Factor 1.0211"},{"value":"20","value_description":"η-Factor 1.0225"},{"value":"21","value_description":"η-Factor 1.0238"},{"value":"22","value_description":"η-Factor 1.0251"},{"value":"23","value_description":"η-Factor 1.0263"},{"value":"24","value_description":"η-Factor 1.0277"},{"value":"25","value_description":"η-Factor 1.0290"},{"value":"26","value_description":"η-Factor 1.0302"},{"value":"27","value_description":"η-Factor 1.0316"},{"value":"28","value_description":"η-Factor 1.0328"},{"value":"29","value_description":"η-Factor 1.0341"},{"value":"2A","value_description":"η-Factor 1.0354"},{"value":"2B","value_description":"η-Factor 1.0367"},{"value":"2C","value_description":"η-Factor 1.0379"},{"value":"2D","value_description":"η-Factor 1.0393"},{"value":"2E","value_description":"η-Factor 1.0405"},{"value":"2F","value_description":"η-Factor 1.0419"},{"value":"30","value_description":"η-Factor 1.0431"},{"value":"31","value_description":"η-Factor 1.0445"},{"value":"32","value_description":"η-Factor 1.0456"},{"value":"33","value_description":"η-Factor 1.0470"},{"value":"34","value_description":"η-Factor 1.0482"},{"value":"35","value_description":"η-Factor 1.0496"},{"value":"36","value_description":"η-Factor 1.0508"},{"value":"37","value_description":"η-Factor 1.0522"}],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.0 | 12h | 12h |
| `default_value_description` | 0.0334 | 1.0 | Reset value; corresponds to ideality factor 1.004. | Reset value; corresponds to ideality factor 1.004. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## Extracted logical register 24: `High_Limit_Status`

v1 location: `registers[23]`; datasheet association: D1 §8.30, p.45, Table 8-33; access code Tables 8-1/8-2 p.25-26.

Associated physical address entries: 0x35 (53).

Audit findings for this logical register: v1 uses `R` where D1 Table 8-1 defines `RC`; read-to-clear is omitted from the access code. 1 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `High_Limit_Status` at `0x35` (53)

Location: `registers[23].field_parts[0]`; source: D1 §8.30, p.45, Table 8-33; access code Tables 8-1/8-2 p.25-26.

**Truth bit field 1: `Reserved` bits 3:7**

Location: `registers[23].field_parts[0].bit_field[0]`; D1 source: D1 §8.30, p.45, Table 8-33; access code Tables 8-1/8-2 p.25-26. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Truth bit field 2: `Ch2_High` bits 2:2**

Location: `registers[23].field_parts[0].bit_field[1]`; D1 source: D1 §8.30, p.45, Table 8-33; access code Tables 8-1/8-2 p.25-26. D1 type is `RC`; v1 has R.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Ch2_High | Ch2_High |
| `field_description` | 0.0586 | 1.0 | Set when remote channel 2 rises above its configured high limit; read-to-clear in Interrupt mode. | Set when remote channel 2 rises above its configured high limit; read-to-clear in Interrupt mode. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.5 | RC | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.5) / 0.9999 = 0.970847.

**Truth bit field 3: `Ch1_High` bits 1:1**

Location: `registers[23].field_parts[0].bit_field[2]`; D1 source: D1 §8.30, p.45, Table 8-33; access code Tables 8-1/8-2 p.25-26. D1 type is `RC`; v1 has R.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Ch1_High | Ch1_High |
| `field_description` | 0.0586 | 1.0 | Set when remote channel 1 rises above its configured high limit; read-to-clear in Interrupt mode. | Set when remote channel 1 rises above its configured high limit; read-to-clear in Interrupt mode. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.5 | RC | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.5) / 0.9999 = 0.970847.

**Truth bit field 4: `Local_High` bits 0:0**

Location: `registers[23].field_parts[0].bit_field[3]`; D1 source: D1 §8.30, p.45, Table 8-33; access code Tables 8-1/8-2 p.25-26. D1 type is `RC`; v1 has R.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Local_High | Local_High |
| `field_description` | 0.0586 | 1.0 | Set when the local channel rises above its configured high limit; read-to-clear in Interrupt mode. | Set when the local channel rises above its configured high limit; read-to-clear in Interrupt mode. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.5 | RC | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.5) / 0.9999 = 0.970847.

**Field-part aggregation**

`bit_field` correctness = mean(0.941694, 0.970847, 0.970847, 0.970847) = **0.963559**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | High_Limit_Status | High_Limit_Status |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x35","decimal":"53","bank":"","page":"","description":"Per-channel high-limit status register."} | {"hex":"0x35","decimal":"53","bank":"","page":"","description":"Per-channel high-limit status register."} |
| `description` | 0.0693 | 1.0 | Read-to-clear (RC) high-limit status flags; interrupt read clears, comparator clears below high limit minus hysteresis. | Read-to-clear high-limit flags in Interrupt mode. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.5 | RC | R |
| `bit_field` | 0.3129 | 0.963559 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":3,"bit_end":7,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Ch2_High","field_description":"Set when remote channel 2 rises above its configured high limit; read-to-clear in Interrupt mode.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Ch1_High","field_description":"Set when remote channel 1 rises above its configured high limit; read-to-clear in Interrupt mode.","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Local_High","field_description":"Set when the local channel rises above its configured high limit; read-to-clear in Interrupt mode.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 0.5 + 0.3129 x 0.963559) = 0.958348.

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.958348) = **0.958348**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | High_Limit_Status | High_Limit_Status |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x35","decimal":"53","bank":"","page":"","description":"Per-channel high-limit status register."}] | [{"hex":"0x35","decimal":"53","bank":"","page":"","description":"Per-channel high-limit status register."}] |
| `register_description` | 0.0564 | 1.0 | Read-to-clear (RC) high-limit status flags; interrupt read clears, comparator clears below high limit minus hysteresis. | Contains per-channel flags set when configured high limits are exceeded. Any set flag also sets Status.THigh and asserts ALERT low. In Interrupt mode, reading this register clears all flags and Status.THigh; qualifying conditions can set them again on the next conversion. In Comparator mode, flags clear when temperature falls below the high limit minus Hysteresis. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 0.5 | RC | R |
| `field_parts` | 0.2987 | 0.958348 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"High_Limit_Status","physical_address":{"hex":"0x35","decimal":"53","bank":"","page":"","description":"Per-channel high-limit status register."},"description":"Read-to-clear high-limit flags in Interrupt mode.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":3,"bit_end":7,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Ch2_High","field_description":"Set when remote channel 2 rises above its configured high limit; read-to-clear in Interrupt mode.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Ch1_High","field_description":"Set when remote channel 1 rises above its configured high limit; read-to-clear in Interrupt mode.","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Local_High","field_description":"Set when the local channel rises above its configured high limit; read-to-clear in Interrupt mode.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | Reset value. | Reset value. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 0.5 + 0.2987 x 0.958348 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.958063.

## Extracted logical register 25: `Low_Limit_Status`

v1 location: `registers[24]`; datasheet association: D1 §8.31, p.45, Table 8-34; access code Tables 8-1/8-2 p.25-26.

Associated physical address entries: 0x36 (54).

Audit findings for this logical register: v1 uses `R` where D1 Table 8-1 defines `RC`; read-to-clear is omitted from the access code. 1 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Low_Limit_Status` at `0x36` (54)

Location: `registers[24].field_parts[0]`; source: D1 §8.31, p.45, Table 8-34; access code Tables 8-1/8-2 p.25-26.

**Truth bit field 1: `Reserved` bits 3:7**

Location: `registers[24].field_parts[0].bit_field[0]`; D1 source: D1 §8.31, p.45, Table 8-34; access code Tables 8-1/8-2 p.25-26. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Truth bit field 2: `Ch2_Low` bits 2:2**

Location: `registers[24].field_parts[0].bit_field[1]`; D1 source: D1 §8.31, p.45, Table 8-34; access code Tables 8-1/8-2 p.25-26. D1 type is `RC`; v1 has R.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Ch2_Low | Ch2_Low |
| `field_description` | 0.0586 | 1.0 | Set when remote channel 2 drops below its configured low limit; read-to-clear in Interrupt mode. | Set when remote channel 2 drops below its configured low limit; read-to-clear in Interrupt mode. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.5 | RC | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.5) / 0.9999 = 0.970847.

**Truth bit field 3: `Ch1_Low` bits 1:1**

Location: `registers[24].field_parts[0].bit_field[2]`; D1 source: D1 §8.31, p.45, Table 8-34; access code Tables 8-1/8-2 p.25-26. D1 type is `RC`; v1 has R.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Ch1_Low | Ch1_Low |
| `field_description` | 0.0586 | 1.0 | Set when remote channel 1 drops below its configured low limit; read-to-clear in Interrupt mode. | Set when remote channel 1 drops below its configured low limit; read-to-clear in Interrupt mode. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.5 | RC | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.5) / 0.9999 = 0.970847.

**Truth bit field 4: `Local_Low` bits 0:0**

Location: `registers[24].field_parts[0].bit_field[3]`; D1 source: D1 §8.31, p.45, Table 8-34; access code Tables 8-1/8-2 p.25-26. D1 type is `RC`; v1 has R.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Local_Low | Local_Low |
| `field_description` | 0.0586 | 1.0 | Set when the local channel drops below its configured low limit; read-to-clear in Interrupt mode. | Set when the local channel drops below its configured low limit; read-to-clear in Interrupt mode. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 0.5 | RC | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.5) / 0.9999 = 0.970847.

**Field-part aggregation**

`bit_field` correctness = mean(0.941694, 0.970847, 0.970847, 0.970847) = **0.963559**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Low_Limit_Status | Low_Limit_Status |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x36","decimal":"54","bank":"","page":"","description":"Per-channel low-limit status register."} | {"hex":"0x36","decimal":"54","bank":"","page":"","description":"Per-channel low-limit status register."} |
| `description` | 0.0693 | 1.0 | Read-to-clear (RC) low-limit status flags; interrupt read clears, comparator clears above low limit plus hysteresis. | Read-to-clear low-limit flags in Interrupt mode. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 0.5 | RC | R |
| `bit_field` | 0.3129 | 0.963559 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":3,"bit_end":7,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Ch2_Low","field_description":"Set when remote channel 2 drops below its configured low limit; read-to-clear in Interrupt mode.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Ch1_Low","field_description":"Set when remote channel 1 drops below its configured low limit; read-to-clear in Interrupt mode.","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Local_Low","field_description":"Set when the local channel drops below its configured low limit; read-to-clear in Interrupt mode.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 0.5 + 0.3129 x 0.963559) = 0.958348.

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.958348) = **0.958348**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Low_Limit_Status | Low_Limit_Status |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":"Per-channel low-limit status register."}] | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":"Per-channel low-limit status register."}] |
| `register_description` | 0.0564 | 1.0 | Read-to-clear (RC) low-limit status flags; interrupt read clears, comparator clears above low limit plus hysteresis. | Contains per-channel flags set when configured low limits are crossed. Any set flag also sets Status.TLow and asserts ALERT low. In Interrupt mode, reading this register clears all flags and Status.TLow; qualifying conditions can set them again on the next conversion. In Comparator mode, flags clear when temperature rises above the low limit plus Hysteresis. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 0.5 | RC | R |
| `field_parts` | 0.2987 | 0.958348 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Low_Limit_Status","physical_address":{"hex":"0x36","decimal":"54","bank":"","page":"","description":"Per-channel low-limit status register."},"description":"Read-to-clear low-limit flags in Interrupt mode.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":3,"bit_end":7,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Ch2_Low","field_description":"Set when remote channel 2 drops below its configured low limit; read-to-clear in Interrupt mode.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Ch1_Low","field_description":"Set when remote channel 1 drops below its configured low limit; read-to-clear in Interrupt mode.","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Local_Low","field_description":"Set when the local channel drops below its configured low limit; read-to-clear in Interrupt mode.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | Reset value. | Reset value. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 0.5 + 0.2987 x 0.958348 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.958063.

## Extracted logical register 26: `TCRIT_Limit_Status`

v1 location: `registers[25]`; datasheet association: D1 §8.32, p.46, Table 8-35.

Associated physical address entries: 0x37 (55).

Audit findings for this logical register: 1 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `TCRIT_Limit_Status` at `0x37` (55)

Location: `registers[25].field_parts[0]`; source: D1 §8.32, p.46, Table 8-35.

**Truth bit field 1: `Reserved` bits 3:7**

Location: `registers[25].field_parts[0].bit_field[0]`; D1 source: D1 §8.32, p.46, Table 8-35. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Truth bit field 2: `Ch2_TCRIT` bits 2:2**

Location: `registers[25].field_parts[0].bit_field[1]`; D1 source: D1 §8.32, p.46, Table 8-35.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Ch2_TCRIT | Ch2_TCRIT |
| `field_description` | 0.0586 | 1.0 | Set when remote channel 2 exceeds its configured TCRIT limit. | Set when remote channel 2 exceeds its configured TCRIT limit. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 3: `Ch1_TCRIT` bits 1:1**

Location: `registers[25].field_parts[0].bit_field[2]`; D1 source: D1 §8.32, p.46, Table 8-35.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Ch1_TCRIT | Ch1_TCRIT |
| `field_description` | 0.0586 | 1.0 | Set when remote channel 1 exceeds its configured TCRIT limit. | Set when remote channel 1 exceeds its configured TCRIT limit. |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 4: `Local_TCRIT` bits 0:0**

Location: `registers[25].field_parts[0].bit_field[3]`; D1 source: D1 §8.32, p.46, Table 8-35.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Local_TCRIT | Local_TCRIT |
| `field_description` | 0.0586 | 1.0 | Set when the local channel exceeds its configured TCRIT limit. | Set when the local channel exceeds its configured TCRIT limit. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(0.941694, 1.000000, 1.000000, 1.000000) = **0.985424**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | TCRIT_Limit_Status | TCRIT_Limit_Status |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x37","decimal":"55","bank":"","page":"","description":"Per-channel T_CRIT status register."} | {"hex":"0x37","decimal":"55","bank":"","page":"","description":"Per-channel T_CRIT status register."} |
| `description` | 0.0693 | 1.0 | Read-only per-channel T_CRIT flags; automatically clear below T_CRIT minus hysteresis. | Automatically cleared T_CRIT status flags. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 0.985424 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":3,"bit_end":7,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Ch2_TCRIT","field_description":"Set when remote channel 2 exceeds its configured TCRIT limit.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Ch1_TCRIT","field_description":"Set when remote channel 1 exceeds its configured TCRIT limit.","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Local_TCRIT","field_description":"Set when the local channel exceeds its configured TCRIT limit.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.985424) = 0.995439.

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.995439) = **0.995439**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | TCRIT_Limit_Status | TCRIT_Limit_Status |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":"Per-channel T_CRIT status register."}] | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":"Per-channel T_CRIT status register."}] |
| `register_description` | 0.0564 | 1.0 | Read-only per-channel T_CRIT flags; automatically clear below T_CRIT minus hysteresis. | Contains per-channel flags set when configured T_CRIT limits are exceeded. Any set flag also sets the TCRIT bit in Status and asserts the TCRIT pin low. Reading does not clear these flags; each clears when temperature falls below its T_CRIT limit minus hysteresis, and Status.TCrit clears when all channel flags clear. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 0.995439 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"TCRIT_Limit_Status","physical_address":{"hex":"0x37","decimal":"55","bank":"","page":"","description":"Per-channel T_CRIT status register."},"description":"Automatically cleared T_CRIT status flags.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":3,"bit_end":7,"bit_width":5,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Ch2_TCRIT","field_description":"Set when remote channel 2 exceeds its configured TCRIT limit.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Ch1_TCRIT","field_description":"Set when remote channel 1 exceeds its configured TCRIT limit.","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Local_TCRIT","field_description":"Set when the local channel exceeds its configured TCRIT limit.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | Reset value. | Reset value. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 0.995439 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.998638.

## Extracted logical register 27: `Filter_Control`

v1 location: `registers[26]`; datasheet association: D1 §8.33, p.46, Table 8-36.

Associated physical address entries: 0x40 (64).

Audit findings for this logical register: 1 reserved bit field(s) leave `type_write_read` empty although D1 gives `R`.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Filter_Control` at `0x40` (64)

Location: `registers[26].field_parts[0]`; source: D1 §8.33, p.46, Table 8-36.

**Truth bit field 1: `Reserved` bits 2:7**

Location: `registers[26].field_parts[0].bit_field[0]`; D1 source: D1 §8.33, p.46, Table 8-36. D1 type is `R`; v1 has ``.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Reserved | Reserved |
| `field_description` | 0.0586 | 1.0 | Reserved. | Reserved. |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 0.0 | R | `` |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 0.0) / 0.9999 = 0.941694.

**Truth bit field 2: `Filter_Control[1:0]` bits 0:1**

Location: `registers[26].field_parts[0].bit_field[1]`; D1 source: D1 §8.33, p.46, Table 8-36.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Filter_Control[1:0] | Filter_Control[1:0] |
| `field_description` | 0.0586 | 1.0 | Selects the moving-average filter level for remote-temperature results. | Selects the moving-average filter level for remote-temperature results. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | same value list as the cited D1 field table: [{"value":"0h","value_description":"0 moving average (default)."},{"value":"1h","value_description":"4 moving average (level 1)."},{"value":"2h","value_description":"4 moving average (level 1)."},{"value":"3h","value_description":"8 moving average (level 2)."}] | [{"value":"0h","value_description":"0 moving average (default)."},{"value":"1h","value_description":"4 moving average (level 1)."},{"value":"2h","value_description":"4 moving average (level 1)."},{"value":"3h","value_description":"8 moving average (level 2)."}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | RW | RW |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(0.941694, 1.000000) = **0.970847**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Filter_Control | Filter_Control |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x40","decimal":"64","bank":"","page":"","description":"Remote-temperature digital filter control register."} | {"hex":"0x40","decimal":"64","bank":"","page":"","description":"Remote-temperature digital filter control register."} |
| `description` | 0.0693 | 1.0 | Two-bit moving-average filter setting for remote results. | Remote-temperature moving-average filter setting. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | RW | RW |
| `bit_field` | 0.3129 | 0.970847 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Filter_Control[1:0]","field_description":"Selects the moving-average filter level for remote-temperature results.","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0h","value_description":"0 moving average (default)."},{"value":"1h","value_description":"4 moving average (level 1)."},{"value":"2h","value_description":"4 moving average (level 1)."},{"value":"3h","value_description":"8 moving average (level 2)."}],"is_reserved":false,"type_write_read":"RW"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 0.970847) = 0.990878.

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.990878) = **0.990878**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Filter_Control | Filter_Control |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x40","decimal":"64","bank":"","page":"","description":"Remote-temperature digital filter control register."}] | [{"hex":"0x40","decimal":"64","bank":"","page":"","description":"Remote-temperature digital filter control register."}] |
| `register_description` | 0.0564 | 1.0 | Two-bit moving-average filter setting for remote results. | Controls the moving-average filter level applied to remote-temperature conversion results. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | RW | RW |
| `field_parts` | 0.2987 | 0.990878 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Filter_Control","physical_address":{"hex":"0x40","decimal":"64","bank":"","page":"","description":"Remote-temperature digital filter control register."},"description":"Remote-temperature moving-average filter setting.","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Reserved","field_description":"Reserved.","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Filter_Control[1:0]","field_description":"Selects the moving-average filter level for remote-temperature results.","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0h","value_description":"0 moving average (default)."},{"value":"1h","value_description":"4 moving average (level 1)."},{"value":"2h","value_description":"4 moving average (level 1)."},{"value":"3h","value_description":"8 moving average (level 2)."}],"is_reserved":false,"type_write_read":"RW"}]}] |
| `default_value` | 0.0667 | 1.0 | 00h | 00h |
| `default_value_description` | 0.0334 | 1.0 | Reset value; selects 0 moving average. | Reset value; selects 0 moving average. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 0.990878 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 0.997276.

## Extracted logical register 28: `Chip_ID`

v1 location: `registers[27]`; datasheet association: D1 §8.34, p.47, Table 8-37.

Associated physical address entries: 0xFD (253).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Chip_ID` at `0xFD` (253)

Location: `registers[27].field_parts[0]`; source: D1 §8.34, p.47, Table 8-37.

**Truth bit field 1: `Chip_ID[7:0]` bits 0:7**

Location: `registers[27].field_parts[0].bit_field[0]`; D1 source: D1 §8.34, p.47, Table 8-37.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Chip_ID[7:0] | Chip_ID[7:0] |
| `field_description` | 0.0586 | 1.0 | Chip ID of the device. | Chip ID of the device. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Chip_ID | Chip_ID |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0xFD","decimal":"253","bank":"","page":"","description":"Chip identification register."} | {"hex":"0xFD","decimal":"253","bank":"","page":"","description":"Chip identification register."} |
| `description` | 0.0693 | 1.0 | 8-bit chip identification value; reset 21h. | 8-bit chip identifier. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Chip_ID[7:0]","field_description":"Chip ID of the device.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Chip_ID | Chip_ID |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0xFD","decimal":"253","bank":"","page":"","description":"Chip identification register."}] | [{"hex":"0xFD","decimal":"253","bank":"","page":"","description":"Chip identification register."}] |
| `register_description` | 0.0564 | 1.0 | 8-bit chip identification value; reset 21h. | Contains the chip ID used to identify the device. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Chip_ID","physical_address":{"hex":"0xFD","decimal":"253","bank":"","page":"","description":"Chip identification register."},"description":"8-bit chip identifier.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Chip_ID[7:0]","field_description":"Chip ID of the device.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.0 | 21h | 21h |
| `default_value_description` | 0.0334 | 1.0 | Reset value. | Reset value. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## Extracted logical register 29: `Vendor_ID`

v1 location: `registers[28]`; datasheet association: D1 §8.35, p.47, Table 8-38.

Associated physical address entries: 0xFE (254).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Vendor_ID` at `0xFE` (254)

Location: `registers[28].field_parts[0]`; source: D1 §8.35, p.47, Table 8-38.

**Truth bit field 1: `Vendor_ID[7:0]` bits 0:7**

Location: `registers[28].field_parts[0].bit_field[0]`; D1 source: D1 §8.35, p.47, Table 8-38.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Vendor_ID[7:0] | Vendor_ID[7:0] |
| `field_description` | 0.0586 | 1.0 | Vendor ID of the device. | Vendor ID of the device. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Vendor_ID | Vendor_ID |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0xFE","decimal":"254","bank":"","page":"","description":"Vendor identification register."} | {"hex":"0xFE","decimal":"254","bank":"","page":"","description":"Vendor identification register."} |
| `description` | 0.0693 | 1.0 | 8-bit vendor identification value; reset 60h. | 8-bit vendor identifier. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Vendor_ID[7:0]","field_description":"Vendor ID of the device.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Vendor_ID | Vendor_ID |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0xFE","decimal":"254","bank":"","page":"","description":"Vendor identification register."}] | [{"hex":"0xFE","decimal":"254","bank":"","page":"","description":"Vendor identification register."}] |
| `register_description` | 0.0564 | 1.0 | 8-bit vendor identification value; reset 60h. | Contains the vendor ID used to identify the device vendor. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Vendor_ID","physical_address":{"hex":"0xFE","decimal":"254","bank":"","page":"","description":"Vendor identification register."},"description":"8-bit vendor identifier.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Vendor_ID[7:0]","field_description":"Vendor ID of the device.","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.0 | 60h | 60h |
| `default_value_description` | 0.0334 | 1.0 | Reset value. | Reset value. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## Extracted logical register 30: `Device_Rev_ID`

v1 location: `registers[29]`; datasheet association: D1 §8.36, p.47, Table 8-39.

Associated physical address entries: 0xFF (255).

Audit finding: all scored facts for this logical register agree with D1; descriptive wording is a functionally correct paraphrase.

### Bottom layer: bit fields, then field parts

#### Field part 1: `Device_Rev_ID` at `0xFF` (255)

Location: `registers[29].field_parts[0]`; source: D1 §8.36, p.47, Table 8-39.

**Truth bit field 1: `Device_ID[3:0]` bits 4:7**

Location: `registers[29].field_parts[0].bit_field[0]`; D1 source: D1 §8.36, p.47, Table 8-39.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Device_ID[3:0] | Device_ID[3:0] |
| `field_description` | 0.0586 | 1.0 | Device ID of the device. | Device ID of the device. |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Truth bit field 2: `Rev_ID[3:0]` bits 0:3**

Location: `registers[29].field_parts[0].bit_field[1]`; D1 source: D1 §8.36, p.47, Table 8-39.

| Scored field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | Rev_ID[3:0] | Rev_ID[3:0] |
| `field_description` | 0.0586 | 1.0 | Revision ID of the device. | Revision ID of the device. |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 4 | 4 |
| `values` | 0.2097 | 1.0 | []; no discrete enumeration in the cited D1 field table. | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | R | R |

Q_BF = (0.0212 x 1.0 + 0.0586 x 1.0 + 0.2594 x 1.0 + 0.2594 x 1.0 + 0.0583 x 1.0 + 0.2097 x 1.0 + 0.0750 x 1.0 + 0.0583 x 1.0) / 0.9999 = 1.000000.

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000) = **1.000000**.

| Field-part field | Weight | C | Datasheet basis | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | Device_Rev_ID | Device_Rev_ID |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0xFF","decimal":"255","bank":"","page":"","description":"Device and revision identification register."} | {"hex":"0xFF","decimal":"255","bank":"","page":"","description":"Device and revision identification register."} |
| `description` | 0.0693 | 1.0 | Device ID in bits 7:4 and revision ID in bits 3:0; reset A0h. | Combined device and revision identifier. |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | R | R |
| `bit_field` | 0.3129 | 1.000000 | mean of all bit-field Q values listed below | [{"name_or_parameter":"Device_ID[3:0]","field_description":"Device ID of the device.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Rev_ID[3:0]","field_description":"Revision ID of the device.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}] |

Q_FP = (0.0280 x 1.0 + 0.4688 x 1.0 + 0.0693 x 1.0 + 0.0605 x 1.0 + 0.0605 x 1.0 + 0.3129 x 1.000000) = 1.000000.

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | Device_Rev_ID | Device_Rev_ID |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0xFF","decimal":"255","bank":"","page":"","description":"Device and revision identification register."}] | [{"hex":"0xFF","decimal":"255","bank":"","page":"","description":"Device and revision identification register."}] |
| `register_description` | 0.0564 | 1.0 | Device ID in bits 7:4 and revision ID in bits 3:0; reset A0h. | Contains the device ID in bits 7:4 and revision ID in bits 3:0 for device identification. |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | R | R |
| `field_parts` | 0.2987 | 1.000000 | mean of the D1 physical-address entries represented by this logical register | [{"register_name":"Device_Rev_ID","physical_address":{"hex":"0xFF","decimal":"255","bank":"","page":"","description":"Device and revision identification register."},"description":"Combined device and revision identifier.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Device_ID[3:0]","field_description":"Device ID of the device.","bit_start":4,"bit_end":7,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Rev_ID[3:0]","field_description":"Revision ID of the device.","bit_start":0,"bit_end":3,"bit_width":4,"values":[],"is_reserved":false,"type_write_read":"R"}]}] |
| `default_value` | 0.0667 | 1.0 | A0h | A0h |
| `default_value_description` | 0.0334 | 1.0 | Reset value: Device_ID = Ah and Rev_ID = 0h. | Reset value: Device_ID = Ah and Rev_ID = 0h. |

Q(L) = (0.0225 x 1.0 + 0.4044 x 1.0 + 0.0564 x 1.0 + 0.0590 x 1.0 + 0.0590 x 1.0 + 0.2987 x 1.000000 + 0.0667 x 1.0 + 0.0334 x 1.0) / 1.0001 = 1.000000.

## 3. Datasheet physical-register scores

For every D1 physical address entry, q_R = mean of the Q(L) values associated with that address. Each address in this candidate is associated with exactly one equivalent extracted logical register, so q_R = Q(L) for every present address.

| D1 physical address | Datasheet role | Associated extracted logical register | q_R |
|---|---|---|---:|
| 0x00 (0) | `Temp_Local` field part 1 | v1 `registers[0]` `Temp_Local` = 1.000000000 | 1.000000000 |
| 0x01 (1) | `Temp_Remote_Ch1` field part 1 | v1 `registers[1]` `Temp_Remote_Ch1` = 0.939643673 | 0.939643673 |
| 0x10 (16) | `Temp_Remote_Ch1` field part 2 | v1 `registers[1]` `Temp_Remote_Ch1` = 0.939643673 | 0.939643673 |
| 0x02 (2) | `Status` field part 1 | v1 `registers[2]` `Status` = 0.998443170 | 0.998443170 |
| 0x03 (3) | `Configuration` field part 1 | v1 `registers[3]` `Configuration` = 0.998637773 | 0.998637773 |
| 0x09 (9) | `Configuration` field part 2 | v1 `registers[3]` `Configuration` = 0.998637773 | 0.998637773 |
| 0x04 (4) | `Conv_Period` field part 1 | v1 `registers[4]` `Conv_Period` = 0.997275547 | 0.997275547 |
| 0x0A (10) | `Conv_Period` field part 2 | v1 `registers[4]` `Conv_Period` = 0.997275547 | 0.997275547 |
| 0x05 (5) | `THigh_Limit_Local` field part 1 | v1 `registers[5]` `THigh_Limit_Local` = 1.000000000 | 1.000000000 |
| 0x0B (11) | `THigh_Limit_Local` field part 2 | v1 `registers[5]` `THigh_Limit_Local` = 1.000000000 | 1.000000000 |
| 0x06 (6) | `TLow_Limit_Local` field part 1 | v1 `registers[6]` `TLow_Limit_Local` = 1.000000000 | 1.000000000 |
| 0x0C (12) | `TLow_Limit_Local` field part 2 | v1 `registers[6]` `TLow_Limit_Local` = 1.000000000 | 1.000000000 |
| 0x07 (7) | `THigh_Limit_Remote_Ch1` field part 1 | v1 `registers[7]` `THigh_Limit_Remote_Ch1` = 0.940097748 | 0.940097748 |
| 0x0D (13) | `THigh_Limit_Remote_Ch1` field part 2 | v1 `registers[7]` `THigh_Limit_Remote_Ch1` = 0.940097748 | 0.940097748 |
| 0x13 (19) | `THigh_Limit_Remote_Ch1` field part 3 | v1 `registers[7]` `THigh_Limit_Remote_Ch1` = 0.940097748 | 0.940097748 |
| 0x08 (8) | `TLow_Limit_Remote_Ch1` field part 1 | v1 `registers[8]` `TLow_Limit_Remote_Ch1` = 0.940097748 | 0.940097748 |
| 0x0E (14) | `TLow_Limit_Remote_Ch1` field part 2 | v1 `registers[8]` `TLow_Limit_Remote_Ch1` = 0.940097748 | 0.940097748 |
| 0x14 (20) | `TLow_Limit_Remote_Ch1` field part 3 | v1 `registers[8]` `TLow_Limit_Remote_Ch1` = 0.940097748 | 0.940097748 |
| 0x0F (15) | `One_Shot` field part 1 | v1 `registers[9]` `One_Shot` = 1.000000000 | 1.000000000 |
| 0x11 (17) | `Scratchpad1` field part 1 | v1 `registers[10]` `Scratchpad1` = 1.000000000 | 1.000000000 |
| 0x12 (18) | `Scratchpad2` field part 1 | v1 `registers[11]` `Scratchpad2` = 1.000000000 | 1.000000000 |
| 0x15 (21) | `THigh_Limit_Remote_Ch2` field part 1 | v1 `registers[12]` `THigh_Limit_Remote_Ch2` = 0.939643673 | 0.939643673 |
| 0x17 (23) | `THigh_Limit_Remote_Ch2` field part 2 | v1 `registers[12]` `THigh_Limit_Remote_Ch2` = 0.939643673 | 0.939643673 |
| 0x16 (22) | `TLow_Limit_Remote_Ch2` field part 1 | v1 `registers[13]` `TLow_Limit_Remote_Ch2` = 0.939643673 | 0.939643673 |
| 0x18 (24) | `TLow_Limit_Remote_Ch2` field part 2 | v1 `registers[13]` `TLow_Limit_Remote_Ch2` = 0.939643673 | 0.939643673 |
| 0x19 (25) | `THigh_Crit_Remote_Ch1` field part 1 | v1 `registers[14]` `THigh_Crit_Remote_Ch1` = 1.000000000 | 1.000000000 |
| 0x1A (26) | `THigh_Crit_Remote_Ch2` field part 1 | v1 `registers[15]` `THigh_Crit_Remote_Ch2` = 1.000000000 | 1.000000000 |
| 0x1B (27) | `Diode_Fault` field part 1 | v1 `registers[16]` `Diode_Fault` = 0.997820437 | 0.997820437 |
| 0x1F (31) | `Alert_Mask` field part 1 | v1 `registers[17]` `Alert_Mask` = 0.998637773 | 0.998637773 |
| 0x20 (32) | `THigh_Crit_Local` field part 1 | v1 `registers[18]` `THigh_Crit_Local` = 1.000000000 | 1.000000000 |
| 0x21 (33) | `Hysteresis` field part 1 | v1 `registers[19]` `Hysteresis` = 0.997275547 | 0.997275547 |
| 0x23 (35) | `Temp_Remote_Ch2` field part 1 | v1 `registers[20]` `Temp_Remote_Ch2` = 0.939643673 | 0.939643673 |
| 0x24 (36) | `Temp_Remote_Ch2` field part 2 | v1 `registers[20]` `Temp_Remote_Ch2` = 0.939643673 | 0.939643673 |
| 0x27 (39) | `η-Factor_Ch1` field part 1 | v1 `registers[21]` `η-Factor_Ch1` = 1.000000000 | 1.000000000 |
| 0x28 (40) | `η-Factor_Ch2` field part 1 | v1 `registers[22]` `η-Factor_Ch2` = 1.000000000 | 1.000000000 |
| 0x35 (53) | `High_Limit_Status` field part 1 | v1 `registers[23]` `High_Limit_Status` = 0.958062612 | 0.958062612 |
| 0x36 (54) | `Low_Limit_Status` field part 1 | v1 `registers[24]` `Low_Limit_Status` = 0.958062612 | 0.958062612 |
| 0x37 (55) | `TCRIT_Limit_Status` field part 1 | v1 `registers[25]` `TCRIT_Limit_Status` = 0.998637773 | 0.998637773 |
| 0x40 (64) | `Filter_Control` field part 1 | v1 `registers[26]` `Filter_Control` = 0.997275547 | 0.997275547 |
| 0xFD (253) | `Chip_ID` field part 1 | v1 `registers[27]` `Chip_ID` = 1.000000000 | 1.000000000 |
| 0xFE (254) | `Vendor_ID` field part 1 | v1 `registers[28]` `Vendor_ID` = 1.000000000 | 1.000000000 |
| 0xFF (255) | `Device_Rev_ID` field part 1 | v1 `registers[29]` `Device_Rev_ID` = 1.000000000 | 1.000000000 |

sum(q_R) for 42 physical address entries = **41.053777984**.

No D1 physical address is missing, and no v1 physical address is extra.

`m=42, x=0, m/(m+x)=42/(42+0)=1.000000`.

S_final = (10 / 42 x 41.053777984) x 1.000000 = **9.774709044/10**.

## 4. Detailed error and omission inventory

### 4.1 Wrong logical widths

D1 defines the remote temperature result and remote alert-limit quantities as 12-bit logical values. v1 uses the two 8-bit physical containers and reports 16 bits at the logical-register level. The field-part widths remain correctly reported as 8 bits.
- `registers[1].width_bits`: v1=16; D1=12. Source: D1 §8.2 p.27 Table 8-4; §8.11 p.33 Table 8-13; §7.5.1 p.19 Table 7-1.
- `registers[7].width_bits`: v1=16; D1=12. Source: D1 §8.8 p.32 Table 8-10; §8.14 p.35 Table 8-16.
- `registers[8].width_bits`: v1=16; D1=12. Source: D1 §8.9 p.32 Table 8-11; §8.15 p.35 Table 8-17.
- `registers[12].width_bits`: v1=16; D1=12. Source: D1 §8.16 p.36 Table 8-18; §8.18 p.37 Table 8-20.
- `registers[13].width_bits`: v1=16; D1=12. Source: D1 §8.17 p.36 Table 8-19; §8.19 p.37 Table 8-21.
- `registers[20].width_bits`: v1=16; D1=12. Source: D1 §8.26-8.27, p.42, Tables 8-28 and 8-29; §7.5.1 p.19 Table 7-1.

### 4.2 Read-to-clear access types incompletely represented

- `registers[23].type_write_read`: D1 Table 8-1 says `RC` for High_Limit_Status; v1 is `R`.
- `registers[23].field_parts[0].type_write_read`: D1 register type is `RC`; v1 is `R`.
- `registers[23].field_parts[0].bit_field[1.3].type_write_read`: D1 Table 8-33 gives `RC` for Ch2_High, Ch1_High, and Local_High; v1 reports `R`.
- `registers[24].type_write_read`: D1 Table 8-1 says `RC` for Low_Limit_Status; v1 is `R`.
- `registers[24].field_parts[0].type_write_read`: D1 register type is `RC`; v1 is `R`.
- `registers[24].field_parts[0].bit_field[1.3].type_write_read`: D1 Table 8-34 gives `RC` for Ch2_Low, Ch1_Low, and Local_Low; v1 reports `R`.

The v1 descriptions mention read-to-clear behavior, so the error is specifically the objective access-code field. It is scored partial because read access is retained.

### 4.3 Missing access type on reserved bit fields

D1 field tables assign `R` to every reserved bit range. v1 correctly marks these ranges reserved and uses acceptable Reserved names/descriptions, but leaves `type_write_read` empty. Exact missing fields:
- `registers[1].field_parts[1].bit_field[1].type_write_read` (Temp_Remote_Ch1, 0x10, bits 0:3): expected `R`, v1 empty string.
- `registers[2].field_parts[0].bit_field[1].type_write_read` (Status, 0x02, bits 5:6): expected `R`, v1 empty string.
- `registers[2].field_parts[0].bit_field[6].type_write_read` (Status, 0x02, bits 0:0): expected `R`, v1 empty string.
- `registers[3].field_parts[0].bit_field[3].type_write_read` (Configuration, 0x03, bits 0:4): expected `R`, v1 empty string.
- `registers[3].field_parts[1].bit_field[3].type_write_read` (Configuration, 0x09, bits 0:4): expected `R`, v1 empty string.
- `registers[4].field_parts[0].bit_field[0].type_write_read` (Conv_Period, 0x04, bits 4:7): expected `R`, v1 empty string.
- `registers[4].field_parts[1].bit_field[0].type_write_read` (Conv_Period, 0x0A, bits 4:7): expected `R`, v1 empty string.
- `registers[7].field_parts[2].bit_field[1].type_write_read` (THigh_Limit_Remote_Ch1, 0x13, bits 0:3): expected `R`, v1 empty string.
- `registers[8].field_parts[2].bit_field[1].type_write_read` (TLow_Limit_Remote_Ch1, 0x14, bits 0:3): expected `R`, v1 empty string.
- `registers[12].field_parts[1].bit_field[1].type_write_read` (THigh_Limit_Remote_Ch2, 0x17, bits 0:3): expected `R`, v1 empty string.
- `registers[13].field_parts[1].bit_field[1].type_write_read` (TLow_Limit_Remote_Ch2, 0x18, bits 0:3): expected `R`, v1 empty string.
- `registers[16].field_parts[0].bit_field[0].type_write_read` (Diode_Fault, 0x1B, bits 4:7): expected `R`, v1 empty string.
- `registers[16].field_parts[0].bit_field[4].type_write_read` (Diode_Fault, 0x1B, bits 0:0): expected `R`, v1 empty string.
- `registers[17].field_parts[0].bit_field[0].type_write_read` (Alert_Mask, 0x1F, bits 3:7): expected `R`, v1 empty string.
- `registers[19].field_parts[0].bit_field[0].type_write_read` (Hysteresis, 0x21, bits 5:7): expected `R`, v1 empty string.
- `registers[20].field_parts[1].bit_field[1].type_write_read` (Temp_Remote_Ch2, 0x24, bits 0:3): expected `R`, v1 empty string.
- `registers[23].field_parts[0].bit_field[0].type_write_read` (High_Limit_Status, 0x35, bits 3:7): expected `R`, v1 empty string.
- `registers[24].field_parts[0].bit_field[0].type_write_read` (Low_Limit_Status, 0x36, bits 3:7): expected `R`, v1 empty string.
- `registers[25].field_parts[0].bit_field[0].type_write_read` (TCRIT_Limit_Status, 0x37, bits 3:7): expected `R`, v1 empty string.
- `registers[26].field_parts[0].bit_field[0].type_write_read` (Filter_Control, 0x40, bits 2:7): expected `R`, v1 empty string.

There are 20 such reserved-bit access-type omissions. Empty reserved names/descriptions are not separately penalized because D1 permits a reserved bit to be represented without a functional name/description; the access type is an objective field and is present in D1.

### 4.4 Deep-field review findings that are not errors

- All 42 physical addresses, including shared aliases, match D1 Table 8-1; all decimal/hex pairs are numerically equivalent.
- All logical names, physical field-part names, bit ranges, physical bit-field/field-part widths, `is_reserved` flags, reset values, and non-`RC` access types match D1.
- `Temp_Local[7:0]` contains the nine examples from D1 Table 7-2 (80, E6, FD, FE, 00, 01, 02, 19, 7F) with correct two's-complement temperatures; no penalty is applied.
- Both 48-entry η-factor lists match D1 Table 8-30; the Ch1/Ch2 reset descriptions correctly identify 12h as η=1.004.
- Description differences are non-contradictory paraphrases or correct additional context and receive full description credit under the relaxed description rule.

## 5. Final result

The datasheet-based score for TMP4719 v1.0 is **9.774709044/10**. Deductions come from six logical `width_bits` facts, six incomplete `RC` access-code facts (two logical, two field-part, and six bit-field fields), and 20 omitted reserved-bit `R` type fields; there are no missing or extra physical register addresses.

D1 source: Texas Instruments TMP4719 datasheet, SBOSAJ7A, local file `D:\python\master_arbeit\data\output\TMP4719\TMP4719.pdf`, with section/table/page citations given throughout.
