// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
    
    void serializeUtil(TreeNode* root, string &res) {
        if (root != NULL) {
            res += " " + to_string(root->val);
            serializeUtil(root->left, res);
            serializeUtil(root->right, res);
            return;
        }
        res += " #";
    }
    
    TreeNode* deserializeUtil(istringstream &in) {
        string val;
        in >> val;
        // cout << val << endl;
        if (val == "#")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeUtil(in);
        root->right = deserializeUtil(in);
        
        return root;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        serializeUtil(root, res);
        // cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeUtil(in);;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));