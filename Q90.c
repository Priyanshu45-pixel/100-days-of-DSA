#include <stdio.h>

// Check if painting is possible within maxTime
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {

        // If a single board exceeds maxTime
        if (arr[i] > maxTime)
            return 0;

        if (currentTime + arr[i] > maxTime) {
            painters++;
            currentTime = arr[i];

            if (painters > k)
                return 0;
        } else {
            currentTime += arr[i];
        }
    }

    return 1;
}

// Function to find minimum time
int minTime(int arr[], int n, int k) {
    int max = arr[0], sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        sum += arr[i];
    }

    int low = max, high = sum, result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            result = mid;
            high = mid - 1;  // try smaller time
        } else {
            low = mid + 1;   // increase time
        }
    }

    return result;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minTime(arr, n, k));

    return 0;
}