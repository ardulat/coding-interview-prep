// https://leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
    char to_ascii(int num) {
        return (char) (num + '@');
    }
    
    string convertToTitle(int n) {
        string res = "";
        
        while (n > 26) {
            int r = n % 26;
            if (r == 0)
                r = 26;
            res += to_ascii(r);
            n = (n - r) / 26;
        }
        
        res += to_ascii(n);
        reverse(res.begin(), res.end());
        
        return res;
    }
};