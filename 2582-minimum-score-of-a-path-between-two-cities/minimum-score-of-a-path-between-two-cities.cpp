class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
         // Build adjacency list: each city has neighbors with road distances
        vector<vector<pair<int,int>>> graph(n + 1);
        for (auto &road : roads) {
            int cityA = road[0], cityB = road[1], distance = road[2];
            graph[cityA].push_back({cityB, distance});
            graph[cityB].push_back({cityA, distance});
        }

        // Track visited cities
        vector<bool> visited(n + 1, false);
        int minDistance = INT_MAX;

        // Simple DFS function
        function<void(int)> dfs = [&](int current) {
            visited[current] = true;
            for (auto &edge : graph[current]) {
                int neighbor = edge.first;
                int roadLength = edge.second;

                // Update minimum distance found so far
                minDistance = min(minDistance, roadLength);

                if (!visited[neighbor]) {
                    dfs(neighbor);
                }
            }
        };

        // Start DFS from city 1
        dfs(1);

        return minDistance;
    }
};