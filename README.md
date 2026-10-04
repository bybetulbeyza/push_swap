*This project has been created as part of the 42 curriculum by betdemir, zeyalcin.*

# push_swap

## Description

push_swap is an algorithmic sorting project written in C.

The goal of the project is to sort a list of integers using two stacks, `a` and `b`, and a limited set of allowed operations.

At the beginning:

- Stack `a` contains all input integers.
- Stack `b` is empty.
- The first input integer is considered the top of stack `a`.

The program does not print the sorted numbers directly. Instead, it prints the sequence of push_swap operations required to sort stack `a` in ascending order.

The available operations are:

- `sa` - Swap the first two elements of stack `a`.
- `sb` - Swap the first two elements of stack `b`.
- `ss` - Perform `sa` and `sb` at the same time.
- `pa` - Push the first element of stack `b` to stack `a`.
- `pb` - Push the first element of stack `a` to stack `b`.
- `ra` - Rotate stack `a`.
- `rb` - Rotate stack `b`.
- `rr` - Perform `ra` and `rb` at the same time.
- `rra` - Reverse rotate stack `a`.
- `rrb` - Reverse rotate stack `b`.
- `rrr` - Perform `rra` and `rrb` at the same time.

---

## Instructions

### Compilation

Compile the project with:

```bash
make
```

This produces the `push_swap` binary. Available Makefile rules: `all`, `clean`, `fclean`, `re`.

### Usage

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <list of integers>
```

- The list of integers is the initial content of stack `a` (first argument = top of stack).
- If no arguments are given, the program prints nothing and returns immediately.
- On invalid input (non-integer arguments, values out of `int` range, duplicate values, or no numeric arguments at all), the program prints `Error` on `stderr` and exits with a non-zero status.
- The sequence of operations that sorts the stack is printed on `stdout`, one instruction per line.

**Strategy selectors** (optional, only one may be used at a time):

| Flag | Strategy | Complexity |
|---|---|---|
| `--simple` | Insertion-sort-style / min extraction | O(n²) |
| `--medium` | Chunk-based partitioning | O(n√n) |
| `--complex` | Bitwise (LSD) radix sort | O(n log n) |
| `--adaptive` | Chooses one of the above based on measured disorder (default) | see below |

**Benchmark mode** (`--bench`): prints, on `stderr`, the measured disorder, the strategy used and its complexity class, the total number of operations, and the count of each individual operation type.

### Examples

```bash
$> ./push_swap 2 1 3 6 5 8
ra
pb
rra
...

$> ./push_swap --simple 5 4 3 2 1 | wc -l
14

$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK

$> ./push_swap --bench --adaptive 5 4 3 2 1 > /dev/null
[bench] disorder: 100.00%
[bench] strategy: Adaptive / O(n^2)
[bench] Total operations: 14
...
```

---

## Algorithms

### Disorder metric

Before any move is executed, the program computes a **disorder** score in `[0, 1]`:
it counts, over all pairs `(i, j)` with `i < j`, how many pairs are "inverted"
(`a[i] > a[j]`), and divides that count by the total number of pairs
`n * (n - 1) / 2`. `0` means the stack is already sorted, `1` means it is in
the worst possible (fully reversed) order.

### 1. Simple — O(n²) (`simple.c`)

Repeatedly finds the current minimum, rotates it to the top of `a` in the
cheapest direction, and pushes it to `b`; once every element has been moved to
`b`, they are pushed back onto `a` in the right order. Finding the minimum and
rotating it into place costs O(n) per element, over n elements: **O(n²)**.
Only used when the stack is already close to sorted (`disorder < 0.2`), since
in that regime the number of misplaced elements — and therefore the real
number of operations — stays small even though the complexity class is
quadratic.

### 2. Medium — O(n√n) (`medium.c`)

Splits the value range into `√n` chunks. Elements are pushed into `b` chunk
by chunk (so that, after processing, `b` holds a sequence of `√n` sorted
runs), then merged back onto `a`. Each of the `√n` chunks costs O(n) to
extract, giving **O(n√n)** overall. This is the middle ground used for
moderately disordered stacks (`0.2 ≤ disorder < 0.5`), where a full O(n log n)
approach isn't necessary but plain insertion (O(n²)) would already start to
cost more operations than needed.

### 3. Complex — O(n log n) (`radix.c`)

A bitwise, two-stack **LSD radix sort**: each element is first assigned a
unique rank (`0` to `n-1`) reflecting its position in the sorted order
(`index.c`). The algorithm then does `⌈log2(n)⌉` passes over the stack, one
per bit of that rank, from the least significant bit to the most significant.
On each pass every element is examined once: if the current bit is `1` it is
rotated back into `a`; if `0` it is pushed to `b`. After a full pass, the
elements pushed to `b` are pushed back on top of `a`. After `log2(n)` passes,
`a` is fully sorted. Each pass is O(n) and there are O(log n) passes, for a
total of **O(n log n)** operations — this is used for heavily disordered
stacks (`disorder ≥ 0.5`), where it clearly outperforms the O(n²) and O(n√n)
approaches.

### 4. Adaptive (`adaptive.c`)

Measures the disorder of the input and dispatches to one of the three
strategies above based on the following thresholds:

| Disorder | Strategy used | Complexity |
|---|---|---|
| `< 0.2` | Simple | O(n²) |
| `0.2 – 0.5` | Medium | O(n√n) |
| `≥ 0.5` | Complex (radix) | O(n log n) |

**Rationale:** a stack with low disorder is nearly sorted already, so the
number of *actual* operations a quadratic algorithm performs stays small even
though its theoretical worst case is O(n²); a stack with high disorder has
close to the maximum number of inversions, where only a genuinely
sub-quadratic strategy keeps the operation count reasonable. The `0.2` and
`0.5` cut-offs were chosen empirically by benchmarking all three algorithms
against random inputs at varying disorder levels and picking the crossover
points where each strategy starts to outperform the others in total
operation count. Space complexity for all four strategies is O(n): each
holds, at most, one extra node per input element on stack `b`
(`t_list` nodes, no auxiliary arrays).

---

## Resources

- [Codingame — push_swap coding rules](https://www.codingame.com/) (algorithm complexity reference)
- GeeksforGeeks — [Radix sort](https://www.geeksforgeeks.org/dsa/radix-sort/), [Insertion sort](https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/)

### AI usage disclosure

AI assistance (ChatGPT) was used during this project as a learning, debugging,
and review aid.

It was used for:

- Reviewing code and checking for logic or edge-case issues.
- Clarifying parts of the sorting algorithms and stack operations when needed.
- Reviewing benchmark output, parsing, and integration between project modules.
- Helping organize and review the README.
AI-generated explanations and code suggestions were reviewed and understood
before being incorporated into the project. The final implementation,
integration, testing, and debugging were performed and verified by the project
authors.

---

## Contributions

- **betdemir**:
  - Argument parsing and validation.
  - Error handling.
  - Simple sorting strategy.
  - Binary LSD Radix Sort strategy.

- **zeyalcin**:
  - Stack data structure and stack utility functions.
  - Low-level Push_swap operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`,
    `rr`, `rra`, `rrb`, `rrr`).
  - Index assignment.
  - Disorder metric.
  - Chunk/range-based Medium sorting strategy.

- **Shared work**:
  - Adaptive strategy and strategy dispatch.
  - Benchmark mode.
  - Integration and optimization.
  - Testing and debugging.
  - Makefile.
  - README.

Both learners reviewed the complete codebase and are able to explain the
implementation and design decisions used throughout the project.