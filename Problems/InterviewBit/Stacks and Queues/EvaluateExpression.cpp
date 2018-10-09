// https://www.interviewbit.com/problems/evaluate-expression/

int Solution::evalRPN(vector<string> &A) {
    int n = A.size();
    stack<int> s;
    
    for (int i = 0; i < n; i++) {
        string ch = A[i];
        
        if (ch == "*" || ch == "/" || ch == "+" || ch == "-") {
            int first = s.top(); s.pop();
            int second = s.top(); s.pop();
            int res;
            if (ch == "*")
                res = first*second;
            else if (ch == "/")
                res = second/first;
            else if (ch == "+")
                res = first+second;
            else if (ch == "-")
                res = second - first;
            s.push(res);
        }
        else {
            int digit = stoi(ch);
            s.push(digit);
        }
    }
    return s.top();
}
