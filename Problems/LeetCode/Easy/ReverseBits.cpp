// https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            uint32_t last = n & (uint32_t) 1; // last bit
            res = res << 1; // shift left
            res = res | last; // add it to the end
            n = n >> 1; // shift right
        }
        return res;
    }
};