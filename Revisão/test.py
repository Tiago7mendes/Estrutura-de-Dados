class Produto:
    def __init__(self, codigo, nome, preco, qttd):
        self.codigo = codigo
        self.nome = nome
        self.preco = preco
        self.qttd = qttd


def cadastroProduto(produtos):
    codigo = len(produtos) + 1
    nome = input("Digite o nome do Produto: ")
    preco = float(input("Digite o preco do Produto: "))
    qttd = int(input("Digite a quantidade do Produto: "))

    novo = Produto(codigo, nome, preco, qttd)
    produtos.append(novo)
    print("Produto cadastrado com sucesso!\n")


def visualizarEstoque(produtos):
    if not produtos:
        print("Estoque vazio!\n")
        return

    for p in produtos:
        print(f"Código: {p.codigo}")
        print(f"Nome: {p.nome}")
        print(f"Preço: R$ {p.preco:.2f}")
        print(f"Quantidade: {p.qttd}")
        print("--------------------------")


def buscaProduto(produtos):
    c = int(input("Digite o código do produto: "))
    encontrado = False

    for p in produtos:
        if p.codigo == c:
            print("Produto encontrado!")
            print(f"Código: {p.codigo}")
            print(f"Nome: {p.nome}")
            print(f"Preço: R$ {p.preco:.2f}")
            print(f"Quantidade: {p.qttd}\n")
            encontrado = True
            break

    if not encontrado:
        print("Produto não encontrado!\n")


def atualizaQuantidade(produtos):
    c = int(input("Digite o código do produto: "))
    encontrado = False

    for p in produtos:
        if p.codigo == c:
            print("Produto encontrado!")
            print(f"Quantidade atual: {p.qttd}")
            novaQtd = int(input("Digite a nova quantidade: "))
            p.qttd = novaQtd
            print("Quantidade atualizada com sucesso!\n")
            encontrado = True
            break

    if not encontrado:
        print("Produto não encontrado!\n")


def excluiProduto(produtos):
    c = int(input("Digite o código do produto que deseja excluir: "))
    encontrado = False

    for i, p in enumerate(produtos):
        if p.codigo == c:
            encontrado = True
            produtos.pop(i)
            print("Produto excluído com sucesso!\n")
            break

    if not encontrado:
        print("Produto não encontrado!\n")


def main():
    produtos = []
    while True:
        print("1. Cadastrar Produto")
        print("2. Visualizar Estoque")
        print("3. Buscar Produto")
        print("4. Atualizar Quantidade")
        print("5. Excluir Produto")
        print("6. Sair")
        opcao = int(input("Escolha uma opção: "))

        if opcao == 1:
            cadastroProduto(produtos)
        elif opcao == 2:
            visualizarEstoque(produtos)
        elif opcao == 3:
            buscaProduto(produtos)
        elif opcao == 4:
            atualizaQuantidade(produtos)
        elif opcao == 5:
            excluiProduto(produtos)
        elif opcao == 6:
            print("Saindo do programa...")
            break
        else:
            print("Opção inválida! Tente novamente.\n")


if __name__ == "__main__":
    main()
