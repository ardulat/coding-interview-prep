// https://leetcode.com/problems/maximum-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
    Algorithm 1: O(NlogN)
    - sort the array in order to retrieve max number in subarray in O(1) time
    - retrieve max element (last in the sorted array)
    - put it as root
    - call the function for the left part of the original array
    - call the function for the right part of the original array
    - put the subtrees in the right order and return the root
    
    Algorithm 2 (brute-force): O(N^2)
    - modification of 1: instead of sorting, find max linearly everytime
    
    Algorithm 3: O(NlogN)
    - modification of 1: copy all the elements to max heap
    */
    
    pair<int,int> indexOfMax(vector<int>& nums, int start, int end) {
        if (start == end)
            return {nums[start], start};
        int maximum = INT_MIN, index = 0;
        for (int i = start; i <= end; i++)
            if (nums[i] > maximum) {
                maximum = nums[i];
                index = i;
            }
        return {maximum,index};
    }
    
    TreeNode* construct(vector<int>& nums, int start, int end) {
        pair<int,int> maxInd = indexOfMax(nums, start, end);
        TreeNode *root = new TreeNode(maxInd.first);
        if (start == end)
            return root;
        TreeNode *left = NULL;
        if (maxInd.second != start)
            left = construct(nums, start, maxInd.second-1);
        TreeNode *right = NULL;
        if (maxInd.second != end)
            right = construct(nums, maxInd.second+1, end);
        root->left = left;
        root->right = right;
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = construct(nums, 0, n-1);
        return root;
    }
};