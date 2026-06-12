class Solution {
public:
    string reverseStr(string s, int k) {
         int n = s.size();
        
        // Step through the string in blocks of 2k
        for (int i = 0; i < n; i += 2 * k) {
            // Reverse the first k characters of this block
            int end = min(i + k, n);  // make sure we don't go past the string
            reverse(s.begin() + i, s.begin() + end);
        }
        
        return s;
    }
};