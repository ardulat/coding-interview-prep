#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

// construct graph
class Graph {
  unordered_map<char, vector<char>> adj;
  unordered_set<char> nodes;
  
  void topologicalSortUtil(char node, 
                           unordered_map<char, bool> &visited,
                           stack<char> &Stack);
  
public:
  Graph(); // constructor
  
  void addEdge(char first, char second); // adding edge to adj list
  
  void topologicalSort(); // topological sort
};

Graph::Graph() {
  adj.clear();
}

void Graph::addEdge(char first, char second) {
  adj[first].push_back(second);
  nodes.insert(first);
  nodes.insert(second);
}

void Graph::topologicalSortUtil(char node,
                                unordered_map<char, bool> &visited,
                                stack<char> &Stack) {
  // mark the current node as visited
  visited[node] = true;
  vector<char> adjacentNodes = adj[node];
  for (int index = 0; index < (int)adjacentNodes.size(); index++) {
    char currentNode = adjacentNodes[index];
    if (!visited[currentNode])
      topologicalSortUtil(currentNode, visited, Stack);
  }
  
  Stack.push(node);
}

void Graph::topologicalSort() {
  stack<char> Stack;
  unordered_map<char, bool> visited;
  
  // mark all nodes as not visited
  for (char node : nodes)
    visited[node] = false;

  // we will need to copy all elements somewhere, because when we iterate,
  // we access the adjacency list which we are iterating through
  // The problem: do not access, change, or even touch list when
  // iterating through it using iterator
  for (char node : nodes)
    if (!visited[node])
      topologicalSortUtil(node, visited, Stack);
  
  while (!Stack.empty()) {
    cout << Stack.top() << " ";
    Stack.pop();
  }
  cout << endl;
}

// construct a graph, and print alphabet in order
void printOrder(vector<string> dictionary) {
  int n = dictionary.size();
  
  Graph g; // graph with alpha nodes
  
  for (int i = 0; i < n-1; i++) {
    string word1 = dictionary[i], word2 = dictionary[i+1];
    for (int j = 0; j < (int)min(word1.length(), word2.length()); j++) {
      if (word1[j] != word2[j]) {
        g.addEdge(word1[j], word2[j]);
        break;
      }
    }
  }
  
  g.topologicalSort();
}

// To execute C++, please define "int main()"
int main() {
  vector<string> words1 = {"caa", "aaa", "aab"};
  printOrder(words1);
  
  vector<string> words2 = {"wrt", "wrf", "er", "ett", "rftt"};
  printOrder(words2);
  
  vector<string> words3 = {"art", "rat", "cat", "car"};
  printOrder(words3);
  
  vector<string> words4 = {"x", "y", "x"}; // need to return empty string
  printOrder(words4);
  
  return 0;
}

/*

Example dictionary: 
Art
Rat
Cat
Car

Alphabet is: [a, t, r, c] 

*/