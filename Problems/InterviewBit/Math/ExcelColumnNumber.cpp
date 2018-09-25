// https://www.interviewbit.com/problems/excel-column-number/

int Solution::titleToNumber(string A) {
    
    int n = A.length();
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        int ch = int (A[i]);
        ch = ch-64;
        result += pow(26, n-i-1)*ch;
    }
    
    return result;
}
