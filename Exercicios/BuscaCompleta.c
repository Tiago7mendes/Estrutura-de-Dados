#include <stdio.h>
#include <stdlib.h>

void buscaBinaria(int X[5], int np)
{
    int inicio = 0, fim = 4, meio, achou = 0;

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

void buscaSequencial(int X[5], int n) {
    int achou = 0, i = 0;

    while (i < 5 && achou == 0 && n >= X[i]) {
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

void bubblesort(int X[]) {
    int aux;
    for(int n=1;n<=5;n++)
    {
        for(int i=0;i<=3;i++)
        {
            if (X[i] > X[i+1])
            {
                aux = X[i];
                X[i] = X[i+1];
                X[i+1] = aux;
            }
        }
    }

    for(int i=0; i<=4; i++)
    {
        printf("%dº numero: %d\n", i+1, X[i]);
    }
}

void insertsort(int X[5]) {
    int j, aux;
    for(int i=1; i<=4; i++)
    {
        aux = X[i];
        j = i - 1;

        while (j >= 0 && X[j] > aux)
        {
            X[j+1] = X[j];
            j = j - 1;
        }
        X[j+1] = aux;
    }

    for(int i=0; i<=4; i++)
    {
        printf("%dº numero: %d\n", i+1, X[i]);
    }
}

int main() {
    int vetor1[5] = {7, 3, 55, 40, 2}, vetor2[5] = {17, 23, 5, 0, 22};
    int num;

    printf("Ordenação Bubblesort: \n");
    bubblesort(vetor1);

    printf("Ordenação Insertsort: \n");
    insertsort(vetor2);

    printf("Digite o numero a ser procurado: ");
    scanf("%d", &num);

    printf("Busca Binaria: \n");
    buscaBinaria(vetor1, num);

    printf("Busca Sequencial: \n");
    buscaSequencial(vetor2, num);
}