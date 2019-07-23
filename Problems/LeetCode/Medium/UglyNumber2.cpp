// https://leetcode.com/problems/ugly-number-ii/submissions/

class Solution {
public:
    /*
    ugly numbers = [1,2,3,4,5,6,8,9,10,12,15,...]
    */
    int nthUglyNumber(int n) {
        if (n == 0) return 0;
        vector<int> ugly(n);
        ugly[0] = 1;
        int ptr2 = 0, ptr3 = 0, ptr5 = 0;
        for (int i = 1; i < n; i++) {
            int k = min(ugly[ptr2]*2, min(ugly[ptr3]*3, ugly[ptr5]*5));
            ugly[i] = k;
            if (k == ugly[ptr2]*2) ptr2++;
            if (k == ugly[ptr3]*3) ptr3++;
            if (k == ugly[ptr5]*5) ptr5++;
        }
        return ugly[n-1];
    }
};