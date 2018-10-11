// https://www.interviewbit.com/problems/modular-expression/

// Fuck the edge cases:
// 1) negative A
// 2) C = 1
// 3) integer overflow

long long mod_helper(long long x, long long m) {
    long long expression = x % m;
    if (expression < 0) {
        // cout << x << " % " << m << " = " << m+x%m << endl;
        return m + expression;
    }
    return expression;
}

int Solution::Mod(int A, int B, int C) {
    if (B == 0)
        return 1 % C;
    else if (B % 2 == 0) { // B is odd
        long long y = Mod(A, B/2, C);
        return mod_helper((y*y), C);
    }
    else {
        return mod_helper((mod_helper(A, C)*Mod(A, B-1, C)), C);
    }
}
