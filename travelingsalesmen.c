#include <stdio.h>
#include <limits.h>

#define MAX 10

int cost[MAX][MAX], n, minCost = INT_MAX;

int tsp(int city, int visited[], int count, int costSoFar) {
    if (count == n) {
        if (cost[city][0] != 0)
            return costSoFar + cost[city][0];
        return INT_MAX;
    }

    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] != 0) {
            visited[i] = 1;
            int newCost = tsp(i, visited, count + 1, costSoFar + cost[city][i]);
            if (newCost < min)
                min = newCost;
            visited[i] = 0;
        }
    }
    return min;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    int visited[MAX] = {0};
    visited[0] = 1;
    printf("The minimum cost of the tour is: %d\n", tsp(0, visited, 1, 0));
    return 0;
}
