// 

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
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> res;
        
        if (start > end) {
            res.push_back(NULL);
            return res;
        }
        
        if (start == end) {
            res.push_back(new TreeNode(start));
            return res;
        }
        
        for (int i = start; i <= end; i++) { // start = 2, end = 3
            vector<TreeNode*> lefts = generateTrees(start, i-1);
            vector<TreeNode*> rights = generateTrees(i+1, end); // 2->3
            
            for (TreeNode *l : lefts)
                for (TreeNode *r : rights) {
                    TreeNode *root = new TreeNode(i); // i-th root
                    root->left = l;
                    root->right = r;

                    res.push_back(root);
                }
        }
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*>();
        
        return generateTrees(1, n);
    }
};