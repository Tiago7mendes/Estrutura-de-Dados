/*Faça um programa que cadastre 15 números ordenados, por exemplo {1, 5, 9, 13, 17,
21, 25, 29, 33, 37, 41, 45, 49, 53, 57}. Verifique se um número digitado pelo usuário
está no vetor.
a) usando busca sequencial;
b) usando busca binária*/

#include <stdio.h>
#include <stdlib.h>

void buscaBinaria(int X[15], int np)
{
    int inicio = 0, fim = 14, meio, achou = 0;
    system("cls"); // Equivalente a clrscr() para limpar a tela

    meio = (inicio+fim)/2;
    while (inicio <= fim && achou == 0)
    {
        if (X[meio] == np)
            achou = 1;
        else
        {
            if (np < X[meio])
                fim = meio-1;
            else
                inicio = meio+1;
        }
        meio = (inicio+fim)/2;
    }
    if (achou == 0)
        printf("Numero nao encontrado no vetor");
    else
        printf("Numero encontrado na posicao %d", meio+1);

    printf("\nPressione Enter para sair...");
    getchar(); 
    getchar();
}

void buscaSequencial(int X[15], int n) {
    int achou = 0, i = 0;

    while (i < 15 && achou == 0 && n >= X[i]) {
        if (X[i] == n) {
            achou = 1;
        } else {
            i++;
        }
    }

    if (achou == 0) {
        printf("Número não encontrado no vetor\n");
    } else {
        printf("Número encontrado na posicao %d\n", i + 1);
    }

}

int main() {
    int vetor[15] = {1, 5, 9, 13, 17, 21, 25, 29, 33, 37, 41, 45, 49, 53, 57};
    int num;

    printf("Digite o numero a ser procurado: ");
    scanf("%d", &num);

    printf("Busca Binaria: \n");
    buscaBinaria(vetor, num);

    printf("Busca Sequencial: \n");
    buscaSequencial(vetor, num);
}