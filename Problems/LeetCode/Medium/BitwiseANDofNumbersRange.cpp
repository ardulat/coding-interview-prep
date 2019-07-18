// https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
public:
    /*
    5 = 0101
    6 = 0110
    7 = 0111
    8 = 1000
    */
    int rangeBitwiseAnd(int m, int n) {
        int res = m;
        if (m == 0 || n / m >= 2)
            return 0;
        for (long i = (long) m+1; i <= n; i++)
            res &= i;
        return res;
    }
};