N = int(input())

nome, popU, vazao, DBO, popA = input().split()
popU, vazao, DBO, popA = [int(popU), float(vazao), float(DBO), int(popA)]

maiorVazao = vazao
menorDBO = DBO
nomeMaior = nome
nomeMenor = nome
popTotalU = popU
popTotalA = popA

for i in range(N-1):
    nome, popU, vazao, DBO, popA = input().split()
    popU, vazao, DBO, popA = [int(popU), float(vazao), float(DBO), int(popA)]

    if maiorVazao < vazao:
        maiorVazao = vazao
        nomeMaior = nome
    if menorDBO > DBO:
        menorDBO = DBO
        nomeMenor = nome
    popTotalU += popU
    popTotalA += popA

popNA = popTotalU - popTotalA

print(nomeMaior)
print(nomeMenor)
print("%.2f" %(popNA*100/popTotalU))
