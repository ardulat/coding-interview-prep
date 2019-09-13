// https://leetcode.com/problems/validate-ip-address/

class Solution {
public:
    bool isIPv4 (string& IP) {
        string num = "";
        int count = 0;
        
        for (int i = 0; i <= IP.length(); i++) {
            if (i < IP.length() && IP[i] != '.') {
                // contain only digits
                if (IP[i] < '0' || IP[i] > '9')
                    return false;
                
                num += IP[i];
            }
            else {
                if (num.empty() || num.length() > 3)
                    return false;
                
                int number = stoi(num);
                if (number < 0 || number > 255)
                    return false;
                
                // leading zeroes
                if (num[0] == '0') {
                    if (number != 0)
                        return false;
                    else if (num.length() > 1)
                        return false;
                }
                
                count++;
                num = ""; // empty the string
            }
        }
        
        if (count != 4)
            return false; // more than four decimal numbers
        
        return true;
    }
    
    bool isIPv6 (string& IP) {
        unordered_set<char> valid ({'0','1','2','3','4','5','6','7','8','9', 'a','A','b','B','c','C','d','D','e','E','f','F'});
        string num = "";
        int count = 0;
        
        for (int i = 0; i <= IP.length(); i++) {
            if (i < IP.length() && IP[i] != ':') {
                if (valid.find(IP[i]) == valid.end())
                    return false;
                
                num += IP[i];
            } else {
                // more than four digits
                if (num.empty() || num.length() > 4)
                    return false;
                
                // check consecutive colons
                
                count++;
                num = "";
            }
        }
        
        if (count != 8)
            return false; // more than 8 numbers
        
        return true;
    }
    
    string validIPAddress(string IP) {
        if (isIPv4 (IP))
            return "IPv4";
        if (isIPv6 (IP))
            return "IPv6";
        return "Neither";
    }
};