class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0)
            return 0;

        vector<int> dp(n,
                       0); // dp[i] stores longest valid substring ending at i
        int maxLen = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                //"()" pattern
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                //  "))" pattern, check if there's a matching '(' before
                // the valid substring
                else if (i - dp[i - 1] - 1 >= 0 &&
                         s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (i - dp[i - 1] - 2 >= 0) {
                        dp[i] += dp[i - dp[i - 1] - 2];
                    }
                }
                maxLen = max(maxLen, dp[i]);
            }
        }

        return maxLen;
    }
};
