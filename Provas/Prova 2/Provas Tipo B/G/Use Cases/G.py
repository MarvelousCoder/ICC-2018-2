N = int(input())

features = []

for i in range(N):
    features.append(input())

M = int(input())
lesser = []

for i in range(M):
    model = input()
    # esta é a melhor forma de resolver esse problema
    # mas eu não sei se `enumerate` chegou a ser apresentado em sala de aula
    # failed aqui é uma array de índices de falhas

    failed = [index for (index, x) in enumerate(model) if x == "O"]

    # uma solução bem menos "pythonica", e que supõe que o aluno
    # não sabe como usar índice no loop seria:
    index = 0
    failed = []
    for c in model:
        if c == 'O':
            failed.append(index)
        index += 1
    # fim da solução pior

    if len(failed) > len(lesser):
        lesser = failed

for index in lesser:
    print(features[index])
