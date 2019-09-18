// https://app.codesignal.com/interview-practice/task/jAKLMWLu8ynBhYsv6/solutions

//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
void preorder(Tree<int> *root, int& k, int& ans) {
    if (root == NULL)
        return;
    
    if (k == 0)
        return;
    
    cout << root->value << endl;
    
    preorder(root->left, k, ans);
    
    k--; // visit root
    if (k == 0)
        ans = root->value;
    
    preorder(root->right, k, ans);
    
}

int kthSmallestInBST(Tree<int> * t, int k) {
    // preorder traversal gives sorted order of BST
    int ans;
    
    preorder(t, k, ans);
    
    return ans;
}

