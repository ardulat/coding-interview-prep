// https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    /*
    Requirements:
    1. Validate that there is a relation between two nodes (DFS)
    2. If there is, find the relationship through a path
    
    [["x1","x2"],["x2","x3"],["x3","x4"],["x4","x5"]]
    [3.0,4.0,5.0,6.0]
    
    x1->x2: 3
    x2->x1: 0.333333
    x2->x3: 4
    x3->x2: 0.25
    x3->x4: 5
    x4->x3: 0.2
    x4->x5: 6
    x5->x4: 0.166667
    
    [["x1","x5"],["x5","x2"],["x2","x4"],["x2","x2"],["x2","x9"],["x9","x9"]]
    
    [360.0,0.00833,20.0,1.0,-1.0,-1.0]
    
    */
    
    void dfs(unordered_map<string,vector<pair<string,double>>>& graph, unordered_set<string>& visited, string src, string target, double evaluated, double& result) {
        visited.insert(src);
        if (src == target) {
            result = evaluated;
            return;
        }
        for (auto& p : graph[src]) {
            string adj = p.first;
            double weight = p.second;
            if (visited.find(adj) == visited.end()) { // haven't visited yet
                dfs(graph, visited, adj, target, evaluated*weight, result);
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> results;
        unordered_map<string,vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            vector<string> eq = equations[i];
            double val = values[i];
            graph[eq[0]].push_back({eq[1],val}); // add adjacent node
            graph[eq[1]].push_back({eq[0],1/val}); // reverse direction
            // cout << eq[0] << "->" << eq[1]<<": "<<val << endl;
            // cout << eq[1] << "->" << eq[0]<<": "<<1/val << endl;
        }
        
        for (vector<string> query : queries) {
            unordered_set<string> visited;
            string src = query[0];
            string target = query[1];
            double result = -1.0;
            if(graph.find(src)!=graph.end()&&graph.find(target)!=graph.end())
                dfs(graph, visited, src, target, 1.0, result);
            results.push_back(result);
        }
        
        return results;
    }
};