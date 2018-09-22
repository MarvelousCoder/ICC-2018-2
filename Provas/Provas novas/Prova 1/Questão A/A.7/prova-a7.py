atividade = ""
atividadeMaior = ""
atividadeMenor = ""
numProcessoMaior = ""
qntMaior = 0
qntMenor = 0
media = 0

i = 0
while atividade != 'sem_atividade':
    numProcesso, atividade, qntAgua = input().split()
    qntAgua = float(qntAgua)
    media += qntAgua

    if atividade != 'sem_atividade':
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
        i += 1

if i == 0:
    print("0.00")
else:
    print(atividadeMaior)
    print(atividadeMenor)
    print("%.2f" %(media/i))
    print(numProcessoMaior)
