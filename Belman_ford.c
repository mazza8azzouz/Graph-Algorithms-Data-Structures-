#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NOMBRES_NOEUDS 5 // Nombre de nœuds dans le graphe
#define NOMBRES_ARETES 8 // Nombre d'arêtes dans le graphe

// Structure pour représenter une arête
struct Arete {
    int source, destination, poids;
};

// Fonction pour imprimer le tableau des distances
void imprimerSolution(int dist[]) {
    printf("Nœud \t Distance depuis la source\n");
    for (int i = 0; i < NOMBRES_NOEUDS; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d \t\t Infini\n", i);
        } else {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
}

// Fonction qui implémente l'algorithme de Bellman-Ford
void bellmanFord(struct Arete aretes[], int source) {
    int dist[NOMBRES_NOEUDS];

    // Étape 1: Initialiser les distances depuis la source vers tous les autres nœuds à l'infini
    for (int i = 0; i < NOMBRES_NOEUDS; i++)
        dist[i] = INT_MAX;
    dist[source] = 0;

    // Étape 2: Relâcher les arêtes de manière répétée
    for (int i = 1; i <= NOMBRES_NOEUDS - 1; i++) {
        for (int j = 0; j < NOMBRES_ARETES; j++) {
            int u = aretes[j].source;
            int v = aretes[j].destination;
            int poids = aretes[j].poids;
            if (dist[u] != INT_MAX && dist[u] + poids < dist[v])
                dist[v] = dist[u] + poids;
        }
    }

    // Étape 3: Vérifier les cycles négatifs
    for (int i = 0; i < NOMBRES_ARETES; i++) {
        int u = aretes[i].source;
        int v = aretes[i].destination;
        int poids = aretes[i].poids;
        if (dist[u] != INT_MAX && dist[u] + poids < dist[v]) {
            printf("Le graphe contient un cycle de poids négatif\n");
            return;
        }
    }

    // Imprimer les distances
    imprimerSolution(dist);
}

int main() {
    struct Arete aretes[NOMBRES_ARETES] = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 1, 1}, {4, 3, -3}, {4, 2, 5}
    };

    bellmanFord(aretes, 0);

    return 0;
}
