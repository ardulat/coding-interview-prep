// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    /*
    Algorithm 1:
    - iterate through each of strings (take shortest as the max length)
    
    Algorithm 2:
    - construct a trie
    */
    string longestCommonPrefix(vector<string>& strs) {
        int ind = 0;
        string lcp = "";
        if (strs.empty())
            return lcp;
        while (ind < strs[0].length()) { // assume first is the shortest
            char ch = strs[0][ind];
            for (string str : strs) {
                if (ind == str.length() || str[ind] != ch)
                    return lcp;
            }
            lcp += ch;
            ind++;
        }
        return lcp;
    }
};