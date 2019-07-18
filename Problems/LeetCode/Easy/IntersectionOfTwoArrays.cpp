// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> first, second;
        for (int num : nums1)
            first.insert(num);
        for (int num : nums2)
            second.insert(num);
        vector<int> res;
        for (int num : first)
            if (second.find(num) != second.end())
                res.push_back(num);
        return res;
    }
};