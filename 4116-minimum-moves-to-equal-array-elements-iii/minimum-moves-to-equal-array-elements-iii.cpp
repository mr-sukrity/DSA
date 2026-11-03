class Solution {
public:
    int minMoves(vector<int>& nums) {
       int max=*max_element(nums.begin(),nums.end());
       int sum=0;
       for(int n : nums){
        int diff=max-n;
        sum+=diff;
       } 
       return sum;
    }
};