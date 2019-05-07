// https://leetcode.com/problems/climbing-stairs/

// Algorithm 1: lightweight solution using O(1) memory
class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, cur = 2;
        if (n == 1)
            return prev;
        if (n == 2)
            return cur;
        int i = 3;
        while (i <= n) {
            int temp = prev + cur;
            prev = cur;
            cur = temp;
            i++;
        }
        return cur;
    }
};