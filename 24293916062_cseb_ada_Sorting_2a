#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two subarrays into a sorted array
void merge(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively divide the array into two halves
        merge(arr, left, mid);
        merge(arr, mid + 1, right);

        // Temporary arrays to hold the two halves
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int leftArr[n1], rightArr[n2];

        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int i = 0; i < n2; i++) {
            rightArr[i] = arr[mid + 1 + i];
        }

        // Merge the temp arrays back into the original array
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
            }
        }

        // Copy the remaining elements of leftArr[], if any
        while (i < n1) {
            arr[k++] = leftArr[i++];
        }

        // Copy the remaining elements of rightArr[], if any
        while (j < n2) {
            arr[k++] = rightArr[j++];
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate random numbers for the array
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Random number between 0 and 999
    }
}

int main() {
    int n;

    // Ask for the number of elements in the array
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    // Allocate memory for the array
    int arr[n];

    // Generate random numbers for the array
    generateRandomArray(arr, n);

    // Record start time
    clock_t start = clock();

    // Sort the array using Merge Sort
    merge(arr, 0, n - 1);

    // Record end time
    clock_t end = clock();

    // Calculate time taken in seconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the sorted array (Optional)
    // printArray(arr, n);

    // Print time taken for sorting
    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    return 0;
}
