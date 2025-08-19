#include <stdio.h>
#include "funcao.h"

int main() {
    NO *lista = criaLista();
    int opcao, valor;
    NO *encontrado;

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no final\n");
        printf("3 - Inserir ordenado\n");
        printf("4 - Mostrar elementos\n");
        printf("5 - Mostrar elementos (recursivo)\n");
        printf("6 - Remover do início\n");
        printf("7 - Remover do final\n");
        printf("8 - Consultar valor\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                if (inserirInicio(&lista, valor))
                    printf("Inserido no início com sucesso.\n");
                else
                    printf("Erro ao inserir.\n");
                break;

            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                if (inserirFinal(&lista, valor))
                    printf("Inserido no final com sucesso.\n");
                else
                    printf("Erro ao inserir.\n");
                break;

            case 3:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                if (inserirOrdenado(&lista, valor))
                    printf("Inserido ordenadamente com sucesso.\n");
                else
                    printf("Erro ao inserir.\n");
                break;

            case 4:
                printf("Elementos da lista:\n");
                mostrarElementos(lista);
                break;

            case 5:
                printf("Elementos da lista (recursivo):\n");
                mostrarElementosREC(lista);
                break;

            case 6:
                if (removerInicio(&lista))
                    printf("Primeiro elemento removido com sucesso.\n");
                else
                    printf("Lista vazia. Nada para remover.\n");
                break;

            case 7:
                if (removerFinal(&lista))
                    printf("Último elemento removido com sucesso.\n");
                else
                    printf("Lista vazia. Nada para remover.\n");
                break;

            case 8:
                printf("Digite o valor a consultar: ");
                scanf("%d", &valor);
                encontrado = consultarValor(lista, valor);
                if (encontrado != NULL)
                    printf("Valor %d encontrado no nó %p.\n", encontrado->info, (void*)encontrado);
                else
                    printf("Valor não encontrado.\n");
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
