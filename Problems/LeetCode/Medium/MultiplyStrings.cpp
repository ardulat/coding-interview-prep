// https://leetcode.com/problems/multiply-strings/

// Approach:
// 1. multiply with the last digit in second string
// 2. add result to the total sum (strings)
// 3. Repeat with preceeding number of the second string
//      - add zeros to the end

class Solution {
public:
    string multiplyUtil(string num1, char num2) {
        int n = num1.size();
        string res = "";
        int carry = 0;
        int i = n-1;
        
        while (i >= 0 || carry != 0) {
            int multiplication = 0;
            if (i >= 0)
                multiplication += (num1[i]-'0') * (num2-'0');
            multiplication += carry;
            
            res = (char) (multiplication % 10 + '0') + res;
            
            carry = multiplication / 10;
            i--;
        }
        
        return res;
    }
    
    string addUtil(string num1, string num2) {
        int size1 = num1.size(), size2 = num2.size();
        int i = size1-1, j = size2-1;
        string res = "";
        int carry = 0;

        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = 0;
            if (i >= 0)
                sum += num1[i];
            if (j >= 0)
                sum += num2[j];
            sum += carry;
            res = (char) (sum % 10) + res;
            carry = sum / 10;
        }
        
        return res;
    }
    
    string multiply(string num1, string num2) {
        
        string res;
        int n = num2.size();
        
        // base case:
        if (num1 == "0" || num2 == "0")
            return "0";
        
        for (int i = n-1; i >= 0; i--) {
            char last_digit = num2[i];
            string multiplication = multiplyUtil(num1, last_digit);
            // step 1: add zeros to the end
            int zeros = n-1-i;
            while (zeros > 0) {
                multiplication += '0';
                zeros--;
            }
            // step 2: add numbers as strings
            res = addUtil(res, multiplication);
        }
        
        return res;
    }
};