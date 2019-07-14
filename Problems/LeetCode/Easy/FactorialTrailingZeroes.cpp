// https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    /*
    30: fives = 5,10,15,20,25,30
    */
    int trailingZeroes(int n) {
        int count = 0;
        for (long i = 5; i <= n; i *= 5)
            count += n/i; // number of multiples of i
        return count;
    }
};