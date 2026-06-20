class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
         unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string,int> freq;

        //  Normalize paragraph
        for(char &c : paragraph) {
            if(isalpha(c)) {
                c = tolower(c);
            } else {
                c = ' '; // replace punctuation with space
            }
        }

        // Split into words
        stringstream ss(paragraph);
        string word;
        string ans;
        int maxCount = 0;

        while(ss >> word) {
            if(bannedSet.find(word) == bannedSet.end()) {
                freq[word]++;
                if(freq[word] > maxCount) {
                    maxCount = freq[word];
                    ans = word;
                }
            }
        }
        return ans;
    }
};