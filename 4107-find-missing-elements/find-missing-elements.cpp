class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        unordered_set<int> numSet(nums.begin(), nums.end());

        vector<int> missing;
        for (int i = minVal; i <= maxVal; i++) {
            if (numSet.find(i) == numSet.end()) {
                missing.push_back(i);
            }
        }

        return missing;

    }
};