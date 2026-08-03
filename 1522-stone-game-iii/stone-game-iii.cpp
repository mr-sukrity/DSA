class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int takeStone = 0;
            dp[i] = INT_MIN;
            for (int k = 0; k < 3 && i + k < n; k++) {
                takeStone += stoneValue[i + k];
                dp[i] = max(dp[i], takeStone - dp[i + k + 1]);
            }
        }
        if (dp[0] > 0)
            return "Alice";
        if (dp[0] < 0)
            return "Bob";
        else
            return "Tie";
    }
};