# BMM350 v1.0 datasheet-based score report

## 1. Scoring basis

- Datasheet source: Bosch Sensortec, **BMM350**, document `BST-BMM350-DS001-27`, document revision `1.27`, release date February 2025, 63 pages. Local source file: [BMM350.pdf](../BMM350.pdf).
- Evaluated extraction: `BMM350/v1_0/register_map.json`.
- The datasheet register universe is the 36 named physical locations in Table 8 (pp.26-28). The v1 result contains the same 36 unique numeric addresses, with no duplicate `(address, bank, page)` key.
- Therefore `n=36`, `m=36`, `x=0`; all physical-register matches are one-to-one and no extra-register penalty applies.
- Source resolution: Table 8 is used for the register universe and field layout; the per-register definitions in §§8.1-8.35 (pp.29-43) are used for exact reset values, access types, bit ranges, and value encodings. For `PMU_CMD_AXIS_EN`, Table 8 p.28 visually shows `0x70` and read-only shading, while §8.5 p.31 gives `RESET: 0x07` and the detailed bit table gives `W` for bits 3:0; the detailed definition is used, so v1 `0x07`/`W` is not penalized. Table 8 p.28 also abbreviates the upper PMU_CMD_STATUS_0 area differently; §8.7 p.33 defines bits 7:5 as reserved, which is the target used below.
- Access spelling is normalized semantically: datasheet `R/W` equals v1 `RW`, and datasheet `n/a` on reserved bits equals an empty v1 access field. Hex case and numeric formatting are normalized, but address, reset value, range, width, reserved status, and functional access are strict.
- Description fields are judged for functional meaning. A missing `field_part.description` receives `0.5` when the datasheet has an explicit register `DESCRIPTION`; a paraphrase with no functional deviation receives `1.0`. `physical_address.description` and `default_value_description` are not penalized where the datasheet supplies no independent target for those subfields.
- Bit-field C-vector order is `(name_or_parameter, field_description, bit_start, bit_end, bit_width, values, is_reserved, type_write_read)`. Rounded AHP weights are normalized by `0.9999` at bit-field level and `1.0001` at logical-register level; field-part weights sum to `1.0000`.

AHP weights used:

- `logical_register`: name `0.0225`, physical_address `0.4044`, register_description `0.0564`, width_bits `0.0590`, type_write_read `0.0590`, field_parts `0.2987`, default_value `0.0667`, default_value_description `0.0334`.
- `field_part`: register_name `0.0280`, physical_address `0.4688`, description `0.0693`, width_bits `0.0605`, type_write_read `0.0605`, bit_field `0.3129`.
- `bit_field`: name_or_parameter `0.0212`, field_description `0.0586`, bit_start `0.2594`, bit_end `0.2594`, bit_width `0.0583`, values `0.2097`, is_reserved `0.0750`, type_write_read `0.0583`.

## 2. Bottom-up calculation for every extracted logical register

Each item below follows the required order: all bit fields first, then the containing field part, then the logical register. In the bit-field tables, `DS target` is the exact objective target from the cited datasheet section; `v1 content` is the extracted content. `values` lists the code-to-label entries when present.

### Extracted logical register 1: `CHIP_ID`

v1 location: `registers[0]`; datasheet association: Table 8 row `CHIP_ID` at `0x00`.
Associated physical location: `0x00` (0).
Datasheet source: **Table 8 pp.26-28; §8.1 p.29**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[0].field_parts[0].bit_field[0]` `chip_id_fixed` | `chip_id_fixed` [7:4]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:4]; access=R; desc="Fixed part of chip ID."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[0].field_parts[0].bit_field[1]` `chip_id_otp` | `chip_id_otp` [3:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[3:0]; access=R; desc="Programmable NVM part of chip ID."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field part 1: `CHIP_ID` at `0x00` (0)

Location: `registers[0].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `CHIP_ID` | `CHIP_ID` |
| physical_address | 0.4688 | 1.0 | `0x00` / `0` | {"hex":"0x00","decimal":"0","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "Chip identification code." (Table 8 pp.26-28; §8.1 p.29) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `CHIP_ID` | `CHIP_ID` |
| physical_address | 0.4044 | 1.0 | `0x00` / `0` | [{"hex":"0x00","decimal":"0","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.1 p.29 register meaning; no functional deviation in v1 | "Chip identification code; read-only value 0x33 helps verify communication with the device." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x00 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x33 | `0x33` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 2: `ERR_REG`

v1 location: `registers[1]`; datasheet association: Table 8 row `ERR_REG` at `0x02`.
Associated physical location: `0x02` (2).
Datasheet source: **Table 8 pp.26-28; §8.2 p.29**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[1].field_parts[0].bit_field[0]` `reserved` | `reserved` [7:1]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[7:1]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[1].field_parts[0].bit_field[1]` `pmu_cmd_error` | `pmu_cmd_error` [0:0]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[0:0]; access=RW; desc="Indicates that a new PMU_CMD was issued before the previous command finished."; values=0x0=>pmu_ok; 0x1=>pmu_error; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `pmu_cmd_error`: 0x0=>pmu_ok; 0x1=>pmu_error.

Bit-field collection correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field part 1: `ERR_REG` at `0x02` (2)

Location: `registers[1].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `ERR_REG` | `ERR_REG` |
| physical_address | 0.4688 | 1.0 | `0x02` / `2` | {"hex":"0x02","decimal":"2","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "Reports Sensor Error Flag. Will be cleared on read. If the user writes a 1 into any status bit, this will also clear that bit." (Table 8 pp.26-28; §8.2 p.29) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R/W | `RW` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `ERR_REG` | `ERR_REG` |
| physical_address | 0.4044 | 1.0 | `0x02` / `2` | [{"hex":"0x02","decimal":"2","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.2 p.29 register meaning; no functional deviation in v1 | "Reports sensor error flags and is cleared on read; writing 1 to a status bit also clears that bit. pmu_cmd_error indicates that a new PMU command was issued before the previous command finished, causing the new command to be ignored." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R/W | `RW` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x02 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 3: `PAD_CTRL`

v1 location: `registers[2]`; datasheet association: Table 8 row `PAD_CTRL` at `0x03`.
Associated physical location: `0x03` (3).
Datasheet source: **Table 8 pp.26-28; §8.3 p.30**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[2].field_parts[0].bit_field[0]` `reserved` | `reserved` [7:3]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[7:3]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[2].field_parts[0].bit_field[1]` `drv` | `drv` [2:0]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[2:0]; access=RW; desc="Sets pad drive capability."; values=0x0=>drv_weakest; 0x7=>drv_strongest; 0xn=>drv_n_7, n=1..6; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `drv`: 0x0=>drv_weakest; 0x7=>drv_strongest; 0xn=>drv_n_7, n=1..6.

Bit-field collection correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field part 1: `PAD_CTRL` at `0x03` (3)

Location: `registers[2].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `PAD_CTRL` | `PAD_CTRL` |
| physical_address | 0.4688 | 1.0 | `0x03` / `3` | {"hex":"0x03","decimal":"3","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "Configure pad behavior." (Table 8 pp.26-28; §8.3 p.30) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R/W | `RW` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `PAD_CTRL` | `PAD_CTRL` |
| physical_address | 0.4044 | 1.0 | `0x03` / `3` | [{"hex":"0x03","decimal":"3","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.3 p.30 register meaning; no functional deviation in v1 | "Configures relative pad drive capability to control signal over- or undershoot; drv=0 selects the weakest and drv=7 the strongest drive strength." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R/W | `RW` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x03 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x07 | `0x07` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "Default relative drive strength is 7 after boot." |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 4: `PMU_CMD_AGGR_SET`

v1 location: `registers[3]`; datasheet association: Table 8 row `PMU_CMD_AGGR_SET` at `0x04`.
Associated physical location: `0x04` (4).
Datasheet source: **Table 8 pp.26-28; §8.4 p.30**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[3].field_parts[0].bit_field[0]` `reserved` | `reserved` [7:6]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[7:6]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[3].field_parts[0].bit_field[1]` `avg` | `avg` [5:4]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[5:4]; access=RW; desc="Measurement averaging/noise performance setting."; values=0x00=>no_avg; no average; 0x01=>avg_2; average between 2 samples; 0x02=>avg_4; average between 4 samples; 0x03=>avg_8; average between 8 samples; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[3].field_parts[0].bit_field[2]` `odr` | `odr` [3:0]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[3:0]; access=RW; desc="Output data rate."; values=0x02=>odr_400hz; 400 Hz ODR; 0x03=>odr_200hz; 200 Hz ODR; 0x04=>odr_100hz; 100 Hz ODR; 0x05=>odr_50hz; 50 Hz ODR; 0x06=>odr_25hz; 25 Hz ODR; 0x07=>odr_12_5hz; 12.5 Hz ODR; 0x08=>odr_6_25hz; 6.25 Hz ODR; 0x09=>odr_3_125hz; 3.125 Hz ODR; 0x0a=>odr_1_5625hz; 1.5625 Hz ODR; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 3 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `avg`: 0x00=>no_avg; no average; 0x01=>avg_2; average between 2 samples; 0x02=>avg_4; average between 4 samples; 0x03=>avg_8; average between 8 samples | `odr`: 0x02=>odr_400hz; 400 Hz ODR; 0x03=>odr_200hz; 200 Hz ODR; 0x04=>odr_100hz; 100 Hz ODR; 0x05=>odr_50hz; 50 Hz ODR; 0x06=>odr_25hz; 25 Hz ODR; 0x07=>odr_12_5hz; 12.5 Hz ODR; 0x08=>odr_6_25hz; 6.25 Hz ODR; 0x09=>odr_3_125hz; 3.125 Hz ODR; 0x0a=>odr_1_5625hz; 1.5625 Hz ODR.

Bit-field collection correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**.

#### Field part 1: `PMU_CMD_AGGR_SET` at `0x04` (4)

Location: `registers[3].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `PMU_CMD_AGGR_SET` | `PMU_CMD_AGGR_SET` |
| physical_address | 0.4688 | 1.0 | `0x04` / `4` | {"hex":"0x04","decimal":"4","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "configuration of the ODR and AVG." (Table 8 pp.26-28; §8.4 p.30) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R/W | `RW` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `PMU_CMD_AGGR_SET` | `PMU_CMD_AGGR_SET` |
| physical_address | 0.4044 | 1.0 | `0x04` / `4` | [{"hex":"0x04","decimal":"4","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.4 p.30 register meaning; no functional deviation in v1 | "Configures output data rate and measurement averaging/noise performance. After changing odr or avg, an update command must be sent through PMU_CMD.pmu_cmd; BMM350_set_odr_performance performs this workflow." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R/W | `RW` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x04 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x14 | `0x14` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 5: `PMU_CMD_AXIS_EN`

v1 location: `registers[4]`; datasheet association: Table 8 row `PMU_CMD_AXIS_EN` at `0x05`.
Associated physical location: `0x05` (5).
Datasheet source: **Table 8 pp.26-28; §8.5 p.31**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[4].field_parts[0].bit_field[0]` `reserved` | `reserved` [7:3]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[7:3]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[4].field_parts[0].bit_field[1]` `en_z` | `en_z` [2:2]; access=W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[2:2]; access=W; desc="Enables axis Z."; values=0x00=>disable; Channel Disabled; 0x01=>enable; Channel Enabled; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[4].field_parts[0].bit_field[2]` `en_y` | `en_y` [1:1]; access=W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[1:1]; access=W; desc="Enables axis Y."; values=0x00=>disable; Channel Disabled; 0x01=>enable; Channel Enabled; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[4].field_parts[0].bit_field[3]` `en_x` | `en_x` [0:0]; access=W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[0:0]; access=W; desc="Enables axis X."; values=0x00=>disable; Channel Disabled; 0x01=>enable; Channel Enabled; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 3 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 4 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `en_z`: 0x00=>disable; Channel Disabled; 0x01=>enable; Channel Enabled | `en_y`: 0x00=>disable; Channel Disabled; 0x01=>enable; Channel Enabled | `en_x`: 0x00=>disable; Channel Disabled; 0x01=>enable; Channel Enabled.

Bit-field collection correctness = mean(1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.

#### Field part 1: `PMU_CMD_AXIS_EN` at `0x05` (5)

Location: `registers[4].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `PMU_CMD_AXIS_EN` | `PMU_CMD_AXIS_EN` |
| physical_address | 0.4688 | 1.0 | `0x05` / `5` | {"hex":"0x05","decimal":"5","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "axis configuration." (Table 8 pp.26-28; §8.5 p.31) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | W | `W` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `PMU_CMD_AXIS_EN` | `PMU_CMD_AXIS_EN` |
| physical_address | 0.4044 | 1.0 | `0x05` / `5` | [{"hex":"0x05","decimal":"5","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.5 p.31 register meaning; no functional deviation in v1 | "Configures which X, Y and Z axes are converted. Axis changes work only in suspend mode; hardware ignores on-the-fly changes in normal mode, and requests to disable all axes are ignored by the API." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | W | `W` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x05 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x07 | `0x07` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 6: `PMU_CMD`

v1 location: `registers[5]`; datasheet association: Table 8 row `PMU_CMD` at `0x06`.
Associated physical location: `0x06` (6).
Datasheet source: **Table 8 pp.26-28; §8.6 p.32**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[5].field_parts[0].bit_field[0]` `reserved` | `reserved` [7:4]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[7:4]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[5].field_parts[0].bit_field[1]` `pmu_cmd` | `pmu_cmd` [3:0]; access=W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[3:0]; access=W; desc="Command for PMU mode switch and related operations."; values=0x00=>SUS; go to SUSPEND mode; 0x01=>NM; go to NORMAL mode; 0x02=>UPD_OAE; update ODR and averaging parameters; wait for data ready after busy clears before another update; 0x03=>FM; go to FORCED mode with full CRST recharge; 0x04=>FM_FAST; go to FORCED mode with fast CRST recharge; 0x05=>FGR; flux-guide reset with full CRST recharge; 0x06=>FGR_FAST; flux-guide reset with fast CRST recharge; 0x07=>BR; bit reset with full CRST recharge; 0x08=>BR_FAST; bit reset with fast CRST recharge; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `pmu_cmd`: 0x00=>SUS; go to SUSPEND mode; 0x01=>NM; go to NORMAL mode; 0x02=>UPD_OAE; update ODR and averaging parameters; wait for data ready after busy clears before another update; 0x03=>FM; go to FORCED mode with full CRST recharge; 0x04=>FM_FAST; go to FORCED mode with fast CRST recharge; 0x05=>FGR; flux-guide reset with full CRST recharge; 0x06=>FGR_FAST; flux-guide reset with fast CRST recharge; 0x07=>BR; bit reset with full CRST recharge; 0x08=>BR_FAST; bit reset with fast CRST recharge.

Bit-field collection correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field part 1: `PMU_CMD` at `0x06` (6)

Location: `registers[5].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `PMU_CMD` | `PMU_CMD` |
| physical_address | 0.4688 | 1.0 | `0x06` / `6` | {"hex":"0x06","decimal":"6","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "PMU cmd configuration." (Table 8 pp.26-28; §8.6 p.32) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | W | `W` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `PMU_CMD` | `PMU_CMD` |
| physical_address | 0.4044 | 1.0 | `0x06` / `6` | [{"hex":"0x06","decimal":"6","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.6 p.32 register meaning; no functional deviation in v1 | "Issues PMU mode-switch, forced-mode, ODR/averaging-update and reset commands. Forced measurements are requested with FM or FM_FAST while suspended; requests during normal mode or an unfinished conversion are ignored." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | W | `W` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x06 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 7: `PMU_CMD_STATUS_0`

v1 location: `registers[6]`; datasheet association: Table 8 row `PMU_CMD_STATUS_0` at `0x07`.
Associated physical location: `0x07` (7).
Datasheet source: **Table 8 pp.26-28; §8.7 p.33**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[6].field_parts[0].bit_field[0]` `reserved` | `reserved` [7:5]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[7:5]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[6].field_parts[0].bit_field[1]` `cmd_is_illegal` | `cmd_is_illegal` [4:4]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[4:4]; access=R; desc="Indicates that the command value is not allowed."; values=0x0=>cmd_ok; 0x1=>illegal; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[6].field_parts[0].bit_field[2]` `pwr_mode_is_normal` | `pwr_mode_is_normal` [3:3]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[3:3]; access=R; desc="Indicates whether the chip is in normal power mode."; values=0x0=>not_normal; 0x1=>normal_mode; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[6].field_parts[0].bit_field[3]` `AVG_ovwr` | `AVG_ovwr` [2:2]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[2:2]; access=R; desc="Indicates that the previous averaging setting was overwritten."; values=0x0=>avg_nochange; 0x1=>avg_ovwr; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[6].field_parts[0].bit_field[4]` `ODR_ovwr` | `ODR_ovwr` [1:1]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[1:1]; access=R; desc="Indicates that the previous ODR setting was overwritten."; values=0x0=>odr_nochange; 0x1=>odr_ovwr; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[6].field_parts[0].bit_field[5]` `pmu_cmd_busy` | `pmu_cmd_busy` [0:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[0:0]; access=R; desc="The previous PMU command is still processing."; values=0x0=>pmu_ok; 0x1=>pmu_busy; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 3 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 4 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 5 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 6 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `cmd_is_illegal`: 0x0=>cmd_ok; 0x1=>illegal | `pwr_mode_is_normal`: 0x0=>not_normal; 0x1=>normal_mode | `AVG_ovwr`: 0x0=>avg_nochange; 0x1=>avg_ovwr | `ODR_ovwr`: 0x0=>odr_nochange; 0x1=>odr_ovwr | `pmu_cmd_busy`: 0x0=>pmu_ok; 0x1=>pmu_busy.

Bit-field collection correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.

#### Field part 1: `PMU_CMD_STATUS_0` at `0x07` (7)

Location: `registers[6].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `PMU_CMD_STATUS_0` | `PMU_CMD_STATUS_0` |
| physical_address | 0.4688 | 1.0 | `0x07` / `7` | {"hex":"0x07","decimal":"7","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "Sensor Status Flag." (Table 8 pp.26-28; §8.7 p.33) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `PMU_CMD_STATUS_0` | `PMU_CMD_STATUS_0` |
| physical_address | 0.4044 | 1.0 | `0x07` / `7` | [{"hex":"0x07","decimal":"7","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.7 p.33 register meaning; no functional deviation in v1 | "Reports PMU command processing, illegal-command status, normal-mode state, and overwritten ODR or averaging settings." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x07 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 8: `PMU_CMD_STATUS_1`

v1 location: `registers[7]`; datasheet association: Table 8 row `PMU_CMD_STATUS_1` at `0x08`.
Associated physical location: `0x08` (8).
Datasheet source: **Table 8 pp.26-28; §8.8 p.34**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[7].field_parts[0].bit_field[0]` `reserved` | `reserved` [7:6]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[7:6]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[7].field_parts[0].bit_field[1]` `pmu_avg_s` | `pmu_avg_s` [5:4]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[5:4]; access=R; desc="Actual effective PMU_CMD_AGGR_SET.avg value."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[7].field_parts[0].bit_field[2]` `pmu_odr_s` | `pmu_odr_s` [3:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[3:0]; access=R; desc="Actual effective PMU_CMD_AGGR_SET.odr value."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 3 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**.

#### Field part 1: `PMU_CMD_STATUS_1` at `0x08` (8)

Location: `registers[7].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `PMU_CMD_STATUS_1` | `PMU_CMD_STATUS_1` |
| physical_address | 0.4688 | 1.0 | `0x08` / `8` | {"hex":"0x08","decimal":"8","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "PMU Status Flag." (Table 8 pp.26-28; §8.8 p.34) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `PMU_CMD_STATUS_1` | `PMU_CMD_STATUS_1` |
| physical_address | 0.4044 | 1.0 | `0x08` / `8` | [{"hex":"0x08","decimal":"8","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.8 p.34 register meaning; no functional deviation in v1 | "Reports the actual effective PMU output-data-rate and averaging settings." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x08 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 9: `I3C_ERR`

v1 location: `registers[8]`; datasheet association: Table 8 row `I3C_ERR` at `0x09`.
Associated physical location: `0x09` (9).
Datasheet source: **Table 8 pp.26-28; §8.9 p.34**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[8].field_parts[0].bit_field[0]` `reserved` | `reserved` [7:4]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[7:4]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[8].field_parts[0].bit_field[1]` `i3c_error_3` | `i3c_error_3` [3:3]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[3:3]; access=RW; desc="S0/S1 error; clears automatically after 60 us or upon an HDR-exit pattern."; values=0x0=>i3c3_noerror; 0x1=>i3c3_error; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[8].field_parts[0].bit_field[2]` `Reserved` | `Reserved` [2:1]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[2:1]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[8].field_parts[0].bit_field[3]` `i3c_error_0` | `i3c_error_0` [0:0]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[0:0]; access=RW; desc="Indicates an SDR parity error."; values=0x0=>i3c0_noerror; 0x1=>i3c0_error; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 3 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 4 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `i3c_error_3`: 0x0=>i3c3_noerror; 0x1=>i3c3_error | `i3c_error_0`: 0x0=>i3c0_noerror; 0x1=>i3c0_error.

Bit-field collection correctness = mean(1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.

#### Field part 1: `I3C_ERR` at `0x09` (9)

Location: `registers[8].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `I3C_ERR` | `I3C_ERR` |
| physical_address | 0.4688 | 1.0 | `0x09` / `9` | {"hex":"0x09","decimal":"9","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "I3C Bus Error Statistics. Will be cleared on read. If the user writes a 1 into any status bit, this will also clear that bit." (Table 8 pp.26-28; §8.9 p.34) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R/W | `RW` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `I3C_ERR` | `I3C_ERR` |
| physical_address | 0.4044 | 1.0 | `0x09` / `9` | [{"hex":"0x09","decimal":"9","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.9 p.34 register meaning; no functional deviation in v1 | "Reports I3C bus errors. Status is cleared on read, and writing 1 to a status bit also clears that bit." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R/W | `RW` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x09 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 10: `I2C_WDT_SET`

v1 location: `registers[9]`; datasheet association: Table 8 row `I2C_WDT_SET` at `0x0A`.
Associated physical location: `0x0A` (10).
Datasheet source: **Table 8 pp.26-28; §8.10 pp.34-35**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[9].field_parts[0].bit_field[0]` `reserved` | `reserved` [7:2]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[7:2]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[9].field_parts[0].bit_field[1]` `i2c_wdt_sel` | `i2c_wdt_sel` [1:1]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[1:1]; access=RW; desc="I2C watchdog timeout period."; values=0x00=>short; timeout after 1.28ms; 0x01=>long; timeout after 40.96ms; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[9].field_parts[0].bit_field[2]` `i2c_wdt_en` | `i2c_wdt_en` [0:0]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[0:0]; access=RW; desc="I2C watchdog enable."; values=0x00=>disabled; Disable I2C watchdog; 0x01=>enabled; Enable I2C watchdog; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 3 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `i2c_wdt_sel`: 0x00=>short; timeout after 1.28ms; 0x01=>long; timeout after 40.96ms | `i2c_wdt_en`: 0x00=>disabled; Disable I2C watchdog; 0x01=>enabled; Enable I2C watchdog.

Bit-field collection correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**.

#### Field part 1: `I2C_WDT_SET` at `0x0A` (10)

Location: `registers[9].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `I2C_WDT_SET` | `I2C_WDT_SET` |
| physical_address | 0.4688 | 1.0 | `0x0A` / `10` | {"hex":"0x0A","decimal":"10","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "i2c watchdog configure registers." (Table 8 pp.26-28; §8.10 pp.34-35) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R/W | `RW` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `I2C_WDT_SET` | `I2C_WDT_SET` |
| physical_address | 0.4044 | 1.0 | `0x0A` / `10` | [{"hex":"0x0A","decimal":"10","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.10 pp.34-35 register meaning; no functional deviation in v1 | "Enables or disables the I2C watchdog and selects its timeout period. The watchdog resets the I2C core if no STOP condition is detected within the configured time and is inactive in I3C mode." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R/W | `RW` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x0A |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 11: `INT_CTRL`

v1 location: `registers[10]`; datasheet association: Table 8 row `INT_CTRL` at `0x2E`.
Associated physical location: `0x2E` (46).
Datasheet source: **Table 8 pp.26-28; §8.11 p.35**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[10].field_parts[0].bit_field[0]` `drdy_data_reg_en` | `drdy_data_reg_en` [7:7]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[7:7]; access=RW; desc="Enables the magnetic data-ready interrupt for the INT pin and INT_STATUS."; values=0x00=>disabled; 0x01=>enabled; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[10].field_parts[0].bit_field[1]` `reserved` | `reserved` [6:4]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[6:4]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[10].field_parts[0].bit_field[2]` `int_output_en` | `int_output_en` [3:3]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[3:3]; access=RW; desc="Enables mapping of the interrupt to the INT pin; reserved on A-Si."; values=0x00=>off; Output disabled; 0x01=>on; Output enabled; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[10].field_parts[0].bit_field[3]` `int_od` | `int_od` [2:2]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[2:2]; access=RW; desc="Configures open-drain or push-pull output."; values=0x00=>open-drain; 0x01=>push-pull; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[10].field_parts[0].bit_field[4]` `int_pol` | `int_pol` [1:1]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[1:1]; access=RW; desc="Configures interrupt polarity."; values=0x00=>active_low; 0x01=>active_high; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[10].field_parts[0].bit_field[5]` `int_mode` | `int_mode` [0:0]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[0:0]; access=RW; desc="Configures pulsed or latched interrupt operation."; values=0x00=>pulsed; 0x01=>latched; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 3 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 4 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 5 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 6 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `drdy_data_reg_en`: 0x00=>disabled; 0x01=>enabled | `int_output_en`: 0x00=>off; Output disabled; 0x01=>on; Output enabled | `int_od`: 0x00=>open-drain; 0x01=>push-pull | `int_pol`: 0x00=>active_low; 0x01=>active_high | `int_mode`: 0x00=>pulsed; 0x01=>latched.

Bit-field collection correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.

#### Field part 1: `INT_CTRL` at `0x2E` (46)

Location: `registers[10].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `INT_CTRL` | `INT_CTRL` |
| physical_address | 0.4688 | 1.0 | `0x2E` / `46` | {"hex":"0x2E","decimal":"46","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "Configuration of interrupts for INT_STATUS register and INT pin." (Table 8 pp.26-28; §8.11 p.35) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R/W | `RW` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `INT_CTRL` | `INT_CTRL` |
| physical_address | 0.4044 | 1.0 | `0x2E` / `46` | [{"hex":"0x2E","decimal":"46","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.11 p.35 register meaning; no functional deviation in v1 | "Configures data-ready interrupt enable, mapping to the INT pin, output drive, polarity, and pulsed or latched operation. int_output_en is unsupported and reserved on A-Si." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R/W | `RW` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x2E |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 12: `INT_CTRL_IBI`

v1 location: `registers[11]`; datasheet association: Table 8 row `INT_CTRL_IBI` at `0x2F`.
Associated physical location: `0x2F` (47).
Datasheet source: **Table 8 pp.26-28; §8.12 p.36**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[11].field_parts[0].bit_field[0]` `reserved` | `reserved` [7:5]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[7:5]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[11].field_parts[0].bit_field[1]` `clear_drdy_int_status_upon_ibi` | `clear_drdy_int_status_upon_ibi` [4:4]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[4:4]; access=RW; desc="Clears INT_STATUS.drdy upon I3C IBI."; values=0x00=>disabled; 0x01=>enabled; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[11].field_parts[0].bit_field[2]` `reserved` | `reserved` [3:1]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[3:1]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[11].field_parts[0].bit_field[3]` `drdy_int_map_to_ibi` | `drdy_int_map_to_ibi` [0:0]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[0:0]; access=RW; desc="Maps the data-ready interrupt to I3C IBI."; values=0x00=>disabled; 0x01=>enabled; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 3 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 4 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `clear_drdy_int_status_upon_ibi`: 0x00=>disabled; 0x01=>enabled | `drdy_int_map_to_ibi`: 0x00=>disabled; 0x01=>enabled.

Bit-field collection correctness = mean(1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.

#### Field part 1: `INT_CTRL_IBI` at `0x2F` (47)

Location: `registers[11].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `INT_CTRL_IBI` | `INT_CTRL_IBI` |
| physical_address | 0.4688 | 1.0 | `0x2F` / `47` | {"hex":"0x2F","decimal":"47","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "Configuration of interrupts features related to IBI." (Table 8 pp.26-28; §8.12 p.36) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R/W | `RW` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `INT_CTRL_IBI` | `INT_CTRL_IBI` |
| physical_address | 0.4044 | 1.0 | `0x2F` / `47` | [{"hex":"0x2F","decimal":"47","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.12 p.36 register meaning; no functional deviation in v1 | "Configures data-ready interrupt features for I3C in-band interrupts, including IBI mapping and automatic clearing of interrupt status. INT_CTRL.drdy_data_reg_en must also enable the data-ready interrupt." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R/W | `RW` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x2F |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 13: `INT_STATUS`

v1 location: `registers[12]`; datasheet association: Table 8 row `INT_STATUS` at `0x30`.
Associated physical location: `0x30` (48).
Datasheet source: **Table 8 pp.26-28; §8.13 p.36**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[12].field_parts[0].bit_field[0]` `reserved` | `reserved` [7:3]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[7:3]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[12].field_parts[0].bit_field[1]` `drdy_data_reg` | `drdy_data_reg` [2:2]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[2:2]; access=RW; desc="Magnetic data-ready interrupt status."; values=0x0=>no_new data; 0x1=>new_data; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[12].field_parts[0].bit_field[2]` `reserved` | `reserved` [1:1]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[1:1]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[12].field_parts[0].bit_field[3]` `reserved` | `reserved` [0:0]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[0:0]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 3 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 4 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `drdy_data_reg`: 0x0=>no_new data; 0x1=>new_data.

Bit-field collection correctness = mean(1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.

#### Field part 1: `INT_STATUS` at `0x30` (48)

Location: `registers[12].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `INT_STATUS` | `INT_STATUS` |
| physical_address | 0.4688 | 1.0 | `0x30` / `48` | {"hex":"0x30","decimal":"48","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "Interrupt Status. Will be cleared on read. If the user writes a 1 into any status bit, this will also clear that bit." (Table 8 pp.26-28; §8.13 p.36) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R/W | `RW` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `INT_STATUS` | `INT_STATUS` |
| physical_address | 0.4044 | 1.0 | `0x30` / `48` | [{"hex":"0x30","decimal":"48","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.13 p.36 register meaning; no functional deviation in v1 | "Reports whether new magnetic data is available. It clears on read; writing 1 to a status bit also clears it. In latched mode reading drdy_data_reg clears it, while in non-latched mode it clears after 1.25ms." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R/W | `RW` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x30 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 14: `MAG_X_XLSB`

v1 location: `registers[13]`; datasheet association: Table 8 row `MAG_X_XLSB` at `0x31`.
Associated physical location: `0x31` (49).
Datasheet source: **Table 8 pp.26-28; §8.14 p.37**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[13].field_parts[0].bit_field[0]` `data_x_7_0` | `data_x_7_0` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Magnetometer X-axis data bits 7:0."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `MAG_X_XLSB` at `0x31` (49)

Location: `registers[13].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `MAG_X_XLSB` | `MAG_X_XLSB` |
| physical_address | 0.4688 | 1.0 | `0x31` / `49` | {"hex":"0x31","decimal":"49","bank":"","page":"","description":"Magnetometer X-axis extreme LSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Magnetometer X-axis extreme LSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `MAG_X_XLSB` | `MAG_X_XLSB` |
| physical_address | 0.4044 | 1.0 | `0x31` / `49` | [{"hex":"0x31","decimal":"49","bank":"","page":"","description":"Magnetometer X-axis extreme LSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.14 p.37 register meaning; no functional deviation in v1 | "Contains magnetometer X-axis data bits 7:0. Data registers should be read in a single burst to prevent inconsistent updates, and host compensation routines correct offset, sensitivity, gain and temperature effects." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x31 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 15: `MAG_X_LSB`

v1 location: `registers[14]`; datasheet association: Table 8 row `MAG_X_LSB` at `0x32`.
Associated physical location: `0x32` (50).
Datasheet source: **Table 8 pp.26-28; §8.15 p.37**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[14].field_parts[0].bit_field[0]` `data_x_15_8` | `data_x_15_8` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Magnetometer X-axis data bits 15:8."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `MAG_X_LSB` at `0x32` (50)

Location: `registers[14].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `MAG_X_LSB` | `MAG_X_LSB` |
| physical_address | 0.4688 | 1.0 | `0x32` / `50` | {"hex":"0x32","decimal":"50","bank":"","page":"","description":"Magnetometer X-axis LSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Magnetometer X-axis LSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `MAG_X_LSB` | `MAG_X_LSB` |
| physical_address | 0.4044 | 1.0 | `0x32` / `50` | [{"hex":"0x32","decimal":"50","bank":"","page":"","description":"Magnetometer X-axis LSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.15 p.37 register meaning; no functional deviation in v1 | "Contains magnetometer X-axis data bits 15:8. Data registers should be read in a single burst to prevent inconsistent updates, and host compensation routines correct offset, sensitivity, gain and temperature effects." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x32 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 16: `MAG_X_MSB`

v1 location: `registers[15]`; datasheet association: Table 8 row `MAG_X_MSB` at `0x33`.
Associated physical location: `0x33` (51).
Datasheet source: **Table 8 pp.26-28; §8.16 p.37**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[15].field_parts[0].bit_field[0]` `data_x_23_16` | `data_x_23_16` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Magnetometer X-axis data bits 23:16."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `MAG_X_MSB` at `0x33` (51)

Location: `registers[15].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `MAG_X_MSB` | `MAG_X_MSB` |
| physical_address | 0.4688 | 1.0 | `0x33` / `51` | {"hex":"0x33","decimal":"51","bank":"","page":"","description":"Magnetometer X-axis MSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Magnetometer X-axis MSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `MAG_X_MSB` | `MAG_X_MSB` |
| physical_address | 0.4044 | 1.0 | `0x33` / `51` | [{"hex":"0x33","decimal":"51","bank":"","page":"","description":"Magnetometer X-axis MSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.16 p.37 register meaning; no functional deviation in v1 | "Contains magnetometer X-axis data bits 23:16. Data registers should be read in a single burst to prevent inconsistent updates, and host compensation routines correct offset, sensitivity, gain and temperature effects." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x33 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 17: `MAG_Y_XLSB`

v1 location: `registers[16]`; datasheet association: Table 8 row `MAG_Y_XLSB` at `0x34`.
Associated physical location: `0x34` (52).
Datasheet source: **Table 8 pp.26-28; §8.17 p.38**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[16].field_parts[0].bit_field[0]` `data_y_7_0` | `data_y_7_0` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Magnetometer Y-axis data bits 7:0."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `MAG_Y_XLSB` at `0x34` (52)

Location: `registers[16].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `MAG_Y_XLSB` | `MAG_Y_XLSB` |
| physical_address | 0.4688 | 1.0 | `0x34` / `52` | {"hex":"0x34","decimal":"52","bank":"","page":"","description":"Magnetometer Y-axis extreme LSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Magnetometer Y-axis extreme LSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `MAG_Y_XLSB` | `MAG_Y_XLSB` |
| physical_address | 0.4044 | 1.0 | `0x34` / `52` | [{"hex":"0x34","decimal":"52","bank":"","page":"","description":"Magnetometer Y-axis extreme LSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.17 p.38 register meaning; no functional deviation in v1 | "Contains magnetometer Y-axis data bits 7:0. Data retrieval follows the magnetic-data access described for MAG_X_XLSB; use a burst read and compensation routines." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x34 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 18: `MAG_Y_LSB`

v1 location: `registers[17]`; datasheet association: Table 8 row `MAG_Y_LSB` at `0x35`.
Associated physical location: `0x35` (53).
Datasheet source: **Table 8 pp.26-28; §8.18 p.38**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[17].field_parts[0].bit_field[0]` `data_y_15_8` | `data_y_15_8` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Magnetometer Y-axis data bits 15:8."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `MAG_Y_LSB` at `0x35` (53)

Location: `registers[17].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `MAG_Y_LSB` | `MAG_Y_LSB` |
| physical_address | 0.4688 | 1.0 | `0x35` / `53` | {"hex":"0x35","decimal":"53","bank":"","page":"","description":"Magnetometer Y-axis LSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Magnetometer Y-axis LSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `MAG_Y_LSB` | `MAG_Y_LSB` |
| physical_address | 0.4044 | 1.0 | `0x35` / `53` | [{"hex":"0x35","decimal":"53","bank":"","page":"","description":"Magnetometer Y-axis LSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.18 p.38 register meaning; no functional deviation in v1 | "Contains magnetometer Y-axis data bits 15:8. Magnetic data should be read in a single burst and processed by the documented compensation routines." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x35 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 19: `MAG_Y_MSB`

v1 location: `registers[18]`; datasheet association: Table 8 row `MAG_Y_MSB` at `0x36`.
Associated physical location: `0x36` (54).
Datasheet source: **Table 8 pp.26-28; §8.19 p.38**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[18].field_parts[0].bit_field[0]` `data_y_23_16` | `data_y_23_16` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Magnetometer Y-axis data bits 23:16."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `MAG_Y_MSB` at `0x36` (54)

Location: `registers[18].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `MAG_Y_MSB` | `MAG_Y_MSB` |
| physical_address | 0.4688 | 1.0 | `0x36` / `54` | {"hex":"0x36","decimal":"54","bank":"","page":"","description":"Magnetometer Y-axis MSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Magnetometer Y-axis MSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `MAG_Y_MSB` | `MAG_Y_MSB` |
| physical_address | 0.4044 | 1.0 | `0x36` / `54` | [{"hex":"0x36","decimal":"54","bank":"","page":"","description":"Magnetometer Y-axis MSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.19 p.38 register meaning; no functional deviation in v1 | "Contains magnetometer Y-axis data bits 23:16. Magnetic data should be read in a single burst and processed by the documented compensation routines." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x36 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 20: `MAG_Z_XLSB`

v1 location: `registers[19]`; datasheet association: Table 8 row `MAG_Z_XLSB` at `0x37`.
Associated physical location: `0x37` (55).
Datasheet source: **Table 8 pp.26-28; §8.20 p.38**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[19].field_parts[0].bit_field[0]` `data_z_7_0` | `data_z_7_0` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Magnetometer Z-axis data bits 7:0."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `MAG_Z_XLSB` at `0x37` (55)

Location: `registers[19].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `MAG_Z_XLSB` | `MAG_Z_XLSB` |
| physical_address | 0.4688 | 1.0 | `0x37` / `55` | {"hex":"0x37","decimal":"55","bank":"","page":"","description":"Magnetometer Z-axis extreme LSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Magnetometer Z-axis extreme LSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `MAG_Z_XLSB` | `MAG_Z_XLSB` |
| physical_address | 0.4044 | 1.0 | `0x37` / `55` | [{"hex":"0x37","decimal":"55","bank":"","page":"","description":"Magnetometer Z-axis extreme LSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.20 p.38 register meaning; no functional deviation in v1 | "Contains magnetometer Z-axis data bits 7:0. Magnetic data should be read in a single burst and processed by the documented compensation routines." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x37 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 21: `MAG_Z_LSB`

v1 location: `registers[20]`; datasheet association: Table 8 row `MAG_Z_LSB` at `0x38`.
Associated physical location: `0x38` (56).
Datasheet source: **Table 8 pp.26-28; §8.21 p.39**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[20].field_parts[0].bit_field[0]` `data_z_15_8` | `data_z_15_8` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Magnetometer Z-axis data bits 15:8."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `MAG_Z_LSB` at `0x38` (56)

Location: `registers[20].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `MAG_Z_LSB` | `MAG_Z_LSB` |
| physical_address | 0.4688 | 1.0 | `0x38` / `56` | {"hex":"0x38","decimal":"56","bank":"","page":"","description":"Magnetometer Z-axis LSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Magnetometer Z-axis LSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `MAG_Z_LSB` | `MAG_Z_LSB` |
| physical_address | 0.4044 | 1.0 | `0x38` / `56` | [{"hex":"0x38","decimal":"56","bank":"","page":"","description":"Magnetometer Z-axis LSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.21 p.39 register meaning; no functional deviation in v1 | "Contains magnetometer Z-axis data bits 15:8. Magnetic data should be read in a single burst and processed by the documented compensation routines." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x38 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 22: `MAG_Z_MSB`

v1 location: `registers[21]`; datasheet association: Table 8 row `MAG_Z_MSB` at `0x39`.
Associated physical location: `0x39` (57).
Datasheet source: **Table 8 pp.26-28; §8.22 p.39**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[21].field_parts[0].bit_field[0]` `data_z_23_16` | `data_z_23_16` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Magnetometer Z-axis data bits 23:16."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `MAG_Z_MSB` at `0x39` (57)

Location: `registers[21].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `MAG_Z_MSB` | `MAG_Z_MSB` |
| physical_address | 0.4688 | 1.0 | `0x39` / `57` | {"hex":"0x39","decimal":"57","bank":"","page":"","description":"Magnetometer Z-axis MSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Magnetometer Z-axis MSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `MAG_Z_MSB` | `MAG_Z_MSB` |
| physical_address | 0.4044 | 1.0 | `0x39` / `57` | [{"hex":"0x39","decimal":"57","bank":"","page":"","description":"Magnetometer Z-axis MSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.22 p.39 register meaning; no functional deviation in v1 | "Contains magnetometer Z-axis data bits 23:16. Magnetic data should be read in a single burst and processed by the documented compensation routines." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x39 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 23: `TEMP_XLSB`

v1 location: `registers[22]`; datasheet association: Table 8 row `TEMP_XLSB` at `0x3A`.
Associated physical location: `0x3A` (58).
Datasheet source: **Table 8 pp.26-28; §8.23 p.39**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[22].field_parts[0].bit_field[0]` `data_t_7_0` | `data_t_7_0` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Temperature data bits 7:0."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `TEMP_XLSB` at `0x3A` (58)

Location: `registers[22].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `TEMP_XLSB` | `TEMP_XLSB` |
| physical_address | 0.4688 | 1.0 | `0x3A` / `58` | {"hex":"0x3A","decimal":"58","bank":"","page":"","description":"Temperature extreme LSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Temperature extreme LSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `TEMP_XLSB` | `TEMP_XLSB` |
| physical_address | 0.4044 | 1.0 | `0x3A` / `58` | [{"hex":"0x3A","decimal":"58","bank":"","page":"","description":"Temperature extreme LSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.23 p.39 register meaning; no functional deviation in v1 | "Contains temperature data bits 7:0. Temperature and magnetic data should be obtained by burst read and processed by the documented compensation routines." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x3A |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 24: `TEMP_LSB`

v1 location: `registers[23]`; datasheet association: Table 8 row `TEMP_LSB` at `0x3B`.
Associated physical location: `0x3B` (59).
Datasheet source: **Table 8 pp.26-28; §8.24 p.39**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[23].field_parts[0].bit_field[0]` `data_t_15_8` | `data_t_15_8` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Temperature data bits 15:8."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `TEMP_LSB` at `0x3B` (59)

Location: `registers[23].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `TEMP_LSB` | `TEMP_LSB` |
| physical_address | 0.4688 | 1.0 | `0x3B` / `59` | {"hex":"0x3B","decimal":"59","bank":"","page":"","description":"Temperature LSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Temperature LSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `TEMP_LSB` | `TEMP_LSB` |
| physical_address | 0.4044 | 1.0 | `0x3B` / `59` | [{"hex":"0x3B","decimal":"59","bank":"","page":"","description":"Temperature LSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.24 p.39 register meaning; no functional deviation in v1 | "Contains temperature data bits 15:8. Temperature and magnetic data should be obtained by burst read and processed by the documented compensation routines." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x3B |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 25: `TEMP_MSB`

v1 location: `registers[24]`; datasheet association: Table 8 row `TEMP_MSB` at `0x3C`.
Associated physical location: `0x3C` (60).
Datasheet source: **Table 8 pp.26-28; §8.25 p.40**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[24].field_parts[0].bit_field[0]` `data_t_23_16` | `data_t_23_16` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Temperature data bits 23:16."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `TEMP_MSB` at `0x3C` (60)

Location: `registers[24].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `TEMP_MSB` | `TEMP_MSB` |
| physical_address | 0.4688 | 1.0 | `0x3C` / `60` | {"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Temperature MSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Temperature MSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `TEMP_MSB` | `TEMP_MSB` |
| physical_address | 0.4044 | 1.0 | `0x3C` / `60` | [{"hex":"0x3C","decimal":"60","bank":"","page":"","description":"Temperature MSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.25 p.40 register meaning; no functional deviation in v1 | "Contains temperature data bits 23:16. Temperature and magnetic data should be obtained by burst read and processed by the documented compensation routines." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x3C |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 26: `SENSORTIME_XLSB`

v1 location: `registers[25]`; datasheet association: Table 8 row `SENSORTIME_XLSB` at `0x3D`.
Associated physical location: `0x3D` (61).
Datasheet source: **Table 8 pp.26-28; §8.26 p.40; functional §5.2.2 p.18**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[25].field_parts[0].bit_field[0]` `data_st_7_0` | `data_st_7_0` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Sensor timer bits 7:0."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `SENSORTIME_XLSB` at `0x3D` (61)

Location: `registers[25].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `SENSORTIME_XLSB` | `SENSORTIME_XLSB` |
| physical_address | 0.4688 | 1.0 | `0x3D` / `61` | {"hex":"0x3D","decimal":"61","bank":"","page":"","description":"Sensor timer extreme LSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Sensor timer extreme LSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `SENSORTIME_XLSB` | `SENSORTIME_XLSB` |
| physical_address | 0.4044 | 1.0 | `0x3D` / `61` | [{"hex":"0x3D","decimal":"61","bank":"","page":"","description":"Sensor timer extreme LSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.26 p.40; functional §5.2.2 p.18 register meaning; no functional deviation in v1 | "Contains sensor-time bits 7:0. Together with addresses 0x3E and 0x3F, the three sensortime registers form a 24-bit value when new data is generated. The counter wraps without saturation and is normally incremented only in normal mode unless CTRL_USER.cfg_sens_tim_aon is set." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x3D |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 27: `SENSORTIME_LSB`

v1 location: `registers[26]`; datasheet association: Table 8 row `SENSORTIME_LSB` at `0x3E`.
Associated physical location: `0x3E` (62).
Datasheet source: **Table 8 pp.26-28; §8.27 p.40; functional §5.2.2 p.18**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[26].field_parts[0].bit_field[0]` `data_st_15_8` | `data_st_15_8` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Sensor timer bits 15:8."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `SENSORTIME_LSB` at `0x3E` (62)

Location: `registers[26].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `SENSORTIME_LSB` | `SENSORTIME_LSB` |
| physical_address | 0.4688 | 1.0 | `0x3E` / `62` | {"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Sensor timer LSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Sensor timer LSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `SENSORTIME_LSB` | `SENSORTIME_LSB` |
| physical_address | 0.4044 | 1.0 | `0x3E` / `62` | [{"hex":"0x3E","decimal":"62","bank":"","page":"","description":"Sensor timer LSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.27 p.40; functional §5.2.2 p.18 register meaning; no functional deviation in v1 | "Contains sensor-time bits 15:8. Together with addresses 0x3D and 0x3F, the three sensortime registers form a 24-bit value when new data is generated." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x3E |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 28: `SENSORTIME_MSB`

v1 location: `registers[27]`; datasheet association: Table 8 row `SENSORTIME_MSB` at `0x3F`.
Associated physical location: `0x3F` (63).
Datasheet source: **Table 8 pp.26-28; §8.28 p.40; functional §5.2.2 p.18**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[27].field_parts[0].bit_field[0]` `data_st_23_16` | `data_st_23_16` [7:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=R; desc="Sensor timer bits 23:16."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `SENSORTIME_MSB` at `0x3F` (63)

Location: `registers[27].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `SENSORTIME_MSB` | `SENSORTIME_MSB` |
| physical_address | 0.4688 | 1.0 | `0x3F` / `63` | {"hex":"0x3F","decimal":"63","bank":"","page":"","description":"Sensor timer MSB byte."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Sensor timer MSB byte." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `SENSORTIME_MSB` | `SENSORTIME_MSB` |
| physical_address | 0.4044 | 1.0 | `0x3F` / `63` | [{"hex":"0x3F","decimal":"63","bank":"","page":"","description":"Sensor timer MSB byte."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.28 p.40; functional §5.2.2 p.18 register meaning; no functional deviation in v1 | "Contains sensor-time bits 23:16. Together with addresses 0x3D and 0x3E, the three sensortime registers form a 24-bit value when new data is generated." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x3F |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x7F | `0x7F` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 29: `OTP_CMD_REG`

v1 location: `registers[28]`; datasheet association: Table 8 row `OTP_CMD_REG` at `0x50`.
Associated physical location: `0x50` (80).
Datasheet source: **Table 8 pp.26-28; §8.29 p.41**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[28].field_parts[0].bit_field[0]` `otp_cmd` | `otp_cmd` [7:5]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[7:5]; access=RW; desc="OTP command."; values=001=>DIR_READ; 010=>DIR_PRGM_1B; 011=>DIR_PRGM; 100=>PWR_OFF_OTP; 101=>EXT_READ; 111=>EXT_PRGM; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[28].field_parts[0].bit_field[1]` `word_addr` | `word_addr` [4:0]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[4:0]; access=RW; desc="Word address for DIR_READ, DIR_PRGM_1B or DIR_PRGM; word start address for EXT_READ or EXT_PRGM."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `otp_cmd`: 001=>DIR_READ; 010=>DIR_PRGM_1B; 011=>DIR_PRGM; 100=>PWR_OFF_OTP; 101=>EXT_READ; 111=>EXT_PRGM.

Bit-field collection correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field part 1: `OTP_CMD_REG` at `0x50` (80)

Location: `registers[28].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `OTP_CMD_REG` | `OTP_CMD_REG` |
| physical_address | 0.4688 | 1.0 | `0x50` / `80` | {"hex":"0x50","decimal":"80","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "OTP command and word address register." (Table 8 pp.26-28; §8.29 p.41) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R/W | `RW` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `OTP_CMD_REG` | `OTP_CMD_REG` |
| physical_address | 0.4044 | 1.0 | `0x50` / `80` | [{"hex":"0x50","decimal":"80","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.29 p.41 register meaning; no functional deviation in v1 | "Selects an OTP command and its word address or word start address." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R/W | `RW` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x50 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 30: `OTP_DATA_MSB_REG`

v1 location: `registers[29]`; datasheet association: Table 8 row `OTP_DATA_MSB_REG` at `0x52`.
Associated physical location: `0x52` (82).
Datasheet source: **Table 8 pp.26-28; §8.30 p.41**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[29].field_parts[0].bit_field[0]` `otp_mem_data_msb` | `otp_mem_data_msb` [7:0]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=RW; desc="Most significant byte of 16-bit memory word."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `OTP_DATA_MSB_REG` at `0x52` (82)

Location: `registers[29].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `OTP_DATA_MSB_REG` | `OTP_DATA_MSB_REG` |
| physical_address | 0.4688 | 1.0 | `0x52` / `82` | {"hex":"0x52","decimal":"82","bank":"","page":"","description":"Most significant byte of an OTP 16-bit memory word."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Most significant byte of 16-bit OTP memory word." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R/W | `RW` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `OTP_DATA_MSB_REG` | `OTP_DATA_MSB_REG` |
| physical_address | 0.4044 | 1.0 | `0x52` / `82` | [{"hex":"0x52","decimal":"82","bank":"","page":"","description":"Most significant byte of an OTP 16-bit memory word."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.30 p.41 register meaning; no functional deviation in v1 | "Contains the most significant byte of OTP data to write for a programming command or read data after a read command executes." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R/W | `RW` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x52 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 31: `OTP_DATA_LSB_REG`

v1 location: `registers[30]`; datasheet association: Table 8 row `OTP_DATA_LSB_REG` at `0x53`.
Associated physical location: `0x53` (83).
Datasheet source: **Table 8 pp.26-28; §8.31 p.41**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[30].field_parts[0].bit_field[0]` `otp_mem_data_lsb` | `otp_mem_data_lsb` [7:0]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[7:0]; access=RW; desc="Least significant byte of 16-bit memory word."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `OTP_DATA_LSB_REG` at `0x53` (83)

Location: `registers[30].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `OTP_DATA_LSB_REG` | `OTP_DATA_LSB_REG` |
| physical_address | 0.4688 | 1.0 | `0x53` / `83` | {"hex":"0x53","decimal":"83","bank":"","page":"","description":"Least significant byte of an OTP 16-bit memory word."} |
| description | 0.0693 | 1.0 | Datasheet register description; no functional deviation | "Least significant byte of 16-bit OTP memory word." |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R/W | `RW` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 1.000000.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `OTP_DATA_LSB_REG` | `OTP_DATA_LSB_REG` |
| physical_address | 0.4044 | 1.0 | `0x53` / `83` | [{"hex":"0x53","decimal":"83","bank":"","page":"","description":"Least significant byte of an OTP 16-bit memory word."}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.31 p.41 register meaning; no functional deviation in v1 | "Contains the least significant byte of OTP data to write for a programming command or read data after a read command executes." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R/W | `RW` |
| field_parts | 0.2987 | 1.000000 | corresponding datasheet field-part collection | one field part at 0x53 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x1.000000 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 1.000000.

### Extracted logical register 32: `OTP_STATUS_REG`

v1 location: `registers[31]`; datasheet association: Table 8 row `OTP_STATUS_REG` at `0x55`.
Associated physical location: `0x55` (85).
Datasheet source: **Table 8 pp.26-28; §8.32 p.42**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[31].field_parts[0].bit_field[0]` `error` | `error` [7:5]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[7:5]; access=R; desc="OTP error status."; values=000=>NO_ERROR; 001=>BOOT_ERR; 010=>PAGE_RD_ERR; 011=>PAGE_PRG_ERR; 100=>SIGN_ERR; 101=>INV_CMD_ERR; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[31].field_parts[0].bit_field[1]` `cur_page_addr` | `cur_page_addr` [4:1]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[4:1]; access=R; desc="Currently selected page out of eight selectable pages."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[31].field_parts[0].bit_field[2]` `otp_cmd_done` | `otp_cmd_done` [0:0]; access=R; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[0:0]; access=R; desc="When 1, a new command can be accepted; otherwise software must wait."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 3 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `error`: 000=>NO_ERROR; 001=>BOOT_ERR; 010=>PAGE_RD_ERR; 011=>PAGE_PRG_ERR; 100=>SIGN_ERR; 101=>INV_CMD_ERR.

Bit-field collection correctness = mean(1.000000, 1.000000, 1.000000) = **1.000000**.

#### Field part 1: `OTP_STATUS_REG` at `0x55` (85)

Location: `registers[31].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `OTP_STATUS_REG` | `OTP_STATUS_REG` |
| physical_address | 0.4688 | 1.0 | `0x55` / `85` | {"hex":"0x55","decimal":"85","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "OTP status register." (Table 8 pp.26-28; §8.32 p.42) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R | `R` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `OTP_STATUS_REG` | `OTP_STATUS_REG` |
| physical_address | 0.4044 | 1.0 | `0x55` / `85` | [{"hex":"0x55","decimal":"85","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.32 p.42 register meaning; no functional deviation in v1 | "Reports OTP command completion, currently selected page, and OTP errors. Software must wait for otp_cmd_done=1 before issuing a new command." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R | `R` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x55 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x10 | `0x10` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 33: `TMR_SELFTEST_USER`

v1 location: `registers[32]`; datasheet association: Table 8 row `TMR_SELFTEST_USER` at `0x60`.
Associated physical location: `0x60` (96).
Datasheet source: **Table 8 pp.26-28; §8.33 p.42**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[32].field_parts[0].bit_field[0]` `reserved` | `reserved` [7:5]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[7:5]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[32].field_parts[0].bit_field[1]` `ist_en_y` | `ist_en_y` [4:4]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[4:4]; access=RW; desc="Activates the internally generated self-test field on the Y-axis transducer when other preconditions are met."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[32].field_parts[0].bit_field[2]` `ist_en_x` | `ist_en_x` [3:3]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[3:3]; access=RW; desc="Activates the internally generated self-test field on the X axis when other preconditions are met."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[32].field_parts[0].bit_field[3]` `st_p` | `st_p` [2:2]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[2:2]; access=RW; desc="Configures positive-field self-test execution when set."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[32].field_parts[0].bit_field[4]` `st_n` | `st_n` [1:1]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[1:1]; access=RW; desc="Configures negative-field self-test execution when set."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[32].field_parts[0].bit_field[5]` `st_igen_en` | `st_igen_en` [0:0]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=none | range=[0:0]; access=RW; desc="Enables the internal self-test current generator when set."; values=none; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 3 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 4 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 5 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 6 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000) = **1.000000**.

#### Field part 1: `TMR_SELFTEST_USER` at `0x60` (96)

Location: `registers[32].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `TMR_SELFTEST_USER` | `TMR_SELFTEST_USER` |
| physical_address | 0.4688 | 1.0 | `0x60` / `96` | {"hex":"0x60","decimal":"96","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "TMR user selftest reg. The datasheet also gives the self-test preconditions and safety note." (Table 8 pp.26-28; §8.33 p.42) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R/W | `RW` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `TMR_SELFTEST_USER` | `TMR_SELFTEST_USER` |
| physical_address | 0.4044 | 1.0 | `0x60` / `96` | [{"hex":"0x60","decimal":"96","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.33 p.42 register meaning; no functional deviation in v1 | "Configures user self-test current generation, positive or negative field, and X/Y self-test axes. The internal current generator must be enabled, and st_n and st_p must never be asserted simultaneously; consult the documented API self-test algorithm and important notes." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R/W | `RW` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x60 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 34: `CTRL_USER`

v1 location: `registers[33]`; datasheet association: Table 8 row `CTRL_USER` at `0x61`.
Associated physical location: `0x61` (97).
Datasheet source: **Table 8 pp.26-28; §8.34 p.43**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[33].field_parts[0].bit_field[0]` `reserved` | `reserved` [7:1]; access=n/a; reserved=true; DS description=reserved; DS/v1 code set=none | range=[7:1]; access=""; desc=""; values=none; reserved=true | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |
| `registers[33].field_parts[0].bit_field[1]` `cfg_sens_tim_aon` | `cfg_sens_tim_aon` [0:0]; access=R/W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[0:0]; access=RW; desc="Forces the sensor timer to run even in suspend mode; writable only in suspend mode."; values=0x0=>sensortime_while_normal; 0x1=>sensortime_always; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Reserved bits; empty description is allowed. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.
- Bit-field 2 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `cfg_sens_tim_aon`: 0x0=>sensortime_while_normal; 0x1=>sensortime_always.

Bit-field collection correctness = mean(1.000000, 1.000000) = **1.000000**.

#### Field part 1: `CTRL_USER` at `0x61` (97)

Location: `registers[33].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `CTRL_USER` | `CTRL_USER` |
| physical_address | 0.4688 | 1.0 | `0x61` / `97` | {"hex":"0x61","decimal":"97","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "user settings register." (Table 8 pp.26-28; §8.34 p.43) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | R/W | `RW` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `CTRL_USER` | `CTRL_USER` |
| physical_address | 0.4044 | 1.0 | `0x61` / `97` | [{"hex":"0x61","decimal":"97","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.34 p.43 register meaning; no functional deviation in v1 | "Controls whether the sensor-time counter continues running in suspend mode. cfg_sens_tim_aon can be written only in suspend mode; sensortime register readings still update only when new data is generated." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | R/W | `RW` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x61 |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 35: `CMD`

v1 location: `registers[34]`; datasheet association: Table 8 row `CMD` at `0x7E`.
Associated physical location: `0x7E` (126).
Datasheet source: **Table 8 pp.26-28; §8.35 p.43; functional §5.10.5 p.22**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[34].field_parts[0].bit_field[0]` `cmd` | `cmd` [7:0]; access=W; reserved=false; DS description=same functional meaning as v1; DS/v1 code set=same | range=[7:0]; access=W; desc="Available command encoding; reads always return 0x00."; values=0x00=>nop; Reserved, no command; 0xb6=>softreset; triggers a power-on reset; reserved=false | `(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0)` | **1.000000** |

- Bit-field 1 judgment: Semantic description matches the datasheet; wording/case differences are non-functional. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x1.0 + 0.2594x1.0 + 0.0583x1.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x1.0)/0.9999 = 1.000000.

- Value mappings checked against the cited datasheet: `cmd`: 0x00=>nop; Reserved, no command; 0xb6=>softreset; triggers a power-on reset.

Bit-field collection correctness = mean(1.000000) = **1.000000**.

#### Field part 1: `CMD` at `0x7E` (126)

Location: `registers[34].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `CMD` | `CMD` |
| physical_address | 0.4688 | 1.0 | `0x7E` / `126` | {"hex":"0x7E","decimal":"126","bank":"","page":"","description":""} |
| description | 0.0693 | 0.5 | Datasheet `DESCRIPTION`: "Command Register." (Table 8 pp.26-28; §8.35 p.43; functional §5.10.5 p.22) | `""` (missing) |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 1.0 | W | `W` |
| bit_field | 0.3129 | 1.000000 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x0.5 + 0.0605x1.0 + 0.0605x1.0 + 0.3129x1.000000 = 0.965350.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `CMD` | `CMD` |
| physical_address | 0.4044 | 1.0 | `0x7E` / `126` | [{"hex":"0x7E","decimal":"126","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 pp.26-28; §8.35 p.43; functional §5.10.5 p.22 register meaning; no functional deviation in v1 | "Write-only command register. Writing 0xB6 triggers a power-on reset; the documented soft-reset sequence writes 0xB6 followed by 0x0. Reads always return 0x00." |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 1.0 | W | `W` |
| field_parts | 0.2987 | 0.965350 | corresponding datasheet field-part collection | one field part at 0x7E |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x00 | `0x00` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x1.0 + 0.2987x0.965350 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.989651.

### Extracted logical register 36: `TRANS_DUCER_REV_ID`

v1 location: `registers[35]`; datasheet association: Table 8 row `TRANS_DUCER_REV_ID` at `0x0D`.
Associated physical location: `0x0D` (13).
Datasheet source: **Table 8 p.27**.

#### Bottom layer: bit fields, then field part

| Bit field path | DS target | v1 content | C-vector | Q(BF) |
|---|---|---|---|---:|
| `registers[35].field_parts[0].bit_field[0]` `trsdcr_rev_id_fixed` | `trsdcr_rev_id_fixed` [7:2]; access=R; reserved=false; DS description=not separately described in Table 8; DS/v1 code set=none | range=[null:null]; access=""; desc=""; values=none; reserved=false | `(1.0,1.0,0.0,0.0,0.0,1.0,1.0,0.0)` | **0.364536** |
| `registers[35].field_parts[0].bit_field[1]` `trsdcr_rev_id_otp` | `trsdcr_rev_id_otp` [1:0]; access=R; reserved=false; DS description=not separately described in Table 8; DS/v1 code set=none | range=[null:null]; access=""; desc=""; values=none; reserved=false | `(1.0,1.0,0.0,0.0,0.0,1.0,1.0,0.0)` | **0.364536** |

- Bit-field 1 judgment: No separate bit-description text is supplied for this row in Table 8; empty v1 description is accepted. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x0.0 + 0.2594x0.0 + 0.0583x0.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0)/0.9999 = 0.364536.
- Bit-field 2 judgment: No separate bit-description text is supplied for this row in Table 8; empty v1 description is accepted. Q(BF) = (0.0212x1.0 + 0.0586x1.0 + 0.2594x0.0 + 0.2594x0.0 + 0.0583x0.0 + 0.2097x1.0 + 0.0750x1.0 + 0.0583x0.0)/0.9999 = 0.364536.

- Value mappings: the datasheet provides no enumeration table for these fields; empty v1 `values` is complete.

Bit-field collection correctness = mean(0.364536, 0.364536) = **0.364536**.

#### Field part 1: `TRANS_DUCER_REV_ID` at `0x0D` (13)

Location: `registers[35].field_parts[0]`; physical address is numerically matched to datasheet Table 8.

| Field-part field | Weight | C | Datasheet target | v1 content |
|---|---:|---:|---|---|
| register_name | 0.0280 | 1.0 | `TRANS_DUCER_REV_ID` | `TRANS_DUCER_REV_ID` |
| physical_address | 0.4688 | 1.0 | `0x0D` / `13` | {"hex":"0x0D","decimal":"13","bank":"","page":"","description":""} |
| description | 0.0693 | 1.0 | No separate register DESCRIPTION is supplied for 0x0D in Table 8 | `""` |
| width_bits | 0.0605 | 1.0 | 8 | 8 |
| type_write_read | 0.0605 | 0.0 | R (Table 8 yellow read-only row) | `""` |
| bit_field | 0.3129 | 0.364536 | corresponding datasheet field set | mean of bit-field Q values |

Q(FP) = 0.0280x1.0 + 0.4688x1.0 + 0.0693x1.0 + 0.0605x1.0 + 0.0605x0.0 + 0.3129x0.364536 = 0.740663.

#### Extracted logical-register aggregation

| Logical-register field | Weight | C | Datasheet comparison target | v1 content |
|---|---:|---:|---|---|
| name | 0.0225 | 1.0 | `TRANS_DUCER_REV_ID` | `TRANS_DUCER_REV_ID` |
| physical_address | 0.4044 | 1.0 | `0x0D` / `13` | [{"hex":"0x0D","decimal":"13","bank":"","page":"","description":""}] |
| register_description | 0.0564 | 1.0 | Datasheet Table 8 p.27 register meaning; no functional deviation in v1 | "" |
| width_bits | 0.0590 | 1.0 | 8 | 8 |
| type_write_read | 0.0590 | 0.0 | R (Table 8 yellow read-only row) | `""` |
| field_parts | 0.2987 | 0.740663 | corresponding datasheet field-part collection | one field part at 0x0D |
| default_value | 0.0667 | 1.0 | Datasheet RESET 0x33 | `0x33` |
| default_value_description | 0.0334 | 1.0 | Datasheet gives the reset value but no independent description subfield | "" |

Q(L) = (0.0225x1.0 + 0.4044x1.0 + 0.0564x1.0 + 0.0590x1.0 + 0.0590x0.0 + 0.2987x0.740663 + 0.0667x1.0 + 0.0334x1.0)/1.0001 = 0.863550.

## 3. Datasheet physical-register scores

The datasheet physical-register set is evaluated by unique numeric address. Each address has one associated v1 logical register, so `q_R = Q(L)` for every row.

| Datasheet physical address | Datasheet register | Associated v1 logical register and path | Q(L) | q_R |
|---|---|---|---:|---:|
| `0x00` (0) | `CHIP_ID` | v1 `registers[0]` `CHIP_ID` | 0.989651 | **0.989651** |
| `0x02` (2) | `ERR_REG` | v1 `registers[1]` `ERR_REG` | 0.989651 | **0.989651** |
| `0x03` (3) | `PAD_CTRL` | v1 `registers[2]` `PAD_CTRL` | 0.989651 | **0.989651** |
| `0x04` (4) | `PMU_CMD_AGGR_SET` | v1 `registers[3]` `PMU_CMD_AGGR_SET` | 0.989651 | **0.989651** |
| `0x05` (5) | `PMU_CMD_AXIS_EN` | v1 `registers[4]` `PMU_CMD_AXIS_EN` | 0.989651 | **0.989651** |
| `0x06` (6) | `PMU_CMD` | v1 `registers[5]` `PMU_CMD` | 0.989651 | **0.989651** |
| `0x07` (7) | `PMU_CMD_STATUS_0` | v1 `registers[6]` `PMU_CMD_STATUS_0` | 0.989651 | **0.989651** |
| `0x08` (8) | `PMU_CMD_STATUS_1` | v1 `registers[7]` `PMU_CMD_STATUS_1` | 0.989651 | **0.989651** |
| `0x09` (9) | `I3C_ERR` | v1 `registers[8]` `I3C_ERR` | 0.989651 | **0.989651** |
| `0x0A` (10) | `I2C_WDT_SET` | v1 `registers[9]` `I2C_WDT_SET` | 0.989651 | **0.989651** |
| `0x2E` (46) | `INT_CTRL` | v1 `registers[10]` `INT_CTRL` | 0.989651 | **0.989651** |
| `0x2F` (47) | `INT_CTRL_IBI` | v1 `registers[11]` `INT_CTRL_IBI` | 0.989651 | **0.989651** |
| `0x30` (48) | `INT_STATUS` | v1 `registers[12]` `INT_STATUS` | 0.989651 | **0.989651** |
| `0x31` (49) | `MAG_X_XLSB` | v1 `registers[13]` `MAG_X_XLSB` | 1.000000 | **1.000000** |
| `0x32` (50) | `MAG_X_LSB` | v1 `registers[14]` `MAG_X_LSB` | 1.000000 | **1.000000** |
| `0x33` (51) | `MAG_X_MSB` | v1 `registers[15]` `MAG_X_MSB` | 1.000000 | **1.000000** |
| `0x34` (52) | `MAG_Y_XLSB` | v1 `registers[16]` `MAG_Y_XLSB` | 1.000000 | **1.000000** |
| `0x35` (53) | `MAG_Y_LSB` | v1 `registers[17]` `MAG_Y_LSB` | 1.000000 | **1.000000** |
| `0x36` (54) | `MAG_Y_MSB` | v1 `registers[18]` `MAG_Y_MSB` | 1.000000 | **1.000000** |
| `0x37` (55) | `MAG_Z_XLSB` | v1 `registers[19]` `MAG_Z_XLSB` | 1.000000 | **1.000000** |
| `0x38` (56) | `MAG_Z_LSB` | v1 `registers[20]` `MAG_Z_LSB` | 1.000000 | **1.000000** |
| `0x39` (57) | `MAG_Z_MSB` | v1 `registers[21]` `MAG_Z_MSB` | 1.000000 | **1.000000** |
| `0x3A` (58) | `TEMP_XLSB` | v1 `registers[22]` `TEMP_XLSB` | 1.000000 | **1.000000** |
| `0x3B` (59) | `TEMP_LSB` | v1 `registers[23]` `TEMP_LSB` | 1.000000 | **1.000000** |
| `0x3C` (60) | `TEMP_MSB` | v1 `registers[24]` `TEMP_MSB` | 1.000000 | **1.000000** |
| `0x3D` (61) | `SENSORTIME_XLSB` | v1 `registers[25]` `SENSORTIME_XLSB` | 1.000000 | **1.000000** |
| `0x3E` (62) | `SENSORTIME_LSB` | v1 `registers[26]` `SENSORTIME_LSB` | 1.000000 | **1.000000** |
| `0x3F` (63) | `SENSORTIME_MSB` | v1 `registers[27]` `SENSORTIME_MSB` | 1.000000 | **1.000000** |
| `0x50` (80) | `OTP_CMD_REG` | v1 `registers[28]` `OTP_CMD_REG` | 0.989651 | **0.989651** |
| `0x52` (82) | `OTP_DATA_MSB_REG` | v1 `registers[29]` `OTP_DATA_MSB_REG` | 1.000000 | **1.000000** |
| `0x53` (83) | `OTP_DATA_LSB_REG` | v1 `registers[30]` `OTP_DATA_LSB_REG` | 1.000000 | **1.000000** |
| `0x55` (85) | `OTP_STATUS_REG` | v1 `registers[31]` `OTP_STATUS_REG` | 0.989651 | **0.989651** |
| `0x60` (96) | `TMR_SELFTEST_USER` | v1 `registers[32]` `TMR_SELFTEST_USER` | 0.989651 | **0.989651** |
| `0x61` (97) | `CTRL_USER` | v1 `registers[33]` `CTRL_USER` | 0.989651 | **0.989651** |
| `0x7E` (126) | `CMD` | v1 `registers[34]` `CMD` | 0.989651 | **0.989651** |
| `0x0D` (13) | `TRANS_DUCER_REV_ID` | v1 `registers[35]` `TRANS_DUCER_REV_ID` | 0.863550 | **0.863550** |

\(\sum_{R=1}^{36} q_R=\mathbf{35.677269257}\).

\(m=36,\ x=0,\ \frac{m}{m+x}=\frac{36}{36+0}=1.000000\).

\[S_{final}=\left(\frac{10}{36}\times 35.677269257\right)\times 1.000000=\boxed{\mathbf{9.910352572/10}}\]

## 4. Detailed deduction inventory

1. **Missing functional field-part descriptions (18 locations, partial credit only):**
   - `registers[0].field_parts[0].description` for `CHIP_ID` at `0x00`: v1 is empty; datasheet Table 8 pp.26-28; §8.1 p.29 provides "Chip identification code.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[1].field_parts[0].description` for `ERR_REG` at `0x02`: v1 is empty; datasheet Table 8 pp.26-28; §8.2 p.29 provides "Reports Sensor Error Flag. Will be cleared on read. If the user writes a 1 into any status bit, this will also clear that bit.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[2].field_parts[0].description` for `PAD_CTRL` at `0x03`: v1 is empty; datasheet Table 8 pp.26-28; §8.3 p.30 provides "Configure pad behavior.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[3].field_parts[0].description` for `PMU_CMD_AGGR_SET` at `0x04`: v1 is empty; datasheet Table 8 pp.26-28; §8.4 p.30 provides "configuration of the ODR and AVG.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[4].field_parts[0].description` for `PMU_CMD_AXIS_EN` at `0x05`: v1 is empty; datasheet Table 8 pp.26-28; §8.5 p.31 provides "axis configuration.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[5].field_parts[0].description` for `PMU_CMD` at `0x06`: v1 is empty; datasheet Table 8 pp.26-28; §8.6 p.32 provides "PMU cmd configuration.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[6].field_parts[0].description` for `PMU_CMD_STATUS_0` at `0x07`: v1 is empty; datasheet Table 8 pp.26-28; §8.7 p.33 provides "Sensor Status Flag.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[7].field_parts[0].description` for `PMU_CMD_STATUS_1` at `0x08`: v1 is empty; datasheet Table 8 pp.26-28; §8.8 p.34 provides "PMU Status Flag.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[8].field_parts[0].description` for `I3C_ERR` at `0x09`: v1 is empty; datasheet Table 8 pp.26-28; §8.9 p.34 provides "I3C Bus Error Statistics. Will be cleared on read. If the user writes a 1 into any status bit, this will also clear that bit.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[9].field_parts[0].description` for `I2C_WDT_SET` at `0x0A`: v1 is empty; datasheet Table 8 pp.26-28; §8.10 pp.34-35 provides "i2c watchdog configure registers.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[10].field_parts[0].description` for `INT_CTRL` at `0x2E`: v1 is empty; datasheet Table 8 pp.26-28; §8.11 p.35 provides "Configuration of interrupts for INT_STATUS register and INT pin.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[11].field_parts[0].description` for `INT_CTRL_IBI` at `0x2F`: v1 is empty; datasheet Table 8 pp.26-28; §8.12 p.36 provides "Configuration of interrupts features related to IBI.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[12].field_parts[0].description` for `INT_STATUS` at `0x30`: v1 is empty; datasheet Table 8 pp.26-28; §8.13 p.36 provides "Interrupt Status. Will be cleared on read. If the user writes a 1 into any status bit, this will also clear that bit.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[28].field_parts[0].description` for `OTP_CMD_REG` at `0x50`: v1 is empty; datasheet Table 8 pp.26-28; §8.29 p.41 provides "OTP command and word address register.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[31].field_parts[0].description` for `OTP_STATUS_REG` at `0x55`: v1 is empty; datasheet Table 8 pp.26-28; §8.32 p.42 provides "OTP status register.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[32].field_parts[0].description` for `TMR_SELFTEST_USER` at `0x60`: v1 is empty; datasheet Table 8 pp.26-28; §8.33 p.42 provides "TMR user selftest reg. The datasheet also gives the self-test preconditions and safety note.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[33].field_parts[0].description` for `CTRL_USER` at `0x61`: v1 is empty; datasheet Table 8 pp.26-28; §8.34 p.43 provides "user settings register.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).
   - `registers[34].field_parts[0].description` for `CMD` at `0x7E`: v1 is empty; datasheet Table 8 pp.26-28; §8.35 p.43; functional §5.10.5 p.22 provides "Command Register.". Because this is a descriptive omission without an address/range/access/value deviation, (C=0.5).

2. **Objective omissions in `TRANS_DUCER_REV_ID` (0x0D):**
   - `registers[35].type_write_read` and `registers[35].field_parts[0].type_write_read` are empty, but Table 8 p.27 marks the 0x0D row read-only (yellow); target `R`, so both direct access fields receive `C=0`.
   - `registers[35].field_parts[0].bit_field[0]` is `trsdcr_rev_id_fixed`: v1 has `bit_start=null`, `bit_end=null`, `bit_width=null`, and empty access; Table 8 p.27 places it at bits `[7:2]` and read-only. The missing range/width/access are scored strictly.
   - `registers[35].field_parts[0].bit_field[1]` is `trsdcr_rev_id_otp`: v1 has `bit_start=null`, `bit_end=null`, `bit_width=null`, and empty access; Table 8 p.27 places it at bits `[1:0]` and read-only. The missing range/width/access are scored strictly.
   - The two field names, `is_reserved=false`, empty value enumerations, address `0x0D`/decimal `13`, width `8`, reset `0x33`, and the one-field-part structure are correct.

3. **No physical-register omissions or extras:** all 36 datasheet addresses in Table 8 are present once in v1; no unmatched address, bank, page, or duplicate physical key was found.

## 5. Datasheet consistency notes

- The score intentionally follows the detailed register definitions. For `PMU_CMD_AXIS_EN`, §8.5 p.31 states reset `0x07` and the low fields are write-only, matching v1; the `0x70`/yellow rendering in the summary Table 8 p.28 is treated as a datasheet inconsistency, not as a v1 error.
- For `PMU_CMD_STATUS_0`, §8.7 p.33 defines reserved bits 7:5 and named fields 4:0, matching v1. The summary Table 8 p.28 uses a different upper label (`pmu_cmd_val`), so the detailed section controls the objective field comparison.
- Reserved ranges are represented as one contiguous reserved bit field where the datasheet shows a contiguous reserved block. Empty reserved names/descriptions and empty access are accepted as allowed by the scoring instructions.

## 6. Invented-field and value check

- No extra logical register or physical address is present.
- No v1 bit-field range extends outside the corresponding datasheet range. The only range issue is the missing `TRANS_DUCER_REV_ID` ranges documented above.
- All non-empty v1 value code sets match the datasheet enumerations in §§8.3-8.35; no unsupported code or contradictory functional label was found. Long explanatory caveats in the datasheet are not treated as omissions when the code meaning and functional behavior are preserved.
- No category field is included in scoring, consistent with AGENTS.md.

## 7. Final result

**BMM350 v1.0 datasheet-based score: 9.910352572/10.**
