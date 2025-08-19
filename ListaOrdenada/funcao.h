#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int info;
    struct no *prox;
} NO;

NO* criaLista();
bool verificaVazia(NO *lista);
bool inserirInicio(NO **lista, int valor);
bool inserirFinal(NO **lista, int valor);
bool inserirOrdenado(NO **lista, int valor);
void mostrarElementos(NO *lista);
void mostrarElementosREC(NO *lista);
bool removerInicio(NO **lista);
bool removerFinal(NO **lista);
NO* consultarValor(NO *lista, int valor);
