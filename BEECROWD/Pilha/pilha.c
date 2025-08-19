#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

// Inicializar pilha
void inicializarPilha(Pilha* p) {
    p->topo = -1;
}

// Verificar se está cheia
int verificarPilhaCheia(Pilha* p) {
    return p->topo == MAX - 1;
}

// Verificar se está vazia
int verificarPilhaVazia(Pilha* p) {
    return p->topo == -1;
}

// Empilhar (push)
int empilhar(Pilha* p, int valor) {
    if (verificarPilhaCheia(p)) return 0;
    p->dados[++p->topo] = valor;
    return 1;
}

// Desempilhar (pop)
int desempilhar(Pilha* p, int* valor) {
    if (verificarPilhaVazia(p)) return 0;
    *valor = p->dados[p->topo--];
    return 1;
}

// Mostrar valor do topo (peek)
int mostrarValorTopo(Pilha* p, int* valor) {
    if (verificarPilhaVazia(p)) return 0;
    *valor = p->dados[p->topo];
    return 1;
}

// Inverter a pilha
void inverterPilha(Pilha* p) {
    int i = 0, j = p->topo, temp;
    while (i < j) {
        temp = p->dados[i];
        p->dados[i] = p->dados[j];
        p->dados[j] = temp;
        i++;
        j--;
    }
}

// Fazer cópia da pilha
void fazerCopiaPilha(Pilha* origem, Pilha* destino) {
    destino->topo = origem->topo;
    for (int i = 0; i <= origem->topo; i++) {
        destino->dados[i] = origem->dados[i];
    }
}

// Verificar se duas pilhas são iguais
int verificaPilhasIguais(Pilha* p1, Pilha* p2) {
    if (p1->topo != p2->topo) return 0;
    for (int i = 0; i <= p1->topo; i++) {
        if (p1->dados[i] != p2->dados[i]) return 0;
    }
    return 1;
}

// Verificar se duas pilhas têm o mesmo tamanho
int verificaPilhasMesmoTamanho(Pilha* p1, Pilha* p2) {
    return p1->topo == p2->topo;
}

// ----------- Função main para teste --------------
int main() {
    Pilha p1, p2, copia;
    int valor;

    inicializarPilha(&p1);
    inicializarPilha(&p2);

    printf("Empilhando valores na p1: 10, 20, 30\n");
    empilhar(&p1, 10);
    empilhar(&p1, 20);
    empilhar(&p1, 30);

    mostrarValorTopo(&p1, &valor);
    printf("Topo da p1: %d\n", valor);

    printf("Copiando p1 para copia...\n");
    fazerCopiaPilha(&p1, &copia);

    printf("Invertendo a pilha copia...\n");
    inverterPilha(&copia);

    printf("Desempilhando todos os valores da copia:\n");
    while (desempilhar(&copia, &valor)) {
        printf("%d ", valor);
    }
    printf("\n");

    printf("Verificando se p1 está vazia: %s\n", verificarPilhaVazia(&p1) ? "Sim" : "Não");

    printf("Desempilhando todos os valores da p1:\n");
    while (desempilhar(&p1, &valor)) {
        printf("%d ", valor);
    }
    printf("\n");

    printf("Verificando se p1 está vazia agora: %s\n", verificarPilhaVazia(&p1) ? "Sim" : "Não");

    // Teste pilhas iguais
    empilhar(&p1, 5);
    empilhar(&p1, 6);
    empilhar(&p1, 7);

    empilhar(&p2, 5);
    empilhar(&p2, 6);
    empilhar(&p2, 7);

    printf("Pilha p1 e p2 são iguais? %s\n", verificaPilhasIguais(&p1, &p2) ? "Sim" : "Não");
    printf("Pilha p1 e p2 têm mesmo tamanho? %s\n", verificaPilhasMesmoTamanho(&p1, &p2) ? "Sim" : "Não");

    empilhar(&p2, 8);  // Agora p2 tem um item a mais

    printf("Após empilhar mais um em p2:\n");
    printf("Pilha p1 e p2 são iguais? %s\n", verificaPilhasIguais(&p1, &p2) ? "Sim" : "Não");
    printf("Pilha p1 e p2 têm mesmo tamanho? %s\n", verificaPilhasMesmoTamanho(&p1, &p2) ? "Sim" : "Não");

    return 0;
}
