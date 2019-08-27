// https://leetcode.com/problems/goat-latin/

class Solution {
public:
    string convertWord(string word, int index) {
        char first = word[0];
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u',
                                    'A', 'E', 'I', 'O', 'U'});
        
        if (vowels.find(first) != vowels.end()) { // first char is vowel
            word += "ma";
        }
        else { // first char is consonant
            word += word[0]; // add first character to the end
            word.erase(word.begin()); // remove first character
            word += "ma";
        }
        
        for (int i = 0; i <= index; i++)
            word += 'a';
        
        return word;
    }
    
    string toGoatLatin(string S) {
        int i = 0;
        int idx = 0; // index of word
        string word = "";
        string res = "";
        
        while (i < S.length()) {
            if (S[i] != ' ')
                word += S[i];
            else {
                res += convertWord(word, idx) + ' ';
                word = ""; // empty the string back
                idx++; // next word
            }
            i++;
        }
        
        if (!word.empty()) {
            res += convertWord(word, idx);
        }
        
        return res;
    }
};