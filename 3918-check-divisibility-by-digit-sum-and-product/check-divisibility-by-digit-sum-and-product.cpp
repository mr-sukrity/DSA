class Solution {
public:
    bool checkDivisibility(int n) {
        int ans = 0;
        int sum = 0;
        int product = 1;
        int temp = n;
        while (n > 0) {
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }
        ans = sum + product;
        return (temp % ans == 0);
    }
};