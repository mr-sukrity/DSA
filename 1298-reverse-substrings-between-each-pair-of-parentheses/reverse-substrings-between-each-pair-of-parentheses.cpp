class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        stack<int> st;
        vector<int> pairOf(n);

        // Find the matching parenthesis for every '(' and ')'
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                st.push(i);

            else if(s[i] == ')')
            {
                int j = st.top();
                st.pop();

                pairOf[i] = j;
                pairOf[j] = i;
            }
        }

        string res = "";

        // dir controls the traversal direction:
        // dir = 1  -> move right
        // dir = -1 -> move left
        for(int i = 0, dir = 1; i < n; i += dir)
        {
            if(s[i] == '(' || s[i] == ')')
            {
                // Jump to the matching parenthesis
                i = pairOf[i];

                // Reverse the traversal direction
                dir = -dir;
            }
            else
            {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};