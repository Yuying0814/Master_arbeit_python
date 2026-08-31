# MCP9808 without detailed score — revised AGENTS.md rules

## 1. Scoring basis

- `n=8` truth physical registers are keyed by numeric address, bank, and page: `0x01` through `0x08`.
- `without` is associated to truth by numeric physical address; all `8` truth addresses are matched and there are `0` extra extracted physical addresses.
- Each matched logical register is calculated independently from the bottom up: truth bit fields → field part → logical register `Q(L)`.
- Bit fields are aligned by exact ordered `(bit_start, bit_end)` within the matched physical field part. All `33` truth bit-field ranges match exactly.
- Objective ranges, widths, access types, reserved flags, numeric addresses, default codes, and value codes are strict. Descriptive paraphrases are accepted only when they preserve the function; omissions of functional default/value information receive C=0.5.
- Reserved labels may be empty. In particular, every truth/extracted empty `type_write_read` pair for a reserved bit is explicitly scored C=1.0.

AHP weights used:

- logical register: `name` 0.0225, `physical_address` 0.4044, `register_description` 0.0564, `width_bits` 0.0590, `type_write_read` 0.0590, `field_parts` 0.2987, `default_value` 0.0667, `default_value_description` 0.0334; category is excluded.
- field part: `register_name` 0.0280, `physical_address` 0.4688, `description` 0.0693, `width_bits` 0.0605, `type_write_read` 0.0605, `bit_field` 0.3129.
- bit field: `name_or_parameter` 0.0212, `field_description` 0.0586, `bit_start` 0.2594, `bit_end` 0.2594, `bit_width` 0.0583, `values` 0.2097, `is_reserved` 0.0750, `type_write_read` 0.0583.

The rounded bit-field weights are normalized by `0.9999`; logical-register weights are normalized by `1.0001`; field-part weights sum to `1.0000`.

## Extracted logical register 1: `CONFIG`

`without` location: `registers[0]`; truth association: `truth registers[0]` (`CONFIG`).
Associated physical location: `0x01` (1).

### Bottom layer: bit fields, then field parts

#### Field part 1: `CONFIG` at `0x01` (1)

Locations: `truth registers[0].field_parts[0]` ↔ `without registers[0].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 11:15**

Locations: `truth registers[0].field_parts[0].bit_field[0]` ↔ `without registers[0].field_parts[0].bit_field[0]`.
Judgment: This is a reserved field. The empty `type_write_read` is present in both objects and is awarded C=1.0; it is not treated as an omitted score.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Unimplemented, read as '0'" |
| `bit_start` | 0.2594 | 1.0 | 11 | 11 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `T_HYST` bits 9:10**

Locations: `truth registers[0].field_parts[0].bit_field[1]` ↔ `without registers[0].field_parts[0].bit_field[1]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "T_HYST" | "T_HYST" |
| `field_description` | 0.0586 | 1.0 | "T_UPPER and T_LOWER limit hysteresis selection." | "Temperature hysteresis selection for T_UPPER/T_LOWER/T_CRIT" |
| `bit_start` | 0.2594 | 1.0 | 9 | 9 |
| `bit_end` | 0.2594 | 1.0 | 10 | 10 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"0°C (power-up default)"},{"value":"01","value_description":"+1.5°C"},{"value":"10","value_description":"+3.0°C"},{"value":"11","value_description":"+6.0°C"}] | [{"value":"00","value_description":"0°C (power-up default)"},{"value":"01","value_description":"+1.5°C"},{"value":"10","value_description":"+3.0°C"},{"value":"11","value_description":"+6.0°C"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `SHDN` bits 8:8**

Locations: `truth registers[0].field_parts[0].bit_field[2]` ↔ `without registers[0].field_parts[0].bit_field[2]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "SHDN" | "SHDN" |
| `field_description` | 0.0586 | 1.0 | "Shutdown Mode bit." | "Shutdown Mode bit" |
| `bit_start` | 0.2594 | 1.0 | 8 | 8 |
| `bit_end` | 0.2594 | 1.0 | 8 | 8 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Continuous conversion (power-up default)"},{"value":"1","value_description":"Shutdown (Low-Power mode)"}] | [{"value":"0","value_description":"Continuous conversion (power-up default)"},{"value":"1","value_description":"Shutdown (Low-Power mode)"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `Crit. Lock` bits 7:7**

Locations: `truth registers[0].field_parts[0].bit_field[3]` ↔ `without registers[0].field_parts[0].bit_field[3]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Crit. Lock" | "Crit. Lock" |
| `field_description` | 0.0586 | 1.0 | "T_CRIT Lock bit." | "T_CRIT Lock bit: when set, T_CRIT cannot be written" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Unlocked; T_CRIT register can be written (power-up default)"},{"value":"1","value_description":"Locked; T_CRIT register cannot be written"}] | [{"value":"0","value_description":"Unlocked; T_CRIT can be written (power-up default)"},{"value":"1","value_description":"Locked; T_CRIT cannot be written until POR/Reset"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 5: `Win. Lock` bits 6:6**

Locations: `truth registers[0].field_parts[0].bit_field[4]` ↔ `without registers[0].field_parts[0].bit_field[4]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Win. Lock" | "Win. Lock" |
| `field_description` | 0.0586 | 1.0 | "T_UPPER and T_LOWER Window Lock bit." | "T_UPPER and T_LOWER Window Lock bit: when set, T_UPPER/T_LOWER cannot be written" |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Unlocked; T_UPPER and T_LOWER registers can be written (power-up default)"},{"value":"1","value_description":"Locked; T_UPPER and T_LOWER registers cannot be written"}] | [{"value":"0","value_description":"Unlocked; T_UPPER and T_LOWER can be written (power-up default)"},{"value":"1","value_description":"Locked; T_UPPER and T_LOWER cannot be written until POR/Reset"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 6: `Int. Clear` bits 5:5**

Locations: `truth registers[0].field_parts[0].bit_field[5]` ↔ `without registers[0].field_parts[0].bit_field[5]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Int. Clear" | "Int. Clear" |
| `field_description` | 0.0586 | 1.0 | "Interrupt Clear bit." | "Interrupt Clear bit: write '1' to clear interrupt; reads back '0'" |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"No effect (power-up default)"},{"value":"1","value_description":"Clear interrupt output; when read, this bit returns to '0'"}] | [{"value":"0","value_description":"No effect (power-up default)"},{"value":"1","value_description":"Clear interrupt output; when read returns to '0'"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 7: `Alert Stat.` bits 4:4**

Locations: `truth registers[0].field_parts[0].bit_field[6]` ↔ `without registers[0].field_parts[0].bit_field[6]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Alert Stat." | "Alert Stat." |
| `field_description` | 0.0586 | 1.0 | "Alert Output Status bit." | "Alert Output Status bit: reflects asserted state of Alert output" |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Alert output is not asserted by the device (power-up default)"},{"value":"1","value_description":"Alert output is asserted as a comparator/Interrupt or critical temperature output"}] | [{"value":"0","value_description":"Alert output is not asserted (power-up default)"},{"value":"1","value_description":"Alert output is asserted by comparator/interrupt or critical output"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 8: `Alert Cnt.` bits 3:3**

Locations: `truth registers[0].field_parts[0].bit_field[7]` ↔ `without registers[0].field_parts[0].bit_field[7]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Alert Cnt." | "Alert Cnt." |
| `field_description` | 0.0586 | 1.0 | "Alert Output Control bit." | "Alert Output Control bit: enable/disable Alert output" |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Disabled (power-up default)"},{"value":"1","value_description":"Enabled"}] | [{"value":"0","value_description":"Disabled (power-up default)"},{"value":"1","value_description":"Enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 9: `Alert Sel.` bits 2:2**

Locations: `truth registers[0].field_parts[0].bit_field[8]` ↔ `without registers[0].field_parts[0].bit_field[8]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Alert Sel." | "Alert Sel." |
| `field_description` | 0.0586 | 1.0 | "Alert Output Select bit." | "Alert Output Select bit: choose alert for window or only critical" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Alert output for T_UPPER, T_LOWER and T_CRIT (power-up default)"},{"value":"1","value_description":"T_A > T_CRIT only; T_UPPER and T_LOWER boundaries are disabled"}] | [{"value":"0","value_description":"Alert for T_UPPER, T_LOWER and T_CRIT (power-up default)"},{"value":"1","value_description":"T_A > T_CRIT only (T_UPPER and T_LOWER disabled)"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 10: `Alert Pol.` bits 1:1**

Locations: `truth registers[0].field_parts[0].bit_field[9]` ↔ `without registers[0].field_parts[0].bit_field[9]`.
Judgment: The value codes and active-low/active-high meanings are correct, but the active-low description omits the truth's functional pull-up-resistor requirement; `values` is therefore partial (C=0.5).

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Alert Pol." | "Alert Pol." |
| `field_description` | 0.0586 | 1.0 | "Alert Output Polarity bit." | "Alert Output Polarity bit" |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.5 | [{"value":"0","value_description":"Active-low (power-up default; pull-up resistor required)"},{"value":"1","value_description":"Active-high"}] | [{"value":"0","value_description":"Active-low (power-up default)"},{"value":"1","value_description":"Active-high"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.5 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.895050/0.9999=\mathbf{0.895140}\).

**Truth bit field 11: `Alert Mod.` bits 0:0**

Locations: `truth registers[0].field_parts[0].bit_field[10]` ↔ `without registers[0].field_parts[0].bit_field[10]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Alert Mod." | "Alert Mod." |
| `field_description` | 0.0586 | 1.0 | "Alert Output Mode bit." | "Alert Output Mode bit" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Comparator output (power-up default)"},{"value":"1","value_description":"Interrupt output"}] | [{"value":"0","value_description":"Comparator output (power-up default)"},{"value":"1","value_description":"Interrupt output"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 0.895140, 1.000000) = **0.990467**. The numeric address together with bank/page, width, access type, and all bit-field ranges are correct. The added address/field description is general, functionally consistent context and is accepted.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "CONFIG" | "CONFIG" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":""} | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"Configuration register (upper and lower byte)"} |
| `description` | 0.0693 | 1.0 | "" | "Configuration register (MSB:bits15:8, LSB:bits7:0)" |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.990467 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.990467=\mathbf{0.997017}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.997017) = **0.997017**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "CONFIG" | "CONFIG" |
| `physical_address` | 0.4044 | 1.0 | [[{"hex":"0x01","decimal":"1","bank":"","page":"","description":""}]] | [[{"hex":"0x01","decimal":"1","bank":"","page":"","description":"Configuration register address (16-bit, accessed as two bytes)"}]] |
| `register_description` | 0.0564 | 1.0 | "16-bit configuration register for temperature alert hysteresis, shutdown mode, temperature-limit locks, and Alert output configuration." | "16-bit configuration register to control device operation: hysteresis, shutdown/continuous conversion, lock bits, interrupt/alert behavior and polarity." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.997017 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 0.5 | "Comparator mode, active-low Alert and Critical output, output disabled, Alert not asserted, interrupt cleared, limits unlocked, continuous conversion, and 0°C hysteresis." | "Power-on default (Comparator mode, Active-Low, Output Disabled, Interrupt cleared, Limits unlocked, Continuous conversion, 0°C hysteresis) " |

\(Q(L_{1})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.997017 + 0.0667×1.0 + 0.0334×0.5)/1.0001=0.982509/1.0001=\mathbf{0.982411}\).

## Extracted logical register 2: `TUPPER`

`without` location: `registers[1]`; truth association: `truth registers[1]` (`TUPPER`).
Associated physical location: `0x02` (2).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TUPPER` at `0x02` (2)

Locations: `truth registers[1].field_parts[0]` ↔ `without registers[1].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 13:15**

Locations: `truth registers[1].field_parts[0].bit_field[0]` ↔ `without registers[1].field_parts[0].bit_field[0]`.
Judgment: This is a reserved field. The empty `type_write_read` is present in both objects and is awarded C=1.0; it is not treated as an omitted score.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Unimplemented, read as '0'" |
| `bit_start` | 0.2594 | 1.0 | 13 | 13 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `Sign` bits 12:12**

Locations: `truth registers[1].field_parts[0].bit_field[1]` ↔ `without registers[1].field_parts[0].bit_field[1]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Sign" | "Sign" |
| `field_description` | 0.0586 | 1.0 | "Sign bit." | "Sign bit: 0 = TA ≥ 0°C; 1 = TA < 0°C" |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 12 | 12 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}] | [{"value":"0","value_description":"TA ≥ 0°C"},{"value":"1","value_description":"TA < 0°C"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `TUPPER` bits 2:11**

Locations: `truth registers[1].field_parts[0].bit_field[2]` ↔ `without registers[1].field_parts[0].bit_field[2]`.
Judgment: The extracted label appends the explicit bit slice to the canonical parameter name; the separate range fields are exact, but the label itself is not identical, so `name_or_parameter` is partial (C=0.5).

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.5 | "TUPPER" | "TUPPER[11:2]" |
| `field_description` | 0.0586 | 1.0 | "Upper temperature boundary trip data in two's complement format." | "Temperature boundary bits (two's complement, 0.25°C LSB)" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 11 | 11 |
| `bit_width` | 0.0583 | 1.0 | 10 | 10 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×0.5 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.989300/0.9999=\mathbf{0.989399}\).

**Truth bit field 4: `Unimplemented` bits 0:1**

Locations: `truth registers[1].field_parts[0].bit_field[3]` ↔ `without registers[1].field_parts[0].bit_field[3]`.
Judgment: This is a reserved field. The empty `type_write_read` is present in both objects and is awarded C=1.0; it is not treated as an omitted score.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Unimplemented, read as '0'" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 0.989399, 1.000000) = **0.997350**. The numeric address together with bank/page, width, access type, and all bit-field ranges are correct. The added address/field description is general, functionally consistent context and is accepted.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "TUPPER" | "TUPPER" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x02","decimal":"2","bank":"","page":"","description":""} | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"T_UPPER register (MSB and LSB)"} |
| `description` | 0.0693 | 1.0 | "" | "Upper boundary temperature register (two's complement, 0.25°C LSB)" |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.997350 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.997350=\mathbf{0.999171}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.999171) = **0.999171**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "TUPPER" | "TUPPER" |
| `physical_address` | 0.4044 | 1.0 | [[{"hex":"0x02","decimal":"2","bank":"","page":"","description":""}]] | [[{"hex":"0x02","decimal":"2","bank":"","page":"","description":"Temperature Upper Boundary register address (16-bit)"}]] |
| `register_description` | 0.0564 | 1.0 | "16-bit read/write Alert Output Temperature Upper Boundary register containing 11-bit temperature data in two's complement format with 0.25°C resolution." | "16-bit read/write temperature Alert Upper Boundary register (two's complement, 0.25°C resolution). Asserting T_A > TUPPER can trigger Alert when enabled." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.999171 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "0°C" | "Power-on default = 0x0000 (0°C)" |

\(Q(L_{2})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.999171 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.999852/1.0001=\mathbf{0.999752}\).

## Extracted logical register 3: `TLOWER`

`without` location: `registers[2]`; truth association: `truth registers[2]` (`TLOWER`).
Associated physical location: `0x03` (3).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TLOWER` at `0x03` (3)

Locations: `truth registers[2].field_parts[0]` ↔ `without registers[2].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 13:15**

Locations: `truth registers[2].field_parts[0].bit_field[0]` ↔ `without registers[2].field_parts[0].bit_field[0]`.
Judgment: This is a reserved field. The empty `type_write_read` is present in both objects and is awarded C=1.0; it is not treated as an omitted score.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Unimplemented, read as '0'" |
| `bit_start` | 0.2594 | 1.0 | 13 | 13 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `Sign` bits 12:12**

Locations: `truth registers[2].field_parts[0].bit_field[1]` ↔ `without registers[2].field_parts[0].bit_field[1]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Sign" | "Sign" |
| `field_description` | 0.0586 | 1.0 | "Sign bit." | "Sign bit: 0 = TA ≥ 0°C; 1 = TA < 0°C" |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 12 | 12 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}] | [{"value":"0","value_description":"TA ≥ 0°C"},{"value":"1","value_description":"TA < 0°C"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `TLOWER` bits 2:11**

Locations: `truth registers[2].field_parts[0].bit_field[2]` ↔ `without registers[2].field_parts[0].bit_field[2]`.
Judgment: The extracted label appends the explicit bit slice to the canonical parameter name; the separate range fields are exact, but the label itself is not identical, so `name_or_parameter` is partial (C=0.5).

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.5 | "TLOWER" | "TLOWER[11:2]" |
| `field_description` | 0.0586 | 1.0 | "Lower temperature boundary trip data in two's complement format." | "Temperature boundary bits (two's complement, 0.25°C LSB)" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 11 | 11 |
| `bit_width` | 0.0583 | 1.0 | 10 | 10 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×0.5 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.989300/0.9999=\mathbf{0.989399}\).

**Truth bit field 4: `Unimplemented` bits 0:1**

Locations: `truth registers[2].field_parts[0].bit_field[3]` ↔ `without registers[2].field_parts[0].bit_field[3]`.
Judgment: This is a reserved field. The empty `type_write_read` is present in both objects and is awarded C=1.0; it is not treated as an omitted score.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Unimplemented, read as '0'" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 0.989399, 1.000000) = **0.997350**. The numeric address together with bank/page, width, access type, and all bit-field ranges are correct. The added address/field description is general, functionally consistent context and is accepted.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "TLOWER" | "TLOWER" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x03","decimal":"3","bank":"","page":"","description":""} | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"T_LOWER register (MSB and LSB)"} |
| `description` | 0.0693 | 1.0 | "" | "Lower boundary temperature register (two's complement, 0.25°C LSB)" |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.997350 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.997350=\mathbf{0.999171}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.999171) = **0.999171**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "TLOWER" | "TLOWER" |
| `physical_address` | 0.4044 | 1.0 | [[{"hex":"0x03","decimal":"3","bank":"","page":"","description":""}]] | [[{"hex":"0x03","decimal":"3","bank":"","page":"","description":"Temperature Lower Boundary register address (16-bit)"}]] |
| `register_description` | 0.0564 | 1.0 | "16-bit read/write Lower Boundary register containing 11-bit temperature data in two's complement format with 0.25°C resolution." | "16-bit read/write temperature Alert Lower Boundary register (two's complement, 0.25°C resolution). Assert when T_A < TLOWER if enabled." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.999171 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "0°C" | "Power-on default = 0x0000 (0°C)" |

\(Q(L_{3})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.999171 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.999852/1.0001=\mathbf{0.999752}\).

## Extracted logical register 4: `TCRIT`

`without` location: `registers[3]`; truth association: `truth registers[3]` (`TCRIT`).
Associated physical location: `0x04` (4).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TCRIT` at `0x04` (4)

Locations: `truth registers[3].field_parts[0]` ↔ `without registers[3].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 13:15**

Locations: `truth registers[3].field_parts[0].bit_field[0]` ↔ `without registers[3].field_parts[0].bit_field[0]`.
Judgment: This is a reserved field. The empty `type_write_read` is present in both objects and is awarded C=1.0; it is not treated as an omitted score.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Unimplemented, read as '0'" |
| `bit_start` | 0.2594 | 1.0 | 13 | 13 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `Sign` bits 12:12**

Locations: `truth registers[3].field_parts[0].bit_field[1]` ↔ `without registers[3].field_parts[0].bit_field[1]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Sign" | "Sign" |
| `field_description` | 0.0586 | 1.0 | "Sign bit." | "Sign bit: 0 = TA ≥ 0°C; 1 = TA < 0°C" |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 12 | 12 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}] | [{"value":"0","value_description":"TA ≥ 0°C"},{"value":"1","value_description":"TA < 0°C"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `TCRIT` bits 2:11**

Locations: `truth registers[3].field_parts[0].bit_field[2]` ↔ `without registers[3].field_parts[0].bit_field[2]`.
Judgment: The extracted label appends the explicit bit slice to the canonical parameter name; the separate range fields are exact, but the label itself is not identical, so `name_or_parameter` is partial (C=0.5).

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.5 | "TCRIT" | "TCRIT[11:2]" |
| `field_description` | 0.0586 | 1.0 | "Critical temperature boundary trip data in two's complement format." | "Critical temperature boundary bits (two's complement, 0.25°C LSB)" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 11 | 11 |
| `bit_width` | 0.0583 | 1.0 | 10 | 10 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×0.5 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.989300/0.9999=\mathbf{0.989399}\).

**Truth bit field 4: `Unimplemented` bits 0:1**

Locations: `truth registers[3].field_parts[0].bit_field[3]` ↔ `without registers[3].field_parts[0].bit_field[3]`.
Judgment: This is a reserved field. The empty `type_write_read` is present in both objects and is awarded C=1.0; it is not treated as an omitted score.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Unimplemented, read as '0'" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 0.989399, 1.000000) = **0.997350**. The numeric address together with bank/page, width, access type, and all bit-field ranges are correct. The added address/field description is general, functionally consistent context and is accepted.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "TCRIT" | "TCRIT" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x04","decimal":"4","bank":"","page":"","description":""} | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"T_CRIT register (MSB and LSB)"} |
| `description` | 0.0693 | 1.0 | "" | "Critical temperature limit register (two's complement, 0.25°C LSB)" |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.997350 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.997350=\mathbf{0.999171}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.999171) = **0.999171**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "TCRIT" | "TCRIT" |
| `physical_address` | 0.4044 | 1.0 | [[{"hex":"0x04","decimal":"4","bank":"","page":"","description":""}]] | [[{"hex":"0x04","decimal":"4","bank":"","page":"","description":"Critical Temperature Limit register address (16-bit)"}]] |
| `register_description` | 0.0564 | 1.0 | "16-bit read/write Critical Boundary register containing 11-bit temperature data in two's complement format with 0.25°C resolution." | "16-bit read/write critical temperature limit register (two's complement, 0.25°C resolution). When TA ≥ T_CRIT Alert is forced to comparator mode." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.999171 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "0°C" | "Power-on default = 0x0000 (0°C)" |

\(Q(L_{4})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.999171 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.999852/1.0001=\mathbf{0.999752}\).

## Extracted logical register 5: `TA`

`without` location: `registers[4]`; truth association: `truth registers[4]` (`TA`).
Associated physical location: `0x05` (5).

### Bottom layer: bit fields, then field parts

#### Field part 1: `TA` at `0x05` (5)

Locations: `truth registers[4].field_parts[0]` ↔ `without registers[4].field_parts[0]`.

**Truth bit field 1: `TA vs. TCRIT` bits 15:15**

Locations: `truth registers[4].field_parts[0].bit_field[0]` ↔ `without registers[4].field_parts[0].bit_field[0]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "TA vs. TCRIT" | "TA vs. TCRIT" |
| `field_description` | 0.0586 | 1.0 | "Indicates whether ambient temperature is at or above the critical limit." | "Flag: set to '1' if TA ≥ T_CRIT" |
| `bit_start` | 0.2594 | 1.0 | 15 | 15 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A < T_CRIT"},{"value":"1","value_description":"T_A ≥ T_CRIT"}] | [{"value":"0","value_description":"TA < T_CRIT"},{"value":"1","value_description":"TA ≥ T_CRIT"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `TA vs. TUPPER` bits 14:14**

Locations: `truth registers[4].field_parts[0].bit_field[1]` ↔ `without registers[4].field_parts[0].bit_field[1]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "TA vs. TUPPER" | "TA vs. TUPPER" |
| `field_description` | 0.0586 | 1.0 | "Indicates whether ambient temperature is above the upper boundary." | "Flag: set to '1' if TA > T_UPPER" |
| `bit_start` | 0.2594 | 1.0 | 14 | 14 |
| `bit_end` | 0.2594 | 1.0 | 14 | 14 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A ≤ T_UPPER"},{"value":"1","value_description":"T_A > T_UPPER"}] | [{"value":"0","value_description":"TA ≤ T_UPPER"},{"value":"1","value_description":"TA > T_UPPER"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 3: `TA vs. TLOWER` bits 13:13**

Locations: `truth registers[4].field_parts[0].bit_field[2]` ↔ `without registers[4].field_parts[0].bit_field[2]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "TA vs. TLOWER" | "TA vs. TLOWER" |
| `field_description` | 0.0586 | 1.0 | "Indicates whether ambient temperature is below the lower boundary." | "Flag: set to '1' if TA < T_LOWER" |
| `bit_start` | 0.2594 | 1.0 | 13 | 13 |
| `bit_end` | 0.2594 | 1.0 | 13 | 13 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A ≥ T_LOWER"},{"value":"1","value_description":"T_A < T_LOWER"}] | [{"value":"0","value_description":"TA ≥ T_LOWER"},{"value":"1","value_description":"TA < T_LOWER"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 4: `SIGN` bits 12:12**

Locations: `truth registers[4].field_parts[0].bit_field[3]` ↔ `without registers[4].field_parts[0].bit_field[3]`.
Judgment: The extracted field name differs only in capitalization from the canonical truth label; the name is partial (C=0.5), while all objective field facts are correct.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.5 | "SIGN" | "Sign" |
| `field_description` | 0.0586 | 1.0 | "Ambient temperature sign bit." | "Sign bit for temperature: 0 = TA ≥ 0°C; 1 = TA < 0°C" |
| `bit_start` | 0.2594 | 1.0 | 12 | 12 |
| `bit_end` | 0.2594 | 1.0 | 12 | 12 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}] | [{"value":"0","value_description":"TA ≥ 0°C"},{"value":"1","value_description":"TA < 0°C"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×0.5 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.989300/0.9999=\mathbf{0.989399}\).

**Truth bit field 5: `TA` bits 0:11**

Locations: `truth registers[4].field_parts[0].bit_field[4]` ↔ `without registers[4].field_parts[0].bit_field[4]`.
Judgment: The extracted label appends the explicit bit slice to the canonical parameter name; the separate range fields are exact, but the label itself is not identical, so `name_or_parameter` is partial (C=0.5).

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.5 | "TA" | "TA[11:0]" |
| `field_description` | 0.0586 | 1.0 | "12-bit ambient temperature data in two's complement format." | "12-bit ambient temperature data (two's complement). Lower fractional bits may be unused depending on resolution." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 11 | 11 |
| `bit_width` | 0.0583 | 1.0 | 12 | 12 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×0.5 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.989300/0.9999=\mathbf{0.989399}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 1.000000, 0.989399, 0.989399) = **0.995760**. The numeric address together with bank/page, width, access type, and all bit-field ranges are correct. The added address/field description is general, functionally consistent context and is accepted.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "TA" | "TA" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x05","decimal":"5","bank":"","page":"","description":""} | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Ambient Temperature register (MSB and LSB)"} |
| `description` | 0.0693 | 1.0 | "" | "Ambient Temperature register with alert/status flags and temperature data" |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.995760 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×0.995760=\mathbf{0.998673}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.998673) = **0.998673**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "TA" | "TA" |
| `physical_address` | 0.4044 | 1.0 | [[{"hex":"0x05","decimal":"5","bank":"","page":"","description":""}]] | [[{"hex":"0x05","decimal":"5","bank":"","page":"","description":"Ambient Temperature register address (16-bit, read-only)"}]] |
| `register_description` | 0.0564 | 1.0 | "Double-buffered 16-bit read-only Ambient Temperature register containing 13-bit two's-complement temperature data and three Alert boundary-status bits; updated at the conversion refresh rate." | "16-bit read-only Ambient Temperature register. Contains TA flags (bits15:13) and 12-bit two's complement temperature data (bits11:0). Updated every tCONV; double-buffered." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.998673 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "0°C" | "Power-on default = 0x0000 (0°C)" |

\(Q(L_{5})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.998673 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.999704/1.0001=\mathbf{0.999604}\).

## Extracted logical register 6: `Manufacturer ID`

`without` location: `registers[5]`; truth association: `truth registers[5]` (`Manufacturer ID`).
Associated physical location: `0x06` (6).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Manufacturer ID` at `0x06` (6)

Locations: `truth registers[5].field_parts[0]` ↔ `without registers[5].field_parts[0]`.

**Truth bit field 1: `Manufacturer ID` bits 0:15**

Locations: `truth registers[5].field_parts[0].bit_field[0]` ↔ `without registers[5].field_parts[0].bit_field[0]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Manufacturer ID" | "Manufacturer ID" |
| `field_description` | 0.0586 | 1.0 | "Device Manufacturer Identification bits." | "Device Manufacturer Identification bits" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 16 | 16 |
| `values` | 0.2097 | 1.0 | [{"value":"0x0054","value_description":"Manufacturer ID for the MCP9808"}] | [{"value":"0x0054","value_description":"Manufacturer ID for MCP9808 (hexadecimal)"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**. The numeric address together with bank/page, width, access type, and all bit-field ranges are correct. The added address/field description is general, functionally consistent context and is accepted.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "Manufacturer ID" | "Manufacturer ID" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x06","decimal":"6","bank":"","page":"","description":""} | {"hex":"0x06","decimal":"6","bank":"","page":"","description":"Manufacturer ID register (MSB and LSB)"} |
| `description` | 0.0693 | 1.0 | "" | "Manufacturer identification (16-bit)" |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 1.000000 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "Manufacturer ID" | "Manufacturer ID" |
| `physical_address` | 0.4044 | 1.0 | [[{"hex":"0x06","decimal":"6","bank":"","page":"","description":""}]] | [[{"hex":"0x06","decimal":"6","bank":"","page":"","description":"Manufacturer ID register address (16-bit, read-only)"}]] |
| `register_description` | 0.0564 | 1.0 | "Read-only register used to identify the device manufacturer for manufacturer-specific operation." | "16-bit read-only Manufacturer Identification register. Manufacturer ID for MCP9808 is 0x0054." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 1.000000 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0054" | "0x0054" |
| `default_value_description` | 0.0334 | 0.5 | "Manufacturer ID for the MCP9808." | "Manufacturer ID (hex)" |

\(Q(L_{6})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.000000 + 0.0667×1.0 + 0.0334×0.5)/1.0001=0.983400/1.0001=\mathbf{0.983302}\).

## Extracted logical register 7: `Device ID/Device Revision`

`without` location: `registers[6]`; truth association: `truth registers[6]` (`Device ID/Revision`).
Associated physical location: `0x07` (7).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Device ID/Device Revision` at `0x07` (7)

Locations: `truth registers[6].field_parts[0]` ↔ `without registers[6].field_parts[0]`.

**Truth bit field 1: `Device ID` bits 8:15**

Locations: `truth registers[6].field_parts[0].bit_field[0]` ↔ `without registers[6].field_parts[0].bit_field[0]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Device ID" | "Device ID" |
| `field_description` | 0.0586 | 1.0 | "Device identification bits." | "Device identification bits (upper byte)" |
| `bit_start` | 0.2594 | 1.0 | 8 | 8 |
| `bit_end` | 0.2594 | 1.0 | 15 | 15 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [{"value":"0x04","value_description":"Device ID for the MCP9808"}] | [{"value":"0x04","value_description":"Device ID for MCP9808 (hex)"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `Device Revision` bits 0:7**

Locations: `truth registers[6].field_parts[0].bit_field[1]` ↔ `without registers[6].field_parts[0].bit_field[1]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Device Revision" | "Device Revision" |
| `field_description` | 0.0586 | 1.0 | "Device revision bits." | "Device revision (lower byte)" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [{"value":"0x00","value_description":"First release revision; incremented for revised versions"}] | [{"value":"0x00","value_description":"Revision 0 (first release POR default)"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000) = **1.000000**. The physical address, width, access type, and bit-field collection are correct. Only the combined Device ID/Revision label differs from the canonical truth label, so `register_name` is partial (C=0.5).

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 0.5 | "Device ID/Revision" | "Device ID/Device Revision" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} | {"hex":"0x07","decimal":"7","bank":"","page":"","description":"Device ID (MSB) and Device Revision (LSB)"} |
| `description` | 0.0693 | 1.0 | "" | "Device identification (upper byte) and device revision (lower byte)" |
| `width_bits` | 0.0605 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 1.000000 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×0.5 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.000000=\mathbf{0.986000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.986000) = **0.986000**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 0.5 | "Device ID/Revision" | "Device ID/Device Revision" |
| `physical_address` | 0.4044 | 1.0 | [[{"hex":"0x07","decimal":"7","bank":"","page":"","description":""}]] | [[{"hex":"0x07","decimal":"7","bank":"","page":"","description":"Device ID and Revision register address (16-bit, read-only)"}]] |
| `register_description` | 0.0564 | 1.0 | "Read-only register whose upper byte specifies the device identification and lower byte specifies the device revision." | "16-bit read-only register: upper byte is Device ID (0x04 for MCP9808), lower byte is Device Revision (POR default 0x00)." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.986000 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0400" | "0x0400" |
| `default_value_description` | 0.0334 | 1.0 | "Device ID 0x04 and initial device revision 0x00." | "Power-on default = 0x0400 (Device ID 0x04, Revision 0x00)" |

\(Q(L_{7})=(0.0225×0.5 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×0.986000 + 0.0667×1.0 + 0.0334×1.0)/1.0001=0.984668/1.0001=\mathbf{0.984570}\).

## Extracted logical register 8: `Resolution`

`without` location: `registers[7]`; truth association: `truth registers[7]` (`Resolution`).
Associated physical location: `0x08` (8).

### Bottom layer: bit fields, then field parts

#### Field part 1: `Resolution` at `0x08` (8)

Locations: `truth registers[7].field_parts[0]` ↔ `without registers[7].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 2:7**

Locations: `truth registers[7].field_parts[0].bit_field[0]` ↔ `without registers[7].field_parts[0].bit_field[0]`.
Judgment: This is a reserved field. The empty `type_write_read` is present in both objects and is awarded C=1.0; it is not treated as an omitted score.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 1.0 | "Unimplemented; read as '0'." | "Unimplemented, read as '0'" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Truth bit field 2: `Resolution` bits 0:1**

Locations: `truth registers[7].field_parts[0].bit_field[1]` ↔ `without registers[7].field_parts[0].bit_field[1]`.
Judgment: All objective range, width, reserved/access, and value-code facts are correct. Descriptive wording is a functionally equivalent paraphrase or accurate additional context.

| Scored field | Weight | C | Truth content | without content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Resolution" | "Resolution" |
| `field_description` | 0.0586 | 1.0 | "Sensor resolution selection." | "Resolution bits" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"00","value_description":"+0.5°C (t_CONV = 30 ms typical)"},{"value":"01","value_description":"+0.25°C (t_CONV = 65 ms typical)"},{"value":"10","value_description":"+0.125°C (t_CONV = 130 ms typical)"},{"value":"11","value_description":"+0.0625°C (power-up default, t_CONV = 250 ms typical)"}] | [{"value":"00","value_description":"+0.5°C (tCONV = 30 ms typical)"},{"value":"01","value_description":"+0.25°C (tCONV = 65 ms typical)"},{"value":"10","value_description":"+0.125°C (tCONV = 130 ms typical)"},{"value":"11","value_description":"+0.0625°C (power-up default, tCONV = 250 ms typical)"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.0 + 0.0586×1.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×1.0 + 0.0750×1.0 + 0.0583×1.0)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000) = **1.000000**. The numeric address together with bank/page, width, access type, and all bit-field ranges are correct. The added address/field description is general, functionally consistent context and is accepted.

| Field-part field | Weight | Correctness | Truth content | without content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "Resolution" | "Resolution" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x08","decimal":"8","bank":"","page":"","description":""} | {"hex":"0x08","decimal":"8","bank":"","page":"","description":"Resolution register (LSB)"} |
| `description` | 0.0693 | 1.0 | "" | "Resolution selection (bits1:0), bits7:2 unimplemented (read as 0)" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 1.000000 | "truth bit-field set" | "matched/extracted bit-field set" |

\(Q_{FP}=0.0280×1.0 + 0.4688×1.0 + 0.0693×1.0 + 0.0605×1.0 + 0.0605×1.0 + 0.3129×1.000000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**.

| Logical-register field | Weight | Correctness | Truth comparison target | without content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "Resolution" | "Resolution" |
| `physical_address` | 0.4044 | 1.0 | [[{"hex":"0x08","decimal":"8","bank":"","page":"","description":""}]] | [[{"hex":"0x08","decimal":"8","bank":"","page":"","description":"Resolution register address (8-bit LSB)"}]] |
| `register_description` | 0.0564 | 1.0 | "Allows the user to select the sensor temperature resolution from +0.5°C to +0.0625°C." | "8-bit Resolution register controlling measurement resolution and conversion time. POR default = 0x03 (+0.0625°C resolution)." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 1.000000 | "corresponding truth field-part collection" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x03" | "0x03" |
| `default_value_description` | 0.0334 | 1.0 | "+0.0625°C resolution." | "Power-up default = 0x03 (+0.0625°C resolution)" |

\(Q(L_{8})=(0.0225×1.0 + 0.4044×1.0 + 0.0564×1.0 + 0.0590×1.0 + 0.0590×1.0 + 0.2987×1.000000 + 0.0667×1.0 + 0.0334×1.0)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

## 2. Physical-register score summary

| Truth physical register | Address | Extracted logical register | q_R |
|---|---:|---|---:|
| `CONFIG` | `0x01` | `without registers[0]` (`CONFIG`) | 0.982410795 |
| `TUPPER` | `0x02` | `without registers[1]` (`TUPPER`) | 0.999752322 |
| `TLOWER` | `0x03` | `without registers[2]` (`TLOWER`) | 0.999752322 |
| `TCRIT` | `0x04` | `without registers[3]` (`TCRIT`) | 0.999752322 |
| `TA` | `0x05` | `without registers[4]` (`TA`) | 0.999603716 |
| `Manufacturer ID` | `0x06` | `without registers[5]` (`Manufacturer ID`) | 0.983301670 |
| `Device ID/Revision` | `0x07` | `without registers[6]` (`Device ID/Device Revision`) | 0.984569743 |
| `Resolution` | `0x08` | `without registers[7]` (`Resolution`) | 1.000000000 |

\(\sum_{R=1}^{8}q_R=\mathbf{7.949142891}\).

\[S_{final}=\left(\frac{10}{8}\times 7.949142891\right)\times\frac{8}{8+0}=\boxed{\mathbf{9.936428614/10}}\]

## 3. Detailed deduction inventory

1. `without registers[0].default_value_description` vs `truth registers[0].default_value_description`: `C=0.5`; truth="Comparator mode, active-low Alert and Critical output, output disabled, Alert not asserted, interrupt cleared, limits unlocked, continuous conversion, and 0°C hysteresis."; extracted="Power-on default (Comparator mode, Active-Low, Output Disabled, Interrupt cleared, Limits unlocked, Continuous conversion, 0°C hysteresis) ". The default description omits the truth's Alert-not-asserted and Critical-output details; it is incomplete, so C=0.5.
2. `without registers[0].field_parts[0].bit_field[9].values` vs `truth registers[0].field_parts[0].bit_field[9].values`: `C=0.5`; truth=[{"value":"0","value_description":"Active-low (power-up default; pull-up resistor required)"},{"value":"1","value_description":"Active-high"}]; extracted=[{"value":"0","value_description":"Active-low (power-up default)"},{"value":"1","value_description":"Active-high"}]. The value codes and active-low/active-high meanings are correct, but the active-low description omits the truth's functional pull-up-resistor requirement; `values` is therefore partial (C=0.5).
3. `without registers[1].field_parts[0].bit_field[2].name_or_parameter` vs `truth registers[1].field_parts[0].bit_field[2].name_or_parameter`: `C=0.5`; truth="TUPPER"; extracted="TUPPER[11:2]". The extracted label appends the explicit bit slice to the canonical parameter name; the separate range fields are exact, but the label itself is not identical, so `name_or_parameter` is partial (C=0.5).
4. `without registers[2].field_parts[0].bit_field[2].name_or_parameter` vs `truth registers[2].field_parts[0].bit_field[2].name_or_parameter`: `C=0.5`; truth="TLOWER"; extracted="TLOWER[11:2]". The extracted label appends the explicit bit slice to the canonical parameter name; the separate range fields are exact, but the label itself is not identical, so `name_or_parameter` is partial (C=0.5).
5. `without registers[3].field_parts[0].bit_field[2].name_or_parameter` vs `truth registers[3].field_parts[0].bit_field[2].name_or_parameter`: `C=0.5`; truth="TCRIT"; extracted="TCRIT[11:2]". The extracted label appends the explicit bit slice to the canonical parameter name; the separate range fields are exact, but the label itself is not identical, so `name_or_parameter` is partial (C=0.5).
6. `without registers[4].field_parts[0].bit_field[3].name_or_parameter` vs `truth registers[4].field_parts[0].bit_field[3].name_or_parameter`: `C=0.5`; truth="SIGN"; extracted="Sign". The extracted field name differs only in capitalization from the canonical truth label; the name is partial (C=0.5), while all objective field facts are correct.
7. `without registers[4].field_parts[0].bit_field[4].name_or_parameter` vs `truth registers[4].field_parts[0].bit_field[4].name_or_parameter`: `C=0.5`; truth="TA"; extracted="TA[11:0]". The extracted label appends the explicit bit slice to the canonical parameter name; the separate range fields are exact, but the label itself is not identical, so `name_or_parameter` is partial (C=0.5).
8. `without registers[5].default_value_description` vs `truth registers[5].default_value_description`: `C=0.5`; truth="Manufacturer ID for the MCP9808."; extracted="Manufacturer ID (hex)". The text says only Manufacturer ID (hex) and omits the actual MCP9808 default identification value; it is incomplete, so C=0.5.
9. `without registers[6].name` vs `truth registers[6].name`: `C=0.5`; truth="Device ID/Revision"; extracted="Device ID/Device Revision". The register is correctly identified, but the canonical combined name differs, so C=0.5.
10. `without registers[6].field_parts[0].register_name` vs `truth registers[6].field_parts[0].register_name`: `C=0.5`; truth="Device ID/Revision"; extracted="Device ID/Device Revision". The physical address, width, access type, and bit-field collection are correct. Only the combined Device ID/Revision label differs from the canonical truth label, so `register_name` is partial (C=0.5).

### Explicit empty `type_write_read` audit

Found `8` truth/extracted empty pairs. Each is a reserved bit and each was credited, not skipped:

- `truth registers[0].field_parts[0].bit_field[0]` ↔ `without registers[0].field_parts[0].bit_field[0]` (bits 11:15): both values are `""`, and `type_write_read` receives C=1.0.
- `truth registers[1].field_parts[0].bit_field[0]` ↔ `without registers[1].field_parts[0].bit_field[0]` (bits 13:15): both values are `""`, and `type_write_read` receives C=1.0.
- `truth registers[1].field_parts[0].bit_field[3]` ↔ `without registers[1].field_parts[0].bit_field[3]` (bits 0:1): both values are `""`, and `type_write_read` receives C=1.0.
- `truth registers[2].field_parts[0].bit_field[0]` ↔ `without registers[2].field_parts[0].bit_field[0]` (bits 13:15): both values are `""`, and `type_write_read` receives C=1.0.
- `truth registers[2].field_parts[0].bit_field[3]` ↔ `without registers[2].field_parts[0].bit_field[3]` (bits 0:1): both values are `""`, and `type_write_read` receives C=1.0.
- `truth registers[3].field_parts[0].bit_field[0]` ↔ `without registers[3].field_parts[0].bit_field[0]` (bits 13:15): both values are `""`, and `type_write_read` receives C=1.0.
- `truth registers[3].field_parts[0].bit_field[3]` ↔ `without registers[3].field_parts[0].bit_field[3]` (bits 0:1): both values are `""`, and `type_write_read` receives C=1.0.
- `truth registers[7].field_parts[0].bit_field[0]` ↔ `without registers[7].field_parts[0].bit_field[0]` (bits 2:7): both values are `""`, and `type_write_read` receives C=1.0.

### Structural and coverage check

- Truth physical registers: `8`; matched: `m=8`; extra extracted physical addresses: `x=0`.
- Missing truth addresses: `[]`; extra extracted addresses: `[]`.
- Bottom-up coverage: `8` logical registers, `8` field parts, and `33` bit fields.
- No extra logical register, field part, or bit field is present after physical-address and exact ordered bit-range matching.
- `category`, `index`, `is_multi_address`, and `source` are excluded by AGENTS.md and do not affect the score.
