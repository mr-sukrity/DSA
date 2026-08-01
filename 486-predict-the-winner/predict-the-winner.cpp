class Solution {
public:
    int helper(vector<int>&nums,int l,int r,vector<vector<int>>&dp){
        if(l==r) return nums[l];
        if(dp[l][r]!=INT_MIN) return dp[l][r];

        int leftChoice=nums[l]-helper(nums,l+1,r,dp);
        int rightChoice=nums[r]-helper(nums,l,r-1,dp);
        return dp[l][r]=max(leftChoice,rightChoice);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        return helper(nums,0,n-1,dp)>=0;
    }
};