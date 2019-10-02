// https://www.interviewbit.com/problems/hotel-reviews/

typedef pair<int,int> pr;

struct comparator {
    bool operator() (const pr left, const pr right) { 
        return left.second > right.second;
    }
};

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord;
    
    TrieNode() : isWord(false) {}
};

void insert(TrieNode *root, string word) {
    for (char ch : word) {
        if (root->children.find(ch) == root->children.end())
            root->children[ch] = new TrieNode();
        
        root = root->children[ch];
    }
    
    root->isWord = true;
}

bool search(TrieNode *root, string word) {
    for (char ch : word) {
        if (root->children.find(ch) == root->children.end())
            return false;
        
        root = root->children[ch];
    }
    
    return root->isWord;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    // step 1: construct trie from good words
    TrieNode *root = new TrieNode();
    string word = "";
    for (int i = 0; i <= A.size(); i++) {
        if (A[i] == '_' || i == A.size()) {
            // cout << word << endl;
            insert(root, word);
            word = "";
        }
        else
            word += A[i];
    }
    // cout << "\n" << endl;
    // step 2: search number of good words in each string
    vector<pr> values;
    for (int j = 0; j < B.size(); j++) {
        int count = 0;
        string str = B[j];
        string word = "";
        for (int i = 0; i <= str.size(); i++) {
            if (str[i] == '_' || i == str.size()) {
                // cout << word << endl;
                count += search(root, word);
                word = "";
            } else
                word += str[i];
        }
        // cout << count << endl;
        values.push_back({j, count});
    }
    
    // step 3: sort good values and construct the result
    stable_sort(values.begin(), values.end(), comparator());
    // for (pr p : values)
    //     cout << "{ " << p.first << ", " << p.second << " }" << endl;
    
    vector<int> res;
    for (pr value : values)
        res.push_back(value.first);
    
    return res;
}
