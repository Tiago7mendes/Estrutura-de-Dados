#include <stdio.h>
int main()
{
    int X[5], n, i, aux;
    
    for(i=0;i<=4;i++)
    {
        printf("Digite o %d° numero: ", i+1);
        scanf("%d", &X[i]);
    }

    for(n=1;n<=5;n++)
    {
        for(i=0;i<=3;i++)
        {
            if (X[i] > X[i+1])
            {
                aux = X[i];
                X[i] = X[i+1];
                X[i+1] = aux;
            }
        }
    }

    for(i=0;i<=4;i++)
    {
        printf("%d° numero: %d\n", i+1, X[i]);
    }
    return 0;
}