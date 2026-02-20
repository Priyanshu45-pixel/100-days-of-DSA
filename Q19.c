#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = abs(arr[left] + arr[right]);
    int x = arr[left], y = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) < min_sum) {
            min_sum = abs(sum);
            x = arr[left];
            y = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", x, y);

    return 0;
}