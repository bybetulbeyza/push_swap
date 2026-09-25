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

## Compilation

Compile the project with:

```bash
make