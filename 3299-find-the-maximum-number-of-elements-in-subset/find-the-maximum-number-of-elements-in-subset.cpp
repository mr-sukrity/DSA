class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        // Count frequency of each number
        for (int x : nums)
            cnt[x]++;

        int ans = 1;

        // Handle number 1 separately
        if (cnt.count(1)) {
            if (cnt[1] % 2 == 0)
                ans = cnt[1] - 1;
            else
                ans = cnt[1];
        }

        // Try every possible starting value
        for (auto &it : cnt) {
            long long x = it.first;

            if (x == 1)
                continue;

            int len = 0; 
             while (cnt.count(x) && cnt[x] >= 2) {
                len += 2;
                x = x * x;
            }

            if (cnt.count(x))
                len += 1;
            else
                len -= 1;

            ans = max(ans, len);
        }

        return ans;
    }
};