class Solution {
public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string word, result;
        int index = 1; // word position counter

        while (ss >> word) {
            // Check if first letter is a vowel
            char first = tolower(word[0]);
            if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') {
                // Vowel case: keep word as is
                word += "ma";
            } else {
                // Consonant case: move first letter to the end
                word = word.substr(1) + word[0] + "ma";
            }

            // Add 'a' repeated index times
            word += string(index, 'a');

            // Append to result
            if (!result.empty()) result += " ";
            result += word;

            index++;
        }

        return result; 
    }
};