class Solution {
public:
    int stoneGameII(vector<int>& piles) {
       int n=piles.size();
        vector<int> suffixSum(n + 1, 0);
       for(int i=n-1;i>=0;i--){
        suffixSum[i]=suffixSum[i+1]+piles[i];
       }
       vector<vector<int>>dp(n,vector<int>(n+1,-1));
       function<int(int,int)>dfs=[&](int i,int M){
        if(i>=n) return 0;
        if(2*M >=n-i) return suffixSum[i];
        if(dp[i][M]!=-1) return dp[i][M];

        int best =0;
        for(int x=1;x<=2*M;x++){
            best=max(best,suffixSum[i]-dfs(i+x,max(M,x)));
        }

       return dp[i][M]=best;
       }; 
        return dfs(0,1);
    }
};