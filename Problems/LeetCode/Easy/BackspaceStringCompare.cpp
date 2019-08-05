// https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length()-1, j = T.length()-1;
        int countS = 0, countT = 0;
        while (i >= 0 || j >= 0) {
            
            while (i >= 0) {
                if (S[i] == '#') {
                    i--;
                    countS++;
                }
                else if (countS > 0) {
                    countS--;
                    i--;
                }
                else
                    break;
            }
            
            while (j >= 0) {
                if (T[j] == '#') {
                    j--;
                    countT++;
                }
                else if (T[j] != '#' && countT > 0) {
                    countT--;
                    j--;
                }
                else
                    break;
            }
            
            if (i >= 0 && j >= 0) {
                cout << S[i] << " and " << T[j] << endl;
                if (S[i] != T[j])
                    return false;
            }
            else if (i < 0 && j < 0)
                continue;
            else
                return false;
            i--;
            j--;
        }
        
        return true;
    }
};