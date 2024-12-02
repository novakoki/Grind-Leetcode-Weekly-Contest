class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r = grid[i][j] % k;
                if (i > 0) {
                    for (int s = 0; s < k; s++) {
                        dp[i][j][(r + s) % k] += dp[i-1][j][s];
                        dp[i][j][(r + s) % k] %= 1000000007;
                    }
                }

                if (j > 0) {
                    for (int s = 0; s < k; s++) {
                        dp[i][j][(r + s) % k] += dp[i][j-1][s];
                        dp[i][j][(r + s) % k] %= 1000000007;
                    }
                }
            }
        }

        return dp[n-1][m-1][0];
    }
};