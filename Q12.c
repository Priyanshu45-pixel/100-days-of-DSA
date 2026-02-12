#include <stdio.h>
int main() {
    int m, n, i, j;
    int matrix[10][10];
    int symmetric = 1;
    scanf("%d %d", &m, &n);
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (!symmetric)
            break;
    }
    if (symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");
    
    return 0;
}
