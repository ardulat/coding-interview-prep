// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    - level order traversal
    - at each level, put all children (NULLs too) to stack
    - pop from stack till reach non-NULL node
    - compare the max width so far with stack size
    - update max
    */
    void printDeque(deque<TreeNode*> level) { // left to right order
        cout << "size = " << level.size() << endl;
        while (!level.empty()) {
            TreeNode* temp = level.front();
            level.pop_front();
            if (temp != NULL)
                cout << temp->val << " ";
        }
        cout << endl<<endl;
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        // take care of root == NULL base case
        if (root == NULL)
            return 0;
        deque<TreeNode*> level, nextLevel;
        level.push_back(root);
        int maxWidth = level.size(); // 1
        while (!level.empty()) {
            TreeNode* temp = level.front();
            level.pop_front();
            if (temp != NULL) {
                nextLevel.push_back(temp->left); // even if it is NULL
                nextLevel.push_back(temp->right); // NULLs too
            } else {
                nextLevel.push_back(NULL); // for each NULL
                nextLevel.push_back(NULL); // we have to others
            }
            if (level.empty()) {
                if (!nextLevel.empty())
                    while (nextLevel.front() == NULL && !nextLevel.empty())
                        nextLevel.pop_front();
                if (!nextLevel.empty())
                    while (nextLevel.back() == NULL && !nextLevel.empty())
                        nextLevel.pop_back();
                if (!nextLevel.empty()) {
                    int width = nextLevel.size();
                    maxWidth = max(maxWidth, width);
                    level.swap(nextLevel);
                }
            }
        }
        return maxWidth;
    }
};

