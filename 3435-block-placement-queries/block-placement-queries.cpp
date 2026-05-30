class FenwickTree {
public:
    FenwickTree(int n) : vals(n + 1) {}

    void maximize(int i, int val) {
        while (i < (int)vals.size()) {
            vals[i] = max(vals[i], val);
            i += lowbit(i);
        }
    }

    int get(int i) const {
        int res = 0;
        while (i > 0) {
            res = max(res, vals[i]);
            i -= lowbit(i);
        }
        return res;
    }

private:
    vector<int> vals;
    static int lowbit(int i) { return i & -i; }
};
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int n = min(50000, (int)queries.size() * 3);
        vector<bool> ans;
        FenwickTree tree(n + 1);
        set<int> obstacles{0, n}; // sentinel values

        // First pass: insert all obstacles
        for (const auto& query : queries) {
            if (query[0] == 1) {
                int x = query[1];
                obstacles.insert(x);
            }
        }

        // Build initial free segments
        for (auto it = obstacles.begin(); next(it) != obstacles.end(); ++it) {
            int x1 = *it;
            int x2 = *next(it);
            tree.maximize(x2, x2 - x1);
        }

        // Process queries backwards
        for (int i = (int)queries.size() - 1; i >= 0; --i) {
            int type = queries[i][0];
            int x = queries[i][1];

            if (type == 1) {
                auto it = obstacles.find(x);
                if (next(it) != obstacles.end()) {
                    tree.maximize(*next(it), *next(it) - *prev(it));
                }
                obstacles.erase(it);
            } else {
                int sz = queries[i][2];
                auto it = obstacles.upper_bound(x);
                int prevVal = *std::prev(it);
                ans.push_back(tree.get(prevVal) >= sz || x - prevVal >= sz);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans; 
    }
};