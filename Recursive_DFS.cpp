#include <iostream>
#include <unordered_map>
#include <list>
#include <unordered_set>

class Graph {
public:
    // A map to represent an adjacency list
    std::unordered_map<int, std::list<int>> adjList;

    // Function to add an edge between two nodes
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // If it's an undirected graph
    }

    // Recursive DFS function
    void dfsRecursive(int node, std::unordered_set<int>& visited) {
        // Mark the node as visited
        visited.insert(node);
        std::cout << node << " ";  // Print the node or store it in a result list

        // Visit all the unvisited neighbors
        for (int neighbor : adjList[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsRecursive(neighbor, visited);  // Recurse for unvisited neighbors
            }
        }
    }

    // Wrapper function for initiating the DFS
    void dfs(int start) {
        std::unordered_set<int> visited;  // Set to track visited nodes
        dfsRecursive(start, visited);     // Start DFS from the `start` node
    }
};

int main() {
    Graph g;

    // Add edges to the graph
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);

    // Perform DFS starting from node 1
    std::cout << "DFS Traversal (Recursive) starting from node 1:" << std::endl;
    g.dfs(1);

    return 0;
}
