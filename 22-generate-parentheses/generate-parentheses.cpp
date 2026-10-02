class Solution {
public:
    vector<string> generateParenthesis(int n) {
     vector<string> result;
     string current="";
     backtrack(result,current,0,0,n);
     return result;

    }

void backtrack(vector<string>& result,string current,int open,int close,int max){
    if(current.size()==max*2){
        result.push_back(current);
        return;
    }
    if(open<max){
        backtrack(result,current + "(",open+1,close,max);

    }
    if(close<open){
        backtrack(result,current+")",open,close+1,max);
            }
}    
};