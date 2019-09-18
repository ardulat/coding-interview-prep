// https://app.codesignal.com/interview-practice/topics/trees-basic

//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool areIdentical(Tree<int> *t1, Tree<int> *t2) {
    if (t1 == NULL && t2 == NULL)
        return true;
    else if (t1 == NULL || t2 == NULL)
        return false;
    
    return t1->value == t2->value && 
        areIdentical(t1->left, t2->left) &&
        areIdentical(t1->right, t2->right);
}

bool isSubtree(Tree<int> * t1, Tree<int> * t2) {
    if (t2 == NULL)
        return true;
    
    if (t1 == NULL)
        return false;
    
    if (areIdentical(t1, t2))
        return true;
    
    return isSubtree(t1->left, t2) || isSubtree(t1->right, t2);
}

