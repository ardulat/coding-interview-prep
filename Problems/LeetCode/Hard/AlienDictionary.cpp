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
  
  bool isCyclicUtil(char node,
                    unordered_map<char, bool> &visited,
                    unordered_map<char, bool> &recStack);
  
  void topologicalSortUtil(char node, 
                           unordered_map<char, bool> &visited,
                           stack<char> &Stack);
  
public:
  Graph(); // constructor
  
  void addEdge(char first, char second); // adding edge to adj list
  
  bool isCyclic(); // detect whether graph is cyclic or not
  
  string topologicalSort(); // topological sort
};

Graph::Graph() {
  adj.clear();
}


void Graph::addEdge(char first, char second) {
  adj[first].push_back(second);
  nodes.insert(first);
  nodes.insert(second);
}

bool Graph::isCyclicUtil(char node,
                         unordered_map<char, bool> &visited,
                         unordered_map<char, bool> &recStack) {
  if(visited[node] == false) 
    { 
        // Mark the current node as visited and part of recursion stack 
        visited[node] = true;
        recStack[node] = true;
  
        // Recur for all the vertices adjacent to this vertex 
        vector<char> adjacentNodes = adj[node];
        for(int i = 0; i < (int) adjacentNodes.size(); i++) {
          char temp = adjacentNodes[i];
          if (!visited[temp] && isCyclicUtil(temp, visited, recStack)) 
              return true; 
          else if (recStack[temp]) 
              return true; 
        } 
  
    } 
    recStack[node] = false;  // remove the vertex from recursion stack 
    return false; 
}

bool Graph::isCyclic() {
  unordered_map<char, bool> visited;
  unordered_map<char, bool> recStack;
  
  // mark all as unvisited
  for (char node : nodes)
    visited[node] = false;
  
  for (char node : nodes)
    if (isCyclicUtil(node, visited, recStack))
      return true;
  
  return false;
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

string Graph::topologicalSort() {
  stack<char> Stack;
  unordered_map<char, bool> visited;
  string result = "";
  
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
    result += Stack.top();
    Stack.pop();
  }
  return result;
}

// construct a graph, and print alphabet in order
string printOrder(vector<string> dictionary) {
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
  if (!g.isCyclic())
    return g.topologicalSort();
  else
    return "";
}

// To execute C++, please define "int main()"
int main() {
  vector<string> words1 = {"caa", "aaa", "aab"};
  cout << printOrder(words1) << endl;
  
  vector<string> words2 = {"wrt", "wrf", "er", "ett", "rftt"};
  cout << printOrder(words2) << endl;
  
  vector<string> words3 = {"art", "rat", "cat", "car"};
  cout << printOrder(words3) << endl;
  
  vector<string> words4 = {"x", "y", "x"}; // need to return empty string
  cout << printOrder(words4) << endl;
  
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