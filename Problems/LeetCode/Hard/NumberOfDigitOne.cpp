// https://leetcode.com/problems/number-of-digit-one/

class Solution {
public:
    /*
    10 11 12 13 14 15 16 17 18 19 100
    1 11 21 31 41 51 61 71 81 91
    */
    int countDigitOne(int n) {
        int count = 0;
        for (long i = 1; i <= n; i *= 10) {
            count += n/(10*i)*i;
            count += min( max( n%(10*i)-i+1, (long) 0), i);
        }
        return count;
    }
};