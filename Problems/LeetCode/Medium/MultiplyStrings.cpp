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
        string res (n, 'x');
        
        int carry = 0;
        for (int i = n-1; i >= 0; i--) {
            int digit1 = num1[i]-'0';
            int digit2 = num2-'0';
            int multiplication = digit1*digit2 + carry;
            carry = multiplication / 10;
            res[i] = (multiplication % 10) + '0';
        }
        
        if (carry > 0) {
            string new_res (n+1, 'x');
            new_res[0] = carry + '0';
            for (int i = 0; i < n; i++)
                new_res[i+1] = res[i];
            return new_res;
        }
        
        return res;
    }
    
    string addUtil(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        int size = max(n, m);
        string res (size, 'x');
        
        int i = n-1, j = m-1;
        int k = size-1;
        int carry = 0;
        while (i > -1 && j > -1) {
            int digit1 = num1[i]-'0';
            int digit2 = num2[j]-'0';
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            res[k] = (sum % 10) + '0';
            i--;
            j--;
            k--;
        }
        
        while (i > -1) {
            int digit1 = num1[i]-'0';
            int sum = digit1 + carry;
            carry = sum / 10;
            res[k] = (sum % 10) + '0';
            i--;
            k--;
        }
        while (j > -1) {
            int digit2 = num2[j]-'0';
            int sum = digit2 + carry;
            carry = sum / 10;
            res[k] = (sum % 10) + '0';
            j--;
            k--;
        }
        
        if (carry > 0) {
            string new_res (size+1, 'x');
            new_res[0] = carry + '0';
            // copy rest of the result
            int i = 0;
            while (i < size) {
                new_res[i+1] = res[i];
                i++;
            }
            return new_res;
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