// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int second = target-numbers[i];
            int start = i+1, end = n-1;
            // binary search
            while (start <= end) {
                int mid = (start+end)/2;
                if (second == numbers[mid]) {
                    res.push_back(i+1);
                    res.push_back(mid+1);
                    return res;
                }
                if (second < numbers[mid])
                    end = mid-1;
                if (second > numbers[mid])
                    start = mid+1;
            }
        }
        return res;
    }
};