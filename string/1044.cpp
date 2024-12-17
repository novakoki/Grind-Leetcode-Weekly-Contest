class Solution {
public:
    string longestDupSubstring(string s) {
        typedef unsigned long long ull;
        int n = s.length(), base = 131;
        vector<ull> hash(n + 1, 0);
        vector<ull> pow(n + 1, 0);
        pow[0] = 1;

        for (int i = 1; i <= n; i++) {
            hash[i] = hash[i-1] * base + (s[i-1] - 'a');
            pow[i] = pow[i-1] * base;
        }

        int left = 1, right = n + 1, mid = 0;
        string res = "";

        while (left < right) {
            mid = left + (right - left) / 2;
            // printf("%d\n", mid);
            bool valid = false;
            unordered_set<ull> hash_set;
            for (int i = 0; i + mid <= n; i++) {
                ull sub_hash = (hash[i+mid] - hash[i] * pow[mid]);
                // printf("%d %d %llu\n", i, i+mid, sub_hash);
                if (hash_set.count(sub_hash)) {
                    valid = true;
                    res = s.substr(i, mid);
                    break;
                }
                hash_set.insert(sub_hash);
            }
            // printf("\n");

            if (valid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return res;
    }
};