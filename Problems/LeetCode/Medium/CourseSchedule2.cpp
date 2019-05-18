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