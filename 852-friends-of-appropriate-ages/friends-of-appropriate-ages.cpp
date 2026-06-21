class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
         int count = 0;
        int n = ages.size();

        sort(ages.begin(), ages.end());

        for (int i = 0; i < n; i++) {
            int low = upper_bound(ages.begin(), ages.end(),
                                  0.5 * ages[i] + 7) - ages.begin();

            int high = upper_bound(ages.begin(), ages.end(),
                                   ages[i]) - ages.begin();

            count += max(0, high - low - 1);
        }

        return count;
    }
};