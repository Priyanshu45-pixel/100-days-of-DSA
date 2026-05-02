#include <stdio.h>

// Merge function that also counts inversions
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;     // left subarray
    int j = mid + 1;  // right subarray
    int k = left;
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);  // count inversions
        }
    }

    // Copy remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Merge Sort function
int mergeSort(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;

    if (left < right) {
        mid = (left + right) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}

// Driver code
int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions: %d\n", result);

    return 0;
}