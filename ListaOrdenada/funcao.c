#include "funcao.h"

NO * criaLista(){
    NO *aux;

    aux = NULL;
    return(aux);
}

bool verificaVazia(NO *lista){
    if (lista == NULL)
    {
        return true;
    } else return false;
}

bool inserirInicio(NO **lista, int valor){
    NO *aux;

    aux = malloc(sizeof(NO));
    if (aux == NULL)
    {
        return false;
    } else{
        aux->info = valor;
        aux->prox = *lista;
        *lista = aux;
        return true;
    }    
}

void mostrarElementos(NO *lista){
    while (lista != NULL)
    {
        printf("%d \n", lista->info);
        lista = lista->prox;
    }
}

void mostrarElementosREC(NO *lista){
    if (verificaVazia(lista) == false)
    {
        printf("%d \n", lista->info);
        mostrarElementosREC(lista->prox);
    }
}

bool inserirFinal(NO **lista, int valor) {
    NO *novo = malloc(sizeof(NO));
    if (novo == NULL) return false;

    novo->info = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        NO *atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    return true;
}

bool inserirOrdenado(NO **lista, int valor) {
    NO *novo = malloc(sizeof(NO));
    if (novo == NULL) return false;

    novo->info = valor;
    novo->prox = NULL;

    if (*lista == NULL || valor < (*lista)->info) {
        novo->prox = *lista;
        *lista = novo;
        return true;
    }

    NO *atual = *lista;
    while (atual->prox != NULL && atual->prox->info < valor) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
    return true;
}

bool removerInicio(NO **lista) {
    if (*lista == NULL) return false;

    NO *remover = *lista;
    *lista = remover->prox;
    free(remover);
    return true;
}

bool removerFinal(NO **lista) {
    if (*lista == NULL) return false;

    NO *atual = *lista;

    if (atual->prox == NULL) {
        free(atual);
        *lista = NULL;
        return true;
    }

    while (atual->prox->prox != NULL) {
        atual = atual->prox;
    }

    free(atual->prox);
    atual->prox = NULL;
    return true;
}

NO* consultarValor(NO *lista, int valor) {
    while (lista != NULL) {
        if (lista->info == valor) {
            return lista;
        }
        lista = lista->prox;
    }
    return NULL;
}
