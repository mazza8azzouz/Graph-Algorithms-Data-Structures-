from collections import deque

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

    def bfs(self, start):
        # Perform BFS starting from the node `start`
        visited = set()  # Set to track visited nodes
        queue = deque([start])  # Queue to manage the nodes to visit

        while queue:
            node = queue.popleft()  # Get the node from the front of the queue
            if node not in visited:
                visited.add(node)  # Mark the node as visited
                print(node, end=" ")  # Print the node or store it in a result list
                
                # Add all unvisited neighbors to the queue
                for neighbor in self.graph[node]:
                    if neighbor not in visited:
                        queue.append(neighbor)

# Example usage
if __name__ == "__main__":
    g = Graph()
    
    # Add edges to the graph
    g.add_edge(1, 2)
    g.add_edge(1, 3)
    g.add_edge(2, 4)
    g.add_edge(2, 5)
    g.add_edge(3, 6)
    
    # Perform BFS starting from node 1
    print("BFS Traversal starting from node 1:")
    g.bfs(1)
