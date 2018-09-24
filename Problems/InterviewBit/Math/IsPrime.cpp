// https://www.interviewbit.com/problems/verify-prime/

int Solution::isPrime(int A) {
    for (int i = 2; i <= sqrt(A); i++) {
        if (A % i == 0)
            return 0;
    }
    
    return 1;
}
