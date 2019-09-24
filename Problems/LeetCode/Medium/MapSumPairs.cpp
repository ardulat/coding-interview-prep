// https://leetcode.com/problems/map-sum-pairs/

class MapSum {
private:
    struct TrieNode {
        unordered_map<char,TrieNode*> children;
        bool isWord;
        int count;
    };
    
    TrieNode *root;
    
    void dfs(TrieNode *root, int& sum) {
        if (root->isWord)
            sum += root->count;
        
        for (auto p : root->children)
            dfs(p.second, sum);
    }
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode *temp = root;
        
        for (char ch : key) {
            if (temp->children.find(ch) == temp->children.end())
                temp->children[ch] = new TrieNode();
            
            temp = temp->children[ch];
        }
        
        temp->isWord = true;
        temp->count = val;
    }
    
    int sum(string prefix) {
        TrieNode *temp = root;
        int sum = 0;
        
        for (char ch : prefix) {
            if (temp->children.find(ch) != temp->children.end())
                temp = temp->children[ch];
            else
                return 0;
        }
        
        dfs(temp, sum);
        
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */