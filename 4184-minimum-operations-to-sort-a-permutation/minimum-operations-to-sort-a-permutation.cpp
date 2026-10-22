class Solution {
public:
    int solve(vector<int>& nums) {
        vector<int> v = nums;

        for (int i : nums) {
            v.push_back(i);
        }

        int count = 1;
        int n = nums.size();

        // First increasing

        for (int i = 1; i < v.size(); i++) {

            if (v[i] < v[i - 1]) {
                count = 1;
            } else {
                count++;

                if (count == n) {
                    return (i + 1) - n;
                }
            }
        }

        // Decreasing Case
        count = 1;
        for (int i = 1; i < v.size(); i++) {

            if (v[i] > v[i - 1]) {
                count = 1;
            } else {
                count++;

                if (count == n) {
                    return i + 2 - n;
                }
            }
        }

        return 1e9;
    }
    int minOperations(vector<int>& nums) {

        if (nums.size() == 1) {
            return 0;
        }
        int ans = solve(nums);

        reverse(nums.begin(), nums.end());

        ans = min(ans, solve(nums) + 1);

        return ans == 1e9 ? -1 : ans;
    }
};