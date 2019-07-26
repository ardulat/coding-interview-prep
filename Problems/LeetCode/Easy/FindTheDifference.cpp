// https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int total = 0;
        for (char c : s) total ^= c;
        for (char c : t) total ^= c;
        return total;
    }
};