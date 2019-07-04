// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    - solve using recursion every time passing the subarray to construct the tree form the given vector
    - middle element will be the root of the tree
    - the left of the mid element will be the left child
    - similarly, the right of the mid element will be the right child
    */
    TreeNode* constructBST(vector<int>& nums, int start, int end) {
        if (start > end)
            return NULL;
        int mid = (start+end+1)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        if (start == end)
            return root;
        TreeNode *left = constructBST(nums, start, mid-1);
        TreeNode *right = constructBST(nums, mid+1, end);
        root->left = left;
        root->right = right;
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums, 0, nums.size()-1);
    }
};