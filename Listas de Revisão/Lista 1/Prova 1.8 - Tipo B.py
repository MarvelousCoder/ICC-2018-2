def mdc(a,b):
    if(b == 0):
        return a
    else:
        return mdc(b, a%b)
def mmc(a,b):
    if(a == 0 or b == 0):
        return 0
    else:
        return (a*b)//mdc(a,b)
    
n = int(input())
a, b = input().split()
a, b = [int(a), int(b)]
maior = mmc(a,b)
soma = maior
quantidade = 1
print(maior)
while(n > 1):
    a, b = input().split()
    a, b = [int(a), int(b)]
    x = mmc(a,b)
    print(x)
    soma += x
    quantidade += 1
    n -= 1
print("%.2f"%(soma/quantidade))
