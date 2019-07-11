// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = 1;
        int n = digits.size();
        for (int i = n-1; i >= 0; i--) {
            sum += digits[i];
            digits[i] = sum % 10;
            sum = sum / 10;
        }
        if (sum != 0) {
            vector<int> res(1, sum);
            res.insert(res.end(), digits.begin(), digits.end());
            return res;
        }
        return digits;
    }
};