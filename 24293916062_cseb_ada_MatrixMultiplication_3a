#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to multiply two matrices
void multiply(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter size of square matrix (n): ");
    scanf("%d", &n);

    // Dynamic allocation
    int (*A)[n] = malloc(sizeof(int[n][n]));
    int (*B)[n] = malloc(sizeof(int[n][n]));
    int (*C)[n] = malloc(sizeof(int[n][n]));

    // Initialize matrices with random numbers
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Measure execution time
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    multiply(n, A, B, C);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Matrix multiplication completed for size %d x %d\n", n, n);
    printf("Execution time: %f seconds\n", cpu_time_used);

    // Free memory
    free(A);
    free(B);
    free(C);

    return 0;
}
