// https://leetcode.com/problems/design-hashset/

class MyHashSet {
private:
    vector<bool> buckets;
    int bucket_size;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        buckets = vector<bool>(100000, false);
        bucket_size = buckets.size();
    }
    
    void add(int key) {
        int hash = key % bucket_size;
        if (buckets[hash])
            cout << "collision" << endl;
        buckets[hash] = true;
    }
    
    void remove(int key) {
        if (!contains(key))
            return;
        
        int hash = key % bucket_size;
        buckets[hash] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash = key % bucket_size;
        if (buckets[hash])
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */