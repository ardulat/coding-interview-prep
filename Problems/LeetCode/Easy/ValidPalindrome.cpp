// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        // base case:
        if (s.empty())
            return true;
        
        // remove trash:
        string s1;
        for (char x : s)
            if ((65 <= x && x <= 90)
                || (97 <= x && x <= 122
                || (48 <= x && x <= 57)))
                s1.push_back(tolower(x));
        
        int n = s1.size();
        string reverse = s1; // copy
        for (int i = 0; i < n; i++)
            reverse[n-1-i] = s1[i];
        
        // traverse them and check if equal
        for (int i = 0; i < n; i++)
            if (s1[i] != ' ' && reverse[i] != ' ')
                if (s1[i] != reverse[i])
                    return false;
        
        return true;
    }
};