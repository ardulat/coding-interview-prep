// https://www.interviewbit.com/problems/mathbug02/

vector<vector<int> > Solution::squareSum(int A) {
    vector<vector<int> > ans;
    for (int a = 0; a * a < A; a++) {
        for (int b = 0; b * b < A; b++) {
            if (a * a + b * b == A && a <= b) {
                vector<int> newEntry; 
                newEntry.push_back(a);
                newEntry.push_back(b);
                ans.push_back(newEntry);
            }
        }
    }
    return ans;
}
