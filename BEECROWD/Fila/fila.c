#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio, fim;
} Fila;

// Inicializar a fila
void inicializarFila(Fila* f) {
    f->inicio = f->fim = 0;
}

// Verificar se a fila está vazia
int verificarVazia(Fila* f) {
    return f->inicio == f->fim;
}

// Verificar se a fila está cheia
int verificarCheia(Fila* f) {
    return (f->fim + 1) % MAX == f->inicio;
}

// Mostrar valor do início da fila (sem remover)
int mostrarInicio(Fila* f, int* valor) {
    if (verificarVazia(f)) return 0;
    *valor = f->dados[f->inicio];
    return 1;
}

// Adicionar elemento (enfileirar)
int enfileirar(Fila* f, int valor) {
    if (verificarCheia(f)) return 0;
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    return 1;
}

// Remover elemento (desenfileirar)
int desenfileirar(Fila* f, int* valor) {
    if (verificarVazia(f)) return 0;
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    return 1;
}

// Retirar valor da posição X da fila
int retirarPosicao(Fila* f, int posicao, int* retirado) {
    int tamanho = (f->fim - f->inicio + MAX) % MAX;
    if (posicao < 0 || posicao >= tamanho) return 0;

    Fila temp;
    inicializarFila(&temp);
    int atual, count = 0;

    while (desenfileirar(f, &atual)) {
        if (count == posicao) {
            *retirado = atual;
        } else {
            enfileirar(&temp, atual);
        }
        count++;
    }
    *f = temp;
    return 1;
}

// Mesclar duas filas em uma terceira
void mesclarFilas(Fila* f1, Fila* f2, Fila* resultado) {
    inicializarFila(resultado);
    int val;
    while (desenfileirar(f1, &val)) enfileirar(resultado, val);
    while (desenfileirar(f2, &val)) enfileirar(resultado, val);
}

// ----------- Função main para testes ----------
int main() {
    Fila f1, f2, resultado;
    int valor;

    inicializarFila(&f1);
    inicializarFila(&f2);

    printf("Enfileirando na f1: 10, 20, 30\n");
    enfileirar(&f1, 10);
    enfileirar(&f1, 20);
    enfileirar(&f1, 30);

    printf("Enfileirando na f2: 40, 50\n");
    enfileirar(&f2, 40);
    enfileirar(&f2, 50);

    printf("Mostrar início da f1:\n");
    if (mostrarInicio(&f1, &valor)) {
        printf("Início da f1: %d\n", valor);
    }

    printf("Fila f1 está vazia? %s\n", verificarVazia(&f1) ? "Sim" : "Não");
    printf("Fila f1 está cheia? %s\n", verificarCheia(&f1) ? "Sim" : "Não");

    printf("Retirando valor da posição 1 da f1:\n");
    if (retirarPosicao(&f1, 1, &valor)) {
        printf("Valor retirado: %d\n", valor);
    }

    printf("Desenfileirando todos os valores restantes de f1:\n");
    while (desenfileirar(&f1, &valor)) {
        printf("%d ", valor);
    }
    printf("\n");

    printf("Mesclando f1 e f2 em resultado...\n");
    enfileirar(&f1, 60);  // f1: 60
    enfileirar(&f2, 70);  // f2: já tinha 40, 50, agora 70

    mesclarFilas(&f1, &f2, &resultado);

    printf("Conteúdo da fila resultado:\n");
    while (desenfileirar(&resultado, &valor)) {
        printf("%d ", valor);
    }
    printf("\n");

    return 0;
}
