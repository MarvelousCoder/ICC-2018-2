N = int(input())

nome, popU, vazaoSem, vazaoCom, popA, investimento = input().split()
popU, vazaoSem, vazaoCom, popA, investimento = [int(popU), float(vazaoSem), float(vazaoCom), int(popA), float(investimento)]
vazaoTotal = vazaoSem + vazaoCom

maior_vazaoSem = vazaoSem
nome_vazaoSem = nome

maior_taxaV = (vazaoCom*100)/vazaoTotal
nome_taxaV = nome

maior_taxaP = (popA*100)/popU
nome_taxaP = nome

soma_investimento = investimento

for i in range(N-1):
    nome, popU, vazaoSem, vazaoCom, popA, investimento = input().split()
    popU, vazaoSem, vazaoCom, popA, investimento = [int(popU), float(vazaoSem), float(vazaoCom), int(popA), float(investimento)]
    vazaoTotal = vazaoSem + vazaoCom

    if vazaoSem > maior_vazaoSem:
        maior_vazaoSem = vazaoSem
        nome_vazaoSem= nome
    if (vazaoCom*100)/vazaoTotal > maior_taxaV:
        maior_taxaV = (vazaoCom*100)/vazaoTotal
        nome_taxaV = nome
    if (popA*100)/popU > maior_taxaP:
        maior_taxaP = (popA*100)/popU
        nome_taxaP = nome

    soma_investimento += investimento

print(nome_vazaoSem)
print(nome_taxaV)
print(nome_taxaP)
print("R$ %.2f" %(soma_investimento/N))

    

