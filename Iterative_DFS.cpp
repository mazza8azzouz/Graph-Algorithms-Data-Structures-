#include <iostream>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <stack>

class Graph {
public:
    // A map to represent an adjacency list
    std::unordered_map<int, std::list<int>> adjList;

    // Function to add an edge between two nodes
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // If it's an undirected graph
    }

    // Iterative DFS function
    void dfsIterative(int start) {
        std::unordered_set<int> visited;  // Set to track visited nodes
        std::stack<int> stack;            // Stack to manage the nodes to visit

        // Start DFS from the `start` node
        stack.push(start);

        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();

            if (visited.find(node) == visited.end()) {
                visited.insert(node);  // Mark the node as visited
                std::cout << node << " ";  // Print the node or store it in a result list

                // Push all unvisited neighbors to the stack
                for (int neighbor : adjList[node]) {
                    if (visited.find(neighbor) == visited.end()) {
                        stack.push(neighbor);  // Add neighbor to the stack
                    }
                }
            }
        }
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
    std::cout << "DFS Traversal (Iterative) starting from node 1:" << std::endl;
    g.dfsIterative(1);

    return 0;
}
