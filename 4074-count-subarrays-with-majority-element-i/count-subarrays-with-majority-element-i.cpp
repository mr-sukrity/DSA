class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
         int n = nums.size();
        long long ans = 0;

        // Iterate over all possible starting points
        for (int i = 0; i < n; i++) {
            int countTarget = 0;
            // Extend subarray from i to j
            for (int j = i; j < n; j++) {
                if (nums[j] == target) countTarget++;
                int len = j - i + 1;
                // Check majority condition
                if (countTarget * 2 > len) ans++;
            }
        }
        return ans;
    }
};