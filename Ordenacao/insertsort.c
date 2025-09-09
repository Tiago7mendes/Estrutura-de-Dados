#include <stdio.h>

int main()
{
    int X[5];
    int i, j, eleito;

    for(i=0; i<=4; i++)
    {
        printf("Digite o %dº numero: ", i+1);
        scanf("%d", &X[i]);
    }

    for(i=1; i<=4; i++)
    {
        eleito = X[i];
        j = i - 1;

        while (j >= 0 && X[j] > eleito)
        {
            X[j+1] = X[j];
            j = j - 1;
        }
        X[j+1] = eleito;
    }

    for(i=0; i<=4; i++)
    {
        printf("%dº numero: %d\n", i+1, X[i]);
    }
    return 0;
}