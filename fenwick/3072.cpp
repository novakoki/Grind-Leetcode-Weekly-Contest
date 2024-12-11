class Solution {
public:
    int query(const vector<int>& tree, int i) {
        int sum = 0;

        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }

        return sum;
    }

    void inc(vector<int>& tree, int i) {
        for (; i < tree.size(); i += (i & -i)) {
            tree[i]++;
        }
    }

    vector<int> resultArray(vector<int>& nums) {
        map<int, int> id_map;
        for (auto&& num:nums) {
            id_map[num] = 0;
        }
        int max_id = 0;
        for (auto& p:id_map) {
            max_id++;
            p.second = max_id;
        }

        vector<int> arr1, arr2, tree1(max_id + 1, 0), tree2(max_id + 1, 0);

        arr1.push_back(nums[0]);
        inc(tree1, id_map[nums[0]]);
        arr2.push_back(nums[1]);
        inc(tree2, id_map[nums[1]]);

        int g1 = 0, g2 = 0;

        for (int i = 2; i < nums.size(); i++) {
            g1 = arr1.size() - query(tree1, id_map[nums[i]]);
            g2 = arr2.size() - query(tree2, id_map[nums[i]]);
            
            if (g1 < g2 || (g1 == g2 && arr2.size() < arr1.size())) {
                arr2.push_back(nums[i]);
                inc(tree2, id_map[nums[i]]);
            } else {
                arr1.push_back(nums[i]);
                inc(tree1, id_map[nums[i]]);
            }
        }

        for (auto&& num:arr2) {
            arr1.push_back(num);
        }

        return arr1;
    }
};