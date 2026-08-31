# MCP9808 11.0 detailed score — revised AGENTS.md rules

## 1. Scoring basis

- `n=8` truth physical registers are keyed by numeric address, bank, and page: `0x01` through `0x08`.
- `v11` is associated to truth by numeric physical address; all `8` truth addresses are matched and there are `0` extra extracted physical addresses.
- Every matched extracted logical register is calculated independently from the bottom up: truth bit fields → field part → logical register `Q(L)`.
- Bit fields are aligned by exact ordered `(bit_start, bit_end)` within the matched physical field part. All 33 bit-field ranges in this version match truth exactly.
- Descriptive paraphrases and general field-part/address descriptions without functional deviation receive 1.0. Objective ranges, widths, access types, reserved flags, and value codes are strict.
- Reserved labels and descriptions are accepted where they state the reserved/read-as-zero function; all objective value-code lists are present and correct.
- Rounded AHP weights are normalized by `0.9999` at bit-field level and `1.0001` at logical-register level; field-part weights sum to `1.0000`.

AHP weights used:

- logical register: `name` 0.0225, `physical_address` 0.4044, `register_description` 0.0564, `width_bits` 0.0590, `type_write_read` 0.0590, `field_parts` 0.2987, `default_value` 0.0667, `default_value_description` 0.0334; category is excluded.
- field part: `register_name` 0.0280, `physical_address` 0.4688, `description` 0.0693, `width_bits` 0.0605, `type_write_read` 0.0605, `bit_field` 0.3129.
- bit field: `name_or_parameter` 0.0212, `field_description` 0.0586, `bit_start` 0.2594, `bit_end` 0.2594, `bit_width` 0.0583, `values` 0.2097, `is_reserved` 0.0750, `type_write_read` 0.0583.

## Extracted logical register 1: `CONFIG`

v11 location: `registers[0]`; truth association: `truth registers[0]` (`CONFIG`).
Associated physical location: `0x01` (1).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CONFIG` at `0x01` (1)

Locations: `truth registers[0].field_parts[0]` ↔ `v11 registers[0].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 11:15**

Locations: `truth registers[0].field_parts[0].bit_field[0]` ↔ `v11 registers[0].field_parts[0].bit_field[0]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Read as '0'." |
| `bit_start` | 0.2594 | 1.0 | 11 | 11 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `T_HYST` bits 9:10**

Locations: `truth registers[0].field_parts[0].bit_field[1]` ↔ `v11 registers[0].field_parts[0].bit_field[1]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "T_HYST" | "T_HYST" |
| `field_description` | 0.0586 | 1.0 | "T_UPPER and T_LOWER limit hysteresis selection." | "TUPPER and TLOWER limit hysteresis bits; cannot be altered when either Lock bit (bit 6/7) is set; programmable in Shutdown mode. Applies for decreasing temperature (Section 5.2.2)." |
| `bit_start` | 0.2594 | 1.0 | 9 | 9 |
| `bit_end` | 0.2594 | 1.0 | 10 | 10 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"0°C (power-up default)"},{"value":"01","value_description":"+1.5°C"},{"value":"10","value_description":"+3.0°C"},{"value":"11","value_description":"+6.0°C"}] | [{"value":"00","value_description":"0°C (power-up default)"},{"value":"01","value_description":"+1.5°C"},{"value":"10","value_description":"+3.0°C"},{"value":"11","value_description":"+6.0°C"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `SHDN` bits 8:8**

Locations: `truth registers[0].field_parts[0].bit_field[2]` ↔ `v11 registers[0].field_parts[0].bit_field[2]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "SHDN" | "SHDN" |
| `field_description` | 0.0586 | 1.0 | "Shutdown Mode bit." | "Shutdown Mode bit; in shutdown all power-consuming activities are disabled while registers remain readable/writable. Cannot be set to '1' when either Lock bit is set, but can be cleared to '0' while locked." |
| `bit_start` | 0.2594 | 1.0 | 8 | 8 |
| `bit_end` | 0.2594 | 1.0 | 8 | 8 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Continuous conversion (power-up default)"},{"value":"1","value_description":"Shutdown (Low-Power mode)"}] | [{"value":"0","value_description":"Continuous conversion (power-up default)"},{"value":"1","value_description":"Shutdown (Low-Power mode)"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `Crit. Lock` bits 7:7**

Locations: `truth registers[0].field_parts[0].bit_field[3]` ↔ `v11 registers[0].field_parts[0].bit_field[3]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Crit. Lock" | "Crit. Lock" |
| `field_description` | 0.0586 | 1.0 | "T_CRIT Lock bit." | "TCRIT lock bit; remains set/locked until cleared by an internal Reset; programmable in Shutdown mode." |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Unlocked; T_CRIT register can be written (power-up default)"},{"value":"1","value_description":"Locked; T_CRIT register cannot be written"}] | [{"value":"0","value_description":"Unlocked; TCRIT register can be written (power-up default)"},{"value":"1","value_description":"Locked; TCRIT register cannot be written"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 5: `Win. Lock` bits 6:6**

Locations: `truth registers[0].field_parts[0].bit_field[4]` ↔ `v11 registers[0].field_parts[0].bit_field[4]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Win. Lock" | "Win. Lock" |
| `field_description` | 0.0586 | 1.0 | "T_UPPER and T_LOWER Window Lock bit." | "TUPPER and TLOWER window lock bit; remains set/locked until cleared by a Power-on Reset; programmable in Shutdown mode." |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Unlocked; T_UPPER and T_LOWER registers can be written (power-up default)"},{"value":"1","value_description":"Locked; T_UPPER and T_LOWER registers cannot be written"}] | [{"value":"0","value_description":"Unlocked; TUPPER and TLOWER registers can be written (power-up default)"},{"value":"1","value_description":"Locked; TUPPER and TLOWER registers cannot be written"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 6: `Int. Clear` bits 5:5**

Locations: `truth registers[0].field_parts[0].bit_field[5]` ↔ `v11 registers[0].field_parts[0].bit_field[5]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Int. Clear" | "Int. Clear" |
| `field_description` | 0.0586 | 1.0 | "Interrupt Clear bit." | "Interrupt Clear bit; cannot be set to '1' in Shutdown mode but can be cleared after entering Shutdown." |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No effect (power-up default)"},{"value":"1","value_description":"Clear interrupt output; when read, this bit returns to '0'"}] | [{"value":"0","value_description":"No effect (power-up default)"},{"value":"1","value_description":"Clear interrupt output; when read, this bit returns to '0'"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 7: `Alert Stat.` bits 4:4**

Locations: `truth registers[0].field_parts[0].bit_field[6]` ↔ `v11 registers[0].field_parts[0].bit_field[6]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Alert Stat." | "Alert Stat." |
| `field_description` | 0.0586 | 1.0 | "Alert Output Status bit." | "Alert Output Status bit; cannot be set/cleared in Shutdown mode, but is cleared if the host clears the interrupt (bit 5) during Shutdown while in Interrupt mode." |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Alert output is not asserted by the device (power-up default)"},{"value":"1","value_description":"Alert output is asserted as a comparator/Interrupt or critical temperature output"}] | [{"value":"0","value_description":"Alert output is not asserted by the device (power-up default)"},{"value":"1","value_description":"Alert output is asserted as comparator/Interrupt or critical temperature output"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 8: `Alert Cnt.` bits 3:3**

Locations: `truth registers[0].field_parts[0].bit_field[7]` ↔ `v11 registers[0].field_parts[0].bit_field[7]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Alert Cnt." | "Alert Cnt." |
| `field_description` | 0.0586 | 1.0 | "Alert Output Control bit." | "Alert Output Control bit; cannot be altered when either Lock bit is set; programmable in Shutdown mode but Alert output will not assert/deassert." |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disabled (power-up default)"},{"value":"1","value_description":"Enabled"}] | [{"value":"0","value_description":"Disabled (power-up default)"},{"value":"1","value_description":"Enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 9: `Alert Sel.` bits 2:2**

Locations: `truth registers[0].field_parts[0].bit_field[8]` ↔ `v11 registers[0].field_parts[0].bit_field[8]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Alert Sel." | "Alert Sel." |
| `field_description` | 0.0586 | 1.0 | "Alert Output Select bit." | "Alert Output Select bit; cannot be altered while Window Lock (bit 6) is set; programmable in Shutdown mode but Alert output will not assert/deassert." |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Alert output for T_UPPER, T_LOWER and T_CRIT (power-up default)"},{"value":"1","value_description":"T_A > T_CRIT only; T_UPPER and T_LOWER boundaries are disabled"}] | [{"value":"0","value_description":"Alert output for TUPPER, TLOWER and TCRIT (power-up default)"},{"value":"1","value_description":"TA > TCRIT only (TUPPER and TLOWER boundaries disabled)"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 10: `Alert Pol.` bits 1:1**

Locations: `truth registers[0].field_parts[0].bit_field[9]` ↔ `v11 registers[0].field_parts[0].bit_field[9]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Alert Pol." | "Alert Pol." |
| `field_description` | 0.0586 | 1.0 | "Alert Output Polarity bit." | "Alert Output Polarity bit; cannot be altered when either Lock bit is set; programmable in Shutdown mode but Alert output will not assert/deassert. Open-drain output requires pull-up resistor." |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Active-low (power-up default; pull-up resistor required)"},{"value":"1","value_description":"Active-high"}] | [{"value":"0","value_description":"Active-low (power-up default; pull-up resistor required)"},{"value":"1","value_description":"Active-high"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 11: `Alert Mod.` bits 0:0**

Locations: `truth registers[0].field_parts[0].bit_field[10]` ↔ `v11 registers[0].field_parts[0].bit_field[10]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Alert Mod." | "Alert Mod." |
| `field_description` | 0.0586 | 1.0 | "Alert Output Mode bit." | "Alert Output Mode bit; cannot be altered when either Lock bit is set; programmable in Shutdown mode but Alert output will not assert/deassert." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Comparator output (power-up default)"},{"value":"1","value_description":"Interrupt output"}] | [{"value":"0","value_description":"Comparator output (power-up default)"},{"value":"1","value_description":"Interrupt output"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**. The field-part address, width, access type, and descriptive content are functionally correct; the general description is accepted.

| Field-part field | Weight | Correctness | Truth content | v11 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.0 | "CONFIG" | "CONFIG" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":""} | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"Register pointer 0001."} |
| `description` | 0.0693 | 1.0 | "" | "16-bit Configuration register (bits 15-0), MSB (bits 15-8) then LSB (bits 7-0)." |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 1.000000 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. All direct logical-register fields are correct; descriptive expansions preserve the register function.

| Logical-register field | Weight | Correctness | Truth comparison target | v11 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "CONFIG" | "CONFIG" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":""}] | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":"Register pointer 0001; 16-bit Configuration register accessed as MSB then LSB over the serial interface."}] |
| `register_description` | 0.0564 | 1.0 | "16-bit configuration register for temperature alert hysteresis, shutdown mode, temperature-limit locks, and Alert output configuration." | "16-bit Configuration register used to set alert hysteresis (T_HYST), Shutdown/Low-Power mode (SHDN), TCRIT and TUPPER/TLOWER window lock bits, interrupt clear, alert output status, alert output enable, alert output select (window vs TCRIT-only), polarity and comparator/interrupt mode. Lock bits (bits 7-6) prevent rewriting TUPPER/TLOWER/TCRIT and are cleared only by reset/POR; several bits cannot be altered while locked, and SHDN cannot be set while locked but can be cleared. Additional behavior is described in Section 5.2.1 Shutdown Mode, Section 5.2.2 Temperature Hysteresis, Section 5.2.3 Alert Output Configuration and Figure 5-10; retrieval hint: those sections/detail the lock, hysteresis and Alert output workflow that CONFIG controls." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 1.000000 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "Comparator mode, active-low Alert and Critical output, output disabled, Alert not asserted, interrupt cleared, limits unlocked, continuous conversion, and 0°C hysteresis." | "POR default: comparator mode, active-low output, alert and critical output, output disabled, alert not asserted, interrupt cleared, limits unlocked, continuous conversion, 0°C hysteresis." |

\(Q(L_{1})=( 0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 2: `TUPPER`

v11 location: `registers[1]`; truth association: `truth registers[1]` (`TUPPER`).
Associated physical location: `0x02` (2).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TUPPER` at `0x02` (2)

Locations: `truth registers[1].field_parts[0]` ↔ `v11 registers[1].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 13:15**

Locations: `truth registers[1].field_parts[0].bit_field[0]` ↔ `v11 registers[1].field_parts[0].bit_field[0]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Read as '0'." |
| `bit_start` | 0.2594 | 1.0 | 13 | 13 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `Sign` bits 12:12**

Locations: `truth registers[1].field_parts[0].bit_field[1]` ↔ `v11 registers[1].field_parts[0].bit_field[1]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Sign" | "Sign" |
| `field_description` | 0.0586 | 1.0 | "Sign bit." | "Sign bit of the boundary value." |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 12 | 12 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}] | [{"value":"0","value_description":"TA ≥ 0°C"},{"value":"1","value_description":"TA < 0°C"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `TUPPER` bits 2:11**

Locations: `truth registers[1].field_parts[0].bit_field[2]` ↔ `v11 registers[1].field_parts[0].bit_field[2]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "TUPPER" | "TUPPER" |
| `field_description` | 0.0586 | 1.0 | "Upper temperature boundary trip data in two's complement format." | "Temperature boundary trip data in two's complement format (0.25°C/bit)." |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 11 | 11 |
| `bit_width` | 0.0583 | 1.0 | 10 | 10 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `Unimplemented` bits 0:1**

Locations: `truth registers[1].field_parts[0].bit_field[3]` ↔ `v11 registers[1].field_parts[0].bit_field[3]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Read as '0'." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**. The field-part address, width, access type, and descriptive content are functionally correct; the general description is accepted.

| Field-part field | Weight | Correctness | Truth content | v11 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.0 | "TUPPER" | "TUPPER" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x02","decimal":"2","bank":"","page":"","description":""} | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"Register pointer 0010."} |
| `description` | 0.0693 | 1.0 | "" | "16-bit upper temperature boundary register (MSB bits 15-8, LSB bits 7-0)." |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 1.000000 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. All direct logical-register fields are correct; descriptive expansions preserve the register function.

| Logical-register field | Weight | Correctness | Truth comparison target | v11 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "TUPPER" | "TUPPER" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":""}] | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":"Register pointer 0010; 16-bit Alert Temperature Upper Boundary Trip register."}] |
| `register_description` | 0.0564 | 1.0 | "16-bit read/write Alert Output Temperature Upper Boundary register containing 11-bit temperature data in two's complement format with 0.25°C resolution." | "16-bit read/write Alert Output Temperature Upper Boundary register containing 11-bit two's complement data (sign bit 12 plus temperature bits 11-2) at 0.25°C resolution representing the upper temperature trip boundary. If enabled via CONFIG and ambient temperature exceeds the boundary/window, the Alert output asserts (Section 5.2.3 Alert Output Configuration, Figure 5-10); writes are blocked when the Window Lock bit (CONFIG bit 6) is set." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 1.000000 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "0°C" | "POR default 0°C." |

\(Q(L_{2})=( 0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 3: `TLOWER`

v11 location: `registers[2]`; truth association: `truth registers[2]` (`TLOWER`).
Associated physical location: `0x03` (3).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TLOWER` at `0x03` (3)

Locations: `truth registers[2].field_parts[0]` ↔ `v11 registers[2].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 13:15**

Locations: `truth registers[2].field_parts[0].bit_field[0]` ↔ `v11 registers[2].field_parts[0].bit_field[0]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Read as '0'." |
| `bit_start` | 0.2594 | 1.0 | 13 | 13 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `Sign` bits 12:12**

Locations: `truth registers[2].field_parts[0].bit_field[1]` ↔ `v11 registers[2].field_parts[0].bit_field[1]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Sign" | "Sign" |
| `field_description` | 0.0586 | 1.0 | "Sign bit." | "Sign bit of the boundary value." |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 12 | 12 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}] | [{"value":"0","value_description":"TA ≥ 0°C"},{"value":"1","value_description":"TA < 0°C"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `TLOWER` bits 2:11**

Locations: `truth registers[2].field_parts[0].bit_field[2]` ↔ `v11 registers[2].field_parts[0].bit_field[2]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "TLOWER" | "TLOWER" |
| `field_description` | 0.0586 | 1.0 | "Lower temperature boundary trip data in two's complement format." | "Temperature boundary trip data in two's complement format (0.25°C/bit)." |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 11 | 11 |
| `bit_width` | 0.0583 | 1.0 | 10 | 10 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `Unimplemented` bits 0:1**

Locations: `truth registers[2].field_parts[0].bit_field[3]` ↔ `v11 registers[2].field_parts[0].bit_field[3]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Read as '0'." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**. The field-part address, width, access type, and descriptive content are functionally correct; the general description is accepted.

| Field-part field | Weight | Correctness | Truth content | v11 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.0 | "TLOWER" | "TLOWER" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x03","decimal":"3","bank":"","page":"","description":""} | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"Register pointer 0011."} |
| `description` | 0.0693 | 1.0 | "" | "16-bit lower temperature boundary register (MSB bits 15-8, LSB bits 7-0)." |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 1.000000 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. All direct logical-register fields are correct; descriptive expansions preserve the register function.

| Logical-register field | Weight | Correctness | Truth comparison target | v11 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "TLOWER" | "TLOWER" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":""}] | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"Register pointer 0011; 16-bit Alert Temperature Lower Boundary Trip register."}] |
| `register_description` | 0.0564 | 1.0 | "16-bit read/write Lower Boundary register containing 11-bit temperature data in two's complement format with 0.25°C resolution." | "16-bit read/write Alert Output Temperature Lower Boundary register containing 11-bit two's complement data (sign bit 12 plus temperature bits 11-2) at 0.25°C resolution representing the lower temperature trip boundary. If enabled via CONFIG and ambient temperature drifts outside the boundary/window, the Alert output asserts (Section 5.2.3 Alert Output Configuration, Figure 5-10); writes are blocked when the Window Lock bit (CONFIG bit 6) is set." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 1.000000 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "0°C" | "POR default 0°C." |

\(Q(L_{3})=( 0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 4: `TCRIT`

v11 location: `registers[3]`; truth association: `truth registers[3]` (`TCRIT`).
Associated physical location: `0x04` (4).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TCRIT` at `0x04` (4)

Locations: `truth registers[3].field_parts[0]` ↔ `v11 registers[3].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 13:15**

Locations: `truth registers[3].field_parts[0].bit_field[0]` ↔ `v11 registers[3].field_parts[0].bit_field[0]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Read as '0'." |
| `bit_start` | 0.2594 | 1.0 | 13 | 13 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `Sign` bits 12:12**

Locations: `truth registers[3].field_parts[0].bit_field[1]` ↔ `v11 registers[3].field_parts[0].bit_field[1]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Sign" | "Sign" |
| `field_description` | 0.0586 | 1.0 | "Sign bit." | "Sign bit of the boundary value." |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 12 | 12 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}] | [{"value":"0","value_description":"TA ≥ 0°C"},{"value":"1","value_description":"TA < 0°C"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `TCRIT` bits 2:11**

Locations: `truth registers[3].field_parts[0].bit_field[2]` ↔ `v11 registers[3].field_parts[0].bit_field[2]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "TCRIT" | "TCRIT" |
| `field_description` | 0.0586 | 1.0 | "Critical temperature boundary trip data in two's complement format." | "Temperature boundary trip data in two's complement format (0.25°C/bit)." |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 11 | 11 |
| `bit_width` | 0.0583 | 1.0 | 10 | 10 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `Unimplemented` bits 0:1**

Locations: `truth registers[3].field_parts[0].bit_field[3]` ↔ `v11 registers[3].field_parts[0].bit_field[3]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Read as '0'." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**. The field-part address, width, access type, and descriptive content are functionally correct; the general description is accepted.

| Field-part field | Weight | Correctness | Truth content | v11 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.0 | "TCRIT" | "TCRIT" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x04","decimal":"4","bank":"","page":"","description":""} | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Register pointer 0100."} |
| `description` | 0.0693 | 1.0 | "" | "16-bit critical temperature boundary register (MSB bits 15-8, LSB bits 7-0)." |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 1.000000 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. All direct logical-register fields are correct; descriptive expansions preserve the register function.

| Logical-register field | Weight | Correctness | Truth comparison target | v11 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "TCRIT" | "TCRIT" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":""}] | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":"Register pointer 0100; 16-bit Critical Temperature Trip register."}] |
| `register_description` | 0.0564 | 1.0 | "16-bit read/write Critical Boundary register containing 11-bit temperature data in two's complement format with 0.25°C resolution." | "16-bit read/write Critical Temperature Boundary register containing 11-bit two's complement data (sign bit 12 plus temperature bits 11-2) at 0.25°C resolution providing an additional critical temperature limit. When TA ≥ TCRIT the Alert output is forced to comparator mode regardless of CONFIG bit 0 until TA < TCRIT - T_HYST (Section 5.2.3, Figure 5-10); writes are blocked when the Critical Lock bit (CONFIG bit 7) is set." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 1.000000 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "0°C" | "POR default 0°C." |

\(Q(L_{4})=( 0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 5: `TA`

v11 location: `registers[4]`; truth association: `truth registers[4]` (`TA`).
Associated physical location: `0x05` (5).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TA` at `0x05` (5)

Locations: `truth registers[4].field_parts[0]` ↔ `v11 registers[4].field_parts[0]`.

**Truth bit field 1: `TA vs. TCRIT` bits 15:15**

Locations: `truth registers[4].field_parts[0].bit_field[0]` ↔ `v11 registers[4].field_parts[0].bit_field[0]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "TA vs. TCRIT" | "TA vs. TCRIT" |
| `field_description` | 0.0586 | 1.0 | "Indicates whether ambient temperature is at or above the critical limit." | "Reflects Alert state for critical limit; not affected by CONFIG<5:0>." |
| `bit_start` | 0.2594 | 1.0 | 15 | 15 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A < T_CRIT"},{"value":"1","value_description":"T_A ≥ T_CRIT"}] | [{"value":"0","value_description":"TA < TCRIT"},{"value":"1","value_description":"TA ≥ TCRIT"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `TA vs. TUPPER` bits 14:14**

Locations: `truth registers[4].field_parts[0].bit_field[1]` ↔ `v11 registers[4].field_parts[0].bit_field[1]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "TA vs. TUPPER" | "TA vs. TUPPER" |
| `field_description` | 0.0586 | 1.0 | "Indicates whether ambient temperature is above the upper boundary." | "Reflects Alert state for upper boundary; not affected by CONFIG<5:0>." |
| `bit_start` | 0.2594 | 1.0 | 14 | 14 |
| `bit_end` | 0.2594 | 1.0 | 14 | 14 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A ≤ T_UPPER"},{"value":"1","value_description":"T_A > T_UPPER"}] | [{"value":"0","value_description":"TA ≤ TUPPER"},{"value":"1","value_description":"TA > TUPPER"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `TA vs. TLOWER` bits 13:13**

Locations: `truth registers[4].field_parts[0].bit_field[2]` ↔ `v11 registers[4].field_parts[0].bit_field[2]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "TA vs. TLOWER" | "TA vs. TLOWER" |
| `field_description` | 0.0586 | 1.0 | "Indicates whether ambient temperature is below the lower boundary." | "Reflects Alert state for lower boundary; not affected by CONFIG<5:0>." |
| `bit_start` | 0.2594 | 1.0 | 13 | 13 |
| `bit_end` | 0.2594 | 1.0 | 13 | 13 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A ≥ T_LOWER"},{"value":"1","value_description":"T_A < T_LOWER"}] | [{"value":"0","value_description":"TA ≥ TLOWER"},{"value":"1","value_description":"TA < TLOWER"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `SIGN` bits 12:12**

Locations: `truth registers[4].field_parts[0].bit_field[3]` ↔ `v11 registers[4].field_parts[0].bit_field[3]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "SIGN" | "SIGN" |
| `field_description` | 0.0586 | 1.0 | "Ambient temperature sign bit." | "Sign bit of ambient temperature." |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 12 | 12 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}] | [{"value":"0","value_description":"TA ≥ 0°C"},{"value":"1","value_description":"TA < 0°C"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 5: `TA` bits 0:11**

Locations: `truth registers[4].field_parts[0].bit_field[4]` ↔ `v11 registers[4].field_parts[0].bit_field[4]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "TA" | "TA" |
| `field_description` | 0.0586 | 1.0 | "12-bit ambient temperature data in two's complement format." | "12-bit ambient temperature data in two's complement format; bits 2-0 may remain '0' depending on the Resolution register (power-up default 0.25°C/bit)." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 11 | 11 |
| `bit_width` | 0.0583 | 1.0 | 12 | 12 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**. The field-part address, width, access type, and descriptive content are functionally correct; the general description is accepted.

| Field-part field | Weight | Correctness | Truth content | v11 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.0 | "TA" | "TA" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x05","decimal":"5","bank":"","page":"","description":""} | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Register pointer 0101."} |
| `description` | 0.0693 | 1.0 | "" | "16-bit ambient temperature register (upper byte bits 15-8, lower byte bits 7-0)." |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 1.000000 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. All direct logical-register fields are correct; descriptive expansions preserve the register function.

| Logical-register field | Weight | Correctness | Truth comparison target | v11 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "TA" | "TA" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x05","decimal":"5","bank":"","page":"","description":""}] | [{"hex":"0x05","decimal":"5","bank":"","page":"","description":"Register pointer 0101; 16-bit read-only Ambient Temperature register."}] |
| `register_description` | 0.0564 | 1.0 | "Double-buffered 16-bit read-only Ambient Temperature register containing 13-bit two's-complement temperature data and three Alert boundary-status bits; updated at the conversion refresh rate." | "16-bit read-only Ambient Temperature register holding 13-bit two's complement temperature data from the band-gap sensor and ΔΣ ADC; bits TA<12:0> are double-buffered and updated every tCONV. Bits 15-13 reflect the Alert pin state (TA≥TCRIT, TA>TUPPER, TA<TLOWER) and are not affected by CONFIG<5:0>. Conversion: mask bits 15-13, check SIGN (bit 12); for TA≥0°C, TA = UpperByte×2^4 + LowerByte×2^-4; for TA<0°C, TA = 256 - (UpperByte×2^4 + LowerByte×2^-4) (Equation 5-1); bits 2-0 may stay '0' depending on the Resolution register (default 0.25°C/bit)." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 1.000000 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "0°C" | "POR default 0°C." |

\(Q(L_{5})=( 0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 6: `Manufacturer ID`

v11 location: `registers[5]`; truth association: `truth registers[5]` (`Manufacturer ID`).
Associated physical location: `0x06` (6).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Manufacturer ID` at `0x06` (6)

Locations: `truth registers[5].field_parts[0]` ↔ `v11 registers[5].field_parts[0]`.

**Truth bit field 1: `Manufacturer ID` bits 0:15**

Locations: `truth registers[5].field_parts[0].bit_field[0]` ↔ `v11 registers[5].field_parts[0].bit_field[0]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Manufacturer ID" | "Manufacturer ID" |
| `field_description` | 0.0586 | 1.0 | "Device Manufacturer Identification bits." | "Device Manufacturer Identification bits (0x0054 for MCP9808)." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 16 | 16 |
| `values` | 0.2097 | 1.0 | [{"value":"0x0054","value_description":"Manufacturer ID for the MCP9808"}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**. The field-part address, width, access type, and descriptive content are functionally correct; the general description is accepted.

| Field-part field | Weight | Correctness | Truth content | v11 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.0 | "Manufacturer ID" | "Manufacturer ID" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x06","decimal":"6","bank":"","page":"","description":""} | {"hex":"0x06","decimal":"6","bank":"","page":"","description":"Register pointer 0110."} |
| `description` | 0.0693 | 1.0 | "" | "16-bit Manufacturer ID register (bits 15-0)." |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 1.000000 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. All direct logical-register fields are correct; descriptive expansions preserve the register function.

| Logical-register field | Weight | Correctness | Truth comparison target | v11 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "Manufacturer ID" | "Manufacturer ID" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":""}] | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":"Register pointer 0110; 16-bit read-only Manufacturer Identification register."}] |
| `register_description` | 0.0564 | 1.0 | "Read-only register used to identify the device manufacturer for manufacturer-specific operation." | "16-bit read-only register identifying the device manufacturer to enable manufacturer-specific operation; the MCP9808 Manufacturer ID is 0x0054 (hex). See Figure 5-6 for the read timing diagram (Section 4.0 Serial Communication)." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 1.000000 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0054" | "0x0054" |
| `default_value_description` | 0.0334 | 1.0 | "Manufacturer ID for the MCP9808." | "Manufacturer ID for the MCP9808 is 0x0054 (hex)." |

\(Q(L_{6})=( 0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## Extracted logical register 7: `Device ID/Device Revision`

v11 location: `registers[6]`; truth association: `truth registers[6]` (`Device ID/Revision`).
Associated physical location: `0x07` (7).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Device ID/Device Revision` at `0x07` (7)

Locations: `truth registers[6].field_parts[0]` ↔ `v11 registers[6].field_parts[0]`.

**Truth bit field 1: `Device ID` bits 8:15**

Locations: `truth registers[6].field_parts[0].bit_field[0]` ↔ `v11 registers[6].field_parts[0].bit_field[0]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Device ID" | "Device ID" |
| `field_description` | 0.0586 | 1.0 | "Device identification bits." | "Bits 15 to 8 are used for device ID (0x04 for MCP9808)." |
| `bit_start` | 0.2594 | 1.0 | 8 | 8 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [{"value":"0x04","value_description":"Device ID for the MCP9808"}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `Device Revision` bits 0:7**

Locations: `truth registers[6].field_parts[0].bit_field[1]` ↔ `v11 registers[6].field_parts[0].bit_field[1]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Device Revision" | "Device Revision" |
| `field_description` | 0.0586 | 1.0 | "Device revision bits." | "Bits 7 to 0 are used for device revision; begins at 0x00 for the first release and increments with revised versions." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [{"value":"0x00","value_description":"First release revision; incremented for revised versions"}] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000) = **1.000000**. The field-part register name differs only for the combined Device ID/Revision label; this is incomplete identification and receives C=0.5.

| Field-part field | Weight | Correctness | Truth content | v11 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 0.5 | "Device ID/Revision" | "Device ID/Device Revision" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} | {"hex":"0x07","decimal":"7","bank":"","page":"","description":"Register pointer 0111."} |
| `description` | 0.0693 | 1.0 | "" | "16-bit Device ID (upper byte) and Device Revision (lower byte) register." |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 1.000000 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×0.500000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{0.986000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.986000) = **0.986000**. Direct-field judgments: the extracted combined Device ID/Revision name is not identical to truth and receives C=0.5.

| Logical-register field | Weight | Correctness | Truth comparison target | v11 content |
|---|---|---|---|---|
| `name` | 0.0225 | 0.5 | "Device ID/Revision" | "Device ID/Device Revision" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":""}] | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":"Register pointer 0111; 16-bit read-only Device ID and Device Revision register."}] |
| `register_description` | 0.0564 | 1.0 | "Read-only register whose upper byte specifies the device identification and lower byte specifies the device revision." | "16-bit read-only register whose upper byte specifies the device identification (MCP9808 Device ID = 0x04) and whose lower byte specifies the device revision, beginning at 0x00 for the first release and incremented for revised versions. See Figure 5-7 for the read timing diagram (Section 4.0 Serial Communication)." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.986000 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0400" | "0x0400" |
| `default_value_description` | 0.0334 | 1.0 | "Device ID 0x04 and initial device revision 0x00." | "POR default 0x0400 (Device ID 0x04, revision 0x00)." |

\(Q(L_{7})=( 0.0225×0.500000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.986000 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=0.984668/1.0001=\mathbf{0.984570}\).

## Extracted logical register 8: `Resolution`

v11 location: `registers[7]`; truth association: `truth registers[7]` (`Resolution`).
Associated physical location: `0x08` (8).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Resolution` at `0x08` (8)

Locations: `truth registers[7].field_parts[0]` ↔ `v11 registers[7].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 2:7**

Locations: `truth registers[7].field_parts[0].bit_field[0]` ↔ `v11 registers[7].field_parts[0].bit_field[0]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Read as '0'." |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `Resolution` bits 0:1**

Locations: `truth registers[7].field_parts[0].bit_field[1]` ↔ `v11 registers[7].field_parts[0].bit_field[1]`. Judgment: All direct scored fields are correct; descriptive paraphrases are accepted where they preserve the function.

| Scored field | Weight | C | Truth content | v11 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Resolution" | "Resolution" |
| `field_description` | 0.0586 | 1.0 | "Sensor resolution selection." | "Resolution selection bits; POR default is +0.0625°C." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"+0.5°C (t_CONV = 30 ms typical)"},{"value":"01","value_description":"+0.25°C (t_CONV = 65 ms typical)"},{"value":"10","value_description":"+0.125°C (t_CONV = 130 ms typical)"},{"value":"11","value_description":"+0.0625°C (power-up default, t_CONV = 250 ms typical)"}] | [{"value":"00","value_description":"+0.5°C (tCONV = 30 ms typical)"},{"value":"01","value_description":"+0.25°C (tCONV = 65 ms typical)"},{"value":"10","value_description":"+0.125°C (tCONV = 130 ms typical)"},{"value":"11","value_description":"+0.0625°C (power-up default, tCONV = 250 ms typical)"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000) = **1.000000**. The field-part address, width, access type, and descriptive content are functionally correct; the general description is accepted.

| Field-part field | Weight | Correctness | Truth content | v11 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.0 | "Resolution" | "Resolution" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x08","decimal":"8","bank":"","page":"","description":""} | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"Register pointer 1000."} |
| `description` | 0.0693 | 1.0 | "" | "8-bit resolution selection register (only LSB at pointer 0x08)." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 1.000000 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. All direct logical-register fields are correct; descriptive expansions preserve the register function.

| Logical-register field | Weight | Correctness | Truth comparison target | v11 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "Resolution" | "Resolution" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":""}] | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":"Register pointer 1000; 8-bit Resolution register."}] |
| `register_description` | 0.0564 | 1.0 | "Allows the user to select the sensor temperature resolution from +0.5°C to +0.0625°C." | "8-bit register that selects the sensor resolution from +0.5°C to +0.0625°C (POR default +0.0625°C, tCONV = 250 ms typical); the selected resolution affects which TA LSBs remain cleared and the conversion time (Table 5-2, Section 5.2.4 Temperature Resolution). See Figure 5-8 for the write timing diagram." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 1.000000 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x03" | "0x03" |
| `default_value_description` | 0.0334 | 1.0 | "+0.0625°C resolution." | "POR default 0x03 (+0.0625°C resolution)." |

\(Q(L_{8})=( 0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## 2. Physical-register score summary

| Truth physical register | Address | Extracted logical register | q_R |
|---|---|---|---|
| `CONFIG` | `0x01` | `v11 registers[0]` (`CONFIG`) | 1.000000000 |
| `TUPPER` | `0x02` | `v11 registers[1]` (`TUPPER`) | 1.000000000 |
| `TLOWER` | `0x03` | `v11 registers[2]` (`TLOWER`) | 1.000000000 |
| `TCRIT` | `0x04` | `v11 registers[3]` (`TCRIT`) | 1.000000000 |
| `TA` | `0x05` | `v11 registers[4]` (`TA`) | 1.000000000 |
| `Manufacturer ID` | `0x06` | `v11 registers[5]` (`Manufacturer ID`) | 1.000000000 |
| `Device ID/Revision` | `0x07` | `v11 registers[6]` (`Device ID/Device Revision`) | 0.984569743 |
| `Resolution` | `0x08` | `v11 registers[7]` (`Resolution`) | 1.000000000 |

\(\sum_{R=1}^{8}q_R=\mathbf{7.984569743}\).

\[S_{final}=\left(\frac{10}{8}\times 7.984569743\right)\times\frac{8}{8+0}=\boxed{\mathbf{9.980712179/10}}\]

## 3. Detailed deduction inventory

1. `v11 registers[6].field_parts[0].register_name` vs `truth registers[6].field_parts[0].register_name`: `C=0.5`; truth="Device ID/Revision"; extracted="Device ID/Device Revision". The combined Device ID/Revision label differs from the truth label.
2. `v11 registers[6].name` vs `truth registers[6].name`: `C=0.5`; truth="Device ID/Revision"; extracted="Device ID/Device Revision". The logical-register combined name differs from truth.

Accepted reserved-bit representation notes:

- No special reserved-bit representation was needed.

The bottom-up tables above are exhaustive: all 8 logical registers, 8 field parts, 33 bit fields, and every scored field are shown.

## 4. Invented-field and structural check

- No unmatched truth physical-register entries; `m=8` and `x=0`, so the extra-register factor is `1.0`.
- No extra extracted physical register, logical register, field part, or bit field is present after physical-address and exact bit-range matching.
- category, index, is_multi_address, and source are excluded by AGENTS.md and do not affect the score.

