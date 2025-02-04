# DFS implementation using an adjacency list

class Graph:
    def __init__(self):
        # Initialize an empty graph
        self.graph = {}

    def add_edge(self, u, v):
        # Add an edge between u and v
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph:
            self.graph[v] = []
        self.graph[u].append(v)
        self.graph[v].append(u)  # If it's an undirected graph

    def dfs(self, start):
        # Perform DFS starting from the node `start`
        visited = set()  # Set to track visited nodes

        def dfs_recursive(node):
            # Mark the node as visited
            visited.add(node)
            print(node, end=" ")  # Print the node or store it in a result list

            # Visit all the adjacent nodes (neighbors)
            for neighbor in self.graph[node]:
                if neighbor not in visited:
                    dfs_recursive(neighbor)

        # Start DFS traversal
        dfs_recursive(start)

# Example usage
if __name__ == "__main__":
    g = Graph()
    
    # Add edges to the graph
    g.add_edge(1, 2)
    g.add_edge(1, 3)
    g.add_edge(2, 4)
    g.add_edge(2, 5)
    g.add_edge(3, 6)
    
    # Perform DFS starting from node 1
    print("DFS Traversal starting from node 1:")
    g.dfs(1)
