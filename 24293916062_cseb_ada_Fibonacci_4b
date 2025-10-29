#include <stdio.h>

int fibonacci_recursive(int n) {
  if(n<=1){
    return n;
  }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series (Recursive): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci_recursive(i));
    }
    printf("\n");
    return 0;
}

