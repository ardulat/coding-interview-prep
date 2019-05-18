// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    /*
    Requirements for the problem:
    1. There has to be no cycle - color the vertices
    2. The order has to be preserved - dfs
    
    1 - WHITE - represents unvisited node
    2 - GRAY - represents visited and not processed node
    3 - BLACK - represents visited and processed node
    */
    
    void visit(vector<vector<int>>& nodes, int node, vector<int>& color, vector<int>& result, bool& isAcyclic) {
        if (!isAcyclic)
            return;
        color[node] = 2;
        for (int adjacent : nodes[node]) {
            if (color[adjacent] == 1) // WHITE
                visit(nodes, adjacent, color, result, isAcyclic);
            else if (color[adjacent] == 2) // GRAY
                isAcyclic = false;
        }
        result.push_back(node);
        color[node] = 3;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> nodes(numCourses, vector<int>()); // graph
        for (vector<int> prereq : prerequisites)
            nodes[prereq[1]].push_back(prereq[0]);
        vector<int> color(numCourses, 1);
        bool isAcyclic = true;
        for (int i = 0; i < nodes.size(); i++) {
            if (color[i] == 1) // WHITE
                visit(nodes, i, color, result, isAcyclic);
        }
        if (!isAcyclic)
            return vector<int>();
        reverse(result.begin(), result.end());
        return result;
    }
};



// Kahn's algorithm
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order; // O(V) space
        vector<vector<int>> nodes(numCourses, vector<int>()); // O(V+E) space
        vector<int> incoming(numCourses, 0); // O(V) space
        queue<int> processing; // O(V) space
        int total = 0;
        
        for (vector<int> prereq : prerequisites) {
            nodes[prereq[1]].push_back(prereq[0]);
            incoming[prereq[0]]++;
            total++;
        }
        
        for (int i = 0; i < numCourses; i++)
            if (incoming[i] == 0)
                processing.push(i);
        
        while (!processing.empty()) {
            int node = processing.front();
            processing.pop();
            order.push_back(node);
            for (int adjacent : nodes[node]) {
                incoming[adjacent]--;
                total--;
                if (incoming[adjacent] == 0)
                    processing.push(adjacent);
            }
        }
        
        if (total != 0) // some edges left - cycle is present
            return vector<int>();
        return order;
    }
};