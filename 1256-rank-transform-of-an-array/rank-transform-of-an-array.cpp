class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        //Copy array and sort it to know rank order
        vector<int>s = arr;
        sort(s.begin(), s.end());

        //Map each unique number to its rank
        unordered_map<int, int> rank;
        int currentRank = 1;
        for (int num : s) {
            if (rank.find(num) == rank.end()) {  //it gives...is the number present in the map...if not then its true.
                rank[num] = currentRank++;
            }
        }

        //Replace each element in original array with its rank
        vector<int> result;
        for (int num : arr) {
            result.push_back(rank[num]);
        }

        return result;
    }
};