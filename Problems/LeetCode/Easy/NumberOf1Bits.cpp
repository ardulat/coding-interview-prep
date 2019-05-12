// https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1;
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & mask) == mask)
                count++;
            mask = mask << 1;
        }
        
        return count;
    }
};