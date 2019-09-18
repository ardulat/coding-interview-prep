// https://app.codesignal.com/interview-practice/task/pMvymcahZ8dY4g75q

int firstDuplicate(std::vector<int> a) {
    
    for (int i = 0; i < a.size(); i++) {
        int idx = abs(a[i])-1; // 1
        
        if (a[idx] < 0)
            return abs(a[i]);
        
        a[idx] = -a[idx];
    }
    // [-2, -1, -3, 5, -3, 2]
    
    return -1;
}

