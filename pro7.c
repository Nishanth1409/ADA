#include <stdio.h>

void greedyKnapsack(int n, int w[], int p[], int m) {
    double maxProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n && currentWeight < m; i++) {
        if (currentWeight + w[i] <= m) {
            currentWeight += w[i];
            maxProfit += p[i];
        } else {
            maxProfit += (double)(m - currentWeight) * p[i] / w[i];
            break;
        }
    }

    printf("Optimal solution for greedy method: %.1f\n", maxProfit);
}

int main() {
    int n, m;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    int w[n], p[n];

    printf("Enter the objects' weights: ");
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);

    printf("Enter the objects' profits: ");
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);

    printf("Enter the maximum capacity: ");
    scanf("%d", &m);

    greedyKnapsack(n, w, p, m);

    return 0;
}
