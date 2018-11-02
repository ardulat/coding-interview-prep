// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

// Approach: use two stack for current and next levels

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> result;
    vector<int> currentResult;
    stack<TreeNode*> currentLevel, nextLevel;
    TreeNode* current = A;
    TreeNode* temp;
    bool leftToRight = true;
    currentLevel.push(current);
    
    while (!currentLevel.empty()) {
        temp = currentLevel.top();
        currentLevel.pop();
        currentResult.push_back(temp->val);
        if (temp != NULL) {
            if (leftToRight) {
                if (temp->left != NULL)
                    nextLevel.push(temp->left);
                if (temp->right != NULL)
                    nextLevel.push(temp->right);
            }
            else {
                if (temp->right != NULL)
                    nextLevel.push(temp->right);
                if (temp->left != NULL)
                    nextLevel.push(temp->left);
            }
        }
        if (currentLevel.empty()) {
            currentLevel.swap(nextLevel);
            result.push_back(currentResult);
            currentResult.clear();
            leftToRight = !leftToRight;
        }
    }
    
    return result;
}
