#include <stdio.h>
#include <conio.h>

void main() {
    int i, j, n, v, k, min, u, c[20][20], s[20], d[20];

    clrscr();  // Clear screen (Turbo C++, not needed for modern compilers)

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    
    printf("\nEnter the cost adjacency matrix: ");
    printf("\nEnter 999 for no edge\n");
    
    // Read the adjacency matrix
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    
    // Read the source vertex
    printf("\nEnter the source vertex: ");
    scanf("%d", &v);

    // Initialize the shortest path array and distance array
    for (i = 1; i <= n; i++) {
        s[i] = 0;  // s[i] = 0 means the vertex i is not yet included in the shortest path tree
        d[i] = c[v][i];  // Set initial distances to the direct cost from source vertex v
    }
    d[v] = 0;  // Distance to the source itself is 0
    s[v] = 1;  // Mark the source vertex as included in the shortest path tree

    // Dijkstra's Algorithm
    for (k = 2; k <= n; k++) {
        min = 999;
        for (i = 1; i <= n; i++) {
            // Find the vertex with the smallest distance that is not yet included in the tree
            if ((s[i] == 0) && (d[i] < min)) {
                min = d[i];
                u = i;
            }
        }
        
        s[u] = 1;  // Include vertex u in the shortest path tree

        // Update the distance of the adjacent vertices of u
        for (i = 1; i <= n; i++) {
            if (s[i] == 0) {
                if (d[i] > (d[u] + c[u][i])) {
                    d[i] = d[u] + c[u][i];
                }
            }
        }
    }

    // Output the shortest distances from the source vertex
    printf("\nThe shortest distance from %d is:\n", v);
    for (i = 1; i <= n; i++) {
        printf("%d --> %d = %d\n", v, i, d[i]);
    }

    getch();  // Wait for user input (used in older compilers)
}
