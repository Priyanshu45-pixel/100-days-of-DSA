#include <stdio.h>
#include <stdlib.h>

// Interval structure
typedef struct {
    int start, end;
} Interval;

// Sort by start time
int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

// Merge intervals
void mergeIntervals(Interval arr[], int n) {
    if (n == 0) return;

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    // Temporary array to store result
    Interval result[n];
    int index = 0;

    result[index] = arr[0];

    // Step 2: Merge overlapping intervals
    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[index].end) {
            // Overlapping → merge
            if (arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        } else {
            // Non-overlapping → add new interval
            index++;
            result[index] = arr[i];
        }
    }

    // Print result
    printf("Merged intervals:\n");
    for (int i = 0; i <= index; i++) {
        printf("(%d, %d) ", result[i].start, result[i].end);
    }
}

// Driver code
int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval arr[n];

    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    mergeIntervals(arr, n);

    return 0;
}