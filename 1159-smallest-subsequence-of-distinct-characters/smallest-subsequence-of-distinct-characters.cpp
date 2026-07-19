class Solution {
public:
    string smallestSubsequence(string s) {
         vector<int> freq(26, 0);     // frequency of characters
        vector<bool> visited(26, false); // track if character is in result

        for (char c : s) {
            freq[c - 'a']++;
        }

        string result = "";
        for (char c : s) {
            freq[c - 'a']--; // one occurrence used

            if (visited[c - 'a']) continue; // skip if already in result

            // maintain lexicographical order
            while (!result.empty() && result.back() > c && freq[result.back() - 'a'] > 0) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            visited[c - 'a'] = true;
        }

        return result;
    }
};