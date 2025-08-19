class Produto:
    def __init__(self, codigo, nome, preco, qttd):
        self.codigo = codigo
        self.nome = nome
        self.preco = preco
        self.qttd = qttd

    def exibir(self):
        print(f"Código: {self.codigo}")
        print(f"Nome: {self.nome}")
        print(f"Preço: R$ {self.preco:.2f}")
        print(f"Quantidade: {self.qttd}")
        print("--------------------------")


class Estoque:
    def __init__(self):
        self.produtos = []

    def cadastrar_produto(self):
        codigo = len(self.produtos) + 1
        nome = input("Digite o nome do Produto: ")
        preco = float(input("Digite o preco do Produto: "))
        qttd = int(input("Digite a quantidade do Produto: "))

        novo = Produto(codigo, nome, preco, qttd)
        self.produtos.append(novo)
        print("Produto cadastrado com sucesso!\n")

    def visualizar_estoque(self):
        if not self.produtos:
            print("Estoque vazio!\n")
            return
        for p in self.produtos:
            p.exibir()

    def buscar_produto(self):
        c = int(input("Digite o código do produto: "))
        for p in self.produtos:
            if p.codigo == c:
                print("Produto encontrado!")
                p.exibir()
                return
        print("Produto não encontrado!\n")

    def atualizar_quantidade(self):
        c = int(input("Digite o código do produto: "))
        for p in self.produtos:
            if p.codigo == c:
                print("Produto encontrado!")
                print(f"Quantidade atual: {p.qttd}")
                novaQtd = int(input("Digite a nova quantidade: "))
                p.qttd = novaQtd
                print("Quantidade atualizada com sucesso!\n")
                return
        print("Produto não encontrado!\n")

    def excluir_produto(self):
        c = int(input("Digite o código do produto que deseja excluir: "))
        for i, p in enumerate(self.produtos):
            if p.codigo == c:
                self.produtos.pop(i)
                print("Produto excluído com sucesso!\n")
                return
        print("Produto não encontrado!\n")


def main():
    estoque = Estoque()

    while True:
        print("1. Cadastrar Produto")
        print("2. Visualizar Estoque")
        print("3. Buscar Produto")
        print("4. Atualizar Quantidade")
        print("5. Excluir Produto")
        print("6. Sair")
        opcao = int(input("Escolha uma opção: "))

        if opcao == 1:
            estoque.cadastrar_produto()
        elif opcao == 2:
            estoque.visualizar_estoque()
        elif opcao == 3:
            estoque.buscar_produto()
        elif opcao == 4:
            estoque.atualizar_quantidade()
        elif opcao == 5:
            estoque.excluir_produto()
        elif opcao == 6:
            print("Saindo do programa...")
            break
        else:
            print("Opção inválida! Tente novamente.\n")


if __name__ == "__main__":
    main()
