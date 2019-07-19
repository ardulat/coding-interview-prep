// https://leetcode.com/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        int times = 0;
        int bracket;
        string res = "", cur, number = "";
        while (i < s.size()) {
            if (s[i] > '0' && s[i] <= '9') {
                while (s[i] != '[') {
                    number += s[i];
                    i++;
                }
                times = stoi(number);
                cur = "";
                i++;
                bracket = 1;
                while (i < s.size()) {
                    if (s[i] == '[')
                        bracket++;
                    if (s[i] == ']')
                        bracket--;
                    if (bracket == 0)
                        break;
                    cur += s[i];
                    i++;
                }
                cur = decodeString(cur);
                for (int i = 0; i < times; i++)
                    res += cur;
                number = "";
            }
            else
                res += s[i];
            i++;
        }
        return res;
    }
};