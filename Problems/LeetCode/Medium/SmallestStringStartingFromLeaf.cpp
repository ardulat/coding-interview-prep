// https://leetcode.com/problems/smallest-string-starting-from-leaf/

class Solution {
private:
    string smallest;
public:
    void dfs(TreeNode *root, vector<char> path) {
        if (root == NULL)
            return;
        path.push_back(root->val+'a');
        if (root->left == NULL && root->right == NULL) { // leaf node
            // construct a string
            string temp = "";
            for (char c : path)
                temp = c + temp;
            if (smallest.empty() || strcmp(temp.c_str(),smallest.c_str())<0)
                smallest = temp;
            return;
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, vector<char>());
        return smallest;
    }
};

// Optimized algorithm
class Solution {
private:
    string smallest;
public:
    void dfs(TreeNode *root, string temp) {
        if (root == NULL)
            return;
        temp = (char) (root->val+'a') + temp;
        if (root->left == NULL && root->right == NULL) { // leaf node
            if (smallest.empty() || strcmp(temp.c_str(),smallest.c_str())<0)
                smallest = temp;
            return;
        }
        dfs(root->left, temp);
        dfs(root->right, temp);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return smallest;
    }
};