class Solution {
public:
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
    int gcdOfOddEvenSums(int n) {
       int oddSum=n*n;
        int evenSum=n*(n+1);
        return gcd(oddSum,evenSum);
    }
};