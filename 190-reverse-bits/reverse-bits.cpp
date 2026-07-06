class Solution {
public:
    int reverseBits(int n) {
         int result=0;
         for(int i=0;i<32;i++){
            result<<=1;
            result |=(n&1);
            n>>=1;
         }
         return result;
    }
};

// Convert decimal to binary (stored as a number with digits 0/1)
        // long long bnum = 0;
        // long long pow = 1;
        // int temp = n;

        // while (temp > 0) {
        //     int remainder = temp % 2;
        //     temp /= 2;
        //     bnum += remainder * pow;
        //     pow *= 10;
        // }

        // // One's complement (flip all bits)
        // bnum = ~bnum;

        // // Add 1 to get two's complement
        // bnum = bnum + 1;

        // return (int)bnum;
        // thid code shows runtime error