# Performance Comparison Report

## Measurement Methodology

In this experiment I compare two implementations to compute sum from 1 to n.

I compile both programs with same flags:

gcc -Wall -Wextra -Werror

I run everything on same macOS ARM machine.  
To measure time I use `clock()` from `<time.h>`:

- start = clock()
- execute code
- end = clock()
- time = (double)(end - start) / CLOCKS_PER_SEC

I run each version 5 times with n = 1,000,000,000.

Loop (O(n)):  
run1: 2.014862 s  
run2: 2.025123 s  
run3: 2.007668 s  
run4: 2.020184 s  
run5: 2.013844 s  
Average: 2.015230 s

Formula (O(1)):  
run1: 0.000078 s  
run2: 0.000079 s  
run3: 0.000080 s  
run4: 0.000080 s  
run5: 0.000079 s  
Average: 0.0000079 s

All numbers come from my program output.  
These measurements provide a solid basis to compare the two algorithms under the same conditions and show real execution time differences.

---

## Observed Performance Differences

Loop version take average 2.015230 seconds.  
Formula version take 0.0000079 seconds.

Difference:

2.015230 − 0.0000079 ≈ 2.0152221 seconds

Performance ratio:

2.015230 / 0.0000079 ≈ 255,092

So formula version is around 255,000 times faster.

Loop make more 600,000,000 iterations.  
Formula make only few operations.  
My measurements clearly show big impact of complexity.  
This demonstrates that algorithm choice is more important than low-level optimizations and can drastically change runtime.

---

## Relation Between Runtime and Energy Consumption

I did not measure power directly.  
But both programs run on same machine.

Loop run for about 2.015 seconds.  
Formula run for 0.0000079 seconds.

CPU stay active much longer for loop.  
So loop consume more energy.  
This conclusion based on measured runtime.  
From an engineering perspective, reducing runtime with better algorithms also reduces energy consumption, which can be critical in large-scale or battery-powered systems.

---

## Limitations of the Experiment

First limitation: I measure only CPU time with `clock()`.  
I did not measure real energy in joules.

Second limitation: small timing variation.  
Loop vary between 2.007 s and 2.025 s.

Background process and CPU scaling can affect results.  
These factors introduce minor variability, but the overall difference between the two algorithms is so large that conclusions remain valid.

---

## Practical Engineering Takeaway

From this experiment I see clearly algorithm matter a lot.

O(n) version take 2.015 seconds.  
O(1) version take 0.0000079 seconds.

Better algorithm give massive improvement.  
Much more important than micro optimization.  
Less runtime mean less CPU active time.  
Less CPU time mean less energy use.

In conclusion, choosing the right algorithm has a major impact on both performance and efficiency.  
Even small changes in approach can lead to huge differences in execution time and resource usage.  
This experiment highlights the importance of algorithm analysis and selection in practical software engineering.