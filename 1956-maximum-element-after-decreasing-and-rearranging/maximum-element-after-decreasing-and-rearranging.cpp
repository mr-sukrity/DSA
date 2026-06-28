class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
         sort(arr.begin(), arr.end());

        // The first element must always be 1
        int first = 1;

        for (int i= 1; i<arr.size(); i++) {
            // (we can only decrease, not increase)
            first = min(arr[i], first+ 1);
        }
        return first;
    }
};