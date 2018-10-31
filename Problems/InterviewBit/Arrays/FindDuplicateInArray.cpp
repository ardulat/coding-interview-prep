// https://www.interviewbit.com/problems/find-duplicate-in-array/

// Floyd's cycle finding

int Solution::repeatedNumber(const vector<int> &A) {
    
    int slow = A[0], fast = A[A[0]];
    
    while (slow != fast) {
        slow = A[slow];
        fast = A[A[fast]];
    }
    fast = 0;
    while (slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }
    
    return slow;
}
