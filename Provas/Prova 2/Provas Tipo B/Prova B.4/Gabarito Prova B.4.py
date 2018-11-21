bina, dec = input().split()

codPar = bina[-1]

for i in range(int(dec)):
    binaAux = input()
    paridade = 0
    for item in binaAux:
        if item == codPar:
            paridade += 1
    if paridade%2 != 0:
        print("OK")
    else:
        print("Erro detectado")
