class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());   // Sort the array
        arr[0] = 1;                     //First element must be 1
        
        for (int i = 1; i < arr.size(); i++) {
            //Ensure arr[i] is at most arr[i-1] + 1
            arr[i] = min(arr[i], arr[i-1] + 1);
        }
        
        return arr.back(); 
    }
};