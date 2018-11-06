// https://leetcode.com/problems/implement-strstr

class Solution {
public:
    int strStr(string haystack, string needle) {
        // base case:
        if (needle.empty())
            return 0;
        if (needle.size() > haystack.size())
            return -1;
        
        int i = 0, j = 0, start = -1, potential_start = -1;
        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                // set for the first time only
                if (start == -1) start = i;
                
                if  (j == needle.size()-1)
                    return start;
                
                j++;
            }
            else {
                // if we started comparing
                if (start != -1) {
                    // restart
                    i = start;
                    start = -1;
                    j = 0;
                }
            }
            i++;
        }
        
        if (j != needle.size())
            return -1;
        
        return start;
    }
};