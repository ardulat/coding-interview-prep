// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    void letterCombinations(string digits, int pos, string comb, unordered_map<char,string>& letters, vector<string>& res) {
        if (pos == digits.size()) {
            res.push_back(comb);
            return;
        }
        for (char c : letters[digits[pos]]) {
            letterCombinations(digits, pos+1, comb+c, letters, res);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> letters({
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        });
        vector<string> res;
        if (digits == "")
            return res;
        letterCombinations(digits, 0, "", letters, res);
        return res;
    }
};