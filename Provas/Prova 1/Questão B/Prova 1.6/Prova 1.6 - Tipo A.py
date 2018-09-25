n = int(input())
soma_pares = 0
quantidade_pares = 0
soma_mdc = 0
while(n > 0):
    a, b = input().split()
    a, b = [int(a), int(b)]
    if(a % 2 == 0):
        soma_pares += a
        quantidade_pares += 1
    if(b % 2 == 0):
        soma_pares += b
        quantidade_pares += 1
    n -= 1
if(quantidade_pares > 0):
    print("%.2f"%(soma_pares/quantidade_pares))
else:
    print("0.00")
