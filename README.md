*This project has been created as part of the 42 curriculum by aamhamdi.*

# push_swap

## Description

`push_swap` sorts a stack of unique integers using only two stacks (`a` and `b`) and a small, fixed set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`), aiming to do it in as few operations as possible. The program takes the unsorted values as its arguments, computes a sequence of operations that sorts `a` in ascending order (smallest value on top), and prints that sequence to standard output — one instruction per line.

A companion bonus program, `checker`, reads a sequence of operations from standard input and replays them against a given stack, reporting whether the result is actually sorted (`OK`) or not (`KO`).

### Algorithm

- **≤ 3 elements**: solved directly with at most two operations (`sort_three`).
- **≤ 5 elements**: the two "extra" elements above 3 are temporarily pushed to stack `b`, the remaining 3 are sorted with `sort_three`, then everything is pushed back onto `a` at the right position (`sort_five`).
- **> 5 elements** (`sort_algo`): every node in `a` is ranked by its sorted position, then nodes are pushed onto `b` one at a time — at each step, the node that's currently cheapest to relocate (combining the rotate/reverse-rotate distance on both `a` and `b`, picking whichever direction is shorter) is moved first. Once `a` is reduced to 3 elements, those are sorted directly, and the rest are pushed back from `b` onto `a` in sorted order, each one going to its optimal position. This cost-based approach is what keeps the operation count well under the benchmark limits for large stacks (see below).

Internally, both stacks are implemented as a doubly linked, circular list (`t_list`/`t_stack`), which makes rotations cheap and avoids reallocating/shifting an array on every push.

### Measured performance

Run with several batches of random unique integers in `[-100000, 100000)` and verified against the project's own `checker`:

| Stack size | Operations (typical) | 100% validation threshold |
|---|---|---|
| 100 | ~540 – 620 | < 700 |
| 500 | ~5050 – 5350 | < 5500 |

All runs sorted correctly (`checker` reported `OK`), and both sizes land comfortably within the subject's top validation bracket. Exact counts vary slightly between runs since the input is randomized.

## Instructions

### Compilation

```bash
make          # builds push_swap
make bonus    # builds checker (links libft + a local get_next_line)
make clean    # removes object files
make fclean   # removes object files and both binaries
make re       # fclean + all
```

The Makefile builds `libft` (vendored in `libft/`) via its own Makefile first, then links it into both `push_swap` and `checker`. Compiled with `-Wall -Wextra -Werror` via `cc`.

### Running push_swap

```bash
./push_swap 2 1 3 6 5 8
```

```
sa
pb
pb
pb
sa
pa
pa
pa
```

Arguments can be passed either as separate shell arguments or as a single quoted, space-separated string — both are accepted. With no arguments, the program prints nothing and exits. Invalid input (non-integers, out-of-range values, duplicates) prints `Error` on stderr.

```bash
./push_swap 0 one 2 3
# Error
```

### Running checker (bonus)

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
# OK
```

`checker` takes the same initial stack as `push_swap`, then reads a sequence of operations (one per line) from stdin, applies them, and reports `OK` if `a` ends up sorted, `KO` otherwise, or `Error` on invalid input/instructions.

## Resources

- [push_swap visualizer (community tool)](https://github.com/o-reo/push_swap_visualizer) — useful for watching the stacks move step by step.
- General algorithmic background: insertion sort and "radix sort on stacks" approaches, which are the two classic strategies discussed for this project (this implementation follows a cost-based/greedy variant rather than literal radix sort).
- `man qsort`, `man malloc` — standard C reference material used while implementing the linked-list stack structure.
- 42's own Norm documentation, for the coding-style constraints the project must follow.

**AI usage:** AI assistance was used in a limited, supporting role — mainly to sanity-check the cost formula used to pick which node to relocate next (comparing rotate vs. reverse-rotate distance on both stacks) and to help think through edge cases (3, 5, and already-sorted inputs) before implementing them by hand. No function was generated wholesale by AI and pasted in; the linked-list stack model, the three sorting strategies, and the parsing/validation logic were designed and written directly, with AI used only as a rubber duck for specific algorithmic questions.
