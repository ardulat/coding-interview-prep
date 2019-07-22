// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
    void sumRootToLeaf(TreeNode *root, vector<int> path, int& sum) {
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            // e.g. leaf node
            int num = path[0];
            for (int i = 1; i < path.size(); i++) {
                num = num << 1;
                num = num | path[i];
            }
            sum += num;
        }
        if (root->left != NULL) sumRootToLeaf(root->left, path, sum);
        if (root->right != NULL) sumRootToLeaf(root->right, path, sum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        if (root != NULL) sumRootToLeaf(root, vector<int>(), sum);
        return sum;
    }
};