// https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    bool divides(string str, string x) {
        int strLen = str.length(), xLen = x.length();
        if (strLen % xLen != 0)
            return false;
        int repeat = strLen/xLen;
        string repeated = "";
        for (int i = 0; i < repeat; i++)
            repeated += x;
        if (str != repeated)
            return false;
        return true;
    }
    
    string gcdOfStrings(string str1, string str2) {
        string prefix = "";
        int index = 0, len1 = str1.length(), len2 = str2.length(), large = 0;
        while (index < len1 && index < len2 && str1[index] == str2[index]) {
            prefix += str1[index];
            bool flag = true;
            if (!divides(str1, prefix))
                flag = false;
            if (!divides(str2, prefix) && flag)
                flag = false;
            if (flag)
                large = index+1;
            index++;
        }
        return str1.substr(0, large);
    }
};