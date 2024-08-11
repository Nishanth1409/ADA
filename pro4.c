#include<stdio.h>
#define INF 999

void dijkstra(int n, int cost[10][10], int dist[10], int s) {
    int visited[10] = {0}, count = 1;
    for (int i = 1; i <= n; i++)
        dist[i] = (i == s) ? 0 : cost[s][i];

    while (count < n) {
        int min = INF, v = -1;
        for (int i = 1; i <= n; i++)
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                v = i;
            }
        if (v == -1) break;

        visited[v] = 1;
        count++;
        for (int i = 1; i <= n; i++)
            if (!visited[i] && dist[v] + cost[v][i] < dist[i])
                dist[i] = dist[v] + cost[v][i];
    }
}

int main() {
    int n, s, dist[10], cost[10][10];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }

    printf("Enter the source vertex: ");
    scanf("%d", &s);

    dijkstra(n, cost, dist, s);

    printf("Shortest distances from source vertex %d:\n", s);
    for (int i = 1; i <= n; i++)
        if (i != s)
            printf("%d -> %d = %d\n", s, i, dist[i]);

    return 0;
}


// 9

// 4  0  0  0  0  0  0  8  0
// 4  0  8  0  0  0  0  11 0
// 0  8  0  7  0  4  0  0  2
// 0  0  7  0  9  14 0  0  0
// 0  0  0  9  0  10 0  0  0
// 0  0  4  14 10 0  2  0  0
// 0  0  0  0  0  2  0  1  6
// 8  11 0  0  0  0  1  0  7
// 0  0  2  0  0  0  6  7  0