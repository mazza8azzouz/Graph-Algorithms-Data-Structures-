#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
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

    // Function to perform BFS starting from the node `start`
    void bfs(int start) {
        std::unordered_set<int> visited;  // Set to track visited nodes
        std::queue<int> q;  // Queue to manage the nodes to visit

        // Start BFS from the `start` node
        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int node = q.front();  // Get the node at the front of the queue
            q.pop();
            std::cout << node << " ";  // Print the node or store it in a result list

            // Visit all the unvisited neighbors
            for (int neighbor : adjList[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);  // Mark neighbor as visited
                    q.push(neighbor);  // Add neighbor to the queue
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

    // Perform BFS starting from node 1
    std::cout << "BFS Traversal starting from node 1:" << std::endl;
    g.bfs(1);

    return 0;
}
