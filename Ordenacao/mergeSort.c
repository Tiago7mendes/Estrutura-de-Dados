#include <stdio.h>
#include <stdlib.h> // Necessary for system("cls") or system("clear")

// o merge sort é o melhor quando tratamos em vetor grandes

void intercala(int X[], int inicio, int fim, int meio) {
  int poslivre, inicio_vetor1, inicio_vetor2, i;
  int aux[10];
  inicio_vetor1 = inicio;
  inicio_vetor2 = meio + 1;
  poslivre = inicio;

  while (inicio_vetor1 <= meio && inicio_vetor2 <= fim) {
    if (X[inicio_vetor1] <= X[inicio_vetor2]) {
      aux[poslivre] = X[inicio_vetor1];
      inicio_vetor1 = inicio_vetor1 + 1;
    } else {
      aux[poslivre] = X[inicio_vetor2];
      inicio_vetor2 = inicio_vetor2 + 1;
    }
    poslivre = poslivre + 1;
  }

  // Se ainda existem números no primeiro vetor
  // que não foram intercalados
  for (i = inicio_vetor1; i <= meio; i++) {
    aux[poslivre] = X[i];
    poslivre = poslivre + 1;
  }

  // Se ainda existem números no segundo vetor
  // que não foram intercalados
  for (i = inicio_vetor2; i <= fim; i++) {
    aux[poslivre] = X[i];
    poslivre = poslivre + 1;
  }

  // Retorna os valores do vetor aux para o vetor X
  for (i = inicio; i <= fim; i++) {
    X[i] = aux[i];
  }
}

void merge(int X[], int inicio, int fim) {
  int meio;
  if (inicio < fim) {
    meio = (inicio + fim) / 2;
    merge(X, inicio, meio); // depois que finaliza esse, ele sai do if() e vai para o segundo merge()
    merge(X, meio + 1, fim); // por causa da recursão!
    intercala(X, inicio, fim, meio);
  }
}

void main() {
  int X[10];
  int i;

  // Limpa a tela. system("cls") é para Windows, system("clear") para Linux.
  // Pode não funcionar em todos os sistemas.
  system("clear");

  // carregando os números no vetor
  for (i = 0; i <= 9; i++) {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &X[i]);
  }

  // ordenando de forma crescente
  merge(X, 0, 9);

  // mostrando o vetor ordenado
  for (i = 0; i <= 9; i++) {
    printf("\n%dº número: %d", i + 1, X[i]);
  }

  // Equivalente ao getch() para pausar a execução.
  printf("\nPressione qualquer tecla para continuar...");
  getchar(); // Captura o ENTER do scanf
  getchar(); // Espera a próxima tecla
}