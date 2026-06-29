class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
         int ans = 0;
        for (string p : patterns) {
            // Check if p is a substring of word
            if (word.find(p) != string::npos) {
                ans++;
            }
        }
        return ans;
    }
};