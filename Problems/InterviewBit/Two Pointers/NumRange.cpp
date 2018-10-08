// https://www.interviewbit.com/problems/numrange/

int Solution::numRange(vector<int> &A, int B, int C) {
    int start = 0, end, count = 0;
    
    while (start < A.size()) {
        if (A[start] <= C) {
            // cout << A[start]<<" <= "<<C << endl;
            if (A[start] >= B) {
                // cout << A[start]<<" >= "<<B << endl;
                count++;
            }
            int sum = A[start];
            end = start+1;
            while (end < A.size()) {
                sum += A[end];
                if (sum > C)
                    break;
                else if (sum <= C && sum >= B) {
                    count++;
                    // cout << A[end] << " ";
                    // cout << B<<" <= "<<sum<<" <= "<<C<< endl;
                }
                end++;
            }
        }
        // cout << endl;
        start++;
    }
    // cout << endl;
    return count;
}
