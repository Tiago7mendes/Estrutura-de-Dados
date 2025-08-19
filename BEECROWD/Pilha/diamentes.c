#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char linha[1100];  

    scanf("%d", &N);
    getchar(); 

    while (N--) {
        fgets(linha, sizeof(linha), stdin);

        int diamantes = 0;
        int pilha = 0;

        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == '<') {
                pilha++;  
            } else if (linha[i] == '>') {
                if (pilha > 0) {
                    pilha--;     
                    diamantes++;  
                }
            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}
