// https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    /*
    Input: "(()())(())"
    Output: "()()()"
    
    decomposition = "(()())" + "(())"
    
    - count opening and closing parentheses
    - when they are equal, remove outer
    - concatenate with resultant string
    */
    string removeOuterParentheses(string S) {
        int i = 0, len = S.length();
        string res = "", temp = "";
        int open = 0, close = 0;
        while (i < len) {
            if (S[i] == '(')
                open++;
            if (S[i] == ')')
                close++;
            
            if (open != 1 && open != close)
                temp += S[i];
            if (open == close) {
                res += temp;
                open = 0;
                close = 0;
                temp = "";
            }
            i++;
        }
        return res;
    }
};