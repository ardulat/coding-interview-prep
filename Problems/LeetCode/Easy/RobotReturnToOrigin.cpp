// https://leetcode.com/problems/robot-return-to-origin/

class Solution {
public:
    bool judgeCircle(string moves) {
        int left = 0, right = 0;
        int up = 0, down = 0;
        for (char ch : moves) {
            if (ch == 'U')
                up++;
            else if (ch == 'D')
                down++;
            else if (ch == 'R')
                right++;
            else // ch == "L"
                left++;
        }
        
        if (left == right && up == down)
            return true;
        return false;
    }
};