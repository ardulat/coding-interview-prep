// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    /*
    - initially we have N opening, N closing brackets
    - if we have any of them left, put opening front or closing back
    - recur back
    - stop when we have no brackets left (opening and closing)
    */
    void backtrack(vector<string>& result, string comb, int opening, int closing) {
        if (opening == 0 && closing == 0) {
            result.push_back(comb);
            return;
        }
        if (opening > 0)
            backtrack(result, comb+"(", opening-1, closing);
        if (closing > opening)
            backtrack(result, comb+")", opening, closing-1);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", n, n);
        return result;
    }
};