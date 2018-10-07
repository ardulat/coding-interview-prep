// https://www.interviewbit.com/problems/length-of-last-word/

int Solution::lengthOfLastWord(const string A) {
    int i = A.length()-1;
    int count = 0;
    
    if (A.length() == 0)
        return 0;
    else {
        while (i >= 0) {
            if (A[i] == ' ') {
                if (count == 0)
                    i--;
                else
                    break;
            }
            else {
                count++;
                i--;
            }
        }
    }
    
    return count;
}
