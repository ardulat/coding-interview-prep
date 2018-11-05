// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        // base case:
        if (s.empty())
            return true;
        
        stack<char> st;
        int i = 0;
        
        while (i < s.size()) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else {
                if (st.empty())
                    return false;
                
                char c = st.top();
                st.pop();
                if (s[i] == ')' && c != '(')
                    return false;
                if (s[i] == '}' && c != '{')
                    return false;
                if (s[i] == ']' && c != '[')
                    return false;
            }
            i++;
        }
        
        if (!st.empty())
            return false;
        
        return true;
    }
};