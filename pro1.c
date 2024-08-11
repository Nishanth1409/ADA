#include <stdio.h>
#include <limits.h>

#define MAX 10

int ne = 0, cost[MAX][MAX];

int findParent(int parent[], int i) {
    while (parent[i] != -1) {
        i = parent[i];
    }
    return i;
}

void unionParent(int parent[], int u, int v) {
    int pu = findParent(parent, u);
    int pv = findParent(parent, v);
    parent[pu] = pv;
}

int main() {
    int i, j, parent[MAX], u, v, n, a, b, min, mincost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize parent array
    for (i = 0; i < n; i++) {
        parent[i] = -1;
    }

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    while (ne < n - 1) {
        min = INT_MAX;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min && cost[i][j] != 0) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if (pu != pv) {
            printf("Edge %d (%d -> %d) mincost is %d\n", ++ne, u, v, min);
            mincost += min;
            unionParent(parent, pu, pv);
        }

        cost[a][b] = cost[b][a] = INT_MAX;  // Set the edge to a large value to avoid reprocessing
    }

    printf("Minimum cost is %d\n", mincost);

    return 0;
}
