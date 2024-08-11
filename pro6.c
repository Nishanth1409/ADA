#include<stdio.h>

int w[10], p[10], n;

int max(int a, int b) {
    return a > b ? a : b;
}

int knap(int i, int m) {
    if (i == n) return w[i] > m ? 0 : p[i];
    return w[i] > m ? knap(i + 1, m) : max(knap(i + 1, m), knap(i + 1, m - w[i]) + p[i]);
}

int main() {
    int W, i, max_profit;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);
    printf("Enter profits followed by weights:\n");
    for (i = 1; i <= n; i++)
        scanf("%d %d", &p[i], &w[i]);

    max_profit = knap(1, W);
    printf("Max profit = %d\n", max_profit);
    return 0;
}
