# Register-Map Scoring Rules

## 1. Final Score

\[
S_{\mathrm{final}}
=
\left(
\frac{10}{n}
\sum_{i=1}^{n} q_{R_i}
\right)
\frac{m}{m+x}
\]

## 2. Physical-Register Correctness

Let \(L_{R_i}\) denote the set of extracted logical registers associated with the ground-truth physical register \(R_i\):

\[
L_{R_i}
=
\{L_1,L_2,\ldots,L_{n_{L_{R_i}}}\}
\]

where:

\[
n_{L_{R_i}}
=
|L_{R_i}|
\]

The correctness score of physical register \(R_i\) is:

\[
q_{R_i}
=
\frac{1}{n_{L_{R_i}}}
\sum_{L\in L_{R_i}}
Q(L)
\]

If no extracted logical register is associated with the ground-truth physical register \(R_i\):

\[
q_{R_i}=0
\]

## 3. Recursive Correctness Function

\[
Q(X)
=
\sum_{j=1}^{r_X}
w_{X,j}\,\phi(f_j)
\]

\[
\phi(f_j)
=
\begin{cases}
Q(f_j),
&
f_j\in
\{\text{logical\_register},
\text{field\_part},
\text{bit\_field}\}
\\[6pt]
C(f_j),
&
\text{otherwise}
\end{cases}
\]

\[
\sum_{j=1}^{r_X} w_{X,j}=1
\]

## 4. Non-Recursive Field Correctness

\[
C(f_j)
=
\begin{cases}
1,
& \text{completely correct}
\\[4pt]
0.5,
& \text{partially correct, including incomplete information}
\\[4pt]
0,
& \text{completely incorrect or missing}
\end{cases}
\]

## 5. Variable Definitions

\[
\begin{aligned}
S_{\mathrm{final}}
&: \text{final register-map score},\quad 0\le S_{\mathrm{final}}\le 10
\\
n
&: \text{number of unique physical registers in the ground truth}
\\
R_i
&: \text{the }i\text{-th ground-truth physical register}
\\
q_{R_i}
&: \text{correctness score of ground-truth physical register }R_i
\\
L_{R_i}
&: \text{set of extracted logical registers associated with ground-truth physical register }R_i
\\
L
&: \text{an extracted logical register}
\\
n_{L_{R_i}}
&: \text{number of extracted logical registers associated with ground-truth physical register }R_i
\\
m
&: \text{number of extracted physical registers matched to ground-truth physical registers}
\\
x
&: \text{number of extra extracted physical registers，reserved registers that can be explicitly proven by device pdf is not included}
\\
X
&: \text{a scored structured object}
\\
f_j
&: \text{the }j\text{-th scored field of }X
\\
r_X
&: \text{number of scored fields in }X
\\
w_{X,j}
&: \text{AHP weight of field }f_j
\\
Q(X)
&: \text{hierarchical correctness score of structured object }X
\\
C(f_j)
&: \text{correctness score of a non-recursive field}
\end{aligned}
\]

## 6. Evaluation Constraints
- Score allocation is based on ground-truth physical registers.
- Only `logical_register`, `field_part`, and `bit_field` are evaluated recursively.
- Bottom-up calculation is performed independently for each logical register in the register map being evaluated. For each logical register, first calculate every `bit_field` score, then calculate each containing `field_part` score from its direct fields and bit-field scores, and finally calculate the logical-register score from its direct fields and field-part scores. Do not treat each physical field part as an independent logical-register evaluation unit or redistribute the logical-register score by recalculating it separately for each physical field part.
- All other fields are evaluated directly using \(C(f_j)\).
- Missing ground-truth physical registers receive \(q_i=0\).
- Extra extracted physical registers are penalized by \(m/(m+x)\).
- Global reserved-entry rule: an extracted physical entry explicitly documented as Reserved, RFU (Reserved for Future Use), or as a device-specific unused/reserved location with no concrete functional behavior is ignored for scoring. It is not included in (x), does not create a matched physical register, and does not contribute a (q_R). This rule applies to every sensor evaluated with these rules. If the entry carries a concrete functional claim, it remains an extra extracted physical register and is counted in (x).
- Equivalent logical-register merge/split representations must not be penalized solely because of grouping differences.
- Truth data files are placed at dir <device_name>, and the extracted register map result of a version are in <device_name>/ version
- The AHP-derived field weights are defined as follows: 

For `logical_register` are: `name` = 0.0225, `physical_address` = 0.4044, `register_description` = 0.0564, `width_bits` = 0.0590, `type_write_read` = 0.0590, `field_parts` = 0.2987, `default_value` = 0.0667, and `default_value_description` = 0.0334; `category` is excluded from the scoring process.

For `field_part`, `register_name` = 0.0280, `physical_address` = 0.4688, `description` = 0.0693, `width_bits` = 0.0605, `type_write_read` = 0.0605, and `bit_field` = 0.3129; 

For `bit_field`, `name_or_parameter` = 0.0212, `field_description` = 0.0586, `bit_start` = 0.2594, `bit_end` = 0.2594, `bit_width` = 0.0583, `values` = 0.2097, `is_reserved` = 0.0750, and `type_write_read` = 0.0583.
Fields not listed above are excluded from the evaluation.

- A logical register entry is one item in `registers` and represents exactly one logical register. Each item in `field_parts` for a logical register represents exactly one physical register entry. Each physical register entry has exactly one physical address.
- Within a `physical_address`, `hex` and `decimal` are two representations of the same numeric address. The numeric address together with `bank` and `page` identifies one unique physical register location.

- You must list in detail the errors, omissions, the exact locations of the items, and the specific content of how they are wrong or missing compared to the truth.

- You must list the calculation process of every logical register, its field parts and all bit fields in detail. Your calculation process must be presented from the bottom up for every logical register item and end up with their sum.
- Reserved bit are allowed with empty name and description.
- If the description in the `values` or `physical_address` has no functional deviation and is just some trivial, general description, it can be evaluated as 1 or 0.5.
