// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size(), min = INT_MAX;
    vector<int> res;
    stack<int> s, temp;
    
    for (int i = 0; i < n; i++) {
        if (s.empty() || min > A[i])
            res.push_back(-1);
        else {
            temp = s;
            while (!temp.empty()) {
                int top = temp.top();
                if (top < A[i]) {
                    res.push_back(top);
                    break;
                }
                temp.pop();
            }
            if (temp.empty())
                res.push_back(-1);
        }
        s.push(A[i]);
        if (min > A[i])
            min = A[i];
    }
    
    return res;
}
