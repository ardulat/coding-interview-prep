// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0, j = n-1;
        while (i <= j) {
            if (nums[i] != val) {
                i++;
            }
            else {
                if (nums[j] != nums[i]) {
                    nums[i] = nums[j];
                    i++;
                    j--;
                } else
                    j--;
            }
        }
        return i;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};