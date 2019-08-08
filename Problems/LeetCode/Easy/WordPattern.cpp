// https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> let2word;
        unordered_map<string,char> word2let;
        
        int i = 0, j = 0;
        while (i < pattern.length() && j < str.length()) {
            char ch = pattern[i];
            string word = "";
            while (j < str.length() && str[j] != ' ') {
                word += str[j];
                j++;
            }
            
            i++;
            j++;
            
            if (let2word.find(ch) == let2word.end() &&
                word2let.find(word) == word2let.end()) {
                let2word[ch] = word;
                word2let[word] = ch;
            }
            else if (let2word[ch] == word && word2let[word] == ch)
                continue;
            else
                return false;
        }
        
        return i == pattern.length() && j >= str.length();
    }
};