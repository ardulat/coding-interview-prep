// https://leetcode.com/problems/longest-uncommon-subsequence-ii/

class Solution {
public:
    // is string A subsequence of string B (B is longer than A)
    bool isSubsequence(const string& a, const string& b) {
        if (b.size() < a.size())
            return false;
        int i = 0;
        for (char ch : b)
            if (i < a.size() && a[i] == ch)
                i++;
        return i == a.size();
    }
    
    int findLUSlength(vector<string>& strs) {
        int len = -1;
        for (int i = 0; i < strs.size(); i++) {
            int j = 0;
            for (; j < strs.size(); j++)
                if (i != j && isSubsequence(strs[i], strs[j]))
                    break;
            if (j == strs.size())
                len = max(len, (int)strs[i].size());
        }
        return len;
    }
};