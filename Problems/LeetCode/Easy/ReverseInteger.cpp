// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        // int count = 0;
        bool isNegative = false;
        if (x < 0) {
            isNegative = true;
            if ((long)-x > INT_MAX)
                return 0;
            x = -x; // negation
        }
        while (x > 0) {
            if ((long)reversed * 10 + x % 10 > INT_MAX
               || -(long)reversed * 10 + x % 10 < INT_MIN)
                return 0;
            reversed = reversed * 10 + x % 10;
            x = x / 10;
        }
        if (isNegative)
            reversed = -reversed;
        return reversed;
    }
};