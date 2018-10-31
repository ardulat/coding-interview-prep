// https://www.interviewbit.com/problems/reverse-integer/

int Solution::reverse(int A) {
    int reverse = 0, prev_reverse = 0;
    bool isNegative = false;
    // determine if it is a negative number
    if (A < 0) {
        isNegative = true;
        A *= -1;
    }
    while (A > 0) {
        reverse = reverse * 10 + A % 10;
        // checking overflow
        if (reverse/10 != prev_reverse)
            return 0;
        prev_reverse = reverse;
        A = A / 10;
    }
    // bring sign back
    if (isNegative)
        reverse *= -1;
    
    return reverse;
}
