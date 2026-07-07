class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;   // concatenated number
        long long sum = 0; // sum of digits
        long long p = 1;   // place multiplier

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            if (digit != 0) {
                sum += digit;       // add to digit sum
                x += p * digit;     // build concatenated number
                p *= 10;            // move to next place
            }
        }

        return x * sum;
    }
};