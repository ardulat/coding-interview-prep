// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> ht;
        // add all characters of S to hash table (with counts of occurences)
        for (int i = 0; i < s.size(); i++) {
            if (ht.find(s[i]) == ht.end())
                ht[s[i]] = 1;
            else
                ht[s[i]]++;
        }
        // check whether each character of T is present in hash table
        for (int i = 0; i < t.size(); i++) {
            if (ht.find(t[i]) == ht.end() || ht[t[i]] == 0)
                return false;
            else
                ht[t[i]]--; // reduce the count if present
        }
        // check if there is anything left in the hast table
        for (auto& it : ht) {
            if (it.second > 0)
                return false;
        }
        return true;
    }
};