class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0;i<s.size();i++) {
            if (s[i]== '(' || s[i]== '{' || s[i]== '[') {
                st.push(s[i]);
            } else {
                // If stack is empty, no matching opening bracket
                if (st.size()==0){
                     return false;
                }
                
                // Check if the closing bracket matches the top of stack
                if ((s[i]== ')' && st.top()== '(') ||
                    (s[i]== '}' && st.top()=='{') ||
                    (s[i]== ']' && st.top()=='[')) {
                    st.pop();
                }
                else{
                    return false; //no match 
                }
            }
        }
        // Valid only if no unmatched opening brackets remain
        return st.size()==0;
    }
};