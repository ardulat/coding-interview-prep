// https://www.interviewbit.com/problems/shortest-unique-prefix/

struct TrieNode {
    unordered_map<char,TrieNode*> children;
    string word;
    int prefixTo;
    
    TrieNode() : prefixTo(0) {}
};

void insert(TrieNode *root, string word) {
    string prefix = "";
    for (char ch : word) {
        prefix += ch;
        
        if (root->children.find(ch) == root->children.end())
            root->children[ch] = new TrieNode();
        
        root = root->children[ch];
        root->word = prefix;
        root->prefixTo++;
    }
}

string findPrefix(TrieNode *root, string word) {
    for (char ch : word) {
        if (root->prefixTo == 1)
            break;
        
        root = root->children[ch];
    }
    
    return root->word;
}

vector<string> Solution::prefix(vector<string> &A) {
    vector<string> res;
    TrieNode *root = new TrieNode();
    
    for (string word : A)
        insert(root, word);
    
    for (string word : A) {
        string prefix = findPrefix(root, word);
        res.push_back(prefix);
    }
    
    return res;
}
