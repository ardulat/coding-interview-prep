// https://www.interviewbit.com/problems/reverse-string/

string Solution::reverseString(string A) {
    int n = A.length();
    stack<char> s;
    
    for (int i = 0; i < n; i++)
        s.push(A[i]);
        
    for (int i = 0; i < n; i++) {
        A[i] = s.top();
        s.pop();
    }    
    return A;
}
