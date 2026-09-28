class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxDepth = 0;
        for (char c : s) {
            if (c == '(') {
                depth++;
                maxDepth = max(maxDepth, depth);
            } else if (c == ')') {
                depth--;
            }
        }
        return maxDepth;

    }
};

//if you see opening  bracket then increase the count and see the closing bracket then decrease the count. 