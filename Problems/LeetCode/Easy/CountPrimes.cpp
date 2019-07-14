// https://leetcode.com/problems/count-primes/

// Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        if (!n) // edge case: n = 0
            return n;
        vector<bool> table(n, true);
        table[0] = false;
        table[1] = false;
        for (int i = 2; i*i < n; i++)
            if (table[i]) {
                for (int j = i; j*i < n; j++) {
                    int num = i*j; // 2x2, 2x3, 2x4, 2x5, ...
                    if (table[num])
                        table[num] = false;
                }
            }
        int count = 0;
        for (bool isPrime : table)
            if (isPrime)
                count++;
        return count;
    }
};