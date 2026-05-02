#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {

        // If a single book has more pages than maxPages → not possible
        if (arr[i] > maxPages)
            return 0;

        // Allocate to next student if limit exceeds
        if (currentPages + arr[i] > maxPages) {
            students++;
            currentPages = arr[i];

            if (students > m)
                return 0;
        } else {
            currentPages += arr[i];
        }
    }

    return 1;
}

// Function to allocate books
int allocateBooks(int arr[], int n, int m) {
    if (n < m)
        return -1;

    int max = arr[0], sum = 0;

    // Find max and sum
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        sum += arr[i];
    }

    int low = max;
    int high = sum;
    int result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;   // try smaller maximum
        } else {
            low = mid + 1;    // increase limit
        }
    }

    return result;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", allocateBooks(arr, n, m));

    return 0;
}