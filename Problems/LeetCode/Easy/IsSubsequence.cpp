// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr = 0;
        
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == s[ptr])
                ptr++;
            if (ptr == s.length())
                break;
        }
        
        return ptr == s.length();
    }
};