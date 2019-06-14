// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    /*
    [1,3,4,2,2]
    start = 1, end = 2
    */
    int findDuplicate(vector<int>& nums) {
        int start = 1, end = nums.size()-1;
        while (start < end) {
            int mid = (start+end)/2;
            int count = 0;
            // count number of elements less or equal to mid
            for (int i = 0; i < nums.size(); i++)
                if (nums[i] <= mid)
                    count++;
            if (count > mid) // the number is in [0, mid]
                end = mid;
            else
                start = mid+1;
        }
        return start;
    }
};

// Floyd's Cycle Detection Algorithm
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0]; // 1
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        int ptr = nums[0];
        while (ptr != slow) {
            ptr = nums[ptr];
            slow = nums[slow];
        }
        
        return ptr;
    }
};