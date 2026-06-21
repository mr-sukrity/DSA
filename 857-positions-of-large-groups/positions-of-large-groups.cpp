class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
      vector<vector<int>> result;
        int n = s.size();
        int i = 0;

        while (i < n) {
            int j = i;
            // Move j forward while characters are the same
            while (j < n && s[j] == s[i]) {
                j++;
            }

            // Length of group = j - i
            if (j - i >= 3) {
                result.push_back({i, j - 1});
            }

            // Move to next group
            i = j;
        }

        return result;  
    }
};