#include <stdio.h>

void main() {
    int a[10][10], n, i, j, k;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                a[i][j] |= (a[i][k] && a[k][j]);

    printf("Transitive closure is:\n");
    for (i = 0; i < n; i++, printf("\n"))
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
}



// 4

// 0 1 0 0
// 1 0 0 1
// 0 0 0 0
// 0 1 0 0

