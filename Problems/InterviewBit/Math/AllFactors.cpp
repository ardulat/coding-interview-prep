// https://www.interviewbit.com/problems/all-factors/

vector<int> Solution::allFactors(int A) {
    vector<int> factors;
    
    for (int i = 1; i < sqrt(A); i++) {
        if (A % i == 0) {
            factors.push_back(i);
        }
    }
    for (int i = sqrt(A); i > 0; i--) {
        if (A % i == 0) {
            factors.push_back(A/i);
        }
    }
    
    return factors;
}
