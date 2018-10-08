// https://www.interviewbit.com/problems/generate-all-parentheses/

bool isPair(char a, char b) {
    if (a == '(' && b == ')')
        return true;
    else if (a == '{' && b == '}')
        return true;
    else if (a == '[' && b == ']')
        return true;
    return false;
}

int Solution::isValid(string A) {
    int n = A.size();
    stack<char> s;
    
    for (int i = 0; i < n; i++) {
        if (A[i] == '(' || A[i] == '{' || A[i] == '[')
            s.push(A[i]);
        else if (A[i] == ')' || A[i] == '}' || A[i] == ']') {
            if (s.empty() || !isPair(s.top(), A[i]))
                return 0;
            else
                s.pop();
        }
    }
    
    if (s.empty())
        return 1;
    
    return 0;
}
