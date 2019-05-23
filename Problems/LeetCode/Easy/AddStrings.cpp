// https://leetcode.com/problems/add-strings/

class Solution {
public:
    pair<char,char> addChars(char num1, char num2, char prevCarry) {
        char carry, sum;
        int intSum = num1-'0'+num2-'0'+prevCarry-'0';
        sum = intSum%10 + '0';
        carry = intSum/10 + '0';
        return {carry,sum};
    }
    
    string addStrings(string num1, string num2) {
        int ptr1 = num1.size()-1, ptr2 = num2.size()-1;
        string res = "";
        char carry = '0';
        while (ptr1 > -1 && ptr2 > -1) {
            pair<char,char> p = addChars(num1[ptr1], num2[ptr2], carry);
            carry = p.first;
            res = p.second + res;
            ptr1--;
            ptr2--;
        }
        
        while (ptr1 > -1) {
            pair<char,char> p = addChars(num1[ptr1], '0', carry);
            carry = p.first;
            res = p.second + res;
            ptr1--;
        }
        
        while (ptr2 > -1) {
            pair<char,char> p = addChars(num2[ptr2], '0', carry);
            carry = p.first;
            res = p.second + res;
            ptr2--;
        }
        
        if (carry != '0')
            res = carry + res;
        
        return res;
    }
};