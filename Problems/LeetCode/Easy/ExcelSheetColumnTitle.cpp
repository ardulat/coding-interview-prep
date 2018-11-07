// https://leetcode.com/problems/excel-sheet-column-title/

// Intuitive approach:
// 1. if in range [1, 26], add 64 to it (convert to ASCII)
// 2. if not, then: 
//       - divie by 26, store it for later usage
//       - get modulus of 26 to know, which character to put at the end of string
// 3. Repeat until divided (and stored) number / division is not less than 26
// 4. Reverse the string at the end

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

// Interviewbit solution:
string Solution::convertToTitle(int A) {
    string result = "";
    
    while (A > 0) {
        int x = (A-1) % 26;
        result += char(65+x);
        A = (A-1) / 26;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}
