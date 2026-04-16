#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1e15 // Large number for infinity

typedef struct {
    int i, m, o;
} Config;

long long calculate_cost(Config a, Config b, int w1, int w2, int w3) {
    return (long long)abs(a.i - b.i) * w1 + (long long)abs(a.m - b.m) * w2 + (long long)abs(a.o - b.o) * w3;
}

int main() {
    // Input parameters
    int L[] = {10, 10, 10};
    int W[] = {1, 3, 5};
    int D = 4;
    int targets[] = {15, 8};
    int num_targets = 2;

    // dp[I][O] stores min cost to be at configuration (I, M, O)
    // Using 11x11 because max limit is 10
    long long dp[11][11];
    long long next_dp[11][11];

    // Initialize DP with infinity
    for (int i = 0; i <= 10; i++)
        for (int o = 0; o <= 10; o++)
            dp[i][o] = INF;

    // Base case: Starting at (0,0,0) with cost 0
    dp[0][0] = 0;
    Config prev_cfg = {0, 0, 0}; 

    for (int t = 0; t < num_targets; t++) {
        int target_val = targets[t];
        for (int i = 0; i <= 10; i++)
            for (int o = 0; o <= 10; o++)
                next_dp[i][o] = INF;

        // Try all possible current configurations (i, m, o)
        for (int i = 0; i <= L[0]; i++) {
            for (int o = 0; o <= L[2]; o++) {
                int m = target_val - i - o;
                
                // Validate current configuration
                if (m >= 0 && m <= L[1] && abs(i - o) <= D) {
                    Config cur = {i, m, o};
                    
                    // Look at all valid configurations from the PREVIOUS step
                    for (int pi = 0; pi <= L[0]; pi++) {
                        for (int po = 0; po <= L[2]; po++) {
                            if (dp[pi][po] != INF) {
                                int pm = (t == 0) ? 0 : (targets[t-1] - pi - po);
                                Config prev = {pi, pm, po};
                                
                                long long cost = dp[pi][po] + calculate_cost(prev, cur, W[0], W[1], W[2]);
                                if (cost < next_dp[i][o]) {
                                    next_dp[i][o] = cost;
                                }
                            }
                        }
                    }
                }
            }
        }
        // Move next_dp to dp for the next target iteration
        for (int i = 0; i <= 10; i++)
            for (int o = 0; o <= 10; o++)
                dp[i][o] = next_dp[i][o];
    }

    // Find the minimum in the final DP table
    long long min_total_cost = INF;
    for (int i = 0; i <= 10; i++) {
        for (int o = 0; o <= 10; o++) {
            if (dp[i][o] < min_total_cost) min_total_cost = dp[i][o];
        }
    }

    printf("Minimum total wear cost: %lld\n", min_total_cost);

    return 0;
}