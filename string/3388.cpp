class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        constexpr static int b = 31;
        // constexpr static int m = 1e9 + 9;
        vector<unsigned long long> b_pow(n + 1);
        b_pow[0] = 1;
        
        vector<unsigned long long> h(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            h[i] = h[i-1] * b + nums[i-1];
            b_pow[i] = b_pow[i-1] * b;
        }

        int res = 0;
        unordered_set<int> left;

        for (int i = 1; i + i < n; i++) {
            if ((h[i + i] - h[i] * b_pow[i]) == h[i]) {
                // printf("left split: %d, right split: %d~%d\n", i, i + i, n - 1);
                res += (n - 1 - (i + i) + 1);
                left.insert(i);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int len = 1; i - len > 0 && i + len <= n; len++) {
                bool valid_right = (h[i + len] - h[i] * b_pow[len]) == (h[i] - h[i-len] * b_pow[len]);
                bool duplicate = (left.count(i - len) && (i >= (i - len) * 2));
                if (valid_right && !duplicate) {
                    // printf("left split: %d, right split: %d\n", i - len, i);
                    res++;
                }
            }
        }
        
        return res;
    }
};