#include <stdio.h>

struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int qttd;
};

void cadastroProduto(struct Produto p[], int *total) {
    p[*total].codigo = *total + 1;

    printf("Digite o nome do Produto: ");
    scanf(" %[^\n]", p[*total].nome);

    printf("Digite o preco do Produto: ");
    scanf("%f", &p[*total].preco);

    printf("Digite a quantidade do Produto: ");
    scanf("%d", &p[*total].qttd);

    (*total)++;
    printf("Produto cadastrado com sucesso!\n\n");
}

void visualizarEstoque(struct Produto p[], int total) {
    if (total == 0) {
        printf("Estoque vazio!\n\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("Código: %d\n", p[i].codigo);
        printf("Nome: %s\n", p[i].nome);
        printf("Preço: R$ %.2f\n", p[i].preco);
        printf("Quantidade: %d\n", p[i].qttd);
        printf("--------------------------\n");
    }
}

void buscaProduto(struct Produto p[], int total) {
    int c, encontrado = 0;

    printf("Digite o código do produto: ");
    scanf("%d", &c);

    for (int i = 0; i < total; i++) {
        if (p[i].codigo == c) {
            printf("Produto encontrado!\n");
            printf("Código: %d\n", p[i].codigo);
            printf("Nome: %s\n", p[i].nome);
            printf("Preço: R$ %.2f\n", p[i].preco);
            printf("Quantidade: %d\n\n", p[i].qttd);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto não encontrado!\n\n");
    }
}

void atualizaQuantidade(struct Produto p[], int total) {
    int c, encontrado = 0;

    printf("Digite o código do produto: ");
    scanf("%d", &c);

    for (int i = 0; i < total; i++) {
        if (p[i].codigo == c) {
            int novaQtd;
            printf("Produto encontrado!\n");
            printf("Quantidade atual: %d\n", p[i].qttd);
            printf("Digite a nova quantidade: ");
            scanf("%d", &novaQtd);
            p[i].qttd = novaQtd;
            printf("Quantidade atualizada com sucesso!\n\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto não encontrado!\n\n");
    }
}

void excluiProduto(struct Produto p[], int *total) {
    int c, encontrado = 0;

    printf("Digite o código do produto que deseja excluir: ");
    scanf("%d", &c);

    for (int i = 0; i < *total; i++) {
        if (p[i].codigo == c) {
            encontrado = 1;

            for (int j = i; j < *total - 1; j++) {
                p[j] = p[j + 1];
            }

            (*total)--;
            printf("Produto excluído com sucesso!\n\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Produto não encontrado!\n\n");
    }
}

int main() {
    int opcao, totalProduto = 0;
    struct Produto p[50]; // Vetor de produtos

    do {
        printf("1. Cadastrar Produto\n");
        printf("2. Visualizar Estoque\n");
        printf("3. Buscar Produto\n");
        printf("4. Atualizar Quantidade\n");
        printf("5. Excluir Produto\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastroProduto(p, &totalProduto);
                break;
            case 2:
                visualizarEstoque(p, totalProduto);
                break;
            case 3:
                buscaProduto(p, totalProduto);
                break;
            case 4:
                atualizaQuantidade(p, totalProduto);
                break;
            case 5:
                excluiProduto(p, &totalProduto);
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}
