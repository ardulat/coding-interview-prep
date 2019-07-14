// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long reverse = 0;
        int copy = x;
        while (copy > 0) {
            int last = copy % 10;
            copy = copy / 10;
            reverse = 10*reverse + last;
        }
        return reverse == x;
    }
};