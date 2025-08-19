#include <stdio.h>

#define MAX_N 50001
#define MAX_ID 100001

int filaInicial[MAX_N];
char removidos[MAX_ID]; // 0 = não saiu, 1 = saiu

int main() {
    int N, M, id;

    // Leitura da fila inicial
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &filaInicial[i]);
    }

    // Leitura dos que saíram e marcação
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &id);
        removidos[id] = 1; // marca que saiu
    }

    // Imprimir estado final da fila
    for (int i = 0; i < N; i++) {
        if (!removidos[filaInicial[i]]) {
            printf("%d ", filaInicial[i]);
        }
    }

    printf("\n");
    return 0;
}
