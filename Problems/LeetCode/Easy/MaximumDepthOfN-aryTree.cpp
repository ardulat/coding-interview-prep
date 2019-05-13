// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL)
            return 0;
        int maxD = 1;
        vector<Node*> children = root->children;
        for (int i = 0; i < children.size(); i++) {
            int depth = maxDepth(children[i])+1;
            maxD = max(depth, maxD);
        }
        return maxD;
    }
};