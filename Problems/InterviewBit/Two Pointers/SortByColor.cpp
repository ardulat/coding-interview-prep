// https://www.interviewbit.com/problems/sort-by-color/

// TEST CASE:
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
// 136 2 0 0 1 0 0 2 2 1 1 0 0 1 0 2 1 1 0 1 0 1 2 2 2 0 0 1 0 2 1 1 2 1 2 2 1 0 2 2 1 1 1 0 1 0 1 0 2 1 2 0 2 0 1 1 0 2 2 1 2 0 2 1 1 1 2 0 1 0 2 2 1 0 0 1 0 1 0 0 0 1 2 1 1 0 2 1 2 0 0 0 2 2 2 2 0 0 0 1 1 0 2 1 2 2 2 1 2 2 0 1 0 1 2 1 1 0 1 2 0 1 0 2 2 1 2 1 0 2 2 1 1 0 2 1 2
void Solution::sortColors(vector<int> &A) {
    int cur = 0, i = 1, color = 0;
    
    while(cur < A.size()) {
        if (A[cur] == color) {
            cur++; i = cur+1;
        } else {
            if (A[i] == color) {
                swap(A[i], A[cur]);
                cur++;
            }
            i++;
            if (i >= A.size()) {
                i = cur+1; color++;
            }
        }
        // cout << "i: " << i << ", cur: " << cur << endl;
        // cout << "A: [ ";
        // for (int j = 0; j < A.size(); j++)
        //     cout << A[j] << " ";
        // cout << "]" << endl;
    }
}
