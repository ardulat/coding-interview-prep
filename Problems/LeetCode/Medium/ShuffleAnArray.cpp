// https://leetcode.com/problems/shuffle-an-array/

class Solution {
private:
    vector<int> original;
public:
    Solution(vector<int>& nums) {
        this->original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled = this->original;
        for (int i = 0; i < shuffled.size(); i++) {
            int idx = rand() % shuffled.size();
            swap(shuffled[idx], shuffled[i]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */