def bin2dec(bina, op):
    if op == 1:
        decod = bina.replace(cod[0], '0').replace(cod[1], '1')
    else:
        decod = bina.replace(cod[0], '1').replace(cod[1], '0')
    dec = 0
    tam = len(decod)-1
    for n in decod:
        if n == '1':
            dec += 2**tam
        tam -=1
    
    print(dec)

def dec2bin(inte, op):
    decod = bin(inte)[2::]
    if op == 1:
        decod = str(decod).replace('0', cod[0]).replace('1', cod[1])
        #print(int(decod))
        while len(decod) != len(bina):
            decod = cod[0] + decod
    else:
        decod = str(decod).replace('1', cod[0]).replace('0', cod[1])
        while len(decod) != len(bina):
            decod = cod[1] + decod
    print(decod)


bina, una = input().split()

qnt = len(una)
cod = []

for letra in bina:
    if letra not in cod:
        cod.append(letra)

aux1 = bina.replace(cod[0], '0').replace(cod[1], '1')
aux2 = bina.replace(cod[0], '1').replace(cod[1], '0')
op = 0
if int(aux1) == int(bin(qnt)[2::]):
    op = 1
else:
    op = 2

numeros = '1234567890'
for i in range(qnt):
    crip = input()
    if crip[0] in numeros:
        dec2bin(int(crip), op)
    else:
        bin2dec(crip, op)