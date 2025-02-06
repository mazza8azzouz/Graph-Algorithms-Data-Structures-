def bellman_ford(graph, source):
    # Initialisation
    distances = {vertex: float('inf') for vertex in graph}
    distances[source] = 0
    predecessors = {vertex: None for vertex in graph}

    # Relaxation des arêtes |V| - 1 fois
    for _ in range(len(graph) - 1):
        for u in graph:
            for v, weight in graph[u]:
                if distances[u] + weight < distances[v]:
                    distances[v] = distances[u] + weight
                    predecessors[v] = u

    # Détection de cycles de poids négatif
    for u in graph:
        for v, weight in graph[u]:
            if distances[u] + weight < distances[v]:
                raise ValueError("Le graphe contient un cycle de poids négatif")

    return distances, predecessors

# Exemple d'utilisation
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('C', -3), ('D', 2)],
    'C': [('D', 1)],
    'D': [('A', 2)]
}

distances, predecessors = bellman_ford(graph, 'A')
print("Distances:", distances)
print("Prédécesseurs:", predecessors)
