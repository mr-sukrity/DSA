class Solution {
public:
    int numberOfSubstrings(string s) {
           int ans = 0;
        vector<int> lastSeen(3, -1);

        for (int i = 0; i < s.size(); i++) {
            lastSeen[s[i] - 'a'] = i;
            ans += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
        }
        return ans;
    }
};