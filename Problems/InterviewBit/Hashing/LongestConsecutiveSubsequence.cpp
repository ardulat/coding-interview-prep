// https://www.interviewbit.com/problems/longest-consecutive-sequence/

int Solution::longestConsecutive(const vector<int> &A) {
    unordered_map<int, bool> hashmap;
    for (int num : A)
        hashmap[num] = true;
        
    int maxLength = 0;
    for (int i = 0; i < A.size(); i++) {
        if (hashmap.find(A[i]-1) == hashmap.end()) {
            int j = A[i];
            while(hashmap.find(j) != hashmap.end())
                j++;
            maxLength = max(maxLength, j-A[i]);
        }
    }
    return maxLength;
}
