#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX 501
#define INF INT_MAX

typedef struct {
    int destino;
    int peso;
} Aresta;

typedef struct Node {
    int destino;
    int peso;
    struct Node* prox;
} Node;

Node* grafo[MAX];         // Grafo original
Node* reverso[MAX];       // Grafo reverso para backtracking
int dist[MAX];            // Distância mínima de S até cada nó
int visitado[MAX];        // Visitado no Dijkstra
int S, D, N, M;           // Origem, destino, número de nós e arestas

int caminho_minimo[MAX][MAX]; // Marcar arestas que pertencem a qualquer caminho mínimo

// -------- Funções auxiliares --------

void adicionar_aresta(Node** lista, int u, int v, int peso) {
    Node* novo = malloc(sizeof(Node));
    novo->destino = v;
    novo->peso = peso;
    novo->prox = lista[u];
    lista[u] = novo;
}

void inicializar() {
    for (int i = 0; i < N; i++) {
        grafo[i] = NULL;
        reverso[i] = NULL;
        dist[i] = INF;
        visitado[i] = 0;
        for (int j = 0; j < N; j++) {
            caminho_minimo[i][j] = 0;
        }
    }
}

// -------- Dijkstra --------

void dijkstra(int origem) {
    dist[origem] = 0;

    for (int i = 0; i < N; i++) {
        int u = -1;
        int menor = INF;

        for (int j = 0; j < N; j++) {
            if (!visitado[j] && dist[j] < menor) {
                menor = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visitado[u] = 1;

        Node* atual = grafo[u];
        while (atual) {
            int v = atual->destino;
            int peso = atual->peso;

            if (!caminho_minimo[u][v] && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
            }

            atual = atual->prox;
        }
    }
}

// -------- Backtrack para encontrar caminhos mínimos --------

void backtrack(int u) {
    if (u == S) return;

    Node* atual = reverso[u];
    while (atual) {
        int v = atual->destino;
        int peso = atual->peso;

        if (dist[v] + peso == dist[u]) {
            caminho_minimo[v][u] = 1;
            backtrack(v);
        }

        atual = atual->prox;
    }
}

// -------- Encontrar quase menor caminho --------

int encontrar_quase_menor_caminho() {
    // Reset e novo Dijkstra ignorando as arestas dos caminhos mínimos
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }

    dijkstra(S);
    return dist[D] != INF ? dist[D] : -1;
}

// -------- Main --------

int main() {
    while (1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;

        inicializar();

        scanf("%d %d", &S, &D);

        for (int i = 0; i < M; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            adicionar_aresta(grafo, u, v, p);
            adicionar_aresta(reverso, v, u, p);
        }

        // Primeiro Dijkstra para caminhos mínimos
        dijkstra(S);

        // Backtrack do destino ao início para marcar todas as arestas mínimas
        backtrack(D);

        // Encontrar o "quase menor caminho"
        int resultado = encontrar_quase_menor_caminho();
        printf("%d\n", resultado);
    }

    return 0;
}

