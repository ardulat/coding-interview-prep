// https://www.interviewbit.com/problems/magician-and-chocolates/

// Note: do not always use map, use priority_queue

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> pq;
    for (int num : B)
        pq.push(num);
    
    int i = 0;
    long long count = 0;
    while (i < A) {
        int maxBag = pq.top();
        count += (long long) maxBag;
        i++;
        pq.pop();
        int newBag = maxBag/2;
        pq.push(newBag);
    }
    return count % (1000000000+7);
}
