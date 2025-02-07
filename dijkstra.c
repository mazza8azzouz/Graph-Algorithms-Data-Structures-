#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define NOMBRES_NOEUDS 10 //  Nombre maximum de nœuds dans le graphe
#define INFINI INT_MAX    // Représente l'infini pour les distances

// Fonction pour trouver le nœud avec la distance minimale parmi les nœuds non encore inclus dans l'arbre du chemin le plus court
int distanceMinimale(int dist[], bool ensembleCourt[]) {
    int min = INFINI, min_index;

    for (int v = 0; v < NOMBRES_NOEUDS; v++)
        if (ensembleCourt[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Fonction pour imprimer le tableau des distances
void imprimerSolution(int dist[]) {
    printf("Nœud \t Distance depuis la source\n");
    for (int i = 0; i < NOMBRES_NOEUDS; i++)
        if (dist[i] == INFINI) {
          printf("%d \t\t Infini\n", i);
        } else {
          printf("%d \t\t %d\n", i, dist[i]);

        }
}


// Fonction qui implémente l'algorithme de Dijkstra pour un graphe représenté par une matrice d'adjacence
void dijkstra(int graphe[NOMBRES_NOEUDS][NOMBRES_NOEUDS], int source) {
    int dist[NOMBRES_NOEUDS]; // Tableau pour stocker la distance la plus courte depuis la source vers chaque nœud
    bool ensembleCourt[NOMBRES_NOEUDS]; // ensembleCourt[i] est vrai si le nœud i est inclus dans l'arbre du chemin le plus court

    // Initialisation de toutes les distances à l'infini et ensembleCourt[] à faux
    for (int i = 0; i < NOMBRES_NOEUDS; i++) {
        dist[i] = INFINI;
        ensembleCourt[i] = false;
    }


    // La distance du nœud source à lui-même est toujours 0
    dist[source] = 0;

    // Trouver le chemin le plus court pour tous les nœuds
    for (int count = 0; count < NOMBRES_NOEUDS - 1; count++) {

        int u = distanceMinimale(dist, ensembleCourt);

        // Marquer le nœud sélectionné comme traité
        ensembleCourt[u] = true;


        for (int v = 0; v < NOMBRES_NOEUDS; v++)

            // Mettre à jour dist[v] seulement si ce n'est pas dans ensembleCourt, il y a un arc de u à v, et le poids total du chemin de la source à v en passant par u est plus petit que la valeur actuelle de dist[v]
            if (!ensembleCourt[v] && graphe[u][v] && dist[u] != INFINI && dist[u] + graphe[u][v] < dist[v])
                dist[v] = dist[u] + graphe[u][v];
    }

    // Imprimer le tableau des distances construites
    imprimerSolution(dist);
}

int main() {

    int graphe[NOMBRES_NOEUDS][NOMBRES_NOEUDS] = {
      {0, 4, 0, 0, 0, 0, 0, 8, 0},
      {4, 0, 8, 0, 0, 0, 0, 11, 0},
      {0, 8, 0, 7, 0, 4, 0, 0, 2},
      {0, 0, 7, 0, 9, 14, 0, 0, 0},
      {0, 0, 0, 9, 0, 10, 0, 0, 0},
      {0, 0, 4, 14, 10, 0, 2, 0, 0},
      {0, 0, 0, 0, 0, 2, 0, 1, 6},
      {8, 11, 0, 0, 0, 0, 1, 0, 7},
      {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graphe, 0);

    return 0;
}
