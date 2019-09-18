// https://app.codesignal.com/interview-practice/task/tXN6wQsTknDT6bNrf

//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool isTreeSymmetric(Tree<int> *left, Tree<int> *right) {
    if (left == NULL && right == NULL)
        return true;
    else if (left == NULL || right == NULL)
        return false;
    
    if (left->value != right->value)
        return false;
    
    return isTreeSymmetric(left->left, right->right) && isTreeSymmetric(left->right, right->left);
}

bool isTreeSymmetric(Tree<int> * t) {
    return isTreeSymmetric(t, t);
}

