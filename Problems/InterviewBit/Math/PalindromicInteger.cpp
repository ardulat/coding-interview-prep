// https://www.interviewbit.com/problems/palindrome-integer/

int Solution::isPalindrome(int A) {
    int divisor = 1;
    
    // base case with negative numbers
    if (A < 0)
        return 0;
    
    while (A / divisor >= 10)
        divisor = divisor * 10;
        
    while (A > 0) {
        // get first and last digits
        int first = A / divisor;
        int last = A % 10;
        // compare, return false if not equal
        if (first != last)
            return 0;
        A = (A%divisor)/10;
        divisor = divisor / 100;
    }
    
    return 1;    
}
