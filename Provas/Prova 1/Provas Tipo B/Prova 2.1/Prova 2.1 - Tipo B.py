def fatorial(num):
    if(num == 1 or num == 0):
        return 1
    else:
        return num*fatorial(num-1)

n = int(input())
soma = 0
quantidade = n
quantidade_fatoriais = 0
while(n > 0):
    a, b = input().split()
    a, b = [int(a), int(b)]
    soma += a
    x = fatorial(a) + fatorial(b)
    print(x)
    if(x % b == 0):
        quantidade_fatoriais += 1
    n -= 1
print("%.2f"%(soma/quantidade))
print(quantidade_fatoriais)
