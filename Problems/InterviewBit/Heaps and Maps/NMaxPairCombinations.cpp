// https://www.interviewbit.com/problems/n-max-pair-combinations/

// My solution (Memory Limit Exceeded)

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<int> pq;
    int n = A.size();
    vector<int> result;
    
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            pq.push(A[i]+B[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}


// Solution from https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> result;
    // sort both arrays A and B 
    sort(A.begin(), A.end()); 
    sort(B.begin(), B.end()); 
  
    int N = A.size(); 
  
    // Max heap which contains tuple of the format 
    // (sum, (i, j)) i and j are the indices  
    // of the elements from array A 
    // and array B which make up the sum. 
    priority_queue<pair<int, pair<int, int> > > pq; 
  
    // my_set is used to store the indices of  
    // the  pair(i, j) we use my_set to make sure 
    // the indices doe not repeat inside max heap. 
    set<pair<int, int> > my_set; 
  
    // initialize the heap with the maximum sum 
    // combination ie (A[N - 1] + B[N - 1]) 
    // and also push indices (N - 1, N - 1) along  
    // with sum. 
    pq.push(make_pair(A[N - 1] + B[N - 1], 
                      make_pair(N-1, N-1))); 
  
    my_set.insert(make_pair(N - 1, N - 1)); 
  
    // iterate upto K 
    for (int count=0; count<N; count++) { 
  
        // tuple format (sum, i, j). 
        pair<int, pair<int, int> > temp = pq.top(); 
        pq.pop(); 
  
        // cout << temp.first << endl; 
        result.push_back(temp.first);
  
        int i = temp.second.first; 
        int j = temp.second.second; 
  
        int sum = A[i - 1] + B[j]; 
  
        // insert (A[i - 1] + B[j], (i - 1, j))  
        // into max heap. 
        pair<int, int> temp1 = make_pair(i - 1, j); 
  
        // insert only if the pair (i - 1, j) is  
        // not already present inside the map i.e. 
        // no repeating pair should be present inside  
        // the heap. 
        if (my_set.find(temp1) == my_set.end()) { 
            pq.push(make_pair(sum, temp1)); 
            my_set.insert(temp1); 
        } 
  
        // insert (A[i] + B[j - 1], (i, j - 1))  
        // into max heap. 
        sum = A[i] + B[j - 1]; 
        temp1 = make_pair(i, j - 1); 
  
        // insert only if the pair (i, j - 1) 
        // is not present inside the heap. 
        if (my_set.find(temp1) == my_set.end()) { 
            pq.push(make_pair(sum, temp1)); 
            my_set.insert(temp1); 
        } 
    }
    
    return result;
}
