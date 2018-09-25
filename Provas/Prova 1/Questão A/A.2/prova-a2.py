num = int(input())

atividadeMaior = ""
atividadeMenor = ""
numProcessoMaior = ""
qntMaior = 0
qntMenor = 0
media = 0
for i in range(num):
    numProcesso, atividade, qntAgua = input().split()
    qntAgua = float(qntAgua)

    media += qntAgua/num

    if i == 0:
        atividadeMaior = atividade
        atividadeMenor = atividade
        qntMaior = qntAgua
        qntMenor = qntAgua
        numProcessoMaior = numProcesso
    else:
        if qntAgua < qntMenor:
            qntMenor = qntAgua
            atividadeMenor = atividade
        if qntAgua > qntMaior:
            qntMaior = qntAgua
            atividadeMaior = atividade
            numProcessoMaior = numProcesso

if num != 0:
    print(atividadeMaior)
    print(atividadeMenor)
print("%.2f" %(media))
print(numProcessoMaior)
