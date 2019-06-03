// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    typedef pair<int,int> pi;
    
    struct CustomCompare {
        bool operator()(const pi& lhs, const pi& rhs) {
            return lhs.second < rhs.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ht;
        for (int num : nums)
            ht[num]++;
        vector<int> res(k, 0); // vector of size k with all elements set to 0 
        priority_queue<pi, vector<pi>, CustomCompare> hp;
        for (auto p : ht)
            hp.push(p);
        int i = 0;
        
        while (!hp.empty() && i < k) {
            pi p = hp.top();
            hp.pop();
            res[i] = p.first;
            i++;
        }
        
        return res;
    }
};