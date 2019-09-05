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

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size()-1;
        
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};