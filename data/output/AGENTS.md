# Register-Map 评分规则

本文件规定 register map 抽取结果的评分、证据记录和报告格式。datasheet 是唯一事实依据，ground_truth.json 只是对 datasheet 事实的结构化、可计算示例，抽取结果是评价对象。先完成地址规范化、Reserved 过滤和合法 split/merge normalization，再进行匹配和评分。

## 1. 评分对象与身份

评分以 datasheet 事实为准，并使用 ground_truth.json 作为结构化参照，包含三个独立指标：

- Average Logical-Register Correctness（ALRC）
- Logical Register Coverage Rate（LRCR）
- Extra Logical-Register Rate（ELRR）

输入路径通常为：

- ground truth：<device_name>
- 抽取版本：<device_name>/<version>

实际评分报告中必须写明使用的路径。

### 1.1 地址规范化

- physical_address.hex 和 physical_address.decimal 是同一地址。
- 物理位置由 numeric_address、bank、page 确定。
- datasheet 明确声明的地址别名属于同一个 address-alias equivalence class，只计一次；抽取任一有效 alias 都可匹配。
- 未经 datasheet 证明的相同地址不得自行合并。
- logical register 主要按地址识别，name 是辅助字段。名称不同但地址和其它事实对应时，不作为额外 logical register。
- 只要抽取 logical register 的规范化 physical address 能与 truth 中的 logical register 对应，就必须建立匹配；字段内容错误应通过字段级评分反映，不得仅因字段错误将其判为不匹配或 E_LR。只有不存在任何可解释的 truth 对应关系时，才计为额外 logical register。
- 合法 split/merge 被确认后，应按照 normalization 结果建立对应的 ground-truth evaluation units，并基于这些 normalized truth units 与抽取 units 进行字段级评分。

### 1.2 Reserved

- datasheet 明确标为 Reserved、RFU、unused 且没有具体功能行为的物理位置，不进入事实目标数量，也不计入 ELRR；抽取出的此类位置仍须在报告中列出。
- 带具体功能的保留位置按正常寄存器评分。
- 有效寄存器内部的 Reserved bit 仍属于 bit_field collection，必须计数和评分。


## 2. Split/merge normalization

logical register 的分组方式可以不同。只要抽取结果保留完整 datasheet 语义，合法 split/merge 不扣分，也不计为额外项。
同样地，`bit_field`字段中的连续reserved bit段的分组方式可以不同。只要抽取结果保留完整 datasheet 语义，合法 split/merge 不扣分，也不计为额外项。
bit_field 不进行一般性的 split/merge normalization。仅允许将同一 field part、同一 physical register 内连续的 Reserved bit 合并为一个 Reserved bit_field。其他拆分或合并均不视为合法 normalization。

Field-part boundary normalization：
当 truth 与 extraction 仅因 physical-register 边界导致 field_part 的拆分或合并方式不同，但两者可以无损表示同一完整 logical-register 语义时，应先将各 part 的局部 bit range 映射到 logical register 的全局 bit range，并构造统一的 normalized field_part 后再评分。
合法的 field-part split/merge 不产生遗漏或额外项；
其 bit_field collection 按 normalized 后的全局位号与语义进行一对一匹配并计算 C_BF。
对于同一 physical address 的 16-bit register，若 extraction 以 MSB/upper byte 与 LSB/lower byte 两个 8-bit field_part 表示，先将 MSB/upper 的局部位 b 映射为完整寄存器的全局位 b+8，LSB/lower 的局部位保持为 b，再将两部分合并后与 truth/PDF 比较。例如 MSB 的 [3:7] 对应完整寄存器的 [11:15]，即按高位到低位表示为 [15:11]。该 field-part representation normalization 不改变 N、G_FP 或 E_FP，也不扩展为一般 bit_field split/merge normalization。

Bit-field semantic split/merge normalization：
当 truth 与 extraction 对同一 bit range 采用不同的 bit_field 拆分或合并方式，但一组字段能够完整、无冲突地覆盖另一侧对应字段的 bit range，并且组合后能够无损表示相同的功能、数据含义和读写语义时，应视为等价表示并进行 normalization。合法的 bit-field split/merge 不产生遗漏或额外项，应按 normalization 后的整体语义进行匹配和评分。
连续的 Reserved bit 也允许按照上述原则进行合并或拆分；只要其 bit range 和 Reserved 语义完整一致，不因分组方式不同扣分。

### 2.1 合法 split

一个 truth logical register 拆成多个 evaluation units 时，必须：

- 覆盖全部 constituent physical addresses（按 alias 去重）；
- 保持 bit range、width、读写语义和数据组成关系；
- 每个拆分 unit 都有 datasheet 依据；
- 无遗漏、无虚构或矛盾的 constituent；
- 拆分后的 units 可以无损还原原 logical register。

若拆成 k 个 units，N 增加 k-1。

### 2.2 合法 merge

多个 truth logical registers 合并为一个 evaluation unit 时，必须：

- 保留所有 truth items 的地址、bit layout、width、读写语义和组合关系；
- 合并后的结构可以无损还原各 constituent；
- 不改变 datasheet 的功能含义。

若 k 个 truth items 合并为一个 unit，N 减少 k-1。

不满足上述条件的 split/merge 不做 normalization，按普通遗漏、错误或额外项处理。

定义：

- N_raw：去除 Reserved、合并 alias 后的 truth logical register 数量；
- N_eval：完成合法 split/merge 后的 evaluation logical-register unit 数量；
- M_eval：成功匹配的 evaluation units 数量;
- E_LR： 抽取结果中完全不存在于 datasheet 事实中的额外非 Reserved 顶层 logical-register units。

## 3. 字段和层级评分

### 3.1 普通字段

适用字段采用离散评分：

- 完全正确或语义等价：C(field) = 1
- 部分正确、信息不完整或局部非核心错误：C(field) = 0.2
- 错误、冲突或缺失：C(field) = 0
- 若仅有大小写不同，语义上等价，按C(field) = 1处理。

对 description 类字段应按 datasheet 支持的功能语义评分，不按与 ground truth 的文本相似度评分；若 extraction 使用更具体的行为描述完整正确地表达了 ground truth 的概括性语义，应视为语义等价并记 C=1。
当description类字段描述为只是一个不影响事实的概念性描述，例如：default value_description：“default value”，尽管truth为空或者pdf中没有相应的描述，但是只要不存在严重事实冲突或者事实遗漏，也可以给C=1。

直接使用表中的 AHP 权重，不再按适用字段或 collection 重新归一化。某个 collection 在 ground truth 和抽取结果中都为空时，令该 collection 的 C=1，并保留其原始权重。

physical_address 比较 numeric address、bank、page 和 alias class；hex/decimal 等价。category 不参与评分。

对于`field_parts`和`bit_field`的item的名称，如果原文没有明确说明这部分的名称，允许提取结果使用概括性描述的名称。

### 3.2 Logical register 权重

| 字段 | AHP 权重 |
|---|---:|
| name | 0.0225 |
| physical_address | 0.4044 |
| register_description | 0.0564 |
| width_bits | 0.0590 |
| type_write_read | 0.0590 |
| field_parts | 0.2987 |
| default_value | 0.0667 |
| default_value_description | 0.0334 |

对 logical register L：

    Q(L) = sum(weight(field) * C(field)) + weight(field_parts) * C_FP(L)

公式中的第一项求和中field只包括除了`field_parts`以外的其他所有字段。对于计入M_eval以外的完全遗漏的Logical Register，Q = 0。 
field_parts 的 collection 统计见第 4 节。

### 3.3 Field part 权重

| 字段 | AHP 权重 |
|---|---:|
| register_name | 0.0280 |
| physical_address | 0.4688 |
| description | 0.0693 |
| width_bits | 0.0605 |
| type_write_read | 0.0605 |
| bit_field | 0.3129 |

对 field part P：

    Q(P) = sum(weight(field) * C(field)) + weight(bit_field) * C_BF(P)
公式中的第一项求和中field只包括除了`bit_field`以外的其他所有字段。对于完全遗漏的P,Q(P) = 0。
bit_field 的 collection 统计见第 4 节。

### 3.4 Bit field 权重

| 字段 | AHP 权重 |
|---|---:|
| name_or_parameter | 0.0193 |
| field_description | 0.0515 |
| bit_start | 0.2333 |
| bit_end | 0.2333 |
| bit_width | 0.0492 |
| values | 0.2020 |
| is_reserved | 0.0674 |
| type_write_read | 0.1440 |

对 bit field B：

    Q(B) = sum(weight(field) * C(field))

Reserved bit 的 name_or_parameter 和 field_description 可为空，视为不适用并令对应 C=1，不扣分。bit range、width、values、is_reserved 和读写属性仍按普通规则评分。对于完全遗漏的Q(B)=0。

## 4. Collection 评分

本节规则分别应用于 field_parts 和 bit_field。

对任一 collection K：

- G_K：ground truth item 数量；
- A_K：成功匹配的 truth item 数量；
- E_K：无法匹配的额外抽取 item 数量；
- 缺失 truth item 的 Q(item) 记为 0。
对于某个 `field_parts` item 的 `bit_field` collection，truth 和抽取结果分别将连续的 Reserved bit 合并后，再进行一对一匹配。`G_K` 为合并后 truth item 的数量，`A_K` 为成功匹配的 truth item 数量，`E_K` 为无法匹配的抽取 item 数量。

当 G_K > 0：

    F_K = sum(Q(K_i) for all truth items) / G_K
    c_K = G_K / (G_K + E_K)
    C_K = c_K * F_K

等价地：

    C_K = sum(Q(K_i) for all truth items) / (G_K + E_K)

因此，遗漏和内容错误由 Q(item) 反映，额外 item 通过增加分母进行比例惩罚。

当 G_K = 0：

- 抽取也为空：C_K = 1，并保留父对象中的对应权重；
- 抽取有 item：C_K = 0，并在额外 collection 项中列出。

额外 field part 和 bit field 不进入事实项的 F_K 分子，但会增加 E_K。它们不计入E_LR。

## 5. 三个总指标

### 5.1 ALRC

对所有 M_eval 个 ground-truth-oriented evaluation units 计算 Q(L)。

    ALRC = sum(Q(L_i) for i = 1..M_eval) / M_eval

### 5.2 LRCR

LRCR 为已经抽取并成功匹配到的 logical registers，占标准化后truth总共拥有的logical registers的比率。

定义：

    LRCR = M_eval / N_eval

若 N_eval 为 0，报告 LRCR=N/A。

### 5.3 ELRR

    ELRR = E_LR / (N_raw + E_LR)

ELRR 只统计抽取结果中完全不存在于 datasheet 事实中的额外非 Reserved 顶层 logical registers。合法 split/merge、有效 alias 的重复表示以及 Reserved 顶层位置不计入 E_LR。

## 6. 匹配和评分顺序

1. 读取 ground truth、抽取结果和 datasheet 证据。
2. 规范化地址、bank/page、alias 和 Reserved 物理位置。
3. 判定合法 split/merge 并建立 normalization 映射。
4. 对 logical registers、field parts 和 bit fields 做一对一、可解释的匹配。
5. 自底向上计算 Q(B)、C_BF、Q(P)、C_FP 和 Q(L)。
6. 计算 ALRC、LRCR 和 ELRR。
7. 生成带证据的完整报告。
8. 递归得到的原值不能四舍五入，要原封不动地传给上一层的评分。

匹配依据为 ground truth、地址和结构语义；名称可以不同，但名称字段仍按适用字段规则评分。所有字段判断都必须能回溯到抽取内容、ground truth 内容和 datasheet 原文位置。

## 7. 强制报告内容

在被评估版本目录生成 register-map-score-report.md，并写明实际输入路径。报告中不得出现规则修改等和上个版本相关的内容。不得出现类似于：“这次没有把xxx算入评分”、“这次修改了。。规则所以。。”这类防御性说明。

### 7.1 汇总表

至少包含：

| 项目                                          | 数值 |
|---------------------------------------------|---:|
| truth 原始非 Reserved logical registers（N_raw） | |
| 合法 split 增量                                 | |
| 合法 merge 减量                                 | |
| normalization 后 evaluation units（N_eval）    | |
| 成功匹配 evaluation units（M_eval）               | |
| 遗漏 evaluation units（N_eval-M_eval）          | |
| truth 非 Reserved 地址数（T_addr）                | |
| 成功识别的非 Reserved 地址数（H_addr）                 | |
| 遗漏地址数（T_addr-H_addr）                        | |
| 额外顶层 logical-register units（E_LR）           | |
| 抽取原始 logical-register 数量                    | |
| 去重/normalization 后抽取数量                      | |
| ALRC                                        | |
| LRCR                                        | |
| ELRR                                        | |

报告中展开：

    ALRC = (Q(L_1) + ... + Q(L_M_eval)) / M_eval
    LRCR = M_eval / N_eval
    ELRR = E_LR / (N_raw + E_LR)

逐一列出每个 Q(L_i) 和每个额外顶层 logical register。

### 7.2 Logical register 证据表

每个 evaluation logical register 一张表，逐行包含：

| 层级路径 | 字段 | AHP 权重 | 抽取内容 | ground-truth/事实内容 | datasheet 原文位置 | 字段得分 | 评分说明 |
|---|---|---:|---|---|---|---:|---|

覆盖所有适用 direct fields 和 field_parts collection 汇总行；category 不列入。表后列出 Q(L) 的各项 weight * score 计算。

### 7.3 Field part 证据和 collection 明细

每个 truth field part 逐行报告：

- register_name
- physical_address
- description
- width_bits
- type_write_read
- bit_field collection

每行同时给出抽取内容、事实内容、datasheet 位置、字段得分和说明。表后列出 Q(P) 计算，以及 G_FP、A_FP、遗漏数、E_FP、F_FP、c_FP 和 C_FP。

### 7.4 Bit field 证据和 collection 明细

每个 truth bit field 逐行报告：

- name_or_parameter
- field_description
- bit_start
- bit_end
- bit_width
- values
- is_reserved
- type_write_read

同时给出抽取内容、事实内容、datasheet 位置、字段得分和说明。Reserved bit 必须列出，并注明名称和描述不影响评分。

表后列出 Q(B) 计算，以及 G_BF、A_BF、遗漏数、E_BF、F_BF、c_BF 和 C_BF。额外 bit field 单独列出，不进入 F_BF。

### 7.5 Normalization 表

单独列出所有合法和不合法的 split/merge：

| normalization 类型 | truth 标识/数量 | 抽取标识/数量 | normalization 前 N | ΔN | normalization 后 N | 是否合法 | 语义依据/原因 |
|---|---|---|---:|---:|---:|---|---|

### 7.6 错误、遗漏和额外项索引

分别列出：

- logical-register、field-part、bit-field 的遗漏和字段错误；
- 额外顶层 logical registers；
- 额外物理地址；
- 额外 field parts；
- 额外 bit fields。

每项包含路径、抽取内容、事实内容、datasheet 位置和原因。
