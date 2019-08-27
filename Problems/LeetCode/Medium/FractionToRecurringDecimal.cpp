// https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    /*
    - is denominator always greater than numerator? -> no, see ex. 2
    - can numbers be negative?
    
    Brute-force:
    - do mathematical division
    - convert to string
    - in case the fractional is repeating, change the string
    
    Optimization:
    - add decimal part first
    - if there is a remainder, initialize a hashtable and start tracking seen
    - if the remainder is repeating, then the fractional part is repeating
    */
    string fractionToDecimal(int numerator, int denominator) {
        // base case
        if (numerator == 0)
            return "0";
        
        string res = "";
        
        if ((numerator < 0) ^ (denominator < 0))
            res += '-';
        
        long num = labs(numerator);
        long den = labs(denominator);
        
        long dec = num / den; // decimal part
        long rem = num % den; // remainder part
        
        res += to_string(dec);
        
        if (rem == 0)
            return res;
    
        res += '.'; // add fractional part
        
        bool repeating = false;
        unordered_map<long,int> seen;
        while (rem > 0 && !repeating) {
            if (seen.find(rem) != seen.end()) {
                repeating = true;
                break;
            }
            
             // otherwise, add to seen
            seen[rem] = res.size(); // the index at which to insert the '('
            
            // update the remainder
            rem = rem * 10;
            long temp = rem / den;
            res += to_string(temp);
            rem = rem % den;
        }
        
        if (repeating) {
            res += ')';
            res.insert(seen[rem], "(");
        }
        
        return res;      
    }
};