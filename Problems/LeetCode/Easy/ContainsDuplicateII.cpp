// https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsDuplicate(unordered_set<int> nums);
    
    void printHashset(unordered_set<int> nums) {
        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        // base fucking case:
        if (nums.empty())
            return false;
        unordered_set<int> window; // is always of size k+1
        // initial setting of window by adding k numbers
        for (int i = 0; i <= k; i ++) {
            // trivial edge case:
            if (i >= n)
                break;
            if (window.find(nums[i]) == window.end())
                window.insert(nums[i]);
            else
                return true;
        }
        // slide and check if the window has duplicates
        for (int i = 0; i < n-(k+1); i ++) {
            window.erase(nums[i]); // removes the leftmost element
            if (window.find(nums[i+k+1]) == window.end())
                window.insert(nums[i+k+1]); // inserts the rightmost element
            else
                return true;
        }
        return false;
    }
};