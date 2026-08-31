# FXOS8700CQ without detailed datasheet score

## 1. Scoring basis

This report compares the extracted `without/FXOS8700CQ.json` map directly with the FXOS8700CQ datasheet PDF, not with a JSON truth file.

### Datasheet source

- `D:\python\master_arbeit\data\input_pdf\FXOS8700CQ.pdf` - NXP Semiconductors, FXOS8700CQ data sheet, Rev. 8.0, 25 April 2017.
- Register existence, address, access, default and comments: Table 16, PDF pp.29-32.
- Bit allocations and field descriptions: the register-specific tables cited below; PDF pp.37-103. The detailed calculation cites the exact table and printed PDF page for every datasheet bit-field target.

### Physical-register universe

The datasheet contains **n=115 actual named register/address entries** in Table 16. Reserved address rows 0x07-0x08, 0x19-0x1C and 0x79 are excluded from n. Physical matching uses numeric address together with bank and page; STATUS/DR_STATUS/F_STATUS at address 0x00 is one physical location.

### Evaluation rules

- The AHP weights and bottom-up recursive calculation are exactly those in `AGENTS.md`; rounded bit-field weights are normalized by 0.9999 and logical-register weights by 1.0001.
- Numeric addresses, widths, exact bit ranges, access types, reserved status, value codes and default values are objective facts and are scored strictly.
- Description-like fields are compared semantically; nonempty wording that preserves the datasheet meaning receives credit. Missing descriptions receive 0. Reserved-bit name and description omissions are allowed when the reserved range itself matches.
- Bit-field collections are matched by exact `bit_start`/`bit_end` range. Unmatched extracted bit fields are listed for auditability; the collection mean is calculated over the datasheet target bit fields, with missing targets receiving 0. Logical-register grouping differences are not independently penalized.
- `category` and fields not listed in `AGENTS.md` are excluded from scoring. Fields that are empty in both the datasheet target and extraction are credited.

## 2. Version result

| Version | n | m | x | sum q_R | extra penalty | final score |
|---|---:|---:|---:|---:|---:|---:|
| without | 115 | 17 | 0 | 16.107916890 | 1.000000 | **1.400688425/10** |

The following sections provide the complete bottom-up calculation for every extracted logical-register item, followed by all missing physical-register deductions and exact field-level deviations.


### Extracted logical register 1: `STATUS`

without location: `registers[0]`; extracted physical locations: 0x00 (0).
Truth association: datasheet `STATUS` at 0x00 (0).
Datasheet source: Tables 16, 18-19 (PDF pp.29, 37); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `STATUS` at 0x00 (0)

Locations: `truth registers[0].field_parts[0]` ↔ `without registers[0].field_parts[0]`.

**Datasheet bit field 1: `DR_STATUS or F_STATUS` [7:0]**

Locations: `truth registers[0].field_parts[0].bit_field[0]` ↔ `without: missing`.
Datasheet source: allocation Table 18 (PDF p.37); field description source: Table 18 (PDF p.37); enumerated-value source: Table 18 (PDF p.37).
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "DR_STATUS or F_STATUS" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 8 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | False | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Additional extracted bit field 1: `zyxow` [7:7]**

Locations: no exact datasheet range ↔ `without registers[0].field_parts[0].bit_field[0]`. Judgment: extracted bit field is not present as an exact datasheet bit-field target; it is reported but not credited.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | MISSING exact target | "zyxow" |
| `field_description` | 0.0586 | 0.0 | MISSING exact target | "X, Y, Z axis data overwrite (set when new data overwrites previous set before read)" |
| `bit_start` | 0.2594 | 0.0 | MISSING exact target | 7 |
| `bit_end` | 0.2594 | 0.0 | MISSING exact target | 7 |
| `bit_width` | 0.0583 | 0.0 | MISSING exact target | 1 |
| `values` | 0.2097 | 0.0 | MISSING exact target | [] |
| `is_reserved` | 0.0750 | 0.0 | MISSING exact target | False |
| `type_write_read` | 0.0583 | 0.0 | MISSING exact target | "R" |

**Additional extracted bit field 2: `zow` [6:6]**

Locations: no exact datasheet range ↔ `without registers[0].field_parts[0].bit_field[1]`. Judgment: extracted bit field is not present as an exact datasheet bit-field target; it is reported but not credited.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | MISSING exact target | "zow" |
| `field_description` | 0.0586 | 0.0 | MISSING exact target | "Z-axis data overwrite (set when Z data overwritten before read)" |
| `bit_start` | 0.2594 | 0.0 | MISSING exact target | 6 |
| `bit_end` | 0.2594 | 0.0 | MISSING exact target | 6 |
| `bit_width` | 0.0583 | 0.0 | MISSING exact target | 1 |
| `values` | 0.2097 | 0.0 | MISSING exact target | [] |
| `is_reserved` | 0.0750 | 0.0 | MISSING exact target | False |
| `type_write_read` | 0.0583 | 0.0 | MISSING exact target | "R" |

**Additional extracted bit field 3: `yow` [5:5]**

Locations: no exact datasheet range ↔ `without registers[0].field_parts[0].bit_field[2]`. Judgment: extracted bit field is not present as an exact datasheet bit-field target; it is reported but not credited.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | MISSING exact target | "yow" |
| `field_description` | 0.0586 | 0.0 | MISSING exact target | "Y-axis data overwrite (set when Y data overwritten before read)" |
| `bit_start` | 0.2594 | 0.0 | MISSING exact target | 5 |
| `bit_end` | 0.2594 | 0.0 | MISSING exact target | 5 |
| `bit_width` | 0.0583 | 0.0 | MISSING exact target | 1 |
| `values` | 0.2097 | 0.0 | MISSING exact target | [] |
| `is_reserved` | 0.0750 | 0.0 | MISSING exact target | False |
| `type_write_read` | 0.0583 | 0.0 | MISSING exact target | "R" |

**Additional extracted bit field 4: `xow` [4:4]**

Locations: no exact datasheet range ↔ `without registers[0].field_parts[0].bit_field[3]`. Judgment: extracted bit field is not present as an exact datasheet bit-field target; it is reported but not credited.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | MISSING exact target | "xow" |
| `field_description` | 0.0586 | 0.0 | MISSING exact target | "X-axis data overwrite (set when X data overwritten before read)" |
| `bit_start` | 0.2594 | 0.0 | MISSING exact target | 4 |
| `bit_end` | 0.2594 | 0.0 | MISSING exact target | 4 |
| `bit_width` | 0.0583 | 0.0 | MISSING exact target | 1 |
| `values` | 0.2097 | 0.0 | MISSING exact target | [] |
| `is_reserved` | 0.0750 | 0.0 | MISSING exact target | False |
| `type_write_read` | 0.0583 | 0.0 | MISSING exact target | "R" |

**Additional extracted bit field 5: `zyxdr` [3:3]**

Locations: no exact datasheet range ↔ `without registers[0].field_parts[0].bit_field[4]`. Judgment: extracted bit field is not present as an exact datasheet bit-field target; it is reported but not credited.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | MISSING exact target | "zyxdr" |
| `field_description` | 0.0586 | 0.0 | MISSING exact target | "X, Y, and Z new data ready (set when any enabled channel has new data)" |
| `bit_start` | 0.2594 | 0.0 | MISSING exact target | 3 |
| `bit_end` | 0.2594 | 0.0 | MISSING exact target | 3 |
| `bit_width` | 0.0583 | 0.0 | MISSING exact target | 1 |
| `values` | 0.2097 | 0.0 | MISSING exact target | [] |
| `is_reserved` | 0.0750 | 0.0 | MISSING exact target | False |
| `type_write_read` | 0.0583 | 0.0 | MISSING exact target | "R" |

**Additional extracted bit field 6: `zdr` [2:2]**

Locations: no exact datasheet range ↔ `without registers[0].field_parts[0].bit_field[5]`. Judgment: extracted bit field is not present as an exact datasheet bit-field target; it is reported but not credited.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | MISSING exact target | "zdr" |
| `field_description` | 0.0586 | 0.0 | MISSING exact target | "Z-axis new data available" |
| `bit_start` | 0.2594 | 0.0 | MISSING exact target | 2 |
| `bit_end` | 0.2594 | 0.0 | MISSING exact target | 2 |
| `bit_width` | 0.0583 | 0.0 | MISSING exact target | 1 |
| `values` | 0.2097 | 0.0 | MISSING exact target | [] |
| `is_reserved` | 0.0750 | 0.0 | MISSING exact target | False |
| `type_write_read` | 0.0583 | 0.0 | MISSING exact target | "R" |

**Additional extracted bit field 7: `ydr` [1:1]**

Locations: no exact datasheet range ↔ `without registers[0].field_parts[0].bit_field[6]`. Judgment: extracted bit field is not present as an exact datasheet bit-field target; it is reported but not credited.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | MISSING exact target | "ydr" |
| `field_description` | 0.0586 | 0.0 | MISSING exact target | "Y-axis new data available" |
| `bit_start` | 0.2594 | 0.0 | MISSING exact target | 1 |
| `bit_end` | 0.2594 | 0.0 | MISSING exact target | 1 |
| `bit_width` | 0.0583 | 0.0 | MISSING exact target | 1 |
| `values` | 0.2097 | 0.0 | MISSING exact target | [] |
| `is_reserved` | 0.0750 | 0.0 | MISSING exact target | False |
| `type_write_read` | 0.0583 | 0.0 | MISSING exact target | "R" |

**Additional extracted bit field 8: `xdr` [0:0]**

Locations: no exact datasheet range ↔ `without registers[0].field_parts[0].bit_field[7]`. Judgment: extracted bit field is not present as an exact datasheet bit-field target; it is reported but not credited.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | MISSING exact target | "xdr" |
| `field_description` | 0.0586 | 0.0 | MISSING exact target | "X-axis new data available" |
| `bit_start` | 0.2594 | 0.0 | MISSING exact target | 0 |
| `bit_end` | 0.2594 | 0.0 | MISSING exact target | 0 |
| `bit_width` | 0.0583 | 0.0 | MISSING exact target | 1 |
| `values` | 0.2097 | 0.0 | MISSING exact target | [] |
| `is_reserved` | 0.0750 | 0.0 | MISSING exact target | False |
| `type_write_read` | 0.0583 | 0.0 | MISSING exact target | "R" |

**Field-part aggregation**

`bit_field` correctness = mean(0.000000) = **0.000000**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "STATUS" | "STATUS" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Real-time data-ready status or FIFO status (DR_STATUS or F_STATUS)"} | {"hex":"0x00","decimal":"0","bank":"","page":"","description":"Status register"} |
| `description` | 0.0693 | 1.0 | "Real-time data-ready status or FIFO status (DR_STATUS or F_STATUS)" | "Status (data-ready or FIFO status depending on F_SETUP[f_mode])" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.000000 | [{"name_or_parameter":"DR_STATUS or F_STATUS","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 18 (PDF p.37); field description source: Table 18 (PDF p.37); enumerated-value source: Table 18 (PDF p.37)."}] | [{"name_or_parameter":"zyxow","field_description":"X, Y, Z axis data overwrite (set when new data overwrites previous set before read)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"zow","field_description":"Z-axis data overwrite (set when Z data overwritten before read)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"yow","field_description":"Y-axis data overwrite (set when Y data overwritten before read)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"xow","field_description":"X-axis data overwrite (set when X data overwritten before read)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"zyxdr","field_description":"X, Y, and Z new data ready (set when any enabled channel has new data)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"zdr","field_description":"Z-axis new data available","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ydr","field_description":"Y-axis new data available","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"xdr","field_description":"X-axis new data available","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.000000)/1.0000=0.687100/1.0000=\mathbf{0.687100}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.687100) = **0.687100**. Judgment: all direct facts match; descriptions compared leniently.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "STATUS" | "STATUS" |
| `physical_address` | 0.4044 | 1.0 | [0] | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":"Real-time data-ready status or FIFO status (DR_STATUS or F_STATUS)"}] |
| `register_description` | 0.0564 | 1.0 | "Real-time data-ready status or FIFO status (DR_STATUS or F_STATUS)" | "Real-time data-ready status or FIFO status; aliases DR_STATUS (f_mode=0) or F_STATUS (f_mode>0)." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.687100 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{1})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.687100 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.906637/1.0001=\mathbf{0.906546}\).

### Extracted logical register 2: `OUT_X_MSB`

without location: `registers[1]`; extracted physical locations: 0x01 (1).
Truth association: datasheet `OUT_X_MSB` at 0x01 (1).
Datasheet source: Table 51 (PDF p.53); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `OUT_X_MSB` at 0x01 (1)

Locations: `truth registers[1].field_parts[0]` ↔ `without registers[1].field_parts[0]`.

**Datasheet bit field 1: `xd[13:6]` [7:0]**

Locations: `truth registers[1].field_parts[0].bit_field[0]` ↔ `without registers[1].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 51 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "xd[13:6]" | "xd[13:6]" |
| `field_description` | 0.0586 | 1.0 | "" | "Bits 13:6 of the 14-bit X-axis sample (MSB bits)" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "OUT_X_MSB" | "OUT_X_MSB" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"[7:0] are 8 MSBs of 14-bit sample. Root pointer to XYZ FIFO data."} | {"hex":"0x01","decimal":"1","bank":"","page":"","description":"X-axis acceleration MSB"} |
| `description` | 0.0693 | 1.0 | "[7:0] are 8 MSBs of 14-bit sample. Root pointer to XYZ FIFO data." | "High byte of 14-bit X-axis accelerometer sample" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"xd[13:6]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 51 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."}] | [{"name_or_parameter":"xd[13:6]","field_description":"Bits 13:6 of the 14-bit X-axis sample (MSB bits)","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. Judgment: default_value is not fully correct.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "OUT_X_MSB" | "OUT_X_MSB" |
| `physical_address` | 0.4044 | 1.0 | [1] | [{"hex":"0x01","decimal":"1","bank":"","page":"","description":"MSB of 14-bit X-axis accelerometer sample (most-significant 8 bits)"}] |
| `register_description` | 0.0564 | 1.0 | "[7:0] are 8 MSBs of 14-bit sample. Root pointer to XYZ FIFO data." | "MSB byte of 14-bit left-justified X-axis accelerometer sample (2's complement)." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 1.000000 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 0.0 | "Data" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{2})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.933400/1.0001=\mathbf{0.933307}\).

### Extracted logical register 3: `OUT_X_LSB`

without location: `registers[2]`; extracted physical locations: 0x02 (2).
Truth association: datasheet `OUT_X_LSB` at 0x02 (2).
Datasheet source: Table 52 (PDF p.53); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `OUT_X_LSB` at 0x02 (2)

Locations: `truth registers[2].field_parts[0]` ↔ `without registers[2].field_parts[0]`.

**Datasheet bit field 1: `xd[5:0]` [7:2]**

Locations: `truth registers[2].field_parts[0].bit_field[0]` ↔ `without registers[2].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 52 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "xd[5:0]" | "xd[5:0]" |
| `field_description` | 0.0586 | 1.0 | "" | "Bits [5:0] of 14-bit X-axis sample, stored in bits [7:2] of this register" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 2: `-` [1:1]**

Locations: `truth registers[2].field_parts[0].bit_field[1]` ↔ `without: missing`.
Datasheet source: allocation Table 52 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Datasheet bit field 3: `-` [0:0]**

Locations: `truth registers[2].field_parts[0].bit_field[2]` ↔ `without: missing`.
Datasheet source: allocation Table 52 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Additional extracted bit field 2: `Reserved` [1:0]**

Locations: no exact datasheet range ↔ `without registers[2].field_parts[0].bit_field[1]`. Judgment: extracted bit field is not present as an exact datasheet bit-field target; it is reported but not credited.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | MISSING exact target | "Reserved" |
| `field_description` | 0.0586 | 0.0 | MISSING exact target | "" |
| `bit_start` | 0.2594 | 0.0 | MISSING exact target | 0 |
| `bit_end` | 0.2594 | 0.0 | MISSING exact target | 1 |
| `bit_width` | 0.0583 | 0.0 | MISSING exact target | 2 |
| `values` | 0.2097 | 0.0 | MISSING exact target | [] |
| `is_reserved` | 0.0750 | 0.0 | MISSING exact target | True |
| `type_write_read` | 0.0583 | 0.0 | MISSING exact target | "" |

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 0.000000, 0.000000) = **0.333333**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "OUT_X_LSB" | "OUT_X_LSB" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"[7:2] are 6 LSBs of 14-bit real-time sample"} | {"hex":"0x02","decimal":"2","bank":"","page":"","description":"X-axis acceleration LSB"} |
| `description` | 0.0693 | 1.0 | "[7:2] are 6 LSBs of 14-bit real-time sample" | "Low byte of 14-bit X-axis accelerometer sample (bits [7:2] are sample LSBs)" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.333333 | [{"name_or_parameter":"xd[5:0]","field_description":"","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 52 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"R","source":"allocation Table 52 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"R","source":"allocation Table 52 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."}] | [{"name_or_parameter":"xd[5:0]","field_description":"Bits [5:0] of 14-bit X-axis sample, stored in bits [7:2] of this register","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.333333)/1.0000=0.791400/1.0000=\mathbf{0.791400}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.791400) = **0.791400**. Judgment: default_value is not fully correct.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "OUT_X_LSB" | "OUT_X_LSB" |
| `physical_address` | 0.4044 | 1.0 | [2] | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":"LSB of 14-bit X-axis accelerometer sample (6 LSBs located in bits [7:2])"}] |
| `register_description` | 0.0564 | 1.0 | "[7:2] are 6 LSBs of 14-bit real-time sample" | "LSB byte of 14-bit left-justified X-axis accelerometer sample; bits [7:2] contain the 6 LSBs of the 14-bit value." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.791400 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 0.0 | "Data" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{3})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.791400 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.871091/1.0001=\mathbf{0.871004}\).

### Extracted logical register 4: `OUT_Y_MSB`

without location: `registers[3]`; extracted physical locations: 0x03 (3).
Truth association: datasheet `OUT_Y_MSB` at 0x03 (3).
Datasheet source: Table 53 (PDF p.53); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `OUT_Y_MSB` at 0x03 (3)

Locations: `truth registers[3].field_parts[0]` ↔ `without registers[3].field_parts[0]`.

**Datasheet bit field 1: `yd[13:6]` [7:0]**

Locations: `truth registers[3].field_parts[0].bit_field[0]` ↔ `without registers[3].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 53 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "yd[13:6]" | "yd[13:6]" |
| `field_description` | 0.0586 | 1.0 | "" | "Bits 13:6 of the 14-bit Y-axis sample (MSB bits)" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "OUT_Y_MSB" | "OUT_Y_MSB" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"[7:0] are 8 MSBs of 14-bit real-time sample"} | {"hex":"0x03","decimal":"3","bank":"","page":"","description":"Y-axis acceleration MSB"} |
| `description` | 0.0693 | 1.0 | "[7:0] are 8 MSBs of 14-bit real-time sample" | "High byte of 14-bit Y-axis accelerometer sample" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"yd[13:6]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 53 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."}] | [{"name_or_parameter":"yd[13:6]","field_description":"Bits 13:6 of the 14-bit Y-axis sample (MSB bits)","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. Judgment: default_value is not fully correct.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "OUT_Y_MSB" | "OUT_Y_MSB" |
| `physical_address` | 0.4044 | 1.0 | [3] | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":"MSB of 14-bit Y-axis accelerometer sample"}] |
| `register_description` | 0.0564 | 1.0 | "[7:0] are 8 MSBs of 14-bit real-time sample" | "MSB byte of 14-bit left-justified Y-axis accelerometer sample (2's complement)." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 1.000000 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 0.0 | "Data" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{4})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.933400/1.0001=\mathbf{0.933307}\).

### Extracted logical register 5: `OUT_Y_LSB`

without location: `registers[4]`; extracted physical locations: 0x04 (4).
Truth association: datasheet `OUT_Y_LSB` at 0x04 (4).
Datasheet source: Table 54 (PDF p.53); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `OUT_Y_LSB` at 0x04 (4)

Locations: `truth registers[4].field_parts[0]` ↔ `without registers[4].field_parts[0]`.

**Datasheet bit field 1: `yd[5:0]` [7:2]**

Locations: `truth registers[4].field_parts[0].bit_field[0]` ↔ `without registers[4].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 54 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "yd[5:0]" | "yd[5:0]" |
| `field_description` | 0.0586 | 1.0 | "" | "Bits [5:0] of 14-bit Y-axis sample stored in bits [7:2]" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 2: `-` [1:1]**

Locations: `truth registers[4].field_parts[0].bit_field[1]` ↔ `without: missing`.
Datasheet source: allocation Table 54 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Datasheet bit field 3: `-` [0:0]**

Locations: `truth registers[4].field_parts[0].bit_field[2]` ↔ `without: missing`.
Datasheet source: allocation Table 54 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Additional extracted bit field 2: `Reserved` [1:0]**

Locations: no exact datasheet range ↔ `without registers[4].field_parts[0].bit_field[1]`. Judgment: extracted bit field is not present as an exact datasheet bit-field target; it is reported but not credited.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | MISSING exact target | "Reserved" |
| `field_description` | 0.0586 | 0.0 | MISSING exact target | "" |
| `bit_start` | 0.2594 | 0.0 | MISSING exact target | 0 |
| `bit_end` | 0.2594 | 0.0 | MISSING exact target | 1 |
| `bit_width` | 0.0583 | 0.0 | MISSING exact target | 2 |
| `values` | 0.2097 | 0.0 | MISSING exact target | [] |
| `is_reserved` | 0.0750 | 0.0 | MISSING exact target | True |
| `type_write_read` | 0.0583 | 0.0 | MISSING exact target | "" |

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 0.000000, 0.000000) = **0.333333**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "OUT_Y_LSB" | "OUT_Y_LSB" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"[7:2] are 6 LSBs of 14-bit real-time sample"} | {"hex":"0x04","decimal":"4","bank":"","page":"","description":"Y-axis acceleration LSB"} |
| `description` | 0.0693 | 1.0 | "[7:2] are 6 LSBs of 14-bit real-time sample" | "Low byte of 14-bit Y-axis accelerometer sample" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.333333 | [{"name_or_parameter":"yd[5:0]","field_description":"","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 54 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"R","source":"allocation Table 54 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"R","source":"allocation Table 54 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."}] | [{"name_or_parameter":"yd[5:0]","field_description":"Bits [5:0] of 14-bit Y-axis sample stored in bits [7:2]","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.333333)/1.0000=0.791400/1.0000=\mathbf{0.791400}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.791400) = **0.791400**. Judgment: default_value is not fully correct.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "OUT_Y_LSB" | "OUT_Y_LSB" |
| `physical_address` | 0.4044 | 1.0 | [4] | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":"LSB of 14-bit Y-axis accelerometer sample (6 LSBs in bits [7:2])"}] |
| `register_description` | 0.0564 | 1.0 | "[7:2] are 6 LSBs of 14-bit real-time sample" | "LSB byte of 14-bit left-justified Y-axis accelerometer sample; bits [7:2] contain the 6 LSBs." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.791400 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 0.0 | "Data" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{5})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.791400 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.871091/1.0001=\mathbf{0.871004}\).

### Extracted logical register 6: `OUT_Z_MSB`

without location: `registers[5]`; extracted physical locations: 0x05 (5).
Truth association: datasheet `OUT_Z_MSB` at 0x05 (5).
Datasheet source: Table 55 (PDF p.54); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `OUT_Z_MSB` at 0x05 (5)

Locations: `truth registers[5].field_parts[0]` ↔ `without registers[5].field_parts[0]`.

**Datasheet bit field 1: `zd[13:6]` [7:0]**

Locations: `truth registers[5].field_parts[0].bit_field[0]` ↔ `without registers[5].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 55 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "zd[13:6]" | "zd[13:6]" |
| `field_description` | 0.0586 | 1.0 | "" | "Bits 13:6 of the 14-bit Z-axis sample (MSB bits)" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "OUT_Z_MSB" | "OUT_Z_MSB" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"[7:0] are 8 MSBs of 14-bit real-time sample"} | {"hex":"0x05","decimal":"5","bank":"","page":"","description":"Z-axis acceleration MSB"} |
| `description` | 0.0693 | 1.0 | "[7:0] are 8 MSBs of 14-bit real-time sample" | "High byte of 14-bit Z-axis accelerometer sample" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"zd[13:6]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 55 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided."}] | [{"name_or_parameter":"zd[13:6]","field_description":"Bits 13:6 of the 14-bit Z-axis sample (MSB bits)","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. Judgment: default_value is not fully correct.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "OUT_Z_MSB" | "OUT_Z_MSB" |
| `physical_address` | 0.4044 | 1.0 | [5] | [{"hex":"0x05","decimal":"5","bank":"","page":"","description":"MSB of 14-bit Z-axis accelerometer sample"}] |
| `register_description` | 0.0564 | 1.0 | "[7:0] are 8 MSBs of 14-bit real-time sample" | "MSB byte of 14-bit left-justified Z-axis accelerometer sample (2's complement)." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 1.000000 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 0.0 | "Data" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{6})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.933400/1.0001=\mathbf{0.933307}\).

### Extracted logical register 7: `OUT_Z_LSB`

without location: `registers[6]`; extracted physical locations: 0x06 (6).
Truth association: datasheet `OUT_Z_LSB` at 0x06 (6).
Datasheet source: Table 56 (PDF p.54); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `OUT_Z_LSB` at 0x06 (6)

Locations: `truth registers[6].field_parts[0]` ↔ `without registers[6].field_parts[0]`.

**Datasheet bit field 1: `zd[5:0]` [7:2]**

Locations: `truth registers[6].field_parts[0].bit_field[0]` ↔ `without registers[6].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 56 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "zd[5:0]" | "zd[5:0]" |
| `field_description` | 0.0586 | 1.0 | "" | "Bits [5:0] of 14-bit Z-axis sample stored in bits [7:2]" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 2: `-` [1:1]**

Locations: `truth registers[6].field_parts[0].bit_field[1]` ↔ `without: missing`.
Datasheet source: allocation Table 56 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 1 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Datasheet bit field 3: `-` [0:0]**

Locations: `truth registers[6].field_parts[0].bit_field[2]` ↔ `without: missing`.
Datasheet source: allocation Table 56 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 0 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "R" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Additional extracted bit field 2: `Reserved` [1:0]**

Locations: no exact datasheet range ↔ `without registers[6].field_parts[0].bit_field[1]`. Judgment: extracted bit field is not present as an exact datasheet bit-field target; it is reported but not credited.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | MISSING exact target | "Reserved" |
| `field_description` | 0.0586 | 0.0 | MISSING exact target | "" |
| `bit_start` | 0.2594 | 0.0 | MISSING exact target | 0 |
| `bit_end` | 0.2594 | 0.0 | MISSING exact target | 1 |
| `bit_width` | 0.0583 | 0.0 | MISSING exact target | 2 |
| `values` | 0.2097 | 0.0 | MISSING exact target | [] |
| `is_reserved` | 0.0750 | 0.0 | MISSING exact target | True |
| `type_write_read` | 0.0583 | 0.0 | MISSING exact target | "" |

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 0.000000, 0.000000) = **0.333333**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "OUT_Z_LSB" | "OUT_Z_LSB" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x06","decimal":"6","bank":"","page":"","description":"[7:2] are 6 LSBs of 14-bit real-time sample"} | {"hex":"0x06","decimal":"6","bank":"","page":"","description":"Z-axis acceleration LSB"} |
| `description` | 0.0693 | 1.0 | "[7:2] are 6 LSBs of 14-bit real-time sample" | "Low byte of 14-bit Z-axis accelerometer sample" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.333333 | [{"name_or_parameter":"zd[5:0]","field_description":"","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 56 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"R","source":"allocation Table 56 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"R","source":"allocation Table 56 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided."}] | [{"name_or_parameter":"zd[5:0]","field_description":"Bits [5:0] of 14-bit Z-axis sample stored in bits [7:2]","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.333333)/1.0000=0.791400/1.0000=\mathbf{0.791400}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.791400) = **0.791400**. Judgment: default_value is not fully correct.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "OUT_Z_LSB" | "OUT_Z_LSB" |
| `physical_address` | 0.4044 | 1.0 | [6] | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":"LSB of 14-bit Z-axis accelerometer sample (6 LSBs in bits [7:2])"}] |
| `register_description` | 0.0564 | 1.0 | "[7:2] are 6 LSBs of 14-bit real-time sample" | "LSB byte of 14-bit left-justified Z-axis accelerometer sample; bits [7:2] contain the 6 LSBs." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.791400 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 0.0 | "Data" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{7})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.791400 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.871091/1.0001=\mathbf{0.871004}\).

### Extracted logical register 8: `F_SETUP`

without location: `registers[7]`; extracted physical locations: 0x09 (9).
Truth association: datasheet `F_SETUP` at 0x09 (9).
Datasheet source: Table 57 (PDF p.54); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `F_SETUP` at 0x09 (9)

Locations: `truth registers[7].field_parts[0]` ↔ `without registers[7].field_parts[0]`.

**Datasheet bit field 1: `f_mode[1:0]` [7:6]**

Locations: `truth registers[7].field_parts[0].bit_field[0]` ↔ `without registers[7].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 57 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "f_mode[1:0]" | "f_mode[1:0]" |
| `field_description` | 0.0586 | 1.0 | "" | "FIFO operating mode: 00 disabled, 01 circular, 10 stop, 11 trigger" |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [{"value":"0b00","value_description":"FIFO disabled"},{"value":"0b01","value_description":"Circular buffer (overwrite oldest)"},{"value":"0b10","value_description":"Stop when full"},{"value":"0b11","value_description":"Trigger mode"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 2: `f_wmrk[5:0]` [5:0]**

Locations: `truth registers[7].field_parts[0].bit_field[1]` ↔ `without registers[7].field_parts[0].bit_field[1]`.
Datasheet source: allocation Table 57 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "f_wmrk[5:0]" | "f_wmrk[5:0]" |
| `field_description` | 0.0586 | 1.0 | "" | "FIFO watermark level or pre-trigger sample count (6 bits)" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 6 | 6 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000) = **1.000000**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "F_SETUP" | "F_SETUP" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"FIFO setup"} | {"hex":"0x09","decimal":"9","bank":"","page":"","description":"FIFO setup"} |
| `description` | 0.0693 | 1.0 | "FIFO setup" | "FIFO mode and watermark/pre-trigger sample count" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"f_mode[1:0]","field_description":"","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 57 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"f_wmrk[5:0]","field_description":"","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 57 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided."}] | [{"name_or_parameter":"f_mode[1:0]","field_description":"FIFO operating mode: 00 disabled, 01 circular, 10 stop, 11 trigger","bit_start":6,"bit_end":7,"bit_width":2,"values":[{"value":"0b00","value_description":"FIFO disabled"},{"value":"0b01","value_description":"Circular buffer (overwrite oldest)"},{"value":"0b10","value_description":"Stop when full"},{"value":"0b11","value_description":"Trigger mode"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"f_wmrk[5:0]","field_description":"FIFO watermark level or pre-trigger sample count (6 bits)","bit_start":0,"bit_end":5,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared leniently.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "F_SETUP" | "F_SETUP" |
| `physical_address` | 0.4044 | 1.0 | [9] | [{"hex":"0x09","decimal":"9","bank":"","page":"","description":"FIFO setup register"}] |
| `register_description` | 0.0564 | 1.0 | "FIFO setup" | "FIFO configuration: mode (disabled, circular, stop, trigger) and watermark level / pre-trigger sample count." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 1.000000 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{8})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

### Extracted logical register 9: `SYSMOD`

without location: `registers[8]`; extracted physical locations: 0x0B (11).
Truth association: datasheet `SYSMOD` at 0x0B (11).
Datasheet source: Table 27 (PDF p.40); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `SYSMOD` at 0x0B (11)

Locations: `truth registers[9].field_parts[0]` ↔ `without registers[8].field_parts[0]`.

**Datasheet bit field 1: `fgerr` [7:7]**

Locations: `truth registers[9].field_parts[0].bit_field[0]` ↔ `without registers[8].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 27 (PDF p.40); field description source: Table 28 (PDF p.40); enumerated-value source: Table 28 (PDF p.40).
Judgment: datasheet value enumeration is missing.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "fgerr" | "fgerr" |
| `field_description` | 0.0586 | 1.0 | "FIFO gate error. Default value: 0. 0 – No FIFO gate error detected. 1 – FIFO gate error was detected. Emptying the FIFO buffer clears the fgerr bit in the SYSMOD register. See Section 14.1.10 for more information on configuring the FIFO gate function." | "FIFO gate error (1 = FIFO gate error detected)" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No FIFO gate error detected"},{"value":"1","value_description":"FIFO gate error was detected. Emptying the FIFO buffer clears the fgerr bit in the SYSMOD register. See Section 14.1.10 for more information on configuring the FIFO gate function"}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Datasheet bit field 2: `fgt[4:0]` [6:2]**

Locations: `truth registers[9].field_parts[0].bit_field[1]` ↔ `without registers[8].field_parts[0].bit_field[1]`.
Datasheet source: allocation Table 27 (PDF p.40); field description source: Table 28 (PDF p.40); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "fgt[4:0]" | "fgt[4:0]" |
| `field_description` | 0.0586 | 1.0 | "Number of ODR time units since fgerr was asserted. Reset when fgerr is cleared" | "Number of ODR time units since fgerr was asserted (reset when fgerr cleared)" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 5 | 5 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 3: `sysmod[1:0]` [1:0]**

Locations: `truth registers[9].field_parts[0].bit_field[2]` ↔ `without registers[8].field_parts[0].bit_field[2]`.
Datasheet source: allocation Table 27 (PDF p.40); field description source: Table 28 (PDF p.40); enumerated-value source: Table 28 (PDF p.40).
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "sysmod[1:0]" | "sysmod[1:0]" |
| `field_description` | 0.0586 | 1.0 | "System mode. Default value: 0b00. 0b00 – Standby mode 0b01 – Wake mode 0b10 – Sleep mode" | "System mode: 00 standby, 01 wake, 10 sleep" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"0b00","value_description":"Standby mode"},{"value":"0b01","value_description":"Wake mode"},{"value":"0b10","value_description":"Sleep mode"}] | [{"value":"0b00","value_description":"Standby"},{"value":"0b01","value_description":"Wake"},{"value":"0b10","value_description":"Sleep"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(0.790279, 1.000000, 1.000000) = **0.930093**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "SYSMOD" | "SYSMOD" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"Current system mode"} | {"hex":"0x0B","decimal":"11","bank":"","page":"","description":"System mode"} |
| `description` | 0.0693 | 1.0 | "Current system mode" | "System mode and FIFO gate information" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.930093 | [{"name_or_parameter":"fgerr","field_description":"FIFO gate error. Default value: 0. 0 – No FIFO gate error detected. 1 – FIFO gate error was detected. Emptying the FIFO buffer clears the fgerr bit in the SYSMOD register. See Section 14.1.10 for more information on configuring the FIFO gate function.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No FIFO gate error detected"},{"value":"1","value_description":"FIFO gate error was detected. Emptying the FIFO buffer clears the fgerr bit in the SYSMOD register. See Section 14.1.10 for more information on configuring the FIFO gate function"}],"is_reserved":false,"type_write_read":"R","source":"allocation Table 27 (PDF p.40); field description source: Table 28 (PDF p.40); enumerated-value source: Table 28 (PDF p.40)."},{"name_or_parameter":"fgt[4:0]","field_description":"Number of ODR time units since fgerr was asserted. Reset when fgerr is cleared","bit_start":2,"bit_end":6,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 27 (PDF p.40); field description source: Table 28 (PDF p.40); enumerated-value source: not separately provided."},{"name_or_parameter":"sysmod[1:0]","field_description":"System mode. Default value: 0b00. 0b00 – Standby mode 0b01 – Wake mode 0b10 – Sleep mode","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"Standby mode"},{"value":"0b01","value_description":"Wake mode"},{"value":"0b10","value_description":"Sleep mode"}],"is_reserved":false,"type_write_read":"R","source":"allocation Table 27 (PDF p.40); field description source: Table 28 (PDF p.40); enumerated-value source: Table 28 (PDF p.40)."}] | [{"name_or_parameter":"fgerr","field_description":"FIFO gate error (1 = FIFO gate error detected)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"fgt[4:0]","field_description":"Number of ODR time units since fgerr was asserted (reset when fgerr cleared)","bit_start":2,"bit_end":6,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"sysmod[1:0]","field_description":"System mode: 00 standby, 01 wake, 10 sleep","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"Standby"},{"value":"0b01","value_description":"Wake"},{"value":"0b10","value_description":"Sleep"}],"is_reserved":false,"type_write_read":"R"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.930093)/1.0000=0.978126/1.0000=\mathbf{0.978126}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.978126) = **0.978126**. Judgment: all direct facts match; descriptions compared leniently.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "SYSMOD" | "SYSMOD" |
| `physical_address` | 0.4044 | 1.0 | [11] | [{"hex":"0x0B","decimal":"11","bank":"","page":"","description":"Current system mode and FIFO gate error status"}] |
| `register_description` | 0.0564 | 1.0 | "Current system mode" | "System mode and FIFO gate error status; indicates standby/wake/sleep and FIFO gate error plus time since error." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.978126 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{9})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.978126 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.993566/1.0001=\mathbf{0.993467}\).

### Extracted logical register 10: `INT_SOURCE`

without location: `registers[9]`; extracted physical locations: 0x0C (12).
Truth association: datasheet `INT_SOURCE` at 0x0C (12).
Datasheet source: Table 29 (PDF p.41); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `INT_SOURCE` at 0x0C (12)

Locations: `truth registers[10].field_parts[0]` ↔ `without registers[9].field_parts[0]`.

**Datasheet bit field 1: `src_aslp` [7:7]**

Locations: `truth registers[10].field_parts[0].bit_field[0]` ↔ `without registers[9].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.41); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "src_aslp" | "src_aslp" |
| `field_description` | 0.0586 | 1.0 | "Auto-sleep/wake interrupt status bit: logic '1' indicates that an interrupt event that can cause a wake-to-sleep or sleep-to-wake system mode transition has occurred and logic '0' indicates that no wake-to-sleep or sleep-to-wake system mode transition interrupt event has occurred. The \"wake-to-sleep\" transition occurs when a period of inactivity that exceeds the user-specified time limit (ASLP_COUNT) has been detected, thus causing the system to transition to a user-specified low ODR setting. A \"sleep-to-wake\" transition occurs when the user-specified interrupt event has awakened the system, thus causing the system to transition to the user-specified higher ODR setting. Reading the SYSMOD register will clear the src_aslp bit." | "Auto-sleep/wake interrupt status (cleared by reading SYSMOD)" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 2: `src_fifo` [6:6]**

Locations: `truth registers[10].field_parts[0].bit_field[1]` ↔ `without registers[9].field_parts[0].bit_field[1]`.
Datasheet source: allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.41); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "src_fifo" | "src_fifo" |
| `field_description` | 0.0586 | 1.0 | "FIFO interrupt status bit: logic '1' indicates that a FIFO interrupt event such as an overflow or watermark (F_STATUS[f_cnt] = F_STATUS[f_wmrk]) event has occurred and logic '0' indicates that no FIFO interrupt event has occurred. This bit is cleared by reading the F_STATUS register." | "FIFO interrupt status (cleared by reading F_STATUS)" |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 3: `src_trans` [5:5]**

Locations: `truth registers[10].field_parts[0].bit_field[2]` ↔ `without registers[9].field_parts[0].bit_field[2]`.
Datasheet source: allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.41); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "src_trans" | "src_trans" |
| `field_description` | 0.0586 | 1.0 | "Transient interrupt status bit: logic '1' indicates that an acceleration transient value greater than user-specified threshold has occurred. and logic '0' indicates that no transient event has occurred. This bit is asserted whenever TRANSIENT_SRC[ea] is asserted and the functional block interrupt has been enabled. This bit is cleared by reading the TRANSIENT_SRC register." | "Transient interrupt status (cleared by reading TRANSIENT_SRC)" |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 4: `src_Indprt` [4:4]**

Locations: `truth registers[10].field_parts[0].bit_field[3]` ↔ `without registers[9].field_parts[0].bit_field[3]`.
Datasheet source: allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.41); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "src_Indprt" | "src_Indprt" |
| `field_description` | 0.0586 | 1.0 | "Landscape/portrait orientation interrupt status bit: logic '1' indicates that an interrupt was generated due to a change in the device orientation status and logic '0' indicates that no change in orientation status was detected. This bit is asserted whenever PL_STATUS[newlp] is asserted and the functional block interrupt has been enabled. This bit is cleared by reading the PL_STATUS register." | "Landscape/portrait interrupt status (cleared by reading PL_STATUS)" |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 5: `src_pulse` [3:3]**

Locations: `truth registers[10].field_parts[0].bit_field[4]` ↔ `without registers[9].field_parts[0].bit_field[4]`.
Datasheet source: allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.41); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "src_pulse" | "src_pulse" |
| `field_description` | 0.0586 | 1.0 | "Pulse interrupt status bit: logic '1' indicates that an interrupt was generated due to single- and/or double-pulse event and logic '0' indicates that no pulse event was detected. This bit is asserted whenever PULSE_SRC[ea] is asserted and the functional block interrupt has been enabled. This bit is cleared by reading the PULSE_SRC register." | "Pulse detection interrupt status (cleared by reading PULSE_SRC)" |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 6: `src_ffmt` [2:2]**

Locations: `truth registers[10].field_parts[0].bit_field[5]` ↔ `without registers[9].field_parts[0].bit_field[5]`.
Datasheet source: allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.42); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "src_ffmt" | "src_ffmt" |
| `field_description` | 0.0586 | 1.0 | "Freefall/motion interrupt status bit: logic '1' indicates that the freefall/motion function interrupt is active and logic '0' indicates that no freefall or motion event was detected. This bit is asserted whenever A_FFMT_SRC[ea] is asserted and the functional block interrupt has been enabled. This bit is cleared by reading the A_FFMT_SRC register." | "Freefall/motion interrupt status (cleared by reading A_FFMT_SRC)" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 7: `src_a_vecm` [1:1]**

Locations: `truth registers[10].field_parts[0].bit_field[6]` ↔ `without registers[9].field_parts[0].bit_field[6]`.
Datasheet source: allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.42); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "src_a_vecm" | "src_a_vecm" |
| `field_description` | 0.0586 | 1.0 | "Accelerometer vector-magnitude interrupt status bit: logic '1' indicates that an interrupt was generated due to acceleration vector-magnitude function and logic '0' indicates that no interrupt has been generated. This bit is cleared by reading this register (INT_SOURCE)." | "Acceleration vector-magnitude interrupt status (cleared by reading INT_SOURCE)" |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 8: `src_drdy` [0:0]**

Locations: `truth registers[10].field_parts[0].bit_field[7]` ↔ `without registers[9].field_parts[0].bit_field[7]`.
Datasheet source: allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.42); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "src_drdy" | "src_drdy" |
| `field_description` | 0.0586 | 1.0 | "Data-ready interrupt status bit. In acceleration only mode this bit indicates that new accelerometer data is available to read. In magnetometer only mode, src_drdy indicates that new magnetic data is available to be read. In hybrid mode, this bit signals that new acceleration and/or magnetic data is available. The src_drdy interrupt flag is cleared by reading out the acceleration data in accelerometer only mode and by reading out the magnetic data in magnetometer only or hybrid modes. In hybrid mode and with M_CTRL_REG2[hyb_autoinc_mode] = 1, all of the sensor data can be read out in a 12-byte burst read starting at register 0x01 (OUT_X_MSB)." | "Data-ready interrupt status (accelerometer/magnetometer depending on mode)" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "INT_SOURCE" | "INT_SOURCE" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Interrupt status"} | {"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Interrupt source register"} |
| `description` | 0.0693 | 1.0 | "Interrupt status" | "Interrupt status bits for various event sources" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"src_aslp","field_description":"Auto-sleep/wake interrupt status bit: logic '1' indicates that an interrupt event that can cause a wake-to-sleep or sleep-to-wake system mode transition has occurred and logic '0' indicates that no wake-to-sleep or sleep-to-wake system mode transition interrupt event has occurred. The \"wake-to-sleep\" transition occurs when a period of inactivity that exceeds the user-specified time limit (ASLP_COUNT) has been detected, thus causing the system to transition to a user-specified low ODR setting. A \"sleep-to-wake\" transition occurs when the user-specified interrupt event has awakened the system, thus causing the system to transition to the user-specified higher ODR setting. Reading the SYSMOD register will clear the src_aslp bit.","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.41); enumerated-value source: not separately provided."},{"name_or_parameter":"src_fifo","field_description":"FIFO interrupt status bit: logic '1' indicates that a FIFO interrupt event such as an overflow or watermark (F_STATUS[f_cnt] = F_STATUS[f_wmrk]) event has occurred and logic '0' indicates that no FIFO interrupt event has occurred. This bit is cleared by reading the F_STATUS register.","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.41); enumerated-value source: not separately provided."},{"name_or_parameter":"src_trans","field_description":"Transient interrupt status bit: logic '1' indicates that an acceleration transient value greater than user-specified threshold has occurred. and logic '0' indicates that no transient event has occurred. This bit is asserted whenever TRANSIENT_SRC[ea] is asserted and the functional block interrupt has been enabled. This bit is cleared by reading the TRANSIENT_SRC register.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.41); enumerated-value source: not separately provided."},{"name_or_parameter":"src_Indprt","field_description":"Landscape/portrait orientation interrupt status bit: logic '1' indicates that an interrupt was generated due to a change in the device orientation status and logic '0' indicates that no change in orientation status was detected. This bit is asserted whenever PL_STATUS[newlp] is asserted and the functional block interrupt has been enabled. This bit is cleared by reading the PL_STATUS register.","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.41); enumerated-value source: not separately provided."},{"name_or_parameter":"src_pulse","field_description":"Pulse interrupt status bit: logic '1' indicates that an interrupt was generated due to single- and/or double-pulse event and logic '0' indicates that no pulse event was detected. This bit is asserted whenever PULSE_SRC[ea] is asserted and the functional block interrupt has been enabled. This bit is cleared by reading the PULSE_SRC register.","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.41); enumerated-value source: not separately provided."},{"name_or_parameter":"src_ffmt","field_description":"Freefall/motion interrupt status bit: logic '1' indicates that the freefall/motion function interrupt is active and logic '0' indicates that no freefall or motion event was detected. This bit is asserted whenever A_FFMT_SRC[ea] is asserted and the functional block interrupt has been enabled. This bit is cleared by reading the A_FFMT_SRC register.","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.42); enumerated-value source: not separately provided."},{"name_or_parameter":"src_a_vecm","field_description":"Accelerometer vector-magnitude interrupt status bit: logic '1' indicates that an interrupt was generated due to acceleration vector-magnitude function and logic '0' indicates that no interrupt has been generated. This bit is cleared by reading this register (INT_SOURCE).","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.42); enumerated-value source: not separately provided."},{"name_or_parameter":"src_drdy","field_description":"Data-ready interrupt status bit. In acceleration only mode this bit indicates that new accelerometer data is available to read. In magnetometer only mode, src_drdy indicates that new magnetic data is available to be read. In hybrid mode, this bit signals that new acceleration and/or magnetic data is available. The src_drdy interrupt flag is cleared by reading out the acceleration data in accelerometer only mode and by reading out the magnetic data in magnetometer only or hybrid modes. In hybrid mode and with M_CTRL_REG2[hyb_autoinc_mode] = 1, all of the sensor data can be read out in a 12-byte burst read starting at register 0x01 (OUT_X_MSB).","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 29 (PDF p.41); field description source: Table 30 (PDF p.42); enumerated-value source: not separately provided."}] | [{"name_or_parameter":"src_aslp","field_description":"Auto-sleep/wake interrupt status (cleared by reading SYSMOD)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"src_fifo","field_description":"FIFO interrupt status (cleared by reading F_STATUS)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"src_trans","field_description":"Transient interrupt status (cleared by reading TRANSIENT_SRC)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"src_Indprt","field_description":"Landscape/portrait interrupt status (cleared by reading PL_STATUS)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"src_pulse","field_description":"Pulse detection interrupt status (cleared by reading PULSE_SRC)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"src_ffmt","field_description":"Freefall/motion interrupt status (cleared by reading A_FFMT_SRC)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"src_a_vecm","field_description":"Acceleration vector-magnitude interrupt status (cleared by reading INT_SOURCE)","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"src_drdy","field_description":"Data-ready interrupt status (accelerometer/magnetometer depending on mode)","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared leniently.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "INT_SOURCE" | "INT_SOURCE" |
| `physical_address` | 0.4044 | 1.0 | [12] | [{"hex":"0x0C","decimal":"12","bank":"","page":"","description":"Interrupt status flags"}] |
| `register_description` | 0.0564 | 1.0 | "Interrupt status" | "Interrupt source/status flags identifying which functional blocks asserted interrupts." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 1.000000 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{10})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

### Extracted logical register 11: `WHO_AM_I`

without location: `registers[10]`; extracted physical locations: 0x0D (13).
Truth association: datasheet `WHO_AM_I` at 0x0D (13).
Datasheet source: Table 31 (PDF p.42); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `WHO_AM_I` at 0x0D (13)

Locations: `truth registers[11].field_parts[0]` ↔ `without registers[10].field_parts[0]`.

**Datasheet bit field 1: `who_am_i[7:0]` [7:0]**

Locations: `truth registers[11].field_parts[0].bit_field[0]` ↔ `without registers[10].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 31 (PDF p.42); field description source: not separately provided; enumerated-value source: Section 14.1.7 (PDF p.42).
Judgment: partial value enumeration; missing codes=[('raw', '"0xC4"')].

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "who_am_i[7:0]" | "who_am_i[7:0]" |
| `field_description` | 0.0586 | 1.0 | "" | "Device identifier" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 0.5 | [{"value":"0xC4","value_description":"Preproduction devices"},{"value":"0xC7","value_description":"Production devices"}] | [{"value":"0xC7","value_description":"Production device ID"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.500000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.895050/0.9999=\mathbf{0.895140}\).

**Field-part aggregation**

`bit_field` correctness = mean(0.895140) = **0.895140**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "WHO_AM_I" | "WHO_AM_I" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Device ID"} | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Device ID"} |
| `description` | 0.0693 | 1.0 | "Device ID" | "Device identification register" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 0.895140 | [{"name_or_parameter":"who_am_i[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"0xC4","value_description":"Preproduction devices"},{"value":"0xC7","value_description":"Production devices"}],"is_reserved":false,"type_write_read":"R","source":"allocation Table 31 (PDF p.42); field description source: not separately provided; enumerated-value source: Section 14.1.7 (PDF p.42)."}] | [{"name_or_parameter":"who_am_i[7:0]","field_description":"Device identifier","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"0xC7","value_description":"Production device ID"}],"is_reserved":false,"type_write_read":"R"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.895140)/1.0000=0.967189/1.0000=\mathbf{0.967189}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.967189) = **0.967189**. Judgment: all direct facts match; descriptions compared leniently.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "WHO_AM_I" | "WHO_AM_I" |
| `physical_address` | 0.4044 | 1.0 | [13] | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":"Device identification (WHO_AM_I)"}] |
| `register_description` | 0.0564 | 1.0 | "Device ID" | "Device ID register; returns device identifier (production = 0xC7)." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 0.967189 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | "0xC7" | "0xC7" |
| `default_value_description` | 0.0334 | 1.0 | "0xC4 for preproduction devices; 0xC7 for production devices." | "Production device ID" |

\(Q(L_{11})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.967189 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.990299/1.0001=\mathbf{0.990200}\).

### Extracted logical register 12: `XYZ_DATA_CFG`

without location: `registers[11]`; extracted physical locations: 0x0E (14).
Truth association: datasheet `XYZ_DATA_CFG` at 0x0E (14).
Datasheet source: Table 59 (PDF p.55); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `XYZ_DATA_CFG` at 0x0E (14)

Locations: `truth registers[12].field_parts[0]` ↔ `without registers[11].field_parts[0]`.

**Datasheet bit field 1: `-` [7:7]**

Locations: `truth registers[12].field_parts[0].bit_field[0]` ↔ `without: missing`.
Datasheet source: allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Datasheet bit field 2: `-` [6:6]**

Locations: `truth registers[12].field_parts[0].bit_field[1]` ↔ `without: missing`.
Datasheet source: allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Datasheet bit field 3: `-` [5:5]**

Locations: `truth registers[12].field_parts[0].bit_field[2]` ↔ `without: missing`.
Datasheet source: allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Datasheet bit field 4: `hpf_out` [4:4]**

Locations: `truth registers[12].field_parts[0].bit_field[3]` ↔ `without registers[11].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 59 (PDF p.55); field description source: Table 60 (PDF p.55); enumerated-value source: Table 60 (PDF p.55).
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "hpf_out" | "hpf_out" |
| `field_description` | 0.0586 | 1.0 | "Enable high-pass filter on acceleration output data 1 – Output data is high-pass filtered 0 – High-pass filter is disabled." | "High-pass filter on acceleration output (1=enabled)" |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"1","value_description":"Output data is high-pass filtered"},{"value":"0","value_description":"High-pass filter is disabled"}] | [{"value":"0","value_description":"HPF disabled"},{"value":"1","value_description":"HPF enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 5: `-` [3:3]**

Locations: `truth registers[12].field_parts[0].bit_field[4]` ↔ `without: missing`.
Datasheet source: allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 3 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Datasheet bit field 6: `-` [2:2]**

Locations: `truth registers[12].field_parts[0].bit_field[5]` ↔ `without: missing`.
Datasheet source: allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 2 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Datasheet bit field 7: `fs[1:0]` [1:0]**

Locations: `truth registers[12].field_parts[0].bit_field[6]` ↔ `without registers[11].field_parts[0].bit_field[1]`.
Datasheet source: allocation Table 59 (PDF p.55); field description source: Table 60 (PDF p.55); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "fs[1:0]" | "fs[1:0]" |
| `field_description` | 0.0586 | 1.0 | "Accelerometer full-scale range selection. See Table 61." | "Full-scale range selection" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [{"value":"0b00","value_description":"±2 g (0.244 mg/LSB)"},{"value":"0b01","value_description":"±4 g (0.488 mg/LSB)"},{"value":"0b10","value_description":"±8 g (0.976 mg/LSB)"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 1.000000) = **0.285714**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "XYZ_DATA_CFG" | "XYZ_DATA_CFG" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x0E","decimal":"14","bank":"","page":"","description":"Acceleration dynamic range and filter enable settings"} | {"hex":"0x0E","decimal":"14","bank":"","page":"","description":"Accelerometer range and HPF enable"} |
| `description` | 0.0693 | 1.0 | "Acceleration dynamic range and filter enable settings" | "Full-scale range selection and output HPF enable" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.285714 | [{"name_or_parameter":"-","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"hpf_out","field_description":"Enable high-pass filter on acceleration output data 1 – Output data is high-pass filtered 0 – High-pass filter is disabled.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"1","value_description":"Output data is high-pass filtered"},{"value":"0","value_description":"High-pass filter is disabled"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: Table 60 (PDF p.55); enumerated-value source: Table 60 (PDF p.55)."},{"name_or_parameter":"-","field_description":"","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"fs[1:0]","field_description":"Accelerometer full-scale range selection. See Table 61.","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: Table 60 (PDF p.55); enumerated-value source: not separately provided."}] | [{"name_or_parameter":"hpf_out","field_description":"High-pass filter on acceleration output (1=enabled)","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"HPF disabled"},{"value":"1","value_description":"HPF enabled"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"fs[1:0]","field_description":"Full-scale range selection","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"±2 g (0.244 mg/LSB)"},{"value":"0b01","value_description":"±4 g (0.488 mg/LSB)"},{"value":"0b10","value_description":"±8 g (0.976 mg/LSB)"}],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.285714)/1.0000=0.776500/1.0000=\mathbf{0.776500}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.776500) = **0.776500**. Judgment: all direct facts match; descriptions compared leniently.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "XYZ_DATA_CFG" | "XYZ_DATA_CFG" |
| `physical_address` | 0.4044 | 1.0 | [14] | [{"hex":"0x0E","decimal":"14","bank":"","page":"","description":"Acceleration dynamic range and filter enable settings"}] |
| `register_description` | 0.0564 | 1.0 | "Acceleration dynamic range and filter enable settings" | "Configures accelerometer full-scale range and enables high-pass filter on output." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.776500 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{12})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.776500 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.933341/1.0001=\mathbf{0.933247}\).

### Extracted logical register 13: `CTRL_REG1`

without location: `registers[12]`; extracted physical locations: 0x2A (42).
Truth association: datasheet `CTRL_REG1` at 0x2A (42).
Datasheet source: Table 32 (PDF p.42); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `CTRL_REG1` at 0x2A (42)

Locations: `truth registers[36].field_parts[0]` ↔ `without registers[12].field_parts[0]`.

**Datasheet bit field 1: `aslp_rate[1:0]` [7:6]**

Locations: `truth registers[36].field_parts[0].bit_field[0]` ↔ `without registers[12].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 32 (PDF p.42); field description source: Table 33 (PDF p.43); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "aslp_rate[1:0]" | "aslp_rate[1:0]" |
| `field_description` | 0.0586 | 1.0 | "Configures the auto-wake sample frequency when the device is in sleep mode. See Table 35 for more information." | "Auto-sleep sample frequency selection" |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 2: `dr[2:0]` [5:3]**

Locations: `truth registers[36].field_parts[0].bit_field[1]` ↔ `without registers[12].field_parts[0].bit_field[1]`.
Datasheet source: allocation Table 32 (PDF p.42); field description source: Table 33 (PDF p.43); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "dr[2:0]" | "dr[2:0]" |
| `field_description` | 0.0586 | 1.0 | "Output data rate (ODR) selection. See Table 35 for more information." | "Output data rate selection (ODR) for accel/mag-only modes; effective ODR halved in hybrid mode" |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 3: `Inoise` [2:2]**

Locations: `truth registers[36].field_parts[0].bit_field[2]` ↔ `without registers[12].field_parts[0].bit_field[2]`.
Datasheet source: allocation Table 32 (PDF p.42); field description source: Table 33 (PDF p.43); enumerated-value source: Table 33 (PDF p.43).
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "Inoise" | "Inoise" |
| `field_description` | 0.0586 | 1.0 | "Reduced noise and full-scale range mode (analog gain times 2). 0 – Normal mode 1 – Reduced noise mode; Note that the FSR setting is restricted to ±2 g or ±4 g mode. This feature cannot be used in ±8 g mode." | "Low-noise mode enable (0 normal, 1 reduced noise; restricts FSR to ±2 g or ±4 g)" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Normal mode"},{"value":"1","value_description":"Reduced noise mode; Note that the FSR setting is restricted to ±2 g or ±4 g mode. This feature cannot be used in ±8 g mode"}] | [{"value":"0","value_description":"Normal"},{"value":"1","value_description":"Reduced noise mode (Inoise)"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 4: `f_read` [1:1]**

Locations: `truth registers[36].field_parts[0].bit_field[3]` ↔ `without registers[12].field_parts[0].bit_field[3]`.
Datasheet source: allocation Table 32 (PDF p.42); field description source: Table 33 (PDF p.43); enumerated-value source: Table 33 (PDF p.43).
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "f_read" | "f_read" |
| `field_description` | 0.0586 | 1.0 | "Fast-read mode: Data format is limited to the 8-bit MSB for accelerometer output data. The auto-address pointer will skip over the LSB addresses for each axes sample data when performing a burst-read operation. 0 – Normal mode 1 – Fast-read mode" | "Fast-read mode (0 normal 16-bit reads, 1 fast 8-bit MSB-only reads)" |
| `bit_start` | 0.2594 | 1.0 | 1 | 1 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Normal mode"},{"value":"1","value_description":"Fast-read mode"}] | [{"value":"0","value_description":"Normal (16-bit reads)"},{"value":"1","value_description":"Fast-read mode (MSB only)"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 5: `active` [0:0]**

Locations: `truth registers[36].field_parts[0].bit_field[4]` ↔ `without registers[12].field_parts[0].bit_field[4]`.
Datasheet source: allocation Table 32 (PDF p.42); field description source: Table 33 (PDF p.43); enumerated-value source: Table 33 (PDF p.43).
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "active" | "active" |
| `field_description` | 0.0586 | 1.0 | "Standby/active. 0 – Standby mode 1 – Active mode" | "Active (1) / Standby (0) mode selection" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 0 | 0 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Standby mode"},{"value":"1","value_description":"Active mode"}] | [{"value":"0","value_description":"Standby"},{"value":"1","value_description":"Active"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "CTRL_REG1" | "CTRL_REG1" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"System ODR, accelerometer OSR, operating mode"} | {"hex":"0x2A","decimal":"42","bank":"","page":"","description":"Control register 1"} |
| `description` | 0.0693 | 1.0 | "System ODR, accelerometer OSR, operating mode" | "ODR, auto-sleep rate, low-noise, fast-read, active" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"aslp_rate[1:0]","field_description":"Configures the auto-wake sample frequency when the device is in sleep mode. See Table 35 for more information.","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 32 (PDF p.42); field description source: Table 33 (PDF p.43); enumerated-value source: not separately provided."},{"name_or_parameter":"dr[2:0]","field_description":"Output data rate (ODR) selection. See Table 35 for more information.","bit_start":3,"bit_end":5,"bit_width":3,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 32 (PDF p.42); field description source: Table 33 (PDF p.43); enumerated-value source: not separately provided."},{"name_or_parameter":"Inoise","field_description":"Reduced noise and full-scale range mode (analog gain times 2). 0 – Normal mode 1 – Reduced noise mode; Note that the FSR setting is restricted to ±2 g or ±4 g mode. This feature cannot be used in ±8 g mode.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Normal mode"},{"value":"1","value_description":"Reduced noise mode; Note that the FSR setting is restricted to ±2 g or ±4 g mode. This feature cannot be used in ±8 g mode"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 32 (PDF p.42); field description source: Table 33 (PDF p.43); enumerated-value source: Table 33 (PDF p.43)."},{"name_or_parameter":"f_read","field_description":"Fast-read mode: Data format is limited to the 8-bit MSB for accelerometer output data. The auto-address pointer will skip over the LSB addresses for each axes sample data when performing a burst-read operation. 0 – Normal mode 1 – Fast-read mode","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Normal mode"},{"value":"1","value_description":"Fast-read mode"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 32 (PDF p.42); field description source: Table 33 (PDF p.43); enumerated-value source: Table 33 (PDF p.43)."},{"name_or_parameter":"active","field_description":"Standby/active. 0 – Standby mode 1 – Active mode","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Standby mode"},{"value":"1","value_description":"Active mode"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 32 (PDF p.42); field description source: Table 33 (PDF p.43); enumerated-value source: Table 33 (PDF p.43)."}] | [{"name_or_parameter":"aslp_rate[1:0]","field_description":"Auto-sleep sample frequency selection","bit_start":6,"bit_end":7,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"dr[2:0]","field_description":"Output data rate selection (ODR) for accel/mag-only modes; effective ODR halved in hybrid mode","bit_start":3,"bit_end":5,"bit_width":3,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"Inoise","field_description":"Low-noise mode enable (0 normal, 1 reduced noise; restricts FSR to ±2 g or ±4 g)","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"Normal"},{"value":"1","value_description":"Reduced noise mode (Inoise)"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"f_read","field_description":"Fast-read mode (0 normal 16-bit reads, 1 fast 8-bit MSB-only reads)","bit_start":1,"bit_end":1,"bit_width":1,"values":[{"value":"0","value_description":"Normal (16-bit reads)"},{"value":"1","value_description":"Fast-read mode (MSB only)"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"active","field_description":"Active (1) / Standby (0) mode selection","bit_start":0,"bit_end":0,"bit_width":1,"values":[{"value":"0","value_description":"Standby"},{"value":"1","value_description":"Active"}],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. Judgment: all direct facts match; descriptions compared leniently.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "CTRL_REG1" | "CTRL_REG1" |
| `physical_address` | 0.4044 | 1.0 | [42] | [{"hex":"0x2A","decimal":"42","bank":"","page":"","description":"System ODR, accelerometer OSR, operating mode (standby/active)"}] |
| `register_description` | 0.0564 | 1.0 | "System ODR, accelerometer OSR, operating mode" | "Controls system ODR (dr), auto-sleep rate (aslp_rate), noise mode, fast-read selection and active/standby state." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 1.000000 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{13})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=1.000100/1.0001=\mathbf{1.000000}\).

### Extracted logical register 14: `CTRL_REG2`

without location: `registers[13]`; extracted physical locations: 0x2B (43).
Truth association: datasheet `CTRL_REG2` at 0x2B (43).
Datasheet source: Table 36 (PDF p.44); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `CTRL_REG2` at 0x2B (43)

Locations: `truth registers[37].field_parts[0]` ↔ `without registers[13].field_parts[0]`.

**Datasheet bit field 1: `st` [7:7]**

Locations: `truth registers[37].field_parts[0].bit_field[0]` ↔ `without registers[13].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 36 (PDF p.44); field description source: Table 37 (PDF p.45); enumerated-value source: Table 37 (PDF p.45).
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "st" | "st" |
| `field_description` | 0.0586 | 1.0 | "The st bit activates the accelerometer self-test function. When st is set to 1, a change will occur in the device output levels for each axis, allowing the host application to check the functionality of the transducer and measurement signal chain. Self-test enable: 0 – Self-test disabled 1 – Self-test enabled" | "Self-test enable (1 enables accelerometer self-test)" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Self-test disabled"},{"value":"1","value_description":"Self-test enabled"}] | [{"value":"0","value_description":"Self-test disabled"},{"value":"1","value_description":"Self-test enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 2: `rst` [6:6]**

Locations: `truth registers[37].field_parts[0].bit_field[1]` ↔ `without registers[13].field_parts[0].bit_field[1]`.
Datasheet source: allocation Table 36 (PDF p.44); field description source: Table 37 (PDF p.45); enumerated-value source: Table 37 (PDF p.45).
Judgment: datasheet value enumeration is missing.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "rst" | "rst" |
| `field_description` | 0.0586 | 1.0 | "The rst bit is used to initiate a software reset. The reset mechanism can be enabled in both standby and active modes. When the rst bit is set, the boot mechanism resets all functional block registers and loads the respective internal registers with their default values. Refer to document FXOS8700CQER for further information and a suggested work-around. After setting the rst bit, the system will automatically transition to standby mode. Therefore, if the system was already in standby mode, the reboot process will immediately begin; else if the system was in active mode the boot mechanism will automatically transition the system from active mode to standby mode, only then can the reboot process begin. A system reset can also be initiated by pulsing the external RST pin high. The host application should allow 1 ms between issuing a software (setting rst bit) or hardware (pulsing RST pin) reset and attempting communications with the device over the I²C or SPI interfaces. When the SPI interface mode is desired and multiple devices are present on the bus, make sure that the bus is quiet (all slave device MISO pins are high-z) during this 1 ms period to ensure the device does not inadvertently enter I²C mode. See Section 10.2.3 for further information about the interface mode auto-detection circuit. Note: The I²C and SPI communication systems are also reset to avoid corrupted data transactions. On issuing a software reset command over an I²C interface, the device immediately resets and does not send any acknowledgment (ACK) of the written byte to the master. The host application has to implement the I²C driver in such a way that it does not look for an ACK following a soft reset command. At the end of the boot process, the rst bit is hardware cleared. 0 – Device reset disabled 1 – Device reset enabled" | "Software reset (setting this bit initiates reset; hardware-cleared when complete)" |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Device reset disabled"},{"value":"1","value_description":"Device reset enabled"}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Datasheet bit field 3: `-` [5:5]**

Locations: `truth registers[37].field_parts[0].bit_field[2]` ↔ `without: missing`.
Datasheet source: allocation Table 36 (PDF p.44); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 5 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Datasheet bit field 4: `smods[1:0]` [4:3]**

Locations: `truth registers[37].field_parts[0].bit_field[3]` ↔ `without registers[13].field_parts[0].bit_field[2]`.
Datasheet source: allocation Table 36 (PDF p.44); field description source: Table 37 (PDF p.45); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "smods[1:0]" | "smods[1:0]" |
| `field_description` | 0.0586 | 1.0 | "Accelerometer sleep mode OSR mode selection. This setting, along with the CTRL_REG1[aslp_rate] ODR setting determines the sleep mode power and noise for acceleration measurements. See Table 38 and Table 39 for more information." | "Accelerometer sleep-mode OSR selection" |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 5: `slpe` [2:2]**

Locations: `truth registers[37].field_parts[0].bit_field[4]` ↔ `without registers[13].field_parts[0].bit_field[3]`.
Datasheet source: allocation Table 36 (PDF p.44); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "slpe" | "slpe" |
| `field_description` | 0.0586 | 1.0 | "" | "Auto-sleep enable (1 = enabled)" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 6: `mods[1:0]` [1:0]**

Locations: `truth registers[37].field_parts[0].bit_field[5]` ↔ `without registers[13].field_parts[0].bit_field[4]`.
Datasheet source: allocation Table 36 (PDF p.44); field description source: Table 37 (PDF p.45); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "mods[1:0]" | "mods[1:0]" |
| `field_description` | 0.0586 | 1.0 | "Accelerometer wake mode OSR mode selection. This setting, along with the ODR selection (CTRL_REG1[dr]) determines the wake mode power and noise for acceleration measurements. See Table 38 and Table 39 for more information." | "Accelerometer wake-mode OSR selection" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 0.790279, 0.000000, 1.000000, 1.000000, 1.000000) = **0.798380**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "CTRL_REG2" | "CTRL_REG2" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Self-test, reset, accelerometer OSR and sleep mode settings"} | {"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Control register 2"} |
| `description` | 0.0693 | 1.0 | "Self-test, reset, accelerometer OSR and sleep mode settings" | "Self-test, software reset, sleep/wake OSR, auto-sleep" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.798380 | [{"name_or_parameter":"st","field_description":"The st bit activates the accelerometer self-test function. When st is set to 1, a change will occur in the device output levels for each axis, allowing the host application to check the functionality of the transducer and measurement signal chain. Self-test enable: 0 – Self-test disabled 1 – Self-test enabled","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Self-test disabled"},{"value":"1","value_description":"Self-test enabled"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 36 (PDF p.44); field description source: Table 37 (PDF p.45); enumerated-value source: Table 37 (PDF p.45)."},{"name_or_parameter":"rst","field_description":"The rst bit is used to initiate a software reset. The reset mechanism can be enabled in both standby and active modes. When the rst bit is set, the boot mechanism resets all functional block registers and loads the respective internal registers with their default values. Refer to document FXOS8700CQER for further information and a suggested work-around. After setting the rst bit, the system will automatically transition to standby mode. Therefore, if the system was already in standby mode, the reboot process will immediately begin; else if the system was in active mode the boot mechanism will automatically transition the system from active mode to standby mode, only then can the reboot process begin. A system reset can also be initiated by pulsing the external RST pin high. The host application should allow 1 ms between issuing a software (setting rst bit) or hardware (pulsing RST pin) reset and attempting communications with the device over the I²C or SPI interfaces. When the SPI interface mode is desired and multiple devices are present on the bus, make sure that the bus is quiet (all slave device MISO pins are high-z) during this 1 ms period to ensure the device does not inadvertently enter I²C mode. See Section 10.2.3 for further information about the interface mode auto-detection circuit. Note: The I²C and SPI communication systems are also reset to avoid corrupted data transactions. On issuing a software reset command over an I²C interface, the device immediately resets and does not send any acknowledgment (ACK) of the written byte to the master. The host application has to implement the I²C driver in such a way that it does not look for an ACK following a soft reset command. At the end of the boot process, the rst bit is hardware cleared. 0 – Device reset disabled 1 – Device reset enabled","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Device reset disabled"},{"value":"1","value_description":"Device reset enabled"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 36 (PDF p.44); field description source: Table 37 (PDF p.45); enumerated-value source: Table 37 (PDF p.45)."},{"name_or_parameter":"-","field_description":"","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 36 (PDF p.44); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"smods[1:0]","field_description":"Accelerometer sleep mode OSR mode selection. This setting, along with the CTRL_REG1[aslp_rate] ODR setting determines the sleep mode power and noise for acceleration measurements. See Table 38 and Table 39 for more information.","bit_start":3,"bit_end":4,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 36 (PDF p.44); field description source: Table 37 (PDF p.45); enumerated-value source: not separately provided."},{"name_or_parameter":"slpe","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 36 (PDF p.44); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"mods[1:0]","field_description":"Accelerometer wake mode OSR mode selection. This setting, along with the ODR selection (CTRL_REG1[dr]) determines the wake mode power and noise for acceleration measurements. See Table 38 and Table 39 for more information.","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 36 (PDF p.44); field description source: Table 37 (PDF p.45); enumerated-value source: not separately provided."}] | [{"name_or_parameter":"st","field_description":"Self-test enable (1 enables accelerometer self-test)","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Self-test disabled"},{"value":"1","value_description":"Self-test enabled"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"rst","field_description":"Software reset (setting this bit initiates reset; hardware-cleared when complete)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"smods[1:0]","field_description":"Accelerometer sleep-mode OSR selection","bit_start":3,"bit_end":4,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"slpe","field_description":"Auto-sleep enable (1 = enabled)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"mods[1:0]","field_description":"Accelerometer wake-mode OSR selection","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.798380)/1.0000=0.936913/1.0000=\mathbf{0.936913}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.936913) = **0.936913**. Judgment: all direct facts match; descriptions compared leniently.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "CTRL_REG2" | "CTRL_REG2" |
| `physical_address` | 0.4044 | 1.0 | [43] | [{"hex":"0x2B","decimal":"43","bank":"","page":"","description":"Self-test, reset, accelerometer OSR and sleep mode settings"}] |
| `register_description` | 0.0564 | 1.0 | "Self-test, reset, accelerometer OSR and sleep mode settings" | "Self-test, software reset, sleep/wake OSR selections and auto-sleep enable; controls accelerometer oversampling modes." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.936913 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{14})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.936913 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.981256/1.0001=\mathbf{0.981158}\).

### Extracted logical register 15: `M_CTRL_REG1`

without location: `registers[14]`; extracted physical locations: 0x5B (91).
Truth association: datasheet `M_CTRL_REG1` at 0x5B (91).
Datasheet source: Table 197 (PDF p.96); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `M_CTRL_REG1` at 0x5B (91)

Locations: `truth registers[85].field_parts[0]` ↔ `without registers[14].field_parts[0]`.

**Datasheet bit field 1: `m_acal` [7:7]**

Locations: `truth registers[85].field_parts[0].bit_field[0]` ↔ `without registers[14].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: Table 198 (PDF p.97).
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "m_acal" | "m_acal" |
| `field_description` | 0.0586 | 1.0 | "Magnetic hard-iron offset auto-calibration enable: 0 – Auto-calibration feature disabled 1 – Auto-calibration feature is enabled; the ASIC uses the maximum and minimum magnetic data to determine the hard iron offset value. The M_OFF_X/Y/Z registers are automatically loaded with (MAX_X/Y/Z + MIN_X/Y/Z)/2 for each axis at the end of every ODR cycle." | "Auto-calibration enable (hard-iron offset auto-cal)" |
| `bit_start` | 0.2594 | 1.0 | 7 | 7 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [{"value":"0","value_description":"Auto-calibration feature disabled"},{"value":"1","value_description":"Auto-calibration feature is enabled; the ASIC uses the maximum and minimum magnetic data to determine the hard iron offset value. The M_OFF_X/Y/Z registers are automatically loaded with (MAX_X/Y/Z + MIN_X/Y/Z)/2 for each axis at the end of every ODR cycle"}] | [{"value":"0","value_description":"Auto-calibration disabled"},{"value":"1","value_description":"Auto-calibration enabled"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 2: `m_rst` [6:6]**

Locations: `truth registers[85].field_parts[0].bit_field[1]` ↔ `without registers[14].field_parts[0].bit_field[1]`.
Datasheet source: allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: Table 198 (PDF p.97).
Judgment: datasheet value enumeration is missing.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "m_rst" | "m_rst" |
| `field_description` | 0.0586 | 1.0 | "One-shot magnetic reset degauss control bit: 0 – No magnetic sensor reset is active 1 – One-shot magnetic reset is enabled, hardware cleared when complete." | "One-shot magnetic reset degauss control (write to initiate)" |
| `bit_start` | 0.2594 | 1.0 | 6 | 6 |
| `bit_end` | 0.2594 | 1.0 | 6 | 6 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No magnetic sensor reset is active"},{"value":"1","value_description":"One-shot magnetic reset is enabled, hardware cleared when complete"}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Datasheet bit field 3: `m_ost` [5:5]**

Locations: `truth registers[85].field_parts[0].bit_field[2]` ↔ `without registers[14].field_parts[0].bit_field[2]`.
Datasheet source: allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: Table 198 (PDF p.97).
Judgment: datasheet value enumeration is missing.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "m_ost" | "m_ost" |
| `field_description` | 0.0586 | 1.0 | "One-shot triggered magnetic measurement mode: 0 – No action taken, or one-shot measurement complete. 1 – If device is in active mode no action is taken. If device is in standby mode, take one set of magnetic measurements, clear this bit, and return to standby mode." | "One-shot triggered magnetic measurement (in standby: take one measurement then return to standby)" |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No action taken, or one-shot measurement complete"},{"value":"1","value_description":"If device is in active mode no action is taken. If device is in standby mode, take one set of magnetic measurements, clear this bit, and return to standby mode"}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Datasheet bit field 4: `m_os[2:0]` [4:2]**

Locations: `truth registers[85].field_parts[0].bit_field[3]` ↔ `without registers[14].field_parts[0].bit_field[3]`.
Datasheet source: allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "m_os[2:0]" | "m_os[2:0]" |
| `field_description` | 0.0586 | 1.0 | "Oversample ratio (OSR) for magnetometer data (see Table 203)." | "Magnetometer oversampling ratio (OSR) selection" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 3 | 3 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 5: `m_hms[1:0]` [1:0]**

Locations: `truth registers[85].field_parts[0].bit_field[4]` ↔ `without registers[14].field_parts[0].bit_field[4]`.
Datasheet source: allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: Table 198 (PDF p.97).
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "m_hms[1:0]" | "m_hms[1:0]" |
| `field_description` | 0.0586 | 1.0 | "0b00 – Only accelerometer sensor is active 0b01 – Only magnetometer sensor is active 0b11 – Hybrid mode, both accelerometer and magnetometer sensors are active[1]" | "Mode select: 00 accel only; 01 mag only; 11 hybrid accel+mag" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"0b00","value_description":"Only accelerometer sensor is active"},{"value":"0b01","value_description":"Only magnetometer sensor is active"},{"value":"0b11","value_description":"Hybrid mode, both accelerometer and magnetometer sensors are active[1]"}] | [{"value":"0b00","value_description":"Accelerometer only"},{"value":"0b01","value_description":"Magnetometer only"},{"value":"0b11","value_description":"Hybrid (accel + mag)"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000, 0.790279, 0.790279, 1.000000, 1.000000) = **0.916112**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "M_CTRL_REG1" | "M_CTRL_REG1" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x5B","decimal":"91","bank":"","page":"","description":"Control for magnetic sensor functions"} | {"hex":"0x5B","decimal":"91","bank":"","page":"","description":"Magnetometer control register 1"} |
| `description` | 0.0693 | 1.0 | "Control for magnetic sensor functions" | "Magnetometer control: auto-cal, reset, one-shot, OSR, hybrid mode" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.916112 | [{"name_or_parameter":"m_acal","field_description":"Magnetic hard-iron offset auto-calibration enable: 0 – Auto-calibration feature disabled 1 – Auto-calibration feature is enabled; the ASIC uses the maximum and minimum magnetic data to determine the hard iron offset value. The M_OFF_X/Y/Z registers are automatically loaded with (MAX_X/Y/Z + MIN_X/Y/Z)/2 for each axis at the end of every ODR cycle.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Auto-calibration feature disabled"},{"value":"1","value_description":"Auto-calibration feature is enabled; the ASIC uses the maximum and minimum magnetic data to determine the hard iron offset value. The M_OFF_X/Y/Z registers are automatically loaded with (MAX_X/Y/Z + MIN_X/Y/Z)/2 for each axis at the end of every ODR cycle"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: Table 198 (PDF p.97)."},{"name_or_parameter":"m_rst","field_description":"One-shot magnetic reset degauss control bit: 0 – No magnetic sensor reset is active 1 – One-shot magnetic reset is enabled, hardware cleared when complete.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No magnetic sensor reset is active"},{"value":"1","value_description":"One-shot magnetic reset is enabled, hardware cleared when complete"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: Table 198 (PDF p.97)."},{"name_or_parameter":"m_ost","field_description":"One-shot triggered magnetic measurement mode: 0 – No action taken, or one-shot measurement complete. 1 – If device is in active mode no action is taken. If device is in standby mode, take one set of magnetic measurements, clear this bit, and return to standby mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No action taken, or one-shot measurement complete"},{"value":"1","value_description":"If device is in active mode no action is taken. If device is in standby mode, take one set of magnetic measurements, clear this bit, and return to standby mode"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: Table 198 (PDF p.97)."},{"name_or_parameter":"m_os[2:0]","field_description":"Oversample ratio (OSR) for magnetometer data (see Table 203).","bit_start":2,"bit_end":4,"bit_width":3,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: not separately provided."},{"name_or_parameter":"m_hms[1:0]","field_description":"0b00 – Only accelerometer sensor is active 0b01 – Only magnetometer sensor is active 0b11 – Hybrid mode, both accelerometer and magnetometer sensors are active[1]","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"Only accelerometer sensor is active"},{"value":"0b01","value_description":"Only magnetometer sensor is active"},{"value":"0b11","value_description":"Hybrid mode, both accelerometer and magnetometer sensors are active[1]"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: Table 198 (PDF p.97)."}] | [{"name_or_parameter":"m_acal","field_description":"Auto-calibration enable (hard-iron offset auto-cal)","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Auto-calibration disabled"},{"value":"1","value_description":"Auto-calibration enabled"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_rst","field_description":"One-shot magnetic reset degauss control (write to initiate)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_ost","field_description":"One-shot triggered magnetic measurement (in standby: take one measurement then return to standby)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_os[2:0]","field_description":"Magnetometer oversampling ratio (OSR) selection","bit_start":2,"bit_end":4,"bit_width":3,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_hms[1:0]","field_description":"Mode select: 00 accel only; 01 mag only; 11 hybrid accel+mag","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"Accelerometer only"},{"value":"0b01","value_description":"Magnetometer only"},{"value":"0b11","value_description":"Hybrid (accel + mag)"}],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.916112)/1.0000=0.973751/1.0000=\mathbf{0.973751}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.973751) = **0.973751**. Judgment: all direct facts match; descriptions compared leniently.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "M_CTRL_REG1" | "M_CTRL_REG1" |
| `physical_address` | 0.4044 | 1.0 | [91] | [{"hex":"0x5B","decimal":"91","bank":"","page":"","description":"Control for magnetic sensor functions"}] |
| `register_description` | 0.0564 | 1.0 | "Control for magnetic sensor functions" | "Magnetometer control: auto-calibration, one-shot reset/measurement, magnetometer OSR (m_os) and hybrid mode selection (m_hms)." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.973751 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{15})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.973751 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.992260/1.0001=\mathbf{0.992160}\).

### Extracted logical register 16: `M_CTRL_REG2`

without location: `registers[15]`; extracted physical locations: 0x5C (92).
Truth association: datasheet `M_CTRL_REG2` at 0x5C (92).
Datasheet source: Table 199 (PDF p.97); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `M_CTRL_REG2` at 0x5C (92)

Locations: `truth registers[86].field_parts[0]` ↔ `without registers[15].field_parts[0]`.

**Datasheet bit field 1: `-` [7:7]**

Locations: `truth registers[86].field_parts[0].bit_field[0]` ↔ `without: missing`.
Datasheet source: allocation Table 199 (PDF p.97); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 7 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Datasheet bit field 2: `-` [6:6]**

Locations: `truth registers[86].field_parts[0].bit_field[1]` ↔ `without: missing`.
Datasheet source: allocation Table 199 (PDF p.97); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: bit field is missing from the extracted map.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 0.0 | "-" | MISSING |
| `field_description` | 0.0586 | 0.0 | "" | MISSING |
| `bit_start` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_end` | 0.2594 | 0.0 | 6 | MISSING |
| `bit_width` | 0.0583 | 0.0 | 1 | MISSING |
| `values` | 0.2097 | 0.0 | [] | MISSING |
| `is_reserved` | 0.0750 | 0.0 | True | MISSING |
| `type_write_read` | 0.0583 | 0.0 | "RW" | MISSING |

\(Q_{BF}=(0.0212×0.000000 + 0.0586×0.000000 + 0.2594×0.000000 + 0.2594×0.000000 + 0.0583×0.000000 + 0.2097×0.000000 + 0.0750×0.000000 + 0.0583×0.000000)/0.9999=0.000000/0.9999=\mathbf{0.000000}\).

**Datasheet bit field 3: `hyb_autoinc_mode` [5:5]**

Locations: `truth registers[86].field_parts[0].bit_field[2]` ↔ `without registers[15].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "hyb_autoinc_mode" | "hyb_autoinc_mode" |
| `field_description` | 0.0586 | 1.0 | "With hyb_autoinc_mode = 1 and fast-read mode is disabled (CTRL_REG1 [f_read] = 0), the register address will automatically advance to register 0x33 (M_OUT_X_MSB) after reading register 0x06 (OUT_Z_LSB) in burst-read mode. For hyb_autoinc_mode = 1 and fast-read mode enabled (CTRL_REG1[f_read] = 1) the register address will automatically advance to register 0x33 (M_OUT_X_MSB) after reading register 0x05 (OUT_Z_MSB) during a burst-read mode. Refer to the register map auto-increment address column for further information." | "Hybrid auto-increment mode (maps magnetometer registers after accel registers in burst reads when set)" |
| `bit_start` | 0.2594 | 1.0 | 5 | 5 |
| `bit_end` | 0.2594 | 1.0 | 5 | 5 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Datasheet bit field 4: `m_maxmin_dis` [4:4]**

Locations: `truth registers[86].field_parts[0].bit_field[3]` ↔ `without registers[15].field_parts[0].bit_field[1]`.
Datasheet source: allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: Table 200 (PDF p.98).
Judgment: datasheet value enumeration is missing.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "m_maxmin_dis" | "m_maxmin_dis" |
| `field_description` | 0.0586 | 1.0 | "Magnetic measurement max/min detection function disable: 0 – Magnetic min/max detection function is enabled (default). 1 – Magnetic min/max detection function is disabled. When enabled, the magnetic min/max detection function will update the MAX_X/Y/Z and MIN_X/Y/Z registers at the end of each ODR cycle with the maximum and minimum magnetic measurements from each axis. This is used along with the auto-cal feature (M_CTRL_REG1[m_acal] = 1) as a hardware based hard-iron offset compensation function." | "Disable magnetic max/min detection (1 = disabled)" |
| `bit_start` | 0.2594 | 1.0 | 4 | 4 |
| `bit_end` | 0.2594 | 1.0 | 4 | 4 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"Magnetic min/max detection function is enabled (default)"},{"value":"1","value_description":"Magnetic min/max detection function is disabled. When enabled, the magnetic min/max detection function will update the MAX_X/Y/Z and MIN_X/Y/Z registers at the end of each ODR cycle with the maximum and minimum magnetic measurements from each axis. This is used along with the auto-cal feature (M_CTRL_REG1[m_acal] = 1) as a hardware based hard-iron offset compensation function"}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Datasheet bit field 5: `m_maxmin_dis_ths` [3:3]**

Locations: `truth registers[86].field_parts[0].bit_field[4]` ↔ `without registers[15].field_parts[0].bit_field[2]`.
Datasheet source: allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: Table 200 (PDF p.98).
Judgment: datasheet value enumeration is missing.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "m_maxmin_dis_ths" | "m_maxmin_dis_ths" |
| `field_description` | 0.0586 | 1.0 | "Magnetic measurement min/max detection function disable using the magnetic threshold event trigger: 0 – No impact to magnetic min/max detection function on a magnetic threshold event 1 – Magnetic min/max detection function is disabled when magnetic threshold event is triggered" | "Disable max/min on magnetic threshold event (1 = disabled on threshold)" |
| `bit_start` | 0.2594 | 1.0 | 3 | 3 |
| `bit_end` | 0.2594 | 1.0 | 3 | 3 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No impact to magnetic min/max detection function on a magnetic threshold event"},{"value":"1","value_description":"Magnetic min/max detection function is disabled when magnetic threshold event is triggered"}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Datasheet bit field 6: `m_maxmin_rst` [2:2]**

Locations: `truth registers[86].field_parts[0].bit_field[5]` ↔ `without registers[15].field_parts[0].bit_field[3]`.
Datasheet source: allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: Table 200 (PDF p.98).
Judgment: datasheet value enumeration is missing.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "m_maxmin_rst" | "m_maxmin_rst" |
| `field_description` | 0.0586 | 1.0 | "Magnetic measurement min/max detection function reset: 0 – No reset sequence is active 1 – Setting this bit resets the MIN_X/Y/Z and MAX_X/Y/Z registers to 0x7FFF and 0x8000, respectively (positive and negative full-scale values).This bit is automatically cleared after the reset is completed." | "Reset MAX/MIN registers when set (hardware cleared when complete)" |
| `bit_start` | 0.2594 | 1.0 | 2 | 2 |
| `bit_end` | 0.2594 | 1.0 | 2 | 2 |
| `bit_width` | 0.0583 | 1.0 | 1 | 1 |
| `values` | 0.2097 | 0.0 | [{"value":"0","value_description":"No reset sequence is active"},{"value":"1","value_description":"Setting this bit resets the MIN_X/Y/Z and MAX_X/Y/Z registers to 0x7FFF and 0x8000, respectively (positive and negative full-scale values).This bit is automatically cleared after the reset is completed"}] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×0.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.790200/0.9999=\mathbf{0.790279}\).

**Datasheet bit field 7: `m_rst_cnt[1:0]` [1:0]**

Locations: `truth registers[86].field_parts[0].bit_field[6]` ↔ `without registers[15].field_parts[0].bit_field[4]`.
Datasheet source: allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: Table 200 (PDF p.98).
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "m_rst_cnt[1:0]" | "m_rst_cnt[1:0]" |
| `field_description` | 0.0586 | 1.0 | "Magnetic sensor reset (degaussing) frequency: 0b00 – Automatic magnetic reset at the beginning of each ODR cycle (default). 0b01 – Automatic magnetic reset every 16 ODR cycles. 0b10 – Automatic magnetic reset every 512 ODR cycles. 0b11 – Automatic magnetic reset is disabled. Magnetic reset only occurs automatically on a transition from standby to active mode, or can be triggered manually by setting M_CTRL_REG1[m_rst] = 1" | "Magnetic reset (degauss) frequency selection" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 1 | 1 |
| `bit_width` | 0.0583 | 1.0 | 2 | 2 |
| `values` | 0.2097 | 1.0 | [{"value":"0b00","value_description":"Automatic magnetic reset at the beginning of each ODR cycle (default)"},{"value":"0b01","value_description":"Automatic magnetic reset every 16 ODR cycles"},{"value":"0b10","value_description":"Automatic magnetic reset every 512 ODR cycles"},{"value":"0b11","value_description":"Automatic magnetic reset is disabled. Magnetic reset only occurs automatically on a transition from standby to active mode, or can be triggered manually by setting M_CTRL_REG1[m_rst] = 1"}] | [{"value":"0b00","value_description":"Reset at beginning of each ODR cycle"},{"value":"0b01","value_description":"Reset every 16 ODR cycles"},{"value":"0b10","value_description":"Reset every 512 ODR cycles"},{"value":"0b11","value_description":"Auto reset disabled"}] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "RW" | "RW" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(0.000000, 0.000000, 1.000000, 0.790279, 0.790279, 0.790279, 1.000000) = **0.624405**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "M_CTRL_REG2" | "M_CTRL_REG2" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x5C","decimal":"92","bank":"","page":"","description":"Control for magnetic sensor functions"} | {"hex":"0x5C","decimal":"92","bank":"","page":"","description":"Magnetometer control register 2"} |
| `description` | 0.0693 | 1.0 | "Control for magnetic sensor functions" | "Magnetometer auto-increment, max/min control, reset configuration" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "RW" | "RW" |
| `bit_field` | 0.3129 | 0.624405 | [{"name_or_parameter":"-","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"hyb_autoinc_mode","field_description":"With hyb_autoinc_mode = 1 and fast-read mode is disabled (CTRL_REG1 [f_read] = 0), the register address will automatically advance to register 0x33 (M_OUT_X_MSB) after reading register 0x06 (OUT_Z_LSB) in burst-read mode. For hyb_autoinc_mode = 1 and fast-read mode enabled (CTRL_REG1[f_read] = 1) the register address will automatically advance to register 0x33 (M_OUT_X_MSB) after reading register 0x05 (OUT_Z_MSB) during a burst-read mode. Refer to the register map auto-increment address column for further information.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: not separately provided."},{"name_or_parameter":"m_maxmin_dis","field_description":"Magnetic measurement max/min detection function disable: 0 – Magnetic min/max detection function is enabled (default). 1 – Magnetic min/max detection function is disabled. When enabled, the magnetic min/max detection function will update the MAX_X/Y/Z and MIN_X/Y/Z registers at the end of each ODR cycle with the maximum and minimum magnetic measurements from each axis. This is used along with the auto-cal feature (M_CTRL_REG1[m_acal] = 1) as a hardware based hard-iron offset compensation function.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Magnetic min/max detection function is enabled (default)"},{"value":"1","value_description":"Magnetic min/max detection function is disabled. When enabled, the magnetic min/max detection function will update the MAX_X/Y/Z and MIN_X/Y/Z registers at the end of each ODR cycle with the maximum and minimum magnetic measurements from each axis. This is used along with the auto-cal feature (M_CTRL_REG1[m_acal] = 1) as a hardware based hard-iron offset compensation function"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: Table 200 (PDF p.98)."},{"name_or_parameter":"m_maxmin_dis_ths","field_description":"Magnetic measurement min/max detection function disable using the magnetic threshold event trigger: 0 – No impact to magnetic min/max detection function on a magnetic threshold event 1 – Magnetic min/max detection function is disabled when magnetic threshold event is triggered","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No impact to magnetic min/max detection function on a magnetic threshold event"},{"value":"1","value_description":"Magnetic min/max detection function is disabled when magnetic threshold event is triggered"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: Table 200 (PDF p.98)."},{"name_or_parameter":"m_maxmin_rst","field_description":"Magnetic measurement min/max detection function reset: 0 – No reset sequence is active 1 – Setting this bit resets the MIN_X/Y/Z and MAX_X/Y/Z registers to 0x7FFF and 0x8000, respectively (positive and negative full-scale values).This bit is automatically cleared after the reset is completed.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No reset sequence is active"},{"value":"1","value_description":"Setting this bit resets the MIN_X/Y/Z and MAX_X/Y/Z registers to 0x7FFF and 0x8000, respectively (positive and negative full-scale values).This bit is automatically cleared after the reset is completed"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: Table 200 (PDF p.98)."},{"name_or_parameter":"m_rst_cnt[1:0]","field_description":"Magnetic sensor reset (degaussing) frequency: 0b00 – Automatic magnetic reset at the beginning of each ODR cycle (default). 0b01 – Automatic magnetic reset every 16 ODR cycles. 0b10 – Automatic magnetic reset every 512 ODR cycles. 0b11 – Automatic magnetic reset is disabled. Magnetic reset only occurs automatically on a transition from standby to active mode, or can be triggered manually by setting M_CTRL_REG1[m_rst] = 1","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"Automatic magnetic reset at the beginning of each ODR cycle (default)"},{"value":"0b01","value_description":"Automatic magnetic reset every 16 ODR cycles"},{"value":"0b10","value_description":"Automatic magnetic reset every 512 ODR cycles"},{"value":"0b11","value_description":"Automatic magnetic reset is disabled. Magnetic reset only occurs automatically on a transition from standby to active mode, or can be triggered manually by setting M_CTRL_REG1[m_rst] = 1"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: Table 200 (PDF p.98)."}] | [{"name_or_parameter":"hyb_autoinc_mode","field_description":"Hybrid auto-increment mode (maps magnetometer registers after accel registers in burst reads when set)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_maxmin_dis","field_description":"Disable magnetic max/min detection (1 = disabled)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_maxmin_dis_ths","field_description":"Disable max/min on magnetic threshold event (1 = disabled on threshold)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_maxmin_rst","field_description":"Reset MAX/MIN registers when set (hardware cleared when complete)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_rst_cnt[1:0]","field_description":"Magnetic reset (degauss) frequency selection","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"Reset at beginning of each ODR cycle"},{"value":"0b01","value_description":"Reset every 16 ODR cycles"},{"value":"0b10","value_description":"Reset every 512 ODR cycles"},{"value":"0b11","value_description":"Auto reset disabled"}],"is_reserved":false,"type_write_read":"RW"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×0.624405)/1.0000=0.882476/1.0000=\mathbf{0.882476}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(0.882476) = **0.882476**. Judgment: all direct facts match; descriptions compared leniently.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "M_CTRL_REG2" | "M_CTRL_REG2" |
| `physical_address` | 0.4044 | 1.0 | [92] | [{"hex":"0x5C","decimal":"92","bank":"","page":"","description":"Control for magnetic sensor functions (auto-increment, max/min settings, reset counts)"}] |
| `register_description` | 0.0564 | 1.0 | "Control for magnetic sensor functions" | "Magnetometer control options: hybrid auto-increment mapping, max/min detection control, reset settings and reset frequency." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "RW" | "RW" |
| `field_parts` | 0.2987 | 0.882476 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 1.0 | "0x00" | "0x00" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{16})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×0.882476 + 0.0667×1.000000 + 0.0334×1.000000)/1.0001=0.964996/1.0001=\mathbf{0.964899}\).

### Extracted logical register 17: `M_OUT_X_MSB`

without location: `registers[16]`; extracted physical locations: 0x33 (51).
Truth association: datasheet `M_OUT_X_MSB` at 0x33 (51).
Datasheet source: Table 153 (PDF p.85); register map Table 16 (PDF pp.29-32).

### Bottom-up calculation: bit fields, then field parts

#### Field part 1: `M_OUT_X_MSB` at 0x33 (51)

Locations: `truth registers[45].field_parts[0]` ↔ `without registers[16].field_parts[0]`.

**Datasheet bit field 1: `m_out_x[15:8]` [7:0]**

Locations: `truth registers[45].field_parts[0].bit_field[0]` ↔ `without registers[16].field_parts[0].bit_field[0]`.
Datasheet source: allocation Table 153 (PDF p.85); field description source: not separately provided; enumerated-value source: not separately provided.
Judgment: objective facts match; description compared leniently.

| Scored field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `name_or_parameter` | 0.0212 | 1.0 | "m_out_x[15:8]" | "m_out_x[15:8]" |
| `field_description` | 0.0586 | 1.0 | "" | "Magnetometer X-axis output MSB (bits 15:8)" |
| `bit_start` | 0.2594 | 1.0 | 0 | 0 |
| `bit_end` | 0.2594 | 1.0 | 7 | 7 |
| `bit_width` | 0.0583 | 1.0 | 8 | 8 |
| `values` | 0.2097 | 1.0 | [] | [] |
| `is_reserved` | 0.0750 | 1.0 | False | False |
| `type_write_read` | 0.0583 | 1.0 | "R" | "R" |

\(Q_{BF}=(0.0212×1.000000 + 0.0586×1.000000 + 0.2594×1.000000 + 0.2594×1.000000 + 0.0583×1.000000 + 0.2097×1.000000 + 0.0750×1.000000 + 0.0583×1.000000)/0.9999=0.999900/0.9999=\mathbf{1.000000}\).

**Field-part aggregation**

`bit_field` correctness = mean(1.000000) = **1.000000**. Exact-range extras are listed above and are not included in this target mean. Direct-field judgment: direct facts match; description compared leniently.

| Field-part field | Weight | C | Datasheet content | Extracted content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.0 | "M_OUT_X_MSB" | "M_OUT_X_MSB" |
| `physical_address` | 0.4688 | 1.0 | {"hex":"0x33","decimal":"51","bank":"","page":"","description":"MSB of 16-bit magnetic data for X-axis"} | {"hex":"0x33","decimal":"51","bank":"","page":"","description":"Magnetometer X-axis MSB"} |
| `description` | 0.0693 | 1.0 | "MSB of 16-bit magnetic data for X-axis" | "High byte of 16-bit magnetometer X-axis output" |
| `width_bits` | 0.0605 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0605 | 1.0 | "R" | "R" |
| `bit_field` | 0.3129 | 1.000000 | [{"name_or_parameter":"m_out_x[15:8]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 153 (PDF p.85); field description source: not separately provided; enumerated-value source: not separately provided."}] | [{"name_or_parameter":"m_out_x[15:8]","field_description":"Magnetometer X-axis output MSB (bits 15:8)","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R"}] |

\(Q_{FP}=(0.0280×1.000000 + 0.4688×1.000000 + 0.0693×1.000000 + 0.0605×1.000000 + 0.0605×1.000000 + 0.3129×1.000000)/1.0000=1.000000/1.0000=\mathbf{1.000000}\).

### Extracted logical-register aggregation

`field_parts` correctness = mean(1.000000) = **1.000000**. Judgment: default_value is not fully correct.

| Logical-register field | Weight | C | Datasheet comparison target | Extracted content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.0 | "M_OUT_X_MSB" | "M_OUT_X_MSB" |
| `physical_address` | 0.4044 | 1.0 | [51] | [{"hex":"0x33","decimal":"51","bank":"","page":"","description":"MSB of 16-bit magnetic data for X-axis"}] |
| `register_description` | 0.0564 | 1.0 | "MSB of 16-bit magnetic data for X-axis" | "MSB of 16-bit 2's complement magnetometer X-axis output (0.1 μT/LSB)." |
| `width_bits` | 0.0590 | 1.0 | 8 | 8 |
| `type_write_read` | 0.0590 | 1.0 | "R" | "R" |
| `field_parts` | 0.2987 | 1.000000 | datasheet field-part collection | extracted field-part collection |
| `default_value` | 0.0667 | 0.0 | "Data" | "" |
| `default_value_description` | 0.0334 | 1.0 | "" | "" |

\(Q(L_{17})=(0.0225×1.000000 + 0.4044×1.000000 + 0.0564×1.000000 + 0.0590×1.000000 + 0.0590×1.000000 + 0.2987×1.000000 + 0.0667×0.000000 + 0.0334×1.000000)/1.0001=0.933400/1.0001=\mathbf{0.933307}\).

## 3. Ground-truth physical-register scores for without

For each datasheet physical register, (q_R) is the mean of the Q(L) values associated with that address. Missing actual datasheet registers receive q_R=0. The 0x00 STATUS/DR_STATUS/F_STATUS aliases share one physical location.

| Datasheet physical register | Associated extracted logical registers and Q(L) | q_R |
|---|---|---:|
| STATUS at 0x00 (0) | without registers[0] `STATUS`=0.906546 | 0.906546 |
| OUT_X_MSB at 0x01 (1) | without registers[1] `OUT_X_MSB`=0.933307 | 0.933307 |
| OUT_X_LSB at 0x02 (2) | without registers[2] `OUT_X_LSB`=0.871004 | 0.871004 |
| OUT_Y_MSB at 0x03 (3) | without registers[3] `OUT_Y_MSB`=0.933307 | 0.933307 |
| OUT_Y_LSB at 0x04 (4) | without registers[4] `OUT_Y_LSB`=0.871004 | 0.871004 |
| OUT_Z_MSB at 0x05 (5) | without registers[5] `OUT_Z_MSB`=0.933307 | 0.933307 |
| OUT_Z_LSB at 0x06 (6) | without registers[6] `OUT_Z_LSB`=0.871004 | 0.871004 |
| F_SETUP at 0x09 (9) | without registers[7] `F_SETUP`=1.000000 | 1.000000 |
| TRIG_CFG at 0x0A (10) | none -> missing physical register | 0.000000 |
| SYSMOD at 0x0B (11) | without registers[8] `SYSMOD`=0.993467 | 0.993467 |
| INT_SOURCE at 0x0C (12) | without registers[9] `INT_SOURCE`=1.000000 | 1.000000 |
| WHO_AM_I at 0x0D (13) | without registers[10] `WHO_AM_I`=0.990200 | 0.990200 |
| XYZ_DATA_CFG at 0x0E (14) | without registers[11] `XYZ_DATA_CFG`=0.933247 | 0.933247 |
| HP_FILTER_CUTOFF at 0x0F (15) | none -> missing physical register | 0.000000 |
| PL_STATUS at 0x10 (16) | none -> missing physical register | 0.000000 |
| PL_CFG at 0x11 (17) | none -> missing physical register | 0.000000 |
| PL_COUNT at 0x12 (18) | none -> missing physical register | 0.000000 |
| PL_BF_ZCOMP at 0x13 (19) | none -> missing physical register | 0.000000 |
| PL_THS_REG at 0x14 (20) | none -> missing physical register | 0.000000 |
| A_FFMT_CFG at 0x15 (21) | none -> missing physical register | 0.000000 |
| A_FFMT_SRC at 0x16 (22) | none -> missing physical register | 0.000000 |
| A_FFMT_THS at 0x17 (23) | none -> missing physical register | 0.000000 |
| A_FFMT_COUNT at 0x18 (24) | none -> missing physical register | 0.000000 |
| TRANSIENT_CFG at 0x1D (29) | none -> missing physical register | 0.000000 |
| TRANSIENT_SRC at 0x1E (30) | none -> missing physical register | 0.000000 |
| TRANSIENT_THS at 0x1F (31) | none -> missing physical register | 0.000000 |
| TRANSIENT_COUNT at 0x20 (32) | none -> missing physical register | 0.000000 |
| PULSE_CFG at 0x21 (33) | none -> missing physical register | 0.000000 |
| PULSE_SRC at 0x22 (34) | none -> missing physical register | 0.000000 |
| PULSE_THSX at 0x23 (35) | none -> missing physical register | 0.000000 |
| PULSE_THSY at 0x24 (36) | none -> missing physical register | 0.000000 |
| PULSE_THSZ at 0x25 (37) | none -> missing physical register | 0.000000 |
| PULSE_TMLT at 0x26 (38) | none -> missing physical register | 0.000000 |
| PULSE_LTCY at 0x27 (39) | none -> missing physical register | 0.000000 |
| PULSE_WIND at 0x28 (40) | none -> missing physical register | 0.000000 |
| ASLP_COUNT at 0x29 (41) | none -> missing physical register | 0.000000 |
| CTRL_REG1 at 0x2A (42) | without registers[12] `CTRL_REG1`=1.000000 | 1.000000 |
| CTRL_REG2 at 0x2B (43) | without registers[13] `CTRL_REG2`=0.981158 | 0.981158 |
| CTRL_REG3 at 0x2C (44) | none -> missing physical register | 0.000000 |
| CTRL_REG4 at 0x2D (45) | none -> missing physical register | 0.000000 |
| CTRL_REG5 at 0x2E (46) | none -> missing physical register | 0.000000 |
| OFF_X at 0x2F (47) | none -> missing physical register | 0.000000 |
| OFF_Y at 0x30 (48) | none -> missing physical register | 0.000000 |
| OFF_Z at 0x31 (49) | none -> missing physical register | 0.000000 |
| M_DR_STATUS at 0x32 (50) | none -> missing physical register | 0.000000 |
| M_OUT_X_MSB at 0x33 (51) | without registers[16] `M_OUT_X_MSB`=0.933307 | 0.933307 |
| M_OUT_X_LSB at 0x34 (52) | none -> missing physical register | 0.000000 |
| M_OUT_Y_MSB at 0x35 (53) | none -> missing physical register | 0.000000 |
| M_OUT_Y_LSB at 0x36 (54) | none -> missing physical register | 0.000000 |
| M_OUT_Z_MSB at 0x37 (55) | none -> missing physical register | 0.000000 |
| M_OUT_Z_LSB at 0x38 (56) | none -> missing physical register | 0.000000 |
| CMP_X_MSB at 0x39 (57) | none -> missing physical register | 0.000000 |
| CMP_X_LSB at 0x3A (58) | none -> missing physical register | 0.000000 |
| CMP_Y_MSB at 0x3B (59) | none -> missing physical register | 0.000000 |
| CMP_Y_LSB at 0x3C (60) | none -> missing physical register | 0.000000 |
| CMP_Z_MSB at 0x3D (61) | none -> missing physical register | 0.000000 |
| CMP_Z_LSB at 0x3E (62) | none -> missing physical register | 0.000000 |
| M_OFF_X_MSB at 0x3F (63) | none -> missing physical register | 0.000000 |
| M_OFF_X_LSB at 0x40 (64) | none -> missing physical register | 0.000000 |
| M_OFF_Y_MSB at 0x41 (65) | none -> missing physical register | 0.000000 |
| M_OFF_Y_LSB at 0x42 (66) | none -> missing physical register | 0.000000 |
| M_OFF_Z_MSB at 0x43 (67) | none -> missing physical register | 0.000000 |
| M_OFF_Z_LSB at 0x44 (68) | none -> missing physical register | 0.000000 |
| MAX_X_MSB at 0x45 (69) | none -> missing physical register | 0.000000 |
| MAX_X_LSB at 0x46 (70) | none -> missing physical register | 0.000000 |
| MAX_Y_MSB at 0x47 (71) | none -> missing physical register | 0.000000 |
| MAX_Y_LSB at 0x48 (72) | none -> missing physical register | 0.000000 |
| MAX_Z_MSB at 0x49 (73) | none -> missing physical register | 0.000000 |
| MAX_Z_LSB at 0x4A (74) | none -> missing physical register | 0.000000 |
| MIN_X_MSB at 0x4B (75) | none -> missing physical register | 0.000000 |
| MIN_X_LSB at 0x4C (76) | none -> missing physical register | 0.000000 |
| MIN_Y_MSB at 0x4D (77) | none -> missing physical register | 0.000000 |
| MIN_Y_LSB at 0x4E (78) | none -> missing physical register | 0.000000 |
| MIN_Z_MSB at 0x4F (79) | none -> missing physical register | 0.000000 |
| MIN_Z_LSB at 0x50 (80) | none -> missing physical register | 0.000000 |
| TEMP at 0x51 (81) | none -> missing physical register | 0.000000 |
| M_THS_CFG at 0x52 (82) | none -> missing physical register | 0.000000 |
| M_THS_SRC at 0x53 (83) | none -> missing physical register | 0.000000 |
| M_THS_X_MSB at 0x54 (84) | none -> missing physical register | 0.000000 |
| M_THS_X_LSB at 0x55 (85) | none -> missing physical register | 0.000000 |
| M_THS_Y_MSB at 0x56 (86) | none -> missing physical register | 0.000000 |
| M_THS_Y_LSB at 0x57 (87) | none -> missing physical register | 0.000000 |
| M_THS_Z_MSB at 0x58 (88) | none -> missing physical register | 0.000000 |
| M_THS_Z_LSB at 0x59 (89) | none -> missing physical register | 0.000000 |
| M_THS_COUNT at 0x5A (90) | none -> missing physical register | 0.000000 |
| M_CTRL_REG1 at 0x5B (91) | without registers[14] `M_CTRL_REG1`=0.992160 | 0.992160 |
| M_CTRL_REG2 at 0x5C (92) | without registers[15] `M_CTRL_REG2`=0.964899 | 0.964899 |
| M_CTRL_REG3 at 0x5D (93) | none -> missing physical register | 0.000000 |
| M_INT_SRC at 0x5E (94) | none -> missing physical register | 0.000000 |
| A_VECM_CFG at 0x5F (95) | none -> missing physical register | 0.000000 |
| A_VECM_THS_MSB at 0x60 (96) | none -> missing physical register | 0.000000 |
| A_VECM_THS_LSB at 0x61 (97) | none -> missing physical register | 0.000000 |
| A_VECM_CNT at 0x62 (98) | none -> missing physical register | 0.000000 |
| A_VECM_INITX_MSB at 0x63 (99) | none -> missing physical register | 0.000000 |
| A_VECM_INITX_LSB at 0x64 (100) | none -> missing physical register | 0.000000 |
| A_VECM_INITY_MSB at 0x65 (101) | none -> missing physical register | 0.000000 |
| A_VECM_INITY_LSB at 0x66 (102) | none -> missing physical register | 0.000000 |
| A_VECM_INITZ_MSB at 0x67 (103) | none -> missing physical register | 0.000000 |
| A_VECM_INITZ_LSB at 0x68 (104) | none -> missing physical register | 0.000000 |
| M_VECM_CFG at 0x69 (105) | none -> missing physical register | 0.000000 |
| M_VECM_THS_MSB at 0x6A (106) | none -> missing physical register | 0.000000 |
| M_VECM_THS_LSB at 0x6B (107) | none -> missing physical register | 0.000000 |
| M_VECM_CNT at 0x6C (108) | none -> missing physical register | 0.000000 |
| M_VECM_INITX_MSB at 0x6D (109) | none -> missing physical register | 0.000000 |
| M_VECM_INITX_LSB at 0x6E (110) | none -> missing physical register | 0.000000 |
| M_VECM_INITY_MSB at 0x6F (111) | none -> missing physical register | 0.000000 |
| M_VECM_INITY_LSB at 0x70 (112) | none -> missing physical register | 0.000000 |
| M_VECM_INITZ_MSB at 0x71 (113) | none -> missing physical register | 0.000000 |
| M_VECM_INITZ_LSB at 0x72 (114) | none -> missing physical register | 0.000000 |
| A_FFMT_THS_X_MSB at 0x73 (115) | none -> missing physical register | 0.000000 |
| A_FFMT_THS_X_LSB at 0x74 (116) | none -> missing physical register | 0.000000 |
| A_FFMT_THS_Y_MSB at 0x75 (117) | none -> missing physical register | 0.000000 |
| A_FFMT_THS_Y_LSB at 0x76 (118) | none -> missing physical register | 0.000000 |
| A_FFMT_THS_Z_MSB at 0x77 (119) | none -> missing physical register | 0.000000 |
| A_FFMT_THS_Z_LSB at 0x78 (120) | none -> missing physical register | 0.000000 |

\(\sum_{R=1}^{115}q_R=\mathbf{16.107916890}\).

\(m=17,\ x=0,\ \frac{m}{m+x}=\frac{17}{17+0}=\mathbf{1.000000}\).

Missing actual datasheet physical registers: **98**.

| Missing datasheet register | Address | Access | Datasheet default | Table 16 comment |
|---|---:|---|---|---|
| TRIG_CFG | 0x0A | RW | "0x00" | "FIFO event trigger configuration register" |
| HP_FILTER_CUTOFF | 0x0F | RW | "0x00" | "Pulse detection high-pass and low-pass filter enable bits. High-pass filter cutoff frequency selection" |
| PL_STATUS | 0x10 | R | "0x00" | "Landscape/portrait orientation status" |
| PL_CFG | 0x11 | RW | "0x80" | "Landscape/portrait configuration" |
| PL_COUNT | 0x12 | RW | "0x00" | "Landscape/portrait debounce counter" |
| PL_BF_ZCOMP | 0x13 | RW | "0x84" | "Back/front trip angle threshold" |
| PL_THS_REG | 0x14 | RW | "0x44" | "Portrait to landscape trip threshold angle and hysteresis settings" |
| A_FFMT_CFG | 0x15 | RW | "0x00" | "Freefall/motion function configuration" |
| A_FFMT_SRC | 0x16 | R | "0x00" | "Freefall/motion event source register" |
| A_FFMT_THS | 0x17 | RW | "0x00" | "Freefall/motion threshold register" |
| A_FFMT_COUNT | 0x18 | RW | "0x00" | "Freefall/motion debounce counter" |
| TRANSIENT_CFG | 0x1D | RW | "0x00" | "FIFO setup" |
| TRANSIENT_SRC | 0x1E | R | "0x00" | "Transient event status register" |
| TRANSIENT_THS | 0x1F | RW | "0x00" | "Transient event threshold" |
| TRANSIENT_COUNT | 0x20 | RW | "0x00" | "Transient debounce counter" |
| PULSE_CFG | 0x21 | RW | "0x00" | "Pulse function configuration" |
| PULSE_SRC | 0x22 | R | "0x00" | "Pulse function source register" |
| PULSE_THSX | 0x23 | RW | "0x00" | "X-axis pulse threshold" |
| PULSE_THSY | 0x24 | RW | "0x00" | "Y-axis pulse threshold" |
| PULSE_THSZ | 0x25 | RW | "0x00" | "Z-axis pulse threshold" |
| PULSE_TMLT | 0x26 | RW | "0x00" | "Time limit for pulse detection" |
| PULSE_LTCY | 0x27 | RW | "0x00" | "Latency time for second pulse detection" |
| PULSE_WIND | 0x28 | RW | "0x00" | "Window time for second pulse detection" |
| ASLP_COUNT | 0x29 | RW | "0x00" | "In activity counter setting for auto-sleep" |
| CTRL_REG3 | 0x2C | RW | "0x00" | "Sleep mode interrupt wake enable, interrupt polarity, push-pull/open-drain configuration" |
| CTRL_REG4 | 0x2D | RW | "0x00" | "Interrupt enable register" |
| CTRL_REG5 | 0x2E | RW | "0x00" | "Interrupt pin (INT1/INT2) map" |
| OFF_X | 0x2F | RW | "0x00" | "X-axis accelerometer offset adjust" |
| OFF_Y | 0x30 | RW | "0x00" | "Y-axis accelerometer offset adjust" |
| OFF_Z | 0x31 | RW | "0x00" | "Z-axis accelerometer offset adjust" |
| M_DR_STATUS | 0x32 | R | "0x00" | "Magnetic data ready" |
| M_OUT_X_LSB | 0x34 | R | "Data" | "LSB of 16-bit magnetic data for X-axis" |
| M_OUT_Y_MSB | 0x35 | R | "Data" | "MSB of 16-bit magnetic data for Y-axis" |
| M_OUT_Y_LSB | 0x36 | R | "Data" | "LSB of 16-bit magnetic data for Y-axis" |
| M_OUT_Z_MSB | 0x37 | R | "Data" | "MSB of 16-bit magnetic data for Z-axis" |
| M_OUT_Z_LSB | 0x38 | R | "Data" | "LSB of 16-bit magnetic data for Z-axis" |
| CMP_X_MSB | 0x39 | R | "Data" | "Bits [13:8] of integrated X-axis acceleration data" |
| CMP_X_LSB | 0x3A | R | "Data" | "Bits [7:0] of integrated X-axis acceleration data" |
| CMP_Y_MSB | 0x3B | R | "Data" | "Bits [13:8] of integrated Y-axis acceleration data" |
| CMP_Y_LSB | 0x3C | R | "Data" | "Bits [7:0] of integrated Y-axis acceleration data" |
| CMP_Z_MSB | 0x3D | R | "Data" | "Bits [13:8] of integrated Z-axis acceleration data" |
| CMP_Z_LSB | 0x3E | R | "Data" | "Bits [7:0] of integrated Z-axis acceleration data" |
| M_OFF_X_MSB | 0x3F | RW | "0x00" | "MSB of magnetometer of X-axis offset" |
| M_OFF_X_LSB | 0x40 | RW | "0x00" | "LSB of magnetometer of X-axis offset" |
| M_OFF_Y_MSB | 0x41 | RW | "0x00" | "MSB of magnetometer of Y-axis offset" |
| M_OFF_Y_LSB | 0x42 | RW | "0x00" | "LSB of magnetometer of Y-axis offset" |
| M_OFF_Z_MSB | 0x43 | RW | "0x00" | "MSB of magnetometer of Z-axis offset" |
| M_OFF_Z_LSB | 0x44 | RW | "0x00" | "LSB of magnetometer of Z-axis offset" |
| MAX_X_MSB | 0x45 | R | "Data" | "Magnetometer X-axis maximum value MSB" |
| MAX_X_LSB | 0x46 | R | "Data" | "Magnetometer X-axis maximum value LSB" |
| MAX_Y_MSB | 0x47 | R | "Data" | "Magnetometer Y-axis maximum value MSB" |
| MAX_Y_LSB | 0x48 | R | "Data" | "Magnetometer Y-axis maximum value LSB" |
| MAX_Z_MSB | 0x49 | R | "Data" | "Magnetometer Z-axis maximum value MSB" |
| MAX_Z_LSB | 0x4A | R | "Data" | "Magnetometer Z-axis maximum value LSB" |
| MIN_X_MSB | 0x4B | R | "Data" | "Magnetometer X-axis minimum value MSB" |
| MIN_X_LSB | 0x4C | R | "Data" | "Magnetometer X-axis minimum value LSB" |
| MIN_Y_MSB | 0x4D | R | "Data" | "Magnetometer Y-axis minimum value MSB" |
| MIN_Y_LSB | 0x4E | R | "Data" | "Magnetometer Y-axis minimum value LSB" |
| MIN_Z_MSB | 0x4F | R | "Data" | "Magnetometer Z-axis minimum value MSB" |
| MIN_Z_LSB | 0x50 | R | "Data" | "Magnetometer Z-axis minimum value LSB" |
| TEMP | 0x51 | R | "Data" | "Device temperature, valid range of -128 to 127 °C when M_CTRL1[m_hms] > 0b00" |
| M_THS_CFG | 0x52 | RW | "0x00" | "Magnetic threshold detection function configuration" |
| M_THS_SRC | 0x53 | R | "Data" | "Magnetic threshold event source register" |
| M_THS_X_MSB | 0x54 | RW | "0x00" | "X-axis magnetic threshold MSB" |
| M_THS_X_LSB | 0x55 | RW | "0x00" | "X-axis magnetic threshold LSB" |
| M_THS_Y_MSB | 0x56 | RW | "0x00" | "Y-axis magnetic threshold MSB" |
| M_THS_Y_LSB | 0x57 | RW | "0x00" | "Y-axis magnetic threshold LSB" |
| M_THS_Z_MSB | 0x58 | RW | "0x00" | "Z-axis magnetic threshold MSB" |
| M_THS_Z_LSB | 0x59 | RW | "0x00" | "Z-axis magnetic threshold LSB" |
| M_THS_COUNT | 0x5A | RW | "0x00" | "Magnetic threshold debounce counter" |
| M_CTRL_REG3 | 0x5D | RW | "0x00" | "Control for magnetic sensor functions" |
| M_INT_SRC | 0x5E | R | "0x00" | "Magnetic interrupt source" |
| A_VECM_CFG | 0x5F | RW | "0x00" | "Acceleration vector-magnitude configuration register" |
| A_VECM_THS_MSB | 0x60 | RW | "0x00" | "Acceleration vector-magnitude threshold MSB" |
| A_VECM_THS_LSB | 0x61 | RW | "0x00" | "Acceleration vector-magnitude threshold LSB" |
| A_VECM_CNT | 0x62 | RW | "0x00" | "Acceleration vector-magnitude debounce count" |
| A_VECM_INITX_MSB | 0x63 | RW | "0x00" | "Acceleration vector-magnitude X-axis reference value MSB" |
| A_VECM_INITX_LSB | 0x64 | RW | "0x00" | "Acceleration vector-magnitude X-axis reference value LSB" |
| A_VECM_INITY_MSB | 0x65 | RW | "0x00" | "Acceleration vector-magnitude Y-axis reference value MSB" |
| A_VECM_INITY_LSB | 0x66 | RW | "0x00" | "Acceleration vector-magnitude Y-axis reference value LSB" |
| A_VECM_INITZ_MSB | 0x67 | RW | "0x00" | "Acceleration vector-magnitude Z-axis reference value MSB" |
| A_VECM_INITZ_LSB | 0x68 | RW | "0x00" | "Acceleration vector-magnitude Z-axis reference value LSB" |
| M_VECM_CFG | 0x69 | RW | "0x00" | "Magnetic vector-magnitude configuration register" |
| M_VECM_THS_MSB | 0x6A | RW | "0x00" | "Magnetic vector-magnitude threshold MSB" |
| M_VECM_THS_LSB | 0x6B | RW | "0x00" | "Magnetic vector-magnitude threshold LSB" |
| M_VECM_CNT | 0x6C | RW | "0x00" | "Magnetic vector-magnitude debounce count" |
| M_VECM_INITX_MSB | 0x6D | RW | "0x00" | "Magnetic vector-magnitude reference value X-axis MSB" |
| M_VECM_INITX_LSB | 0x6E | RW | "0x00" | "Magnetic vector-magnitude reference value X-axis LSB" |
| M_VECM_INITY_MSB | 0x6F | RW | "0x00" | "Magnetic vector-magnitude reference value Y-axis MSB" |
| M_VECM_INITY_LSB | 0x70 | RW | "0x00" | "Magnetic vector-magnitude reference value Y-axis LSB" |
| M_VECM_INITZ_MSB | 0x71 | RW | "0x00" | "Magnetic vector-magnitude reference value Z-axis MSB" |
| M_VECM_INITZ_LSB | 0x72 | RW | "0x00" | "Magnetic vector-magnitude reference value Z-axis LSB" |
| A_FFMT_THS_X_MSB | 0x73 | RW | "0x00" | "X-axis FMT threshold MSB" |
| A_FFMT_THS_X_LSB | 0x74 | RW | "0x00" | "X-axis FFMT threshold LSB" |
| A_FFMT_THS_Y_MSB | 0x75 | RW | "0x00" | "Y-axis FFMT threshold MSB" |
| A_FFMT_THS_Y_LSB | 0x76 | RW | "0x00" | "Y-axis FFMT threshold LSB" |
| A_FFMT_THS_Z_MSB | 0x77 | RW | "0x00" | "Z-axis FFMT threshold MSB" |
| A_FFMT_THS_Z_LSB | 0x78 | RW | "0x00" | "Z-axis FFMT threshold LSB" |

Extra extracted physical addresses not corresponding to actual named datasheet registers: **0**.

\(S_{final}=\left(\frac{10}{115}\times 16.107916890\right)\times\frac{17}{17+0}=\boxed{\mathbf{1.400688425/10}}\)

## 4. Detailed error and omission inventory

The following inventory lists the exact extracted JSON locations, datasheet content, extracted content and reason for every scored deviation. Missing physical registers are listed in the preceding table and summarized again below.

### 4.1 Missing physical registers

1. Datasheet `registers[8]` `TRIG_CFG` at 0x0A is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
2. Datasheet `registers[13]` `HP_FILTER_CUTOFF` at 0x0F is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
3. Datasheet `registers[14]` `PL_STATUS` at 0x10 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
4. Datasheet `registers[15]` `PL_CFG` at 0x11 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
5. Datasheet `registers[16]` `PL_COUNT` at 0x12 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
6. Datasheet `registers[17]` `PL_BF_ZCOMP` at 0x13 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
7. Datasheet `registers[18]` `PL_THS_REG` at 0x14 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
8. Datasheet `registers[19]` `A_FFMT_CFG` at 0x15 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
9. Datasheet `registers[20]` `A_FFMT_SRC` at 0x16 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
10. Datasheet `registers[21]` `A_FFMT_THS` at 0x17 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
11. Datasheet `registers[22]` `A_FFMT_COUNT` at 0x18 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
12. Datasheet `registers[23]` `TRANSIENT_CFG` at 0x1D is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
13. Datasheet `registers[24]` `TRANSIENT_SRC` at 0x1E is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
14. Datasheet `registers[25]` `TRANSIENT_THS` at 0x1F is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
15. Datasheet `registers[26]` `TRANSIENT_COUNT` at 0x20 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
16. Datasheet `registers[27]` `PULSE_CFG` at 0x21 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
17. Datasheet `registers[28]` `PULSE_SRC` at 0x22 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
18. Datasheet `registers[29]` `PULSE_THSX` at 0x23 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
19. Datasheet `registers[30]` `PULSE_THSY` at 0x24 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
20. Datasheet `registers[31]` `PULSE_THSZ` at 0x25 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
21. Datasheet `registers[32]` `PULSE_TMLT` at 0x26 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
22. Datasheet `registers[33]` `PULSE_LTCY` at 0x27 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
23. Datasheet `registers[34]` `PULSE_WIND` at 0x28 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
24. Datasheet `registers[35]` `ASLP_COUNT` at 0x29 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
25. Datasheet `registers[38]` `CTRL_REG3` at 0x2C is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
26. Datasheet `registers[39]` `CTRL_REG4` at 0x2D is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
27. Datasheet `registers[40]` `CTRL_REG5` at 0x2E is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
28. Datasheet `registers[41]` `OFF_X` at 0x2F is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
29. Datasheet `registers[42]` `OFF_Y` at 0x30 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
30. Datasheet `registers[43]` `OFF_Z` at 0x31 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
31. Datasheet `registers[44]` `M_DR_STATUS` at 0x32 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
32. Datasheet `registers[46]` `M_OUT_X_LSB` at 0x34 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
33. Datasheet `registers[47]` `M_OUT_Y_MSB` at 0x35 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
34. Datasheet `registers[48]` `M_OUT_Y_LSB` at 0x36 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
35. Datasheet `registers[49]` `M_OUT_Z_MSB` at 0x37 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
36. Datasheet `registers[50]` `M_OUT_Z_LSB` at 0x38 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
37. Datasheet `registers[51]` `CMP_X_MSB` at 0x39 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
38. Datasheet `registers[52]` `CMP_X_LSB` at 0x3A is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
39. Datasheet `registers[53]` `CMP_Y_MSB` at 0x3B is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
40. Datasheet `registers[54]` `CMP_Y_LSB` at 0x3C is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
41. Datasheet `registers[55]` `CMP_Z_MSB` at 0x3D is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
42. Datasheet `registers[56]` `CMP_Z_LSB` at 0x3E is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
43. Datasheet `registers[57]` `M_OFF_X_MSB` at 0x3F is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
44. Datasheet `registers[58]` `M_OFF_X_LSB` at 0x40 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
45. Datasheet `registers[59]` `M_OFF_Y_MSB` at 0x41 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
46. Datasheet `registers[60]` `M_OFF_Y_LSB` at 0x42 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
47. Datasheet `registers[61]` `M_OFF_Z_MSB` at 0x43 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
48. Datasheet `registers[62]` `M_OFF_Z_LSB` at 0x44 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
49. Datasheet `registers[63]` `MAX_X_MSB` at 0x45 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
50. Datasheet `registers[64]` `MAX_X_LSB` at 0x46 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
51. Datasheet `registers[65]` `MAX_Y_MSB` at 0x47 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
52. Datasheet `registers[66]` `MAX_Y_LSB` at 0x48 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
53. Datasheet `registers[67]` `MAX_Z_MSB` at 0x49 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
54. Datasheet `registers[68]` `MAX_Z_LSB` at 0x4A is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
55. Datasheet `registers[69]` `MIN_X_MSB` at 0x4B is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
56. Datasheet `registers[70]` `MIN_X_LSB` at 0x4C is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
57. Datasheet `registers[71]` `MIN_Y_MSB` at 0x4D is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
58. Datasheet `registers[72]` `MIN_Y_LSB` at 0x4E is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
59. Datasheet `registers[73]` `MIN_Z_MSB` at 0x4F is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
60. Datasheet `registers[74]` `MIN_Z_LSB` at 0x50 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
61. Datasheet `registers[75]` `TEMP` at 0x51 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
62. Datasheet `registers[76]` `M_THS_CFG` at 0x52 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
63. Datasheet `registers[77]` `M_THS_SRC` at 0x53 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
64. Datasheet `registers[78]` `M_THS_X_MSB` at 0x54 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
65. Datasheet `registers[79]` `M_THS_X_LSB` at 0x55 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
66. Datasheet `registers[80]` `M_THS_Y_MSB` at 0x56 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
67. Datasheet `registers[81]` `M_THS_Y_LSB` at 0x57 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
68. Datasheet `registers[82]` `M_THS_Z_MSB` at 0x58 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
69. Datasheet `registers[83]` `M_THS_Z_LSB` at 0x59 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
70. Datasheet `registers[84]` `M_THS_COUNT` at 0x5A is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
71. Datasheet `registers[87]` `M_CTRL_REG3` at 0x5D is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
72. Datasheet `registers[88]` `M_INT_SRC` at 0x5E is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
73. Datasheet `registers[89]` `A_VECM_CFG` at 0x5F is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
74. Datasheet `registers[90]` `A_VECM_THS_MSB` at 0x60 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
75. Datasheet `registers[91]` `A_VECM_THS_LSB` at 0x61 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
76. Datasheet `registers[92]` `A_VECM_CNT` at 0x62 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
77. Datasheet `registers[93]` `A_VECM_INITX_MSB` at 0x63 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
78. Datasheet `registers[94]` `A_VECM_INITX_LSB` at 0x64 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
79. Datasheet `registers[95]` `A_VECM_INITY_MSB` at 0x65 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
80. Datasheet `registers[96]` `A_VECM_INITY_LSB` at 0x66 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
81. Datasheet `registers[97]` `A_VECM_INITZ_MSB` at 0x67 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
82. Datasheet `registers[98]` `A_VECM_INITZ_LSB` at 0x68 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
83. Datasheet `registers[99]` `M_VECM_CFG` at 0x69 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
84. Datasheet `registers[100]` `M_VECM_THS_MSB` at 0x6A is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
85. Datasheet `registers[101]` `M_VECM_THS_LSB` at 0x6B is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
86. Datasheet `registers[102]` `M_VECM_CNT` at 0x6C is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
87. Datasheet `registers[103]` `M_VECM_INITX_MSB` at 0x6D is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
88. Datasheet `registers[104]` `M_VECM_INITX_LSB` at 0x6E is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
89. Datasheet `registers[105]` `M_VECM_INITY_MSB` at 0x6F is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
90. Datasheet `registers[106]` `M_VECM_INITY_LSB` at 0x70 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
91. Datasheet `registers[107]` `M_VECM_INITZ_MSB` at 0x71 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
92. Datasheet `registers[108]` `M_VECM_INITZ_LSB` at 0x72 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
93. Datasheet `registers[109]` `A_FFMT_THS_X_MSB` at 0x73 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
94. Datasheet `registers[110]` `A_FFMT_THS_X_LSB` at 0x74 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
95. Datasheet `registers[111]` `A_FFMT_THS_Y_MSB` at 0x75 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
96. Datasheet `registers[112]` `A_FFMT_THS_Y_LSB` at 0x76 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
97. Datasheet `registers[113]` `A_FFMT_THS_Z_MSB` at 0x77 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).
98. Datasheet `registers[114]` `A_FFMT_THS_Z_LSB` at 0x78 is missing from `without/FXOS8700CQ.json`; q_R=0. Source: Table 16 (PDF pp.29-32).

### 4.2 Field-level deviations

| Exact location | Field | Datasheet content | Extracted content | C | Judgment |
|---|---|---|---|---:|---|
| `truth registers[0].field_parts[0].bit_field[0]` | `name_or_parameter` | "DR_STATUS or F_STATUS" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[0].field_parts[0].bit_field[0]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[0].field_parts[0].bit_field[0]` | `bit_start` | 0 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[0].field_parts[0].bit_field[0]` | `bit_end` | 7 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[0].field_parts[0].bit_field[0]` | `bit_width` | 8 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[0].field_parts[0].bit_field[0]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[0].field_parts[0].bit_field[0]` | `is_reserved` | False | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[0].field_parts[0].bit_field[0]` | `type_write_read` | "R" | null | 0.0 | bit field is missing from the extracted map |
| `without registers[0].field_parts[0].bit_field[0]` | `name_or_parameter` | null | "zyxow" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[0]` | `field_description` | null | "X, Y, Z axis data overwrite (set when new data overwrites previous set before read)" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[0]` | `bit_start` | null | 7 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[0]` | `bit_end` | null | 7 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[0]` | `bit_width` | null | 1 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[0]` | `values` | null | [] | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[0]` | `is_reserved` | null | False | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[0]` | `type_write_read` | null | "R" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[1]` | `name_or_parameter` | null | "zow" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[1]` | `field_description` | null | "Z-axis data overwrite (set when Z data overwritten before read)" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[1]` | `bit_start` | null | 6 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[1]` | `bit_end` | null | 6 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[1]` | `bit_width` | null | 1 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[1]` | `values` | null | [] | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[1]` | `is_reserved` | null | False | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[1]` | `type_write_read` | null | "R" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[2]` | `name_or_parameter` | null | "yow" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[2]` | `field_description` | null | "Y-axis data overwrite (set when Y data overwritten before read)" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[2]` | `bit_start` | null | 5 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[2]` | `bit_end` | null | 5 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[2]` | `bit_width` | null | 1 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[2]` | `values` | null | [] | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[2]` | `is_reserved` | null | False | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[2]` | `type_write_read` | null | "R" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[3]` | `name_or_parameter` | null | "xow" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[3]` | `field_description` | null | "X-axis data overwrite (set when X data overwritten before read)" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[3]` | `bit_start` | null | 4 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[3]` | `bit_end` | null | 4 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[3]` | `bit_width` | null | 1 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[3]` | `values` | null | [] | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[3]` | `is_reserved` | null | False | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[3]` | `type_write_read` | null | "R" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[4]` | `name_or_parameter` | null | "zyxdr" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[4]` | `field_description` | null | "X, Y, and Z new data ready (set when any enabled channel has new data)" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[4]` | `bit_start` | null | 3 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[4]` | `bit_end` | null | 3 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[4]` | `bit_width` | null | 1 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[4]` | `values` | null | [] | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[4]` | `is_reserved` | null | False | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[4]` | `type_write_read` | null | "R" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[5]` | `name_or_parameter` | null | "zdr" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[5]` | `field_description` | null | "Z-axis new data available" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[5]` | `bit_start` | null | 2 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[5]` | `bit_end` | null | 2 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[5]` | `bit_width` | null | 1 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[5]` | `values` | null | [] | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[5]` | `is_reserved` | null | False | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[5]` | `type_write_read` | null | "R" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[6]` | `name_or_parameter` | null | "ydr" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[6]` | `field_description` | null | "Y-axis new data available" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[6]` | `bit_start` | null | 1 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[6]` | `bit_end` | null | 1 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[6]` | `bit_width` | null | 1 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[6]` | `values` | null | [] | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[6]` | `is_reserved` | null | False | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[6]` | `type_write_read` | null | "R" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[7]` | `name_or_parameter` | null | "xdr" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[7]` | `field_description` | null | "X-axis new data available" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[7]` | `bit_start` | null | 0 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[7]` | `bit_end` | null | 0 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[7]` | `bit_width` | null | 1 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[7]` | `values` | null | [] | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[7]` | `is_reserved` | null | False | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field[7]` | `type_write_read` | null | "R" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[0].field_parts[0].bit_field` | `bit_field` | [{"name_or_parameter":"DR_STATUS or F_STATUS","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 18 (PDF p.37); field description source: Table 18 (PDF p.37); enumerated-value source: Table 18 (PDF p.37)."}] | [{"name_or_parameter":"zyxow","field_description":"X, Y, Z axis data overwrite (set when new data overwrites previous set before read)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"zow","field_description":"Z-axis data overwrite (set when Z data overwritten before read)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"yow","field_description":"Y-axis data overwrite (set when Y data overwritten before read)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"xow","field_description":"X-axis data overwrite (set when X data overwritten before read)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"zyxdr","field_description":"X, Y, and Z new data ready (set when any enabled channel has new data)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"zdr","field_description":"Z-axis new data available","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"ydr","field_description":"Y-axis new data available","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"xdr","field_description":"X-axis new data available","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"}] | 0.0 | datasheet bit-field target collection is only partially represented |
| `without registers[0]` | `field_parts` | "datasheet field-part collection" | "extracted field-part collection" | 0.7 | field-part collection is reduced by the bottom-up field-part score |
| `without registers[1]` | `default_value` | "Data" | "" | 0.0 | datasheet default value is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[1]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[1]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[1]` | `bit_start` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[1]` | `bit_end` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[1]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[1]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[2].field_parts[0].bit_field[1]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[1]` | `type_write_read` | "R" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[2]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[2]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[2]` | `bit_start` | 0 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[2]` | `bit_end` | 0 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[2]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[2]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[2].field_parts[0].bit_field[2]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[2].field_parts[0].bit_field[2]` | `type_write_read` | "R" | null | 0.0 | bit field is missing from the extracted map |
| `without registers[2].field_parts[0].bit_field[1]` | `name_or_parameter` | null | "Reserved" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[2].field_parts[0].bit_field[1]` | `field_description` | null | "" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[2].field_parts[0].bit_field[1]` | `bit_start` | null | 0 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[2].field_parts[0].bit_field[1]` | `bit_end` | null | 1 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[2].field_parts[0].bit_field[1]` | `bit_width` | null | 2 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[2].field_parts[0].bit_field[1]` | `values` | null | [] | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[2].field_parts[0].bit_field[1]` | `is_reserved` | null | True | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[2].field_parts[0].bit_field[1]` | `type_write_read` | null | "" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[2].field_parts[0].bit_field` | `bit_field` | [{"name_or_parameter":"xd[5:0]","field_description":"","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 52 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"R","source":"allocation Table 52 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"R","source":"allocation Table 52 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."}] | [{"name_or_parameter":"xd[5:0]","field_description":"Bits [5:0] of 14-bit X-axis sample, stored in bits [7:2] of this register","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""}] | 0.3 | datasheet bit-field target collection is only partially represented |
| `without registers[2]` | `default_value` | "Data" | "" | 0.0 | datasheet default value is missing from the extracted map |
| `without registers[2]` | `field_parts` | "datasheet field-part collection" | "extracted field-part collection" | 0.8 | field-part collection is reduced by the bottom-up field-part score |
| `without registers[3]` | `default_value` | "Data" | "" | 0.0 | datasheet default value is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[1]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[1]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[1]` | `bit_start` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[1]` | `bit_end` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[1]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[1]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[4].field_parts[0].bit_field[1]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[1]` | `type_write_read` | "R" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[2]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[2]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[2]` | `bit_start` | 0 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[2]` | `bit_end` | 0 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[2]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[2]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[4].field_parts[0].bit_field[2]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[4].field_parts[0].bit_field[2]` | `type_write_read` | "R" | null | 0.0 | bit field is missing from the extracted map |
| `without registers[4].field_parts[0].bit_field[1]` | `name_or_parameter` | null | "Reserved" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[4].field_parts[0].bit_field[1]` | `field_description` | null | "" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[4].field_parts[0].bit_field[1]` | `bit_start` | null | 0 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[4].field_parts[0].bit_field[1]` | `bit_end` | null | 1 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[4].field_parts[0].bit_field[1]` | `bit_width` | null | 2 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[4].field_parts[0].bit_field[1]` | `values` | null | [] | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[4].field_parts[0].bit_field[1]` | `is_reserved` | null | True | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[4].field_parts[0].bit_field[1]` | `type_write_read` | null | "" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[4].field_parts[0].bit_field` | `bit_field` | [{"name_or_parameter":"yd[5:0]","field_description":"","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 54 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"R","source":"allocation Table 54 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"R","source":"allocation Table 54 (PDF p.53); field description source: not separately provided; enumerated-value source: not separately provided."}] | [{"name_or_parameter":"yd[5:0]","field_description":"Bits [5:0] of 14-bit Y-axis sample stored in bits [7:2]","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""}] | 0.3 | datasheet bit-field target collection is only partially represented |
| `without registers[4]` | `default_value` | "Data" | "" | 0.0 | datasheet default value is missing from the extracted map |
| `without registers[4]` | `field_parts` | "datasheet field-part collection" | "extracted field-part collection" | 0.8 | field-part collection is reduced by the bottom-up field-part score |
| `without registers[5]` | `default_value` | "Data" | "" | 0.0 | datasheet default value is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[1]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[1]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[1]` | `bit_start` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[1]` | `bit_end` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[1]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[1]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[6].field_parts[0].bit_field[1]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[1]` | `type_write_read` | "R" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[2]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[2]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[2]` | `bit_start` | 0 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[2]` | `bit_end` | 0 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[2]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[2]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[6].field_parts[0].bit_field[2]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[6].field_parts[0].bit_field[2]` | `type_write_read` | "R" | null | 0.0 | bit field is missing from the extracted map |
| `without registers[6].field_parts[0].bit_field[1]` | `name_or_parameter` | null | "Reserved" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[6].field_parts[0].bit_field[1]` | `field_description` | null | "" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[6].field_parts[0].bit_field[1]` | `bit_start` | null | 0 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[6].field_parts[0].bit_field[1]` | `bit_end` | null | 1 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[6].field_parts[0].bit_field[1]` | `bit_width` | null | 2 | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[6].field_parts[0].bit_field[1]` | `values` | null | [] | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[6].field_parts[0].bit_field[1]` | `is_reserved` | null | True | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[6].field_parts[0].bit_field[1]` | `type_write_read` | null | "" | 0.0 | extracted bit field has no exact datasheet bit range |
| `without registers[6].field_parts[0].bit_field` | `bit_field` | [{"name_or_parameter":"zd[5:0]","field_description":"","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 56 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":1,"bit_end":1,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"R","source":"allocation Table 56 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":0,"bit_end":0,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"R","source":"allocation Table 56 (PDF p.54); field description source: not separately provided; enumerated-value source: not separately provided."}] | [{"name_or_parameter":"zd[5:0]","field_description":"Bits [5:0] of 14-bit Z-axis sample stored in bits [7:2]","bit_start":2,"bit_end":7,"bit_width":6,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"Reserved","field_description":"","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":true,"type_write_read":""}] | 0.3 | datasheet bit-field target collection is only partially represented |
| `without registers[6]` | `default_value` | "Data" | "" | 0.0 | datasheet default value is missing from the extracted map |
| `without registers[6]` | `field_parts` | "datasheet field-part collection" | "extracted field-part collection" | 0.8 | field-part collection is reduced by the bottom-up field-part score |
| `without registers[8].field_parts[0].bit_field[0]` | `values` | [{"value":"0","value_description":"No FIFO gate error detected"},{"value":"1","value_description":"FIFO gate error was detected. Emptying the FIFO buffer clears the fgerr bit in the SYSMOD register. See Section 14.1.10 for more information on configuring the FIFO gate function"}] | [] | 0.0 | datasheet value enumeration is missing |
| `without registers[8].field_parts[0].bit_field` | `bit_field` | [{"name_or_parameter":"fgerr","field_description":"FIFO gate error. Default value: 0. 0 – No FIFO gate error detected. 1 – FIFO gate error was detected. Emptying the FIFO buffer clears the fgerr bit in the SYSMOD register. See Section 14.1.10 for more information on configuring the FIFO gate function.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"No FIFO gate error detected"},{"value":"1","value_description":"FIFO gate error was detected. Emptying the FIFO buffer clears the fgerr bit in the SYSMOD register. See Section 14.1.10 for more information on configuring the FIFO gate function"}],"is_reserved":false,"type_write_read":"R","source":"allocation Table 27 (PDF p.40); field description source: Table 28 (PDF p.40); enumerated-value source: Table 28 (PDF p.40)."},{"name_or_parameter":"fgt[4:0]","field_description":"Number of ODR time units since fgerr was asserted. Reset when fgerr is cleared","bit_start":2,"bit_end":6,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R","source":"allocation Table 27 (PDF p.40); field description source: Table 28 (PDF p.40); enumerated-value source: not separately provided."},{"name_or_parameter":"sysmod[1:0]","field_description":"System mode. Default value: 0b00. 0b00 – Standby mode 0b01 – Wake mode 0b10 – Sleep mode","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"Standby mode"},{"value":"0b01","value_description":"Wake mode"},{"value":"0b10","value_description":"Sleep mode"}],"is_reserved":false,"type_write_read":"R","source":"allocation Table 27 (PDF p.40); field description source: Table 28 (PDF p.40); enumerated-value source: Table 28 (PDF p.40)."}] | [{"name_or_parameter":"fgerr","field_description":"FIFO gate error (1 = FIFO gate error detected)","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"fgt[4:0]","field_description":"Number of ODR time units since fgerr was asserted (reset when fgerr cleared)","bit_start":2,"bit_end":6,"bit_width":5,"values":[],"is_reserved":false,"type_write_read":"R"},{"name_or_parameter":"sysmod[1:0]","field_description":"System mode: 00 standby, 01 wake, 10 sleep","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"Standby"},{"value":"0b01","value_description":"Wake"},{"value":"0b10","value_description":"Sleep"}],"is_reserved":false,"type_write_read":"R"}] | 0.9 | datasheet bit-field target collection is only partially represented |
| `without registers[8]` | `field_parts` | "datasheet field-part collection" | "extracted field-part collection" | 1.0 | field-part collection is reduced by the bottom-up field-part score |
| `without registers[10].field_parts[0].bit_field[0]` | `values` | [{"value":"0xC4","value_description":"Preproduction devices"},{"value":"0xC7","value_description":"Production devices"}] | [{"value":"0xC7","value_description":"Production device ID"}] | 0.5 | partial value enumeration; missing codes=[('raw', '"0xC4"')] |
| `without registers[10].field_parts[0].bit_field` | `bit_field` | [{"name_or_parameter":"who_am_i[7:0]","field_description":"","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"0xC4","value_description":"Preproduction devices"},{"value":"0xC7","value_description":"Production devices"}],"is_reserved":false,"type_write_read":"R","source":"allocation Table 31 (PDF p.42); field description source: not separately provided; enumerated-value source: Section 14.1.7 (PDF p.42)."}] | [{"name_or_parameter":"who_am_i[7:0]","field_description":"Device identifier","bit_start":0,"bit_end":7,"bit_width":8,"values":[{"value":"0xC7","value_description":"Production device ID"}],"is_reserved":false,"type_write_read":"R"}] | 0.9 | datasheet bit-field target collection is only partially represented |
| `without registers[10]` | `field_parts` | "datasheet field-part collection" | "extracted field-part collection" | 1.0 | field-part collection is reduced by the bottom-up field-part score |
| `truth registers[12].field_parts[0].bit_field[0]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[0]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[0]` | `bit_start` | 7 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[0]` | `bit_end` | 7 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[0]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[0]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[12].field_parts[0].bit_field[0]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[0]` | `type_write_read` | "RW" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[1]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[1]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[1]` | `bit_start` | 6 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[1]` | `bit_end` | 6 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[1]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[1]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[12].field_parts[0].bit_field[1]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[1]` | `type_write_read` | "RW" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[2]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[2]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[2]` | `bit_start` | 5 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[2]` | `bit_end` | 5 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[2]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[2]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[12].field_parts[0].bit_field[2]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[2]` | `type_write_read` | "RW" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[4]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[4]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[4]` | `bit_start` | 3 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[4]` | `bit_end` | 3 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[4]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[4]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[12].field_parts[0].bit_field[4]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[4]` | `type_write_read` | "RW" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[5]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[5]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[5]` | `bit_start` | 2 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[5]` | `bit_end` | 2 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[5]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[5]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[12].field_parts[0].bit_field[5]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[12].field_parts[0].bit_field[5]` | `type_write_read` | "RW" | null | 0.0 | bit field is missing from the extracted map |
| `without registers[11].field_parts[0].bit_field` | `bit_field` | [{"name_or_parameter":"-","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"hpf_out","field_description":"Enable high-pass filter on acceleration output data 1 – Output data is high-pass filtered 0 – High-pass filter is disabled.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"1","value_description":"Output data is high-pass filtered"},{"value":"0","value_description":"High-pass filter is disabled"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: Table 60 (PDF p.55); enumerated-value source: Table 60 (PDF p.55)."},{"name_or_parameter":"-","field_description":"","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"fs[1:0]","field_description":"Accelerometer full-scale range selection. See Table 61.","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 59 (PDF p.55); field description source: Table 60 (PDF p.55); enumerated-value source: not separately provided."}] | [{"name_or_parameter":"hpf_out","field_description":"High-pass filter on acceleration output (1=enabled)","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"HPF disabled"},{"value":"1","value_description":"HPF enabled"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"fs[1:0]","field_description":"Full-scale range selection","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"±2 g (0.244 mg/LSB)"},{"value":"0b01","value_description":"±4 g (0.488 mg/LSB)"},{"value":"0b10","value_description":"±8 g (0.976 mg/LSB)"}],"is_reserved":false,"type_write_read":"RW"}] | 0.3 | datasheet bit-field target collection is only partially represented |
| `without registers[11]` | `field_parts` | "datasheet field-part collection" | "extracted field-part collection" | 0.8 | field-part collection is reduced by the bottom-up field-part score |
| `without registers[13].field_parts[0].bit_field[1]` | `values` | [{"value":"0","value_description":"Device reset disabled"},{"value":"1","value_description":"Device reset enabled"}] | [] | 0.0 | datasheet value enumeration is missing |
| `truth registers[37].field_parts[0].bit_field[2]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[37].field_parts[0].bit_field[2]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[37].field_parts[0].bit_field[2]` | `bit_start` | 5 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[37].field_parts[0].bit_field[2]` | `bit_end` | 5 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[37].field_parts[0].bit_field[2]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[37].field_parts[0].bit_field[2]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[37].field_parts[0].bit_field[2]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[37].field_parts[0].bit_field[2]` | `type_write_read` | "RW" | null | 0.0 | bit field is missing from the extracted map |
| `without registers[13].field_parts[0].bit_field` | `bit_field` | [{"name_or_parameter":"st","field_description":"The st bit activates the accelerometer self-test function. When st is set to 1, a change will occur in the device output levels for each axis, allowing the host application to check the functionality of the transducer and measurement signal chain. Self-test enable: 0 – Self-test disabled 1 – Self-test enabled","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Self-test disabled"},{"value":"1","value_description":"Self-test enabled"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 36 (PDF p.44); field description source: Table 37 (PDF p.45); enumerated-value source: Table 37 (PDF p.45)."},{"name_or_parameter":"rst","field_description":"The rst bit is used to initiate a software reset. The reset mechanism can be enabled in both standby and active modes. When the rst bit is set, the boot mechanism resets all functional block registers and loads the respective internal registers with their default values. Refer to document FXOS8700CQER for further information and a suggested work-around. After setting the rst bit, the system will automatically transition to standby mode. Therefore, if the system was already in standby mode, the reboot process will immediately begin; else if the system was in active mode the boot mechanism will automatically transition the system from active mode to standby mode, only then can the reboot process begin. A system reset can also be initiated by pulsing the external RST pin high. The host application should allow 1 ms between issuing a software (setting rst bit) or hardware (pulsing RST pin) reset and attempting communications with the device over the I²C or SPI interfaces. When the SPI interface mode is desired and multiple devices are present on the bus, make sure that the bus is quiet (all slave device MISO pins are high-z) during this 1 ms period to ensure the device does not inadvertently enter I²C mode. See Section 10.2.3 for further information about the interface mode auto-detection circuit. Note: The I²C and SPI communication systems are also reset to avoid corrupted data transactions. On issuing a software reset command over an I²C interface, the device immediately resets and does not send any acknowledgment (ACK) of the written byte to the master. The host application has to implement the I²C driver in such a way that it does not look for an ACK following a soft reset command. At the end of the boot process, the rst bit is hardware cleared. 0 – Device reset disabled 1 – Device reset enabled","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"Device reset disabled"},{"value":"1","value_description":"Device reset enabled"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 36 (PDF p.44); field description source: Table 37 (PDF p.45); enumerated-value source: Table 37 (PDF p.45)."},{"name_or_parameter":"-","field_description":"","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 36 (PDF p.44); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"smods[1:0]","field_description":"Accelerometer sleep mode OSR mode selection. This setting, along with the CTRL_REG1[aslp_rate] ODR setting determines the sleep mode power and noise for acceleration measurements. See Table 38 and Table 39 for more information.","bit_start":3,"bit_end":4,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 36 (PDF p.44); field description source: Table 37 (PDF p.45); enumerated-value source: not separately provided."},{"name_or_parameter":"slpe","field_description":"","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 36 (PDF p.44); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"mods[1:0]","field_description":"Accelerometer wake mode OSR mode selection. This setting, along with the ODR selection (CTRL_REG1[dr]) determines the wake mode power and noise for acceleration measurements. See Table 38 and Table 39 for more information.","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 36 (PDF p.44); field description source: Table 37 (PDF p.45); enumerated-value source: not separately provided."}] | [{"name_or_parameter":"st","field_description":"Self-test enable (1 enables accelerometer self-test)","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Self-test disabled"},{"value":"1","value_description":"Self-test enabled"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"rst","field_description":"Software reset (setting this bit initiates reset; hardware-cleared when complete)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"smods[1:0]","field_description":"Accelerometer sleep-mode OSR selection","bit_start":3,"bit_end":4,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"slpe","field_description":"Auto-sleep enable (1 = enabled)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"mods[1:0]","field_description":"Accelerometer wake-mode OSR selection","bit_start":0,"bit_end":1,"bit_width":2,"values":[],"is_reserved":false,"type_write_read":"RW"}] | 0.8 | datasheet bit-field target collection is only partially represented |
| `without registers[13]` | `field_parts` | "datasheet field-part collection" | "extracted field-part collection" | 0.9 | field-part collection is reduced by the bottom-up field-part score |
| `without registers[14].field_parts[0].bit_field[1]` | `values` | [{"value":"0","value_description":"No magnetic sensor reset is active"},{"value":"1","value_description":"One-shot magnetic reset is enabled, hardware cleared when complete"}] | [] | 0.0 | datasheet value enumeration is missing |
| `without registers[14].field_parts[0].bit_field[2]` | `values` | [{"value":"0","value_description":"No action taken, or one-shot measurement complete"},{"value":"1","value_description":"If device is in active mode no action is taken. If device is in standby mode, take one set of magnetic measurements, clear this bit, and return to standby mode"}] | [] | 0.0 | datasheet value enumeration is missing |
| `without registers[14].field_parts[0].bit_field` | `bit_field` | [{"name_or_parameter":"m_acal","field_description":"Magnetic hard-iron offset auto-calibration enable: 0 – Auto-calibration feature disabled 1 – Auto-calibration feature is enabled; the ASIC uses the maximum and minimum magnetic data to determine the hard iron offset value. The M_OFF_X/Y/Z registers are automatically loaded with (MAX_X/Y/Z + MIN_X/Y/Z)/2 for each axis at the end of every ODR cycle.","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Auto-calibration feature disabled"},{"value":"1","value_description":"Auto-calibration feature is enabled; the ASIC uses the maximum and minimum magnetic data to determine the hard iron offset value. The M_OFF_X/Y/Z registers are automatically loaded with (MAX_X/Y/Z + MIN_X/Y/Z)/2 for each axis at the end of every ODR cycle"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: Table 198 (PDF p.97)."},{"name_or_parameter":"m_rst","field_description":"One-shot magnetic reset degauss control bit: 0 – No magnetic sensor reset is active 1 – One-shot magnetic reset is enabled, hardware cleared when complete.","bit_start":6,"bit_end":6,"bit_width":1,"values":[{"value":"0","value_description":"No magnetic sensor reset is active"},{"value":"1","value_description":"One-shot magnetic reset is enabled, hardware cleared when complete"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: Table 198 (PDF p.97)."},{"name_or_parameter":"m_ost","field_description":"One-shot triggered magnetic measurement mode: 0 – No action taken, or one-shot measurement complete. 1 – If device is in active mode no action is taken. If device is in standby mode, take one set of magnetic measurements, clear this bit, and return to standby mode.","bit_start":5,"bit_end":5,"bit_width":1,"values":[{"value":"0","value_description":"No action taken, or one-shot measurement complete"},{"value":"1","value_description":"If device is in active mode no action is taken. If device is in standby mode, take one set of magnetic measurements, clear this bit, and return to standby mode"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: Table 198 (PDF p.97)."},{"name_or_parameter":"m_os[2:0]","field_description":"Oversample ratio (OSR) for magnetometer data (see Table 203).","bit_start":2,"bit_end":4,"bit_width":3,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: not separately provided."},{"name_or_parameter":"m_hms[1:0]","field_description":"0b00 – Only accelerometer sensor is active 0b01 – Only magnetometer sensor is active 0b11 – Hybrid mode, both accelerometer and magnetometer sensors are active[1]","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"Only accelerometer sensor is active"},{"value":"0b01","value_description":"Only magnetometer sensor is active"},{"value":"0b11","value_description":"Hybrid mode, both accelerometer and magnetometer sensors are active[1]"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 197 (PDF p.96); field description source: Table 198 (PDF p.97); enumerated-value source: Table 198 (PDF p.97)."}] | [{"name_or_parameter":"m_acal","field_description":"Auto-calibration enable (hard-iron offset auto-cal)","bit_start":7,"bit_end":7,"bit_width":1,"values":[{"value":"0","value_description":"Auto-calibration disabled"},{"value":"1","value_description":"Auto-calibration enabled"}],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_rst","field_description":"One-shot magnetic reset degauss control (write to initiate)","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_ost","field_description":"One-shot triggered magnetic measurement (in standby: take one measurement then return to standby)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_os[2:0]","field_description":"Magnetometer oversampling ratio (OSR) selection","bit_start":2,"bit_end":4,"bit_width":3,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_hms[1:0]","field_description":"Mode select: 00 accel only; 01 mag only; 11 hybrid accel+mag","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"Accelerometer only"},{"value":"0b01","value_description":"Magnetometer only"},{"value":"0b11","value_description":"Hybrid (accel + mag)"}],"is_reserved":false,"type_write_read":"RW"}] | 0.9 | datasheet bit-field target collection is only partially represented |
| `without registers[14]` | `field_parts` | "datasheet field-part collection" | "extracted field-part collection" | 1.0 | field-part collection is reduced by the bottom-up field-part score |
| `truth registers[86].field_parts[0].bit_field[0]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[86].field_parts[0].bit_field[0]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[86].field_parts[0].bit_field[0]` | `bit_start` | 7 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[86].field_parts[0].bit_field[0]` | `bit_end` | 7 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[86].field_parts[0].bit_field[0]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[86].field_parts[0].bit_field[0]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[86].field_parts[0].bit_field[0]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[86].field_parts[0].bit_field[0]` | `type_write_read` | "RW" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[86].field_parts[0].bit_field[1]` | `name_or_parameter` | "-" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[86].field_parts[0].bit_field[1]` | `field_description` | "" | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[86].field_parts[0].bit_field[1]` | `bit_start` | 6 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[86].field_parts[0].bit_field[1]` | `bit_end` | 6 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[86].field_parts[0].bit_field[1]` | `bit_width` | 1 | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[86].field_parts[0].bit_field[1]` | `values` | [] | null | 0.0 | objective value-code set matches |
| `truth registers[86].field_parts[0].bit_field[1]` | `is_reserved` | True | null | 0.0 | bit field is missing from the extracted map |
| `truth registers[86].field_parts[0].bit_field[1]` | `type_write_read` | "RW" | null | 0.0 | bit field is missing from the extracted map |
| `without registers[15].field_parts[0].bit_field[1]` | `values` | [{"value":"0","value_description":"Magnetic min/max detection function is enabled (default)"},{"value":"1","value_description":"Magnetic min/max detection function is disabled. When enabled, the magnetic min/max detection function will update the MAX_X/Y/Z and MIN_X/Y/Z registers at the end of each ODR cycle with the maximum and minimum magnetic measurements from each axis. This is used along with the auto-cal feature (M_CTRL_REG1[m_acal] = 1) as a hardware based hard-iron offset compensation function"}] | [] | 0.0 | datasheet value enumeration is missing |
| `without registers[15].field_parts[0].bit_field[2]` | `values` | [{"value":"0","value_description":"No impact to magnetic min/max detection function on a magnetic threshold event"},{"value":"1","value_description":"Magnetic min/max detection function is disabled when magnetic threshold event is triggered"}] | [] | 0.0 | datasheet value enumeration is missing |
| `without registers[15].field_parts[0].bit_field[3]` | `values` | [{"value":"0","value_description":"No reset sequence is active"},{"value":"1","value_description":"Setting this bit resets the MIN_X/Y/Z and MAX_X/Y/Z registers to 0x7FFF and 0x8000, respectively (positive and negative full-scale values).This bit is automatically cleared after the reset is completed"}] | [] | 0.0 | datasheet value enumeration is missing |
| `without registers[15].field_parts[0].bit_field` | `bit_field` | [{"name_or_parameter":"-","field_description":"","bit_start":7,"bit_end":7,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"-","field_description":"","bit_start":6,"bit_end":6,"bit_width":1,"values":[],"is_reserved":true,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: not separately provided; enumerated-value source: not separately provided."},{"name_or_parameter":"hyb_autoinc_mode","field_description":"With hyb_autoinc_mode = 1 and fast-read mode is disabled (CTRL_REG1 [f_read] = 0), the register address will automatically advance to register 0x33 (M_OUT_X_MSB) after reading register 0x06 (OUT_Z_LSB) in burst-read mode. For hyb_autoinc_mode = 1 and fast-read mode enabled (CTRL_REG1[f_read] = 1) the register address will automatically advance to register 0x33 (M_OUT_X_MSB) after reading register 0x05 (OUT_Z_MSB) during a burst-read mode. Refer to the register map auto-increment address column for further information.","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: not separately provided."},{"name_or_parameter":"m_maxmin_dis","field_description":"Magnetic measurement max/min detection function disable: 0 – Magnetic min/max detection function is enabled (default). 1 – Magnetic min/max detection function is disabled. When enabled, the magnetic min/max detection function will update the MAX_X/Y/Z and MIN_X/Y/Z registers at the end of each ODR cycle with the maximum and minimum magnetic measurements from each axis. This is used along with the auto-cal feature (M_CTRL_REG1[m_acal] = 1) as a hardware based hard-iron offset compensation function.","bit_start":4,"bit_end":4,"bit_width":1,"values":[{"value":"0","value_description":"Magnetic min/max detection function is enabled (default)"},{"value":"1","value_description":"Magnetic min/max detection function is disabled. When enabled, the magnetic min/max detection function will update the MAX_X/Y/Z and MIN_X/Y/Z registers at the end of each ODR cycle with the maximum and minimum magnetic measurements from each axis. This is used along with the auto-cal feature (M_CTRL_REG1[m_acal] = 1) as a hardware based hard-iron offset compensation function"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: Table 200 (PDF p.98)."},{"name_or_parameter":"m_maxmin_dis_ths","field_description":"Magnetic measurement min/max detection function disable using the magnetic threshold event trigger: 0 – No impact to magnetic min/max detection function on a magnetic threshold event 1 – Magnetic min/max detection function is disabled when magnetic threshold event is triggered","bit_start":3,"bit_end":3,"bit_width":1,"values":[{"value":"0","value_description":"No impact to magnetic min/max detection function on a magnetic threshold event"},{"value":"1","value_description":"Magnetic min/max detection function is disabled when magnetic threshold event is triggered"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: Table 200 (PDF p.98)."},{"name_or_parameter":"m_maxmin_rst","field_description":"Magnetic measurement min/max detection function reset: 0 – No reset sequence is active 1 – Setting this bit resets the MIN_X/Y/Z and MAX_X/Y/Z registers to 0x7FFF and 0x8000, respectively (positive and negative full-scale values).This bit is automatically cleared after the reset is completed.","bit_start":2,"bit_end":2,"bit_width":1,"values":[{"value":"0","value_description":"No reset sequence is active"},{"value":"1","value_description":"Setting this bit resets the MIN_X/Y/Z and MAX_X/Y/Z registers to 0x7FFF and 0x8000, respectively (positive and negative full-scale values).This bit is automatically cleared after the reset is completed"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: Table 200 (PDF p.98)."},{"name_or_parameter":"m_rst_cnt[1:0]","field_description":"Magnetic sensor reset (degaussing) frequency: 0b00 – Automatic magnetic reset at the beginning of each ODR cycle (default). 0b01 – Automatic magnetic reset every 16 ODR cycles. 0b10 – Automatic magnetic reset every 512 ODR cycles. 0b11 – Automatic magnetic reset is disabled. Magnetic reset only occurs automatically on a transition from standby to active mode, or can be triggered manually by setting M_CTRL_REG1[m_rst] = 1","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"Automatic magnetic reset at the beginning of each ODR cycle (default)"},{"value":"0b01","value_description":"Automatic magnetic reset every 16 ODR cycles"},{"value":"0b10","value_description":"Automatic magnetic reset every 512 ODR cycles"},{"value":"0b11","value_description":"Automatic magnetic reset is disabled. Magnetic reset only occurs automatically on a transition from standby to active mode, or can be triggered manually by setting M_CTRL_REG1[m_rst] = 1"}],"is_reserved":false,"type_write_read":"RW","source":"allocation Table 199 (PDF p.97); field description source: Table 200 (PDF p.98); enumerated-value source: Table 200 (PDF p.98)."}] | [{"name_or_parameter":"hyb_autoinc_mode","field_description":"Hybrid auto-increment mode (maps magnetometer registers after accel registers in burst reads when set)","bit_start":5,"bit_end":5,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_maxmin_dis","field_description":"Disable magnetic max/min detection (1 = disabled)","bit_start":4,"bit_end":4,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_maxmin_dis_ths","field_description":"Disable max/min on magnetic threshold event (1 = disabled on threshold)","bit_start":3,"bit_end":3,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_maxmin_rst","field_description":"Reset MAX/MIN registers when set (hardware cleared when complete)","bit_start":2,"bit_end":2,"bit_width":1,"values":[],"is_reserved":false,"type_write_read":"RW"},{"name_or_parameter":"m_rst_cnt[1:0]","field_description":"Magnetic reset (degauss) frequency selection","bit_start":0,"bit_end":1,"bit_width":2,"values":[{"value":"0b00","value_description":"Reset at beginning of each ODR cycle"},{"value":"0b01","value_description":"Reset every 16 ODR cycles"},{"value":"0b10","value_description":"Reset every 512 ODR cycles"},{"value":"0b11","value_description":"Auto reset disabled"}],"is_reserved":false,"type_write_read":"RW"}] | 0.6 | datasheet bit-field target collection is only partially represented |
| `without registers[15]` | `field_parts` | "datasheet field-part collection" | "extracted field-part collection" | 0.9 | field-part collection is reduced by the bottom-up field-part score |
| `without registers[16]` | `default_value` | "Data" | "" | 0.0 | datasheet default value is missing from the extracted map |

### 4.3 Unmatched extracted bit ranges

These extracted bit fields have no exact datasheet `bit_start`/`bit_end` target. They are listed for auditability and are not counted as additional physical registers.

| Extracted location | Datasheet part | Extracted name | Extracted range |
|---|---|---|---|
| `without registers[0].field_parts[0].bit_field[0]` | `truth registers[0].field_parts[0]` | "zyxow" | 7:7 |
| `without registers[0].field_parts[0].bit_field[1]` | `truth registers[0].field_parts[0]` | "zow" | 6:6 |
| `without registers[0].field_parts[0].bit_field[2]` | `truth registers[0].field_parts[0]` | "yow" | 5:5 |
| `without registers[0].field_parts[0].bit_field[3]` | `truth registers[0].field_parts[0]` | "xow" | 4:4 |
| `without registers[0].field_parts[0].bit_field[4]` | `truth registers[0].field_parts[0]` | "zyxdr" | 3:3 |
| `without registers[0].field_parts[0].bit_field[5]` | `truth registers[0].field_parts[0]` | "zdr" | 2:2 |
| `without registers[0].field_parts[0].bit_field[6]` | `truth registers[0].field_parts[0]` | "ydr" | 1:1 |
| `without registers[0].field_parts[0].bit_field[7]` | `truth registers[0].field_parts[0]` | "xdr" | 0:0 |
| `without registers[2].field_parts[0].bit_field[1]` | `truth registers[2].field_parts[0]` | "Reserved" | 1:0 |
| `without registers[4].field_parts[0].bit_field[1]` | `truth registers[4].field_parts[0]` | "Reserved" | 1:0 |
| `without registers[6].field_parts[0].bit_field[1]` | `truth registers[6].field_parts[0]` | "Reserved" | 1:0 |

### 4.4 Description differences credited under the requested leniency

Nonempty descriptions with preserved functional meaning receive C=1.0 even when wording differs.

| Datasheet location | Extracted location | Field | Datasheet content | Extracted content | Result |
|---|---|---|---|---|---|
| `truth registers[0].field_parts[0]` | `without registers[0].field_parts[0]` | `description` | "Real-time data-ready status or FIFO status (DR_STATUS or F_STATUS)" | "Status (data-ready or FIFO status depending on F_SETUP[f_mode])" | C=1.0, meaning preserved |
| `truth registers[0].register_description` | `without registers[0].register_description` | `register_description` | "Real-time data-ready status or FIFO status (DR_STATUS or F_STATUS)" | "Real-time data-ready status or FIFO status; aliases DR_STATUS (f_mode=0) or F_STATUS (f_mode>0)." | C=1.0, meaning preserved |
| `truth registers[1].field_parts[0]` | `without registers[1].field_parts[0]` | `description` | "[7:0] are 8 MSBs of 14-bit sample. Root pointer to XYZ FIFO data." | "High byte of 14-bit X-axis accelerometer sample" | C=1.0, meaning preserved |
| `truth registers[1].register_description` | `without registers[1].register_description` | `register_description` | "[7:0] are 8 MSBs of 14-bit sample. Root pointer to XYZ FIFO data." | "MSB byte of 14-bit left-justified X-axis accelerometer sample (2's complement)." | C=1.0, meaning preserved |
| `truth registers[2].field_parts[0]` | `without registers[2].field_parts[0]` | `description` | "[7:2] are 6 LSBs of 14-bit real-time sample" | "Low byte of 14-bit X-axis accelerometer sample (bits [7:2] are sample LSBs)" | C=1.0, meaning preserved |
| `truth registers[2].register_description` | `without registers[2].register_description` | `register_description` | "[7:2] are 6 LSBs of 14-bit real-time sample" | "LSB byte of 14-bit left-justified X-axis accelerometer sample; bits [7:2] contain the 6 LSBs of the 14-bit value." | C=1.0, meaning preserved |
| `truth registers[3].field_parts[0]` | `without registers[3].field_parts[0]` | `description` | "[7:0] are 8 MSBs of 14-bit real-time sample" | "High byte of 14-bit Y-axis accelerometer sample" | C=1.0, meaning preserved |
| `truth registers[3].register_description` | `without registers[3].register_description` | `register_description` | "[7:0] are 8 MSBs of 14-bit real-time sample" | "MSB byte of 14-bit left-justified Y-axis accelerometer sample (2's complement)." | C=1.0, meaning preserved |
| `truth registers[4].field_parts[0]` | `without registers[4].field_parts[0]` | `description` | "[7:2] are 6 LSBs of 14-bit real-time sample" | "Low byte of 14-bit Y-axis accelerometer sample" | C=1.0, meaning preserved |
| `truth registers[4].register_description` | `without registers[4].register_description` | `register_description` | "[7:2] are 6 LSBs of 14-bit real-time sample" | "LSB byte of 14-bit left-justified Y-axis accelerometer sample; bits [7:2] contain the 6 LSBs." | C=1.0, meaning preserved |
| `truth registers[5].field_parts[0]` | `without registers[5].field_parts[0]` | `description` | "[7:0] are 8 MSBs of 14-bit real-time sample" | "High byte of 14-bit Z-axis accelerometer sample" | C=1.0, meaning preserved |
| `truth registers[5].register_description` | `without registers[5].register_description` | `register_description` | "[7:0] are 8 MSBs of 14-bit real-time sample" | "MSB byte of 14-bit left-justified Z-axis accelerometer sample (2's complement)." | C=1.0, meaning preserved |
| `truth registers[6].field_parts[0]` | `without registers[6].field_parts[0]` | `description` | "[7:2] are 6 LSBs of 14-bit real-time sample" | "Low byte of 14-bit Z-axis accelerometer sample" | C=1.0, meaning preserved |
| `truth registers[6].register_description` | `without registers[6].register_description` | `register_description` | "[7:2] are 6 LSBs of 14-bit real-time sample" | "LSB byte of 14-bit left-justified Z-axis accelerometer sample; bits [7:2] contain the 6 LSBs." | C=1.0, meaning preserved |
| `truth registers[7].field_parts[0]` | `without registers[7].field_parts[0]` | `description` | "FIFO setup" | "FIFO mode and watermark/pre-trigger sample count" | C=1.0, meaning preserved |
| `truth registers[7].register_description` | `without registers[7].register_description` | `register_description` | "FIFO setup" | "FIFO configuration: mode (disabled, circular, stop, trigger) and watermark level / pre-trigger sample count." | C=1.0, meaning preserved |
| `truth registers[9].field_parts[0]` | `without registers[8].field_parts[0]` | `description` | "Current system mode" | "System mode and FIFO gate information" | C=1.0, meaning preserved |
| `truth registers[9].register_description` | `without registers[8].register_description` | `register_description` | "Current system mode" | "System mode and FIFO gate error status; indicates standby/wake/sleep and FIFO gate error plus time since error." | C=1.0, meaning preserved |
| `truth registers[10].field_parts[0]` | `without registers[9].field_parts[0]` | `description` | "Interrupt status" | "Interrupt status bits for various event sources" | C=1.0, meaning preserved |
| `truth registers[10].register_description` | `without registers[9].register_description` | `register_description` | "Interrupt status" | "Interrupt source/status flags identifying which functional blocks asserted interrupts." | C=1.0, meaning preserved |
| `truth registers[11].field_parts[0]` | `without registers[10].field_parts[0]` | `description` | "Device ID" | "Device identification register" | C=1.0, meaning preserved |
| `truth registers[11].register_description` | `without registers[10].register_description` | `register_description` | "Device ID" | "Device ID register; returns device identifier (production = 0xC7)." | C=1.0, meaning preserved |
| `truth registers[12].field_parts[0]` | `without registers[11].field_parts[0]` | `description` | "Acceleration dynamic range and filter enable settings" | "Full-scale range selection and output HPF enable" | C=1.0, meaning preserved |
| `truth registers[12].register_description` | `without registers[11].register_description` | `register_description` | "Acceleration dynamic range and filter enable settings" | "Configures accelerometer full-scale range and enables high-pass filter on output." | C=1.0, meaning preserved |
| `truth registers[36].field_parts[0]` | `without registers[12].field_parts[0]` | `description` | "System ODR, accelerometer OSR, operating mode" | "ODR, auto-sleep rate, low-noise, fast-read, active" | C=1.0, meaning preserved |
| `truth registers[36].register_description` | `without registers[12].register_description` | `register_description` | "System ODR, accelerometer OSR, operating mode" | "Controls system ODR (dr), auto-sleep rate (aslp_rate), noise mode, fast-read selection and active/standby state." | C=1.0, meaning preserved |
| `truth registers[37].field_parts[0]` | `without registers[13].field_parts[0]` | `description` | "Self-test, reset, accelerometer OSR and sleep mode settings" | "Self-test, software reset, sleep/wake OSR, auto-sleep" | C=1.0, meaning preserved |
| `truth registers[37].register_description` | `without registers[13].register_description` | `register_description` | "Self-test, reset, accelerometer OSR and sleep mode settings" | "Self-test, software reset, sleep/wake OSR selections and auto-sleep enable; controls accelerometer oversampling modes." | C=1.0, meaning preserved |
| `truth registers[85].field_parts[0]` | `without registers[14].field_parts[0]` | `description` | "Control for magnetic sensor functions" | "Magnetometer control: auto-cal, reset, one-shot, OSR, hybrid mode" | C=1.0, meaning preserved |
| `truth registers[85].register_description` | `without registers[14].register_description` | `register_description` | "Control for magnetic sensor functions" | "Magnetometer control: auto-calibration, one-shot reset/measurement, magnetometer OSR (m_os) and hybrid mode selection (m_hms)." | C=1.0, meaning preserved |
| `truth registers[86].field_parts[0]` | `without registers[15].field_parts[0]` | `description` | "Control for magnetic sensor functions" | "Magnetometer auto-increment, max/min control, reset configuration" | C=1.0, meaning preserved |
| `truth registers[86].register_description` | `without registers[15].register_description` | `register_description` | "Control for magnetic sensor functions" | "Magnetometer control options: hybrid auto-increment mapping, max/min detection control, reset settings and reset frequency." | C=1.0, meaning preserved |
| `truth registers[45].field_parts[0]` | `without registers[16].field_parts[0]` | `description` | "MSB of 16-bit magnetic data for X-axis" | "High byte of 16-bit magnetometer X-axis output" | C=1.0, meaning preserved |
| `truth registers[45].register_description` | `without registers[16].register_description` | `register_description` | "MSB of 16-bit magnetic data for X-axis" | "MSB of 16-bit 2's complement magnetometer X-axis output (0.1 μT/LSB)." | C=1.0, meaning preserved |

### 4.5 Coverage summary

- Actual datasheet physical-register coverage: 17/115; missing actual physical registers: 98.
- Extra extracted physical addresses: 0; extra-physical penalty factor: 1.000000.
- Extracted logical registers: 17; extracted field parts: 17; extracted bit fields: 54.
- Unmatched extracted bit-field ranges: 11; field-level deviation entries: 243.

## 5. Calculation summary

The `without` extraction contains 17 logical registers, all at actual datasheet addresses, but omits 98 of the 115 actual physical registers. For the 17 present logical registers, every Q(L) is calculated bottom-up from bit fields to field parts and then to the logical register. The final score is **1.400688425/10** with n=115, m=17, x=0.

The largest deductions among the present entries come from the STATUS alias being represented as eight DR_STATUS bit fields instead of the datasheet's single `DR_STATUS or F_STATUS [7:0]` allocation, omitted reserved-bit targets in the accelerometer and magnetic control maps, and missing default markers for data registers. These are objective or structural omissions; description wording differences are treated leniently.

