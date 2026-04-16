#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;

    int map[10000];
    for (int i = 0; i < 10000; i++)
        map[i] = -2;

    int offset = 5000;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            max_len = i + 1;

        if (map[sum + offset] != -2) {
            int len = i - map[sum + offset];
            if (len > max_len)
                max_len = len;
        } else {
            map[sum + offset] = i;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLen(arr, n));

    return 0;
}