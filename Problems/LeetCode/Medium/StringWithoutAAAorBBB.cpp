// https://leetcode.com/problems/string-without-aaa-or-bbb/

// Note: very ugly code implementation with shitty workaround
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        int len = A+B;
        string res(len, '_');
        int i = 0;
        // Assuming that A > B
        int cA = A, cB = B; // make copy of original numbers
        if (A < B) swap(A, B); // correct later (swap all 'a' and 'b')
        int atmost = A/B; // put at most 'a'
        if (atmost > 2) atmost = 2;
        if (A == B) atmost = 1;
        while (i < len) {
            for (int c = 0; c < atmost; c++)
                if (A > 0) {
                    res[i] = 'a';
                    A--;
                    i++;
                }
            if (B != 0 && A%B > 0 && atmost != 2 && cA != cB) {
                res[i] = 'a';
                A--;
                i++;
            }
            if (B > 0) {
                res[i] = 'b';
                B--;
                i++;
            }
        }
        cout << res << endl;
        if (cA < cB) {
            for (int c = 0; c < len; c++) {
                if (res[c] == 'a') res[c] = 'b';
                else res[c] = 'a';
            }
        }
        return res;
    }
};