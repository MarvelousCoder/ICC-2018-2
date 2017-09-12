x, y = input().split()
x, y = [int(x), int(y)]
s = 0
n = y
while(n > 0):
    if(x % 2 == 0):
        s += x
        n -= 1
    x += 1
print(s)

maior = s
menor = s
soma_s = s
quantidade_s = 1
while(y >= 0):
    x, y = input().split()
    x, y = [int(x), int(y)]
    if(y >= 0):
        n = y
        s = 0
        while(n > 0):
            if(x % 2 == 0):
                s += x
                n -= 1
            x += 1
        print(s)
        if(s > maior):
            maior = s
        if(s < menor):
            menor = s
        soma_s += s
        quantidade_s += 1
        
print(maior)
print(menor)
print("%.2f"%(soma_s/quantidade_s))
