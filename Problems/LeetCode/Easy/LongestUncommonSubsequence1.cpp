// https://leetcode.com/problems/longest-uncommon-subsequence-i/

class Solution {
public:
    /*
    - longest subsequence is derived from not removing characters at all
    - thus, compare whole string in the following way:
    - if both strings are identical, return -1 because there is no uncommon subsequence
    - if not identical but the length is equal, return it
    - if the lengths are different, the bigger string can't be a subsequence of the smaller one, thus return its length
    */
    int findLUSlength(string a, string b) {
        if (a == b)
            return -1;
        if (a.length() == b.length())
            return a.length();
        else
            return max(a.length(),b.length());
    }
};