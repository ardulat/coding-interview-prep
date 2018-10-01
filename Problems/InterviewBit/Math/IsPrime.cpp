// https://www.interviewbit.com/problems/verify-prime/

int Solution::isPrime(int A) {

    if (A == 1) // 1 is not prime number
        return 0;

    for (int i = 2; i <= sqrt(A); i++) {
        if (A % i == 0)
            return 0;
    }
    
    return 1;
}
