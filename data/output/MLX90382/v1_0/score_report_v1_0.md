# MLX90382 v1.0 detailed score - datasheet comparison

## 1. Scoring basis

- The comparison baseline is the MLX90382 datasheet itself; no truth JSON is used for this report.
- Datasheet source: [MLX90382.pdf](D:/python/master_arbeit/data/output/MLX90382/MLX90382.pdf), MLX90382 16-Bit Triaxis High Speed Position Sensor IC Datasheet, Revision 1.0, 17-Nov-2025, document 3901090382, 74 pages.
- Printed page numbers are used below. The PDF page index in pages.json is zero-based, so PDF page_index=58 corresponds to printed p.59.
- The datasheet defines 64 unique physical register locations in the user-programmable/register tables, including 0x0BE from Table 32 and the 17 DSP locations in Tables 46-47.
- The v1 result contains 64 logical register entries and one physical field part per entry. All 64 numeric addresses match the datasheet; therefore n=64, m=64, x=0, and every q_R has exactly one associated Q(L).
- Bottom-up evaluation is performed independently for every logical register: every bit field -> its field part -> its logical register. Rounded bit-field weights are normalized by 0.9999; logical-register weights are normalized by 1.0001; field-part weights sum to 1.0000.
- For physical_address, the numeric address plus empty bank/page is the objective content. Empty address-description submembers are not treated as a functional address error. Empty field_parts[*].description is incomplete descriptive information and is scored 0.5.
- All top-level register descriptions are semantically consistent with the cited datasheet and are scored 1.0. default_value_description is scored 1.0 when empty because the datasheet has no separate default-description column.
- Register-word defaults are normalized from the datasheet field defaults. For multi-field words, each field default is placed at its listed bit range. N/A, symbolic defaults, and the partial USER_ID4/USER_ID5 case are preserved.

### Datasheet inconsistencies handled explicitly

- The prose on p.30 writes DE_SR[2:0] = 3, while Table 32 on p.31 gives DE_SR[3:1]. The objective bit range follows the register table (Table 32); v1 uses [3:1] and is not penalized.
- Table 49 on p.61 leaves ABI_CFG bits [11:8] absent. The physical register is still treated as a 16-bit word because the device and SPI register data are 16-bit; the reported default 0x005C is explicitly marked as listed-bits-only.
- Section 6.8 on p.22 refers to SC_HL[7:0], while Table 52 on p.65 gives [8:0]. The register table is used for the objective bit range; v1 uses [8:0] and is not penalized.

## 2. Global error and omission inventory

| Exact v1 location | Datasheet fact | v1 content | Judgment |
|---|---|---|---|
| `registers[0].default_value` | `0x0000 (datasheet field default is 0)` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[1].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[2].default_value` | `0x0002` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[4].default_value` | `N/A` | `""` | C=0.5; Datasheet says N/A; blank is incomplete. |
| `registers[5].default_value` | `0x0008` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[6].default_value` | `0x0017` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[7].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[8].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[18].default_value` | `0x0E30 (derived from SENSING_MODE=0, GPIO_IF=2, ABI_IF=1, ABI_DIFF=0, GPIO_CFG=28, Not used=0)` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[19].default_value` | `0x005C (listed defaults only; datasheet Table 49 omits bits [11:8])` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[20].default_value` | `0xD803` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[21].default_value` | `0x00F4` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[23].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[24].default_value` | `0x3C00` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[25].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[26].default_value` | `0x003A` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[27].default_value` | `0x000C` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[28].default_value` | `0x0008` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[29].default_value` | `0x1000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[30].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[32].default_value` | `0x750E` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[33].default_value` | `0x007A` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[34].default_value` | `0x02FE` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[35].default_value` | `0xFA02` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[36].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[38].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[39].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[40].default_value` | `partial: USER_ID4=0, USER_ID5=N/A` | `""` | C=0.5; One byte is 0, the other is N/A; blank is incomplete. |
| `registers[41].default_value` | `0x0FC0` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[42].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[43].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[44].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[45].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[46].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[47].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[48].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[49].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[50].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[58].default_value` | `0x0080` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[59].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[60].default_value` | `0xA840` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[61].default_value` | `0x0314` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[62].default_value` | `0x0000` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[63].default_value` | `0x0380` | `""` | C=0.0; The normalized datasheet default is missing. |
| `registers[0].width_bits` and `registers[0].field_parts[0].width_bits` | `16` bits for the 16-bit physical register word | `""` | C=0.0; width is missing. |
| `registers[19].width_bits` and `registers[19].field_parts[0].width_bits` | `16` bits for the 16-bit physical register word | `""` | C=0.0; width is missing. |
| `registers[1].field_parts[0].bit_field[1].type_write_read` | `R` for `Not used [15:4]` | `""` | C=0.0; access type is omitted. |
| `registers[2].field_parts[0].bit_field[2].type_write_read` | `R` for `Not used [15:3]` | `""` | C=0.0; access type is omitted. |
| `registers[4].field_parts[0].bit_field[2].type_write_read` | `RW` for `Reserved [2:2]` | `""` | C=0.0; access type is omitted. |
| `registers[4].field_parts[0].bit_field[3].type_write_read` | `R` for `Not used [15:3]` | `""` | C=0.0; access type is omitted. |
| `registers[5].field_parts[0].bit_field[1].type_write_read` | `R` for `Not used [15:8]` | `""` | C=0.0; access type is omitted. |
| `registers[6].field_parts[0].bit_field[1].type_write_read` | `RW` for `Reserved [6:6]` | `""` | C=0.0; access type is omitted. |
| `registers[6].field_parts[0].bit_field[2].type_write_read` | `R` for `Not used [15:7]` | `""` | C=0.0; access type is omitted. |
| `registers[7].field_parts[0].bit_field[1].type_write_read` | `R` for `Not used [15:13]` | `""` | C=0.0; access type is omitted. |
| `registers[8].field_parts[0].bit_field[1].type_write_read` | `R` for `Not used [15:12]` | `""` | C=0.0; access type is omitted. |
| `registers[18].field_parts[0].bit_field[5].type_write_read` | `R` for `Not used [15:12]` | `""` | C=0.0; access type is omitted. |
| `registers[19].field_parts[0].bit_field[2].type_write_read` | `R` for `Not used [15:12]` | `""` | C=0.0; access type is omitted. |
| `registers[21].field_parts[0].bit_field[2].type_write_read` | `RW` for `Reserved [7:2]` | `""` | C=0.0; access type is omitted. |
| `registers[21].field_parts[0].bit_field[3].type_write_read` | `R` for `Not used [15:8]` | `""` | C=0.0; access type is omitted. |
| `registers[23].field_parts[0].bit_field[1].type_write_read` | `R` for `Not used [15:9]` | `""` | C=0.0; access type is omitted. |
| `registers[26].field_parts[0].bit_field[6].type_write_read` | `R` for `Not used [15:14]` | `""` | C=0.0; access type is omitted. |
| `registers[28].field_parts[0].bit_field[4].type_write_read` | `R` for `Not used [15:12]` | `""` | C=0.0; access type is omitted. |
| `registers[29].field_parts[0].bit_field[3].type_write_read` | `R` for `Not used [15:13]` | `""` | C=0.0; access type is omitted. |
| `registers[30].field_parts[0].bit_field[3].type_write_read` | `RW` for `Reserved [6:5]` | `""` | C=0.0; access type is omitted. |
| `registers[30].field_parts[0].bit_field[4].type_write_read` | `R` for `Not used [15:7]` | `""` | C=0.0; access type is omitted. |
| `registers[33].field_parts[0].bit_field[1].type_write_read` | `RW` for `Reserved [8:8]` | `""` | C=0.0; access type is omitted. |
| `registers[34].field_parts[0].bit_field[2].type_write_read` | `R` for `Not used [15:11]` | `""` | C=0.0; access type is omitted. |
| `registers[41].field_parts[0].bit_field[2].type_write_read` | `R` for `Not used [15:12]` | `""` | C=0.0; access type is omitted. |
| `registers[42].field_parts[0].bit_field[1].type_write_read` | `R` for `Not used [15:3]` | `""` | C=0.0; access type is omitted. |
| `registers[58].field_parts[0].bit_field[1].type_write_read` | `R` for `Not used [15:9]` | `""` | C=0.0; access type is omitted. |
| `registers[59].field_parts[0].bit_field[1].type_write_read` | `R` for `Not used [15:8]` | `""` | C=0.0; access type is omitted. |
| `registers[60].field_parts[0].bit_field[3].type_write_read` | `RW` for `Reserved [6:6]` | `""` | C=0.0; access type is omitted. |
| `registers[61].field_parts[0].bit_field[4].type_write_read` | `RW` for `Reserved [14:10]` | `""` | C=0.0; access type is omitted. |
| `registers[61].field_parts[0].bit_field[5].type_write_read` | `R` for `Not used [15:15]` | `""` | C=0.0; access type is omitted. |
| `registers[62].field_parts[0].bit_field[3].type_write_read` | `RW` for `Reserved [15:15]` | `""` | C=0.0; access type is omitted. |
| `registers[63].field_parts[0].bit_field[0].type_write_read` | `RW` for `Reserved [6:0]` | `""` | C=0.0; access type is omitted. |
| `registers[63].field_parts[0].bit_field[2].type_write_read` | `RW` for `Reserved [9:9]` | `""` | C=0.0; access type is omitted. |
| `registers[63].field_parts[0].bit_field[3].type_write_read` | `R` for `Not used [14:10]` | `""` | C=0.0; access type is omitted. |
| `registers[63].field_parts[0].bit_field[4].type_write_read` | `RW` for `Reserved [15:15]` | `""` | C=0.0; access type is omitted. |
| `registers[33].field_parts[0].bit_field[2].type_write_read` | `R` for `Not used [15:9]` | `""` | C=0.0; access type is omitted. |
| `registers[28].field_parts[0].bit_field[1].values` | Datasheet Table 49 lists the 1 behavior; it does not enumerate the 0 behavior in that table. | `[0 -&gt; Angular position is captured before each slave's DATA(FADDR0)[15:8].; 1 -&gt; Capture is aligned with the first DATA(FADDR0)[15:8] byte in the Super Frame.]` | C=0.5; partially supported by the datasheet. |
| `registers[0..63].field_parts[0].description` | The cited datasheet table provides a physical-register/field-set description. | `""` for every field part | C=0.5 for each field part; descriptive omission only. |

No logical register is missing, no datasheet physical address is unmatched, and no extra extracted physical address is present. The exact bottom-up audit for every entry follows.

## 3. Detailed bottom-up calculation for every extracted logical register

For every bit-field table below, the C-vector order is name_or_parameter, field_description, bit_start, bit_end, bit_width, values, is_reserved, type_write_read. The formula is Q_BF = (0.0212*C1 + 0.0586*C2 + 0.2594*C3 + 0.2594*C4 + 0.0583*C5 + 0.2097*C6 + 0.0750*C7 + 0.0583*C8) / 0.9999.

## Extracted logical register 1: `DE_SR`

v1 location: `registers[0]`; datasheet association: `DE_SR` at `0x0BE`. Physical location: `0x0BE (190)`.
Datasheet source: pp.30-31, Table 32; explanatory text on p.30.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DE_SR` at `0x0BE (190)`

Locations: datasheet row(s) cited above <-> v1 `registers[0].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[0].field_parts[0].bit_field[0]` | `DE_SR` / `DE_SR` | "Disable Shadow Register Monitor. If 3, register monitor is disabled." / "Disable Shadow Register Monitor. If 3, register monitor is disabled." | `1:3` / `1:3` | `3` / `3` | "[3 -&gt; Register monitor is disabled.]" / "[3 -&gt; Register monitor is disabled.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `DE_SR`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `DE_SR` | `DE_SR` |
| `physical_address` | 0.4688 | 1.000000 | `0x0BE (190), bank="", page=""` | `0x0BE (190), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 0.000000 | `16` | "" |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.904850 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x0.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.904850**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.904850) = **0.904850**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `DE_SR` | `DE_SR` |
| `physical_address` | 0.4044 | 1.000000 | `0x0BE (190), bank="", page=""` | `0x0BE (190), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Controls the shadow register monitor. Set DE_SR[3:1] to 3 before sequentially reading many registers, then restore its default value after the read attempt; angular data must not be used during this procedure.` |
| `width_bits` | 0.0590 | 0.000000 | `16` | "" |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.904850 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000 (datasheet field default is 0)` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_1) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x0.000000 + 0.0590x1.000000 + 0.2987x0.904850 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.845894**.

## Extracted logical register 2: `NVOP_KEY`

v1 location: `registers[1]`; datasheet association: `NVOP_KEY` at `0x010`. Physical location: `0x010 (16)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `NVOP_KEY` at `0x010 (16)`

Locations: datasheet row(s) cited above <-> v1 `registers[1].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[1].field_parts[0].bit_field[0]` | `NVOP_KEY` / `NVOP_KEY` | "8 bits KEY to unlock non-volatile operation." / "8 bits KEY to unlock non-volatile operation." | `0:3` / `0:3` | `4` / `4` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[1].field_parts[0].bit_field[1]` | `Not used` / `Not used` | "" / "" | `4:15` / `4:15` | `12` / `12` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `NVOP_KEY`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 0.941694) = **0.970847**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `NVOP_KEY` | `NVOP_KEY` |
| `physical_address` | 0.4688 | 1.000000 | `0x010 (16), bank="", page=""` | `0x010 (16), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.956228 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.970847 = **0.956228**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.956228) = **0.956228**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `NVOP_KEY` | `NVOP_KEY` |
| `physical_address` | 0.4044 | 1.000000 | `0x010 (16), bank="", page=""` | `0x010 (16), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Key used to unlock non-volatile operation.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.956228 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_2) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.956228 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.920233**.

## Extracted logical register 3: `IN_APPLICATION`

v1 location: `registers[2]`; datasheet association: `IN_APPLICATION` at `0x024`. Physical location: `0x024 (36)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `IN_APPLICATION` at `0x024 (36)`

Locations: datasheet row(s) cited above <-> v1 `registers[2].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[2].field_parts[0].bit_field[0]` | `IN_APPLICATION` / `IN_APPLICATION` | "Application-mode state." / "Application-mode state." | `0:1` / `0:1` | `2` / `2` | "[2 -&gt; Application mode off.; else -&gt; Application running.]" / "[2 -&gt; Application mode off.; else -&gt; Application running.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[2].field_parts[0].bit_field[1]` | `DE_NVM_CRC` / `DE_NVM_CRC` | "Disable NVRAM CRC calculation." / "Disable NVRAM CRC calculation." | `2:2` / `2:2` | `1` / `1` | "[1 -&gt; Disable NVRAM CRC calculation.]" / "[1 -&gt; Disable NVRAM CRC calculation.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[2].field_parts[0].bit_field[2]` | `Not used` / `Not used` | "" / "" | `3:15` / `3:15` | `13` / `13` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `IN_APPLICATION`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_NVM_CRC`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 1.000000, 0.941694) = **0.980565**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `IN_APPLICATION` | `IN_APPLICATION` |
| `physical_address` | 0.4688 | 1.000000 | `0x024 (36), bank="", page=""` | `0x024 (36), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.959269 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.980565 = **0.959269**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.959269) = **0.959269**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `IN_APPLICATION` | `IN_APPLICATION` |
| `physical_address` | 0.4044 | 1.000000 | `0x024 (36), bank="", page=""` | `0x024 (36), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Controls application mode and NVRAM CRC calculation.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.959269 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0002` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_3) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.959269 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.921141**.

## Extracted logical register 4: `CRC`

v1 location: `registers[3]`; datasheet association: `CRC` at `0x026`. Physical location: `0x026 (38)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `CRC` at `0x026 (38)`

Locations: datasheet row(s) cited above <-> v1 `registers[3].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[3].field_parts[0].bit_field[0]` | `CRC` / `CRC` | "NVRAM CRC calculation result." / "NVRAM CRC calculation result." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `CRC`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `CRC` | `CRC` |
| `physical_address` | 0.4688 | 1.000000 | `0x026 (38), bank="", page=""` | `0x026 (38), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `CRC` | `CRC` |
| `physical_address` | 0.4044 | 1.000000 | `0x026 (38), bank="", page=""` | `0x026 (38), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Contains the NVRAM CRC calculation result; it is updated when checksum computation finishes.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0000` | `0` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_4) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 5: `CRC_CALC_STRT`

v1 location: `registers[4]`; datasheet association: `CRC_CALC_STRT` at `0x028`. Physical location: `0x028 (40)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `CRC_CALC_STRT` at `0x028 (40)`

Locations: datasheet row(s) cited above <-> v1 `registers[4].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[4].field_parts[0].bit_field[0]` | `CRC_CALC_STRT` / `CRC_CALC_STRT` | "Start NVRAM checksum computation." / "Start NVRAM checksum computation." | `0:0` / `0:0` | `1` / `1` | "[]" / "[]" | `False` / `False` | `W` / `W` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[4].field_parts[0].bit_field[1]` | `CRC_CALC_DONE` / `CRC_CALC_DONE` | "NVRAM checksum computation completion status; CRC is updated in 0x026." / "NVRAM checksum computation completion status; CRC is updated in 0x026." | `1:1` / `1:1` | `1` / `1` | "[1 -&gt; NVRAM checksum computation finished.]" / "[1 -&gt; NVRAM checksum computation finished.]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[4].field_parts[0].bit_field[2]` | `Reserved` / `Reserved` | "Reserved, don't change." / "Reserved, don't change." | `2:2` / `2:2` | `1` / `1` | "[]" / "[]" | `True` / `True` | `RW` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |
| BF4 `registers[4].field_parts[0].bit_field[3]` | `Not used` / `Not used` | "" / "" | `3:15` / `3:15` | `13` / `13` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `CRC_CALC_STRT`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `CRC_CALC_DONE`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Reserved`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 1.000000, 0.941694, 0.941694) = **0.970847**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `CRC_CALC_STRT` | `CRC_CALC_STRT` |
| `physical_address` | 0.4688 | 1.000000 | `0x028 (40), bank="", page=""` | `0x028 (40), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.956228 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.970847 = **0.956228**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.956228) = **0.956228**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `CRC_CALC_STRT` | `CRC_CALC_STRT` |
| `physical_address` | 0.4044 | 1.000000 | `0x028 (40), bank="", page=""` | `0x028 (40), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Starts NVRAM checksum computation and reports completion; the calculated CRC is updated in register 0x026.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.956228 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.500000 | `N/A` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_5) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.956228 + 0.0667x0.500000 + 0.0334x1.000000) / 1.0001 = **0.953580**.

## Extracted logical register 6: `STATE`

v1 location: `registers[5]`; datasheet association: `STATE` at `0x02C`. Physical location: `0x02C (44)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `STATE` at `0x02C (44)`

Locations: datasheet row(s) cited above <-> v1 `registers[5].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[5].field_parts[0].bit_field[0]` | `STATE` / `STATE` | "Device state." / "Device state." | `0:7` / `0:7` | `8` / `8` | "[0x08 -&gt; Norm state.; 0x10 -&gt; Safe-State SS2 (NVRAM failure).; 0x20 -&gt; Safe-State SS2.; 0x40 -&gt; Safe-State SS3.]" / "[0x08 -&gt; Norm state.; 0x10 -&gt; Safe-State SS2 (NVRAM failure).; 0x20 -&gt; Safe-State SS2.; 0x40 -&gt; Safe-State SS3.]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[5].field_parts[0].bit_field[1]` | `Not used` / `Not used` | "" / "" | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `STATE`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 0.941694) = **0.970847**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `STATE` | `STATE` |
| `physical_address` | 0.4688 | 1.000000 | `0x02C (44), bank="", page=""` | `0x02C (44), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.956228 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.970847 = **0.956228**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.956228) = **0.956228**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `STATE` | `STATE` |
| `physical_address` | 0.4044 | 1.000000 | `0x02C (44), bank="", page=""` | `0x02C (44), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Reports the device normal or fail-safe state.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.956228 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0008` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_6) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.956228 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.920233**.

## Extracted logical register 7: `AGC_GAIN`

v1 location: `registers[6]`; datasheet association: `AGC_GAIN` at `0x034`. Physical location: `0x034 (52)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `AGC_GAIN` at `0x034 (52)`

Locations: datasheet row(s) cited above <-> v1 `registers[6].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[6].field_parts[0].bit_field[0]` | `AGC_GAIN` / `AGC_GAIN` | "Current AGC gain setting." / "Current AGC gain setting." | `0:5` / `0:5` | `6` / `6` | "[]" / "[]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[6].field_parts[0].bit_field[1]` | `Reserved` / `Reserved` | "Reserved, don't change." / "Reserved, don't change." | `6:6` / `6:6` | `1` / `1` | "[]" / "[]" | `True` / `True` | `RW` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |
| BF3 `registers[6].field_parts[0].bit_field[2]` | `Not used` / `Not used` | "" / "" | `7:15` / `7:15` | `9` / `9` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `AGC_GAIN`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Reserved`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 0.941694, 0.941694) = **0.961129**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `AGC_GAIN` | `AGC_GAIN` |
| `physical_address` | 0.4688 | 1.000000 | `0x034 (52), bank="", page=""` | `0x034 (52), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.953187 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.961129 = **0.953187**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.953187) = **0.953187**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `AGC_GAIN` | `AGC_GAIN` |
| `physical_address` | 0.4044 | 1.000000 | `0x034 (52), bank="", page=""` | `0x034 (52), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Reports the current AGC gain setting.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.953187 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0017` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_7) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.953187 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.919325**.

## Extracted logical register 8: `AGC_AMP`

v1 location: `registers[7]`; datasheet association: `AGC_AMP` at `0x036`. Physical location: `0x036 (54)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `AGC_AMP` at `0x036 (54)`

Locations: datasheet row(s) cited above <-> v1 `registers[7].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[7].field_parts[0].bit_field[0]` | `AGC_AMP` / `AGC_AMP` | "AGC measured amplitude used for AGC and AGC monitoring." / "AGC measured amplitude used for AGC and AGC monitoring." | `0:12` / `0:12` | `13` / `13` | "[]" / "[]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[7].field_parts[0].bit_field[1]` | `Not used` / `Not used` | "" / "" | `13:15` / `13:15` | `3` / `3` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `AGC_AMP`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 0.941694) = **0.970847**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `AGC_AMP` | `AGC_AMP` |
| `physical_address` | 0.4688 | 1.000000 | `0x036 (54), bank="", page=""` | `0x036 (54), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.956228 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.970847 = **0.956228**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.956228) = **0.956228**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `AGC_AMP` | `AGC_AMP` |
| `physical_address` | 0.4044 | 1.000000 | `0x036 (54), bank="", page=""` | `0x036 (54), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Reports the measured amplitude used for AGC and AGC monitoring.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.956228 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_8) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.956228 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.920233**.

## Extracted logical register 9: `TEMP`

v1 location: `registers[8]`; datasheet association: `TEMP` at `0x038`. Physical location: `0x038 (56)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `TEMP` at `0x038 (56)`

Locations: datasheet row(s) cited above <-> v1 `registers[8].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[8].field_parts[0].bit_field[0]` | `TEMP` / `TEMP` | "Temperature range [200.125:0.125:711] K." / "Temperature range [200.125:0.125:711] K." | `0:11` / `0:11` | `12` / `12` | "[]" / "[]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[8].field_parts[0].bit_field[1]` | `Not used` / `Not used` | "" / "" | `12:15` / `12:15` | `4` / `4` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `TEMP`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 0.941694) = **0.970847**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `TEMP` | `TEMP` |
| `physical_address` | 0.4688 | 1.000000 | `0x038 (56), bank="", page=""` | `0x038 (56), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.956228 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.970847 = **0.956228**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.956228) = **0.956228**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `TEMP` | `TEMP` |
| `physical_address` | 0.4044 | 1.000000 | `0x038 (56), bank="", page=""` | `0x038 (56), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Reports temperature over the stated range [200.125:0.125:711] K.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.956228 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_9) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.956228 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.920233**.

## Extracted logical register 10: `LIN_PHASE`

v1 location: `registers[9]`; datasheet association: `LIN_PHASE` at `0x03A`. Physical location: `0x03A (58)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `LIN_PHASE` at `0x03A (58)`

Locations: datasheet row(s) cited above <-> v1 `registers[9].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[9].field_parts[0].bit_field[0]` | `LIN_PHASE` / `LIN_PHASE` | "Angular value after linearization and before delay compensation; resolution 360/2^16 degrees." / "Angular value after linearization and before delay compensation; resolution 360/2^16 degrees." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `LIN_PHASE`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `LIN_PHASE` | `LIN_PHASE` |
| `physical_address` | 0.4688 | 1.000000 | `0x03A (58), bank="", page=""` | `0x03A (58), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `LIN_PHASE` | `LIN_PHASE` |
| `physical_address` | 0.4044 | 1.000000 | `0x03A (58), bank="", page=""` | `0x03A (58), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Contains the 16-bit angular value after linearization and before delay compensation, with resolution 360/2^16 degrees.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0000` | `0` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_10) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 11: `SPEED`

v1 location: `registers[10]`; datasheet association: `SPEED` at `0x03C`. Physical location: `0x03C (60)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SPEED` at `0x03C (60)`

Locations: datasheet row(s) cited above <-> v1 `registers[10].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[10].field_parts[0].bit_field[0]` | `SPEED` / `SPEED` | "Signed speed value; v[Hz] = signed(SPEED) / 2^22 * fac/26 and v[rpm] = v[Hz] * 60." / "Signed speed value; v[Hz] = signed(SPEED) / 2^22 * fac/26 and v[rpm] = v[Hz] * 60." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `SPEED`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SPEED` | `SPEED` |
| `physical_address` | 0.4688 | 1.000000 | `0x03C (60), bank="", page=""` | `0x03C (60), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SPEED` | `SPEED` |
| `physical_address` | 0.4044 | 1.000000 | `0x03C (60), bank="", page=""` | `0x03C (60), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Contains the signed 16-bit speed value. Conversion is v[Hz] = signed(SPEED) / 2^22 * fac/26 and v[rpm] = v[Hz] * 60; stated range is ±6009.43.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0000` | `0` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_11) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 12: `DRIFTC_PHASE`

v1 location: `registers[11]`; datasheet association: `DRIFTC_PHASE` at `0x042`. Physical location: `0x042 (66)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DRIFTC_PHASE` at `0x042 (66)`

Locations: datasheet row(s) cited above <-> v1 `registers[11].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[11].field_parts[0].bit_field[0]` | `DRIFTC_PHASE` / `DRIFTC_PHASE` | "Angular value after delay compensation and zero-point offset correction; resolution 360/2^16 degrees." / "Angular value after delay compensation and zero-point offset correction; resolution 360/2^16 degrees." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `DRIFTC_PHASE`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `DRIFTC_PHASE` | `DRIFTC_PHASE` |
| `physical_address` | 0.4688 | 1.000000 | `0x042 (66), bank="", page=""` | `0x042 (66), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `DRIFTC_PHASE` | `DRIFTC_PHASE` |
| `physical_address` | 0.4044 | 1.000000 | `0x042 (66), bank="", page=""` | `0x042 (66), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Contains the angular value after delay compensation and zero-point offset correction, with resolution 360/2^16 degrees.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0000` | `0` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_12) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 13: `SC_PHASE`

v1 location: `registers[12]`; datasheet association: `SC_PHASE` at `0x044`. Physical location: `0x044 (68)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SC_PHASE` at `0x044 (68)`

Locations: datasheet row(s) cited above <-> v1 `registers[12].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[12].field_parts[0].bit_field[0]` | `SC_PHASE` / `SC_PHASE` | "Angular value after signal conditioning." / "Angular value after signal conditioning." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `SC_PHASE`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SC_PHASE` | `SC_PHASE` |
| `physical_address` | 0.4688 | 1.000000 | `0x044 (68), bank="", page=""` | `0x044 (68), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SC_PHASE` | `SC_PHASE` |
| `physical_address` | 0.4044 | 1.000000 | `0x044 (68), bank="", page=""` | `0x044 (68), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Contains the angular value after signal conditioning.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0000` | `0` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_13) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 14: `GC_I`

v1 location: `registers[13]`; datasheet association: `GC_I` at `0x048`. Physical location: `0x048 (72)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GC_I` at `0x048 (72)`

Locations: datasheet row(s) cited above <-> v1 `registers[13].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[13].field_parts[0].bit_field[0]` | `GC_I` / `GC_I` | "Gain-compensated I component averaging result." / "Gain-compensated I component averaging result." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `GC_I`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `GC_I` | `GC_I` |
| `physical_address` | 0.4688 | 1.000000 | `0x048 (72), bank="", page=""` | `0x048 (72), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `GC_I` | `GC_I` |
| `physical_address` | 0.4044 | 1.000000 | `0x048 (72), bank="", page=""` | `0x048 (72), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Contains the averaged gain-compensated I component. Averaging is configured by DSP_GC_AVG; when averaging is enabled, reading GC_Q can trigger averaging and GC_I is available after tavg.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0000` | `0` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_14) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 15: `GC_Q`

v1 location: `registers[14]`; datasheet association: `GC_Q` at `0x04E`. Physical location: `0x04E (78)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `GC_Q` at `0x04E (78)`

Locations: datasheet row(s) cited above <-> v1 `registers[14].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[14].field_parts[0].bit_field[0]` | `GC_Q` / `GC_Q` | "Gain-compensated Q component averaging result." / "Gain-compensated Q component averaging result." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `GC_Q`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `GC_Q` | `GC_Q` |
| `physical_address` | 0.4688 | 1.000000 | `0x04E (78), bank="", page=""` | `0x04E (78), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `GC_Q` | `GC_Q` |
| `physical_address` | 0.4044 | 1.000000 | `0x04E (78), bank="", page=""` | `0x04E (78), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Contains the averaged gain-compensated Q component. When DSP_GC_AVG is greater than zero, reading GC_Q can trigger the start of averaging; averaged GC_I and GC_Q values are available after tavg.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0000` | `0` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_15) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 16: `RMM_ASIQ`

v1 location: `registers[15]`; datasheet association: `RMM_ASIQ` at `0x062`. Physical location: `0x062 (98)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `RMM_ASIQ` at `0x062 (98)`

Locations: datasheet row(s) cited above <-> v1 `registers[15].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[15].field_parts[0].bit_field[0]` | `RMM_ASIQ` / `RMM_ASIQ` | "Adaptive orthogonality correction value AS_IQ." / "Adaptive orthogonality correction value AS_IQ." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `RMM_ASIQ`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `RMM_ASIQ` | `RMM_ASIQ` |
| `physical_address` | 0.4688 | 1.000000 | `0x062 (98), bank="", page=""` | `0x062 (98), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `RMM_ASIQ` | `RMM_ASIQ` |
| `physical_address` | 0.4044 | 1.000000 | `0x062 (98), bank="", page=""` | `0x062 (98), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Reports the adaptive orthogonality correction value tracked by self-calibration.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `SC_IQ` | `SC_IQ` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_16) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 17: `RMM_ASQQ`

v1 location: `registers[16]`; datasheet association: `RMM_ASQQ` at `0x064`. Physical location: `0x064 (100)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `RMM_ASQQ` at `0x064 (100)`

Locations: datasheet row(s) cited above <-> v1 `registers[16].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[16].field_parts[0].bit_field[0]` | `RMM_ASQQ` / `RMM_ASQQ` | "Adaptive sensitivity correction value AS_SQ." / "Adaptive sensitivity correction value AS_SQ." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `RMM_ASQQ`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `RMM_ASQQ` | `RMM_ASQQ` |
| `physical_address` | 0.4688 | 1.000000 | `0x064 (100), bank="", page=""` | `0x064 (100), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `RMM_ASQQ` | `RMM_ASQQ` |
| `physical_address` | 0.4044 | 1.000000 | `0x064 (100), bank="", page=""` | `0x064 (100), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Reports the adaptive sensitivity correction value tracked by self-calibration.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `SC_QQ` | `SC_QQ` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_17) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 18: `PWM_PCNT`

v1 location: `registers[17]`; datasheet association: `PWM_PCNT` at `0x10A`. Physical location: `0x10A (266)`.
Datasheet source: pp.59-60, Tables 46-47; explanatory DSP text on p.18 where applicable.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PWM_PCNT` at `0x10A (266)`

Locations: datasheet row(s) cited above <-> v1 `registers[17].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[17].field_parts[0].bit_field[0]` | `PWM_PCNT` / `PWM_PCNT` | "PWM period counter when PWM_PCNT_ON = 1." / "PWM period counter when PWM_PCNT_ON = 1." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `R` / `R` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `PWM_PCNT`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PWM_PCNT` | `PWM_PCNT` |
| `physical_address` | 0.4688 | 1.000000 | `0x10A (266), bank="", page=""` | `0x10A (266), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `R` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PWM_PCNT` | `PWM_PCNT` |
| `physical_address` | 0.4044 | 1.000000 | `0x10A (266), bank="", page=""` | `0x10A (266), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Reports the PWM period counter when PWM_PCNT_ON is 1.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `R` | `R` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0000` | `0` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_18) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 19: `SENSING_MODE`

v1 location: `registers[18]`; datasheet association: `SENSING_MODE` at `0x200`. Physical location: `0x200 (512)`.
Datasheet source: p.60, Tables 48-49.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SENSING_MODE` at `0x200 (512)`

Locations: datasheet row(s) cited above <-> v1 `registers[18].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[18].field_parts[0].bit_field[0]` | `SENSING_MODE` / `SENSING_MODE` | "Magnetic sensing mode." / "Magnetic sensing mode." | `0:2` / `0:2` | `3` / `3` | "[0 -&gt; X-Y (default).; 1 -&gt; X-Z.; 2 -&gt; Y-Z.]" / "[0 -&gt; X-Y (default).; 1 -&gt; X-Z.; 2 -&gt; Y-Z.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[18].field_parts[0].bit_field[1]` | `GPIO_IF` / `GPIO_IF` | "GPIO protocol selection." / "GPIO protocol selection." | `3:4` / `3:4` | `2` / `2` | "[0 -&gt; PWM/Differential ABI or UVW.; 1 -&gt; SSI.; 2 -&gt; SPI bus mode.]" / "[0 -&gt; PWM/Differential ABI or UVW.; 1 -&gt; SSI.; 2 -&gt; SPI bus mode.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[18].field_parts[0].bit_field[2]` | `ABI_IF` / `ABI_IF` | "ABI/UVW protocol selection." / "ABI/UVW protocol selection." | `5:5` / `5:5` | `1` / `1` | "[0 -&gt; UVW.; 1 -&gt; ABI.]" / "[0 -&gt; UVW.; 1 -&gt; ABI.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF4 `registers[18].field_parts[0].bit_field[3]` | `ABI_DIFF` / `ABI_DIFF` | "ABI/UVW differential mode." / "ABI/UVW differential mode." | `6:6` / `6:6` | `1` / `1` | "[0 -&gt; Single-ended mode.; 1 -&gt; Differential mode.]" / "[0 -&gt; Single-ended mode.; 1 -&gt; Differential mode.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF5 `registers[18].field_parts[0].bit_field[4]` | `GPIO_CFG` / `GPIO_CFG` | "GPIO output driver strength and mode; GPIO_CFG[2:0] must not be changed for 5 V mode because it overrides factory trimming." / "GPIO output driver strength and mode; GPIO_CFG[2:0] must not be changed for 5 V mode because it overrides factory trimming." | `7:11` / `7:11` | `5` / `5` | "[GPIO_CFG[4:3] = 0 -&gt; Off.; GPIO_CFG[4:3] = 1 -&gt; Open-drain p-MOS.; GPIO_CFG[4:3] = 2 -&gt; Open-drain n-MOS.; GPIO_CFG[4:3] = 3 -&gt; Push-pull.]" / "[GPIO_CFG[4:3] = 0 -&gt; Off.; GPIO_CFG[4:3] = 1 -&gt; Open-drain p-MOS.; GPIO_CFG[4:3] = 2 -&gt; Open-drain n-MOS.; GPIO_CFG[4:3] = 3 -&gt; Push-pull.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF6 `registers[18].field_parts[0].bit_field[5]` | `Not used` / `Not used` | "" / "" | `12:15` / `12:15` | `4` / `4` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `SENSING_MODE`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `GPIO_IF`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `ABI_IF`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `ABI_DIFF`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `GPIO_CFG`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 0.941694) = **0.990282**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SENSING_MODE` | `SENSING_MODE` |
| `physical_address` | 0.4688 | 1.000000 | `0x200 (512), bank="", page=""` | `0x200 (512), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.962309 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.990282 = **0.962309**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.962309) = **0.962309**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SENSING_MODE` | `SENSING_MODE` |
| `physical_address` | 0.4044 | 1.000000 | `0x200 (512), bank="", page=""` | `0x200 (512), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures the magnetic sensing mode and GPIO interface, ABI/UVW protocol, differential mode, and GPIO output driver.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.962309 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0E30 (derived from SENSING_MODE=0, GPIO_IF=2, ABI_IF=1, ABI_DIFF=0, GPIO_CFG=28, Not used=0)` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_19) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.962309 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922050**.

## Extracted logical register 20: `ABI_CFG`

v1 location: `registers[19]`; datasheet association: `ABI_CFG` at `0x202`. Physical location: `0x202 (514)`.
Datasheet source: p.61, Table 49; p.63, Table 50.

### Bottom layer: bit fields, then field parts

#### Field part 1: `ABI_CFG` at `0x202 (514)`

Locations: datasheet row(s) cited above <-> v1 `registers[19].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[19].field_parts[0].bit_field[0]` | `ABI_CFG` / `ABI_CFG` | "ABI output driver strength and mode for the ABI single-ended port; ABI_CFG[2:0] must not be changed for 5 V mode because it overrides factory trimming." / "ABI output driver strength and mode for the ABI single-ended port; ABI_CFG[2:0] must not be changed for 5 V mode because it overrides factory trimming." | `0:4` / `0:4` | `5` / `5` | "[ABI_CFG[4:3] = 0 -&gt; Off.; ABI_CFG[4:3] = 1 -&gt; Open-drain p-MOS.; ABI_CFG[4:3] = 2 -&gt; Open-drain n-MOS.; ABI_CFG[4:3] = 3 -&gt; Push-pull.]" / "[ABI_CFG[4:3] = 0 -&gt; Off.; ABI_CFG[4:3] = 1 -&gt; Open-drain p-MOS.; ABI_CFG[4:3] = 2 -&gt; Open-drain n-MOS.; ABI_CFG[4:3] = 3 -&gt; Push-pull.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[19].field_parts[0].bit_field[1]` | `EH_MIN_SS_PERIOD` / `EH_MIN_SS_PERIOD` | "Minimum fail-safe-state period; refer to the MLX90382 Safety Manual for details." / "Minimum fail-safe-state period; refer to the MLX90382 Safety Manual for details." | `5:7` / `5:7` | `3` / `3` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[19].field_parts[0].bit_field[2]` | `Not used` / `Not used` | "" / "" | `12:15` / `12:15` | `4` / `4` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `ABI_CFG`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `EH_MIN_SS_PERIOD`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 1.000000, 0.941694) = **0.980565**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `ABI_CFG` | `ABI_CFG` |
| `physical_address` | 0.4688 | 1.000000 | `0x202 (514), bank="", page=""` | `0x202 (514), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 0.000000 | `16` | "" |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.898769 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x0.000000 + 0.0605x1.000000 + 0.3129x0.980565 = **0.898769**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.898769) = **0.898769**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `ABI_CFG` | `ABI_CFG` |
| `physical_address` | 0.4044 | 1.000000 | `0x202 (514), bank="", page=""` | `0x202 (514), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures the ABI single-ended output driver and minimum fail-safe-state period. Safety-related settings require impact analysis; consult the MLX90382 Safety Manual for EH_MIN_SS_PERIOD details.` |
| `width_bits` | 0.0590 | 0.000000 | `16` | "" |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.898769 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x005C (listed defaults only; datasheet Table 49 omits bits [11:8])` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_20) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x0.000000 + 0.0590x1.000000 + 0.2987x0.898769 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.844078**.

## Extracted logical register 21: `ABI_LOG2N`

v1 location: `registers[20]`; datasheet association: `ABI_LOG2N` at `0x204`. Physical location: `0x204 (516)`.
Datasheet source: p.61, Table 49.

### Bottom layer: bit fields, then field parts

#### Field part 1: `ABI_LOG2N` at `0x204 (516)`

Locations: datasheet row(s) cited above <-> v1 `registers[20].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[20].field_parts[0].bit_field[0]` | `ABI_LOG2N` / `ABI_LOG2N` | "ABI number of counts per revolution: 4 * 2^ABI_LOG2N." / "ABI number of counts per revolution: 4 * 2^ABI_LOG2N." | `0:3` / `0:3` | `4` / `4` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[20].field_parts[0].bit_field[1]` | `UVW_PP` / `UVW_PP` | "UVW pole pairs." / "UVW pole pairs." | `4:8` / `4:8` | `5` / `5` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[20].field_parts[0].bit_field[2]` | `ABIUVW_DIR` / `ABIUVW_DIR` | "ABI/UVW rotation direction." / "ABI/UVW rotation direction." | `9:9` / `9:9` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF4 `registers[20].field_parts[0].bit_field[3]` | `ABIUVW_HYS` / `ABIUVW_HYS` | "ABI/UVW hysteresis: ±floor(2^(ABIUVW_HYS-1))." / "ABI/UVW hysteresis: ±floor(2^(ABIUVW_HYS-1))." | `10:13` / `10:13` | `4` / `4` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF5 `registers[20].field_parts[0].bit_field[4]` | `ABI_I_LEN` / `ABI_I_LEN` | "ABI I-pulse length selection." / "ABI I-pulse length selection." | `14:14` / `14:14` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF6 `registers[20].field_parts[0].bit_field[5]` | `ABI_PORT` / `ABI_PORT` | "QFN-24 ABI/UVW pin group selection." / "QFN-24 ABI/UVW pin group selection." | `15:15` / `15:15` | `1` / `1` | "[0 -&gt; Select pin group AU_N, SCLK and MOSI.; 1 -&gt; Select pin group AU, BV and IW.]" / "[0 -&gt; Select pin group AU_N, SCLK and MOSI.; 1 -&gt; Select pin group AU, BV and IW.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `ABI_LOG2N`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `UVW_PP`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `ABIUVW_DIR`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `ABIUVW_HYS`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `ABI_I_LEN`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `ABI_PORT`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `ABI_LOG2N` | `ABI_LOG2N` |
| `physical_address` | 0.4688 | 1.000000 | `0x204 (516), bank="", page=""` | `0x204 (516), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `ABI_LOG2N` | `ABI_LOG2N` |
| `physical_address` | 0.4044 | 1.000000 | `0x204 (516), bank="", page=""` | `0x204 (516), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures ABI counts per revolution, UVW pole pairs, rotation direction, hysteresis, I-pulse length, and QFN-24 ABI/UVW pin group.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0xD803` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_21) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 22: `PWM_INV`

v1 location: `registers[21]`; datasheet association: `PWM_INV` at `0x206`. Physical location: `0x206 (518)`.
Datasheet source: p.61, Table 49.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PWM_INV` at `0x206 (518)`

Locations: datasheet row(s) cited above <-> v1 `registers[21].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[21].field_parts[0].bit_field[0]` | `PWM_INV` / `PWM_INV` | "PWM waveform inversion." / "PWM waveform inversion." | `0:0` / `0:0` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[21].field_parts[0].bit_field[1]` | `PWM_PCNT_ON` / `PWM_PCNT_ON` | "PWM period counter control." / "PWM period counter control." | `1:1` / `1:1` | `1` / `1` | "[0 -&gt; Period counter off.; 1 -&gt; PWM counter runs despite the GPIO_IF setting.]" / "[0 -&gt; Period counter off.; 1 -&gt; PWM counter runs despite the GPIO_IF setting.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[21].field_parts[0].bit_field[2]` | `Reserved` / `Reserved` | "Reserved, don't change." / "Reserved, don't change." | `2:7` / `2:7` | `6` / `6` | "[]" / "[]" | `True` / `True` | `RW` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |
| BF4 `registers[21].field_parts[0].bit_field[3]` | `Not used` / `Not used` | "" / "" | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `PWM_INV`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `PWM_PCNT_ON`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Reserved`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 1.000000, 0.941694, 0.941694) = **0.970847**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PWM_INV` | `PWM_INV` |
| `physical_address` | 0.4688 | 1.000000 | `0x206 (518), bank="", page=""` | `0x206 (518), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.956228 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.970847 = **0.956228**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.956228) = **0.956228**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PWM_INV` | `PWM_INV` |
| `physical_address` | 0.4044 | 1.000000 | `0x206 (518), bank="", page=""` | `0x206 (518), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures PWM waveform inversion and operation of the PWM period counter.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.956228 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x00F4` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_22) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.956228 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.920233**.

## Extracted logical register 23: `PWM_PERIOD`

v1 location: `registers[22]`; datasheet association: `PWM_PERIOD` at `0x22E`. Physical location: `0x22E (558)`.
Datasheet source: p.61, Table 49; PWM details on p.35.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PWM_PERIOD` at `0x22E (558)`

Locations: datasheet row(s) cited above <-> v1 `registers[22].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[22].field_parts[0].bit_field[0]` | `PWM_PERIOD` / `PWM_PERIOD` | "PWM period." / "PWM period." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `PWM_PERIOD`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PWM_PERIOD` | `PWM_PERIOD` |
| `physical_address` | 0.4688 | 1.000000 | `0x22E (558), bank="", page=""` | `0x22E (558), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PWM_PERIOD` | `PWM_PERIOD` |
| `physical_address` | 0.4044 | 1.000000 | `0x22E (558), bank="", page=""` | `0x22E (558), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures the PWM period.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0FFF` | `4095` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_23) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 24: `PWM_DC_OFS`

v1 location: `registers[23]`; datasheet association: `PWM_DC_OFS` at `0x248`. Physical location: `0x248 (584)`.
Datasheet source: pp.61,65, Tables 49 and 52; PWM details on p.35.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PWM_DC_OFS` at `0x248 (584)`

Locations: datasheet row(s) cited above <-> v1 `registers[23].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[23].field_parts[0].bit_field[0]` | `PWM_DC_OFS` / `PWM_DC_OFS` | "PWM duty-cycle offset trimming." / "PWM duty-cycle offset trimming." | `0:8` / `0:8` | `9` / `9` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[23].field_parts[0].bit_field[1]` | `Not used` / `Not used` | "" / "" | `9:15` / `9:15` | `7` / `7` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `PWM_DC_OFS`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 0.941694) = **0.970847**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PWM_DC_OFS` | `PWM_DC_OFS` |
| `physical_address` | 0.4688 | 1.000000 | `0x248 (584), bank="", page=""` | `0x248 (584), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.956228 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.970847 = **0.956228**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.956228) = **0.956228**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PWM_DC_OFS` | `PWM_DC_OFS` |
| `physical_address` | 0.4044 | 1.000000 | `0x248 (584), bank="", page=""` | `0x248 (584), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures PWM duty-cycle offset trimming.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.956228 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_24) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.956228 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.920233**.

## Extracted logical register 25: `SPI_FADDR0`

v1 location: `registers[24]`; datasheet association: `SPI_FADDR0` at `0x230`. Physical location: `0x230 (560)`.
Datasheet source: pp.61-63, Table 49; SPI/SSI interface text on pp.30-35.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SPI_FADDR0` at `0x230 (560)`

Locations: datasheet row(s) cited above <-> v1 `registers[24].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[24].field_parts[0].bit_field[0]` | `SPI_FADDR0` / `SPI_FADDR0` | "SPI Frame Read address 0." / "SPI Frame Read address 0." | `0:7` / `0:7` | `8` / `8` | "[0x00 -&gt; Transmit the angular value.]" / "[0x00 -&gt; Transmit the angular value.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[24].field_parts[0].bit_field[1]` | `SPI_FADDR1` / `SPI_FADDR1` | "SPI Frame Read address 1." / "SPI Frame Read address 1." | `8:15` / `8:15` | `8` / `8` | "[0x00 -&gt; Content is not transmitted and is not part of the frame.]" / "[0x00 -&gt; Content is not transmitted and is not part of the frame.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `SPI_FADDR0`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `SPI_FADDR1`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SPI_FADDR0` | `SPI_FADDR0` |
| `physical_address` | 0.4688 | 1.000000 | `0x230 (560), bank="", page=""` | `0x230 (560), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SPI_FADDR0` | `SPI_FADDR0` |
| `physical_address` | 0.4044 | 1.000000 | `0x230 (560), bank="", page=""` | `0x230 (560), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures Frame Read addresses 0 and 1. Setting SPI_FADDR0 to 0x00 transmits the angular value; SPI_FADDR1 set to 0x00 suppresses its content from the frame.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x3C00` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_25) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 26: `SPI_FADDR2`

v1 location: `registers[25]`; datasheet association: `SPI_FADDR2` at `0x232`. Physical location: `0x232 (562)`.
Datasheet source: pp.61-63, Table 49; SPI/SSI interface text on pp.30-35.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SPI_FADDR2` at `0x232 (562)`

Locations: datasheet row(s) cited above <-> v1 `registers[25].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[25].field_parts[0].bit_field[0]` | `SPI_FADDR2` / `SPI_FADDR2` | "SPI Frame Read address 2." / "SPI Frame Read address 2." | `0:7` / `0:7` | `8` / `8` | "[0x00 -&gt; Content is not transmitted and is not part of the frame.]" / "[0x00 -&gt; Content is not transmitted and is not part of the frame.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[25].field_parts[0].bit_field[1]` | `SPI_FADDR3` / `SPI_FADDR3` | "SPI Frame Read address 3." / "SPI Frame Read address 3." | `8:15` / `8:15` | `8` / `8` | "[0x00 -&gt; Content is not transmitted and is not part of the frame.]" / "[0x00 -&gt; Content is not transmitted and is not part of the frame.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `SPI_FADDR2`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `SPI_FADDR3`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SPI_FADDR2` | `SPI_FADDR2` |
| `physical_address` | 0.4688 | 1.000000 | `0x232 (562), bank="", page=""` | `0x232 (562), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SPI_FADDR2` | `SPI_FADDR2` |
| `physical_address` | 0.4044 | 1.000000 | `0x232 (562), bank="", page=""` | `0x232 (562), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures Frame Read addresses 2 and 3. A value of 0x00 for SPI_FADDR2 or SPI_FADDR3 omits that content from the frame.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_26) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 27: `SPI_FRFS`

v1 location: `registers[26]`; datasheet association: `SPI_FRFS` at `0x234`. Physical location: `0x234 (564)`.
Datasheet source: pp.61-63, Table 49; SPI/SSI interface text on pp.30-35.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SPI_FRFS` at `0x234 (564)`

Locations: datasheet row(s) cited above <-> v1 `registers[26].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[26].field_parts[0].bit_field[0]` | `SPI_FRFS` / `SPI_FRFS` | "SPI Frame Read frame-start pattern." / "SPI Frame Read frame-start pattern." | `0:3` / `0:3` | `4` / `4` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[26].field_parts[0].bit_field[1]` | `SPI_FRFSEN` / `SPI_FRFSEN` | "SPI Frame Read frame-start enable." / "SPI Frame Read frame-start enable." | `4:4` / `4:4` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[26].field_parts[0].bit_field[2]` | `SPI_FRCRCEN` / `SPI_FRCRCEN` | "SPI Frame Read CRC enable." / "SPI Frame Read CRC enable." | `5:5` / `5:5` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF4 `registers[26].field_parts[0].bit_field[3]` | `SPI_FRINV` / `SPI_FRINV` | "Selects Frame Read data bytes for binary inversion to support transmission-error detection." / "Selects Frame Read data bytes for binary inversion to support transmission-error detection." | `6:9` / `6:9` | `4` / `4` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF5 `registers[26].field_parts[0].bit_field[4]` | `SPI_MODE` / `SPI_MODE` | "SPI clock polarity and phase mode selection." / "SPI clock polarity and phase mode selection." | `10:11` / `10:11` | `2` / `2` | "[0 -&gt; CPOL = 0, CPHA = 0.; 1 -&gt; CPOL = 0, CPHA = 1.; 2 -&gt; CPOL = 1, CPHA = 0.; 3 -&gt; CPOL = 1, CPHA = 1.]" / "[0 -&gt; CPOL = 0, CPHA = 0.; 1 -&gt; CPOL = 0, CPHA = 1.; 2 -&gt; CPOL = 1, CPHA = 0.; 3 -&gt; CPOL = 1, CPHA = 1.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF6 `registers[26].field_parts[0].bit_field[5]` | `SPI_DMY` / `SPI_DMY` | "Optional output word-alignment dummy-byte controls: bit 13 adds a dummy byte after byte 2 in RR mode; bit 12 adds one after byte 2 in FR mode." / "Optional output word-alignment dummy-byte controls: bit 13 adds a dummy byte after byte 2 in RR mode; bit 12 adds one after byte 2 in FR mode." | `12:13` / `12:13` | `2` / `2` | "[SPI_DMY[13] = 1 -&gt; Add an additional dummy-byte transfer after byte 2 in RR mode.; SPI_DMY[12] = 1 -&gt; Add an additional dummy-byte transfer after byte 2 in FR mode.]" / "[SPI_DMY[13] = 1 -&gt; Add an additional dummy-byte transfer after byte 2 in RR mode.; SPI_DMY[12] = 1 -&gt; Add an additional dummy-byte transfer after byte 2 in FR mode.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF7 `registers[26].field_parts[0].bit_field[6]` | `Not used` / `Not used` | "" / "" | `14:15` / `14:15` | `2` / `2` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `SPI_FRFS`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `SPI_FRFSEN`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `SPI_FRCRCEN`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `SPI_FRINV`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `SPI_MODE`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `SPI_DMY`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 0.941694) = **0.991671**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SPI_FRFS` | `SPI_FRFS` |
| `physical_address` | 0.4688 | 1.000000 | `0x234 (564), bank="", page=""` | `0x234 (564), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.962744 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.991671 = **0.962744**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.962744) = **0.962744**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SPI_FRFS` | `SPI_FRFS` |
| `physical_address` | 0.4044 | 1.000000 | `0x234 (564), bank="", page=""` | `0x234 (564), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures the SPI Frame Read start pattern, optional frame-start and CRC bytes, data inversion, SPI mode, and optional dummy-byte alignment. The frame-start byte combines SPI_FRFS with a rolling counter.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.962744 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x003A` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_27) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.962744 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922179**.

## Extracted logical register 28: `SPI_SFRL`

v1 location: `registers[27]`; datasheet association: `SPI_SFRL` at `0x236`. Physical location: `0x236 (566)`.
Datasheet source: pp.61-63, Table 49; SPI/SSI interface text on pp.30-35.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SPI_SFRL` at `0x236 (566)`

Locations: datasheet row(s) cited above <-> v1 `registers[27].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[27].field_parts[0].bit_field[0]` | `SPI_SFRL` / `SPI_SFRL` | "SPI Super Frame length in bytes." / "SPI Super Frame length in bytes." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[27].field_parts[0].bit_field[1]` | `SPI_SFRDLY` / `SPI_SFRDLY` | "SPI Frame Read delay within the Super Frame, in bytes; default is 6 for Die 1 in TSSOP-16/TSSOP-16_EP." / "SPI Frame Read delay within the Super Frame, in bytes; default is 6 for Die 1 in TSSOP-16/TSSOP-16_EP." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `SPI_SFRL`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `SPI_SFRDLY`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SPI_SFRL` | `SPI_SFRL` |
| `physical_address` | 0.4688 | 1.000000 | `0x236 (566), bank="", page=""` | `0x236 (566), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SPI_SFRL` | `SPI_SFRL` |
| `physical_address` | 0.4044 | 1.000000 | `0x236 (566), bank="", page=""` | `0x236 (566), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures Super Frame length and the byte delay before a slave's Frame Read response within the Super Frame.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x000C` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_28) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 29: `SPI_CPTLT`

v1 location: `registers[28]`; datasheet association: `SPI_CPTLT` at `0x238`. Physical location: `0x238 (568)`.
Datasheet source: pp.61-63, Table 49; SPI/SSI interface text on pp.30-35.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SPI_CPTLT` at `0x238 (568)`

Locations: datasheet row(s) cited above <-> v1 `registers[28].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[28].field_parts[0].bit_field[0]` | `SPI_CPTLT` / `SPI_CPTLT` | "SPI synchronous capture lead time: (SPI_CPTLT + 1) * TSCLK before DATA(FADDR0)[15:8]." / "SPI synchronous capture lead time: (SPI_CPTLT + 1) * TSCLK before DATA(FADDR0)[15:8]." | `0:2` / `0:2` | `3` / `3` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[28].field_parts[0].bit_field[1]` | `SPI_SFR_SCPT` / `SPI_SFR_SCPT` | "Synchronizes angle capture on all slaves to the DATA(FADDR0)[15:8] position with SPI_SFRDLY = 0." / "Synchronizes angle capture on all slaves to the DATA(FADDR0)[15:8] position with SPI_SFRDLY = 0." | `3:3` / `3:3` | `1` / `1` | "[1 -&gt; synchronize angle capture time point on all slaves to DATA(FADDR0)[15:8] when SPI_SFRDLY=0; value 0 not enumerated in Table 49]" / "[0 -&gt; Angular position is captured before each slave's DATA(FADDR0)[15:8].; 1 -&gt; Capture is aligned with the first DATA(FADDR0)[15:8] byte in the Super Frame.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,0.5,1.0,1.0]` | 0.895140 |
| BF3 `registers[28].field_parts[0].bit_field[2]` | `SPI_DBNC_CS` / `SPI_DBNC_CS` | "SPI CS debounce filter; τCS = SPI_DBNC_CS * 2 / fRCO." / "SPI CS debounce filter; τCS = SPI_DBNC_CS * 2 / fRCO." | `4:7` / `4:7` | `4` / `4` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF4 `registers[28].field_parts[0].bit_field[3]` | `SPI_DBNC` / `SPI_DBNC` | "SPI SCLK/MOSI debounce filter; τSCLK/MOSI = SPI_DBNC / fRCO." / "SPI SCLK/MOSI debounce filter; τSCLK/MOSI = SPI_DBNC / fRCO." | `8:11` / `8:11` | `4` / `4` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF5 `registers[28].field_parts[0].bit_field[4]` | `Not used` / `Not used` | "" / "" | `12:15` / `12:15` | `4` / `4` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `SPI_CPTLT`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `SPI_SFR_SCPT`: C-vector `[1.0,1.0,1.0,1.0,1.0,0.5,1.0,1.0]`; Q_BF = 0.895140.
- `SPI_DBNC_CS`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `SPI_DBNC`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 0.895140, 1.000000, 1.000000, 0.941694) = **0.967367**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SPI_CPTLT` | `SPI_CPTLT` |
| `physical_address` | 0.4688 | 1.000000 | `0x238 (568), bank="", page=""` | `0x238 (568), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.955139 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.967367 = **0.955139**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.955139) = **0.955139**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SPI_CPTLT` | `SPI_CPTLT` |
| `physical_address` | 0.4044 | 1.000000 | `0x238 (568), bank="", page=""` | `0x238 (568), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures SPI angle-capture lead time, synchronized Super Frame capture, and CS/SCLK/MOSI debounce filtering. For Frame Read angle sampling, SPI_CPTLT must satisfy the documented timing requirement relative to fSCLK and fac.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.955139 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0008` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_29) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.955139 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.919908**.

## Extracted logical register 30: `SSI_PARPOS`

v1 location: `registers[29]`; datasheet association: `SSI_PARPOS` at `0x23A`. Physical location: `0x23A (570)`.
Datasheet source: pp.61-63, Table 49; SPI/SSI interface text on pp.30-35.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SSI_PARPOS` at `0x23A (570)`

Locations: datasheet row(s) cited above <-> v1 `registers[29].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[29].field_parts[0].bit_field[0]` | `SSI_PARPOS` / `SSI_PARPOS` | "SSI odd-parity bit position; values ≤8 select parity of angle[15:SSI_PARPOS+1], while values &gt;8 disable the parity bit and transmit angle[15:0]." / "SSI odd-parity bit position; values ≤8 select parity of angle[15:SSI_PARPOS+1], while values &gt;8 disable the parity bit and transmit angle[15:0]." | `0:3` / `0:3` | `4` / `4` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[29].field_parts[0].bit_field[1]` | `SSI_TM` / `SSI_TM` | "SSI timeout, TM = (SSI_TM + 1) * 8 / fac." / "SSI timeout, TM = (SSI_TM + 1) * 8 / fac." | `4:11` / `4:11` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[29].field_parts[0].bit_field[2]` | `SSI_CPT` / `SSI_CPT` | "SSI DSP output capture-point selection." / "SSI DSP output capture-point selection." | `12:12` / `12:12` | `1` / `1` | "[0 -&gt; Capture at the first falling edge of SCLK; Table 35 states SCLK ≤ 2 MHz.; 1 -&gt; Capture after TM / at the configured pause-pulse timing.]" / "[0 -&gt; Capture at the first falling edge of SCLK; Table 35 states SCLK ≤ 2 MHz.; 1 -&gt; Capture after TM / at the configured pause-pulse timing.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF4 `registers[29].field_parts[0].bit_field[3]` | `Not used` / `Not used` | "" / "" | `13:15` / `13:15` | `3` / `3` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `SSI_PARPOS`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `SSI_TM`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `SSI_CPT`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 1.000000, 1.000000, 0.941694) = **0.985424**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SSI_PARPOS` | `SSI_PARPOS` |
| `physical_address` | 0.4688 | 1.000000 | `0x23A (570), bank="", page=""` | `0x23A (570), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.960789 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.985424 = **0.960789**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.960789) = **0.960789**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SSI_PARPOS` | `SSI_PARPOS` |
| `physical_address` | 0.4044 | 1.000000 | `0x23A (570), bank="", page=""` | `0x23A (570), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures SSI odd-parity placement, timeout, and DSP output capture timing.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.960789 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x1000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_30) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.960789 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.921596**.

## Extracted logical register 31: `PHY_RC_EN`

v1 location: `registers[30]`; datasheet association: `PHY_RC_EN` at `0x23C`. Physical location: `0x23C (572)`.
Datasheet source: pp.61-63, Table 49; SPI/SSI interface text on pp.30-35.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PHY_RC_EN` at `0x23C (572)`

Locations: datasheet row(s) cited above <-> v1 `registers[30].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[30].field_parts[0].bit_field[0]` | `PHY_RC_EN` / `PHY_RC_EN` | "EMC RC filter enable: bit 0 for CS, bit 1 for IW/MOSI, and bit 2 for BV/SCLK according to package." / "EMC RC filter enable: bit 0 for CS, bit 1 for IW/MOSI, and bit 2 for BV/SCLK according to package." | `0:2` / `0:2` | `3` / `3` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[30].field_parts[0].bit_field[1]` | `PHY_CS_RPU_DIS` / `PHY_CS_RPU_DIS` | "CS pin pull-up disable." / "CS pin pull-up disable." | `3:3` / `3:3` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[30].field_parts[0].bit_field[2]` | `PHY_BV_RPU_DIS` / `PHY_BV_RPU_DIS` | "BV pad pull-up disable (SCK)." / "BV pad pull-up disable (SCK)." | `4:4` / `4:4` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF4 `registers[30].field_parts[0].bit_field[3]` | `Reserved` / `Reserved` | "Reserved, don't change." / "Reserved, don't change." | `5:6` / `5:6` | `2` / `2` | "[]" / "[]" | `True` / `True` | `RW` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |
| BF5 `registers[30].field_parts[0].bit_field[4]` | `Not used` / `Not used` | "" / "" | `7:15` / `7:15` | `9` / `9` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `PHY_RC_EN`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `PHY_CS_RPU_DIS`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `PHY_BV_RPU_DIS`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Reserved`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 1.000000, 1.000000, 0.941694, 0.941694) = **0.976678**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PHY_RC_EN` | `PHY_RC_EN` |
| `physical_address` | 0.4688 | 1.000000 | `0x23C (572), bank="", page=""` | `0x23C (572), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.958052 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.976678 = **0.958052**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.958052) = **0.958052**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PHY_RC_EN` | `PHY_RC_EN` |
| `physical_address` | 0.4044 | 1.000000 | `0x23C (572), bank="", page=""` | `0x23C (572), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures interface-pin EMC RC filters and pull-ups.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.958052 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_31) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.958052 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.920778**.

## Extracted logical register 32: `SC_YE`

v1 location: `registers[31]`; datasheet association: `SC_YE` at `0x22A`. Physical location: `0x22A (554)`.
Datasheet source: p.63, Table 50; p.65, Table 52; explanatory signal-conditioning text on p.22.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SC_YE` at `0x22A (554)`

Locations: datasheet row(s) cited above <-> v1 `registers[31].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[31].field_parts[0].bit_field[0]` | `SC_YE` / `SC_YE` | "Signal-conditioning output fault-band level in SS3." / "Signal-conditioning output fault-band level in SS3." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `SC_YE`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SC_YE` | `SC_YE` |
| `physical_address` | 0.4688 | 1.000000 | `0x22A (554), bank="", page=""` | `0x22A (554), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SC_YE` | `SC_YE` |
| `physical_address` | 0.4044 | 1.000000 | `0x22A (554), bank="", page=""` | `0x22A (554), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Defines the signal-conditioning output fault-band level. Angular output values inside this band assert fail-safe state SS3; consult the MLX90382 Safety Manual for SS3 details.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x7FFE` | `32766` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_32) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 33: `DIAG_TEMP_THD_LO`

v1 location: `registers[32]`; datasheet association: `DIAG_TEMP_THD_LO` at `0x24A`. Physical location: `0x24A (586)`.
Datasheet source: pp.63-64, Table 50.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DIAG_TEMP_THD_LO` at `0x24A (586)`

Locations: datasheet row(s) cited above <-> v1 `registers[32].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[32].field_parts[0].bit_field[0]` | `DIAG_TEMP_THD_LO` / `DIAG_TEMP_THD_LO` | "Under-temperature diagnostic threshold, unit 2 K." / "Under-temperature diagnostic threshold, unit 2 K." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[32].field_parts[0].bit_field[1]` | `DIAG_TEMP_THD_HI` / `DIAG_TEMP_THD_HI` | "Over-temperature diagnostic threshold, unit 2 K." / "Over-temperature diagnostic threshold, unit 2 K." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `DIAG_TEMP_THD_LO`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DIAG_TEMP_THD_HI`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `DIAG_TEMP_THD_LO` | `DIAG_TEMP_THD_LO` |
| `physical_address` | 0.4688 | 1.000000 | `0x24A (586), bank="", page=""` | `0x24A (586), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `DIAG_TEMP_THD_LO` | `DIAG_TEMP_THD_LO` |
| `physical_address` | 0.4044 | 1.000000 | `0x24A (586), bank="", page=""` | `0x24A (586), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures under-temperature and over-temperature diagnostic thresholds in units of 2 K.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x750E` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_33) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 34: `DIAG_TEMP_THD_MAX`

v1 location: `registers[33]`; datasheet association: `DIAG_TEMP_THD_MAX` at `0x24C`. Physical location: `0x24C (588)`.
Datasheet source: pp.63-64, Table 50.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DIAG_TEMP_THD_MAX` at `0x24C (588)`

Locations: datasheet row(s) cited above <-> v1 `registers[33].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[33].field_parts[0].bit_field[0]` | `DIAG_TEMP_THD_MAX` / `DIAG_TEMP_THD_MAX` | "Maximum-temperature diagnostic threshold, unit 2 K." / "Maximum-temperature diagnostic threshold, unit 2 K." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[33].field_parts[0].bit_field[1]` | `Reserved` / `Reserved` | "Reserved, don't change." / "Reserved, don't change." | `8:8` / `8:8` | `1` / `1` | "[]" / "[]" | `True` / `True` | `RW` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |
| BF3 `registers[33].field_parts[0].bit_field[2]` | `Not used` / `Not used` | "" / "" | `9:15` / `9:15` | `7` / `7` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `DIAG_TEMP_THD_MAX`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Reserved`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 0.941694, 0.941694) = **0.961129**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `DIAG_TEMP_THD_MAX` | `DIAG_TEMP_THD_MAX` |
| `physical_address` | 0.4688 | 1.000000 | `0x24C (588), bank="", page=""` | `0x24C (588), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.953187 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.961129 = **0.953187**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.953187) = **0.953187**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `DIAG_TEMP_THD_MAX` | `DIAG_TEMP_THD_MAX` |
| `physical_address` | 0.4044 | 1.000000 | `0x24C (588), bank="", page=""` | `0x24C (588), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures the maximum-temperature diagnostic threshold in units of 2 K.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.953187 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x007A` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_34) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.953187 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.919325**.

## Extracted logical register 35: `DIAG_SPEED_THD`

v1 location: `registers[34]`; datasheet association: `DIAG_SPEED_THD` at `0x24E`. Physical location: `0x24E (590)`.
Datasheet source: pp.63-64, Table 50.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DIAG_SPEED_THD` at `0x24E (590)`

Locations: datasheet row(s) cited above <-> v1 `registers[34].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[34].field_parts[0].bit_field[0]` | `DIAG_SPEED_THD` / `DIAG_SPEED_THD` | "Speed monitoring limit." / "Speed monitoring limit." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[34].field_parts[0].bit_field[1]` | `DIAG_ALF_THD` / `DIAG_ALF_THD` | "Phase tracking error limit." / "Phase tracking error limit." | `8:10` / `8:10` | `3` / `3` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[34].field_parts[0].bit_field[2]` | `Not used` / `Not used` | "" / "" | `11:15` / `11:15` | `5` / `5` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `DIAG_SPEED_THD`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DIAG_ALF_THD`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 1.000000, 0.941694) = **0.980565**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `DIAG_SPEED_THD` | `DIAG_SPEED_THD` |
| `physical_address` | 0.4688 | 1.000000 | `0x24E (590), bank="", page=""` | `0x24E (590), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.959269 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.980565 = **0.959269**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.959269) = **0.959269**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `DIAG_SPEED_THD` | `DIAG_SPEED_THD` |
| `physical_address` | 0.4044 | 1.000000 | `0x24E (590), bank="", page=""` | `0x24E (590), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures the speed-monitoring and phase-tracking-error limits.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.959269 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x02FE` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_35) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.959269 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.921141**.

## Extracted logical register 36: `DIAG_AGC_THD_LO`

v1 location: `registers[35]`; datasheet association: `DIAG_AGC_THD_LO` at `0x252`. Physical location: `0x252 (594)`.
Datasheet source: pp.63-64, Table 50.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DIAG_AGC_THD_LO` at `0x252 (594)`

Locations: datasheet row(s) cited above <-> v1 `registers[35].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[35].field_parts[0].bit_field[0]` | `DIAG_AGC_THD_LO` / `DIAG_AGC_THD_LO` | "AGC monitoring lower bound." / "AGC monitoring lower bound." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[35].field_parts[0].bit_field[1]` | `DIAG_AGC_THD_HI` / `DIAG_AGC_THD_HI` | "AGC monitoring upper bound." / "AGC monitoring upper bound." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `DIAG_AGC_THD_LO`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DIAG_AGC_THD_HI`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `DIAG_AGC_THD_LO` | `DIAG_AGC_THD_LO` |
| `physical_address` | 0.4688 | 1.000000 | `0x252 (594), bank="", page=""` | `0x252 (594), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `DIAG_AGC_THD_LO` | `DIAG_AGC_THD_LO` |
| `physical_address` | 0.4044 | 1.000000 | `0x252 (594), bank="", page=""` | `0x252 (594), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures lower and upper AGC monitoring limits.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0xFA02` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_36) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 37: `DE_OV_VDD`

v1 location: `registers[36]`; datasheet association: `DE_OV_VDD` at `0x25A`. Physical location: `0x25A (602)`.
Datasheet source: pp.63-64, Table 50.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DE_OV_VDD` at `0x25A (602)`

Locations: datasheet row(s) cited above <-> v1 `registers[36].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[36].field_parts[0].bit_field[0]` | `DE_OV_VDD` / `DE_OV_VDD` | "Disable VDD overvoltage monitor." / "Disable VDD overvoltage monitor." | `0:0` / `0:0` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[36].field_parts[0].bit_field[1]` | `DE_UV_VDD` / `DE_UV_VDD` | "Disable VDD undervoltage monitor." / "Disable VDD undervoltage monitor." | `1:1` / `1:1` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[36].field_parts[0].bit_field[2]` | `DE_OV_VDDD` / `DE_OV_VDDD` | "Disable VDDD overvoltage monitor." / "Disable VDDD overvoltage monitor." | `2:2` / `2:2` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF4 `registers[36].field_parts[0].bit_field[3]` | `DE_VDDA` / `DE_VDDA` | "Disable VDDA over-/undervoltage monitor." / "Disable VDDA over-/undervoltage monitor." | `3:3` / `3:3` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF5 `registers[36].field_parts[0].bit_field[4]` | `DE_VAUX` / `DE_VAUX` | "Disable VAUX over-/undervoltage monitor." / "Disable VAUX over-/undervoltage monitor." | `4:4` / `4:4` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF6 `registers[36].field_parts[0].bit_field[5]` | `DE_AGC` / `DE_AGC` | "Disable AGC monitor." / "Disable AGC monitor." | `5:5` / `5:5` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF7 `registers[36].field_parts[0].bit_field[6]` | `DE_DSP` / `DE_DSP` | "Disable DSP-related monitor." / "Disable DSP-related monitor." | `6:6` / `6:6` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF8 `registers[36].field_parts[0].bit_field[7]` | `DE_RCO` / `DE_RCO` | "Disable RCO monitor." / "Disable RCO monitor." | `7:7` / `7:7` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF9 `registers[36].field_parts[0].bit_field[8]` | `DE_ADC_LIN` / `DE_ADC_LIN` | "Disable ADC linearity monitor." / "Disable ADC linearity monitor." | `8:8` / `8:8` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF10 `registers[36].field_parts[0].bit_field[9]` | `DE_ADC` / `DE_ADC` | "Disable ADC monitor." / "Disable ADC monitor." | `9:9` / `9:9` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF11 `registers[36].field_parts[0].bit_field[10]` | `DE_ADC_OVF` / `DE_ADC_OVF` | "Disable ADC overflow monitor." / "Disable ADC overflow monitor." | `10:10` / `10:10` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF12 `registers[36].field_parts[0].bit_field[11]` | `DE_AFE_REF` / `DE_AFE_REF` | "Disable AFE reference monitor." / "Disable AFE reference monitor." | `11:11` / `11:11` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF13 `registers[36].field_parts[0].bit_field[12]` | `DE_TEMP` / `DE_TEMP` | "Disable over/under-temperature monitor." / "Disable over/under-temperature monitor." | `12:12` / `12:12` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF14 `registers[36].field_parts[0].bit_field[13]` | `DE_TEMP_MAX` / `DE_TEMP_MAX` | "Disable maximum-temperature monitor." / "Disable maximum-temperature monitor." | `13:13` / `13:13` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF15 `registers[36].field_parts[0].bit_field[14]` | `DE_SPEED` / `DE_SPEED` | "Disable speed monitor." / "Disable speed monitor." | `14:14` / `14:14` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF16 `registers[36].field_parts[0].bit_field[15]` | `DE_DSP_ALF` / `DE_DSP_ALF` | "Disable DSP ALF monitor." / "Disable DSP ALF monitor." | `15:15` / `15:15` | `1` / `1` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `DE_OV_VDD`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_UV_VDD`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_OV_VDDD`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_VDDA`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_VAUX`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_AGC`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_DSP`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_RCO`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_ADC_LIN`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_ADC`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_ADC_OVF`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_AFE_REF`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_TEMP`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_TEMP_MAX`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_SPEED`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DE_DSP_ALF`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `DE_OV_VDD` | `DE_OV_VDD` |
| `physical_address` | 0.4688 | 1.000000 | `0x25A (602), bank="", page=""` | `0x25A (602), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `DE_OV_VDD` | `DE_OV_VDD` |
| `physical_address` | 0.4044 | 1.000000 | `0x25A (602), bank="", page=""` | `0x25A (602), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Disables selected voltage, AGC, DSP, oscillator, ADC, AFE, temperature, and speed safety monitors. These settings affect safety hardware metrics and must not be modified without impact analysis; consult the MLX90382 Safety Manual.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_37) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 38: `CUS_CRC`

v1 location: `registers[37]`; datasheet association: `CUS_CRC` at `0x25E`. Physical location: `0x25E (606)`.
Datasheet source: p.64, Table 51.

### Bottom layer: bit fields, then field parts

#### Field part 1: `CUS_CRC` at `0x25E (606)`

Locations: datasheet row(s) cited above <-> v1 `registers[37].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[37].field_parts[0].bit_field[0]` | `CUS_CRC` / `CUS_CRC` | "CUS area checksum (CRC16 CCITT)." / "CUS area checksum (CRC16 CCITT)." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `CUS_CRC`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `CUS_CRC` | `CUS_CRC` |
| `physical_address` | 0.4688 | 1.000000 | `0x25E (606), bank="", page=""` | `0x25E (606), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `CUS_CRC` | `CUS_CRC` |
| `physical_address` | 0.4044 | 1.000000 | `0x25E (606), bank="", page=""` | `0x25E (606), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Contains the customer-area CRC16-CCITT checksum.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `N/A` | `N/A` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_38) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 39: `USER_ID0`

v1 location: `registers[38]`; datasheet association: `USER_ID0` at `0x23E`. Physical location: `0x23E (574)`.
Datasheet source: p.64, Table 51.

### Bottom layer: bit fields, then field parts

#### Field part 1: `USER_ID0` at `0x23E (574)`

Locations: datasheet row(s) cited above <-> v1 `registers[38].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[38].field_parts[0].bit_field[0]` | `USER_ID0` / `USER_ID0` | "Reserved for customers for traceability." / "Reserved for customers for traceability." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[38].field_parts[0].bit_field[1]` | `USER_ID1` / `USER_ID1` | "Reserved for customers for traceability." / "Reserved for customers for traceability." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `USER_ID0`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `USER_ID1`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `USER_ID0` | `USER_ID0` |
| `physical_address` | 0.4688 | 1.000000 | `0x23E (574), bank="", page=""` | `0x23E (574), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `USER_ID0` | `USER_ID0` |
| `physical_address` | 0.4044 | 1.000000 | `0x23E (574), bank="", page=""` | `0x23E (574), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Stores customer-reserved traceability identifiers USER_ID0 and USER_ID1.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_39) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 40: `USER_ID2`

v1 location: `registers[39]`; datasheet association: `USER_ID2` at `0x240`. Physical location: `0x240 (576)`.
Datasheet source: p.64, Table 51.

### Bottom layer: bit fields, then field parts

#### Field part 1: `USER_ID2` at `0x240 (576)`

Locations: datasheet row(s) cited above <-> v1 `registers[39].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[39].field_parts[0].bit_field[0]` | `USER_ID2` / `USER_ID2` | "Reserved for customers for traceability." / "Reserved for customers for traceability." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[39].field_parts[0].bit_field[1]` | `USER_ID3` / `USER_ID3` | "Reserved for customers for traceability." / "Reserved for customers for traceability." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `USER_ID2`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `USER_ID3`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `USER_ID2` | `USER_ID2` |
| `physical_address` | 0.4688 | 1.000000 | `0x240 (576), bank="", page=""` | `0x240 (576), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `USER_ID2` | `USER_ID2` |
| `physical_address` | 0.4044 | 1.000000 | `0x240 (576), bank="", page=""` | `0x240 (576), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Stores customer-reserved traceability identifiers USER_ID2 and USER_ID3.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_40) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 41: `USER_ID4`

v1 location: `registers[40]`; datasheet association: `USER_ID4` at `0x242`. Physical location: `0x242 (578)`.
Datasheet source: p.64, Table 51.

### Bottom layer: bit fields, then field parts

#### Field part 1: `USER_ID4` at `0x242 (578)`

Locations: datasheet row(s) cited above <-> v1 `registers[40].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[40].field_parts[0].bit_field[0]` | `USER_ID4` / `USER_ID4` | "Reserved for customers for traceability." / "Reserved for customers for traceability." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[40].field_parts[0].bit_field[1]` | `USER_ID5` / `USER_ID5` | "Reserved for customers for traceability." / "Reserved for customers for traceability." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `USER_ID4`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `USER_ID5`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `USER_ID4` | `USER_ID4` |
| `physical_address` | 0.4688 | 1.000000 | `0x242 (578), bank="", page=""` | `0x242 (578), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `USER_ID4` | `USER_ID4` |
| `physical_address` | 0.4044 | 1.000000 | `0x242 (578), bank="", page=""` | `0x242 (578), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Stores customer-reserved traceability identifiers USER_ID4 and USER_ID5.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.500000 | `partial: USER_ID4=0, USER_ID5=N/A` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_41) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.500000 + 0.0334x1.000000) / 1.0001 = **0.956304**.

## Extracted logical register 42: `AGC_GAIN_MIN`

v1 location: `registers[41]`; datasheet association: `AGC_GAIN_MIN` at `0x208`. Physical location: `0x208 (520)`.
Datasheet source: pp.64-65, Table 52; explanatory linearization text on pp.20-21.

### Bottom layer: bit fields, then field parts

#### Field part 1: `AGC_GAIN_MIN` at `0x208 (520)`

Locations: datasheet row(s) cited above <-> v1 `registers[41].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[41].field_parts[0].bit_field[0]` | `AGC_GAIN_MIN` / `AGC_GAIN_MIN` | "AGC minimum gain, range 0..63; values above 47 LSB are treated as 63 LSB." / "AGC minimum gain, range 0..63; values above 47 LSB are treated as 63 LSB." | `0:5` / `0:5` | `6` / `6` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[41].field_parts[0].bit_field[1]` | `AGC_GAIN_MAX` / `AGC_GAIN_MAX` | "AGC maximum gain, range 0..63; values above 47 LSB are treated as 63 LSB." / "AGC maximum gain, range 0..63; values above 47 LSB are treated as 63 LSB." | `6:11` / `6:11` | `6` / `6` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[41].field_parts[0].bit_field[2]` | `Not used` / `Not used` | "" / "" | `12:15` / `12:15` | `4` / `4` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `AGC_GAIN_MIN`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `AGC_GAIN_MAX`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 1.000000, 0.941694) = **0.980565**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `AGC_GAIN_MIN` | `AGC_GAIN_MIN` |
| `physical_address` | 0.4688 | 1.000000 | `0x208 (520), bank="", page=""` | `0x208 (520), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.959269 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.980565 = **0.959269**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.959269) = **0.959269**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `AGC_GAIN_MIN` | `AGC_GAIN_MIN` |
| `physical_address` | 0.4044 | 1.000000 | `0x208 (520), bank="", page=""` | `0x208 (520), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures minimum and maximum AGC gain. Each field ranges from 0 to 63; values above 47 LSB are treated as 63 LSB.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.959269 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0FC0` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_42) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.959269 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.921141**.

## Extracted logical register 43: `PEQ_GAIN`

v1 location: `registers[42]`; datasheet association: `PEQ_GAIN` at `0x20A`. Physical location: `0x20A (522)`.
Datasheet source: pp.64-65, Table 52; explanatory linearization text on pp.20-21.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PEQ_GAIN` at `0x20A (522)`

Locations: datasheet row(s) cited above <-> v1 `registers[42].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[42].field_parts[0].bit_field[0]` | `PEQ_GAIN` / `PEQ_GAIN` | "Linearization gain controlling phase offsets per reference point." / "Linearization gain controlling phase offsets per reference point." | `0:2` / `0:2` | `3` / `3` | "[0 -&gt; No equalization; phase offsets are 0.; 1 -&gt; Resolution 0.0055 deg; range ±0.70 deg.; 2 -&gt; Resolution 0.011 deg; range ±1.40 deg.; 3 -&gt; Resolution 0.022 deg; range ±2.79 deg.; 4 -&gt; Resolution 0.044 deg; range ±5.58 deg.; 5 -&gt; Resolution 0.088 deg; range ±11.16 deg.; 6 -&gt; Resolution 0.176 deg; range ±22.32 deg.; 7 -&gt; Resolution 0.352 deg; range ±44.65 deg.]" / "[0 -&gt; No equalization; phase offsets are 0.; 1 -&gt; Resolution 0.0055 deg; range ±0.70 deg.; 2 -&gt; Resolution 0.011 deg; range ±1.40 deg.; 3 -&gt; Resolution 0.022 deg; range ±2.79 deg.; 4 -&gt; Resolution 0.044 deg; range ±5.58 deg.; 5 -&gt; Resolution 0.088 deg; range ±11.16 deg.; 6 -&gt; Resolution 0.176 deg; range ±22.32 deg.; 7 -&gt; Resolution 0.352 deg; range ±44.65 deg.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[42].field_parts[0].bit_field[1]` | `Not used` / `Not used` | "" / "" | `3:15` / `3:15` | `13` / `13` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `PEQ_GAIN`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 0.941694) = **0.970847**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PEQ_GAIN` | `PEQ_GAIN` |
| `physical_address` | 0.4688 | 1.000000 | `0x20A (522), bank="", page=""` | `0x20A (522), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.956228 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.970847 = **0.956228**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.956228) = **0.956228**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PEQ_GAIN` | `PEQ_GAIN` |
| `physical_address` | 0.4044 | 1.000000 | `0x20A (522), bank="", page=""` | `0x20A (522), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Controls 16-point angular linearization strength. PEQ_GAIN = 0 disables equalization; for values 1..7, Δφ(xx) = signed(PEQxx[7:0]) * 2^(PEQ_GAIN-17) * 360 degrees, with range and resolution detailed in Table 22.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.956228 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_43) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.956228 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.920233**.

## Extracted logical register 44: `PEQ00`

v1 location: `registers[43]`; datasheet association: `PEQ00` at `0x20C`. Physical location: `0x20C (524)`.
Datasheet source: pp.64-65, Table 52; explanatory linearization text on pp.20-21.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PEQ00` at `0x20C (524)`

Locations: datasheet row(s) cited above <-> v1 `registers[43].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[43].field_parts[0].bit_field[0]` | `PEQ00` / `PEQ00` | "Phase Equalizer value at 0/16 * 360 degrees." / "Phase Equalizer value at 0/16 * 360 degrees." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[43].field_parts[0].bit_field[1]` | `PEQ01` / `PEQ01` | "Phase Equalizer value at 1/16 * 360 degrees." / "Phase Equalizer value at 1/16 * 360 degrees." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `PEQ00`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `PEQ01`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PEQ00` | `PEQ00` |
| `physical_address` | 0.4688 | 1.000000 | `0x20C (524), bank="", page=""` | `0x20C (524), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PEQ00` | `PEQ00` |
| `physical_address` | 0.4044 | 1.000000 | `0x20C (524), bank="", page=""` | `0x20C (524), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Stores signed 8-bit phase-equalizer values at angular sample points 0/16 and 1/16 of 360 degrees. Intermediate equalization values are linearly interpolated and scaled by PEQ_GAIN.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_44) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 45: `PEQ02`

v1 location: `registers[44]`; datasheet association: `PEQ02` at `0x20E`. Physical location: `0x20E (526)`.
Datasheet source: pp.64-65, Table 52; explanatory linearization text on pp.20-21.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PEQ02` at `0x20E (526)`

Locations: datasheet row(s) cited above <-> v1 `registers[44].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[44].field_parts[0].bit_field[0]` | `PEQ02` / `PEQ02` | "Phase Equalizer value at 2/16 * 360 degrees." / "Phase Equalizer value at 2/16 * 360 degrees." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[44].field_parts[0].bit_field[1]` | `PEQ03` / `PEQ03` | "Phase Equalizer value at 3/16 * 360 degrees." / "Phase Equalizer value at 3/16 * 360 degrees." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `PEQ02`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `PEQ03`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PEQ02` | `PEQ02` |
| `physical_address` | 0.4688 | 1.000000 | `0x20E (526), bank="", page=""` | `0x20E (526), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PEQ02` | `PEQ02` |
| `physical_address` | 0.4044 | 1.000000 | `0x20E (526), bank="", page=""` | `0x20E (526), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Stores signed 8-bit phase-equalizer values at angular sample points 2/16 and 3/16 of 360 degrees, scaled by PEQ_GAIN.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_45) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 46: `PEQ04`

v1 location: `registers[45]`; datasheet association: `PEQ04` at `0x210`. Physical location: `0x210 (528)`.
Datasheet source: pp.64-65, Table 52; explanatory linearization text on pp.20-21.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PEQ04` at `0x210 (528)`

Locations: datasheet row(s) cited above <-> v1 `registers[45].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[45].field_parts[0].bit_field[0]` | `PEQ04` / `PEQ04` | "Phase Equalizer value at 4/16 * 360 degrees." / "Phase Equalizer value at 4/16 * 360 degrees." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[45].field_parts[0].bit_field[1]` | `PEQ05` / `PEQ05` | "Phase Equalizer value at 5/16 * 360 degrees." / "Phase Equalizer value at 5/16 * 360 degrees." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `PEQ04`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `PEQ05`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PEQ04` | `PEQ04` |
| `physical_address` | 0.4688 | 1.000000 | `0x210 (528), bank="", page=""` | `0x210 (528), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PEQ04` | `PEQ04` |
| `physical_address` | 0.4044 | 1.000000 | `0x210 (528), bank="", page=""` | `0x210 (528), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Stores signed 8-bit phase-equalizer values at angular sample points 4/16 and 5/16 of 360 degrees, scaled by PEQ_GAIN.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_46) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 47: `PEQ06`

v1 location: `registers[46]`; datasheet association: `PEQ06` at `0x212`. Physical location: `0x212 (530)`.
Datasheet source: pp.64-65, Table 52; explanatory linearization text on pp.20-21.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PEQ06` at `0x212 (530)`

Locations: datasheet row(s) cited above <-> v1 `registers[46].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[46].field_parts[0].bit_field[0]` | `PEQ06` / `PEQ06` | "Phase Equalizer value at 6/16 * 360 degrees." / "Phase Equalizer value at 6/16 * 360 degrees." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[46].field_parts[0].bit_field[1]` | `PEQ07` / `PEQ07` | "Phase Equalizer value at 7/16 * 360 degrees." / "Phase Equalizer value at 7/16 * 360 degrees." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `PEQ06`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `PEQ07`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PEQ06` | `PEQ06` |
| `physical_address` | 0.4688 | 1.000000 | `0x212 (530), bank="", page=""` | `0x212 (530), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PEQ06` | `PEQ06` |
| `physical_address` | 0.4044 | 1.000000 | `0x212 (530), bank="", page=""` | `0x212 (530), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Stores signed 8-bit phase-equalizer values at angular sample points 6/16 and 7/16 of 360 degrees, scaled by PEQ_GAIN.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_47) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 48: `PEQ08`

v1 location: `registers[47]`; datasheet association: `PEQ08` at `0x214`. Physical location: `0x214 (532)`.
Datasheet source: pp.64-65, Table 52; explanatory linearization text on pp.20-21.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PEQ08` at `0x214 (532)`

Locations: datasheet row(s) cited above <-> v1 `registers[47].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[47].field_parts[0].bit_field[0]` | `PEQ08` / `PEQ08` | "Phase Equalizer value at 8/16 * 360 degrees." / "Phase Equalizer value at 8/16 * 360 degrees." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[47].field_parts[0].bit_field[1]` | `PEQ09` / `PEQ09` | "Phase Equalizer value at 9/16 * 360 degrees." / "Phase Equalizer value at 9/16 * 360 degrees." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `PEQ08`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `PEQ09`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PEQ08` | `PEQ08` |
| `physical_address` | 0.4688 | 1.000000 | `0x214 (532), bank="", page=""` | `0x214 (532), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PEQ08` | `PEQ08` |
| `physical_address` | 0.4044 | 1.000000 | `0x214 (532), bank="", page=""` | `0x214 (532), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Stores signed 8-bit phase-equalizer values at angular sample points 8/16 and 9/16 of 360 degrees, scaled by PEQ_GAIN.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_48) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 49: `PEQ10`

v1 location: `registers[48]`; datasheet association: `PEQ10` at `0x216`. Physical location: `0x216 (534)`.
Datasheet source: pp.64-65, Table 52; explanatory linearization text on pp.20-21.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PEQ10` at `0x216 (534)`

Locations: datasheet row(s) cited above <-> v1 `registers[48].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[48].field_parts[0].bit_field[0]` | `PEQ10` / `PEQ10` | "Phase Equalizer value at 10/16 * 360 degrees." / "Phase Equalizer value at 10/16 * 360 degrees." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[48].field_parts[0].bit_field[1]` | `PEQ11` / `PEQ11` | "Phase Equalizer value at 11/16 * 360 degrees." / "Phase Equalizer value at 11/16 * 360 degrees." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `PEQ10`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `PEQ11`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PEQ10` | `PEQ10` |
| `physical_address` | 0.4688 | 1.000000 | `0x216 (534), bank="", page=""` | `0x216 (534), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PEQ10` | `PEQ10` |
| `physical_address` | 0.4044 | 1.000000 | `0x216 (534), bank="", page=""` | `0x216 (534), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Stores signed 8-bit phase-equalizer values at angular sample points 10/16 and 11/16 of 360 degrees, scaled by PEQ_GAIN.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_49) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 50: `PEQ12`

v1 location: `registers[49]`; datasheet association: `PEQ12` at `0x218`. Physical location: `0x218 (536)`.
Datasheet source: pp.64-65, Table 52; explanatory linearization text on pp.20-21.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PEQ12` at `0x218 (536)`

Locations: datasheet row(s) cited above <-> v1 `registers[49].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[49].field_parts[0].bit_field[0]` | `PEQ12` / `PEQ12` | "Phase Equalizer value at 12/16 * 360 degrees." / "Phase Equalizer value at 12/16 * 360 degrees." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[49].field_parts[0].bit_field[1]` | `PEQ13` / `PEQ13` | "Phase Equalizer value at 13/16 * 360 degrees." / "Phase Equalizer value at 13/16 * 360 degrees." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `PEQ12`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `PEQ13`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PEQ12` | `PEQ12` |
| `physical_address` | 0.4688 | 1.000000 | `0x218 (536), bank="", page=""` | `0x218 (536), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PEQ12` | `PEQ12` |
| `physical_address` | 0.4044 | 1.000000 | `0x218 (536), bank="", page=""` | `0x218 (536), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Stores signed 8-bit phase-equalizer values at angular sample points 12/16 and 13/16 of 360 degrees, scaled by PEQ_GAIN.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_50) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 51: `PEQ14`

v1 location: `registers[50]`; datasheet association: `PEQ14` at `0x21A`. Physical location: `0x21A (538)`.
Datasheet source: pp.64-65, Table 52; explanatory linearization text on pp.20-21.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PEQ14` at `0x21A (538)`

Locations: datasheet row(s) cited above <-> v1 `registers[50].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[50].field_parts[0].bit_field[0]` | `PEQ14` / `PEQ14` | "Phase Equalizer value at 14/16 * 360 degrees." / "Phase Equalizer value at 14/16 * 360 degrees." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[50].field_parts[0].bit_field[1]` | `PEQ15` / `PEQ15` | "Phase Equalizer value at 15/16 * 360 degrees." / "Phase Equalizer value at 15/16 * 360 degrees." | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `PEQ14`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `PEQ15`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PEQ14` | `PEQ14` |
| `physical_address` | 0.4688 | 1.000000 | `0x21A (538), bank="", page=""` | `0x21A (538), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PEQ14` | `PEQ14` |
| `physical_address` | 0.4044 | 1.000000 | `0x21A (538), bank="", page=""` | `0x21A (538), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Stores signed 8-bit phase-equalizer values at angular sample points 14/16 and 15/16 of 360 degrees, scaled by PEQ_GAIN.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_51) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922958**.

## Extracted logical register 52: `S_IQ`

v1 location: `registers[51]`; datasheet association: `S_IQ` at `0x21C`. Physical location: `0x21C (540)`.
Datasheet source: p.65, Table 52; explanatory I/Q and phase-offset text on pp.20-21.

### Bottom layer: bit fields, then field parts

#### Field part 1: `S_IQ` at `0x21C (540)`

Locations: datasheet row(s) cited above <-> v1 `registers[51].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[51].field_parts[0].bit_field[0]` | `S_IQ` / `S_IQ` | "Relative cross-sensitivity from in-phase to quadrature component; nonzero values override factory trimming." / "Relative cross-sensitivity from in-phase to quadrature component; nonzero values override factory trimming." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `S_IQ`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `S_IQ` | `S_IQ` |
| `physical_address` | 0.4688 | 1.000000 | `0x21C (540), bank="", page=""` | `0x21C (540), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `S_IQ` | `S_IQ` |
| `physical_address` | 0.4044 | 1.000000 | `0x21C (540), bank="", page=""` | `0x21C (540), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures relative cross-sensitivity from the in-phase to quadrature component. In I/Q correction, the coefficient is applied as S_IQ/2^15; a nonzero value overrides factory trimming.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0000` | `0` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_52) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 53: `S_QQ`

v1 location: `registers[52]`; datasheet association: `S_QQ` at `0x21E`. Physical location: `0x21E (542)`.
Datasheet source: p.65, Table 52; explanatory I/Q and phase-offset text on pp.20-21.

### Bottom layer: bit fields, then field parts

#### Field part 1: `S_QQ` at `0x21E (542)`

Locations: datasheet row(s) cited above <-> v1 `registers[52].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[52].field_parts[0].bit_field[0]` | `S_QQ` / `S_QQ` | "Relative quadrature-component sensitivity; overrides factory trimming when not equal to 2^15." / "Relative quadrature-component sensitivity; overrides factory trimming when not equal to 2^15." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `S_QQ`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `S_QQ` | `S_QQ` |
| `physical_address` | 0.4688 | 1.000000 | `0x21E (542), bank="", page=""` | `0x21E (542), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `S_QQ` | `S_QQ` |
| `physical_address` | 0.4044 | 1.000000 | `0x21E (542), bank="", page=""` | `0x21E (542), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures relative sensitivity of the quadrature component. In I/Q correction, the coefficient is applied as S_QQ/2^15; it overrides factory trimming when not equal to 2^15.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x8000` | `32768` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_53) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 54: `PHASE_OFS`

v1 location: `registers[53]`; datasheet association: `PHASE_OFS` at `0x220`. Physical location: `0x220 (544)`.
Datasheet source: p.65, Table 52; explanatory I/Q and phase-offset text on pp.20-21.

### Bottom layer: bit fields, then field parts

#### Field part 1: `PHASE_OFS` at `0x220 (544)`

Locations: datasheet row(s) cited above <-> v1 `registers[53].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[53].field_parts[0].bit_field[0]` | `PHASE_OFS` / `PHASE_OFS` | "Signed phase/angle offset before signal conditioning; resolution 360/2^16 degrees." / "Signed phase/angle offset before signal conditioning; resolution 360/2^16 degrees." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `PHASE_OFS`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `PHASE_OFS` | `PHASE_OFS` |
| `physical_address` | 0.4688 | 1.000000 | `0x220 (544), bank="", page=""` | `0x220 (544), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `PHASE_OFS` | `PHASE_OFS` |
| `physical_address` | 0.4044 | 1.000000 | `0x220 (544), bank="", page=""` | `0x220 (544), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Defines a signed zero-angle offset that is systematically added to the phase-tracking position before signal conditioning; resolution is 360/2^16 degrees.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0000` | `0` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_54) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 55: `SC_X1`

v1 location: `registers[54]`; datasheet association: `SC_X1` at `0x222`. Physical location: `0x222 (546)`.
Datasheet source: p.65, Table 52; explanatory signal-conditioning text on p.22.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SC_X1` at `0x222 (546)`

Locations: datasheet row(s) cited above <-> v1 `registers[54].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[54].field_parts[0].bit_field[0]` | `SC_X1` / `SC_X1` | "Signal-conditioning X1 input-range low parameter." / "Signal-conditioning X1 input-range low parameter." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `SC_X1`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SC_X1` | `SC_X1` |
| `physical_address` | 0.4688 | 1.000000 | `0x222 (546), bank="", page=""` | `0x222 (546), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SC_X1` | `SC_X1` |
| `physical_address` | 0.4044 | 1.000000 | `0x222 (546), bank="", page=""` | `0x222 (546), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Defines one boundary of the signal-conditioning input window. SC_X1 and SC_X2 select and saturate the input angle range; either ordering is allowed, including a range wrapping across zero.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0000` | `0` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_55) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 56: `SC_X2`

v1 location: `registers[55]`; datasheet association: `SC_X2` at `0x224`. Physical location: `0x224 (548)`.
Datasheet source: p.65, Table 52; explanatory signal-conditioning text on p.22.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SC_X2` at `0x224 (548)`

Locations: datasheet row(s) cited above <-> v1 `registers[55].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[55].field_parts[0].bit_field[0]` | `SC_X2` / `SC_X2` | "Signal-conditioning X2 input-range high parameter." / "Signal-conditioning X2 input-range high parameter." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `SC_X2`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SC_X2` | `SC_X2` |
| `physical_address` | 0.4688 | 1.000000 | `0x224 (548), bank="", page=""` | `0x224 (548), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SC_X2` | `SC_X2` |
| `physical_address` | 0.4044 | 1.000000 | `0x224 (548), bank="", page=""` | `0x224 (548), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Defines the other boundary of the signal-conditioning input window. SC_X1 and SC_X2 select and saturate the input angle range; either ordering is allowed, including a range wrapping across zero.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0000` | `0` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_56) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 57: `SC_Y1`

v1 location: `registers[56]`; datasheet association: `SC_Y1` at `0x226`. Physical location: `0x226 (550)`.
Datasheet source: p.65, Table 52; explanatory signal-conditioning text on p.22.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SC_Y1` at `0x226 (550)`

Locations: datasheet row(s) cited above <-> v1 `registers[56].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[56].field_parts[0].bit_field[0]` | `SC_Y1` / `SC_Y1` | "Signal-conditioning Y1 output-range low parameter." / "Signal-conditioning Y1 output-range low parameter." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `SC_Y1`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SC_Y1` | `SC_Y1` |
| `physical_address` | 0.4688 | 1.000000 | `0x226 (550), bank="", page=""` | `0x226 (550), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SC_Y1` | `SC_Y1` |
| `physical_address` | 0.4044 | 1.000000 | `0x226 (550), bank="", page=""` | `0x226 (550), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Defines the signal-conditioning output offset and one output limit. The output is limited between min(SC_Y1,SC_Y2) and max(SC_Y1,SC_Y2); reversing Y1/Y2 relative to X1/X2 inverts the transfer characteristic.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x0001` | `1` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_57) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 58: `SC_Y2`

v1 location: `registers[57]`; datasheet association: `SC_Y2` at `0x228`. Physical location: `0x228 (552)`.
Datasheet source: p.65, Table 52; explanatory signal-conditioning text on p.22.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SC_Y2` at `0x228 (552)`

Locations: datasheet row(s) cited above <-> v1 `registers[57].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[57].field_parts[0].bit_field[0]` | `SC_Y2` / `SC_Y2` | "Signal-conditioning Y2 output-range high parameter." / "Signal-conditioning Y2 output-range high parameter." | `0:15` / `0:15` | `16` / `16` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `SC_Y2`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000) = **1.000000**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SC_Y2` | `SC_Y2` |
| `physical_address` | 0.4688 | 1.000000 | `0x228 (552), bank="", page=""` | `0x228 (552), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.965350 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x1.000000 = **0.965350**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.965350) = **0.965350**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SC_Y2` | `SC_Y2` |
| `physical_address` | 0.4044 | 1.000000 | `0x228 (552), bank="", page=""` | `0x228 (552), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Defines the other signal-conditioning output limit. The output is limited between min(SC_Y1,SC_Y2) and max(SC_Y1,SC_Y2); reversing Y1/Y2 relative to X1/X2 inverts the transfer characteristic.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.965350 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 1.000000 | `0x7FFD` | `32765` |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_58) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.965350 + 0.0667x1.000000 + 0.0334x1.000000) / 1.0001 = **0.989651**.

## Extracted logical register 59: `SC_HL`

v1 location: `registers[58]`; datasheet association: `SC_HL` at `0x22C`. Physical location: `0x22C (556)`.
Datasheet source: p.65, Table 52; explanatory signal-conditioning text on p.22.

### Bottom layer: bit fields, then field parts

#### Field part 1: `SC_HL` at `0x22C (556)`

Locations: datasheet row(s) cited above <-> v1 `registers[58].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[58].field_parts[0].bit_field[0]` | `SC_HL` / `SC_HL` | "Transition point for high-to-low clamping as an offset from the X-range center; resolution 360 degrees/2^8." / "Transition point for high-to-low clamping as an offset from the X-range center; resolution 360 degrees/2^8." | `0:8` / `0:8` | `9` / `9` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[58].field_parts[0].bit_field[1]` | `Not used` / `Not used` | "" / "" | `9:15` / `9:15` | `7` / `7` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `SC_HL`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 0.941694) = **0.970847**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `SC_HL` | `SC_HL` |
| `physical_address` | 0.4688 | 1.000000 | `0x22C (556), bank="", page=""` | `0x22C (556), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.956228 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.970847 = **0.956228**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.956228) = **0.956228**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `SC_HL` | `SC_HL` |
| `physical_address` | 0.4044 | 1.000000 | `0x22C (556), bank="", page=""` | `0x22C (556), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Shifts the signal-conditioning transition between high and low clamping relative to the center of the SC_X1/SC_X2 window, with resolution 360 degrees/2^8.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.956228 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0080` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_59) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.956228 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.920233**.

## Extracted logical register 60: `DELAY_CUS`

v1 location: `registers[59]`; datasheet association: `DELAY_CUS` at `0x244`. Physical location: `0x244 (580)`.
Datasheet source: pp.65-66, Table 52; explanatory processing/self-calibration text on pp.20-22.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DELAY_CUS` at `0x244 (580)`

Locations: datasheet row(s) cited above <-> v1 `registers[59].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[59].field_parts[0].bit_field[0]` | `DELAY_CUS` / `DELAY_CUS` | "Customer processing delay, range [0:255] * 26/64 / fRCO." / "Customer processing delay, range [0:255] * 26/64 / fRCO." | `0:7` / `0:7` | `8` / `8` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[59].field_parts[0].bit_field[1]` | `Not used` / `Not used` | "" / "" | `8:15` / `8:15` | `8` / `8` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `DELAY_CUS`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 0.941694) = **0.970847**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `DELAY_CUS` | `DELAY_CUS` |
| `physical_address` | 0.4688 | 1.000000 | `0x244 (580), bank="", page=""` | `0x244 (580), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.956228 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.970847 = **0.956228**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.956228) = **0.956228**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `DELAY_CUS` | `DELAY_CUS` |
| `physical_address` | 0.4044 | 1.000000 | `0x244 (580), bank="", page=""` | `0x244 (580), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures compensation for additional customer processing delays, such as external filter-network delay, over the range 0..255 in steps of (26/64)/fRCO.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.956228 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_60) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.956228 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.920233**.

## Extracted logical register 61: `DSP_IQNEG`

v1 location: `registers[60]`; datasheet association: `DSP_IQNEG` at `0x246`. Physical location: `0x246 (582)`.
Datasheet source: pp.65-66, Table 52; explanatory processing/self-calibration text on pp.20-22.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DSP_IQNEG` at `0x246 (582)`

Locations: datasheet row(s) cited above <-> v1 `registers[60].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[60].field_parts[0].bit_field[0]` | `DSP_IQNEG` / `DSP_IQNEG` | "I/Q sign inversion: bit 0 controls GC_I and bit 1 controls GC_Q." / "I/Q sign inversion: bit 0 controls GC_I and bit 1 controls GC_Q." | `0:1` / `0:1` | `2` / `2` | "[Bit[0] = 0 -&gt; GC_I.; Bit[0] = 1 -&gt; -GC_I.; Bit[1] = 0 -&gt; GC_Q.; Bit[1] = 1 -&gt; -GC_Q.]" / "[Bit[0] = 0 -&gt; GC_I.; Bit[0] = 1 -&gt; -GC_I.; Bit[1] = 0 -&gt; GC_Q.; Bit[1] = 1 -&gt; -GC_Q.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[60].field_parts[0].bit_field[1]` | `DSP_GC_AVG` / `DSP_GC_AVG` | "GC averaging control. For values 1..6 the window uses 4^DSP_GC_AVG samples; value 7 uses 8 samples." / "GC averaging control. For values 1..6 the window uses 4^DSP_GC_AVG samples; value 7 uses 8 samples." | `2:4` / `2:4` | `3` / `3` | "[0 -&gt; Averaging off.; 1...6 -&gt; Average over 4^DSP_GC_AVG samples.; 7 -&gt; Average over 8 samples.]" / "[0 -&gt; Averaging off.; 1...6 -&gt; Average over 4^DSP_GC_AVG samples.; 7 -&gt; Average over 8 samples.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[60].field_parts[0].bit_field[2]` | `DSP_DRIFTC_DIS` / `DSP_DRIFTC_DIS` | "Delay-compensation disable." / "Delay-compensation disable." | `5:5` / `5:5` | `1` / `1` | "[1 -&gt; Disable delay compensation.]" / "[1 -&gt; Disable delay compensation.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF4 `registers[60].field_parts[0].bit_field[3]` | `Reserved` / `Reserved` | "Reserved, don't change." / "Reserved, don't change." | `6:6` / `6:6` | `1` / `1` | "[]" / "[]" | `True` / `True` | `RW` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |
| BF5 `registers[60].field_parts[0].bit_field[4]` | `DSP_LFC_LO` / `DSP_LFC_LO` | "Lowest DSP loop-filter bandwidth; adaptive loop filtering is enabled when DSP_LFC_LO &lt; DSP_LFC_HI." / "Lowest DSP loop-filter bandwidth; adaptive loop filtering is enabled when DSP_LFC_LO &lt; DSP_LFC_HI." | `8:10` / `8:10` | `3` / `3` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF6 `registers[60].field_parts[0].bit_field[5]` | `DSP_LFC_HI` / `DSP_LFC_HI` | "Upper DSP loop-filter bandwidth." / "Upper DSP loop-filter bandwidth." | `11:13` / `11:13` | `3` / `3` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF7 `registers[60].field_parts[0].bit_field[6]` | `DSP_SROS` / `DSP_SROS` | "Phase-tracking step-response overshoot; lower settings are more damped, while higher settings provide faster response with more transient overshoot." / "Phase-tracking step-response overshoot; lower settings are more damped, while higher settings provide faster response with more transient overshoot." | `14:15` / `14:15` | `2` / `2` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |

Bit-field aggregation:
- `DSP_IQNEG`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DSP_GC_AVG`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DSP_DRIFTC_DIS`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Reserved`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- `DSP_LFC_LO`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DSP_LFC_HI`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `DSP_SROS`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- bit_field correctness = mean(1.000000, 1.000000, 1.000000, 0.941694, 1.000000, 1.000000, 1.000000) = **0.991671**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `DSP_IQNEG` | `DSP_IQNEG` |
| `physical_address` | 0.4688 | 1.000000 | `0x246 (582), bank="", page=""` | `0x246 (582), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.962744 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.991671 = **0.962744**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.962744) = **0.962744**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `DSP_IQNEG` | `DSP_IQNEG` |
| `physical_address` | 0.4044 | 1.000000 | `0x246 (582), bank="", page=""` | `0x246 (582), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures I/Q sign inversion, GC averaging, delay compensation, phase-tracking loop-filter range, and step-response overshoot. Equal DSP_LFC_LO and DSP_LFC_HI values fix the loop filter; DSP_LFC_LO below DSP_LFC_HI enables adaptive bandwidth.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.962744 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0xA840` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_61) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.962744 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.922179**.

## Extracted logical register 62: `RMM_FAST`

v1 location: `registers[61]`; datasheet association: `RMM_FAST` at `0x256`. Physical location: `0x256 (598)`.
Datasheet source: pp.65-66, Table 52; explanatory processing/self-calibration text on pp.20-22.

### Bottom layer: bit fields, then field parts

#### Field part 1: `RMM_FAST` at `0x256 (598)`

Locations: datasheet row(s) cited above <-> v1 `registers[61].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[61].field_parts[0].bit_field[0]` | `RMM_FAST` / `RMM_FAST` | "Settling configuration for self-calibration after startup." / "Settling configuration for self-calibration after startup." | `0:2` / `0:2` | `3` / `3` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[61].field_parts[0].bit_field[1]` | `RMM_LFC` / `RMM_LFC` | "Settling constant for the self-calibration tracking filter." / "Settling constant for the self-calibration tracking filter." | `3:5` / `3:5` | `3` / `3` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[61].field_parts[0].bit_field[2]` | `RMM_AVG_MIN` / `RMM_AVG_MIN` | "Minimum self-calibration averaging value." / "Minimum self-calibration averaging value." | `6:7` / `6:7` | `2` / `2` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF4 `registers[61].field_parts[0].bit_field[3]` | `RMM_AVG_MAX` / `RMM_AVG_MAX` | "Maximum self-calibration averaging value." / "Maximum self-calibration averaging value." | `8:9` / `8:9` | `2` / `2` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF5 `registers[61].field_parts[0].bit_field[4]` | `Reserved` / `Reserved` | "Reserved, don't change." / "Reserved, don't change." | `10:14` / `10:14` | `5` / `5` | "[]" / "[]" | `True` / `True` | `RW` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |
| BF6 `registers[61].field_parts[0].bit_field[5]` | `Not used` / `Not used` | "" / "" | `15:15` / `15:15` | `1` / `1` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `RMM_FAST`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `RMM_LFC`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `RMM_AVG_MIN`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `RMM_AVG_MAX`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Reserved`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 0.941694, 0.941694) = **0.980565**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `RMM_FAST` | `RMM_FAST` |
| `physical_address` | 0.4688 | 1.000000 | `0x256 (598), bank="", page=""` | `0x256 (598), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.959269 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.980565 = **0.959269**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.959269) = **0.959269**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `RMM_FAST` | `RMM_FAST` |
| `physical_address` | 0.4044 | 1.000000 | `0x256 (598), bank="", page=""` | `0x256 (598), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures self-calibration settling after startup, tracking-filter settling constant, and minimum/maximum averaging.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.959269 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0314` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_62) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.959269 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.921141**.

## Extracted logical register 63: `RMM_ASQQ_MIN`

v1 location: `registers[62]`; datasheet association: `RMM_ASQQ_MIN` at `0x258`. Physical location: `0x258 (600)`.
Datasheet source: pp.65-66, Table 52; explanatory processing/self-calibration text on pp.20-22.

### Bottom layer: bit fields, then field parts

#### Field part 1: `RMM_ASQQ_MIN` at `0x258 (600)`

Locations: datasheet row(s) cited above <-> v1 `registers[62].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[62].field_parts[0].bit_field[0]` | `RMM_ASQQ_MIN` / `RMM_ASQQ_MIN` | "Self-calibration minimum ASQQ clamping value." / "Self-calibration minimum ASQQ clamping value." | `0:4` / `0:4` | `5` / `5` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF2 `registers[62].field_parts[0].bit_field[1]` | `RMM_ASQQ_MAX` / `RMM_ASQQ_MAX` | "Self-calibration maximum ASQQ clamping value." / "Self-calibration maximum ASQQ clamping value." | `5:9` / `5:9` | `5` / `5` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[62].field_parts[0].bit_field[2]` | `RMM_ASIQ_MAX` / `RMM_ASIQ_MAX` | "Self-calibration maximum absolute ASIQ clamping value." / "Self-calibration maximum absolute ASIQ clamping value." | `10:14` / `10:14` | `5` / `5` | "[]" / "[]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF4 `registers[62].field_parts[0].bit_field[3]` | `Reserved` / `Reserved` | "Reserved, don't change." / "Reserved, don't change." | `15:15` / `15:15` | `1` / `1` | "[]" / "[]" | `True` / `True` | `RW` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `RMM_ASQQ_MIN`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `RMM_ASQQ_MAX`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `RMM_ASIQ_MAX`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Reserved`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(1.000000, 1.000000, 1.000000, 0.941694) = **0.985424**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `RMM_ASQQ_MIN` | `RMM_ASQQ_MIN` |
| `physical_address` | 0.4688 | 1.000000 | `0x258 (600), bank="", page=""` | `0x258 (600), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.960789 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.985424 = **0.960789**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.960789) = **0.960789**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `RMM_ASQQ_MIN` | `RMM_ASQQ_MIN` |
| `physical_address` | 0.4044 | 1.000000 | `0x258 (600), bank="", page=""` | `0x258 (600), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Configures self-calibration clamping limits for adaptive sensitivity and orthogonality correction values.` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.960789 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0000` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_63) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.960789 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.921596**.

## Extracted logical register 64: `DE_DSP_RMM`

v1 location: `registers[63]`; datasheet association: `DE_DSP_RMM` at `0x25C`. Physical location: `0x25C (604)`.
Datasheet source: pp.65-66, Table 52; explanatory processing/self-calibration text on pp.20-22.

### Bottom layer: bit fields, then field parts

#### Field part 1: `DE_DSP_RMM` at `0x25C (604)`

Locations: datasheet row(s) cited above <-> v1 `registers[63].field_parts[0]`.

| Bit field | Datasheet name / v1 name | Datasheet description / v1 description | Datasheet bits / v1 bits | Datasheet width / v1 width | Datasheet values / v1 values | Datasheet reserved / v1 reserved | Datasheet R/W / v1 R/W | C-vector | Q_BF |
|---|---|---|---|---|---|---|---|---|---:|
| BF1 `registers[63].field_parts[0].bit_field[0]` | `Reserved` / `Reserved` | "Reserved, don't change." / "Reserved, don't change." | `0:6` / `0:6` | `7` / `7` | "[]" / "[]" | `True` / `True` | `RW` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |
| BF2 `registers[63].field_parts[0].bit_field[1]` | `DE_DSP_RMM` / `DE_DSP_RMM` | "Self-calibration disable controls: field bit 0 disables sensitivity self-calibration and field bit 1 disables orthogonality self-calibration." / "Self-calibration disable controls: field bit 0 disables sensitivity self-calibration and field bit 1 disables orthogonality self-calibration." | `7:8` / `7:8` | `2` / `2` | "[0 -&gt; Sensitivity and orthogonality self-calibration are enabled.; bit[0] = 1 -&gt; Disable sensitivity self-calibration.; bit[1] = 1 -&gt; Disable orthogonality self-calibration.]" / "[0 -&gt; Sensitivity and orthogonality self-calibration are enabled.; bit[0] = 1 -&gt; Disable sensitivity self-calibration.; bit[1] = 1 -&gt; Disable orthogonality self-calibration.]" | `False` / `False` | `RW` / `RW` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]` | 1.000000 |
| BF3 `registers[63].field_parts[0].bit_field[2]` | `Reserved` / `Reserved` | "Reserved, don't change." / "Reserved, don't change." | `9:9` / `9:9` | `1` / `1` | "[]" / "[]" | `True` / `True` | `RW` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |
| BF4 `registers[63].field_parts[0].bit_field[3]` | `Not used` / `Not used` | "" / "" | `10:14` / `10:14` | `5` / `5` | "[]" / "[]" | `True` / `True` | `R` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |
| BF5 `registers[63].field_parts[0].bit_field[4]` | `Reserved` / `Reserved` | "Reserved, don't change." / "Reserved, don't change." | `15:15` / `15:15` | `1` / `1` | "[]" / "[]" | `True` / `True` | `RW` / `""` | `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]` | 0.941694 |

Bit-field aggregation:
- `Reserved`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- `DE_DSP_RMM`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]`; Q_BF = 1.000000.
- `Reserved`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- `Not used`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- `Reserved`: C-vector `[1.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0]`; Q_BF = 0.941694.
- bit_field correctness = mean(0.941694, 1.000000, 0.941694, 0.941694, 0.941694) = **0.953355**.

#### Field-part aggregation

| Field-part field | Weight | C | Datasheet content | v1 content |
|---|---:|---:|---|---|
| `register_name` | 0.0280 | 1.000000 | `DE_DSP_RMM` | `DE_DSP_RMM` |
| `physical_address` | 0.4688 | 1.000000 | `0x25C (604), bank="", page=""` | `0x25C (604), bank="", page=""` |
| `description` | 0.0693 | 0.500000 | `Description is present in the cited datasheet row(s).` | "" |
| `width_bits` | 0.0605 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0605 | 1.000000 | `RW` | `RW` |
| `bit_field` | 0.3129 | 0.950755 | `corresponding datasheet bit-field set` | `extracted bit-field set` |

Q_FP = 0.0280x1.000000 + 0.4688x1.000000 + 0.0693x0.500000 + 0.0605x1.000000 + 0.0605x1.000000 + 0.3129x0.953355 = **0.950755**.

### Extracted logical-register aggregation

field_parts correctness = mean(0.950755) = **0.950755**.

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| `name` | 0.0225 | 1.000000 | `DE_DSP_RMM` | `DE_DSP_RMM` |
| `physical_address` | 0.4044 | 1.000000 | `0x25C (604), bank="", page=""` | `0x25C (604), bank="", page=""` |
| `register_description` | 0.0564 | 1.000000 | `Cited datasheet description; semantic match accepted under relaxed description rule` | `Controls sensitivity and orthogonality self-calibration. Setting DE_DSP_RMM[1:0] to 0 enables both functions. For recommended settings and programming procedure for all self-calibration registers, retrieve the MLX90382 Application Note [6].` |
| `width_bits` | 0.0590 | 1.000000 | `16` | `16` |
| `type_write_read` | 0.0590 | 1.000000 | `RW` | `RW` |
| `field_parts` | 0.2987 | 0.950755 | `corresponding datasheet field-part collection` | `extracted field-part collection` |
| `default_value` | 0.0667 | 0.000000 | `0x0380` | "" |
| `default_value_description` | 0.0334 | 1.000000 | "" | "" |

Q(L_64) = (0.0225x1.000000 + 0.4044x1.000000 + 0.0564x1.000000 + 0.0590x1.000000 + 0.0590x1.000000 + 0.2987x0.950755 + 0.0667x0.000000 + 0.0334x1.000000) / 1.0001 = **0.918599**.

## 4. Ground-truth physical-register scores

Every datasheet physical location has one associated v1 logical register and one field part. Therefore q_R = Q(L) for each row below; no missing physical register receives a zero and no extra-register penalty is applied.

| Datasheet physical address | Datasheet register association | v1 location and Q(L) | q_R |
|---|---|---|---:|
| `0x0BE (190)` | `DE_SR` | `registers[0]` = 0.845894 | 0.845894 |
| `0x010 (16)` | `NVOP_KEY` | `registers[1]` = 0.920233 | 0.920233 |
| `0x024 (36)` | `IN_APPLICATION` | `registers[2]` = 0.921141 | 0.921141 |
| `0x026 (38)` | `CRC` | `registers[3]` = 0.989651 | 0.989651 |
| `0x028 (40)` | `CRC_CALC_STRT` | `registers[4]` = 0.953580 | 0.953580 |
| `0x02C (44)` | `STATE` | `registers[5]` = 0.920233 | 0.920233 |
| `0x034 (52)` | `AGC_GAIN` | `registers[6]` = 0.919325 | 0.919325 |
| `0x036 (54)` | `AGC_AMP` | `registers[7]` = 0.920233 | 0.920233 |
| `0x038 (56)` | `TEMP` | `registers[8]` = 0.920233 | 0.920233 |
| `0x03A (58)` | `LIN_PHASE` | `registers[9]` = 0.989651 | 0.989651 |
| `0x03C (60)` | `SPEED` | `registers[10]` = 0.989651 | 0.989651 |
| `0x042 (66)` | `DRIFTC_PHASE` | `registers[11]` = 0.989651 | 0.989651 |
| `0x044 (68)` | `SC_PHASE` | `registers[12]` = 0.989651 | 0.989651 |
| `0x048 (72)` | `GC_I` | `registers[13]` = 0.989651 | 0.989651 |
| `0x04E (78)` | `GC_Q` | `registers[14]` = 0.989651 | 0.989651 |
| `0x062 (98)` | `RMM_ASIQ` | `registers[15]` = 0.989651 | 0.989651 |
| `0x064 (100)` | `RMM_ASQQ` | `registers[16]` = 0.989651 | 0.989651 |
| `0x10A (266)` | `PWM_PCNT` | `registers[17]` = 0.989651 | 0.989651 |
| `0x200 (512)` | `SENSING_MODE` | `registers[18]` = 0.922050 | 0.922050 |
| `0x202 (514)` | `ABI_CFG` | `registers[19]` = 0.844078 | 0.844078 |
| `0x204 (516)` | `ABI_LOG2N` | `registers[20]` = 0.922958 | 0.922958 |
| `0x206 (518)` | `PWM_INV` | `registers[21]` = 0.920233 | 0.920233 |
| `0x22E (558)` | `PWM_PERIOD` | `registers[22]` = 0.989651 | 0.989651 |
| `0x248 (584)` | `PWM_DC_OFS` | `registers[23]` = 0.920233 | 0.920233 |
| `0x230 (560)` | `SPI_FADDR0` | `registers[24]` = 0.922958 | 0.922958 |
| `0x232 (562)` | `SPI_FADDR2` | `registers[25]` = 0.922958 | 0.922958 |
| `0x234 (564)` | `SPI_FRFS` | `registers[26]` = 0.922179 | 0.922179 |
| `0x236 (566)` | `SPI_SFRL` | `registers[27]` = 0.922958 | 0.922958 |
| `0x238 (568)` | `SPI_CPTLT` | `registers[28]` = 0.919908 | 0.919908 |
| `0x23A (570)` | `SSI_PARPOS` | `registers[29]` = 0.921596 | 0.921596 |
| `0x23C (572)` | `PHY_RC_EN` | `registers[30]` = 0.920778 | 0.920778 |
| `0x22A (554)` | `SC_YE` | `registers[31]` = 0.989651 | 0.989651 |
| `0x24A (586)` | `DIAG_TEMP_THD_LO` | `registers[32]` = 0.922958 | 0.922958 |
| `0x24C (588)` | `DIAG_TEMP_THD_MAX` | `registers[33]` = 0.919325 | 0.919325 |
| `0x24E (590)` | `DIAG_SPEED_THD` | `registers[34]` = 0.921141 | 0.921141 |
| `0x252 (594)` | `DIAG_AGC_THD_LO` | `registers[35]` = 0.922958 | 0.922958 |
| `0x25A (602)` | `DE_OV_VDD` | `registers[36]` = 0.922958 | 0.922958 |
| `0x25E (606)` | `CUS_CRC` | `registers[37]` = 0.989651 | 0.989651 |
| `0x23E (574)` | `USER_ID0` | `registers[38]` = 0.922958 | 0.922958 |
| `0x240 (576)` | `USER_ID2` | `registers[39]` = 0.922958 | 0.922958 |
| `0x242 (578)` | `USER_ID4` | `registers[40]` = 0.956304 | 0.956304 |
| `0x208 (520)` | `AGC_GAIN_MIN` | `registers[41]` = 0.921141 | 0.921141 |
| `0x20A (522)` | `PEQ_GAIN` | `registers[42]` = 0.920233 | 0.920233 |
| `0x20C (524)` | `PEQ00` | `registers[43]` = 0.922958 | 0.922958 |
| `0x20E (526)` | `PEQ02` | `registers[44]` = 0.922958 | 0.922958 |
| `0x210 (528)` | `PEQ04` | `registers[45]` = 0.922958 | 0.922958 |
| `0x212 (530)` | `PEQ06` | `registers[46]` = 0.922958 | 0.922958 |
| `0x214 (532)` | `PEQ08` | `registers[47]` = 0.922958 | 0.922958 |
| `0x216 (534)` | `PEQ10` | `registers[48]` = 0.922958 | 0.922958 |
| `0x218 (536)` | `PEQ12` | `registers[49]` = 0.922958 | 0.922958 |
| `0x21A (538)` | `PEQ14` | `registers[50]` = 0.922958 | 0.922958 |
| `0x21C (540)` | `S_IQ` | `registers[51]` = 0.989651 | 0.989651 |
| `0x21E (542)` | `S_QQ` | `registers[52]` = 0.989651 | 0.989651 |
| `0x220 (544)` | `PHASE_OFS` | `registers[53]` = 0.989651 | 0.989651 |
| `0x222 (546)` | `SC_X1` | `registers[54]` = 0.989651 | 0.989651 |
| `0x224 (548)` | `SC_X2` | `registers[55]` = 0.989651 | 0.989651 |
| `0x226 (550)` | `SC_Y1` | `registers[56]` = 0.989651 | 0.989651 |
| `0x228 (552)` | `SC_Y2` | `registers[57]` = 0.989651 | 0.989651 |
| `0x22C (556)` | `SC_HL` | `registers[58]` = 0.920233 | 0.920233 |
| `0x244 (580)` | `DELAY_CUS` | `registers[59]` = 0.920233 | 0.920233 |
| `0x246 (582)` | `DSP_IQNEG` | `registers[60]` = 0.922179 | 0.922179 |
| `0x256 (598)` | `RMM_FAST` | `registers[61]` = 0.921141 | 0.921141 |
| `0x258 (600)` | `RMM_ASQQ_MIN` | `registers[62]` = 0.921596 | 0.921596 |
| `0x25C (604)` | `DE_DSP_RMM` | `registers[63]` = 0.918599 | 0.918599 |

Sum q_R = **60.257359529**.

m=64, x=0, m/(m+x)=64/(64+0)=1.000000.

S_final = (10/64 x 60.257359529) x 64/(64+0) = **9.415212426/10**

## 5. Detailed deduction inventory

1. All 64 datasheet physical locations are present exactly once in v1. There is no missing-register or extra-register penalty.
2. registers[0] (DE_SR) omits width_bits at both logical-register and field-part level; its datasheet table is a 16-bit register context with field [3:1]. Its default value is also omitted.
3. registers[19] (ABI_CFG) omits width_bits at both levels and omits the normalized default. Datasheet Table 49 does not print bits [11:8]; the listed defaults still yield 0x005C on the printed fields.
4. Every registers[i].field_parts[0].description is empty. This is a descriptive omission only and receives C=0.5, not a functional-zero judgment.
5. The missing default values are objective omissions. In particular, many multi-field words have nonzero datasheet defaults, so an empty top-level default_value is not treated as correct merely because individual bit ranges are correct.
6. Reserved and Not used bit fields are structurally present with correct names, ranges, widths, and reserved flags, but v1 leaves type_write_read empty. Where the datasheet prints R or R/W, that field receives C=0.
7. registers[28].field_parts[0].bit_field[1] (SPI_SFR_SCPT) contains a useful 0 interpretation, but Table 49 only explicitly states the 1 behavior; values therefore receives C=0.5 under a datasheet-only baseline.
8. No invented field, wrong numeric address, wrong bit range, wrong bit width, wrong non-reserved access type, or contradictory top-level description was found.

## 6. Final result

The MLX90382 v1 register map scores **9.415212426/10** against the cited MLX90382 Revision 1.0 datasheet. The result is structurally complete and factually strong; the remaining loss is concentrated in omitted register defaults, omitted reserved/Not used access attributes, the two missing width fields, and empty physical field-part descriptions.
