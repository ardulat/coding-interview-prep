// https://www.interviewbit.com/problems/greatest-common-divisor/

// Brute-force
int Solution::gcd(int A, int B) {
    int gcd = 1;
    int lessNumber;
    // case with zero
    if (A == 0)
        return B;
    if (B == 0)
        return A;
    // find number less than second
    if (A >= B)
        lessNumber = B;
    else
        lessNumber = A;
        
    for (int i = 2; i <= lessNumber; i++) {
        if (A % i == 0 && B % i == 0)
            gcd = i;
    }
        
    return gcd;
}
