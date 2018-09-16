// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray(const vector<int> &A) {
    // Brute-force solution - O(N^2)
    // However, there is also a divide-and-conquer solution - O(NlogN)
    int maxMaxSum = INT_MIN;
    
    for (int i = 0; i < A.size(); i++) {
        int maxSum = A[i];
        int sum = A[i];
        for (int j = i+1; j < A.size(); j++) {
            sum += A[j];
            if (maxSum < sum)
                maxSum = sum;
        }
        if (maxMaxSum < maxSum)
            maxMaxSum = maxSum;
    }
    
    return maxMaxSum;
}

int Solution::maxSubArray(const vector<int> &A) {
    // Kadane's algorithm - O(N)
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    
    for (int i = 0; i < A.size(); i++) {
        max_ending_here = max_ending_here + A[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    
    return max_so_far;
}
