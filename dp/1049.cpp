class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // s[0], s[1], ..., s[n-1]
        // (s[b] - s[a]) - s[c] ...
        // divide all stones to two piles
        // suppose the bigger one is A, the smaller one is B
        // A + B = sum(s), A - B = ans
        // we need to minimize ans, ans = sum(s) - 2 * B
        // and we need at most one stone left, so ans >= 0, B <= sum(s) / 2
        // the problem is translated to:
        // can we choose i stones and make j (the sum of them) and j <= sum(s) / 2
        // dp[i][j] = dp[i-1][j]
        // or dp[i][j - s[i]] if j >= s[i]

        int n = stones.size(), sum = 0;

        for (auto&& stone:stones) {
            sum += stone;
        }

        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, 0));

        dp[0][0] = 1;

        int res = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum / 2; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= stones[i-1]) {
                    dp[i][j] |= dp[i-1][j - stones[i-1]];
                }

                if (dp[i][j]) {
                    res = max(res, j);
                }
            }
        }

        return sum - 2 * res;
    }
};