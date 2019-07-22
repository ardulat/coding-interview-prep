// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        string res = "";
        while (i < n) {
            string word = "";
            while (i < n && s[i] != ' ') {
                word = s[i] + word;
                i++;
            }
            res += word;
            if (i != n) res += ' ';
            i++; // skip the space
        }
        return res;
    }
};