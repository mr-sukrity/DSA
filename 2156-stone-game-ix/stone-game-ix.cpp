class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int a = 0;
        int b = 0;
        int c = 0;

        for (int i : stones) {
            if (i % 3 == 0) {
                a++;
            }
            else if (i % 3 == 1) {
                b++;
            }
            else {
                c++;
            }
        }

        if (a % 2 == 0) {
            return b > 0 && c > 0;  //means Alice wins .....if not then bob will win
        }

        return abs(b - c) > 2;   //alice wins....otherwise bob
    }
};

            //              START
            //                |
            //                v
            //      Count cnt0, cnt1, cnt2
            //                |
            //                v
            //         Is cnt0 even?
            //          /          \
            //        YES           NO
            //         |             |
            //         v             v
            //  cnt1 > 0 &&     abs(cnt1-cnt2)
            //     cnt2 > 0          > 2
            //     /    \           /    \
            //   YES    NO        YES    NO
            //    |      |         |      |
            //    v      v         v      v
            //  Alice   Bob      Alice   Bob
            //   Wins   Wins      Wins   Wins