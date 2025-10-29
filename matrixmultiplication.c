#include <stdio.h>
#include <stdlib.h>

int C1,R2,R1,C2;


void multiplyMatrix(int m1[][C1], int m2[][C2]) {
    int result[R1][C2];
    printf("matrix is");



    
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < R2; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    if (C1 != R2) {
        printf("Columns of Matrix-1 must equal rows of Matrix-2\n");
        exit(EXIT_FAILURE);
    }
    int m1[R1][C1] = {{1,1}, {2,2}};
    int m2[R2][C2] = {{1,1,1}, {2,2,2}};
    multiplyMatrix(m1, m2);
    return 0;
}