// https://leetcode.com/problems/reverse-string/submissions/

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int n = s.size();
        for (int i = 0; i < n/2; i++) {
            temp = s[i]; // "h"
            s[i] = s[n-1-i]; // "o"
            s[n-1-i] = temp;
        }
    }
};