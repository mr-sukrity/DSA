class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
    int sum = nums[0];
    int i = 1;
    while (i < n && nums[i] == nums[i-1] + 1) {
        sum += nums[i];
        i++;
    }
    unordered_set<int> seen(nums.begin(), nums.end());
    int ans = sum;
    while (seen.count(ans)) ans++;
    return ans;
    }
};