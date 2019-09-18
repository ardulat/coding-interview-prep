// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
typedef pair<char,int> pr;
    
private:
    struct frequency {
        bool operator() (const pr& a, const pr& b) {
            return a.second < b.second;
        }
    };
    
public:
    string frequencySort(string s) {
        // step 1: construct hashmap of occurences
        unordered_map<char,int> hm;
        for (char ch : s)
            hm[ch]++;
        
        // step 2: constuct max-heap of pairs sorted by frequency
        priority_queue<pr, vector<pr>, frequency> heap;
        for (auto& p : hm)
            heap.push(p);
        
        // step 3: construct string sorted by frequency
        string res = "";
        
        while (!heap.empty()) {
            pr p = heap.top();
            char ch = p.first;
            int freq = p.second;
            
            for (int i = 0; i < freq; i++)
                res += ch;
            
            heap.pop();
        }
        
        return res;
    }
};