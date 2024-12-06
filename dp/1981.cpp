class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();

        int sum = 0, max_ele = 0;
        for (int i = 0; i < n; i++) {
            max_ele = 0;
            for (int j = 0; j < m; j++) {
                max_ele = max(max_ele, mat[i][j]);
            }
            sum += max_ele;
        }

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, false));

        dp[0][0] = true;

        int res = INT_MAX;
        for (int i = 1; i <= n; i++) {
            // printf("%d: ", i);
            for (int v = 1; v <= sum; v++) {
                for (int j = 1; j <= m; j++) {
                    // dp[i][v] = dp[i-1][v];
                    if (v >= mat[i-1][j-1]) {
                        dp[i][v] |= dp[i-1][v - mat[i-1][j-1]];
                        if (dp[i][v]) {
                            // printf("%d,%d ", j, v);
                            break;
                        }
                    }
                }

                if ((i == n) && dp[i][v]) {
                    res = min(res, abs(v - target));
                }
            }
            // printf("\n");
        }

        return res;
    }
};