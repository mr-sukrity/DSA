class Solution {
public:
    bool checkRecord(string s) {
         int countA = 0;  // count of 'A'
        int countL = 0;  // consecutive 'L'

        for (char c : s) {
            if (c == 'A') {
                countA++;
                if (countA > 1) return false;  // more than 1 'A'
                countL = 0;  // reset consecutive 'L'
            } else if (c == 'L') {
                countL++;
                if (countL > 2) return false;  // more than 2 consecutive 'L'
            } else {
                countL = 0;  // reset consecutive 'L' when 'P'
            }
        }
        return true;
    }
};