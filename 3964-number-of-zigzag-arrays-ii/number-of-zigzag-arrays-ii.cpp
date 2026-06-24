class Solution {
public:
    static const int MOD = 1000000007;

    vector<vector<long long>> multiply(vector<vector<long long>>& A,
                                       vector<vector<long long>>& B) {
        int n = A.size();
        vector<vector<long long>> C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<vector<long long>> power(vector<vector<long long>> base,
                                    long long exp) {
        int n = base.size();

        vector<vector<long long>> result(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            result[i][i] = 1;

        while (exp > 0) {
            if (exp & 1)
                result = multiply(result, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return result;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<vector<long long>> Up(m, vector<long long>(m, 0));
        vector<vector<long long>> Down(m, vector<long long>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++)
                Up[i][j] = 1;

            for (int j = i + 1; j < m; j++)
                Down[i][j] = 1;
        }

        vector<vector<long long>> T = multiply(Up, Down);

        long long len = n - 1;

        vector<vector<long long>> M = power(T, len / 2);

        if (len % 2)
            M = multiply(M, Up);

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ans = (ans + M[i][j]) % MOD;
            }
        }

        return (ans * 2) % MOD;
    }
};