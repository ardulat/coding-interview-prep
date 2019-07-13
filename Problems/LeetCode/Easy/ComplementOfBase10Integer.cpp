// https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0)
            return 1;
        int res = 0;
        int bits = 0;
        while (N > 0) {
            int lsb = N & 1; // least significant bit
            lsb = lsb == 1 ? 0 : 1; // complement
            res = res | (lsb << bits);
            bits++;
            N = N >> 1;
        }
        return res;
    }
};