a, n = input().split()
a, n = [int(a), int(n)]
soma_n = 0
while(a != -1):
    if(a % 8 == 0):
        soma_n += n
    a, n = input().split()
    a, n = [int(a), int(n)]
print(soma_n)
