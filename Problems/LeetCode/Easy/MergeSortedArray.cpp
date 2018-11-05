// https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1_copy = nums1;
        int i = 0, j = 0, k = 0;
        
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                nums1_copy[k] = nums1[i];
                i++;
            }
            else {
                nums1_copy[k] = nums2[j];
                j++;
            }
            k++;
        }
        
        while (i < m) {
            nums1_copy[k] = nums1[i];
            i++; k++;
        }
        
        while (j < n) {
            nums1_copy[k] = nums2[j];
            j++; k++;
        }
        
        nums1 = nums1_copy;
    }
};