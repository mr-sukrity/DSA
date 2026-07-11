class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;   // negative numbers are not palindromes
        int original = x;         // save the original number
        int revNum = 0;

        while(x != 0) {
            int digit = x % 10;
            if(revNum<INT_MIN /10 || revNum>INT_MAX /10) return 0;
            revNum = (revNum * 10) + digit;
            x /= 10;
        }

        return revNum == original;
    }
};