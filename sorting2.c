#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function for QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
            arr[i] = rand() % 10000;  // random numbers up to 10000
        }
    }

    clock_t start, end;
    double time_taken;

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    // Save sorted output (optional)
    fp = fopen("output.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);

    free(arr);
    return 0;
}