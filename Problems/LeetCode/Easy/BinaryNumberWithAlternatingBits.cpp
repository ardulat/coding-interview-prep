// https://leetcode.com/problems/binary-number-with-alternating-bits/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = n & 1;
        n = n >> 1;
        while (n > 0) {
            if (1 - (n & 1) != last) return false;
            last = n & 1;
            n = n >> 1;
        }
        return true;
    }
};