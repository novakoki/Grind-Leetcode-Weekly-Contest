class Solution {
public:
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        map<int, set<int>> verts;
        map<int, int> idY;

        for (int i = 0; i < yCoord.size(); i++) {
            idY[yCoord[i]] = 0;
        }
        int id = 1;
        for (auto& p:idY) {
            p.second = id;
            id++;
        }

        for (int i = 0; i < xCoord.size(); i++) {
            verts[xCoord[i]].insert(yCoord[i]);
        }

        vector<int> tree(idY.size() + 1, 0);

        auto query = [&](int i) {
            int sum = 0;
            while (i > 0) {
                sum += tree[i];
                i -= (i & -i);
                // printf("query\n");
            }
            return sum;
        };

        auto add = [&](int i) {
            // printf("add %d\n", i);
            while (i <= idY.size()) {
                tree[i]++;
                i += (i & -i);
                // printf("add\n");
            }
        };

        long long res = -1;
        unordered_map<long long, pair<int,int>> last_cnt_map;

        for (auto&& p:verts) {
            auto&& ys = p.second;

            for (auto it = ys.begin(); it != ys.end(); it++) {
                int y2 = *it, y2_id = idY[y2];
                add(y2_id);

                if (it == ys.begin()) {
                    continue;
                }

                auto it1 = it;
                it1--;
                int y1 = *it1, y1_id = idY[y1];

                int cnt = query(y2_id) - query(y1_id - 1);
                long long key = (long long)y1_id * idY.size() + y2_id;

                if (last_cnt_map.count(key)) {
                    auto &[last_cnt, last_x] = last_cnt_map[key];
                    if (cnt - last_cnt == 2) {
                        res = max(res, (p.first - last_x) * (long long)(y2 - y1));
                    }
                }
                last_cnt_map[key] = {cnt, p.first};
            }
        }

        return res;
    }
};