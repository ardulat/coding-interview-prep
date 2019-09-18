// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        vector<int> level;
        queue<Node*> q, next;
        if (root != NULL)
            q.push(root);
        
        while (!q.empty()) {
            Node *temp = q.front();
            q.pop(); // pops from front
            
            level.push_back(temp->val);
            
            for (Node *child : temp->children)
                if (child != NULL)
                    next.push(child);
            
            if (q.empty()) {
                // swap two queues
                q.swap(next);
                res.push_back(level);
                level = vector<int>(); // empty level
            }
        }
        
        return res;
    }
};