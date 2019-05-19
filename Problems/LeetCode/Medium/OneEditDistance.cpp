// https://leetcode.com/problems/one-edit-distance/

class Solution {
public:
    /*
        s = detacher
        t = teacher
        False
        
        s = cab
        t = ad
        False
        
        s = acb
        t = ab
        True
        
        s = 1203
        t = 1213
        
        s = ac
        t = a
    */
    bool isOneEditDistance(string s, string t) {
        if (s.length() >= t.length()) {
            int diff = 0, sPtr = 0, tPtr = 0;
            while (sPtr < s.length() && tPtr < t.length()) {
                if (s[sPtr] != t[tPtr]) {
                    diff++;
                    if (s.length() == t.length())
                        tPtr++;
                }
                else
                    tPtr++;
                sPtr++;
            }
            if (s.length()-sPtr+diff == 1)
                return true;
            return false;
        }
        return isOneEditDistance(t,s);
    }
};
