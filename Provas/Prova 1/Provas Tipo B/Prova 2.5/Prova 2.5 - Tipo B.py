def somatorio_impar(k):
    if(k > 0):
        if(k % 2 != 0):
            return k + somatorio_impar(k-1)
        else:
            return k-1 + somatorio_impar(k-3)
    else:
        return 0

n = int(input())
k = int(input())
if(k < 0):
    print("erro")
    menor_s = 9999999999
    quantidade = 0
    soma_s = 0
else:
    quantidade = 1
    menor_s = somatorio_impar(k)
    soma_s = menor_s
    print(menor_s)
while(n > 1):
    k = int(input())
    if(k < 0):
        print("erro")
    else:
        x = somatorio_impar(k)
        print(x)
        soma_s += x
        quantidade += 1
        if(x < menor_s):
            menor_s = x
    n -= 1
print(menor_s)
print("%.2f"%(soma_s/quantidade))
