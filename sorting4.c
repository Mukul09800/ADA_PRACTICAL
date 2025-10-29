#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Insertion Sort function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n, choice;
    FILE *fp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Choose input method:\n1. Read from file\n2. Generate random numbers\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        fp = fopen("input.txt", "r");
        if (fp == NULL) {
            printf("Error opening file!\n");
            return 1;
        }
        for (int i = 0; i < n; i++) {
            fscanf(fp, "%d", &arr[i]);
        }
        fclose(fp);
    } else {
        srand(time(0));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10000;  // random numbers between 0 and 9999
        }
    }

    clock_t start, end;
    double time_taken;

    start = clock();
    insertionSort(arr, n);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    // Save sorted array (optional)
    fp = fopen("output.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);

    free(arr);
    return 0;
}