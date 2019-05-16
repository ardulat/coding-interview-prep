// https://www.lintcode.com/problem/route-between-two-nodes-in-graph/description

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t) {
        queue<DirectedGraphNode*> qs; // O(V) space
        unordered_map<DirectedGraphNode*, bool> visited; // O(V) space
        // set all nodes to not visited
        for (DirectedGraphNode* x : graph) // O(V) time
            visited[x] = false;
        // run bfs from each of the nodes
        qs.push(s);
        while (!qs.empty()) {
            DirectedGraphNode* temp = qs.front();
            qs.pop();
            if (temp == t)
                return true;
            visited[temp] = true;
            // add neighbors to queue
            if (!(temp->neighbors).empty())
                for (DirectedGraphNode* x : temp->neighbors)
                    if (visited[x] == false) // add it to the queue only if not visited yet
                        qs.push(x);
        }
        return false;
    }
};