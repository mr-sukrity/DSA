class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
         const int MOD = 1e9+7;
        int n = board.size();

        // dp[i][j] = max score to reach (i,j) from 'S'
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // count[i][j] = number of ways to achieve dp[i][j]
        vector<vector<int>> count(n, vector<int>(n, 0));

        dp[n-1][n-1] = 0;   // starting point 'S'
        count[n-1][n-1] = 1;

        // directions: up, left, diagonal up-left
        int dirs[3][2] = {{-1,0},{0,-1},{-1,-1}};

        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (board[i][j] == 'X' || (i==n-1 && j==n-1)) continue;

                int best = -1;
                long long ways = 0;

                for (auto& d : dirs) {
                    int x = i - d[0], y = j - d[1];
                    if (x < 0 || y < 0 || x >= n || y >= n) continue;
                    if (dp[x][y] == -1) continue;

                    if (dp[x][y] > best) {
                        best = dp[x][y];
                        ways = count[x][y];
                    } else if (dp[x][y] == best) {
                        ways = (ways + count[x][y]) % MOD;
                    }
                }

                if (best != -1) {
                    if (board[i][j] != 'E') best += board[i][j] - '0';
                    dp[i][j] = best % MOD;
                    count[i][j] = ways % MOD;
                }
            }
        }

        if (dp[0][0] == -1) return {0,0};
        return {dp[0][0], count[0][0]};
    }
};