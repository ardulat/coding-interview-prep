// https://leetcode.com/problems/perfect-number/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if (num > 1)
            sum += 1;
        for (int i = 2; i*i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num)
                    sum += num/i;
            }
        }
        return num == 0 ? false : num == sum;
    }
};