class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         unordered_map<int, int> mp;  // sum -> first index
        mp[0] = -1;  // base case: sum 0 at index -1
        int sum = 0, maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            // convert 0 to -1, keep 1 as +1
            sum += (nums[i] == 1 ? 1 : -1);

            if (mp.find(sum) != mp.end()) {
                // subarray found with equal 0s and 1s
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                // store first occurrence of this sum
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};