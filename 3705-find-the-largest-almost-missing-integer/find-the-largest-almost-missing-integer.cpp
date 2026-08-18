class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int f[51] = {0};
        for (auto& x : nums)
            f[x]++;

        int result = -1, n = nums.size();
        for (int i = 0; i < n; i++)
            if (k == n || (f[nums[i]]==1 && (k==1||!i||i==n-1)))
                result = max(result, nums[i]);

        return result;
    }
};