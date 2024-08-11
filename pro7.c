#include <stdio.h>
#define MAX 50
void greedyKnapsack(int n, int w[], int p[], int m) {
    double ratio[MAX], maxProfit = 0.0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++) ratio[i] = (double)p[i] / w[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                double tempRatio = ratio[i]; ratio[i] = ratio[j]; ratio[j] = tempRatio;
                int temp = w[i]; w[i] = w[j]; w[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }
    for (int i = 0; i < n && currentWeight < m; i++) {
        if (currentWeight + w[i] <= m) {
            currentWeight += w[i];
            maxProfit += p[i];
        } else {
            maxProfit += (m - currentWeight) * ratio[i];
            break;
        }
    }
    printf("Max Profit: %.1f\n", maxProfit);
}
int main() {
    int n, m, w[MAX], p[MAX];
    printf("Number of items:");
    scanf("%d", &n);
    printf("Weights:\n");
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    printf("Profits:\n");
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    printf("Max Capacity:");
    scanf("%d", &m);
    greedyKnapsack(n, w, p, m);
    return 0;
}
