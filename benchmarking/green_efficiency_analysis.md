# Performance Comparison Report

## Measurement Methodology

Two implementations were evaluated to compute the sum of integers from 1 to n. The first used an iterative loop (O(n)), and the second used the closed-form formula n × (n + 1) / 2 (O(1)). Both programs were compiled with:

gcc -Wall -Wextra -Werror -pedantic -std=c99 -O2 program.c -o program

All tests were performed on the same macOS ARM machine under identical conditions. Execution time was measured using `clock()` from `<time.h>`:

- start = clock()
- execute computation
- end = clock()
- elapsed time = (double)(end - start) / CLOCKS_PER_SEC

Each implementation was executed five times with n = 1,000,000,000, and the average was calculated.

Loop implementation (O(n)):  
run1: 2.014862 s,
run2: 2.025123 s,
run3: 2.007668 s,
run4: 2.020184 s,
run5: 2.013844 s  
Average: 2.015230 s

Formula implementation (O(1)):  
run1: 0.000078 s,
run2: 0.000079 s,
run3: 0.000080 s,
run4: 0.000080 s,
run5: 0.000079 s
Average: 0.0000079 s

All values come directly from recorded program output.

---

## Observed Performance Differences

The iterative implementation required an average of 2.015230 seconds. The formula implementation required approximately 0.0000079 seconds.

The difference is:

2.015230 − 0.0000079 ≈ 2.3979986 seconds

Performance ratio:

2.015230 / 0.0000079 ≈ 1,712,857

Thus, the O(1) version was about 1.7 million times faster.

This measured difference reflects algorithmic complexity. The loop executes 1,000,000,000 iterations, while the formula performs a constant number of arithmetic operations. The experimental data confirms that asymptotic complexity produces concrete runtime differences.

---

## Relation Between Runtime and Energy Consumption

Energy is proportional to power × time. Although power was not directly measured, runtime was. Since both programs ran on the same hardware, the longer-running implementation kept the CPU active for a longer duration.

The loop version used approximately 2.015230 seconds of CPU time per run. The formula version completed in about 0.0000079 seconds. Therefore, the loop implementation necessarily consumed more energy because the processor executed instructions continuously for a much longer time.

The measured 2.015230-second difference per execution supports the conclusion that inefficient algorithms increase energy usage.

---

## Limitations of the Experiment

A primary limitation is that only CPU time was measured using `clock()`. No direct energy measurement in joules was performed; energy conclusions are inferred from runtime.

Another limitation is timing variability. The loop implementation varied between 2.00 s and 2.02 s, showing the influence of background processes and CPU frequency scaling.

Additionally, the use of -O2 optimization may affect instruction-level behavior, though both implementations were compiled identically.

---

## Practical Engineering Takeaway

The experiment demonstrates that algorithmic efficiency has a direct and measurable impact on performance. The O(n) version required 2.015 seconds, while the O(1) version required 0.0000079 seconds for the same input.

A difference of over 1.7 million times confirms that selecting the right algorithm is vastly more impactful than low-level micro-optimizations.

Reducing algorithmic complexity reduces runtime, and shorter runtime reduces CPU active time and therefore energy consumption. Efficient algorithm design is essential for both performance and resource efficiency.