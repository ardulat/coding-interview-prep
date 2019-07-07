// https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (char ch : address) {
            if (ch != '.')
                res += ch;
            else
                res += "[.]";
        }
        return res;
    }
};