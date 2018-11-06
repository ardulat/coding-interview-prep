// https://leetcode.com/problems/hamming-distance/

// Approach: calculate XOR, count set bits

class Solution {
public:
    int hammingDistance(int x, int y) {
        // calculate XOR
        int op = x^y;
        // count set bits
        int count = 0;
        
        while (op > 0) {
            count += op & 1;
            op = op >> 1;
        }
        
        return count;
    }
};

