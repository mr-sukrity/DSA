class Solution {
public:
       string removeOuterParentheses(string s) {
      int len =s.length();
      int cnt=0;
      string ans="";
      for(int i =0;i<len;i++){
        if(s[i]==')') cnt-=1;
        if(cnt !=0) ans+=s[i];
        if(s[i]=='(') cnt+=1;
      }
      return ans;

       }
};   

        // Another Approach
//     string result;
//     int depth = 0;

//     for (char c : s) {
//         if (c == '(') {
//             if (depth > 0) result += c;
//             depth++;
//         } else { // c == ')'
//             depth--;
//             if (depth > 0) result += c;
//         }
//     }

//     return result;
// }

// };