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

// Optimized solution
class Solution {
public:
    /*
    K = 9
    1 % 9 = 1
    11 % 9 = 1*10+1 % 9 = 2
    111 % 9 = 2*10+1 % 9 = 3
    1111 % 9 = 3*10+1 % 9 = 4
    */
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1;
        int remainder = 0;
        for (int i = 1; i <= K; i++) {
            remainder = (remainder * 10 + 1) % K;
            if (remainder == 0) return i;
        }
        return -1;
    }
};