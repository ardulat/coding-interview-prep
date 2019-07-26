// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> prev;
        int longest = 0, current = 0;
        int i = 0, start;
        while (i < s.length()) {
            if (!prev[s[i]]) { // new character
                prev[s[i]]++;
                if (!current) start = i;
                current++;
                i++;
            }
            else { // character already exists
                longest = max(longest, current);
                prev[s[start]]--; // remove first character
                current--; // reduce current length by one
                start++; // move start to the next
            }
        }
        return max(longest, current);
    }
};