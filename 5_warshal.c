#include <stdio.h>

int n;
int a[10][10];
int p[10][10];

void write_data() {
    int i, j;
    printf("The path matrix is shown below:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

void read_data() {
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void path_matrix() {
    int i, j, k;
    
    // Initialize the path matrix p with the adjacency matrix a
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            p[i][j] = a[i][j];
        }
    }
    
    // Floyd-Warshall algorithm to find the path matrix
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (p[i][k] == 1 && p[k][j] == 1) {
                    p[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    read_data();
    path_matrix();
    write_data();
    return 0;
}
