#include <stdio.h>
#include <time.h>

long long fib_dp(int n) {
    if (n <= 1)
        return n;
    long long table[n+1];
    table[0] = 0;
    table[1] = 1;
    for (int i = 2; i <= n; i++) {
        table[i] = table[i-1] + table[i-2];
    }
    return table[n];
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    clock_t start = clock();
    long long result = fib_dp(n);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Fib(%d) = %lld\n", n, result);
    printf("Time taken = %f sec\n", time_taken);

    return 0;
}