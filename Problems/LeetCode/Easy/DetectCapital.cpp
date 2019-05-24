// https://leetcode.com/problems/detect-capital/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCase = 0; // 1,2,3 - according to the description
        for (int i = 0; i < word.length(); i ++) {
            char ch = word[i];
            if ('A' <= ch && ch <= 'Z') { // uppercase
                if (i == 0)
                    capitalCase = 1;
                if (capitalCase != 1)
                    return false;
            } else { // lowercase
                if (i == 0)
                    capitalCase = 2;
                if (i == 1 && capitalCase == 1)
                    capitalCase = 3;
                if (capitalCase != 3 && capitalCase != 2)
                    return false;
            }
        }
        return true;
    }
};