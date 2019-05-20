// https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

int findMaxDepth(vector<vector<int>>& graph, int root) {
    if (graph[root].empty())
        return 0;
    int depth = 0;
    for (int child : graph[root])
        depth = max(depth, findMaxDepth(graph, child));
    return depth+1;
}

int largestDistance(vector<vector<int>>& graph, int root) {
    // step 2: find max depths
    int maxDepth1 = -1, maxDepth2 = -1;
    for (int child : graph[root]) {
        int depth = findMaxDepth(graph, child);
        if (depth > maxDepth1) {
            maxDepth2 = maxDepth1;
            maxDepth1 = depth;
        } else if (depth > maxDepth2)
            maxDepth2 = depth;
    }
    int left2right = maxDepth1 + maxDepth2 + 2;
    
    // step 3: find largest distance among children
    int largestChild = 0;
    for (int child : graph[root])
        largestChild = max(largestChild, largestDistance(graph, child));
    
    // step 4: compare distances
    return max(left2right, largestChild);
    
}

int Solution::solve(vector<int> &A) {
    // step 1: construct a graph
    vector<vector<int>> graph(A.size(), vector<int>());
    int root;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != -1)
            graph[A[i]].push_back(i); // A[i] - parent, i - child
        else
            root = i; // root node number
    }
    
    return largestDistance(graph, root);
}

/*
- construct a graph from the given vector
- find first maxDepth and second maxDepth among children
- find largest distance among all children
- compare those two and return greater one
*/
