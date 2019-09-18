// https://app.codesignal.com/interview-practice/task/TG4tEMPnAc3PnzRCs

//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool hasPathWithGivenSum(Tree<int> * t, int s) {
    if (t == NULL)
        return false;
    
    s = s - t->value;
    
    if (s == 0 && t->right == NULL && t->left == NULL) // leaf 
        return true;
    
    return hasPathWithGivenSum(t->left, s) || hasPathWithGivenSum(t->right, s);
}

