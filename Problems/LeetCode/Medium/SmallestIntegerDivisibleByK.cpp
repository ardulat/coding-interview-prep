// https://leetcode.com/problems/smallest-integer-divisible-by-k/

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0) return -1;
        unordered_set<int> rem;
        int remainder = 1 % K;
        int count = 1;
        while (remainder != 0) {
            if (rem.find(remainder) != rem.end()) return -1;
            else rem.insert(remainder);
            remainder = (((remainder % K) * (10 % K)) % K + 1) % K;
            count++;
        }
        return count;
    }
};