// https://leetcode.com/problems/power-of-three/

class Solution {
public:
    /*
    1, 3, 9, 27, 81, 243, ...
    */
    bool isPowerOfThree(int n) {
        if (n == 1)
            return true;
        if (n % 3 == 0 && n != 0)
            return isPowerOfThree(n/3);
        return false;
    }
};