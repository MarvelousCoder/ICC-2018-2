N = int(input())

nomeBH, areaBH, indiceV, indiceO, indiceI, indiceP = input().split()
areaBH, indiceV, indiceO, indiceI, indiceP = [float(areaBH), float(indiceV), float(indiceO),
                                              float(indiceI), float(indiceP)]

maiorIndice = indiceV + indiceO + indiceI + indiceP
menorIndice = indiceV
if menorIndice > indiceO:
    menorIndice = indiceO
if menorIndice > indiceI:
    menorIndice = indiceI
if menorIndice > indiceP:
    menorIndice = indiceP

nomeMaior = nomeBH
nomeMenor = nomeBH
areaTotal = areaBH

for i in range(N - 1):
    nomeBH, areaBH, indiceV, indiceO, indiceI, indiceP = input().split()
    areaBH, indiceV, indiceO, indiceI, indiceP = [float(areaBH), float(indiceV), float(indiceO),
                                                  float(indiceI), float(indiceP)]
    indiceAux = indiceV + indiceO + indiceI + indiceP

    if indiceAux > maiorIndice:
        maiorIndice = indiceAux
        nomeMaior = nomeBH

    if menorIndice > indiceV:
        menorIndice = indiceV
        nomeMenor = nomeBH
    if menorIndice > indiceO:
        menorIndice = indiceO
        nomeMenor = nomeBH
    if menorIndice > indiceI:
        menorIndice = indiceI
        nomeMenor = nomeBH
    if menorIndice > indiceP:
        menorIndice = indiceP
        nomeMenor = nomeBH
    areaTotal += areaBH

print(nomeMaior)
print(nomeMenor)
print("%.2f" %(areaTotal/N))


    
        
    
