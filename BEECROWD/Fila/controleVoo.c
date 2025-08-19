#include <stdio.h>
#include <string.h>

int main() {
    char filaOeste[100][10];
    char filaNorte[100][10];
    char filaSul[100][10];
    char filaLeste[100][10];
    char aviao[10];
    int pontoCardeal;

    int qOeste = 0, qNorte = 0, qSul = 0, qLeste = 0;

    printf("Digite as entradas (0 para encerrar):\n");

    while (1) {
        scanf("%s", aviao);

        if (strcmp(aviao, "0") == 0)
            break;

        if (aviao[0] == '-') {
            sscanf(aviao, "%d", &pontoCardeal);
        } else {
            if (pontoCardeal == -1) {
                strcpy(filaOeste[qOeste++], aviao);
            } else if (pontoCardeal == -3) {
                strcpy(filaNorte[qNorte++], aviao);
            } else if (pontoCardeal == -2) {
                strcpy(filaSul[qSul++], aviao);
            } else if (pontoCardeal == -4) {
                strcpy(filaLeste[qLeste++], aviao);
            }
        }
    }
    
    int iOeste = 0, iNorte = 0, iSul = 0, iLeste = 0;
    int total = qOeste + qNorte + qSul + qLeste;

    printf("\nOrdem das aeronaves:\n");

    while (total > 0) {
        if (iOeste < qOeste) {
            printf("%s ", filaOeste[iOeste++]);
            total--;
        }
        if (iNorte < qNorte) {
            printf("%s ", filaNorte[iNorte++]);
            total--;
        }
        if (iSul < qSul) {
            printf("%s ", filaSul[iSul++]);
            total--;
        }
        if (iLeste < qLeste) {
            printf("%s ", filaLeste[iLeste++]);
            total--;
        }
    }

    printf("\n");

    return 0;
}
