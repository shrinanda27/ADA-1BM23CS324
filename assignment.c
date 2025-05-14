#include <stdio.h>
#include <limits.h>

#define MAX 10

int cost[MAX][MAX], n, x[MAX], y[MAX];

int findMinCost(int n) {
    int i, j, minCost = 0;
    for (i = 0; i < n; i++) {
        int min = INT_MAX;
        for (j = 0; j < n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                x[i] = i;
                y[i] = j;
            }
        }
        minCost += min;
    }
    return minCost;
}

int main() {
    printf("Enter number of workers/jobs: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("The minimum cost is: %d\n", findMinCost(n));
    return 0;
}
