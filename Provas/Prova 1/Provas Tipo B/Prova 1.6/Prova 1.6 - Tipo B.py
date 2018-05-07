a, n = input().split()
a, n = [int(a), int(n)]

maior = a + n
soma_n = 0
media_n = 0
quantidade_n = 0
while(a != -1):
    if(a % 8 == 0):
        soma_n += n
    if(n > 3):
        media_n += n
        quantidade_n += 1
    a, n = input().split()
    a, n = [int(a), int(n)]
    if(a != -1):
        if(a + n > maior):
            maior = a + n
print(soma_n)
if(quantidade_n > 0):
    print("%.2f"%(media_n/quantidade_n))
else:
    print("0.00")
print(maior)
