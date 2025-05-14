#include <stdio.h>

int n = 5;
int p[10] = {3, 3, 2, 5, 1};
int w[10] = {10, 15, 10, 12, 8};
int W = 10;

int main() {
    int cur_w;
    float tot_v = 0;
    int i, maxi;
    int used[10];
    
    // Initialize all items as unused
    for (i = 0; i < n; ++i)
        used[i] = 0;
    
    cur_w = W;
    
    // Loop until there's no more space left in the knapsack
    while (cur_w > 0) {
        maxi = -1;
        
        // Find the item with the highest value per weight ratio
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) && ((maxi == -1) || ((float)w[i] / p[i] > (float)w[maxi] / p[maxi]))))
                maxi = i;
        
        used[maxi] = 1;
        cur_w -= p[maxi];
        tot_v += w[maxi];
        
        // Check if the current item fits completely
        if (cur_w >= 0)
            printf("Added object %d (%d, %d) completely in the bag. Space left: %d.\n", maxi + 1, w[maxi], p[maxi], cur_w);
        else {
            // If not, add a fraction of it
            printf("Added %d%% (%d, %d) of object %d in the bag.\n", (int)((1 + (float)cur_w / p[maxi]) * 100), w[maxi], p[maxi], maxi + 1);
            tot_v -= w[maxi];
            tot_v += (1 + (float)cur_w / p[maxi]) * w[maxi];
        }
    }
    
    // Output the total value of the filled knapsack
    printf("Filled the bag with objects worth %.2f.\n", tot_v);
    
    return 0;
}
