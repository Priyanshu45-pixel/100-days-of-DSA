#include <stdio.h>
#include <stdlib.h>

// Structure for bucket (dynamic array)
typedef struct {
    float *arr;
    int count;
} Bucket;

// Insertion sort for each bucket
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket Sort function
void bucketSort(float arr[], int n) {
    // Step 1: Create n buckets
    Bucket buckets[n];

    for (int i = 0; i < n; i++) {
        buckets[i].arr = (float *)malloc(n * sizeof(float));
        buckets[i].count = 0;
    }

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];  // bucket index
        buckets[index].arr[buckets[index].count++] = arr[i];
    }

    // Step 3: Sort each bucket
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i].arr, buckets[i].count);
    }

    // Step 4: Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[k++] = buckets[i].arr[j];
        }
        free(buckets[i].arr);
    }
}

// Driver code
int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter elements (range [0,1)):\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%.3f ", arr[i]);

    return 0;
}