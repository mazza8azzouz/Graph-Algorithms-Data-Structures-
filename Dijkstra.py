def dijkstra(graph, start):
    # Initialisation
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0
    predecessors = {vertex: None for vertex in graph}
    unvisited = set(graph)

    while unvisited:
        # Sélection du sommet avec la distance minimale
        current = min(unvisited, key=lambda vertex: distances[vertex])
        unvisited.remove(current)

        # Mise à jour des distances des voisins
        for neighbor, weight in graph[current].items():
            if neighbor in unvisited:
                new_distance = distances[current] + weight
                if new_distance < distances[neighbor]:
                    distances[neighbor] = new_distance
                    predecessors[neighbor] = current

    return distances, predecessors
