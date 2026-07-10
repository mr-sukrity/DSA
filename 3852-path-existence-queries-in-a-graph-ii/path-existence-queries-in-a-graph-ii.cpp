class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
         //Sort node indices by value
        vector<int> order(n);
        for (int i = 0; i < n; i++) order[i] = i;
        sort(order.begin(), order.end(), [&](int x, int y) {
            return nums[x] < nums[y];
        });

        vector<int> pos(n);          // pos[originalIndex] = rank in sorted order
        vector<long long> a(n);      // sorted values
        for (int k = 0; k < n; k++) {
            pos[order[k]] = k;
            a[k] = nums[order[k]];
        }

        //Component ids based on consecutive gaps
        vector<int> comp(n);
        comp[0] = 0;
        for (int k = 1; k < n; k++) {
            comp[k] = comp[k - 1] + ((a[k] - a[k - 1] > maxDiff) ? 1 : 0);
        }

        //Two-pointer to compute right[i]
        vector<int> right(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < i) j = i;
            while (j + 1 < n && a[j + 1] - a[i] <= maxDiff) j++;
            right[i] = j;
        }

        //Binary lifting table
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG = max(LOG, 1);

        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = right;
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        // Helper: minimum jumps from i to reach at least j (i < j, same component)
        auto getDist = [&](int i, int j) -> int {
            int cur = i;
            int steps = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < j) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }
            return steps + 1; // one more hop guaranteed to cover j
        };

        //Answer queries
        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            int pu = pos[u], pv = pos[v];
            if (comp[pu] != comp[pv]) {
                ans.push_back(-1);
                continue;
            }
            int i = min(pu, pv), jj = max(pu, pv);
            ans.push_back(getDist(i, jj));
        }

        return ans;
    }
};