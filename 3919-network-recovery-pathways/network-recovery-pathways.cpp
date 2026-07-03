class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        long long maxEdgeCost = 0;

        // Precompute maximum edge cost
        for (auto &e : edges) {
            maxEdgeCost = max(maxEdgeCost, (long long)e[2]);
        }

        // Function to check if a path with min edge >= limit exists
        auto isValid = [&](long long limit) {
            vector<vector<pair<int,long long>>> rrr(n);
            vector<int> indegree(n, 0);

            // Build reduced graph
            for (auto &e : edges) {
                int u = e[0], v = e[1];
                long long w = e[2];
                if (w >= limit && online[u] && online[v]) {
                    rrr[u].push_back({v, w});
                    indegree[v]++;
                }
            }

            // Topological order
            vector<int> topo;
            topo.reserve(n);
            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (indegree[i] == 0) q.push(i);
            }
            while (!q.empty()) {
                int u = q.front(); q.pop();
                topo.push_back(u);
                for (auto &edge : rrr[u]) {
                    if (--indegree[edge.first] == 0) q.push(edge.first);
                }
            }

            // DP for shortest path
            vector<long long> dist(n, LLONG_MAX);
            dist[0] = 0;
            for (int u : topo) {
                if (dist[u] == LLONG_MAX) continue;
                for (auto &edge : rrr[u]) {
                    int v = edge.first;
                    long long w = edge.second;
                    dist[v] = min(dist[v], dist[u] + w);
                }
            }

            return dist[n-1] <= k;
        };

        // Binary search for maximum feasible score
        long long low = 0, high = maxEdgeCost, best = -1;
        while (low <= high) {
            long long mid = low+(high-low) / 2;
            if (isValid(mid)) {
                best = mid;
                low = mid + 1; // try higher
            } else {
                high = mid - 1; // lower threshold
            }
        }
        return best;
    }
};