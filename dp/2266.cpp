class Solution {
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size(), win_len = 0, j = 0;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') {
                win_len = 4;
            } else {
                win_len = 3;
            }

            for (j = i - 1; j >= 0 && j >= i - win_len; j--) {
                if (pressedKeys[i-1] != pressedKeys[j]) {
                    break;
                }
                // printf("%d %d\n", i, j);
                dp[i] += dp[j];
                dp[i] %= 1000000007;
            }

            // printf("dp[%d]=%d\n", i, dp[i]);
        }
        return dp[n];
    }
};