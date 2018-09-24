// https://www.interviewbit.com/problems/prime-numbers/

vector<int> Solution::sieve(int A) {
    vector<int> primes(A+1, 1);
    primes[0] = 0;
    primes[1] = 0;
    
    for (int i = 2; i <= sqrt(A); i++)
        if (primes[i] == 1)
            for (int j = 2; i*j <= A; j++)
                primes[i*j] = 0;
    
    vector<int> prime_numbers;
    for (int i = 0; i < primes.size(); i++)
        if (primes[i] == 1)
            prime_numbers.push_back(i);
            
    return prime_numbers;
}
