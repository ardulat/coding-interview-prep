// https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> letters;
        for (char ch : magazine) {
            if (letters.find(ch) == letters.end())
                letters[ch] = 1;
            else
                letters[ch]++;
        }
        for (char ch : ransomNote) {
            if (letters.find(ch) == letters.end() || letters[ch] < 1)
                return false;
            letters[ch]--;
        }
        return true;
    }
};