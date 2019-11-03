#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

#define NODES_SIZE 875715

vector<int> res; // we can change it to heap

void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, stack<int>& st) {
    // mark node as visited
    visited[node] = true;

    // visit all adjacent nodes
    for (int num : graph[node]) {
        if (visited[num] == false)
            dfs(graph, num, visited, st);
    }

    // push node to stack (for finishing time)
    st.push(node);
}

void dfsLoop(vector<vector<int>>& graph, vector<bool> visited,
stack<int>& st) {

    for (int i = 1; i < NODES_SIZE; i++) {
        if (visited[i] == false)
            dfs(graph, i, visited, st);
    }
}

void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, int& count) {
    // mark node as visited
    visited[node] = true;
    count++; // size increases

    // visit adjacent nodes
    for (int num : graph[node]) {
        if (visited[num] == false)
            dfs(graph, num, visited, count);
    }
}

void stronglyConnectedComponents(vector<vector<int>>& graph,
vector<vector<int>>& rev) {
    stack<int> st;
    vector<bool> visited(NODES_SIZE, false); // all initialized as false

    // step 1: run DFS loop on reversed graph
    dfsLoop(rev, visited, st);
    // right result: [1, 2, 4, 3, 0]

    // note: make sure visited list is all false (copied above)

    // step 2: run DFS loop on the stack's node (sorted according to finishing time)
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        // do dfs loop here
        if (visited[node] == false) {
            int count = 0;
            dfs(graph, node, visited, count);
            cout << "leader #" << node << " size " << count << endl;
            res.push_back(count);
        }
    }

}

int main() {

    // read input array from file
    int x;
    ifstream f;
    f.open("SCC.txt");

    if (!f) {
        cout << "Unable to open a file." << endl;
        exit(1);
    }

    vector<vector<int>> graph(NODES_SIZE), rev(NODES_SIZE);
    int src, trg;
    while (f >> src >> trg) {
        graph[src].push_back(trg);
        rev[trg].push_back(src);
    }

    f.close();

    // for (int i = 0; i < NODES_SIZE; i++) {
    //     cout << i << ": ";
    //     for (int adj : rev[i])
    //         cout << adj << ", ";
    //     cout << endl;
    // }

    stronglyConnectedComponents(graph, rev);

    sort(res.begin(), res.end(), greater<int>());
    if (res.size() < 5)
        while (res.size() < 5)
            res.push_back(0);
    
    for (int i = 0; i < 5; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}