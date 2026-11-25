class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;
    static constexpr long long BASE = 100'003;   // > max value (1e5)
    long long pw = 1;                             // BASE^(k-1) % MOD for the current k

    void buildHash(int left, int right, std::vector<int>& nums, int& hash) {
        if (left != -1) {
            // remove left part out of hash
            hash = (hash - nums[left] * pw % MOD + MOD) % MOD;
        }
        // insert the right part of hash
        hash = (1LL * hash * BASE + nums[right]) % MOD;
    }

    bool check(size_t& k, size_t& n, std::vector<int>& nums) {
        pw = 1;
        for (size_t i = 0; i + 1 < k; ++i) pw = pw * BASE % MOD;
        std::unordered_map<int, int> subarrays;
        int hash = 0;
        for (size_t i = 0; i < k - 1; ++i) {
            buildHash(-1, i, nums, hash);
        }
        for (int i = k - 1; i < n; ++i) {
            buildHash(i - k, i, nums, hash);
            ++subarrays[hash];
        }
        for (auto& [_, freq] : subarrays) {
            if (freq == 1) return true;
        }
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        size_t n = nums.size();
        size_t left = 1, right = n;
        while (left <= right) {
            size_t middle = left + ((right - left) >> 1);
            if (check(middle, n, nums)) right = middle - 1;
            else left = middle + 1;
        }
        return left;
    }
};