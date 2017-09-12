a, b, c = input().split()
a, b, c = [int(a), int(b), int(c)]
print("%.2f"%((a+b+c)/3))
quantidade_pares = 0
soma_pares = 0
soma_sequencias = (a+b+c)/3
quantidade_sequencias = 1
maior = (a+b+c)/3
while(a != -1):
    if(a % 2 == 0):
        quantidade_pares += 1
        soma_pares += a
    if(b % 2 == 0):
        quantidade_pares += 1
        soma_pares += b
    if(c % 2 == 0):
        quantidade_pares += 1
        soma_pares += c
    a, b, c = input().split()
    a, b, c = [int(a), int(b), int(c)]
    if(a != -1):
        media = (a+b+c)/3
        soma_sequencias += media
        quantidade_sequencias += 1
        print("%.2f"%media)
        if(media > maior):
            maior = media
if(quantidade_pares > 0):
    print("%.2f"%(soma_pares/quantidade_pares))
else:
    print("0.00")
print("%.2f"%maior)
print("%.2f"%(soma_sequencias/quantidade_sequencias))
