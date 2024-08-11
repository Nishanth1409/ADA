#include <stdio.h>
#define INF 99999 // Define a large value to represent infinity

void main() {
    int i, j, k, cost[10][10], n;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0) {
                cost[i][j] = INF; // No direct path
            }
        }
    }
    
    // Floyd-Warshall algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if ((cost[i][k] + cost[k][j]) < cost[i][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }
    
    printf("The shortest paths between every pair of vertices:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if (cost[i][j] == INF) {
                printf("Edge %d to %d, cost is INF\n", i, j);
            } else {
                printf("Edge %d to %d, cost is %d\n", i, j, cost[i][j]);
            }
        }
    }
}




// 4

// 0 3 99999 7
// 99999 0 1 99999
// 99999 99999 0 2
// 99999 99999 99999 0