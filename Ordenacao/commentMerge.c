#include <stdio.h>
#include <stdlib.h>

// A função intercala combina dois subvetores ordenados em um único vetor ordenado.
void intercala(int X[], int inicio, int fim, int meio) {
  int poslivre, inicio_vetor1, inicio_vetor2, i;
  int aux[10];

  printf("\n--- Intercalando os subvetores ---");
  printf("\nValores de entrada: inicio = %d, fim = %d, meio = %d\n", inicio, fim, meio);
  printf("Subvetor 1: [");
  for (i = inicio; i <= meio; i++) {
    printf("%d ", X[i]);
  }
  printf("]");
  printf("\nSubvetor 2: [");
  for (i = meio + 1; i <= fim; i++) {
    printf("%d ", X[i]);
  }
  printf("]\n");
  
  // 1. Inicializando as variáveis para a intercalação.
  printf("\n// 1. Inicializando as variaveis para a intercalacao.\n");
  poslivre = inicio;
  inicio_vetor1 = inicio;
  inicio_vetor2 = meio + 1;
  printf("Variaveis iniciais: poslivre = %d, inicio_vetor1 = %d, inicio_vetor2 = %d\n", poslivre, inicio_vetor1, inicio_vetor2);

  // 2. Compara os elementos dos dois subvetores e os coloca no vetor auxiliar em ordem.
  printf("\n// 2. Compara os elementos dos dois subvetores e os coloca no vetor auxiliar em ordem.\n");
  printf("while (inicio_vetor1 <= meio && inicio_vetor2 <= fim) {\n");
  while (inicio_vetor1 <= meio && inicio_vetor2 <= fim) {
    if (X[inicio_vetor1] <= X[inicio_vetor2]) {
      aux[poslivre] = X[inicio_vetor1];
      printf("  if (X[%d] <= X[%d]) -> %d <= %d eh verdadeiro. aux[%d] = %d\n", inicio_vetor1, inicio_vetor2, X[inicio_vetor1], X[inicio_vetor2], poslivre, X[inicio_vetor1]);
      inicio_vetor1 = inicio_vetor1 + 1;
    } else {
      aux[poslivre] = X[inicio_vetor2];
      printf("  if (X[%d] <= X[%d]) -> %d <= %d eh falso. aux[%d] = %d\n", inicio_vetor1, inicio_vetor2, X[inicio_vetor1], X[inicio_vetor2], poslivre, X[inicio_vetor2]);
      inicio_vetor2 = inicio_vetor2 + 1;
    }
    poslivre = poslivre + 1;
    printf("  Apos a iteracao: inicio_vetor1 = %d, inicio_vetor2 = %d, poslivre = %d\n", inicio_vetor1, inicio_vetor2, poslivre);
  }
  printf("}\n");

  // 3. Copia os elementos restantes do primeiro subvetor (se houver).
  printf("\n// 3. Copia os elementos restantes do primeiro subvetor (se houver).\n");
  printf("for (i = inicio_vetor1; i <= meio; i++) {\n");
  for (i = inicio_vetor1; i <= meio; i++) {
    aux[poslivre] = X[i];
    printf("  aux[%d] = X[%d] -> aux[%d] = %d\n", poslivre, i, poslivre, X[i]);
    poslivre = poslivre + 1;
  }
  printf("}\n");

  // 4. Copia os elementos restantes do segundo subvetor (se houver).
  printf("\n// 4. Copia os elementos restantes do segundo subvetor (se houver).\n");
  printf("for (i = inicio_vetor2; i <= fim; i++) {\n");
  for (i = inicio_vetor2; i <= fim; i++) {
    aux[poslivre] = X[i];
    printf("  aux[%d] = X[%d] -> aux[%d] = %d\n", poslivre, i, poslivre, X[i]);
    poslivre = poslivre + 1;
  }
  printf("}\n");

  // 5. Copia os elementos ordenados do vetor auxiliar de volta para o vetor original.
  printf("\n// 5. Copia os elementos ordenados do vetor auxiliar de volta para o vetor original.\n");
  printf("for (i = inicio; i <= fim; i++) {\n");
  for (i = inicio; i <= fim; i++) {
    X[i] = aux[i];
    printf("  X[%d] = aux[%d] -> X[%d] = %d\n", i, i, i, aux[i]);
  }
  printf("}\n");
  
  printf("Subvetor intercalado: [");
  for (i = inicio; i <= fim; i++) {
    printf("%d ", X[i]);
  }
  printf("]\n");
}

// A função merge divide o vetor recursivamente até que cada subvetor tenha apenas um elemento.
void merge(int X[], int inicio, int fim) {
  int meio;
  printf("\n--- Chamada Recursiva: merge(X, %d, %d) ---", inicio, fim);
  printf("\nEstado atual do vetor: [");
  for (int j = inicio; j <= fim; j++) {
      printf("%d ", X[j]);
  }
  printf("]\n");

  // 1. Condição de parada da recursão.
  printf("\n// 1. Condicao de parada da recursao: if (inicio < fim) {\n");
  if (inicio < fim) {
    // 2. Calcula o ponto médio para dividir o vetor.
    printf("\n// 2. Calcula o ponto medio para dividir o vetor.\n");
    meio = (inicio + fim) / 2;
    printf("  meio = (inicio + fim) / 2 -> meio = (%d + %d) / 2 = %d\n", inicio, fim, meio);
    
    // 3. Chamada recursiva para a primeira metade.
    printf("\n// 3. Chamada recursiva para a primeira metade.\n");
    printf("  merge(X, inicio, meio) -> merge(X, %d, %d)\n", inicio, meio);
    merge(X, inicio, meio);
    
    // 4. Chamada recursiva para a segunda metade.
    printf("\n// 4. Chamada recursiva para a segunda metade.\n");
    printf("  merge(X, meio + 1, fim) -> merge(X, %d, %d)\n", meio + 1, fim);
    merge(X, meio + 1, fim);
    
    // 5. Combina os dois subvetores ordenados.
    printf("\n// 5. Combina os dois subvetores ordenados (voltando da recursao).\n");
    printf("  intercala(X, inicio, fim, meio) -> intercala(X, %d, %d, %d)\n", inicio, fim, meio);
    intercala(X, inicio, fim, meio);
  } else {
    printf("} else {\n  Base da recursao atingida. O subvetor tem apenas um elemento: [%d]\n}\n", X[inicio]);
  }
}

void main() {
  int X[10] = {5,3,1,9,7,2,4,5,8,3};
  int i;

  system("clear");

  printf("Vetor inicial: [");
  for (i = 0; i < 10; i++) {
      printf("%d ", X[i]);
  }
  printf("]\n");

  printf("\n--- Inicio do Merge Sort ---\n");
  merge(X, 0, 9);
  printf("\n--- Fim do Merge Sort ---\n");

  printf("\n\nVetor ordenado final:\n");
  for (i = 0; i < 10; i++) {
    printf("%d ", X[i]);
  }
  printf("\n");

  printf("\nPressione qualquer tecla para continuar...");
  getchar();
  getchar();
}