// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double pow(double x, int n) {
        if (n == 0)
            return 1.0;
        double temp = pow(x, n/2);
        if (n % 2 == 0)
            return temp*temp;
        else
            return x*temp*temp;
    }
    
    double myPow(double x, int n) {
        double result = pow(x, abs(n));
        
        if (n < 0)
            return 1.0/result;
        
        return result;
    }
};