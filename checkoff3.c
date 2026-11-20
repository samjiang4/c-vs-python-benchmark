#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static uint64_t sum_squares(uint64_t n) {
    uint64_t total = 0;
    for (uint64_t i = 0; i < n; i++) {
        total += i * i; 
    }
    return total;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s n\n", argv[0]);
        return 1;
    }
    uint64_t n = strtoull(argv[1], NULL, 10);
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    uint64_t r = sum_squares(n);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double secs = (t1.tv_sec - t0.tv_sec) +
                  (t1.tv_nsec - t0.tv_nsec) / 1e9;
    printf("%llu %.6f\n", (unsigned long long)r, secs);
    return 0;
}
