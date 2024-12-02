class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        map<int, long long> dp;

        for (int i = 0; i < n; i++) {
            dp[power[i]] += power[i];
        }

        for (auto it = dp.rbegin(); it != dp.rend(); it++) {
            // printf("%d %lld\n", it->first, it->second);
            auto it1 = dp.lower_bound(it->first + 3);
            if (it1 != dp.end()) {
                // printf("add %d: %lld\n", it1->first, it1->second);
                it->second += it1->second;
            }

            if (dp.find(it->first + 2) != dp.end()) {
                it->second = max(it->second, dp[it->first + 2]);
            }

            if (dp.find(it->first + 1) != dp.end()) {
                it->second = max(it->second, dp[it->first + 1]);
            }
        }

        return dp.begin()->second;
    }
};