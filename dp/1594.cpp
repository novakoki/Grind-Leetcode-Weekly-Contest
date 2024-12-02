class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> min_dp(n, vector<long long>(m, LLONG_MAX)),
            max_dp(n, vector<long long>(m, LLONG_MIN));
        
        min_dp[0][0] = grid[0][0];
        max_dp[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) {
                    min_dp[i][j] = min(min_dp[i][j],
                        min(max_dp[i-1][j] * grid[i][j],
                            min_dp[i-1][j] * grid[i][j])
                    );
                    max_dp[i][j] = max(max_dp[i][j],
                        max(max_dp[i-1][j] * grid[i][j],
                            min_dp[i-1][j] * grid[i][j])
                    );
                }

                if (j > 0) {
                    min_dp[i][j] = min(min_dp[i][j],
                        min(max_dp[i][j-1] * grid[i][j],
                            min_dp[i][j-1] * grid[i][j])
                    );
                    max_dp[i][j] = max(max_dp[i][j],
                        max(max_dp[i][j-1] * grid[i][j],
                            min_dp[i][j-1] * grid[i][j])
                    );
                }
            }
        }

        return max_dp[n-1][m-1] >= 0 ? max_dp[n-1][m-1] % 1000000007 : -1;
    }
};
