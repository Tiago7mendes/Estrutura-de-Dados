#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20005
#define MAX_M 100005
#define MAX_S 50005

typedef struct {
    int u, v, peso;
} Aresta;

typedef struct {
    int origem, destino;
    int indice; // Para manter a ordem original das consultas
} Consulta;

Aresta arestas[MAX_M];
Consulta consultas[MAX_S];
int resposta[MAX_S];
int pai[MAX_N];

// Função de comparação para ordenar arestas em ordem decrescente de peso
int cmpArestas(const void* a, const void* b) {
    return ((Aresta*)b)->peso - ((Aresta*)a)->peso;
}

// Union-Find
int find(int x) {
    if (pai[x] != x)
        pai[x] = find(pai[x]);
    return pai[x];
}

void unir(int a, int b) {
    int raizA = find(a);
    int raizB = find(b);
    if (raizA != raizB)
        pai[raizB] = raizA;
}

int main() {
    int N, M, S;
    while (scanf("%d %d %d", &N, &M, &S) != EOF) {
        // Ler arestas
        for (int i = 0; i < M; ++i) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
        }

        // Ler consultas
        for (int i = 0; i < S; ++i) {
            scanf("%d %d", &consultas[i].origem, &consultas[i].destino);
            consultas[i].indice = i;
            resposta[i] = -1; // Inicialmente, nenhuma resposta
        }

        // Inicializar Union-Find
        for (int i = 1; i <= N; ++i) {
            pai[i] = i;
        }

        // Ordenar arestas por peso decrescente
        qsort(arestas, M, sizeof(Aresta), cmpArestas);

        int respondidas = 0;

        // Para marcar quais consultas já foram respondidas
        char feita[MAX_S] = {0};

        for (int i = 0; i < M && respondidas < S; ++i) {
            unir(arestas[i].u, arestas[i].v);

            for (int j = 0; j < S; ++j) {
                if (!feita[j]) {
                    int a = consultas[j].origem;
                    int b = consultas[j].destino;

                    if (find(a) == find(b)) {
                        resposta[j] = arestas[i].peso;
                        feita[j] = 1;
                        respondidas++;
                    }
                }
            }
        }

        // Imprimir respostas na ordem original
        for (int i = 0; i < S; ++i) {
            printf("%d\n", resposta[i]);
        }
    }

    return 0;
}

