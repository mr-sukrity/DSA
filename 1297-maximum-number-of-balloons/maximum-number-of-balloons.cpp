class Solution {
public:
    int maxNumberOfBalloons(string text) {
   // Count frequency of each character
    unordered_map<char, int> freq;
    for(char c : text) {
        freq[c]++;
    }

    // Balloon requires: b=1, a=1, l=2, o=2, n=1
    int countB = freq['b'];
    int countA = freq['a'];
    int countL = freq['l'] / 2;  // divide by 2
    int countO = freq['o'] / 2;  // divide by 2
    int countN = freq['n'];

    // Minimum among all requirements
    return min({countB, countA, countL, countO, countN});

    }
};