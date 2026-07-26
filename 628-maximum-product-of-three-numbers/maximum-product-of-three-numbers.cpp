class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int max1=nums[n-1]*nums[n-2]*nums[n-3];//all are +ve
        int max2=nums[0]*nums[1]*nums[n-1];//two -ve and one +ve
        return max(max1,max2);
    }
};