class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        // after swap
        // new_sum = nums1[0] + ... + nums1[left-1]
        // + nums2[left] + ... + nums2[right]
        // + nums1[right+1] + ... + nums1[n-1]
        // new_sum - sum = nums2[left] - nums1[left] + ... + nums2[right] - nums1[left]

        int n = nums1.size(), s = 0, diff = 0, max_diff = 0, res = 0;
        for (int i = 0; i < n; i++) {
            s += nums1[i];
            diff = max(diff + (nums2[i] - nums1[i]), nums2[i] - nums1[i]);
            max_diff = max(max_diff, diff);
        }
        res = s + max_diff;
        s = 0;
        diff = 0;
        max_diff = 0;
        for (int i = 0; i < n; i++) {
            s += nums2[i];
            diff = max(diff + (nums1[i] - nums2[i]), nums1[i] - nums2[i]);
            max_diff = max(max_diff, diff);
        }
        res = max(res, s + max_diff);

        return res;
    }
};