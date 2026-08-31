# MCP9808 v12.0 detailed score — revised AGENTS.md rules

## 1. Scoring basis

- `n=8` truth physical registers are keyed by numeric address, bank, and page: `0x01` through `0x08`.
- Primary matching associates each truth physical register with the v12 logical register whose first physical-address entry has the same numeric key. This gives `m=8` matched truth locations. The explicitly recorded RFU at 0x00 is exempt under the revised rule, so `x=0` for the extra-register factor.
- An explicitly recorded RFU/Reserved for Future Use register is not counted as an extra deduction. The adjacent non-reserved MSB/LSB claims remain structural claims and are still handled as described below.
- v12 registers[1] through registers[7] add adjacent MSB/LSB address entries to otherwise single-address MCP9808 registers. These are not accepted as equivalent logical-register merges: for example, CONFIG claims 0x02 although 0x02 is the distinct truth TUPPER register. The first field part is the primary matched target; additional field parts and their bit fields are listed as structural extras and do not receive credit for the primary truth target.
- Each truth bit field is aligned only to an exact ordered (bit_start, bit_end) range within the matched primary field part. Split byte-local ranges do not receive credit merely because their union covers some truth bits. The one reversed Resolution reserved interval receives only the direct empty type_write_read credit permitted by the reserved-bit rule.
- Descriptive register/field wording and general physical-address descriptions are judged semantically. Numeric addresses, widths, ordered bit ranges, value meanings, reserved flags, access types, and default values are strict.
- Both-empty type_write_read values receive C=1.0 when the compared bit-field target is structurally aligned or is the same reversed numeric interval; an entirely missing exact-range object remains missing and receives C=0.0 for all leaves.
- Rounded AHP weights are normalized by `0.9999` at bit-field level and `1.0001` at logical-register level; field-part weights sum to `1.0000`.

AHP weights used:

- logical register: `name` 0.0225, `physical_address` 0.4044, `register_description` 0.0564, `width_bits` 0.0590, `type_write_read` 0.0590, `field_parts` 0.2987, `default_value` 0.0667, `default_value_description` 0.0334; category is excluded.
- field part: `register_name` 0.0280, `physical_address` 0.4688, `description` 0.0693, `width_bits` 0.0605, `type_write_read` 0.0605, `bit_field` 0.3129.
- bit field: `name_or_parameter` 0.0212, `field_description` 0.0586, `bit_start` 0.2594, `bit_end` 0.2594, `bit_width` 0.0583, `values` 0.2097, `is_reserved` 0.0750, `type_write_read` 0.0583.

## Extracted logical register 1: `CONFIG`

v12 location: `registers[1]`; truth association: `truth registers[0]` (`CONFIG`).
Primary physical location: `0x01` (1).
Additional extracted physical claims: `0x02 (2)`; these are structurally extra claims for this logical register.

### Bottom layer: bit fields, then field parts

#### Primary field part 1: `CONFIG[MSB]` at `0x01` (1)

Locations: `truth registers[0].field_parts[0]` ↔ `v12 registers[1].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 11:15**

Locations: `truth registers[0].field_parts[0].bit_field[0]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(11, 15) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Unimplemented" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Unimplemented; read as '0'." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 11 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 15 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 5 | "MISSING" |
| `values` | 0.2097 | 0.0 | [] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | true | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 2: `T_HYST` bits 9:10**

Locations: `truth registers[0].field_parts[0].bit_field[1]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(9, 10) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "T_HYST" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "T_UPPER and T_LOWER limit hysteresis selection." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 9 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 10 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 2 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"00","value_description":"0°C (power-up default)"},{"value":"01","value_description":"+1.5°C"},{"value":"10","value_description":"+3.0°C"},{"value":"11","value_description":"+6.0°C"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 3: `SHDN` bits 8:8**

Locations: `truth registers[0].field_parts[0].bit_field[2]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(8, 8) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "SHDN" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Shutdown Mode bit." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 8 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 8 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Continuous conversion (power-up default)"},{"value":"1","value_description":"Shutdown (Low-Power mode)"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 4: `Crit. Lock` bits 7:7**

Locations: `truth registers[0].field_parts[0].bit_field[3]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(7, 7) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Crit. Lock" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "T_CRIT Lock bit." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 7 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 7 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Unlocked; T_CRIT register can be written (power-up default)"},{"value":"1","value_description":"Locked; T_CRIT register cannot be written"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 5: `Win. Lock` bits 6:6**

Locations: `truth registers[0].field_parts[0].bit_field[4]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(6, 6) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Win. Lock" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "T_UPPER and T_LOWER Window Lock bit." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 6 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 6 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Unlocked; T_UPPER and T_LOWER registers can be written (power-up default)"},{"value":"1","value_description":"Locked; T_UPPER and T_LOWER registers cannot be written"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 6: `Int. Clear` bits 5:5**

Locations: `truth registers[0].field_parts[0].bit_field[5]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(5, 5) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Int. Clear" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Interrupt Clear bit." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 5 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 5 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No effect (power-up default)"},{"value":"1","value_description":"Clear interrupt output; when read, this bit returns to '0'"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 7: `Alert Stat.` bits 4:4**

Locations: `truth registers[0].field_parts[0].bit_field[6]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(4, 4) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Alert Stat." | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Alert Output Status bit." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 4 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 4 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Alert output is not asserted by the device (power-up default)"},{"value":"1","value_description":"Alert output is asserted as a comparator/Interrupt or critical temperature output"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "R" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 8: `Alert Cnt.` bits 3:3**

Locations: `truth registers[0].field_parts[0].bit_field[7]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(3, 3) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Alert Cnt." | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Alert Output Control bit." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 3 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 3 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Disabled (power-up default)"},{"value":"1","value_description":"Enabled"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 9: `Alert Sel.` bits 2:2**

Locations: `truth registers[0].field_parts[0].bit_field[8]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(2, 2) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Alert Sel." | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Alert Output Select bit." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 2 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 2 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Alert output for T_UPPER, T_LOWER and T_CRIT (power-up default)"},{"value":"1","value_description":"T_A > T_CRIT only; T_UPPER and T_LOWER boundaries are disabled"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 10: `Alert Pol.` bits 1:1**

Locations: `truth registers[0].field_parts[0].bit_field[9]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(1, 1) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Alert Pol." | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Alert Output Polarity bit." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 1 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 1 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Active-low (power-up default; pull-up resistor required)"},{"value":"1","value_description":"Active-high"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 11: `Alert Mod.` bits 0:0**

Locations: `truth registers[0].field_parts[0].bit_field[10]` ↔ `v12 registers[1].field_parts[0].bit_field[2]`. Judgment: The only exact-range alignment is a semantic collision: the truth Alert Mod. target is paired with the extracted SHDN field. Range/width/reserved/access leaves are compared directly, while the name, description, and value meanings are functionally wrong.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Alert Mod." | "SHDN" |
| `field_description` | 0.0586 | 0.0 | "Alert Output Mode bit." | "Shutdown Mode bit. 0 = Continuous conversion (default), 1 = Shutdown (Low-Power mode)." |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Comparator output (power-up default)"},{"value":"1","value_description":"Interrupt output"}] | [{"value":"0","value_description":"Continuous conversion (power-up default)"},{"value":"1","value_description":"Shutdown (Low-Power mode)"}] |
| `is_reserved` | 0.0750 | 1.0 | false | false |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×1.0 + 0.2594×1.0 + 0.0583×1.0 + 0.2097×0.0 + 0.0750×1.0 + 0.0583×1.0 )/0.9999=0.710400/0.9999=\mathbf{0.710471}\).

**Primary field-part aggregation**

`bit_field` correctness = mean(0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.710471) = **0.064588**. Direct judgments: the extracted register name adds [MSB] to the truth register name and is partial; the matched physical field part is reported as 8 bits instead of the truth 16 bits.

| Field-part field | Weight | Correctness | Truth content | v12 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 0.5 | "CONFIG" | "CONFIG[MSB]" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":""} | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"MSB"} |
| `description` | 0.0693 | 1.0 | "" | "Configuration register MSB byte (bits 15-8)." |
| `width_bits` | 0.0605 | 0.0 | 16 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.064588 | "truth bit-field target" | "matched primary bit-field target" |

\(Q_{FP}=0.0280×0.500000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×0.000000 + 0.0605×1.000000 + 0.3129×0.064588=\mathbf{0.632810}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.632810) = **0.632810**. Direct judgments: the extracted logical register includes the correct primary address plus an additional adjacent address, so physical_address is partial.

| Logical-register field | Weight | Correctness | Truth comparison target | v12 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "CONFIG" | "CONFIG" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":""}] | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":"MSB"},{"hex":"0x02","decimal":"2","bank":"","page":"","description":"LSB"}] |
| `register_description` | 0.0564 | 1.0 | "16-bit configuration register for temperature alert hysteresis, shutdown mode, temperature-limit locks, and Alert output configuration." | "16-bit Configuration register. Allows configuration of temperature alert output hysteresis, device shutdown or Low-Power mode, temperature boundary and critical temperature lock, Alert output enable/disable, Alert output condition, status, polarity, and mode (Comparator/Interrupt)." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.632810 | "corresponding truth field-part target" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "Comparator mode, active-low Alert and Critical output, output disabled, Alert not asserted, interrupt cleared, limits unlocked, continuous conversion, and 0°C hysteresis." | "Comparator Mode, Active-Low Output, Alert and Critical Output, Output Disabled, Alert Not Asserted, Interrupt Cleared, Alert Limits Unlocked, Critical Limit Unlocked, Continuous Conversion, 0°C Hysteresis" |

\(Q(L_{1})=( 0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.632810 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=0.688220/1.0001=\mathbf{0.688151}\).

## Extracted logical register 2: `TUPPER`

v12 location: `registers[2]`; truth association: `truth registers[1]` (`TUPPER`).
Primary physical location: `0x02` (2).
Additional extracted physical claims: `0x03 (3)`; these are structurally extra claims for this logical register.

### Bottom layer: bit fields, then field parts

#### Primary field part 1: `TUPPER[MSB]` at `0x02` (2)

Locations: `truth registers[1].field_parts[0]` ↔ `v12 registers[2].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 13:15**

Locations: `truth registers[1].field_parts[0].bit_field[0]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(13, 15) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Unimplemented" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Unimplemented; read as '0'." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 13 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 15 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 3 | "MISSING" |
| `values` | 0.2097 | 0.0 | [] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | true | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 2: `Sign` bits 12:12**

Locations: `truth registers[1].field_parts[0].bit_field[1]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(12, 12) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Sign" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Sign bit." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 12 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 12 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 3: `TUPPER` bits 2:11**

Locations: `truth registers[1].field_parts[0].bit_field[2]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(2, 11) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "TUPPER" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Upper temperature boundary trip data in two's complement format." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 2 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 11 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 10 | "MISSING" |
| `values` | 0.2097 | 0.0 | [] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 4: `Unimplemented` bits 0:1**

Locations: `truth registers[1].field_parts[0].bit_field[3]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(0, 1) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Unimplemented" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Unimplemented; read as '0'." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 0 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 1 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 2 | "MISSING" |
| `values` | 0.2097 | 0.0 | [] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | true | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Primary field-part aggregation**

`bit_field` correctness = mean(0.000000, 0.000000, 0.000000, 0.000000) = **0.000000**. Direct judgments: the extracted register name adds [MSB] to the truth register name and is partial; the matched physical field part is reported as 8 bits instead of the truth 16 bits.

| Field-part field | Weight | Correctness | Truth content | v12 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 0.5 | "TUPPER" | "TUPPER[MSB]" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x02","decimal":"2","bank":"","page":"","description":""} | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"MSB"} |
| `description` | 0.0693 | 1.0 | "" | "TUPPER register MSB byte (bits 15-8)." |
| `width_bits` | 0.0605 | 0.0 | 16 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.000000 | "truth bit-field target" | "matched primary bit-field target" |

\(Q_{FP}=0.0280×0.500000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×0.000000 + 0.0605×1.000000 + 0.3129×0.000000=\mathbf{0.612600}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.612600) = **0.612600**. Direct judgments: the extracted logical register includes the correct primary address plus an additional adjacent address, so physical_address is partial.

| Logical-register field | Weight | Correctness | Truth comparison target | v12 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "TUPPER" | "TUPPER" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":""}] | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":"MSB"},{"hex":"0x03","decimal":"3","bank":"","page":"","description":"LSB"}] |
| `register_description` | 0.0564 | 1.0 | "16-bit read/write Alert Output Temperature Upper Boundary register containing 11-bit temperature data in two's complement format with 0.25°C resolution." | "16-bit read/write Alert Output Temperature Upper Boundary register. Contains 11-bit two's complement temperature data (0.25°C resolution) representing the upper boundary for temperature monitoring." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.612600 | "corresponding truth field-part target" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "0°C" | "0°C" |

\(Q(L_{2})=( 0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.612600 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=0.682184/1.0001=\mathbf{0.682115}\).

## Extracted logical register 3: `TLOWER`

v12 location: `registers[3]`; truth association: `truth registers[2]` (`TLOWER`).
Primary physical location: `0x03` (3).
Additional extracted physical claims: `0x04 (4)`; these are structurally extra claims for this logical register.

### Bottom layer: bit fields, then field parts

#### Primary field part 1: `TLOWER[MSB]` at `0x03` (3)

Locations: `truth registers[2].field_parts[0]` ↔ `v12 registers[3].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 13:15**

Locations: `truth registers[2].field_parts[0].bit_field[0]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(13, 15) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Unimplemented" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Unimplemented; read as '0'." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 13 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 15 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 3 | "MISSING" |
| `values` | 0.2097 | 0.0 | [] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | true | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 2: `Sign` bits 12:12**

Locations: `truth registers[2].field_parts[0].bit_field[1]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(12, 12) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Sign" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Sign bit." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 12 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 12 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 3: `TLOWER` bits 2:11**

Locations: `truth registers[2].field_parts[0].bit_field[2]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(2, 11) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "TLOWER" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Lower temperature boundary trip data in two's complement format." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 2 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 11 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 10 | "MISSING" |
| `values` | 0.2097 | 0.0 | [] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 4: `Unimplemented` bits 0:1**

Locations: `truth registers[2].field_parts[0].bit_field[3]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(0, 1) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Unimplemented" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Unimplemented; read as '0'." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 0 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 1 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 2 | "MISSING" |
| `values` | 0.2097 | 0.0 | [] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | true | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Primary field-part aggregation**

`bit_field` correctness = mean(0.000000, 0.000000, 0.000000, 0.000000) = **0.000000**. Direct judgments: the extracted register name adds [MSB] to the truth register name and is partial; the matched physical field part is reported as 8 bits instead of the truth 16 bits.

| Field-part field | Weight | Correctness | Truth content | v12 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 0.5 | "TLOWER" | "TLOWER[MSB]" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x03","decimal":"3","bank":"","page":"","description":""} | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"MSB"} |
| `description` | 0.0693 | 1.0 | "" | "TLOWER register MSB byte (bits 15-8)." |
| `width_bits` | 0.0605 | 0.0 | 16 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.000000 | "truth bit-field target" | "matched primary bit-field target" |

\(Q_{FP}=0.0280×0.500000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×0.000000 + 0.0605×1.000000 + 0.3129×0.000000=\mathbf{0.612600}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.612600) = **0.612600**. Direct judgments: the extracted logical register includes the correct primary address plus an additional adjacent address, so physical_address is partial.

| Logical-register field | Weight | Correctness | Truth comparison target | v12 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "TLOWER" | "TLOWER" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":""}] | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"MSB"},{"hex":"0x04","decimal":"4","bank":"","page":"","description":"LSB"}] |
| `register_description` | 0.0564 | 1.0 | "16-bit read/write Lower Boundary register containing 11-bit temperature data in two's complement format with 0.25°C resolution." | "16-bit read/write Alert Output Temperature Lower Boundary register. Contains 11-bit two's complement temperature data (0.25°C resolution) representing the lower boundary for temperature monitoring." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.612600 | "corresponding truth field-part target" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "0°C" | "0°C" |

\(Q(L_{3})=( 0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.612600 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=0.682184/1.0001=\mathbf{0.682115}\).

## Extracted logical register 4: `TCRIT`

v12 location: `registers[4]`; truth association: `truth registers[3]` (`TCRIT`).
Primary physical location: `0x04` (4).
Additional extracted physical claims: `0x05 (5)`; these are structurally extra claims for this logical register.

### Bottom layer: bit fields, then field parts

#### Primary field part 1: `TCRIT[MSB]` at `0x04` (4)

Locations: `truth registers[3].field_parts[0]` ↔ `v12 registers[4].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 13:15**

Locations: `truth registers[3].field_parts[0].bit_field[0]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(13, 15) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Unimplemented" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Unimplemented; read as '0'." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 13 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 15 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 3 | "MISSING" |
| `values` | 0.2097 | 0.0 | [] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | true | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 2: `Sign` bits 12:12**

Locations: `truth registers[3].field_parts[0].bit_field[1]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(12, 12) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Sign" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Sign bit." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 12 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 12 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 3: `TCRIT` bits 2:11**

Locations: `truth registers[3].field_parts[0].bit_field[2]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(2, 11) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "TCRIT" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Critical temperature boundary trip data in two's complement format." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 2 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 11 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 10 | "MISSING" |
| `values` | 0.2097 | 0.0 | [] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 4: `Unimplemented` bits 0:1**

Locations: `truth registers[3].field_parts[0].bit_field[3]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(0, 1) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Unimplemented" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Unimplemented; read as '0'." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 0 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 1 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 2 | "MISSING" |
| `values` | 0.2097 | 0.0 | [] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | true | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Primary field-part aggregation**

`bit_field` correctness = mean(0.000000, 0.000000, 0.000000, 0.000000) = **0.000000**. Direct judgments: the extracted register name adds [MSB] to the truth register name and is partial; the matched physical field part is reported as 8 bits instead of the truth 16 bits.

| Field-part field | Weight | Correctness | Truth content | v12 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 0.5 | "TCRIT" | "TCRIT[MSB]" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x04","decimal":"4","bank":"","page":"","description":""} | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"MSB"} |
| `description` | 0.0693 | 1.0 | "" | "TCRIT register MSB byte (bits 15-8)." |
| `width_bits` | 0.0605 | 0.0 | 16 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.000000 | "truth bit-field target" | "matched primary bit-field target" |

\(Q_{FP}=0.0280×0.500000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×0.000000 + 0.0605×1.000000 + 0.3129×0.000000=\mathbf{0.612600}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.612600) = **0.612600**. Direct judgments: the extracted logical register includes the correct primary address plus an additional adjacent address, so physical_address is partial.

| Logical-register field | Weight | Correctness | Truth comparison target | v12 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "TCRIT" | "TCRIT" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":""}] | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":"MSB"},{"hex":"0x05","decimal":"5","bank":"","page":"","description":"LSB"}] |
| `register_description` | 0.0564 | 1.0 | "16-bit read/write Critical Boundary register containing 11-bit temperature data in two's complement format with 0.25°C resolution." | "16-bit read/write Critical Temperature Trip register. Contains 11-bit two's complement temperature data (0.25°C resolution) representing the critical temperature limit." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.612600 | "corresponding truth field-part target" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "0°C" | "0°C" |

\(Q(L_{4})=( 0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.612600 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=0.682184/1.0001=\mathbf{0.682115}\).

## Extracted logical register 5: `TA`

v12 location: `registers[5]`; truth association: `truth registers[4]` (`TA`).
Primary physical location: `0x05` (5).
Additional extracted physical claims: `0x06 (6)`; these are structurally extra claims for this logical register.

### Bottom layer: bit fields, then field parts

#### Primary field part 1: `TA[MSB]` at `0x05` (5)

Locations: `truth registers[4].field_parts[0]` ↔ `v12 registers[5].field_parts[0]`.

**Truth bit field 1: `TA vs. TCRIT` bits 15:15**

Locations: `truth registers[4].field_parts[0].bit_field[0]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(15, 15) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "TA vs. TCRIT" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Indicates whether ambient temperature is at or above the critical limit." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 15 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 15 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"T_A < T_CRIT"},{"value":"1","value_description":"T_A ≥ T_CRIT"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "R" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 2: `TA vs. TUPPER` bits 14:14**

Locations: `truth registers[4].field_parts[0].bit_field[1]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(14, 14) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "TA vs. TUPPER" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Indicates whether ambient temperature is above the upper boundary." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 14 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 14 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"T_A ≤ T_UPPER"},{"value":"1","value_description":"T_A > T_UPPER"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "R" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 3: `TA vs. TLOWER` bits 13:13**

Locations: `truth registers[4].field_parts[0].bit_field[2]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(13, 13) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "TA vs. TLOWER" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Indicates whether ambient temperature is below the lower boundary." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 13 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 13 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"T_A ≥ T_LOWER"},{"value":"1","value_description":"T_A < T_LOWER"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "R" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 4: `SIGN` bits 12:12**

Locations: `truth registers[4].field_parts[0].bit_field[3]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(12, 12) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "SIGN" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Ambient temperature sign bit." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 12 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 12 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 1 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "R" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 5: `TA` bits 0:11**

Locations: `truth registers[4].field_parts[0].bit_field[4]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(0, 11) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "TA" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "12-bit ambient temperature data in two's complement format." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 0 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 11 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 12 | "MISSING" |
| `values` | 0.2097 | 0.0 | [] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "R" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Primary field-part aggregation**

`bit_field` correctness = mean(0.000000, 0.000000, 0.000000, 0.000000, 0.000000) = **0.000000**. Direct judgments: the extracted register name adds [MSB] to the truth register name and is partial; the matched physical field part is reported as 8 bits instead of the truth 16 bits.

| Field-part field | Weight | Correctness | Truth content | v12 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 0.5 | "TA" | "TA[MSB]" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x05","decimal":"5","bank":"","page":"","description":""} | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"MSB"} |
| `description` | 0.0693 | 1.0 | "" | "TA register MSB byte (bits 15-8)." |
| `width_bits` | 0.0605 | 0.0 | 16 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.000000 | "truth bit-field target" | "matched primary bit-field target" |

\(Q_{FP}=0.0280×0.500000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×0.000000 + 0.0605×1.000000 + 0.3129×0.000000=\mathbf{0.612600}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.612600) = **0.612600**. Direct judgments: the extracted logical register includes the correct primary address plus an additional adjacent address, so physical_address is partial.

| Logical-register field | Weight | Correctness | Truth comparison target | v12 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "TA" | "TA" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x05","decimal":"5","bank":"","page":"","description":""}] | [{"hex":"0x05","decimal":"5","bank":"","page":"","description":"MSB"},{"hex":"0x06","decimal":"6","bank":"","page":"","description":"LSB"}] |
| `register_description` | 0.0564 | 1.0 | "Double-buffered 16-bit read-only Ambient Temperature register containing 13-bit two's-complement temperature data and three Alert boundary-status bits; updated at the conversion refresh rate." | "16-bit read-only Ambient Temperature register. Contains 13-bit two's complement temperature data (default 0.25°C resolution). Bits 15-13 reflect Alert pin state (TA vs TCRIT, TUPPER, TLOWER). Double-buffered to allow access during ADC conversion." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.612600 | "corresponding truth field-part target" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0000" | "0x0000" |
| `default_value_description` | 0.0334 | 1.0 | "0°C" | "0°C" |

\(Q(L_{5})=( 0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.612600 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=0.682184/1.0001=\mathbf{0.682115}\).

## Extracted logical register 6: `Manufacturer ID`

v12 location: `registers[6]`; truth association: `truth registers[5]` (`Manufacturer ID`).
Primary physical location: `0x06` (6).
Additional extracted physical claims: `0x07 (7)`; these are structurally extra claims for this logical register.

### Bottom layer: bit fields, then field parts

#### Primary field part 1: `Manufacturer ID[MSB]` at `0x06` (6)

Locations: `truth registers[5].field_parts[0]` ↔ `v12 registers[6].field_parts[0]`.

**Truth bit field 1: `Manufacturer ID` bits 0:15**

Locations: `truth registers[5].field_parts[0].bit_field[0]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(0, 15) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Manufacturer ID" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Device Manufacturer Identification bits." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 0 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 15 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 16 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0x0054","value_description":"Manufacturer ID for the MCP9808"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "R" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Primary field-part aggregation**

`bit_field` correctness = mean(0.000000) = **0.000000**. Direct judgments: the extracted register name adds [MSB] to the truth register name and is partial; the matched physical field part is reported as 8 bits instead of the truth 16 bits.

| Field-part field | Weight | Correctness | Truth content | v12 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 0.5 | "Manufacturer ID" | "Manufacturer ID[MSB]" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x06","decimal":"6","bank":"","page":"","description":""} | {"hex":"0x06","decimal":"6","bank":"","page":"","description":"MSB"} |
| `description` | 0.0693 | 1.0 | "" | "Manufacturer ID register MSB byte (bits 15-8)." |
| `width_bits` | 0.0605 | 0.0 | 16 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.000000 | "truth bit-field target" | "matched primary bit-field target" |

\(Q_{FP}=0.0280×0.500000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×0.000000 + 0.0605×1.000000 + 0.3129×0.000000=\mathbf{0.612600}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.612600) = **0.612600**. Direct judgments: the extracted logical register includes the correct primary address plus an additional adjacent address, so physical_address is partial.

| Logical-register field | Weight | Correctness | Truth comparison target | v12 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "Manufacturer ID" | "Manufacturer ID" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":""}] | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":"MSB"},{"hex":"0x07","decimal":"7","bank":"","page":"","description":"LSB"}] |
| `register_description` | 0.0564 | 1.0 | "Read-only register used to identify the device manufacturer for manufacturer-specific operation." | "16-bit read-only Manufacturer Identification register. Value is 0x0054 (Microchip)." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.612600 | "corresponding truth field-part target" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0054" | "0x0054" |
| `default_value_description` | 0.0334 | 1.0 | "Manufacturer ID for the MCP9808." | "Manufacturer ID for MCP9808 (hex)" |

\(Q(L_{6})=( 0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.612600 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=0.682184/1.0001=\mathbf{0.682115}\).

## Extracted logical register 7: `Device ID/Revision`

v12 location: `registers[7]`; truth association: `truth registers[6]` (`Device ID/Revision`).
Primary physical location: `0x07` (7).
Additional extracted physical claims: `0x08 (8)`; these are structurally extra claims for this logical register.

### Bottom layer: bit fields, then field parts

#### Primary field part 1: `Device ID/Revision[MSB]` at `0x07` (7)

Locations: `truth registers[6].field_parts[0]` ↔ `v12 registers[7].field_parts[0]`.

**Truth bit field 1: `Device ID` bits 8:15**

Locations: `truth registers[6].field_parts[0].bit_field[0]` ↔ no exact-range v12 target. Judgment: No v12 bit field has the exact ordered (bit_start, bit_end)=(8, 15) target; the complete truth bit-field object is missing for this exact-range comparison.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Device ID" | "MISSING" |
| `field_description` | 0.0586 | 0.0 | "Device identification bits." | "MISSING" |
| `bit_start` | 0.2594 | 0.0 | 8 | "MISSING" |
| `bit_end` | 0.2594 | 0.0 | 15 | "MISSING" |
| `bit_width` | 0.0583 | 0.0 | 8 | "MISSING" |
| `values` | 0.2097 | 0.0 | [{"value":"0x04","value_description":"Device ID for the MCP9808"}] | "MISSING" |
| `is_reserved` | 0.0750 | 0.0 | false | "MISSING" |
| `type_write_read` | 0.0583 | 0.0 | "R" | "MISSING" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Truth bit field 2: `Device Revision` bits 0:7**

Locations: `truth registers[6].field_parts[0].bit_field[1]` ↔ `v12 registers[7].field_parts[0].bit_field[0]`. Judgment: The extracted endpoints reverse the same numeric interval; structural bit fields are not aligned, and the nonempty type_write_read field is not credited.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Device Revision" | "Device ID" |
| `field_description` | 0.0586 | 0.0 | "Device revision bits." | "Bit 15 to bit 8 are used for device ID. MCP9808 Device ID is 0x04." |
| `bit_start` | 0.2594 | 0.0 | 0 | 7 |
| `bit_end` | 0.2594 | 0.0 | 7 | 0 |
| `bit_width` | 0.0583 | 0.0 | 8 | 8 |
| `values` | 0.2097 | 0.0 | [{"value":"0x00","value_description":"First release revision; incremented for revised versions"}] | [] |
| `is_reserved` | 0.0750 | 0.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "R" | "R" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Primary field-part aggregation**

`bit_field` correctness = mean(0.000000, 0.000000) = **0.000000**. Direct judgments: the extracted register name adds [MSB] to the truth register name and is partial; the matched physical field part is reported as 8 bits instead of the truth 16 bits.

| Field-part field | Weight | Correctness | Truth content | v12 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 0.5 | "Device ID/Revision" | "Device ID/Revision[MSB]" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} | {"hex":"0x07","decimal":"7","bank":"","page":"","description":"MSB"} |
| `description` | 0.0693 | 1.0 | "" | "Device ID byte (bits 15-8)." |
| `width_bits` | 0.0605 | 0.0 | 16 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.000000 | "truth bit-field target" | "matched primary bit-field target" |

\(Q_{FP}=0.0280×0.500000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×0.000000 + 0.0605×1.000000 + 0.3129×0.000000=\mathbf{0.612600}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.612600) = **0.612600**. Direct judgments: the extracted logical register includes the correct primary address plus an additional adjacent address, so physical_address is partial.

| Logical-register field | Weight | Correctness | Truth comparison target | v12 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "Device ID/Revision" | "Device ID/Revision" |
| `physical_address` | 0.4044 | 0.5 | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":""}] | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":"MSB"},{"hex":"0x08","decimal":"8","bank":"","page":"","description":"LSB"}] |
| `register_description` | 0.0564 | 1.0 | "Read-only register whose upper byte specifies the device identification and lower byte specifies the device revision." | "16-bit read-only Device ID and Revision register. Upper byte (bits 15-8) is Device ID (0x04 for MCP9808). Lower byte (bits 7-0) is Device Revision (starts at 0x00)." |
| `width_bits` | 0.0590 | 1.0 | 16 | 16 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.612600 | "corresponding truth field-part target" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x0400" | "0x0400" |
| `default_value_description` | 0.0334 | 1.0 | "Device ID 0x04 and initial device revision 0x00." | "Device ID 0x04, Revision 0x00 (hex)" |

\(Q(L_{7})=( 0.0225×1.000000 + 0.4044×0.500000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.612600 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=0.682184/1.0001=\mathbf{0.682115}\).

## Extracted logical register 8: `Resolution`

v12 location: `registers[8]`; truth association: `truth registers[7]` (`Resolution`).
Primary physical location: `0x08` (8).

### Bottom layer: bit fields, then field parts

#### Primary field part 1: `Resolution` at `0x08` (8)

Locations: `truth registers[7].field_parts[0]` ↔ `v12 registers[8].field_parts[0]`.

**Truth bit field 1: `Unimplemented` bits 2:7**

Locations: `truth registers[7].field_parts[0].bit_field[0]` ↔ `v12 registers[8].field_parts[0].bit_field[0]`. Judgment: The extracted endpoints reverse the same numeric interval; structural bit fields are not aligned. Both type_write_read values are empty, so only that direct field receives C=1.0.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Unimplemented" | "Unimplemented" |
| `field_description` | 0.0586 | 0.0 | "Unimplemented; read as '0'." | "Read as '0'" |
| `bit_start` | 0.2594 | 0.0 | 2 | 7 |
| `bit_end` | 0.2594 | 0.0 | 7 | 2 |
| `bit_width` | 0.0583 | 0.0 | 6 | 6 |
| `values` | 0.2097 | 0.0 | [] | [] |
| `is_reserved` | 0.0750 | 0.0 | true | true |
| `type_write_read` | 0.0583 | 1.0 | "" | "" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×1.0 )/0.9999=0.058300/0.9999=\mathbf{0.058306}\).

**Truth bit field 2: `Resolution` bits 0:1**

Locations: `truth registers[7].field_parts[0].bit_field[1]` ↔ `v12 registers[8].field_parts[0].bit_field[1]`. Judgment: The extracted endpoints reverse the same numeric interval; structural bit fields are not aligned, and the nonempty type_write_read field is not credited.

| Scored field | Weight | C | Truth content | v12 content |
|---|---|---|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "Resolution" | "Resolution" |
| `field_description` | 0.0586 | 0.0 | "Sensor resolution selection." | "Resolution bits. 00 = +0.5°C, 01 = +0.25°C, 10 = +0.125°C, 11 = +0.0625°C (default)." |
| `bit_start` | 0.2594 | 0.0 | 0 | 1 |
| `bit_end` | 0.2594 | 0.0 | 1 | 0 |
| `bit_width` | 0.0583 | 0.0 | 2 | 2 |
| `values` | 0.2097 | 0.0 | [{"value":"00","value_description":"+0.5°C (t_CONV = 30 ms typical)"},{"value":"01","value_description":"+0.25°C (t_CONV = 65 ms typical)"},{"value":"10","value_description":"+0.125°C (t_CONV = 130 ms typical)"},{"value":"11","value_description":"+0.0625°C (power-up default, t_CONV = 250 ms typical)"}] | [{"value":"00","value_description":"+0.5°C (t_CONV = 30 ms typical)"},{"value":"01","value_description":"+0.25°C (t_CONV = 65 ms typical)"},{"value":"10","value_description":"+0.125°C (t_CONV = 130 ms typical)"},{"value":"11","value_description":"+0.0625°C (power-up default, t_CONV = 250 ms typical)"}] |
| `is_reserved` | 0.0750 | 0.0 | false | false |
| `type_write_read` | 0.0583 | 0.0 | "RW" | "RW" |

\(Q_{BF}=( 0.0212×0.0 + 0.0586×0.0 + 0.2594×0.0 + 0.2594×0.0 + 0.0583×0.0 + 0.2097×0.0 + 0.0750×0.0 + 0.0583×0.0 )/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Primary field-part aggregation**

`bit_field` correctness = mean(0.058306, 0.000000) = **0.029153**. All direct matched field-part fields are correct; general address and description wording is accepted.

| Field-part field | Weight | Correctness | Truth content | v12 content |
|---|---|---|---|---|
| `register_name` | 0.0280 | 1.0 | "Resolution" | "Resolution" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x08","decimal":"8","bank":"","page":"","description":""} | {"hex":"0x08","decimal":"8","bank":"","page":"","description":""} |
| `description` | 0.0693 | 1.0 | "" | "Resolution register (bits 7-0)." |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.029153 | "truth bit-field target" | "matched primary bit-field target" |

\(Q_{FP}=0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.029153=\mathbf{0.696222}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.696222) = **0.696222**. All direct logical-register fields are correct; description wording preserves the register facts.

| Logical-register field | Weight | Correctness | Truth comparison target | v12 content |
|---|---|---|---|---|
| `name` | 0.0225 | 1.0 | "Resolution" | "Resolution" |
| `physical_address` | 0.4044 | 1.0 | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":""}] | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":""}] |
| `register_description` | 0.0564 | 1.0 | "Allows the user to select the sensor temperature resolution from +0.5°C to +0.0625°C." | "8-bit read/write Resolution register. Selects sensor resolution: 00 = +0.5°C, 01 = +0.25°C, 10 = +0.125°C, 11 = +0.0625°C (default)." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.696222 | "corresponding truth field-part target" | "extracted field-part collection" |
| `default_value` | 0.0667 | 1.0 | "0x03" | "0x03" |
| `default_value_description` | 0.0334 | 1.0 | "+0.0625°C resolution." | "+0.0625°C resolution (hex)" |

\(Q(L_{8})=( 0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.696222 + 0.0667×1.000000 + 0.0334×1.000000 )/1.0001=0.909361/1.0001=\mathbf{0.909271}\).

## 2. Physical-register score summary

| Truth physical register | Address | Extracted logical register | q_R |
|---|---|---|---|
| `CONFIG` | `0x01` | `v12 registers[1]` (`CONFIG`) | 0.688151434 |
| `TUPPER` | `0x02` | `v12 registers[2]` (`TUPPER`) | 0.682115408 |
| `TLOWER` | `0x03` | `v12 registers[3]` (`TLOWER`) | 0.682115408 |
| `TCRIT` | `0x04` | `v12 registers[4]` (`TCRIT`) | 0.682115408 |
| `TA` | `0x05` | `v12 registers[5]` (`TA`) | 0.682115408 |
| `Manufacturer ID` | `0x06` | `v12 registers[6]` (`Manufacturer ID`) | 0.682115408 |
| `Device ID/Revision` | `0x07` | `v12 registers[7]` (`Device ID/Revision`) | 0.682115408 |
| `Resolution` | `0x08` | `v12 registers[8]` (`Resolution`) | 0.909270569 |

\(\sum_{R=1}^{8}q_R=\mathbf{5.690114453}\).

\(m=8,\ x=0,\ \frac{m}{m+x}=\frac{8}{8+0}=1.000000\).

\[S_{final}=\left(\frac{10}{8}\times 5.690114453\right)\times\frac{8}{8+0}=\boxed{\mathbf{7.112643066/10}}\]

## 3. Detailed deduction inventory

### 3.1 Direct scored deductions

1. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[0]).name_or_parameter` vs `truth registers[0].field_parts[0].bit_field[0].name_or_parameter`: `C=0.0`; truth="Unimplemented"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
2. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[0]).field_description` vs `truth registers[0].field_parts[0].bit_field[0].field_description`: `C=0.0`; truth="Unimplemented; read as '0'."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
3. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_start` vs `truth registers[0].field_parts[0].bit_field[0].bit_start`: `C=0.0`; truth=11; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
4. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_end` vs `truth registers[0].field_parts[0].bit_field[0].bit_end`: `C=0.0`; truth=15; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
5. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_width` vs `truth registers[0].field_parts[0].bit_field[0].bit_width`: `C=0.0`; truth=5; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
6. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[0]).values` vs `truth registers[0].field_parts[0].bit_field[0].values`: `C=0.0`; truth=[]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
7. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[0]).is_reserved` vs `truth registers[0].field_parts[0].bit_field[0].is_reserved`: `C=0.0`; truth=true; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
8. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[0]).type_write_read` vs `truth registers[0].field_parts[0].bit_field[0].type_write_read`: `C=0.0`; truth=""; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
9. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[1]).name_or_parameter` vs `truth registers[0].field_parts[0].bit_field[1].name_or_parameter`: `C=0.0`; truth="T_HYST"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
10. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[1]).field_description` vs `truth registers[0].field_parts[0].bit_field[1].field_description`: `C=0.0`; truth="T_UPPER and T_LOWER limit hysteresis selection."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
11. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_start` vs `truth registers[0].field_parts[0].bit_field[1].bit_start`: `C=0.0`; truth=9; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
12. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_end` vs `truth registers[0].field_parts[0].bit_field[1].bit_end`: `C=0.0`; truth=10; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
13. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_width` vs `truth registers[0].field_parts[0].bit_field[1].bit_width`: `C=0.0`; truth=2; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
14. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[1]).values` vs `truth registers[0].field_parts[0].bit_field[1].values`: `C=0.0`; truth=[{"value":"00","value_description":"0°C (power-up default)"},{"value":"01","value_description":"+1.5°C"},{"value":"10","value_description":"+3.0°C"},{"value":"11","value_description":"+6.0°C"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
15. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[1]).is_reserved` vs `truth registers[0].field_parts[0].bit_field[1].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
16. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[1]).type_write_read` vs `truth registers[0].field_parts[0].bit_field[1].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
17. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[2]).name_or_parameter` vs `truth registers[0].field_parts[0].bit_field[2].name_or_parameter`: `C=0.0`; truth="SHDN"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
18. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[2]).field_description` vs `truth registers[0].field_parts[0].bit_field[2].field_description`: `C=0.0`; truth="Shutdown Mode bit."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
19. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_start` vs `truth registers[0].field_parts[0].bit_field[2].bit_start`: `C=0.0`; truth=8; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
20. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_end` vs `truth registers[0].field_parts[0].bit_field[2].bit_end`: `C=0.0`; truth=8; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
21. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_width` vs `truth registers[0].field_parts[0].bit_field[2].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
22. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[2]).values` vs `truth registers[0].field_parts[0].bit_field[2].values`: `C=0.0`; truth=[{"value":"0","value_description":"Continuous conversion (power-up default)"},{"value":"1","value_description":"Shutdown (Low-Power mode)"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
23. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[2]).is_reserved` vs `truth registers[0].field_parts[0].bit_field[2].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
24. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[2]).type_write_read` vs `truth registers[0].field_parts[0].bit_field[2].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
25. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[3]).name_or_parameter` vs `truth registers[0].field_parts[0].bit_field[3].name_or_parameter`: `C=0.0`; truth="Crit. Lock"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
26. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[3]).field_description` vs `truth registers[0].field_parts[0].bit_field[3].field_description`: `C=0.0`; truth="T_CRIT Lock bit."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
27. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_start` vs `truth registers[0].field_parts[0].bit_field[3].bit_start`: `C=0.0`; truth=7; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
28. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_end` vs `truth registers[0].field_parts[0].bit_field[3].bit_end`: `C=0.0`; truth=7; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
29. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_width` vs `truth registers[0].field_parts[0].bit_field[3].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
30. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[3]).values` vs `truth registers[0].field_parts[0].bit_field[3].values`: `C=0.0`; truth=[{"value":"0","value_description":"Unlocked; T_CRIT register can be written (power-up default)"},{"value":"1","value_description":"Locked; T_CRIT register cannot be written"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
31. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[3]).is_reserved` vs `truth registers[0].field_parts[0].bit_field[3].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
32. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[3]).type_write_read` vs `truth registers[0].field_parts[0].bit_field[3].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
33. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[4]).name_or_parameter` vs `truth registers[0].field_parts[0].bit_field[4].name_or_parameter`: `C=0.0`; truth="Win. Lock"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
34. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[4]).field_description` vs `truth registers[0].field_parts[0].bit_field[4].field_description`: `C=0.0`; truth="T_UPPER and T_LOWER Window Lock bit."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
35. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[4]).bit_start` vs `truth registers[0].field_parts[0].bit_field[4].bit_start`: `C=0.0`; truth=6; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
36. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[4]).bit_end` vs `truth registers[0].field_parts[0].bit_field[4].bit_end`: `C=0.0`; truth=6; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
37. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[4]).bit_width` vs `truth registers[0].field_parts[0].bit_field[4].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
38. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[4]).values` vs `truth registers[0].field_parts[0].bit_field[4].values`: `C=0.0`; truth=[{"value":"0","value_description":"Unlocked; T_UPPER and T_LOWER registers can be written (power-up default)"},{"value":"1","value_description":"Locked; T_UPPER and T_LOWER registers cannot be written"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
39. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[4]).is_reserved` vs `truth registers[0].field_parts[0].bit_field[4].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
40. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[4]).type_write_read` vs `truth registers[0].field_parts[0].bit_field[4].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
41. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[5]).name_or_parameter` vs `truth registers[0].field_parts[0].bit_field[5].name_or_parameter`: `C=0.0`; truth="Int. Clear"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
42. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[5]).field_description` vs `truth registers[0].field_parts[0].bit_field[5].field_description`: `C=0.0`; truth="Interrupt Clear bit."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
43. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[5]).bit_start` vs `truth registers[0].field_parts[0].bit_field[5].bit_start`: `C=0.0`; truth=5; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
44. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[5]).bit_end` vs `truth registers[0].field_parts[0].bit_field[5].bit_end`: `C=0.0`; truth=5; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
45. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[5]).bit_width` vs `truth registers[0].field_parts[0].bit_field[5].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
46. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[5]).values` vs `truth registers[0].field_parts[0].bit_field[5].values`: `C=0.0`; truth=[{"value":"0","value_description":"No effect (power-up default)"},{"value":"1","value_description":"Clear interrupt output; when read, this bit returns to '0'"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
47. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[5]).is_reserved` vs `truth registers[0].field_parts[0].bit_field[5].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
48. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[5]).type_write_read` vs `truth registers[0].field_parts[0].bit_field[5].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
49. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[6]).name_or_parameter` vs `truth registers[0].field_parts[0].bit_field[6].name_or_parameter`: `C=0.0`; truth="Alert Stat."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
50. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[6]).field_description` vs `truth registers[0].field_parts[0].bit_field[6].field_description`: `C=0.0`; truth="Alert Output Status bit."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
51. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[6]).bit_start` vs `truth registers[0].field_parts[0].bit_field[6].bit_start`: `C=0.0`; truth=4; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
52. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[6]).bit_end` vs `truth registers[0].field_parts[0].bit_field[6].bit_end`: `C=0.0`; truth=4; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
53. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[6]).bit_width` vs `truth registers[0].field_parts[0].bit_field[6].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
54. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[6]).values` vs `truth registers[0].field_parts[0].bit_field[6].values`: `C=0.0`; truth=[{"value":"0","value_description":"Alert output is not asserted by the device (power-up default)"},{"value":"1","value_description":"Alert output is asserted as a comparator/Interrupt or critical temperature output"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
55. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[6]).is_reserved` vs `truth registers[0].field_parts[0].bit_field[6].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
56. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[6]).type_write_read` vs `truth registers[0].field_parts[0].bit_field[6].type_write_read`: `C=0.0`; truth="R"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
57. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[7]).name_or_parameter` vs `truth registers[0].field_parts[0].bit_field[7].name_or_parameter`: `C=0.0`; truth="Alert Cnt."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
58. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[7]).field_description` vs `truth registers[0].field_parts[0].bit_field[7].field_description`: `C=0.0`; truth="Alert Output Control bit."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
59. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[7]).bit_start` vs `truth registers[0].field_parts[0].bit_field[7].bit_start`: `C=0.0`; truth=3; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
60. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[7]).bit_end` vs `truth registers[0].field_parts[0].bit_field[7].bit_end`: `C=0.0`; truth=3; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
61. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[7]).bit_width` vs `truth registers[0].field_parts[0].bit_field[7].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
62. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[7]).values` vs `truth registers[0].field_parts[0].bit_field[7].values`: `C=0.0`; truth=[{"value":"0","value_description":"Disabled (power-up default)"},{"value":"1","value_description":"Enabled"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
63. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[7]).is_reserved` vs `truth registers[0].field_parts[0].bit_field[7].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
64. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[7]).type_write_read` vs `truth registers[0].field_parts[0].bit_field[7].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
65. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[8]).name_or_parameter` vs `truth registers[0].field_parts[0].bit_field[8].name_or_parameter`: `C=0.0`; truth="Alert Sel."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
66. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[8]).field_description` vs `truth registers[0].field_parts[0].bit_field[8].field_description`: `C=0.0`; truth="Alert Output Select bit."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
67. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[8]).bit_start` vs `truth registers[0].field_parts[0].bit_field[8].bit_start`: `C=0.0`; truth=2; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
68. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[8]).bit_end` vs `truth registers[0].field_parts[0].bit_field[8].bit_end`: `C=0.0`; truth=2; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
69. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[8]).bit_width` vs `truth registers[0].field_parts[0].bit_field[8].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
70. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[8]).values` vs `truth registers[0].field_parts[0].bit_field[8].values`: `C=0.0`; truth=[{"value":"0","value_description":"Alert output for T_UPPER, T_LOWER and T_CRIT (power-up default)"},{"value":"1","value_description":"T_A > T_CRIT only; T_UPPER and T_LOWER boundaries are disabled"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
71. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[8]).is_reserved` vs `truth registers[0].field_parts[0].bit_field[8].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
72. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[8]).type_write_read` vs `truth registers[0].field_parts[0].bit_field[8].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
73. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[9]).name_or_parameter` vs `truth registers[0].field_parts[0].bit_field[9].name_or_parameter`: `C=0.0`; truth="Alert Pol."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
74. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[9]).field_description` vs `truth registers[0].field_parts[0].bit_field[9].field_description`: `C=0.0`; truth="Alert Output Polarity bit."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
75. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[9]).bit_start` vs `truth registers[0].field_parts[0].bit_field[9].bit_start`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
76. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[9]).bit_end` vs `truth registers[0].field_parts[0].bit_field[9].bit_end`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
77. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[9]).bit_width` vs `truth registers[0].field_parts[0].bit_field[9].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
78. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[9]).values` vs `truth registers[0].field_parts[0].bit_field[9].values`: `C=0.0`; truth=[{"value":"0","value_description":"Active-low (power-up default; pull-up resistor required)"},{"value":"1","value_description":"Active-high"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
79. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[9]).is_reserved` vs `truth registers[0].field_parts[0].bit_field[9].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
80. `v12 registers[1].field_parts[0].bit_field(no exact range for truth bit_field[9]).type_write_read` vs `truth registers[0].field_parts[0].bit_field[9].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
81. `v12 registers[1].field_parts[0].bit_field[2].name_or_parameter` vs `truth registers[0].field_parts[0].bit_field[10].name_or_parameter`: `C=0.0`; truth="Alert Mod."; extracted="SHDN". The exact range is paired with the wrong SHDN semantic field.
82. `v12 registers[1].field_parts[0].bit_field[2].field_description` vs `truth registers[0].field_parts[0].bit_field[10].field_description`: `C=0.0`; truth="Alert Output Mode bit."; extracted="Shutdown Mode bit. 0 = Continuous conversion (default), 1 = Shutdown (Low-Power mode).". The exact range is paired with the wrong SHDN semantic field.
83. `v12 registers[1].field_parts[0].bit_field[2].values` vs `truth registers[0].field_parts[0].bit_field[10].values`: `C=0.0`; truth=[{"value":"0","value_description":"Comparator output (power-up default)"},{"value":"1","value_description":"Interrupt output"}]; extracted=[{"value":"0","value_description":"Continuous conversion (power-up default)"},{"value":"1","value_description":"Shutdown (Low-Power mode)"}]. The exact range is paired with the wrong SHDN semantic field.
84. `v12 registers[1].field_parts[0].register_name` vs `truth registers[0].field_parts[0].register_name`: `C=0.5`; truth="CONFIG"; extracted="CONFIG[MSB]". The [MSB] suffix identifies only a byte fragment rather than the truth physical-register name.
85. `v12 registers[1].field_parts[0].width_bits` vs `truth registers[0].field_parts[0].width_bits`: `C=0.0`; truth=16; extracted=8. The primary extracted physical field part is 8 bits, while the truth physical register is 16 bits.
86. `v12 registers[1].physical_address` vs `truth registers[0].physical_address`: `C=0.5`; truth=[{"hex":"0x01","decimal":"1","bank":"","page":"","description":""}]; extracted=[{"hex":"0x01","decimal":"1","bank":"","page":"","description":"MSB"},{"hex":"0x02","decimal":"2","bank":"","page":"","description":"LSB"}]. The primary numeric physical address is correct, but the extracted logical register also claims an additional adjacent physical address.
87. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[0]).name_or_parameter` vs `truth registers[1].field_parts[0].bit_field[0].name_or_parameter`: `C=0.0`; truth="Unimplemented"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
88. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[0]).field_description` vs `truth registers[1].field_parts[0].bit_field[0].field_description`: `C=0.0`; truth="Unimplemented; read as '0'."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
89. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_start` vs `truth registers[1].field_parts[0].bit_field[0].bit_start`: `C=0.0`; truth=13; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
90. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_end` vs `truth registers[1].field_parts[0].bit_field[0].bit_end`: `C=0.0`; truth=15; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
91. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_width` vs `truth registers[1].field_parts[0].bit_field[0].bit_width`: `C=0.0`; truth=3; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
92. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[0]).values` vs `truth registers[1].field_parts[0].bit_field[0].values`: `C=0.0`; truth=[]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
93. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[0]).is_reserved` vs `truth registers[1].field_parts[0].bit_field[0].is_reserved`: `C=0.0`; truth=true; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
94. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[0]).type_write_read` vs `truth registers[1].field_parts[0].bit_field[0].type_write_read`: `C=0.0`; truth=""; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
95. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[1]).name_or_parameter` vs `truth registers[1].field_parts[0].bit_field[1].name_or_parameter`: `C=0.0`; truth="Sign"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
96. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[1]).field_description` vs `truth registers[1].field_parts[0].bit_field[1].field_description`: `C=0.0`; truth="Sign bit."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
97. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_start` vs `truth registers[1].field_parts[0].bit_field[1].bit_start`: `C=0.0`; truth=12; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
98. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_end` vs `truth registers[1].field_parts[0].bit_field[1].bit_end`: `C=0.0`; truth=12; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
99. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_width` vs `truth registers[1].field_parts[0].bit_field[1].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
100. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[1]).values` vs `truth registers[1].field_parts[0].bit_field[1].values`: `C=0.0`; truth=[{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
101. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[1]).is_reserved` vs `truth registers[1].field_parts[0].bit_field[1].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
102. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[1]).type_write_read` vs `truth registers[1].field_parts[0].bit_field[1].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
103. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[2]).name_or_parameter` vs `truth registers[1].field_parts[0].bit_field[2].name_or_parameter`: `C=0.0`; truth="TUPPER"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
104. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[2]).field_description` vs `truth registers[1].field_parts[0].bit_field[2].field_description`: `C=0.0`; truth="Upper temperature boundary trip data in two's complement format."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
105. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_start` vs `truth registers[1].field_parts[0].bit_field[2].bit_start`: `C=0.0`; truth=2; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
106. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_end` vs `truth registers[1].field_parts[0].bit_field[2].bit_end`: `C=0.0`; truth=11; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
107. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_width` vs `truth registers[1].field_parts[0].bit_field[2].bit_width`: `C=0.0`; truth=10; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
108. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[2]).values` vs `truth registers[1].field_parts[0].bit_field[2].values`: `C=0.0`; truth=[]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
109. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[2]).is_reserved` vs `truth registers[1].field_parts[0].bit_field[2].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
110. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[2]).type_write_read` vs `truth registers[1].field_parts[0].bit_field[2].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
111. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[3]).name_or_parameter` vs `truth registers[1].field_parts[0].bit_field[3].name_or_parameter`: `C=0.0`; truth="Unimplemented"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
112. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[3]).field_description` vs `truth registers[1].field_parts[0].bit_field[3].field_description`: `C=0.0`; truth="Unimplemented; read as '0'."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
113. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_start` vs `truth registers[1].field_parts[0].bit_field[3].bit_start`: `C=0.0`; truth=0; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
114. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_end` vs `truth registers[1].field_parts[0].bit_field[3].bit_end`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
115. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_width` vs `truth registers[1].field_parts[0].bit_field[3].bit_width`: `C=0.0`; truth=2; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
116. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[3]).values` vs `truth registers[1].field_parts[0].bit_field[3].values`: `C=0.0`; truth=[]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
117. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[3]).is_reserved` vs `truth registers[1].field_parts[0].bit_field[3].is_reserved`: `C=0.0`; truth=true; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
118. `v12 registers[2].field_parts[0].bit_field(no exact range for truth bit_field[3]).type_write_read` vs `truth registers[1].field_parts[0].bit_field[3].type_write_read`: `C=0.0`; truth=""; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
119. `v12 registers[2].field_parts[0].register_name` vs `truth registers[1].field_parts[0].register_name`: `C=0.5`; truth="TUPPER"; extracted="TUPPER[MSB]". The [MSB] suffix identifies only a byte fragment rather than the truth physical-register name.
120. `v12 registers[2].field_parts[0].width_bits` vs `truth registers[1].field_parts[0].width_bits`: `C=0.0`; truth=16; extracted=8. The primary extracted physical field part is 8 bits, while the truth physical register is 16 bits.
121. `v12 registers[2].physical_address` vs `truth registers[1].physical_address`: `C=0.5`; truth=[{"hex":"0x02","decimal":"2","bank":"","page":"","description":""}]; extracted=[{"hex":"0x02","decimal":"2","bank":"","page":"","description":"MSB"},{"hex":"0x03","decimal":"3","bank":"","page":"","description":"LSB"}]. The primary numeric physical address is correct, but the extracted logical register also claims an additional adjacent physical address.
122. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[0]).name_or_parameter` vs `truth registers[2].field_parts[0].bit_field[0].name_or_parameter`: `C=0.0`; truth="Unimplemented"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
123. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[0]).field_description` vs `truth registers[2].field_parts[0].bit_field[0].field_description`: `C=0.0`; truth="Unimplemented; read as '0'."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
124. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_start` vs `truth registers[2].field_parts[0].bit_field[0].bit_start`: `C=0.0`; truth=13; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
125. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_end` vs `truth registers[2].field_parts[0].bit_field[0].bit_end`: `C=0.0`; truth=15; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
126. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_width` vs `truth registers[2].field_parts[0].bit_field[0].bit_width`: `C=0.0`; truth=3; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
127. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[0]).values` vs `truth registers[2].field_parts[0].bit_field[0].values`: `C=0.0`; truth=[]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
128. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[0]).is_reserved` vs `truth registers[2].field_parts[0].bit_field[0].is_reserved`: `C=0.0`; truth=true; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
129. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[0]).type_write_read` vs `truth registers[2].field_parts[0].bit_field[0].type_write_read`: `C=0.0`; truth=""; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
130. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[1]).name_or_parameter` vs `truth registers[2].field_parts[0].bit_field[1].name_or_parameter`: `C=0.0`; truth="Sign"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
131. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[1]).field_description` vs `truth registers[2].field_parts[0].bit_field[1].field_description`: `C=0.0`; truth="Sign bit."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
132. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_start` vs `truth registers[2].field_parts[0].bit_field[1].bit_start`: `C=0.0`; truth=12; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
133. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_end` vs `truth registers[2].field_parts[0].bit_field[1].bit_end`: `C=0.0`; truth=12; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
134. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_width` vs `truth registers[2].field_parts[0].bit_field[1].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
135. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[1]).values` vs `truth registers[2].field_parts[0].bit_field[1].values`: `C=0.0`; truth=[{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
136. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[1]).is_reserved` vs `truth registers[2].field_parts[0].bit_field[1].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
137. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[1]).type_write_read` vs `truth registers[2].field_parts[0].bit_field[1].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
138. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[2]).name_or_parameter` vs `truth registers[2].field_parts[0].bit_field[2].name_or_parameter`: `C=0.0`; truth="TLOWER"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
139. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[2]).field_description` vs `truth registers[2].field_parts[0].bit_field[2].field_description`: `C=0.0`; truth="Lower temperature boundary trip data in two's complement format."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
140. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_start` vs `truth registers[2].field_parts[0].bit_field[2].bit_start`: `C=0.0`; truth=2; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
141. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_end` vs `truth registers[2].field_parts[0].bit_field[2].bit_end`: `C=0.0`; truth=11; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
142. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_width` vs `truth registers[2].field_parts[0].bit_field[2].bit_width`: `C=0.0`; truth=10; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
143. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[2]).values` vs `truth registers[2].field_parts[0].bit_field[2].values`: `C=0.0`; truth=[]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
144. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[2]).is_reserved` vs `truth registers[2].field_parts[0].bit_field[2].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
145. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[2]).type_write_read` vs `truth registers[2].field_parts[0].bit_field[2].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
146. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[3]).name_or_parameter` vs `truth registers[2].field_parts[0].bit_field[3].name_or_parameter`: `C=0.0`; truth="Unimplemented"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
147. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[3]).field_description` vs `truth registers[2].field_parts[0].bit_field[3].field_description`: `C=0.0`; truth="Unimplemented; read as '0'."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
148. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_start` vs `truth registers[2].field_parts[0].bit_field[3].bit_start`: `C=0.0`; truth=0; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
149. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_end` vs `truth registers[2].field_parts[0].bit_field[3].bit_end`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
150. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_width` vs `truth registers[2].field_parts[0].bit_field[3].bit_width`: `C=0.0`; truth=2; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
151. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[3]).values` vs `truth registers[2].field_parts[0].bit_field[3].values`: `C=0.0`; truth=[]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
152. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[3]).is_reserved` vs `truth registers[2].field_parts[0].bit_field[3].is_reserved`: `C=0.0`; truth=true; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
153. `v12 registers[3].field_parts[0].bit_field(no exact range for truth bit_field[3]).type_write_read` vs `truth registers[2].field_parts[0].bit_field[3].type_write_read`: `C=0.0`; truth=""; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
154. `v12 registers[3].field_parts[0].register_name` vs `truth registers[2].field_parts[0].register_name`: `C=0.5`; truth="TLOWER"; extracted="TLOWER[MSB]". The [MSB] suffix identifies only a byte fragment rather than the truth physical-register name.
155. `v12 registers[3].field_parts[0].width_bits` vs `truth registers[2].field_parts[0].width_bits`: `C=0.0`; truth=16; extracted=8. The primary extracted physical field part is 8 bits, while the truth physical register is 16 bits.
156. `v12 registers[3].physical_address` vs `truth registers[2].physical_address`: `C=0.5`; truth=[{"hex":"0x03","decimal":"3","bank":"","page":"","description":""}]; extracted=[{"hex":"0x03","decimal":"3","bank":"","page":"","description":"MSB"},{"hex":"0x04","decimal":"4","bank":"","page":"","description":"LSB"}]. The primary numeric physical address is correct, but the extracted logical register also claims an additional adjacent physical address.
157. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[0]).name_or_parameter` vs `truth registers[3].field_parts[0].bit_field[0].name_or_parameter`: `C=0.0`; truth="Unimplemented"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
158. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[0]).field_description` vs `truth registers[3].field_parts[0].bit_field[0].field_description`: `C=0.0`; truth="Unimplemented; read as '0'."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
159. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_start` vs `truth registers[3].field_parts[0].bit_field[0].bit_start`: `C=0.0`; truth=13; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
160. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_end` vs `truth registers[3].field_parts[0].bit_field[0].bit_end`: `C=0.0`; truth=15; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
161. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_width` vs `truth registers[3].field_parts[0].bit_field[0].bit_width`: `C=0.0`; truth=3; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
162. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[0]).values` vs `truth registers[3].field_parts[0].bit_field[0].values`: `C=0.0`; truth=[]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
163. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[0]).is_reserved` vs `truth registers[3].field_parts[0].bit_field[0].is_reserved`: `C=0.0`; truth=true; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
164. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[0]).type_write_read` vs `truth registers[3].field_parts[0].bit_field[0].type_write_read`: `C=0.0`; truth=""; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
165. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[1]).name_or_parameter` vs `truth registers[3].field_parts[0].bit_field[1].name_or_parameter`: `C=0.0`; truth="Sign"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
166. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[1]).field_description` vs `truth registers[3].field_parts[0].bit_field[1].field_description`: `C=0.0`; truth="Sign bit."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
167. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_start` vs `truth registers[3].field_parts[0].bit_field[1].bit_start`: `C=0.0`; truth=12; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
168. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_end` vs `truth registers[3].field_parts[0].bit_field[1].bit_end`: `C=0.0`; truth=12; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
169. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_width` vs `truth registers[3].field_parts[0].bit_field[1].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
170. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[1]).values` vs `truth registers[3].field_parts[0].bit_field[1].values`: `C=0.0`; truth=[{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
171. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[1]).is_reserved` vs `truth registers[3].field_parts[0].bit_field[1].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
172. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[1]).type_write_read` vs `truth registers[3].field_parts[0].bit_field[1].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
173. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[2]).name_or_parameter` vs `truth registers[3].field_parts[0].bit_field[2].name_or_parameter`: `C=0.0`; truth="TCRIT"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
174. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[2]).field_description` vs `truth registers[3].field_parts[0].bit_field[2].field_description`: `C=0.0`; truth="Critical temperature boundary trip data in two's complement format."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
175. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_start` vs `truth registers[3].field_parts[0].bit_field[2].bit_start`: `C=0.0`; truth=2; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
176. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_end` vs `truth registers[3].field_parts[0].bit_field[2].bit_end`: `C=0.0`; truth=11; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
177. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_width` vs `truth registers[3].field_parts[0].bit_field[2].bit_width`: `C=0.0`; truth=10; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
178. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[2]).values` vs `truth registers[3].field_parts[0].bit_field[2].values`: `C=0.0`; truth=[]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
179. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[2]).is_reserved` vs `truth registers[3].field_parts[0].bit_field[2].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
180. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[2]).type_write_read` vs `truth registers[3].field_parts[0].bit_field[2].type_write_read`: `C=0.0`; truth="RW"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
181. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[3]).name_or_parameter` vs `truth registers[3].field_parts[0].bit_field[3].name_or_parameter`: `C=0.0`; truth="Unimplemented"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
182. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[3]).field_description` vs `truth registers[3].field_parts[0].bit_field[3].field_description`: `C=0.0`; truth="Unimplemented; read as '0'."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
183. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_start` vs `truth registers[3].field_parts[0].bit_field[3].bit_start`: `C=0.0`; truth=0; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
184. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_end` vs `truth registers[3].field_parts[0].bit_field[3].bit_end`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
185. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_width` vs `truth registers[3].field_parts[0].bit_field[3].bit_width`: `C=0.0`; truth=2; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
186. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[3]).values` vs `truth registers[3].field_parts[0].bit_field[3].values`: `C=0.0`; truth=[]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
187. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[3]).is_reserved` vs `truth registers[3].field_parts[0].bit_field[3].is_reserved`: `C=0.0`; truth=true; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
188. `v12 registers[4].field_parts[0].bit_field(no exact range for truth bit_field[3]).type_write_read` vs `truth registers[3].field_parts[0].bit_field[3].type_write_read`: `C=0.0`; truth=""; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
189. `v12 registers[4].field_parts[0].register_name` vs `truth registers[3].field_parts[0].register_name`: `C=0.5`; truth="TCRIT"; extracted="TCRIT[MSB]". The [MSB] suffix identifies only a byte fragment rather than the truth physical-register name.
190. `v12 registers[4].field_parts[0].width_bits` vs `truth registers[3].field_parts[0].width_bits`: `C=0.0`; truth=16; extracted=8. The primary extracted physical field part is 8 bits, while the truth physical register is 16 bits.
191. `v12 registers[4].physical_address` vs `truth registers[3].physical_address`: `C=0.5`; truth=[{"hex":"0x04","decimal":"4","bank":"","page":"","description":""}]; extracted=[{"hex":"0x04","decimal":"4","bank":"","page":"","description":"MSB"},{"hex":"0x05","decimal":"5","bank":"","page":"","description":"LSB"}]. The primary numeric physical address is correct, but the extracted logical register also claims an additional adjacent physical address.
192. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[0]).name_or_parameter` vs `truth registers[4].field_parts[0].bit_field[0].name_or_parameter`: `C=0.0`; truth="TA vs. TCRIT"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
193. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[0]).field_description` vs `truth registers[4].field_parts[0].bit_field[0].field_description`: `C=0.0`; truth="Indicates whether ambient temperature is at or above the critical limit."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
194. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_start` vs `truth registers[4].field_parts[0].bit_field[0].bit_start`: `C=0.0`; truth=15; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
195. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_end` vs `truth registers[4].field_parts[0].bit_field[0].bit_end`: `C=0.0`; truth=15; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
196. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_width` vs `truth registers[4].field_parts[0].bit_field[0].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
197. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[0]).values` vs `truth registers[4].field_parts[0].bit_field[0].values`: `C=0.0`; truth=[{"value":"0","value_description":"T_A < T_CRIT"},{"value":"1","value_description":"T_A ≥ T_CRIT"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
198. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[0]).is_reserved` vs `truth registers[4].field_parts[0].bit_field[0].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
199. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[0]).type_write_read` vs `truth registers[4].field_parts[0].bit_field[0].type_write_read`: `C=0.0`; truth="R"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
200. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[1]).name_or_parameter` vs `truth registers[4].field_parts[0].bit_field[1].name_or_parameter`: `C=0.0`; truth="TA vs. TUPPER"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
201. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[1]).field_description` vs `truth registers[4].field_parts[0].bit_field[1].field_description`: `C=0.0`; truth="Indicates whether ambient temperature is above the upper boundary."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
202. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_start` vs `truth registers[4].field_parts[0].bit_field[1].bit_start`: `C=0.0`; truth=14; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
203. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_end` vs `truth registers[4].field_parts[0].bit_field[1].bit_end`: `C=0.0`; truth=14; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
204. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[1]).bit_width` vs `truth registers[4].field_parts[0].bit_field[1].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
205. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[1]).values` vs `truth registers[4].field_parts[0].bit_field[1].values`: `C=0.0`; truth=[{"value":"0","value_description":"T_A ≤ T_UPPER"},{"value":"1","value_description":"T_A > T_UPPER"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
206. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[1]).is_reserved` vs `truth registers[4].field_parts[0].bit_field[1].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
207. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[1]).type_write_read` vs `truth registers[4].field_parts[0].bit_field[1].type_write_read`: `C=0.0`; truth="R"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
208. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[2]).name_or_parameter` vs `truth registers[4].field_parts[0].bit_field[2].name_or_parameter`: `C=0.0`; truth="TA vs. TLOWER"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
209. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[2]).field_description` vs `truth registers[4].field_parts[0].bit_field[2].field_description`: `C=0.0`; truth="Indicates whether ambient temperature is below the lower boundary."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
210. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_start` vs `truth registers[4].field_parts[0].bit_field[2].bit_start`: `C=0.0`; truth=13; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
211. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_end` vs `truth registers[4].field_parts[0].bit_field[2].bit_end`: `C=0.0`; truth=13; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
212. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[2]).bit_width` vs `truth registers[4].field_parts[0].bit_field[2].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
213. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[2]).values` vs `truth registers[4].field_parts[0].bit_field[2].values`: `C=0.0`; truth=[{"value":"0","value_description":"T_A ≥ T_LOWER"},{"value":"1","value_description":"T_A < T_LOWER"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
214. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[2]).is_reserved` vs `truth registers[4].field_parts[0].bit_field[2].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
215. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[2]).type_write_read` vs `truth registers[4].field_parts[0].bit_field[2].type_write_read`: `C=0.0`; truth="R"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
216. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[3]).name_or_parameter` vs `truth registers[4].field_parts[0].bit_field[3].name_or_parameter`: `C=0.0`; truth="SIGN"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
217. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[3]).field_description` vs `truth registers[4].field_parts[0].bit_field[3].field_description`: `C=0.0`; truth="Ambient temperature sign bit."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
218. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_start` vs `truth registers[4].field_parts[0].bit_field[3].bit_start`: `C=0.0`; truth=12; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
219. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_end` vs `truth registers[4].field_parts[0].bit_field[3].bit_end`: `C=0.0`; truth=12; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
220. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[3]).bit_width` vs `truth registers[4].field_parts[0].bit_field[3].bit_width`: `C=0.0`; truth=1; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
221. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[3]).values` vs `truth registers[4].field_parts[0].bit_field[3].values`: `C=0.0`; truth=[{"value":"0","value_description":"T_A ≥ 0°C"},{"value":"1","value_description":"T_A < 0°C"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
222. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[3]).is_reserved` vs `truth registers[4].field_parts[0].bit_field[3].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
223. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[3]).type_write_read` vs `truth registers[4].field_parts[0].bit_field[3].type_write_read`: `C=0.0`; truth="R"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
224. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[4]).name_or_parameter` vs `truth registers[4].field_parts[0].bit_field[4].name_or_parameter`: `C=0.0`; truth="TA"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
225. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[4]).field_description` vs `truth registers[4].field_parts[0].bit_field[4].field_description`: `C=0.0`; truth="12-bit ambient temperature data in two's complement format."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
226. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[4]).bit_start` vs `truth registers[4].field_parts[0].bit_field[4].bit_start`: `C=0.0`; truth=0; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
227. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[4]).bit_end` vs `truth registers[4].field_parts[0].bit_field[4].bit_end`: `C=0.0`; truth=11; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
228. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[4]).bit_width` vs `truth registers[4].field_parts[0].bit_field[4].bit_width`: `C=0.0`; truth=12; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
229. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[4]).values` vs `truth registers[4].field_parts[0].bit_field[4].values`: `C=0.0`; truth=[]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
230. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[4]).is_reserved` vs `truth registers[4].field_parts[0].bit_field[4].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
231. `v12 registers[5].field_parts[0].bit_field(no exact range for truth bit_field[4]).type_write_read` vs `truth registers[4].field_parts[0].bit_field[4].type_write_read`: `C=0.0`; truth="R"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
232. `v12 registers[5].field_parts[0].register_name` vs `truth registers[4].field_parts[0].register_name`: `C=0.5`; truth="TA"; extracted="TA[MSB]". The [MSB] suffix identifies only a byte fragment rather than the truth physical-register name.
233. `v12 registers[5].field_parts[0].width_bits` vs `truth registers[4].field_parts[0].width_bits`: `C=0.0`; truth=16; extracted=8. The primary extracted physical field part is 8 bits, while the truth physical register is 16 bits.
234. `v12 registers[5].physical_address` vs `truth registers[4].physical_address`: `C=0.5`; truth=[{"hex":"0x05","decimal":"5","bank":"","page":"","description":""}]; extracted=[{"hex":"0x05","decimal":"5","bank":"","page":"","description":"MSB"},{"hex":"0x06","decimal":"6","bank":"","page":"","description":"LSB"}]. The primary numeric physical address is correct, but the extracted logical register also claims an additional adjacent physical address.
235. `v12 registers[6].field_parts[0].bit_field(no exact range for truth bit_field[0]).name_or_parameter` vs `truth registers[5].field_parts[0].bit_field[0].name_or_parameter`: `C=0.0`; truth="Manufacturer ID"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
236. `v12 registers[6].field_parts[0].bit_field(no exact range for truth bit_field[0]).field_description` vs `truth registers[5].field_parts[0].bit_field[0].field_description`: `C=0.0`; truth="Device Manufacturer Identification bits."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
237. `v12 registers[6].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_start` vs `truth registers[5].field_parts[0].bit_field[0].bit_start`: `C=0.0`; truth=0; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
238. `v12 registers[6].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_end` vs `truth registers[5].field_parts[0].bit_field[0].bit_end`: `C=0.0`; truth=15; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
239. `v12 registers[6].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_width` vs `truth registers[5].field_parts[0].bit_field[0].bit_width`: `C=0.0`; truth=16; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
240. `v12 registers[6].field_parts[0].bit_field(no exact range for truth bit_field[0]).values` vs `truth registers[5].field_parts[0].bit_field[0].values`: `C=0.0`; truth=[{"value":"0x0054","value_description":"Manufacturer ID for the MCP9808"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
241. `v12 registers[6].field_parts[0].bit_field(no exact range for truth bit_field[0]).is_reserved` vs `truth registers[5].field_parts[0].bit_field[0].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
242. `v12 registers[6].field_parts[0].bit_field(no exact range for truth bit_field[0]).type_write_read` vs `truth registers[5].field_parts[0].bit_field[0].type_write_read`: `C=0.0`; truth="R"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
243. `v12 registers[6].field_parts[0].register_name` vs `truth registers[5].field_parts[0].register_name`: `C=0.5`; truth="Manufacturer ID"; extracted="Manufacturer ID[MSB]". The [MSB] suffix identifies only a byte fragment rather than the truth physical-register name.
244. `v12 registers[6].field_parts[0].width_bits` vs `truth registers[5].field_parts[0].width_bits`: `C=0.0`; truth=16; extracted=8. The primary extracted physical field part is 8 bits, while the truth physical register is 16 bits.
245. `v12 registers[6].physical_address` vs `truth registers[5].physical_address`: `C=0.5`; truth=[{"hex":"0x06","decimal":"6","bank":"","page":"","description":""}]; extracted=[{"hex":"0x06","decimal":"6","bank":"","page":"","description":"MSB"},{"hex":"0x07","decimal":"7","bank":"","page":"","description":"LSB"}]. The primary numeric physical address is correct, but the extracted logical register also claims an additional adjacent physical address.
246. `v12 registers[7].field_parts[0].bit_field(no exact range for truth bit_field[0]).name_or_parameter` vs `truth registers[6].field_parts[0].bit_field[0].name_or_parameter`: `C=0.0`; truth="Device ID"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
247. `v12 registers[7].field_parts[0].bit_field(no exact range for truth bit_field[0]).field_description` vs `truth registers[6].field_parts[0].bit_field[0].field_description`: `C=0.0`; truth="Device identification bits."; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
248. `v12 registers[7].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_start` vs `truth registers[6].field_parts[0].bit_field[0].bit_start`: `C=0.0`; truth=8; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
249. `v12 registers[7].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_end` vs `truth registers[6].field_parts[0].bit_field[0].bit_end`: `C=0.0`; truth=15; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
250. `v12 registers[7].field_parts[0].bit_field(no exact range for truth bit_field[0]).bit_width` vs `truth registers[6].field_parts[0].bit_field[0].bit_width`: `C=0.0`; truth=8; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
251. `v12 registers[7].field_parts[0].bit_field(no exact range for truth bit_field[0]).values` vs `truth registers[6].field_parts[0].bit_field[0].values`: `C=0.0`; truth=[{"value":"0x04","value_description":"Device ID for the MCP9808"}]; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
252. `v12 registers[7].field_parts[0].bit_field(no exact range for truth bit_field[0]).is_reserved` vs `truth registers[6].field_parts[0].bit_field[0].is_reserved`: `C=0.0`; truth=false; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
253. `v12 registers[7].field_parts[0].bit_field(no exact range for truth bit_field[0]).type_write_read` vs `truth registers[6].field_parts[0].bit_field[0].type_write_read`: `C=0.0`; truth="R"; extracted="MISSING". The truth bit field has no exact ordered range target in the matched primary byte-local field part.
254. `v12 registers[7].field_parts[0].bit_field[0].name_or_parameter` vs `truth registers[6].field_parts[0].bit_field[1].name_or_parameter`: `C=0.0`; truth="Device Revision"; extracted="Device ID". The extracted range is reversed; structural leaves are not aligned.
255. `v12 registers[7].field_parts[0].bit_field[0].field_description` vs `truth registers[6].field_parts[0].bit_field[1].field_description`: `C=0.0`; truth="Device revision bits."; extracted="Bit 15 to bit 8 are used for device ID. MCP9808 Device ID is 0x04.". The extracted range is reversed; structural leaves are not aligned.
256. `v12 registers[7].field_parts[0].bit_field[0].bit_start` vs `truth registers[6].field_parts[0].bit_field[1].bit_start`: `C=0.0`; truth=0; extracted=7. The extracted range is reversed; structural leaves are not aligned.
257. `v12 registers[7].field_parts[0].bit_field[0].bit_end` vs `truth registers[6].field_parts[0].bit_field[1].bit_end`: `C=0.0`; truth=7; extracted=0. The extracted range is reversed; structural leaves are not aligned.
258. `v12 registers[7].field_parts[0].bit_field[0].bit_width` vs `truth registers[6].field_parts[0].bit_field[1].bit_width`: `C=0.0`; truth=8; extracted=8. The extracted range is reversed; structural leaves are not aligned.
259. `v12 registers[7].field_parts[0].bit_field[0].values` vs `truth registers[6].field_parts[0].bit_field[1].values`: `C=0.0`; truth=[{"value":"0x00","value_description":"First release revision; incremented for revised versions"}]; extracted=[]. The extracted range is reversed; structural leaves are not aligned.
260. `v12 registers[7].field_parts[0].bit_field[0].is_reserved` vs `truth registers[6].field_parts[0].bit_field[1].is_reserved`: `C=0.0`; truth=false; extracted=false. The extracted range is reversed; structural leaves are not aligned.
261. `v12 registers[7].field_parts[0].bit_field[0].type_write_read` vs `truth registers[6].field_parts[0].bit_field[1].type_write_read`: `C=0.0`; truth="R"; extracted="R". The extracted range is reversed; structural leaves are not aligned.
262. `v12 registers[7].field_parts[0].register_name` vs `truth registers[6].field_parts[0].register_name`: `C=0.5`; truth="Device ID/Revision"; extracted="Device ID/Revision[MSB]". The [MSB] suffix identifies only a byte fragment rather than the truth physical-register name.
263. `v12 registers[7].field_parts[0].width_bits` vs `truth registers[6].field_parts[0].width_bits`: `C=0.0`; truth=16; extracted=8. The primary extracted physical field part is 8 bits, while the truth physical register is 16 bits.
264. `v12 registers[7].physical_address` vs `truth registers[6].physical_address`: `C=0.5`; truth=[{"hex":"0x07","decimal":"7","bank":"","page":"","description":""}]; extracted=[{"hex":"0x07","decimal":"7","bank":"","page":"","description":"MSB"},{"hex":"0x08","decimal":"8","bank":"","page":"","description":"LSB"}]. The primary numeric physical address is correct, but the extracted logical register also claims an additional adjacent physical address.
265. `v12 registers[8].field_parts[0].bit_field[0].name_or_parameter` vs `truth registers[7].field_parts[0].bit_field[0].name_or_parameter`: `C=0.0`; truth="Unimplemented"; extracted="Unimplemented". The extracted range is reversed; structural leaves are not aligned.
266. `v12 registers[8].field_parts[0].bit_field[0].field_description` vs `truth registers[7].field_parts[0].bit_field[0].field_description`: `C=0.0`; truth="Unimplemented; read as '0'."; extracted="Read as '0'". The extracted range is reversed; structural leaves are not aligned.
267. `v12 registers[8].field_parts[0].bit_field[0].bit_start` vs `truth registers[7].field_parts[0].bit_field[0].bit_start`: `C=0.0`; truth=2; extracted=7. The extracted range is reversed; structural leaves are not aligned.
268. `v12 registers[8].field_parts[0].bit_field[0].bit_end` vs `truth registers[7].field_parts[0].bit_field[0].bit_end`: `C=0.0`; truth=7; extracted=2. The extracted range is reversed; structural leaves are not aligned.
269. `v12 registers[8].field_parts[0].bit_field[0].bit_width` vs `truth registers[7].field_parts[0].bit_field[0].bit_width`: `C=0.0`; truth=6; extracted=6. The extracted range is reversed; structural leaves are not aligned.
270. `v12 registers[8].field_parts[0].bit_field[0].values` vs `truth registers[7].field_parts[0].bit_field[0].values`: `C=0.0`; truth=[]; extracted=[]. The extracted range is reversed; structural leaves are not aligned.
271. `v12 registers[8].field_parts[0].bit_field[0].is_reserved` vs `truth registers[7].field_parts[0].bit_field[0].is_reserved`: `C=0.0`; truth=true; extracted=true. The extracted range is reversed; structural leaves are not aligned.
272. `v12 registers[8].field_parts[0].bit_field[1].name_or_parameter` vs `truth registers[7].field_parts[0].bit_field[1].name_or_parameter`: `C=0.0`; truth="Resolution"; extracted="Resolution". The extracted range is reversed; structural leaves are not aligned.
273. `v12 registers[8].field_parts[0].bit_field[1].field_description` vs `truth registers[7].field_parts[0].bit_field[1].field_description`: `C=0.0`; truth="Sensor resolution selection."; extracted="Resolution bits. 00 = +0.5°C, 01 = +0.25°C, 10 = +0.125°C, 11 = +0.0625°C (default).". The extracted range is reversed; structural leaves are not aligned.
274. `v12 registers[8].field_parts[0].bit_field[1].bit_start` vs `truth registers[7].field_parts[0].bit_field[1].bit_start`: `C=0.0`; truth=0; extracted=1. The extracted range is reversed; structural leaves are not aligned.
275. `v12 registers[8].field_parts[0].bit_field[1].bit_end` vs `truth registers[7].field_parts[0].bit_field[1].bit_end`: `C=0.0`; truth=1; extracted=0. The extracted range is reversed; structural leaves are not aligned.
276. `v12 registers[8].field_parts[0].bit_field[1].bit_width` vs `truth registers[7].field_parts[0].bit_field[1].bit_width`: `C=0.0`; truth=2; extracted=2. The extracted range is reversed; structural leaves are not aligned.
277. `v12 registers[8].field_parts[0].bit_field[1].values` vs `truth registers[7].field_parts[0].bit_field[1].values`: `C=0.0`; truth=[{"value":"00","value_description":"+0.5°C (t_CONV = 30 ms typical)"},{"value":"01","value_description":"+0.25°C (t_CONV = 65 ms typical)"},{"value":"10","value_description":"+0.125°C (t_CONV = 130 ms typical)"},{"value":"11","value_description":"+0.0625°C (power-up default, t_CONV = 250 ms typical)"}]; extracted=[{"value":"00","value_description":"+0.5°C (t_CONV = 30 ms typical)"},{"value":"01","value_description":"+0.25°C (t_CONV = 65 ms typical)"},{"value":"10","value_description":"+0.125°C (t_CONV = 130 ms typical)"},{"value":"11","value_description":"+0.0625°C (power-up default, t_CONV = 250 ms typical)"}]. The extracted range is reversed; structural leaves are not aligned.
278. `v12 registers[8].field_parts[0].bit_field[1].is_reserved` vs `truth registers[7].field_parts[0].bit_field[1].is_reserved`: `C=0.0`; truth=false; extracted=false. The extracted range is reversed; structural leaves are not aligned.
279. `v12 registers[8].field_parts[0].bit_field[1].type_write_read` vs `truth registers[7].field_parts[0].bit_field[1].type_write_read`: `C=0.0`; truth="RW"; extracted="RW". The extracted range is reversed; structural leaves are not aligned.

The full scored-field tables above show every leaf C value. Missing exact-range bit fields are intentionally listed as missing rather than paired with a merely covering byte fragment.

### 3.2 Recorded reserved register and extra field-part claims

- Recorded reserved physical location: `v12 registers[0]` (`RFU`) at `0x00` (`0`); it is outside the truth physical-register set but is explicitly reserved, so it is excluded from `x` and incurs no deduction under the revised rule.
- Complete extra logical-register content at `v12 registers[0]`: {"index":1,"name":"RFU","is_multi_address":false,"physical_address":[{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Reserved for Future Use (Read-Only register)"}],"register_description":"Reserved for Future Use. Read-Only register.","width_bits":null,"type_write_read":"R","field_parts":[{"register_name":"RFU","physical_address":{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Reserved for Future Use (Read-Only register)"},"description":"Reserved for Future Use. Read-Only.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Unimplemented","field_description":"Read as '0'","bit_start":7,"bit_end":4,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Pointer bits","field_description":"0000 = RFU, Reserved for Future Use","bit_start":3,"bit_end":0,"bit_width":4,"values":[{"value":"0000","value_description":"RFU, Reserved for Future Use"}],"is_reserved":true,"type_write_read":"R"}]}],"category":"","source":[{"page_index":15}],"default_value":"","default_value_description":""}.
- The following additional field-part entries lie outside their matched primary field-part targets. Seven claim addresses belonging to adjacent truth registers remain non-reserved structural claims and are not included in the matched primary field-part means. The RFU entry is recorded reserved, so it is excluded from deductions and likewise is not included in the truth means:

| v12 location | Claimed address | Extracted content | Treatment |
|---|---|---|---|
| `v12 registers[0].field_parts[0]` | `0x00 (0)` | {"register_name":"RFU","physical_address":{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Reserved for Future Use (Read-Only register)"},"description":"Reserved for Future Use. Read-Only.","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Unimplemented","field_description":"Read as '0'","bit_start":7,"bit_end":4,"bit_width":4,"values":[],"is_reserved":true,"type_write_read":""},{"name_or_parameter":"Pointer bits","field_description":"0000 = RFU, Reserved for Future Use","bit_start":3,"bit_end":0,"bit_width":4,"values":[{"value":"0000","value_description":"RFU, Reserved for Future Use"}],"is_reserved":true,"type_write_read":"R"}]} | recorded reserved register; excluded from deductions and not credited to truth means |
| `v12 registers[1].field_parts[1]` | `0x02 (2)` | {"register_name":"CONFIG[LSB]","physical_address":{"hex":"0x02","decimal":"2","bank":"","page":"","description":"LSB"},"description":"Configuration register LSB byte (bits 7-0).","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"Crit. Lock","field_description":"T_CRIT Lock bit. 0 = Unlocked, 1 = Locked.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Unlocked. T_CRIT register can be written (power-up default)"},{"value":"1","value_description":"Locked. T_CRIT register cannot be written"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Win. Lock","field_description":"T_UPPER and T_LOWER Window Lock bit. 0 = Unlocked, 1 = Locked.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Unlocked; T_UPPER and T_LOWER registers can be written (power-up default)"},{"value":"1","value_description":"Locked; T_UPPER and T_LOWER registers cannot be written"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Int. Clear","field_description":"Interrupt Clear bit. 0 = No effect, 1 = Clear interrupt output.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No effect (power-up default)"},{"value":"1","value_description":"Clear interrupt output; when read, this bit returns to '0'"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Alert Stat.","field_description":"Alert Output Status bit. 0 = Not asserted, 1 = Asserted.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Alert output is not asserted by the device (power-up default)"},{"value":"1","value_description":"Alert output is asserted as a comparator/Interrupt or critical temperature output"}],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Alert Cnt.","field_description":"Alert Output Control bit. 0 = Disabled, 1 = Enabled.","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"Disabled (power-up default)"},{"value":"1","value_description":"Enabled"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Alert Sel.","field_description":"Alert Output Select bit. 0 = Alert for T_UPPER, T_LOWER and T_CRIT, 1 = T_A > T_CRIT only.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Alert output for T_UPPER, T_LOWER and T_CRIT (power-up default)"},{"value":"1","value_description":"T_A > T_CRIT only"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Alert Pol.","field_description":"Alert Output Polarity bit. 0 = Active-low, 1 = Active-high.","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Active-low (power-up default; pull-up resistor required)"},{"value":"1","value_description":"Active-high"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Alert Mod.","field_description":"Alert Output Mode bit. 0 = Comparator output, 1 = Interrupt output.","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Comparator output (power-up default)"},{"value":"1","value_description":"Interrupt output"}],"is_reserved":false,"type_write_read":"RW"}]} | extra/unmatched physical field-part claim; not credited |
| `v12 registers[2].field_parts[1]` | `0x03 (3)` | {"register_name":"TUPPER[LSB]","physical_address":{"hex":"0x03","decimal":"3","bank":"","page":"","description":"LSB"},"description":"TUPPER register LSB byte (bits 7-0).","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"2^3°C","field_description":"Temperature data bit (2^3°C weight).","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^2°C","field_description":"Temperature data bit (2^2°C weight).","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^1°C","field_description":"Temperature data bit (2^1°C weight).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^0°C","field_description":"Temperature data bit (2^0°C weight).","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^-1°C","field_description":"Temperature data bit (2^-1°C weight).","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^-2°C","field_description":"Temperature data bit (2^-2°C weight).","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Unimplemented","field_description":"Read as '0'","bit_start":1,"bit_end":0,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""}]} | extra/unmatched physical field-part claim; not credited |
| `v12 registers[3].field_parts[1]` | `0x04 (4)` | {"register_name":"TLOWER[LSB]","physical_address":{"hex":"0x04","decimal":"4","bank":"","page":"","description":"LSB"},"description":"TLOWER register LSB byte (bits 7-0).","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"2^3°C","field_description":"Temperature data bit (2^3°C weight).","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^2°C","field_description":"Temperature data bit (2^2°C weight).","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^1°C","field_description":"Temperature data bit (2^1°C weight).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^0°C","field_description":"Temperature data bit (2^0°C weight).","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^-1°C","field_description":"Temperature data bit (2^-1°C weight).","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^-2°C","field_description":"Temperature data bit (2^-2°C weight).","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Unimplemented","field_description":"Read as '0'","bit_start":1,"bit_end":0,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""}]} | extra/unmatched physical field-part claim; not credited |
| `v12 registers[4].field_parts[1]` | `0x05 (5)` | {"register_name":"TCRIT[LSB]","physical_address":{"hex":"0x05","decimal":"5","bank":"","page":"","description":"LSB"},"description":"TCRIT register LSB byte (bits 7-0).","width_bits":8,"type_write_read":"RW","bit_field":[{"name_or_parameter":"2^3°C","field_description":"Temperature data bit (2^3°C weight).","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^2°C","field_description":"Temperature data bit (2^2°C weight).","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^1°C","field_description":"Temperature data bit (2^1°C weight).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^0°C","field_description":"Temperature data bit (2^0°C weight).","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^-1°C","field_description":"Temperature data bit (2^-1°C weight).","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"2^-2°C","field_description":"Temperature data bit (2^-2°C weight).","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Unimplemented","field_description":"Read as '0'","bit_start":1,"bit_end":0,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""}]} | extra/unmatched physical field-part claim; not credited |
| `v12 registers[5].field_parts[1]` | `0x06 (6)` | {"register_name":"TA[LSB]","physical_address":{"hex":"0x06","decimal":"6","bank":"","page":"","description":"LSB"},"description":"TA register LSB byte (bits 7-0).","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"2^3°C","field_description":"Temperature data bit (2^3°C weight).","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2^2°C","field_description":"Temperature data bit (2^2°C weight).","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2^1°C","field_description":"Temperature data bit (2^1°C weight).","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2^0°C","field_description":"Temperature data bit (2^0°C weight).","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2^-1°C","field_description":"Temperature data bit (2^-1°C weight).","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2^-2°C","field_description":"Temperature data bit (2^-2°C weight).","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2^-3°C","field_description":"Temperature data bit (2^-3°C weight). May remain clear depending on Resolution register.","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"2^-4°C","field_description":"Temperature data bit (2^-4°C weight). May remain clear depending on Resolution register.","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}]} | extra/unmatched physical field-part claim; not credited |
| `v12 registers[6].field_parts[1]` | `0x07 (7)` | {"register_name":"Manufacturer ID[LSB]","physical_address":{"hex":"0x07","decimal":"7","bank":"","page":"","description":"LSB"},"description":"Manufacturer ID register LSB byte (bits 7-0).","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Manufacturer ID","field_description":"Device Manufacturer Identification bits (LSB).","bit_start":7,"bit_end":0,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]} | extra/unmatched physical field-part claim; not credited |
| `v12 registers[7].field_parts[1]` | `0x08 (8)` | {"register_name":"Device ID/Revision[LSB]","physical_address":{"hex":"0x08","decimal":"8","bank":"","page":"","description":"LSB"},"description":"Device Revision byte (bits 7-0).","width_bits":8,"type_write_read":"R","bit_field":[{"name_or_parameter":"Device Revision","field_description":"Bit 7 to bit 0 are used for device revision. Starts at 0x00.","bit_start":7,"bit_end":0,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}]} | extra/unmatched physical field-part claim; not credited |

### 3.3 Unmatched extracted bit fields

These extracted bit fields have no exact truth bit_start/bit_end target within the matched primary field part or belong to an extra field part. They are shown for auditability and are not independently added to the truth bit-field mean.

| v12 location | Range | Name | Reserved | Access | Treatment |
|---|---|---|---|---|---|
| `v12 registers[0].field_parts[0].bit_field[0]` | `7:4` | "Unimplemented" | true | "" | no exact truth target; not credited |
| `v12 registers[0].field_parts[0].bit_field[1]` | `3:0` | "Pointer bits" | true | "R" | no exact truth target; not credited |
| `v12 registers[1].field_parts[0].bit_field[0]` | `7:4` | "Unimplemented" | true | "" | no exact truth target; not credited |
| `v12 registers[1].field_parts[0].bit_field[1]` | `2:3` | "T_HYST" | false | "RW" | no exact truth target; not credited |
| `v12 registers[1].field_parts[1].bit_field[0]` | `7:7` | "Crit. Lock" | false | "RW" | no exact truth target; not credited |
| `v12 registers[1].field_parts[1].bit_field[1]` | `6:6` | "Win. Lock" | false | "RW" | no exact truth target; not credited |
| `v12 registers[1].field_parts[1].bit_field[2]` | `5:5` | "Int. Clear" | false | "RW" | no exact truth target; not credited |
| `v12 registers[1].field_parts[1].bit_field[3]` | `4:4` | "Alert Stat." | false | "R" | no exact truth target; not credited |
| `v12 registers[1].field_parts[1].bit_field[4]` | `3:3` | "Alert Cnt." | false | "RW" | no exact truth target; not credited |
| `v12 registers[1].field_parts[1].bit_field[5]` | `2:2` | "Alert Sel." | false | "RW" | no exact truth target; not credited |
| `v12 registers[1].field_parts[1].bit_field[6]` | `1:1` | "Alert Pol." | false | "RW" | no exact truth target; not credited |
| `v12 registers[1].field_parts[1].bit_field[7]` | `0:0` | "Alert Mod." | false | "RW" | no exact truth target; not credited |
| `v12 registers[2].field_parts[0].bit_field[0]` | `7:5` | "Unimplemented" | true | "" | no exact truth target; not credited |
| `v12 registers[2].field_parts[0].bit_field[1]` | `4:4` | "SIGN" | false | "RW" | no exact truth target; not credited |
| `v12 registers[2].field_parts[0].bit_field[2]` | `3:3` | "2^7°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[2].field_parts[0].bit_field[3]` | `2:2` | "2^6°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[2].field_parts[0].bit_field[4]` | `1:1` | "2^5°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[2].field_parts[0].bit_field[5]` | `0:0` | "2^4°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[2].field_parts[1].bit_field[0]` | `7:7` | "2^3°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[2].field_parts[1].bit_field[1]` | `6:6` | "2^2°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[2].field_parts[1].bit_field[2]` | `5:5` | "2^1°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[2].field_parts[1].bit_field[3]` | `4:4` | "2^0°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[2].field_parts[1].bit_field[4]` | `3:3` | "2^-1°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[2].field_parts[1].bit_field[5]` | `2:2` | "2^-2°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[2].field_parts[1].bit_field[6]` | `1:0` | "Unimplemented" | true | "" | no exact truth target; not credited |
| `v12 registers[3].field_parts[0].bit_field[0]` | `7:5` | "Unimplemented" | true | "" | no exact truth target; not credited |
| `v12 registers[3].field_parts[0].bit_field[1]` | `4:4` | "SIGN" | false | "RW" | no exact truth target; not credited |
| `v12 registers[3].field_parts[0].bit_field[2]` | `3:3` | "2^7°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[3].field_parts[0].bit_field[3]` | `2:2` | "2^6°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[3].field_parts[0].bit_field[4]` | `1:1` | "2^5°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[3].field_parts[0].bit_field[5]` | `0:0` | "2^4°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[3].field_parts[1].bit_field[0]` | `7:7` | "2^3°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[3].field_parts[1].bit_field[1]` | `6:6` | "2^2°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[3].field_parts[1].bit_field[2]` | `5:5` | "2^1°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[3].field_parts[1].bit_field[3]` | `4:4` | "2^0°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[3].field_parts[1].bit_field[4]` | `3:3` | "2^-1°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[3].field_parts[1].bit_field[5]` | `2:2` | "2^-2°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[3].field_parts[1].bit_field[6]` | `1:0` | "Unimplemented" | true | "" | no exact truth target; not credited |
| `v12 registers[4].field_parts[0].bit_field[0]` | `7:5` | "Unimplemented" | true | "" | no exact truth target; not credited |
| `v12 registers[4].field_parts[0].bit_field[1]` | `4:4` | "SIGN" | false | "RW" | no exact truth target; not credited |
| `v12 registers[4].field_parts[0].bit_field[2]` | `3:3` | "2^7°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[4].field_parts[0].bit_field[3]` | `2:2` | "2^6°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[4].field_parts[0].bit_field[4]` | `1:1` | "2^5°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[4].field_parts[0].bit_field[5]` | `0:0` | "2^4°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[4].field_parts[1].bit_field[0]` | `7:7` | "2^3°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[4].field_parts[1].bit_field[1]` | `6:6` | "2^2°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[4].field_parts[1].bit_field[2]` | `5:5` | "2^1°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[4].field_parts[1].bit_field[3]` | `4:4` | "2^0°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[4].field_parts[1].bit_field[4]` | `3:3` | "2^-1°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[4].field_parts[1].bit_field[5]` | `2:2` | "2^-2°C" | false | "RW" | no exact truth target; not credited |
| `v12 registers[4].field_parts[1].bit_field[6]` | `1:0` | "Unimplemented" | true | "" | no exact truth target; not credited |
| `v12 registers[5].field_parts[0].bit_field[0]` | `7:7` | "TA vs. TCRIT" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[0].bit_field[1]` | `6:6` | "TA vs. TUPPER" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[0].bit_field[2]` | `5:5` | "TA vs. TLOWER" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[0].bit_field[3]` | `4:4` | "SIGN" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[0].bit_field[4]` | `3:3` | "2^7°C" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[0].bit_field[5]` | `2:2` | "2^6°C" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[0].bit_field[6]` | `1:1` | "2^5°C" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[0].bit_field[7]` | `0:0` | "2^4°C" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[1].bit_field[0]` | `7:7` | "2^3°C" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[1].bit_field[1]` | `6:6` | "2^2°C" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[1].bit_field[2]` | `5:5` | "2^1°C" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[1].bit_field[3]` | `4:4` | "2^0°C" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[1].bit_field[4]` | `3:3` | "2^-1°C" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[1].bit_field[5]` | `2:2` | "2^-2°C" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[1].bit_field[6]` | `1:1` | "2^-3°C" | false | "R" | no exact truth target; not credited |
| `v12 registers[5].field_parts[1].bit_field[7]` | `0:0` | "2^-4°C" | false | "R" | no exact truth target; not credited |
| `v12 registers[6].field_parts[0].bit_field[0]` | `7:0` | "Manufacturer ID" | false | "R" | no exact truth target; not credited |
| `v12 registers[6].field_parts[1].bit_field[0]` | `7:0` | "Manufacturer ID" | false | "R" | no exact truth target; not credited |
| `v12 registers[7].field_parts[1].bit_field[0]` | `7:0` | "Device Revision" | false | "R" | no exact truth target; not credited |

### 3.4 Reserved/type_write_read audit

- Every structurally aligned truth/extracted bit-field comparison with both type_write_read values empty receives C=1.0. In v12, the reversed Resolution reserved interval is the such comparison; its Q_BF table shows only type_write_read credited.
- For truth reserved fields whose complete bit-field object has no exact range target, the extracted object is MISSING rather than an empty type field, so type_write_read correctly receives C=0.0 for that missing comparison.

## 4. Invented-field and structural check

- Truth physical-register coverage is 8/8; the recorded RFU is exempt; extra non-reserved unique extracted physical locations are 0; the extra-register factor is `1.000000`.
- The RFU register at 0x00 is recorded reserved and therefore incurs no deduction. The adjacent non-reserved MSB/LSB address claims are recorded above; repeated address collisions do not create additional unique physical locations, but they remain structural claims and cause the already-calculated partial logical physical_address scores.
- category, index, is_multi_address, and source are excluded by AGENTS.md and do not affect the score. The multi-address flag itself is therefore not separately scored.

The bottom-up tables above are exhaustive for all 8 truth logical registers, 8 truth field parts, and 33 truth bit fields; the extra extracted structures are listed separately.

