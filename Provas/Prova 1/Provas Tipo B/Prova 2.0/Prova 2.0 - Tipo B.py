def mdc(a,b):
    if(b == 0):
        return a
    else:
        return mdc(b, a%b)

n = int(input())
soma_pares = 0
quantidade = n
quantidade_pares = 0
soma_mdc = 0
while(n > 0):
    a, b = input().split()
    a, b = [int(a), int(b)]
    x = mdc(a,b)
    print(x)
    soma_mdc += x
    if(a % 2 == 0):
        soma_pares += a
        quantidade_pares += 1
    if(b % 2 == 0):
        soma_pares += b
        quantidade_pares += 1
    n -= 1
if(quantidade_pares > 0):
    print("%.2f"%(soma_mdc/quantidade))
    print("%.2f"%(soma_pares/quantidade_pares))
else:
    print("%.2f"%(soma_mdc/quantidade))
    print("0.00")
