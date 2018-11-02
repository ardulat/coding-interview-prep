// https://www.interviewbit.com/problems/next-pointer-binary-tree/

// Approach: use two queues for current and next levels
// Problem: uses extra space for two queues

void connect(TreeLinkNode* A) {
    if (A == NULL)
        return;
    queue<TreeLinkNode*> currentLevel, nextLevel;
    currentLevel.push(A);
    TreeLinkNode* current;
    while (!currentLevel.empty()) {
        current = currentLevel.front();
        currentLevel.pop();
        
        if (current->left != NULL)
            nextLevel.push(currentLevel->left);
        if (current->right != NULL)
            nextLevel.push(currentLevel->right);
        
        if (!currentLevel.empty())
            current->next = currentLevel.front();
        else
            currentLevel.swap(nextLevel);
    }
}


// Constant space approach: use two loops.
// Outer for each level, inner for nodes at each level

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if (A == NULL)
        return;
    TreeLinkNode* temp = A;
    
    while (temp != NULL) {
        TreeLinkNode* node = temp;
        while (node != NULL) {
            if (node->left != NULL)
                node->left->next = node->right;
            if (node->next != NULL && node->right != NULL)
                node->right->next = node->next->left;
            node = node->next;
        }
        temp = temp->left;
    }
}
