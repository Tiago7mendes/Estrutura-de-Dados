#include <stdio.h>
#define MAX_VERTICES 100

typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Grafo;

// Inicializa o grafo
void inicializarGrafo(Grafo* g, int numVertices) {
    g->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

// Adiciona uma aresta entre dois vértices
void adicionarAresta(Grafo* g, int v1, int v2) {
    if (v1 >= 0 && v1 < g->numVertices && v2 >= 0 && v2 < g->numVertices) {
        g->adj[v1][v2] = 1;
        g->adj[v2][v1] = 1;  // Não direcionado
    }
}

// Remove uma aresta entre dois vértices
void removerAresta(Grafo* g, int v1, int v2) {
    if (v1 >= 0 && v1 < g->numVertices && v2 >= 0 && v2 < g->numVertices) {
        g->adj[v1][v2] = 0;
        g->adj[v2][v1] = 0;
    }
}

// Verifica se há uma aresta entre dois vértices
int temAresta(Grafo* g, int v1, int v2) {
    if (v1 >= 0 && v1 < g->numVertices && v2 >= 0 && v2 < g->numVertices) {
        return g->adj[v1][v2] == 1;
    }
    return 0;
}

// Mostra os vizinhos de um vértice
void mostrarVizinhos(Grafo* g, int v) {
    if (v >= 0 && v < g->numVertices) {
        printf("Vizinhos do vértice %d: ", v);
        for (int i = 0; i < g->numVertices; i++) {
            if (g->adj[v][i] == 1) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}

int main() {
    Grafo g;
    inicializarGrafo(&g, 5); // Criar grafo com 5 vértices

    // Adicionar arestas
    adicionarAresta(&g, 0, 1);
    adicionarAresta(&g, 0, 2);
    adicionarAresta(&g, 1, 3);
    adicionarAresta(&g, 3, 4);

    // Mostrar vizinhos
    for (int i = 0; i < g.numVertices; i++) {
        mostrarVizinhos(&g, i);
    }

    // Testar se tem aresta entre 0 e 1
    printf("Tem aresta entre 0 e 1? %s\n", temAresta(&g, 0, 1) ? "Sim" : "Não");

    // Remover aresta entre 0 e 1
    removerAresta(&g, 0, 1);
    printf("Após remover aresta entre 0 e 1...\n");

    // Mostrar vizinhos novamente
    for (int i = 0; i < g.numVertices; i++) {
        mostrarVizinhos(&g, i);
    }

    // Testar novamente se tem aresta entre 0 e 1
    printf("Tem aresta entre 0 e 1? %s\n", temAresta(&g, 0, 1) ? "Sim" : "Não");

    return 0;
}
