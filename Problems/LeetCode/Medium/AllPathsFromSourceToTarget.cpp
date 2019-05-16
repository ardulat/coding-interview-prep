// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    void dfs(vector<vector<int>>& graph, int s, int t, vector<vector<int>>& res, vector<int>& path) {
        if (s == t) { // there exist a path
            path.push_back(t);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(s); // push the starting node to the path
        for (int x : graph[s]) { // adjacent nodes
            dfs(graph, x, t, res, path);
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int N = graph.size();
        int s = 0, t = N-1;
        vector<vector<int>> res;
        vector<int> path;
        dfs(graph, s, t, res, path);
        return res;
    }
};