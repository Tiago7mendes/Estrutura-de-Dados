def busca_ordenada():
    X = []
    for i in range(10):
        num = int(input(f"Digite o {i+1}º número: "))
        X.append(num)

    n = int(input("Digite o número a ser buscado no vetor: "))

    i = 0
    achou = False
    while i < 10 and not achou and n >= X[i]:
        if X[i] == n:
            achou = True
        else:
            i += 1

    if achou:
        print(f"Número encontrado na posição {i+1}")
    else:
        print("Número não encontrado no vetor")


if __name__ == "__main__":
    busca_ordenada()
