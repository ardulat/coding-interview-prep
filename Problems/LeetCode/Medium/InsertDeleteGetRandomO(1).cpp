// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
public:
    unordered_map<int,int> hashmap;
    vector<int> nums;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hashmap.find(val) != hashmap.end()) return false;
        hashmap[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hashmap.find(val) == hashmap.end()) return false;
        int idx = hashmap[val];
        // swap idx and last elements
        swap(nums[idx], nums[nums.size()-1]);
        // update index of the last in the map
        hashmap[nums[idx]] = idx;
        nums.pop_back(); // O(1) time
        hashmap.erase(val); // average O(1) time
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */