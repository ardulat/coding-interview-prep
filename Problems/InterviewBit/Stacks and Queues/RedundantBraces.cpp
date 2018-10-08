// https://www.interviewbit.com/problems/redundant-braces/

// Test-case of the year:
// ((2+3)*(3+4))/6
// Interviewbit bug: expected output does not match the problem
int Solution::braces(string A) {
    int n = A.size();
    stack<int> s;
    
    for (int i = 0; i < n; i++) {
        if (A[i] == ')') {
            char top = s.top();
            bool hasRedundant = true;
            while (top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    hasRedundant = false;
                top = s.top();
                s.pop();
            }
            if (hasRedundant)
                return 1;
        }
        else
            s.push(A[i]);
    }
    return 0;
}
