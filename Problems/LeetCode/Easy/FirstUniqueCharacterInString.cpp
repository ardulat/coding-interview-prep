// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> ht;
        // insert characters of S to ordered hash table (with occurences)
        for (int i = 0; i < s.size(); i++) {
            if (ht.find(s[i]) == ht.end())
                ht[s[i]] = 1;
            else
                ht[s[i]]++;
        }
        // do linear scan of S and find the character in hash table with 1 occurence
        for (int i = 0; i < s.size(); i++) {
            if (ht[s[i]] == 1)
                return i;
        }
        return -1;
    }
};