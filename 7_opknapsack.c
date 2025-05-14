#include <stdio.h>
#include <conio.h>

int i, j, n, c, w[10], p[10], v[10][10];

void knapsack(int n, int w[10], int p[10], int c) {
    int max(int, int);
    
    // Fill the table v[][] based on the weights and profits
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= c; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i] > j)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], (v[i - 1][j - w[i]] + p[i]));
        }
    }

    // Display the maximum profit
    printf("\n\n Maximum Profit is : %d ", v[n][c]);
    
    // Display the table of values
    printf("\n\n\n Table : \n\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= c; j++) {
            printf("\t%d", v[i][j]);
        }
        printf("\n");
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void main() {
    clrscr();  // Clear screen for old compilers, can be removed in modern compilers.
    
    printf("\n Enter the number of objects: ");
    scanf("%d", &n);
    
    printf("\n Enter the weights: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    
    printf("\n Enter the Profits: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    
    printf("\n Enter the capacity: ");
    scanf("%d", &c);
    
    knapsack(n, w, p, c);
    
    getch();  // To pause the output, can be removed for most modern compilers.
}
