class Solution {
public:
    int minimumPushes(string word) {
      vector<int>count(26,0);
      for(char c : word){
        count[c-'a']++;
      }
         sort(count.begin(),count.end(),greater<int>());
         int ans=0;
         for(int i=0;i<26;i++){
            if(count[i]==0) break;
            ans+=count[i]*(i/8+1);
      }
      return ans;

    }
};