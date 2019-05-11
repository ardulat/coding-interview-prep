// https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> a2b, b2a;
        for (int i = 0; i < s.size(); i++) {
            char first = s[i], second = t[i];
            if (a2b.find(first) == a2b.end())
                a2b[first] = second;
            if (b2a.find(second) == b2a.end())
                b2a[second] = first;
            if (a2b[first] != second || b2a[second] != first)
                return false;
        }
        return true;
    }
};