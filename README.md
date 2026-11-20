# C vs. Python Performance Benchmarking

Samuel Jiang — COMP211 Checkoff 3

## Question

How much does language implementation affect the runtime of a numerical loop?
This project compares C and Python programs that sum the squares of integers
from 0 through n - 1 using the same basic loop algorithm.

## Run the experiment

Requirements: GCC (or a compatible C compiler), Python 3, and a system supporting
`clock_gettime(CLOCK_MONOTONIC)` such as Linux or modern macOS.
Run these commands from this repository's root:

```bash
gcc -O2 -o sumsq checkoff3.c
./sumsq 100000000
python3 checkoff3.py 100000000
```

Each program prints its result followed by elapsed calculation time in seconds.
Use a nonnegative integer input that fits in uint64_t. These small demonstration
programs assume valid input; they do not fully validate command-line arguments.

## Observed results

The original experiment used n = 100,000,000. The screenshot in
[results/benchmark-output.png](results/benchmark-output.png) records these results:

| Program | Printed result | Runtime (seconds) |
| --- | --- | ---: |
| C, compiled with GCC -O2 | 662921401752298880 | 0.044634 |
| Python | 662921401752298880 | 2.348675 |

Python runtime / C runtime = approximately **52.6**. Optimized C completed this
calculation about 52.6 times faster in this run. These are single-run measurements,
not averages or medians. Hardware, OS, compiler version, and Python version were
not recorded in the supplied results, so exact reproduction is limited.

## What the comparison shows

C is compiled into machine code, and -O2 enables compiler optimizations. CPython
executes bytecode and handles integer objects at runtime. Those differences can
add substantial overhead in a long numerical loop. This experiment does not
isolate how much each individual factor contributes.

The integer arithmetic also differs: C uses uint64_t and wraps modulo 2^64,
while Python computes the full integer sum. Python's final mask keeps only the
lowest 64 bits, making the outputs comparable. That mask is outside the timed
calculation. Matching final outputs does not mean identical internal arithmetic.

Both timers surround the sum_squares call, excluding startup, input parsing,
and printing. Compiler transformations can still affect the generated C code;
this project does not claim the compiled loop was inspected.

## Limitations and next steps

- Repeat trials and compare medians to reduce the effect of timing noise.
- Record hardware, operating system, compiler version, and Python version.
- Compare different input sizes and compiler optimization settings.
- Inspect generated C assembly to investigate compiler transformations.
- Avoid generalizing this result to all C and Python workloads or to Python
  libraries that execute compiled code.

## Files

- [checkoff3.c](checkoff3.c): C implementation.
- [checkoff3.py](checkoff3.py): Python implementation.
- [slides/presentation.pptx](slides/presentation.pptx): presentation slides.
- [results/benchmark-output.png](results/benchmark-output.png): original output.

## Further reading

- [Python time.perf_counter](https://docs.python.org/3/library/time.html#time.perf_counter)
- [Python integer types](https://docs.python.org/3/library/stdtypes.html#numeric-types-int-float-complex)
- [GCC optimization options](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)

## AI exploration

AI assisted with explanations and repository preparation. The assignment's
personal AI reflection and conversation permalink should be submitted separately.
