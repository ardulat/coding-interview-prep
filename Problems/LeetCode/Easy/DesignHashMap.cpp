// https://leetcode.com/problems/design-hashmap/

class MyHashMap {
private:
    vector<int> buckets;
    int buckets_size;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        buckets = vector<int>(100000, -1);
        buckets_size = buckets.size();
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash = key % buckets_size;
        buckets[hash] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash = key % buckets_size;
        return buckets[hash];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hash = key % buckets_size;
        if (buckets[hash] != -1)
            buckets[hash] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */