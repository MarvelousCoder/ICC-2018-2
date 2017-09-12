a, b, c = input().split()
a, b, c = [int(a), int(b), int(c)]
print("%.2f"%((a+b+c)/3))
soma_sequencias = (a+b+c)/3
quantidade_sequencias = 1
while(a != -1):
    a, b, c = input().split()
    a, b, c = [int(a), int(b), int(c)]
    if(a != -1):
        media = (a+b+c)/3
        soma_sequencias += media
        quantidade_sequencias += 1
        print("%.2f"%media)
print("%.2f"%(soma_sequencias/quantidade_sequencias))
