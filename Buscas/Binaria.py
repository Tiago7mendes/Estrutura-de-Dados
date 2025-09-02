def busca_binaria():
    X = []
    for i in range(10):
        num = int(input(f"Digite o {i+1}º número: "))
        X.append(num)

    np = int(input("Digite o número a ser buscado no vetor: "))

    inicio = 0
    fim = 9
    achou = False

    while inicio <= fim and not achou:
        meio = (inicio + fim) // 2
        if X[meio] == np:
            achou = True
        elif np < X[meio]:
            fim = meio - 1
        else:
            inicio = meio + 1

    if achou:
        print(f"Número encontrado na posição {meio+1}")
    else:
        print("Número não encontrado no vetor")


if __name__ == "__main__":
    busca_binaria()
