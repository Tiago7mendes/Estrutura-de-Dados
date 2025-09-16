#include <stdio.h>
#include <stdlib.h> // Necessary for system("cls") or system("clear")

void main() {
  int X[5];
  int i, j, eleito, menor, pos;
  
  // Limpa a tela. system("cls") é para Windows, system("clear") para Linux.
  // Pode não funcionar em todos os sistemas.
  system("clear");

  // carregando os números no vetor
  for (i = 0; i <= 4; i++) {
    printf("Digite o %dº numero: ", i + 1);
    scanf("%d", &X[i]);
  }

  // ordenando de forma crescente
  // laço que percorre da 1ª posição à penúltima posição do vetor
  for (i = 0; i <= 3; i++) {
    // elegendo um número para ser comparado
    eleito = X[i];

    // encontrando o menor número à direita do eleito
    // com sua respectiva posição
    // posição do eleito = i
    // primeiro número à direita do eleito na posição = i + 1
    menor = X[i + 1];
    pos = i + 1;

    // laço que percorre os elementos que estão à direita do
    // número eleito, retornando o menor número à direita
    // e sua posição
    for (j = i + 1; j <= 4; j++) {
      if (X[j] < menor) {
        menor = X[j];
        pos = j;
      }
    }

    // troca do número eleito com o número da posição pos
    // o número da posição pos é o menor número à direita do número eleito
    if (menor < eleito) {
      X[i] = X[pos];
      X[pos] = eleito;
    }
  }

  // mostrando o vetor ordenado
  for (i = 0; i <= 4; i++) {
    printf("%dº numero: %d\n", i + 1, X[i]);
  }
}
