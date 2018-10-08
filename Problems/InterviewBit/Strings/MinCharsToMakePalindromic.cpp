// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

bool isPalindrome(string word) {
    int n = word.length();
    int mid = n/2;
    int i = 0;
    
    while (i<mid) {
        if (word[i] != word[n-i-1])
            return false;
        i++;
    }
    return true;
}

int Solution::solve(string A) {
    int n = A.length();
    int count = 0, i = 0;
    string prefix = "";
    
    while (i<n) {
        if (isPalindrome(prefix+A))
            break;
        prefix += A[n-i-1];
        count++; i++;
    }
    
    return count;
}
