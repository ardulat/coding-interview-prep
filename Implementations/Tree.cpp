// This is my implementation of 
// binary search tree based on
// mycodeschool videos

struct Node {
    int data;
    Node* left;
    Node* right;
}

// alternative approach: add initializer to struct
Node* getNewNode(int data) {
    Node* newNode = new Node(); // memory allocation in C++
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// passing pointer to root by reference
void insert(Node** root, int data) {
    if (*root == NULL)
        *root = getNewNode(data);
    else if (data <= (*root)->data)
        insert(&(root->left), data);
    else
        insert(&(root->right), data);
}

bool search(Node* root, int data) {
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (root->data < data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// TO-DO: add delete method,
//        determine height,
//        traversal (in-order, post-order, pre-order)