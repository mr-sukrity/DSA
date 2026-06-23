class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD=1e9+7;
        int m = r - l + 1; // total distinct values available
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(m+1, 0)));

    // Initialization: arrays of length 1
    for (int x = 1; x <= m; x++) {
        dp[1][0][x] = 1; // last move was "down"
        dp[1][1][x] = 1; // last move was "up"
    }

    // Build DP
    for (int i = 1; i < n; i++) {
        // prefix sums for optimization
        vector<int> prefix(m+1, 0), suffix(m+2, 0);

        // prefix for "up" direction
        for (int x = 1; x <= m; x++) {
            prefix[x] = (prefix[x-1] + dp[i][1][x]) % MOD;
        }
        // suffix for "down" direction
        for (int x = m; x >= 1; x--) {
            suffix[x] = (suffix[x+1] + dp[i][0][x]) % MOD;
        }

        for (int y = 1; y <= m; y++) {
            // If next must be down, pick x > y
            dp[i+1][1][y] = suffix[y+1];
             // If next must be up, pick x < y
            dp[i+1][0][y] = prefix[y-1];
        }
    }

    // Final answer: sum over all states of length n
    long long ans = 0;
    for (int dir = 0; dir < 2; dir++) {
        for (int x = 1; x <= m; x++) {
            ans = (ans + dp[n][dir][x]) % MOD;
        }
    }
    return ans;
    }
};