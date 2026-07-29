class Solution {
public:
    const int MAX = 1e6 + 1;

    long long nCk(long long n, long long k) {
        long long res = 1;
        for (int i = 1; i <= min(k, n - k); i++) {
            res = res * (n - i + 1) / i;
            if (res >= MAX) return MAX;
        }
        return res;
    }

    long long countArrangements(vector<int>& count) {
        int total = accumulate(count.begin(), count.end(), 0);
        long long res = 1;
        for (int freq : count) {
            res *= nCk(total, freq);
            if (res >= MAX) return MAX;
            total -= freq;
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string mid = "";
        vector<int> halfCount(26, 0);
        for (int i = 0; i < 26; i++) {
            halfCount[i] = freq[i] / 2;
            if (freq[i] % 2 == 1) mid = string(1, char('a' + i));
        }

        long long totalPerm = countArrangements(halfCount);
        if (k > totalPerm) return "";

        int halfLen = accumulate(halfCount.begin(), halfCount.end(), 0);
        string left = "";
        for (int pos = 0; pos < halfLen; pos++) {
            for (int i = 0; i < 26; i++) {
                if (halfCount[i] == 0) continue;
                halfCount[i]--;
                long long arrangements = countArrangements(halfCount);
                if (arrangements >= k) {
                    left.push_back('a' + i);
                    break;
                } else {
                    k -= arrangements;
                    halfCount[i]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};