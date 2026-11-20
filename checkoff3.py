import sys
import time

MASK = (1 << 64) - 1


def sum_squares(n):
    total = 0
    for i in range(n):
        total += i * i
    return total


n = int(sys.argv[1])
t0 = time.perf_counter()
r = sum_squares(n)
t1 = time.perf_counter()
print(r & MASK, f"{t1 - t0:.6f}")
