#include <stdio.h>
int main() {
    int n, i, j = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter sorted array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    printf("Array after removing duplicates:\n");
    for (i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
