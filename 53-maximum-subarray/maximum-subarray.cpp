class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum =0;
        int maxSum=INT_MIN;

        for(int val : nums){
            currentSum+=val;
            maxSum=max(currentSum,maxSum);
            if(currentSum<0)
            currentSum=0;
        }
        return maxSum;

    }
};
//this algorithm is called kadane's algorithm