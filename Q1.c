#include <stdio.h>
int main() {
    int arr[100], n, x, pos, i;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to insert: ");
    scanf("%d", &x);
    printf("Enter the 1-based position (1 to %d): ", n + 1);
    scanf("%d", &pos);
    for (i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = x;


    n++;

    
    printf("Array after insertion: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}