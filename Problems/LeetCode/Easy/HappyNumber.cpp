// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1) {
            int happy = 0;
            while (n > 0) {
                happy += (n%10)*(n%10);
                n = n/10;
            }
            if (seen.find(happy) != seen.end()) return false;
            seen.insert(happy);
            // cout << happy << endl;
            n = happy;
        }
        
        return true;
    }
};