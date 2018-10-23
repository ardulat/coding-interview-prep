// 

// Solution 1
// Note: can't make it faster

bool areAnagrams(string A, string B) {
    
    if (A.size() != B.size())
        return false;
    
    unordered_map<char,int> ht;
    
    for (int i = 0; i < A.size(); i++) {
        if (ht.find(A[i]) != ht.end())
            ht[A[i]]++;
        else
            ht[A[i]] = 1;
    }
    
    for (int i = 0; i < B.size(); i++) {
        if (ht.find(B[i]) != ht.end()) {
            ht[B[i]]--;
            if (ht[B[i]] == 0)
                ht.erase(B[i]);
        }
        else
            return false;
    }
    return true;
}

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> result;
    vector<bool> isGrouped(A.size(), false);
    
    for (int i = 0; i < A.size(); i++) {
        vector<int> group;
        if (!isGrouped[i])
            for (int j = i+1; j < A.size(); j++) {
                if (!isGrouped[j])
                    if (areAnagrams(A[i], A[j])) {
                        if (!isGrouped[i]) {
                            group.push_back(i+1);
                            isGrouped[i] = true;
                        }
                        if (!isGrouped[j]) {
                            group.push_back(j+1);
                            isGrouped[j] = true;
                        }
                    }
            }
        if (!isGrouped[i]) {
            group.push_back(i+1);
        }
        if (!group.empty())
            result.push_back(group);
    }
    return result;
}

// Solution 2
// O(N^2logN)

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> result;
    unordered_map<string, vector<int>> ht;
    
    for (int i = 0; i < A.size(); i++) {
        string temp = A[i];
        sort(temp.begin(), temp.end());
        ht[temp].push_back(i+1);
    }
    
    for (auto& x : ht)
        result.push_back(x.second);
    
    return result;
}
