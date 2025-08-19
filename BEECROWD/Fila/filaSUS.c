#include <stdio.h>

#define MAX 25

typedef struct {
    int hora, minuto, critico;
} Paciente;

int minutosDesdeSete(int h, int m) {
    return (h - 7) * 60 + m;
}

int proximoHorario(int atual) {
    if (atual % 30 == 0) return atual;
    return ((atual / 30) + 1) * 30;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;

        Paciente pilha[MAX];
        int topo = -1;

        for (int i = 0; i < n; i++) {
            int h, m, c;
            scanf("%d %d %d", &h, &m, &c);
            topo++;
            pilha[topo].hora = h;
            pilha[topo].minuto = m;
            pilha[topo].critico = c;
        }

        int tempoAtual = 0; // em minutos desde 7h00
        int criticos = 0;

        for (int i = 0; i <= topo; i++) {
            int chegada = minutosDesdeSete(pilha[i].hora, pilha[i].minuto);

            if (chegada > tempoAtual) {
                // Médico está ocioso, atende imediatamente
                tempoAtual = chegada;
            } else {
                // Médico está ocupado, atende no próximo múltiplo de 30
                tempoAtual = proximoHorario(tempoAtual);
            }

            int espera = tempoAtual - chegada;
            if (espera > pilha[i].critico) {
                criticos++;
            }

            tempoAtual += 30; // duração da consulta
        }

        printf("%d\n", criticos);
    }

    return 0;
}
