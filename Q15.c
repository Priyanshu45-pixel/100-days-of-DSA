#include <stdio.h>
int main() {
    int m, n;
    int sum = 0;
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);

            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }
    printf("%d", sum);

    return 0;
}
