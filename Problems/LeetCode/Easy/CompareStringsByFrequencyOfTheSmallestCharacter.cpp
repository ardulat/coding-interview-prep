// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

class Solution {
public:
    int f (string str) {
        unordered_map<char,int> hashmap;
        
        for (char ch : str)
            hashmap[ch]++;
        
        char smallest = 'z'+1; // max possible value
        int res = 0;
        
        for (auto pr : hashmap)
            if (pr.first < smallest) {
                smallest = pr.first;
                res = pr.second;
            }
        
        return res;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        // construct array of ints for queries and words
        int n = queries.size();
        int m = words.size();
        
        vector<int> q (n, 0), w (m, 0);
        
        for (int i = 0; i < n; i++)
            q[i] = f (queries[i]);
        
        for (int i = 0; i < m; i++)
            w[i] = f (words[i]);
        
//         for (int num : q)
//             cout << num << " ";
//         cout << endl;
        
//         for (int num : w)
//             cout << num << " ";
//         cout << endl;
        
        // iterate over two arrays to construct result
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            int count = 0;
            
            for (int j = 0; j < m; j++) {
                if (q[i] < w[j])
                    count++;
            }
            
            res[i] = count;
        }
        
        return res;
    }
};

/*
Brute-force implementation:
- start by implementing f function:
    - use hashmap to iterate over string and find all frequencies - O(N)
    - iterate over hashmap and find the smallest character (ASCII value) and return its frequencies - O(26)

- find all f's for each query and each word in words array - O(N+M)
- iterate over two of them in O(N^2) to find how many words are greater

queries = [3, 2], words = [1, 2, 3, 4]
*/