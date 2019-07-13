// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hashtable;
        for (int num : nums1)
            hashtable[num]++;
        vector<int> res;
        for (int num : nums2)
            if (hashtable[num] > 0) {
                res.push_back(num);
                hashtable[num]--;
            }
        return res;
    }
};