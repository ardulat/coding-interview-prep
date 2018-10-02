// https://www.interviewbit.com/problems/implement-power-function/

// wrong solution which overfills the long long
// TEST CASE OF THE YEAR:
// 71045970
// 41535484
// 64735492
int Solution::pow(int x, int n, int d) {
    long long power = 1;
    long long copyX = (long long)x;
    while(n > 0) {
        if (n % 2 == 1) {
            power = power * copyX;
        }
        n = n/2;
        copyX = copyX*copyX;
    }
    
    long long result = power%(long long)d;
    if (result < 0)
        result = (long long)d + result;
    
    return result;
}

// Optimized solution: modulus of power of modulus
int Solution::pow(int x, int n, int d) {
    long long power = 1;
    long long copyX = (long long) x;
    
    if (n == 0)
        power = (long long) 1 % (long long) d;
    
    while(n > 0) {
        if (n % 2 == 1) {
            power = (power * copyX) % (long long) d;
            if (power < 0)
                power = (long long) d + power;
        }
        n = n/2;
        copyX = copyX%(long long)d;
        if (copyX < 0)
            copyX = (long long)d+copyX;
        copyX = (copyX*copyX) % (long long)d;
        if (copyX < 0)
            copyX = (long long)d+copyX;
    }
    
    return power;
}

