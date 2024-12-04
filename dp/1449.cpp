class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();
        vector<string> dp(target + 1, "-");
        dp[0] = "";

        for (int i = 1; i <= n; i++) {
            for (int j = cost[i-1]; j <= target; j++) {
                string s = dp[j - cost[i-1]];
                if (s[0] == '-') continue;

                // s += (char)(i + '0');
                auto it = lower_bound(s.begin(), s.end(), (char)(i + '0'), greater<char>());
                s.insert(it, (char)(i + '0'));
                if (s.length() > dp[j].length()
                    || (s.length() == dp[j].length() && s > dp[j])
                ) {
                    dp[j] = s;
                }
                // printf("%d %d %s\n", i, j, dp[j].c_str());
            }
        }

        if (dp[target] == "-") {
            return "0";
        }

        return dp[target];
    }
};