// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    /*
    Brute-force:
    - reverse each substring in brackets everytime
    - pass the indices (start, end) for reversing
    - find all indices of brackets and put in the stack
    
    Optimization:
    - count the number of brackets before the substring
    - if even, don't reverse
    - if odd, reverse once!
    */
    void reverseSubstring(string& s, int start, int end) {
        int l = start, r = end;
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        // cout << s.substr(l, r-l+1) << endl;
    }
    
    string reverseParentheses(string s) {
        stack<int> st; // opening brackets indices
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                // reverse in this range
                int left = st.top();
                int right = i;
                
                st.pop(); // remove bracket from stack
                
                reverseSubstring(s, left+1, right-1);
            }
                
            i++;
        }
        
        string res = "";
        for (char ch : s)
            if (ch != '(' && ch != ')')
                res += ch;
        
        // cout << res << endl;
        
        return res;
    }
};
// "taawsu"
// "tauswa" - expected