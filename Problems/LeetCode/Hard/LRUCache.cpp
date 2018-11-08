// https://leetcode.com/problems/lru-cache/

// Approach:
// 1. Use dequeue (or double linked list) to store all keys
// 2. Use map to store all key, value pairs
// 3. All the most recently used keys will be at front
// 4. All the least recently used keys will be at back

class LRUCache {
public:
    list<int> keyDequeue;
    map<int,int> mp;
    int cache_size;
    
    LRUCache(int capacity) {
        keyDequeue.clear();
        mp.clear();
        cache_size = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) { // key exists
            // update keyDequeue
            keyDequeue.remove(key);
            keyDequeue.push_front(key);
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            if (mp.size() == cache_size) {
                // remove last
                int last = keyDequeue.back();
                keyDequeue.pop_back();
                mp.erase(last);
            }
        }
        else // just update the value
            keyDequeue.remove(key);
        
        keyDequeue.push_front(key);
        mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */