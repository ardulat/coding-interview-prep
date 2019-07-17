// https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ones = 0;
        while (n > 0) {
            if (n&1 == 1)
                ones++;
            n = n >> 1;
        }
        return ones == 1;
    }
};