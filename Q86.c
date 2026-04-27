#include <stdio.h>

int integerSqrt(int n) {
    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        // To avoid overflow, use mid <= n / mid instead of mid * mid
        if (mid <= n / mid) {
            ans = mid;        // mid^2 <= n → store answer
            low = mid + 1;    // try to find larger value
        } else {
            high = mid - 1;   // mid^2 > n → go left
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));

    return 0;
}