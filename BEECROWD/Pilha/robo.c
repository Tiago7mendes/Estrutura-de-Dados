#include <stdio.h>
#include <string.h>

#define MAX 10

char pilha[MAX][20];
int topo = -1;

void push(char comando[]) {
    if (topo < MAX - 1) {
        topo++;
        strcpy(pilha[topo], comando);
    }
}

void retornar() {
    printf("GIRAR 180\n");
    for (int i = topo; i >= 0; i--) {
        if (strcmp(pilha[i], "FRENTE") == 0) {
            printf("FRENTE\n");
        } else if (strcmp(pilha[i], "DIREITA") == 0) {
            printf("ESQUERDA\n");
        } else if (strcmp(pilha[i], "ESQUERDA") == 0) {
            printf("DIREITA\n");
        }
    }
}

int main() {
    char comando[20];
    int total = 0;

    while (total < MAX) {
        scanf("%s", comando);

        if (strcmp(comando, "RETORNAR") == 0) {
            retornar();
            break; // termina o programa após retornar
        }

        // empilha o comando e imprime
        push(comando);
        printf("%s\n", comando);
        total++;
    }

    return 0;
}
