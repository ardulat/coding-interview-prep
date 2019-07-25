// https://leetcode.com/problems/valid-mountain-array/

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if (n < 3) return false;
        int i = 0;
        while (i+1 < n && A[i] < A[i+1]) i++;
        if (i == 0 || i == n-1) return false;
        while (i+1 < n && A[i] > A[i+1]) i++;
        if (i+1 != n) return false;
        return true;
    }
};