// https://www.interviewbit.com/problems/lru-cache/

#include<list>

// global vars
list<int> dq;
unordered_map<int, list<int>::iterator> mp;
int cache_size;

LRUCache::LRUCache(int capacity) {
    dq.clear();
    mp.clear();
    cache_size = capacity;
}

int LRUCache::get(int key) {
    if (mp.find(key) != mp.end()) {
        dq.remove(key);
        dq.push_front(key);
        return *mp[key];
    }
    return -1;
}

void LRUCache::set(int key, int value) {
    // if not present in cache
    if (mp.find(key) == mp.end()) {
        // if cache is full
        if (mp.size() == cache_size) {
            int last = dq.back();
            dq.pop_back();
            mp.erase(last);
        }
    }
    else {
        dq.remove(key);
    }
    dq.push_front(key);
    mp[key] = value;
}
