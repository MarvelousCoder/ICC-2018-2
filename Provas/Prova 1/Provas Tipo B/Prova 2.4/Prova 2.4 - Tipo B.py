def somatorio_par(n):
    if(n > 0):
        if(n % 2 == 0):
            return n + somatorio_par(n-2)
        else:
            return n-1 + somatorio_par(n-3)
    else:
        return 0

n = int(input())
maior = somatorio_par(n)
soma = maior
quantidade = 1
while(n >= 0):
    print(somatorio_par(n))
    n = int(input())
    if(n >= 0):
        x = somatorio_par(n)
        if(x > maior):
            maior = x
        soma += x
        quantidade += 1
print(maior)
print("%.2f"%(soma/quantidade))

    
