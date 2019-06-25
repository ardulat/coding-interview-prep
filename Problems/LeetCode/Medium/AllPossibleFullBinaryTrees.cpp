// https://leetcode.com/problems/all-possible-full-binary-trees/

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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if (N % 2 == 0)
            return res;
        if (N == 1)
            res.push_back(new TreeNode(0));
        else
            for (int x = 1; x < N; x += 2) {
                int y = N-1-x;
                for (TreeNode *left : allPossibleFBT(x))
                    for (TreeNode *right : allPossibleFBT(y)) {
                        TreeNode *temp = new TreeNode(0);
                        temp->left = left;
                        temp->right = right;
                        res.push_back(temp);
                    }
            }

        return res;
    }
};