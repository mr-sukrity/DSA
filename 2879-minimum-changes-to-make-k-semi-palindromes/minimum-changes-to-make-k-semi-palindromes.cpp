class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;
        vector<vector<int>> divs(n + 1);
        for (int d = 1; d <= n; d++)
            for (int len = 2 * d; len <= n; len += d) divs[len].push_back(d);

        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int best = INF;
                for (int d : divs[len]) {
                    int m = len / d, cnt = 0;
                    for (int r = 0; r < d; r++) {
                        for (int lo = r, hi = r + (m - 1) * d; lo < hi; lo += d, hi -= d) {
                            if (s[i + lo] != s[i + hi]) cnt++;
                        }
                    }
                    best = min(best, cnt);
                }
                cost[i][j] = best;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int c = 1; c <= k; c++) {
            for (int p = 2 * c; p <= n; p++) {
                for (int q = 2 * (c - 1); q <= p - 2; q++) {
                    if (dp[q][c - 1] < INF) {
                        dp[p][c] = min(dp[p][c], dp[q][c - 1] + cost[q][p - 1]);
                    }
                }
            }
        }
        return dp[n][k];
    }
};