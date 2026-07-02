class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
         int rows = grid.size();
        int cols = grid[0].size();

        // Track minimum health lost to reach each cell
        vector<vector<int>> minLoss(rows, vector<int>(cols, INT_MAX));
        minLoss[0][0] = grid[0][0];

        queue<pair<int,int>> q;
        q.push({0,0});

        // Directions: up, down, left, right
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    int newLoss = minLoss[x][y] + grid[nx][ny];
                    if (newLoss < minLoss[nx][ny]) {
                        minLoss[nx][ny] = newLoss;
                        q.push({nx, ny});
                    }
                }
            }
        }

        // Safe if health remaining ≥ 1
        return minLoss[rows-1][cols-1] < health;
    }
};