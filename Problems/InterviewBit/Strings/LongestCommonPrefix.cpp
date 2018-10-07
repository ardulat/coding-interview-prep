// https://www.interviewbit.com/problems/longest-common-prefix/

string Solution::longestCommonPrefix(vector<string> &A) {
    string prefix = A[0];
    
    for (int i = 0; i < A.size(); i++) {
        int j = 0;
        string newprefix = "";
        
        while (j < A[i].length() && j < prefix.length()) {
            if (A[i][j] == prefix[j]) {
                newprefix += prefix[j];
                j++;
            }
            else
                break;
        }
        
        prefix = newprefix;
    }
    
    return prefix;
}
