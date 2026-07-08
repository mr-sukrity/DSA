class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
         static const long long MOD = 1'000'000'007LL;
        const int n = (int)s.size();
        const char* str = s.data();

        // Powers of 10 mod p, up to n.
        vector<int> tenPow(n + 1);
        tenPow[0] = 1;
        for (int i = 1; i <= n; ++i) {
            tenPow[i] = (int)((long long)tenPow[i - 1] * 10 % MOD);
        }

        // Combined prefix pass: non-zero count, digit sum, and concatenated value (mod p).
        vector<int> cnt(n + 1);
        vector<int> dsum(n + 1);
        vector<int> val(n + 1);
        cnt[0] = dsum[0] = val[0] = 0;

        for (int i = 0; i < n; ++i) {
            int d = str[i] - '0';
            dsum[i + 1] = dsum[i] + d;
            if (d) {
                cnt[i + 1] = cnt[i] + 1;
                val[i + 1] = (int)(((long long)val[i] * 10 + d) % MOD);
            } else {
                cnt[i + 1] = cnt[i];
                val[i + 1] = val[i];
            }
        }

        int q = (int)queries.size();
        vector<int> result(q);

        for (int i = 0; i < q; ++i) {
            const int l = queries[i][0];
            const int r = queries[i][1];

            const int shift = cnt[r + 1] - cnt[l];
            const int digitSum = dsum[r + 1] - dsum[l];   // always < MOD, no mod needed

            long long x = val[r + 1] - (long long)val[l] * tenPow[shift] % MOD;
            x %= MOD;
            if (x < 0) x += MOD;

            result[i] = (int)(x * digitSum % MOD);
        }

        return result;
    }
};