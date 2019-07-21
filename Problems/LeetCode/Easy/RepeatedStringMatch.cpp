// https://leetcode.com/problems/repeated-string-match/

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int i = 0, j = 0;
        int n = A.length(), m = B.length();
        int start = 0;
        int count = -1;
        while (i < n) {
            if (A[i] != B[j]) i++;
            else {
                start = i;
                count = 1;
                while (j < m) {
                    if (A[i] != B[j]) {
                        i = start+1;
                        j = 0;
                        break;
                    }
                    i++; j++;
                    if (i == n && j != m) {
                        count++;
                        i = i % n;
                    }
                }
            }
        }
        if (i == n && j != m) return -1;
        
        return count;
    }
};