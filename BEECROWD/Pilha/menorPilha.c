#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

int stackValores[MAX];
int stackMinimos[MAX];
int topo = -1;
int topoMin = -1;

void push(int valor) {
    stackValores[++topo] = valor;

    if (topoMin == -1 || valor <= stackMinimos[topoMin]) {
        stackMinimos[++topoMin] = valor;
    }
}

void pop() {
    if (topo == -1) {
        printf("EMPTY\n");
        return;
    }

    int removido = stackValores[topo--];

    if (removido == stackMinimos[topoMin]) {
        topoMin--;
    }
}

void min() {
    if (topoMin == -1) {
        printf("EMPTY\n");
    } else {
        printf("%d\n", stackMinimos[topoMin]);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    char operacao[10];
    int valor;

    for (int i = 0; i < N; i++) {
        scanf("%s", operacao);

        if (strcmp(operacao, "PUSH") == 0) {
            scanf("%d", &valor);
            push(valor);
        } else if (strcmp(operacao, "POP") == 0) {
            pop();
        } else if (strcmp(operacao, "MIN") == 0) {
            min();
        }
    }

    return 0;
}
