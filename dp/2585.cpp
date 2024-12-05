class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int v = 1; v <= target; v++) {
                for (int j = 0; j <= min(types[i-1][0], v / types[i-1][1]); j++) {
                    if (v - j * types[i-1][1] >= 0) {
                        dp[i][v] += dp[i-1][v - j * types[i-1][1]];
                        dp[i][v] %= 1000000007;
                    }
                }
                // printf("%d %d %d\n", i, v, dp[i][v]);
            }
        }

        return dp[n][target];
    }

    int waysToReachTargetSpaceOptimization(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
    
        for (int i = 0; i < n; i++) {
            // question 1: why reversely iterate ?
            for (int v = target; v > 0; v--) {
                // question 2: why from j=1 instead of 0 ?
                for (int j = 1; j <= min(types[i][0], v / types[i][1]); j++) {
                    if (v - j * types[i][1] >= 0) {
                        dp[v] += dp[v - j * types[i][1]];
                        dp[v] %= 1000000007;
                    }
                }
                // printf("%d %d %d\n", i, v, dp[i][v]);
            }
        }

        return dp[target];
    }
};