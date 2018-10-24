// https://www.interviewbit.com/problems/longest-substring-without-repeat/

// Note: the problem was in iterating throught unordered_map
// and erasing elements at the same time

int Solution::lengthOfLongestSubstring(string A) {
    int maxLength = 0;
    unordered_map<char, int> ht;
    int start = 0;
    
    
    for (int i = 0; i < A.size(); i ++) {
        if (ht.find(A[i]) == ht.end())
            ht[A[i]] = i;
        else {
            // remove all characters that has values less than ht[A[i]]
            for (auto it = ht.begin(); it != ht.end();) {
                if (it->second < ht[A[i]])
                    it = ht.erase(it);
                else
                    it++;
            }
            start = ht[A[i]]+1;
            ht[A[i]] = i;
        }
        if (i-start+1 > maxLength)
            maxLength = i-start+1;
    }
    return maxLength;
}
