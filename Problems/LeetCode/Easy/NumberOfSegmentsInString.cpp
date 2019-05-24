// https://leetcode.com/problems/number-of-segments-in-a-string/

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        bool hasStarted = false;
        for (char ch : s) {
            if (ch != ' ') {
                if (!hasStarted)
                    hasStarted = true;
            } else {
                if (hasStarted) {
                    count++;
                    hasStarted = false;
                }
            }
        }
        if (hasStarted)
            count++;
        return count;
    }
};