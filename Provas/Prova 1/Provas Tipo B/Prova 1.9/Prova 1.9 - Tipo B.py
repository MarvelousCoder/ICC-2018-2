def fatorial(k):
    if(k == 0 or k == 1):
        return 1
    else:
        return k*fatorial(k-1)

k = int(input())
quantidade_k = 1
soma_k = k
print(fatorial(k))
if(fatorial(k) % 3 == 0):
    quantidade_fatoriais = 1
else:
    quantidade_fatoriais = 0
while(k >= 0):
    k = int(input())
    if(k >= 0):
        quantidade_k += 1
        soma_k += k
        x = fatorial(k)
        print(x)
        if(x % 3 == 0):
            quantidade_fatoriais += 1
print("%.2f"%(soma_k/quantidade_k))
print(quantidade_fatoriais)
