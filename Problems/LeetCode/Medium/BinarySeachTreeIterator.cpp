// https://leetcode.com/problems/binary-search-tree-iterator/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> Stack;
    
    void pushAll(TreeNode *root) {
        TreeNode* temp = root;
        while (temp != NULL) {
            Stack.push(temp);
            temp = temp->left;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !Stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = Stack.top();
        Stack.pop();
        pushAll(top->right);
        return top->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */